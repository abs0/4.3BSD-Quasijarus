h31858
s 00001/00001/00762
d D 5.4 88/05/22 17:29:59 mckusick 24 23
c change verbose info to debug info
e
s 00002/00001/00761
d D 5.3 87/06/18 10:15:16 mckusick 23 22
c provide more info on the missing file name
e
s 00011/00001/00751
d D 5.2 86/03/05 22:44:58 mckusick 22 21
c handle case with directory entry, but no inode on tape
e
s 00008/00004/00744
d D 5.1 85/05/28 15:14:27 dist 21 20
c Add copyright
e
s 00002/00002/00746
d D 3.20 85/02/18 18:29:10 mckusick 20 19
c do not set owner and times on directories that already exist ('i' and 'x' only)
e
s 00002/00000/00746
d D 3.19 84/03/22 19:23:16 mckusick 19 18
c must skip maps when file spans two volumes
e
s 00002/00002/00744
d D 3.18 83/12/30 00:39:33 mckusick 18 17
c lint
e
s 00002/00002/00744
d D 3.17 83/08/11 23:05:57 sam 17 16
c standardize sccs keyword lines
e
s 00018/00001/00728
d D 3.16 83/05/15 03:24:05 mckusick 16 15
c have to check old directories for unreferenced names too
e
s 00055/00024/00674
d D 3.15 83/05/15 00:25:58 mckusick 15 14
c fix bugs dealing with handling of links
e
s 00016/00016/00682
d D 3.14 83/05/14 16:47:43 mckusick 14 13
c after making a name into a tempname, treat file as NEW instead of EXTRACT
e
s 00002/00004/00696
d D 3.13 83/05/03 23:30:49 mckusick 13 12
c missing parameter to dprintf; remove ! when testing BIT against zero
e
s 00036/00015/00664
d D 3.12 83/04/19 02:12:13 mckusick 12 11
c add and debug interactive extraction mode
e
s 00011/00001/00668
d D 3.11 83/04/16 13:04:43 mckusick 11 10
c only try to make links when they are truely new
e
s 00006/00002/00663
d D 3.10 83/04/16 12:39:28 mckusick 10 9
c make extra files on the tape non-fatal
c they occur when active file systems are dumped
e
s 00042/00024/00623
d D 3.9 83/04/11 18:09:16 mckusick 9 8
c generalize the printing of flags
e
s 00218/00079/00429
d D 3.8 83/03/27 18:31:52 mckusick 8 7
c pass pruning argument back to treescan; lint; comments;
c discard hard links to directories
e
s 00054/00028/00454
d D 3.7 83/03/08 13:38:18 mckusick 7 6
c get 'r' and 'R' commands working
e
s 00081/00190/00401
d D 3.6 83/01/16 06:03:44 mckusick 6 5
c new incremental restore algorithm
e
s 00038/00009/00553
d D 3.5 83/03/05 16:18:42 mckusick 5 4
c fix debugging across tapes; account for dumpmap at start of every tape
e
s 00026/00009/00536
d D 3.4 83/02/28 00:38:37 mckusick 4 3
c get "h" and "m" flags working; clean up interface with getvol()
e
s 00002/00002/00543
d D 3.3 83/02/27 16:30:52 mckusick 3 2
c get input from a pipe to work
e
s 00009/00001/00536
d D 3.2 83/02/27 14:39:36 mckusick 2 1
c get "x" command working
e
s 00537/00000/00000
d D 3.1 83/02/18 00:41:38 mckusick 1 0
c date and time created 83/02/18 00:41:38 by mckusick
e
u
U
t
T
I 1
D 17
/* Copyright (c) 1983 Regents of the University of California */

E 17
D 21
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%E%";
#endif
E 21
I 21
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 21
I 17

D 21
/* Copyright (c) 1983 Regents of the University of California */
E 21
I 21
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 21
E 17

#include "restore.h"

I 6
D 8
static struct entry *removelist;	/* list of nodes to be deleted */

E 8
E 6
/*
D 7
 *	Mark entries to be removed.
E 7
I 7
D 8
 *	Remove unneeded leaves from the old tree.
 *	Remove directories from the lookup chains.
E 8
I 8
 * This implements the 't' option.
 * List entries on the tape.
E 8
E 7
 */
