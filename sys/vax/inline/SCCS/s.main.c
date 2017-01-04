h42274
s 00002/00002/00367
d D 7.1 86/06/05 01:12:54 mckusick 13 12
c 4.3BSD release version
e
s 00007/00005/00362
d D 1.12 86/05/08 22:02:02 karels 12 11
c test?  did I say test?
e
s 00002/00002/00365
d D 1.11 86/05/03 12:51:45 bloom 11 10
c fix argument handling
e
s 00034/00004/00333
d D 1.10 86/04/27 20:54:03 karels 10 9
c break out tables for subset vax on -s option; for kridle and bloom
e
s 00045/00002/00292
d D 1.9 85/08/22 16:35:41 mckusick 9 8
c do validity checking on number of arguments (from donn@utah-cs)
e
s 00012/00002/00282
d D 1.8 85/06/08 14:24:38 mckusick 8 7
c Add copyright
e
s 00012/00007/00272
d D 1.7 85/03/20 12:58:24 mckusick 7 6
c need to be a bit more careful about identifying labels
e
s 00003/00001/00276
d D 1.6 84/09/20 12:30:55 mckusick 6 5
c add provision for mc68000
e
s 00025/00001/00252
d D 1.5 84/08/20 21:39:04 mckusick 5 4
c add provision to gather statistics
e
s 00050/00021/00203
d D 1.4 84/08/20 21:03:56 mckusick 4 3
c add instruction stop table; 
c generalize the hash function; 
c untangle logic in `expand'
e
s 00018/00017/00206
d D 1.3 84/08/20 19:09:35 mckusick 3 2
c cleanup of initialization code
e
s 00001/00001/00222
d D 1.2 84/08/18 18:04:49 mckusick 2 1
c change name of header file from pc2.h to inline.h
e
s 00223/00000/00000
d D 1.1 84/08/18 17:35:41 mckusick 1 0
c date and time created 84/08/18 17:35:41 by mckusick
e
u
U
t
T
I 1
D 8
/* Copyright (c) 1984 Regents of the University of California */
E 8
I 8
/*
D 13
 * Copyright (c) 1984 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1984, 1986 Regents of the University of California.
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 8

#ifndef lint
D 8
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 8
I 8
char copyright[] =
D 13
"%Z% Copyright (c) 1984 Regents of the University of California.\n\
E 13
I 13
"%Z% Copyright (c) 1984, 1986 Regents of the University of California.\n\
E 13
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
#endif not lint

#include <stdio.h>
#include <ctype.h>
D 2
#include "pc2.h"
E 2
I 2
#include "inline.h"
E 2

I 3
/*
 * These are the pattern tables to be loaded
 */
D 10
struct pats *inittables[] = {
E 10
I 10
struct pats *vax_inittables[] = {
E 10
	language_ptab,
	libc_ptab,
I 10
	vax_libc_ptab,
E 10
	machine_ptab,
I 10
	vax_ptab,
E 10
	0
};

I 10
struct pats *vaxsubset_inittables[] = {
	language_ptab,
	libc_ptab,
	vaxsubset_libc_ptab,
	machine_ptab,
	vaxsubset_ptab,
	0
};

E 10
I 5
/*
 * Statistics collection
 */
struct stats {
	int	attempted;	/* number of expansion attempts */
	int	finished;	/* expansions done before end of basic block */
	int	lostmodified;	/* mergers inhibited by intervening mod */
	int	savedpush;	/* successful push/pop merger */
} stats;
I 9

extern char *strcpy();

char *whoami;
int lineno = 0;
E 9
int dflag;

E 5
E 3
main(argc, argv)
	int argc;
	char *argv[];
{
D 4
	register struct pats *pp, **hp;
E 4
	register char *cp, *lp;
	register char *bufp;
I 3
D 4
	register struct pats **tablep;
E 4
I 4
	register struct pats *pp, **php;
	struct pats **tablep;
	register struct inststoptbl *itp, **ithp;
E 4
E 3
	int size;
	extern char *index();
I 10
	int subset = 0;
E 10

I 9
	whoami = argv[0];
E 9
I 5
D 10
	if (argc > 1 && bcmp(argv[1], "-d", 3) == 0)
		dflag++, argc--, argv++;
E 10
I 10
D 11
	while (argc > 0 && argv[0][0] == '-') {
		switch(argv[0][1]) {
E 11
I 11
D 12
	while (argc > 1 && argv[1][0] == '-') {
		switch(argv[1][1]) {
E 12
I 12
	argc--;
	argv++;
	while (argc > 0 && argv[0][0] == '-') {
		switch(argv[0][1]) {
E 12
E 11

		case 's':
			subset++;
			break;

		case 'd':
			dflag++;
			break;

		default:
			break;
		}
		argc--, argv++;
	}
I 12
	if (argc > 0)
		freopen(argv[0], "r", stdin);
E 12
E 10
E 5
	if (argc > 1)
D 12
		freopen(argv[1], "r", stdin);
	if (argc > 2)
		freopen(argv[2], "w", stdout);
E 12
I 12
		freopen(argv[1], "w", stdout);
E 12
	/*
D 4
	 * set up the hash table
E 4
I 4
	 * Set up the hash table for the patterns.
E 4
	 */
D 3
	for (pp = language_ptab; pp->name[0] != '\0'; pp++) {
		hp = hash(pp->name, &size);
		pp->size = size;
		pp->next = *hp;
		*hp = pp;
	}
	for (pp = libc_ptab; pp->name[0] != '\0'; pp++) {
		hp = hash(pp->name, &size);
		pp->size = size;
		pp->next = *hp;
		*hp = pp;
	}
	for (pp = machine_ptab; pp->name[0] != '\0'; pp++) {
		hp = hash(pp->name, &size);
		pp->size = size;
		pp->next = *hp;
		*hp = pp;
E 3
I 3
D 10
	for (tablep = inittables; *tablep; tablep++) {
E 10
I 10
	if (subset)
		tablep = vaxsubset_inittables;
	else
		tablep = vax_inittables;
	for ( ; *tablep; tablep++) {
E 10
		for (pp = *tablep; pp->name[0] != '\0'; pp++) {
D 4
			hp = hash(pp->name, &size);
E 4
I 4
			php = &patshdr[hash(pp->name, &size)];
E 4
			pp->size = size;
D 4
			pp->next = *hp;
			*hp = pp;
E 4
I 4
			pp->next = *php;
			*php = pp;
E 4
		}
E 3
	}
	/*
I 4
	 * Set up the hash table for the instruction stop table.
	 */
	for (itp = inststoptable; itp->name[0] != '\0'; itp++) {
		ithp = &inststoptblhdr[hash(itp->name, &size)];
		itp->size = size;
		itp->next = *ithp;
		*ithp = itp;
	}
	/*
E 4
	 * check each line and replace as appropriate
	 */
	buftail = bufhead = 0;
	bufp = line[0];
	while (fgets(bufp, MAXLINELEN, stdin)) {
I 9
		lineno++;
E 9
		lp = index(bufp, LABELCHAR);
		if (lp != NULL) {
D 7
			bufp = newline();
			if (*++lp == '\n') {
E 7
I 7
			for (cp = bufp; cp < lp; cp++)
				if (!isalnum(*cp))
					break;
			if (cp == lp) {
				bufp = newline();
				if (*++lp == '\n') {
					emptyqueue();
					continue;
				}
D 9
				strcpy(bufp, lp);
E 9
I 9
				(void) strcpy(bufp, lp);
E 9
				*lp++ = '\n';
				*lp = '\0';
E 7
				emptyqueue();
D 7
				continue;
E 7
			}
D 7
			strcpy(bufp, lp);
			*lp++ = '\n';
			*lp = '\0';
			emptyqueue();
E 7
		}
		for (cp = bufp; isspace(*cp); cp++)
			/* void */;
		if ((cp = doreplaceon(cp)) == 0) {
			bufp = newline();
			continue;
		}
D 4
		for (pp = *hash(cp, &size); pp; pp = pp->next) {
E 4
I 4
		for (pp = patshdr[hash(cp, &size)]; pp; pp = pp->next) {
E 4
			if (pp->size == size && bcmp(pp->name, cp, size) == 0) {
I 9
				if (argcounterr(pp->args, countargs(bufp), pp->name)) {
					pp = NULL;
					break;
				}
E 9
				expand(pp->replace);
				bufp = line[bufhead];
				break;
			}
		}
		if (!pp) {
			emptyqueue();
			fputs(bufp, stdout);
		}
	}
	emptyqueue();
I 5
	if (dflag)
D 9
		fprintf(stderr, "inline: %s %d, %s %d, %s %d, %s %d\n",
E 9
I 9
		fprintf(stderr, "%s: %s %d, %s %d, %s %d, %s %d\n",
			whoami,
E 9
			"attempts", stats.attempted,
			"finished", stats.finished,
			"inhibited", stats.lostmodified,
			"merged", stats.savedpush);
E 5
	exit(0);
}

/*
 * Integrate an expansion into the assembly stream
 */
expand(replace)
	char *replace;
{
	register int curptr;
	char *nextreplace, *argv[MAXARGS];
D 4
	int argc, argreg, queueempty, mod = 0;
E 4
I 4
D 6
	int argc, argreg, foundarg, mod = 0;
E 6
I 6
	int argc, argreg, foundarg, mod = 0, args = 0;
E 6
E 4
	char parsebuf[BUFSIZ];

D 5
	for (curptr = bufhead; curptr != buftail; ) {
E 5
I 5
	stats.attempted++;
	for (curptr = bufhead; ; ) {
E 5
D 4
		queueempty = (curptr == buftail);
		curptr = PRED(curptr);
E 4
		nextreplace = copyline(replace, line[bufhead]);
		argc = parseline(line[bufhead], argv, parsebuf);
		argreg = nextarg(argc, argv);
		if (argreg == -1)
			break;
I 6
		args++;
E 6
D 4
		while (!queueempty) {
E 4
I 4
		for (foundarg = 0; curptr != buftail; ) {
			curptr = PRED(curptr);
E 4
			argc = parseline(line[curptr], argv, parsebuf);
D 4
			if (ispusharg(argc, argv))
E 4
I 4
			if (isendofblock(argc, argv))
E 4
				break;
I 4
			if (foundarg = ispusharg(argc, argv))
				break;
E 4
			mod |= 1 << modifies(argc, argv);
D 4
			queueempty = (curptr == buftail);
			curptr = PRED(curptr);
E 4
		}
D 4
		if (queueempty)
E 4
I 4
		if (!foundarg)
E 4
			break;
		replace = nextreplace;
		if (mod & (1 << argreg)) {
I 5
			stats.lostmodified++;
E 5
I 4
			if (curptr == buftail) {
				(void)newline();
				break;
			}
E 4
			(void)newline();
		} else {
I 5
			stats.savedpush++;
E 5
			rewrite(line[curptr], argc, argv, argreg);
			mod |= 1 << argreg;
		}
	}
I 5
	if (argreg == -1)
		stats.finished++;
E 5
	emptyqueue();
	fputs(replace, stdout);
I 6
	cleanup(args);
E 6
}

/*
 * Parse a line of assembly language into opcode and arguments.
 */
parseline(linep, argv, linebuf)
	char *linep;
	char *argv[];
	char *linebuf;
{
	register char *bufp = linebuf, *cp = linep;
	register int argc = 0;

	for (;;) {
		/*
		 * skip over white space
		 */
		while (isspace(*cp))
			cp++;
		if (*cp == '\0')
			return (argc);
		/*
		 * copy argument
		 */
		if (argc == MAXARGS - 1) {
			fprintf(stderr, "instruction too long->%s", linep);
			return (argc);
		}
		argv[argc++] = bufp;
D 4
		while (!isspace(*cp) && *cp != ',' && *cp != COMMENTCHAR)
E 4
I 4
		while (!isspace(*cp) && *cp != ARGSEPCHAR && *cp != COMMENTCHAR)
E 4
			*bufp++ = *cp++;
		*bufp++ = '\0';
		if (*cp == COMMENTCHAR)
			return (argc);
D 4
		if (*cp == ',')
E 4
I 4
		if (*cp == ARGSEPCHAR)
E 4
			cp++;
	}
}

/*
I 4
 * Check for instructions that end a basic block.
 */
isendofblock(argc, argv)
	int argc;
	char *argv[];
{
	register struct inststoptbl *itp;
	int size;

	if (argc == 0)
		return (0);
	for (itp = inststoptblhdr[hash(argv[0], &size)]; itp; itp = itp->next)
		if (itp->size == size && bcmp(argv[0], itp->name, size) == 0)
			return (1);
	return (0);
}

/*
E 4
 * Copy a newline terminated string.
 * Return pointer to character following last character copied.
 */
char *
copyline(from, to)
	register char *from, *to;
{

	while (*from != '\n')
		*to++ = *from++;
	*to++ = *from++;
	*to = '\0';
	return (from);
I 9
}

/*
 * Check for a disparity between the number of arguments a function
 * is called with and the number which we expect to see.
 * If the error is unrecoverable, return 1, otherwise 0.
 */
argcounterr(args, callargs, name)
	int args, callargs;
	char *name;
{
	register char *cp;
	char namebuf[MAXLINELEN];

	if (args == callargs)
		return (0);
	cp = strcpy(namebuf, name);
	while (*cp != '\0' && *cp != '\n')
		++cp;
	if (*cp == '\n')
		*cp = '\0';
	if (callargs >= 0) {
		fprintf(stderr,
		"%s: error: arg count mismatch, %d != %d for '%s' at line %d\n",
			whoami, callargs, args, namebuf, lineno);
		return (1);
	}
	fprintf(stderr,
		"%s: warning: can't verify arg count for '%s' at line %d\n",
		whoami, namebuf, lineno);
	return (0);
E 9
}

/*
 * open space for next line in the queue
 */
char *
newline()
{
	bufhead = SUCC(bufhead);
	if (bufhead == buftail) {
		fputs(line[buftail], stdout);
		buftail = SUCC(buftail);
	}
	return (line[bufhead]);
}

/*
 * empty the queue by printing out all its lines.
 */
emptyqueue()
{
	while (buftail != bufhead) {
		fputs(line[buftail], stdout);
		buftail = SUCC(buftail);
	}
}

/*
 * Compute the hash of a string.
 * Return the hash and the size of the item hashed
 */
D 4
struct pats **
E 4
hash(cp, size)
	char *cp;
	int *size;
{
	register char *cp1 = cp;
D 4
	register int hash;
E 4
I 4
	register int hash = 0;
E 4

D 4
	hash = 1;
E 4
	while (*cp1 && *cp1 != '\n')
		hash += (int)*cp1++;
	*size = cp1 - cp + 1;
	hash &= HSHSIZ - 1;
D 4
	return (&hashhdr[hash]);
E 4
I 4
	return (hash);
E 4
}
E 1
