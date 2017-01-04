h58017
s 00006/00005/00548
d D 5.2 99/12/31 18:40:27 msokolov 5 4
c Y2K
e
s 00013/00001/00540
d D 5.1 85/06/06 09:52:10 dist 4 3
c Add copyright
e
s 00073/00028/00468
d D 1.3 84/08/09 18:20:31 wall 3 2
c modify to account for all spoolfiles being owned by "daemon".
e
s 00318/00318/00178
d D 1.2 84/08/02 10:14:46 mckusick 2 1
c reformat, reinsert sccs headers
e
s 00496/00000/00000
d D 1.1 84/08/02 00:17:05 wall 1 0
c date and time created 84/08/02 00:17:05 by wall
e
u
U
t
T
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
I 1
#ifndef lint
D 2
static char sccsid[] = "@(#)atq.c       4.1 (Berkeley) 5/25/84";
#endif
E 2
I 2
D 4
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 4
I 4
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
#endif not lint
E 2

/*
 *
D 2
 *      Synopsis:  atq [ -c ] [ -n ] [ name ... ]
E 2
I 2
 *	Synopsis:  atq [ -c ] [ -n ] [ name ... ]
E 2
 *
 *
D 2
 *      Print the queue of files waiting to be executed. These files 
 *      were created by using the "at" command and are located in the 
 *      directory "/usr/spool/at".
E 2
I 2
 *	Print the queue of files waiting to be executed. These files 
 *	were created by using the "at" command and are located in the 
 *	directory "/usr/spool/at".
E 2
 *
 *
D 2
 *      Author: Steve Wall
 *              Computer Systems Research Group
 *              University of California @ Berkeley
E 2
I 2
 *	Author: Steve Wall
 *		Computer Systems Research Group
 *		University of California @ Berkeley
E 2
 *
 */

# include <stdio.h>
# include <sys/types.h>
# include <sys/file.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <sys/time.h>
I 5
# include <tzfile.h>
E 5
# include <pwd.h>
# include <ctype.h>
 
D 2
# define ATDIR          "/usr/spool/at"                 /* spooling area */
# define LASTFILE       "/usr/spool/at/lasttimedone"    /* update time record 
                                                           file */
E 2
I 2
# define ATDIR		"/usr/spool/at"			/* spooling area */
# define LASTFILE	"/usr/spool/at/lasttimedone"	/* update time record 
							   file */
E 2

/*
 * Months of the year
 */
static char *mthnames[12] = {
D 2
        "Jan","Feb","Mar","Apr","May","Jun","Jul",
        "Aug","Sep","Oct","Nov","Dec",
E 2
I 2
	"Jan","Feb","Mar","Apr","May","Jun","Jul",
	"Aug","Sep","Oct","Nov","Dec",
E 2
};


D 2
int numentries;                         /* number of entries in spooling area */
int namewanted = 0;                     /* only print jobs belonging to a 
                                           certain person */
struct direct **queue;                  /* the queue itself */
E 2
I 2
int numentries;				/* number of entries in spooling area */
int namewanted = 0;			/* only print jobs belonging to a 
					   certain person */
struct direct **queue;			/* the queue itself */
E 2


