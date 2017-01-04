h53759
s 00001/00001/00155
d D 5.2 88/01/03 00:20:00 bostic 12 11
c it's really a union; for ANSI C
e
s 00008/00002/00148
d D 5.1 85/06/05 13:58:41 dist 11 10
c Add copyright
e
s 00000/00000/00150
d D 2.1 84/02/08 20:29:17 aoki 10 9
c synchronize to version 2
e
s 00002/00002/00148
d D 1.9 83/11/09 15:35:42 mckusick 9 8
c clean up output format of statement count
e
s 00008/00013/00142
d D 1.8 83/07/02 23:30:04 sam 8 7
c update to use getrusage{
e
s 00004/00003/00151
d D 1.7 83/01/22 01:22:11 mckusick 7 6
c name changes to confuse the innocent
e
s 00000/00001/00154
d D 1.6 82/08/29 16:33:10 mckusick 6 5
c get rid of unneeded header file
e
s 00045/00010/00110
d D 1.5 82/02/03 00:00:26 mckusic 5 4
c get rid of panics, so that all signals and errors pass through ERROR()
e
s 00001/00001/00119
d D 1.4 81/03/06 23:56:47 mckusic 4 3
c fix lint warnings
e
s 00004/00003/00116
d D 1.3 81/03/06 23:01:54 mckusic 3 2
c add onyx code
e
s 00038/00032/00081
d D 1.2 81/01/10 18:25:10 mckusic 2 1
c add "ap" and "fp" notion, fix SUCC and PRED
e
s 00113/00000/00000
d D 1.1 81/01/07 16:56:07 mckusick 1 0
c date and time created 81/01/07 16:56:07 by mckusick
e
u
U
t
T
I 1
D 11
/* Copyright (c) 1979 Regents of the University of California */
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 11

D 11
static char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 11

I 5
#include	<signal.h>
E 5
I 3
#include	"whoami.h"
E 3
#include	"vars.h"
I 7
#include	"objfmt.h"
I 8
#include	<sys/time.h>
#include	<sys/resource.h>
E 8
E 7
D 5
#include	"panics.h"
E 5
D 6
#include	"h02opcs.h"
E 6

stats()
{
D 8
	struct	{
		long	usr_time;
		long	sys_time;
		long	child_usr_time;
		long	child_sys_time;
D 2
		} tbuf;
E 2
I 2
	} tbuf;
E 8
I 8
	struct rusage ru;
E 8
E 2
	register double l;
	register long count;
I 2
#	ifdef PROFILE
#	define	proffile	"/vb/grad/mckusick/px/profile/pcnt.out"
	struct cntrec {
		double	counts[NUMOPS];	/* instruction counts */
		long	runs;		/* number of interpreter runs */
		long	startdate;	/* date profile started */
		long	usrtime;	/* total user time consumed */
		long	systime;	/* total system time consumed */
		double	stmts;		/* number of pascal stmts executed */
	} profdata;
	FILE *datafile;
#	endif PROFILE
E 2

	if (_nodump)
		return(0);
D 8
	times(&tbuf);
E 8
I 8
	getrusage(RUSAGE_SELF, &ru);
E 8
D 2
#ifdef profile
E 2
I 2
#	ifdef PROFILE
E 2
	datafile = fopen(proffile,"r");
D 2
	if (datafile != NULL) {
		count = fread(&profdata,sizeof(profdata),1,datafile);
		if (count != 1) {
			for (count = 0;  count < numops;  count++)
				profdata.counts[count] = 0.0;
			profdata.runs = 0;
			profdata.startdate = time(0);
			profdata.usrtime = 0;
			profdata.systime = 0;
			profdata.stmts = 0;
		}
		for (count = 0;  count < numops;  count++)
			profdata.counts[count] += profcnts[count];
		profdata.runs += 1;
		profdata.stmts += stcnt;
		profdata.usrtime += tbuf.usr_time;
		profdata.systime += tbuf.sys_time;
		datafile = freopen(proffile,"w",datafile);
		if (datafile != NULL) {
			fwrite(&profdata,sizeof(profdata),1,datafile);
			fclose(datafile);
		}
	}
#endif
E 2
I 2
	if (datafile == NULL)
		goto skipprof;
	count = fread(&profdata,1,sizeof(profdata),datafile);
	if (count != sizeof(profdata))
		goto skipprof;
	for (count = 0;  count < NUMOPS;  count++)
		profdata.counts[count] += _profcnts[count];
	profdata.runs += 1;
	profdata.stmts += _stcnt;
D 8
	profdata.usrtime += tbuf.usr_time;
	profdata.systime += tbuf.sys_time;
E 8
I 8
	profdata.usrtime += ru.ru_utime.tv_sec;
	profdata.systime += ru.ru_stime.tv_sec;
E 8
	datafile = freopen(proffile,"w",datafile);
	if (datafile == NULL)
		goto skipprof;
	count = fwrite(&profdata,1,sizeof(profdata),datafile);
	if (count != sizeof(profdata))
		goto skipprof;
	fclose(datafile);
skipprof:
#	endif PROFILE
E 2
D 8
	l = tbuf.usr_time;
	l = l / HZ;
E 8
	fprintf(stderr,
D 8
		"\n%1ld statements executed in %04.2f seconds cpu time.\n",
		_stcnt,l);
E 8
I 8
D 9
		"\n%1ld statements executed in %04d.%02d seconds cpu time.\n",
		_stcnt, ru.ru_utime.tv_sec, ru.ru_utime.tv_usec / 1000);
