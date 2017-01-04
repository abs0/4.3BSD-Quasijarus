h03808
s 00007/00007/00114
d D 5.3 87/12/21 11:29:02 bostic 13 12
c make ANSI C compatible
e
s 00002/00002/00119
d D 5.2 86/03/09 19:48:34 donn 12 11
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00112
d D 5.1 85/05/30 10:42:23 dist 11 10
c Add copyright
e
s 00021/00014/00092
d D 4.7 85/02/04 21:15:40 serge 10 7
c made setpwfile work with getpwnam and getpwuid
e
s 00017/00010/00096
d R 4.7 85/01/21 20:12:42 serge 9 7
c made setpwfile work with getpwnam and getpwuid
e
s 00017/00009/00097
d R 4.7 85/01/16 15:14:32 serge 8 7
c made setpwfile work with getpwnam and getpwuid
e
s 00006/00003/00100
d D 4.6 85/01/10 09:17:04 ralph 7 6
c make code more portable
e
s 00013/00013/00090
d D 4.5 84/08/28 17:03:47 ralph 6 4
c unify dbm names, break pwent <-> pwnamuid dependencies.
e
s 00009/00009/00094
d R 4.5 84/08/28 14:57:28 ralph 5 4
c unify dbm names, break pwent <-> pwnamuid dependencies.
e
s 00039/00012/00064
d D 4.4 84/04/26 10:32:39 ralph 4 3
c added stayopen flag for database, defaults to old code if no db.
e
s 00005/00006/00071
d D 4.3 84/01/31 16:30:10 ralph 3 2
c save data in static array because dbmclose does a free().
e
s 00004/00000/00073
d D 4.2 83/12/20 11:31:34 ralph 2 1
c use flock so data base can be updated directly.
e
s 00073/00000/00000
d D 4.1 83/12/02 17:14:37 ralph 1 0
c date and time created 83/12/02 17:14:37 by ralph
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 12
#ifndef lint
E 12
I 12
#if defined(LIBC_SCCS) && !defined(lint)
E 12
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif not lint
E 12
I 12
#endif LIBC_SCCS and not lint
E 12
E 11

#include <stdio.h>
#include <pwd.h>
#include <ndbm.h>

#include <sys/file.h>

D 10
static char PASSWD[] = "/etc/passwd";
static char EMPTY[] = "";
E 10
static char line[BUFSIZ+1];
static struct passwd passwd;
D 3
static datum curkey;
E 3
D 4
static DBM *db = 0;
E 4
I 4
D 6
DBM *_pw_db = 0;
int _pw_stayopen = 0;
E 6
I 6
D 10
DBM *_pw_db;
int _pw_stayopen;
E 10
E 6
E 4

I 10
/*
 * The following are shared with getpwent.c
 */
extern	char *_pw_file;
DBM	*_pw_db;
int	_pw_stayopen;

E 10
static struct passwd *
fetchpw(key)
	datum key;
{
D 3
        register char *cp;
E 3
I 3
        register char *cp, *tp;
E 3

D 3
        curkey = key;
        if (curkey.dptr == 0)
E 3
I 3
        if (key.dptr == 0)
E 3
                return ((struct passwd *)NULL);
D 3
	key = dbmfetch(db, curkey);
E 3
I 3
D 4
	key = dbmfetch(db, key);
E 4
I 4
D 6
	key = dbmfetch(_pw_db, key);
E 6
I 6
	key = dbm_fetch(_pw_db, key);
E 6
E 4
E 3
	if (key.dptr == 0)
                return ((struct passwd *)NULL);
        cp = key.dptr;
I 3
	tp = line;
E 3

D 3
#define	EXPAND(e)	passwd.pw_/**/e = cp; while (*cp++);
E 3
I 3
D 13
#define	EXPAND(e)	passwd.pw_/**/e = tp; while (*tp++ = *cp++);
E 3
	EXPAND(name);
	EXPAND(passwd);
E 13
I 13
#define	EXPAND(e)	passwd.e = tp; while (*tp++ = *cp++);
	EXPAND(pw_name);
	EXPAND(pw_passwd);
E 13
D 7
	passwd.pw_uid = *(int *)cp; cp += sizeof (int);
	passwd.pw_gid = *(int *)cp; cp += sizeof (int);
	passwd.pw_quota = *(int *)cp; cp += sizeof (int);
E 7
I 7
	bcopy(cp, (char *)&passwd.pw_uid, sizeof (int));
	cp += sizeof (int);
	bcopy(cp, (char *)&passwd.pw_gid, sizeof (int));
	cp += sizeof (int);
	bcopy(cp, (char *)&passwd.pw_quota, sizeof (int));
	cp += sizeof (int);
E 7
D 13
	EXPAND(comment);
	EXPAND(gecos);
	EXPAND(dir);
	EXPAND(shell);
E 13
I 13
	EXPAND(pw_comment);
	EXPAND(pw_gecos);
	EXPAND(pw_dir);
	EXPAND(pw_shell);
E 13
        return (&passwd);
}

