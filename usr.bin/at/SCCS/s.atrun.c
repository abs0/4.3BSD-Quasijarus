h24281
s 00006/00005/00538
d D 5.6 99/12/31 18:40:31 msokolov 14 13
c Y2K
e
s 00003/00004/00540
d D 5.5 86/11/26 12:35:57 bostic 13 12
c bug report 4.3BSD/usr.lib/26
e
s 00022/00007/00522
d D 5.4 86/05/28 18:43:20 mckusick 12 11
c update from dss%fatkid@SUN.COM (Daniel Steinberg)
e
s 00005/00005/00524
d D 5.3 86/05/28 16:12:41 bloom 11 10
c fix spelling
e
s 00001/00001/00528
d D 5.2 85/09/18 15:49:22 serge 10 9
c notify by mail if any errors occur during execution
e
s 00014/00001/00515
d D 5.1 85/06/06 10:27:11 dist 9 8
c Add copyright
e
s 00007/00002/00509
d D 4.8 85/06/06 10:23:43 kjd 8 7
c Fix closing files and add initgroup
e
s 00013/00000/00498
d D 4.7 84/08/09 18:22:24 wall 7 6
c modify to account for all spoolfiles being owned by "daemon".
e
s 00361/00361/00137
d D 4.6 84/08/02 10:14:28 mckusick 6 5
c reformat, reinsert sccs headers
e
s 00476/00087/00022
d D 4.5 84/08/02 00:38:21 wall 5 4
c added initgroups(3x) for multiple groups, added mail option, store
c last update time in seconds instead of hours.
e
s 00003/00001/00106
d D 4.4 83/07/02 18:35:54 sam 4 3
c include fix
e
s 00011/00014/00096
d D 4.3 82/10/21 00:24:51 mckusick 3 2
c update to new directory structure
e
s 00000/00001/00110
d D 4.2 80/10/21 20:36:29 bill 2 1
c dont nice
e
s 00111/00000/00000
d D 4.1 80/10/02 10:50:08 bill 1 0
c date and time created 80/10/02 10:50:08 by bill
e
u
U
t
T
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 9
I 4
#ifndef lint
E 4
I 1
D 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
D 6
static char *sccsid = "@(#)atrun.c      4.4 (Berkeley) 5/25/84";
E 5
I 4
#endif
E 6
I 6
D 9
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 9
I 9
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
E 9
#endif not lint
I 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 9
E 6
E 4
/*
D 5
 * Run programs submitted by at.
E 5
I 5
D 6
 *      Synopsis: atrun
E 6
I 6
 *	Synopsis: atrun
E 6
 *
 *
D 6
 *      Run jobs created by at(1)
E 6
I 6
 *	Run jobs created by at(1)
E 6
 *
 *
D 6
 *      Modifications by:       Steve Wall
 *                              Computer Systems Research Group
 *                              University of California @ Berkeley
E 6
I 6
 *	Modifications by:	Steve Wall
 *				Computer Systems Research Group
 *				University of California @ Berkeley
E 6
 *
E 5
 */
D 5
#include <stdio.h>
D 3
#include <sys/types.h>
E 3
I 3
#include <sys/param.h>
E 3
#include <sys/dir.h>
D 4
#include <time.h>
E 4
I 4
#include <sys/time.h>
E 4
#include <sys/stat.h>
E 5
I 5
# include <stdio.h>
D 13
# include <sys/types.h>
E 13
I 13
# include <sys/param.h>
E 13
# include <sys/dir.h>
# include <sys/file.h>
# include <sys/time.h>
I 8
D 13
# include <sys/param.h>
E 13
I 12
#ifdef notdef
E 12
# include <sys/quota.h>
I 12
#endif
E 12
E 8
# include <sys/stat.h>
# include <pwd.h>
I 14
# include <tzfile.h>
E 14
E 5

D 3
# define DIR "/usr/spool/at"
E 3
I 3
D 5
# define ATDIR "/usr/spool/at"
E 3
# define PDIR	"past"
# define LASTF "/usr/spool/at/lasttimedone"
E 5
I 5
D 6
# define ATDIR          "/usr/spool/at"         /* spooling area */
# define TMPDIR         "/tmp"                  /* area for temporary files */
# define MAILER         "/bin/mail"             /* program to use for sending
                                                   mail */
# define NORMAL         0                       /* job exited normally */
# define ABNORMAL       1                       /* job exited abnormally */
# define PASTDIR        "/usr/spool/at/past"    /* area to run jobs from */
# define LASTFILE       "/usr/spool/at/lasttimedone"    /* update time file */
E 6
I 6
# define ATDIR		"/usr/spool/at"		/* spooling area */
# define TMPDIR		"/tmp"			/* area for temporary files */
# define MAILER		"/bin/mail"		/* program to use for sending
						   mail */