main(argc,argv)
int argc;
char **argv;
{

D 2
        int cflag = 0;                  /* print in order of creation time */
        int nflag = 0;                  /* just print the number of jobs in 
                                           queue */
        int usage();                    /* print usage info and exit */
        int creation();                 /* sort jobs by date of creation */
        int alphasort();                /* sort jobs by date of execution */
        int filewanted();               /* should a file be included in queue?*/
        int printqueue();               /* print the queue */
        int countfiles();               /* count the number of files in queue
                                           for a given person */
        char **namelist;                /* array of specific name(s) requested*/
E 2
I 2
	int cflag = 0;			/* print in order of creation time */
	int nflag = 0;			/* just print the number of jobs in 
					   queue */
	int usage();			/* print usage info and exit */
	int creation();			/* sort jobs by date of creation */
	int alphasort();		/* sort jobs by date of execution */
	int filewanted();		/* should a file be included in queue?*/
	int printqueue();		/* print the queue */
	int countfiles();		/* count the number of files in queue
					   for a given person */
	char **namelist;		/* array of specific name(s) requested*/
E 2


D 2
        --argc, ++argv;
E 2
I 2
	--argc, ++argv;
E 2

D 2
        /*
         * Interpret command line flags if they exist.
         */
        while (argc > 0 && **argv == '-') {
                (*argv)++;
                while (**argv) switch (*(*argv)++) {
E 2
I 2
	/*
	 * Interpret command line flags if they exist.
	 */
	while (argc > 0 && **argv == '-') {
		(*argv)++;
		while (**argv) switch (*(*argv)++) {
E 2

D 2
                        case 'c' :      cflag++; 
                                        break;
E 2
I 2
			case 'c' :	cflag++; 
					break;
E 2

D 2
                        case 'n' :      nflag++; 
                                        break;
E 2
I 2
			case 'n' :	nflag++; 
					break;
E 2

D 2
                        default  :      usage();
E 2
I 2
			default	 :	usage();
E 2

D 2
                }
                --argc, ++argv;
        }
E 2
I 2
		}
		--argc, ++argv;
	}
E 2

D 2
        /*
         * If a certain name (or names) is requested, set a pointer to the
         * beginning of the list.
         */
        if (**argv) {
                ++namewanted;
                namelist = argv;
        }
E 2
I 2
	/*
	 * If a certain name (or names) is requested, set a pointer to the
	 * beginning of the list.
	 */
	if (**argv) {
		++namewanted;
		namelist = argv;
	}
E 2

D 2
        /*
         * Move to the spooling area and scan the directory, placing the
         * files in the queue structure. The queue comes back sorted by
         * execution time or creation time.
         */
        if (chdir(ATDIR) == -1) {
                perror(ATDIR);
                exit(1);
        }
        if ((numentries = scandir(".",&queue,filewanted, (cflag) ? creation : 
                                alphasort)) < 0) {
                perror(ATDIR);
                exit(1);
        }
E 2
I 2
	/*
	 * Move to the spooling area and scan the directory, placing the
	 * files in the queue structure. The queue comes back sorted by
	 * execution time or creation time.
	 */
	if (chdir(ATDIR) == -1) {
		perror(ATDIR);
		exit(1);
	}
	if ((numentries = scandir(".",&queue,filewanted, (cflag) ? creation : 
				alphasort)) < 0) {
		perror(ATDIR);
		exit(1);
	}
E 2

D 2
        /*
         * Either print a message stating:
         *
         *      1) that the spooling area is empty.
         *      2) the number of jobs in the spooling area.
         *      3) the number of jobs in the spooling area belonging to 
         *         a certain person.
         *      4) that the person requested doesn't have any files in the
         *         spooling area.
         *
         * or send the queue off to "printqueue" for printing.
         *
         * This whole process might seem a bit elaborate, but it's worthwhile
         * to print some informative messages for the user.
         *
         */
        if ((numentries == 0) && (!nflag)) {
                printf("no files in queue.\n");
                exit(0);
        }
        if (nflag) {
                printf("%d\n",(namewanted) ? countfiles(namelist) : numentries);
                exit(0);
        }
        if ((namewanted) && (countfiles(namelist) == 0)) {
                printf("no files for %s.\n", (argc == 1) ?
                                        *argv : "specified users");
                exit(0);
        }
        printqueue(namelist);
        exit(0);
E 2
I 2
	/*
	 * Either print a message stating:
	 *
	 *	1) that the spooling area is empty.
	 *	2) the number of jobs in the spooling area.
	 *	3) the number of jobs in the spooling area belonging to 
	 *	   a certain person.
	 *	4) that the person requested doesn't have any files in the
	 *	   spooling area.
	 *
	 * or send the queue off to "printqueue" for printing.
	 *
	 * This whole process might seem a bit elaborate, but it's worthwhile
	 * to print some informative messages for the user.
	 *
	 */
	if ((numentries == 0) && (!nflag)) {
		printf("no files in queue.\n");
		exit(0);
	}
	if (nflag) {
		printf("%d\n",(namewanted) ? countfiles(namelist) : numentries);
		exit(0);
	}
	if ((namewanted) && (countfiles(namelist) == 0)) {
		printf("no files for %s.\n", (argc == 1) ?
					*argv : "specified users");
		exit(0);
	}
	printqueue(namelist);
	exit(0);
E 2
}

/*
 * Count the number of jobs in the spooling area owned by a certain person(s).
 */
