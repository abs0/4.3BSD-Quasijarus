h23049
s 00001/00001/00616
d D 5.3 87/05/08 10:54:28 sam 30 29
c wait.h needs param.h (from jim mckie)
e
s 00004/00004/00613
d D 5.2 86/11/17 17:22:05 mckusick 29 28
c add CCI (tahoe) support
e
s 00014/00002/00603
d D 5.1 85/06/05 16:27:01 dist 28 27
c Add copyright
e
s 00005/00001/00600
d D 3.26 83/12/28 20:35:18 aoki 27 26
c dosys(): fork() used instead of vfork() to preserve the parent's
c SIGINT handler.  This is to fix the core-dump-on-ctrl-C bug.
e
s 00004/00002/00597
d D 3.25 83/07/02 23:28:49 sam 26 25
c include fix
e
s 00002/00000/00597
d D 3.24 83/06/10 15:44:31 mckusick 25 24
c pass -J flag through to pc0 so it can handle big case statements
e
s 00009/00001/00588
d D 3.23 83/06/06 17:54:47 peter 24 23
c error checks for -t.
e
s 00035/00007/00554
d D 3.22 83/06/01 20:01:14 peter 23 22
c add the -t flag to use temporary files elsewhere.
e
s 00000/00005/00561
d D 3.21 83/04/18 13:08:05 rt 22 21
c undo deltas to 3.18, so that libraries used with Pascal are 
c the "usual" ones on sun.
e
s 00003/00003/00563
d D 3.20 83/02/03 17:38:42 mckusick 21 20
c update defaults for -T0 -T2 -T3
e
s 00001/00000/00565
d D 3.19 83/02/01 22:09:07 peter 20 19
c ignore warnings returned by pc3.
e
s 00005/00000/00560
d D 3.18 83/01/21 15:14:28 mckusick 19 18
c sun library mods
e
s 00005/00005/00555
d D 3.17 82/11/12 19:22:28 mckusick 18 17
c redefine where all the source directories live (again...)
e
s 00042/00002/00518
d D 3.16 82/08/16 19:55:09 mckusick 17 16
c give more complete error messages when components of pc have fatal errors
e
s 00016/00010/00504
d D 3.15 82/07/29 16:31:11 mckusick 16 15
c pass -w flag to pc3 to suppress warning messages
e
s 00004/00003/00510
d D 3.14 82/07/19 15:16:48 mckusick 15 13
c add pcexterns to resolve outside references in pc3
e
s 00002/00002/00511
d R 3.14 82/02/03 00:15:39 mckusic 14 13
c use -lnm instead of -lm
e
s 00018/00005/00495
d D 3.13 81/11/23 18:48:58 mckusic 13 12
c gprof mods
e
s 00015/00000/00485
d D 3.12 81/06/08 00:49:12 mckusic 12 11
c put in optional path names for -Tn options
e
s 00009/00014/00476
d D 3.11 81/02/04 18:07:45 mckusic 11 10
c run pc2 after /lib/c2; remove /lib/c2 hacks from pc2
e
s 00002/00002/00488
d D 3.10 81/01/17 21:50:19 mckusic 10 9
c update location of pc2 and pc3 for -T option.
e
s 00001/00001/00489
d D 3.9 81/01/13 15:48:44 mckusic 9 8
c change from -lm to -lnm, Kahan's math library.
e
s 00001/00001/00489
d D 3.8 81/01/13 15:21:16 mckusic 8 7
c change name of ``pclib'' to ``libpc''
e
s 00017/00001/00473
d D 3.7 80/10/06 16:43:19 peter 7 6
c new test pclib location and dealing with .s files
e
s 00029/00022/00445
d D 3.6 80/09/24 01:21:15 bill 6 5
c Move programs to /lib instead of /new, share fortran code generator.
e
s 00002/00002/00465
d D 3.5 80/08/29 16:32:17 peter 5 4
c new -T names for pc0 and pc3 to /usr/src/new/pc[03]/a.out
e
s 00002/00002/00465
d D 3.4 80/08/29 16:24:24 bill 4 3
c -lc after -lm, not before it
e
s 00001/00000/00466
d D 3.3 80/08/22 18:17:59 bill 3 2
c -lm
e
s 00028/00022/00438
d D 3.2 80/08/17 01:58:33 bill 2 1
c -O by default, correct suffix routine, -p option
e
s 00460/00000/00000
d D 3.1 80/08/15 01:55:18 bill 1 0
c date and time created 80/08/15 01:55:18 by bill
e
u
U
t
T
I 28
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 28
I 1
D 26
static	char sccsid[] = "%Z%%M% %I% %G%";
E 26
I 26
#ifndef lint
D 28
static	char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 28
I 28
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 28
E 26
I 13

