h18970
s 00005/00003/00993
d D 5.12 88/05/04 13:51:43 rick 12 11
c use setproctitle a la sendmail
e
s 00079/00027/00917
d D 5.11 88/04/05 12:03:52 rick 11 10
c use syslog for errors, fix turnaround code, fork uuxqt on turnaround
e
s 00007/00003/00937
d D 5.10 88/02/24 21:09:41 rick 10 9
c log which protocol using
e
s 00008/00009/00932
d D 5.9 88/02/24 19:47:00 rick 9 8
c better error logging
e
s 00035/00073/00906
d D 5.8 86/01/24 13:18:27 bloom 8 7
c still more fixes and changes from rick@seismo
e
s 00014/00024/00965
d D 5.7 85/10/09 15:34:42 bloom 7 6
c still more fixes from rick@seismo
e
s 00038/00023/00951
d D 5.6 85/06/19 18:05:54 bloom 6 5
c fix from rick adams
e
s 00058/00008/00916
d D 5.5 85/04/10 15:18:27 ralph 5 4
c more changes from rick adams.
e
s 00231/00162/00693
d D 5.4 85/01/22 13:58:41 ralph 4 3
c bug fixes and changes from Rick Adams
e
s 00023/00001/00832
d D 5.3 85/01/08 15:14:34 ralph 3 2
c don't use protocol 'n' if not connected to network.
e
s 00004/00000/00829
d D 5.2 84/08/30 16:13:57 ralph 2 1
c added network device NET
e
s 00829/00000/00000
d D 5.1 83/07/02 17:56:28 sam 1 0
c date and time created 83/07/02 17:56:28 by sam
e
u
U
t
T
I 1
#ifndef lint
D 11
static char sccsid[] = "%W% (Berkeley) %G%";
E 11
I 11
static char sccsid[] = "%W%	(Berkeley) %G%";
E 11
#endif

#include "uucp.h"
D 5
#include <sys/types.h>
E 5
#include <sys/stat.h>
I 4
#include "uust.h"
E 4

I 4
extern int errno;
I 5
extern int turntime;
int willturn;
I 6
int HaveSentHup = 0;
E 6
E 5
E 4

D 4

E 4
struct Proto {
	char P_id;
	int (*P_turnon)();
	int (*P_rdmsg)();
	int (*P_wrmsg)();
	int (*P_rddata)();
	int (*P_wrdata)();
	int (*P_turnoff)();
};

D 4

E 4
extern int gturnon(), gturnoff();
extern int grdmsg(), grddata();
extern int gwrmsg(), gwrdata();
I 2
D 4
extern int nturnon(), nturnoff();
extern int nrdmsg(), nrddata();
extern int nwrmsg(), nwrdata();
E 4
E 2
D 6
extern int imsg(), omsg();
I 4
#ifdef BSDTCP
extern int tnullf();
E 6
I 6
extern int imsg(), omsg(), nullf();
#ifdef TCPIP
E 6
extern int twrmsg(), trdmsg();
extern int twrdata(), trddata();
D 6
#endif BSDTCP
E 6
I 6
#endif TCPIP
E 6
#ifdef PAD
extern int fturnon(), fturnoff();
extern int frdmsg(), frddata();
extern int fwrmsg(), fwrdata();
#endif PAD
E 4

struct Proto Ptbl[]={
I 2
D 4
	'n', nturnon, nrdmsg, nwrmsg, nrddata, nwrdata, nturnoff,
E 4
I 4
D 6
#ifdef BSDTCP
	't', tnullf, trdmsg, twrmsg, trddata, twrdata, tnullf,
#endif BSDTCP
E 6
I 6
#ifdef TCPIP
	't', nullf, trdmsg, twrmsg, trddata, twrdata, nullf,
#endif TCPIP
E 6
#ifdef PAD
	'f', fturnon, frdmsg, fwrmsg, frddata, fwrdata, fturnoff,
#endif PAD
E 4
E 2
	'g', gturnon, grdmsg, gwrmsg, grddata, gwrdata, gturnoff,
	'\0'
};

D 4
int (*Imsg)() = imsg, (*Omsg)() = omsg;	/* avoid SEL compiler limitation */
E 4
I 4
int (*Imsg)() = imsg, (*Omsg)() = omsg;
E 4

int (*Rdmsg)()=imsg, (*Rddata)();
int (*Wrmsg)()=omsg, (*Wrdata)();
D 6
int (*Turnon)(), (*Turnoff)();
E 6
I 6
int (*Turnon)()=nullf, (*Turnoff)() = nullf;
E 6

I 5
D 7
struct timeb Now, LastTurned;
E 7
I 7
struct timeb Now, LastTurned, LastCheckedNoLogin;
E 7
E 5

D 4
#define YES "Y"
#define NO "N"
E 4
I 4
static char *YES = "Y";
static char *NO = "N";
E 4

I 5
int TransferSucceeded = 1;

E 5
/*  failure messages  */
#define EM_MAX		6
#define EM_LOCACC	"N1"	/* local access to file denied */
#define EM_RMTACC	"N2"	/* remote access to file/path denied */
#define EM_BADUUCP	"N3"	/* a bad uucp command was generated */
#define EM_NOTMP	"N4"	/* remote error - can't create temp */
#define EM_RMTCP	"N5"	/* can't copy to remote directory - file in public */
#define EM_LOCCP	"N6"	/* can't copy on local system */

char *Em_msg[] = {
	"COPY FAILED (reason not given by remote)",
	"local access to file denied",
	"remote access to path/file denied",
	"system error - bad uucp command generated",
	"remote system can't create temp file",
	"can't copy to file/directory - file left in PUBDIR/user/file",
D 4
	"can't copy to file/directory - file left in PUBDIR/user/file"
E 4
I 4
	"can't copy to file/directory on local system  - file left in PUBDIR/user/file"
E 4
};

D 4
/*       */
E 4

D 4

E 4
#define XUUCP 'X'	/* execute uucp (string) */
#define SLTPTCL 'P'	/* select protocol  (string)  */
#define USEPTCL 'U'	/* use protocol (character) */
#define RCVFILE 'R'	/* receive file (string) */
#define SNDFILE 'S'	/* send file (string) */
#define RQSTCMPT 'C'	/* request complete (string - yes | no) */
#define HUP     'H'	/* ready to hangup (string - yes | no) */
#define RESET	'X'	/* reset line modes */

D 4

E 4
#define W_TYPE		wrkvec[0]
#define W_FILE1		wrkvec[1]
#define W_FILE2		wrkvec[2]
#define W_USER		wrkvec[3]
#define W_OPTNS		wrkvec[4]
#define W_DFILE		wrkvec[5]
#define W_MODE		wrkvec[6]
#define W_NUSER		wrkvec[7]

