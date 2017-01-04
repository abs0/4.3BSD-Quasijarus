h05700
s 00057/00056/00147
d D 5.5 88/05/07 00:16:40 mckusick 11 10
c &sblock => fs; &cgrp => cg
e
s 00076/00046/00127
d D 5.4 88/05/01 23:43:26 mckusick 10 9
c conversion and checking of dynamic and static cylinder group tables
e
s 00006/00000/00167
d D 5.3 86/10/13 15:36:25 sam 9 8
c add tahoe compiller  workaround
e
s 00006/00000/00161
d D 5.2 86/03/05 17:14:43 mckusick 8 7
c add firewall check for bad entry in state map
e
s 00008/00002/00153
d D 5.1 85/06/05 08:58:01 dist 7 6
c Add copyright
e
s 00001/00002/00154
d D 3.6 85/05/31 00:19:33 mckusick 6 5
c check for improper directory offsets; recover gracefully from read errors
e
s 00002/00001/00154
d D 3.5 85/04/21 20:42:02 mckusick 5 4
c properly calculate the size of the active block map
e
s 00129/00119/00026
d D 3.4 85/02/08 19:15:49 mckusick 4 3
c merge passes 5 and 6 into a single pass
e
s 00000/00015/00145
d D 3.3 85/01/10 17:04:57 mckusick 3 2
c -r3.2 is no longer needed as the kernel handles all updates of cg_irotor
e
s 00015/00000/00145
d D 3.2 84/08/06 20:27:33 mckusick 2 1
c include validation check for cg_irotor
e
s 00145/00000/00000
d D 3.1 84/03/31 21:03:51 mckusick 1 0
c date and time created 84/03/31 21:03:51 by mckusick
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
#ifndef lint
D 7
static char version[] = "%W% (Berkeley) %G%";
#endif
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7

#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include "fsck.h"

