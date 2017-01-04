h11930
s 00051/00029/00537
d D 5.4 88/05/07 01:04:12 mckusick 16 15
c expand from three static buffer to a dynamic buffer pool;
c initial sizing of the buffer pool is 128K (For 8K fs == 16 buffers)
e
s 00009/00013/00557
d D 5.3 87/01/07 19:26:38 mckusick 15 14
c be more persistent in trying to read directories; 
c add FOUND return status for routines called from dirscan
e
s 00001/00001/00569
d D 5.2 86/11/24 20:54:40 mckusick 14 13
c get the right name
e
s 00008/00002/00562
d D 5.1 85/06/05 08:54:24 dist 13 12
c Add copyright
e
s 00026/00010/00538
d D 3.11 85/05/31 19:06:21 mckusick 12 10
c check for improper directory offsets; recover gracefully from read errors
e
s 00023/00008/00540
d R 3.11 85/05/31 00:19:14 mckusick 11 10
c check for improper directory offsets; recover gracefully from read errors
e
s 00007/00004/00541
d D 3.10 85/02/15 15:22:53 mckusick 10 9
c insure that entire directory block is checked;
c when making entries, upsize directory as needed
e
s 00024/00019/00521
d D 3.9 85/02/15 12:42:27 mckusick 9 8
c restructure function of makeentry()
e
s 00000/00006/00540
d D 3.8 85/02/15 12:06:40 mckusick 8 7
c filesize now set by ckinode(); pass1() uses id_entryno to calc block count
e
s 00037/00011/00509
d D 3.7 85/02/13 19:07:30 mckusick 7 6
c reallocate lost+found if it is not a directory
e
s 00092/00006/00428
d D 3.6 85/02/13 18:22:33 mckusick 6 5
c create lost+found directory if none already in existence
e
s 00071/00003/00363
d D 3.5 85/02/11 20:55:26 mckusick 5 4
c expand lost+found when running out of space
e
s 00020/00017/00346
d D 3.4 85/02/11 18:29:08 mckusick 4 3
c ginode() succeeds or exits
e
s 00006/00005/00357
d D 3.3 85/02/08 19:14:55 mckusick 3 2
c merge passes 5 and 6 into a single pass
e
s 00009/00009/00353
d D 3.2 85/02/07 17:51:26 mckusick 2 1
c code reorganization and cleanup
e
s 00362/00000/00000
d D 3.1 84/03/31 21:03:39 mckusick 1 0
c date and time created 84/03/31 21:03:39 by mckusick
e
u
U
t
T
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 13
I 1
#ifndef lint
D 13
static char version[] = "%W% (Berkeley) %G%";
#endif
E 13
I 13
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 13

#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#define KERNEL
#include <sys/dir.h>
#undef KERNEL
#include "fsck.h"

#define MINDIRSIZE	(sizeof (struct dirtemplate))

char	*endpathname = &pathname[BUFSIZ - 2];
char	*lfname = "lost+found";
I 5
struct	dirtemplate emptydir = { 0, DIRBLKSIZ };
I 6
struct	dirtemplate dirhead = { 0, 12, 1, ".", 0, DIRBLKSIZ - 12, 2, ".." };
E 6
E 5

DIRECT	*fsck_readdir();
I 16
BUFAREA	*getdirblk();
E 16

