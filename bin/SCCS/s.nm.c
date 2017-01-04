h56829
s 00261/00228/00120
d D 4.8 87/04/07 17:25:35 bostic 11 10
c bug report 4.2BSD/bin/31 (well, that's how it started...)
e
s 00005/00003/00343
d D 4.7 86/05/19 18:13:51 karels 10 9
c don't print binary
e
s 00002/00002/00344
d D 4.6 85/01/22 17:05:34 ralph 9 8
c close files before returning.
e
s 00004/00002/00342
d D 4.5 84/11/26 12:35:11 ralph 8 7
c don't quit if __SYMDEF should happen to have a valid a.out magic #.
e
s 00000/00000/00344
d D 4.4 83/07/01 23:57:01 wnj 7 6
c include problems
e
s 00001/00001/00343
d D 4.3 83/06/30 14:51:10 sam 6 5
c include fix
e
s 00002/00001/00342
d D 4.2 83/05/22 18:32:27 sam 5 4
c pagsiz.h must go....
e
s 00000/00000/00343
d D 4.1 80/10/01 16:39:34 bill 4 3
c Define 4.1
e
s 00001/00000/00342
d D 3.3 80/09/09 16:04:47 bill 3 2
c added N_PC to stbnames, since i added it to <stab.h>
e
s 00003/00003/00339
d D 3.2 80/08/17 01:55:36 bill 2 1
c typo in .o length check
e
s 00342/00000/00000
d D 3.1 80/08/15 01:55:17 bill 1 0
c date and time created 80/08/15 01:55:17 by bill
e
u
U
t
T
I 11
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 11
I 5
#ifndef lint
E 5
I 1
static	char sccsid[] = "%Z%%M% %I% %G%";
I 5
#endif
I 11

E 11
E 5
/*
 * nm - print name list; VAX string table version
 */
I 11

E 11
#include <sys/types.h>
I 11
#include <sys/file.h>
E 11
D 2
#include <newar.h>
E 2
I 2
#include <ar.h>
E 2
#include <stdio.h>
#include <ctype.h>
D 2
#include <newa.out.h>
E 2
I 2
#include <a.out.h>
E 2
#include <stab.h>
D 5
#include <pagsiz.h>
E 5
D 6
#include <stat.h>
E 6
I 6
D 11
#include <sys/stat.h>
E 11
I 11
#include <ranlib.h>
E 11
E 6

D 11
#define	SELECT	archive ? archdr.ar_name : *xargv
E 11
I 11
#define	OARMAG		0177545		/* OLD archive magic number */
#define	SELECT		(archive ? archdr.ar_name : *xargv)
E 11

D 11
int	aflg, gflg, nflg, oflg, pflg, uflg; 
int	rflg = 1;
char	**xargv;
int	archive;
struct	ar_hdr	archdr;
union {
	char	mag_armag[SARMAG+1];
E 11
I 11
#define	YES		1
#define	NO		0

#define	u_strx		n_un.n_strx
#define	u_name		n_un.n_name

typedef struct nlist	NLIST;

union {				/* exec header, or magic string from library */
	char	mag_armag[SARMAG + 1];
E 11
	struct	exec mag_exp;
} mag_un;
D 11
#define	OARMAG	0177545
FILE	*fi;
off_t	off;
off_t	ftell();
char	*malloc();
char	*realloc();
char	*strp;
char	*stab();
off_t	strsiz;
int	compare();
int	narg;
int	errs;
E 11

I 11
struct	ar_hdr	archdr;		/* archive file header structure */
FILE	*fi;			/* input file stream */
off_t	off;			/* offset into file */
int	aflg,			/* print debugger symbols */
	gflg,			/* print only global (external symbols */
	nflg,			/* sort numerically, not alphabetically */
	oflg,			/* prepend element name to each output line */
	pflg,			/* don't sort */
	rflg = 1,		/* how to sort */
	uflg,			/* print only undefined symbols */
	narg,			/* global number of arguments */
	errs,			/* global error flag */
	archive;		/* if file is an archive */
char	**xargv;		/* global pointer to file name */

E 11
main(argc, argv)
D 11
char **argv;
E 11
I 11
	int	argc;
	char	**argv;
E 11
{
I 11
	extern int	optind;
	int	ch;			/* getopts char */
E 11

D 11
	if (--argc>0 && argv[1][0]=='-' && argv[1][1]!=0) {
		argv++;
		while (*++*argv) switch (**argv) {

		case 'n':
			nflg++;
			continue;
E 11
I 11
	while ((ch = getopt(argc, argv, "agnopru")) != EOF)
		switch((char)ch) {
		case 'a':
			aflg = YES;
			break;
E 11
		case 'g':
D 11
			gflg++;
			continue;
		case 'u':
			uflg++;
			continue;
E 11
I 11
			gflg = YES;
			break;
		case 'n':
			nflg = YES;
			break;
		case 'o':
			oflg = YES;
			break;
		case 'p':
			pflg = YES;
			break;
E 11
		case 'r':
			rflg = -1;
D 11
			continue;
		case 'p':
			pflg++;
			continue;
		case 'o':
			oflg++;
			continue;
		case 'a':
			aflg++;
			continue;
E 11
I 11
			break;
		case 'u':
			uflg = YES;
			break;
		case '?':
E 11
		default:
D 11
			fprintf(stderr, "nm: invalid argument -%c\n",
			    *argv[0]);
E 11
I 11
			fputs("usage: nm [-agnopru] [file ...]\n", stderr);
E 11
			exit(2);
		}
D 11
		argc--;
	}
	if (argc == 0) {
E 11
I 11
	argc -= optind;
	argv += optind;
	if (!argc) {
E 11
		argc = 1;
D 11
		argv[1] = "a.out";
E 11
I 11
		argv[0] = "a.out";
E 11
	}
	narg = argc;
D 11
	xargv = argv;
	while (argc--) {
		++xargv;
		namelist();
	}
E 11
I 11
	for (xargv = argv; argc--; ++xargv)
		if (fi = fopen(*xargv, "r")) {
			namelist();
			(void)fclose(fi);
		}
		else
			error(NO, "cannot open");
E 11
	exit(errs);
}

namelist()
{
D 11
	register int j;
E 11
I 11
	register NLIST	*N, **L;
	register int	symcount, nsyms;
	static	NLIST	*symp, **list;
	static int	lastnsyms = -1,
			laststrsiz = -1;
	static char	*strp;
	off_t	strsiz;
	long	lseek();
	int	compare();
	char	*malloc(), *realloc();
E 11

D 11
	archive = 0;
	fi = fopen(*xargv, "r");
	if (fi == NULL) {
		error(0, "cannot open");
E 11
I 11
	/*
	 * read first few bytes, determine if an archive,
	 * or executable; if executable, check magic number
	 */
	/*NOSTRICT*/
	if (!fread((char *)&mag_un, sizeof(mag_un), 1, fi)) {
		error(NO, "unable to read file");
E 11
		return;
	}
D 11
	off = SARMAG;
	fread((char *)&mag_un, 1, sizeof(mag_un), fi);
E 11
	if (mag_un.mag_exp.a_magic == OARMAG) {
D 11
		error(0, "old archive");
D 9
		return;
E 9
I 9
		goto out;
E 11
I 11
		error(NO, "old archive");
		return;
E 11
E 9
	}
D 11
	if (strncmp(mag_un.mag_armag, ARMAG, SARMAG)==0)
		archive++;
	else if (N_BADMAG(mag_un.mag_exp)) {
		error(0, "bad format");
D 9
		return;
E 9
I 9
		goto out;
E 11
I 11
	if (bcmp(mag_un.mag_armag, ARMAG, SARMAG)) {
		if (N_BADMAG(mag_un.mag_exp)) {
			error(NO, "bad format");
			return;
		}
		archive = NO;
		rewind(fi);
E 11
E 9
	}
D 11
	fseek(fi, 0L, 0);
	if (archive) {
		nextel(fi);
E 11
I 11
	else {
		/*
		 * if archive, skip first entry
		 * if ranlib'd, skip second entry
		 */
		off = SARMAG;		/* see nextel() */
		(void)nextel();
		if (!strcmp(RANLIBMAG, archdr.ar_name))
			(void)nextel();
E 11
		if (narg > 1)
			printf("\n%s:\n", *xargv);
I 11
		archive = YES;
E 11
	}
D 11
	do {
		off_t o;
		register i, n, c;
		struct nlist *symp = NULL;
		struct nlist sym;
		struct stat stb;
E 11

D 11
		fread((char *)&mag_un.mag_exp, 1, sizeof(struct exec), fi);
E 11
I 11
	do {
		/* check for bad magic number */
		/*NOSTRICT*/
		if (!fread((char *)&mag_un.mag_exp, sizeof(struct exec), 1, fi)) {
			error(NO, "unable to read magic number");
			return;
		}
E 11
		if (N_BADMAG(mag_un.mag_exp))
			continue;
D 11
		if (archive == 0)
			fstat(fileno(fi), &stb);
		o = N_SYMOFF(mag_un.mag_exp) - sizeof (struct exec);
		fseek(fi, o, 1);
		n = mag_un.mag_exp.a_syms / sizeof(struct nlist);
		if (n == 0) {
			error(0, "no name list");
E 11
I 11

		/* calculate number of symbols in object */
		if (!(nsyms = mag_un.mag_exp.a_syms / sizeof(NLIST))) {
			error(NO, "no name list");
E 11
			continue;
		}
D 11
		if (N_STROFF(mag_un.mag_exp) + sizeof (off_t) >
D 2
		    stb.st_size)
E 2
I 2
D 8
		    (archive ? off : stb.st_size))
E 2
			error(1, "old format .o (no string table) or truncated file");
E 8
I 8
		    (archive ? off : stb.st_size)) {
			error(0, "old format .o (no string table) or truncated file");
E 11
I 11

		/* seek to and read symbols */
		(void)fseek(fi, (long)(N_SYMOFF(mag_un.mag_exp) - sizeof(struct exec)), L_INCR);
		if (!symp || nsyms > lastnsyms) {
			if (!symp) {
				/*NOSTRICT*/
				symp = (NLIST *)malloc((u_int)(nsyms * sizeof(NLIST)));
				/*NOSTRICT*/
				list = (NLIST **)malloc((u_int)(nsyms * sizeof(NLIST *)));
			}
			else {
				/*NOSTRICT*/
				symp = (NLIST *)realloc((char *)symp, (u_int)(nsyms * sizeof(NLIST)));
				/*NOSTRICT*/
				list = (NLIST **)realloc((char *)list, (u_int)(nsyms * sizeof(NLIST *)));
			}
			if (!symp || !list)
				error(YES, "out of memory");
			lastnsyms = nsyms;
		}
		/*NOSTRICT*/
		if (fread((char *)symp, sizeof(NLIST), nsyms, fi) != nsyms) {
			error(NO, "bad symbol table");
E 11
			continue;
		}
E 8
D 11
		i = 0;
		if (strp)
			free(strp), strp = 0;
		while (--n >= 0) {
			fread((char *)&sym, 1, sizeof(sym), fi);
			if (gflg && (sym.n_type&N_EXT)==0)
				continue;
			if ((sym.n_type&N_STAB) && (!aflg||gflg||uflg))
				continue;
			if (symp==NULL)
				symp = (struct nlist *)
				    malloc(sizeof(struct nlist));
			else
				symp = (struct nlist *)
				    realloc(symp,
					(i+1)*sizeof(struct nlist));
			if (symp == NULL)
				error(1, "out of memory");
			symp[i++] = sym;
		}
		if (archive && ftell(fi)+sizeof(off_t) >= off) {
			error(0, "no string table (old format .o?)");
E 11
I 11

		/* read number of strings, string table */
		/*NOSTRICT*/
		if (!fread((char *)&strsiz, sizeof(strsiz), 1, fi)) {
			error(NO, "no string table (old format .o?)");
E 11
			continue;
		}
D 11
		if (fread((char *)&strsiz,sizeof(strsiz),1,fi) != 1) {
			error(0, "no string table (old format .o?)");
			goto out;
E 11
I 11
		if (!strp || strsiz > laststrsiz) {
			strp = strp ? realloc(strp, (u_int)strsiz) : malloc((u_int)strsiz);
			if (!strp)
				error(YES, "out of memory");
			laststrsiz = strsiz;
E 11
		}
D 11
		strp = (char *)malloc(strsiz);
		if (strp == NULL)
			error(1, "ran out of memory");
		if (fread(strp+sizeof(strsiz),strsiz-sizeof(strsiz),1,fi) != 1)
			error(1, "error reading string table");
		for (j = 0; j < i; j++)
			if (symp[j].n_un.n_strx)
				symp[j].n_un.n_name =
				    symp[j].n_un.n_strx + strp;
			else
				symp[j].n_un.n_name = "";
		if (pflg==0)
			qsort(symp, i, sizeof(struct nlist), compare);
		if ((archive || narg>1) && oflg==0)
E 11
I 11
		if (!fread(strp + sizeof(strsiz), 1, (int)(strsiz - sizeof(strsiz)), fi)) {
			error(NO, "no string table (old format .o?)");
			continue;
		}

		for (symcount = nsyms, L = list, N = symp;--nsyms >= 0;++N)
			if (!(N->n_type & N_EXT) && gflg || N->n_type & N_STAB && (!aflg || gflg || uflg))
				--symcount;
			else {
				N->u_name = N->u_strx ? strp + N->u_strx : "";
				*L++ = N;
			}

		if (!pflg)
			qsort(list, symcount, sizeof(NLIST *), compare);

		if ((archive || narg > 1) && !oflg)
E 11
			printf("\n%s:\n", SELECT);
D 11
		psyms(symp, i);
		if (symp)
			free((char *)symp), symp = 0;
		if (strp)
			free((char *)strp), strp = 0;
	} while(archive && nextel(fi));
out:
	fclose(fi);
E 11
I 11

		psyms(list, symcount);
	} while(archive && nextel());
E 11
}

D 11
psyms(symp, nsyms)
	register struct nlist *symp;
	int nsyms;
E 11
I 11
psyms(list, nsyms)
	NLIST	**list;
	register int	nsyms;
E 11
{
D 11
	register int n, c;
E 11
I 11
	register NLIST	*L;
	register u_char	type;
	char	*stab();
E 11

D 11
	for (n=0; n<nsyms; n++) {
		c = symp[n].n_type;
		if (c & N_STAB) {
E 11
I 11
	while (nsyms--) {
		L = *list++;
		type = L->n_type;
		if (type & N_STAB) {
E 11
			if (oflg) {
				if (archive)
					printf("%s:", *xargv);
				printf("%s:", SELECT);
			}
D 11
			printf("%08x - %02x %04x %5.5s %s\n",
			    symp[n].n_value,
			    symp[n].n_other & 0xff, symp[n].n_desc & 0xffff,
			    stab(symp[n].n_type & 0xff),
			    symp[n].n_un.n_name);
E 11
I 11
			printf("%08x - %02x %04x %5.5s %s\n", (int)L->n_value, L->n_other & 0xff, L->n_desc & 0xffff, stab(L->n_type), L->u_name);
E 11
			continue;
		}
D 10
		switch (c&N_TYPE) {
E 10
I 10
D 11
		if (c == N_FN)
			c = 'f';
		else switch (c&N_TYPE) {
E 10

E 11
I 11
		switch (type & N_TYPE) {
E 11
		case N_UNDF:
D 11
			c = 'u';
			if (symp[n].n_value)
				c = 'c';
E 11
I 11
			type = L->n_value ? 'c' : 'u';
E 11
			break;
		case N_ABS:
D 11
			c = 'a';
E 11
I 11
			type = 'a';
E 11
			break;
		case N_TEXT:
D 11
			c = 't';
E 11
I 11
			type = 't';
E 11
			break;
		case N_DATA:
D 11
			c = 'd';
E 11
I 11
			type = 'd';
E 11
			break;
		case N_BSS:
D 11
			c = 'b';
E 11
I 11
			type = 'b';
E 11
			break;
I 11
		case N_FN:
			type = 'f';
			break;
E 11
D 10
		case N_FN:
			c = 'f';
E 10
I 10
		default:
D 11
			c = '?';
E 11
I 11
			type = '?';
E 11
E 10
			break;
		}
D 11
		if (uflg && c!='u')
E 11
I 11
		if (uflg && type != 'u')
E 11
			continue;
		if (oflg) {
			if (archive)
				printf("%s:", *xargv);
			printf("%s:", SELECT);
		}
D 11
		if (symp[n].n_type&N_EXT)
			c = toupper(c);
E 11
I 11
		if (L->n_type & N_EXT)
			type = toupper(type);
E 11
		if (!uflg) {
D 11
			if (c=='u' || c=='U')
				printf("        ");
E 11
I 11
			if (type == 'u' || type == 'U')
				fputs("        ", stdout);
E 11
			else
D 11
				printf(N_FORMAT, symp[n].n_value);
			printf(" %c ", c);
E 11
I 11
				printf(N_FORMAT, (int)L->n_value);
			printf(" %c ", (char)type);
E 11
		}
D 11
		printf("%s\n", symp[n].n_un.n_name);
l1:		;
E 11
I 11
		puts(L->u_name);
E 11
	}
}

compare(p1, p2)
D 11
struct nlist *p1, *p2;
E 11
I 11
	NLIST	**p1, **p2;
E 11
{
D 11
	register i;

E 11
	if (nflg) {
D 11
		if (p1->n_value > p2->n_value)
E 11
I 11
		if ((*p1)->n_value > (*p2)->n_value)
E 11
			return(rflg);
D 11
		if (p1->n_value < p2->n_value)
E 11
I 11
		if ((*p1)->n_value < (*p2)->n_value)
E 11
			return(-rflg);
	}
D 11
	return (rflg * strcmp(p1->n_un.n_name, p2->n_un.n_name));
E 11
I 11
	return(rflg * strcmp((*p1)->u_name, (*p2)->u_name));
E 11
}

D 11
nextel(af)
FILE *af;
E 11
I 11
nextel()
E 11
{
D 11
	register char *cp;
	register r;
	long arsize;
E 11
I 11
	register char	*cp;
	long	arsize,
		lseek();
E 11

D 11
	fseek(af, off, 0);
	r = fread((char *)&archdr, 1, sizeof(struct ar_hdr), af);
	if (r != sizeof(struct ar_hdr))
E 11
I 11
	(void)fseek(fi, off, L_SET);
	/*NOSTRICT*/
	if (!fread((char *)&archdr, sizeof(struct ar_hdr), 1, fi))
E 11
		return(0);
D 11
	for (cp = archdr.ar_name; cp < &archdr.ar_name[sizeof(archdr.ar_name)]; cp++)
		if (*cp == ' ')
E 11
I 11
	for (cp = archdr.ar_name; cp < &archdr.ar_name[sizeof(archdr.ar_name)]; ++cp)
		if (*cp == ' ') {
E 11
			*cp = '\0';
I 11
			break;
		}
E 11
	arsize = atol(archdr.ar_size);
	if (arsize & 1)
		++arsize;
D 11
	off = ftell(af) + arsize;	/* beginning of next element */
E 11
I 11
	off = ftell(fi) + arsize;	/* beginning of next element */
E 11
	return(1);
}

D 11
error(n, s)
char *s;
{
	fprintf(stderr, "nm: %s:", *xargv);
	if (archive) {
		fprintf(stderr, "(%s)", archdr.ar_name);
		fprintf(stderr, ": ");
	} else
		fprintf(stderr, " ");
	fprintf(stderr, "%s\n", s);
	if (n)
		exit(2);
	errs = 1;
}

E 11
struct	stabnames {
	int	st_value;
	char	*st_name;
} stabnames[] ={
D 11
	N_GSYM, "GSYM",
	N_FNAME, "FNAME",
	N_FUN, "FUN",
	N_STSYM, "STSYM",
	N_LCSYM, "LCSYM",
	N_RSYM, "RSYM",
	N_SLINE, "SLINE",
	N_SSYM, "SSYM",
	N_SO, "SO",
	N_LSYM, "LSYM",
	N_SOL, "SOL",
	N_PSYM, "PSYM",
	N_ENTRY, "ENTRY",
	N_LBRAC, "LBRAC",
	N_RBRAC, "RBRAC",
	N_BCOMM, "BCOMM",
	N_ECOMM, "ECOMM",
	N_ECOML, "ECOML",
	N_LENG, "LENG",
I 3
	N_PC, "PC",
E 3
	0, 0
E 11
I 11
	N_GSYM,		"GSYM",
	N_FNAME,	"FNAME",
	N_FUN,		"FUN",
	N_STSYM,	"STSYM",
	N_LCSYM,	"LCSYM",
	N_RSYM,		"RSYM",
	N_SLINE,	"SLINE",
	N_SSYM,		"SSYM",
	N_SO,		"SO",
	N_LSYM,		"LSYM",
	N_SOL,		"SOL",
	N_PSYM,		"PSYM",
	N_ENTRY,	"ENTRY",
	N_LBRAC,	"LBRAC",
	N_RBRAC,	"RBRAC",
	N_BCOMM,	"BCOMM",
	N_ECOMM,	"ECOMM",
	N_ECOML,	"ECOML",
	N_LENG,		"LENG",
	N_PC,		"PC",
	0,		0
E 11
};

char *
stab(val)
I 11
	register u_char	val;
E 11
{
D 11
	register struct stabnames *sp;
	static char prbuf[32];
E 11
I 11
	register struct stabnames	*sp;
	static char	prbuf[5];
E 11

D 11
	for (sp = stabnames; sp->st_name; sp++)
E 11
I 11
	for (sp = stabnames; sp->st_value; ++sp)
E 11
		if (sp->st_value == val)
D 11
			return (sp->st_name);
	sprintf(prbuf, "%02x", val);
	return (prbuf);
E 11
I 11
			return(sp->st_name);
	(void)sprintf(prbuf, "%02x", (int)val);
	return(prbuf);
}

error(doexit, msg)
	int	doexit;
	char	*msg;
{
	fprintf(stderr, "nm: %s:", *xargv);
	if (archive)
		fprintf(stderr, "(%s): %s\n", archdr.ar_name, msg);
	else
		fprintf(stderr, " %s\n", msg);
	if (doexit)
		exit(2);
	errs = 1;
E 11
}
E 1
