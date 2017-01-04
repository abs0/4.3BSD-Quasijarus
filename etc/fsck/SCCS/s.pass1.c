h03781
s 00002/00001/00210
d D 5.4 87/04/09 10:36:09 mckusick 11 10
c more stringent test on negative size (from chris@maryland.edu - 4.2BSD/etc/36)
e
s 00007/00006/00204
d D 5.3 86/05/13 16:36:06 mckusick 10 9
c must check for bad block earlier
e
s 00002/00000/00208
d D 5.2 86/03/05 17:15:22 mckusick 9 8
c must define state of unknown type inodes
e
s 00008/00002/00200
d D 5.1 85/06/05 08:56:24 dist 8 7
c Add copyright
e
s 00007/00003/00195
d D 3.7 85/06/02 16:47:07 mckusick 7 6
c dynamically allocate zero link count table
e
s 00016/00010/00182
d D 3.6 85/05/31 20:08:40 mckusick 6 5
c dynamically allocate the duplicate block table
e
s 00008/00006/00184
d D 3.5 85/02/15 12:07:02 mckusick 5 4
c filesize now set by ckinode(); pass1() uses id_entryno to calc block count
e
s 00001/00002/00189
d D 3.4 85/02/11 18:29:20 mckusick 4 3
c ginode() succeeds or exits
e
s 00081/00118/00110
d D 3.3 85/02/08 19:15:35 mckusick 3 2
c merge passes 5 and 6 into a single pass
e
s 00036/00019/00192
d D 3.2 85/02/07 17:52:06 mckusick 2 1
c code reorganization and cleanup
e
s 00211/00000/00000
d D 3.1 84/03/31 21:03:45 mckusick 1 0
c date and time created 84/03/31 21:03:45 by mckusick
e
u
U
f b 
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 8
I 1
#ifndef lint
D 8
static char version[] = "%W% (Berkeley) %G%";
#endif
E 8
I 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8

#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include "fsck.h"

D 3
int	pass1check();
E 3
I 3
static daddr_t badblk;
static daddr_t dupblk;
int pass1check();
E 3