struct passwd *
getpwnam(nam)
	char *nam;
{
        datum key;
	register struct passwd *pw;

D 4
        if ((db = ndbmopen(PASSWD, O_RDONLY)) == (DBM *)0)
                return ((struct passwd *)NULL);
I 2
	if (flock(db->db_dirf, LOCK_SH) < 0)
                return ((struct passwd *)NULL);
E 4
I 4
        if (_pw_db == (DBM *)0 &&
D 6
	    (_pw_db = ndbmopen(PASSWD, O_RDONLY)) == (DBM *)0) {
E 6
I 6
D 10
	    (_pw_db = dbm_open(PASSWD, O_RDONLY)) == (DBM *)0) {
E 10
I 10
	    (_pw_db = dbm_open(_pw_file, O_RDONLY)) == (DBM *)0) {
E 10
E 6
	oldcode:
		setpwent();
D 10
		while ((pw = getpwent()) && strcmp(nam, pw->pw_name));
		endpwent();
E 10
I 10
		while ((pw = getpwent()) && strcmp(nam, pw->pw_name))
			;
		if (!_pw_stayopen)
			endpwent();
E 10
		return (pw);
	}
D 6
	if (flock(_pw_db->db_dirf, LOCK_SH) < 0) {
		ndbmclose(_pw_db);
E 6
I 6
D 10
	if (flock(_pw_db->dbm_dirf, LOCK_SH) < 0) {
E 10
I 10
	if (flock(dbm_dirfno(_pw_db), LOCK_SH) < 0) {
E 10
		dbm_close(_pw_db);
E 6
		_pw_db = (DBM *)0;
		goto oldcode;
	}
E 4
E 2
        key.dptr = nam;
        key.dsize = strlen(nam);
	pw = fetchpw(key);
D 4
	ndbmclose(db);
E 4
I 4
D 6
	(void) flock(_pw_db->db_dirf, LOCK_UN);
E 6
I 6
D 10
	(void) flock(_pw_db->dbm_dirf, LOCK_UN);
E 10
I 10
	(void) flock(dbm_dirfno(_pw_db), LOCK_UN);
E 10
E 6
	if (!_pw_stayopen) {
D 6
		ndbmclose(_pw_db);
E 6
I 6
		dbm_close(_pw_db);
E 6
		_pw_db = (DBM *)0;
	}
E 4
        return (pw);
}

struct passwd *
getpwuid(uid)
	int uid;
{
        datum key;
	register struct passwd *pw;

D 4
        if ((db = ndbmopen(PASSWD, O_RDONLY)) == (DBM *)0)
I 2
                return ((struct passwd *)NULL);
	if (flock(db->db_dirf, LOCK_SH) < 0)
E 2
                return ((struct passwd *)NULL);
E 4
I 4
        if (_pw_db == (DBM *)0 &&
D 6
	    (_pw_db = ndbmopen(PASSWD, O_RDONLY)) == (DBM *)0) {
E 6
I 6
D 10
	    (_pw_db = dbm_open(PASSWD, O_RDONLY)) == (DBM *)0) {
E 10
I 10
	    (_pw_db = dbm_open(_pw_file, O_RDONLY)) == (DBM *)0) {
E 10
E 6
	oldcode:
		setpwent();
D 10
		while ((pw = getpwent()) && pw->pw_uid != uid);
		endpwent();
E 10
I 10
		while ((pw = getpwent()) && pw->pw_uid != uid)
			;
		if (!_pw_stayopen)
			endpwent();
E 10
		return (pw);
	}
D 6
	if (flock(_pw_db->db_dirf, LOCK_SH) < 0) {
		ndbmclose(_pw_db);
E 6
I 6
D 10
	if (flock(_pw_db->dbm_dirf, LOCK_SH) < 0) {
E 10
I 10
	if (flock(dbm_dirfno(_pw_db), LOCK_SH) < 0) {
E 10
		dbm_close(_pw_db);
E 6
		_pw_db = (DBM *)0;
		goto oldcode;
	}
E 4
        key.dptr = (char *) &uid;
        key.dsize = sizeof uid;
	pw = fetchpw(key);
D 4
	ndbmclose(db);
E 4
I 4
D 6
	(void) flock(_pw_db->db_dirf, LOCK_UN);
E 6
I 6
D 10
	(void) flock(_pw_db->dbm_dirf, LOCK_UN);
E 10
I 10
	(void) flock(dbm_dirfno(_pw_db), LOCK_UN);
E 10
E 6
	if (!_pw_stayopen) {
D 6
		ndbmclose(_pw_db);
E 6
I 6
		dbm_close(_pw_db);
E 6
		_pw_db = (DBM *)0;
	}
E 4
        return (pw);
}
E 1
