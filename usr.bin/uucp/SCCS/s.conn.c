h39006
s 00010/00017/01156
d D 5.15 88/05/04 13:52:28 rick 15 14
c fix \s problem in expect, setprotitle
e
s 00003/00001/01170
d D 5.14 88/04/24 16:47:51 bostic 14 13
c fix for ANSI C
e
s 00027/00009/01144
d D 5.13 88/04/05 12:04:44 rick 13 12
c use syslog for errors
e
s 00003/00000/01150
d D 5.12 88/02/24 20:08:52 rick 12 11
c add missing sccsid
e
s 00048/00045/01102
d D 5.11 88/02/24 19:53:10 rick 11 10
c new code for PC Pursuit
e
s 00009/00046/01138
d D 5.10 86/01/24 13:19:29 bloom 10 9
c still more fixes and changes from rick@seismo
e
s 00203/00099/00981
d D 5.9 86/01/06 15:01:32 bloom 9 8
c more fixes from rick adams
e
s 00033/00000/01047
d D 5.8 85/11/22 05:48:12 tef 8 7
c Must set linebaudrate variable when in slave mode too.
e
s 00093/00030/00954
d D 5.7 85/10/09 15:43:49 bloom 7 6
c still more fixes from rick@seismo
e
s 00069/00057/00915
d D 5.6 85/06/19 18:23:16 bloom 6 5
c fixes from rick adams
e
s 00075/00095/00897
d D 5.5 85/04/10 15:19:17 ralph 5 4
c more changes from rick adams.
e
s 00294/00189/00698
d D 5.4 85/01/22 14:07:43 ralph 4 3
c bug fixes and changes from Rick Adams
e
s 00001/00001/00886
d D 5.3 83/08/13 10:22:36 karels 3 2
c rdvec doesn't need to be static, makes uucico fit on PDP11's
e
s 00001/00001/00886
d D 5.2 83/07/02 18:24:54 sam 2 1
c include fixes
e
s 00887/00000/00000
d D 5.1 83/07/02 17:56:41 sam 1 0
c date and time created 83/07/02 17:56:41 by sam
e
u
U
t
T
I 12
#ifndef lint
D 13
static char sccsid[] = "%W% (Berkeley) %G%";
E 13
I 13
static char sccsid[] = "%W%	(Berkeley) %G%";
E 13
#endif
E 12
I 1
D 11
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 11

D 6
#include "uucp.h"
E 6
#include <signal.h>
I 6
#include "uucp.h"
E 6
#include <setjmp.h>
#include <ctype.h>
D 5
#include <sys/types.h>
E 5
D 2
#include <time.h>
E 2
I 2
D 4
#include <sys/time.h>
E 4
E 2
#include <errno.h>
D 4
#ifdef	SYSIII
E 4
I 4
#ifdef	USG
E 4
#include <termio.h>
#include <fcntl.h>
#endif
D 4
#ifndef	SYSIII
E 4
I 4
#ifndef	USG
E 4
#include <sgtty.h>
#endif
I 4
#ifdef BSD4_2
#include <sys/time.h>
#else
#include <time.h>
#endif
E 4

#define MAXC 1000

extern jmp_buf Sjbuf;
I 4
jmp_buf Cjbuf;
E 4
D 5
extern int errno;
E 5
I 5
extern int errno, onesys;
E 5
I 4
extern char *sys_errlist[];
I 5
extern char MaxGrade, DefMaxGrade;
E 5
E 4

/* Parity control during login procedure */
#define	P_ZERO	0
#define	P_ONE	1
#define	P_EVEN	2
#define	P_ODD	3
D 4
char	par_tab[128];	/* must be power of two */
E 4

I 4
#define ABORT -2

char 	*AbortOn = NULL;
char	par_tab[128];	/* must be power of two */
int	linebaudrate;	/* used for the sleep test in pk1.c */
E 4
int next_fd = -1;	/* predicted fd to close interrupted opens */
D 9
				/* rti!trt, courtesy unc!smb */
E 9
I 9

char *PCP = "PCP";	/* PC Pursuit device type */
E 9
D 7
/***
 *	alarmtr()  -  catch alarm routine for "expect".
E 7
I 7
/*
 *	catch alarm routine for "expect".
E 7
 */
alarmtr()
{
	signal(SIGALRM, alarmtr);
	if (next_fd >= 0) {
		if (close(next_fd))
			logent("FAIL", "ACU LINE CLOSE");
		next_fd = -1;
	}
	longjmp(Sjbuf, 1);
}

I 9
/* This template is for seismo to call ihnp4 
 * the 3 lines marked ---> will be overwritten for the appropriate city
 */
#define PCP_BAUD	3
#define PCP_PHONE	4
D 11
#define PCP_CALLBACK	8
#define PCP_CITY	10
#define PCP_RPHONE	12
#define NPCFIELDS	15
E 11
I 11
#define PCP_CITY	14
#define PCP_PASSWORD	16
#define PCP_RPHONE	20
#define NPCFIELDS	23
E 11

static char *PCFlds[] = {
	"PC-PURSUIT",
	"Any",
	"ACU",
	"1200",
D 11
	CNULL,	/* <--- **** Welcome to Telenet PC Pursuit ***** */
E 11
I 11
	CNULL,
	CNULL,
	"P_ZERO",	/* Telenet insists on zero parity */
E 11
	"ABORT",
D 11
	"Good",	/* Abort of Good bye! */
	")", 	/* <--- Enter your 7-digit phone number (xxx-xxxx) */
	CNULL,	/* ---> 528-1234 */
	"call?", 	/* <--- Which city do you wish to call? */
	CNULL,	/* ---> CHICAGO */
	")", 	/* <--- Enter the phone number you wish to call (xxx-xxxx) */
	CNULL,	/* ---> 690-7171 */
	"R)?", 	/* <--- You are #1 in the queue. Do you want to wait, or Restart (Y/N/R)? */
	"Y",
	CNULL 	/* <--- .....Good Bye! */
E 11
I 11
	"BUSY",		/* Abort on Busy Signal */
	CNULL,
	"\\d\\d\\r\\d\\r",	/* Get telenet's attention */
	"TERMINAL=~3-\r-TERM~3-\r-TERM~5", 	/* Terminal type ? */
	"\\r",
	"@",		/* telenet's prompt */
	"D/DCWAS/21,telenetloginstring", /* overwritten later */
	"PASSWORD",
	CNULL,		/* telenet password */
	"CONNECTED",	/* We're now talking to a Hayes in the remote city */
	"ATZ",		/* Reset it */
	"OK",
	"ATDT6907171", /* overwritten */
	"CONNECT",	
	"\\d\\r",		/* We're in !*/
	CNULL,
E 11
};

D 11
static char PCP_brand[20];
E 11
I 11
static char PCP_brand[25];
I 15
int Dcf = -1;
char *Flds[MAXC/10];
char LineType[10];
extern int LocalOnly;
E 15
E 11

E 9
D 5
/*******
 *	conn(system)
 *	char *system;
E 5
I 5
/*
 *	place a telephone call to system and login, etc.
E 5
 *
D 5
 *	conn - place a telephone call to system and
 *	login, etc.
 *
E 5
 *	return codes:
 *		CF_SYSTEM: don't know system
 *		CF_TIME: wrong time to call
 *		CF_DIAL: call failed
 *		CF_NODEV: no devices available to place call
 *		CF_LOGIN: login/password dialog failed
 *
 *		>0  - file no.  -  connect ok
D 5
 *
E 5
 */
D 15

int Dcf = -1;
I 4
char *Flds[MAXC/10];
I 10
char LineType[10];
E 10
extern int LocalOnly;
E 4

