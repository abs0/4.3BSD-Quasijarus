h40213
s 00001/00001/00381
d D 5.4 87/04/06 19:20:56 bostic 15 14
c added RANLIBMAG
e
s 00136/00019/00246
d D 5.3 86/01/22 13:44:37 mckusick 14 13
c use dynamic allocation (from dlu%lumiere%tektronix.csnet@CSNET-RELAY.ARPA)
e
s 00001/00001/00264
d D 5.2 85/09/05 18:01:25 mckusick 13 12
c fix for -t (from ks@purdue)
e
s 00015/00002/00250
d D 5.1 85/06/06 09:43:10 dist 12 11
c Add copyright
e
s 00019/00005/00233
d D 4.9 85/05/06 18:19:33 mckusick 11 10
c more comprehensive error checking (from arnold@ucsfcgl.arpa)
e
s 00013/00000/00225
d D 4.8 85/05/03 20:33:22 mckusick 10 9
c add -t option (from arnold@ucsfcgl)
e
s 00006/00004/00219
d D 4.7 84/11/26 12:13:26 ralph 9 8
c ignore __SYMDEF if it should happen to have a valid a.out magic #.
e
s 00002/00001/00221
d D 4.6 83/05/22 18:37:32 sam 8 7
c purge pagsiz.h
e
s 00001/00001/00221
d D 4.5 83/02/18 19:19:29 shantz 7 6
c MJS increased TABSZ to 6000
e
s 00011/00004/00211
d D 4.4 82/11/24 18:11:33 rt 6 5
c Avoid alignment problem on machines without arbitrary memory fetching.
e
s 00001/00001/00214
d D 4.3 81/04/26 17:16:07 sklower 5 4
c Ok to have members of random archives with no symbol tables.
e
s 00002/00002/00213
d D 4.2 80/11/08 09:43:04 bill 4 3
c 3* size of fixed tables
e
s 00000/00000/00215
d D 4.1 80/10/01 16:39:55 bill 3 2
c Define 4.1
e
s 00005/00005/00210
d D 3.2 80/09/20 18:50:46 bill 2 1
c now installed, a.out.h, ar not newa.out.h /usr/new/ar
e
s 00215/00000/00000
d D 3.1 80/08/15 01:58:05 bill 1 0
c date and time created 80/08/15 01:58:05 by bill
e
u
U
t
T
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 12
I 8
#ifndef lint
E 8
I 1
D 12
static	char sccsid[] = "%Z%%M% %I% %G%";
I 8
#endif
E 12
I 12
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 12
E 8
/*
 * ranlib - create table of contents for archive; string table version
 */
#include <sys/types.h>
D 2
#include <newar.h>
E 2
I 2
#include <ar.h>
E 2
#include <ranlib.h>
D 8
#include <pagsiz.h>
E 8
D 2
#include <newa.out.h>
E 2
I 2
#include <a.out.h>
E 2
#include <stdio.h>

struct	ar_hdr	archdr;
#define	OARMAG 0177545
long	arsize;
struct	exec	exp;
FILE	*fi, *fo;
long	off, oldoff;
long	atol(), ftell();
D 2
#define TABSZ	1500
E 2
I 2
D 4
#define TABSZ	2000
E 4
I 4
D 7
#define TABSZ	5000
E 7
I 7
D 14
#define TABSZ	6000
E 7
E 4
E 2
struct	ranlib tab[TABSZ];
E 14
I 14
#define TABSZ	3000
E 14
int	tnum;
D 4
#define	STRTABSZ	25000
E 4
I 4
D 14
#define	STRTABSZ	75000
E 4
char	tstrtab[STRTABSZ];
E 14
I 14
#define	STRTABSZ	30000
E 14
int	tssiz;
char	*strtab;
int	ssiz;
int	new;
D 15
char	tempnm[] = "__.SYMDEF";
E 15
I 15
char	tempnm[] = RANLIBMAG;
E 15
char	firstname[17];
I 14
void	stash();
char *malloc(), *calloc();
E 14

I 14
/*
 * table segment definitions
 */
char	*segalloc();
void	segclean();
struct	tabsegment {
	struct tabsegment	*pnext;
	unsigned		nelem;
	struct ranlib		tab[TABSZ];
} tabbase, *ptabseg;
struct	strsegment {
	struct strsegment	*pnext;
	unsigned		nelem;
	char			stab[STRTABSZ];
} strbase, *pstrseg;

