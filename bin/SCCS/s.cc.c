h09507
s 00001/00001/00468
d D 4.17 00/08/30 10:34:44 msokolov 22 21
c pass -J to ccom as -XJ
e
s 00008/00001/00461
d D 4.16 00/08/30 02:10:44 msokolov 21 20
c pass -J along to ccom and as
e
s 00001/00001/00461
d D 4.15 87/10/22 09:48:31 bostic 20 19
c ANSI C; sprintf now returns an int.
e
s 00003/00001/00459
d D 4.14 87/09/16 15:50:52 bostic 19 18
c continue compile after cpp failure; bug report 4.3BSD/bin/78
e
s 00002/00000/00458
d D 4.13 85/09/18 23:47:19 lepreau 18 17
c catch HUP too
e
s 00001/00001/00457
d D 4.12 85/09/05 11:10:30 bloom 17 16
c don't assemble file.s if -M used
e
s 00012/00004/00446
d D 4.11 85/01/24 09:21:56 ralph 16 15
c added -f option to use short floats (non-standard).
e
s 00012/00004/00438
d D 4.10 84/12/04 15:41:53 ralph 15 14
c allow -o to work for -c and -S.
e
s 00003/00000/00439
d D 4.9 84/08/30 23:49:58 sam 14 13
c add -L option (a la -I for cpp) for specifying alternate directories 
c in which libraries may be found
e
s 00022/00004/00417
d D 4.8 84/03/24 19:56:55 mckusick 13 12
c add -M to cpp to generate Makefile dependencies
c add -d to list commands as they are exec'ed
e
s 00001/00001/00420
d D 4.7 83/07/01 23:57:45 wnj 12 11
c include problems
e
s 00013/00005/00408
d D 4.6 82/12/18 11:38:14 linton 11 10
c added "-gold" option to call ccom with "-XG" to get old stab format
e
s 00001/00001/00412
d D 4.5 82/05/07 16:15:16 mckusick 10 9
c update to new fs
e
s 00001/00001/00412
d D 4.4 82/03/31 21:55:50 mckusic 9 8
c change <sys/types.h> to <sys/param.h> for benefit of <ndir.h>
e
s 00002/00002/00411
d D 4.3 82/02/25 21:39:01 mckusic 8 7
c convert to new directory format
e
s 00007/00003/00406
d D 4.2 81/11/23 18:59:01 mckusic 7 6
c gprof mods
e
s 00000/00000/00409
d D 4.1 80/10/01 16:38:10 bill 6 5
c Define 4.1
e
s 00008/00008/00401
d D 3.5 80/09/20 18:40:48 bill 5 4
c install in /lib
e
s 00001/00012/00408
d D 3.4 80/09/06 02:15:43 bill 4 3
c unimplement '8' stuff
e
s 00001/00001/00419
d D 3.3 80/08/27 17:24:51 bill 3 2
c -t2
e
s 00009/00002/00411
d D 3.2 80/08/17 01:54:45 bill 2 1
c -R
e
s 00413/00000/00000
d D 3.1 80/08/15 01:55:07 bill 1 0
c date and time created 80/08/15 01:55:07 by bill
e
u
U
t
T
I 1
D 4
/* USE <wait.h> */
E 4
static	char sccsid[] = "%Z%%M% %I% %G%";
/*
 * cc - front end for C compiler
 */
D 9
#include <sys/types.h>
E 9
I 9
#include <sys/param.h>
E 9
#include <stdio.h>
#include <ctype.h>
#include <signal.h>
D 8
#include <dir.h>
E 8
I 8
D 10
#include <ndir.h>
E 10
I 10
D 12
#include <dir.h>
E 12
I 12
#include <sys/dir.h>
E 12
E 10
E 8

D 5
char	*cpp = "/usr/new/cpp";
char	*ccom = "/usr/new/ccom";
char	*c2 = "/usr/new/c2";
char	*as = "/usr/new/as";
char	*ld = "/usr/new/ld";
char	*crt0 = "/usr/new/crt0.o";
E 5
I 5
char	*cpp = "/lib/cpp";
char	*ccom = "/lib/ccom";
I 16
char	*sccom = "/lib/sccom";
E 16
char	*c2 = "/lib/c2";
char	*as = "/bin/as";
char	*ld = "/bin/ld";
char	*crt0 = "/lib/crt0.o";
E 5

