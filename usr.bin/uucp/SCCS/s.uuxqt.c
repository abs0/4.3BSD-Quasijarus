h13605
s 00021/00017/00762
d D 5.12 88/05/13 08:11:54 rick 12 11
c didnt use proper logfile if LOGBYSITE defined
e
s 00001/00000/00778
d D 5.11 88/05/04 13:55:42 rick 11 10
c initialize Rmtname in case of early error
e
s 00053/00028/00725
d D 5.10 88/04/05 12:27:39 rick 10 9
c use syslog for errors, use getopt, export UU_MACHINE to environment
e
s 00053/00017/00700
d D 5.9 88/02/24 20:06:19 rick 9 8
c make more robust. increase buffersizes . handle corrupt files
e
s 00012/00007/00705
d D 5.8 86/01/24 13:20:23 bloom 8 7
c still more fixes and changes from rick@seismo
e
s 00007/00002/00705
d D 5.7 85/10/09 17:08:34 bloom 7 6
c still more fixes from rick@seismo
e
s 00003/00024/00704
d D 5.6 85/06/23 13:58:04 bloom 6 5
c fixes from rick adams
e
s 00111/00064/00617
d D 5.5 85/04/10 15:23:40 ralph 5 4
c more changes from rick adams.
e
s 00028/00013/00653
d D 5.4 85/01/28 10:27:33 ralph 4 3
c security bug fix from rick@seismo
e
s 00209/00074/00457
d D 5.3 85/01/22 14:13:57 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00001/00001/00530
d D 5.2 83/07/02 18:06:02 sam 2 1
c include fixes
e
s 00531/00000/00000
d D 5.1 83/07/02 17:58:06 sam 1 0
c date and time created 83/07/02 17:58:06 by sam
e
u
U
t
T
I 1
#ifndef lint
D 10
static char sccsid[] = "%W% (Berkeley) %G%";
E 10
I 10
static char sccsid[] = "%W%	(Berkeley) %G%";
E 10
#endif

#include "uucp.h"
D 5
#include <sys/types.h>
E 5
#include <sys/stat.h>
#ifdef	NDIR
#include "ndir.h"
#else
D 2
#include <dir.h>
E 2
I 2
#include <sys/dir.h>
E 2
#endif
I 3
#include <signal.h>
E 3

I 4
D 5
#define BADCHARS	"&^|(`\\<>;"
E 5
I 5
#define BADCHARS	"&^|(`\\<>;\"{}\n'"
#define RECHECKTIME	60*10	/* 10 minutes */
E 5

E 4
#define APPCMD(d) {\
char *p;\
D 3
for (p = d; *p != '\0';) *cmdp++ = *p++;\
*cmdp++ = ' ';\
*cmdp = '\0';}
E 3
I 3
for (p = d; *p != '\0';) *cmdp++ = *p++; *cmdp++ = ' '; *cmdp = '\0';}
E 3

I 9
extern char Filent[LLEN][NAMESIZE];

E 9
/*
 *	uuxqt will execute commands set up by a uux command,
 *	usually from a remote machine - set by uucp.
 */

#define	NCMDS	50
D 3
char *Cmds[NCMDS];
E 3
I 3
char *Cmds[NCMDS+1];
int Notify[NCMDS+1];
#define	NT_YES	0	/* if should notify on execution */
#define	NT_ERR	1	/* if should notify if non-zero exit status (-z equivalent) */
#define	NT_NO	2	/* if should not notify ever (-n equivalent) */
E 3

I 3
extern int Nfiles;
I 4
D 5
char *sindex();
E 5
I 5
D 6
char *strpbrk();
E 6
E 5
E 4

I 5
int TransferSucceeded = 1;
E 5
E 3
int notiok = 1;
int nonzero = 0;

I 7
struct timeb Now;

E 7
D 3
char PATH[MAXFULLNAME] = "PATH=/bin:/usr/bin";
E 3
I 3
D 5
#ifdef SIGCHLD
#include <sys/wait.h>
reapchild()
{
	union wait status;
E 5
I 5
char PATH[MAXFULLNAME] = "PATH=/bin:/usr/bin:/usr/ucb";
I 10
char UU_MACHINE[MAXFULLNAME];
E 10
char Shell[MAXFULLNAME];
char HOME[MAXFULLNAME];
E 5

D 5
	while (wait3(&status,WNOHANG,0) > 0)
		;
}
#endif SIGCHLD
E 5
I 5
extern char **environ;
char *nenv[] = {
	PATH,
	Shell,
	HOME,
I 10
	UU_MACHINE,
E 10
	0
};
E 5

D 5
char PATH[MAXFULLNAME] = "PATH=/bin:/usr/bin:/usr/ucb";
E 5
E 3
/*  to remove restrictions from uuxqt
 *  define ALLOK 1
 *
 *  to add allowable commands, add to the file CMDFILE
 *  A line of form "PATH=..." changes the search path
 */
D 3