D 4
#define	XFRRATE	350000L
#define RMESG(m, s, n) if (rmesg(m, s, n) != 0) {(*Turnoff)(); return(FAIL);} else
#define RAMESG(s, n) if (rmesg('\0', s, n) != 0) {(*Turnoff)(); return(FAIL);} else
#define WMESG(m, s) if(wmesg(m, s) != 0) {(*Turnoff)(); return(FAIL);} else
E 4
I 4
#define	XFRRATE	35000L
#define RMESG(m, s, n) if (rmesg(m, s, n) != 0) {(*Turnoff)(); return FAIL;} else
#define RAMESG(s, n) if (rmesg('\0', s, n) != 0) {(*Turnoff)(); return FAIL;} else
#define WMESG(m, s) if(wmesg(m, s) != 0) {(*Turnoff)(); return FAIL;} else
E 4

char Wfile[MAXFULLNAME] = {'\0'};
char Dfile[MAXFULLNAME];

/*
 * To avoid a huge backlog of X. files, start uuxqt every so often.
D 4
 * To avoid a huge number of uuxqt zombies, 
 * wait for one occasionally!
E 4
 */
static int nXfiles = 0;	/* number of X files since last uuxqt start */
D 6
static int nXQTs = 0;	/* number of uuxqts started */
E 6
I 4
static char send_or_receive;
struct stat stbuf;
E 4

D 4
/*******
 *	cntrl(role, wkpre)
 *	int role;
 *	char *wkpre;
 *
E 4
I 4
/*
E 4
 *	cntrl  -  this routine will execute the conversation
 *	between the two machines after both programs are
 *	running.
 *
 *	return codes
 *		SUCCESS - ok
 *		FAIL - failed
 */

