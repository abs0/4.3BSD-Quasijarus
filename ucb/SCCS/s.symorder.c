h03623
s 00007/00002/00244
d D 5.2 85/07/02 21:31:27 mckusick 9 8
c must calculate actual length (from chris@maryland)
e
s 00014/00002/00232
d D 5.1 85/05/31 09:34:16 dist 8 7
c Add copyright
e
s 00140/00057/00094
d D 4.5 84/07/05 16:47:24 ralph 7 6
c changes from Robert Elz to reorder the string table too.
e
s 00001/00001/00150
d D 4.4 83/07/02 00:55:44 sam 6 5
c include fixes
e
s 00002/00001/00149
d D 4.3 83/05/22 18:40:47 sam 5 4
c purge pagsiz.h
e
s 00001/00001/00149
d D 4.2 80/10/02 10:59:22 bill 4 3
c botched sccsid line.
e
s 00000/00000/00150
d D 4.1 80/10/01 16:40:04 bill 3 2
c Define 4.1
e
s 00002/00002/00148
d D 3.2 80/10/01 16:28:41 bill 2 1
c change reference to new a.out format.
e
s 00150/00000/00000
d D 3.1 80/08/15 01:55:22 bill 1 0
c date and time created 80/08/15 01:55:22 by bill
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 8
I 5
#ifndef lint
E 5
I 1
D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
D 4
static char *sccsid = "%W% (Berkeley) %G%;
E 4
I 4
D 8
static char *sccsid = "%W% (Berkeley) %G%";
I 5
#endif
E 8
I 8
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8
I 7

E 7
E 5
E 4
E 2
/*
 * symorder - reorder symbol table
 */
I 7

E 7
#include <stdio.h>
D 5
#include <pagsiz.h>
E 5
#include <sys/types.h>
D 6
#include <stat.h>
E 6
I 6
#include <sys/stat.h>
E 6
D 2
#include <newa.out.h>
E 2
I 2
#include <a.out.h>
E 2

#define SPACE 100

struct	nlist order[SPACE];

D 7
char	*savestr();
struct	nlist nl1, nl2;
E 7
I 7
char	*savestr(), *index(), *malloc();
E 7
struct	exec exec;
D 7
FILE	*strf;
off_t	sa, ss;
E 7
I 7
off_t	sa;
E 7
struct	stat stb;
int	nsym = 0;
int	symfound = 0;
I 7
char	*strings;
char	*newstrings;
struct	nlist *symtab;
struct	nlist *newtab;
int	symsize;
E 7
char	asym[BUFSIZ];