pass1()
{
D 3
	register int c, i, n, j;
E 3
I 3
	register int c, i, j;
E 3
	register DINODE *dp;
I 7
	struct zlncnt *zlnp;
E 7
D 2
	int ndb, partial;
E 2
I 2
	int ndb, partial, cgd;
E 2
	struct inodesc idesc;
	ino_t inumber;

I 2
	/*
	 * Set file system reserved blocks in used block map.
	 */
	for (c = 0; c < sblock.fs_ncg; c++) {
		cgd = cgdmin(&sblock, c);
		if (c == 0) {
			i = cgbase(&sblock, c);
			cgd += howmany(sblock.fs_cssize, sblock.fs_fsize);
		} else
			i = cgsblock(&sblock, c);
		for (; i < cgd; i++)
			setbmap(i);
	}
	/*
	 * Find all allocated blocks.
	 */
E 2
	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = ADDR;
	idesc.id_func = pass1check;
	inumber = 0;
D 3
	n_blks += howmany(sblock.fs_cssize, sblock.fs_fsize);
E 3
I 3
	n_files = n_blks = 0;
E 3
	for (c = 0; c < sblock.fs_ncg; c++) {
D 3
		if (getblk(&cgblk, cgtod(&sblock, c), sblock.fs_cgsize) == 0)
			continue;
		if (cgrp.cg_magic != CG_MAGIC) {
			pfatal("CG %d: BAD MAGIC NUMBER\n", c);
			bzero((char *)&cgrp, (int)sblock.fs_cgsize);
		}
		n = 0;
E 3
		for (i = 0; i < sblock.fs_ipg; i++, inumber++) {
D 3
			dp = ginode(inumber);
			if (dp == NULL)
E 3
I 3
			if (inumber < ROOTINO)
E 3
				continue;
D 3
			n++;
D 2
			if (ALLOC) {
E 2
I 2
			if (ALLOC(dp)) {
E 2
				if (!isset(cgrp.cg_iused, i)) {
					if (debug)
						printf("%d bad, not used\n",
						    inumber);
					inosumbad++;
				}
				n--;
				lastino = inumber;
				if (!preen && (dp->di_mode & IFMT) == IFMT &&
				    reply("HOLD BAD BLOCK") == 1) {
					dp->di_size = sblock.fs_fsize;
					dp->di_mode = IFREG|0600;
					inodirty();
				} else if (ftypeok(dp) == 0)
					goto unknown;
				if (dp->di_size < 0) {
					if (debug)
						printf("bad size %d:",
							dp->di_size);
					goto unknown;
				}
				ndb = howmany(dp->di_size, sblock.fs_bsize);
D 2
				if (SPECIAL)
E 2
I 2
				if (SPECIAL(dp))
E 2
					ndb++;
				for (j = ndb; j < NDADDR; j++)
					if (dp->di_db[j] != 0) {
						if (debug)
							printf("bad direct addr: %d\n",
								dp->di_db[j]);
						goto unknown;
					}
				for (j = 0, ndb -= NDADDR; ndb > 0; j++)
					ndb /= NINDIR(&sblock);
				for (; j < NIADDR; j++)
					if (dp->di_ib[j] != 0) {
						if (debug)
							printf("bad indirect addr: %d\n",
								dp->di_ib[j]);
						goto unknown;
					}
				n_files++;
				lncntp[inumber] = dp->di_nlink;
				if (dp->di_nlink <= 0) {
					if (badlnp < &badlncnt[MAXLNCNT])
						*badlnp++ = inumber;
					else {
						pfatal("LINK COUNT TABLE OVERFLOW");
						if (reply("CONTINUE") == 0)
							errexit("");
					}
				}
D 2
				statemap[inumber] = DIRCT ? DSTATE : FSTATE;
E 2
I 2
				statemap[inumber] = DIRCT(dp) ? DSTATE : FSTATE;
E 2
				badblk = dupblk = 0; maxblk = 0;
				idesc.id_number = inumber;
				idesc.id_filesize = 0;
				(void)ckinode(dp, &idesc);
				idesc.id_filesize *= btodb(sblock.fs_fsize);
				if (dp->di_blocks != idesc.id_filesize) {
					pwarn("INCORRECT BLOCK COUNT I=%u (%ld should be %ld)",
					    inumber, dp->di_blocks,
					    idesc.id_filesize);
					if (preen)
						printf(" (CORRECTED)\n");
					else if (reply("CORRECT") == 0)
						continue;
					dp->di_blocks = idesc.id_filesize;
					inodirty();
				}
E 3
I 3
D 4
			if ((dp = ginode(inumber)) == NULL)
E 3
				continue;
E 4
I 4
			dp = ginode(inumber);
E 4
D 3
		unknown:
				pfatal("UNKNOWN FILE TYPE I=%u", inumber);
				if (reply("CLEAR") == 1) {
					zapino(dp);
					inodirty();
					inosumbad++;
				}
			} else {
				if (isset(cgrp.cg_iused, i)) {
					if (debug)
						printf("%d bad, marked used\n",
						    inumber);
					inosumbad++;
					n--;
				}
				partial = 0;
				for (j = 0; j < NDADDR; j++)
					if (dp->di_db[j] != 0)
						partial++;
				for (j = 0; j < NIADDR; j++)
					if (dp->di_ib[j] != 0)
						partial++;
				if (partial || dp->di_mode != 0 ||
				    dp->di_size != 0) {
E 3
I 3
			if (!ALLOC(dp)) {
				if (bcmp((char *)dp->di_db, (char *)zino.di_db,
					NDADDR * sizeof(daddr_t)) ||
				    bcmp((char *)dp->di_ib, (char *)zino.di_ib,
					NIADDR * sizeof(daddr_t)) ||
				    dp->di_mode || dp->di_size) {
E 3
					pfatal("PARTIALLY ALLOCATED INODE I=%u",
						inumber);
					if (reply("CLEAR") == 1) {
						zapino(dp);
						inodirty();
D 3
						inosumbad++;
E 3
					}
				}
I 3
				statemap[inumber] = USTATE;
				continue;
E 3
			}
I 3
			lastino = inumber;
D 11
			if (dp->di_size < 0) {
E 11
I 11
			if (dp->di_size < 0 ||
			    dp->di_size + sblock.fs_bsize - 1 < 0) {
E 11
				if (debug)
					printf("bad size %d:", dp->di_size);
				goto unknown;
			}
I 10
			if (!preen && (dp->di_mode & IFMT) == IFMT &&
			    reply("HOLD BAD BLOCK") == 1) {
				dp->di_size = sblock.fs_fsize;
				dp->di_mode = IFREG|0600;
				inodirty();
			}
E 10
			ndb = howmany(dp->di_size, sblock.fs_bsize);
			if (SPECIAL(dp))
				ndb++;
			for (j = ndb; j < NDADDR; j++)
				if (dp->di_db[j] != 0) {
					if (debug)
						printf("bad direct addr: %d\n",
							dp->di_db[j]);
					goto unknown;
				}
			for (j = 0, ndb -= NDADDR; ndb > 0; j++)
				ndb /= NINDIR(&sblock);
			for (; j < NIADDR; j++)
				if (dp->di_ib[j] != 0) {
					if (debug)
						printf("bad indirect addr: %d\n",
							dp->di_ib[j]);
					goto unknown;
				}
D 10
			if (!preen && (dp->di_mode & IFMT) == IFMT &&
			    reply("HOLD BAD BLOCK") == 1) {
				dp->di_size = sblock.fs_fsize;
				dp->di_mode = IFREG|0600;
				inodirty();
			} else if (ftypeok(dp) == 0)
E 10
I 10
			if (ftypeok(dp) == 0)
E 10
				goto unknown;
			n_files++;
			lncntp[inumber] = dp->di_nlink;
			if (dp->di_nlink <= 0) {
D 7
				if (badlnp < &badlncnt[MAXLNCNT])
					*badlnp++ = inumber;
				else {
E 7
I 7
				zlnp = (struct zlncnt *)malloc(sizeof *zlnp);
				if (zlnp == NULL) {
E 7
					pfatal("LINK COUNT TABLE OVERFLOW");
					if (reply("CONTINUE") == 0)
						errexit("");
I 7
				} else {
					zlnp->zlncnt = inumber;
					zlnp->next = zlnhead;
					zlnhead = zlnp;
E 7
				}
			}
			statemap[inumber] = DIRCT(dp) ? DSTATE : FSTATE;
			badblk = dupblk = 0; maxblk = 0;
			idesc.id_number = inumber;
D 5
			idesc.id_filesize = 0;
E 5
			(void)ckinode(dp, &idesc);
D 5
			idesc.id_filesize *= btodb(sblock.fs_fsize);
			if (dp->di_blocks != idesc.id_filesize) {
E 5
I 5
			idesc.id_entryno *= btodb(sblock.fs_fsize);
			if (dp->di_blocks != idesc.id_entryno) {
E 5
				pwarn("INCORRECT BLOCK COUNT I=%u (%ld should be %ld)",
D 5
				    inumber, dp->di_blocks, idesc.id_filesize);
E 5
I 5
				    inumber, dp->di_blocks, idesc.id_entryno);
E 5
				if (preen)
					printf(" (CORRECTED)\n");
				else if (reply("CORRECT") == 0)
					continue;
D 5
				dp->di_blocks = idesc.id_filesize;
E 5
I 5
				dp->di_blocks = idesc.id_entryno;
E 5
				inodirty();
			}
			continue;
	unknown:
			pfatal("UNKNOWN FILE TYPE I=%u", inumber);
I 9
			statemap[inumber] = FCLEAR;
E 9
			if (reply("CLEAR") == 1) {
I 9
				statemap[inumber] = USTATE;
E 9
				zapino(dp);
				inodirty();
			}
E 3
		}
D 3
		if (n != cgrp.cg_cs.cs_nifree) {
			if (debug)
				printf("cg[%d].cg_cs.cs_nifree is %d; calc %d\n",
				    c, cgrp.cg_cs.cs_nifree, n);
			inosumbad++;
		}
		if (cgrp.cg_cs.cs_nbfree != sblock.fs_cs(&sblock, c).cs_nbfree
		  || cgrp.cg_cs.cs_nffree != sblock.fs_cs(&sblock, c).cs_nffree
		  || cgrp.cg_cs.cs_nifree != sblock.fs_cs(&sblock, c).cs_nifree
		  || cgrp.cg_cs.cs_ndir != sblock.fs_cs(&sblock, c).cs_ndir)
			sbsumbad++;
E 3
	}
}

pass1check(idesc)
	register struct inodesc *idesc;
{
D 6
	register daddr_t *dlp;
E 6
	int res = KEEPON;
	int anyout, nfrags;
	daddr_t blkno = idesc->id_blkno;
I 6
	register struct dups *dlp;
	struct dups *new;
E 6

D 2
	anyout = outrange(blkno, idesc->id_numfrags);
E 2
I 2
	if ((anyout = outrange(blkno, idesc->id_numfrags)) != 0) {
		blkerr(idesc->id_number, "BAD", blkno);
		if (++badblk >= MAXBAD) {
			pwarn("EXCESSIVE BAD BLKS I=%u",
				idesc->id_number);
			if (preen)
				printf(" (SKIPPING)\n");
			else if (reply("CONTINUE") == 0)
				errexit("");
			return (STOP);
		}
	}
E 2
	for (nfrags = idesc->id_numfrags; nfrags > 0; blkno++, nfrags--) {
		if (anyout && outrange(blkno, 1)) {
D 2
			blkerr(idesc->id_number, "BAD", blkno);
			if (++badblk >= MAXBAD) {
				pwarn("EXCESSIVE BAD BLKS I=%u",
					idesc->id_number);
				if (preen)
					printf(" (SKIPPING)\n");
				else if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
			}
E 2
			res = SKIP;
D 2
		} else if (getbmap(blkno)) {
E 2
I 2
		} else if (!getbmap(blkno)) {
			n_blks++;
			setbmap(blkno);
		} else {
E 2
			blkerr(idesc->id_number, "DUP", blkno);
			if (++dupblk >= MAXDUP) {
				pwarn("EXCESSIVE DUP BLKS I=%u",
					idesc->id_number);
				if (preen)
					printf(" (SKIPPING)\n");
				else if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
			}
D 6
			if (enddup >= &duplist[DUPTBLSIZE]) {
E 6
I 6
			new = (struct dups *)malloc(sizeof(struct dups));
			if (new == NULL) {
E 6
				pfatal("DUP TABLE OVERFLOW.");
				if (reply("CONTINUE") == 0)
					errexit("");
				return (STOP);
			}
D 6
			for (dlp = duplist; dlp < muldup; dlp++)
				if (*dlp == blkno) {
					*enddup++ = blkno;
					break;
				}
			if (dlp >= muldup) {
				*enddup++ = *muldup;
				*muldup++ = blkno;
E 6
I 6
			new->dup = blkno;
			if (muldup == 0) {
				duplist = muldup = new;
				new->next = 0;
			} else {
				new->next = muldup->next;
				muldup->next = new;
E 6
			}
I 6
			for (dlp = duplist; dlp != muldup; dlp = dlp->next)
				if (dlp->dup == blkno)
					break;
			if (dlp == muldup && dlp->dup != blkno)
				muldup = new;
E 6
D 2
		} else {
			n_blks++;
			setbmap(blkno);
E 2
		}
D 5
		idesc->id_filesize++;
E 5
I 5
		/*
		 * count the number of blocks found in id_entryno
		 */
		idesc->id_entryno++;
E 5
	}
	return (res);
}
E 1
