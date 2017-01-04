h26129
s 00010/00005/00095
d D 5.3 88/06/18 14:34:35 bostic 10 9
c install approved copyright notice
e
s 00022/00018/00078
d D 5.2 87/12/26 12:37:50 bostic 9 8
c Berkeley header; cpp usage fixes for ANSI C; minor cleanups
e
s 00014/00002/00082
d D 5.1 85/05/28 14:58:28 dist 8 7
c Add copyright
e
s 00006/00003/00078
d D 4.6 85/01/10 09:16:28 ralph 7 6
c make code more portable
e
s 00012/00004/00069
d D 4.5 84/10/26 09:11:07 ralph 6 4
c update for new ndbm routines.
e
s 00011/00004/00069
d R 4.5 84/10/26 09:04:37 ralph 5 4
c update for new ndbm routines.
e
s 00003/00045/00070
d D 4.4 84/05/17 16:01:10 ralph 4 3
c use new setpwfile() and sethostfile() to override default files.
e
s 00052/00004/00063
d D 4.3 84/01/25 15:11:42 ralph 3 2
c read from the right password file.
e
s 00002/00002/00065
d D 4.2 83/12/20 12:15:38 ralph 2 1
c added new parameter to dbmstore().
e
s 00067/00000/00000
d D 4.1 83/12/05 16:21:09 ralph 1 0
c date and time created 83/12/05 16:21:09 by ralph
e
u
U
t
T
I 8
/*
D 9
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * Copyright (c) 1980, 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 10
E 9
 */

E 8
I 1
#ifndef lint
D 8
static	char *sccsid = "%W% (Berkeley) %E%";
#endif
E 8
I 8
char copyright[] =
D 9
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 9
I 9
"%Z% Copyright (c) 1980, 1983 Regents of the University of California.\n\
E 9
 All rights reserved.\n";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9
E 8

#include <sys/file.h>
#include <stdio.h>
#include <pwd.h>
#include <ndbm.h>

D 9
char	buf[BUFSIZ];
I 3
D 4
char	line[BUFSIZ+1];
char	EMPTY[] = "";
struct	passwd passwd;
E 4
E 3

I 3
struct	passwd *fgetpwent();

E 9
E 3
main(argc, argv)
I 9
	int argc;
E 9
	char *argv[];
{
I 3
D 4
	FILE *pwf;
E 4
E 3
	DBM *dp;
	datum key, content;
	register char *cp, *tp;
	register struct passwd *pwd;
	int verbose = 0, entries = 0, maxlen = 0;
I 9
	char buf[BUFSIZ];
E 9

	if (argc > 1 && strcmp(argv[1], "-v") == 0) {
		verbose++;
		argv++, argc--;
	}
	if (argc != 2) {
		fprintf(stderr, "usage: mkpasswd [ -v ] file\n");
		exit(1);
	}
I 3
D 4
	if ((pwf = fopen(argv[1], "r" )) == NULL) {
E 4
I 4
	if (access(argv[1], R_OK) < 0) {
E 4
		fprintf(stderr, "mkpasswd: ");
		perror(argv[1]);
		exit(1);
	}
E 3
D 9
	umask(0);
E 9
I 9
	(void)umask(0);
E 9
D 6
	dp = ndbmopen(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0644);
E 6
I 6
	dp = dbm_open(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0644);
E 6
	if (dp == NULL) {
D 3
		fprintf(stderr, "dbminit failed: ");
E 3
I 3
		fprintf(stderr, "mkpasswd: ");
E 3
		perror(argv[1]);
		exit(1);
	}
D 6
	dp->db_maxbno = 0;
E 6
D 3
	setpwent();
	while (pwd = getpwent()) {
E 3
I 3
D 4
	while (pwd = fgetpwent(pwf)) {
E 4
I 4
	setpwfile(argv[1]);
	while (pwd = getpwent()) {
E 4
E 3
		cp = buf;
D 9
#define	COMPACT(e)	tp = pwd->pw_/**/e; while (*cp++ = *tp++);
		COMPACT(name);
		COMPACT(passwd);
E 9
I 9
#define	COMPACT(e)	tp = pwd->e; while (*cp++ = *tp++);
		COMPACT(pw_name);
		COMPACT(pw_passwd);
E 9
D 7
		*(int *)cp = pwd->pw_uid; cp += sizeof (int);
		*(int *)cp = pwd->pw_gid; cp += sizeof (int);
		*(int *)cp = pwd->pw_quota; cp += sizeof (int);
E 7
I 7
		bcopy((char *)&pwd->pw_uid, cp, sizeof (int));
		cp += sizeof (int);
		bcopy((char *)&pwd->pw_gid, cp, sizeof (int));
		cp += sizeof (int);
		bcopy((char *)&pwd->pw_quota, cp, sizeof (int));
		cp += sizeof (int);
E 7
D 9
		COMPACT(comment);
		COMPACT(gecos);
		COMPACT(dir);
		COMPACT(shell);
E 9
I 9
		COMPACT(pw_comment);
		COMPACT(pw_gecos);
		COMPACT(pw_dir);
		COMPACT(pw_shell);
E 9
		content.dptr = buf;
		content.dsize = cp - buf;
		if (verbose)
			printf("store %s, uid %d\n", pwd->pw_name, pwd->pw_uid);
		key.dptr = pwd->pw_name;
		key.dsize = strlen(pwd->pw_name);
D 2
		dbmstore(dp, key, content);
E 2
I 2
D 6
		dbmstore(dp, key, content, DB_INSERT);
E 6
I 6
		if (dbm_store(dp, key, content, DBM_INSERT) < 0) {
			fprintf(stderr, "mkpasswd: ");
			perror("dbm_store failed");
			exit(1);
		}
E 6
E 2
		key.dptr = (char *)&pwd->pw_uid;
		key.dsize = sizeof (int);
D 2
		dbmstore(dp, key, content);
E 2
I 2
D 6
		dbmstore(dp, key, content, DB_INSERT);
E 6
I 6
		if (dbm_store(dp, key, content, DBM_INSERT) < 0) {
			fprintf(stderr, "mkpasswd: ");
			perror("dbm_store failed");
			exit(1);
		}
E 6
E 2
		entries++;
		if (cp - buf > maxlen)
			maxlen = cp - buf;
	}
I 6
	dbm_close(dp);
E 6
D 3
	endpwent();
E 3
	printf("%d password entries, maximum length %d\n", entries, maxlen);
	exit(0);
I 3
D 4
}

static char *
pwskip(p)
register char *p;
{
	while( *p && *p != ':' )
		++p;
	if( *p ) *p++ = 0;
	return(p);
}

struct passwd *
fgetpwent(pwf)
	FILE *pwf;
{
	register char *p;

	p = fgets(line, BUFSIZ, pwf);
	if (p==NULL)
		return(0);
	passwd.pw_name = p;
	p = pwskip(p);
	passwd.pw_passwd = p;
	p = pwskip(p);
	passwd.pw_uid = atoi(p);
	p = pwskip(p);
	passwd.pw_gid = atoi(p);
	passwd.pw_quota = 0;
	passwd.pw_comment = EMPTY;
	p = pwskip(p);
	passwd.pw_gecos = p;
	p = pwskip(p);
	passwd.pw_dir = p;
	p = pwskip(p);
	passwd.pw_shell = p;
	while(*p && *p != '\n') p++;
	*p = '\0';
	return(&passwd);
E 4
E 3
}
E 1
