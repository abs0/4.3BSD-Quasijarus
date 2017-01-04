h53369
s 00007/00000/00191
d D 5.2 86/10/13 16:41:11 sam 12 11
c add tahoe cipher 
e
s 00016/00001/00175
d D 5.1 85/04/30 15:04:48 dist 11 10
c Add copyright
e
s 00005/00005/00171
d D 4.8 83/05/08 14:28:53 sam 10 9
c arg checking out of order
e
s 00003/00003/00173
d D 4.7 83/02/09 13:17:22 sam 9 8
c from sun
e
s 00000/00004/00176
d D 4.6 83/02/08 23:28:32 sam 8 7
c yank sun changes -- no longer used
e
s 00026/00010/00154
d D 4.5 83/01/02 14:32:04 sam 7 6
c from sun
e
s 00010/00005/00154
d D 4.4 82/12/19 13:09:03 sam 6 5
c include files rearranged
e
s 00111/00020/00048
d D 4.3 81/11/12 16:42:13 sam 5 4
c major overhaul, plus addition of status command
e
s 00012/00014/00056
d D 4.2 81/07/05 22:14:44 root 4 1
c open tape only as needed and only once
e
s 00003/00006/00065
d R 4.3 81/07/05 22:12:50 root 3 2
c only one open of tape
e
s 00015/00014/00056
d R 4.2 81/07/05 22:11:03 root 2 1
c open tape r/w only when needed
e
s 00070/00000/00000
d D 4.1 81/05/11 03:13:39 root 1 0
c date and time created 81/05/11 03:13:39 by root
e
u
U
t
T
I 1
D 11
static	char *sccsid = "%W% (Berkeley) %E%";
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 11
D 5

E 5
/*
D 5
 * mt
E 5
I 5
 * mt --
 *   magnetic tape manipulation program
E 5
 */
D 5

E 5
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/mtio.h>
#include <sys/ioctl.h>

I 5
#define	equal(s1,s2)	(strcmp(s1, s2) == 0)
D 7
#define	DEFTAPE		"/dev/rmt12"
E 7

E 5
struct commands {
	char *c_name;
	int c_code;
I 4
	int c_ronly;
E 4
} com[] = {
D 4
	"eof",	MTWEOF,
	"fsf",	MTFSF,
	"bsf",	MTBSF,
	"fsr",	MTFSR,
	"bsr",	MTBSR,
	"rewind",	MTREW,
	"offline",	MTOFFL,
E 4
I 4
D 5
	"eof",	MTWEOF,	0,
	"fsf",	MTFSF,	1,
	"bsf",	MTBSF,	1,
	"fsr",	MTFSR,	1,
	"bsr",	MTBSR,	1,
	"rewind",	MTREW,	1,
	"offline",	MTOFFL,	1,
E 4
	0,0
E 5
I 5
	{ "weof",	MTWEOF,	0 },
	{ "eof",	MTWEOF,	0 },
	{ "fsf",	MTFSF,	1 },
	{ "bsf",	MTBSF,	1 },
	{ "fsr",	MTFSR,	1 },
	{ "bsr",	MTBSR,	1 },
	{ "rewind",	MTREW,	1 },
	{ "offline",	MTOFFL,	1 },
	{ "rewoffl",	MTOFFL,	1 },
	{ "status",	MTNOP,	1 },
I 7
D 8
	{ "tense",	MTTENSE,1 },
	{ "tension",	MTTENSE,1 },
	{ "retension",	MTTENSE,1 },
	{ "erase",	MTERASE,1 },
E 8
E 7
	{ 0 }
E 5
};

int mtfd;
struct mtop mt_com;
I 5
struct mtget mt_status;
E 5
char *tape;

main(argc, argv)
D 5
char **argv;
E 5
I 5
	char **argv;
