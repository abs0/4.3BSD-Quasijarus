h22689
s 00001/00001/00527
d D 5.4 87/09/04 17:38:39 mckusick 9 8
c cast sizeof operator to int so will work with ANSI C (4.3BSD/lib/91)
e
s 00002/00002/00526
d D 5.3 86/03/09 19:51:05 donn 8 7
c added LIBC_SCCS condition for sccs ids
e
s 00001/00000/00527
d D 5.2 85/06/19 12:16:38 mckusick 7 6
c must undef setbit from param.h as we define it as a local routine
e
s 00007/00001/00520
d D 5.1 85/05/30 10:46:07 dist 6 5
c Add copyright
e
s 00100/00157/00421
d D 4.4 84/09/05 15:34:05 ralph 5 3
c speedup changes
e
s 00101/00158/00420
d R 4.4 84/09/05 15:22:31 ralph 4 3
c speed up changes mostly, hash function changed.
e
s 00198/00165/00380
d D 4.3 84/08/28 14:08:56 ralph 3 2
c added write error checking, speed fixes, unify subroutine names.
e
s 00004/00004/00541
d D 4.2 83/12/20 10:16:09 ralph 2 1
c make replacement of items optional when using dbmstore().
e
s 00545/00000/00000
d D 4.1 83/12/02 17:14:58 ralph 1 0
c date and time created 83/12/02 17:14:58 by ralph
e
u
U
t
T
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 6
I 1
D 8
#ifndef lint
E 8
I 8
#if defined(LIBC_SCCS) && !defined(lint)
E 8
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif
E 6
I 6
D 8
#endif not lint
E 8
I 8
#endif LIBC_SCCS and not lint
E 8
E 6

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
I 3
#include <stdio.h>
E 3
#include <errno.h>
#include <ndbm.h>

D 3
#define NULL    (char *)0
E 3
#define BYTESIZ 8
I 7
#undef setbit
E 7

D 5
static  datum firsthash();
E 5
D 3
static  dbm_access();
static  getbit();
static  setbit();
E 3
static  datum makdatum();
D 3
static  cmpdatum();
E 3
static  long hashinc();
static  long dcalchash();
D 3
static  delitem();
static  additem();
static  chkblk();
E 3
extern  int errno;

DBM *
D 3
ndbmopen(file, flags, mode)
E 3
I 3
dbm_open(file, flags, mode)
E 3
	char *file;
	int flags, mode;
{
	struct stat statb;
	register DBM *db;

	if ((db = (DBM *)malloc(sizeof *db)) == 0) {
		errno = ENOMEM;
		return ((DBM *)0);
	}
I 3
	db->dbm_flags = (flags & 03) == O_RDONLY ? _DBM_RDONLY : 0;
E 3
	if ((flags & 03) == O_WRONLY)
		flags = (flags & ~03) | O_RDWR;
D 3
	db->db_flags = 0;
	strcpy(db->db_pagbuf, file);
	strcat(db->db_pagbuf, ".pag");
	db->db_pagf = open(db->db_pagbuf, flags, mode);
	if (db->db_pagf < 0)
E 3
I 3
	strcpy(db->dbm_pagbuf, file);
	strcat(db->dbm_pagbuf, ".pag");
	db->dbm_pagf = open(db->dbm_pagbuf, flags, mode);
	if (db->dbm_pagf < 0)
E 3
		goto bad;
D 3
	strcpy(db->db_pagbuf, file);
	strcat(db->db_pagbuf, ".dir");
	db->db_dirf = open(db->db_pagbuf, flags, mode);
	if (db->db_dirf < 0)
E 3
I 3
	strcpy(db->dbm_pagbuf, file);
	strcat(db->dbm_pagbuf, ".dir");
	db->dbm_dirf = open(db->dbm_pagbuf, flags, mode);
	if (db->dbm_dirf < 0)
E 3
		goto bad1;
D 3
	fstat(db->db_dirf, &statb);
	db->db_maxbno = statb.st_size*BYTESIZ-1;
	db->db_pagbno = db->db_dirbno = -1;
E 3
I 3
	fstat(db->dbm_dirf, &statb);
	db->dbm_maxbno = statb.st_size*BYTESIZ-1;
	db->dbm_pagbno = db->dbm_dirbno = -1;
E 3
	return (db);
bad1:
D 3
	(void) close(db->db_pagf);
E 3
I 3
	(void) close(db->dbm_pagf);
E 3
bad:
	free((char *)db);
	return ((DBM *)0);
}