char	tmp0[30];		/* big enough for /tmp/ctm%05.5d */
char	*tmp1, *tmp2, *tmp3, *tmp4, *tmp5;
char	*outfile;
char	*savestr(), *strspl(), *setsuf();
int	idexit();
char	**av, **clist, **llist, **plist;
D 2
int	cflag, eflag, gflag, oflag, pflag, sflag, wflag, cps8, exflag, proflag;
E 2
I 2
D 11
int	cflag, eflag, gflag, oflag, pflag, sflag, wflag, Rflag, exflag, proflag;
E 11
I 11
int	cflag, eflag, oflag, pflag, sflag, wflag, Rflag, exflag, proflag;
D 13
int	gflag, Gflag;
E 13
I 13
D 16
int	gflag, Gflag, Mflag, debug;
E 16
I 16
D 21
int	fflag, gflag, Gflag, Mflag, debug;
E 21
I 21
int	fflag, jflag, gflag, Gflag, Mflag, debug;
E 21
E 16
E 13
E 11
D 4
int	cps8;
E 4
E 2
char	*dflag;
int	exfail;
char	*chpass;
char	*npassname;

int	nc, nl, np, nxo, na;

#define	cunlink(s)	if (s) unlink(s)

main(argc, argv)
	char **argv;
{
	char *t;
	char *assource;
	int i, j, c;

	/* ld currently adds upto 5 args; 10 is room to spare */
	av = (char **)calloc(argc+10, sizeof (char **));
	clist = (char **)calloc(argc, sizeof (char **));
	llist = (char **)calloc(argc, sizeof (char **));
	plist = (char **)calloc(argc, sizeof (char **));
	for (i = 1; i < argc; i++) {
		if (*argv[i] == '-') switch (argv[i][1]) {

D 4
		case '8':
			cps8++;
			cpp = "/usr/bin/8cpp";
			ccom = "/usr/lib/8ccom";
			c2 = "/usr/bin/8c2";
			as = "/usr/bin/8as";
			ld = "/usr/bin/8ld";
			crt0 = "/usr/lib/8crt0";
			continue;
E 4
		case 'S':
			sflag++;
			cflag++;
			continue;
		case 'o':
			if (++i < argc) {
				outfile = argv[i];
				switch (getsuf(outfile)) {

				case 'c':
D 15
				case 'o':
E 15
					error("-o would overwrite %s",
					    outfile);
					exit(8);
				}
			}
			continue;
I 2
		case 'R':
			Rflag++;
			continue;
E 2
		case 'O':
			oflag++;
			continue;
		case 'p':
			proflag++;
I 7
			crt0 = "/lib/mcrt0.o";
			if (argv[i][2] == 'g')
				crt0 = "/usr/lib/gcrt0.o";
E 7
			continue;
I 16
		case 'f':
			fflag++;
			continue;
I 21
		case 'J':
			jflag++;
			continue;
E 21
E 16
		case 'g':
D 11
			gflag++;
E 11
I 11
			if (argv[i][2] == 'o') {
			    Gflag++;	/* old format for -go */
			} else {
			    gflag++;	/* new format for -g */
			}
E 11
			continue;
		case 'w':
			wflag++;
			continue;
		case 'E':
			exflag++;
		case 'P':
			pflag++;
			if (argv[i][1]=='P')
				fprintf(stderr,
	"cc: warning: -P option obsolete; you should use -E instead\n");
			plist[np++] = argv[i];
		case 'c':
			cflag++;
			continue;
I 13
		case 'M':
			exflag++;
			pflag++;
			Mflag++;
			/* and fall through */
E 13
		case 'D':
		case 'I':
		case 'U':
		case 'C':
			plist[np++] = argv[i];
			continue;
I 14
		case 'L':
			llist[nl++] = argv[i];
			continue;
E 14
		case 't':
			if (chpass)
				error("-t overwrites earlier option", 0);
			chpass = argv[i]+2;
			if (chpass[0]==0)
				chpass = "012p";
			continue;
		case 'B':
			if (npassname)
				error("-B overwrites earlier option", 0);
			npassname = argv[i]+2;
			if (npassname[0]==0)
				npassname = "/usr/c/o";
			continue;
		case 'd':
I 13
			if (argv[i][2] == '\0') {
				debug++;
				continue;
			}
E 13
			dflag = argv[i];
			continue;
		}
		t = argv[i];
		c = getsuf(t);
		if (c=='c' || c=='s' || exflag) {
			clist[nc++] = t;
			t = setsuf(t, 'o');
		}
		if (nodup(llist, t)) {
			llist[nl++] = t;
			if (getsuf(t)=='o')
				nxo++;
		}
	}
D 11
	if (gflag) {
E 11
I 11
	if (gflag || Gflag) {
E 11
		if (oflag)
			fprintf(stderr, "cc: warning: -g disables -O\n");
		oflag = 0;
	}
	if (npassname && chpass ==0)
		chpass = "012p";
	if (chpass && npassname==0)
D 3
		npassname = "/usr/c/";
E 3
I 3
D 5
		npassname = "/usr/new/new";
E 5
I 5
		npassname = "/usr/new";
E 5
E 3
	if (chpass)
	for (t=chpass; *t; t++) {
		switch (*t) {

		case '0':
D 16
			ccom = strspl(npassname, "ccom");
E 16
I 16
			if (fflag)
				sccom = strspl(npassname, "sccom");
			else
				ccom = strspl(npassname, "ccom");
E 16
			continue;
		case '2':
			c2 = strspl(npassname, "c2");
			continue;
		case 'p':
			cpp = strspl(npassname, "cpp");
			continue;
		}
	}
D 7
	if (proflag)
D 4
		crt0 = cps8 ? "/usr/lib/8mcrt0.o" : "/usr/new/mcrt0.o";
E 4
I 4
D 5
		crt0 = "/usr/new/mcrt0.o";
E 5
I 5
		crt0 = "/lib/mcrt0.o";
E 7
E 5
E 4
	if (nc==0)
		goto nocom;
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, idexit);
	if (signal(SIGTERM, SIG_IGN) != SIG_IGN)
		signal(SIGTERM, idexit);
I 18
	if (signal(SIGHUP, SIG_IGN) != SIG_IGN)
		signal(SIGHUP, idexit);
E 18
	if (pflag==0)
D 20
		sprintf(tmp0, "/tmp/ctm%05.5d", getpid());
E 20
I 20
		(void)sprintf(tmp0, "/tmp/ctm%05.5d", getpid());
E 20
	tmp1 = strspl(tmp0, "1");
	tmp2 = strspl(tmp0, "2");
	tmp3 = strspl(tmp0, "3");
	if (pflag==0)
		tmp4 = strspl(tmp0, "4");
	if (oflag)
		tmp5 = strspl(tmp0, "5");
	for (i=0; i<nc; i++) {
D 13
		if (nc > 1) {
E 13
I 13
		if (nc > 1 && !Mflag) {
E 13
			printf("%s:\n", clist[i]);
			fflush(stdout);
		}
D 17
		if (getsuf(clist[i]) == 's') {
E 17
I 17
		if (!Mflag && getsuf(clist[i]) == 's') {
E 17
			assource = clist[i];
			goto assemble;
		} else
			assource = tmp3;
		if (pflag)
			tmp4 = setsuf(clist[i], 'i');
D 13
		av[0] = "cpp"; av[1] = clist[i]; av[2] = exflag ? "-" : tmp4;
		na = 3;
E 13
I 13
		av[0] = "cpp"; av[1] = clist[i];
		na = 2;
		if (!exflag)
			av[na++] = tmp4;
E 13
		for (j = 0; j < np; j++)
			av[na++] = plist[j];
		av[na++] = 0;
		if (callsys(cpp, av)) {
			exfail++;
			eflag++;
I 19
			cflag++;
			continue;
E 19
		}
D 19
		if (pflag || exfail) {
E 19
I 19
		if (pflag) {
E 19
			cflag++;
			continue;
		}
D 15
		if (sflag)
			assource = tmp3 = setsuf(clist[i], 's');
E 15
I 15
		if (sflag) {
			if (nc==1 && outfile)
				tmp3 = outfile;
			else
				tmp3 = setsuf(clist[i], 's');
			assource = tmp3;
		}
E 15
D 16
		av[0] = "ccom"; av[1] = tmp4; av[2] = oflag?tmp5:tmp3; na = 3;
E 16
I 16
		av[0] = fflag ? "sccom" : "ccom";
		av[1] = tmp4; av[2] = oflag?tmp5:tmp3; na = 3;
E 16
		if (proflag)
			av[na++] = "-XP";
D 11
		if (gflag)
E 11
I 11
		if (gflag) {
E 11
			av[na++] = "-Xg";
I 11
		} else if (Gflag) {
			av[na++] = "-XG";
		}
I 21
		if (jflag)
D 22
			av[na++] = "-J";
E 22
I 22
			av[na++] = "-XJ";
E 22
E 21
E 11
		if (wflag)
			av[na++] = "-w";
		av[na] = 0;
D 16
		if (callsys(ccom, av)) {
E 16
I 16
		if (callsys(fflag ? sccom : ccom, av)) {
E 16
			cflag++;
			eflag++;
			continue;
		}
		if (oflag) {
			av[0] = "c2"; av[1] = tmp5; av[2] = tmp3; av[3] = 0;
			if (callsys(c2, av)) {
				unlink(tmp3);
				tmp3 = assource = tmp5;
			} else
				unlink(tmp5);
		}
		if (sflag)
			continue;
	assemble:
		cunlink(tmp1); cunlink(tmp2); cunlink(tmp4);
D 15
		av[0] = "as"; av[1] = "-o"; av[2] = setsuf(clist[i], 'o');
E 15
I 15
		av[0] = "as"; av[1] = "-o";
		if (cflag && nc==1 && outfile)
			av[2] = outfile;
		else
			av[2] = setsuf(clist[i], 'o');
E 15
D 2
		av[3] = assource; na = 4;
E 2
I 2
		na = 3;
		if (Rflag)
			av[na++] = "-R";
I 21
		if (jflag)
			av[na++] = "-J";
E 21
E 2
		if (dflag)
			av[na++] = dflag;
I 2
		av[na++] = assource;
E 2
		av[na] = 0;
		if (callsys(as, av) > 1) {
			cflag++;
			eflag++;
			continue;
		}
	}
nocom:
	if (cflag==0 && nl!=0) {
		i = 0;
		av[0] = "ld"; av[1] = "-X"; av[2] = crt0; na = 3;
		if (outfile) {
			av[na++] = "-o";
			av[na++] = outfile;
		}
		while (i < nl)
			av[na++] = llist[i++];
D 11
		if (gflag)
E 11
I 11
		if (gflag || Gflag)
E 11
			av[na++] = "-lg";
D 7
		av[na++] = "-lc";
E 7
I 7
		if (proflag)
			av[na++] = "-lc_p";
		else
			av[na++] = "-lc";
E 7
		av[na++] = 0;
		eflag |= callsys(ld, av);
		if (nc==1 && nxo==1 && eflag==0)
			unlink(setsuf(clist[0], 'o'));
	}
	dexit();
}

idexit()
{

	eflag = 100;
	dexit();
}

dexit()
{

	if (!pflag) {
		cunlink(tmp1);
		cunlink(tmp2);
		if (sflag==0)
			cunlink(tmp3);
		cunlink(tmp4);
		cunlink(tmp5);
	}
	exit(eflag);
}

error(s, x)
	char *s, *x;
{
	FILE *diag = exflag ? stderr : stdout;

	fprintf(diag, "cc: ");
	fprintf(diag, s, x);
	putc('\n', diag);
	exfail++;
	cflag++;
	eflag++;
}

getsuf(as)
char as[];
{
	register int c;
	register char *s;
	register int t;

	s = as;
	c = 0;
	while (t = *s++)
		if (t=='/')
			c = 0;
		else
			c++;
	s -= 3;
D 8
	if (c <= DIRSIZ && c > 2 && *s++ == '.')
E 8
I 8
	if (c <= MAXNAMLEN && c > 2 && *s++ == '.')
E 8
		return (*s);
	return (0);
}

char *
setsuf(as, ch)
	char *as;
{
	register char *s, *s1;

	s = s1 = savestr(as);
	while (*s)
		if (*s++ == '/')
			s1 = s;
	s[-1] = ch;
	return (s1);
}

callsys(f, v)
	char *f, **v;
{
	int t, status;
I 13
	char **cpp;
E 13

I 13
	if (debug) {
		fprintf(stderr, "%s:", f);
		for (cpp = v; *cpp != 0; cpp++)
			fprintf(stderr, " %s", *cpp);
		fprintf(stderr, "\n");
	}
E 13
	t = vfork();
	if (t == -1) {
		printf("No more processes\n");
		return (100);
	}
	if (t == 0) {
		execv(f, v);
		printf("Can't find %s\n", f);
		fflush(stdout);
		_exit(100);
	}
	while (t != wait(&status))
		;
	if ((t=(status&0377)) != 0 && t!=14) {
		if (t!=2) {
			printf("Fatal error in %s\n", f);
			eflag = 8;
		}
		dexit();
	}
	return ((status>>8) & 0377);
}

nodup(l, os)
	char **l, *os;
{
	register char *t, *s;
	register int c;

	s = os;
	if (getsuf(s) != 'o')
		return (1);
	while (t = *l++) {
		while (c = *s++)
			if (c != *t++)
				break;
		if (*t==0 && c==0)
			return (0);
		s = os;
	}
	return (1);
}

#define	NSAVETAB	1024
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
	saveleft -= len;
	return (cp);
}

char *
strspl(left, right)
	char *left, *right;
{
	char buf[BUFSIZ];

	strcpy(buf, left);
	strcat(buf, right);
	return (savestr(buf));
}
E 1