E 9
I 9
		"\n%1ld statements executed in %d.%02d seconds cpu time.\n",
		_stcnt, ru.ru_utime.tv_sec, ru.ru_utime.tv_usec / 10000);
E 9
E 8
}

D 5
backtrace(errnum)
D 3
	long	errnum;
E 3
I 3
	int	errnum;
E 5
I 5
backtrace(type)
	char	*type;
E 5
E 3
{
D 7
	register struct disp *mydp;
	register struct stack *ap;
E 7
I 7
	register struct dispsave *mydp;
	register struct blockmark *ap;
E 7
	register char *cp;
	register long i, linum;
D 2
	struct disp disp[MAXLVL];
E 2
I 2
D 7
	struct disply disp;
E 7
I 7
D 12
	struct display disp;
E 12
I 12
	union display disp;
E 12
E 7
E 2

	if (_lino <= 0) {
		fputs("Program was not executed.\n",stderr);
		return;
	}
D 2
	for (i=0; i<MAXLVL; i++)
		disp[i] = _display[i];
E 2
I 2
	disp = _display;
E 2
D 5
	if (errnum == PINTR)
		fputs("\n\tInterrupted in \"",stderr);
	else if (errnum == PHALT)
		fputs("\n\tHalted in \"",stderr);
	else
		fputs("\n\tError in \"",stderr);
E 5
I 5
	fprintf(stderr, "\n\t%s in \"", type);
E 5
	mydp = _dp;
	linum = _lino;
	for (;;) {
		ap = mydp->stp;
		i = linum - (((ap)->entry)->offset & 0177777);
		fprintf(stderr,"%s\"",(ap->entry)->name);
D 4
		if (_nodump == 0)
E 4
I 4
		if (_nodump == FALSE)
E 4
D 3
			fprintf(stderr,"+%1d near line %1d.",i,linum);
E 3
I 3
			fprintf(stderr,"+%D near line %D.",i,linum);
E 3
		fputc('\n',stderr);
		*mydp = (ap)->odisp;
D 2
		if (mydp <= &_display[1]){
			for (i=0; i<MAXLVL; i++)
				_display[i] = disp[i];
E 2
I 2
		if (mydp <= &_display.frame[1]){
			_display = disp;
E 2
D 5
			psexit(errnum);
E 5
I 5
			return;
E 5
		}
		mydp = (ap)->dp;
		linum = (ap)->lino;
		fputs("\tCalled by \"",stderr);
	}
}

psexit(code)

D 3
	long	code;
E 3
I 3
	int	code;
E 3
{
	if (_pcpcount != 0)
		PMFLUSH(_cntrs, _rtns, _pcpcount);
	if (_mode == PIX) {
		fputs("Execution terminated",stderr);
		if (code)
			fputs(" abnormally",stderr);
		fputc('.',stderr);
		fputc('\n',stderr);
	}
	stats();
	exit(code);
I 5
}

/*
 * Routines to field various types of signals
 *
 * catch a library error and generate a backtrace
 */
liberr()
{
	backtrace("Error");
	psexit(2);
}

/*
 * catch an interrupt and generate a backtrace
 */
intr()
{
	signal(SIGINT, intr);
	backtrace("Interrupted");
	psexit(1);
}

/*
 * catch memory faults
 */
memsize()
{
	signal(SIGSEGV, memsize);
	ERROR("Run time stack overflow\n");
}

/*
 * catch random system faults
 */
syserr(signum)
	int signum;
{
	signal(signum, syserr);
	ERROR("Panic: Computational error in interpreter\n");
E 5
}
E 1
