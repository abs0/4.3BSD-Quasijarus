h30698
s 00003/00007/00592
d D 5.13 88/07/22 09:08:32 bostic 13 12
c fix for the 4.3BSD-tahoe getopt
e
s 00016/00016/00583
d D 5.12 88/06/08 12:35:31 rick 12 11
c sysexits is back (wont it ever die?)
e
s 00001/00000/00598
d D 5.11 88/05/04 14:41:21 rick 11 10
c add include of errno.h
e
s 00015/00024/00583
d D 5.10 88/05/04 13:55:24 rick 10 9
c purge use of sysexits in favor of errno
e
s 00009/00000/00598
d D 5.9 88/04/25 19:09:01 bostic 9 8
c uux includes sysexits.h itself
e
s 00051/00025/00547
d D 5.8 88/04/05 12:26:26 rick 8 7
c use syslog for errors, use getopt
e
s 00026/00002/00546
d D 5.7 88/02/24 20:05:49 rick 7 6
c add gradedelta hack -gA50000. dont fail if getuid(uucp) fails
e
s 00029/00008/00519
d D 5.6 86/01/24 13:20:10 bloom 6 5
c still more fixes and changes from rick@seismo
e
s 00057/00010/00470
d D 5.5 85/10/09 16:48:09 bloom 5 4
c still more fixes from rick@seismo
e
s 00008/00006/00472
d D 5.4 85/06/23 13:55:40 bloom 4 3
c fixes from rick adams
e
s 00007/00008/00471
d D 5.3 85/04/10 15:23:19 ralph 3 2
c more changes from rick adams.
e
s 00099/00040/00380
d D 5.2 85/01/22 14:13:41 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00420/00000/00000
d D 5.1 83/07/02 17:58:04 sam 1 0
c date and time created 83/07/02 17:58:04 by sam
e
u
U
t
T
I 1
#ifndef lint
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
static char sccsid[] = "%W%	(Berkeley) %G%";
E 8
#endif

D 2
/*
 * Grade option "-g<g>" added. See cbosgd.2611 (Mark Horton)
 * no-copy option "-c" added. Suggested by Steve Bellovin
 * "-l" is synonym for "-c".
 * "X" files use local system name, avoids conflict. Steve Bellovin
 */
E 2
#include "uucp.h"
I 7
#include <sys/stat.h>
I 11
D 12
#include <sys/errno.h>
E 12
I 12
#include <sysexits.h>
E 12
E 11
I 9
D 10
/*
 * If you have it, include <sysexits.h> to use exit
 * codes that will be understood by sendmail.
 * Otherwise, define EX_NOHOST, EX_CANTCREAT, and EX_NOINPUT.
 */
#include <sysexits.h>
/*#define EX_NOINPUT	66	/**/
/*#define EX_NOHOST	68	/**/
/*#define EX_CANTCREAT	73	/**/
E 10
E 9
E 7

#define NOSYSPART 0
#define HASSYSPART 1

I 5
#define LQUOTE	'('
#define RQUOTE ')'

E 5
#define APPCMD(d) {\
D 2
char *p;\
for (p = d; *p != '\0';) *cmdp++ = *p++;\
*cmdp++ = ' ';\
*cmdp = '\0';}
E 2
I 2
D 6
char *p; for (p = d; *p != '\0';) *cmdp++ = *p++; *cmdp++ = ' '; *cmdp = '\0';}
E 6
I 6
register char *p; for (p = d; *p != '\0';)\
	{*cmdp++ = *p++;\
		if(cmdp>(sizeof(cmd)+&cmd[0])){\
			fprintf(stderr,"argument list too long\n");\
D 10
			cleanup(EX_SOFTWARE);\
E 10
I 10
D 12
			cleanup(E2BIG);\
E 12
I 12
			cleanup(EX_SOFTWARE);\
E 12
E 10
		}\
	}\
	*cmdp++ = ' '; *cmdp = '\0';}
E 6
E 2

#define GENSEND(f, a, b, c, d, e) {\
D 2
fprintf(f, "S %s %s %s -%s %s 0666\n", a, b, c, d, e);\
}
#define GENRCV(f, a, b, c) {\
fprintf(f, "R %s %s %s - \n", a, b, c);\
}
E 2
I 2
D 6
fprintf(f, "S %s %s %s -%s %s 0666\n", a, b, c, d, e); }
E 6
I 6
	fprintf(f, "S %s %s %s -%s %s 0666\n", a, b, c, d, e); }