cntrl(role, wkpre)
int role;
char *wkpre;
{
	char msg[BUFSIZ], rqstr[BUFSIZ];
	register FILE *fp;
	int filemode;
D 4
	struct stat stbuf;
E 4
	char filename[MAXFULLNAME], wrktype, *wrkvec[20];
	extern (*Rdmsg)(), (*Wrmsg)();
	extern char *index(), *lastpart();
	int status = 1;
	register int i, narg;
	int mailopt, ntfyopt;
	int ret;
	static int pnum, tmpnum = 0;
I 4
	extern int ReverseRole;
E 4

	pnum = getpid();
D 4
/*
 * ima.247, John Levine, IECC, PO Box 349, Cambridge MA 02238; (617) 491-5450
 * zap Wfile to prevent reuse of wrong C. file
 */
E 4
	Wfile[0] = '\0';
I 5
	willturn = turntime > 0;
remaster:
#ifdef USG
	time(&LastTurned.time);
	LastTurned.millitm = 0;
#else !USG
	ftime(&LastTurned);
#endif !USG
	send_or_receive = RESET;
I 6
	HaveSentHup = 0;
E 6
E 5
top:
	for (i = 0; i < sizeof wrkvec / sizeof wrkvec[0]; i++)
		wrkvec[i] = 0;
D 4
	DEBUG(4, "*** TOP ***  -  role=%d, ", role);
E 4
I 4
	DEBUG(4, "*** TOP ***  -  role=%s\n", role ? "MASTER" : "SLAVE");
I 12
	setproctitle("%s: %s", Rmtname, role ? "MASTER" : "SLAVE");
E 12
E 4
D 6
	setline(RESET);
E 6
I 6
	setupline(RESET);
E 6
I 4
D 5
	send_or_receive = RESET;
E 5
I 5
D 7
	if (nologinflag) {
		logent(NOLOGIN, "UUCICO SHUTDOWN");
D 6
		if (Debug)
E 6
I 6
		if (Debug > 4)
E 6
			logent("DEBUGGING", "continuing anyway");
		else {
			WMESG(HUP, YES);
			RMESG(HUP, msg, 1);
			goto process;
E 7
I 7
	if (Now.time > (LastCheckedNoLogin.time+60)) {
		LastCheckedNoLogin = Now;
		if (access(NOLOGIN, 0) == 0) {
			logent(NOLOGIN, "UUCICO SHUTDOWN");
			if (Debug > 4)
				logent("DEBUGGING", "continuing anyway");
			else {
				WMESG(HUP, YES);
				RMESG(HUP, msg, 1);
				goto process;
			}
E 7
		}
	}
E 5
E 4
	if (role == MASTER) {
		/* get work */
D 4
		if ((narg = gtwvec(Wfile, Spool, wkpre, wrkvec)) == 0) {
E 4
I 4
		if (ReverseRole || (narg = gtwvec(Wfile, Spool, wkpre, wrkvec)) == 0) {
			ReverseRole = 0;
E 4
			WMESG(HUP, "");
			RMESG(HUP, msg, 1);
			goto process;
		}
		wrktype = W_TYPE[0];
D 4
		mailopt = index(W_OPTNS, 'm') != NULL;
		ntfyopt = index(W_OPTNS, 'n') != NULL;
E 4

		msg[0] = '\0';
		for (i = 1; i < narg; i++) {
			strcat(msg, " ");
			strcat(msg, wrkvec[i]);
		}

		if (wrktype == XUUCP) {
			sprintf(rqstr, "X %s", msg);
			logent(rqstr, "REQUEST");
			goto sendmsg;
		}
I 4
		mailopt = index(W_OPTNS, 'm') != NULL;
		ntfyopt = index(W_OPTNS, 'n') != NULL;
E 4

D 4
		ASSERT(narg > 4, "ARG COUNT<5", "", i);
E 4
I 4
D 9
		if (narg < 5) {
E 9
I 9
		if (narg < 5 || W_TYPE[1] != '\0') {
E 9
			char *bnp;
			bnp = rindex(Wfile, '/');
			sprintf(rqstr, "%s/%s", CORRUPT, bnp ? bnp + 1 : Wfile);
			xmv(Wfile, rqstr);
D 9
			logent(Wfile, "CMD FILE CORRUPTED");
E 9
I 9
D 11
			assert("CMD FILE CORRUPTED", Wfile, narg);
E 11
I 11
			syslog(LOG_WARNING, "%s CORRUPTED: %d args", Wfile,
				narg);
E 11
E 9
			Wfile[0] = '\0';
			goto top;
		}
E 4
		sprintf(User, "%.9s", W_USER);
D 12
		sprintf(rqstr, "%s %s %s %s", W_TYPE, W_FILE1,
E 12
I 12
		sprintf(rqstr, "(%s %s %s %s)", W_TYPE, W_FILE1,
E 12
		  W_FILE2, W_USER);
		logent(rqstr, "REQUEST");
		if (wrktype == SNDFILE ) {
			strcpy(filename, W_FILE1);
			i = expfile(filename);
D 4
			DEBUG(4, "expfile type - %d", i);
E 4
I 4
			DEBUG(4, "expfile type - %d, ", i);
E 4
			if (i != 0 && chkpth(User, "", filename))
				goto e_access;
			strcpy(Dfile, W_DFILE);
			fp = NULL;
			if (index(W_OPTNS, 'c') == NULL) {
				fp = fopen(subfile(Dfile), "r");
				if (fp != NULL)
					i = 0;
			}
			if (fp == NULL &&
			   (fp = fopen(subfile(filename), "r")) == NULL) {
				/*  can not read data file  */
D 4
				logent("CAN'T READ DATA", "FAILED");
E 4
I 4
				logent("CAN'T READ DATA", _FAILED);
I 6
				TransferSucceeded = 1; /* else will keep sending */
E 6
				USRF(USR_LOCACC);
E 4
				unlinkdf(Dfile);
				lnotify(User, filename, "can't access");
				goto top;
			}
			/* if file exists but is not generally readable... */
			if (i != 0 && fstat(fileno(fp), &stbuf) == 0
			&&  (stbuf.st_mode & ANYREAD) == 0) {
		e_access:;
				/*  access denied  */
D 11
				fclose(fp);
				fp = NULL;
E 11
I 11
				if (fp != NULL) {
					fclose(fp);
					fp = NULL;
				}
E 11
I 6
				TransferSucceeded = 1; /* else will keep sending */
E 6
				logent("DENIED", "ACCESS");
I 4
				USRF(USR_LOCACC);
E 4
				unlinkdf(W_DFILE);
				lnotify(User, filename, "access denied");
				goto top;
			}

D 6
			setline(SNDFILE);
E 6
I 6
			setupline(SNDFILE);
E 6
		}

		if (wrktype == RCVFILE) {
			strcpy(filename, W_FILE2);
			expfile(filename);
			if (chkpth(User, "", filename)
			 || chkperm(filename, index(W_OPTNS, 'd'))) {
				/*  access denied  */
				logent("DENIED", "ACCESS");
I 6
				TransferSucceeded = 1; /* else will keep trying */
E 6
I 4
				USRF(USR_LOCACC);
E 4
				lnotify(User, filename, "access denied");
				goto top;
			}
			sprintf(Dfile, "%s/TM.%05d.%03d", Spool, pnum, tmpnum++);
			if ((fp = fopen(subfile(Dfile), "w")) == NULL) {
				/*  can not create temp  */
D 4
				logent("CAN'T CREATE TM", "FAILED");
E 4
I 4
				logent("CAN'T CREATE TM", _FAILED);
				USRF(USR_LNOTMP);
E 4
				unlinkdf(Dfile);
				goto top;
			}
D 6
			setline(RCVFILE);
E 6
I 6
			setupline(RCVFILE);
E 6
		}
sendmsg:
D 4
		DEBUG(4, "wrktype - %c\n ", wrktype);
E 4
I 4
		DEBUG(4, "wrktype - %c\n", wrktype);
E 4
		WMESG(wrktype, msg);
		RMESG(wrktype, msg, 1);
		goto process;
	}

	/* role is slave */
	RAMESG(msg, 1);
D 5
	goto process;

E 5
I 5
	if (willturn < 0)
		willturn = msg[0] == HUP;
			
E 5
process:
D 4
/*	rti!trt: ultouch is now done in gio.c (yes, kludge)
 *	ultouch();
 */
	DEBUG(4, " PROCESS: msg - %s\n", msg);
E 4
I 4
	DEBUG(4, "PROCESS: msg - %s\n", msg);
E 4
	switch (msg[0]) {

	case RQSTCMPT:
D 4
		DEBUG(4, "%s\n", "RQSTCMPT:");
E 4
I 4
		DEBUG(4, "RQSTCMPT:\n", CNULL);
I 5
D 6
		TransferSucceeded = msg[1] == 'Y';
E 6
E 5
E 4
		if (msg[1] == 'N') {
			i = atoi(&msg[2]);
D 6
			if (i<0 || i>EM_MAX) i=0;
E 6
I 6
			if (i<0 || i>EM_MAX)
				i = 0;
E 6
D 4
			/* duke!rti: only note failed requests */
			logent(msg, "REQUESTED");
E 4
I 4
			USRF( 1 << i );
D 7
				i = 0;
E 7
			logent(Em_msg[i], "REQUEST FAILED");
D 7
			if (strcmp(&msg[1], EM_NOTMP) == 0) {
				/* dont send him files he can't save */
				WMESG(HUP, "");
				RMESG(HUP, msg, 1);
				goto process;
D 6
			}
E 6
I 6
			} else
				TransferSucceeded = 1; /* He had his chance */
E 7
I 7
			TransferSucceeded = 1; /* He had his chance */
E 7
E 6
E 4
		}
I 4
D 6
		if (msg[1] == 'Y')
E 6
I 6
		if (msg[1] == 'Y') {
E 6
			USRF(USR_COK);
I 6
			TransferSucceeded = 1;
		}
E 6
E 4
D 11
		if (role == MASTER) {
E 11
I 11
		if (role == MASTER)
E 11
D 9
			notify(mailopt, W_USER, W_FILE1, Rmtname, &msg[1]);
E 9
I 9
D 10
			notify(mailopt, W_USER, W_FILE2, Rmtname, &msg[1]);
E 10
I 10
			notify(mailopt, W_USER, W_FILE1, Rmtname, &msg[1]);
E 10
E 9
D 11
		}
I 5
		if (msg[2] == 'M') {
E 11
I 11

		if (msg[2] == 'M' && role == MASTER) {
E 11
			extern int Nfiles;
			WMESG(HUP, "");
			RMESG(HUP, msg, 1);
			logent(Rmtname, "TURNAROUND");
#ifdef USG
				time(&LastTurned.time);
				LastTurned.millitm = 0;
#else !USG
				ftime(&LastTurned);
#endif !USG
			Nfiles = 0; /* force rescan of queue for work */
			goto process;
		}
E 5
		goto top;

	case HUP:
D 4
		DEBUG(4, "%s\n", "HUP:");
E 4
I 4
		DEBUG(4, "HUP:\n", CNULL);
I 6
		HaveSentHup = 1;
E 6
E 4
		if (msg[1] == 'Y') {
D 4
			WMESG(HUP, YES);
E 4
I 4
			if (role == MASTER)
				WMESG(HUP, YES);
E 4
			(*Turnoff)();
			Rdmsg = Imsg;
			Wrmsg = Omsg;
D 4
			return(0);
E 4
I 4
			return SUCCESS;
E 4
		}

		if (msg[1] == 'N') {
D 4
			ASSERT(role == MASTER, "WRONG ROLE", "", role);
E 4
I 4
D 11
			ASSERT(role == MASTER, "WRONG ROLE - HUP", CNULL, role);
E 11
I 11
			if (role != MASTER) {
				syslog(LOG_ERR, "Wrong Role - HUP");
				cleanup(FAIL);
			}
E 11
E 4
			role = SLAVE;
D 5
			goto top;
E 5
I 5
			goto remaster;
E 5
		}

		/* get work */
		if (!iswrk(Wfile, "chk", Spool, wkpre)) {
			WMESG(HUP, YES);
			RMESG(HUP, msg, 1);
			goto process;
		}

		WMESG(HUP, NO);
I 11
		/*
		 * want to create an orphan uuxqt,
		 * so a double-fork is needed.
		 */
		if (fork() == 0) {
			xuuxqt();
			_exit(0);
		}
		wait((int *)0);
E 11
		role = MASTER;
D 5
		goto top;
E 5
I 5
		goto remaster;
E 5

	case XUUCP:
		if (role == MASTER) {
			goto top;
		}

		/*  slave part  */
D 4
		i = getargs(msg, wrkvec);
E 4
I 4
		i = getargs(msg, wrkvec, 20);
E 4
		strcpy(filename, W_FILE1);
D 4
		if (index(filename, ';') != NULL
		  || index(W_FILE2, ';') != NULL
		  || i < 3) {
E 4
I 4
		if (index(filename, ';') != NULL || index(W_FILE2, ';') != NULL
		    || i < 3) {
E 4
			WMESG(XUUCP, NO);
			goto top;
		}
		expfile(filename);
		if (chkpth("", Rmtname, filename)) {
			WMESG(XUUCP, NO);
			logent("XUUCP DENIED", filename);
I 4
				USRF(USR_XUUCP);
E 4
			goto top;
		}
		sprintf(rqstr, "%s %s", filename, W_FILE2);
		xuucp(rqstr);
		WMESG(XUUCP, YES);
		goto top;

	case SNDFILE:
		/*  MASTER section of SNDFILE  */

		DEBUG(4, "%s\n", "SNDFILE:");
		if (msg[1] == 'N') {
			i = atoi(&msg[2]);
			if (i < 0 || i > EM_MAX)
				i = 0;
D 4
			logent(Em_msg[i], "REQUEST");
			notify(mailopt, W_USER, W_FILE1, Rmtname, &msg[1]);
			ASSERT(role == MASTER, "WRONG ROLE", "", role);
E 4
I 4
			logent(Em_msg[i], "REQUEST FAILED");
			USRF( 1 << i );
E 4
			fclose(fp);
			fp = NULL;
I 7
			/* dont send him files he can't save */
E 7
I 4
			if (strcmp(&msg[1], EM_NOTMP) == 0) {
D 7
				/* dont send him files he can't save */
E 7
				WMESG(HUP, "");
				RMESG(HUP, msg, 1);
				goto process;
			}
D 9
			notify(mailopt, W_USER, W_FILE1, Rmtname, &msg[1]);
E 9
I 9
D 10
			notify(mailopt, W_USER, W_FILE2, Rmtname, &msg[1]);
E 10
I 10
			notify(mailopt, W_USER, W_FILE1, Rmtname, &msg[1]);
E 10
E 9
D 11
			ASSERT(role == MASTER, "WRONG ROLE - SN", CNULL, role);
E 11
I 11
			if (role != MASTER) {
				syslog(LOG_ERR, "Wrong Role - SN");
				cleanup(FAIL);
			}
E 11
E 4
D 9
			if (msg[1] != '4')
				unlinkdf(W_DFILE);
E 9
I 9
			unlinkdf(W_DFILE);
E 9
			goto top;
		}

		if (msg[1] == 'Y') {
			/* send file */
D 4
			ASSERT(role == MASTER, "WRONG ROLE", "", role);
E 4
I 4
D 11
			ASSERT(role == MASTER, "WRONG ROLE - SY", CNULL, role);
E 4
			ret = fstat(fileno(fp), &stbuf);
			ASSERT(ret != -1, "STAT FAILED", filename, 0);
E 11
I 11
			if (role != MASTER) {
				syslog(LOG_ERR, "Wrong Role - SY");
				cleanup(FAIL);
			}
			if (fstat(fileno(fp), &stbuf) < 0) {
				syslog(LOG_ERR, "stat(%s) failed: %m",filename);
				cleanup(FAIL);
			}
E 11
			i = 1 + (int)(stbuf.st_size / XFRRATE);
I 4
			if (send_or_receive != SNDFILE) {
				send_or_receive = SNDFILE;
				systat(Rmtname, SS_INPROGRESS, "SENDING");
			}
E 4
			ret = (*Wrdata)(fp, Ofn);
			fclose(fp);
			fp = NULL;
D 4
			if (ret != 0) {
E 4
I 4
			if (ret != SUCCESS) {
E 4
				(*Turnoff)();
D 4
				return(FAIL);
E 4
I 4
				USRF(USR_CFAIL);
				return FAIL;
E 4
			}
			RMESG(RQSTCMPT, msg, i);
D 4
/* put the unlink *after* the RMESG -- fortune!Dave-Yost */
E 4
			unlinkdf(W_DFILE);
			goto process;
		}

		/*  SLAVE section of SNDFILE  */
D 4
		ASSERT(role == SLAVE, "WRONG ROLE", "", role);
E 4
I 4
D 11
		ASSERT(role == SLAVE, "WRONG ROLE - SLAVE", CNULL, role);
E 11
I 11
		if (role != SLAVE) {
			syslog(LOG_ERR, "Wrong Role - SLAVE");
			cleanup(FAIL);
		}
E 11
E 4

		/* request to receive file */
		/* check permissions */
D 4
		i = getargs(msg, wrkvec);
		ASSERT(i > 4, "ARG COUNT<5", "", i);
		sprintf(rqstr, "%s %s %s %s", W_TYPE, W_FILE1,
		  W_FILE2, W_USER);
E 4
I 4
		i = getargs(msg, wrkvec, 20);
		if (i < 5) {
			char *bnp;
			bnp = rindex(Wfile, '/');
			sprintf(rqstr, "%s/%s", CORRUPT, bnp ? bnp + 1 : Wfile);
			xmv(Wfile, rqstr);
D 9
			logent(Wfile, "CMD FILE CORRUPTED");
E 9
I 9
D 11
			assert("CMD FILE CORRUPTED",Wfile, i);
E 11
I 11
			syslog(LOG_WARNING, "%s CORRUPTED: %d args", Wfile, i);
E 11
E 9
			Wfile[0] = '\0';
			goto top;
		}
D 12
		sprintf(rqstr, "%s %s %s %s", W_TYPE, W_FILE1, W_FILE2, W_USER);
E 12
I 12
		sprintf(rqstr, "(%s %s %s %s)", W_TYPE, W_FILE1, W_FILE2,
			W_USER);
E 12
E 4
		logent(rqstr, "REQUESTED");
		DEBUG(4, "msg - %s\n", msg);
		strcpy(filename, W_FILE2);
		/* Run uuxqt occasionally */
		if (filename[0] == XQTPRE) {
			if (++nXfiles > 10) {
				nXfiles = 0;
D 4
				/* I sure hope the wait(II) does not hang.
				 * One can never tell about UNIX variants.
E 4
I 4
				/*
				 * want to create an orphan uuxqt,
				 * so a double-fork is needed.
E 4
				 */
D 4
				if (++nXQTs > 2)
					wait((int *)0);
				xuuxqt();
E 4
I 4
				if (fork() == 0) {
					xuuxqt();
					_exit(0);
				}
				wait((int *)0);
E 4
			}
		}
D 4
		/* rti!trt: expand filename, i is set to 0 if this is
E 4
I 4
		/* expand filename, i is set to 0 if this is
E 4
		 * is a vanilla spool file, so no stat(II)s are needed */
		i = expfile(filename);
		DEBUG(4, "expfile type - %d\n", i);
		if (i != 0) {
			if (chkpth("", Rmtname, filename)
			 || chkperm(filename, index(W_OPTNS, 'd'))) {
				WMESG(SNDFILE, EM_RMTACC);
				logent("DENIED", "PERMISSION");
				goto top;
			}
			if (isdir(filename)) {
				strcat(filename, "/");
				strcat(filename, lastpart(W_FILE1));
			}
		}
		sprintf(User, "%.9s", W_USER);

		DEBUG(4, "chkpth ok Rmtname - %s\n", Rmtname);
I 4
		/* speed things up by OKing file before
		 * creating TM file.  If the TM file cannot be created,
		 * then the conversation bombs, but that seems reasonable,
		 * as there are probably serious problems then.
		 */
		WMESG(SNDFILE, YES);
E 4
		sprintf(Dfile, "%s/TM.%05d.%03d", Spool, pnum, tmpnum++);
		if((fp = fopen(subfile(Dfile), "w")) == NULL) {
D 4
			WMESG(SNDFILE, EM_NOTMP);
			logent("CAN'T OPEN", "DENIED");
E 4
I 4
/*			WMESG(SNDFILE, EM_NOTMP);*/
			logent("CAN'T OPEN", "TM FILE");
E 4
			unlinkdf(Dfile);
D 4
			goto top;
E 4
I 4
			(*Turnoff)();
			return FAIL;
E 4
		}

D 4
		WMESG(SNDFILE, YES);
E 4
I 4
		if (send_or_receive != RCVFILE) {
			send_or_receive = RCVFILE;
			systat(Rmtname, SS_INPROGRESS, "RECEIVING");
		}
E 4
		ret = (*Rddata)(Ifn, fp);
D 4
		/* ittvax!swatt: (try to) make sure IO successful */
E 4
		fflush(fp);
		if (ferror(fp) || fclose(fp))
			ret = FAIL;
I 5
D 6

E 6
I 6
		
E 6
E 5
D 4
		if (ret != 0) {
E 4
I 4
		if (ret != SUCCESS) {
			(void) unlinkdf(Dfile);
E 4
			(*Turnoff)();
D 4
			return(FAIL);
E 4
I 4
			return FAIL;
E 4
		}
		/* copy to user directory */
		ntfyopt = index(W_OPTNS, 'n') != NULL;
		status = xmv(Dfile, filename);
D 5
		WMESG(RQSTCMPT, status ? EM_RMTCP : YES);
E 5
I 5

		if (willturn && Now.time > (LastTurned.time+turntime)
			&& iswrk(Wfile, "chk", Spool, wkpre)) {
				WMESG(RQSTCMPT, status ? EM_RMTCP : "YM");
				willturn = -1;
		} else
			WMESG(RQSTCMPT, status ? EM_RMTCP : YES);
E 5
D 4
		if (status == 0) {
			sscanf(W_MODE, "%o", &filemode);
			if (filemode <= 0)
E 4
I 4
		if (i == 0)
			;	/* vanilla file, nothing to do */
		else if (status == 0) {
			if (W_MODE == 0 || sscanf(W_MODE, "%o", &filemode) != 1)
E 4
				filemode = BASEMODE;
D 4
			chmod(subfile(filename), filemode | BASEMODE);
E 4
I 4
			chmod(subfile(filename), (filemode|BASEMODE)&0777);
E 4
			arrived(ntfyopt, filename, W_NUSER, Rmtname, User);
D 4
		}
		else {
			logent("FAILED", "COPY");
E 4
I 4
		} else {
			logent(_FAILED, "COPY");
E 4
			status = putinpub(filename, Dfile, W_USER);
			DEBUG(4, "->PUBDIR %d\n", status);
			if (status == 0)
D 4
				arrived(ntfyopt, filename, W_NUSER,
				  Rmtname, User);
E 4
I 4
				arrived(ntfyopt, filename, W_NUSER, Rmtname, User);
E 4
		}

		goto top;

	case RCVFILE:
		/*  MASTER section of RCVFILE  */

		DEBUG(4, "%s\n", "RCVFILE:");
		if (msg[1] == 'N') {
			i = atoi(&msg[2]);
			if (i < 0 || i > EM_MAX)
				i = 0;
D 4
			logent(Em_msg[i], "REQUEST");
			notify(mailopt, W_USER, W_FILE1, Rmtname, &msg[1]);
			ASSERT(role == MASTER, "WRONG ROLE", "", role);
E 4
I 4
			logent(Em_msg[i], "REQUEST FAILED");
			USRF( 1 << i );
E 4
			fclose(fp);
I 4
			fp = NULL;
D 7
			if (strcmp(&msg[1], EM_NOTMP) == 0) {
				/* dont send him files he can't save */
				WMESG(HUP, "");
				RMESG(HUP, msg, 1);
				goto process;
			}
E 7
D 9
			notify(mailopt, W_USER, W_FILE1, Rmtname, &msg[1]);
E 9
I 9
D 10
			notify(mailopt, W_USER, W_FILE2, Rmtname, &msg[1]);
E 10
I 10
			notify(mailopt, W_USER, W_FILE1, Rmtname, &msg[1]);
E 10
E 9
D 11
			ASSERT(role == MASTER, "WRONG ROLE - RN", CNULL, role);
E 11
I 11
			if (role != MASTER) {
				syslog(LOG_ERR, "Wrong Role - RN");
				cleanup(FAIL);
			}
E 11
E 4
			unlinkdf(Dfile);
			goto top;
		}

		if (msg[1] == 'Y') {
			/* receive file */
D 4
			ASSERT(role == MASTER, "WRONG ROLE", "", role);
E 4
I 4
D 11
			ASSERT(role == MASTER, "WRONG ROLE - RY", CNULL, role);
E 11
I 11
			if (role != MASTER) {
				syslog(LOG_ERR, "Wrong Role - RY");
				cleanup(FAIL);
			}
E 11
			if (send_or_receive != RCVFILE) {
				send_or_receive = RCVFILE;
				systat(Rmtname, SS_INPROGRESS, "RECEIVING");
			}
E 4
			ret = (*Rddata)(Ifn, fp);
D 4
			/* ittvax!swatt: (try to) make sure IO successful */
E 4
			fflush(fp);
			if (ferror(fp) || fclose(fp))
				ret = FAIL;
D 4
			if (ret != 0) {
E 4
I 4
			if (ret != SUCCESS) {
				unlinkdf(Dfile);
E 4
				(*Turnoff)();
D 4
				return(FAIL);
E 4
I 4
				USRF(USR_CFAIL);
				return FAIL;
E 4
			}
			/* copy to user directory */
			if (isdir(filename)) {
				strcat(filename, "/");
				strcat(filename, lastpart(W_FILE1));
			}
			status = xmv(Dfile, filename);
D 5
			WMESG(RQSTCMPT, status ? EM_RMTCP : YES);
E 5
I 5
D 11
			if (willturn && Now.time > (LastTurned.time+turntime)
				&& iswrk(Wfile, "chk", Spool, wkpre)) {
					WMESG(RQSTCMPT, status ? EM_RMTCP : "YM");
					willturn = -1;
			} else
				WMESG(RQSTCMPT, status ? EM_RMTCP : YES);
E 11
I 11
			WMESG(RQSTCMPT, status ? EM_RMTCP : YES);
E 11
E 5
			notify(mailopt, W_USER, filename, Rmtname,
D 8
			  status ? EM_LOCCP : YES);
E 8
I 8
				status ? EM_LOCCP : YES);
E 8
			if (status == 0) {
				sscanf(&msg[2], "%o", &filemode);
				if (filemode <= 0)
					filemode = BASEMODE;
D 4
				chmod(subfile(filename), filemode | BASEMODE);
E 4
I 4
				chmod(subfile(filename), (filemode|BASEMODE)&0777);
				USRF(USR_COK);
E 4
D 8
			}
			else {
E 8
I 8
			} else {
E 8
D 4
				logent("FAILED", "COPY");
E 4
I 4
				logent(_FAILED, "COPY");
E 4
				putinpub(filename, Dfile, W_USER);
I 4
				USRF(USR_LOCCP);
E 4
			}
I 11
			if (msg[strlen(msg)-1] == 'M') {
				extern int Nfiles;
				WMESG(HUP, "");
				RMESG(HUP, msg, 1);
				logent(Rmtname, "TURNAROUND");
#ifdef USG
				time(&LastTurned.time);
				LastTurned.millitm = 0;
#else !USG
				ftime(&LastTurned);
#endif !USG
				Nfiles = 0; /* force rescan of queue for work */
				goto process;
			}
E 11
			goto top;
		}

		/*  SLAVE section of RCVFILE  */
D 4
		ASSERT(role == SLAVE, "WRONG ROLE", "", role);
E 4
I 4
D 11
		ASSERT(role == SLAVE, "WRONG ROLE - SLAVE RCV", CNULL, role);
E 11
I 11
		if (role != SLAVE) {
			syslog(LOG_ERR, "Wrong Role - SLAVE RCV");
			cleanup(FAIL);
		}
E 11
E 4

		/* request to send file */
D 12
		strcpy(rqstr, msg);
E 12
I 12
		sprintf(rqstr,"(%s)", msg);
E 12
		logent(rqstr, "REQUESTED");

		/* check permissions */
D 4
		i = getargs(msg, wrkvec);
		ASSERT(i > 3, "ARG COUNT<4", "", i);
E 4
I 4
		i = getargs(msg, wrkvec, 20);
		if (i < 4) {
			char *bnp;
			bnp = rindex(Wfile, '/');
			sprintf(rqstr, "%s/%s", CORRUPT, bnp ? bnp + 1 : Wfile);
			xmv(Wfile, rqstr);
D 9
			logent(Wfile, "CMD FILE CORRUPTED");
E 9
I 9
D 11
			assert("CMD FILE CORRUPTED", Wfile, i);
E 11
I 11
			syslog(LOG_WARNING, "%s CORRUPTED: %d args", Wfile, i);
E 11
E 9
			Wfile[0] = '\0';
			goto top;
		}
E 4
		DEBUG(4, "msg - %s\n", msg);
		DEBUG(4, "W_FILE1 - %s\n", W_FILE1);
		strcpy(filename, W_FILE1);
		expfile(filename);
		if (isdir(filename)) {
			strcat(filename, "/");
			strcat(filename, lastpart(W_FILE2));
		}
		sprintf(User, "%.9s", W_USER);
		if (chkpth("", Rmtname, filename) || anyread(filename)) {
			WMESG(RCVFILE, EM_RMTACC);
			logent("DENIED", "PERMISSION");
			goto top;
		}
		DEBUG(4, "chkpth ok Rmtname - %s\n", Rmtname);

		if ((fp = fopen(subfile(filename), "r")) == NULL) {
			WMESG(RCVFILE, EM_RMTACC);
			logent("CAN'T OPEN", "DENIED");
			goto top;
		}

		/*  ok to send file */
D 11
		ret = fstat(fileno(fp), &stbuf);
		ASSERT(ret != -1, "STAT FAILED", filename, 0);
E 11
I 11
		if (fstat(fileno(fp), &stbuf) < 0) {
			syslog(LOG_ERR, "stat(%s) failed: %m", filename);
			cleanup(FAIL);
		}

E 11
		i = 1 + (int)(stbuf.st_size / XFRRATE);
D 6
		sprintf(msg, "%s %o", YES, stbuf.st_mode & 0777);
E 6
I 6
D 11
		sprintf(msg, "%s %o", YES, (int)stbuf.st_mode & 0777);
E 11
I 11
		if (willturn && Now.time > (LastTurned.time+turntime)
			&& iswrk(Wfile, "chk", Spool, wkpre)) {
				willturn = -1;
		}
		sprintf(msg, "%s %o%s", YES, (int)stbuf.st_mode & 0777,
			willturn < 0 ? " M" : "");
E 11
E 6
		WMESG(RCVFILE, msg);
I 4
		if (send_or_receive != SNDFILE) {
			send_or_receive = SNDFILE;
			systat(Rmtname, SS_INPROGRESS, "SENDING");
		}
E 4
		ret = (*Wrdata)(fp, Ofn);
		fclose(fp);
D 4
		if (ret != 0) {
E 4
I 4
		if (ret != SUCCESS) {
E 4
			(*Turnoff)();
D 4
			return(FAIL);
E 4
I 4
			return FAIL;
E 4
		}
		RMESG(RQSTCMPT, msg, i);
		goto process;
	}
	(*Turnoff)();
D 4
	return(FAIL);
E 4
I 4
	return FAIL;
E 4
}


D 8
/***
 *	rmesg(c, msg, n)	read message 'c'
 *				try 'n' times
 *	char *msg, c;
E 8
I 8
/*
 *	read message 'c'. try 'n' times
E 8
 *
D 8
 *	return code:  0  |  FAIL
E 8
I 8
 *	return code:  SUCCESS  |  FAIL
E 8
 */
D 8

E 8
rmesg(c, msg, n)
register char *msg, c;
register int n;
{
D 4
	char str[50];
E 4
I 4
D 8
	char str[128];
E 8
I 8
	char str[MAXFULLNAME];
E 8
E 4

	DEBUG(4, "rmesg - '%c' ", c);
D 4
	if (n != 1) {
		sprintf(str, "%d", n);
		logent(str, "PATIENCE");
	}
	while ((*Rdmsg)(msg, Ifn) != 0) {
		if (--n > 0)
E 4
I 4
	while ((*Rdmsg)(msg, Ifn) != SUCCESS) {
		if (--n > 0) {
			sprintf(str, "%d", n);
			logent(str, "PATIENCE");
E 4
			continue;
D 4
		DEBUG(4, "got %s\n", "FAIL");
		sprintf(str, "expected '%c' got FAIL", c);
E 4
I 4
		}
		DEBUG(4, "got FAIL\n", CNULL);
		if (c != '\0')
			sprintf(str, "expected '%c' got FAIL (%d)", c, errno);
		else
			sprintf(str, "expected ANY got FAIL (%d)", errno);
E 4
		logent(str, "BAD READ");
D 4
		return(FAIL);
E 4
I 4
		return FAIL;
E 4
	}
	if (c != '\0' && msg[0] != c) {
		DEBUG(4, "got %s\n", msg);
D 4
		sprintf(str, "expected '%c' got %.25s", c, msg);
E 4
I 4
		sprintf(str, "expected '%c' got %s", c, msg);
E 4
		logent(str, "BAD READ");
D 4
		return(FAIL);
E 4
I 4
		return FAIL;
E 4
	}
D 4
	DEBUG(4, "got %.25s\n", msg);
	return(0);
E 4
I 4
	DEBUG(4, "got %s\n", msg);
	return SUCCESS;
E 4
}


D 8
/***
 *	wmesg(m, s)	write a message (type m)
 *	char *s, m;
E 8
I 8
/*
 *	write a message (type m)
E 8
 *
D 8
 *	return codes: 0 - ok | FAIL - ng
E 8
I 8
 *	return codes: SUCCESS - ok | FAIL - ng
E 8
 */
D 8

E 8
wmesg(m, s)
register char *s, m;
{
D 4
	DEBUG(4, "wmesg '%c'", m);
	DEBUG(4, "%.25s\n", s);
	return((*Wrmsg)(m, s, Ofn));
E 4
I 4
	DEBUG(4, "wmesg '%c' ", m);
	DEBUG(4, "%s\n", s);
	return (*Wrmsg)(m, s, Ofn);
E 4
}

D 8

/***
 *	notify		mail results of command
E 8
I 8
/*
 *	mail results of command
E 8
 *
 *	return codes:  none
 */
D 8

E 8
notify(mailopt, user, file, sys, msgcode)
char *user, *file, *sys, *msgcode;
{
D 8
	char str[200];
E 8
I 8
	char str[BUFSIZ];
E 8
	int i;
	char *msg;

	if (!mailopt && *msgcode == 'Y')
		return;
	if (*msgcode == 'Y')
		msg = "copy succeeded";
	else {
		i = atoi(msgcode + 1);
		if (i < 1 || i > EM_MAX)
			i = 0;
		msg = Em_msg[i];
	}
D 4
	sprintf(str, "file %s, system %s\n%s\n",
		file, sys, msg);
	mailst(user, str, "");
E 4
I 4
	sprintf(str, "file %s!%s -- %s\n",
		sys,file, msg);
	mailst(user, str, CNULL);
E 4
	return;
}

D 8
/***
 *	lnotify(user, file, mesg)	- local notify
E 8
I 8
/*
 *	local notify
E 8
 *
 *	return code - none
 */
D 8

E 8
lnotify(user, file, mesg)
char *user, *file, *mesg;
{
	char mbuf[200];
D 4
	sprintf(mbuf, "file %s on %s\n%s\n", file, Myname, mesg);
	mailst(user, mbuf, "");
E 4
I 4
	sprintf(mbuf, "file %s!%s -- %s\n", Myname, file, mesg);
	mailst(user, mbuf, CNULL);
E 4
	return;
}

I 10
char UsingProtocol;

E 10
D 8

/***
 *	startup(role)
 *	int role;
E 8
I 8
/*
 *	converse with the remote machine, agree upon a protocol (if possible)
 *	and start the protocol.
E 8
 *
D 8
 *	startup  -  this routine will converse with the remote
 *	machine, agree upon a protocol (if possible) and start the
 *	protocol.
 *
E 8
 *	return codes:
 *		SUCCESS - successful protocol selection
 *		FAIL - can't find common or open failed
 */
D 8

E 8
startup(role)
int role;
{
	extern (*Rdmsg)(), (*Wrmsg)();
	extern char *blptcl(), fptcl();
D 4
	char msg[BUFSIZ], str[BUFSIZ];
E 4
I 4
	char msg[BUFSIZ], str[MAXFULLNAME];
E 4

	Rdmsg = Imsg;
	Wrmsg = Omsg;
	if (role == MASTER) {
		RMESG(SLTPTCL, msg, 1);
		if ((str[0] = fptcl(&msg[1])) == NULL) {
			/* no protocol match */
			WMESG(USEPTCL, NO);
D 4
			return(FAIL);
E 4
I 4
			return FAIL;
E 4
		}
		str[1] = '\0';
		WMESG(USEPTCL, str);
		if (stptcl(str) != 0)
D 4
			return(FAIL);
E 4
I 4
			return FAIL;
E 4
		DEBUG(4, "protocol %s\n", str);
I 10
		UsingProtocol = str[0];
E 10
D 4
		return(SUCCESS);
E 4
I 4
		return SUCCESS;
E 4
	}
	else {
		WMESG(SLTPTCL, blptcl(str));
		RMESG(USEPTCL, msg, 1);
		if (msg[1] == 'N') {
D 4
			return(FAIL);
E 4
I 4
			return FAIL;
E 4
		}

		if (stptcl(&msg[1]) != 0)
D 4
			return(FAIL);
E 4
I 4
			return FAIL;
E 4
		DEBUG(4, "Protocol %s\n", msg);
I 10
		UsingProtocol = msg[1];
E 10
D 4
		return(SUCCESS);
E 4
I 4
		return SUCCESS;
E 4
	}
}

D 8

/*******
 *	char
 *	fptcl(str)
 *	char *str;
E 8
I 8
/*
 *	choose a protocol from the input string (str) and return the it
E 8
 *
D 8
 *	fptcl  -  this routine will choose a protocol from
 *	the input string (str) and return the found letter.
 *
E 8
 *	return codes:
 *		'\0'  -  no acceptable protocol
 *		any character  -  the chosen protocol
 */
D 8

E 8
char
fptcl(str)
register char *str;
{
	register struct Proto *p;
I 3
D 4
	struct stat stbuf;
E 4
I 4
D 8
	extern char *Flds[];
E 8
I 8
	extern char LineType[];
E 8
E 4
E 3

I 3
D 4
	if (fstat(Ifn, &stbuf) < 0)
		return ('\0');
E 4
E 3
	for (p = Ptbl; p->P_id != '\0'; p++) {
I 3
D 4
		/*
		 * Hack to avoid using network protocol if not connected
		 * to network.
		 */
		if ((stbuf.st_mode & S_IFMT) != S_IFSOCK && p->P_id == 'n')
E 4
I 4
D 6
#ifdef BSDTCP
		if (!IsTcpIp && p->P_id == 't')	/* Only use 't' on TCP/IP */
E 6
I 6
#ifdef TCPIP
		/* Only use 't' on TCP/IP */
D 8
		if (p->P_id == 't' && strcmp("TCP", Flds[F_LINE]))
E 8
I 8
		if (p->P_id == 't' && strcmp("TCP", LineType))
E 8
E 6
E 4
			continue;
I 4
D 6
#endif BSDTCP
E 6
I 6
#endif TCPIP
#ifdef PAD
E 6
		/* only use 'f' protocol on PAD */
D 6
		if (strcmp("PAD", Flds[F_LINE]) && p->P_id == 'f')
E 6
I 6
D 8
		if (p->P_id == 'f' && strcmp("PAD", Flds[F_LINE]))
E 8
I 8
		if (p->P_id == 'f' && strcmp("PAD", LineType))
E 8
E 6
			continue;
I 6
#endif PAD
E 6
E 4
E 3
		if (index(str, p->P_id) != NULL) {
D 4
			return(p->P_id);
E 4
I 4
			return p->P_id;
E 4
		}
	}

D 4
	return('\0');
E 4
I 4
	return '\0';
E 4
}

D 8

/***
 *	char *
 *	blptcl(str)
 *	char *str;
 *
 *	blptcl  -  this will build a string of the
 *	letters of the available protocols and return
 *	the string (str).
 *
 *	return:
 *		a pointer to string (str)
E 8
I 8
/*
 *	build a string of the letters of the available protocols 
E 8
 */
D 8

E 8
char *
blptcl(str)
register char *str;
{
	register struct Proto *p;
	register char *s;
I 3
D 4
	struct stat stbuf;
E 4
E 3

D 3
	for (p = Ptbl, s = str; (*s++ = p->P_id) != '\0'; p++);
E 3
I 3
D 4
	if (fstat(Ofn, &stbuf) < 0)
		stbuf.st_mode = S_IFCHR;
	for (p = Ptbl, s = str; p->P_id != '\0'; p++) {
		/*
		 * Hack to avoid using network protocol if not connected
		 * to network.
		 */
		if ((stbuf.st_mode & S_IFMT) != S_IFSOCK && p->P_id == 'n')
			continue;
		*s++ = p->P_id;
	}
E 4
I 4
	for (p = Ptbl, s = str; (*s++ = p->P_id) != '\0'; p++)
		;
E 4
	*s = '\0';
D 4

E 3
	return(str);
E 4
I 4
	return str;
E 4
}

D 8
/***
 *	stptcl(c)
 *	char *c;
 *
 *	stptcl  -  this routine will set up the six routines
E 8
I 8
/*
 *	this routine will set up the six routines
E 8
 *	(Rdmsg, Wrmsg, Rddata, Wrdata, Turnon, Turnoff) for the
 *	desired protocol.
 *
 *	return codes:
 *		SUCCESS - ok
 *		FAIL - no find or failed to open
 *
 */
D 8

E 8
stptcl(c)
register char *c;
{
	register struct Proto *p;

	for (p = Ptbl; p->P_id != '\0'; p++) {
		if (*c == p->P_id) {
			/* found protocol - set routines */
			Rdmsg = p->P_rdmsg;
			Wrmsg = p->P_wrmsg;
			Rddata = p->P_rddata;
			Wrdata = p->P_wrdata;
			Turnon = p->P_turnon;
			Turnoff = p->P_turnoff;
D 4
			if ((*Turnon)() != 0)
				return(FAIL);
E 4
I 4
			if ((*Turnon)() != SUCCESS)
				return FAIL;
E 4
			DEBUG(4, "Proto started %c\n", *c);
D 4
			return(SUCCESS);
E 4
I 4
			return SUCCESS;
E 4
		}
	}
	DEBUG(4, "Proto start-fail %c\n", *c);
D 4
	return(FAIL);
E 4
I 4
	return FAIL;
E 4
}

D 8
/***
 *	putinpub	put file in public place
 *			if successful, filename is modified
E 8
I 8
/*
 *	put file in public place. if successful, filename is modified
E 8
 *
D 8
 *	return code  0 | FAIL
E 8
I 8
 *	return code  SUCCESS | FAIL
E 8
 */

putinpub(file, tmp, user)
D 8
register char *file, *user, *tmp;
E 8
I 8
register char *file, *tmp, *user;
E 8
{
	char fullname[MAXFULLNAME];
	char *lastpart();
	int status;

	sprintf(fullname, "%s/%s/", PUBDIR, user);
	if (mkdirs(fullname) != 0) {
		/* can not make directories */
I 8
		DEBUG(1, "Cannot mkdirs(%s)\n", fullname);
E 8
D 4
		return(FAIL);
E 4
I 4
		return FAIL;
E 4
	}
	strcat(fullname, lastpart(file));
	status = xmv(tmp, fullname);
	if (status == 0) {
		strcpy(file, fullname);
		chmod(subfile(fullname), BASEMODE);
	}
D 4
	return(status);
E 4
I 4
	return status;
E 4
}

D 8
/***
 *	unlinkdf(file)	- unlink D. file
E 8
I 8
/*
 *	unlink D. file
E 8
 *
 *	return code - none
 */

unlinkdf(file)
register char *file;
{
	if (strlen(file) > 6)
		unlink(subfile(file));
	return;
}

D 8
/***
 *	arrived - notify receiver of arrived file
E 8
I 8
/*
 *	notify receiver of arrived file
E 8
 *
 *	return code - none
 */
D 8

E 8
arrived(opt, file, nuser, rmtsys, rmtuser)
char *file, *nuser, *rmtsys, *rmtuser;
{
	char mbuf[200];

	if (!opt)
		return;
	sprintf(mbuf, "%s from %s!%s arrived\n", file, rmtsys, rmtuser);
D 4
	mailst(nuser, mbuf, "");
E 4
I 4
	mailst(nuser, mbuf, CNULL);
E 4
	return;
I 6
}

nullf()
{
	return SUCCESS;
E 6
}
E 1