countfiles(namelist)
char **namelist;
{
D 2
        int i;                                  /* for loop index */
        int entryfound;                         /* found file owned by user(s)*/
        int numfiles = 0;                       /* number of files owned by a
                                                   certain person(s) */
        char **ptr;                             /* scratch pointer */
        struct stat stbuf;                      /* buffer for file stats */
        
E 2
I 2
	int i;					/* for loop index */
	int entryfound;				/* found file owned by user(s)*/
	int numfiles = 0;			/* number of files owned by a
						   certain person(s) */
	char **ptr;				/* scratch pointer */
D 3
	struct stat stbuf;			/* buffer for file stats */
	
E 3
E 2


D 2
        /*
         * For each file in the queue, see if the user(s) own the file. We
         * have to use "entryfound" (rather than simply incrementing "numfiles")
         * so that if a person's name appears twice on the command line we 
         * don't double the number of files owned by him/her.
         */
        for (i = 0; i < numentries ; i++) {
                if ((stat(queue[i]->d_name, &stbuf)) < 0) {
                        continue;
                }
                ptr = namelist;
                entryfound = 0;
E 2
I 2
	/*
	 * For each file in the queue, see if the user(s) own the file. We
	 * have to use "entryfound" (rather than simply incrementing "numfiles")
	 * so that if a person's name appears twice on the command line we 
	 * don't double the number of files owned by him/her.
	 */
	for (i = 0; i < numentries ; i++) {
D 3
		if ((stat(queue[i]->d_name, &stbuf)) < 0) {
			continue;
		}
E 3
		ptr = namelist;
		entryfound = 0;
E 2

D 2
                while (*ptr) {
                        if (getid(*ptr) == stbuf.st_uid)
                                ++entryfound;
                        ++ptr;
                }
                if (entryfound)
                        ++numfiles;
        }
        return(numfiles);
}
E 2
I 2
		while (*ptr) {
D 3
			if (getid(*ptr) == stbuf.st_uid)
E 3
I 3
			if (isowner(*ptr,queue[i]->d_name))
E 3
				++entryfound;
			++ptr;
		}
		if (entryfound)
			++numfiles;
	}
	return(numfiles);
}
E 2

/*
 * Print the queue. If only jobs belonging to a certain person(s) are requested,
 * only print jobs that belong to that person(s).
 */
printqueue(namelist)
char **namelist;
{
D 2
        int i;                                  /* for loop index */
        int rank = 1;                           /* rank of a job */
        int entryfound;                         /* found file owned by user(s)*/
        int printrank();                        /* print the rank of a job */
        int plastrun();                         /* print the last time the 
                                                   spooling area was updated */
        int getid();                            /* get uid of a person */
        char **ptr;                             /* scratch pointer */
        char *getname();                        /* get the login name of a 
                                                   person using their uid */
        struct stat stbuf;                      /* buffer for file stats */
E 2
I 2
	int i;					/* for loop index */
	int rank = 1;				/* rank of a job */
	int entryfound;				/* found file owned by user(s)*/
	int printrank();			/* print the rank of a job */
	int plastrun();				/* print the last time the 
						   spooling area was updated */
I 3
	int powner();				/* print the name of the owner
						   of the job */
E 3
	int getid();				/* get uid of a person */
	char **ptr;				/* scratch pointer */
D 3
	char *getname();			/* get the login name of a 
						   person using their uid */
E 3
	struct stat stbuf;			/* buffer for file stats */
E 2


D 2
        /*
         * Print the time the spooling area was last modified and the header
         * for the queue.
         */
        plastrun();
        printf(" Rank     Execution Date     Owner     Job #   Job Name\n");
E 2
I 2
	/*
	 * Print the time the spooling area was last modified and the header
	 * for the queue.
	 */
	plastrun();
	printf(" Rank	  Execution Date     Owner     Job #   Job Name\n");
E 2

D 2
        /*
         * Print the queue. If a certain name(s) was requested, print only jobs
         * belonging to that person(s), otherwise print the entire queue.
         * Once again, we have to use "entryfound" (rather than simply 
         * comparing each command line argument) so that if a person's name 
         * appears twice we don't print each file owned by him/her twice.
         *
         *
         * "printrank", "printdate", and "printjobname" all take existing 
         * data and display it in a friendly manner.
         *
         */
        for (i = 0; i < numentries; i++) {
                if ((stat(queue[i]->d_name, &stbuf)) < 0) {
                        continue;
                }
                if (namewanted) {
                        ptr = namelist;
                        entryfound = 0;
E 2
I 2
	/*
	 * Print the queue. If a certain name(s) was requested, print only jobs
	 * belonging to that person(s), otherwise print the entire queue.
	 * Once again, we have to use "entryfound" (rather than simply 
	 * comparing each command line argument) so that if a person's name 
	 * appears twice we don't print each file owned by him/her twice.
	 *
	 *
	 * "printrank", "printdate", and "printjobname" all take existing 
	 * data and display it in a friendly manner.
	 *
	 */
	for (i = 0; i < numentries; i++) {
		if ((stat(queue[i]->d_name, &stbuf)) < 0) {
			continue;
		}
		if (namewanted) {
			ptr = namelist;
			entryfound = 0;
E 2

D 2
                        while (*ptr) {
                                if (getid(*ptr) == stbuf.st_uid)
                                        ++entryfound;
                                ++ptr;
                        }
                        if (!entryfound)
                                continue;
                }
                printrank(rank++);
                printdate(queue[i]->d_name);
                printf("%-10.9s",getname(stbuf.st_uid));
                printf("%5d",stbuf.st_ino);
                printjobname(queue[i]->d_name);
        }
        ++ptr;
}
E 2
I 2
			while (*ptr) {
D 3
				if (getid(*ptr) == stbuf.st_uid)
E 3
I 3
				if (isowner(*ptr,queue[i]->d_name))
E 3
					++entryfound;
				++ptr;
			}
			if (!entryfound)
				continue;
		}
		printrank(rank++);
		printdate(queue[i]->d_name);
D 3
		printf("%-10.9s",getname(stbuf.st_uid));
E 3
I 3
		powner(queue[i]->d_name);
E 3
		printf("%5d",stbuf.st_ino);
		printjobname(queue[i]->d_name);
	}
	++ptr;
}
E 2