descend(parentino, inumber)
	struct inodesc *parentino;
	ino_t inumber;
{
	register DINODE *dp;
	struct inodesc curino;

	bzero((char *)&curino, sizeof(struct inodesc));
D 3
	statemap[inumber] = FSTATE;
E 3
I 3
	if (statemap[inumber] != DSTATE)
		errexit("BAD INODE %d TO DESCEND", statemap[inumber]);
	statemap[inumber] = DFOUND;
E 3
D 4
	if ((dp = ginode(inumber)) == NULL)
		return;
E 4
I 4
	dp = ginode(inumber);
E 4
	if (dp->di_size == 0) {
		direrr(inumber, "ZERO LENGTH DIRECTORY");
		if (reply("REMOVE") == 1)
D 3
			statemap[inumber] = CLEAR;
E 3
I 3
			statemap[inumber] = DCLEAR;
E 3
		return;
	}
	if (dp->di_size < MINDIRSIZE) {
		direrr(inumber, "DIRECTORY TOO SHORT");
		dp->di_size = MINDIRSIZE;
		if (reply("FIX") == 1)
			inodirty();
	}
I 12
	if ((dp->di_size & (DIRBLKSIZ - 1)) != 0) {
		pwarn("DIRECTORY %s: LENGTH %d NOT MULTIPLE OF %d",
			pathname, dp->di_size, DIRBLKSIZ);
		dp->di_size = roundup(dp->di_size, DIRBLKSIZ);
		if (preen)
			printf(" (ADJUSTED)\n");
		if (preen || reply("ADJUST") == 1)
			inodirty();
	}
E 12
	curino.id_type = DATA;
	curino.id_func = parentino->id_func;
	curino.id_parent = parentino->id_number;
	curino.id_number = inumber;
D 8
	curino.id_filesize = dp->di_size;
E 8
	(void)ckinode(dp, &curino);
I 15
	if (curino.id_entryno < 2) {
		direrr(inumber, "NULL DIRECTORY");
		if (reply("REMOVE") == 1)
			statemap[inumber] = DCLEAR;
	}
E 15
}

dirscan(idesc)
	register struct inodesc *idesc;
{
	register DIRECT *dp;
I 16
	register BUFAREA *bp;
E 16
	int dsize, n;
	long blksiz;
	char dbuf[DIRBLKSIZ];

	if (idesc->id_type != DATA)
		errexit("wrong type to dirscan %d\n", idesc->id_type);
I 10
	if (idesc->id_entryno == 0 &&
	    (idesc->id_filesize & (DIRBLKSIZ - 1)) != 0)
		idesc->id_filesize = roundup(idesc->id_filesize, DIRBLKSIZ);
E 10
	blksiz = idesc->id_numfrags * sblock.fs_fsize;
	if (outrange(idesc->id_blkno, idesc->id_numfrags)) {
		idesc->id_filesize -= blksiz;
		return (SKIP);
	}
	idesc->id_loc = 0;
	for (dp = fsck_readdir(idesc); dp != NULL; dp = fsck_readdir(idesc)) {
		dsize = dp->d_reclen;
		bcopy((char *)dp, dbuf, dsize);
		idesc->id_dirp = (DIRECT *)dbuf;
		if ((n = (*idesc->id_func)(idesc)) & ALTERED) {
D 12
			if (getblk(&fileblk, idesc->id_blkno, blksiz) != NULL) {
E 12
I 12
D 16
			getblk(&fileblk, idesc->id_blkno, blksiz);
E 16
I 16
			bp = getdirblk(idesc->id_blkno, blksiz);
E 16
D 15
			if (fileblk.b_errs != NULL) {
				n &= ~ALTERED;
			} else {
E 12
				bcopy(dbuf, (char *)dp, dsize);
				dirty(&fileblk);
				sbdirty();
D 12
			} else
				n &= ~ALTERED;
E 12
I 12
			}
E 15
I 15
			bcopy(dbuf, (char *)dp, dsize);
D 16
			dirty(&fileblk);
E 16
I 16
			dirty(bp);
E 16
			sbdirty();
E 15
E 12
		}
		if (n & STOP) 
			return (n);
	}
	return (idesc->id_filesize > 0 ? KEEPON : STOP);
}

/*
 * get next entry in a directory.
 */
