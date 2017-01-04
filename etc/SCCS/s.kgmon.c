h47911
s 00065/00084/00239
d D 5.4 88/05/04 19:57:48 bostic 13 12
c add getopt, read dead kernels correctly, lint fluff
e
s 00003/00000/00320
d D 5.3 86/10/13 15:03:00 sam 12 11
c tahoe support
e
s 00023/00020/00297
d D 5.2 86/02/18 17:02:08 sam 11 10
c use L_SET, O_RDONLY; make vax dependency explicit
e
s 00014/00002/00303
d D 5.1 85/05/28 14:24:47 dist 10 9
c add copyright
e
s 00001/00003/00304
d D 4.9 83/08/11 22:51:32 sam 9 8
c standardize sccs keyword lines
e
s 00001/00001/00306
d D 4.8 83/07/01 03:14:19 sam 8 7
c nil pointer
e
s 00004/00001/00303
d D 4.7 83/03/10 18:51:12 sam 7 6
c from shannon
e
s 00014/00010/00290
d D 4.6 83/01/16 15:55:58 mckusick 6 5
c change -s to -p, no longer generate gmon.out by default
e
s 00009/00005/00291
d D 4.5 83/01/15 16:43:29 mckusick 5 4
c fix up exit codes; make messages more accurate
e
s 00011/00011/00285
d D 4.4 83/01/15 16:10:46 mckusick 4 3
c fix up exit codes; pte.h moves from sys => machine
e
s 00120/00047/00176
d D 4.3 83/01/15 15:41:17 mckusick 3 2
c new austere memory version; add wondrous flags
e
s 00001/00001/00222
d D 4.2 82/12/24 12:55:01 sam 2 1
c header files moved around a bit
e
s 00223/00000/00000
d D 4.1 82/06/21 00:52:43 mckusick 1 0
c date and time created 82/06/21 00:52:43 by mckusick
e
u
U
t
T
I 10
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 10
I 1
D 9
/* Copyright (c) 1982 Regents of the University of California */

E 9
#ifndef lint
D 9
static char sccsid[] = "%W% %E%";
E 9
I 9
D 10
static char sccsid[] = "%W% (Berkeley) %E%";
E 9
#endif
E 10
I 10
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 13
#endif not lint
E 13
I 13
#endif /* not lint */
E 13

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif not lint
E 13
I 13
#endif /* not lint */
E 13
E 10

#include <sys/param.h>
D 2
#include <sys/pte.h>
E 2
I 2
D 3
#include <machine/pte.h>
E 3
I 3
D 4
#include <sys/pte.h>
E 4
I 4
#include <machine/pte.h>
I 11
#include <sys/file.h>
E 11
I 7
#include <sys/vm.h>
E 7
E 4
E 3
E 2
#include <stdio.h>
#include <nlist.h>
#include <ctype.h>
D 3
#include <sys/crt0.h>
E 3
I 3
#include <sys/gprof.h>
E 3

#define	PROFILING_ON	0
D 13
#define PROFILING_OFF	3
E 13
I 13
#define	PROFILING_OFF	3
E 13

D 13
/*
 * froms is actually a bunch of unsigned shorts indexing tos
 */
u_short	*froms;
struct	tostruct *tos;
char	*s_lowpc;
E 13
u_long	s_textsize;
I 13
off_t	sbuf, klseek(), lseek();
E 13
int	ssiz;
D 13
off_t	sbuf;
E 13

struct nlist nl[] = {
#define	N_SYSMAP	0
	{ "_Sysmap" },
#define	N_SYSSIZE	1
	{ "_Syssize" },
#define N_FROMS		2
	{ "_froms" },
#define	N_PROFILING	3
	{ "_profiling" },
#define	N_S_LOWPC	4
	{ "_s_lowpc" },
#define	N_S_TEXTSIZE	5
	{ "_s_textsize" },
#define	N_SBUF		6
	{ "_sbuf" },
#define N_SSIZ		7
	{ "_ssiz" },
#define	N_TOS		8
	{ "_tos" },
	0,
};

I 11
D 13
#if defined(vax)
#define	clear(x)	((x) &~ 0x80000000)
#endif
I 12
#if defined(tahoe)
#define	clear(x)	((x) &~ 0xc0000000)
#endif
E 12

E 13
E 11
struct	pte *Sysmap;