/*
D 3
 * Get the full login name of a person using his/her user id.
E 3
I 3
 * See if "name" owns "job".
E 3
 */
D 3
char *
getname(uid)
int uid;
E 3
I 3
isowner(name,job)
char *name;
char *job;
E 3
{
D 2
        struct passwd *pwdinfo;                 /* password info structure */
        
E 2
I 2
D 3
	struct passwd *pwdinfo;			/* password info structure */
	
E 3
I 3
	char buf[30];			/* buffer for 1st line of spoolfile 
					   header */
	FILE *infile;			/* I/O stream to spoolfile */
E 3
E 2

D 2
        if ((pwdinfo = getpwuid(uid)) == 0) {
                perror(uid);
                exit(1);
        }
        return(pwdinfo->pw_name);
E 2
I 2
D 3
	if ((pwdinfo = getpwuid(uid)) == 0) {
		perror(uid);
		exit(1);
E 3
I 3
	if ((infile = fopen(job,"r")) == NULL) {
		fprintf(stderr,"Couldn't open spoolfile");
		perror(job);
		return(0);
E 3
	}
D 3
	return(pwdinfo->pw_name);
E 3
I 3

	if (fscanf(infile,"# owner: %s\n",buf) != 1) {
		fclose(infile);
		return(0);
	}

	fclose(infile);
	return((strcmp(name,buf) == 0) ? 1 : 0);
E 3
E 2
}
I 3

/*
 * Print the owner of the job. This is stored on the first line of the
 * spoolfile. If we run into trouble getting the name, we'll just print "???".
 */
powner(file)
char *file;
{
	char owner[80];				/* the owner */
	FILE *infile;				/* I/O stream to spoolfile */

	/*
	 * Open the job file and grab the first line.
	 */

	if ((infile = fopen(file,"r")) == NULL) {
		printf("%-10.9s","???");
		return;
	}

	if (fscanf(infile,"# owner: %s",owner) != 1) {
		printf("%-10.9s","???");
		fclose(infile);
		return;
	}

	fclose(infile);
	printf("%-10.9s",owner);

}
E 3
D 2
        
E 2
I 2
	
I 3

E 3
E 2
/*
 * Get the uid of a person using his/her login name. Return -1 if no
 * such account name exists.
 */
getid(name)
char *name;
{

D 2
        struct passwd *pwdinfo;                 /* password info structure */
E 2
I 2
	struct passwd *pwdinfo;			/* password info structure */
E 2


D 2
        if ((pwdinfo = getpwnam(name)) == 0)
                return(-1);
E 2
I 2
	if ((pwdinfo = getpwnam(name)) == 0)
		return(-1);
E 2

D 2
        return(pwdinfo->pw_uid);
E 2
I 2
	return(pwdinfo->pw_uid);
E 2
}

/*
 * Print the time the spooling area was updated.
 */
plastrun()
{
D 2
        struct timeval now;                     /* time it is right now */
        struct timezone zone;                   /* NOT USED */
        struct tm *loc;                         /* detail of time it is right */
        u_long lasttime;                        /* last update time in seconds
                                                   since 1/1/70 */
        FILE *last;                             /* file where last update hour
                                                   is stored */
E 2
I 2
	struct timeval now;			/* time it is right now */
	struct timezone zone;			/* NOT USED */
	struct tm *loc;				/* detail of time it is right */
	u_long lasttime;			/* last update time in seconds
						   since 1/1/70 */
	FILE *last;				/* file where last update hour
						   is stored */
E 2


D 2
        /*
         * Open the file where the last update time is stored, and grab the
         * last update hour. The update time is measured in seconds since
         * 1/1/70.
         */
        if ((last = fopen(LASTFILE,"r")) == NULL) {
                perror(LASTFILE);
                exit(1);
        }
        fscanf(last,"%d",(u_long) &lasttime);
        fclose(last);
E 2
I 2
	/*
	 * Open the file where the last update time is stored, and grab the
	 * last update hour. The update time is measured in seconds since
	 * 1/1/70.
	 */
	if ((last = fopen(LASTFILE,"r")) == NULL) {
		perror(LASTFILE);
		exit(1);
	}
	fscanf(last,"%d",(u_long) &lasttime);
	fclose(last);
E 2

D 2
        /*
         * Get a broken down representation of the last update time.
         */
        loc = localtime(&lasttime);
E 2
I 2
	/*
	 * Get a broken down representation of the last update time.
	 */
	loc = localtime(&lasttime);
E 2

D 2
        /*
         * Print the time that the spooling area was last updated.
         */
        printf("\n LAST EXECUTION TIME: %s ",mthnames[loc->tm_mon]);
        printf("%d, 19%d ",loc->tm_mday,loc->tm_year);
        printf("at %d:%02d\n\n",loc->tm_hour,loc->tm_min);
E 2
I 2
	/*
	 * Print the time that the spooling area was last updated.
	 */
	printf("\n LAST EXECUTION TIME: %s ",mthnames[loc->tm_mon]);
D 5
	printf("%d, 19%d ",loc->tm_mday,loc->tm_year);
E 5
I 5
	printf("%d, %d ",loc->tm_mday,loc->tm_year + TM_YEAR_BASE);
E 5
	printf("at %d:%02d\n\n",loc->tm_hour,loc->tm_min);
E 2
}

/*
 * Print the rank of a job. (I've got to admit it, I stole it from "lpq")
 */
static 
printrank(n)
{
D 2
        static char *r[] = {
                "th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"
        };
E 2
I 2
	static char *r[] = {
		"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"
	};
E 2

D 2
        if ((n/10) == 1)
                 printf("%3d%-5s", n,"th");
        else
                 printf("%3d%-5s", n, r[n%10]);
E 2
I 2
	if ((n/10) == 1)
		 printf("%3d%-5s", n,"th");
	else
		 printf("%3d%-5s", n, r[n%10]);
E 2
}

/*
 * Print the date that a job is to be executed. This takes some manipulation 
 * of the file name.
 */
printdate(filename)
char *filename;
{
D 2
        int yday  =  0;                         /* day of year file will be 
                                                   executed */
        int min   =  0;                         /* min. file will be executed */
        int hour  =  0;                         /* hour file will be executed */
        int day   =  0;                         /* day file will be executed */
        int month =  0;                         /* month file will be executed*/
        int year  =  0;                         /* year file will be executed */
        int get_mth_day();                      /* convert a day of year to a
                                                   month and day of month */
        char date[18];                          /* reformatted execution date */
E 2
I 2
	int yday  =  0;				/* day of year file will be 
						   executed */
	int min	  =  0;				/* min. file will be executed */
	int hour  =  0;				/* hour file will be executed */
	int day	  =  0;				/* day file will be executed */
	int month =  0;				/* month file will be executed*/
	int year  =  0;				/* year file will be executed */
	int get_mth_day();			/* convert a day of year to a
						   month and day of month */
	char date[18];				/* reformatted execution date */
E 2

D 2
        /*
         * Pick off the necessary info from the file name and convert the day
         * of year to a month and day of month.
         */
        sscanf(filename,"%2d.%3d.%2d%2d",&year,&yday,&hour,&min);
        get_mth_day(year,yday,&month,&day);
E 2
I 2
	/*
	 * Pick off the necessary info from the file name and convert the day
	 * of year to a month and day of month.
	 */
D 5
	sscanf(filename,"%2d.%3d.%2d%2d",&year,&yday,&hour,&min);
E 5
I 5
	sscanf(filename,"%4d.%3d.%2d%2d",&year,&yday,&hour,&min);
E 5
	get_mth_day(year,yday,&month,&day);
E 2

D 2
        /*
         * Format the execution date of a job.
         */
        sprintf(date,"%3s %2d, 19%2d %02d:%02d",mthnames[month],
                                                    day, year,hour,min);
E 2
I 2
	/*
	 * Format the execution date of a job.
	 */
D 5
	sprintf(date,"%3s %2d, 19%2d %02d:%02d",mthnames[month],
E 5
I 5
	sprintf(date,"%3s %2d, %4d %02d:%02d",mthnames[month],
E 5
						    day, year,hour,min);
E 2

D 2
        /*
         * Print the date the job will be executed.
         */
        printf("%-21.18s",date);
E 2
I 2
	/*
	 * Print the date the job will be executed.
	 */
	printf("%-21.18s",date);
E 2
}

/*
 * Given a day of the year, calculate the month and day of month.
 */
get_mth_day(year,dayofyear,month,day)
int year, dayofyear, *month, *day;

{

D 2
        int i = 1;                              /* for loop index */
        int leap;                               /* are we dealing with a leap
                                                   year? */
                                                /* Table of the number of days 
                                                   in each month of the year.
E 2
I 2
	int i = 1;				/* for loop index */
	int leap;				/* are we dealing with a leap
						   year? */
						/* Table of the number of days 
						   in each month of the year.
E 2

D 2
                                                     dofy_tab[1] -- regular year
                                                     dofy_tab[2] -- leap year 
                                                                              */
E 2
I 2
						     dofy_tab[1] -- regular year
						     dofy_tab[2] -- leap year 
									      */
E 2

D 2
        static int dofy_tab[2][13] = {
                { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        };
E 2
I 2
	static int dofy_tab[2][13] = {
		{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	};
E 2

D 2
        /*
         * Are we dealing with a leap year?
         */
        leap = ((year%4 == 0 && year%100 != 0) || year%100 == 0);
E 2
I 2
	/*
	 * Are we dealing with a leap year?
	 */
D 5
	leap = ((year%4 == 0 && year%100 != 0) || year%100 == 0);
E 5
I 5
	leap = isleap(year);
E 5
E 2

D 2
        /*
         * Calculate the month of the year and day of the month.
         */
        while (dayofyear >= dofy_tab[leap][i]) {
                dayofyear -= dofy_tab[leap][i++];
                ++(*month);
        }
        *day = (dayofyear + 1);
E 2
I 2
	/*
	 * Calculate the month of the year and day of the month.
	 */
	while (dayofyear >= dofy_tab[leap][i]) {
		dayofyear -= dofy_tab[leap][i++];
		++(*month);
	}
	*day = (dayofyear + 1);
E 2
}
D 2
        
E 2
I 2
	
E 2
/*
 * Print a job name. If the old "at" has been used to create the spoolfile,
 * the three line header that the new version of "at" puts in the spoolfile.
 * Thus, we just print "???".
 */
printjobname(file)
char *file;
{
D 2
        char *ch;                               /* char ptr */
        char jobname[80];                       /* the job name */
        FILE *filename;                         /* job file in spooling area */
E 2
I 2
D 3
	char *ch;				/* char ptr */
E 3
I 3
	char *ptr;				/* scratch pointer */
E 3
	char jobname[80];			/* the job name */
	FILE *filename;				/* job file in spooling area */
E 2

D 2
        /*
         * Open the job file and grab the first line.
         */
        printf("   ");
E 2
I 2
	/*
D 3
	 * Open the job file and grab the first line.
E 3
I 3
	 * Open the job file and grab the second line.
E 3
	 */
	printf("   ");
E 2

D 2
        if ((filename = fopen(file,"r")) == NULL) {
                printf("%.27s\n", "???");
                fclose(filename);
                return;
        }
        if (fscanf(filename,"# jobname: %s",jobname) != 1) {
                printf("%.27s\n", "???");
                fclose(filename);
                return;
        }
        fclose(filename);
E 2
I 2
	if ((filename = fopen(file,"r")) == NULL) {
		printf("%.27s\n", "???");
D 3
		fclose(filename);
E 3
		return;
	}
I 3
	/*
	 * We'll yank the first line into the buffer temporarily.
	 */
	fgets(jobname,80,filename);

	/*
	 * Now get the job name.
	 */
E 3
	if (fscanf(filename,"# jobname: %s",jobname) != 1) {
		printf("%.27s\n", "???");
		fclose(filename);
		return;
	}
	fclose(filename);
E 2

D 2
        /*
         * Put a pointer at the begining of the line and remove the basename
         * from the job file.
         */
        ch = jobname;
        if ((ch = (char *)rindex(jobname,'/')) != 0)
                ++ch;
        else 
                ch = jobname;
E 2
I 2
	/*
	 * Put a pointer at the begining of the line and remove the basename
	 * from the job file.
	 */
D 3
	ch = jobname;
	if ((ch = (char *)rindex(jobname,'/')) != 0)
		++ch;
E 3
I 3
	ptr = jobname;
	if ((ptr = (char *)rindex(jobname,'/')) != 0)
		++ptr;
E 3
	else 
D 3
		ch = jobname;
E 3
I 3
		ptr = jobname;
E 3
E 2

D 2
        printf("%.27s\n",ch);
E 2
I 2
D 3
	printf("%.27s\n",ch);
E 3
I 3
	if (strlen(ptr) > 23)
		printf("%.23s ...\n",ptr);
	else
		printf("%.27s\n",ptr);
E 3
E 2
}

/*
 * Do we want to include a file in the queue? (used by "scandir") We are looking
D 5
 * for files with following syntax: yy.ddd.hhhh. so the test is made to see if 
E 5
I 5
 * for files with following syntax: yyyy.ddd.hhhh. so the test is made to see if
E 5
 * the file name has three dots in it. This test will suffice since the only
 * other files in /usr/spool/at don't have any dots in their name.
 */
filewanted(direntry)
struct direct *direntry;
{
D 2
        int numdot = 0;
        char *filename;
E 2
I 2
	int numdot = 0;
	char *filename;
E 2

D 2
        filename = direntry->d_name;
        while (*filename)
                numdot += (*(filename++) == '.');
        return(numdot == 3);
E 2
I 2
	filename = direntry->d_name;
	while (*filename)
		numdot += (*(filename++) == '.');
	return(numdot == 3);
E 2
}

/*
 * Sort files by time of creation. (used by "scandir")
 */
creation(d1, d2)
struct direct **d1, **d2;
{
D 2
        struct stat stbuf1, stbuf2;
E 2
I 2
	struct stat stbuf1, stbuf2;
E 2

D 2
        if (stat((*d1)->d_name,&stbuf1) < 0)
                return(1);
E 2
I 2
	if (stat((*d1)->d_name,&stbuf1) < 0)
		return(1);
E 2

D 2
        if (stat((*d2)->d_name,&stbuf2) < 0)
                return(1);
E 2
I 2
	if (stat((*d2)->d_name,&stbuf2) < 0)
		return(1);
E 2

D 2
        return(stbuf1.st_ctime < stbuf2.st_ctime);
E 2
I 2
	return(stbuf1.st_ctime < stbuf2.st_ctime);
E 2
}
D 2
        
E 2
I 2
	
E 2
/*
 * Print usage info and exit.
 */
usage() 
{
D 2
        fprintf(stderr,"usage:  atq [-c] [-n] [name ...]\n");
        exit(1);
E 2
I 2
	fprintf(stderr,"usage:	atq [-c] [-n] [name ...]\n");
	exit(1);
E 2
}
E 1