E 3
main(argc, argv)
char *argv[];
{
D 9
	char xcmd[MAXFULLNAME];
E 9
I 9
	char xcmd[BUFSIZ*2];
E 9
	int argnok;
D 3
	char xfile[MAXFULLNAME], user[32], buf[BUFSIZ];
	char lbuf[30];
E 3
I 3
	int notiflg;
D 9
	char xfile[MAXFULLNAME], user[MAXFULLNAME], buf[BUFSIZ];
E 9
I 9
	char xfile[MAXFULLNAME], user[MAXFULLNAME], buf[BUFSIZ*2];
E 9
	char lbuf[MAXFULLNAME];
E 3
	char cfile[NAMESIZE], dfile[MAXFULLNAME];
	char file[NAMESIZE];
	char fin[MAXFULLNAME], sysout[NAMESIZE], fout[MAXFULLNAME];
	register FILE *xfp, *fp;
	FILE *dfp;
	char path[MAXFULLNAME];
D 9
	char cmd[BUFSIZ];
E 9
I 9
	char cmd[BUFSIZ*2];
E 9
D 3
	/* set size of prm to something large -- cmcl2!salkind */
E 3
	char *cmdp, prm[1000], *ptr;
	char *getprm(), *lastpart();
D 3
	int uid, ret, badfiles;
E 3
I 3
D 10
	int uid, ret, ret2, badfiles;
E 10
I 10
	int uid, ret, badfiles;
E 10
E 3
	register int i;
	int stcico = 0;
I 5
	time_t xstart, xnow;
E 5
	char retstat[30];
I 5
D 10
	char **ep;
E 10
I 10
	extern char *optarg;
	extern int optind;
E 10
E 5
D 3
	int orig_uid = getuid();
E 3

	strcpy(Progname, "uuxqt");
	uucpname(Myname);
I 11
	strcpy(Rmtname, Myname);
E 11

D 3
	/* Try to run as uucp -- rti!trt */
	setgid(getegid());
	setuid(geteuid());
E 3
I 3
D 5
#ifdef SIGCHLD
	signal(SIGCHLD, reapchild);
#endif SIGCHLD
E 3

E 5
	umask(WFMASK);
	Ofn = 1;
	Ifn = 0;
D 10
	while (argc>1 && argv[1][0] == '-') {
		switch(argv[1][1]){
E 10
I 10
	while ((i = getopt(argc, argv, "x:S:")) != EOF) 
		switch(i) {
E 10
		case 'x':
D 3
			chkdebug(orig_uid);
E 3
I 3
			chkdebug();
E 3
D 10
			Debug = atoi(&argv[1][2]);
E 10
I 10
			Debug = atoi(optarg);
E 10
			if (Debug <= 0)
				Debug = 1;
			break;
I 9
		case 'S':
D 10
			Spool = &argv[1][2];
E 10
I 10
			Spool = optarg;
E 10
			DEBUG(1, "Spool set to %s", Spool);
			break;
I 10
		case '?':
E 10
E 9
		default:
D 10
			fprintf(stderr, "unknown flag %s\n", argv[1]);
E 10
I 10
			fprintf(stderr, "unknown flag %s\n", argv[optind-1]);
E 10
				break;
		}
D 10
		--argc;  argv++;
	}
E 10

D 5
	DEBUG(4, "\n\n** %s **\n", "START");
E 5
I 5
	DEBUG(4, "\n\n** START **\n", CNULL);
E 5
D 3
	subchdir(Spool);
E 3
I 3
D 10
	ret = subchdir(Spool);
	ASSERT(ret >= 0, "CHDIR FAILED", Spool, ret);
E 10
I 10
	if (subchdir(Spool) < 0) {
		syslog(LOG_WARNING, "chdir(%s) failed: %m", Spool);
		cleanup(1);
	}
E 10
E 3
	strcpy(Wrkdir, Spool);
	uid = getuid();
D 9
	guinfo(uid, User, path);
E 9
I 9
	if (guinfo(uid, User, path) != SUCCESS) {
D 10
		assert("Can't find username for ", "uid", uid);
E 10
I 10
		syslog(LOG_WARNING, "Can't find username for uid %d", uid);
E 10
		DEBUG(1, "Using username", "uucp");
		strcpy(User, "uucp");
	}
E 9
I 3
D 5
	/* Try to run as uucp -- rti!trt */
E 5
	setgid(getegid());
	setuid(geteuid());

E 3
	DEBUG(4, "User - %s\n", User);
D 6
	if (ulockf(X_LOCK, (time_t)  X_LOCKTIME) != 0)
E 6
I 6
	if (ulockf(X_LOCK, X_LOCKTIME) != 0)
E 6
		exit(0);

	fp = fopen(CMDFILE, "r");
	if (fp == NULL) {
D 3
		/* Fall-back if CMDFILE missing. Sept 1982, rti!trt */
		logent("CAN'T OPEN", CMDFILE);
E 3
I 3
		logent(CANTOPEN, CMDFILE);
E 3
		Cmds[0] = "rmail";
		Cmds[1] = "rnews";
		Cmds[2] = "ruusend";
		Cmds[3] = NULL;
		goto doprocess;
	}
	DEBUG(5, "%s opened\n", CMDFILE);
D 3
	for (i=0; i<NCMDS-1 && cfgets(xcmd, sizeof(xcmd), fp) != NULL; i++) {
		xcmd[strlen(xcmd)-1] = '\0';
E 3
I 3
	for (i=0; i<NCMDS && cfgets(xcmd, sizeof(xcmd), fp) != NULL; i++) {
		int j;
		/* strip trailing whitespace */
		for (j = strlen(xcmd)-1; j >= 0; --j)
			if (xcmd[j] == '\n' || xcmd[j] == ' ' || xcmd[j] == '\t')
				xcmd[j] = '\0';
			else
				break;
		/* look for imbedded whitespace */
		for (; j >= 0; --j)
			if (xcmd[j] == '\n' || xcmd[j] == ' ' || xcmd[j] == '\t')
				break;
		/* skip this entry if it has embedded whitespace */
		/* This defends against a bad PATH=, for example */
		if (j >= 0) {
			logent(xcmd, "BAD WHITESPACE");
			continue;
		}
E 3
		if (strncmp(xcmd, "PATH=", 5) == 0) {
			strcpy(PATH, xcmd);
D 3
			i--; /* kludge */
E 3
I 3
			i--;	/*kludge */
E 3
			continue;
		}
		DEBUG(5, "xcmd = %s\n", xcmd);
D 3
		Cmds[i] = malloc((unsigned)(strlen(xcmd)+1));
E 3
I 3

		if ((ptr = index(xcmd, ',')) != NULL) {
			*ptr++ = '\0';
			if (strncmp(ptr, "Err", 3) == SAME)
				Notify[i] = NT_ERR;
			else if (strcmp(ptr, "No") == SAME)
				Notify[i] = NT_NO;
			else
				Notify[i] = NT_YES;
		} else
			Notify[i] = NT_YES;
		if ((Cmds[i] = malloc((unsigned)(strlen(xcmd)+1))) == NULL) {
			DEBUG(1, "MALLOC FAILED", CNULL);
			break;
		}
E 3
		strcpy(Cmds[i], xcmd);
	}
D 3
	Cmds[i] = 0;
E 3
I 3
	Cmds[i] = CNULL;
E 3
	fclose(fp);

doprocess:
I 5

	(void) sprintf(HOME, "HOME=%s", Spool);
	(void) sprintf(Shell, "SHELL=%s", SHELL);
	environ = nenv; /* force use if our environment */

	DEBUG(11,"path = %s\n", getenv("PATH"));

E 5
D 3
	DEBUG(4, "process %s\n", "");
E 3
I 3
	DEBUG(4, "process %s\n", CNULL);
I 9

E 9
I 5
	time(&xstart);
E 5
E 3
	while (gtxfile(xfile) > 0) {
D 3
		ultouch();	/* rti!trt */
E 3
I 3
D 7
		ultouch();
E 7
		/* if /etc/nologin exists, exit cleanly */
I 7
#if defined(BSD4_2) || defined(USG)
		if (access(NOLOGIN) == 0) {
#else !BSD4_2 && ! USG
		ultouch();
E 7
		if (nologinflag) {
I 7
#endif !BSD4_2 && !USG
E 7
			logent(NOLOGIN, "UUXQT SHUTDOWN");
			if (Debug)
				logent("debugging", "continuing anyway");
			else
				break;
		}
E 3
		DEBUG(4, "xfile - %s\n", xfile);

		xfp = fopen(subfile(xfile), "r");
D 3
		ASSERT(xfp != NULL, "CAN'T OPEN", xfile, 0);
E 3
I 3
D 10
		ASSERT(xfp != NULL, CANTOPEN, xfile, 0);
E 10
I 10
		if (xfp == NULL) {
			syslog(LOG_ERR, "fopen(%s) failed: %m", subfile(xfile));
			cleanup(1);
		}
E 10
E 3

		/*  initialize to default  */
		strcpy(user, User);
D 3
		strcpy(fin, "/dev/null");
		strcpy(fout, "/dev/null");
E 3
I 3
		strcpy(fin, DEVNULL);
		strcpy(fout, DEVNULL);
E 3
D 6
		sprintf(sysout, "%.7s", Myname);
E 6
I 6
		strcpy(sysout, Myname);
E 6
D 3
		badfiles = 0;	/* this was missing -- rti!trt */
E 3
I 3
		badfiles = 0;
E 3
		while (fgets(buf, BUFSIZ, xfp) != NULL) {
I 9
D 12
	if(buf[0] != '\0' && buf[0] != '#' &&
		buf[1] != ' ' && buf[1] != '\0' && buf[1] != '\n') {
		char *bnp, cfilename[BUFSIZ];
		DEBUG(4, "uuxqt: buf = %s\n", buf);
		bnp = rindex(xfile, '/');
		sprintf(cfilename, "%s/%s", CORRUPT,
			bnp ? bnp + 1 : xfile);
		DEBUG(4, "uuxqt: move %s to ", xfile);
		DEBUG(4, "%s\n", cfilename);
		xmv(xfile, cfilename);
D 10
		assert("X. FILE CORRUPTED", xfile, 0);
E 10
I 10
		syslog(LOG_WARNING, "%s: X. FILE CORRUPTED", xfile);
E 10
		fclose(xfp);
		goto doprocess;
		
	}
E 12
I 12
			if(buf[0] != '\0' && buf[0] != '#' &&
			    buf[1] != ' ' && buf[1] != '\0' && buf[1] != '\n') {
				char *bnp, cfilename[BUFSIZ];
				DEBUG(4, "uuxqt: buf = %s\n", buf);
				bnp = rindex(xfile, '/');
				sprintf(cfilename, "%s/%s", CORRUPT,
					bnp ? bnp + 1 : xfile);
				DEBUG(4, "uuxqt: move %s to ", xfile);
				DEBUG(4, "%s\n", cfilename);
				xmv(xfile, cfilename);
				syslog(LOG_WARNING, "%s: X. FILE CORRUPTED",
					xfile);
				fclose(xfp);
				goto doprocess;
			}
E 12
E 9
			switch (buf[0]) {
D 12
			case X_USER:
E 12
I 12
			case X_USER: {
				char ORmtname[MAXFULLNAME];
				strcpy(ORmtname, Rmtname);
E 12
D 3
				sscanf(&buf[1], "%s%s", user, Rmtname);
E 3
I 3
				sscanf(&buf[1], "%s %s", user, Rmtname);
I 10
				sprintf(UU_MACHINE, "UU_MACHINE=%s", Rmtname);
E 10
E 3
D 12
				break;
E 12
I 12
				if (strcmp(ORmtname, Rmtname) != 0)
					logcls();
				break;}
E 12
I 3
			case X_RETURNTO:
				sscanf(&buf[1], "%s", user);
				break;
E 3
			case X_STDIN:
				sscanf(&buf[1], "%s", fin);
				i = expfile(fin);
				/* rti!trt: do not check permissions of
				 * vanilla spool file */
				if (i != 0
				 && (chkpth("", "", fin) || anyread(fin) != 0))
					badfiles = 1;
				break;
			case X_STDOUT:
				sscanf(&buf[1], "%s%s", fout, sysout);
D 6
				sysout[7] = '\0';
E 6
I 6
				sysout[MAXBASENAME] = '\0';
E 6
				/* rti!trt: do not check permissions of
				 * vanilla spool file.  DO check permissions
				 * of writing on a non-vanilla file */
				i = 1;
				if (fout[0] != '~' || prefix(sysout, Myname))
					i = expfile(fout);
				if (i != 0
				 && (chkpth("", "", fout)
					|| chkperm(fout, (char *)1)))
					badfiles = 1;
				break;
			case X_CMD:
				strcpy(cmd, &buf[2]);
				if (*(cmd + strlen(cmd) - 1) == '\n')
					*(cmd + strlen(cmd) - 1) = '\0';
				break;
			case X_NONOTI:
				notiok = 0;
				break;
			case X_NONZERO:
				nonzero = 1;
				break;
			default:
				break;
			}
		}

		fclose(xfp);
		DEBUG(4, "fin - %s, ", fin);
		DEBUG(4, "fout - %s, ", fout);
		DEBUG(4, "sysout - %s, ", sysout);
		DEBUG(4, "user - %s\n", user);
		DEBUG(4, "cmd - %s\n", cmd);

		/*  command execution  */
D 3
		if (strcmp(fout, "/dev/null") == SAME)
			strcpy(dfile,"/dev/null");
E 3
I 3
		if (strcmp(fout, DEVNULL) == SAME)
			strcpy(dfile,DEVNULL);
E 3
		else
			gename(DATAPRE, sysout, 'O', dfile);

		/* expand file names where necessary */
		expfile(dfile);
D 5
		strcpy(buf, PATH);
D 3
		strcat(buf, ";export PATH;");
E 3
I 3
		strcat(buf, " ");
E 3
		cmdp = buf + strlen(buf);
E 5
I 5
		cmdp = buf;
E 5
		ptr = cmd;
		xcmd[0] = '\0';
		argnok = 0;
		while ((ptr = getprm(ptr, prm)) != NULL) {
			if (prm[0] == ';' || prm[0] == '^'
			  || prm[0] == '&'  || prm[0] == '|') {
				xcmd[0] = '\0';
				APPCMD(prm);
				continue;
			}

D 3
			if ((argnok = argok(xcmd, prm)) != 0) 
E 3
I 3
			if ((argnok = argok(xcmd, prm)) != SUCCESS)
E 3
				/*  command not valid  */
				break;

			if (prm[0] == '~')
				expfile(prm);
			APPCMD(prm);
		}
I 3
		/*
		 * clean up trailing ' ' in command.
		 */
		if (cmdp > buf && cmdp[0] == '\0' && cmdp[-1] == ' ')
			*--cmdp = '\0';
I 4
D 5
		if (sindex(user, BADCHARS) != NULL) {
E 5
I 5
D 8
		if (strpbrk(user, BADCHARS) != NULL) {
E 5
			sprintf(lbuf, "%s INVALID CHARACTER IN USERNAME", user);
			logent(cmd, lbuf);
			strcpy(user, "postmaster");
		}
E 8
E 4
E 3
		if (argnok || badfiles) {
			sprintf(lbuf, "%s XQT DENIED", user);
			logent(cmd, lbuf);
			DEBUG(4, "bad command %s\n", prm);
			notify(user, Rmtname, cmd, "DENIED");
			goto rmfiles;
		}
		sprintf(lbuf, "%s XQT", user);
		logent(buf, lbuf);
		DEBUG(4, "cmd %s\n", buf);

		mvxfiles(xfile);
D 3
		subchdir(XQTDIR);
		ret = shio(buf, fin, dfile, (char *)NULL);
/* watcgl.11, dmmartindale, signal and exit values were reversed */
E 3
I 3
D 10
		ret = subchdir(XQTDIR);
		ASSERT(ret >= 0, "CHDIR FAILED", XQTDIR, ret);
E 10
I 10
		if (subchdir(XQTDIR) < 0) {
			syslog(LOG_ERR, "chdir(%s) failed: %m", XQTDIR);
			cleanup(1);
		}
E 10
D 5
		ret = shio(buf, fin, dfile, CNULL);
E 5
I 5
		ret = shio(buf, fin, dfile);
E 5
E 3
		sprintf(retstat, "signal %d, exit %d", ret & 0377,
		  (ret>>8) & 0377);
		if (strcmp(xcmd, "rmail") == SAME)
			notiok = 0;
		if (strcmp(xcmd, "rnews") == SAME)
			nonzero = 1;
D 3
		 if (notiok && (!nonzero || (nonzero && ret != 0)))
E 3
I 3
		notiflg = chknotify(xcmd);
		if (notiok && notiflg != NT_NO &&
		   (ret != 0 || (!nonzero && notiflg == NT_YES)))
E 3
			notify(user, Rmtname, cmd, retstat);
		else if (ret != 0 && strcmp(xcmd, "rmail") == SAME) {
			/* mail failed - return letter to sender  */
D 3
			retosndr(user, Rmtname, fin);
			sprintf(buf, "ret (%o) from %s!%s", ret, Rmtname, user);
E 3
I 3
#ifdef	DANGEROUS
			/* NOT GUARANTEED SAFE!!! */
			if (!nonzero)
				retosndr(user, Rmtname, fin);
#else
			notify(user, Rmtname, cmd, retstat);
#endif
			sprintf(buf, "%s (%s) from %s!%s", buf, retstat, Rmtname, user);
E 3
			logent("MAIL FAIL", buf);
		}
		DEBUG(4, "exit cmd - %d\n", ret);
D 3
		subchdir(Spool);
E 3
I 3
D 10
		ret2 = subchdir(Spool);
		ASSERT(ret2 >= 0, "CHDIR FAILED", Spool, ret);
E 10
I 10
		if (subchdir(Spool) < 0) {
			syslog(LOG_ERR, "chdir(%s) failed: %m", Spool);
			cleanup(1);
		}
E 10
E 3
		rmxfiles(xfile);
		if (ret != 0) {
			/*  exit status not zero */
			dfp = fopen(subfile(dfile), "a");
D 3
			ASSERT(dfp != NULL, "CAN'T OPEN", dfile, 0);
E 3
I 3
D 10
			ASSERT(dfp != NULL, CANTOPEN, dfile, 0);
E 10
I 10
			if (dfp == NULL) {
				syslog(LOG_ERR, "fopen(%s) failed: %m",
					subfile(dfile));
				cleanup(1);
			}
E 10
E 3
			fprintf(dfp, "exit status %d", ret);
			fclose(dfp);
		}
D 3
		if (strcmp(fout, "/dev/null") != SAME) {
E 3
I 3
		if (strcmp(fout, DEVNULL) != SAME) {
E 3
			if (prefix(sysout, Myname)) {
				xmv(dfile, fout);
				chmod(fout, BASEMODE);
D 5
			}
			else {
E 5
I 5
			} else {
E 5
I 3
				char *cp = rindex(user, '!');
E 3
				gename(CMDPRE, sysout, 'O', cfile);
				fp = fopen(subfile(cfile), "w");
D 10
				ASSERT(fp != NULL, "OPEN", cfile, 0);
E 10
I 10
				if (fp == NULL) {
					syslog(LOG_ERR, "fopen(%s) failed: %m",
						subfile(cfile));
					cleanup(1);
				}
E 10
D 3
				fprintf(fp, "S %s %s %s - %s 0666\n",
				dfile, fout, user, lastpart(dfile));
E 3
I 3
				fprintf(fp, "S %s %s %s - %s 0666\n", dfile,
					fout, cp ? cp : user, lastpart(dfile));
E 3
				fclose(fp);
			}
		}
	rmfiles:
		xfp = fopen(subfile(xfile), "r");
D 3
		ASSERT(xfp != NULL, "CAN'T OPEN", xfile, 0);
E 3
I 3
D 10
		ASSERT(xfp != NULL, CANTOPEN, xfile, 0);
E 10
I 10
		if (xfp == NULL) {
			syslog(LOG_ERR, "fopen(%s) failed: %m",
				subfile(xfile));
			cleanup(1);
		}
E 10
E 3
		while (fgets(buf, BUFSIZ, xfp) != NULL) {
			if (buf[0] != X_RQDFILE)
				continue;
			sscanf(&buf[1], "%s", file);
			unlink(subfile(file));
		}
		unlink(subfile(xfile));
		fclose(xfp);
I 5

		/* rescan X. for new work every RECHECKTIME seconds */
		time(&xnow);
		if (xnow > (xstart + RECHECKTIME)) {
			extern int Nfiles;
			Nfiles = 0; 	/*force rescan for new work */
		}
		xstart = xnow;
E 5
	}

	if (stcico)
		xuucico("");
	cleanup(0);
}


cleanup(code)
int code;
{
	logcls();
	rmlock(CNULL);
I 3
#ifdef	VMS
	/*
	 *	Since we run as a BATCH job we must wait for all processes to
	 *	to finish
	 */
D 5
	while(wait(0) != -1);
E 5
I 5
	while(wait(0) != -1)
		;
E 5
#endif VMS
E 3
	exit(code);
}


D 5
/*******
 *	gtxfile(file)	get a file to execute
 *	char *file;
E 5
I 5
/*
 *	get a file to execute
E 5
 *
 *	return codes:  0 - no file  |  1 - file to execute
D 3
 * Mod to recheck for X-able files. Sept 1982, rti!trt.
 * Suggested by utzoo.2458 (utzoo!henry)
 * Uses iswrk/gtwrkf to keep files in sequence, May 1983.
E 3
 */

gtxfile(file)
register char *file;
{
	char pre[3];
D 3
	register int rechecked;
E 3
I 3
D 9
	int rechecked;
E 9
I 9
	register int rechecked, i;
E 9
	time_t ystrdy;		/* yesterday */
D 6
	extern time_t time();
E 6
	struct stat stbuf;	/* for X file age */
E 3

	pre[0] = XQTPRE;
	pre[1] = '.';
	pre[2] = '\0';
	rechecked = 0;
retry:
D 9
	if (!gtwrkf(Spool, file)) {
E 9
I 9
	if (Nfiles-- <= 0) {
		Nfiles = 0;
E 9
		if (rechecked)
D 3
			return(0);
E 3
I 3
			return 0;
E 3
		rechecked = 1;
D 3
		DEBUG(4, "iswrk\n", "");
E 3
I 3
		DEBUG(4, "iswrk\n", CNULL);
E 3
D 9
		if (!iswrk(file, "get", Spool, pre))
D 3
			return(0);
E 3
I 3
			return 0;
E 9
I 9
		return iswrk(file, "get", Spool, pre);
E 9
E 3
	}
I 9
	sprintf(file, "%s/%s", Spool, Filent[0]);
	for (i=0; i<Nfiles;i++)
		strcpy(Filent[i], Filent[i+1]);

E 9
	DEBUG(4, "file - %s\n", file);
D 3
#ifndef UUDIR
E 3
	/* skip spurious subdirectories */
	if (strcmp(pre, file) == SAME)
		goto retry;
D 3
#endif
E 3
	if (gotfiles(file))
D 3
		return(1);
E 3
I 3
		return 1;
	/* check for old X. file with no work files and remove them. */
	if (Nfiles > LLEN/2) {
	    time(&ystrdy);
	    ystrdy -= (4 * 3600L);		/* 4 hours ago */
	    DEBUG(4, "gtxfile: Nfiles > LLEN/2\n", CNULL);
D 9
	    while (gtwrkf(Spool, file) && !gotfiles(file)) {
E 9
I 9
	    while (Nfiles-- > 0) {
		sprintf(file, "%s/%s", Spool, Filent[0]);
		for (i=0; i<Nfiles; i++)
			strcpy(Filent[i], Filent[i+1]);

		if (gotfiles(file))
			return 1;
E 9
		if (stat(subfile(file), &stbuf) == 0)
		    if (stbuf.st_mtime <= ystrdy) {
			char *bnp, cfilename[NAMESIZE];
			DEBUG(4, "gtxfile: move %s to CORRUPT \n", file);
D 9
			unlink(subfile(file));
			bnp = rindex(subfile(file), '/');
E 9
I 9
			bnp = rindex(file, '/');
E 9
			sprintf(cfilename, "%s/%s", CORRUPT,
D 9
				bnp ? bnp + 1 : subfile(file));
			xmv(subfile(file), cfilename);
			logent(file, "X. FILE CORRUPTED");
E 9
I 9
				bnp ? bnp + 1 : file);
			xmv(file, cfilename);
D 10
			assert("X. FILE MISSING FILES", file, 0);
E 10
I 10
			syslog(LOG_WARNING, "%s: X. FILE MISSING FILES", file);
E 10
E 9
		    }
	    }
I 9
 	    Nfiles = 0;
E 9
	    DEBUG(4, "iswrk\n", CNULL);
	    if (!iswrk(file, "get", Spool, pre))
		return 0;
	}
E 3
	goto retry;
}

D 5

/***
 *	gotfiles(file)		check for needed files
 *	char *file;
E 5
I 5
/*
 *	check for needed files
E 5
 *
 *	return codes:  0 - not ready  |  1 - all files ready
 */

gotfiles(file)
register char *file;
{
	struct stat stbuf;
	register FILE *fp;
	char buf[BUFSIZ], rqfile[MAXFULLNAME];

	fp = fopen(subfile(file), "r");
	if (fp == NULL)
D 3
		return(0);
E 3
I 3
		return 0;
E 3

	while (fgets(buf, BUFSIZ, fp) != NULL) {
		DEBUG(4, "%s\n", buf);
		if (buf[0] != X_RQDFILE)
			continue;
		sscanf(&buf[1], "%s", rqfile);
		expfile(rqfile);
		if (stat(subfile(rqfile), &stbuf) == -1) {
			fclose(fp);
D 3
			return(0);
E 3
I 3
			return 0;
E 3
		}
	}

	fclose(fp);
D 3
	return(1);
E 3
I 3
	return 1;
E 3
}


D 5
/***
 *	rmxfiles(xfile)		remove execute files to x-directory
 *	char *xfile;
 *
 *	return codes - none
E 5
I 5
/*
 *	remove execute files to x-directory
E 5
 */

rmxfiles(xfile)
register char *xfile;
{
	register FILE *fp;
	char buf[BUFSIZ], file[NAMESIZE], tfile[NAMESIZE];
	char tfull[MAXFULLNAME];

	if((fp = fopen(subfile(xfile), "r")) == NULL)
		return;

	while (fgets(buf, BUFSIZ, fp) != NULL) {
		if (buf[0] != X_RQDFILE)
			continue;
		if (sscanf(&buf[1], "%s%s", file, tfile) < 2)
			continue;
		sprintf(tfull, "%s/%s", XQTDIR, tfile);
		unlink(subfile(tfull));
	}
	fclose(fp);
	return;
}


D 5
/***
 *	mvxfiles(xfile)		move execute files to x-directory
 *	char *xfile;
 *
 *	return codes - none
E 5
I 5
/*
 *	move execute files to x-directory
E 5
 */

mvxfiles(xfile)
char *xfile;
{
	register FILE *fp;
	char buf[BUFSIZ], ffile[MAXFULLNAME], tfile[NAMESIZE];
	char tfull[MAXFULLNAME];
D 10
	int ret;
E 10

	if((fp = fopen(subfile(xfile), "r")) == NULL)
		return;

	while (fgets(buf, BUFSIZ, fp) != NULL) {
		if (buf[0] != X_RQDFILE)
			continue;
		if (sscanf(&buf[1], "%s%s", ffile, tfile) < 2)
			continue;
		expfile(ffile);
		sprintf(tfull, "%s/%s", XQTDIR, tfile);
D 3
		/* duke!rti, ncsu!mcm: use xmv, not link(II) */
E 3
		unlink(subfile(tfull));
D 10
		ret = xmv(ffile, tfull);
D 3
		ASSERT(ret == 0, "XQTDIR ERROR", "", ret);
E 3
I 3
		ASSERT(ret == 0, "XQTDIR ERROR", CNULL, ret);
E 10
I 10
		if (xmv(ffile, tfull) != 0) {
			syslog(LOG_WARNING, "xmv(%s,%s) failed: %m",
				ffile, tfull);
			cleanup(1);
		}
E 10
E 3
	}
	fclose(fp);
D 5
	return;
E 5
}

D 5

/***
 *	argok(xc, cmd)		check for valid command/argumanet
 *			*NOTE - side effect is to set xc to the
 *				command to be executed.
 *	char *xc, *cmd;
E 5
I 5
/*
 *	check for valid command/argument	
 *	*NOTE - side effect is to set xc to the	command to be executed.
E 5
 *
 *	return 0 - ok | 1 nok
 */

argok(xc, cmd)
register char *xc, *cmd;
{
	register char **ptr;

#ifndef ALLOK
D 4
	/* don't allow sh command strings `....` */
	/* don't allow redirection of standard in or out  */
	/* don't allow other funny stuff */
	/* but there are probably total holes here */
	/* post-script.  ittvax!swatt has a uuxqt that solves this. */
	/* This version of uuxqt will shortly disappear */
	if (index(cmd, '`') != NULL
	  || index(cmd, '>') != NULL
	  || index(cmd, ';') != NULL
	  || index(cmd, '^') != NULL
	  || index(cmd, '&') != NULL
	  || index(cmd, '|') != NULL
D 3
	  || index(cmd, '<') != NULL)
		return(1);
#endif
E 3
I 3
	  || index(cmd, '<') != NULL) {
E 4
I 4
D 5
	if (sindex(cmd, BADCHARS) != NULL) {
E 5
I 5
	if (strpbrk(cmd, BADCHARS) != NULL) {
E 5
E 4
		DEBUG(1,"MAGIC CHARACTER FOUND\n", CNULL);
I 5
		logent(cmd, "NASTY MAGIC CHARACTER FOUND");
E 5
		return FAIL;
	}
#endif !ALLOK
E 3

	if (xc[0] != '\0')
D 3
		return(0);
E 3
I 3
		return SUCCESS;
E 3

#ifndef ALLOK
	ptr = Cmds;
I 3
	DEBUG(9, "Compare %s and\n", cmd);
E 3
	while(*ptr != NULL) {
I 3
		DEBUG(9, "\t%s\n", *ptr);
E 3
		if (strcmp(cmd, *ptr) == SAME)
			break;
D 3
	ptr++;
E 3
I 3
		ptr++;
E 3
	}
D 3
	if (*ptr == NULL)
		return(1);
E 3
I 3
	if (*ptr == NULL) {
		DEBUG(1,"COMMAND NOT FOUND\n", CNULL);
		return FAIL;
	}
E 3
#endif
	strcpy(xc, cmd);
D 3
	return(0);
E 3
I 3
	DEBUG(9, "MATCHED %s\n", xc);
	return SUCCESS;
E 3
}


D 5
/***
I 3
 *	chknotify(cmd)	check if notification should be sent for
 *			successful execution of cmd
 *	char *cmd;
E 5
I 5
/*
 *	if notification should be sent for successful execution of cmd
E 5
 *
 *	return NT_YES - do notification
 *	       NT_ERR - do notification if exit status != 0
 *	       NT_NO  - don't do notification ever
 */

chknotify(cmd)
char *cmd;
{
	register char **ptr;
	register int *nptr;

	ptr = Cmds;
	nptr = Notify;
	while (*ptr != NULL) {
		if (strcmp(cmd, *ptr) == SAME)
			return *nptr;
		ptr++;
		nptr++;
	}
	return NT_YES;		/* "shouldn't happen" */
}



D 5
/***
E 3
 *	notify	send mail to user giving execution results
 *	return code - none
 *	This program assumes new mail command - send remote mail
E 5
I 5
/*
 *	send mail to user giving execution results
E 5
 */

notify(user, rmt, cmd, str)
char *user, *rmt, *cmd, *str;
{
D 9
	char text[MAXFULLNAME];
E 9
I 9
	char text[BUFSIZ*2];
E 9
	char ruser[MAXFULLNAME];

I 8
	if (strpbrk(user, BADCHARS) != NULL) {
		char lbuf[MAXFULLNAME];
		sprintf(lbuf, "%s INVALID CHARACTER IN USERNAME", user);
		logent(cmd, lbuf);
		strcpy(user, "postmaster");
	}
E 8
D 3
	sprintf(text, "uuxqt cmd (%.50s) status (%s)", cmd, str);
E 3
I 3
	sprintf(text, "uuxqt cmd (%s) status (%s)", cmd, str);
E 3
	if (prefix(rmt, Myname))
		strcpy(ruser, user);
	else
		sprintf(ruser, "%s!%s", rmt, user);
D 3
	mailst(ruser, text, "");
E 3
I 3
	mailst(ruser, text, CNULL);
E 3
D 8
	return;
E 8
}

D 5
/***
 *	retosndr - return mail to sender
E 5
I 5
/*
 *	return mail to sender
E 5
 *
D 5
 *	return code - none
E 5
 */
D 8

E 8
retosndr(user, rmt, file)
char *user, *rmt, *file;
{
D 3
	char ruser[100];
E 3
I 3
	char ruser[MAXFULLNAME];
E 3

I 8
	if (strpbrk(user, BADCHARS) != NULL) {
		char lbuf[MAXFULLNAME];
		sprintf(lbuf, "%s INVALID CHARACTER IN USERNAME", user);
		logent(file, lbuf);
		strcpy(user, "postmaster");
	}
E 8
	if (strcmp(rmt, Myname) == SAME)
		strcpy(ruser, user);
	else
		sprintf(ruser, "%s!%s", rmt, user);

	if (anyread(file) == 0)
		mailst(ruser, "Mail failed.  Letter returned to sender.\n", file);
	else
D 3
		mailst(ruser, "Mail failed.  Letter returned to sender.\n", "");
E 3
I 3
		mailst(ruser, "Mail failed.  Letter returned to sender.\n", CNULL);
E 3
	return;
I 4
D 6
}

/*
 * this is like index, but takes a string as the second argument
 */
char *
D 5
sindex(str, chars)
E 5
I 5
strpbrk(str, chars)
E 5
register char *str, *chars;
{
	register char *cp;

	do {
		cp = chars - 1;
		while (*++cp) {
			if (*str == *cp)
				return str;
		}
	} while (*str++);
	return NULL;
E 6
I 5
}

/*
 *	execute shell of command with fi and fo as standard input/output
 */

shio(cmd, fi, fo)
char *cmd, *fi, *fo;
{
	int status, f;
D 10
	int uid, pid, ret;
	char path[MAXFULLNAME];
E 10
I 10
	int pid, ret;
E 10
D 9
	char *args[20];
E 9
I 9
	char *args[256];
E 9
	extern int errno;

	if (fi == NULL)
		fi = DEVNULL;
	if (fo == NULL)
		fo = DEVNULL;

D 9
	getargs(cmd, args, 20);
E 9
I 9
	getargs(cmd, args, 256);
E 9
	DEBUG(3, "shio - %s\n", cmd);
#ifdef SIGCHLD
	signal(SIGCHLD, SIG_IGN);
#endif SIGCHLD
	if ((pid = fork()) == 0) {
		signal(SIGINT, SIG_IGN);
		signal(SIGHUP, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
D 7
		signal(SIGKILL, SIG_IGN);
E 7
		close(Ifn);
		close(Ofn);
		close(0);
		setuid(getuid());
		f = open(subfile(fi), 0);
		if (f != 0) {
			logent(fi, "CAN'T READ");
			exit(-errno);
		}
		close(1);
		f = creat(subfile(fo), 0666);
		if (f != 1) {
			logent(fo, "CAN'T WRITE");
			exit(-errno);
		}
		execvp(args[0], args);
		exit(100+errno);
	}
	while ((ret = wait(&status)) != pid && ret != -1)
		;
	DEBUG(3, "status %d\n", status);
	return status;
E 5
E 4
}
E 1