DIRECT *
fsck_readdir(idesc)
	register struct inodesc *idesc;
{
	register DIRECT *dp, *ndp;
I 16
	register BUFAREA *bp;
E 16
	long size, blksiz;

	blksiz = idesc->id_numfrags * sblock.fs_fsize;
D 12
	if (getblk(&fileblk, idesc->id_blkno, blksiz) == NULL) {
E 12
I 12
D 16
	getblk(&fileblk, idesc->id_blkno, blksiz);
E 16
I 16
	bp = getdirblk(idesc->id_blkno, blksiz);
E 16
D 15
	if (fileblk.b_errs != NULL) {
E 12
		idesc->id_filesize -= blksiz - idesc->id_loc;
		return NULL;
	}
E 15
	if (idesc->id_loc % DIRBLKSIZ == 0 && idesc->id_filesize > 0 &&
	    idesc->id_loc < blksiz) {
D 16
		dp = (DIRECT *)(dirblk.b_buf + idesc->id_loc);
E 16
I 16
		dp = (DIRECT *)(bp->b_un.b_buf + idesc->id_loc);
E 16
		if (dircheck(idesc, dp))
			goto dpok;
		idesc->id_loc += DIRBLKSIZ;
		idesc->id_filesize -= DIRBLKSIZ;
		dp->d_reclen = DIRBLKSIZ;
		dp->d_ino = 0;
		dp->d_namlen = 0;
		dp->d_name[0] = '\0';
D 2
		if (dofix(idesc))
E 2
I 2
		if (dofix(idesc, "DIRECTORY CORRUPTED"))
E 2
D 16
			dirty(&fileblk);
E 16
I 16
			dirty(bp);
E 16
		return (dp);
	}
dpok:
	if (idesc->id_filesize <= 0 || idesc->id_loc >= blksiz)
		return NULL;
D 16
	dp = (DIRECT *)(dirblk.b_buf + idesc->id_loc);
E 16
I 16
	dp = (DIRECT *)(bp->b_un.b_buf + idesc->id_loc);
E 16
	idesc->id_loc += dp->d_reclen;
	idesc->id_filesize -= dp->d_reclen;
	if ((idesc->id_loc % DIRBLKSIZ) == 0)
		return (dp);
D 16
	ndp = (DIRECT *)(dirblk.b_buf + idesc->id_loc);
E 16
I 16
	ndp = (DIRECT *)(bp->b_un.b_buf + idesc->id_loc);
E 16
	if (idesc->id_loc < blksiz && idesc->id_filesize > 0 &&
	    dircheck(idesc, ndp) == 0) {
		size = DIRBLKSIZ - (idesc->id_loc % DIRBLKSIZ);
		dp->d_reclen += size;
		idesc->id_loc += size;
		idesc->id_filesize -= size;
D 2
		if (dofix(idesc))
E 2
I 2
		if (dofix(idesc, "DIRECTORY CORRUPTED"))
E 2
D 16
			dirty(&fileblk);
E 16
I 16
			dirty(bp);
E 16
	}
	return (dp);
}

/*
 * Verify that a directory entry is valid.
 * This is a superset of the checks made in the kernel.
 */
dircheck(idesc, dp)
	struct inodesc *idesc;
	register DIRECT *dp;
{
	register int size;
	register char *cp;
	int spaceleft;

	size = DIRSIZ(dp);
	spaceleft = DIRBLKSIZ - (idesc->id_loc % DIRBLKSIZ);
	if (dp->d_ino < imax &&
	    dp->d_reclen != 0 &&
	    dp->d_reclen <= spaceleft &&
	    (dp->d_reclen & 0x3) == 0 &&
	    dp->d_reclen >= size &&
	    idesc->id_filesize >= size &&
	    dp->d_namlen <= MAXNAMLEN) {
		if (dp->d_ino == 0)
			return (1);
		for (cp = dp->d_name, size = 0; size < dp->d_namlen; size++)
			if (*cp == 0 || (*cp++ & 0200))
				return (0);
		if (*cp == 0)
			return (1);
	}
	return (0);
}

direrr(ino, s)
	ino_t ino;
	char *s;
{
	register DINODE *dp;

	pwarn("%s ", s);
	pinode(ino);
	printf("\n");
D 4
	if ((dp = ginode(ino)) != NULL && ftypeok(dp))
E 4
I 4
	if (ino < ROOTINO || ino > imax) {
		pfatal("NAME=%s\n", pathname);
		return;
	}
	dp = ginode(ino);
	if (ftypeok(dp))
E 4
D 2
		pfatal("%s=%s\n", DIRCT?"DIR":"FILE", pathname);
E 2
I 2
		pfatal("%s=%s\n", DIRCT(dp) ? "DIR" : "FILE", pathname);
E 2
	else
		pfatal("NAME=%s\n", pathname);
}

adjust(idesc, lcnt)
	register struct inodesc *idesc;
	short lcnt;
{
	register DINODE *dp;

D 4
	if ((dp = ginode(idesc->id_number)) == NULL)
		return;
E 4
I 4
	dp = ginode(idesc->id_number);
E 4
	if (dp->di_nlink == lcnt) {
		if (linkup(idesc->id_number, (ino_t)0) == 0)
			clri(idesc, "UNREF", 0);
D 3
	}
	else {
E 3
I 3
	} else {
E 3
D 2
		pwarn("LINK COUNT %s",
			(lfdir==idesc->id_number)?lfname:(DIRCT?"DIR":"FILE"));
E 2
I 2
		pwarn("LINK COUNT %s", (lfdir == idesc->id_number) ? lfname :
			(DIRCT(dp) ? "DIR" : "FILE"));
E 2
		pinode(idesc->id_number);
		printf(" COUNT %d SHOULD BE %d",
			dp->di_nlink, dp->di_nlink-lcnt);
		if (preen) {
			if (lcnt < 0) {
				printf("\n");
D 2
				preendie();
E 2
I 2
				pfatal("LINK COUNT INCREASING");
E 2
			}
			printf(" (ADJUSTED)\n");
		}
		if (preen || reply("ADJUST") == 1) {
			dp->di_nlink -= lcnt;
			inodirty();
		}
	}
}

mkentry(idesc)
	struct inodesc *idesc;
{
	register DIRECT *dirp = idesc->id_dirp;
	DIRECT newent;
	int newlen, oldlen;

	newent.d_namlen = 11;
	newlen = DIRSIZ(&newent);
	if (dirp->d_ino != 0)
		oldlen = DIRSIZ(dirp);
	else
		oldlen = 0;
	if (dirp->d_reclen - oldlen < newlen)
		return (KEEPON);
	newent.d_reclen = dirp->d_reclen - oldlen;
	dirp->d_reclen = oldlen;
	dirp = (struct direct *)(((char *)dirp) + oldlen);
	dirp->d_ino = idesc->id_parent;	/* ino to be entered is in id_parent */
	dirp->d_reclen = newent.d_reclen;
D 6
	dirp->d_namlen = lftempname(dirp->d_name, idesc->id_parent);
E 6
I 6
	dirp->d_namlen = strlen(idesc->id_name);
	bcopy(idesc->id_name, dirp->d_name, dirp->d_namlen + 1);
E 6
	return (ALTERED|STOP);
}

D 7
chgdd(idesc)
E 7
I 7
chgino(idesc)
E 7
	struct inodesc *idesc;
{
	register DIRECT *dirp = idesc->id_dirp;

D 7
	if (dirp->d_name[0] == '.' && dirp->d_name[1] == '.' &&
	dirp->d_name[2] == 0) {
		dirp->d_ino = lfdir;
		return (ALTERED|STOP);
	}
	return (KEEPON);
E 7
I 7
	if (bcmp(dirp->d_name, idesc->id_name, dirp->d_namlen + 1))
		return (KEEPON);
	dirp->d_ino = idesc->id_parent;;
	return (ALTERED|STOP);
E 7
}

linkup(orphan, pdir)
	ino_t orphan;
	ino_t pdir;
{
	register DINODE *dp;
	int lostdir, len;
I 6
	ino_t oldlfdir;
E 6
	struct inodesc idesc;
I 6
	char tempname[BUFSIZ];
I 7
	extern int pass4check();
E 7
E 6

	bzero((char *)&idesc, sizeof(struct inodesc));
D 4
	if ((dp = ginode(orphan)) == NULL)
		return (0);
E 4
I 4
	dp = ginode(orphan);
E 4
D 2
	lostdir = DIRCT;
E 2
I 2
	lostdir = DIRCT(dp);
E 2
	pwarn("UNREF %s ", lostdir ? "DIR" : "FILE");
	pinode(orphan);
	if (preen && dp->di_size == 0)
		return (0);
	if (preen)
		printf(" (RECONNECTED)\n");
	else
		if (reply("RECONNECT") == 0)
			return (0);
	pathp = pathname;
	*pathp++ = '/';
	*pathp = '\0';
	if (lfdir == 0) {
D 4
		if ((dp = ginode(ROOTINO)) == NULL)
			return (0);
E 4
I 4
		dp = ginode(ROOTINO);
E 4
D 2
		srchname = lfname;
E 2
I 2
		idesc.id_name = lfname;
E 2
		idesc.id_type = DATA;
		idesc.id_func = findino;
		idesc.id_number = ROOTINO;
D 8
		idesc.id_filesize = dp->di_size;
E 8
D 15
		(void)ckinode(dp, &idesc);
D 4
		if ((lfdir = idesc.id_parent) == 0) {
E 4
I 4
D 6
		lfdir = idesc.id_parent;
		if (lfdir < ROOTINO || lfdir > imax)
			lfdir = 0;
E 6
I 6
		if (idesc.id_parent >= ROOTINO && idesc.id_parent < imax) {
E 15
I 15
		if ((ckinode(dp, &idesc) & FOUND) != 0) {
E 15
			lfdir = idesc.id_parent;
		} else {
			pwarn("NO lost+found DIRECTORY");
			if (preen || reply("CREATE")) {
D 9
				idesc.id_func = mkentry;
				idesc.id_parent = allocdir(ROOTINO, 0);
D 8
				idesc.id_filesize = dp->di_size;
E 8
				if (idesc.id_parent != 0) {
					if (makeentry(dp, &idesc) != 0) {
						lfdir = idesc.id_parent;
E 9
I 9
				lfdir = allocdir(ROOTINO, 0);
				if (lfdir != 0) {
					if (makeentry(ROOTINO, lfdir, lfname) != 0) {
E 9
						if (preen)
							printf(" (CREATED)\n");
					} else {
D 9
						freedir(idesc.id_parent, ROOTINO);
E 9
I 9
						freedir(lfdir, ROOTINO);
						lfdir = 0;
E 9
						if (preen)
							printf("\n");
					}
				}
			}
		}
E 6
		if (lfdir == 0) {
E 4
D 6
			pfatal("SORRY. NO lost+found DIRECTORY");
E 6
I 6
			pfatal("SORRY. CANNOT CREATE lost+found DIRECTORY");
E 6
			printf("\n\n");
			return (0);
		}
	}
D 4
	if ((dp = ginode(lfdir)) == NULL ||
D 2
	     !DIRCT || statemap[lfdir] != FSTATE) {
E 2
I 2
D 3
	     !DIRCT(dp) || statemap[lfdir] != FSTATE) {
E 3
I 3
	     !DIRCT(dp) || statemap[lfdir] != DFOUND) {
E 4
I 4
	dp = ginode(lfdir);
D 7
	if (!DIRCT(dp) || statemap[lfdir] != DFOUND) {
E 4
E 3
E 2
		pfatal("SORRY. NO lost+found DIRECTORY");
		printf("\n\n");
E 7
I 7
	if (!DIRCT(dp)) {
		pfatal("lost+found IS NOT A DIRECTORY");
		if (reply("REALLOCATE") == 0)
			return (0);
		oldlfdir = lfdir;
		if ((lfdir = allocdir(ROOTINO, 0)) == 0) {
			pfatal("SORRY. CANNOT CREATE lost+found DIRECTORY\n\n");
			return (0);
		}
		idesc.id_type = DATA;
		idesc.id_func = chgino;
		idesc.id_number = ROOTINO;
		idesc.id_parent = lfdir;	/* new inumber for lost+found */
		idesc.id_name = lfname;
		if ((ckinode(ginode(ROOTINO), &idesc) & ALTERED) == 0) {
			pfatal("SORRY. CANNOT CREATE lost+found DIRECTORY\n\n");
			return (0);
		}
		inodirty();
		idesc.id_type = ADDR;
		idesc.id_func = pass4check;
		idesc.id_number = oldlfdir;
		adjust(&idesc, lncntp[oldlfdir] + 1);
		lncntp[oldlfdir] = 0;
		dp = ginode(lfdir);
	}
	if (statemap[lfdir] != DFOUND) {
		pfatal("SORRY. NO lost+found DIRECTORY\n\n");
E 7
		return (0);
	}
D 5
	if (fragoff(&sblock, dp->di_size)) {
		dp->di_size = fragroundup(&sblock, dp->di_size);
E 5
I 5
D 10
	if (dp->di_size % DIRBLKSIZ) {
		dp->di_size = roundup(dp->di_size, DIRBLKSIZ);
E 5
		inodirty();
	}
E 10
	len = strlen(lfname);
	bcopy(lfname, pathp, len + 1);
	pathp += len;
D 9
	idesc.id_type = DATA;
	idesc.id_func = mkentry;
	idesc.id_number = lfdir;
D 8
	idesc.id_filesize = dp->di_size;
E 8
	idesc.id_parent = orphan;	/* this is the inode to enter */
	idesc.id_fix = DONTKNOW;
I 6
	idesc.id_name = tempname;
	len = lftempname(idesc.id_name, orphan);
E 6
D 5
	if ((ckinode(dp, &idesc) & ALTERED) == 0) {
E 5
I 5
	if (makeentry(dp, &idesc) == 0) {
E 9
I 9
	len = lftempname(tempname, orphan);
	if (makeentry(lfdir, orphan, tempname) == 0) {
E 9
E 5
		pfatal("SORRY. NO SPACE IN lost+found DIRECTORY");
		printf("\n\n");
		return (0);
	}
	lncntp[orphan]--;
	*pathp++ = '/';
D 6
	pathp += lftempname(pathp, orphan);
E 6
I 6
D 14
	bcopy(idesc.id_name, pathp, len + 1);
E 14
I 14
	bcopy(tempname, pathp, len + 1);
E 14
	pathp += len;
E 6
	if (lostdir) {
		dp = ginode(orphan);
		idesc.id_type = DATA;
D 7
		idesc.id_func = chgdd;
E 7
I 7
		idesc.id_func = chgino;
E 7
		idesc.id_number = orphan;
D 8
		idesc.id_filesize = dp->di_size;
E 8
		idesc.id_fix = DONTKNOW;
I 7
		idesc.id_name = "..";
		idesc.id_parent = lfdir;	/* new value for ".." */
E 7
		(void)ckinode(dp, &idesc);
D 4
		if ((dp = ginode(lfdir)) != NULL) {
			dp->di_nlink++;
			inodirty();
			lncntp[lfdir]++;
		}
E 4
I 4
		dp = ginode(lfdir);
		dp->di_nlink++;
		inodirty();
		lncntp[lfdir]++;
E 4
		pwarn("DIR I=%u CONNECTED. ", orphan);
		printf("PARENT WAS I=%u\n", pdir);
		if (preen == 0)
			printf("\n");
	}
	return (1);
I 5
}

/*
 * make an entry in a directory
 */
D 9
makeentry(dp, idesc)
	DINODE *dp;
	struct inodesc *idesc;
E 9
I 9
makeentry(parent, ino, name)
	ino_t parent, ino;
	char *name;
E 9
{
I 9
	DINODE *dp;
	struct inodesc idesc;
E 9
	
D 9
	if ((ckinode(dp, idesc) & ALTERED) != 0)
E 9
I 9
	if (parent < ROOTINO || parent >= imax || ino < ROOTINO || ino >= imax)
		return (0);
	bzero(&idesc, sizeof(struct inodesc));
	idesc.id_type = DATA;
	idesc.id_func = mkentry;
	idesc.id_number = parent;
	idesc.id_parent = ino;	/* this is the inode to enter */
	idesc.id_fix = DONTKNOW;
	idesc.id_name = name;
	dp = ginode(parent);
I 10
	if (dp->di_size % DIRBLKSIZ) {
		dp->di_size = roundup(dp->di_size, DIRBLKSIZ);
		inodirty();
	}
E 10
	if ((ckinode(dp, &idesc) & ALTERED) != 0)
E 9
		return (1);
	if (expanddir(dp) == 0)
		return (0);
D 8
	idesc->id_filesize = dp->di_size;
E 8
D 9
	return (ckinode(dp, idesc) & ALTERED);
E 9
I 9
	return (ckinode(dp, &idesc) & ALTERED);
E 9
}

/*
 * Attempt to expand the size of a directory
 */
expanddir(dp)
	register DINODE *dp;
{
	daddr_t lastbn, newblk;
I 16
	register BUFAREA *bp;
E 16
	char *cp, firstblk[DIRBLKSIZ];

	lastbn = lblkno(&sblock, dp->di_size);
	if (lastbn >= NDADDR - 1)
		return (0);
	if ((newblk = allocblk(sblock.fs_frag)) == 0)
		return (0);
	dp->di_db[lastbn + 1] = dp->di_db[lastbn];
	dp->di_db[lastbn] = newblk;
	dp->di_size += sblock.fs_bsize;
	dp->di_blocks += btodb(sblock.fs_bsize);
D 12
	if (getblk(&fileblk, dp->di_db[lastbn + 1],
	    dblksize(&sblock, dp, lastbn + 1)) == NULL)
E 12
I 12
D 16
	getblk(&fileblk, dp->di_db[lastbn + 1],
	    dblksize(&sblock, dp, lastbn + 1));
	if (fileblk.b_errs != NULL)
E 16
I 16
	bp = getdirblk(dp->di_db[lastbn + 1],
		dblksize(&sblock, dp, lastbn + 1));
	if (bp->b_errs != NULL)
E 16
E 12
		goto bad;
D 16
	bcopy(dirblk.b_buf, firstblk, DIRBLKSIZ);
D 12
	if (getblk(&fileblk, newblk, sblock.fs_bsize) == NULL)
E 12
I 12
	getblk(&fileblk, newblk, sblock.fs_bsize);
	if (fileblk.b_errs != NULL)
E 16
I 16
	bcopy(bp->b_un.b_buf, firstblk, DIRBLKSIZ);
	bp = getdirblk(newblk, sblock.fs_bsize);
	if (bp->b_errs != NULL)
E 16
E 12
		goto bad;
D 16
	bcopy(firstblk, dirblk.b_buf, DIRBLKSIZ);
	for (cp = &dirblk.b_buf[DIRBLKSIZ];
	     cp < &dirblk.b_buf[sblock.fs_bsize];
E 16
I 16
	bcopy(firstblk, bp->b_un.b_buf, DIRBLKSIZ);
	for (cp = &bp->b_un.b_buf[DIRBLKSIZ];
	     cp < &bp->b_un.b_buf[sblock.fs_bsize];
E 16
	     cp += DIRBLKSIZ)
		bcopy((char *)&emptydir, cp, sizeof emptydir);
D 16
	dirty(&fileblk);
D 12
	if (getblk(&fileblk, dp->di_db[lastbn + 1],
	    dblksize(&sblock, dp, lastbn + 1)) == NULL)
E 12
I 12
	getblk(&fileblk, dp->di_db[lastbn + 1],
	    dblksize(&sblock, dp, lastbn + 1));
	if (fileblk.b_errs != NULL)
E 16
I 16
	dirty(bp);
	bp = getdirblk(dp->di_db[lastbn + 1],
		dblksize(&sblock, dp, lastbn + 1));
	if (bp->b_errs != NULL)
E 16
E 12
		goto bad;
D 16
	bcopy((char *)&emptydir, dirblk.b_buf, sizeof emptydir);
E 16
I 16
	bcopy((char *)&emptydir, bp->b_un.b_buf, sizeof emptydir);
E 16
	pwarn("NO SPACE LEFT IN %s", pathname);
	if (preen)
		printf(" (EXPANDED)\n");
	else if (reply("EXPAND") == 0)
		goto bad;
D 16
	dirty(&fileblk);
E 16
I 16
	dirty(bp);
E 16
	inodirty();
	return (1);
bad:
	dp->di_db[lastbn] = dp->di_db[lastbn + 1];
	dp->di_db[lastbn + 1] = 0;
	dp->di_size -= sblock.fs_bsize;
	dp->di_blocks -= btodb(sblock.fs_bsize);
	freeblk(newblk, sblock.fs_frag);
	return (0);
I 6
}

/*
 * allocate a new directory
 */
allocdir(parent, request)
	ino_t parent, request;
{
	ino_t ino;
	char *cp;
	DINODE *dp;
I 16
	register BUFAREA *bp;
E 16

	ino = allocino(request, IFDIR|0755);
	dirhead.dot_ino = ino;
	dirhead.dotdot_ino = parent;
	dp = ginode(ino);
D 12
	if (getblk(&fileblk, dp->di_db[0], sblock.fs_fsize) == NULL) {
E 12
I 12
D 16
	getblk(&fileblk, dp->di_db[0], sblock.fs_fsize);
	if (fileblk.b_errs != NULL) {
E 16
I 16
	bp = getdirblk(dp->di_db[0], sblock.fs_fsize);
	if (bp->b_errs != NULL) {
E 16
E 12
		freeino(ino);
		return (0);
	}
D 16
	bcopy((char *)&dirhead, dirblk.b_buf, sizeof dirhead);
	for (cp = &dirblk.b_buf[DIRBLKSIZ];
	     cp < &dirblk.b_buf[sblock.fs_fsize];
E 16
I 16
	bcopy((char *)&dirhead, bp->b_un.b_buf, sizeof dirhead);
	for (cp = &bp->b_un.b_buf[DIRBLKSIZ];
	     cp < &bp->b_un.b_buf[sblock.fs_fsize];
E 16
	     cp += DIRBLKSIZ)
		bcopy((char *)&emptydir, cp, sizeof emptydir);
D 16
	dirty(&fileblk);
E 16
I 16
	dirty(bp);
E 16
	dp->di_nlink = 2;
	inodirty();
	if (ino == ROOTINO) {
		lncntp[ino] = dp->di_nlink;
		return(ino);
	}
	if (statemap[parent] != DSTATE && statemap[parent] != DFOUND) {
		freeino(ino);
		return (0);
	}
	statemap[ino] = statemap[parent];
	if (statemap[ino] == DSTATE) {
		lncntp[ino] = dp->di_nlink;
		lncntp[parent]++;
	}
	dp = ginode(parent);
	dp->di_nlink++;
	inodirty();
	return (ino);
}

/*
 * free a directory inode
 */
freedir(ino, parent)
	ino_t ino, parent;
{
	DINODE *dp;

	if (ino != parent) {
		dp = ginode(parent);
		dp->di_nlink--;
		inodirty();
	}
	freeino(ino);
E 6
E 5
}

/*
 * generate a temporary name for the lost+found directory.
 */
lftempname(bufp, ino)
	char *bufp;
	ino_t ino;
{
	register ino_t in;
	register char *cp;
	int namlen;

	cp = bufp + 2;
	for (in = imax; in > 0; in /= 10)
		cp++;
	*--cp = 0;
	namlen = cp - bufp;
	in = ino;
	while (cp > bufp) {
		*--cp = (in % 10) + '0';
		in /= 10;
	}
	*cp = '#';
	return (namlen);
I 16
}

/*
 * Get a directory block.
 * Insure that it is held until another is requested.
 */
BUFAREA *
getdirblk(blkno, size)
	daddr_t blkno;
	long size;
{
	static BUFAREA *pbp = 0;

	if (pbp != 0)
		pbp->b_flags &= ~B_INUSE;
	pbp = getdatablk(blkno, size);
	return (pbp);
E 16
}
E 1