E 13
#include <stdio.h>
#include <signal.h>
D 26
#include <wait.h>
E 26
I 26
D 30
#include <sys/wait.h>
E 30
E 26
I 23
#include <sys/param.h>
I 30
#include <sys/wait.h>
E 30
E 23

/*
D 2
 * pc - front end for pascal compiler.
E 2
I 2
 * Pc - front end for Pascal compiler.
E 2
 */
D 6
char	*pc0 = "/usr/new/pc0";
char	*pc1 = "/usr/new/pc1";
char	*pc2 = "/usr/new/pc2";
char	*c2 = "/usr/new/c2";
char	*pc3 = "/usr/new/pc3";
char	*ld = "/usr/new/ld";
char	*as = "/usr/new/as";
E 6
I 6
char	*pc0 = "/usr/lib/pc0";
char	*pc1 = "/lib/f1";
char	*pc2 = "/usr/lib/pc2";
char	*c2 = "/lib/c2";
char	*pc3 = "/usr/lib/pc3";
char	*ld = "/bin/ld";
char	*as = "/bin/as";
E 6
char	*lpc = "-lpc";
I 2
D 6
char	*crt0 = "/usr/new/crt0.o";
char	*mcrt0 = "/usr/new/mcrt0.o";
E 6
I 6
char	*crt0 = "/lib/crt0.o";
char	*mcrt0 = "/lib/mcrt0.o";
I 13
char	*gcrt0 = "/usr/lib/gcrt0.o";
E 13
E 6
E 2

char	*mktemp();
I 23
char	*tmpdir = "/tmp";
char	tmp0[MAXPATHLEN], tmp1[MAXPATHLEN];
E 23
char	*tname[2];
char	*tfile[2];

char	*setsuf(), *savestr();

D 2
int	Sflag, Oflag, cflag, gflag;
E 2
I 2
D 6
int	Sflag, Oflag, cflag, gflag, pflag;
E 6
I 6
D 13
int	Jflag, Sflag, Oflag, cflag, gflag, pflag;
E 13
I 13
D 16
int	Jflag, Sflag, Oflag, Tlflag, cflag, gflag, pflag;
E 16
I 16
D 23
int	Jflag, Sflag, Oflag, Tlflag, cflag, gflag, pflag, wflag;
E 23
I 23
int	Jflag, Sflag, Oflag, Tlflag, cflag, gflag, pflag, wflag, tflag;
E 23
E 16
E 13
E 6
E 2
int	debug;

#define	NARGS	512
int	ldargx = 3;
int	pc0argx = 3;
char	*pc0args[NARGS] =	{ "pc0", "-o", "XXX" };
char	*pc1args[3] =		{ "pc1", 0, };
char	*pc2args[2] =		{ "pc2", 0 };
char	*c2args[4] =		{ "c2", 0, 0, 0 };
D 15
int	pc3argx = 1;
E 15
I 15
D 16
int	pc3argx = 2;
E 16
I 16
int	pc3argx = 1;
E 16
E 15
#define	pc3args	pc0args
#define	ldargs	pc0args
D 15
/* char	*pc3args[NARGS] =	{ "pc3", 0 }; */
E 15
I 15
D 16
/* char	*pc3args[NARGS] =	{ "pc3", /usr/lib/pcexterns.o, 0 }; */
E 16
I 16
/* char	*pc3args[NARGS] =	{ "pc3", 0 }; */
E 16
E 15
D 6
/* char	*ldargs[NARGS] =	{ "ld", "-X", "/usr/new/crt0.o", 0, }; */
char	*asargs[5] =		{ "as", 0, };
E 6
I 6
/* char	*ldargs[NARGS] =	{ "ld", "-X", "/lib/crt0.o", 0, }; */
I 23

				/* as -J -t tmpdir -o objfile srcfile \0 */