D 6
markremove()
E 6
I 6
D 8
removeoldleaves()
E 6
{
	register struct entry *ep;
D 6
	register int i;
E 6
I 6
	register ino_t i;
E 6

	vprintf(stdout, "Mark entries to be removed.\n");
D 7
	for (i = ROOTINO; i < maxino; i++) {
E 7
I 7
	for (i = ROOTINO + 1; i < maxino; i++) {
E 7
		ep = lookupino(i);
		if (ep == NIL)
			continue;
D 7
		if (BIT(i, clrimap)) {
			for ( ; ep != NIL; ep = ep->e_links) {
D 6
				ep->e_flags |= REMOVE;
E 6
				dprintf(stdout, "%s: REMOVE\n", myname(ep));
I 6
				if (ep->e_type == LEAF) {
					removeleaf(ep);
					freeentry(ep);
				} else {
					mktempname(ep);
					deleteino(ep->e_ino);
					ep->e_next = removelist;
					removelist = ep;
				}
E 7
I 7
		if (BIT(i, clrimap))
			continue;
		for ( ; ep != NIL; ep = ep->e_links) {
			dprintf(stdout, "%s: REMOVE\n", myname(ep));
			if (ep->e_type == LEAF) {
				removeleaf(ep);
				freeentry(ep);
			} else {
				mktempname(ep);
				deleteino(ep->e_ino);
				ep->e_next = removelist;
				removelist = ep;
E 7
E 6
			}
		}
	}
}

/*
 *	List entries on the tape.
 */
void
E 8
I 8
long
E 8
listfile(name, ino, type)
	char *name;
	ino_t ino;
	int type;
{
I 8
	long descend = hflag ? GOOD : FAIL;
E 8

	if (BIT(ino, dumpmap) == 0) {
D 8
		return;
E 8
I 8
		return (descend);
E 8
	}
D 7
	vprintf(stdout, "%s\t", type == LEAF ? "leaf" : "dir");
E 7
I 7
	vprintf(stdout, "%s", type == LEAF ? "leaf" : "dir ");
E 7
	fprintf(stdout, "%10d\t%s\n", ino, name);
I 8
	return (descend);
E 8
}

/*
D 8
 *	Request that new entries be extracted.
E 8
I 8
 * This implements the 'x' option.
 * Request that new entries be extracted.
E 8
 */
D 8
void
E 8
I 8
long
E 8
addfile(name, ino, type)
	char *name;
	ino_t ino;
	int type;
{
	register struct entry *ep;
I 8
	long descend = hflag ? GOOD : FAIL;
E 8
	char buf[100];

	if (BIT(ino, dumpmap) == 0) {
D 24
		vprintf(stdout, "%s: not on the tape\n", name);
E 24
I 24
		dprintf(stdout, "%s: not on the tape\n", name);
E 24
D 8
		return;
E 8
I 8
		return (descend);
E 8
	}
D 4
	if (mflag) {
I 2
		if (ino == ROOTINO)
E 4
I 4
	if (!mflag) {
D 8
		sprintf(buf, "./%u", ino);
E 8
I 8
		(void) sprintf(buf, "./%u", ino);
E 8
		name = buf;
		if (type == NODE) {
D 6
			genliteraldir(name, ino);
E 6
I 6
			(void) genliteraldir(name, ino);
E 6
E 4
D 8
			return;
E 8
I 8
			return (descend);
E 8
D 4
		ep = lookupino(ino);
		if (ep != NIL)
			type |= LINK;
E 2
		ep = addentry(name, ino, type);
	} else {
		(void) sprintf(buf, "./%u", ino);
		ep = addentry(buf, ino, type);
E 4
I 4
		}
E 4
	}
I 4
D 13
	if (ino == ROOTINO)
D 8
		return;
E 8
I 8
		return (descend);
E 13
E 8
	ep = lookupino(ino);
	if (ep != NIL) {
D 12
		if (strcmp(name, myname(ep)) == 0)
E 12
I 12
		if (strcmp(name, myname(ep)) == 0) {
			ep->e_flags |= NEW;
E 12
D 8
			return;
E 8
I 8
			return (descend);
I 12
		}
E 12
E 8
		type |= LINK;
	}
	ep = addentry(name, ino, type);
D 12
	if (type == NODE) {
E 12
I 12
	if (type == NODE)
E 12
		newnode(ep);
I 12
	ep->e_flags |= NEW;
	return (descend);
}

/*
 * This is used by the 'i' option to undo previous requests made by addfile.
 * Delete entries from the request queue.
 */
/* ARGSUSED */
long
deletefile(name, ino, type)
	char *name;
	ino_t ino;
	int type;
{
	long descend = hflag ? GOOD : FAIL;
	struct entry *ep;

	if (BIT(ino, dumpmap) == 0) {
E 12
D 8
		return;
E 8
I 8
		return (descend);
E 8
	}
E 4
D 12
	ep->e_flags |= NEW;
E 12
I 12
	ep = lookupino(ino);
	if (ep != NIL)
		ep->e_flags &= ~NEW;
E 12
I 4
D 8
	return;
E 8
I 8
	return (descend);
E 8
E 4
}

I 8
/* 
 * The following four routines implement the incremental
 * restore algorithm. The first removes old entries, the second
 * does renames and calculates the extraction list, the third
 * cleans up link names missed by the first two, and the final
 * one deletes old directories.
 *
 * Directories cannot be immediately deleted, as they may have
 * other files in them which need to be moved out first. As
 * directories to be deleted are found, they are put on the 
 * following deletion list. After all deletions and renames
 * are done, this list is actually deleted.
 */
static struct entry *removelist;

E 8
/*
I 8
 *	Remove unneeded leaves from the old tree.
 *	Remove directories from the lookup chains.
 */
removeoldleaves()
{
	register struct entry *ep;
	register ino_t i;

	vprintf(stdout, "Mark entries to be removed.\n");
	for (i = ROOTINO + 1; i < maxino; i++) {
		ep = lookupino(i);
		if (ep == NIL)
			continue;
		if (BIT(i, clrimap))
			continue;
		for ( ; ep != NIL; ep = ep->e_links) {
			dprintf(stdout, "%s: REMOVE\n", myname(ep));
			if (ep->e_type == LEAF) {
				removeleaf(ep);
				freeentry(ep);
			} else {
				mktempname(ep);
				deleteino(ep->e_ino);
				ep->e_next = removelist;
				removelist = ep;
			}
		}
	}
}

/*
E 8
D 5
 *	For each directory entry, determine which catagory it falls
E 5
I 5
D 6
 *	For each directory entry, determine which category it falls
E 5
 *	into as follows:
E 6
I 6
 *	For each directory entry on the incremental tape, determine which
 *	category it falls into as follows:
E 6
 *	KEEP - entries that are to be left alone.
 *	NEW - new entries to be added.
D 6
 *	RENAME - entries whose name is to be changed.
E 6
 *	EXTRACT - files that must be updated with new contents.
D 6
 *	CHANGE - REMOVE followed by EXTRACT.
 *	RENUMBER - same as CHANGE, but not reusing same inode number.
E 6
I 6
 *	LINK - new links to be added.
 *	Renames are done at the same time.
E 6
 */
D 8
void
E 8
I 8
long
E 8
D 6
markfile(name, ino, type)
E 6
I 6
nodeupdates(name, ino, type)
E 6
	char *name;
	ino_t ino;
	int type;
{
	register struct entry *ep, *np, *ip;
I 8
	long descend = GOOD;
I 15
	int lookuptype = 0;
E 15
E 8
	int key = 0;
		/* key values */
D 8
#		define ONTAPE	0x1
#		define INOFND	0x2
#		define NAMEFND	0x4
#		define MODECHG	0x8
E 8
I 8
#		define ONTAPE	0x1	/* inode is on the tape */
#		define INOFND	0x2	/* inode already exists */
#		define NAMEFND	0x4	/* name already exists */
#		define MODECHG	0x8	/* mode of inode changed */
E 8
D 9
	char keybuf[32], *keyval = &keybuf[1];
E 9
I 9
	extern char *keyval();
E 9

	/*
	 * This routine is called once for each element in the 
D 5
	 * directory heirarchy, with a full path name.
E 5
I 5
	 * directory hierarchy, with a full path name.
E 5
	 * The "type" value is incorrectly specified as LEAF for
	 * directories that are not on the dump tape.
I 15
	 *
	 * Check to see if the file is on the tape.
E 15
	 */
D 9
	strcpy(keybuf, "|NIL");
	keybuf[0] = '\0';
	if (BIT(ino, dumpmap)) {
E 9
I 9
	if (BIT(ino, dumpmap))
E 9
		key |= ONTAPE;
I 15
	/*
	 * Check to see if the name exists, and if the name is a link.
	 */
E 15
D 9
		strcat(keybuf, "|ONTAPE");
	}
E 9
	np = lookupname(name);
D 15
	if (np != NIL)
E 15
I 15
	if (np != NIL) {
E 15
		key |= NAMEFND;
I 15
		ip = lookupino(np->e_ino);
		if (ip == NULL)
			panic("corrupted symbol table\n");
		if (ip != np)
			lookuptype = LINK;
	}
	/*
	 * Check to see if the inode exists, and if one of its links
	 * corresponds to the name (if one was found).
	 */
E 15
	ip = lookupino(ino);
	if (ip != NIL) {
		key |= INOFND;
D 9
		strcat(keybuf, "|INOFND");
E 9
D 15
		for (ep = ip; ep != NIL; ep = ep->e_links)
E 15
I 15
		for (ep = ip->e_links; ep != NIL; ep = ep->e_links) {
E 15
			if (ep == np) {
				ip = ep;
				break;
			}
I 15
		}
E 15
	}
I 8
	/*
D 15
	 * If both a name and an inode are found, but they do
	 * not correspond to the same file, then both the inode
	 * which has been found and the inode corresponding to
	 * the name which has been found need to be renamed.
	 * The current pathname is the new name for the inode
	 * which has been found. Since all files to be
	 * deleted have already been removed, the file found by
	 * name must live under a new name in this dump level.
	 * For the time being it is given a temporary name in anticipation
	 * that it will be renamed when it is later found by inode number.
E 15
I 15
	 * If both a name and an inode are found, but they do not
	 * correspond to the same file, then both the inode that has
	 * been found and the inode corresponding to the name that
	 * has been found need to be renamed. The current pathname
	 * is the new name for the inode that has been found. Since
	 * all files to be deleted have already been removed, the
	 * named file is either a now unneeded link, or it must live
	 * under a new name in this dump level. If it is a link, it
	 * can be removed. If it is not a link, it is given a
	 * temporary name in anticipation that it will be renamed
	 * when it is later found by inode number.
E 15
	 */
E 8
D 7
	if ((key & (INOFND|NAMEFND) == (INOFND|NAMEFND)) && ip != np) {
E 7
I 7
	if (((key & (INOFND|NAMEFND)) == (INOFND|NAMEFND)) && ip != np) {
I 8
D 15
		dprintf(stdout, "name/inode conflict, mktempname %s\n",
			myname(np));
E 8
E 7
D 6
		if ((np->e_flags & REMOVE) == 0)
			panic("%s: not on remove list\n", name);
E 6
I 6
		mktempname(np);
E 15
I 15
		if (lookuptype == LINK) {
			removeleaf(np);
			freeentry(np);
		} else {
			dprintf(stdout, "name/inode conflict, mktempname %s\n",
				myname(np));
			mktempname(np);
		}
E 15
D 8
		dprintf(stdout, "[%s] %s: mktempname\n", keyval, name);
E 8
E 6
		np = NIL;
		key &= ~NAMEFND;
	}
D 9
	if (key & NAMEFND)
		strcat(keybuf, "|NAMEFND");
E 9
	if ((key & ONTAPE) &&
	  (((key & INOFND) && ip->e_type != type) ||
D 9
	   ((key & NAMEFND) && np->e_type != type))) {
E 9
I 9
	   ((key & NAMEFND) && np->e_type != type)))
E 9
		key |= MODECHG;
D 6
		strcat(keybuf, "|MODECHG");
E 6
I 6
D 9
		(void) strcat(keybuf, "|MODECHG");
E 6
	}
E 9
I 8

	/*
	 * Decide on the disposition of the file based on its flags.
	 * Note that we have already handled the case in which
	 * a name and inode are found that correspond to different files.
	 * Thus if both NAMEFND and INOFND are set then ip == np.
	 */
E 8
	switch (key) {

I 8
	/*
	 * A previously existing file has been found.
	 * Mark it as KEEP so that other links to the inode can be
	 * detected, and so that it will not be reclaimed by the search
	 * for unreferenced names.
	 */
E 8
	case INOFND|NAMEFND:
D 6
		if (ip->e_flags & RENAME) {
			ip->e_flags &= ~RENAME;
			ep = addentry(ip->e_newname, ip->e_ino,
			    ip->e_type|LINK);
			dprintf(stdout, "[%s] %s: RENAME become LINK\n", keyval,
			    ip->e_newname);
			np->e_flags |= NEW;
			free(ip->e_newname);
			ip->e_newname = NULL;
		}
E 6
		ip->e_flags |= KEEP;
D 9
		dprintf(stdout, "[%s] %s: KEEP\n", keyval, name);
E 9
I 9
		dprintf(stdout, "[%s] %s: %s\n", keyval(key), name,
			flagvalues(ip));
E 9
		break;

I 8
	/*
I 14
	 * A file on the tape has a name which is the same as a name
	 * corresponding to a different file in the previous dump.
	 * Since all files to be deleted have already been removed,
D 15
	 * this file must live under a new name in this dump level.
	 * For the time being it is given a temporary name in anticipation
	 * that it will be renamed when it is later found by inode number
	 * (see INOFND case below). The entry is then treated as a new
	 * file.
E 15
I 15
	 * this file is either a now unneeded link, or it must live
	 * under a new name in this dump level. If it is a link, it
	 * can simply be removed. If it is not a link, it is given a
	 * temporary name in anticipation that it will be renamed
	 * when it is later found by inode number (see INOFND case
	 * below). The entry is then treated as a new file.
E 15
	 */
	case ONTAPE|NAMEFND:
	case ONTAPE|NAMEFND|MODECHG:
D 15
		mktempname(np);
E 15
I 15
		if (lookuptype == LINK) {
			removeleaf(np);
			freeentry(np);
		} else {
			mktempname(np);
		}
E 15
		/* fall through */

	/*
E 14
	 * A previously non-existent file.
	 * Add it to the file system, and request its extraction.
	 * If it is a directory, create it immediately.
	 * (Since the name is unused there can be no conflict)
	 */
E 8
	case ONTAPE:
		ep = addentry(name, ino, type);
D 6
		ep->e_flags |= NEW;
		dprintf(stdout, "[%s] %s: NEW\n", keyval, name);
E 6
I 6
		if (type == NODE)
			newnode(ep);
D 12
		else
			ep->e_flags |= NEW;
		ep->e_flags |= KEEP;
E 12
I 12
		ep->e_flags |= NEW|KEEP;
E 12
D 9
		dprintf(stdout, "[%s] %s: KEEP|NEW\n", keyval, name);
E 9
I 9
		dprintf(stdout, "[%s] %s: %s\n", keyval(key), name,
			flagvalues(ep));
E 9
E 6
		break;

I 8
	/*
	 * A file with the same inode number, but a different
	 * name has been found. If the other name has not already
	 * been found (indicated by the KEEP flag, see above) then
	 * this must be a new name for the file, and it is renamed.
	 * If the other name has been found then this must be a
	 * link to the file. Hard links to directories are not
	 * permitted, and are either deleted or converted to
	 * symbolic links. Finally, if the file is on the tape,
	 * a request is made to extract it.
	 */
E 8
	case ONTAPE|INOFND:
D 6
		ip->e_flags |= EXTRACT;
E 6
I 6
D 8
		if (type == LEAF)
E 8
I 8
D 9
		if (type == LEAF && (ip->e_flags & KEEP) == 0) {
E 9
I 9
		if (type == LEAF && (ip->e_flags & KEEP) == 0)
E 9
E 8
			ip->e_flags |= EXTRACT;
E 6
D 8
		dprintf(stdout, "[%s] %s: EXTRACT\n", keyval, name);
E 8
I 8
D 9
			dprintf(stdout, "[%s] %s: EXTRACT\n", keyval, name);
		}
E 9
E 8
		/* fall through */
	case INOFND:
D 6
		if (ip->e_flags & (KEEP|NEW|EXTRACT)) {
			ep = addentry(name, ip->e_ino, ip->e_type|LINK);
E 6
I 6
D 8
		if (ip->e_flags & KEEP) {
			if (ip->e_type == NODE)
				panic("%s linked to directory %s\n",
				    name, myname(ip));
			ep = addentry(name, ino, type|LINK);
E 6
			ep->e_flags |= NEW;
D 7
			dprintf(stdout, "[%s] %s: NEW\n", keyval, name);
E 7
I 7
			dprintf(stdout, "[%s] %s: LINK\n", keyval, name);
E 8
I 8
		if ((ip->e_flags & KEEP) == 0) {
			renameit(myname(ip), name);
			moveentry(ip, name);
			ip->e_flags |= KEEP;
D 9
			dprintf(stdout, "[%s] %s: RENAME\n", keyval, name);
E 9
I 9
D 13
			dprintf(stdout, "[%s] %s: %s\n", keyval(key),
E 13
I 13
			dprintf(stdout, "[%s] %s: %s\n", keyval(key), name,
E 13
				flagvalues(ip));
E 9
E 8
E 7
			break;
		}
D 6
		ip->e_newname = savename(name);
		ip->e_flags |= RENAME;
E 6
I 6
D 8
		renameit(myname(ip), name);
		moveentry(ip, name);
		ip->e_flags |= KEEP;
E 6
		dprintf(stdout, "[%s] %s: RENAME\n", keyval, name);
E 8
I 8
		if (ip->e_type == NODE) {
			descend = FAIL;
			fprintf(stderr,
				"deleted hard link %s to directory %s\n",
				name, myname(ip));
			break;
		}
		ep = addentry(name, ino, type|LINK);
		ep->e_flags |= NEW;
D 9
		dprintf(stdout, "[%s] %s: LINK\n", keyval, name);
E 9
I 9
		dprintf(stdout, "[%s] %s: %s|LINK\n", keyval(key), name,
			flagvalues(ep));
E 9
E 8
		break;

I 8
	/*
D 14
	 * A file on the tape has a name which is the same as a name
	 * corresponding to a different file in the previous dump.
	 * Since all files to be deleted have already been removed,
	 * this file must live under a new name in this dump level.
	 * For the time being it is given a temporary name in anticipation
	 * that it will be renamed when it is later found by inode number
	 * (see INOFND case above).
	 * This then falls into the simple case of a previously known
	 * file which is to be updated.
E 14
I 14
	 * A previously known file which is to be updated.
E 14
	 */
E 8
D 14
	case ONTAPE|NAMEFND:
D 6
		if ((np->e_flags & REMOVE) == 0)
			panic("[%s] %s: not on remove list\n", keyval, name);
		renumber(np, ino);
E 6
I 6
	case ONTAPE|NAMEFND|MODECHG:
		mktempname(np);
		np = addentry(name, ino, type);
		if (type == NODE)
			newnode(np);
E 6
		/* fall through */
E 14
	case ONTAPE|INOFND|NAMEFND:
D 6
		np->e_flags |= EXTRACT;
		dprintf(stdout, "[%s] %s: EXTRACT\n", keyval, name);
E 6
I 6
D 15
		if (type == LEAF)
E 15
I 15
		if (type == LEAF && lookuptype != LINK)
E 15
			np->e_flags |= EXTRACT;
		np->e_flags |= KEEP;
D 9
		dprintf(stdout, "[%s] %s: KEEP|EXTRACT\n", keyval, name);
E 9
I 9
		dprintf(stdout, "[%s] %s: %s\n", keyval(key), name,
			flagvalues(np));
E 9
E 6
		break;

I 8
	/*
	 * An inode is being reused in a completely different way.
	 * Normally an extract can simply do an "unlink" followed
	 * by a "creat". Here we must do effectively the same
	 * thing. The complications arise because we cannot really
	 * delete a directory since it may still contain files
	 * that we need to rename, so we delete it from the symbol
	 * table, and put it on the list to be deleted eventually.
	 * Conversely if a directory is to be created, it must be
	 * done immediately, rather than waiting until the 
	 * extraction phase.
	 */
E 8
D 6
	case ONTAPE|NAMEFND|MODECHG:
		renumber(np, ino);
		ip = np;
		/* fall through */
E 6
	case ONTAPE|INOFND|MODECHG:
	case ONTAPE|INOFND|NAMEFND|MODECHG:
D 6
		if ((ip->e_flags & REMOVE) == 0)
			panic("[%s] %s: not on remove list\n", keyval, name);
		ip->e_flags |= CHANGE;
		dprintf(stdout, "[%s] %s: CHANGE\n", keyval, name);
E 6
I 6
D 7
		badentry(ip, "not removed");
E 7
I 7
		if (ip->e_flags & KEEP) {
			badentry(ip, "cannot KEEP and change modes");
			break;
		}
		if (ip->e_type == LEAF) {
			/* changing from leaf to node */
			removeleaf(ip);
			freeentry(ip);
			ip = addentry(name, ino, type);
			newnode(ip);
		} else {
			/* changing from node to leaf */
D 16
			mktempname(ip);
E 16
I 16
			if ((ip->e_flags & TMPNAME) == 0)
				mktempname(ip);
E 16
			deleteino(ip->e_ino);
			ip->e_next = removelist;
			removelist = ip;
			ip = addentry(name, ino, type);
D 12
			ip->e_flags |= NEW;
E 12
		}
D 12
		ip->e_flags |= KEEP;
E 12
I 12
		ip->e_flags |= NEW|KEEP;
E 12
D 9
		dprintf(stdout, "[%s] %s: KEEP|NEW\n", keyval, name);
E 9
I 9
		dprintf(stdout, "[%s] %s: %s\n", keyval(key), name,
			flagvalues(ip));
E 9
E 7
E 6
		break;

I 8
	/*
	 * A hard link to a diirectory that has been removed.
	 * Ignore it.
	 */
	case NAMEFND:
D 9
		dprintf(stdout, "[%s] %s: Extraneous name\n", keyval, name);
E 9
I 9
		dprintf(stdout, "[%s] %s: Extraneous name\n", keyval(key),
			name);
E 9
		descend = FAIL;
		break;

	/*
I 22
	 * If we find a directory entry for a file that is not on
	 * the tape, then we must have found a file that was created
	 * while the dump was in progress. Since we have no contents
	 * for it, we discard the name knowing that it will be on the
	 * next incremental tape.
	 */
	case NIL:
D 23
		fprintf(stderr, "%s: not found on tape\n", name);
E 23
I 23
		fprintf(stderr, "%s: (inode %d) not found on tape\n",
			name, ino);
E 23
		break;

	/*
E 22
	 * If any of these arise, something is grievously wrong with
	 * the current state of the symbol table.
	 */
E 8
	case INOFND|NAMEFND|MODECHG:
	case NAMEFND|MODECHG:
	case INOFND|MODECHG:
D 8
	case NAMEFND:
E 8
D 22
	case NIL:
E 22
D 9
		panic("[%s] %s: inconsistent state\n", keyval, name);
E 9
I 9
		panic("[%s] %s: inconsistent state\n", keyval(key), name);
E 9
		break;

I 8
	/*
	 * These states "cannot" arise for any state of the symbol table.
	 */
E 8
	case ONTAPE|MODECHG:
	case MODECHG:
	default:
D 9
		panic("[%s] %s: impossible state\n", keyval, name);
E 9
I 9
		panic("[%s] %s: impossible state\n", keyval(key), name);
E 9
		break;
	}	
I 8
	return (descend);
I 9
}

/*
 * Calculate the active flags in a key.
 */
char *
keyval(key)
	int key;
{
	static char keybuf[32];

D 12
	strcpy(keybuf, "|NIL");
E 12
I 12
	(void) strcpy(keybuf, "|NIL");
E 12
	keybuf[0] = '\0';
	if (key & ONTAPE)
		(void) strcat(keybuf, "|ONTAPE");
	if (key & INOFND)
		(void) strcat(keybuf, "|INOFND");
	if (key & NAMEFND)
		(void) strcat(keybuf, "|NAMEFND");
	if (key & MODECHG)
		(void) strcat(keybuf, "|MODECHG");
	return (&keybuf[1]);
E 9
E 8
}

/*
D 6
 *	Find unreferenced names.
E 6
I 6
D 8
 *	Find unreferenced link names.
E 8
I 8
 * Find unreferenced link names.
E 8
E 6
 */
D 6
findunref()
E 6
I 6
findunreflinks()
E 6
{
	register struct entry *ep, *np;
D 6
	register int i;
E 6
I 6
	register ino_t i;
E 6

	vprintf(stdout, "Find unreferenced names.\n");
	for (i = ROOTINO; i < maxino; i++) {
		ep = lookupino(i);
D 12
		if (ep == NIL || ep->e_type == LEAF || !BIT(i, dumpmap))
E 12
I 12
D 13
		if (ep == NIL || ep->e_type == LEAF || !BIT(i, dumpmap) == 0)
E 13
I 13
		if (ep == NIL || ep->e_type == LEAF || BIT(i, dumpmap) == 0)
E 13
E 12
			continue;
		for (np = ep->e_entries; np != NIL; np = np->e_sibling) {
			if (np->e_flags == 0) {
I 16
				dprintf(stdout,
				    "%s: remove unreferenced name\n",
				    myname(np));
				removeleaf(np);
				freeentry(np);
			}
		}
	}
	/*
	 * Any leaves remaining in removed directories is unreferenced.
	 */
	for (ep = removelist; ep != NIL; ep = ep->e_next) {
		for (np = ep->e_entries; np != NIL; np = np->e_sibling) {
			if (np->e_type == LEAF) {
				if (np->e_flags != 0)
					badentry(np, "unreferenced with flags");
E 16
D 6
				np->e_flags |= REMOVE;
				dprintf(stdout, "%s: REMOVE\n", myname(np));
E 6
I 6
				dprintf(stdout,
				    "%s: remove unreferenced name\n",
				    myname(np));
				removeleaf(np);
				freeentry(np);
E 6
			}
		}
	}
}

/*
D 6
 *	Remove old leaves.
E 6
I 6
D 8
 *	Remove old nodes (directories).
E 8
I 8
 * Remove old nodes (directories).
 * Note that this routine runs in O(N*D) where:
 *	N is the number of directory entries to be removed.
 *	D is the maximum depth of the tree.
 * If N == D this can be quite slow. If the list were
 * topologically sorted, the deletion could be done in
 * time O(N).
E 8
E 6
 */
D 6
removeleaves()
E 6
I 6
removeoldnodes()
E 6
{
D 7
	register struct entry *ep;
E 7
I 7
	register struct entry *ep, **prev;
E 7
D 6
	register int i;
E 6
I 6
	long change;
E 6

D 6
	vprintf(stdout, "Remove old leaves.\n");
	for (i = ROOTINO; i < maxino; i++) {
		for (ep = lookupino(i); ep != NIL; ep = ep->e_links) {
			if (ep->e_type != LEAF || (ep->e_flags & REMOVE) == 0)
				continue;
			removeleaf(ep);
			ep->e_flags &= ~REMOVE;
			if ((ep->e_flags & (CHANGE|EXTRACT)) == 0)
				freeentry(ep);
		}
	}
}
			
/*
 *	Rename nodes (directories).
 */
renamenodes()
{
	register struct entry *ep, *np, *pp;
	register int i;
	char oldname[MAXPATHLEN];

	vprintf(stdout, "Rename nodes (directories).\n");
	for (i = ROOTINO; i < maxino; i++) {
		np = lookupino(i);
		if (np == NIL || np->e_type != NODE ||
		    (np->e_flags & RENAME) == 0)
			continue;
		strcpy(oldname, myname(np));
		if (np->e_newname == NULL) {
			badentry(np, "no new name");
			continue;
		}
		np->e_flags &= ~RENAME;
		if (strcmp(oldname, np->e_newname) == 0)
			continue;
		ep = lookupname(np->e_newname);
		if (ep != NIL) {
			if (ep->e_flags & TMPNODE) {
				movecontents(ep, np);
E 6
I 6
	vprintf(stdout, "Remove old nodes (directories).\n");
	do	{
		change = 0;
D 7
		for (ep = removelist; ep != NIL; ep = ep->e_next) {
			if (ep->e_entries == NIL) {
				dprintf(stdout, "%s: removed\n", myname(ep));
E 6
				removenode(ep);
				freeentry(ep);
D 6
			} else {
				mktempname(ep);
E 6
I 6
				change++;
E 7
I 7
		prev = &removelist;
		for (ep = removelist; ep != NIL; ep = *prev) {
			if (ep->e_entries != NIL) {
				prev = &ep->e_next;
				continue;
E 7
E 6
			}
I 7
			*prev = ep->e_next;
			removenode(ep);
			freeentry(ep);
			change++;
E 7
D 6
		} else {
			pp = pathcheck(np->e_newname, TMPNODE);
			if (pp == np) {
				mktempname(np);
				strcpy(oldname, myname(np));
				pp = pathcheck(np->e_newname, TMPNODE);
				if (pp == np)
					badentry(np, "mktempname failed");
			}
E 6
		}
D 6
		renameit(oldname, np->e_newname);
		moveentry(np, np->e_newname);
	}
E 6
I 6
	} while (change);
	for (ep = removelist; ep != NIL; ep = ep->e_next)
		badentry(ep, "cannot remove, non-empty");
E 6
}

/*
D 6
 *	Create new nodes (directories).
 */
createnodes()
{
	register struct entry *ep;
	register int i;

	vprintf(stdout, "Create new nodes (directories).\n");
	for (i = ROOTINO; i < maxino; i++) {
		ep = lookupino(i);
		if (ep == NIL || ep->e_type == LEAF ||
		    ((ep->e_flags & (EXTRACT|CHANGE|NEW)) == 0))
			continue;
		if (ep->e_flags & (CHANGE|NEW)) {
			if (ep->e_flags & REMOVE)
				badentry(ep, "bad REMOVE flag");
			newnode(ep);
			ep->e_flags &= ~(CHANGE|NEW);
			continue;
		}
		if (ep->e_flags & REMOVE) {
			if (ep->e_flags & RENUMBER)
				ep->e_flags &= ~REMOVE;
			else
				badentry(ep, "REMOVE without RENUMBER flag");
			if (ep->e_flags & (TMPNODE|TMPNAME))
				badentry(ep, "creating TMPNODE or TMPNAME");
			ep->e_flags &= ~EXTRACT;
		}
	}
}

/*
 *	Rename leaves.
 */
renameleaves()
{
	register struct entry *ep, *np;
	register int i;

	vprintf(stdout, "Rename leaves.\n");
	for (i = ROOTINO; i < maxino; i++) {
		for (ep = lookupino(i); ep != NIL; ep = ep->e_links) {
			if ((ep->e_flags & RENAME) == 0)
				continue;
			if (ep->e_type == NODE)
				badentry(ep, "too late to RENAME directory");
			ep->e_flags &= ~RENAME;
			np = lookupname(ep->e_newname);
			if (np != NIL)
				mktempname(np);
			renameit(myname(ep), ep->e_newname);
			moveentry(ep, ep->e_newname);
		}
	}
}

/*
 *	Remove old nodes (directories).
 */
removenodes()
{
	register struct entry *ep;
	register int i;

	vprintf(stdout, "Remove old nodes (directories).\n");
	for (i = ROOTINO; i < maxino; i++) {
		ep = lookupino(i);
		if (ep == NIL || (ep->e_flags & REMOVE) == 0)
			continue;
		removenode(ep);
		ep->e_flags &= ~REMOVE;
		if ((ep->e_flags & (CHANGE|EXTRACT)) == 0)
			freeentry(ep);
	}
}

/*
E 6
D 8
 *	Extract new leaves.
E 8
I 8
 * This is the routine used to extract files for the 'r' command.
 * Extract new leaves.
E 8
 */
createleaves(symtabfile)
	char *symtabfile;
{
	register struct entry *ep;
	ino_t first;
	long curvol;

D 7
	if (command == 'R')
E 7
I 7
	if (command == 'R') {
E 7
		vprintf(stdout, "Continue extraction of new leaves\n");
D 7
	else
E 7
I 7
	} else {
E 7
		vprintf(stdout, "Extract new leaves.\n");
D 7
	dumpsymtable(symtabfile, volno);
E 7
I 7
		dumpsymtable(symtabfile, volno);
	}
E 7
	first = lowerbnd(ROOTINO);
	curvol = volno;
	while (curfile.ino < maxino) {
I 7
		first = lowerbnd(first);
I 8
		/*
		 * If the next available file is not the one which we
		 * expect then we have missed one or more files. Since
		 * we do not request files that were not on the tape,
D 11
		 * the lost files must have been due to a tape read error.
E 11
I 11
		 * the lost files must have been due to a tape read error,
		 * or a file that was removed while the dump was in progress.
E 11
		 */
E 8
E 7
		while (first < curfile.ino) {
			ep = lookupino(first);
			if (ep == NIL)
				panic("%d: bad first\n", first);
			fprintf(stderr, "%s: not found on tape\n", myname(ep));
D 6
			ep->e_flags &= ~(NEW|EXTRACT|CHANGE);
			first = lowerbnd(first + 1);
E 6
I 6
			ep->e_flags &= ~(NEW|EXTRACT);
			first = lowerbnd(first);
E 6
		}
I 11
		/*
		 * If we find files on the tape that have no corresponding
		 * directory entries, then we must have found a file that
		 * was created while the dump was in progress. Since we have 
		 * no name for it, we discard it knowing that it will be
		 * on the next incremental tape.
		 */
E 11
D 10
		if (first != curfile.ino)
			panic("expected next file %d, got %d\n",
E 10
I 10
		if (first != curfile.ino) {
			fprintf(stderr, "expected next file %d, got %d\n",
E 10
				first, curfile.ino);
I 10
			skipfile();
			goto next;
		}
E 10
		ep = lookupino(curfile.ino);
		if (ep == NIL)
			panic("unknown file on tape\n");
D 6
		if ((ep->e_flags & (NEW|EXTRACT|CHANGE)) == 0)
E 6
I 6
		if ((ep->e_flags & (NEW|EXTRACT)) == 0)
E 6
			badentry(ep, "unexpected file on tape");
I 8
		/*
		 * If the file is to be extracted, then the old file must
		 * be removed since its type may change from one leaf type
		 * to another (eg "file" to "character special").
		 */
E 8
D 6
		ep->e_flags &= ~(NEW|EXTRACT|CHANGE);
E 6
I 6
		if ((ep->e_flags & EXTRACT) != 0) {
			removeleaf(ep);
			ep->e_flags &= ~REMOVED;
		}
E 6
D 8
		extractfile(myname(ep));
E 8
I 8
		(void) extractfile(myname(ep));
E 8
I 6
		ep->e_flags &= ~(NEW|EXTRACT);
I 8
		/*
		 * We checkpoint the restore after every tape reel, so
		 * as to simplify the amount of work re quired by the
		 * 'R' command.
		 */
I 10
	next:
E 10
E 8
E 6
		if (curvol != volno) {
			dumpsymtable(symtabfile, volno);
I 6
			skipmaps();
E 6
			curvol = volno;
		}
	}
}

/*
D 8
 *	Efficiently extract a subset of the files on a tape
E 8
I 8
D 15
 * This is the routine used to extract files for the 'x' command.
 * Efficiently extract a subset of the files on a tape
E 15
I 15
 * This is the routine used to extract files for the 'x' and 'i' commands.
 * Efficiently extract a subset of the files on a tape.
E 15
E 8
 */
createfiles()
{
	register ino_t first, next, last;
	register struct entry *ep;
	long curvol;

	vprintf(stdout, "Extract requested files\n");
I 2
	curfile.action = SKIP;
D 3
	getvol((long)0);
E 3
I 3
	getvol((long)1);
I 5
	skipmaps();
	skipdirs();
E 5
E 3
E 2
	first = lowerbnd(ROOTINO);
D 2
	last = upperbnd(maxino);
E 2
I 2
	last = upperbnd(maxino - 1);
E 2
	for (;;) {
I 4
D 5
		skipmaps();
		skipdirs();
E 5
E 4
		first = lowerbnd(first);
		last = upperbnd(last);
I 5
		/*
		 * Check to see if any files remain to be extracted
		 */
E 5
		if (first > last)
			return;
I 5
		/*
		 * Reject any volumes with inodes greater
		 * than the last one needed
		 */
E 5
		while (curfile.ino > last) {
			curfile.action = SKIP;
			getvol((long)0);
I 4
D 5
			if (volno == 1) {
				skipmaps();
				skipdirs();
			}
E 5
I 5
			skipmaps();
			skipdirs();
E 5
E 4
		}
I 5
		/*
		 * Decide on the next inode needed.
		 * Skip across the inodes until it is found
		 * or an out of order volume change is encountered
		 */
E 5
		next = lowerbnd(curfile.ino);
		do	{
			curvol = volno;
			while (next > curfile.ino && volno == curvol)
				skipfile();
I 5
			skipmaps();
			skipdirs();
E 5
		} while (volno == curvol + 1);
I 5
		/*
		 * If volume change out of order occurred the
D 12
		 * current state must be re calculated
E 12
I 12
		 * current state must be recalculated
E 12
		 */
E 5
		if (volno != curvol)
			continue;
I 5
		/*
		 * If the current inode is greater than the one we were
		 * looking for then we missed the one we were looking for.
		 * Since we only attempt to extract files listed in the
D 12
		 * dump map, the file must have been lost due to a tape
		 * read error. Thus we report all requested files between
		 * the one we were looking for, and the one we found as
		 * missing, and delete their request flags.
E 12
I 12
		 * dump map, the lost files must have been due to a tape
		 * read error, or a file that was removed while the dump
		 * was in progress. Thus we report all requested files
		 * between the one we were looking for, and the one we
		 * found as missing, and delete their request flags.
E 12
		 */
E 5
		while (next < curfile.ino) {
			ep = lookupino(next);
			if (ep == NIL)
				panic("corrupted symbol table\n");
			fprintf(stderr, "%s: not found on tape\n", myname(ep));
			ep->e_flags &= ~NEW;
D 5
			next = lowerbnd(next + 1);
E 5
I 5
			next = lowerbnd(next);
E 5
		}
I 5
		/*
		 * The current inode is the one that we are looking for,
		 * so extract it per its requested name.
		 */
E 5
D 3
		if (next == curfile.ino) {
E 3
I 3
		if (next == curfile.ino && next <= last) {
E 3
			ep = lookupino(next);
			if (ep == NIL)
				panic("corrupted symbol table\n");
D 8
			extractfile(myname(ep));
E 8
I 8
			(void) extractfile(myname(ep));
E 8
			ep->e_flags &= ~NEW;
I 19
			if (volno != curvol)
				skipmaps();
E 19
		}
	}
}

/*
D 8
 *	Add links.
E 8
I 8
 * Add links.
E 8
 */
createlinks()
{
	register struct entry *np, *ep;
D 6
	register long i;
E 6
I 6
	register ino_t i;
E 6
	char name[BUFSIZ];

	vprintf(stdout, "Add links\n");
	for (i = ROOTINO; i < maxino; i++) {
		ep = lookupino(i);
		if (ep == NIL)
			continue;
		for (np = ep->e_links; np != NIL; np = np->e_links) {
I 11
			if ((np->e_flags & NEW) == 0)
				continue;
E 11
D 6
			strcpy(name, myname(ep));
E 6
I 6
			(void) strcpy(name, myname(ep));
E 6
			if (ep->e_type == NODE) {
D 8
				vprintf(stdout, "changing hard link to directory to a symbolic link:");
E 8
D 18
				linkit(name, myname(np), SYMLINK);
E 18
I 18
				(void) linkit(name, myname(np), SYMLINK);
E 18
			} else {
D 18
				linkit(name, myname(np), HARDLINK);
E 18
I 18
				(void) linkit(name, myname(np), HARDLINK);
E 18
			}
I 2
			np->e_flags &= ~NEW;
E 2
		}
	}
}

/*
D 8
 *	Check the symbol table.
E 8
I 8
 * Check the symbol table.
 * We do this to insure that all the requested work was done, and
 * that no temporary names remain.
E 8
 */
checkrestore()
{
	register struct entry *ep;
D 6
	register long i;
E 6
I 6
	register ino_t i;
E 6

	vprintf(stdout, "Check the symbol table.\n");
	for (i = ROOTINO; i < maxino; i++) {
D 20
		for (ep= lookupino(i); ep != NIL; ep = ep->e_links) {
E 20
I 20
		for (ep = lookupino(i); ep != NIL; ep = ep->e_links) {
E 20
			ep->e_flags &= ~KEEP;
I 15
			if (ep->e_type == NODE)
D 20
				ep->e_flags &= ~NEW;
E 20
I 20
				ep->e_flags &= ~(NEW|EXISTED);
E 20
E 15
			if (ep->e_flags != NULL)
				badentry(ep, "incomplete operations");
		}
	}
}

/*
D 8
 *	Compare with the directory structure on the tape
E 8
I 8
 * Compare with the directory structure on the tape
 * A paranoid check that things are as they should be.
E 8
 */
D 8
void
E 8
I 8
long
E 8
verifyfile(name, ino, type)
	char *name;
	ino_t ino;
	int type;
{
	struct entry *np, *ep;
I 8
	long descend = GOOD;
E 8

	ep = lookupname(name);
D 8
	if (ep == NIL)
		panic("missing name %s\n", name);
	for (np = lookupino(ino); np != NIL; np = np->e_links)
E 8
I 8
	if (ep == NIL) {
		fprintf(stderr, "Warning: missing name %s\n", name);
		return (FAIL);
	}
	np = lookupino(ino);
	if (np != ep)
		descend = FAIL;
	for ( ; np != NIL; np = np->e_links)
E 8
		if (np == ep)
			break;
	if (np == NIL)
		panic("missing inumber %d\n", ino);
	if (ep->e_type == LEAF && type != LEAF)
		badentry(ep, "type should be LEAF");
I 8
	return (descend);
E 8
}
E 1
