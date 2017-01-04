h48309
s 00009/00018/00892
d D 5.6 99/12/31 18:40:23 msokolov 21 20
c Y2K
e
s 00020/00042/00890
d D 5.5 87/01/18 20:29:48 karels 20 18
c rm prompt; change shell quoting (for bostic)
e
s 00002/00000/00932
d R 5.5 86/12/18 22:55:58 bostic 19 18
c checked in for Jim Bloom
e
s 00093/00112/00839
d D 5.4 86/05/28 18:42:55 mckusick 18 17
c update from dss%fatkid@SUN.COM (Daniel Steinberg)
e
s 00012/00000/00939
d D 5.3 85/08/05 11:11:16 bloom 17 15
c fix problem with histchars and expansions
e
s 00010/00000/00939
d R 5.3 85/08/02 17:30:36 bloom 16 15
c unset histchars before trying to set environment for csh
e
s 00066/00015/00873
d D 5.2 85/07/29 10:00:34 mckusick 15 14
c allow at to run with user's permissions (from pur-ee!ks)
e
s 00013/00001/00875
d D 5.1 85/06/06 09:51:23 dist 14 13
c Add copyright
e
s 00007/00001/00869
d D 4.13 85/05/25 13:47:32 kjd 13 12
c Fix prompt routine so that you dont get the prompt when you pipe 
c the input.
e
s 00006/00009/00864
d D 4.12 85/04/25 22:42:32 edward 12 11
c usr getwd(), pwd no longer works (sh doesn't allow setuid)
e
s 00012/00004/00861
d D 4.11 85/04/17 16:41:06 kjd 11 10
c Kevin Dunlap - fix day/year increment bug as per 
c allegra!psuvax!cbosgd!philabs!mcvax!pc@ukc.ac.uk  suggestion.
e
s 00007/00003/00858
d D 4.10 84/08/29 01:01:49 wall 10 9
c Fix small bug in "isprefix" routine.
e
s 00028/00003/00833
d D 4.9 84/08/09 18:16:49 wall 9 8
c modify so that all spoolfiles are owned by "daemon".
e
s 00573/00573/00263
d D 4.8 84/08/02 10:13:57 mckusick 8 7
c reformat, reinsert sccs headers
e
s 00789/00301/00047
d D 4.7 84/08/02 00:27:59 wall 7 6
c MAJOR CHANGES -- added comments (much needed), 3 line header in spoolfile
c (for atq), -m, -s, -c flags, and more error checking.
e
s 00003/00001/00345
d D 4.6 83/07/02 00:54:15 sam 6 5
c include fixes
e
s 00001/00001/00345
d D 4.5 83/04/29 00:28:34 mckusick 5 4
c added perror
e
s 00002/00000/00344
d D 4.4 82/06/28 03:48:15 wnj 4 3
c dates before today must be next year, no?
e
s 00003/00002/00341
d D 4.3 81/07/03 19:31:33 root 3 2
c fix per jag@cmu
e
s 00001/00001/00342
d D 4.2 80/10/21 11:17:25 bill 2 1
c put in the dots
e
s 00343/00000/00000
d D 4.1 80/10/01 17:25:00 bill 1 0
c date and time created 80/10/01 17:25:00 by bill
e
u
U
t
T
I 14
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 14
I 6
#ifndef lint
E 6
I 1
D 7
static char *sccsid = "%W% (Berkeley) %G%";
E 7
I 7
D 8
static char *sccsid = "@(#)at.c 4.6 (Berkeley) 5/25/84";
E 7
I 6
#endif
E 8
I 8
D 14
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 14
I 14
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
E 14
#endif not lint
E 8
I 7

E 7
E 6
/*
D 7
 * at time mon day
 * at time wday
 * at time wday 'week'
E 7
I 7
D 8
 *      Synopsis:       at [-s] [-c] [-m] time [filename]
 *                                              
E 8
I 8
 *	Synopsis:	at [-s] [-c] [-m] time [filename]
 *						
E 8
 * 
E 7
 *
I 7
D 8
 *      Execute commands at a later date.
E 8
I 8
 *	Execute commands at a later date.
E 8
 *
 *
D 8
 *      Modifications by:       Steve Wall
 *                              Computer Systems Research Group
 *                              University of California @ Berkeley
E 8
I 8
 *	Modifications by:	Steve Wall
 *				Computer Systems Research Group
 *				University of California @ Berkeley
E 8
 *
E 7
 */
I 21
#include <sys/param.h>
#include <sys/file.h>
#include <sys/time.h>
E 21
#include <stdio.h>
#include <ctype.h>
D 6
#include <time.h>
E 6
#include <signal.h>
I 9
#include <pwd.h>
I 12
D 21
#include <sys/param.h>
E 12
E 9
I 6
#include <sys/time.h>
I 7
#include <sys/file.h>
E 21
I 21
#include <tzfile.h>
E 21
E 7
E 6

D 7
#define HOUR 100
#define HALFDAY	(12*HOUR)
#define DAY	(24*HOUR)
#define THISDAY "/usr/spool/at"
E 7
I 7
D 8
#define HOUR            100             /* 1 hour (using military time) */
#define HALFDAY         (12 * HOUR)     /* half a day (12 hours) */
#define FULLDAY         (24 * HOUR)     /* a full day (24 hours) */
E 8
I 8
#define HOUR		100		/* 1 hour (using military time) */
#define HALFDAY		(12 * HOUR)	/* half a day (12 hours) */
#define FULLDAY		(24 * HOUR)	/* a full day (24 hours) */
E 8
E 7

D 7
char *days[] = {
	"sunday",
	"monday",
	"tuesday",
	"wednesday",
	"thursday",
	"friday",
	"saturday",
E 7
I 7
D 8
#define WEEK            1               /* day requested is 'week' */
#define DAY             2               /* day requested is a weekday */
#define MONTH           3               /* day requested is a month */
E 8
I 8
#define WEEK		1		/* day requested is 'week' */
#define DAY		2		/* day requested is a weekday */
#define MONTH		3		/* day requested is a month */
E 8

D 8
#define BOURNE          0               /* run commands with Bourne shell*/
#define CSHELL          1               /* run commands with C shell */
E 8
I 8
D 18
#define BOURNE		0		/* run commands with Bourne shell*/
#define CSHELL		1		/* run commands with C shell */
E 18
I 18
#define BOURNE		"/bin/sh"	/* run commands with Bourne shell*/
#define CSHELL		"/bin/csh"	/* run commands with C shell */
E 18
E 8

D 8
#define NODATEFOUND     -1              /* no date was given on command line */
E 8
I 8
#define NODATEFOUND	-1		/* no date was given on command line */
E 8

D 8
#define ATDIR           "/usr/spool/at"         /* spooling area */
E 8
I 8
#define ATDIR		"/usr/spool/at"		/* spooling area */
E 8

I 18
#define LINSIZ		256		/* length of input buffer */
E 18

/*
 * A table to identify potential command line values for "time". 
 *
 * We need this so that we can do some decent error checking on the 
 * command line arguments. (This was inspired by the old "at", which 
 * accepted "at 900 jan 55" as valid input and other small bugs.
 */
struct datetypes {
D 8
        int type;
        char *name;
E 8
I 8
	int type;
	char *name;
E 8
} dates_info[22] = {
D 8
        { DAY,   "sunday"    },
        { DAY,   "monday"    },
        { DAY,   "tuesday"   },
        { DAY,   "wednesday" },
        { DAY,   "thursday"  },
        { DAY,   "friday"    },
        { DAY,   "saturday"  },
        { MONTH, "january"   },
        { MONTH, "february"  },
        { MONTH, "march"     },
        { MONTH, "april"     },
        { MONTH, "may"       },
        { MONTH, "june"      },
        { MONTH, "july"      },
        { MONTH, "august"    },
        { MONTH, "september" },
        { MONTH, "october"   },
        { MONTH, "november"  },
        { MONTH, "december"  },
        { 0, ""},
E 8
I 8
	{ DAY,	 "sunday"    },
	{ DAY,	 "monday"    },
	{ DAY,	 "tuesday"   },
	{ DAY,	 "wednesday" },
	{ DAY,	 "thursday"  },
	{ DAY,	 "friday"    },
	{ DAY,	 "saturday"  },
	{ MONTH, "january"   },
	{ MONTH, "february"  },
	{ MONTH, "march"     },
	{ MONTH, "april"     },
	{ MONTH, "may"	     },
	{ MONTH, "june"	     },
	{ MONTH, "july"	     },
	{ MONTH, "august"    },
	{ MONTH, "september" },
	{ MONTH, "october"   },
	{ MONTH, "november"  },
	{ MONTH, "december"  },
	{ 0, ""},
E 8
E 7
};

D 7
struct monstr {
	char *mname; 
	int mlen;
} months[] = {
	{ "january", 31 },
	{ "february", 28 },
	{ "march", 31 },
	{ "april", 30 },
	{ "may", 31 },
	{ "june", 30 },
	{ "july", 31 },
	{ "august", 31 },
	{ "september", 30 },
	{ "october", 31 },
	{ "november", 30 },
	{ "december", 31 },
	{ 0, 0 },
E 7
I 7
/*
 * Months of the year.
 */
char *months[13] = {
D 8
        "jan", "feb", "mar", "apr", "may", "jun",
        "jul", "aug", "sep", "oct", "nov", "dec", 0,
E 8
I 8
	"jan", "feb", "mar", "apr", "may", "jun",
	"jul", "aug", "sep", "oct", "nov", "dec", 0,
E 8
E 7
};

D 7
char	fname[100];
int	utime;  /* requested time in grains */
int	now;	/* when is it */
int	uday; /* day of year to be done */
int	uyear; /* year */
int	today; /* day of year today */
FILE	*file;
FILE	*ifile;
char	**environ;
char	*prefix();
char    *getenv();
FILE	*popen();
E 7
I 7
/*
 * A table of the number of days in each month of the year.
 *
D 8
 *      yeartable[0] -- normal year
 *      yeartable[1] -- leap year
E 8
I 8
 *	yeartable[0] -- normal year
 *	yeartable[1] -- leap year
E 8
 */
static int yeartable[2][13] = {
D 8
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
E 8
I 8
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
E 8
};
E 7

I 7
/*
 * Structure holding the relevant values needed to create a spoolfile.
 * "attime" will contain the info about when a job is to be run, and
 * "nowtime" will contain info about what time the "at" command is in-
 * voked.
 */
struct times {
D 8
        int year;                       /* year that job is to be run */
        int yday;                       /* day of year that job is to be run */
        int mon;                        /* month of year that job is to be run*/
        int mday;                       /* day of month that job is to be run */
        int wday;                       /* day of week that job is to be run */
        int hour;                       /* hour of day that job is to be run */
        int min;                        /* min. of hour that job is to be run */
E 8
I 8
	int year;			/* year that job is to be run */
	int yday;			/* day of year that job is to be run */
	int mon;			/* month of year that job is to be run*/
	int mday;			/* day of month that job is to be run */
	int wday;			/* day of week that job is to be run */
	int hour;			/* hour of day that job is to be run */
	int min;			/* min. of hour that job is to be run */
E 8
} attime, nowtime;

D 8
char    atfile[100];                    /* name of spoolfile "yy.ddd.hhhh.??" */
char    *getenv();                      /* get info on user's environment */
char    **environ;                      /* user's environment */
FILE    *spoolfile;                     /* spool file */
FILE    *inputfile;                     /* input file ("stdin" or "filename") */
FILE    *popen();                       /* used to get current directory info */
E 8
I 8
D 21
char	atfile[100];			/* name of spoolfile "yy.ddd.hhhh.??" */
E 21
I 21
char	atfile[100];			/* spoolfile name "yyyy.ddd.hhhh.??" */
E 21
char	*getenv();			/* get info on user's environment */
char	**environ;			/* user's environment */
FILE	*spoolfile;			/* spool file */
FILE	*inputfile;			/* input file ("stdin" or "filename") */
D 12
FILE	*popen();			/* used to get current directory info */
E 12
I 12
char	*getwd();			/* used to get current directory info */
E 12
E 8


E 7
main(argc, argv)
I 7
int argc;
E 7
char **argv;
{
D 7
	extern onintr();
	register c;
	char pwbuf[100];
	FILE *pwfil;
	int larg;
	char *tmp;
E 7
I 7
D 8
        int c;                          /* scratch variable */
        int usage();                    /* print usage info and exit */
        int cleanup();                  /* do cleanup on an interrupt signal */
        int dateindex;                  /* if a day is specified, what option
                                           is it? (mon day, week, dayofweek) */
        int shell = 0;                  /* what shell do we use to run job?   
                                           BOURNE = 0   CSHELL = 1 */
        int shflag = 0;                 /* override the current shell and run
                                           job using the Bourne Shell */
        int cshflag = 0;                /* override the current shell and run 
                                           job using the Cshell */
        int mailflag = 0;               /* send mail after a job has been run?*/
        int standardin = 0;             /* are we reading from stardard input */
        char *tmp;                      /* scratch pointer */
        char line[100];                 /* a line from input file */
        char pwbuf[100];                /* the current working directory */
        char *jobfile = "stdin";        /* file containing job to be run */
        FILE *pwfil;                    /* "pwd" process (used to get the
                                           current working directory */
E 8
I 8
	int c;				/* scratch variable */
	int usage();			/* print usage info and exit */
	int cleanup();			/* do cleanup on an interrupt signal */
D 18
	int dateindex;			/* if a day is specified, what option
E 18
I 18
	int dateindex = NODATEFOUND;	/* if a day is specified, what option
E 18
					   is it? (mon day, week, dayofweek) */
D 18
	int shell = 0;			/* what shell do we use to run job?   
					   BOURNE = 0	CSHELL = 1 */
E 18
I 18
	char *shell = BOURNE;		/* what shell do we use to run job? */
E 18
	int shflag = 0;			/* override the current shell and run
					   job using the Bourne Shell */
	int cshflag = 0;		/* override the current shell and run 
					   job using the Cshell */
	int mailflag = 0;		/* send mail after a job has been run?*/
	int standardin = 0;		/* are we reading from stardard input */
	char *tmp;			/* scratch pointer */
D 18
	char line[100];			/* a line from input file */
E 18
I 18
	char line[LINSIZ];		/* a line from input file */
E 18
D 12
	char pwbuf[100];		/* the current working directory */
E 12
I 12
	char pwbuf[MAXPATHLEN];		/* the current working directory */
E 12
	char *jobfile = "stdin";	/* file containing job to be run */
I 9
	char *getname();		/* get the login name of a user */
I 15
	int pid;			/* For forking for security reasons */
E 15
E 9
D 12
	FILE *pwfil;			/* "pwd" process (used to get the
					   current working directory */
E 12
E 8
E 7

D 7
	/* argv[1] is the user's time: e.g.,  3AM */
	/* argv[2] is a month name or day of week */
	/* argv[3] is day of month or 'week' */
	/* another argument might be an input file */
	if (argc < 2) {
		fprintf(stderr, "at: arg count\n");
		exit(1);
	}
	makeutime(argv[1]);
	larg = makeuday(argc,argv)+1;
	if (uday==today && larg<=2 && utime<=now)
		uday++;
I 4
	if (uday < today)
		uyear++;
E 4
	c = uyear%4==0? 366: 365;
	if (uday >= c) {
		uday -= c;
		uyear++;
	}
	filename(THISDAY, uyear, uday, utime);
	/* Create file, then change UIDS */
	close(creat(fname,0644));
	chown(fname,getuid(),getgid());
	setuid(getuid());
	ifile = stdin;
	if (argc > larg)
		ifile = fopen(argv[larg], "r");
	if (ifile == NULL) {
D 5
		fprintf(stderr, "at: cannot open input: %s\n", argv[larg]);
E 5
I 5
		perror(argv[larg]);
E 5
		exit(1);
	}
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, onintr);
	file = fopen(fname, "w");
	if (file == NULL) {
		fprintf(stderr, "at: cannot open memo file\n");
		exit(1);
	}
	if ((pwfil = popen("pwd", "r")) == NULL) {
		fprintf(stderr, "at: can't execute pwd\n");
		exit(1);
	}
	fgets(pwbuf, 100, pwfil);
	pclose(pwfil);
	fprintf(file, "cd %s", pwbuf);
	c = umask(0);
	umask(c);
	fprintf(file, "umask %.1o\n", c);
	if (environ) {
		char **ep = environ;
		while(*ep)
		{
			char *cp;
			for (tmp = *ep, cp = "TERMCAP"; *tmp==*cp; tmp++,cp++);
			if (*cp == 0 && *tmp== '=') {
				ep++;
				continue;
			}
			for(tmp = *ep ; *tmp != '=' ; tmp++) putc(*tmp,file);
			putc('=', file);
			putc('\'', file);
			for (tmp++; *tmp; tmp++) {
				if (*tmp == '\'')
D 3
					putc('\\', file);
				putc(*tmp, file);
E 3
I 3
					fputs("'\\''", file);
				else
					putc(*tmp, file);
E 3
			}
			putc('\'', file);
			fprintf(file, "\nexport ");
			for(tmp = *ep ; *tmp != '=' ; tmp++) putc(*tmp,file);
			putc('\n',file);
			ep++;
		}
	}
	/*
	 * see if the SHELL variable in the current enviroment is /bin/csh
	 * and in that case, use the csh as the shell
	 */
	tmp = getenv("SHELL");
	if (strcmp(tmp+strlen(tmp)-3, "csh") == 0)
		fprintf(file, "%s %s\n", tmp, "<< 'xxFUNNYxx'");
	while((c = getc(ifile)) != EOF) {
		putc(c, file);
	}
	if (strcmp(tmp+strlen(tmp)-3, "csh") == 0)
		fprintf(file, "%s\n", "xxFUNNYxx");
	exit(0);
}
E 7
I 7


D 8
        argv++; argc--;
E 8
I 8
	argv++; argc--;
E 8

D 8
        /*
         * Interpret command line flags if they exist.
         */
        while (argc > 0 && **argv == '-') {
                (*argv)++;
                while (**argv) switch (*(*argv)++) {
E 8
I 8
	/*
	 * Interpret command line flags if they exist.
	 */
	while (argc > 0 && **argv == '-') {
		(*argv)++;
		while (**argv) switch (*(*argv)++) {
E 8

D 8
                        case 'c' :      cshflag++; 
                                        shell = CSHELL;
                                        break;
E 8
I 8
			case 'c' :	cshflag++; 
					shell = CSHELL;
					break;
E 8

D 8
                        case 's' :      shflag++;
                                        shell = BOURNE;
                                        break;
E 8
I 8
			case 's' :	shflag++;
					shell = BOURNE;
					break;
E 8

D 8
                        case 'm' :      mailflag++;
                                        break;
E 8
I 8
			case 'm' :	mailflag++;
					break;
E 8

D 8
                        default  :      usage();
E 8
I 8
			default	 :	usage();
E 8

D 8
                }
                --argc, ++argv;
        }
        if (shflag && cshflag) {
                fprintf(stderr,"ambiguous shell request.\n");
                exit(1);
        }
E 8
I 8
		}
		--argc, ++argv;
	}
	if (shflag && cshflag) {
		fprintf(stderr,"ambiguous shell request.\n");
		exit(1);
	}
E 8
E 7

D 7
makeutime(pp)
char *pp; 
{
	register val;
	register char *p;
E 7
I 7
D 8
        /*
         * Get the time it is when "at" is invoked. We set both nowtime and 
         * attime to this value so that as we interpret the time the job is to
         * be run we can compare the two values to determine such things as
         * whether of not the job should be run the same day the "at" command
         * is given, whether a job is to be run next year, etc.
         */
        getnowtime(&nowtime, &attime);
E 8
I 8
	/*
	 * Get the time it is when "at" is invoked. We set both nowtime and 
	 * attime to this value so that as we interpret the time the job is to
	 * be run we can compare the two values to determine such things as
	 * whether of not the job should be run the same day the "at" command
	 * is given, whether a job is to be run next year, etc.
	 */
	getnowtime(&nowtime, &attime);
E 8
E 7

D 7
	/* p points to a user time */
	p = pp;
	val = 0;
	while(isdigit(*p)) {
		val = val*10+(*p++ -'0');
	}
	if (p-pp < 3)
		val *= HOUR;
E 7
I 7
#ifdef DEBUG
D 8
        printit();
E 8
I 8
	printit();
E 8
#endif
E 7

D 7
	for (;;) {
		switch(*p) {
E 7
I 7
D 8
        if (!(*argv))
                usage();
E 8
I 8
D 18
	if (!(*argv))
E 18
I 18
	if (argc <= 0)
E 18
		usage();
E 8
E 7

D 7
		case ':':
			++p;
			if (isdigit(*p)) {
				if (isdigit(p[1])) {
					val +=(10* *p + p[1] - 11*'0');
					p += 2;
					continue;
				}
			}
			fprintf(stderr, "at: bad time format:\n");
			exit(1);
E 7
I 7
D 8
        /*
         * Interpret argv[1] and create the time of day that the job is to
         * be run. This is the same function that was used in the old "at"
         */
        maketime(&attime, *argv);
        --argc; ++argv;
E 8
I 8
	/*
	 * Interpret argv[1] and create the time of day that the job is to
	 * be run. This is the same function that was used in the old "at"
	 */
	maketime(&attime, *argv);
	--argc; ++argv;
E 8
E 7

D 7
		case 'A':
		case 'a':
			if (val >= HALFDAY+HOUR)
				val = DAY+1;  /* illegal */
			if (val >= HALFDAY && val <(HALFDAY+HOUR))
				val -= HALFDAY;
			break;
E 7
I 7
#ifdef DEBUG
D 8
        printf("\n\nAFTER MAKETIME\n");
        printit();
E 8
I 8
	printf("\n\nAFTER MAKETIME\n");
	printit();
E 8
#endif
E 7

D 7
		case 'P':
		case 'p':
			if (val >= HALFDAY+HOUR)
				val = DAY+1;  /* illegal */
			if (val < HALFDAY)
				val += HALFDAY;
			break;
E 7
I 7
D 8
        /*
         * If no argv[2] exists, then we are reading from standard input
         * and only a time of day has been specified. Therefore, we set
         * the standard input flag, and indicate that a date was not
         * specified (NODATEFOUND).
         */
        if (!*argv) {
                ++standardin;
                dateindex = NODATEFOUND;
        } else {
E 8
I 8
	/*
D 18
	 * If no argv[2] exists, then we are reading from standard input
	 * and only a time of day has been specified. Therefore, we set
	 * the standard input flag, and indicate that a date was not
	 * specified (NODATEFOUND).
	 */
	if (!*argv) {
		++standardin;
		dateindex = NODATEFOUND;
	} else {
E 8
E 7

D 7
		case 'n':
		case 'N':
			val = HALFDAY;
			break;
E 7
I 7
D 8
        /*
         * Otherwise, we are dealing with a request to run a job on a certain
         * day of year or a certain day of week.
         *
         * We send  argv to the function "getdateindex" which returns the 
         * index value of the requested day in the table "dates_info" 
         * (see line 50 for table). If 'getdateindex" returns a NODATEFOUND, 
         * then the requested day format was not found in the table (usually 
         * this means that the argument is a "filename"). If the requested 
         * day is found, we continue to process command line arguments.
         */
                if ((dateindex = getdateindex(*argv)) != NODATEFOUND) {
E 8
I 8
	/*
	 * Otherwise, we are dealing with a request to run a job on a certain
E 18
I 18
	 * If argv[(2)] exists, this is a request to run a job on a certain
E 18
	 * day of year or a certain day of week.
	 *
	 * We send  argv to the function "getdateindex" which returns the 
	 * index value of the requested day in the table "dates_info" 
	 * (see line 50 for table). If 'getdateindex" returns a NODATEFOUND, 
	 * then the requested day format was not found in the table (usually 
	 * this means that the argument is a "filename"). If the requested 
	 * day is found, we continue to process command line arguments.
	 */
I 18
	if (argc > 0) {
E 18
		if ((dateindex = getdateindex(*argv)) != NODATEFOUND) {
E 8
E 7

D 7
		case 'M':
		case 'm':
			val = 0;
			break;
E 7
I 7
D 8
                        ++argv; --argc;
E 8
I 8
			++argv; --argc;
E 8
E 7

I 7
D 8
                        /*
                         * Determine the day of year that the job will be run
                         * depending on the value of argv.
                         */
                        makedayofyear(dateindex, argv);
E 8
I 8
			/*
			 * Determine the day of year that the job will be run
			 * depending on the value of argv.
			 */
D 18
			makedayofyear(dateindex, argv);
E 8
E 7

D 7
		case '\0':
		case ' ':
			/* 24 hour time */
			if (val == DAY)
				val -= DAY;
			break;
E 7
I 7
D 8
                        /*
                         * If we were dealing with the <month day> format,
                         * we need to skip over the next argv (the day of
                         * month).
                         */
                        if (dates_info[dateindex].type == MONTH)
                                ++argv; --argc;
E 8
I 8
			/*
			 * If we were dealing with the <month day> format,
			 * we need to skip over the next argv (the day of
			 * month).
			 */
			if (dates_info[dateindex].type == MONTH)
				++argv; --argc;
E 8
E 7

D 7
		default:
			fprintf(stderr, "at: bad time format\n");
			exit(1);
E 7
I 7
D 8
                        /*
                         * If 'week' was requested, we need to skip over 
                         * the next argv ('week').
                         */
                        if (strcmp(*argv,"week") == 0) 
                                ++argv; --argc;
E 8
I 8
			/*
			 * If 'week' was requested, we need to skip over 
			 * the next argv ('week').
			 */
			if (strcmp(*argv,"week") == 0) 
				++argv; --argc;
E 8
E 7

D 7
		}
		break;
	}
	if (val < 0 || val >= DAY) {
		fprintf(stderr, "at: time out of range\n");
		exit(1);
	}
	if (val%HOUR >= 60) {
		fprintf(stderr, "at: illegal minute field\n");
		exit(1);
	}
	utime = val;
}
E 7
I 7
D 8
                        /*
                         * If no more arguments exist, then we are reading
                         * from standard input. Thus, we set the standard
                         * input flag (++standardin).
                         */
                        if (!(*argv))
                                ++standardin;
                }
        }
E 8
I 8
			/*
			 * If no more arguments exist, then we are reading
			 * from standard input. Thus, we set the standard
			 * input flag (++standardin).
			 */
			if (!(*argv))
				++standardin;
E 18
I 18
			makedayofyear(dateindex, &argv, &argc);
E 18
		}
	}
E 8
E 7

I 7
D 8
        /*
         * If we get to this point and "dateindex" is set to NODATEFOUND,
         * then we are dealing with a request with only a "time" specified
         * (i.e. at 400p) and perhaps 'week' specified (i.e. at 400p week).
         * If 'week' is specified, we just set excecution for 7 days in the
         * future. Otherwise, we need to check to see if the requested time 
         * has already passed for the current day. If it has, then we add 
         * one to the day of year that the job will be executed.
         */
        if (dateindex == NODATEFOUND) {
                if (strncmp(*argv,"week",4) == 0)
                        attime.yday += 7;
E 8
I 8
	/*
	 * If we get to this point and "dateindex" is set to NODATEFOUND,
	 * then we are dealing with a request with only a "time" specified
	 * (i.e. at 400p) and perhaps 'week' specified (i.e. at 400p week).
	 * If 'week' is specified, we just set excecution for 7 days in the
	 * future. Otherwise, we need to check to see if the requested time 
	 * has already passed for the current day. If it has, then we add 
	 * one to the day of year that the job will be executed.
	 */
	if (dateindex == NODATEFOUND) {
I 11
		int daysinyear;
E 11
D 18
		if (strncmp(*argv,"week",4) == 0)
E 18
I 18
		if ((argc > 0) && (strcmp(*argv,"week") == 0)) {
E 18
			attime.yday += 7;
E 8
E 7
D 18

D 7
makeuday(argc,argv)
E 7
I 7
D 8
                else if (istomorrow())
                        ++attime.yday;
        }
E 8
I 8
		else if (istomorrow())
E 18
I 18
			++argv; --argc;
		} else if (istomorrow())
E 18
			++attime.yday;
I 11

		daysinyear = isleap(attime.year) ? 366 : 365;
		if (attime.yday >= daysinyear) {
			attime.yday -= daysinyear;
			++attime.year;
		}
E 11
	}
E 8

I 18
	/*
	 * If no more arguments exist, then we are reading
	 * from standard input. Thus, we set the standard
	 * input flag (++standardin).
	 */
	if (argc <= 0)
		++standardin;
E 18

I 18

E 18
#ifdef DEBUG
D 8
        printf("\n\nAFTER ADDDAYS\n");
        printit();
E 8
I 8
	printf("\n\nAFTER ADDDAYS\n");
	printit();
E 8
#endif

D 8
        /*
         * Start off assuming we're going to read from standard input,
         * but if a filename has been given to read from, open it.
         */
        inputfile = stdin;
        if (!standardin) {
                jobfile = *argv;
                if ((inputfile = fopen(jobfile, "r")) == NULL) {
                        perror(jobfile);
                        exit(1);
                }
        }
E 8
I 8
	/*
	 * Start off assuming we're going to read from standard input,
D 15
	 * but if a filename has been given to read from, open it.
E 15
I 15
	 * but if a filename has been given to read from, we will open it
	 * later.
E 15
	 */
	inputfile = stdin;
D 15
	if (!standardin) {
		jobfile = *argv;
		if ((inputfile = fopen(jobfile, "r")) == NULL) {
			perror(jobfile);
			exit(1);
		}
	}
E 15
E 8

D 8
        /*
         * Create the filename for the spoolfile.
         */
        makeatfile(atfile,attime.year,attime.yday,attime.hour,attime.min);
E 8
I 8
	/*
	 * Create the filename for the spoolfile.
	 */
	makeatfile(atfile,attime.year,attime.yday,attime.hour,attime.min);
E 8

D 8
        /*
         * Open the spoolfile for writing.
         */
        if ((spoolfile = fopen(atfile, "w")) == NULL){
                perror(atfile);
                exit(1);
        }
E 8
I 8
	/*
	 * Open the spoolfile for writing.
	 */
	if ((spoolfile = fopen(atfile, "w")) == NULL){
		perror(atfile);
		exit(1);
	}
E 8

D 8
        /*
         * On an interrupt signal, clean up any open files and unlink the
         * spoolfile.
         */
        signal(SIGINT, cleanup);
        
        /*
         * Determine what shell we should use to run the job. If the user
         * didn't explicitly request that his/her current shell be over-
         * ridden (shflag of cshflag) then we use the current shell.
         */
        if ((!shflag) && (!cshflag)) {
                tmp = getenv("SHELL");
                shell = ((strcmp(tmp+strlen(tmp)-3, "csh") == 0) ? 
                                                        CSHELL : BOURNE);
        }
E 8
I 8
	/*
D 15
	 * On an interrupt signal, clean up any open files and unlink the
	 * spoolfile.
E 15
I 15
	 * Make the file not world readable.
E 15
	 */
D 15
	signal(SIGINT, cleanup);
	
E 15
I 15
	fchmod(fileno(spoolfile), 0400);

E 15
	/*
I 15
	 * The protection mechanism works like this:
D 20
	 * We are running ruid=user, euid=daemon.  So far we have been
	 * messing around in the spool directory, so we needed the
	 * daemon stuff.  Now, we want to read the users file,
	 * so we must give up the daemon protection,  but we might
	 * need the daemon's protection if the user interrupts and
	 * we need to remove the spool files.
	 * So, we fork and let the kid set the real and effective
	 * user id's to the user, so he can read everything of his
	 * own, but not his professor's final exam and not stuff
	 * owned by daemon.  If the kid exits with non-zero status,
	 * that means that the user typed interrupt, and the parent
	 * (still with daemon permissions) removes the spool file.
E 20
I 20
	 * We are running ruid=user, euid=spool owner.  So far we have been
	 * messing around in the spool directory, so we needed to run
	 * as the owner of the spool directory.
	 * We now need to switch to the user's effective uid
	 * to simplify permission checking.  However, we fork first,
	 * so that we can clean up if interrupted.
E 20
	 */
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(1);
	}
	if (pid) {
		int wpid, status;

		/*
		 * We are the parent. If the kid has problems,
		 * cleanup the spool directory.
		 */
		wpid = wait(&status);
		if (wpid != pid || status) {
			cleanup();
			exit(1);
		}
		/*
		 * The kid should have alread flushed the buffers.
		 */
		_exit(0);
	}

	/*
	 * Exit on interrupt.
	 */
	signal(SIGINT, SIG_DFL);

	/*
D 20
	 * We are the kid, give up daemon permissions.
E 20
I 20
	 * We are the kid, give up special permissions.
E 20
	 */
	setuid(getuid());

	/*
	 * Open the input file with the user's permissions.
	 */
	if (!standardin) {
		jobfile = *argv;
		if ((inputfile = fopen(jobfile, "r")) == NULL) {
			perror(jobfile);
			exit(1);
		}
	}
D 20
		
	/*
I 18
	 * If the inputfile is not from a tty then turn off standardin
	 * If the inputfile is a tty, put out a prompt now, instead of
	 * waiting for a lot of file activity to complete.
	 */
	if (!(isatty(fileno(inputfile)))) 
		standardin = 0 ;
	if (standardin) {
		fputs("at> ", stdout);
		fflush(stdout);
	}
E 20

	/*
E 18
E 15
	 * Determine what shell we should use to run the job. If the user
	 * didn't explicitly request that his/her current shell be over-
	 * ridden (shflag of cshflag) then we use the current shell.
	 */
D 18
	if ((!shflag) && (!cshflag)) {
		tmp = getenv("SHELL");
		shell = ((strcmp(tmp+strlen(tmp)-3, "csh") == 0) ? 
							CSHELL : BOURNE);
	}
E 18
I 18
	if ((!shflag) && (!cshflag) && (getenv("SHELL") != NULL))
		shell = "$SHELL";
E 18
E 8

D 8
        /*
         * Put some standard information at the top of the spoolfile.
         * This info is used by the other "at"-oriented programs (atq,
         * atrm, atrun).
         */
        fprintf(spoolfile, "# jobname: %s\n",jobfile);
        fprintf(spoolfile, "# shell: %s\n",(shell == 1) ? "csh" : "sh");
        fprintf(spoolfile, "# notify by mail: %s\n",(mailflag) ? "yes" : "no");
        fprintf(spoolfile, "\n");
E 8
I 8
	/*
	 * Put some standard information at the top of the spoolfile.
	 * This info is used by the other "at"-oriented programs (atq,
	 * atrm, atrun).
	 */
I 9
D 18
	fprintf(spoolfile, "# owner: %s\n",getname(getuid()));
E 9
	fprintf(spoolfile, "# jobname: %s\n",jobfile);
	fprintf(spoolfile, "# shell: %s\n",(shell == 1) ? "csh" : "sh");
E 18
I 18
	fprintf(spoolfile, "# owner: %.127s\n",getname(getuid()));
	fprintf(spoolfile, "# jobname: %.127s\n",jobfile);
	fprintf(spoolfile, "# shell: sh\n");
E 18
	fprintf(spoolfile, "# notify by mail: %s\n",(mailflag) ? "yes" : "no");
	fprintf(spoolfile, "\n");
E 8

D 8
        /*
         * Set the modes for any files created by the job being run.
         */
        c = umask(0);
        umask(c);
        fprintf(spoolfile, "umask %.1o\n", c);
E 8
I 8
	/*
	 * Set the modes for any files created by the job being run.
	 */
	c = umask(0);
	umask(c);
	fprintf(spoolfile, "umask %.1o\n", c);
E 8

D 8
        /*
         * Get the current working directory so we know what directory to 
         * run the job from.
         */
        if ((pwfil = popen("pwd", "r")) == NULL) {
                fprintf(stderr, "at: can't execute pwd\n");
                exit(1);
        }
        fgets(pwbuf, 100, pwfil);
        fprintf(spoolfile, "cd %s\n",pwbuf);
        pclose(pwfil);
E 8
I 8
	/*
	 * Get the current working directory so we know what directory to 
	 * run the job from.
	 */
D 12
	if ((pwfil = popen("pwd", "r")) == NULL) {
		fprintf(stderr, "at: can't execute pwd\n");
E 12
I 12
	if (getwd(pwbuf) == NULL) {
		fprintf(stderr, "at: can't get working directory\n");
E 12
		exit(1);
	}
D 12
	fgets(pwbuf, 100, pwfil);
	fprintf(spoolfile, "cd %s\n",pwbuf);
	pclose(pwfil);
E 12
I 12
	fprintf(spoolfile, "cd %s\n", pwbuf);
E 12
E 8

D 8
        /*
         * Copy the user's environment to the spoolfile.
         */
        if (environ) {
                copyenvironment(shell,&spoolfile);
        }
E 8
I 8
	/*
	 * Copy the user's environment to the spoolfile.
	 */
	if (environ) {
D 18
		copyenvironment(shell,&spoolfile);
E 18
I 18
		copyenvironment(&spoolfile);
E 18
	}
E 8

D 8
        /*
         * Now that we have all the files set up, we can start reading in
         * the job. (I added the prompt "at>" so that the user could tell
         * when/if he/she was supposed to enter commands from standard
         * input. The old "at" just sat there and didn't send any kind of 
         * message that said it was waiting for input if it was reading
         * form standard input).
         */
        while(fputs((standardin) ? "at> " : "",stdout) 
                                && (fgets(line,100,inputfile) != NULL)) {
                fputs(line, spoolfile);
        }
E 8
I 8
	/*
I 13
D 18
	 * If the inputfile is not from a tty then turn off standardin
E 18
I 18
	 * Put in a line to run the proper shell using the rest of
	 * the file as input.  Note that 'exec'ing the shell will
D 20
	 * cause sh() to leave a /tmp/sh### file around.
E 20
I 20
	 * cause sh() to leave a /tmp/sh### file around.  This line
	 * depends on the shells allowing EOF to end tagged input.  The
	 * quotes also guarantee a quoting of the lines before EOF.
E 20
E 18
	 */
D 18
	if (!(isatty(fileno(inputfile)))) 
		standardin = 0 ;
E 18
I 18
D 20
	fprintf(spoolfile,
	    "%s << '...the rest of this file is shell input'\n", shell);
E 20
I 20
	fprintf(spoolfile, "%s << 'QAZWSXEDCRFVTGBYHNUJMIKOLP'\n", shell);
E 20
E 18

	/*
E 13
	 * Now that we have all the files set up, we can start reading in
D 20
	 * the job. (I added the prompt "at>" so that the user could tell
	 * when/if he/she was supposed to enter commands from standard
	 * input. The old "at" just sat there and didn't send any kind of 
	 * message that said it was waiting for input if it was reading
	 * form standard input).
E 20
I 20
	 * the job.
E 20
	 */
D 13
	while(fputs((standardin) ? "at> " : "",stdout) 
E 13
I 13
D 18
	while(fputs((standardin) ? "at> " : "",stdout) != EOF
E 13
				&& (fgets(line,100,inputfile) != NULL)) {
E 18
I 18
D 20
	while (fgets(line, LINSIZ, inputfile) != NULL) {
E 20
I 20
	while (fgets(line, LINSIZ, inputfile) != NULL)
E 20
E 18
		fputs(line, spoolfile);
I 18
D 20
		if (standardin)
			fputs("at> ", stdout);
E 18
	}
I 18
	if (standardin)
		fputs("<EOT>\n", stdout);	/* clean up the final output */
E 20
E 18
E 8

D 8
        /*
         * Close all files and change the mode and the owner of the spoolfile.
         */
        fclose(inputfile);
        fclose(spoolfile);
        chmod(atfile,0644);
        chown(atfile,getuid(),getgid());
E 8
I 8
	/*
D 9
	 * Close all files and change the mode and the owner of the spoolfile.
E 9
I 9
	 * Close all files and change the mode of the spoolfile.
E 9
	 */
	fclose(inputfile);
	fclose(spoolfile);
D 9
	chmod(atfile,0644);
	chown(atfile,getuid(),getgid());
E 9
I 9
D 15
	chmod(atfile,0444);
E 15
E 9
E 8

D 8
        exit(0);
E 8
I 8
	exit(0);
E 8

}

/*
D 18
 * Copy the user's environment to the spoolfile. Depending on the value of
 * "shell" we convert the environment values so they correspond to the syntax 
 * of the Cshell (1) or the Bourne shell (0). This thing DOES work, although 
 * it may look a bit kludgey.
E 18
I 18
 * Copy the user's environment to the spoolfile in the syntax of the
 * Bourne shell.  After the environment is set up, the proper shell
 * will be invoked.
E 18
 */
D 18
copyenvironment(shell,spoolfile)
int shell;
E 18
I 18
copyenvironment(spoolfile)
E 18
FILE **spoolfile;
{
D 8
        char *tmp;                      /* scratch pointer */
        char **environptr = environ;    /* pointer to an environment setting */
E 8
I 8
	char *tmp;			/* scratch pointer */
	char **environptr = environ;	/* pointer to an environment setting */
E 8

I 17
D 18
	if (shell == CSHELL) {
		fprintf(*spoolfile, "if ($?histchars) then\n");
		fprintf(*spoolfile, "set xxhist=$histchars\nendif\n");
		fprintf(*spoolfile, "set histchars=''\n");
		fprintf(*spoolfile, "set noglob\n");
	}
E 18
E 17
D 8
        while(*environptr) {
                tmp = *environptr;
E 8
I 8
	while(*environptr) {
		tmp = *environptr;
E 8

D 8
                /*
                 * We don't want the termcap or terminal entry so skip them.
                 */
                if (strncmp(tmp,"TERM",4) == 0) {
                        ++environptr;
                        continue;
                }
E 8
I 8
		/*
		 * We don't want the termcap or terminal entry so skip them.
		 */
D 18
		if (strncmp(tmp,"TERM",4) == 0) {
E 18
I 18
		if ((strncmp(tmp,"TERM=",5) == 0) ||
		    (strncmp(tmp,"TERMCAP=",8) == 0)) {
E 18
			++environptr;
			continue;
		}
E 8

D 8
                /*
                 * Set up the proper syntax. ("setenv xx yy" for the Cshell
                 * and "xx = 'yy'" for the Bourne shell).
                 */
                if (shell == CSHELL)
                        fputs("setenv ",*spoolfile);
                while (*tmp != '=')
                        fputc(*tmp++,*spoolfile);
                if (shell == BOURNE) {
                        fputc('=', *spoolfile);
                }
                fputs((shell == CSHELL) ? " \"" : "'" , *spoolfile);
                ++tmp;
E 8
I 8
		/*
D 18
		 * Set up the proper syntax. ("setenv xx yy" for the Cshell
		 * and "xx = 'yy'" for the Bourne shell).
E 18
I 18
		 * Set up the proper syntax.
E 18
		 */
D 18
		if (shell == CSHELL)
			fputs("setenv ",*spoolfile);
E 18
		while (*tmp != '=')
			fputc(*tmp++,*spoolfile);
D 18
		if (shell == BOURNE) {
			fputc('=', *spoolfile);
		}
		fputs((shell == CSHELL) ? " \"" : "'" , *spoolfile);
E 18
I 18
		fputc('=', *spoolfile);
		fputc('\'' , *spoolfile);
E 18
		++tmp;
E 8

D 8
                /*
                 * Now copy the entry.
                 */
                while (*tmp) {
                        if (*tmp == '\'')
                                fputs("'\\''", *spoolfile);
                        else if (*tmp == '\n')
                                fputs("\\",*spoolfile);
                        else
                                fputc(*tmp, *spoolfile);
                        ++tmp;
                }
                fputc((shell == CSHELL) ? '"' : '\'' , *spoolfile);
E 8
I 8
		/*
		 * Now copy the entry.
		 */
		while (*tmp) {
			if (*tmp == '\'')
				fputs("'\\''", *spoolfile);
			else if (*tmp == '\n')
				fputs("\\",*spoolfile);
			else
				fputc(*tmp, *spoolfile);
			++tmp;
		}
D 18
		fputc((shell == CSHELL) ? '"' : '\'' , *spoolfile);
E 18
I 18
		fputc('\'' , *spoolfile);
E 18
E 8

D 8
                /*
                 * If it's the Bourne shell, we need to "export" environment
                 * settings.
                 */
                if (shell == BOURNE) {
                        fprintf(*spoolfile, "\nexport ");
                        tmp = *environptr;
                        while (*tmp != '=')
                                fputc(*tmp++,*spoolfile);
                }
                fputc('\n',*spoolfile);
                ++environptr;
        }
        /*
         * My god, it worked! (I hope)
         */
        return;
}
E 8
I 8
		/*
D 18
		 * If it's the Bourne shell, we need to "export" environment
		 * settings.
E 18
I 18
		 * We need to "export" environment settings.
E 18
		 */
D 18
		if (shell == BOURNE) {
			fprintf(*spoolfile, "\nexport ");
			tmp = *environptr;
			while (*tmp != '=')
				fputc(*tmp++,*spoolfile);
		}
E 18
I 18
		fprintf(*spoolfile, "\nexport ");
		tmp = *environptr;
		while (*tmp != '=')
			fputc(*tmp++,*spoolfile);
E 18
		fputc('\n',*spoolfile);
		++environptr;
I 17
	}
D 18
	if (shell == CSHELL) {
		fprintf(*spoolfile, "unset noglob\n");
		fprintf(*spoolfile, "if ($?xxhist) then\n");
		fprintf(*spoolfile, "set histchars=$xxhist\nelse\n");
		fprintf(*spoolfile, "unset histchars\nendif\n");
E 17
	}
	/*
	 * My god, it worked! (I hope)
	 */
E 18
	return;
}
E 8

/*
D 21
 * Create the filename for the spoolfile. The format is "yy.ddd.mmmm.??"
 * where "yy" is the year the job will be run, "ddd" the day of year, 
E 21
I 21
 * Create the filename for the spoolfile. The format is "yyyy.ddd.mmmm.??"
 * where "yyyy" is the year the job will be run, "ddd" the day of year, 
E 21
 * "mmmm" the hour and minute, and "??" a scratch value used to dis-
 * tinguish between two files that are to be run at the same time.
 */
makeatfile(atfile,year,dayofyear,hour,minute)
int year;
int hour;
int minute;
int dayofyear;
char *atfile;
{
D 8
        int i;                          /* scratch variable */
E 8
I 8
	int i;				/* scratch variable */
E 8

D 8
        for (i=0; ; i += 53) {
                sprintf(atfile, "%s/%02d.%03d.%02d%02d.%02d", ATDIR, year,
                        dayofyear, hour, minute, (getpid() + i) % 100);
E 8
I 8
	for (i=0; ; i += 53) {
D 21
		sprintf(atfile, "%s/%02d.%03d.%02d%02d.%02d", ATDIR, year,
E 21
I 21
		sprintf(atfile, "%s/%04d.%03d.%02d%02d.%02d", ATDIR, year,
E 21
			dayofyear, hour, minute, (getpid() + i) % 100);
E 8

D 8
                /*
                 * Make sure that the file name that we've created is unique.
                 */
                if (access(atfile, F_OK) == -1)
                        return;
        }
E 8
I 8
		/*
		 * Make sure that the file name that we've created is unique.
		 */
		if (access(atfile, F_OK) == -1)
			return;
	}
E 8
}

/*
 * Has the requested time already passed for the currrent day? If so, we
 * will run the job "tomorrow".
 */
istomorrow()
{
D 8
        if (attime.hour < nowtime.hour)
                return(1);
        if ((attime.hour == nowtime.hour) && (attime.min < nowtime.min))
                return(1);
E 8
I 8
	if (attime.hour < nowtime.hour)
		return(1);
	if ((attime.hour == nowtime.hour) && (attime.min < nowtime.min))
		return(1);
E 8

D 8
        return(0);
E 8
I 8
	return(0);
E 8
}

/*
 * Debugging wreckage.
 */
printit()
{
D 8
        printf("YEAR\tnowtime: %d\tattime: %d\n",nowtime.year,attime.year);
        printf("YDAY\tnowtime: %d\tattime: %d\n",nowtime.yday,attime.yday);
        printf("MON\tnowtime: %d\tattime: %d\n",nowtime.mon,attime.mon);
        printf("MONDAY\tnowtime: %d\tattime: %d\n",nowtime.mday,attime.mday);
        printf("WDAY\tnowtime: %d\tattime: %d\n",nowtime.wday,attime.wday);
        printf("HOUR\tnowtime: %d\tattime: %d\n",nowtime.hour,attime.hour);
        printf("MIN\tnowtime: %d\tattime: %d\n",nowtime.min,attime.min);
E 8
I 8
	printf("YEAR\tnowtime: %d\tattime: %d\n",nowtime.year,attime.year);
	printf("YDAY\tnowtime: %d\tattime: %d\n",nowtime.yday,attime.yday);
	printf("MON\tnowtime: %d\tattime: %d\n",nowtime.mon,attime.mon);
	printf("MONDAY\tnowtime: %d\tattime: %d\n",nowtime.mday,attime.mday);
	printf("WDAY\tnowtime: %d\tattime: %d\n",nowtime.wday,attime.wday);
	printf("HOUR\tnowtime: %d\tattime: %d\n",nowtime.hour,attime.hour);
	printf("MIN\tnowtime: %d\tattime: %d\n",nowtime.min,attime.min);
E 8
}

/*
 * Calculate the day of year that the job will be executed.
I 18
 * The av,ac arguments are ptrs to argv,argc; updated as necessary.
E 18
 */
D 18
makedayofyear(dateindex,argv)
E 7
char **argv;
E 18
I 18
makedayofyear(dateindex, av, ac)
E 18
I 7
int dateindex;
I 18
char ***av;
int *ac;
E 18
E 7
{
D 7
	/* the presumption is that argv[2], argv[3] are either
	   month day OR weekday [week].  Returns either 2 or 3 as last
	   argument used */
	/* first of all, what's today */
	long tm;
	int found = -1;
	char **ps;
	struct tm *detail, *localtime();
	struct monstr *pt;
E 7
I 7
D 8
        
        char *ptr;                              /* scratch pointer */
        struct datetypes *daterequested;        /* pointer to information about
                                                   the type of date option
                                                   we're dealing with */
E 8
I 8
D 18
	
E 18
I 18
	char **argv = *av;	/* imitate argc,argv and update args at end */
	int argc = *ac;
E 18
	char *ptr;				/* scratch pointer */
	struct datetypes *daterequested;	/* pointer to information about
						   the type of date option
						   we're dealing with */
E 8
E 7

D 7
	time(&tm);
	detail = localtime(&tm);
	uday = today = detail->tm_yday;
	uyear = detail->tm_year;
	now = detail->tm_hour*100+detail->tm_min;
	if (argc<=2)
		return(1);
	/* is the next argument a month name ? */
	for (pt=months; pt->mname; pt++) {
		if (prefix(argv[2], pt->mname)) {
			if (found<0)
				found = pt-months;
			else {
				fprintf(stderr, "at: ambiguous month\n");
				exit(1);
			}
		}
	}
	if (found>=0) {
		if (argc<=3)
			return(2);
		uday = atoi(argv[3]) - 1;
		if (uday<0) {
			fprintf(stderr, "at: illegal day\n");
			exit(1);
		}
		while(--found>=0)
			uday += months[found].mlen;
		if (detail->tm_year%4==0 && uday>59)
			uday += 1;
		return(3);
	}
	/* not a month, try day of week */
	found = -1;
	for (ps=days; ps<days+7; ps++) {
		if (prefix(argv[2], *ps)) {
			if (found<0)
				found = ps-days;
			else {
				fprintf(stderr, "at: ambiguous day of week\n");
				exit(1);
			}
		}
	}
	if (found<0)
		return(1);
	/* find next day of this sort */
	uday = found - detail->tm_wday;
	if (uday<=0)
		uday += 7;
	uday += today;
	if (argc>3 && strcmp("week", argv[3])==0) {
		uday += 7;
		return(3);
	}
	return(2);
}
E 7
I 7
D 8
        daterequested = &dates_info[dateindex];
E 8
I 8
	daterequested = &dates_info[dateindex];
E 8

D 8
        /*
         * If we're dealing with a day of week, determine the number of days
         * in the future the next day of this type will fall on. Add this
         * value to "attime.yday".
         */
        if (daterequested->type == DAY) {
                if (attime.wday < dateindex) 
                        attime.yday += dateindex - attime.wday;
                else if(attime.wday > dateindex) 
                        attime.yday += (7 - attime.wday) + dateindex;
                else attime.yday += 7;
        }
E 8
I 8
	/*
	 * If we're dealing with a day of week, determine the number of days
	 * in the future the next day of this type will fall on. Add this
	 * value to "attime.yday".
	 */
	if (daterequested->type == DAY) {
		if (attime.wday < dateindex) 
			attime.yday += dateindex - attime.wday;
		else if(attime.wday > dateindex) 
			attime.yday += (7 - attime.wday) + dateindex;
		else attime.yday += 7;
	}
E 8

D 8
        /*
         * If we're dealing with a month and day of month, determine the
         * day of year that this date will fall on.
         */
        if (daterequested->type == MONTH) {
E 8
I 8
	/*
	 * If we're dealing with a month and day of month, determine the
	 * day of year that this date will fall on.
	 */
	if (daterequested->type == MONTH) {
E 8

D 8
                /*
                 * If a day of month isn't specified, print a message
                 * and exit.
                 */
                if (!*argv) {
                        fprintf(stderr,"day of month not specified.\n");
                        exit(1);
                }
E 8
I 8
		/*
		 * If a day of month isn't specified, print a message
		 * and exit.
		 */
D 18
		if (!*argv) {
E 18
I 18
		if (argc <= 0) {
E 18
			fprintf(stderr,"day of month not specified.\n");
			exit(1);
		}
E 8
E 7

D 7
char *
prefix(begin, full)
char *begin, *full;
E 7
I 7
D 8
                /*
                 * Scan the day of month value and make sure that it
                 * has no characters in it. If characters are found or
                 * the day requested is zero, print a message and exit.
                 */
                ptr = *argv;
                while (isdigit(*ptr))
                        ++ptr;
                if ((*ptr != '\0') || (atoi(*argv) == 0)) {
                        fprintf(stderr,"\"%s\": illegal day of month\n",*argv);
                        exit(1);
                }
E 8
I 8
		/*
		 * Scan the day of month value and make sure that it
		 * has no characters in it. If characters are found or
		 * the day requested is zero, print a message and exit.
		 */
		ptr = *argv;
		while (isdigit(*ptr))
			++ptr;
		if ((*ptr != '\0') || (atoi(*argv) == 0)) {
			fprintf(stderr,"\"%s\": illegal day of month\n",*argv);
			exit(1);
		}
E 8

D 8
                /*
                 * Set the month of year and day of month values. Since
                 * the first 7 values in our dateinfo table do not deal
                 * with month names, we subtract 7 from the month of year
                 * value.
                 */
                attime.mon = (dateindex - 7);
                attime.mday = (atoi(*argv) - 1);
E 8
I 8
		/*
		 * Set the month of year and day of month values. Since
		 * the first 7 values in our dateinfo table do not deal
		 * with month names, we subtract 7 from the month of year
		 * value.
		 */
		attime.mon = (dateindex - 7);
		attime.mday = (atoi(*argv) - 1);
E 8

D 8
                /*
                 * Test the day of month value to make sure that the
                 * value is legal.
                 */
                if ((attime.mday + 1) > 
                    yeartable[isleap(attime.year)][attime.mon + 1]) {
                        fprintf(stderr,"\"%s\": illegal day of month\n",*argv);
                        exit(1);
                }
E 8
I 8
		/*
		 * Test the day of month value to make sure that the
		 * value is legal.
		 */
		if ((attime.mday + 1) > 
		    yeartable[isleap(attime.year)][attime.mon + 1]) {
			fprintf(stderr,"\"%s\": illegal day of month\n",*argv);
			exit(1);
		}
E 8

D 8
                /*
                 * Finally, we determine the day of year.
                 */
                attime.yday = (countdays());
                ++argv;
        }
E 8
I 8
		/*
		 * Finally, we determine the day of year.
		 */
		attime.yday = (countdays());
D 18
		++argv;
E 18
I 18
		++argv; --argc;
E 18
	}
E 8

D 8
        /*
         * If 'week' is specified, add 7 to the day of year.
         */
        if (strncmp(*argv,"week",4) == 0)
                attime.yday += 7;
E 8
I 8
	/*
	 * If 'week' is specified, add 7 to the day of year.
	 */
D 18
	if (strncmp(*argv,"week",4) == 0)
E 18
I 18
	if ((argc > 0) && (strcmp(*argv,"week") == 0)) {
E 18
		attime.yday += 7;
I 18
		++argv; --argc;
	}
E 18
E 8

D 8
        /*
         * Now that all that is done, see if the requested execution time
         * has already passed for this year, and if it has, set execution
         * for next year.
         */
        if (isnextyear())
                ++attime.year;
E 8
I 8
	/*
	 * Now that all that is done, see if the requested execution time
	 * has already passed for this year, and if it has, set execution
	 * for next year.
	 */
	if (isnextyear())
		++attime.year;
I 18
	
	/*
	 * Finally, reflect the updated argc,argv to the caller
	 */
	*av = argv;
	*ac = argc;
E 18
E 8
}

/*
 * Should the job be run next year? We check for the following situations:
 *
D 8
 *      1) the requested time has already passed for the current year. 
 *      2) the day of year is greater than the number of days in the year. 
E 8
I 8
 *	1) the requested time has already passed for the current year. 
 *	2) the day of year is greater than the number of days in the year. 
E 8
 *
 * If either of these tests succeed, we increment "attime.year" by 1. 
 * If #2 is true, we also subtract the number of days in the current year
 * from "attime.yday". #2 can only occur if someone specifies a job to
 * be run "tomorrow" on Dec. 31 or if they specify a job to be run a
 * 'week' later and the date is at least Dec. 24. (I think so anyway)
 */
isnextyear()
E 7
D 11
{
E 11
I 11
{	register daysinyear;
E 11
D 7
	int c;
	while (c = *begin++) {
		if (isupper(c))
			c = tolower(c);
		if (*full != c)
			return(0);
		else
			full++;
	}
	return(full);
E 7
I 7
D 8
        if (attime.yday < nowtime.yday)
                return(1);
E 8
I 8
	if (attime.yday < nowtime.yday)
		return(1);
E 8

D 8
        if ((attime.yday == nowtime.yday) && (attime.hour < nowtime.hour))
                return(1);
E 8
I 8
	if ((attime.yday == nowtime.yday) && (attime.hour < nowtime.hour))
		return(1);
E 8

D 8
        if ((attime.yday == nowtime.yday) && (attime.hour == nowtime.hour) 
                                && (attime.min < nowtime.min))
                return(1);
E 8
I 8
D 11
	if ((attime.yday == nowtime.yday) && (attime.hour == nowtime.hour) 
				&& (attime.min < nowtime.min))
E 11
I 11
	daysinyear = isleap(attime.year) ? 366 : 365;
	if (attime.yday >= daysinyear) {
		attime.yday -= daysinyear;
E 11
		return(1);
E 8
D 11

E 11
I 11
	}
E 11
D 8
        if (attime.yday > (isleap(attime.year) ? 366 : 365)) {
                attime.yday -= (isleap(attime.year) ? 366 : 365);
                return(1);
        }
E 8
I 8
	if (attime.yday > (isleap(attime.year) ? 366 : 365)) {
		attime.yday -= (isleap(attime.year) ? 366 : 365);
		return(1);
	}
E 8

D 8
        return(0);
E 8
I 8
	return(0);
E 8
E 7
}

D 7
filename(dir, y, d, t)
char *dir;
E 7
I 7
/*
 * Determine the day of year given a month and day of month value.
 */
countdays()
E 7
{
D 7
	register i;
E 7
I 7
D 8
        int leap;                       /* are we dealing with a leap year? */
        int dayofyear;                  /* the day of year after conversion */
        int monthofyear;                /* the month of year that we are
                                           dealing with */
E 8
I 8
	int leap;			/* are we dealing with a leap year? */
	int dayofyear;			/* the day of year after conversion */
	int monthofyear;		/* the month of year that we are
					   dealing with */
E 8
E 7

D 7
	for (i=0; ; i += 53) {
D 2
		sprintf(fname, "%s/%.2d%.3d%.4d%.2d", dir, y, d, t,
E 2
I 2
		sprintf(fname, "%s/%02d.%03d.%04d.%02d", dir, y, d, t,
E 2
		   (getpid()+i)%100);
		if (access(fname, 0) == -1)
			return;
	}
E 7
I 7
D 8
        /*
         * Are we dealing with a leap year?
         */
        leap = isleap(attime.year);
E 8
I 8
	/*
	 * Are we dealing with a leap year?
	 */
	leap = isleap(attime.year);
E 8

D 8
        monthofyear = attime.mon;
        dayofyear = attime.mday;
E 8
I 8
	monthofyear = attime.mon;
	dayofyear = attime.mday;
E 8

D 8
        /*
         * Determine the day of year.
         */
        while (monthofyear > 0)
                dayofyear += yeartable[leap][monthofyear--];
E 8
I 8
	/*
	 * Determine the day of year.
	 */
	while (monthofyear > 0)
		dayofyear += yeartable[leap][monthofyear--];
E 8

D 8
        return(dayofyear);
E 8
I 8
	return(dayofyear);
E 8
E 7
}

D 7
onintr()
E 7
I 7
D 21
/*
 * Is a year a leap year?
 */
isleap(year)
int year;

E 7
{
D 7
	unlink(fname);
	exit(1);
E 7
I 7
D 8
        return((year%4 == 0 && year%100 != 0) || year%100 == 0);
E 8
I 8
	return((year%4 == 0 && year%100 != 0) || year%100 == 0);
E 8
E 7
}
I 7

E 21
getdateindex(date)
char *date;
{
D 8
        int i = 0;
        struct datetypes *ptr;
E 8
I 8
	int i = 0;
	struct datetypes *ptr;
E 8

D 8
        ptr = dates_info;
E 8
I 8
	ptr = dates_info;
E 8

D 8
        for (ptr = dates_info; ptr->type != 0; ptr++, i++) {
                if (isprefix(date, ptr->name))
                        return(i);
        }
        return(-1);
E 8
I 8
	for (ptr = dates_info; ptr->type != 0; ptr++, i++) {
		if (isprefix(date, ptr->name))
			return(i);
	}
D 18
	return(-1);
E 18
I 18
	return(NODATEFOUND);
E 18
E 8
}

isprefix(prefix, fullname)
char *prefix, *fullname;
{
I 10
	char ch;
E 10
D 8
        char *ptr;
        char *ptr1;
E 8
I 8
	char *ptr;
	char *ptr1;
E 8

D 8
        ptr = prefix;
        ptr1 = fullname;
E 8
I 8
	ptr = prefix;
	ptr1 = fullname;
E 8

D 8
        while (*ptr) {
                if (isupper(*ptr))
                        *ptr = tolower(*ptr);
E 8
I 8
	while (*ptr) {
D 10
		if (isupper(*ptr))
			*ptr = tolower(*ptr);
E 10
I 10
		ch = *ptr;
		if (isupper(ch))
			ch = tolower(ch);
E 10
E 8

D 8
                if (*ptr++ != *ptr1++)
                        return(0);
        }
        return(1);
E 8
I 8
D 10
		if (*ptr++ != *ptr1++)
E 10
I 10
		if (ch != *ptr1++)
E 10
			return(0);
I 10

		++ptr;
E 10
	}
	return(1);
E 8
}

getnowtime(nowtime, attime)
struct times *nowtime;
struct times *attime;
{
D 8
        struct tm *now;
        struct timeval time;
        struct timezone zone;
E 8
I 8
	struct tm *now;
	struct timeval time;
	struct timezone zone;
E 8

D 8
        if (gettimeofday(&time,&zone) < 0) {
                perror("gettimeofday");
                exit(1);
        }
        now = localtime(&time.tv_sec);
E 8
I 8
	if (gettimeofday(&time,&zone) < 0) {
		perror("gettimeofday");
		exit(1);
	}
	now = localtime(&time.tv_sec);
E 8

D 8
        attime->year = nowtime->year = now->tm_year;
        attime->yday = nowtime->yday = now->tm_yday;
        attime->mon = nowtime->mon = now->tm_mon;
        attime->mday = nowtime->mday = now->tm_mday;
        attime->wday = nowtime->wday = now->tm_wday;
        attime->hour = nowtime->hour = now->tm_hour;
        attime->min = nowtime->min = now->tm_min;
E 8
I 8
D 21
	attime->year = nowtime->year = now->tm_year;
E 21
I 21
	attime->year = nowtime->year = now->tm_year + TM_YEAR_BASE;
E 21
	attime->yday = nowtime->yday = now->tm_yday;
	attime->mon = nowtime->mon = now->tm_mon;
	attime->mday = nowtime->mday = now->tm_mday;
	attime->wday = nowtime->wday = now->tm_wday;
	attime->hour = nowtime->hour = now->tm_hour;
	attime->min = nowtime->min = now->tm_min;
E 8
}

/*
 * This is the same routine used in the old "at", so I won't bother
 * commenting it. It'll give you an idea of what the code looked
 * like when I got it.
 */
maketime(attime,ptr)
char *ptr;
struct times *attime;
{
D 8
        int val;
        char *p;
E 8
I 8
	int val;
	char *p;
E 8

D 8
        p = ptr;
        val = 0;
        while(isdigit(*p)) {
                val = val*10+(*p++ -'0');
        }
        if (p-ptr < 3)
                val *= HOUR;
E 8
I 8
	p = ptr;
	val = 0;
	while(isdigit(*p)) {
		val = val*10+(*p++ -'0');
	}
	if (p-ptr < 3)
		val *= HOUR;
E 8

D 8
        for (;;) {
                switch(*p) {
E 8
I 8
	for (;;) {
		switch(*p) {
E 8

D 8
                case ':':
                        ++p;
                        if (isdigit(*p)) {
                                if (isdigit(p[1])) {
                                        val +=(10* *p + p[1] - 11*'0');
                                        p += 2;
                                        continue;
                                }
                        }
                        fprintf(stderr, "bad time format:\n");
                        exit(1);
E 8
I 8
		case ':':
			++p;
			if (isdigit(*p)) {
				if (isdigit(p[1])) {
					val +=(10* *p + p[1] - 11*'0');
					p += 2;
					continue;
				}
			}
			fprintf(stderr, "bad time format:\n");
			exit(1);
E 8

D 8
                case 'A':
                case 'a':
                        if (val >= HALFDAY+HOUR)
                                val = FULLDAY+1;  /* illegal */
                        if (val >= HALFDAY && val <(HALFDAY+HOUR))
                                val -= HALFDAY;
                        break;
E 8
I 8
		case 'A':
		case 'a':
			if (val >= HALFDAY+HOUR)
				val = FULLDAY+1;  /* illegal */
			if (val >= HALFDAY && val <(HALFDAY+HOUR))
				val -= HALFDAY;
			break;
E 8

D 8
                case 'P':
                case 'p':
                        if (val >= HALFDAY+HOUR)
                                val = FULLDAY+1;  /* illegal */
                        if (val < HALFDAY)
                                val += HALFDAY;
                        break;
E 8
I 8
		case 'P':
		case 'p':
			if (val >= HALFDAY+HOUR)
				val = FULLDAY+1;  /* illegal */
			if (val < HALFDAY)
				val += HALFDAY;
			break;
E 8

D 8
                case 'n':
                case 'N':
                        val = HALFDAY;
                        break;
E 8
I 8
		case 'n':
		case 'N':
D 18
			val = HALFDAY;
E 18
I 18
			if ((val == 0) || (val == HALFDAY))
				val = HALFDAY;
			else
				val = FULLDAY+1;  /* illegal */
E 18
			break;
E 8

D 8
                case 'M':
                case 'm':
                        val = 0;
                        break;
E 8
I 8
		case 'M':
		case 'm':
D 18
			val = 0;
E 18
I 18
			if ((val == 0) || (val == HALFDAY))
				val = 0;
			else
				val = FULLDAY+1;  /* illegal */
E 18
			break;
E 8


D 8
                case '\0':
                case ' ':
                        /* 24 hour time */
                        if (val == FULLDAY)
                                val -= FULLDAY;
                        break;
E 8
I 8
		case '\0':
		case ' ':
			/* 24 hour time */
			if (val == FULLDAY)
				val -= FULLDAY;
			break;
E 8

D 8
                default:
                        fprintf(stderr, "bad time format\n");
                        exit(1);
E 8
I 8
		default:
			fprintf(stderr, "bad time format\n");
			exit(1);
E 8

D 8
                }
                break;
        }
        if (val < 0 || val >= FULLDAY) {
                fprintf(stderr, "time out of range\n");
                exit(1);
        }
        if (val%HOUR >= 60) {
                fprintf(stderr, "illegal minute field\n");
                exit(1);
        }
        attime->hour = val/100;
        attime->min = val%100;
}
E 8
I 8
		}
		break;
	}
	if (val < 0 || val >= FULLDAY) {
		fprintf(stderr, "time out of range\n");
		exit(1);
	}
	if (val%HOUR >= 60) {
		fprintf(stderr, "illegal minute field\n");
		exit(1);
	}
D 18
	attime->hour = val/100;
	attime->min = val%100;
E 18
I 18
	attime->hour = val/HOUR;
	attime->min = val%HOUR;
E 18
}
E 8

I 9
/*
 * Get the full login name of a person using his/her user id.
 */
char *
getname(uid)
int uid;
{
	struct passwd *pwdinfo;			/* password info structure */
D 20
	
E 20
I 20
	char *logname, *getlogin();
E 20

D 20
	if ((pwdinfo = getpwuid(uid)) == 0) {
		perror(uid);
E 20
I 20
	logname = getlogin();
	if (logname == NULL || (pwdinfo = getpwnam(logname)) == NULL ||
	    pwdinfo->pw_uid != uid)
		pwdinfo = getpwuid(uid);
	if (pwdinfo == 0) {
		fprintf(stderr, "no name for uid %d?\n", uid);
E 20
		exit(1);
	}
	return(pwdinfo->pw_name);
}

/*
 * Do general cleanup.
 */
E 9
cleanup()
{
D 8
        fclose(inputfile);
        fclose(spoolfile);
        if (unlink(atfile) == -1)
                perror(atfile);
        exit(1);
E 8
I 8
D 15
	fclose(inputfile);
	fclose(spoolfile);
E 15
	if (unlink(atfile) == -1)
		perror(atfile);
	exit(1);
E 8
}

I 9
/*
 * Print usage info and exit.
 */
E 9
usage()
{
D 8
        fprintf(stderr,"usage: at [-c] [-s] [-m] ");
        fprintf(stderr,"time [filename]\n");
        exit(1);
E 8
I 8
D 18
	fprintf(stderr,"usage: at [-c] [-s] [-m] ");
	fprintf(stderr,"time [filename]\n");
E 18
I 18
	fprintf(stderr,"usage: at [-csm] time [date] [filename]\n");
E 18
	exit(1);
E 8
}

E 7
E 1