E 14
main(argc, argv)
char **argv;
{
	char cmdbuf[BUFSIZ];
D 6
	char magbuf[SARMAG+1];
E 6
I 6
	/* magbuf must be an int array so it is aligned on an int-ish
	   boundary, so that we may access its first word as an int! */
	int magbuf[(SARMAG+sizeof(int))/sizeof(int)];
I 10
	register int just_touch = 0;
I 14
	register struct tabsegment *ptab;
	register struct strsegment *pstr;
E 14
E 10
E 6

I 10
	/* check for the "-t" flag" */
	if (argc > 1 && strcmp(argv[1], "-t") == 0) {
		just_touch++;
		argc--;
		argv++;
	}

E 10
	--argc;
	while(argc--) {
I 10
D 11
		if (just_touch) {
			fixdate(*++argv);
			continue;
		}

E 11
E 10
		fi = fopen(*++argv,"r");
		if (fi == NULL) {
			fprintf(stderr, "ranlib: cannot open %s\n", *argv);
			continue;
		}
		off = SARMAG;
D 6
		fread(magbuf, 1, SARMAG, fi);
		if (strncmp(magbuf, ARMAG, SARMAG)) {
			if (*(int *)magbuf == OARMAG)
E 6
I 6
		fread((char *)magbuf, 1, SARMAG, fi);
		if (strncmp((char *)magbuf, ARMAG, SARMAG)) {
			if (magbuf[0] == OARMAG)
E 6
				fprintf(stderr, "old format ");
			else
				fprintf(stderr, "not an ");
			fprintf(stderr, "archive: %s\n", *argv);
I 11
			continue;
		}
		if (just_touch) {
			register int	len;

			fseek(fi, (long) SARMAG, 0);
			if (fread(cmdbuf, sizeof archdr.ar_name, 1, fi) != 1) {
				fprintf(stderr, "malformed archive: %s\n",
					*argv);
				continue;
			}
			len = strlen(tempnm);
			if (bcmp(cmdbuf, tempnm, len) != 0 ||
			    cmdbuf[len] != ' ') {
				fprintf(stderr, "no symbol table: %s\n", *argv);
				continue;
			}
			fclose(fi);
D 13
			fixdate(*++argv);
E 13
I 13
			fixdate(*argv);
E 13
E 11
			continue;
		}
		fseek(fi, 0L, 0);
D 14
		new = tnum = 0;
E 14
I 14
		new = tssiz = tnum = 0;
		segclean();
E 14
		if (nextel(fi) == 0) {
			fclose(fi);
			continue;
		}
		do {
			long o;
			register n;
			struct nlist sym;

			fread((char *)&exp, 1, sizeof(struct exec), fi);
			if (N_BADMAG(exp))
				continue;
I 9
			if (!strncmp(tempnm, archdr.ar_name, sizeof(archdr.ar_name)))
				continue;
E 9
			if (exp.a_syms == 0) {
				fprintf(stderr, "ranlib: warning: %s(%s): no symbol table\n", *argv, archdr.ar_name);
D 5
				exit(1);
E 5
I 5
				continue;
E 5
			}
			o = N_STROFF(exp) - sizeof (struct exec);
			if (ftell(fi)+o+sizeof(ssiz) >= off) {
D 9
				fprintf(stderr, "ranlib: %s(%s): old format .o file\n", *argv, archdr.ar_name);
				exit(1);
E 9
I 9
				fprintf(stderr, "ranlib: warning: %s(%s): old format .o file\n", *argv, archdr.ar_name);
				continue;
E 9
			}
			fseek(fi, o, 1);
			fread((char *)&ssiz, 1, sizeof (ssiz), fi);
I 6
			if (ssiz < sizeof ssiz){
				/* sanity check */
D 9
				fprintf(stderr, "ranlib: %s(%s): mangled string table\n", *argv, archdr.ar_name);
				exit(1);
E 9
I 9
				fprintf(stderr, "ranlib: warning: %s(%s): mangled string table\n", *argv, archdr.ar_name);
				continue;
E 9
			}
E 6
			strtab = (char *)calloc(1, ssiz);
			if (strtab == 0) {
				fprintf(stderr, "ranlib: ran out of memory\n");
				exit(1);
			}
			fread(strtab+sizeof(ssiz), ssiz - sizeof(ssiz), 1, fi);
			fseek(fi, -(exp.a_syms+ssiz), 1);
			n = exp.a_syms / sizeof(struct nlist);
			while (--n >= 0) {
				fread((char *)&sym, 1, sizeof(sym), fi);
				if (sym.n_un.n_strx == 0)
					continue;
				sym.n_un.n_name = strtab + sym.n_un.n_strx;
				if ((sym.n_type&N_EXT)==0)
					continue;
				switch (sym.n_type&N_TYPE) {

				case N_UNDF:
					if (sym.n_value!=0)
						stash(&sym);
					continue;

				default:
					stash(&sym);
					continue;
				}
			}
I 14
			free(strtab);
E 14
		} while(nextel(fi));
		new = fixsize();
		fclose(fi);
		fo = fopen(tempnm, "w");
		if(fo == NULL) {
			fprintf(stderr, "can't create temporary\n");
			exit(1);
		}
		tnum *= sizeof (struct ranlib);
		fwrite(&tnum, 1, sizeof (tnum), fo);
		tnum /= sizeof (struct ranlib);
D 14
		fwrite((char *)tab, tnum, sizeof(struct ranlib), fo);
E 14
I 14
		ptab = &tabbase;
		do {
			fwrite((char *)ptab->tab, ptab->nelem,
			    sizeof(struct ranlib), fo);
		} while (ptab = ptab->pnext);
E 14
		fwrite(&tssiz, 1, sizeof (tssiz), fo);
D 14
		fwrite(tstrtab, tssiz, 1, fo);
E 14
I 14
		pstr = &strbase;
		do {
			fwrite(pstr->stab, pstr->nelem, 1, fo);
			tssiz -= pstr->nelem;
		} while (pstr = pstr->pnext);
		/* pad with nulls */
		while (tssiz--) putc('\0', fo);
E 14
		fclose(fo);
		if(new)
D 2
			sprintf(cmdbuf, "/usr/new/ar rlb %s %s %s\n", firstname, *argv, tempnm);
E 2
I 2
			sprintf(cmdbuf, "ar rlb %s %s %s\n", firstname, *argv, tempnm);
E 2
		else
D 2
			sprintf(cmdbuf, "/usr/new/ar rl %s %s\n", *argv, tempnm);
E 2
I 2
			sprintf(cmdbuf, "ar rl %s %s\n", *argv, tempnm);
E 2
		if(system(cmdbuf))
			fprintf(stderr, "ranlib: ``%s'' failed\n", cmdbuf);
		else
			fixdate(*argv);
		unlink(tempnm);
	}
	exit(0);
}

nextel(af)
FILE *af;
{
	register r;
	register char *cp;

	oldoff = off;
	fseek(af, off, 0);
	r = fread((char *)&archdr, 1, sizeof(struct ar_hdr), af);
	if (r != sizeof(struct ar_hdr))
		return(0);
	for (cp=archdr.ar_name; cp < & archdr.ar_name[sizeof(archdr.ar_name)]; cp++)
		if (*cp == ' ')
			*cp = '\0';
	arsize = atol(archdr.ar_size);
	if (arsize & 1)
		arsize++;
	off = ftell(af) + arsize;
	return(1);
}

I 14
void
E 14
stash(s)
	struct nlist *s;
{
D 14
	int i;
E 14
	register char *cp;
I 14
	register char *strtab;
	register strsiz;
	register struct ranlib *tab;
	register tabsiz;
E 14

D 14
	if(tnum >= TABSZ) {
		fprintf(stderr, "ranlib: symbol table overflow\n");
		exit(1);
E 14
I 14
	if (ptabseg->nelem >= TABSZ) {
		/* allocate a new symbol table segment */
		ptabseg = ptabseg->pnext =
		    (struct tabsegment *) segalloc(sizeof(struct tabsegment));
		ptabseg->pnext = NULL;
		ptabseg->nelem = 0;
E 14
	}
D 14
	tab[tnum].ran_un.ran_strx = tssiz;
	tab[tnum].ran_off = oldoff;
	for (cp = s->n_un.n_name; tstrtab[tssiz++] = *cp++;)
		if (tssiz > STRTABSZ) {
			fprintf(stderr, "ranlib: string table overflow\n");
			exit(1);
E 14
I 14
	tabsiz = ptabseg->nelem;
	tab = ptabseg->tab;

	if (pstrseg->nelem >= STRTABSZ) {
		/* allocate a new string table segment */
		pstrseg = pstrseg->pnext =
		    (struct strsegment *) segalloc(sizeof(struct strsegment));
		pstrseg->pnext = NULL;
		pstrseg->nelem = 0;
	}
	strsiz = pstrseg->nelem;
	strtab = pstrseg->stab;

	tab[tabsiz].ran_un.ran_strx = tssiz;
	tab[tabsiz].ran_off = oldoff;
redo:
	for (cp = s->n_un.n_name; strtab[strsiz++] = *cp++;)
		if (strsiz >= STRTABSZ) {
			/* allocate a new string table segment */
			pstrseg = pstrseg->pnext =
			    (struct strsegment *) segalloc(sizeof(struct strsegment));
			pstrseg->pnext = NULL;
			strsiz = pstrseg->nelem = 0;
			strtab = pstrseg->stab;
			goto redo;
E 14
		}
I 14

	tssiz += strsiz - pstrseg->nelem; /* length of the string */
	pstrseg->nelem = strsiz;
E 14
	tnum++;
I 14
	ptabseg->nelem++;
E 14
}

I 14
/* allocate a zero filled segment of size bytes */
char *
segalloc(size)
unsigned size;
{
	char *pseg = NULL;

	pseg = malloc(size);
	if (pseg == NULL) {
		fprintf(stderr, "ranlib: ran out of memeory\n");
		exit(1);
	}
	return(pseg);
}

/* free segments */
void
segclean()
{
	register struct tabsegment *ptab;
	register struct strsegment *pstr;

	/*
	 * symbol table
	 *
	 * The first entry is static.
	 */
	ptabseg = &tabbase;
	ptab = ptabseg->pnext;
	while (ptabseg = ptab) {
		ptab = ptabseg->pnext;
		free((char *)ptabseg);
	}
	ptabseg = &tabbase;
	ptabseg->pnext = NULL;
	ptabseg->nelem = 0;

	/*
	 * string table
	 *
	 * The first entry is static.
	 */
	pstrseg = &strbase;
	pstr = pstrseg->pnext;
	while (pstrseg = pstr) {
		pstr = pstrseg->pnext;
		free((char *)pstrseg);
	}
	pstrseg = &strbase;
	pstrseg->pnext = NULL;
	pstrseg->nelem = 0;
}

E 14
fixsize()
{
	int i;
	off_t offdelta;
I 14
	register struct tabsegment *ptab;
E 14

	if (tssiz&1)
		tssiz++;
	offdelta = sizeof(archdr) + sizeof (tnum) + tnum * sizeof(struct ranlib) +
	    sizeof (tssiz) + tssiz;
	off = SARMAG;
	nextel(fi);
	if(strncmp(archdr.ar_name, tempnm, sizeof (archdr.ar_name)) == 0) {
		new = 0;
		offdelta -= sizeof(archdr) + arsize;
	} else {
		new = 1;
		strncpy(firstname, archdr.ar_name, sizeof(archdr.ar_name));
	}
D 14
	for(i=0; i<tnum; i++)
		tab[i].ran_off += offdelta;
E 14
I 14
	ptab = &tabbase;
	do {
		for (i = 0; i < ptab->nelem; i++)
			ptab->tab[i].ran_off += offdelta;
	} while (ptab = ptab->pnext);
E 14
	return(new);
}

/* patch time */
fixdate(s)
	char *s;
{
	long time();
	char buf[24];
	int fd;

	fd = open(s, 1);
	if(fd < 0) {
		fprintf(stderr, "ranlib: can't reopen %s\n", s);
		return;
	}
	sprintf(buf, "%-*ld", sizeof(archdr.ar_date), time((long *)NULL)+5);
	lseek(fd, (long)SARMAG + ((char *)archdr.ar_date-(char *)&archdr), 0);
	write(fd, buf, sizeof(archdr.ar_date));
	close(fd);
}
E 1
