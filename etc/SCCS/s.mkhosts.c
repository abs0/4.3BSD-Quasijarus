h43047
s 00007/00007/00124
d D 5.2 87/10/22 10:36:44 bostic 8 7
c ANSI C; sprintf now returns an int.
e
s 00014/00002/00117
d D 5.1 85/05/28 14:57:32 dist 7 6
c Add copyright
e
s 00003/00002/00116
d D 4.5 85/02/18 17:32:14 bloom 6 4
c use bcopy with unknown alignment for portability
e
s 00003/00002/00116
d R 4.5 85/02/18 17:25:36 bloom 5 4
c use bcopy when alignment isn't known for portability
e
s 00038/00007/00080
d D 4.4 84/08/28 14:26:11 ralph 4 3
c check dbm for errors, use new.pag, new.dir and rename if no errors.
e
s 00005/00000/00082
d D 4.3 84/05/17 16:01:04 ralph 3 2
c use new setpwfile() and sethostfile() to override default files.
e
s 00003/00003/00079
d D 4.2 84/02/02 13:56:58 ralph 2 1
c added DB_INSERT parameter to dbmstore().
e
s 00082/00000/00000
d D 4.1 83/12/05 16:21:36 ralph 1 0
c date and time created 83/12/05 16:21:36 by ralph
e
u
U
t
T
I 7
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
#ifndef lint
D 7
static	char *sccsid = "%W% (Berkeley) %E%";
#endif
E 7
I 7
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7

#include <sys/file.h>
#include <stdio.h>
#include <netdb.h>
#include <ndbm.h>

char	buf[BUFSIZ];

main(argc, argv)
	char *argv[];
{
	DBM *dp;
	register struct hostent *hp;
	datum key, content;
	register char *cp, *tp, **sp;
D 6
	register int naliases, *nap;
E 6
I 6
	register int *nap;
	int naliases;
E 6
D 4
	int verbose = 0, entries = 0, maxlen = 0;
E 4
I 4
	int verbose = 0, entries = 0, maxlen = 0, error = 0;
	char tempname[BUFSIZ], newname[BUFSIZ];
E 4

	if (argc > 1 && strcmp(argv[1], "-v") == 0) {
		verbose++;
		argv++, argc--;
	}
	if (argc != 2) {
		fprintf(stderr, "usage: mkhosts [ -v ] file\n");
		exit(1);
	}
I 3
	if (access(argv[1], R_OK) < 0) {
		perror(argv[1]);
		exit(1);
	}
E 3
	umask(0);
D 4
	dp = ndbmopen(argv[1], O_WRONLY|O_CREAT|O_EXCL, 0644);
E 4
I 4

D 8
	sprintf(tempname, "%s.new", argv[1]);
E 8
I 8
	(void)sprintf(tempname, "%s.new", argv[1]);
E 8
	dp = dbm_open(tempname, O_WRONLY|O_CREAT|O_EXCL, 0644);
E 4
	if (dp == NULL) {
D 4
		fprintf(stderr, "dbminit failed: ");
E 4
I 4
		fprintf(stderr, "dbm_open failed: ");
E 4
		perror(argv[1]);
		exit(1);
	}
D 4
	dp->db_maxbno = 0;
E 4
I 3
	sethostfile(argv[1]);
E 3
	sethostent(1);
	while (hp = gethostent()) {
		cp = buf;
		tp = hp->h_name;
		while (*cp++ = *tp++)
			;
		nap = (int *)cp;
		cp += sizeof (int);
		naliases = 0;
		for (sp = hp->h_aliases; *sp; sp++) {
			tp = *sp;
			while (*cp++ = *tp++)
				;
			naliases++;
		}
D 6
		*nap = naliases;
E 6
I 6
		bcopy((char *)&naliases, (char *)nap, sizeof(int));
E 6
		bcopy((char *)&hp->h_addrtype, cp, sizeof (int));
		cp += sizeof (int);
		bcopy((char *)&hp->h_length, cp, sizeof (int));
		cp += sizeof (int);
		bcopy(hp->h_addr, cp, hp->h_length);
		cp += hp->h_length;
		content.dptr = buf;
		content.dsize = cp - buf;
		if (verbose)
			printf("store %s, %d aliases\n", hp->h_name, naliases);
		key.dptr = hp->h_name;
		key.dsize = strlen(hp->h_name);
D 2
		dbmstore(dp, key, content);
E 2
I 2
D 4
		dbmstore(dp, key, content, DB_INSERT);
E 4
I 4
		if (dbm_store(dp, key, content, DBM_INSERT) < 0) {
			perror(hp->h_name);
			goto err;
		}
E 4
E 2
		for (sp = hp->h_aliases; *sp; sp++) {
			key.dptr = *sp;
			key.dsize = strlen(*sp);
D 2
			dbmstore(dp, key, content);
E 2
I 2
D 4
			dbmstore(dp, key, content, DB_INSERT);
E 4
I 4
			if (dbm_store(dp, key, content, DBM_INSERT) < 0) {
				perror(*sp);
				goto err;
			}
E 4
E 2
		}
		key.dptr = hp->h_addr;
		key.dsize = hp->h_length;
D 2
		dbmstore(dp, key, content);
E 2
I 2
D 4
		dbmstore(dp, key, content, DB_INSERT);
E 4
I 4
		if (dbm_store(dp, key, content, DBM_INSERT) < 0) {
			perror("dbm_store host address");
			goto err;
		}
E 4
E 2
		entries++;
		if (cp - buf > maxlen)
			maxlen = cp - buf;
	}
	endhostent();
I 4
	dbm_close(dp);

D 8
	sprintf(tempname, "%s.new.pag", argv[1]);
	sprintf(newname, "%s.pag", argv[1]);
E 8
I 8
	(void)sprintf(tempname, "%s.new.pag", argv[1]);
	(void)sprintf(newname, "%s.pag", argv[1]);
E 8
	if (rename(tempname, newname) < 0) {
		perror("rename .pag");
		exit(1);
	}
D 8
	sprintf(tempname, "%s.new.dir", argv[1]);
	sprintf(newname, "%s.dir", argv[1]);
E 8
I 8
	(void)sprintf(tempname, "%s.new.dir", argv[1]);
	(void)sprintf(newname, "%s.dir", argv[1]);
E 8
	if (rename(tempname, newname) < 0) {
		perror("rename .dir");
		exit(1);
	}
E 4
	printf("%d host entries, maximum length %d\n", entries, maxlen);
	exit(0);
I 4
err:
D 8
	sprintf(tempname, "%s.new.pag", argv[1]);
E 8
I 8
	(void)sprintf(tempname, "%s.new.pag", argv[1]);
E 8
	unlink(tempname);
D 8
	sprintf(tempname, "%s.new.dir", argv[1]);
E 8
I 8
	(void)sprintf(tempname, "%s.new.dir", argv[1]);
E 8
	unlink(tempname);
	exit(1);
E 4
}
E 1