E 15
conn(system)
char *system;
{
D 9
	int ret, nf;
D 4
	register int fn, fnd;
	char info[MAXC], *flds[MAXC/10];
E 4
I 4
	register int fn = 0;
E 9
I 9
	int nf;
E 9
D 5
	char info[MAXC];
E 5
I 5
	char info[MAXC], wkpre[NAMESIZE], file[NAMESIZE];
E 5
E 4
	register FILE *fsys;
	int fcode = 0;

	nf = 0;
D 4
	fnd = 0;
E 4

D 4

E 4
	fsys = fopen(SYSFILE, "r");
D 13
	ASSERT(fsys != NULL, "CAN'T OPEN", SYSFILE, 0);
E 13
I 13
	if (fsys == NULL) {
		syslog(LOG_ERR, "fopen(%s) failed: %m", SYSFILE);
		cleanup(FAIL);
	}
E 13

D 4
	DEBUG(4, "finds %s\n", "called");
	while((nf = finds(fsys, system, info, flds)) > 0) {
		DEBUG(4, "getto %s\n", "called");
		if ((fn = getto(flds)) > 0) {
			fnd = 1;
E 4
I 4
	DEBUG(4, "finds (%s) called\n", system);
I 7
keeplooking:
E 7
	while((nf = finds(fsys, system, info, Flds)) > 0) {
I 10
		strncpy(LineType, Flds[F_LINE], 10);
E 10
		if (LocalOnly) {
D 10
			if (strcmp("TCP", Flds[F_LINE])
				&& strcmp("DIR", Flds[F_LINE])
D 9
				&& strcmp("LOCAL", Flds[F_LINE]) )
					fn = CF_TIME;
E 9
I 9
				&& strcmp("LOCAL", Flds[F_LINE]) ) {
E 10
I 10
			if (strcmp("TCP", LineType)
				&& strcmp("DIR", LineType)
				&& strcmp("LOCAL", LineType) ) {
E 10
					fcode = CF_TIME;
					continue;
			}
E 9
		}
I 5
D 6
		sprintf(wkpre, "%c.%.7s", CMDPRE, Rmtname);
E 6
I 6
		sprintf(wkpre, "%c.%.*s", CMDPRE, SYSNSIZE, Rmtname);
E 6
		if (!onesys && MaxGrade != DefMaxGrade &&
D 9
			!iswrk(file, "chk", Spool, wkpre)) 
				fn = CF_TIME;
E 5
		if (fn != CF_TIME && (fn = getto(Flds)) > 0) {
E 4
			Dcf = fn;
			break;
E 9
I 9
			!iswrk(file, "chk", Spool, wkpre))  {
				fcode = CF_TIME;
				continue;
E 9
		}
D 9
		fcode = (fn == FAIL ? CF_DIAL : fn);
E 9
I 9
		/* For GTE's PC Pursuit */
D 10
		if (snccmp(Flds[F_LINE], PCP) == SAME) {
E 10
I 10
		if (snccmp(LineType, PCP) == SAME) {
E 10
			FILE *dfp;
			int status;
			static struct Devices dev;
I 11

E 11
			dfp = fopen(DEVFILE, "r");
D 13
			ASSERT(dfp != NULL, "Can't open", DEVFILE, 0);
E 13
I 13
			if (dfp == NULL) {
				syslog(LOG_ERR, "fopen(%s) failed: %m",
					DEVFILE);
				cleanup(FAIL);
			}
E 13
			while ((status=rddev(dfp, &dev)) != FAIL
				&& strcmp(PCP, dev.D_type) != SAME)
					;
			fclose(dfp);
			if (status == FAIL)
				continue;
			if (mlock(PCP) == FAIL) {
				fcode = CF_NODEV;
				logent("DEVICE", "NO");
				continue;
			}
			PCFlds[PCP_BAUD] = dev.D_class;
			PCFlds[PCP_PHONE] = dev.D_calldev;
D 11
			PCFlds[PCP_CALLBACK] = dev.D_arg[D_CHAT];
			PCFlds[PCP_CITY] = Flds[F_CLASS];
			PCFlds[PCP_RPHONE] = Flds[F_PHONE];
E 11
I 11
			sprintf(PCFlds[PCP_CITY], "c d/%s%s,%s",
				Flds[F_CLASS],
				index(Flds[F_CLASS], '/') == NULL ? "/12" : "",
				dev.D_arg[D_CHAT]);
			PCFlds[PCP_PASSWORD] = dev.D_line;
			strncpy(&PCFlds[PCP_RPHONE][4], Flds[F_PHONE], 7);
E 11
			strncpy(PCP_brand, dev.D_brand, sizeof(PCP_brand));
D 11
			if ((fcode = getto(PCFlds)) < 0)
E 11
I 11
			if ((fcode = getto(PCFlds)) < 0) {
				rmlock(PCP);
E 11
				continue;
I 11
			}
E 11
			Dcf = fcode;
			fcode = login(NPCFIELDS, PCFlds, Dcf);
D 11
			clsacu(); /* Hang up, they'll call back */
			if (fcode != SUCCESS) {
				fcode = CF_DIAL;
				continue;
			}
			Flds[F_CLASS] = dev.D_class;
			Flds[F_PHONE] = dev.D_line;
			
		} /* end PC Pursuit */
		if ((fcode = getto(Flds)) > 0) 
E 11
I 11
			if (fcode == SUCCESS)
				break;
			fcode = CF_DIAL;
			rmlock(PCP);
			/* end PC Pursuit */
		} else if ((fcode = getto(Flds)) > 0)  {
			Dcf = fcode;
E 11
			break;
I 11
		}
E 11
E 9
	}
D 7
	fclose(fsys);
E 7

D 7
	if (nf <= 0)
E 7
I 7
	if (nf <= 0) {
		fclose(fsys);
E 7
D 4
		return(fcode ? fcode : nf);
E 4
I 4
		return fcode ? fcode : nf;
I 7
	}
E 7
E 4

D 9
	DEBUG(4, "login %s\n", "called");
D 4
	ret = login(nf, flds, fn);
	if (ret < 0) {
E 4
I 4
	ret = login(nf, Flds, fn);
D 6
	if (ret == FAIL) {
E 6
I 6
	if (ret != SUCCESS) {
E 9
I 9
D 11
	Dcf = fcode;
E 11

D 10
	if (fcode >= 0 && snccmp(Flds[F_LINE], PCP) == SAME) {
E 10
I 10
D 11
	if (fcode >= 0 && snccmp(LineType, PCP) == SAME) {
E 10
		AbortOn = "Good";	/* .... Good Bye */
		fcode = expect("****~300", Dcf);
		if (fcode != SUCCESS) {
			DEBUG(4, "\nexpect timed out\n", CNULL);
			fcode = CF_DIAL;
		}
	}
E 11
	if (fcode >= 0) {
		DEBUG(4, "login %s\n", "called");
I 15
		setproctitle("login");
E 15
D 11
		fcode = login(nf, Flds, Dcf);
	}
E 11
I 11
		fcode = login(nf, Flds, Dcf); }
E 11
	if (fcode < 0) {
E 9
E 6
E 4
		clsacu();
D 4
		return(CF_LOGIN);
E 4
I 4
D 6
		return CF_LOGIN;
E 6
I 6
D 7
		if (ret == ABORT)
			return CF_DIAL;
		else
E 7
I 7
D 9
		if (ret == ABORT) {
E 9
I 9
		if (fcode == ABORT) {
E 9
			fcode = CF_DIAL;
			goto  keeplooking;
		} else {
			fclose(fsys);
E 7
			return CF_LOGIN;
I 7
		}
E 7
E 6
E 4
	}
D 7
	/* rti!trt:  avoid passing file to children */
E 7
I 7
	fclose(fsys);
E 7
D 9
	fioclex(fn);
D 4
	return(fn);
E 4
I 4
	return fn;
E 9
I 9
	fioclex(Dcf);
	return Dcf;
E 9
E 4
}

I 15
int nulldev();
int (*CU_end)() = nulldev;

E 15
D 7
/***
 *	getto(flds)		connect to remote machine
 *	char *flds[];
E 7
I 7
/*
 *	connect to remote machine
E 7
 *
 *	return codes:
 *		>0  -  file number - ok
 *		FAIL  -  failed
 */
D 15

I 14
int nulldev();

E 15
E 14
getto(flds)
register char *flds[];
{
	register struct condev *cd;
D 14
	int nulldev(), diropn();
E 14
I 14
	int diropn();
E 14
I 7
	char *line;
E 7

D 4
	DEBUG(4, "call: no. %s ", flds[F_PHONE]);
E 4
I 4
	DEBUG(4, "getto: call no. %s ", flds[F_PHONE]);
E 4
	DEBUG(4, "for sys %s\n", flds[F_NAME]);

I 7
	if (snccmp(flds[F_LINE], "LOCAL") == SAME)
		line = "ACU";
	else
		line = flds[F_LINE];
#ifdef DIALINOUT
	if (snccmp(line, "ACU") != SAME)
		reenable();
#endif DIALINOUT
E 7
	CU_end = nulldev;
D 9
	for (cd = condevs; cd->CU_meth != NULL; cd++) {
D 7
		if (snccmp(cd->CU_meth, flds[F_LINE]) == SAME) {
E 7
I 7
		if (snccmp(cd->CU_meth, line) == SAME) {
E 7
			DEBUG(4, "Using %s to call\n", cd->CU_meth);
D 4
			return((*(cd->CU_gen))(flds));
			}
E 4
I 4
			return (*(cd->CU_gen))(flds);
E 9
I 9
	if (snccmp(line, PCP) == SAME) {
		for(cd = condevs; cd->CU_meth != NULL; cd++) {
			if (snccmp(PCP_brand, cd->CU_brand) == SAME) {
				CU_end = cd->CU_clos;
				return diropn(flds);
			}
E 9
E 4
		}
I 9
		logent(PCP_brand, "UNSUPPORTED ACU TYPE");
	} else {
		for (cd = condevs; cd->CU_meth != NULL; cd++) {
			if (snccmp(cd->CU_meth, line) == SAME) {
				DEBUG(4, "Using %s to call\n", cd->CU_meth);
				return (*(cd->CU_gen))(flds);
			}
		}
		DEBUG(1, "Can't find %s, assuming DIR\n", flds[F_LINE]);
E 9
D 4
	logent(flds[F_LINE], "getto: Can't find, using DIR");
	return(diropn(flds));	/* search failed, so use direct */
E 4
	}
I 4
D 7
	DEBUG(1, "Can't find %s, assuming DIR", flds[F_LINE]);
E 7
I 7
D 9
	DEBUG(1, "Can't find %s, assuming DIR\n", flds[F_LINE]);
E 9
E 7
	return diropn(flds);	/* search failed, so use direct */
}
E 4

D 7
/***
 *	clsacu()	close call unit
E 7
I 7
/*
 *	close call unit
E 7
 *
 *	return codes:  none
 */
D 15

int (*CU_end)() = nulldev;
E 15
clsacu()
{
D 4
	(*(CU_end))(Dcf);
E 4
I 4
	/* make *sure* Dcf is no longer exclusive.
	 * Otherwise dual call-in/call-out modems could get stuck.
	 * Unfortunately, doing this here is not ideal, but it is the
	 * easiest place to put the call.
	 * Hopefully everyone honors the LCK protocol, of course
	 */
D 9
#ifndef	USG
E 9
I 9
#ifdef	TIOCNXCL
E 9
D 6
	ioctl(Dcf, TIOCNXCL, STBNULL);
E 6
I 6
	if (!IsTcpIp && Dcf >= 0 && ioctl(Dcf, TIOCNXCL, STBNULL) < 0)
		DEBUG(5, "clsacu ioctl %s\n", sys_errlist[errno]);
E 6
#endif
	if  (setjmp(Sjbuf))
		logent(Rmtname, "CLOSE TIMEOUT");
	else {
		signal(SIGALRM, alarmtr);
		alarm(20);
		(*(CU_end))(Dcf);
		alarm(0);
	}
E 4
	if (close(Dcf) == 0) {
		DEBUG(4, "fd %d NOT CLOSED by CU_clos\n", Dcf);
		logent("clsacu", "NOT CLOSED by CU_clos");
	}
	Dcf = -1;
	CU_end = nulldev;
}

D 7
/***
 *	exphone - expand phone number for given prefix and number
 *
 *	return code - none
E 7
I 7
/*
 *	expand phone number for given prefix and number
E 7
 */
D 15

E 15
exphone(in, out)
register char *in, *out;
{
	FILE *fn;
	char pre[MAXPH], npart[MAXPH], tpre[MAXPH], p[MAXPH];
	char buf[BUFSIZ];
	register char *s1;

D 4
	if (!isalpha(*in)) {
E 4
I 4
	if (!isascii(*in) || !isalpha(*in)) {
E 4
		strcpy(out, in);
		return;
	}

	s1=pre;
D 4
	while (isalpha(*in))
E 4
I 4
	while (isascii(*in) && isalpha(*in))
E 4
		*s1++ = *in++;
	*s1 = '\0';
	s1 = npart;
	while (*in != '\0')
		*s1++ = *in++;
	*s1 = '\0';

	tpre[0] = '\0';
	if ((fn = fopen(DIALFILE, "r")) == NULL)
		DEBUG(2, "CAN'T OPEN %s\n", DIALFILE);
	else {
		while (cfgets(buf, BUFSIZ, fn)) {
D 4
			sscanf(buf, "%s%s", p, tpre);
E 4
I 4
			if (sscanf(buf, "%s%s", p, tpre) != 2)
				continue;
E 4
			if (strcmp(p, pre) == SAME)
				goto found;
			tpre[0] = '\0';
		}
		DEBUG(2, "CAN'T FIND dialcodes prefix '%s'\n", pre);
	found:;
		fclose(fn);
	}

	strcpy(out, tpre);
	strcat(out, npart);
D 4
	return;
E 4
}

D 5
/***
 *	rddev - read and decode a line from device file
E 5
I 5
/*
 *	read and decode a line from device file
E 5
 *
 *	return code - FAIL at end-of file; 0 otherwise
 */
D 15

E 15
rddev(fp, dev)
register struct Devices *dev;
FILE *fp;
{
D 4
	char *fdig();
	char buf[BUFSIZ];
	int na;
E 4
I 4
	register int na;
E 4

D 4
	if (!cfgets(buf, BUFSIZ, fp))
		return(FAIL);

	na = sscanf(buf, "%s%s%s%s%s", dev->D_type, dev->D_line,
	  dev->D_calldev, dev->D_class, dev->D_brand);
	ASSERT(na >= 4, "BAD DEVICE ENTRY", buf, 0);
	if (na != 5) dev->D_brand[0] = '\0';
E 4
I 4
	if (!cfgets(dev->D_argbfr, sizeof(dev->D_argbfr), fp))
		return FAIL;
	na = getargs(dev->D_argbfr, dev->D_arg, 20);
D 13
	ASSERT(na >= 4, "BAD DEVICE ENTRY", dev->D_argbfr, 0);
E 13
I 13
	if (na < 4) {
		syslog(LOG_ERR, "%s: invalid device entry", dev->D_argbfr);
		cleanup(FAIL);
	}
E 13
	if (na == 4) {
		dev->D_brand = "";
		na++;
	}
E 4
	dev->D_speed = atoi(fdig(dev->D_class));
D 4
	return(0);
E 4
I 4
	dev->D_numargs = na;
	return 0;
E 4
}

D 5
/***
 *	finds(fsys, sysnam, info, flds)	set system attribute vector
E 5
I 5
/*
 *	set system attribute vector
E 5
 *
 *	return codes:
 *		>0  -  number of arguments in vector - succeeded
 *		CF_SYSTEM  -  system name not found
 *		CF_TIME  -  wrong time to call
 */
D 15

E 15
finds(fsys, sysnam, info, flds)
char *sysnam, info[], *flds[];
FILE *fsys;
{
D 5
	char sysn[8];
E 5
	int na;
	int fcode = 0;

	/* format of fields
	 *	0 name;
	 *	1 time
	 *	2 acu/hardwired
	 *	3 speed
	 *	etc
	 */
	while (cfgets(info, MAXC, fsys) != NULL) {
D 4
		na = getargs(info, flds);
E 4
I 4
		na = getargs(info, flds, MAXC/10);
E 4
D 5
		sprintf(sysn, "%.7s", flds[F_NAME]);
		if (strcmp(sysnam, sysn) != SAME)
E 5
I 5
D 6
		if (strncmp(sysnam, flds[F_NAME], 7) != SAME)
E 6
I 6
		if (strncmp(sysnam, flds[F_NAME], MAXBASENAME) != SAME)
E 6
E 5
			continue;
D 5
		if (ifdate(flds[F_TIME]))
E 5
I 5
		if (ifdate(flds[F_TIME]) != FAIL)
E 5
			/*  found a good entry  */
D 4
			return(na);
E 4
I 4
			return na;
E 4
		DEBUG(2, "Wrong time ('%s') to call\n", flds[F_TIME]);
		fcode = CF_TIME;
	}
D 4
	return(fcode ? fcode : CF_SYSTEM);
E 4
I 4
	return fcode ? fcode : CF_SYSTEM;
E 4
}

D 5
/***
 *	login(nf, flds, dcr)		do login conversation
 *	char *flds[];
 *	int nf;
E 5
I 5
/*
 *	do login conversation
E 5
 *
D 6
 *	return codes:  0  |  FAIL
E 6
I 6
 *	return codes:  SUCCESS  |  FAIL
E 6
 */
D 15

E 15
login(nf, flds, fn)
register char *flds[];
int nf, fn;
{
	register char *want, *altern;
D 6
	extern char *index();
E 6
	int k, ok;

D 4
	ASSERT(nf > 4, "TOO FEW LOG FIELDS", "", nf);
E 4
I 4
D 13
	ASSERT(nf > 4, "TOO FEW LOG FIELDS", CNULL, nf);
E 13
I 13
	if (nf < 4) {
		syslog(LOG_ERR, "Too few log fields: %d", nf);
		cleanup(FAIL);
	}
E 13
	if (setjmp(Cjbuf))
		return FAIL;
	AbortOn = NULL;
E 4
	for (k = F_LOGIN; k < nf; k += 2) {
		want = flds[k];
I 11
		if (want == NULL)
			want = "";
E 11
		ok = FAIL;
D 4
		while (ok != 0) {
E 4
I 4
		while (ok != SUCCESS) {
E 4
			altern = index(want, '-');
			if (altern != NULL)
				*altern++ = '\0';
D 4
			DEBUG(4, "wanted %s ", want);
			ok = expect(want, fn);
			DEBUG(4, "got %s\n", ok ? "?" : "that");
			if (ok == 0)
				break;
			if (altern == NULL) {
				logent("LOGIN", "FAILED");
				/* close *not* needed here. rti!trt */
				return(FAIL);
E 4
I 4
			if (strcmp(want, "ABORT") == 0) {
				AbortOn = flds[k+1];
				DEBUG(4, "ABORT ON: %s\n", AbortOn);
				goto nextfield;
E 4
			}
D 4
			want = index(altern, '-');
			if (want != NULL)
				*want++ = '\0';
			sendthem(altern, fn);
E 4
I 4
D 9
			DEBUG(4, "wanted: %s\n", want);
E 9
I 9
			DEBUG(4, "wanted \"%s\"\n", want);
E 9
			ok = expect(want, fn);
			DEBUG(4, "got: %s\n", ok ? "?" : "that");
			if (ok == FAIL) {
				if (altern == NULL) {
					logent("LOGIN", _FAILED);
					return FAIL;
				}
				want = index(altern, '-');
				if (want != NULL)
					*want++ = '\0';
				sendthem(altern, fn);
			} else
				if (ok == ABORT) {
D 11
					logent("LOGIN ABORTED", _FAILED);
E 11
I 11
					char sbuf[MAXFULLNAME];
					sprintf(sbuf, "LOGIN ABORTED on \"%s\"",						AbortOn);
					logent(sbuf, _FAILED);
E 11
D 6
					return FAIL;
E 6
I 6
					return ABORT;
E 6
				}
E 4
		}
D 4
		sleep(2);
E 4
I 4
		sleep(1);
E 4
		if (k+1 < nf)
			sendthem(flds[k+1], fn);
I 4
nextfield: ;
E 4
	}
D 4
	return(0);
E 4
I 4
	return SUCCESS;
E 4
}


D 4
/* rti!trt: conditional table generation to support odd speeds */
/* Suggested in n44a.139 by n44!dan (Dan Ts'o) */
E 4
I 4
/* conditional table generation to support odd speeds */
E 4
struct sg_spds {int sp_val, sp_name;} spds[] = {
#ifdef B50
	{  50,	 B50},
#endif
#ifdef B75
	{  75,	 B75},
#endif
#ifdef B110
	{ 110,	B110},
#endif
#ifdef B150
	{ 150,	B150},
#endif
#ifdef B200
	{ 200,	B200},
#endif
#ifdef B300
	{ 300,  B300},
#endif
#ifdef B600
	{600,	B600},
#endif
#ifdef B1200
	{1200, B1200},
#endif
#ifdef B1800
	{1800, B1800},
#endif
#ifdef B2000
	{2000, B2000},
#endif
#ifdef B2400
	{2400, B2400},
#endif
#ifdef B3600
	{3600, B3600},
#endif
#ifdef B4800
	{4800, B4800},
#endif
#ifdef B7200
	{7200, B7200},
#endif
#ifdef B9600
	{9600, B9600},
#endif
#ifdef B19200
D 4
	{19200,B19200},
E 4
I 4
	{19200, B19200},
E 4
#endif
I 4
#ifdef EXTA
	{19200, EXTA},
#endif
E 4
	{0, 0}
};

D 5
/***
 *	fixline(tty, spwant)	set speed/echo/mode...
 *	int tty, spwant;
E 5
I 5
/*
 *	set speed/echo/mode...
E 5
 *
 *	return codes:  none
 */
D 15

E 15
fixline(tty, spwant)
int tty, spwant;
{
D 4
#ifdef	SYSIII
E 4
I 4
#ifdef	USG
E 4
	struct termio ttbuf;
D 4
#endif
#ifndef	SYSIII
E 4
I 4
#else	!USG
E 4
	struct sgttyb ttbuf;
D 4
#endif
E 4
I 4
#endif !USG
E 4
	register struct sg_spds *ps;
	int speed = -1;
D 6
	int ret;
E 6

	for (ps = spds; ps->sp_val; ps++)
		if (ps->sp_val == spwant)
			speed = ps->sp_name;
D 4
	ASSERT(speed >= 0, "BAD SPEED", "", speed);
#ifdef	SYSIII
E 4
I 4
D 13
	ASSERT(speed >= 0, "BAD SPEED", CNULL, speed);
E 13
I 13
	if (speed < 0) {
		syslog(LOG_ERR, "unrecognized speed: %d", speed);
		cleanup(FAIL);
	}
E 13
#ifdef	USG
E 4
D 6
	ioctl(tty, TCGETA, &ttbuf);
E 6
I 6
	if (ioctl(tty, TCGETA, &ttbuf) < 0)
		return FAIL;
E 6
	/* ttbuf.sg_flags = (ANYP|RAW);
	ttbuf.sg_ispeed = ttbuf.sg_ospeed = speed; */
	ttbuf.c_iflag = (ushort)0;
	ttbuf.c_oflag = (ushort)0;
	ttbuf.c_cflag = (speed|CS8|HUPCL|CREAD);
	ttbuf.c_lflag = (ushort)0;
	ttbuf.c_cc[VMIN] = 6;
	ttbuf.c_cc[VTIME] = 1;
D 6
	ret = ioctl(tty, TCSETA, &ttbuf);
E 6
I 6
	if (ioctl(tty, TCSETA, &ttbuf) < 0)
		return FAIL;
E 6
D 4
#endif
#ifndef	SYSIII
E 4
I 4
#else	!USG
E 4
D 6
	ioctl(tty, TIOCGETP, &ttbuf);
E 6
I 6
	if (ioctl(tty, TIOCGETP, &ttbuf) < 0)
		return FAIL;
E 6
	ttbuf.sg_flags = (ANYP|RAW);
	ttbuf.sg_ispeed = ttbuf.sg_ospeed = speed;
D 6
	ret = ioctl(tty, TIOCSETP, &ttbuf);
E 6
I 6
	if (ioctl(tty, TIOCSETP, &ttbuf) < 0)
		return FAIL;
E 6
#endif
D 4
	ASSERT(ret >= 0, "RETURN FROM STTY", "", ret);
#ifndef	SYSIII
E 4
I 4
D 6
	ASSERT(ret >= 0, "RETURN FROM STTY", CNULL, ret);
E 6
#ifndef	USG
E 4
D 6
	ioctl(tty, TIOCHPCL, STBNULL);
	ioctl(tty, TIOCEXCL, STBNULL);
E 6
I 6
	if (ioctl(tty, TIOCHPCL, STBNULL) < 0)
		return FAIL;
	if (ioctl(tty, TIOCEXCL, STBNULL) < 0)
		return FAIL;
E 6
#endif
I 4
	linebaudrate = spwant;
E 4
D 6
	return;
E 6
I 6
	return SUCCESS;
E 6
}

I 8
D 9
/***
E 9
I 9
D 10
/*
E 9
 *	getbaud(tty)	set linebaudrate variable
 *
 *	return codes:  none
 */

getbaud(tty)
int tty;
{
#ifdef	USG
	struct termio ttbuf;
#else
	struct sgttyb ttbuf;
#endif
	register struct sg_spds *ps;
	register int name;

	if (IsTcpIp)
		return;
#ifdef	USG
	ioctl(tty, TCGETA, &ttbuf);
	name = ttbuf.c_cflag & CBAUD;
#else
	ioctl(tty, TIOCGETP, &ttbuf);
	name = ttbuf.sg_ispeed;
#endif
	for (ps = spds; ps->sp_val; ps++)
		if (ps->sp_name == name) {
			linebaudrate = ps->sp_val;
			break;
		}
}

E 10
E 8
I 4
#define MR 100
E 4

D 4
/* Bill Shannon recommends MR 2000, but that takes too much space on PDPs */
/* Actually, the 'expect' algorithm should be rewritten. */
#define MR 1000


E 4
D 5
/***
 *	expect(str, fn)	look for expected string
 *	char *str;
E 5
I 5
/*
 *	look for expected string
E 5
 *
 *	return codes:
 *		0  -  found
 *		FAIL  -  lost line or too many characters read
 *		some character  -  timed out
 */
D 15

E 15
expect(str, fn)
register char *str;
int fn;
{
D 3
	static char rdvec[MR];
E 3
I 3
	char rdvec[MR];
E 3
D 4
	register char *rp = rdvec;
	int kr;
E 4
I 4
	register char *rp = rdvec, *strptr;
	int kr, cnt_char;
E 4
	char nextch;
I 7
	int timo = MAXMSGTIME;
E 7

D 4
	if (strcmp(str, "\"\"") == SAME)
		return(0);
	*rp = 0;
	if (setjmp(Sjbuf)) {
		return(FAIL);
E 4
I 4
	if (*str == '\0' || strcmp(str, "\"\"") == SAME)
		return SUCCESS;
	/* Cleanup str, convert \0xx strings to one char  */
	for (strptr = str; *strptr; strptr++) {
		if (*strptr == '\\')
			switch(*++strptr) {
			case 's':
				DEBUG(5, "BLANK\n", CNULL);
I 15
				strptr--;
E 15
				*strptr = ' ';
I 15
				strcpy(&strptr[1], &strptr[4]);
E 15
				break;
			default:
				strptr--;  /* back up to backslash */
				sscanf(strptr + 1,"%o", &cnt_char);
				DEBUG(6, "BACKSLASHED %02xH\n", cnt_char);
				*strptr = (char) (cnt_char);
				strcpy(&strptr[1], &strptr[4]);
			}
E 4
	}
I 4

D 7
	*rp = 0;
E 7
I 7
	strptr = index(str, '~');
	if (strptr != NULL) {
		*strptr++ = '\0';
		timo = atoi(strptr);
		if (timo <= 0)
			timo = MAXMSGTIME;
	}

E 7
	if (setjmp(Sjbuf))
		return FAIL;
E 4
	signal(SIGALRM, alarmtr);
D 4
/* change MAXCHARTIME to MAXMSGTIME, outside while loop -- brl-bmd!dpk */
E 4
D 7
	alarm(MAXMSGTIME);
E 7
I 7
	alarm(timo);
	*rp = 0;
E 7
	while (notin(str, rdvec)) {
I 9
		int c;
E 9
I 4
		if(AbortOn != NULL && !notin(AbortOn, rdvec)) {
			DEBUG(1, "Call aborted on '%s'\n", AbortOn);
			alarm(0);
			return ABORT;
		}
E 4
		kr = read(fn, &nextch, 1);
		if (kr <= 0) {
			alarm(0);
			DEBUG(4, "lost line kr - %d\n, ", kr);
			logent("LOGIN", "LOST LINE");
D 4
			return(FAIL);
E 4
I 4
			return FAIL;
E 4
		}
D 9
		{
		int c;
E 9
		c = nextch & 0177;
D 9
		DEBUG(4, c >= 040 ? "%c" : "\\%03o", c);
I 4
		if (c == '\n')
			DEBUG(4,"\n", CNULL);
E 4
		}
		if ((*rp = nextch & 0177) != '\0')
			rp++;
E 9
I 9
		if (c == '\0')
			continue;
		DEBUG(4, (isprint(c) || isspace(c)) ? "%c" : "\\%03o", c);
		*rp++ = c;
E 9
D 4
/* Check rdvec before null termination -- cmcl2!salkind */
E 4
		if (rp >= rdvec + MR) {
D 4
			alarm(0);
			return(FAIL);
E 4
I 4
			register char *p;
			for (p = rdvec+MR/2; p < rp; p++)
				*(p-MR/2) = *p;
			rp -= MR/2;
E 4
		}
		*rp = '\0';
	}
	alarm(0);
D 4
	return(0);
E 4
I 4
	return SUCCESS;
E 4
}


/*
 * Determine next file descriptor that would be allocated.
 * This permits later closing of a file whose open was interrupted.
 * It is a UNIX kernel problem, but it has to be handled.
 * unc!smb (Steve Bellovin) probably first discovered it.
 */
getnextfd()
{
	close(next_fd = open("/", 0));
}

D 4
/***
 *	sendthem(str, fn)	send line of login sequence
 *	char *str;
E 4
I 4
/*
 *	send line of login sequence
E 4
 *
 *	return codes:  none
 */
D 4

E 4
sendthem(str, fn)
register char *str;
int fn;
{
	register char *strptr;
	int i, n, cr = 1;
I 4
	register char c;
E 4
	static int p_init = 0;

D 4
	/* Note: debugging authorized only for privileged users */
E 4
D 9
	DEBUG(5, "send %s\n", str);
E 9
I 9
	DEBUG(5, "send \"%s\"\n", str);
E 9

	if (!p_init) {
		p_init++;
D 13
		bld_partab(P_EVEN);
E 13
I 13
		bld_partab(P_ZERO);
E 13
	}

	if (prefix("BREAK", str)) {
		sscanf(&str[5], "%1d", &i);
		if (i <= 0 || i > 10)
			i = 3;
		/* send break */
		genbrk(fn, i);
		return;
	}

	if (prefix("PAUSE", str)) {
		sscanf(&str[5], "%1d", &i);
		if (i <= 0 || i > 10)
			i = 3;
		/* pause for a while */
		sleep((unsigned)i);
		return;
	}

	if (strcmp(str, "EOT") == SAME) {
		p_chwrite(fn, '\04');
		return;
	}

D 4
	/* LF, CR, and "" courtesy unc!smb */
E 4
	/* Send a '\n' */
D 9
	if (strcmp(str, "LF") == SAME)
		str = "\\n\\c";
E 9
I 9
	if (strcmp(str, "LF") == SAME) {
		p_chwrite(fn, '\n');
		return;
	}
E 9

	/* Send a '\r' */
D 9
	if (strcmp(str, "CR") == SAME)
		str = "\\r\\c";
E 9
I 9
	if (strcmp(str, "CR") == SAME) {
		p_chwrite(fn, '\r');
		return;
	}
E 9

	/* Set parity as needed */
	if (strcmp(str, "P_ZERO") == SAME) {
		bld_partab(P_ZERO);
		return;
	}
	if (strcmp(str, "P_ONE") == SAME) {
		bld_partab(P_ONE);
		return;
	}
	if (strcmp(str, "P_EVEN") == SAME) {
		bld_partab(P_EVEN);
		return;
	}
	if (strcmp(str, "P_ODD") == SAME) {
		bld_partab(P_ODD);
		return;
	}

	/* If "", just send '\r' */
D 4
	if (strcmp(str, "\"\"") != SAME)
	for (strptr = str; *strptr; strptr++) {
		if (*strptr == '\\') switch(*++strptr) {
		case 's':
			DEBUG(5, "BLANK\n", "");
			*strptr = ' ';
			break;
		case 'd':
			DEBUG(5, "DELAY\n", "");
			sleep(1);
			continue;
		case 'r':
			DEBUG(5, "RETURN\n", "");
			*strptr = '\r';
			break;
		case 'b':
			if (isdigit(*(strptr+1))) {
				i = (*++strptr - '0');
				if (i <= 0 || i > 10)
E 4
I 4
	if (strcmp(str, "\"\"") == SAME) {
		p_chwrite(fn, '\r');
		return;
	}

D 9
	for (strptr = str; c = *strptr++;) {
E 9
I 9
	strptr = str;
	while ((c = *strptr++) != '\0') {
E 9
		if (c == '\\') {
			switch(*strptr++) {
I 9
			case '\0':
				DEBUG(5, "TRAILING BACKSLASH IGNORED\n", CNULL);
				--strptr;
				continue;
E 9
			case 's':
				DEBUG(5, "BLANK\n", CNULL);
D 9
				p_chwrite(fn, ' ');
E 9
I 9
				c = ' ';
E 9
				break;
			case 'd':
				DEBUG(5, "DELAY\n", CNULL);
				sleep(1);
				continue;
I 9
			case 'n':
				DEBUG(5, "NEW LINE\n", CNULL);
				c = '\n';
				break;
E 9
			case 'r':
				DEBUG(5, "RETURN\n", CNULL);
D 9
				p_chwrite(fn, '\r');
E 9
I 9
				c = '\r';
E 9
				break;
			case 'b':
				if (isdigit(*strptr)) {
					i = (*strptr++ - '0');
					if (i <= 0 || i > 10)
						i = 3;
				} else
E 4
					i = 3;
D 4
			} else
				i = 3;
			/* send break */
			genbrk(fn, i);
			continue;
		case 'c':
			if (*(strptr+1) == '\0') {
			DEBUG(5, "NO CR\n", "");
				cr = 0;
E 4
I 4
				/* send break */
				genbrk(fn, i);
				if (*strptr == '\0')
					cr = 0;
E 4
				continue;
D 4
			}
			DEBUG(5, "NO CR - MIDDLE IGNORED\n", "");
			continue;
		default:
			if (isdigit(strptr[1])) {
				i = 0;
				n = 0;
				while (isdigit(strptr[1]) && ++n <= 3)
					i = i*8 + (*++strptr - '0');
				p_chwrite(fn, i);
E 4
I 4
			case 'c':
				if (*strptr == '\0') {
					DEBUG(5, "NO CR\n", CNULL);
					cr = 0;
D 9
					continue;
				}
				DEBUG(5, "NO CR - MIDDLE IGNORED\n", CNULL);
E 9
I 9
				} else
					DEBUG(5, "NO CR - IGNORED NOT EOL\n", CNULL);
E 9
E 4
				continue;
I 9
#define isoctal(x)	((x >= '0') && (x <= '7'))
E 9
I 4
			default:
D 9
				if (isdigit(*strptr)) {
E 9
I 9
				if (isoctal(strptr[-1])) {
E 9
					i = 0;
					n = 0;
D 9
					while (isdigit(*strptr) && ++n <= 3)
						i = i*8 + (*strptr++ - '0');
E 9
I 9
					--strptr;
					while (isoctal(*strptr) && ++n <= 3)
						i = i * 8 + (*strptr++ - '0');
					DEBUG(5, "\\%o\n", i);
E 9
					p_chwrite(fn, (char)i);
					continue;
				}
D 9
				DEBUG(5, "BACKSLASH\n", CNULL);
				--strptr;
E 9
E 4
			}
D 4
			DEBUG(5, "BACKSLASH\n", "");
			strptr--;
		}
		p_chwrite(fn, *strptr);
E 4
I 4
D 9
		} else
			p_chwrite(fn, c);
E 9
I 9
		}
		p_chwrite(fn, c);
E 9
E 4
	}

D 4
	/* '\n' changed to '\r'--a better default. rti!trt */
E 4
	if (cr)
		p_chwrite(fn, '\r');
	return;
}

p_chwrite(fd, c)
int fd;
D 4
int c;
E 4
I 4
char c;
E 4
{
D 4
	char t[2];

	t[0] = par_tab[c&0177];
	t[1] = '\0';
	ASSERT(write(fd, t, 1) == 1, "BAD WRITE", "", t[0]);
E 4
I 4
	c = par_tab[c&0177];
	if (write(fd, &c, 1) != 1) {
		logent(sys_errlist[errno], "BAD WRITE");
		longjmp(Cjbuf, 2);
	}
E 4
}

/*
 * generate parity table for use by p_chwrite.
 */
bld_partab(type)
int type;
{
	register int i, j, n;

	for (i = 0; i < sizeof(par_tab); i++) {
		n = 0;
		for (j = i&(sizeof(par_tab)-1); j; j = (j-1)&j)
			n++;
		par_tab[i] = i;
		if (type == P_ONE
		 || (type == P_EVEN && (n&01) != 0)
		 || (type == P_ODD && (n&01) == 0))
			par_tab[i] |= sizeof(par_tab);
	}
}

D 9
#define BSPEED B150

E 9
D 5
/***
 *	genbrk		send a break
E 5
I 5
/*
D 9
 *	send a break
E 5
D 6
 *
 *	return codes;  none
E 6
 */
D 6

E 6
genbrk(fn, bnulls)
register int fn, bnulls;
{
D 6
	register int ret;
E 6
D 4
#ifdef	SYSIII
E 4
I 4
#ifdef	USG
E 4
D 6
	ret = ioctl(fn, TCSBRK, STBNULL);
	DEBUG(5, "break ioctl ret %d\n", ret);
E 6
I 6
	if (ioctl(fn, TCSBRK, STBNULL) < 0)
		DEBUG(5, "break ioctl %s\n", sys_errlist[errno]);
E 6
D 4
#endif
#ifndef	SYSIII
E 4
I 4
#else	!USG
E 4
D 6
#ifdef	TIOCSBRK
	ret = ioctl(fn, TIOCSBRK, STBNULL);
	DEBUG(5, "break ioctl ret %d\n", ret);
#ifdef	TIOCCBRK
D 4
	ret = write(fn, "\0\0\0\0\0\0\0\0\0\0\0\0", bnulls);
	ASSERT(ret > 0, "BAD WRITE genbrk", "", ret);
E 4
	sleep(1);
	ret = ioctl(fn, TIOCCBRK, STBNULL);
	DEBUG(5, "break ioctl ret %d\n", ret);
D 4
#endif
	DEBUG(4, "ioctl 1 second break\n", STBNULL);
#else
E 4
I 4
#endif TIOCCBRK
	DEBUG(4, "ioctl %d second break\n", bnulls );
#else !TIOCSBRK
E 6
E 4
	struct sgttyb ttbuf;
	register int sospeed;
I 6
# ifdef	TIOCSBRK
	if (ioctl(fn, TIOCSBRK, STBNULL) < 0)
		DEBUG(5, "break ioctl %s\n", sys_errlist[errno]);
# ifdef	TIOCCBRK
	sleep(1);
	if (ioctl(fn, TIOCCBRK, STBNULL) < 0)
		DEBUG(5, "break ioctl %s\n", sys_errlist[errno]);
# endif TIOCCBRK
	DEBUG(4, "ioctl %d second break\n", bnulls );
# else !TIOCSBRK
E 6

D 6
	ret = ioctl(fn, TIOCGETP, &ttbuf);
E 6
I 6
	if (ioctl(fn, TIOCGETP, &ttbuf) < 0)
		DEBUG(5, "break ioctl %s\n", sys_errlist[errno]);
E 6
	sospeed = ttbuf.sg_ospeed;
	ttbuf.sg_ospeed = BSPEED;
D 6
	ret = ioctl(fn, TIOCSETP, &ttbuf);
	ret = write(fn, "\0\0\0\0\0\0\0\0\0\0\0\0", bnulls);
D 4
	ASSERT(ret > 0, "BAD WRITE genbrk", "", ret);
E 4
I 4
	if (ret != bnulls) {
E 6
I 6
	if (ioctl(fn, TIOCSETP, &ttbuf) < 0)
		DEBUG(5, "break ioctl %s\n", sys_errlist[errno]);
	if (write(fn, "\0\0\0\0\0\0\0\0\0\0\0\0", bnulls) != bnulls) {
E 6
badbreak:
		logent(sys_errlist[errno], "BAD WRITE genbrk");
		alarm(0);
		longjmp(Sjbuf, 3);
	}
E 4
	ttbuf.sg_ospeed = sospeed;
D 6
	ret = ioctl(fn, TIOCSETP, &ttbuf);
	ret = write(fn, "@", 1);
D 4
	ASSERT(ret > 0, "BAD WRITE genbrk", "", ret);
E 4
I 4
	if (ret != 1)
E 6
I 6
	if (ioctl(fn, TIOCSETP, &ttbuf) < 0)
		DEBUG(5, "break ioctl %s\n", sys_errlist[errno]);
	if (write(fn, "@", 1) != 1)
E 6
		goto badbreak;
E 4
	DEBUG(4, "sent BREAK nulls - %d\n", bnulls);
D 4
#endif
#endif
E 4
I 4
#endif !TIOCSBRK
#endif !USG
E 4
}

D 4

E 4
D 5
/***
 *	notin(sh, lg)	check for occurrence of substring "sh"
 *	char *sh, *lg;
E 5
I 5
/*
E 9
 *	check for occurrence of substring "sh"
E 5
 *
 *	return codes:
 *		0  -  found the string
 *		1  -  not in the string
 */
D 4

E 4
notin(sh, lg)
register char *sh, *lg;
{
	while (*lg != '\0') {
D 4
		/* Dave Martingale: permit wild cards in 'expect' */
E 4
		if (wprefix(sh, lg))
D 5
			return(0);
E 5
I 5
			return 0;
E 5
		else
			lg++;
	}
D 5
	return(1);
E 5
I 5
	return 1;
E 5
}

D 4

E 4
D 5
/*******
 *	ifdate(s)
 *	char *s;
 *
 *	ittvax!swatt
E 5
I 5
/*
E 5
D 6
 *	Allow multiple date specifications separated by '|'.
E 6
I 6
 *	Allow multiple date specifications separated by ','.
E 6
D 5
 *	Calls ifadate, formerly "ifdate".
 *
 *	return codes:
 *		see ifadate
E 5
 */
D 5

ifdate(s)
char *s;
E 5
I 5
ifdate(p)
register char *p;
E 5
{
I 6
D 9
	register char *np, c;
E 9
I 9
	register char *np;
E 9
E 6
D 5
	register char *p;
	register int ret;
E 5
I 5
	register int ret, g;
I 6
	int rtime, i;
E 6
E 5

I 6
	/*  pick up retry time for failures  */
	/*  global variable Retrytime is set here  */
	if ((np = index(p, ';')) == NULL) {
		Retrytime = RETRYTIME;
	} else {
		i = sscanf(np+1, "%d", &rtime);
		if (i < 1 || rtime < 0)
			rtime = 5;
		Retrytime  = rtime * 60;
	}

E 6
D 5
	for (p = s; p && (*p == '|' ? *++p : *p); p = index(p, '|'))
		if (ret = ifadate(p))
D 4
			return(ret);
	return(0);
E 4
I 4
			return ret;
	return 0;
E 5
I 5
	ret = FAIL;
	MaxGrade = '\0';
	do {
I 6
		np = strpbrk(p, ",|");	/* prefer , but allow | for compat */
		if (np)
			*np = '\0';
E 6
		g = ifadate(p);
		DEBUG(11,"ifadate returns %o\n", g);
		if (g != FAIL) {
			ret = SUCCESS;
			if (g > MaxGrade)
				MaxGrade = g;
		}
D 6
		p = index(p, '|');
	} while (p++ && *p);
E 6
I 6
		if (np)
			*np = ',';
		p = np + 1;
	} while (np);
	if (MaxGrade == '\0')
		MaxGrade = DefMaxGrade;
E 6
	return ret;
E 5
E 4
}

D 4

E 4
D 5
/*******
 *	ifadate(s)
 *	char *s;
 *
 *	ifadate  -  this routine will check a string (s)
E 5
I 5
/*
 *	this routine will check a string (string)
E 5
 *	like "MoTu0800-1730" to see if the present
 *	time is within the given limits.
 *	SIDE EFFECT - Retrytime is set
 *
D 5
 *	String alternatives:
 *		Wk - Mo thru Fr
 *		zero or one time means all day
 *		Any - any day
 *
E 5
 *	return codes:
 *		0  -  not within limits
 *		1  -  within limits
 */

D 5
ifadate(s)
char *s;
E 5
I 5
ifadate(string)
char *string;
E 5
{
	static char *days[]={
		"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa", 0
	};
	time_t clock;
I 5
	register char *s = string;
E 5
D 6
	int rtime;
E 6
D 4
	int i, tl, th, tn, flag, dayok=0;
E 4
I 4
	int i, tl, th, tn, dayok=0;
E 4
	struct tm *localtime();
	struct tm *tp;
D 5
	char *index();
	char *p;
E 5
I 5
	char *p, MGrade;
E 5

D 6
	/*  pick up retry time for failures  */
	/*  global variable Retrytime is set here  */
	if ((p = index(s, ',')) == NULL) {
		Retrytime = RETRYTIME;
D 4
	}
	else {
E 4
I 4
	} else {
E 4
		i = sscanf(p+1, "%d", &rtime);
D 4
		if (i < 1 || rtime < 5)
E 4
I 4
		if (i < 1 || rtime < 0)
E 4
			rtime = 5;
		Retrytime  = rtime * 60;
	}

I 5
	if ((p = index(s, '@')) == NULL)
E 6
I 6
	if ((p = index(s, '/')) == NULL)
E 6
		MGrade = DefMaxGrade;
	else
		MGrade = p[1];

E 5
	time(&clock);
	tp = localtime(&clock);
D 4
	while (isalpha(*s)) {
E 4
I 4
	while (isascii(*s) && isalpha(*s)) {
E 4
		for (i = 0; days[i]; i++) {
			if (prefix(days[i], s))
				if (tp->tm_wday == i)
					dayok = 1;
		}

		if (prefix("Wk", s))
			if (tp->tm_wday >= 1 && tp->tm_wday <= 5)
				dayok = 1;
		if (prefix("Any", s))
			dayok = 1;
I 4
		if (prefix("Evening", s)) {
			/* Sat or Sun */
			if (tp->tm_wday == 6 || tp->tm_wday == 0
				|| tp->tm_hour >= 17 || tp->tm_hour < 8)
					dayok = 1;
		}
		if (prefix("Night", s)) {
			if (tp->tm_wday == 6  /* Sat */
D 5
				|| tp->tm_hour > 23 || tp->tm_hour < 8)
E 5
I 5
				|| tp->tm_hour >= 23 || tp->tm_hour < 8
					/* Sunday before 5pm */
				|| (tp->tm_wday == 0 && tp->tm_hour < 17))
E 5
					dayok = 1;
		}
I 9
		if (prefix("NonPeak", s)) { /* For Tymnet and PC Pursuit */
			/* Sat or Sun */
			if (tp->tm_wday == 6 || tp->tm_wday == 0
				|| tp->tm_hour >= 18 || tp->tm_hour < 7)
					dayok = 1;
		}
E 9
E 4
		s++;
	}

D 5
	if (dayok == 0)
		return(0);
E 5
I 5
	if (dayok == 0 && s != string)
		return FAIL;
E 5
	i = sscanf(s, "%d-%d", &tl, &th);
D 4
	tn = tp->tm_hour * 100 + tp->tm_min;
E 4
D 5
	if (i < 2)
		return(1);
E 5
I 5
  	if (i < 2)
  		return MGrade;
E 5
D 4
	if (th < tl)
		flag = 0;  /* set up for crossover 2400 test */
	else
		flag = 1;
	if ((tn >= tl && tn <= th)
	  || (tn >= th && tn <= tl)) /* test for crossover 2400 */
		return(flag);
	else
		return(!flag);
E 4
I 4
	tn = tp->tm_hour * 100 + tp->tm_min;
D 5
	if (th < tl) {		/* crosses midnight */
E 5
I 5
  	if (th < tl) { 		/* crosses midnight */
  		if (tl <= tn || tn < th)
  			return MGrade;
D 10
  	} else

	if (i < 2)
		return MGrade;
	if (th < tl) { 	/* crosses midnight */
E 5
		if (tl <= tn || tn < th)
D 5
			return(1);
E 5
I 5
			return MGrade;
E 5
	} else
E 10
I 10
  	} else {
E 10
		if (tl <= tn && tn < th)
D 5
			return(1);
	return(0);
E 5
I 5
			return MGrade;
I 10
	}
E 10
	return FAIL;
E 5
E 4
}

D 5

/***
 *	char *
 *	lastc(s)	return pointer to last character
 *	char *s;
 *
 */
D 4

E 4
char *
lastc(s)
register char *s;
{
D 4
	while (*s != '\0') s++;
	return(s);
E 4
I 4
	while (*s != '\0')
		s++;
	return s;
E 4
}

D 4

E 4
/***
 *	char *
 *	fdig(cp)	find first digit in string
E 5
I 5
/*
 *	find first digit in string
E 5
 *
 *	return - pointer to first digit in string or end of string
 */
D 4

E 4
char *
fdig(cp)
register char *cp;
{
	register char *c;

	for (c = cp; *c; c++)
		if (*c >= '0' && *c <= '9')
			break;
D 4
	return(c);
E 4
I 4
	return c;
E 4
}

D 4

E 4
/*
 * Compare strings:  s1>s2: >0  s1==s2: 0  s1<s2: <0
 * Strings are compared as if they contain all capital letters.
 */
D 4

E 4
snccmp(s1, s2)
register char *s1, *s2;
{
	char c1, c2;

D 7
	if (islower(*s1)) c1 = toupper(*s1);
	else c1 = *s1;
	if (islower(*s2)) c2 = toupper(*s2);
	else c2 = *s2;
E 7
I 7
	if (islower(*s1))
		c1 = toupper(*s1);
	else
		c1 = *s1;
	if (islower(*s2))
		c2 = toupper(*s2);
	else
		c2 = *s2;
E 7

	while (c1 == c2) {
D 7
		if (*s1++=='\0')
E 7
I 7
		if (*s1++ == '\0')
E 7
D 4
			return(0);
E 4
I 4
			return 0;
E 4
		s2++;
D 7
		if (islower(*s1)) c1 = toupper(*s1);
		else c1 = *s1;
		if (islower(*s2)) c2 = toupper(*s2);
		else c2 = *s2;
E 7
I 7
		if (islower(*s1))
			c1 = toupper(*s1);
		else
			c1 = *s1;
		if (islower(*s2))
			c2 = toupper(*s2);
		else
			c2 = *s2;
E 7
	}
D 4
	return(c1 - c2);
E 4
I 4
	return c1 - c2;
I 7
}

/*
 * Compare strings:  s1>s2: >0  s1==s2: 0  s1<s2: <0
 * Strings are compared as if they contain all capital letters.
 */
sncncmp(s1, s2, n)
register char *s1, *s2;
register int n;
{
	char c1, c2;

	if (islower(*s1))
		c1 = toupper(*s1);
	else
		c1 = *s1;
	if (islower(*s2))
		c2 = toupper(*s2);
	else
		c2 = *s2;

	while ( --n >= 0 && c1 == c2) {
		if (*s1++ == '\0')
			return 0;
		s2++;
		if (islower(*s1))
			c1 = toupper(*s1);
		else
			c1 = *s1;
		if (islower(*s2))
			c2 = toupper(*s2);
		else
			c2 = *s2;
	}
	return n<0 ? 0 : (c1 - c2);
E 7
}
/*
 * do chat script
 * occurs after local port is opened,
 * before 'dialing' the other machine.
 */
dochat(dev, flds, fd)
register struct Devices *dev;
char *flds[];
int fd;
{
	register int i;
	register char *p;
	char bfr[sizeof(dev->D_argbfr)];

	if (dev->D_numargs <= 5)
		return(0);
	DEBUG(4, "dochat called %d\n", dev->D_numargs);
	for (i = 0; i < dev->D_numargs-5; i++) {
		sprintf(bfr, dev->D_arg[D_CHAT+i], flds[F_PHONE]);
		if (strcmp(bfr, dev->D_arg[D_CHAT+i])) {
			p = malloc((unsigned)strlen(bfr)+1);
			if (p != NULL) {
				strcpy(p, bfr);
				dev->D_arg[D_CHAT+i] = p;
			}
		}
	}
	/* following is a kludge because login() arglist is a kludge */
	i = login(dev->D_numargs, &dev->D_arg[D_CHAT-5], fd);
	/*
	 * If login() last did a sendthem(), must pause so things can settle.
	 * But don't bother if chat failed.
	 */
	if (i == 0 && (dev->D_numargs&01))
		sleep(2);
	return(i);
E 4
}
I 9

/*
 *	fix kill/echo/raw on line
 *
 *	return codes:  none
 */
fixmode(tty)
register int tty;
{
#ifdef	USG
	struct termio ttbuf;
#else	!USG
	struct sgttyb ttbuf;
#endif	!USG
	register struct sg_spds *ps;
	int speed;

	if (IsTcpIp)
		return;
#ifdef	USG
	ioctl(tty, TCGETA, &ttbuf);
	ttbuf.c_iflag = ttbuf.c_oflag = ttbuf.c_lflag = (ushort)0;
	speed = ttbuf.c_cflag &= (CBAUD);
	ttbuf.c_cflag |= (CS8|CREAD);
	ttbuf.c_cc[VMIN] = 6;
	ttbuf.c_cc[VTIME] = 1;
	ioctl(tty, TCSETA, &ttbuf);
#else	!USG
	ioctl(tty, TIOCGETP, &ttbuf);
	ttbuf.sg_flags = (ANYP | RAW);
	ioctl(tty, TIOCSETP, &ttbuf);
	speed = ttbuf.sg_ispeed;
	ioctl(tty, TIOCEXCL, STBNULL);
#endif	!USG

	for (ps = spds; ps->sp_val; ps++)
		if (ps->sp_name == speed) {
			linebaudrate = ps->sp_val;
			DEBUG(9,"Incoming baudrate is %d\n", linebaudrate);
			return;
		}
D 13
	ASSERT(linebaudrate >= 0, "BAD SPEED", CNULL, speed);
E 13
I 13
	if (linebaudrate < 0) {
		syslog(LOG_ERR, "unrecognized speed: %d", linebaudrate);
		cleanup(FAIL);
	}
E 13
}
D 13

E 13
E 9
E 1
