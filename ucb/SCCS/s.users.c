h39498
s 00010/00005/00086
d D 5.6 88/06/29 21:51:12 bostic 8 7
c install approved copyright notice
e
s 00036/00033/00055
d D 5.5 87/12/26 21:49:39 bostic 7 6
c add Berkeley header, minor reformat
e
s 00013/00022/00075
d D 5.4 87/01/28 14:38:51 bostic 6 5
c removed argument processing, put duplicates back
e
s 00058/00040/00039
d D 5.3 86/12/10 07:01:08 bostic 5 4
c removed duplicates from output list, general cleanup
e
s 00004/00003/00075
d D 5.2 85/11/15 08:44:42 lepreau 4 3
c be quiet if no users
e
s 00016/00001/00062
d D 5.1 85/05/31 09:36:13 dist 3 2
c Add copyright
e
s 00001/00001/00062
d D 4.2 83/04/28 23:48:12 mckusick 2 1
c added perror
e
s 00063/00000/00000
d D 4.1 80/10/01 17:29:15 bill 1 0
c date and time created 80/10/01 17:29:15 by bill
e
u
U
t
T
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
/*
D 7
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * Copyright (c) 1980, 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

#ifndef lint
char copyright[] =
D 7
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 7
I 7
"%Z% Copyright (c) 1980, 1987 Regents of the University of California.\n\
E 7
 All rights reserved.\n";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

E 3
/*
 * users
 */
D 5
char	*malloc();

#include <stdio.h>
E 5
I 5
#include <sys/types.h>
E 5
#include <utmp.h>
I 5
#include <stdio.h>
E 5

D 5
#define NMAX sizeof(utmp.ut_name)
#define LMAX sizeof(utmp.ut_line)
E 5
I 5
D 7
#define ERREXIT		1
#define OKEXIT		0
E 7
#define NMAX		sizeof(utmp.ut_name)
#define MAXUSERS	200
I 6
#define UTMP_FILE	"/etc/utmp"
E 6
E 5

D 5
struct utmp utmp;
E 5
I 5
D 7
static struct utmp	utmp;		/* read structure */
static int	ncnt;			/* count of names */
D 6
static char	*names[MAXUSERS],	/* names table */
		**namp;			/* pointer to names table */
E 6
I 6
static char	*names[MAXUSERS];	/* names table */
E 7
I 7
static struct utmp utmp;		/* read structure */
static int ncnt;			/* count of names */
static char *names[MAXUSERS];		/* names table */
E 7
E 6
E 5