E 6
#define GENRCV(f, a, b, c) {fprintf(f, "R %s %s %s - \n", a, b, c);}
E 2

I 5
struct timeb Now;

E 5
D 2

/*
 *	
 */

E 2
main(argc, argv)
D 8
char *argv[];
E 8
I 8
int argc;
char **argv;
E 8
{
	char cfile[NAMESIZE];	/* send commands for files from here */
	char dfile[NAMESIZE];	/* used for all data files from here */
	char rxfile[NAMESIZE];	/* to be sent to xqt file (X. ...) */
	char tfile[NAMESIZE];	/* temporary file name */
	char tcfile[NAMESIZE];	/* temporary file name */
	char t2file[NAMESIZE];	/* temporary file name */
	int cflag = 0;		/*  commands in C. file flag  */
	int rflag = 0;		/*  C. files for receiving flag  */
I 2
#ifdef DONTCOPY
	int Copy = 0;		/* Don't Copy spool files */
#else !DONTCOPY
E 2
	int Copy = 1;		/* Copy spool files */
I 2
#endif !DONTCOPY
	int Linkit = 0;		/* Try link before copy */
E 2
D 6
	char buf[BUFSIZ];
	char inargs[BUFSIZ];
E 6
I 6
	char buf[2*BUFSIZ];
	char inargs[2*BUFSIZ];
E 6
	int pipein = 0;
	int startjob = 1;
	char Grade = 'A';
I 7
	long Gradedelta = 100000000L;	/* "huge number" */
	long size = 0L;
E 7
	char path[MAXFULLNAME];
D 6
	char cmd[BUFSIZ];
E 6
I 6
	char cmd[2*BUFSIZ];
E 6
	char *ap, *cmdp;
D 6
	char prm[BUFSIZ];
E 6
I 6
	char prm[2*BUFSIZ];
E 6
D 4
	char syspart[8], rest[MAXFULLNAME];
D 3
	char xsys[8], local[8];
E 3
I 3
	char Xsys[8], local[8];
E 4
I 4
	char syspart[MAXBASENAME+1], rest[MAXFULLNAME];
	char Xsys[MAXBASENAME+1], local[MAXBASENAME+1];
E 4
	char *xsys = Xsys;
E 3
	FILE *fprx, *fpc, *fpd, *fp;
	extern char *getprm(), *lastpart();
	extern FILE *ufopen();
D 8
	int uid, ret;
E 8
I 8
	int uid, ret, c;
E 8
	char redir = '\0';
	int nonoti = 0;
	int nonzero = 0;
D 2
	int orig_uid = getuid();
E 2
I 2
	int link_failed;
	char *ReturnTo = NULL;
	extern int LocalOnly;
I 8
	extern char *optarg;
	extern int optind;
E 8
E 2

	strcpy(Progname, "uux");
	uucpname(Myname);
	umask(WFMASK);
	Ofn = 1;
	Ifn = 0;
I 2
#ifdef	VMS
	arg_fix(argc, argv);
#endif
E 2
D 8
	while (argc>1 && argv[1][0] == '-') {
		switch(argv[1][1]){
E 8
I 8
D 13
	while ((c = getopt(argc, argv, "prclCg:x:nzLa:")) != EOF ||
		*argv[optind] == '-')
E 13
I 13
	while ((c = getopt(argc, argv, "-prclCg:x:nzLa:")) != EOF)
E 13
		switch (c) {
D 13
		case EOF:
			/* getopt doesn't like "-" as an argument... */
			optind++;	
			/* NO BREAK */
E 13
I 13
		case '-':
			/* FALLTHROUGH */
E 13
E 8
		case 'p':
D 8
		case '\0':
E 8
			pipein = 1;
			break;
		case 'r':
			startjob = 0;
			break;
		case 'c':
I 2
			Copy = 0;
			Linkit = 0;
			break;
E 2
		case 'l':
			Copy = 0;
I 2
			Linkit = 1;
E 2
			break;
I 2
		case 'C':
			Copy = 1;
			Linkit = 0;
			break;
E 2
		case 'g':
D 8
			Grade = argv[1][2];
I 7
			Gradedelta = atol(&argv[1][3]);
E 8
I 8
			Grade = *optarg;
			Gradedelta = atol(optarg+1);
E 8
E 7
			break;
		case 'x':
D 2
			chkdebug(orig_uid);
E 2
I 2
			chkdebug();
E 2
D 8
			Debug = atoi(&argv[1][2]);
E 8
I 8
			Debug = atoi(optarg);
E 8
			if (Debug <= 0)
				Debug = 1;
			break;
		case 'n':
			nonoti = 1;
			break;
		case 'z':
			nonzero = 1;
			break;
I 2
		case 'L':
			LocalOnly++;
			break;
		case 'a':
D 8
			ReturnTo = &argv[1][2];
E 8
I 8
			ReturnTo = optarg;
E 8
I 4
			if (prefix(Myname, ReturnTo) && ReturnTo[strlen(Myname)]				== '!')
				ReturnTo = index(ReturnTo, '!') + 1;
E 4
			break;
I 8
		case '?':
E 8
E 2
		default:
D 8
			fprintf(stderr, "unknown flag %s\n", argv[1]);
				break;
E 8
I 8
D 13
			fprintf(stderr, "unknown flag %s\n", argv[optind-1]);
E 13
			break;
E 8
		}
D 8
		--argc;  argv++;
	}
E 8
I 8

E 8
I 2
D 5
	if (argc > 2) {
D 4
		ret = gwd(Wrkdir);
		if (ret != 0) {
E 4
I 4
		ap = getwd(Wrkdir);
		if (ap == 0) {
E 4
			fprintf(stderr, "can't get working directory; will try to continue\n");
			strcpy(Wrkdir, "/UNKNOWN");
		}
E 5
I 5
	ap = getwd(Wrkdir);
	if (ap == 0) {
		fprintf(stderr, "can't get working directory; will try to continue\n");
		strcpy(Wrkdir, "/UNKNOWN");
E 5
	}
E 2

	DEBUG(4, "\n\n** %s **\n", "START");

	inargs[0] = '\0';
D 8
	for (argv++; argc > 1; argc--) {
		DEBUG(4, "arg - %s:", *argv);
E 8
I 8
	while (optind < argc) {
		DEBUG(4, "arg - %s:", argv[optind]);
E 8
		strcat(inargs, " ");
D 8
		strcat(inargs, *argv++);
E 8
I 8
		strcat(inargs, argv[optind++]);
E 8
	}
	DEBUG(4, "arg - %s\n", inargs);
D 2
	ret = gwd(Wrkdir);
	if (ret != 0) {
		fprintf(stderr, "can't get working directory; will try to continue\n");
		strcpy(Wrkdir, "/UNKNOWN");
	}
	subchdir(Spool);
E 2
I 2
D 8
	ret = subchdir(Spool);
	ASSERT(ret >= 0, "CHDIR FAILED", Spool, ret);
E 8
I 8
	if (subchdir(Spool) < 0) {
		syslog(LOG_WARNING, "chdir(%s) failed: %m", Spool);
		cleanup(1);
	}
E 8
E 2
	uid = getuid();
D 7
	guinfo(uid, User, path);
E 7
I 7
	if (guinfo(uid, User, path) != SUCCESS) {
D 8
		assert("Can't find username for ", "uid", uid);
E 8
I 8
		syslog(LOG_WARNING, "Can't find username for uid %d", uid);
E 8
		DEBUG(1, "Using username", "uucp");
		strcpy(User, "uucp");
	}
E 7

D 4
	sprintf(local, "%.7s", Myname);
E 4
I 4
	strncpy(local, Myname, MAXBASENAME);
E 4
	cmdp = cmd;
	*cmdp = '\0';
	gename(DATAPRE, local, 'X', rxfile);
	fprx = ufopen(rxfile, "w");
D 8
	ASSERT(fprx != NULL, "CAN'T OPEN", rxfile, 0);
E 8
I 8
	if (fprx == NULL) {
		syslog(LOG_WARNING, "fopen(%s) failed: %m", rxfile);
		cleanup(1);
	}
E 8
	gename(DATAPRE, local, 'T', tcfile);
	fpc = ufopen(tcfile, "w");
D 8
	ASSERT(fpc != NULL, "CAN'T OPEN", tcfile, 0);
E 8
I 8
	if (fpc == NULL) {
		syslog(LOG_WARNING, "fopen(%s) failed: %m", tcfile);
		cleanup(1);
	}
E 8
	fprintf(fprx, "%c %s %s\n", X_USER, User, local);
	if (nonoti)
		fprintf(fprx, "%c\n", X_NONOTI);
	if (nonzero)
		fprintf(fprx, "%c\n", X_NONZERO);
I 2
	if (ReturnTo == NULL || *ReturnTo == '\0')
		ReturnTo = User;
	fprintf(fprx, "%c %s\n", X_RETURNTO, ReturnTo);
E 2

	/* find remote system name */
	ap = inargs;
	xsys[0] = '\0';
	while ((ap = getprm(ap, prm)) != NULL) {
		if (prm[0] == '>' || prm[0] == '<') {
			ap = getprm(ap, prm);
			continue;
		}

D 5

E 5
		split(prm, xsys, rest);
		break;
	}
	if (xsys[0] == '\0')
		strcpy(xsys, local);
D 4
	sprintf(Rmtname, "%.7s", xsys);
E 4
I 4
D 5
	strncpy(Rmtname, xsys, MAXBASENAME);
E 4
	DEBUG(4, "xsys %s\n", xsys);
E 5
D 3
	if (versys(xsys) != 0) {
E 3
I 3
	if (versys(&xsys) != 0) {
E 3
		/*  bad system name  */
		fprintf(stderr, "bad system name: %s\n", xsys);
		fclose(fprx);
		fclose(fpc);
D 10
		cleanup(EX_NOHOST);
E 10
I 10
D 12
		cleanup(EHOSTUNREACH);
E 12
I 12
		cleanup(EX_NOHOST);
E 12
E 10
	}

I 5
	strncpy(Rmtname, xsys, MAXBASENAME);
	DEBUG(4, "xsys %s\n", xsys);

E 5
	if (pipein) {
		gename(DATAPRE, local, 'B', dfile);
		fpd = ufopen(dfile, "w");
D 8
		ASSERT(fpd != NULL, "CAN'T OPEN", dfile, 0);
E 8
I 8
		if (fpd == NULL) {
			syslog(LOG_WARNING, "fopen(%s) failed: %m", dfile);
			cleanup(1);
		}
E 8
		while (!feof(stdin)) {
			ret = fread(buf, 1, BUFSIZ, stdin);
			fwrite(buf, 1, ret, fpd);
I 6
			if (ferror(stdin)) {
				perror("stdin");
D 10
				cleanup(EX_IOERR);
E 10
I 10
D 12
				cleanup(EIO);
E 12
I 12
				cleanup(EX_IOERR);
E 12
E 10
			}
			if (ferror(fpd)) {
				perror(dfile);
D 10
				cleanup(EX_IOERR);
E 10
I 10
D 12
				cleanup(EIO);
E 12
I 12
				cleanup(EX_IOERR);
E 12
E 10
			}
I 7
			size += ret;
E 7
E 6
		}
		fclose(fpd);
I 2
		strcpy(tfile, dfile);
E 2
		if (strcmp(local, xsys) != SAME) {
D 2
			GENSEND(fpc, dfile, dfile, User, "", dfile);
E 2
I 2
D 5
			tfile[strlen(local) + 2] = 'S';
E 5
I 5
			register int Len = strlen(local);
			if (Len > SYSNSIZE)
				Len = SYSNSIZE;
			tfile[Len + 2] = 'S';
E 5
			GENSEND(fpc, dfile, tfile, User, "", dfile);
E 2
			cflag++;
		}
D 2
		fprintf(fprx, "%c %s\n", X_RQDFILE, dfile);
		fprintf(fprx, "%c %s\n", X_STDIN, dfile);
E 2
I 2
		fprintf(fprx, "%c %s\n", X_RQDFILE, tfile);
		fprintf(fprx, "%c %s\n", X_STDIN, tfile);
E 2
	}
	/* parse command */
	ap = inargs;
	while ((ap = getprm(ap, prm)) != NULL) {
		DEBUG(4, "prm - %s\n", prm);
		if (prm[0] == '>' || prm[0] == '<') {
			redir = prm[0];
			continue;
		}

		if (prm[0] == ';') {
			APPCMD(prm);
			continue;
		}

		if (prm[0] == '|' || prm[0] == '^') {
			if (cmdp != cmd)
				APPCMD(prm);
			continue;
		}

		/* process command or file or option */
		ret = split(prm, syspart, rest);
		DEBUG(4, "s - %s, ", syspart);
		DEBUG(4, "r - %s, ", rest);
		DEBUG(4, "ret - %d\n", ret);
		if (syspart[0] == '\0')
			strcpy(syspart, local);

		if (cmdp == cmd && redir == '\0') {
			/* command */
			APPCMD(rest);
			continue;
		}

		/* process file or option */
		DEBUG(4, "file s- %s, ", syspart);
		DEBUG(4, "local - %s\n", local);
		/* process file */
		if (redir == '>') {
			if (rest[0] != '~')
				if (ckexpf(rest))
D 10
					cleanup(EX_CANTCREAT);
E 10
I 10
D 12
					cleanup(EACCES);
E 12
I 12
					cleanup(EX_CANTCREAT);
E 12
E 10
			fprintf(fprx, "%c %s %s\n", X_STDOUT, rest,
			 syspart);
			redir = '\0';
			continue;
		}

		if (ret == NOSYSPART && redir == '\0') {
			/* option */
			APPCMD(rest);
			continue;
		}

I 7
		if (rest[0] != '\0') {
			struct stat stbuf;
			if (stat(rest, &stbuf) < 0)
				DEBUG(4, "Can't stat %s\n", rest);
			else 
				size += stbuf.st_size;
			DEBUG(4, "size = %ld\n", size);
		}

E 7
		if (strcmp(xsys, local) == SAME
		 && strcmp(xsys, syspart) == SAME) {
			if (ckexpf(rest))
D 10
				cleanup(EX_CANTCREAT);
E 10
I 10
D 12
				cleanup(EACCES);
E 12
I 12
				cleanup(EX_CANTCREAT);
E 12
E 10
			if (redir == '<')
				fprintf(fprx, "%c %s\n", X_STDIN, rest);
			else
				APPCMD(rest);
			redir = '\0';
			continue;
		}

		if (strcmp(syspart, local) == SAME) {
			/*  generate send file */
			if (ckexpf(rest))
D 10
				cleanup(EX_CANTCREAT);
E 10
I 10
D 12
				cleanup(EACCES);
E 12
I 12
				cleanup(EX_CANTCREAT);
E 12
E 10
			gename(DATAPRE, local, 'A', dfile);
			DEBUG(4, "rest %s\n", rest);
			if ((chkpth(User, "", rest) || anyread(rest)) != 0) {
				fprintf(stderr, "permission denied %s\n", rest);
D 10
				cleanup(EX_NOINPUT);
E 10
I 10
D 12
				cleanup(EACCES);
E 12
I 12
				cleanup(EX_NOINPUT);
E 12
E 10
			}
D 2
			if (Copy) {
E 2
I 2
			link_failed = 0;
			if (Linkit) {
				if (link(subfile(rest), subfile(dfile)) != 0)
					link_failed++;
				else
					GENSEND(fpc, rest, dfile, User, "", dfile);
			}
			if (Copy || link_failed) {
E 2
				if (xcp(rest, dfile) != 0) {
					fprintf(stderr, "can't copy %s to %s\n", rest, dfile);
D 10
					cleanup(EX_NOINPUT);
E 10
I 10
D 12
					cleanup(EIO);
E 12
I 12
					cleanup(EX_NOINPUT);
E 12
E 10
				}
				GENSEND(fpc, rest, dfile, User, "", dfile);
			}
D 2
			else {
E 2
I 2
			if (!Copy && !Linkit) {
E 2
				GENSEND(fpc, rest, dfile, User, "c", "D.0");
			}
			cflag++;
			if (redir == '<') {
				fprintf(fprx, "%c %s\n", X_STDIN, dfile);
				fprintf(fprx, "%c %s\n", X_RQDFILE, dfile);
D 3
			}
			else {
E 3
I 3
			} else {
E 3
				APPCMD(lastpart(rest));
				fprintf(fprx, "%c %s %s\n", X_RQDFILE,
				 dfile, lastpart(rest));
			}
			redir = '\0';
			continue;
		}

		if (strcmp(local, xsys) == SAME) {
			/*  generate local receive  */
			gename(CMDPRE, syspart, 'R', tfile);
			strcpy(dfile, tfile);
			dfile[0] = DATAPRE;
			fp = ufopen(tfile, "w");
D 8
			ASSERT(fp != NULL, "CAN'T OPEN", tfile, 0);
E 8
I 8
			if (fp == NULL) {
				syslog(LOG_WARNING, "fopen(%s) failed: %m",
					tfile);
				cleanup(1);
			}
E 8
			if (ckexpf(rest))
D 10
				cleanup(EX_CANTCREAT);
E 10
I 10
D 12
				cleanup(EPERM);
E 12
I 12
				cleanup(EX_CANTCREAT);
E 12
E 10
			GENRCV(fp, rest, dfile, User);
			fclose(fp);
			rflag++;
			if (rest[0] != '~')
				if (ckexpf(rest))
D 10
					cleanup(EX_CANTCREAT);
E 10
I 10
D 12
					cleanup(EPERM);
E 12
I 12
					cleanup(EX_CANTCREAT);
E 12
E 10
			if (redir == '<') {
				fprintf(fprx, "%c %s\n", X_RQDFILE, dfile);
				fprintf(fprx, "%c %s\n", X_STDIN, dfile);
D 3
			}
			else {
E 3
I 3
			} else {
E 3
				fprintf(fprx, "%c %s %s\n", X_RQDFILE, dfile,
				  lastpart(rest));
				APPCMD(lastpart(rest));
			}

			redir = '\0';
			continue;
		}

		if (strcmp(syspart, xsys) != SAME) {
			/* generate remote receives */
			gename(DATAPRE, syspart, 'R', dfile);
			strcpy(tfile, dfile);
			tfile[0] = CMDPRE;
			fpd = ufopen(dfile, "w");
D 8
			ASSERT(fpd != NULL, "CAN'T OPEN", dfile, 0);
E 8
I 8
			if (fpd == NULL) {
				syslog(LOG_WARNING, "fopen(%s) failed: %m",
					dfile);
				cleanup(1);
			}
E 8
			gename(DATAPRE, local, 'T', t2file);
			GENRCV(fpd, rest, t2file, User);
			fclose(fpd);
			GENSEND(fpc, dfile, tfile, User, "", dfile);
			cflag++;
			if (redir == '<') {
				fprintf(fprx, "%c %s\n", X_RQDFILE, t2file);
				fprintf(fprx, "%c %s\n", X_STDIN, t2file);
D 3
			}
			else {
E 3
I 3
			} else {
E 3
				fprintf(fprx, "%c %s %s\n", X_RQDFILE, t2file,
				  lastpart(rest));
				APPCMD(lastpart(rest));
			}
			redir = '\0';
			continue;
		}

		/* file on remote system */
		if (rest[0] != '~')
			if (ckexpf(rest))
D 10
				cleanup(EX_CANTCREAT);
E 10
I 10
D 12
				cleanup(EACCES);
E 12
I 12
				cleanup(EX_CANTCREAT);
E 12
E 10
		if (redir == '<')
			fprintf(fprx, "%c %s\n", X_STDIN, rest);
		else
			APPCMD(rest);
		redir = '\0';
		continue;

	}
I 2
	/*
	 * clean up trailing ' ' in command.
	 */
	if (cmdp > cmd && cmdp[0] == '\0' && cmdp[-1] == ' ')
		*--cmdp = '\0';
	/* block multi-hop uux, which doesn't work */
	for (ap = cmd; *ap && *ap != ' '; ap++)
		if (*ap == '!') {
			fprintf(stderr, "uux handles only adjacent sites.\n");
			fprintf(stderr, "Try uusend for multi-hop delivery.\n");
D 6
			cleanup(1);
E 6
I 6
D 10
			cleanup(EX_USAGE);
E 10
I 10
D 12
			cleanup(EINVAL);
E 12
I 12
			cleanup(EX_USAGE);
E 12
E 10
E 6
		}
E 2

	fprintf(fprx, "%c %s\n", X_CMD, cmd);
D 6
	logent(cmd, "XQT QUE'D");
E 6
I 6
	if (ferror(fprx)) {
		logent(cmd, "COULD NOT QUEUE XQT");
D 10
		cleanup(EX_IOERR);
E 10
I 10
D 12
		cleanup(EIO);
E 12
I 12
		cleanup(EX_IOERR);
E 12
E 10
	} else
		logent(cmd, "XQT QUE'D");
E 6
	fclose(fprx);

I 7
	if (size > 0 && Gradedelta > 0) {
		DEBUG (4, "Grade changed from %c ", Grade);
		Grade += size/Gradedelta;
		if (Grade > 'z')
			Grade = 'z';
		DEBUG(4, "to %c\n", Grade);
	}
E 7
D 2
	strcpy(tfile, rxfile);
	tfile[0] = XQTPRE;
E 2
I 2
	gename(XQTPRE, local, Grade, tfile);
E 2
	if (strcmp(xsys, local) == SAME) {
		/* rti!trt: xmv() works across filesystems, link(II) doesnt */
		xmv(rxfile, tfile);
		if (startjob)
			if (rflag)
				xuucico(xsys);
			else
				xuuxqt();
	}
	else {
		GENSEND(fpc, rxfile, tfile, User, "", rxfile);
		cflag++;
	}

I 6
	if (ferror(fpc))
D 10
		cleanup(EX_IOERR);
E 10
I 10
D 12
		cleanup(EIO);
E 12
I 12
		cleanup(EX_IOERR);
E 12
E 10
E 6
	fclose(fpc);
	if (cflag) {
		gename(CMDPRE, xsys, Grade, cfile);
		/* rti!trt: use xmv() rather than link(II) */
		xmv(tcfile, cfile);
		if (startjob)
			xuucico(xsys);
		cleanup(0);
	}
	else
		unlink(subfile(tcfile));
I 3
	exit(0);
E 3
}

#define FTABSIZE 30
char Fname[FTABSIZE][NAMESIZE];
int Fnamect = 0;

D 2
/***
 *	cleanup - cleanup and unlink if error
E 2
I 2
/*
 *	cleanup and unlink if error
E 2
 *
 *	return - none - do exit()
 */

cleanup(code)
int code;
{
	int i;

	logcls();
	rmlock(CNULL);
	if (code) {
		for (i = 0; i < Fnamect; i++)
			unlink(subfile(Fname[i]));
		fprintf(stderr, "uux failed. code %d\n", code);
	}
	DEBUG(1, "exit code %d\n", code);
	exit(code);
}

D 2
/***
 *	ufopen - open file and record name
E 2
I 2
/*
 *	open file and record name
E 2
 *
 *	return file pointer.
 */

FILE *ufopen(file, mode)
char *file, *mode;
{
	if (Fnamect < FTABSIZE)
		strcpy(Fname[Fnamect++], file);
	else
		logent("Fname", "TABLE OVERFLOW");
D 2
	return(fopen(subfile(file), mode));
E 2
I 2
	return fopen(subfile(file), mode);
E 2
}
I 2
#ifdef	VMS
/*
 * EUNICE bug:
 *	quotes are not stripped from DCL.  Do it here.
 *	Note if we are running under Unix shell we don't
 *	do the right thing.
 */
arg_fix(argc, argv)
char **argv;
{
	register char *cp, *tp;

	for (; argc > 0; --argc, argv++) {
		cp = *argv;
		if (cp == (char *)0 || *cp++ != '"')
			continue;
		tp = cp;
		while (*tp++) ;
		tp -= 2;
		if (*tp == '"') {
			*tp = '\0';
			*argv = cp;
		}
	}
}
#endif VMS
I 5

/*
 *	split into system and file part
 *
 *	return codes:
 *		NOSYSPART
 *		HASSYSPART
 */

split(name, sys, rest)
register char *name, *rest;
char *sys;
{
	register char *c;
D 7
	register int i;
E 7

	if (*name == LQUOTE) {
		if ((c = index(name + 1, RQUOTE)) != NULL) {
		/* strip off quotes */
			name++;
			while (c != name)
				*rest++ = *name++;
			*rest = '\0';
			*sys = '\0';
			return NOSYSPART;
		}
	}

	if ((c = index(name, '!')) == NULL) {
		strcpy(rest, name);
		*sys = '\0';
		return NOSYSPART;
	}

	*c++ = '\0';
	strncpy(sys, name, MAXBASENAME);
	sys[MAXBASENAME] = '\0';

	strcpy(rest, c);
	return HASSYSPART;
}
E 5
E 2
E 1