E 23
int	asargx;
D 23
char	*asargs[6] =		{ "as", 0, };
E 23
I 23
char	*asargs[8] =		{ "as", 0, };
E 23
E 6

I 17
char *mesg[] = {
	0,
	"Hangup",
	"Interrupt",	
	"Quit",
	"Illegal instruction",
	"Trace/BPT trap",
	"IOT trap",
	"EMT trap",
	"Floating exception",
	"Killed",
	"Bus error",
	"Segmentation fault",
	"Bad system call",
	"Broken pipe",
	"Alarm clock",
	"Terminated",
	"Signal 16",
	"Stopped (signal)",
	"Stopped",
	"Continued",
	"Child exited",
	"Stopped (tty input)",
	"Stopped (tty output)",
	"Tty input interrupt",
	"Cputime limit exceeded",
	"Filesize limit exceeded",
	"Signal 26",
	"Signal 27",
	"Signal 28",
	"Signal 29",
	"Signal 30",
	"Signal 31",
	"Signal 32"
};

E 17
/*
 * If the number of .p arguments (np) is 1, and the number of .o arguments
 * (nxo) is 0, and we successfully create an ``a.out'', then we remove
 * the one .ps .o file (onepso).
 */
int	np, nxo;
char	*onepso;
int	errs;

int	onintr();