D 5
main(argc, argv)
char **argv;
E 5
I 5
D 6
main(argc,argv)
int	argc;
char	**argv;
E 6
I 6
main()
E 6
E 5
{
D 5
	register char *tp, *s;
	register FILE *fi;
E 5
I 5
D 7
	register FILE	*fp;		/* file pointer */
E 7
I 7
	register FILE *fp;		/* file pointer */
E 7
D 6
	char	*fname;
E 6
E 5

D 5
	s = "/etc/utmp";
	if(argc == 2)
		s = argv[1];
	if ((fi = fopen(s, "r")) == NULL) {
D 2
		puts("who: cannot open utmp");
E 2
I 2
		perror(s);
E 2
		exit(1);
E 5
I 5
D 6
	if (argc > 2) {
		fputs("usage: users [ utmp_file ]\n",stderr);
E 6
I 6
D 7
	if (!(fp = fopen(UTMP_FILE,"r"))) {
E 7
I 7
	if (!(fp = fopen(UTMP_FILE, "r"))) {
E 7
		perror(UTMP_FILE);
E 6
D 7
		exit(ERREXIT);
E 7
I 7
		exit(1);
E 7
E 5
	}
D 5
	while (fread((char *)&utmp, sizeof(utmp), 1, fi) == 1) {
		if(utmp.ut_name[0] == '\0')
			continue;
		putline();
E 5
I 5
D 6
	fname = argc == 2 ? argv[1] : "/etc/utmp";
	if (!(fp = fopen(fname,"r"))) {
		perror(fname);
		exit(ERREXIT);
E 5
	}
D 5
	summary();
E 5
I 5
	namp = names;
E 6
D 7
	while (fread((char *)&utmp,sizeof(utmp),1,fp) == 1)
E 7
I 7
	while (fread((char *)&utmp, sizeof(utmp), 1, fp) == 1)
E 7
		if (*utmp.ut_name) {
			if (++ncnt > MAXUSERS) {
				ncnt = MAXUSERS;
D 7
				fputs("users: too many users.\n",stderr);
E 7
I 7
				fputs("users: too many users.\n", stderr);
E 7
				break;
			}
			nsave();
		}
D 6
	if (ncnt)
		summary();
E 6
I 6
	summary();
E 6
D 7
	exit(OKEXIT);
E 7
I 7
	exit(0);
E 7
E 5
}

D 5
char	*names[128];
char	**namp = names;
putline()
E 5
I 5
nsave()
E 5
{
I 6
D 7
	static char	**namp = names;		/* pointer to names table */
E 6
D 5
	char temp[NMAX+1];
	strncpy(temp, utmp.ut_name, NMAX);
	temp[NMAX] = 0;
	*namp = malloc(strlen(temp) + 1);
	strcpy(*namp++, temp);
}
E 5
I 5
	char	*calloc();
E 7
I 7
	static char **namp = names;	/* pointer to names table */
	char *calloc();
E 7
E 5

D 5
scmp(p, q)
char **p, **q;
{
	return(strcmp(*p, *q));
E 5
I 5
D 7
	if (!(*namp = calloc((u_int)(NMAX + 1),sizeof(char)))) {
		fputs("users: malloc error.\n",stderr);
		exit(ERREXIT);
E 7
I 7
	if (!(*namp = calloc((u_int)(NMAX + 1), sizeof(char)))) {
		fputs("users: malloc error.\n", stderr);
		exit(1);
E 7
	}
D 7
	bcopy(utmp.ut_name,*namp++,NMAX);
E 7
I 7
	bcopy(utmp.ut_name, *namp++, NMAX);
E 7
E 5
}
I 5

E 5
summary()
{
D 5
	register char **p;
E 5
I 5
D 6
	register char	**p,
			**q;
E 6
I 6
D 7
	register char	**p;
E 6
	int	scmp();
E 7
I 7
	register char **p;
	int scmp();
E 7
E 5

I 6
	if (!ncnt)
		return;
E 6
D 5
	qsort(names, namp - names, sizeof names[0], scmp);
	for (p=names; p < namp; p++) {
E 5
I 5
D 7
	qsort((char *)names,ncnt,sizeof(names[0]),scmp);
D 6
	for (p = names;p < namp;p = q) {
E 5
		if (p != names)
D 4
			printf(" ");
		printf("%s", *p);
E 4
I 4
			putchar(' ');
E 6
I 6
	fputs(names[0],stdout);
	for (p = &names[1];--ncnt;++p) {
E 7
I 7
	qsort((char *)names, ncnt, sizeof(names[0]), scmp);
	fputs(names[0], stdout);
	for (p = &names[1]; --ncnt; ++p) {
E 7
		putchar(' ');
E 6
D 5
		fputs(*p, stdout);
E 5
I 5
D 7
		fputs(*p,stdout);
E 7
I 7
		fputs(*p, stdout);
E 7
D 6
		for (q = p + 1;q < namp && !strcmp(*q,*p);++q);
E 6
E 5
E 4
	}
D 4
	printf("\n");
E 4
I 4
D 5
	if (namp != names)		/* at least one user */
		putchar('\n');
E 5
I 5
	putchar('\n');
}

D 7
scmp(p,q)
char	**p,
	**q;
E 7
I 7
scmp(p, q)
	char **p, **q;
E 7
{
D 7
	return(strcmp(*p,*q));
E 7
I 7
	return(strcmp(*p, *q));
E 7
E 5
E 4
}
E 1
