h14117
s 00001/00001/00483
d D 5.8 88/04/24 16:53:56 bostic 8 7
c fix for ANSI C
e
s 00049/00037/00435
d D 5.7 88/04/05 12:20:40 rick 7 6
c use syslog for errors, use getopt
e
s 00007/00002/00465
d D 5.6 88/02/24 20:02:57 rick 6 5
c dont barf if getuid fails (yellowpages suck)
e
s 00005/00000/00462
d D 5.5 85/10/09 16:22:06 bloom 5 4
c still more fixes from rick@seismo
e
s 00019/00017/00443
d D 5.4 85/06/23 13:15:29 bloom 4 3
c fixes from rick adams
e
s 00004/00004/00456
d D 5.3 85/04/10 15:21:27 ralph 3 2
c more changes from rick adams.
e
s 00078/00057/00382
d D 5.2 85/01/22 14:12:03 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00439/00000/00000
d D 5.1 83/07/02 17:57:43 sam 1 0
c date and time created 83/07/02 17:57:43 by sam
e
u
U
t
T
I 1
#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
static char sccsid[] = "%W%	(Berkeley) %G%";
E 7
#endif

#include "uucp.h"
D 3
#include <sys/types.h>
E 3
#include <sys/stat.h>
I 2
#include "uust.h"
E 2

/*
D 7
 *	uucp
E 7
I 7
 *	uucp command
E 7
 */
I 7

E 7
D 2

E 2
int Uid;
char *Ropt = " ";
D 4
char Path[100], Optns[10], Ename[8];
E 4
I 4
char Path[100], Optns[10], Ename[MAXBASENAME+1];
E 4
char Grade = 'n';
I 2
#ifdef DONTCOPY
int Copy = 0;
#else !DONTCOPY
E 2
int Copy = 1;
I 2
#endif !DONTCOPY
E 2
char Nuser[32];
I 5
struct timeb Now;
E 5

/* variables used to check if talking to more than one system. */
int	xsflag = -1;
D 4
char	xsys[8] = 0;
E 4
I 4
D 8
char	xsys[MAXBASENAME+1] = 0;
E 8
I 8
char	xsys[MAXBASENAME+1];
E 8
E 4

D 2
#define MAXCOUNT 20	/* maximun number of commands per C. file */
E 2
I 2
long Nbytes = 0;
#define MAXBYTES 50000	/* maximun number of bytes of data per C. file */
#define MAXCOUNT 15	/* maximun number of files per C. file */
E 2

D 2