E 5
{
	char line[80], *getenv();
	register char *cp;
	register struct commands *comp;

D 10
	if (argc < 2) {
D 5
		fprintf(stderr, "usage: mt [ -t tape ] command [ count ]\n");
E 5
I 5
		fprintf(stderr, "usage: mt [ -f device ] command [ count ]\n");
E 5
		exit(1);
	}
D 5
	if ((strcmp(argv[1], "-t") == 0) && argc > 2) {
E 5
I 5
	if ((equal(argv[1], "-t") || equal(argv[1], "-f")) && argc > 2) {
E 10
I 10
	if (argc > 2 && (equal(argv[1], "-t") || equal(argv[1], "-f"))) {
E 10
E 5
		argc -= 2;
		tape = argv[2];
		argv += 2;
	} else
		if ((tape = getenv("TAPE")) == NULL)
D 5
			tape = "/dev/rmt12";
E 5
I 5
			tape = DEFTAPE;
I 10
	if (argc < 2) {
		fprintf(stderr, "usage: mt [ -f device ] command [ count ]\n");
		exit(1);
	}
E 10
E 5
D 4
	if ((mtfd = open(tape, 2)) < 0) {
		if ((mtfd = open(tape, 0)) < 0) {
			perror(tape);
			exit(1);
		}
	}

E 4
	cp = argv[1];
	for (comp = com; comp->c_name != NULL; comp++)
		if (strncmp(cp, comp->c_name, strlen(cp)) == 0)
			break;
	if (comp->c_name == NULL) {
		fprintf(stderr, "mt: don't grok \"%s\"\n", cp);
I 4
		exit(1);
	}
	if ((mtfd = open(tape, comp->c_ronly ? 0 : 2)) < 0) {
		perror(tape);
E 4
		exit(1);
	}
D 5
	mt_com.mt_count = (argc > 2 ? atoi(argv[2]) : 1);
	mt_com.mt_op = comp->c_code;
	if (ioctl(mtfd, MTIOCTOP, &mt_com) < 0) {
		fprintf(stderr, "%s %d ", comp->c_name, mt_com.mt_count);
		perror("failed");
E 5
I 5
	if (comp->c_code != MTNOP) {
		mt_com.mt_op = comp->c_code;
		mt_com.mt_count = (argc > 2 ? atoi(argv[2]) : 1);
		if (mt_com.mt_count < 0) {
			fprintf(stderr, "mt: negative repeat count\n");
			exit(1);
		}
		if (ioctl(mtfd, MTIOCTOP, &mt_com) < 0) {
D 7
			fprintf(stderr, "%s %d ", comp->c_name,
E 7
I 7
			fprintf(stderr, "%s %s %d ", tape, comp->c_name,
E 7
				mt_com.mt_count);
			perror("failed");
			exit(2);
		}
	} else {
		if (ioctl(mtfd, MTIOCGET, (char *)&mt_status) < 0) {
			perror("mt");
			exit(2);
		}
		status(&mt_status);
	}
}

D 6
#include <sys/mtreg.h>
#include <sys/utreg.h>
#include <sys/htreg.h>
#include <sys/tmreg.h>
E 6
I 6
#ifdef vax
#include <vaxmba/mtreg.h>
#include <vaxmba/htreg.h>

#include <vaxuba/utreg.h>
#include <vaxuba/tmreg.h>
E 6
#undef b_repcnt		/* argh */
D 6
#include <sys/tsreg.h>
E 6
I 6
#include <vaxuba/tsreg.h>
#endif
E 6

I 7
#ifdef sun
D 9
#include <sys/tmreg.h>
#include <sys/arreg.h>
E 9
I 9
#include <sundev/tmreg.h>
#include <sundev/arreg.h>
E 9
#endif

I 12
#ifdef tahoe
#include <tahoevba/cyreg.h>
#endif

E 12
E 7
struct tape_desc {
	short	t_type;		/* type of magtape device */
	char	*t_name;	/* printing name */
	char	*t_dsbits;	/* "drive status" register */
	char	*t_erbits;	/* "error" register */
} tapes[] = {
I 6
#ifdef vax
E 6
	{ MT_ISTS,	"ts11",		0,		TSXS0_BITS },
	{ MT_ISHT,	"tm03",		HTDS_BITS,	HTER_BITS },
	{ MT_ISTM,	"tm11",		0,		TMER_BITS },
	{ MT_ISMT,	"tu78",		MTDS_BITS,	0 },
	{ MT_ISUT,	"tu45",		UTDS_BITS,	UTER_BITS },
I 6
#endif
I 7
#ifdef sun
	{ MT_ISCPC,	"TapeMaster",	TMS_BITS,	0 },
D 9
	{ MT_ISARCH,	"Archive",	ARCH_CTRL_BITS,	ARCH_BITS },
E 9
I 9
	{ MT_ISAR,	"Archive",	ARCH_CTRL_BITS,	ARCH_BITS },
I 12
#endif
#ifdef tahoe
	{ MT_ISCY,	"cipher",	CYS_BITS,	CYCW_BITS },
E 12
E 9
#endif
E 7
E 6
	{ 0 }
};

/*
 * Interpret the status buffer returned
 */
status(bp)
	register struct mtget *bp;
{
	register struct tape_desc *mt;

	for (mt = tapes; mt->t_type; mt++)
		if (mt->t_type == bp->mt_type)
			break;
	if (mt->t_type == 0) {
		printf("unknown tape drive type (%d)\n", bp->mt_type);
		return;
	}
D 7
	printf("%s tape drive\n", mt->t_name);
E 7
I 7
	printf("%s tape drive, residual=%d\n", mt->t_name, bp->mt_resid);
E 7
	printreg("ds", bp->mt_dsreg, mt->t_dsbits);
D 7
	printreg(" er", bp->mt_erreg, mt->t_erbits);
	printf("\nresidual=%d\n", bp->mt_resid);
E 7
I 7
	printreg("\ner", bp->mt_erreg, mt->t_erbits);
	putchar('\n');
E 7
}

/*
 * Print a register a la the %b format of the kernel's printf
 */
printreg(s, v, bits)
D 7
	char *s, *bits;
	unsigned short v;
E 7
I 7
	char *s;
	register char *bits;
	register unsigned short v;
E 7
{
	register int i, any = 0;
	register char c;

D 7
	printf("%s=%o", s, v);
E 7
I 7
	if (bits && *bits == 8)
		printf("%s=%o", s, v);
	else
		printf("%s=%x", s, v);
	bits++;
E 7
	if (v && bits) {
		putchar('<');
		while (i = *bits++) {
			if (v & (1 << (i-1))) {
				if (any)
					putchar(',');
				any = 1;
				for (; (c = *bits) > 32; bits++)
					putchar(c);
			} else
				for (; *bits > 32; bits++)
					;
		}
D 7
		if (any)
			putchar('>');
E 7
I 7
		putchar('>');
E 7
E 5
	}
}
E 1