main(argc, argv)
	int argc;
	char **argv;
{
	register char *argp;
	register int i;
	int savargx;
	char *t, c;
	int j;

	argc--, argv++;
	if (argc == 0) {
		execl("/bin/cat", "cat", "/usr/lib/how_pc");
		exit(1);
	}
	if (signal(SIGINT, SIG_IGN) != SIG_IGN) {
		signal(SIGINT, onintr);
		signal(SIGTERM, onintr);
	}
	for (i = 0; i < argc; i++) {
		argp = argv[i];
		if (argp[0] != '-')
			continue;
		switch (argp[1]) {

		case 'd':
			if (argp[2] == 0)
				debug++;
			continue;
		case 'i':
			pc0args[pc0argx++] = "-i";
			while (i+1 < argc && argv[i+1][0] != '-' &&
			    getsuf(argv[i+1]) != 'p') {
				pc0args[pc0argx++] = argv[i+1];
				i++;
			}
			if (i+1 == argc) {
				fprintf(stderr, "pc: bad -i construction\n");
				exit(1);
			}
			continue;
		case 'o':
			i++;
			if (i == argc) {
				fprintf(stderr, "pc: -o must specify file\n");
				exit(1);
			}
			c = getsuf(argv[i]);
			if (c == 'o' || c == 'p' || c == 'c') {
				fprintf(stderr, "pc: -o would overwrite %s\n",
				    argv[i]);
				exit(1);
			}
			continue;
I 23
		case 't':
			i++;
			if (i == argc) {
D 24
				fprintf(stderr, "pc: -T but no directory\n");
E 24
I 24
				fprintf(stderr, "pc: -t but no directory\n");
E 24
				exit(1);
			}
I 24
			if (argp[2] != '\0') {
				fprintf(stderr, "pc: bad -t option\n");
				exit(1);
			}
E 24
			tmpdir = argv[i];
I 24
			if (tmpdir[0] == '-') {
				fprintf(stderr, "pc: bad -t option\n");
				exit(1);
			}
E 24
			tflag = 1;
			continue;
E 23
		case 'O':
			Oflag = 1;
			continue;
		case 'S':
			Sflag = 1;
			continue;
I 6
		case 'J':
			Jflag = 1;
			continue;
E 6
		case 'T':
			switch (argp[2]) {

			case '0':
D 4
				pc0 = "/vb/grad/peter/pc/npc0/src/a.pc";
E 4
I 4
D 5
				pc0 = "/vb/grad/peter/pc/pc0/src/a.out";
E 5
I 5
D 6
				pc0 = "/usr/src/new/pc0/a.out";
E 6
I 6
D 18
				pc0 = "/usr/src/cmd/pc0/a.out";
E 18
I 18
D 21
				pc0 = "/usr/src/ucb/pc0/a.out";
E 21
I 21
				pc0 = "/usr/src/ucb/pascal/pc0/a.out";
E 21
E 18
I 12
				if (argp[3] != '\0') {
					pc0 = &argp[3];
				}
E 12
E 6
E 5
E 4
				continue;
			case '1':
D 6
				pc1 = "/usr/src/new/pcc/pc1";
E 6
I 6
D 18
				pc1 = "/usr/src/cmd/pcc/pc1";
E 18
I 18
				pc1 = "/usr/src/lib/pcc/fort";
E 18
I 12
				if (argp[3] != '\0') {
					pc1 = &argp[3];
				}
E 12
E 6
				continue;
			case '2':
D 6
				pc2 = "/usr/new/pc2";
E 6
I 6
D 10
				pc2 = "/usr/src/cmd/pc2/a.out";
E 10
I 10
D 18
				pc2 = "/usr/src/cmd/pascal/pc2";
E 18
I 18
D 21
				pc2 = "/usr/src/ucb/pascal/pc2";
E 21
I 21
				pc2 = "/usr/src/ucb/pascal/utilities/pc2";
E 21
E 18
I 12
				if (argp[3] != '\0') {
					pc2 = &argp[3];
				}
E 12
E 10
E 6
				continue;
			case '3':
D 5
				pc3 = "/usr/new/pc3";
E 5
I 5
D 6
				pc3 = "/usr/src/new/pc3/a.out";
E 6
I 6
D 10
				pc3 = "/usr/src/cmd/pc3/a.out";
E 10
I 10
D 18
				pc3 = "/usr/src/cmd/pascal/pc3";
E 18
I 18
D 21
				pc3 = "/usr/src/ucb/pascal/pc3";
E 21
I 21
				pc3 = "/usr/src/ucb/pascal/utilities/pc3";
E 21
E 18
I 12
				if (argp[3] != '\0') {
					pc3 = &argp[3];
				}
E 12
E 10
E 6
E 5
				continue;
			case 'l':
I 13
				Tlflag = 1;
E 13
D 7
				lpc = "-lnpc";
E 7
I 7
D 8
				lpc = "/usr/src/lib/libpc/pclib";
E 8
I 8
D 18
				lpc = "/usr/src/lib/libpc/libpc";
E 18
I 18
				lpc = "/usr/src/usr.lib/libpc/libpc";
E 18
I 12
				if (argp[3] != '\0') {
					lpc = &argp[3];
				}
E 12
E 8
E 7
				continue;
			}
			continue;
		case 'c':
			cflag = 1;
			continue;
		case 'l':
			if (argp[2])
				continue;
			/* fall into ... */
		case 'b':
D 16
		case 'g':
E 16
		case 's':
D 16
		case 'w':
E 16
		case 'z':
		case 'C':
			pc0args[pc0argx++] = argp;
D 16
			if (argp[1] == 'g')
				gflag = 1;
E 16
			continue;
I 16
		case 'w':
			wflag = 1;
			pc0args[pc0argx++] = argp;
			continue;
		case 'g':
			gflag = 1;
			pc0args[pc0argx++] = argp;
			continue;
E 16
D 23
		case 't':
			fprintf(stderr, "pc: -t is default; -C for checking\n");
			continue;
E 23
		case 'p':
D 2
			fprintf(stderr, "pc: -p (profiling) not implemented\n");
			exit(1);
E 2
I 2
D 13
			crt0 = mcrt0;
			pflag++;
E 13
I 13
			if (argp[2] == 'g')
				crt0 = gcrt0;
			else
				crt0 = mcrt0;
			if (!Tlflag)
				lpc = "-lpc_p";
			pflag = 1;
E 13
			continue;
E 2
		}
	}
	if (gflag && Oflag) {
		fprintf(stderr, "pc: warning: -g overrides -O\n");
		Oflag = 0;
	}
D 23
	tname[0] = mktemp("/tmp/p0XXXXXX");
	tname[1] = mktemp("/tmp/p1XXXXXX");
E 23
I 23
	sprintf(tmp0, "%s/%s", tmpdir, "p0XXXXXX");
	tname[0] = mktemp(tmp0);
	sprintf(tmp1, "%s/%s", tmpdir, "p1XXXXXX");
	tname[1] = mktemp(tmp1);
E 23
	savargx = pc0argx;
	for (i = 0; i < argc; i++) {
		argp = argv[i];
		if (argp[0] == '-')
			continue;
I 7
		if (suffix(argp) == 's') {
			asargx = 1;
			if (Jflag)
				asargs[asargx++] = "-J";
I 23
D 29
#			ifdef vax
E 29
I 29
#			if defined(vax) || defined(tahoe)
E 29
				if (tflag) {
					asargs[asargx++] = "-t";
					asargs[asargx++] = tmpdir;
				}
D 29
#			endif vax
E 29
I 29
#			endif vax || tahoe
E 29
E 23
			asargs[asargx++] = argp;
			asargs[asargx++] = "-o";
			tfile[1] = setsuf(argp, 'o');
			asargs[asargx++] = tfile[1];
			asargs[asargx] = 0;
			if (dosys(as, asargs, 0, 0))
				continue;
			tfile[1] = 0;
			continue;
		}
E 7
		if (suffix(argp) != 'p')
			continue;
		tfile[0] = tname[0];
		pc0args[2] = tfile[0];
		pc0argx = savargx;
I 2
		if (pflag)
			pc0args[pc0argx++] = "-p";
I 25
		if (Jflag)
			pc0args[pc0argx++] = "-J";
E 25
E 2
		pc0args[pc0argx++] = argp;
		pc0args[pc0argx] = 0;
		if (dosys(pc0, pc0args, 0, 0))
			continue;
		pc1args[1] = tfile[0];
D 2
		if (Sflag && !Oflag)
			tfile[1] = setsuf(argp, 's');
		else
			tfile[1] = tname[1];
E 2
I 2
		tfile[1] = tname[1];
E 2
		if (dosys(pc1, pc1args, 0, tfile[1]))
			continue;
		unlink(tfile[0]);
I 2
D 11
		if (Sflag && !Oflag)
E 11
I 11
		tfile[0] = tname[0];
		if (Oflag) {
			if (dosys(c2, c2args, tfile[1], tfile[0]))
				continue;
			unlink(tfile[1]);
			tfile[1] = tfile[0];
			tfile[0] = tname[1];
		}
		if (Sflag)
E 11
			tfile[0] = setsuf(argp, 's');
D 11
		else
			tfile[0] = tname[0];
E 11
E 2
		if (dosys(pc2, pc2args, tfile[1], tfile[0]))
			continue;
		unlink(tfile[1]);
		tfile[1] = 0;
D 11
		if (Oflag) {
			if (Sflag)
				tfile[1] = setsuf(argp, 's');
			else
D 2
				tfile[1] = tname[0];
E 2
I 2
				tfile[1] = tname[1];
E 2
			if (dosys(c2, c2args, tfile[0], tfile[1]))
				continue;
			unlink(tfile[0]);
			tfile[0] = tfile[1];
			tfile[1] = 0;
		}
E 11
D 2
		if (Sflag)
E 2
I 2
		if (Sflag) {
			tfile[0] = 0;
E 2
			continue;
I 2
		}
E 2
D 6
		asargs[1] = tfile[0];
		asargs[2] = "-o";
E 6
I 6
		asargx = 1;
		if (Jflag)
			asargs[asargx++] = "-J";
I 23
D 29
#		ifdef vax
E 29
I 29
#		if defined(vax) || defined(tahoe)
E 29
			if (tflag) {
				asargs[asargx++] = "-t";
				asargs[asargx++] = tmpdir;
			}
D 29
#		endif vax
E 29
I 29
#		endif vax || tahoe
E 29
E 23
		asargs[asargx++] = tfile[0];
		asargs[asargx++] = "-o";
E 6
		tfile[1] = setsuf(argp, 'o');
D 6
		asargs[3] = tfile[1];
E 6
I 6
		asargs[asargx++] = tfile[1];
		asargs[asargx] = 0;
E 6
		if (dosys(as, asargs, 0, 0))
			continue;
		tfile[1] = 0;
		remove();
	}
	if (errs || cflag || Sflag)
		done();
D 15
/* char	*pc3args[NARGS] =	{ "pc3", 0 }; */
E 15
I 15
D 16
/* char	*pc3args[NARGS] =	{ "pc3", "/usr/lib/pcexterns.o", 0 }; */
E 16
I 16
/* char	*pc3args[NARGS] =	{ "pc3", 0 }; */
E 16
E 15
	pc3args[0] = "pc3";
I 15
D 16
	pc3args[1] = "/usr/lib/pcexterns.o";
E 16
I 16
	if (wflag)
		pc3args[pc3argx++] = "-w";
	pc3args[pc3argx++] = "/usr/lib/pcexterns.o";
E 16
E 15
	for (i = 0; i < argc; i++) {
		argp = argv[i];
		if (!strcmp(argp, "-o"))
			i++;
		if (argp[0] == '-')
			continue;
		switch (getsuf(argp)) {

D 6
		case 'd':
			continue;
E 6
		case 'o':
			pc3args[pc3argx++] = argp;
			nxo++;
			continue;
I 7
		case 's':
E 7
		case 'p':
			onepso = pc3args[pc3argx++] =
			    savestr(setsuf(argp, 'o'));
			np++;
			continue;
		}
	}
	pc3args[pc3argx] = 0;
D 16
	if (dosys(pc3, pc3args, 0, 0))
E 16
I 16
	if (dosys(pc3, pc3args, 0, 0) > 1)
E 16
		done();
I 20
	errs = 0;
E 20
D 6
/* char	*ldargs[NARGS] =	{ "ld", "-X", "/usr/new/crt0.o", 0, }; */
E 6
I 6
/* char	*ldargs[NARGS] =	{ "ld", "-X", "/lib/crt0.o", 0, }; */
E 6
	ldargs[0] = "ld";
	ldargs[1] = "-X";
D 2
	ldargs[2] = "/usr/new/crt0.o";
E 2
I 2
	ldargs[2] = crt0;
E 2
	for (i = 0; i < argc; i++) {
		argp = argv[i];
		if (argp[0] != '-') {
			switch (getsuf(argp)) {

			case 'p':
I 7
			case 's':
E 7
				ldargs[ldargx] = savestr(setsuf(argp, 'o'));
				break;
			default:
				ldargs[ldargx] = argp;
				break;
			}
			if (getsuf(ldargs[ldargx]) == 'o')
			for (j = 0; j < ldargx; j++)
				if (!strcmp(ldargs[j], ldargs[ldargx]))
					goto duplicate;
			ldargx++;
duplicate:
			continue;
		}
		switch (argp[1]) {

		case 'i':
			while (i+1 < argc && argv[i+1][0] != '-' &&
			    getsuf(argv[i+1]) != 'p')
				i++;
			continue;
		case 'd':
			if (argp[2] == 0)
				continue;
			ldargs[ldargx++] = argp;
			continue;
		case 'o':
			ldargs[ldargx++] = argp;
			i++;
			ldargs[ldargx++] = argv[i];
			continue;
		case 'l':
			if (argp[2])
				ldargs[ldargx++] = argp;
I 23
			continue;
		case 't':
			i++;
E 23
			continue;
		case 'c':
		case 'g':
		case 'w':
		case 'p':
		case 'S':
I 6
		case 'J':
E 6
		case 'T':
		case 'O':
		case 'C':
		case 'b':
		case 's':
		case 'z':
			continue;
		default:
			ldargs[ldargx++] = argp;
			continue;
		}
	}
	ldargs[ldargx++] = lpc;
	if (gflag)
		ldargs[ldargx++] = "-lg";
D 4
	ldargs[ldargx++] = "-lc";
E 4
I 3
D 9
	ldargs[ldargx++] = "-lm";
E 9
I 9
D 13
	ldargs[ldargx++] = "-lnm";
E 9
I 4
	ldargs[ldargx++] = "-lc";
E 13
I 13
	if (pflag) {
		ldargs[ldargx++] = "-lm_p";
		ldargs[ldargx++] = "-lc_p";
	} else {
I 19
D 22
#ifndef sun
E 22
E 19
		ldargs[ldargx++] = "-lm";
		ldargs[ldargx++] = "-lc";
I 19
D 22
#else
		ldargs[ldargx++] = "-lMm";
		ldargs[ldargx++] = "-lMc";
#endif
E 22
E 19
	}
E 13
E 4
E 3
	ldargs[ldargx] = 0;
	if (dosys(ld, ldargs, 0, 0)==0 && np == 1 && nxo == 0)
		unlink(onepso);
	done();
}