pass5()
{
D 4
	register int c, n, i, b, d;
	short bo[MAXCPG][NRPOS];
	long botot[MAXCPG];
	long frsum[MAXFRAG];
	int blk;
	daddr_t cbase;
	int blockbits = (1<<sblock.fs_frag)-1;
E 4
I 4
D 10
	int c, blk, frags, sumsize, mapsize;
	daddr_t dbase, dmax, d;
E 10
I 10
	int c, blk, frags, basesize, sumsize, mapsize, savednrpos;
I 11
	register struct fs *fs = &sblock;
	register struct cg *cg = &cgrp;
E 11
	daddr_t dbase, dmax;
	register daddr_t d;
E 10
	register long i, j;
	struct csum *cs;
	time_t now;
	struct csum cstotal;
	struct inodesc idesc;
	char buf[MAXBSIZE];
	register struct cg *newcg = (struct cg *)buf;
I 10
	struct ocg *ocg = (struct ocg *)buf;
E 10
E 4

D 4
	bcopy(blockmap, freemap, (unsigned)bmapsz);
	dupblk = 0;
	n_index = sblock.fs_ncg * (cgdmin(&sblock, 0) - cgtod(&sblock, 0));
E 4
I 4
D 11
	bzero((char *)newcg, sblock.fs_cgsize);
D 10
	newcg->cg_magic = CG_MAGIC;
E 10
I 10
	newcg->cg_niblk = sblock.fs_ipg;
	switch (sblock.fs_postblformat) {
E 11
I 11
	bzero((char *)newcg, fs->fs_cgsize);
	newcg->cg_niblk = fs->fs_ipg;
	switch (fs->fs_postblformat) {
E 11

	case FS_42POSTBLFMT:
		basesize = (char *)(&ocg->cg_btot[0]) - (char *)(&ocg->cg_link);
		sumsize = &ocg->cg_iused[0] - (char *)(&ocg->cg_btot[0]);
D 11
		mapsize = &ocg->cg_free[howmany(sblock.fs_fpg, NBBY)] -
E 11
I 11
		mapsize = &ocg->cg_free[howmany(fs->fs_fpg, NBBY)] -
E 11
			(u_char *)&ocg->cg_iused[0];
		ocg->cg_magic = CG_MAGIC;
D 11
		savednrpos = sblock.fs_nrpos;
		sblock.fs_nrpos = 8;
E 11
I 11
		savednrpos = fs->fs_nrpos;
		fs->fs_nrpos = 8;
E 11
		break;

	case FS_DYNAMICPOSTBLFMT:
		newcg->cg_btotoff =
		 	&newcg->cg_space[0] - (u_char *)(&newcg->cg_link);
		newcg->cg_boff =
D 11
			newcg->cg_btotoff + sblock.fs_cpg * sizeof(long);
E 11
I 11
			newcg->cg_btotoff + fs->fs_cpg * sizeof(long);
E 11
		newcg->cg_iusedoff = newcg->cg_boff + 
D 11
			sblock.fs_cpg * sblock.fs_nrpos * sizeof(short);
E 11
I 11
			fs->fs_cpg * fs->fs_nrpos * sizeof(short);
E 11
		newcg->cg_freeoff =
D 11
			newcg->cg_iusedoff + howmany(sblock.fs_ipg, NBBY);
E 11
I 11
			newcg->cg_iusedoff + howmany(fs->fs_ipg, NBBY);
E 11
		newcg->cg_nextfreeoff = newcg->cg_freeoff +
D 11
			howmany(sblock.fs_cpg * sblock.fs_spc / NSPF(&sblock),
E 11
I 11
			howmany(fs->fs_cpg * fs->fs_spc / NSPF(fs),
E 11
				NBBY);
		newcg->cg_magic = CG_MAGIC;
		basesize = &newcg->cg_space[0] - (u_char *)(&newcg->cg_link);
		sumsize = newcg->cg_iusedoff - newcg->cg_btotoff;
		mapsize = newcg->cg_nextfreeoff - newcg->cg_iusedoff;
		break;

	default:
		errexit("UNKNOWN ROTATIONAL TABLE FORMAT %d\n",
D 11
			sblock.fs_postblformat);
E 11
I 11
			fs->fs_postblformat);
E 11
	}
E 10
	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = ADDR;
	bzero((char *)&cstotal, sizeof(struct csum));
D 10
	sumsize = cgrp.cg_iused - (char *)(&cgrp);
D 5
	mapsize = howmany(MAXIPG + sblock.fs_fpg, NBBY);
E 5
I 5
	mapsize = &cgrp.cg_free[howmany(sblock.fs_fpg, NBBY)] -
		(u_char *)cgrp.cg_iused;
E 10
E 5
	(void)time(&now);
I 10
D 11
	for (i = sblock.fs_size; i < fragroundup(&sblock, sblock.fs_size); i++)
E 11
I 11
	for (i = fs->fs_size; i < fragroundup(fs, fs->fs_size); i++)
E 11
		setbmap(i);
E 10
E 4
D 11
	for (c = 0; c < sblock.fs_ncg; c++) {
D 4
		cbase = cgbase(&sblock, c);
		bzero((char *)botot, sizeof (botot));
		bzero((char *)bo, sizeof (bo));
		bzero((char *)frsum, sizeof (frsum));
		/*
		 * need to account for the super blocks
		 * which appear (inaccurately) bad
		 */
		n_bad += cgtod(&sblock, c) - cgsblock(&sblock, c);
E 4
D 6
		if (getblk(&cgblk, cgtod(&sblock, c), sblock.fs_cgsize) == 0)
			continue;
E 6
I 6
		getblk(&cgblk, cgtod(&sblock, c), sblock.fs_cgsize);
E 6
D 4
		if (cgrp.cg_magic != CG_MAGIC) {
E 4
I 4
D 10
		if (cgrp.cg_magic != CG_MAGIC)
E 10
I 10
		if (!cg_chkmagic(&cgrp))
E 11
I 11
	for (c = 0; c < fs->fs_ncg; c++) {
		getblk(&cgblk, cgtod(fs, c), fs->fs_cgsize);
		if (!cg_chkmagic(cg))
E 11
E 10
E 4
			pfatal("CG %d: BAD MAGIC NUMBER\n", c);
D 4
			bzero((char *)&cgrp, (int)sblock.fs_cgsize);
E 4
I 4
D 11
		dbase = cgbase(&sblock, c);
		dmax = dbase + sblock.fs_fpg;
		if (dmax > sblock.fs_size)
			dmax = sblock.fs_size;
		if (now > cgrp.cg_time)
			newcg->cg_time = cgrp.cg_time;
E 11
I 11
		dbase = cgbase(fs, c);
		dmax = dbase + fs->fs_fpg;
		if (dmax > fs->fs_size)
			dmax = fs->fs_size;
		if (now > cg->cg_time)
			newcg->cg_time = cg->cg_time;
E 11
		else
			newcg->cg_time = now;
		newcg->cg_cgx = c;
D 11
		if (c == sblock.fs_ncg - 1)
			newcg->cg_ncyl = sblock.fs_ncyl % sblock.fs_cpg;
E 11
I 11
		if (c == fs->fs_ncg - 1)
			newcg->cg_ncyl = fs->fs_ncyl % fs->fs_cpg;
E 11
		else
D 11
			newcg->cg_ncyl = sblock.fs_cpg;
E 11
I 11
			newcg->cg_ncyl = fs->fs_cpg;
E 11
D 10
		newcg->cg_niblk = sblock.fs_ipg;
E 10
		newcg->cg_ndblk = dmax - dbase;
		newcg->cg_cs.cs_ndir = 0;
		newcg->cg_cs.cs_nffree = 0;
		newcg->cg_cs.cs_nbfree = 0;
D 11
		newcg->cg_cs.cs_nifree = sblock.fs_ipg;
		if (cgrp.cg_rotor < newcg->cg_ndblk)
			newcg->cg_rotor = cgrp.cg_rotor;
E 11
I 11
		newcg->cg_cs.cs_nifree = fs->fs_ipg;
		if (cg->cg_rotor < newcg->cg_ndblk)
			newcg->cg_rotor = cg->cg_rotor;
E 11
		else
			newcg->cg_rotor = 0;
D 11
		if (cgrp.cg_frotor < newcg->cg_ndblk)
			newcg->cg_frotor = cgrp.cg_frotor;
E 11
I 11
		if (cg->cg_frotor < newcg->cg_ndblk)
			newcg->cg_frotor = cg->cg_frotor;
E 11
		else
			newcg->cg_frotor = 0;
D 11
		if (cgrp.cg_irotor < newcg->cg_niblk)
			newcg->cg_irotor = cgrp.cg_irotor;
E 11
I 11
		if (cg->cg_irotor < newcg->cg_niblk)
			newcg->cg_irotor = cg->cg_irotor;
E 11
		else
			newcg->cg_irotor = 0;
D 10
		bzero((char *)newcg->cg_frsum, sizeof newcg->cg_frsum);
		bzero((char *)newcg->cg_btot, sizeof newcg->cg_btot);
		bzero((char *)newcg->cg_b, sizeof newcg->cg_b);
		bzero((char *)newcg->cg_free, howmany(sblock.fs_fpg, NBBY));
		bzero((char *)newcg->cg_iused, howmany(sblock.fs_ipg, NBBY));
E 10
I 10
		bzero((char *)&newcg->cg_frsum[0], sizeof newcg->cg_frsum);
		bzero((char *)&cg_blktot(newcg)[0], sumsize + mapsize);
D 11
		if (sblock.fs_postblformat == FS_42POSTBLFMT)
E 11
I 11
		if (fs->fs_postblformat == FS_42POSTBLFMT)
E 11
			ocg->cg_magic = CG_MAGIC;
E 10
D 11
		j = sblock.fs_ipg * c;
		for (i = 0; i < sblock.fs_ipg; j++, i++) {
E 11
I 11
		j = fs->fs_ipg * c;
		for (i = 0; i < fs->fs_ipg; j++, i++) {
E 11
			switch (statemap[j]) {

			case USTATE:
				break;

			case DSTATE:
			case DCLEAR:
			case DFOUND:
				newcg->cg_cs.cs_ndir++;
				/* fall through */

			case FSTATE:
			case FCLEAR:
				newcg->cg_cs.cs_nifree--;
D 10
				setbit(newcg->cg_iused, i);
E 10
I 10
				setbit(cg_inosused(newcg), i);
E 10
				break;
I 8

			default:
				if (j < ROOTINO)
					break;
				errexit("BAD STATE %d FOR INODE I=%d",
				    statemap[j], j);
E 8
			}
E 4
		}
I 2
D 3
		for (i = 0, n = 0; i < sblock.fs_ipg; i += NBBY, n++)
			if (cgrp.cg_iused[n] != 0xff)
				break;
		for ( ; i < sblock.fs_ipg; i++) {
			if (isclr(cgrp.cg_iused, i)) {
				if (i < cgrp.cg_irotor) {
					if (debug) printf(
					    "cg %d, first free %d, irotor %d\n",
					     c, i, cgrp.cg_irotor);
					cgrp.cg_irotor = i;
					cgdirty();
					break;
				}
			}
		}
E 3
E 2
D 4
		for (b = 0; b < sblock.fs_fpg; b += sblock.fs_frag) {
			blk = blkmap(&sblock, cgrp.cg_free, b);
			if (blk == 0)
				continue;
			if (blk == blockbits) {
				if (pass5check(cbase+b, sblock.fs_frag) == STOP)
					goto out5;
				/* this is clumsy ... */
				n_ffree -= sblock.fs_frag;
				n_bfree++;
				botot[cbtocylno(&sblock, b)]++;
				bo[cbtocylno(&sblock, b)]
				    [cbtorpos(&sblock, b)]++;
				continue;
E 4
I 4
		if (c == 0)
			for (i = 0; i < ROOTINO; i++) {
D 10
				setbit(newcg->cg_iused, i);
E 10
I 10
				setbit(cg_inosused(newcg), i);
E 10
				newcg->cg_cs.cs_nifree--;
E 4
			}
D 4
			for (d = 0; d < sblock.fs_frag; d++)
				if ((blk & (1<<d)) &&
				    pass5check(cbase + b + d, (long)1) == STOP)
					goto out5;
			fragacct(&sblock, blk, frsum, 1);
E 4
I 4
		for (i = 0, d = dbase;
D 10
		     d <= dmax - sblock.fs_frag;
E 10
I 10
		     d < dmax;
E 10
D 11
		     d += sblock.fs_frag, i += sblock.fs_frag) {
E 11
I 11
		     d += fs->fs_frag, i += fs->fs_frag) {
E 11
			frags = 0;
D 11
			for (j = 0; j < sblock.fs_frag; j++) {
E 11
I 11
			for (j = 0; j < fs->fs_frag; j++) {
E 11
				if (getbmap(d + j))
					continue;
D 10
				setbit(newcg->cg_free, i + j);
E 10
I 10
				setbit(cg_blksfree(newcg), i + j);
E 10
				frags++;
			}
D 11
			if (frags == sblock.fs_frag) {
E 11
I 11
			if (frags == fs->fs_frag) {
E 11
				newcg->cg_cs.cs_nbfree++;
D 11
				j = cbtocylno(&sblock, i);
E 11
I 11
				j = cbtocylno(fs, i);
E 11
D 10
				newcg->cg_btot[j]++;
				newcg->cg_b[j][cbtorpos(&sblock, i)]++;
E 10
I 10
				cg_blktot(newcg)[j]++;
D 11
				cg_blks(&sblock, newcg, j)
				    [cbtorpos(&sblock, i)]++;
E 11
I 11
				cg_blks(fs, newcg, j)[cbtorpos(fs, i)]++;
E 11
E 10
			} else if (frags > 0) {
				newcg->cg_cs.cs_nffree += frags;
D 10
				blk = blkmap(&sblock, newcg->cg_free, i);
E 10
I 10
D 11
				blk = blkmap(&sblock, cg_blksfree(newcg), i);
E 10
				fragacct(&sblock, blk, newcg->cg_frsum, 1);
E 11
I 11
				blk = blkmap(fs, cg_blksfree(newcg), i);
				fragacct(fs, blk, newcg->cg_frsum, 1);
E 11
			}
E 4
		}
D 4
		if (bcmp((char *)cgrp.cg_frsum, (char *)frsum, sizeof(frsum))) {
			if (debug)
			for (i = 0; i < sblock.fs_frag; i++)
				if (cgrp.cg_frsum[i] != frsum[i])
				printf("cg[%d].cg_frsum[%d] have %d calc %d\n",
				    c, i, cgrp.cg_frsum[i], frsum[i]);
			frsumbad++;
E 4
I 4
D 10
		for (frags = d; d < dmax; d++) {
			if (getbmap(d))
				continue;
			setbit(newcg->cg_free, d - dbase);
			newcg->cg_cs.cs_nffree++;
E 4
		}
D 4
		if (bcmp((char *)cgrp.cg_btot, (char *)botot, sizeof (botot))) {
			if (debug)
			for (n = 0; n < sblock.fs_cpg; n++)
				if (botot[n] != cgrp.cg_btot[n])
				printf("cg[%d].cg_btot[%d] have %d calc %d\n",
				    c, n, cgrp.cg_btot[n], botot[n]);
			offsumbad++;
E 4
I 4
		if (frags != d) {
I 9
#ifdef tahoe
			/* tahoe compiler workaround */
			int x = frags - dbase;
			blk = blkmap(&sblock, newcg->cg_free, x);
#else
E 9
			blk = blkmap(&sblock, newcg->cg_free, (frags - dbase));
I 9
#endif
E 9
			fragacct(&sblock, blk, newcg->cg_frsum, 1);
E 4
		}
E 10
D 4
		if (bcmp((char *)cgrp.cg_b, (char *)bo, sizeof (bo))) {
			if (debug)
			for (i = 0; i < NRPOS; i++)
				if (bo[n][i] != cgrp.cg_b[n][i])
				printf("cg[%d].cg_b[%d][%d] have %d calc %d\n",
				    c, n, i, cgrp.cg_b[n][i], bo[n][i]);
			offsumbad++;
E 4
I 4
		cstotal.cs_nffree += newcg->cg_cs.cs_nffree;
		cstotal.cs_nbfree += newcg->cg_cs.cs_nbfree;
		cstotal.cs_nifree += newcg->cg_cs.cs_nifree;
		cstotal.cs_ndir += newcg->cg_cs.cs_ndir;
D 10
		if (bcmp(newcg->cg_iused, cgrp.cg_iused, mapsize) != 0 &&
		    dofix(&idesc, "BLK(S) MISSING IN BIT MAPS")) {
			bcopy(newcg->cg_iused, cgrp.cg_iused, mapsize);
			cgdirty();
E 4
		}
D 4
	}
out5:
	if (dupblk)
		pwarn("%d DUP BLKS IN BIT MAPS\n", dupblk);
	if (fixcg == 0) {
		if ((b = n_blks+n_ffree+sblock.fs_frag*n_bfree+n_index+n_bad) != fmax) {
			pwarn("%ld BLK(S) MISSING\n", fmax - b);
			fixcg = 1;
		} else if (inosumbad + offsumbad + frsumbad + sbsumbad) {
			pwarn("SUMMARY INFORMATION %s%s%s%sBAD\n",
			    inosumbad ? "(INODE FREE) " : "",
			    offsumbad ? "(BLOCK OFFSETS) " : "",
			    frsumbad ? "(FRAG SUMMARIES) " : "",
			    sbsumbad ? "(SUPER BLOCK SUMMARIES) " : "");
			fixcg = 1;
		} else if (n_ffree != sblock.fs_cstotal.cs_nffree ||
		    n_bfree != sblock.fs_cstotal.cs_nbfree) {
			pwarn("FREE BLK COUNT(S) WRONG IN SUPERBLK");
			if (preen)
				printf(" (FIXED)\n");
			if (preen || reply("FIX") == 1) {
				sblock.fs_cstotal.cs_nffree = n_ffree;
				sblock.fs_cstotal.cs_nbfree = n_bfree;
				sbdirty();
			}
E 4
I 4
		if (bcmp((char *)newcg, (char *)&cgrp, sumsize) != 0 &&
		    dofix(&idesc, "SUMMARY INFORMATION BAD")) {
			bcopy((char *)newcg, (char *)&cgrp, sumsize);
			cgdirty();
E 4
		}
E 10
D 4
	}
	if (fixcg) {
		pwarn("BAD CYLINDER GROUPS");
		if (preen)
			printf(" (SALVAGED)\n");
		else if (reply("SALVAGE") == 0)
			fixcg = 0;
	}
}

pass5check(blk, size)
	daddr_t blk;
	long size;
{

	if (outrange(blk, (int)size)) {
		fixcg = 1;
		if (preen)
			pfatal("BAD BLOCKS IN BIT MAPS.");
		if (++badblk >= MAXBAD) {
			printf("EXCESSIVE BAD BLKS IN BIT MAPS.");
			if (reply("CONTINUE") == 0)
				errexit("");
			return (STOP);
E 4
I 4
D 11
		cs = &sblock.fs_cs(&sblock, c);
E 11
I 11
		cs = &fs->fs_cs(fs, c);
E 11
		if (bcmp((char *)&newcg->cg_cs, (char *)cs, sizeof *cs) != 0 &&
		    dofix(&idesc, "FREE BLK COUNT(S) WRONG IN SUPERBLK")) {
			bcopy((char *)&newcg->cg_cs, (char *)cs, sizeof *cs);
			sbdirty();
E 4
		}
I 10
		if (cvtflag) {
D 11
			bcopy((char *)newcg, (char *)&cgrp, sblock.fs_cgsize);
E 11
I 11
			bcopy((char *)newcg, (char *)cg, fs->fs_cgsize);
E 11
			cgdirty();
			continue;
		}
		if (bcmp(cg_inosused(newcg),
D 11
			 cg_inosused(&cgrp), mapsize) != 0 &&
E 11
I 11
			 cg_inosused(cg), mapsize) != 0 &&
E 11
		    dofix(&idesc, "BLK(S) MISSING IN BIT MAPS")) {
D 11
			bcopy(cg_inosused(newcg), cg_inosused(&cgrp), mapsize);
E 11
I 11
			bcopy(cg_inosused(newcg), cg_inosused(cg), mapsize);
E 11
			cgdirty();
		}
D 11
		if ((bcmp((char *)newcg, (char *)&cgrp, basesize) != 0 ||
E 11
I 11
		if ((bcmp((char *)newcg, (char *)cg, basesize) != 0 ||
E 11
		     bcmp((char *)&cg_blktot(newcg)[0],
D 11
			  (char *)&cg_blktot(&cgrp)[0], sumsize) != 0) &&
E 11
I 11
			  (char *)&cg_blktot(cg)[0], sumsize) != 0) &&
E 11
		    dofix(&idesc, "SUMMARY INFORMATION BAD")) {
D 11
			bcopy((char *)newcg, (char *)&cgrp, basesize);
E 11
I 11
			bcopy((char *)newcg, (char *)cg, basesize);
E 11
			bcopy((char *)&cg_blktot(newcg)[0],
D 11
			      (char *)&cg_blktot(&cgrp)[0], sumsize);
E 11
I 11
			      (char *)&cg_blktot(cg)[0], sumsize);
E 11
			cgdirty();
		}
E 10
	}
I 10
D 11
	if (sblock.fs_postblformat == FS_42POSTBLFMT)
		sblock.fs_nrpos = savednrpos;
E 10
D 4
	for (; size > 0; blk++, size--)
		if (getfmap(blk)) {
			fixcg = 1;
			++dupblk;
		} else {
			n_ffree++;
			setfmap(blk);
		}
	return (KEEPON);
E 4
I 4
	if (bcmp((char *)&cstotal, (char *)&sblock.fs_cstotal, sizeof *cs) != 0
E 11
I 11
	if (fs->fs_postblformat == FS_42POSTBLFMT)
		fs->fs_nrpos = savednrpos;
	if (bcmp((char *)&cstotal, (char *)&fs->fs_cstotal, sizeof *cs) != 0
E 11
	    && dofix(&idesc, "FREE BLK COUNT(S) WRONG IN SUPERBLK")) {
D 11
		bcopy((char *)&cstotal, (char *)&sblock.fs_cstotal, sizeof *cs);
		sblock.fs_ronly = 0;
		sblock.fs_fmod = 0;
E 11
I 11
		bcopy((char *)&cstotal, (char *)&fs->fs_cstotal, sizeof *cs);
		fs->fs_ronly = 0;
		fs->fs_fmod = 0;
E 11
		sbdirty();
	}
E 4
}
E 1