void
D 3
ndbmclose(db)
E 3
I 3
dbm_close(db)
E 3
	DBM *db;
{

D 3
	(void) close(db->db_dirf);
	(void) close(db->db_pagf);
E 3
I 3
	(void) close(db->dbm_dirf);
	(void) close(db->dbm_pagf);
E 3
	free((char *)db);
}

long
D 3
dbmforder(db, key)
E 3
I 3
dbm_forder(db, key)
E 3
	register DBM *db;
	datum key;
{
	long hash;

	hash = dcalchash(key);
D 3
	for (db->db_hmask=0;; db->db_hmask=(db->db_hmask<<1)+1) {
		db->db_blkno = hash & db->db_hmask;
		db->db_bitno = db->db_blkno + db->db_hmask;
E 3
I 3
	for (db->dbm_hmask=0;; db->dbm_hmask=(db->dbm_hmask<<1)+1) {
		db->dbm_blkno = hash & db->dbm_hmask;
		db->dbm_bitno = db->dbm_blkno + db->dbm_hmask;
E 3
		if (getbit(db) == 0)
			break;
	}
D 3
	return (db->db_blkno);
E 3
I 3
	return (db->dbm_blkno);
E 3
}

datum
D 3
dbmfetch(db, key)
E 3
I 3
dbm_fetch(db, key)
E 3
	register DBM *db;
	datum key;
{
	register i;
	datum item;

I 3
	if (dbm_error(db))
		goto err;
E 3
	dbm_access(db, dcalchash(key));
I 3
D 5
	if (dbm_error(db))
		goto err;
E 3
	for (i=0;; i+=2) {
D 3
		item = makdatum(db->db_pagbuf, i);
E 3
I 3
		item = makdatum(db->dbm_pagbuf, i);
E 3
		if (item.dptr == NULL)
E 5
I 5
	if ((i = finddatum(db->dbm_pagbuf, key)) >= 0) {
		item = makdatum(db->dbm_pagbuf, i+1);
		if (item.dptr != NULL)
E 5
			return (item);
D 5
		if (cmpdatum(key, item) == 0) {
D 3
			item = makdatum(db->db_pagbuf, i+1);
E 3
I 3
			item = makdatum(db->dbm_pagbuf, i+1);
E 3
			if (item.dptr == NULL)
D 3
				printf("items not in pairs\n");
E 3
I 3
				fprintf(stderr, "dbm: items not in pairs\n");
E 3
			return (item);
		}
E 5
	}
I 3
err:
	item.dptr = NULL;
	item.dsize = 0;
	return (item);
E 3
}

D 3
dbmdelete(db, key)
E 3
I 3
dbm_delete(db, key)
E 3
	register DBM *db;
	datum key;
{
	register i;
	datum item;

D 3
	if (dbrdonly(db)) {
E 3
I 3
	if (dbm_error(db))
		return (-1);
	if (dbm_rdonly(db)) {
E 3
		errno = EPERM;
		return (-1);
	}
	dbm_access(db, dcalchash(key));
I 3
D 5
	if (dbm_error(db))
E 5
I 5
	if ((i = finddatum(db->dbm_pagbuf, key)) < 0)
E 5
		return (-1);
E 3
D 5
	for (i=0;; i+=2) {
D 3
		item = makdatum(db->db_pagbuf, i);
E 3
I 3
		item = makdatum(db->dbm_pagbuf, i);
E 3
		if (item.dptr == NULL)
			return (-1);
		if (cmpdatum(key, item) == 0) {
D 3
			delitem(db->db_pagbuf, i);
			delitem(db->db_pagbuf, i);
E 3
I 3
			if (!delitem(db->dbm_pagbuf, i) ||
			    !delitem(db->dbm_pagbuf, i))
				db->dbm_flags |= _DBM_IOERR;
E 3
			break;
		}
	}
E 5
I 5
	if (!delitem(db->dbm_pagbuf, i))
		goto err;
E 5
D 3
	(void) lseek(db->db_pagf, db->db_blkno*PBLKSIZ, L_SET);
	(void) write(db->db_pagf, db->db_pagbuf, PBLKSIZ);
	db->db_pagbno = db->db_blkno;
E 3
I 3
	db->dbm_pagbno = db->dbm_blkno;
	(void) lseek(db->dbm_pagf, db->dbm_blkno*PBLKSIZ, L_SET);
	if (write(db->dbm_pagf, db->dbm_pagbuf, PBLKSIZ) != PBLKSIZ) {
I 5
	err:
E 5
		db->dbm_flags |= _DBM_IOERR;
		return (-1);
	}
E 3
	return (0);
}

D 2
dbmstore(db, key, dat)
E 2
I 2
D 3
dbmstore(db, key, dat, replace)
E 3
I 3
dbm_store(db, key, dat, replace)
E 3
E 2
	register DBM *db;
	datum key, dat;
I 2
	int replace;
E 2
{
	register i;
D 5
	datum item;
E 5
I 5
	datum item, item1;
E 5
	char ovfbuf[PBLKSIZ];

D 3
	if (dbrdonly(db)) {
E 3
I 3
	if (dbm_error(db))
		return (-1);
	if (dbm_rdonly(db)) {
E 3
		errno = EPERM;
		return (-1);
	}
loop:
	dbm_access(db, dcalchash(key));
I 3
D 5
	if (dbm_error(db))
		return (-1);
E 3
	for (i=0;; i+=2) {
D 3
		item = makdatum(db->db_pagbuf, i);
E 3
I 3
		item = makdatum(db->dbm_pagbuf, i);
E 3
		if (item.dptr == NULL)
			break;
		if (cmpdatum(key, item) == 0) {
D 2
			return(0);
/*
E 2
I 2
			if (!replace)
				return (1);
E 2
D 3
			delitem(db->db_pagbuf, i);
			delitem(db->db_pagbuf, i);
			break;
E 3
I 3
			if (!delitem(db->dbm_pagbuf, i) ||
			    !delitem(db->dbm_pagbuf, i)) {
				db->dbm_flags |= _DBM_IOERR;
				return (-1);
			}
E 5
I 5
	if ((i = finddatum(db->dbm_pagbuf, key)) >= 0) {
		if (!replace)
			return (1);
		if (!delitem(db->dbm_pagbuf, i)) {
			db->dbm_flags |= _DBM_IOERR;
			return (-1);
E 5
E 3
D 2
*/
E 2
		}
	}
D 3
	i = additem(db->db_pagbuf, key);
	if (i < 0)
E 3
I 3
D 5
	if (!additem(db->dbm_pagbuf, key))
E 5
I 5
	if (!additem(db->dbm_pagbuf, key, dat))
E 5
E 3
		goto split;
D 3
	if (additem(db->db_pagbuf, dat) < 0) {
		delitem(db->db_pagbuf, i);
E 3
I 3
D 5
	if (!additem(db->dbm_pagbuf, dat)) {
		/* special case of delitem() expanded inline here */
		((short *) db->dbm_pagbuf)[0]--;
E 3
		goto split;
	}
E 5
D 3
	(void) lseek(db->db_pagf, db->db_blkno*PBLKSIZ, L_SET);
	(void) write(db->db_pagf, db->db_pagbuf, PBLKSIZ);
	db->db_pagbno = db->db_blkno;
E 3
I 3
	db->dbm_pagbno = db->dbm_blkno;
	(void) lseek(db->dbm_pagf, db->dbm_blkno*PBLKSIZ, L_SET);
	if (write(db->dbm_pagf, db->dbm_pagbuf, PBLKSIZ) != PBLKSIZ) {
		db->dbm_flags |= _DBM_IOERR;
		return (-1);
	}
E 3
	return (0);

split:
D 5
	if (key.dsize+dat.dsize+2*sizeof(short) >= PBLKSIZ) {
E 5
I 5
	if (key.dsize+dat.dsize+3*sizeof(short) >= PBLKSIZ) {
E 5
I 3
		db->dbm_flags |= _DBM_IOERR;
E 3
		errno = ENOSPC;
		return (-1);
	}
	bzero(ovfbuf, PBLKSIZ);
	for (i=0;;) {
D 3
		item = makdatum(db->db_pagbuf, i);
E 3
I 3
		item = makdatum(db->dbm_pagbuf, i);
E 3
		if (item.dptr == NULL)
			break;
D 3
		if (dcalchash(item) & (db->db_hmask+1)) {
			additem(ovfbuf, item);
			delitem(db->db_pagbuf, i);
			item = makdatum(db->db_pagbuf, i);
E 3
I 3
		if (dcalchash(item) & (db->dbm_hmask+1)) {
D 5
			if (!additem(ovfbuf, item) ||
			    !delitem(db->dbm_pagbuf, i)) {
				db->dbm_flags |= _DBM_IOERR;
				return (-1);
			}
			item = makdatum(db->dbm_pagbuf, i);
E 3
			if (item.dptr == NULL) {
E 5
I 5
			item1 = makdatum(db->dbm_pagbuf, i+1);
			if (item1.dptr == NULL) {
E 5
D 3
				printf("ndbm: split not paired\n");
E 3
I 3
				fprintf(stderr, "ndbm: split not paired\n");
				db->dbm_flags |= _DBM_IOERR;
E 3
				break;
			}
D 3
			additem(ovfbuf, item);
			delitem(db->db_pagbuf, i);
E 3
I 3
D 5
			if (!additem(ovfbuf, item) ||
E 5
I 5
			if (!additem(ovfbuf, item, item1) ||
E 5
			    !delitem(db->dbm_pagbuf, i)) {
				db->dbm_flags |= _DBM_IOERR;
				return (-1);
			}
E 3
			continue;
		}
		i += 2;
	}
D 3
	(void) lseek(db->db_pagf, db->db_blkno*PBLKSIZ, L_SET);
	(void) write(db->db_pagf, db->db_pagbuf, PBLKSIZ);
	db->db_pagbno = db->db_blkno;
	(void) lseek(db->db_pagf, (db->db_blkno+db->db_hmask+1)*PBLKSIZ, L_SET);
	(void) write(db->db_pagf, ovfbuf, PBLKSIZ);
E 3
I 3
	db->dbm_pagbno = db->dbm_blkno;
	(void) lseek(db->dbm_pagf, db->dbm_blkno*PBLKSIZ, L_SET);
	if (write(db->dbm_pagf, db->dbm_pagbuf, PBLKSIZ) != PBLKSIZ) {
		db->dbm_flags |= _DBM_IOERR;
		return (-1);
	}
	(void) lseek(db->dbm_pagf, (db->dbm_blkno+db->dbm_hmask+1)*PBLKSIZ, L_SET);
	if (write(db->dbm_pagf, ovfbuf, PBLKSIZ) != PBLKSIZ) {
		db->dbm_flags |= _DBM_IOERR;
		return (-1);
	}
E 3
	setbit(db);
	goto loop;
}

datum
D 3
dbmfirstkey(db)
E 3
I 3
dbm_firstkey(db)
E 3
	DBM *db;
{

D 5
	return (firsthash(db, 0L));
E 5
I 5
	db->dbm_blkptr = 0L;
	db->dbm_keyptr = 0;
	return (dbm_nextkey(db));
E 5
}

datum
D 3
dbmnextkey(db, key)
E 3
I 3
D 5
dbm_nextkey(db, key)
E 5
I 5
dbm_nextkey(db)
E 5
E 3
	register DBM *db;
D 5
	datum key;
E 5
{
D 5
	register i;
	datum item, bitem;
	long hash;
	int f;
E 5
I 5
	struct stat statb;
	datum item;
E 5

D 3
	hash = dcalchash(key);
	dbm_access(db, hash);
E 3
I 3
D 5
	if (dbm_error(db))
E 5
I 5
	if (dbm_error(db) || fstat(db->dbm_pagf, &statb) < 0)
E 5
		goto err;
D 5
	dbm_access(db, hash = dcalchash(key));
	if (dbm_error(db))
		goto err;
E 3
	f = 1;
	for (i=0;; i+=2) {
D 3
		item = makdatum(db->db_pagbuf, i);
E 3
I 3
		item = makdatum(db->dbm_pagbuf, i);
E 3
		if (item.dptr == NULL)
			break;
		if (cmpdatum(key, item) <= 0)
			continue;
		if (f || cmpdatum(bitem, item) < 0) {
			bitem = item;
			f = 0;
E 5
I 5
	statb.st_size /= PBLKSIZ;
	for (;;) {
		if (db->dbm_blkptr != db->dbm_pagbno) {
			db->dbm_pagbno = db->dbm_blkptr;
			(void) lseek(db->dbm_pagf, db->dbm_blkptr*PBLKSIZ, L_SET);
			if (read(db->dbm_pagf, db->dbm_pagbuf, PBLKSIZ) != PBLKSIZ)
				bzero(db->dbm_pagbuf, PBLKSIZ);
#ifdef DEBUG
			else if (chkblk(db->dbm_pagbuf) < 0)
				db->dbm_flags |= _DBM_IOERR;
#endif
E 5
		}
I 5
		if (((short *)db->dbm_pagbuf)[0] != 0) {
			item = makdatum(db->dbm_pagbuf, db->dbm_keyptr);
			if (item.dptr != NULL) {
				db->dbm_keyptr += 2;
				return (item);
			}
			db->dbm_keyptr = 0;
		}
		if (++db->dbm_blkptr >= statb.st_size)
			break;
E 5
	}
D 5
	if (f == 0)
		return (bitem);
	hash = hashinc(db, hash);
	if (hash == 0)
		return (item);
	return (firsthash(db, hash));
E 5
I 3
err:
	item.dptr = NULL;
	item.dsize = 0;
	return (item);
E 3
}

D 5
static datum
firsthash(db, hash)
	register DBM *db;
	long hash;
{
	register i;
	datum item, bitem;

loop:
	dbm_access(db, hash);
D 3
	bitem = makdatum(db->db_pagbuf, 0);
E 3
I 3
	if (dbm_error(db)) {
		item.dptr = NULL;
		return (item);
	}
	bitem = makdatum(db->dbm_pagbuf, 0);
E 3
	for (i=2;; i+=2) {
D 3
		item = makdatum(db->db_pagbuf, i);
E 3
I 3
		item = makdatum(db->dbm_pagbuf, i);
E 3
		if (item.dptr == NULL)
			break;
		if (cmpdatum(bitem, item) < 0)
			bitem = item;
	}
	if (bitem.dptr != NULL)
		return (bitem);
	hash = hashinc(db, hash);
	if (hash == 0)
		return (item);
	goto loop;
}

E 5
static
dbm_access(db, hash)
	register DBM *db;
	long hash;
{
D 5
	
E 5
I 5

E 5
D 3
	for (db->db_hmask=0;; db->db_hmask=(db->db_hmask<<1)+1) {
		db->db_blkno = hash & db->db_hmask;
		db->db_bitno = db->db_blkno + db->db_hmask;
E 3
I 3
	for (db->dbm_hmask=0;; db->dbm_hmask=(db->dbm_hmask<<1)+1) {
		db->dbm_blkno = hash & db->dbm_hmask;
		db->dbm_bitno = db->dbm_blkno + db->dbm_hmask;
E 3
		if (getbit(db) == 0)
			break;
	}
D 3
	if (db->db_blkno != db->db_pagbno) {
		bzero(db->db_pagbuf, PBLKSIZ);
		(void) lseek(db->db_pagf, db->db_blkno*PBLKSIZ, L_SET);
		(void) read(db->db_pagf, db->db_pagbuf, PBLKSIZ);
		chkblk(db->db_pagbuf);
		db->db_pagbno = db->db_blkno;
E 3
I 3
	if (db->dbm_blkno != db->dbm_pagbno) {
		db->dbm_pagbno = db->dbm_blkno;
		(void) lseek(db->dbm_pagf, db->dbm_blkno*PBLKSIZ, L_SET);
		if (read(db->dbm_pagf, db->dbm_pagbuf, PBLKSIZ) != PBLKSIZ)
			bzero(db->dbm_pagbuf, PBLKSIZ);
I 5
#ifdef DEBUG
E 5
		else if (chkblk(db->dbm_pagbuf) < 0)
			db->dbm_flags |= _DBM_IOERR;
I 5
#endif
E 5
E 3
	}
}

static
getbit(db)
	register DBM *db;
{
	long bn;
	register b, i, n;
	

D 3
	if (db->db_bitno > db->db_maxbno)
E 3
I 3
	if (db->dbm_bitno > db->dbm_maxbno)
E 3
		return (0);
D 3
	n = db->db_bitno % BYTESIZ;
	bn = db->db_bitno / BYTESIZ;
E 3
I 3
	n = db->dbm_bitno % BYTESIZ;
	bn = db->dbm_bitno / BYTESIZ;
E 3
	i = bn % DBLKSIZ;
	b = bn / DBLKSIZ;
D 3
	if (b != db->db_dirbno) {
		bzero(db->db_dirbuf, DBLKSIZ);
		(void) lseek(db->db_dirf, (long)b*DBLKSIZ, L_SET);
		(void) read(db->db_dirf, db->db_dirbuf, DBLKSIZ);
		db->db_dirbno = b;
E 3
I 3
	if (b != db->dbm_dirbno) {
		db->dbm_dirbno = b;
		(void) lseek(db->dbm_dirf, (long)b*DBLKSIZ, L_SET);
		if (read(db->dbm_dirf, db->dbm_dirbuf, DBLKSIZ) != DBLKSIZ)
			bzero(db->dbm_dirbuf, DBLKSIZ);
E 3
	}
D 3
	if (db->db_dirbuf[i] & (1<<n))
E 3
I 3
D 5
	if (db->dbm_dirbuf[i] & (1<<n))
E 3
		return (1);
	return (0);
E 5
I 5
	return (db->dbm_dirbuf[i] & (1<<n));
E 5
}

static
setbit(db)
	register DBM *db;
{
	long bn;
	register i, n, b;

D 3
	if (dbrdonly(db)) {
E 3
I 3
D 5
	if (dbm_rdonly(db)) {
E 3
		errno = EPERM;
		return (-1);
	}
D 3
	if (db->db_bitno > db->db_maxbno) {
		db->db_maxbno = db->db_bitno;
E 3
I 3
	if (db->dbm_bitno > db->dbm_maxbno) {
E 5
I 5
	if (db->dbm_bitno > db->dbm_maxbno)
E 5
		db->dbm_maxbno = db->dbm_bitno;
E 3
D 5
		getbit(db);
	}
E 5
D 3
	n = db->db_bitno % BYTESIZ;
	bn = db->db_bitno / BYTESIZ;
E 3
I 3
	n = db->dbm_bitno % BYTESIZ;
	bn = db->dbm_bitno / BYTESIZ;
E 3
	i = bn % DBLKSIZ;
	b = bn / DBLKSIZ;
I 5
	if (b != db->dbm_dirbno) {
		db->dbm_dirbno = b;
		(void) lseek(db->dbm_dirf, (long)b*DBLKSIZ, L_SET);
		if (read(db->dbm_dirf, db->dbm_dirbuf, DBLKSIZ) != DBLKSIZ)
			bzero(db->dbm_dirbuf, DBLKSIZ);
	}
E 5
D 3
	db->db_dirbuf[i] |= 1<<n;
	(void) lseek(db->db_dirf, (long)b*DBLKSIZ, L_SET);
	(void) write(db->db_dirf, db->db_dirbuf, DBLKSIZ);
	db->db_dirbno = b;
E 3
I 3
	db->dbm_dirbuf[i] |= 1<<n;
	db->dbm_dirbno = b;
	(void) lseek(db->dbm_dirf, (long)b*DBLKSIZ, L_SET);
D 5
	if (write(db->dbm_dirf, db->dbm_dirbuf, DBLKSIZ) != DBLKSIZ) {
E 5
I 5
	if (write(db->dbm_dirf, db->dbm_dirbuf, DBLKSIZ) != DBLKSIZ)
E 5
		db->dbm_flags |= _DBM_IOERR;
D 5
		return (-1);
	}
	return (0);
E 5
E 3
}

static datum
makdatum(buf, n)
	char buf[PBLKSIZ];
{
	register short *sp;
	register t;
	datum item;

	sp = (short *)buf;
D 3
	if (n < 0 || n >= sp[0])
		goto null;
E 3
I 3
D 5
	if (n < 0 || n >= sp[0]) {
E 5
I 5
	if ((unsigned)n >= sp[0]) {
E 5
		item.dptr = NULL;
		item.dsize = 0;
		return (item);
	}
E 3
	t = PBLKSIZ;
	if (n > 0)
D 3
		t = sp[n+1-1];
E 3
I 3
		t = sp[n];
E 3
	item.dptr = buf+sp[n+1];
	item.dsize = t - sp[n+1];
	return (item);
D 3

null:
	item.dptr = NULL;
	item.dsize = 0;
	return (item);
E 3
}

static
D 5
cmpdatum(d1, d2)
	datum d1, d2;
E 5
I 5
finddatum(buf, item)
	char buf[PBLKSIZ];
	datum item;
E 5
{
D 3
	register n;
E 3
I 3
D 5
	register int n;
E 3
	register char *p1, *p2;
E 5
I 5
	register short *sp;
	register int i, n, j;
E 5

D 5
	n = d1.dsize;
	if (n != d2.dsize)
		return (n - d2.dsize);
	if (n == 0)
		return (0);
	p1 = d1.dptr;
	p2 = d2.dptr;
	do
		if (*p1++ != *p2++)
			return (*--p1 - *--p2);
	while (--n);
	return (0);
E 5
I 5
	sp = (short *)buf;
	n = PBLKSIZ;
	for (i=0, j=sp[0]; i<j; i+=2, n = sp[i]) {
		n -= sp[i+1];
		if (n != item.dsize)
			continue;
		if (n == 0 || bcmp(&buf[sp[i+1]], item.dptr, n) == 0)
			return (i);
	}
	return (-1);
E 5
}

static  int hitab[16]
/* ken's
{
	055,043,036,054,063,014,004,005,
	010,064,077,000,035,027,025,071,
};
*/
 = {    61, 57, 53, 49, 45, 41, 37, 33,
	29, 25, 21, 17, 13,  9,  5,  1,
};
static  long hltab[64]
 = {
	06100151277L,06106161736L,06452611562L,05001724107L,
	02614772546L,04120731531L,04665262210L,07347467531L,
	06735253126L,06042345173L,03072226605L,01464164730L,
	03247435524L,07652510057L,01546775256L,05714532133L,
	06173260402L,07517101630L,02431460343L,01743245566L,
	00261675137L,02433103631L,03421772437L,04447707466L,
	04435620103L,03757017115L,03641531772L,06767633246L,
	02673230344L,00260612216L,04133454451L,00615531516L,
	06137717526L,02574116560L,02304023373L,07061702261L,
	05153031405L,05322056705L,07401116734L,06552375715L,
	06165233473L,05311063631L,01212221723L,01052267235L,
	06000615237L,01075222665L,06330216006L,04402355630L,
	01451177262L,02000133436L,06025467062L,07121076461L,
	03123433522L,01010635225L,01716177066L,05161746527L,
	01736635071L,06243505026L,03637211610L,01756474365L,
	04723077174L,03642763134L,05750130273L,03655541561L,
};

static long
hashinc(db, hash)
	register DBM *db;
	long hash;
{
	long bit;

D 3
	hash &= db->db_hmask;
	bit = db->db_hmask+1;
E 3
I 3
	hash &= db->dbm_hmask;
	bit = db->dbm_hmask+1;
E 3
	for (;;) {
		bit >>= 1;
		if (bit == 0)
			return (0L);
D 3
		if ((hash&bit) == 0)
			return (hash|bit);
E 3
I 3
		if ((hash & bit) == 0)
			return (hash | bit);
E 3
		hash &= ~bit;
	}
}

static long
dcalchash(item)
	datum item;
{
D 3
	register i, j, f;
	long hashl;
	int hashi;
E 3
I 3
	register int s, c, j;
	register char *cp;
	register long hashl;
	register int hashi;
E 3

	hashl = 0;
	hashi = 0;
D 3
	for (i=0; i<item.dsize; i++) {
		f = item.dptr[i];
E 3
I 3
	for (cp = item.dptr, s=item.dsize; --s >= 0; ) {
		c = *cp++;
E 3
		for (j=0; j<BYTESIZ; j+=4) {
D 3
			hashi += hitab[f&017];
E 3
I 3
			hashi += hitab[c&017];
E 3
			hashl += hltab[hashi&63];
D 3
			f >>= 4;
E 3
I 3
			c >>= 4;
E 3
		}
	}
	return (hashl);
}

I 5
/*
 * Delete pairs of items (n & n+1).
 */
E 5
static
delitem(buf, n)
	char buf[PBLKSIZ];
{
D 3
	register short *sp;
	register i1, i2, i3;
E 3
I 3
	register short *sp, *sp1;
	register i1, i2;
E 3

	sp = (short *)buf;
D 3
	if (n < 0 || n >= sp[0])
		goto bad;
	i1 = sp[n+1];
	i2 = PBLKSIZ;
E 3
I 3
	i2 = sp[0];
D 5
	if (n < 0 || n >= i2)
E 5
I 5
	if ((unsigned)n >= i2 || (n & 1))
E 5
		return (0);
D 5
	if (n == i2-1) {
		sp[0]--;
E 5
I 5
	if (n == i2-2) {
		sp[0] -= 2;
E 5
		return (1);
	}
	i1 = PBLKSIZ;
E 3
	if (n > 0)
D 3
		i2 = sp[n+1-1];
	i3 = sp[sp[0]+1-1];
	if (i2 > i1)
	while (i1 > i3) {
		i1--;
		i2--;
		buf[i2] = buf[i1];
		buf[i1] = 0;
E 3
I 3
		i1 = sp[n];
D 5
	i1 -= sp[n+1];
E 5
I 5
	i1 -= sp[n+2];
E 5
	if (i1 > 0) {
		i2 = sp[i2];
D 5
		bcopy(&buf[i2], &buf[i2 + i1], sp[n+1] - i2);
E 5
I 5
		bcopy(&buf[i2], &buf[i2 + i1], sp[n+2] - i2);
E 5
E 3
	}
D 3
	i2 -= i1;
	for (i1=n+1; i1<sp[0]; i1++)
		sp[i1+1-1] = sp[i1+1] + i2;
	sp[0]--;
	sp[sp[0]+1] = 0;
	return;

bad:
	printf("ndbm: bad delitem\n");
	abort();
E 3
I 3
D 5
	for (sp1 = sp + sp[0]--, sp += n+1; sp < sp1; sp++)
		sp[0] = sp[1] + i1;
E 5
I 5
	sp[0] -= 2;
	for (sp1 = sp + sp[0], sp += n+1; sp <= sp1; sp++)
		sp[0] = sp[2] + i1;
E 5
	return (1);
E 3
}

I 5
/*
 * Add pairs of items (item & item1).
 */
E 5
static
D 5
additem(buf, item)
E 5
I 5
additem(buf, item, item1)
E 5
	char buf[PBLKSIZ];
D 5
	datum item;
E 5
I 5
	datum item, item1;
E 5
{
	register short *sp;
	register i1, i2;

	sp = (short *)buf;
	i1 = PBLKSIZ;
D 3
	if (sp[0] > 0)
		i1 = sp[sp[0]+1-1];
E 3
I 3
	i2 = sp[0];
	if (i2 > 0)
		i1 = sp[i2];
E 3
D 5
	i1 -= item.dsize;
D 3
	i2 = (sp[0]+2) * sizeof(short);
E 3
I 3
	i2 = (i2+2) * sizeof(short);
E 3
	if (i1 <= i2)
E 5
I 5
	i1 -= item.dsize + item1.dsize;
D 9
	if (i1 <= (i2+3) * sizeof(short))
E 9
I 9
	if (i1 <= (i2+3) * (int)sizeof(short))
E 9
E 5
D 3
		return (-1);
	sp[sp[0]+1] = i1;
	for (i2=0; i2<item.dsize; i2++) {
		buf[i1] = item.dptr[i2];
		i1++;
	}
	sp[0]++;
	return (sp[0]-1);
E 3
I 3
		return (0);
D 5
	sp[++sp[0]] = i1;
	bcopy(item.dptr, &buf[i1], item.dsize);
E 5
I 5
	sp[0] += 2;
	sp[++i2] = i1 + item1.dsize;
	bcopy(item.dptr, &buf[i1 + item1.dsize], item.dsize);
	sp[++i2] = i1;
	bcopy(item1.dptr, &buf[i1], item1.dsize);
E 5
	return (1);
E 3
}

I 5
#ifdef DEBUG
E 5
static
chkblk(buf)
	char buf[PBLKSIZ];
{
	register short *sp;
	register t, i;

	sp = (short *)buf;
	t = PBLKSIZ;
	for (i=0; i<sp[0]; i++) {
		if (sp[i+1] > t)
D 3
			goto bad;
E 3
I 3
			return (-1);
E 3
		t = sp[i+1];
	}
	if (t < (sp[0]+1)*sizeof(short))
D 3
		goto bad;
	return;

bad:
	printf("ndbm: bad block\n");
	abort();
	bzero(buf, PBLKSIZ);
E 3
I 3
		return (-1);
	return (0);
E 3
}
I 5
#endif
E 5
E 1
