h15126
s 00000/00000/00141
d D 4.2 82/08/17 13:24:56 rrh 2 1
c Changed the data types for the sdb class characters to be unsigned
c characters; this fixed a bug that prevented the arguments to a function
c from being printed symbolically.  The fix was done globally; it is not
c known if the "fix" fixed other bugs
e
s 00141/00000/00000
d D 4.1 80/10/09 23:57:38 bill 1 0
c date and time created 80/10/09 23:57:38 by bill
e
u
U
t
T
I 1
static	char sccsid[] = "%Z%%M% %I% %G%";
#
/*
 *
 *	UNIX debugger
 *
 */

#include	"head.h"
#include	<signal.h>
#include	<stdio.h>
#include	<sys/stat.h>

INT		mkfault;
INT		executing;
CHAR		*lp;
L_INT		maxoff;
L_INT		maxpos;
ADDR		sigint;
ADDR		sigqit;
INT		wtflag;
L_INT		maxfile;
L_INT		maxstor;
L_INT		txtsiz;
L_INT		datsiz;
L_INT		datbas;
L_INT		stksiz;
STRING		errflg;
INT		magic;
L_INT		entrypt;

CHAR		lastc;

STRING		symfil;
STRING		corfil;
INT 		argcount;
ADDR		userpc;
int	fpe();

main(argc, argv)
REG STRING	*argv;
REG INT		argc;
{
	register char *p;
	struct stat stbuf;

	userpc = 1;
	symfil = "a.out";
	corfil = "core";
	maxfile=1L<<24; maxstor=1L<<31;
#ifndef STD
#ifndef VAX135
	maxstor -= ctob(UPAGES);
#endif
#endif

	setbuf(stdout, NULL);
	setbuf(stderr, NULL);

	WHILE argc>1
	DO	IF eqstr("-w",argv[1])
		THEN	wtflag=2; argc--; argv++;
		ELSE	break;
		FI
	OD

	IF argc>1 THEN symfil = argv[1]; FI
	IF argc>2 THEN corfil = argv[2]; FI
	fp = filework;
	if (argc > 3) {
		for (p = argv[3]; *p; *fp++ = *p++) ;
		*fp++ = '/';
	}
	argcount=argc;

	if (stat(symfil, &stbuf) == -1) {
		printf("`%s' does not exist\n", symfil);
		exit(4);
	}
	symtime = stbuf.st_mtime;
	if (stat(corfil, &stbuf) != -1) {
		if (symtime > stbuf.st_mtime)
			printf("Warning: `%s' newer than `%s'\n",
				symfil, corfil);
	}

	setsym(); setcor();
	initfp();
	mkioptab();

	/* set up variables for user */
	maxoff=MAXOFF; maxpos=MAXPOS;
	gtty(2, &sdbttym);
	IF (sigint= (ADDR) signal(SIGINT,01))!=01
	THEN	sigint= (ADDR) fault; signal(SIGINT,fault);
	FI
	sigqit= (ADDR) signal(SIGQUIT,1);
	signal(SIGILL, fpe);

	setjmp(env);
	if (debug) printf("Sdb restarted\n");
	gtty(2, &userttym);
	if (sdbttym.sg_flags != userttym.sg_flags)
		stty(2, &sdbttym);
	IF executing THEN delbp(); FI
	executing=FALSE;

	for (;;) {
		mkfault = 0;
		printf("*");
		if (decode(readline(stdin)) == 1) {
			printf("Error; try again\n");
			continue;
		}

	if (debug) {
		printf("cmd %c:\n", cmd);
		printf("%s:%s\n", proc, var);
		printf("args-%s;re-%s;integ-%d\n", args, re, integ);
		printf("scallf-%d;reflg-%d\n", scallf, reflag);
		printf("colonflag-%d;ncolonflag-%d\n\n",
			colonflag, ncolonflag);
 	}
		docommand();
	}
}


fault(a)
{
	signal(a,fault);
	mkfault++;
	printf("\n");
	longjmp(env, 0);
}

fpe() {
	signal(SIGILL, fpe);
	error("Illegal floating constant");
	longjmp(env, 0);
}
E 1