dosys(cmd, argv, in, out)
	char *cmd, **argv, *in, *out;
{
	union wait status;
	int pid;

	if (debug) {
		int i;
		printf("%s:", cmd);
		for (i = 0; argv[i]; i++)
			printf(" %s", argv[i]);
		if (in)
			printf(" <%s", in);
		if (out)
			printf(" >%s", out);
		printf("\n");
	}
D 27
	pid = vfork();
E 27
I 27
	/*
	 * warning: vfork doesn't work here, because the call to signal() 
	 * done by the child process destroys the parent's SIGINT handler.
	 */
	pid = fork();
E 27
	if (pid < 0) {
		fprintf(stderr, "pc: No more processes\n");
		done();
	}
	if (pid == 0) {
		if (in) {
			close(0);
			if (open(in, 0) != 0) {
				perror(in);
				exit(1);
			}
		}
		if (out) {
			close(1);
			unlink(out);
			if (creat(out, 0666) != 1) {
				perror(out);
				exit(1);
			}
		}
		signal(SIGINT, SIG_DFL);
		execv(cmd, argv);
		perror(cmd);
		exit(1);
	}
	while (wait(&status) != pid)
		;
	if (WIFSIGNALED(status)) {
D 17
		if (status.w_termsig != SIGINT)
			fprintf(stderr, "Fatal error in %s\n", cmd);
E 17
I 17
		if (status.w_termsig != SIGINT) {
			fprintf(stderr, "%s: %s", cmd, mesg[status.w_termsig]);
			if (status.w_coredump)
				fprintf(stderr, " (core dumped)");
			fprintf(stderr, "\n");
		}
E 17
		errs = 100;
		done();
		/*NOTREACHED*/
	}
	if (status.w_retcode) {
		errs = 1;
		remove();
	}
	return (status.w_retcode);
}