E 2
main(argc, argv)
D 7
char *argv[];
E 7
I 7
int argc;
char **argv;
E 7
{
D 7
	int ret;
E 7
D 3
	register char *sysfile1, *sysfl2, *cp;
E 3
I 3
	char *sysfile1, *sysfl2;
	register char *cp;
E 3
	char file1[MAXFULLNAME], file2[MAXFULLNAME];
D 2
	int orig_uid = getuid();
E 2
I 2
D 7
	int avoidgwd = 0;
E 7
I 7
	int avoidgwd = 0, c;
	extern char *optarg;
	extern int optind;
E 7
E 2

	strcpy(Progname, "uucp");
	uucpname(Myname);
	umask(WFMASK);
	Optns[0] = '-';
	Optns[1] = 'd';
I 2
#ifdef DONTCOPY
	Optns[2] = 'c';
#else !DONTCOPY
E 2
	Optns[2] = 'C';
I 2
#endif !DONTCOPY
E 2
	Ename[0] = Nuser[0] = Optns[3] = '\0';
D 7
	while(argc>1 && argv[1][0] == '-'){
		switch(argv[1][1]){
E 7
I 7
	while((c = getopt(argc, argv, "aCcdfe:g:mn:rs:x:")) != EOF)
		switch(c) {
E 7
I 2
		case 'a':
			/* efficiency hack; avoid gwd call */
			avoidgwd = 1;
			break;
E 2
		case 'C':
			Copy = 1;
			Optns[2] = 'C';
			break;
		case 'c':
			Copy = 0;
			Optns[2] = 'c';
			break;
		case 'd':
			break;
		case 'f':
			Optns[1] = 'f';
			break;
		case 'e':
D 4
			sprintf(Ename, "%.7s", &argv[1][2]);
E 4
I 4
D 7
			strncpy(Ename, &argv[1][2], MAXBASENAME);
E 7
I 7
			strncpy(Ename, optarg, MAXBASENAME);
E 7
E 4
			break;
		case 'g':
D 2
			Grade = argv[1][2]; break;
E 2
I 2
D 7
			Grade = argv[1][2];
E 7
I 7
			Grade = *optarg;
E 7
			break;
E 2
		case 'm':
			strcat(Optns, "m");
			break;
		case 'n':
D 7
			sprintf(Nuser, "%.31s", &argv[1][2]);
E 7
I 7
			sprintf(Nuser, "%.31s", optarg);
E 7
			break;
		case 'r':
D 7
			Ropt = argv[1];
E 7
I 7
			Ropt = argv[optind-1];
E 7
			break;
		case 's':
D 7
			Spool = &argv[1][2]; break;
E 7
I 7
			Spool = optarg;
			break;
E 7
		case 'x':
D 2
			chkdebug(orig_uid);
E 2
I 2
			chkdebug();
E 2
D 7
			Debug = atoi(&argv[1][2]);
E 7
I 7
			Debug = atoi(optarg);
E 7
			if (Debug <= 0)
				Debug = 1;
I 7
			fprintf(stderr, "DEBUG %d\n", Debug);
E 7
			break;
I 7
		case '?':
E 7
		default:
D 7
			printf("unknown flag %s\n", argv[1]); break;
E 7
I 7
			fprintf(stderr, "unknown flag %s\n", argv[optind-1]);
			break;
E 7
		}
D 7
		--argc;  argv++;
	}
E 7
I 7

E 7
	DEBUG(4, "\n\n** %s **\n", "START");
D 2
	gwd(Wrkdir);
	subchdir(Spool);
E 2
I 2
D 4
	if (!avoidgwd)
		gwd(Wrkdir);
E 4
I 4
	if (!avoidgwd) {
		cp = getwd(Wrkdir);
D 7
		ASSERT(cp != 0, "GETWD FAILED", Wrkdir, cp);
E 7
I 7
		if (cp == NULL) {
			syslog(LOG_WARNING, "getwd failed");
			cleanup(1);
		}
E 7
	}
E 4
D 7
	ret = subchdir(Spool);
	ASSERT(ret >= 0, "CHDIR FAILED", Spool, ret);
E 7
I 7
	if (subchdir(Spool) < 0) {
		syslog(LOG_WARNING, "chdir(%s) failed: %m", Spool);
		cleanup(1);
	}
E 7
E 2

	Uid = getuid();
D 6
	ret = guinfo(Uid, User, Path);
D 2
	ASSERT(ret == 0, "CAN NOT FIND UID", "", Uid);
E 2
I 2
	ASSERT(ret == 0, "CAN NOT FIND UID", CNULL, Uid);
E 6
I 6
	if (guinfo(Uid, User, Path) != SUCCESS) {
D 7
		assert("Can't find username for ", "uid", Uid);
E 7
I 7
		syslog(LOG_WARNING, "Can't find username for uid %d", Uid);
E 7
		DEBUG(1, "Using username", "uucp");
		strcpy(User, "uucp");
	}
E 6
E 2
	DEBUG(4, "UID %d, ", Uid);
	DEBUG(4, "User %s,", User);
	DEBUG(4, "Ename (%s) ", Ename);
	DEBUG(4, "PATH %s\n", Path);
D 7
	if (argc < 3) {
		fprintf(stderr, "usage uucp from ... to\n");
E 7
I 7
	if (optind > (argc-2)) {
		fprintf(stderr, "usage: uucp [flags] from... to\n");
E 7
D 2
		cleanup(0);
E 2
I 2
		cleanup(1);
E 2
	}


	/*  set up "to" system and file names  */
D 7
	if ((cp = index(argv[argc - 1], '!')) != NULL) {
		sysfl2 = argv[argc - 1];
E 7
I 7
	if ((cp = index(argv[--argc], '!')) != NULL) {
		sysfl2 = argv[argc];
E 7
		*cp = '\0';
		if (*sysfl2 == '\0')
			sysfl2 = Myname;
		else
D 4
			sprintf(Rmtname, "%.7s", sysfl2);
E 4
I 4
			strncpy(Rmtname, sysfl2, MAXBASENAME);
E 4
D 3
		if (versys(sysfl2) != 0) {
E 3
I 3
		if (versys(&sysfl2) != 0) {
E 3
			fprintf(stderr, "bad system name: %s\n", sysfl2);
D 2
			cleanup(0);
E 2
I 2
			cleanup(1);
E 2
		}
I 5
		if (Rmtname[0] != '\0')
			strncpy(Rmtname, sysfl2, MAXBASENAME);
E 5
I 2
		/* block multi-hop requests immediately */
		if (index(cp+1, '!') != NULL) {
			fprintf(stderr, "uucp handles only adjacent sites.\n");
			fprintf(stderr, "Try uusend for multi-hop delivery.\n");
			cleanup(1);
		}
E 2
		strcpy(file2, cp + 1);
D 7
	}
	else {
E 7
I 7
	} else {
E 7
		sysfl2 = Myname;
D 7
		strcpy(file2, argv[argc - 1]);
E 7
I 7
		strcpy(file2, argv[argc]);
E 7
	}
D 4
	if (strlen(sysfl2) > 7)
		*(sysfl2 + 7) = '\0';
E 4
I 4
	if (strlen(sysfl2) > MAXBASENAME)
		sysfl2[MAXBASENAME] = '\0';
E 4


	/*  do each from argument  */
D 7
	while (argc > 2) {
		if ((cp = index(argv[1], '!')) != NULL) {
			sysfile1 = argv[1];
E 7
I 7
	while (optind < argc) {
		if ((cp = index(argv[optind], '!')) != NULL) {
			sysfile1 = argv[optind];
E 7
			*cp = '\0';
D 4
			if (strlen(sysfile1) > 7)
				*(sysfile1 + 7) = '\0';
E 4
I 4
			if (strlen(sysfile1) > MAXBASENAME)
				sysfile1[MAXBASENAME] = '\0';
E 4
			if (*sysfile1 == '\0')
				sysfile1 = Myname;
			else
D 4
				sprintf(Rmtname, "%.7s", sysfile1);
E 4
I 4
				strncpy(Rmtname, sysfile1, MAXBASENAME);
E 4
D 3
			if (versys(sysfile1) != 0) {
E 3
I 3
			if (versys(&sysfile1) != 0) {
E 3
				fprintf(stderr, "bad system name: %s\n", sysfile1);
D 7
				cleanup(0);
E 7
I 7
				cleanup(1);
E 7
			}
I 5
			if (Rmtname[0] != '\0')
				strncpy(Rmtname, sysfl2, MAXBASENAME);
E 5
			strcpy(file1, cp + 1);
D 7
		}
		else {
E 7
I 7
		} else {
E 7
			sysfile1 = Myname;
D 7
			strcpy(file1, argv[1]);
E 7
I 7
			strcpy(file1, argv[optind]);
E 7
		}
		DEBUG(4, "file1 - %s\n", file1);
		copy(sysfile1, file1, sysfl2, file2);
D 7
		--argc;
		argv++;
E 7
I 7
		optind++;
E 7
	}

	clscfile();
	if (*Ropt != '-' && xsflag >= 0)
		xuucico(xsys);
	cleanup(0);
}

cleanup(code)
int code;
{
	logcls();
	rmlock(CNULL);
	if (code)
		fprintf(stderr, "uucp failed. code %d\n", code);
	exit(code);
}


D 2
/***
 *	copy(s1, f1, s2, f2)	generate copy files
 *	char *s1, *f1, *s2, *f2;
E 2
I 2
/*
 *	generate copy files
E 2
 *
 *	return codes 0  |  FAIL
 */

copy(s1, f1, s2, f2)
register char *s1, *f1, *s2, *f2;
{
	int type, statret;
	struct stat stbuf, stbuf1;
	char dfile[NAMESIZE];
	char file1[MAXFULLNAME], file2[MAXFULLNAME];
	FILE *cfp, *gtcfile();
	char opts[100];

	type = 0;
	opts[0] = '\0';
	strcpy(file1, f1);
	strcpy(file2, f2);
	if (strcmp(s1, Myname) != SAME)
		type = 1;
	if (strcmp(s2, Myname) != SAME)
		type += 2;
	if (type & 01)
		if ((index(f1, '*') != NULL
		  || index(f1, '?') != NULL
		  || index(f1, '[') != NULL))
			type = 4;

	switch (type) {
	case 0:
		/* all work here */
		DEBUG(4, "all work here %d\n", type);
		if (ckexpf(file1))
D 2
			 return(FAIL);
E 2
I 2
			 return FAIL;
E 2
		if (ckexpf(file2))
D 2
			 return(FAIL);
E 2
I 2
			 return FAIL;
E 2
		if (stat(subfile(file1), &stbuf) != 0) {
			fprintf(stderr, "can't get file status %s \n copy failed\n",
			  file1);
D 2
			return(0);
E 2
I 2
			return SUCCESS;
E 2
		}
		statret = stat(subfile(file2), &stbuf1);
		if (statret == 0
		  && stbuf.st_ino == stbuf1.st_ino
		  && stbuf.st_dev == stbuf1.st_dev) {
			fprintf(stderr, "%s %s - same file; can't copy\n", file1, file2);
D 2
			return(0);
E 2
I 2
			return SUCCESS;
E 2
		}
		if (chkpth(User, "", file1) != 0
		  || chkperm(file2, index(Optns, 'd'))
		  || chkpth(User, "", file2) != 0) {
			fprintf(stderr, "permission denied\n");
			cleanup(1);
		}
		if ((stbuf.st_mode & ANYREAD) == 0) {
			fprintf(stderr, "can't read file (%s) mode (%o)\n",
D 4
			  file1, stbuf.st_mode);
E 4
I 4
			  file1, (int)stbuf.st_mode);
E 4
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		}
		if (statret == 0 && (stbuf1.st_mode & ANYWRITE) == 0) {
			fprintf(stderr, "can't write file (%s) mode (%o)\n",
D 4
			  file2, stbuf.st_mode);
E 4
I 4
			  file2, (int)stbuf.st_mode);
E 4
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		}
		xcp(file1, file2);
I 6
		/* With odd umask() might not be able to read it himself */
		(void) chmod(file2, 0666);
E 6
		logent("WORK HERE", "DONE");
D 2
		return(0);
E 2
I 2
		return SUCCESS;
E 2
	case 1:
		/* receive file */
		DEBUG(4, "receive file - %d\n", type);
		chsys(s1);
		if (file1[0] != '~')
			if (ckexpf(file1))
D 2
				 return(FAIL);
E 2
I 2
				 return FAIL;
E 2
		if (ckexpf(file2))
D 2
			 return(FAIL);
E 2
I 2
			 return FAIL;
E 2
		if (chkpth(User, "", file2) != 0) {
			fprintf(stderr, "permission denied\n");
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		}
		if (Ename[0] != '\0') {
			/* execute uux - remote uucp */
			xuux(Ename, s1, file1, s2, file2, opts);
D 2
			return(0);
E 2
I 2
			return SUCCESS;
E 2
		}

		cfp = gtcfile(s1);
		fprintf(cfp, "R %s %s %s %s\n", file1, file2, User, Optns);
		break;
	case 2:
		/* send file */
		if (ckexpf(file1))
D 2
			 return(FAIL);
E 2
I 2
			 return FAIL;
E 2
		if (file2[0] != '~')
			if (ckexpf(file2))
D 2
				 return(FAIL);
E 2
I 2
				 return FAIL;
E 2
		DEBUG(4, "send file - %d\n", type);
		chsys(s2);

		if (chkpth(User, "", file1) != 0) {
			fprintf(stderr, "permission denied %s\n", file1);
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		}
		if (stat(subfile(file1), &stbuf) != 0) {
			fprintf(stderr, "can't get status for file %s\n", file1);
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		}
		if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
			fprintf(stderr, "directory name illegal - %s\n",
			  file1);
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		}
		if ((stbuf.st_mode & ANYREAD) == 0) {
			fprintf(stderr, "can't read file (%s) mode (%o)\n",
D 4
			  file1, stbuf.st_mode);
E 4
I 4
			  file1, (int)stbuf.st_mode);
E 4
D 2
			return(FAIL);
E 2
I 2
			return FAIL;
E 2
		}
		if ((Nuser[0] != '\0') && (index(Optns, 'n') == NULL))
			strcat(Optns, "n");
		if (Ename[0] != '\0') {
			/* execute uux - remote uucp */
			if (Nuser[0] != '\0')
				sprintf(opts, "-n%s", Nuser);
			xuux(Ename, s1, file1, s2, file2, opts);
D 2
			return(0);
E 2
I 2
			return SUCCESS;
E 2
		}
I 2
		Nbytes +=  stbuf.st_size;
E 2
		if (Copy) {
D 2
			gename(DATAPRE, s2, Grade, dfile);
E 2
I 2
			gename(DATAPRE, Myname, Grade, dfile);
E 2
			if (xcp(file1, dfile) != 0) {
				fprintf(stderr, "can't copy %s\n", file1);
D 2
				return(FAIL);
E 2
I 2
				return FAIL;
E 2
			}
		}
		else {
			/* make a dummy D. name */
			/* cntrl.c knows names < 6 chars are dummy D. files */
			strcpy(dfile, "D.0");
		}
		cfp = gtcfile(s2);
		fprintf(cfp, "S %s %s %s %s %s %o %s\n", file1, file2,
D 4
			User, Optns, dfile, stbuf.st_mode & 0777, Nuser);
E 4
I 4
			User, Optns, dfile, (int)stbuf.st_mode & 0777, Nuser);
E 4
		break;
	case 3:
	case 4:
		/*  send uucp command for execution on s1  */
		DEBUG(4, "send uucp command - %d\n", type);
		chsys(s1);
		if (strcmp(s2,  Myname) == SAME) {
			if (ckexpf(file2))
D 2
				 return(FAIL);
E 2
I 2
				 return FAIL;
E 2
			if (chkpth(User, "", file2) != 0) {
				fprintf(stderr, "permission denied\n");
D 2
				return(FAIL);
E 2
I 2
				return FAIL;
E 2
			}
		}
		if (Ename[0] != '\0') {
			/* execute uux - remote uucp */
			xuux(Ename, s1, file1, s2, file2, opts);
D 2
			return(0);
E 2
I 2
			return SUCCESS;
E 2
		}
		cfp = gtcfile(s1);
		fprintf(cfp, "X %s %s!%s %s %s\n", file1, s2, file2, User, Optns);
		break;
	}
D 2
	return(0);
E 2
I 2
	return SUCCESS;
E 2
}

D 2
/***
 *	xuux(ename, s1, s2, f1, f2, opts)	execute uux for remote uucp
E 2
I 2
/*
 *	execute uux for remote uucp
E 2
 *
 *	return code - none
 */

xuux(ename, s1, f1, s2, f2, opts)
char *ename, *s1, *s2, *f1, *f2, *opts;
{
	char cmd[200];

	DEBUG(4, "Ropt(%s) ", Ropt);
	DEBUG(4, "ename(%s) ", ename);
	DEBUG(4, "s1(%s) ", s1);
	DEBUG(4, "f1(%s) ", f1);
	DEBUG(4, "s2(%s) ", s2);
	DEBUG(4, "f2(%s)\n", f2);
	sprintf(cmd, "uux %s %s!uucp %s %s!%s \\(%s!%s\\)",
	 Ropt, ename, opts,  s1, f1, s2, f2);
	DEBUG(4, "cmd (%s)\n", cmd);
	system(cmd);
	return;
}

FILE *Cfp = NULL;
char Cfile[NAMESIZE];

D 2
/***
 *	gtcfile(sys)	- get a Cfile descriptor
E 2
I 2
/*
 *	get a Cfile descriptor
E 2
 *
 *	return an open file descriptor
 */

FILE *
gtcfile(sys)
register char *sys;
{
	static char presys[8] = "";
	static int cmdcount = 0;
	register int savemask;

	if (strcmp(presys, sys) != SAME  /* this is !SAME on first call */
I 2
	  || Nbytes > MAXBYTES
E 2
	  || ++cmdcount > MAXCOUNT) {
D 2

E 2
		cmdcount = 1;
I 2
		Nbytes = 0;
E 2
		if (presys[0] != '\0') {
			clscfile();
		}
		gename(CMDPRE, sys, Grade, Cfile);
I 2
#ifdef VMS
		savemask = umask(~0600); /* vms must have read permission */
#else !VMS
E 2
		savemask = umask(~0200);
I 2
#endif !VMS
E 2
		Cfp = fopen(subfile(Cfile), "w");
		umask(savemask);
D 2
		ASSERT(Cfp != NULL, "CAN'T OPEN", Cfile, 0);
E 2
I 2
D 7
		ASSERT(Cfp != NULL, CANTOPEN, Cfile, 0);
E 7
I 7
		if (Cfp == NULL) {
			syslog(LOG_WARNING, "fopen(%s) failed: %m",
				subfile(Cfile));
			cleanup(1);
		}
E 7
E 2
		strcpy(presys, sys);
	}
D 2
	return(Cfp);
E 2
I 2
	return Cfp;
E 2
}

D 2
/***
 *	clscfile()	- close cfile
E 2
I 2
/*
 *	close cfile
E 2
 *
 *	return code - none
 */

clscfile()
{
	if (Cfp == NULL)
		return;
	fclose(Cfp);
	chmod(subfile(Cfile), ~WFMASK & 0777);
	logent(Cfile, "QUE'D");
I 2
	US_CRS(Cfile);
E 2
	Cfp = NULL;
D 2
	return;
E 2
}

D 2
/****
 *
 * chsys(s1)	compile a list of all systems we are referencing
 *	char *s1
 *
 * no return code -- sets up the xsys array.
 * Author: mcnc!swd, Stephen Daniel
E 2
I 2
/*
 * compile a list of all systems we are referencing
E 2
 */
D 2

E 2
chsys(s1)
register char *s1;
{
	if (xsflag < 0)
		xsflag = 0;
	else if (xsflag > 0)
		return;

	if (xsys[0] == '\0') {
D 4
		strncpy(xsys, s1, 7);
E 4
I 4
		strncpy(xsys, s1, MAXBASENAME);
E 4
		return;
	}

D 2
	if (strcmp(xsys, s1) == SAME)
E 2
I 2
D 4
	if (strncmp(xsys, s1, 7) == SAME)
E 4
I 4
	if (strncmp(xsys, s1, MAXBASENAME) == SAME)
E 4
E 2
		return;

	xsflag++;
	xsys[0] = '\0';
}
E 1