D 13
char	*system = "/vmunix";
char	*kmemf = "/dev/kmem";
E 13
int	kmem;
D 3
int	kflg;
E 3
I 3
D 6
int	bflag, hflag, kflag, rflag, sflag;
E 6
I 6
int	bflag, hflag, kflag, rflag, pflag;
E 6
int	debug = 0;
E 3

main(argc, argv)
	int argc;
	char *argv[];
{
D 3
	int i, j, k;
	char *cp;
	long conptr;
	int fd;
	int fromindex;
	u_long frompc;
	int toindex;
	struct rawarc rawarc;
	off_t kfroms, ktos;
	char buf[BUFSIZ];
	int debug = 0;
E 3
I 3
D 5
	int disp;
E 5
I 5
D 6
	int mode, disp, ronly = 0;
E 6
I 6
D 11
	int mode, disp, openmode = 0;
E 11
I 11
D 13
	int mode, disp, openmode = O_RDONLY;
E 13
I 13
	extern char *optarg;
	extern int optind;
	int ch, mode, disp, openmode;
	char *system, *kmemf, *malloc();
E 13
E 11
E 6
E 5
E 3

D 13
	argc--, argv++;
I 3
D 8
	while (argv[0][0] == '-') {
E 8
I 8
	while (argc > 0 && argv[0][0] == '-') {
E 8
		switch (argv[0][1]) {
E 13
I 13
	while ((ch = getopt(argc, argv, "bhpr")) != EOF)
		switch((char)ch) {
E 13
		case 'b':
			bflag++;
I 6
D 11
			openmode = 2;
E 11
I 11
D 13
			openmode = O_RDWR;
E 13
E 11
E 6
			break;
		case 'h':
			hflag++;
I 6
D 11
			openmode = 2;
E 11
I 11
D 13
			openmode = O_RDWR;
E 13
E 11
E 6
			break;
D 13
		case 'r':
			rflag++;
I 6
D 11
			openmode = 2;
E 11
I 11
			openmode = O_RDWR;
E 11
E 6
			break;
E 13
D 6
		case 's':
			sflag++;
E 6
I 6
		case 'p':
			pflag++;
D 11
			openmode = 2;
E 11
I 11
D 13
			openmode = O_RDWR;
E 13
E 11
E 6
			break;
I 13
		case 'r':
			rflag++;
			break;
E 13
		default:
D 6
			printf("Usage: kgmon [ -b -h -r -s system memory ]\n");
E 6
I 6
D 13
			printf("Usage: kgmon [ -b -h -r -p system memory ]\n");
E 13
I 13
			fputs("usage: kgmon [-bhrp] [system [core]]\n", stderr);
E 13
E 6
			exit(1);
		}
D 13
		argc--, argv++;
	}
E 13
I 13

	openmode = (bflag || hflag || pflag || rflag) ? O_RDWR : O_RDONLY;

	kmemf = "/dev/kmem";
E 13
E 3
	if (argc > 0) {
		system = *argv;
		argv++, argc--;
I 13
		if (argc > 0) {
			kmemf = *argv;
			kflag++;
		}
E 13
	}
D 13
	nlist(system, nl);
	if (nl[0].n_type == 0) {
E 13
I 13
	else
		system = "/vmunix";

	if (nlist(system, nl) < 0 || nl[0].n_type == 0) {
E 13
		fprintf(stderr, "%s: no namelist\n", system);
D 4
		exit(1);
E 4
I 4
		exit(2);
E 4
	}
D 13
	if (argc > 0) {
		kmemf = *argv;
D 3
		kflg++;
E 3
I 3
		kflag++;
E 13
I 13
	if (!nl[N_PROFILING].n_value) {
		fputs("profiling: not defined in kernel.\n", stderr);
		exit(10);
E 13
E 3
	}
D 6
	kmem = open(kmemf, 2);
E 6
I 6
	kmem = open(kmemf, openmode);
E 6
	if (kmem < 0) {
D 6
		kmem = open(kmemf, 0);
E 6
I 6
D 11
		openmode = 0;
E 11
I 11
		openmode = O_RDONLY;
E 11
		kmem = open(kmemf, openmode);
E 6
		if (kmem < 0) {
D 13
			fprintf(stderr, "cannot open ");
E 13
			perror(kmemf);
D 4
			exit(1);
E 4
I 4
			exit(3);
E 4
		}
I 5
D 6
		ronly++;
E 6
E 5
D 3
		fprintf(stderr,
		    "%s opened read-only, data may be inconsistent\n",
		    kmemf);
E 3
I 3
		fprintf(stderr, "%s opened read-only\n", kmemf);
D 5
		if (!sflag)
			fprintf(stderr, "data may be inconsistent\n");
E 5
		if (rflag)
			fprintf(stderr, "-r supressed\n");
		if (bflag)
			fprintf(stderr, "-b supressed\n");
		if (hflag)
			fprintf(stderr, "-h supressed\n");
D 13
		rflag = 0;
		bflag = 0;
		hflag = 0;
E 13
I 13
		rflag = bflag = hflag = 0;
E 13
E 3
	}
D 3
	if (kflg) {
E 3
I 3
	if (kflag) {
E 3
		off_t off;

D 11
		off = nl[N_SYSMAP].n_value & 0x7fffffff;
		lseek(kmem, off, 0);
E 11
I 11
D 13
		off = clear(nl[N_SYSMAP].n_value);
		lseek(kmem, off, L_SET);
E 11
		nl[N_SYSSIZE].n_value *= 4;
		Sysmap = (struct pte *)malloc(nl[N_SYSSIZE].n_value);
		if (Sysmap == 0) {
			perror("Sysmap");
D 4
			exit(1);
E 4
I 4
			exit(4);
E 13
I 13
		Sysmap = (struct pte *)
		   malloc((u_int)(nl[N_SYSSIZE].n_value * sizeof(struct pte)));
		if (!Sysmap) {
			fputs("arp: can't get memory for Sysmap.\n", stderr);
			exit(1);
E 13
E 4
		}
D 13
		read(kmem, Sysmap, nl[N_SYSSIZE].n_value);
E 13
I 13
		off = nl[N_SYSMAP].n_value & ~KERNBASE;
		(void)lseek(kmem, off, L_SET);
		(void)read(kmem, (char *)Sysmap,
		    (int)(nl[N_SYSSIZE].n_value * sizeof(struct pte)));
E 13
	}
I 5
	mode = kfetch(N_PROFILING);
E 5
I 3
	if (hflag)
		disp = PROFILING_OFF;
	else if (bflag)
		disp = PROFILING_ON;
	else
D 5
		disp = kfetch(N_PROFILING);
	if (!sflag)
E 5
I 5
		disp = mode;
D 6
	if (!sflag) {
		if (ronly && mode == PROFILING_ON)
E 6
I 6
	if (pflag) {
D 11
		if (openmode == 0 && mode == PROFILING_ON)
E 11
I 11
		if (openmode == O_RDONLY && mode == PROFILING_ON)
E 11
E 6
			fprintf(stderr, "data may be inconsistent\n");
E 5
		dumpstate();
I 5
	}
E 5
	if (rflag)
		resetstate();
	turnonoff(disp);
I 5
	fprintf(stdout, "kernel profiling is %s.\n", disp ? "off" : "running");
E 5
}

dumpstate()
{
D 13
	int i;
	int fd;
	off_t kfroms, ktos;
	int fromindex, endfrom, fromssize, tossize;
	u_long frompc;
	int toindex;
E 13
	struct rawarc rawarc;
D 13
	char buf[BUFSIZ];
E 13
I 13
	struct tostruct *tos;
	u_long frompc;
	off_t kfroms, ktos;
	u_short *froms;		/* froms is a bunch of u_shorts indexing tos */
	int i, fd, fromindex, endfrom, fromssize, tossize, toindex;
	char buf[BUFSIZ], *s_lowpc, *malloc();
E 13

E 3
	turnonoff(PROFILING_OFF);
	fd = creat("gmon.out", 0666);
	if (fd < 0) {
		perror("gmon.out");
		return;
	}
	ssiz = kfetch(N_SSIZ);
	sbuf = kfetch(N_SBUF);
D 11
	klseek(kmem, (off_t)sbuf, 0);
E 11
I 11
D 13
	klseek(kmem, (off_t)sbuf, L_SET);
E 13
I 13
	(void)klseek(kmem, (off_t)sbuf, L_SET);
E 13
E 11
	for (i = ssiz; i > 0; i -= BUFSIZ) {
		read(kmem, buf, i < BUFSIZ ? i : BUFSIZ);
		write(fd, buf, i < BUFSIZ ? i : BUFSIZ);
	}
	s_textsize = kfetch(N_S_TEXTSIZE);
D 3
	froms = (u_short *)malloc(s_textsize);
E 3
I 3
	fromssize = s_textsize / HASHFRACTION;
D 13
	froms = (u_short *)malloc(fromssize);
E 13
I 13
	froms = (u_short *)malloc((u_int)fromssize);
E 13
E 3
	kfroms = kfetch(N_FROMS);
D 11
	klseek(kmem, kfroms, 0);
E 11
I 11
D 13
	klseek(kmem, kfroms, L_SET);
E 13
I 13
	(void)klseek(kmem, kfroms, L_SET);
E 13
E 11
D 3
	for (i = 0; i < s_textsize; i += BUFSIZ) {
		j = s_textsize - i;
		if (j > BUFSIZ)
			j = BUFSIZ;
		k = read(kmem, ((char *)(froms)) + i, j);
		if (j != k) {
			fprintf(stderr, "read tos: loc %d, request %d, got %d",
			    i, j, k);
			perror("");
			exit(5);
		}
E 3
I 3
	i = read(kmem, ((char *)(froms)), fromssize);
	if (i != fromssize) {
		fprintf(stderr, "read froms: request %d, got %d", fromssize, i);
D 13
		perror("");
E 13
I 13
		perror((char *)NULL);
E 13
		exit(5);
E 3
	}
D 3
	tos = (struct tostruct *)malloc(s_textsize);
E 3
I 3
	tossize = (s_textsize * ARCDENSITY / 100) * sizeof(struct tostruct);
D 13
	tos = (struct tostruct *)malloc(tossize);
E 13
I 13
	tos = (struct tostruct *)malloc((u_int)tossize);
E 13
E 3
	ktos = kfetch(N_TOS);
D 11
	klseek(kmem, ktos, 0);
E 11
I 11
D 13
	klseek(kmem, ktos, L_SET);
E 13
I 13
	(void)klseek(kmem, ktos, L_SET);
E 13
E 11
D 3
	for (i = 0; i < s_textsize; i += BUFSIZ) {
		j = s_textsize - i;
		if (j > BUFSIZ)
			j = BUFSIZ;
		k = read(kmem, ((char *)(tos)) + i, j);
		if (j != k) {
			fprintf(stderr, "read tos: loc %d, request %d, got %d",
			    i, j, k);
			perror("");
			exit(6);
		}
E 3
I 3
	i = read(kmem, ((char *)(tos)), tossize);
	if (i != tossize) {
		fprintf(stderr, "read tos: request %d, got %d", tossize, i);
D 13
		perror("");
E 13
I 13
		perror((char *)NULL);
E 13
		exit(6);
E 3
	}
	s_lowpc = (char *)kfetch(N_S_LOWPC);
	if (debug)
		fprintf(stderr, "s_lowpc 0x%x, s_textsize 0x%x\n",
		    s_lowpc, s_textsize);
D 3
	for (fromindex = 0; fromindex < s_textsize>>1; fromindex++) {
E 3
I 3
	endfrom = fromssize / sizeof(*froms);
	for (fromindex = 0; fromindex < endfrom; fromindex++) {
E 3
		if (froms[fromindex] == 0)
			continue;
D 3
		frompc = (u_long)s_lowpc + (fromindex<<1);
E 3
I 3
		frompc = (u_long)s_lowpc +
		    (fromindex * HASHFRACTION * sizeof(*froms));
E 3
		for (toindex = froms[fromindex]; toindex != 0;
		   toindex = tos[toindex].link) {
			if (debug)
			    fprintf(stderr,
			    "[mcleanup] frompc 0x%x selfpc 0x%x count %d\n" ,
			    frompc, tos[toindex].selfpc, tos[toindex].count);
			rawarc.raw_frompc = frompc;
			rawarc.raw_selfpc = (u_long)tos[toindex].selfpc;
			rawarc.raw_count = tos[toindex].count;
D 13
			write(fd, &rawarc, sizeof (rawarc));
E 13
I 13
			write(fd, (char *)&rawarc, sizeof (rawarc));
E 13
		}
	}
	close(fd);
D 3
	turnonoff(PROFILING_ON);
E 3
}

I 3
resetstate()
{
D 13
	int i;
E 13
	off_t kfroms, ktos;
D 13
	int fromssize, tossize;
E 13
I 13
	int i, fromssize, tossize;
E 13
	char buf[BUFSIZ];

	turnonoff(PROFILING_OFF);
	bzero(buf, BUFSIZ);
	ssiz = kfetch(N_SSIZ);
	sbuf = kfetch(N_SBUF);
	ssiz -= sizeof(struct phdr);
	sbuf += sizeof(struct phdr);
D 11
	klseek(kmem, (off_t)sbuf, 0);
E 11
I 11
D 13
	klseek(kmem, (off_t)sbuf, L_SET);
E 13
I 13
	(void)klseek(kmem, (off_t)sbuf, L_SET);
E 13
E 11
	for (i = ssiz; i > 0; i -= BUFSIZ)
		if (write(kmem, buf, i < BUFSIZ ? i : BUFSIZ) < 0) {
			perror("sbuf write");
D 4
			exit(1);
E 4
I 4
			exit(7);
E 4
		}
	s_textsize = kfetch(N_S_TEXTSIZE);
	fromssize = s_textsize / HASHFRACTION;
	kfroms = kfetch(N_FROMS);
D 11
	klseek(kmem, kfroms, 0);
E 11
I 11
D 13
	klseek(kmem, kfroms, L_SET);
E 13
I 13
	(void)klseek(kmem, kfroms, L_SET);
E 13
E 11
	for (i = fromssize; i > 0; i -= BUFSIZ)
		if (write(kmem, buf, i < BUFSIZ ? i : BUFSIZ) < 0) {
			perror("kforms write");
D 4
			exit(1);
E 4
I 4
			exit(8);
E 4
		}
	tossize = (s_textsize * ARCDENSITY / 100) * sizeof(struct tostruct);
	ktos = kfetch(N_TOS);
D 11
	klseek(kmem, ktos, 0);
E 11
I 11
D 13
	klseek(kmem, ktos, L_SET);
E 13
I 13
	(void)klseek(kmem, ktos, L_SET);
E 13
E 11
	for (i = tossize; i > 0; i -= BUFSIZ)
		if (write(kmem, buf, i < BUFSIZ ? i : BUFSIZ) < 0) {
			perror("ktos write");
D 4
			exit(1);
E 4
I 4
			exit(9);
E 4
		}
}

E 3
turnonoff(onoff)
	int onoff;
{
D 13
	off_t off;

	if ((off = nl[N_PROFILING].n_value) == 0) {
		printf("profiling: not defined in kernel\n");
D 4
		exit(1);
E 4
I 4
		exit(10);
E 4
	}
D 11
	klseek(kmem, off, 0);
E 11
I 11
	klseek(kmem, off, L_SET);
E 11
	write(kmem, (char *)&onoff, sizeof (onoff));
E 13
I 13
	(void)klseek(kmem, (long)nl[N_PROFILING].n_value, L_SET);
	(void)write(kmem, (char *)&onoff, sizeof (onoff));
E 13
}

kfetch(index)
	int index;
{
	off_t off;
	int value;

	if ((off = nl[index].n_value) == 0) {
		printf("%s: not defined in kernel\n", nl[index].n_name);
D 4
		exit(1);
E 4
I 4
		exit(11);
E 4
	}
D 11
	if (klseek(kmem, off, 0) == -1) {
E 11
I 11
	if (klseek(kmem, off, L_SET) == -1) {
E 11
		perror("lseek");
D 4
		exit(2);
E 4
I 4
		exit(12);
E 4
	}
	if (read(kmem, (char *)&value, sizeof (value)) != sizeof (value)) {
		perror("read");
D 4
		exit(3);
E 4
I 4
		exit(13);
E 4
	}
	return (value);
}

I 13
off_t
E 13
klseek(fd, base, off)
D 13
	int fd, base, off;
E 13
I 13
	int fd, off;
	off_t base;
E 13
{
D 13

D 3
	if (kflg) {
E 3
I 3
	if (kflag) {
E 3
		/* get kernel pte */
I 7
D 11
#if vax
E 7
		base &= 0x7fffffff;
D 7
		base = Sysmap[base >> 9].pg_pfnum * 512 + (base & 0x1ff);
E 7
I 7
#endif
E 11
I 11
		base = clear(base);
E 11
		base = ((int)ptob(Sysmap[btop(base)].pg_pfnum))+(base&(NBPG-1));
E 13
I 13
	if (kflag) {	/* get kernel pte */
		base &= ~KERNBASE;
		base = ctob(Sysmap[btop(base)].pg_pfnum) + (base & PGOFSET);
E 13
E 7
	}
	return (lseek(fd, base, off));
}
E 1