# define NORMAL		0			/* job exited normally */
# define ABNORMAL	1			/* job exited abnormally */
# define PASTDIR	"/usr/spool/at/past"	/* area to run jobs from */
# define LASTFILE	"/usr/spool/at/lasttimedone"	/* update time file */
E 6
E 5

D 5
int	nowtime;
int	nowdate;
int	nowyear;
E 5

I 5
D 6
char nowtime[11];                       /* time it is right now (yy.ddd.hhmm) */
char errfile[25];                       /* file where we redirect errors to */
E 6
I 6
D 14
char nowtime[11];			/* time it is right now (yy.ddd.hhmm) */
E 14
I 14
char nowtime[13];			/* time right now (yyyy.ddd.hhmm) */
E 14
char errfile[25];			/* file where we redirect errors to */
E 6


E 5
main(argc, argv)
char **argv;
{
D 5
	int tt, day, year, uniq;
D 3
	struct direct dirent;
	FILE *dirf;
	char file[DIRSIZ+1];
E 3
I 3
	struct direct *dirent;
	DIR *dirp;
E 5
E 3

D 3
	chdir(DIR);
E 3
I 3
D 5
	chdir(ATDIR);
E 3
	makenowtime();
D 3
	if ((dirf = fopen(".", "r")) == NULL) {
E 3
I 3
	if ((dirp = opendir(".")) == NULL) {
E 3
		fprintf(stderr, "Cannot read at directory\n");
		exit(1);
	}
D 3
	while (fread((char *)&dirent, sizeof(dirent), 1, dirf) == 1) {
		if (dirent.d_ino==0)
E 3
I 3
	while ((dirent = readdir(dirp)) != NULL) {
		if (dirent->d_ino==0)
E 3
			continue;
D 3
		strcpyn(file, dirent.d_name, DIRSIZ);
		file[DIRSIZ] = '\0';
		if (sscanf(file, "%2d.%3d.%4d.%2d", &year, &day, &tt, &uniq) != 4)
E 3
I 3
		if (sscanf(dirent->d_name, "%2d.%3d.%4d.%2d", &year, &day, &tt, &uniq) != 4)
E 3
			continue;
		if (nowyear < year)
			continue;
		if (nowyear==year && nowdate < day)
			continue;
		if (nowyear==year && nowdate==day && nowtime < tt)
			continue;
D 3
		run(file);
E 3
I 3
		run(dirent->d_name);
E 3
	}
D 3
	fclose(dirf);
E 3
I 3
	closedir(dirp);
E 3
	updatetime(nowtime);
	exit(0);
}
E 5
I 5
D 6
        int i;                          /* for loop index */
        int numjobs;                    /* number of jobs to be run */
        int should_be_run();            /* should a job be run? */
        struct direct **jobqueue;       /* queue of jobs to be run */
E 6
I 6
	int i;				/* for loop index */
	int numjobs;			/* number of jobs to be run */
	int should_be_run();		/* should a job be run? */
	struct direct **jobqueue;	/* queue of jobs to be run */
E 6


D 6
        /*
         * Move to the spooling area.
         */
        chdir(ATDIR);
E 6
I 6
	/*
	 * Move to the spooling area.
	 */
	chdir(ATDIR);
E 6

D 6
        /*
         * Create a filename that represents the time it is now. This is used
         * to determine if the execution time for a job has arrived.
         */
        makenowtime(nowtime);
E 6
I 6
	/*
	 * Create a filename that represents the time it is now. This is used
	 * to determine if the execution time for a job has arrived.
	 */
	makenowtime(nowtime);
E 6

D 6
        /*
         * Create a queue of the jobs that should be run.
         */
        if ((numjobs = scandir(".",&jobqueue,should_be_run, 0)) < 0) {
                perror(ATDIR);
                exit(1);
        }
E 6
I 6
	/*
	 * Create a queue of the jobs that should be run.
	 */
	if ((numjobs = scandir(".",&jobqueue,should_be_run, 0)) < 0) {
		perror(ATDIR);
		exit(1);
	}
E 6

D 6
        /*
         * If there are jobs to be run, run them.
         */
        if (numjobs > 0) {
                for (i = 0; i < numjobs; ++i) {
                        run(jobqueue[i]->d_name);
                }
        }
E 6
I 6
	/*
	 * If there are jobs to be run, run them.
	 */
	if (numjobs > 0) {
		for (i = 0; i < numjobs; ++i) {
			run(jobqueue[i]->d_name);
		}
	}
E 6
E 5

D 5
makenowtime()
E 5
I 5
D 6
        /*
         * Record the last update time.
         */
        updatetime();
E 6
I 6
	/*
	 * Record the last update time.
	 */
	updatetime();
E 6

}

/*
D 14
 * Create a string with the syntax yy.ddd.hhmm that represents the
E 14
I 14
 * Create a string with the syntax yyyy.ddd.hhmm that represents the
E 14
 * time it is right now. This string is used to determine whether a
 * job should be run.
 */
makenowtime(nowtime)
char *nowtime;
E 5
{
D 5
	long t;
	struct tm *localtime();
	register struct tm *tp;
E 5
I 5
D 6
        struct tm *now;                 /* broken down representation of the
                                           time it is right now */
        struct timeval time;            /* number of seconds since 1/1/70 */
        struct timezone zone;           /* time zone we're in (NOT USED) */
E 6
I 6
	struct tm *now;			/* broken down representation of the
					   time it is right now */
	struct timeval time;		/* number of seconds since 1/1/70 */
	struct timezone zone;		/* time zone we're in (NOT USED) */
E 6
E 5

D 5
	time(&t);
	tp = localtime(&t);
	nowtime = tp->tm_hour*100 + tp->tm_min;
	nowdate = tp->tm_yday;
	nowyear = tp->tm_year;
E 5
I 5
D 6
        /*
         * Get the time of day.
         */
        if (gettimeofday(&time,&zone) < 0) {
                perror("gettimeofday");
                exit(1);
        }
E 6
I 6
	/*
	 * Get the time of day.
	 */
	if (gettimeofday(&time,&zone) < 0) {
		perror("gettimeofday");
		exit(1);
	}
E 6

D 6
        /*
         * Get a broken down representation of the time it is right now.
         */
        now = localtime(&time.tv_sec);
E 6
I 6
	/*
	 * Get a broken down representation of the time it is right now.
	 */
	now = localtime(&time.tv_sec);
E 6

D 6
        /*
         * Create a string to be used in determining whether or not a job
         * should be run. The syntax is yy.ddd.hhmm .
         */
        sprintf(nowtime,"%d.%03d.%02d%02d",now->tm_year,
                                           now->tm_yday,
                                           now->tm_hour,
                                           now->tm_min);
        return;
E 6
I 6
	/*
	 * Create a string to be used in determining whether or not a job
D 14
	 * should be run. The syntax is yy.ddd.hhmm .
E 14
I 14
	 * should be run. The syntax is yyyy.ddd.hhmm .
E 14
	 */
D 14
	sprintf(nowtime,"%d.%03d.%02d%02d",now->tm_year,
E 14
I 14
	sprintf(nowtime,"%d.%03d.%02d%02d",now->tm_year + TM_YEAR_BASE,
E 14
					   now->tm_yday,
					   now->tm_hour,
					   now->tm_min);
	return;
E 6
E 5
}

D 5
updatetime(t)
E 5
I 5
/*
 * Run a job.
 */
run(spoolfile)
char *spoolfile;
E 5
{
D 5
	FILE *tfile;
E 5
I 5
D 6
        int i;                          /* scratch variable */
        int pid;                        /* process id of forked shell */
        int exitstatus;                 /* exit status of the job */
        int notifybymail;               /* should we notify the owner of the
                                           job after the job is run? */
        char shell[4];                  /* shell to run the job under */
        char *getname();                /* get a uname from using a uid */
        char mailvar[4];                /* send mail variable ("yes" or "no") */
        char runfile[100];              /* file sent to forked shell for exec-
                                           ution */
        char jobname[100];              /* name of job we're going to run */
        char whichshell[100];           /* which shell should we fork off? */
        struct stat errbuf;             /* stats on error file */
        struct stat jobbuf;             /* stats on job file */
        FILE *infile;                   /* I/O stream to spoolfile */
E 6
I 6
	int i;				/* scratch variable */
	int pid;			/* process id of forked shell */
	int exitstatus;			/* exit status of the job */
	int notifybymail;		/* should we notify the owner of the
					   job after the job is run? */
	char shell[4];			/* shell to run the job under */
	char *getname();		/* get a uname from using a uid */
	char mailvar[4];		/* send mail variable ("yes" or "no") */
	char runfile[100];		/* file sent to forked shell for exec-
					   ution */
I 7
D 12
	char owner[16];			/* owner of job we're going to run */
E 7
	char jobname[100];		/* name of job we're going to run */
E 12
I 12
	char owner[128];		/* owner of job we're going to run */
	char jobname[128];		/* name of job we're going to run */
E 12
	char whichshell[100];		/* which shell should we fork off? */
I 7
	struct passwd *pwdbuf;		/* password info of the owner of job */
E 7
	struct stat errbuf;		/* stats on error file */
	struct stat jobbuf;		/* stats on job file */
	FILE *infile;			/* I/O stream to spoolfile */
E 6
E 5

D 5
	tfile = fopen(LASTF, "w");
	if (tfile == NULL) {
		fprintf(stderr, "can't write lastfile\n");
		exit(1);
	}
	fprintf(tfile, "%04d\n", t);
}
E 5
I 5

D 6
        /*
         * First we fork a child so that the main can run other jobs.
         */
        if (pid = fork())
                return;
E 6
I 6
	/*
	 * First we fork a child so that the main can run other jobs.
	 */
	if (pid = fork())
		return;
E 6

D 6
        /*
         * Open the spoolfile.
         */
        if ((infile = fopen(spoolfile,"r")) == NULL) {
                perror(spoolfile);
                exit(1);
        }
E 6
I 6
	/*
	 * Open the spoolfile.
	 */
	if ((infile = fopen(spoolfile,"r")) == NULL) {
		perror(spoolfile);
		exit(1);
	}
E 6

D 6
        /*
         * Grab the 3-line header out of the spoolfile.
         */
        fscanf(infile,"# jobname: %s\n",jobname);
        fscanf(infile,"# shell: %s\n",shell);
        fscanf(infile,"# notify by mail: %s\n",mailvar);
E 6
I 6
	/*
D 12
	 * Grab the 3-line header out of the spoolfile.
E 12
I 12
	 * Grab the 4-line header out of the spoolfile.
E 12
	 */
I 7
D 12
	fscanf(infile,"# owner: %s\n",owner);
E 7
	fscanf(infile,"# jobname: %s\n",jobname);
	fscanf(infile,"# shell: %s\n",shell);
	fscanf(infile,"# notify by mail: %s\n",mailvar);
E 12
I 12
	if (
	    (fscanf(infile,"# owner: %127s%*[^\n]\n",owner) != 1) ||
	    (fscanf(infile,"# jobname: %127s%*[^\n]\n",jobname) != 1) ||
	    (fscanf(infile,"# shell: %3s%*[^\n]\n",shell) != 1) ||
	    (fscanf(infile,"# notify by mail: %3s%*[^\n]\n",mailvar) != 1)
	    ) {
		fprintf(stderr, "%s: bad spool header\n", spoolfile);
		exit(1);
	}
E 12
E 6

D 6
        /*
         * Check to see if we should send mail to the owner.
         */
        notifybymail = (strcmp(mailvar, "yes") == 0);
        fclose(infile);
E 6
I 6
	/*
	 * Check to see if we should send mail to the owner.
	 */
	notifybymail = (strcmp(mailvar, "yes") == 0);
	fclose(infile);
I 7

	/*
	 * Change the ownership of the spoolfile from "daemon" to the owner
	 * of the job.
	 */
	pwdbuf = getpwnam(owner);
I 12
	if (pwdbuf == NULL) {
		fprintf(stderr, "%s: could not find owner in passwd file\n",
		    spoolfile);
		exit(1);
	}
E 12
	if (chown(spoolfile,pwdbuf->pw_uid,pwdbuf->pw_gid) == -1) {
		perror(spoolfile);
		exit(1);
	}
E 7
E 6

D 6
        /*
         * Move the spoolfile to the directory where jobs are run from and
         * then move into that directory.
         */
        sprintf(runfile,"%s/%s",PASTDIR,spoolfile);
        rename(spoolfile, runfile);
        chdir(PASTDIR);
E 6
I 6
	/*
	 * Move the spoolfile to the directory where jobs are run from and
	 * then move into that directory.
	 */
	sprintf(runfile,"%s/%s",PASTDIR,spoolfile);
	rename(spoolfile, runfile);
	chdir(PASTDIR);
E 6

D 6
        /*
         * Create a temporary file where we will redirect errors to.
         * Just to make sure we've got a unique file, we'll run an "access"
         * check on the file.
         */
        for (i = 0; i <= 1000; i += 2) {
                sprintf(errfile,"%s/at.err%d",TMPDIR,(getpid() + i));
E 6
I 6
	/*
	 * Create a temporary file where we will redirect errors to.
	 * Just to make sure we've got a unique file, we'll run an "access"
	 * check on the file.
	 */
	for (i = 0; i <= 1000; i += 2) {
		sprintf(errfile,"%s/at.err%d",TMPDIR,(getpid() + i));
E 6

D 6
                if (access(errfile, F_OK))
                        break;
E 6
I 6
		if (access(errfile, F_OK))
			break;
E 6

D 6
                if (i == 1000) {
                        fprintf(stderr, "couldn't create errorfile.\n");
                        exit(1);
                }
        }
E 6
I 6
		if (i == 1000) {
			fprintf(stderr, "couldn't create errorfile.\n");
			exit(1);
		}
	}
E 6
E 5

D 5
run(file)
char *file;
E 5
I 5
D 6
        /*
         * Get the stats of the job being run.
         */
        if (stat(runfile, &jobbuf) == -1) {
                perror(runfile);
                exit(1);
        }
E 6
I 6
	/*
	 * Get the stats of the job being run.
	 */
	if (stat(runfile, &jobbuf) == -1) {
		perror(runfile);
		exit(1);
	}
E 6

D 6
        /*
         * Fork another child that will run the job.
         */
        if (pid = fork()) {
E 6
I 6
	/*
	 * Fork another child that will run the job.
	 */
	if (pid = fork()) {
E 6

D 6
                /*
                 * If the child fails, save the job so that it gets
                 * rerun the next time "atrun" is executed and then exit.
                 */
                if (pid == -1) {
                        chdir(ATDIR);
                        rename(runfile, spoolfile);
                        exit(1);
                }
E 6
I 6
		/*
		 * If the child fails, save the job so that it gets
		 * rerun the next time "atrun" is executed and then exit.
		 */
		if (pid == -1) {
			chdir(ATDIR);
			rename(runfile, spoolfile);
			exit(1);
		}
E 6

D 6
                /*
                 * Wait for the child to terminate.
                 */
                wait((int *)0);
E 6
I 6
		/*
		 * Wait for the child to terminate.
		 */
		wait((int *)0);
E 6

D 6
                /*
                 * Get the stats of the error file and determine the exit
                 * status of the child. We assume that if there is anything
                 * in the error file then the job ran into some errors.
                 */
                if (stat(errfile,&errbuf) != 0) {
                        perror(errfile);
                        exit(1);
                }
                exitstatus = ((errbuf.st_size == 0) ? NORMAL : ABNORMAL);
E 6
I 6
		/*
		 * Get the stats of the error file and determine the exit
		 * status of the child. We assume that if there is anything
		 * in the error file then the job ran into some errors.
		 */
		if (stat(errfile,&errbuf) != 0) {
			perror(errfile);
			exit(1);
		}
		exitstatus = ((errbuf.st_size == 0) ? NORMAL : ABNORMAL);
E 6

D 6
                /* If errors occured, then we send mail to the owner
                 * telling him/her that we ran into trouble.  
                 *
                 * (NOTE: this could easily be modified so that if any 
                 * errors occured while running a job, mail is sent regard-
                 * less of whether the -m flag was set or not.
                 *
                 * i.e. rather than:
                 *
                 *      "if (notifybymail)" use
                 * use:
                 *
                 *      "if ((exitstatus == ABNORMAL) || (notifybymail))"
                 *
                 * It's up to you if you want to implement this.
                 *
                 */ 
                if (notifybymail)
                        sendmailto(getname(jobbuf.st_uid),jobname,exitstatus);
E 6
I 6
D 11
		/* If errors occured, then we send mail to the owner
E 11
I 11
		/* If errors occurred, then we send mail to the owner
E 11
		 * telling him/her that we ran into trouble.  
		 *
		 * (NOTE: this could easily be modified so that if any 
D 11
		 * errors occured while running a job, mail is sent regard-
E 11
I 11
		 * errors occurred while running a job, mail is sent regard-
E 11
		 * less of whether the -m flag was set or not.
		 *
		 * i.e. rather than:
		 *
		 *	"if (notifybymail)" use
		 * use:
		 *
		 *	"if ((exitstatus == ABNORMAL) || (notifybymail))"
		 *
		 * It's up to you if you want to implement this.
		 *
		 */ 
D 10
		if (notifybymail)
E 10
I 10
		if (exitstatus == ABNORMAL || notifybymail)
E 10
			sendmailto(getname(jobbuf.st_uid),jobname,exitstatus);
E 6

D 6
                /*
                 * Remove the errorfile and the jobfile.
                 */
                if (unlink(errfile) == -1)
                        perror(errfile);
                if (unlink(runfile) == -1)
                        perror(runfile);
E 6
I 6
		/*
		 * Remove the errorfile and the jobfile.
		 */
		if (unlink(errfile) == -1)
			perror(errfile);
		if (unlink(runfile) == -1)
			perror(runfile);
E 6

D 6
                exit(0);
        }
E 6
I 6
		exit(0);
	}
E 6

D 6
        /*
         * HERE'S WHERE WE SET UP AND FORK THE SHELL.
         */
E 6
I 6
	/*
	 * HERE'S WHERE WE SET UP AND FORK THE SHELL.
	 */
E 6

D 6
        /*
         * Run the job as the owner of the jobfile
         */
        setgid(jobbuf.st_gid);
        setuid(jobbuf.st_uid);
E 6
I 6
	/*
	 * Run the job as the owner of the jobfile
	 */
I 12
#ifdef notdef
	/* This is no longer needed with the new, stripped-down quota system */
E 12
I 8
	quota(Q_SETUID,jobbuf.st_uid,0,0);
I 12
#endif
E 12
E 8
	setgid(jobbuf.st_gid);
I 8
	initgroups(getname(jobbuf.st_uid),jobbuf.st_gid);
E 8
	setuid(jobbuf.st_uid);
E 6

D 6
        /*
         * Close all open files so that we can reopen a temporary file
         * for stdout and sterr.
         */
        for (i=0; i<15; i++)
                close(i);
E 6
I 6
	/*
	 * Close all open files so that we can reopen a temporary file
	 * for stdout and sterr.
	 */
D 8
	for (i=0; i<15; i++)
E 8
I 8
	for (i = getdtablesize(); --i >= 0;)
E 8
		close(i);
E 6

D 6
        /*
         * Reposition stdin, stdout, and stderr.
         *
         *      stdin  = /dev/null
         *      stout  = /dev/null
         *      stderr = /tmp/at.err{pid}
         *      
         */
        open("/dev/null", 0);
        open("/dev/null", 0);
        open(errfile,O_CREAT|O_WRONLY,00644);
E 6
I 6
	/*
	 * Reposition stdin, stdout, and stderr.
	 *
	 *	stdin  = /dev/null
	 *	stout  = /dev/null
	 *	stderr = /tmp/at.err{pid}
	 *	
	 */
	open("/dev/null", 0);
D 8
	open("/dev/null", 0);
E 8
I 8
	open("/dev/null", 1);
E 8
	open(errfile,O_CREAT|O_WRONLY,00644);
E 6

D 6
        /*
         * Now we fork the shell.
         *
         * See if the shell is in /bin
         */
        sprintf(whichshell,"/bin/%s",shell);
        execl(whichshell,shell,runfile, 0);
E 6
I 6
	/*
	 * Now we fork the shell.
	 *
	 * See if the shell is in /bin
	 */
	sprintf(whichshell,"/bin/%s",shell);
	execl(whichshell,shell,runfile, 0);
E 6

D 6
        /*
         * If not in /bin, look for the shell in /usr/bin.
         */
        sprintf(whichshell,"/usr/bin/%s",shell);
        execl(whichshell,shell,runfile, 0);
E 6
I 6
	/*
	 * If not in /bin, look for the shell in /usr/bin.
	 */
	sprintf(whichshell,"/usr/bin/%s",shell);
	execl(whichshell,shell,runfile, 0);
E 6

D 6
        /*
         * If not in /bin, look for the shell in /usr/new.
         */
        sprintf(whichshell,"/usr/new/%s",shell);
        execl(whichshell,shell,runfile, 0);
E 6
I 6
	/*
	 * If not in /bin, look for the shell in /usr/new.
	 */
	sprintf(whichshell,"/usr/new/%s",shell);
	execl(whichshell,shell,runfile, 0);
E 6

D 6
        /*
         * If we don't succeed by now, we're really having troubles,
         * so we'll send the owner some mail.
         */
        fprintf(stderr, "%s: Can't execl shell\n",shell);
E 6
I 6
	/*
	 * If we don't succeed by now, we're really having troubles,
	 * so we'll send the owner some mail.
	 */
	fprintf(stderr, "%s: Can't execl shell\n",shell);
I 8
	exit(1);
E 8
E 6
}

/*
 * Send mail to the owner of the job. 
 */
sendmailto(user,jobname,exitstatus)
char *user;
char *jobname;
int exitstatus;
E 5
{
D 5
	struct stat stbuf;
	register pid, i;
	char sbuf[64];
E 5
I 5
D 6
        char ch;                        /* scratch variable */
        char mailtouser[100];           /* the process we use to send mail */
        FILE *mailptr;                  /* I/O stream to the mail process */
        FILE *errptr;                   /* I/O stream to file containing error
                                           messages */
        FILE *popen();                  /* initiate I/O to a process */
E 6
I 6
D 13
	char ch;			/* scratch variable */
E 13
I 13
	int ch;				/* scratch variable */
E 13
	char mailtouser[100];		/* the process we use to send mail */
	FILE *mailptr;			/* I/O stream to the mail process */
	FILE *errptr;			/* I/O stream to file containing error
					   messages */
	FILE *popen();			/* initiate I/O to a process */
E 6
E 5

D 5
	/* printf("running %s\n", file); */
	if (fork()!=0)
		return;
	for (i=0; i<15; i++)
		close(i);
	dup(dup(open("/dev/null", 0)));
	sprintf(sbuf, "%s/%s", PDIR, file);
	link(file, sbuf);
	unlink(file);
	chdir(PDIR);
	if (stat(file, &stbuf) == -1)
		exit(1);
	if (pid = fork()) {
		if (pid == -1)
			exit(1);
		wait((int *)0);
		unlink(file);
		exit(0);
	}
	setgid(stbuf.st_gid);
	setuid(stbuf.st_uid);
D 2
	nice(5);
E 2
	execl("/bin/sh", "sh", file, 0);
	execl("/usr/bin/sh", "sh", file, 0);
	fprintf(stderr, "Can't execl shell\n");
	exit(1);
E 5
I 5

D 6
        /*
         * Create the full name for the mail process.
         */
        sprintf(mailtouser,"%s %s",MAILER, user);
E 6
I 6
	/*
	 * Create the full name for the mail process.
	 */
	sprintf(mailtouser,"%s %s",MAILER, user);
E 6

D 6
        /*
         * Open a stream to the mail process.
         */
        if ((mailptr = popen(mailtouser,"w")) == NULL) {
                perror(MAILER);
                exit(1);
        }
E 6
I 6
	/*
	 * Open a stream to the mail process.
	 */
	if ((mailptr = popen(mailtouser,"w")) == NULL) {
		perror(MAILER);
		exit(1);
	}
E 6

D 6
        /*
         * Send the letter. If the job exited normally, just send a
         * quick letter notifying the owner that everthing went ok.
         */
        if (exitstatus == NORMAL) {
                fprintf(mailptr,"Your job \"%s\" was run without ",jobname);
                fprintf(mailptr,"any errors.\n");
        }
E 6
I 6
	/*
	 * Send the letter. If the job exited normally, just send a
	 * quick letter notifying the owner that everthing went ok.
	 */
	if (exitstatus == NORMAL) {
		fprintf(mailptr,"Your job \"%s\" was run without ",jobname);
		fprintf(mailptr,"any errors.\n");
	}
E 6

D 6
        /*
         * If the job exited abnormally, send a letter notifying the user
         * that the job didn't run proberly. Also, send a copy of the errors 
         * that occured to the user.
         */
        else {
                if (exitstatus == ABNORMAL) {
E 6
I 6
	/*
	 * If the job exited abnormally, send a letter notifying the user
	 * that the job didn't run proberly. Also, send a copy of the errors 
D 11
	 * that occured to the user.
E 11
I 11
	 * that occurred to the user.
E 11
	 */
	else {
		if (exitstatus == ABNORMAL) {
E 6

D 6
                        /*
                         * Write the intro to the letter.
                         */
                        fprintf(mailptr,"\n\nThe job you submitted to at, ");
                        fprintf(mailptr,"\"%s\", ",jobname);
                        fprintf(mailptr,"exited abnormally.\nA list of the ");
                        fprintf(mailptr," errors that occured follows:\n\n\n");
E 6
I 6
			/*
			 * Write the intro to the letter.
			 */
			fprintf(mailptr,"\n\nThe job you submitted to at, ");
			fprintf(mailptr,"\"%s\", ",jobname);
			fprintf(mailptr,"exited abnormally.\nA list of the ");
D 11
			fprintf(mailptr," errors that occured follows:\n\n\n");
E 11
I 11
			fprintf(mailptr," errors that occurred follows:\n\n\n");
E 11
E 6

D 6
                        /*
                         * Open the file containing a log of the errors that
                         * occured.
                         */
                        if ((errptr = fopen(errfile,"r")) == NULL) {
                                perror(errfile);
                                exit(1);
                        }
E 6
I 6
			/*
			 * Open the file containing a log of the errors that
D 11
			 * occured.
E 11
I 11
			 * occurred.
E 11
			 */
			if ((errptr = fopen(errfile,"r")) == NULL) {
				perror(errfile);
				exit(1);
			}
E 6

D 6
                        /*
                         * Send the copy of the errors to the owner.
                         */
                        fputc('\t',mailptr);
                        while ((ch = fgetc(errptr)) != EOF) {
                                fputc(ch,mailptr);
                                if (ch == '\n')
                                        fputc('\t',mailptr);
                        }
                        fclose(errptr);
                }
        }
E 6
I 6
			/*
			 * Send the copy of the errors to the owner.
			 */
			fputc('\t',mailptr);
			while ((ch = fgetc(errptr)) != EOF) {
				fputc(ch,mailptr);
D 13
				if (ch == '\n')
E 13
I 13
				if (ch == (int)'\n')
E 13
					fputc('\t',mailptr);
			}
			fclose(errptr);
		}
	}
E 6

D 6
        /*
         * Sign the letter.
         */
        fprintf(mailptr,"\n\n-----------------\n");
        fprintf(mailptr,"The Atrun Program\n");
E 6
I 6
	/*
	 * Sign the letter.
	 */
	fprintf(mailptr,"\n\n-----------------\n");
	fprintf(mailptr,"The Atrun Program\n");
E 6

D 6
        /*
         * Close the stream to the mail process.
         */
        pclose(mailptr);
        return;
E 6
I 6
	/*
	 * Close the stream to the mail process.
	 */
	pclose(mailptr);
	return;
E 6
}

/*
 * Do we want to include a file in the job queue? (used by "scandir") 
 * We are looking for files whose "value" (its name) is less than or 
 * equal to the time it is right now (represented by "nowtime").
 * We'll only consider files with three dots in their name since these
 * are the only files that represent jobs to be run.
 */
should_be_run(direntry)
struct direct *direntry;
{
D 6
        int numdot = 0;                 /* number of dots found in a filename */
        char *filename;                 /* pointer for scanning a filename */
E 6
I 6
	int numdot = 0;			/* number of dots found in a filename */
	char *filename;			/* pointer for scanning a filename */
E 6


D 6
        filename = direntry->d_name;
E 6
I 6
	filename = direntry->d_name;
E 6

D 6
        /*
         * Count the number of dots found in the directory entry.
         */
        while (*filename)
                numdot += (*(filename++) == '.');
E 6
I 6
	/*
	 * Count the number of dots found in the directory entry.
	 */
	while (*filename)
		numdot += (*(filename++) == '.');
E 6

D 6
        /*
         * If the directory entry doesn't represent a job, just return a 0.
         */
        if (numdot != 3)
                return(0);
E 6
I 6
	/*
	 * If the directory entry doesn't represent a job, just return a 0.
	 */
	if (numdot != 3)
		return(0);
E 6

D 6
        /*
         * If a directory entry represents a job, determine if it's time to
         * run it.
         */
        return(strncmp(direntry->d_name, nowtime,11) <= 0);
E 6
I 6
	/*
	 * If a directory entry represents a job, determine if it's time to
	 * run it.
	 */
D 14
	return(strncmp(direntry->d_name, nowtime,11) <= 0);
E 14
I 14
	return(strncmp(direntry->d_name, nowtime,13) <= 0);
E 14
E 6
}

/*
 * Record the last time that "atrun" was run.
 */
updatetime()
{

D 6
        struct timeval time;            /* number of seconds since 1/1/70 */
        struct timezone zone;           /* time zone we're in (NOT USED) */
        FILE *lastimefile;              /* file where recored is kept */
E 6
I 6
	struct timeval time;		/* number of seconds since 1/1/70 */
	struct timezone zone;		/* time zone we're in (NOT USED) */
	FILE *lastimefile;		/* file where recored is kept */
E 6

D 6
        /*
         * Get the time of day.
         */
        if (gettimeofday(&time,&zone) < 0) {
                perror("gettimeofday");
                exit(1);
        }
E 6
I 6
	/*
	 * Get the time of day.
	 */
	if (gettimeofday(&time,&zone) < 0) {
		perror("gettimeofday");
		exit(1);
	}
E 6

D 6
        /*
         * Open the record file.
         */
        if ((lastimefile = fopen(LASTFILE, "w")) == NULL) {
                fprintf(stderr, "can't update lastfile: ");
                perror(LASTFILE);
                exit(1);
        }
E 6
I 6
	/*
	 * Open the record file.
	 */
	if ((lastimefile = fopen(LASTFILE, "w")) == NULL) {
		fprintf(stderr, "can't update lastfile: ");
		perror(LASTFILE);
		exit(1);
	}
E 6

D 6
        /*
         * Record the last update time (in seconds since 1/1/70).
         */
        fprintf(lastimefile, "%d\n", (u_long) time.tv_sec);
E 6
I 6
	/*
	 * Record the last update time (in seconds since 1/1/70).
	 */
	fprintf(lastimefile, "%d\n", (u_long) time.tv_sec);
E 6

D 6
        /*
         * Close the record file.
         */
        fclose(lastimefile);
E 6
I 6
	/*
	 * Close the record file.
	 */
	fclose(lastimefile);
E 6
}

/*
 * Get the full login name of a person using his/her user id.
 */
char *
getname(uid)
int uid;
{
D 6
        struct passwd *pwdinfo;                 /* password info structure */
        
E 6
I 6
	struct passwd *pwdinfo;			/* password info structure */
	
E 6

D 6
        if ((pwdinfo = getpwuid(uid)) == 0) {
                perror(uid);
                exit(1);
        }
        return(pwdinfo->pw_name);
E 6
I 6
	if ((pwdinfo = getpwuid(uid)) == 0) {
		perror(uid);
		exit(1);
	}
	return(pwdinfo->pw_name);
E 6
E 5
}
E 1