main(argc, argv)
	char **argv;
{
D 7
	register struct nlist *p, *q;
E 7
I 7
	register char *ns;
	register struct nlist *symp;
	register struct nlist *p;
E 7
	register FILE *f;
D 7
	register int na, i, j;
	int maxlen;
E 7
I 7
	register int i;
E 7
	int n, o;

D 7
	if(argc != 3) {
E 7
I 7
	if (argc != 3) {
E 7
		fprintf(stderr, "Usage: symorder orderlist file\n");
		exit(1);
	}
D 7
	if((f = fopen(argv[1], "r")) == NULL) {
E 7
I 7
	if ((f = fopen(argv[1], "r")) == NULL) {
E 7
		perror(argv[1]);
		exit(1);
	}
D 7
	maxlen = 0;
	for(p = order; fgets(asym, sizeof asym, f) != NULL; p++, nsym++) {
		for(i = 0; asym[i] && asym[i] != '\n'; i++)
E 7
I 7
	for (p = order; fgets(asym, sizeof asym, f) != NULL; p++, nsym++) {
		for (i = 0; asym[i] && asym[i] != '\n'; i++)
E 7
			continue;
		if (asym[i] == '\n')
			asym[i] = 0;
		p->n_un.n_name = savestr(asym);
D 7
		if (maxlen < strlen(p->n_un.n_name))
			maxlen = strlen(p->n_un.n_name);
E 7
	}
	fclose(f);
D 7
	if((f = fopen(argv[2], "r")) == NULL)
E 7
I 7
	if ((f = fopen(argv[2], "r")) == NULL)
E 7
		perror(argv[2]), exit(1);
D 7
	if((strf = fopen(argv[2], "r")) == NULL)
E 7
I 7
	if ((o = open(argv[2], 1)) < 0)
E 7
		perror(argv[2]), exit(1);
D 7
	if((o = open(argv[2], 1)) < 0)
		perror(argv[2]), exit(1);
	if((fread(&exec, sizeof exec, 1, f)) != 1 || N_BADMAG(exec)) {
E 7
I 7
	if ((fread(&exec, sizeof exec, 1, f)) != 1 || N_BADMAG(exec)) {
E 7
		fprintf(stderr, "symorder: %s: bad format\n", argv[2]);
		exit(1);
	}
	if (exec.a_syms == 0) {
		fprintf(stderr, "symorder: %s is stripped\n", argv[2]);
		exit(1);
	}
	fstat(fileno(f), &stb);
	if (stb.st_size < N_STROFF(exec)+sizeof(off_t)) {
D 7
		fprintf(stderr, "symorder: %s is in old format or truncated\n", argv[2]);
E 7
I 7
		fprintf(stderr, "symorder: %s is in old format or truncated\n",
		    argv[2]);
E 7
		exit(1);
	}
	sa = N_SYMOFF(exec);
D 7
	na = sa;
	ss = sa + exec.a_syms;
E 7
	fseek(f, sa, 0);
	n = exec.a_syms;
D 7
	while(n && symfound < nsym) {
		if(fread(&nl1, sizeof nl1, 1, f) != 1) {
			fprintf(stderr, "Short file "); perror(argv[2]);
E 7
I 7
	symtab = (struct nlist *)malloc(n);
	if (symtab == (struct nlist *)0) {
		fprintf(stderr, "symorder: Out of core, no space for symtab\n");
		exit(1);
	}
	if (fread((char *)symtab, 1, n, f) != n) {
		fprintf(stderr, "symorder: Short file "); perror(argv[2]);
		exit(1);
	}
	if (fread((char *)&symsize, sizeof (int), 1, f) != 1 ||
	    symsize <= 0) {
		fprintf(stderr, "symorder: No strings "); perror(argv[2]);
		exit(1);
	}
	strings = malloc(symsize);
	if (strings == (char *)0) {
		fprintf(stderr,"symorder: Out of core, no space for strings\n");
		exit(1);
	}
D 9
	if (fread(strings, 1, symsize, f) != symsize) {
E 9
I 9
	/*
	 * Need to subtract four from symsize here since
	 * symsize includes itself, and we've already read
	 * it.  (6/30/85 chris@maryland)
	 */
	if (fread(strings, 1, symsize - 4, f) != symsize - 4) {
E 9
		fprintf(stderr, "symorder: Truncated strings "); 
		perror(argv[2]);
		exit(1);
	}

	newtab = (struct nlist *)malloc(n);
	if (newtab == (struct nlist *)0) {
		fprintf(stderr,
		    "symorder: Out of core, no space for new symtab\n");
		exit(1);
	}
	i = n / sizeof (struct nlist);
	reorder(symtab, newtab, i);
	free((char *)symtab);
	symtab = newtab;

	newstrings = malloc(symsize);
	if (newstrings == (char *)0) {
		fprintf(stderr,
		    "symorder: Out of core, no space for newstrings\n");
		exit(1);
	}
	ns = newstrings;
	for (symp = symtab; --i >= 0; symp++) {
		if (symp->n_un.n_strx == 0)
			continue;
		symp->n_un.n_strx -= sizeof (int);
		if ((unsigned)symp->n_un.n_strx >= symsize) {
			fprintf(stderr,"symorder: Corrupted string pointers\n");
E 7
			exit(1);
		}
D 7
		na += sizeof nl1;
		n -= sizeof nl1;
		if (nl1.n_un.n_strx == 0 || nl1.n_type & N_STAB)
			continue;
		fseek(strf, ss+nl1.n_un.n_strx, 0);
		fread(asym, maxlen+1, 1, strf);
		for(j = 0; j < nsym; j++) {
			for(i = 0; asym[i]; i++)
				if(asym[i] != order[j].n_un.n_name[i])
					goto cont;
			if (order[j].n_un.n_name[i])
				goto cont;
			if (order[j].n_value)
				goto cont;
			order[j].n_value = 1;
			fseek(f, (i = (sa+(j * sizeof nl1))), 0);
			if(fread(&nl2, sizeof nl2, 1, f) != 1)
				printf("Read err on 2nd asym\n");
			lseek(o, i, 0);
			if(write(o, &nl1, sizeof nl1) == -1)
				perror("write1");
			lseek(o, na-sizeof nl1, 0);
			if(write(o, &nl2, sizeof nl2) == -1)
				perror("write2");
			fseek(f, 0, 0);
			fseek(f, na, 0);
			symfound++;
			break;
	cont:           ;

E 7
I 7
		strcpy(ns, &strings[symp->n_un.n_strx]);
		symp->n_un.n_strx = (ns - newstrings) + sizeof (int);
		ns = index(ns, 0) + 1;
		if (ns > &newstrings[symsize]) {
			fprintf(stderr, "symorder: Strings grew longer!\n");
			exit(1);
E 7
		}
	}
D 7
	if(symfound < nsym) {
		fprintf(stderr, "%d symbol(s) not found:\n", nsym - symfound);
E 7
I 7

	lseek(o, sa, 0);
	if (write(o, (char *)symtab, n) != n) {
		fprintf(stderr, "symorder: Write failed "); perror(argv[2]);
		exit(1);
	}
	if (write(o, (char *)&symsize, sizeof (int)) != sizeof (int)) {
		fprintf(stderr, "symorder: Write failed "); perror(argv[2]);
		exit(1);
	}
D 9
	if (write(o, newstrings, symsize) != symsize) {
E 9
I 9
	if (write(o, newstrings, symsize - 4) != symsize - 4) {
E 9
		fprintf(stderr, "symorder: Write failed "); perror(argv[2]);
		exit(1);
	}
	if ((i = nsym - symfound) > 0) {
		fprintf(stderr, "symorder: %d symbol%s not found:\n",
		    i, i == 1 ? "" : "s");
E 7
		for (i = 0; i < nsym; i++) {
			if (order[i].n_value == 0)
				printf("%s\n", order[i].n_un.n_name);
		}
	}
I 7
	exit(0);
}

reorder(st1, st2, n)
	register struct nlist *st1, *st2;
	register n;
{
	register struct nlist *stp = st2 + nsym;
	register i;

	while (--n >= 0) {
		i = inlist(st1);
		if (i == -1)
			*stp++ = *st1++;
		else
			st2[i] = *st1++;
	}
}

inlist(p)
	register struct nlist *p;
{
	register char *nam;
	register struct nlist *op;

	if (p->n_type & N_STAB)
		return (-1);
	if (p->n_un.n_strx == 0)
		return (-1);

	nam = &strings[p->n_un.n_strx - sizeof(int)];
	if (nam >= &strings[symsize]) {
		fprintf(stderr, "symorder: corrupt symtab\n");
		exit(1);
	}

	for (op = &order[nsym]; --op >= order; ) {
		if (strcmp(op->n_un.n_name, nam) != 0)
			continue;
		if (op->n_value == 0) {
			op->n_value++;
			symfound++;
		}
		return (op - order);
	}
	return (-1);
E 7
}

#define	NSAVETAB	4096
char	*savetab;
int	saveleft;

char *
savestr(cp)
	register char *cp;
{
	register int len;

	len = strlen(cp) + 1;
	if (len > saveleft) {
		saveleft = NSAVETAB;
		if (len > saveleft)
			saveleft = len;
		savetab = (char *)malloc(saveleft);
		if (savetab == 0) {
			fprintf(stderr,
			    "symorder: ran out of memory (savestr)\n");
			exit(1);
		}
	}
	strncpy(savetab, cp, len);
	cp = savetab;
	savetab += len;
	saveleft -= len;
	return (cp);
}
E 1