done()
{

	remove();
	exit(errs);
}

remove()
{

	if (tfile[0])
		unlink(tfile[0]);
	if (tfile[1])
		unlink(tfile[1]);
}

onintr()
{

	errs = 1;
	done();
}

getsuf(cp)
	char *cp;
{

	if (*cp == 0)
		return;
	while (cp[1])
		cp++;
	if (cp[-1] != '.')
		return (0);
	return (*cp);
}

D 2
char	sufbuf[BUFSIZ];

E 2
char *
D 2
setsuf(cp, c)
	char *cp;
E 2
I 2
setsuf(as, ch)
	char *as;
E 2
{
D 2
	register char *dp;
E 2
I 2
	register char *s, *s1;
E 2

D 2
	for (dp = sufbuf; *cp; *dp++ = *cp++)
		continue;
	*dp = 0;
	if (dp-sufbuf > 2 && dp[-2] == '.')
		dp[-1] = c;
	return (sufbuf);
E 2
I 2
	s = s1 = savestr(as);
	while (*s)
		if (*s++ == '/')
			s1 = s;
	s[-1] = ch;
	return (s1);
E 2
}

#define	NSAVETAB	512
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
			fprintf(stderr, "ran out of memory (savestr)\n");
			exit(1);
		}
	}
	strncpy(savetab, cp, len);
	cp = savetab;
	savetab += len;
	return (cp);
}

suffix(cp)
	char *cp;
{

	if (cp[0] == 0 || cp[1] == 0)
		return (0);
	while (cp[1])
		cp++;
	if (cp[-1] == '.')
		return (*cp);
	return (0);
}
E 1
