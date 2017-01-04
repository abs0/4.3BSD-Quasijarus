h37350
s 00001/00001/00406
d D 5.4 99/12/31 18:40:29 msokolov 8 7
c Y2K
e
s 00061/00084/00346
d D 5.3 87/01/18 19:05:30 karels 7 5
c icky icky!
e
s 00061/00083/00347
d R 5.3 87/01/18 18:45:36 karels 6 5
c icky, icky!
e
s 00035/00023/00395
d D 5.2 86/05/28 18:43:43 mckusick 5 4
c update from dss%fatkid@SUN.COM (Daniel Steinberg)
e
s 00013/00001/00405
d D 5.1 85/06/06 09:52:42 dist 4 3
c Add copyright
e
s 00087/00031/00319
d D 1.3 84/08/09 18:21:36 wall 3 2
c modify to account for all spoolfiles being owned by "daemon". modify to run
c as "daemon" instead of "root".
e
s 00224/00224/00126
d D 1.2 84/08/02 10:15:03 mckusick 2 1
c reformat, reinsert sccs headers
e
s 00350/00000/00000
d D 1.1 84/08/02 00:17:35 wall 1 0
c date and time created 84/08/02 00:17:35 by wall
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
static char sccsid[] = "@(#)atrm.c      4.1 (Berkeley) 5/25/84";
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
D 2
 *      synopsis: atrm [-f] [-i] [-] [[job #] [user] ...]
E 2
I 2
 *	synopsis: atrm [-f] [-i] [-] [[job #] [user] ...]
E 2
 *
 *
D 2
 *      Remove files from the directory /usr/spool/at. These files
 *      represent jobs to be run at a later date.
E 2
I 2
 *	Remove files from the directory /usr/spool/at. These files
 *	represent jobs to be run at a later date.
E 2
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

#include <stdio.h>
#include <pwd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/file.h>
#include <sys/stat.h>

D 2
#define SUPERUSER       0                       /* is user super-user? */
#define MAXENTRIES      1000                    /* max # of entries allowed */
#define ATDIR           "/usr/spool/at"         /* spooling area */
E 2
I 2
#define SUPERUSER	0			/* is user super-user? */
#define MAXENTRIES	1000			/* max # of entries allowed */
#define ATDIR		"/usr/spool/at"		/* spooling area */
E 2


D 2
int user;                                       /* person requesting removal */
int fflag = 0;                                  /* suppress announcements? */
int iflag = 0;                                  /* run interactively? */
E 2
I 2
int user;					/* person requesting removal */
int fflag = 0;					/* suppress announcements? */
int iflag = 0;					/* run interactively? */
E 2

main(argc,argv)
int argc;
char **argv;

{
D 2
        int i;                          /* for loop index */
        int userid;                     /* uid of owner of file */
        int isuname;                    /* is a command line argv a user name?*/
        int numjobs;                    /* # of jobs in spooling area */
        int usage();                    /* print usage info and exit */
        int allflag = 0;                /* remove all jobs belonging to user? */
        int jobexists;                  /* does a requested job exist? */
        int alphasort();                /* sort jobs by date of execution */
        int filewanted();               /* should a file be listed in queue? */
        struct stat *statptr;           /* pointer to file stat structure */
        struct stat *stbuf[MAXENTRIES]; /* array of pointers to stat structs */
        struct direct **namelist;       /* names of jobs in spooling area */
E 2
I 2
D 7
	int i;				/* for loop index */
	int userid;			/* uid of owner of file */
E 7
I 7
	register int i;			/* for loop index */
E 7
	int isuname;			/* is a command line argv a user name?*/
	int numjobs;			/* # of jobs in spooling area */
	int usage();			/* print usage info and exit */
	int allflag = 0;		/* remove all jobs belonging to user? */
I 7
	int jobno;
E 7
	int jobexists;			/* does a requested job exist? */
	int alphasort();		/* sort jobs by date of execution */
	int filewanted();		/* should a file be listed in queue? */
I 3
D 7
	char *getname();		/* get a user name from a uid */
E 7
I 7
	char *myname, *getname();	/* current user's name */
	char *owner, *fowner();
E 7
E 3
	struct stat *statptr;		/* pointer to file stat structure */
	struct stat *stbuf[MAXENTRIES]; /* array of pointers to stat structs */
	struct direct **namelist;	/* names of jobs in spooling area */
E 2


D 2
        /*
         * If job number, user name, or "-" is not specified, just print
         * usage info and exit.
         */
        if (argc < 2)
                usage();
E 2
I 2
	/*
	 * If job number, user name, or "-" is not specified, just print
	 * usage info and exit.
	 */
	if (argc < 2)
		usage();
E 2

D 2
        --argc; ++argv;
E 2
I 2
	--argc; ++argv;
E 2

D 2
        /*
         * Process command line flags.
         */
        while (**argv == '-') {
                (*argv)++;
                switch (**argv) {
E 2
I 2
	/*
	 * Process command line flags.
I 5
	 * Special case the "-" option so that others may be grouped.
E 5
	 */
D 5
	while (**argv == '-') {
		(*argv)++;
		switch (**argv) {
E 5
I 5
	while (argc > 0 && **argv == '-') {
		if (*(++(*argv)) == '\0') {
			++allflag;
		} else while (**argv) switch (*(*argv)++) {
E 5
E 2

D 2
                        case '\0':      ++allflag;
                                        break;
E 2
I 2
D 5
			case '\0':	++allflag;
					break;
E 2

E 5
D 2
                        case 'f':       ++fflag;
                                        break;
                                        
                        case 'i':       ++iflag;
                                        break;
                                        
                        default:        usage();
                }
                ++argv; --argc;
        }
E 2
I 2
			case 'f':	++fflag;
					break;
					
			case 'i':	++iflag;
					break;
					
			default:	usage();
		}
		++argv; --argc;
	}
E 2

D 2
        /*
         * If all jobs are to be removed and extra command line arguments 
         * are given, print usage info and exit.
         */
        if (allflag && argc) 
                usage();
E 2
I 2
	/*
	 * If all jobs are to be removed and extra command line arguments 
	 * are given, print usage info and exit.
	 */
	if (allflag && argc) 
		usage();
E 2

D 2
        /*
         * If only certain jobs are to be removed and no job #'s or user
         * names are specified, print usage info and exit.
         */
        if (!allflag && !argc)
                usage();
E 2
I 2
	/*
	 * If only certain jobs are to be removed and no job #'s or user
	 * names are specified, print usage info and exit.
	 */
	if (!allflag && !argc)
		usage();
E 2

D 2
        /*
         * If interactive removal and quiet removal are requested, override
         * quiet removal and run interactively.
         */
        if (iflag && fflag)
                fflag = 0;
E 2
I 2
	/*
	 * If interactive removal and quiet removal are requested, override
	 * quiet removal and run interactively.
	 */
	if (iflag && fflag)
		fflag = 0;
E 2

D 2
        /* 
         * Move to spooling area and get user id of person requesting removal.
         */
        if (chdir(ATDIR) == -1) {
                perror(ATDIR);
                exit(1);
        }
        user = getuid();
E 2
I 2
	/* 
	 * Move to spooling area and get user id of person requesting removal.
	 */
	if (chdir(ATDIR) == -1) {
		perror(ATDIR);
		exit(1);
	}
	user = getuid();
I 7
	myname = getname(user);
E 7
E 2

D 2
        /*
         * Get a list of the files in the spooling area.
         */
        if ((numjobs = scandir(".",&namelist,filewanted, alphasort)) < 0) {
                perror(ATDIR);
                exit(1);
        }
E 2
I 2
	/*
	 * Get a list of the files in the spooling area.
	 */
D 3
	if ((numjobs = scandir(".",&namelist,filewanted, alphasort)) < 0) {
E 3
I 3
	if ((numjobs = scandir(".",&namelist,filewanted,alphasort)) < 0) {
E 3
		perror(ATDIR);
		exit(1);
	}
E 2

D 2
        /*
         * Build an array of pointers to the file stats for all jobs in
         * the spooling area.
         */
        for (i = 0; i < numjobs; ++i) { 
                statptr = (struct stat *) malloc(sizeof(struct stat));
                if (statptr == NULL) {
                        perror("malloc");
                        exit(1);
                }
                if (stat(namelist[i]->d_name,statptr) < 0) {
                        perror("stat");
                        continue;
                }
                stbuf[i] = statptr;
        }
E 2
I 2
	/*
	 * Build an array of pointers to the file stats for all jobs in
	 * the spooling area.
	 */
	for (i = 0; i < numjobs; ++i) { 
		statptr = (struct stat *) malloc(sizeof(struct stat));
		if (statptr == NULL) {
			perror("malloc");
			exit(1);
		}
		if (stat(namelist[i]->d_name,statptr) < 0) {
			perror("stat");
			continue;
		}
		stbuf[i] = statptr;
	}
E 2

D 2
        /*
         * If all jobs belonging to the user are to be removed, compare
         * the user's id to the owner of the file. If they match, remove
         * the file. If the user is the super-user, don't bother comparing
         * the id's. After all files are removed, exit (status 0).
         */
        if (allflag) {
                for (i = 0; i < numjobs; ++i) { 
                        if (user == SUPERUSER || user == stbuf[i]->st_uid)
                                removentry(namelist[i]->d_name,
                                                (int)stbuf[i]->st_ino,
                                                        stbuf[i]->st_uid);
                }
                exit(0);
        }
E 2
I 2
	/*
	 * If all jobs belonging to the user are to be removed, compare
	 * the user's id to the owner of the file. If they match, remove
	 * the file. If the user is the super-user, don't bother comparing
	 * the id's. After all files are removed, exit (status 0).
	 */
	if (allflag) {
		for (i = 0; i < numjobs; ++i) { 
D 3
			if (user == SUPERUSER || user == stbuf[i]->st_uid)
E 3
I 3
D 7
			if (user == SUPERUSER || isowner(getname(user),
							namelist[i]->d_name)) 
E 3
D 5
				removentry(namelist[i]->d_name,
E 5
I 5
				(void) removentry(namelist[i]->d_name,
E 5
						(int)stbuf[i]->st_ino,
D 3
							stbuf[i]->st_uid);
E 3
I 3
							user);
E 7
I 7
			owner = fowner(namelist[i]->d_name); 
			if (isowner(myname, owner)) 
				removentry(namelist[i]->d_name,
				    (int)stbuf[i]->st_ino, NULL);
E 7
E 3
		}
		exit(0);
	}
E 2

D 2
        /*
         * If only certain jobs are to be removed, interpret each command
         * line argument. A check is done to see if it is a user's name or
         * a job number (inode #). If it's a user's name, compare the argument
         * to the files owner. If it's a job number, compare the argument to
         * the inode number of the file. In either case, if a match occurs,
         * try to remove the file. (The function "isusername" scans the
         * argument to see if it is all digits which we will assume means 
         * that it's a job number (a fairly safe assumption?). This is done
         * because we have to determine whether we are dealing with a user
         * name or a job number. By assuming that only arguments that are
         * all digits is a job number, we allow users to have digits in
         * their login name i.e. "johndoe2").
         */
E 2
I 2
	/*
	 * If only certain jobs are to be removed, interpret each command
	 * line argument. A check is done to see if it is a user's name or
	 * a job number (inode #). If it's a user's name, compare the argument
	 * to the files owner. If it's a job number, compare the argument to
	 * the inode number of the file. In either case, if a match occurs,
	 * try to remove the file. (The function "isusername" scans the
	 * argument to see if it is all digits which we will assume means 
	 * that it's a job number (a fairly safe assumption?). This is done
	 * because we have to determine whether we are dealing with a user
	 * name or a job number. By assuming that only arguments that are
	 * all digits is a job number, we allow users to have digits in
	 * their login name i.e. "johndoe2").
	 */
E 2

D 2
        while (argc--) {
                jobexists = 0;
                isuname = isusername(*argv);
                for (i = 0; i < numjobs; ++i) {
E 2
I 2
	while (argc--) {
		jobexists = 0;
		isuname = isusername(*argv);
I 7
		if (!isuname)
			jobno = atoi(*argv);
E 7
		for (i = 0; i < numjobs; ++i) {
E 2

I 5
			/* if the inode number is 0, this entry was removed */
			if (stbuf[i]->st_ino == 0)
				continue;

I 7
			owner = fowner(namelist[i]->d_name);
E 7
E 5
D 2
                        /* 
                         * if argv is a username, compare his/her uid to
                         * the uid of the owner of the file......
                         */
                        if (isuname) {
                                if ((userid = getid(*argv)) == -1) {
                                        printf("%6s: no such ",*argv);
                                        printf("user name\n");
                                        break;
                                }
                                if (stbuf[i]->st_uid != userid)
                                        continue;
E 2
I 2
			/* 
D 7
			 * if argv is a username, compare his/her uid to
			 * the uid of the owner of the file......
			 */
			if (isuname) {
D 3
				if ((userid = getid(*argv)) == -1) {
					printf("%6s: no such ",*argv);
					printf("user name\n");
					break;
				}
				if (stbuf[i]->st_uid != userid)
E 3
I 3
				if (!isowner(*argv,namelist[i]->d_name))
E 3
					continue;
E 2

D 2
                        /*
                         * otherwise, we assume that the argv is a job # and
                         * thus compare argv to the inode (job #) of the file.
                         */
                        } else {
                                if (stbuf[i]->st_ino != atoi(*argv)) 
                                        continue;
                        }
                        ++jobexists;
                        removentry(namelist[i]->d_name, (int)stbuf[i]->st_ino,
                                        stbuf[i]->st_uid);
                }
E 2
I 2
			/*
E 7
I 7
			 * if argv is a username, compare it to
			 * the owner of the file......
E 7
			 * otherwise, we assume that the argv is a job # and
			 * thus compare argv to the inode (job #) of the file.
			 */
I 7
			if (isuname) {
				if (strcmp(*argv, owner))
					continue;
E 7
			} else {
D 7
				if (stbuf[i]->st_ino != atoi(*argv)) 
E 7
I 7
				if (stbuf[i]->st_ino != jobno) 
E 7
					continue;
			}
			++jobexists;
D 5
			removentry(namelist[i]->d_name, (int)stbuf[i]->st_ino,
D 3
					stbuf[i]->st_uid);
E 3
I 3
					user);
E 5
I 5
			/*
D 7
			 * if the entry is ultimately removed, don't
E 7
I 7
			 * if the entry is removed, don't
E 7
			 * try to remove it again later.
			 */
D 7
			if (removentry(namelist[i]->d_name,
			    (int)stbuf[i]->st_ino, user)) {
E 7
I 7
			if (user == SUPERUSER || isowner(myname, owner)) {
				removentry(namelist[i]->d_name,
				    (int)stbuf[i]->st_ino, owner);
E 7
				stbuf[i]->st_ino = 0;
D 7
			}
E 7
I 7
			} else if (!fflag)
				printf("%6d: permission denied\n",
				    stbuf[i]->st_ino);
			if (!isuname)
				break;
E 7
E 5
E 3
		}
E 2

D 2
                /*
                 * If a requested argument doesn't exist, print a message.
                 */
                if (!jobexists && !fflag && !isuname) {
                        printf("%6s: no such job number\n", *argv);
                }
                ++argv;
        }
        exit(0);
}
E 2
I 2
		/*
		 * If a requested argument doesn't exist, print a message.
		 */
		if (!jobexists && !fflag && !isuname) {
D 5
			printf("%6s: no such job number\n", *argv);
E 5
I 5
			fprintf(stderr, "%6s: no such job number\n", *argv);
E 5
		}
		++argv;
	}
	exit(0);
}
E 2

/*
 * Print usage info and exit.
 */
usage()
{
D 2
        fprintf(stderr,"usage: atrm [-f] [-i] [-] [[job #] [user] ...]\n");
        exit(1);
E 2
I 2
	fprintf(stderr,"usage: atrm [-f] [-i] [-] [[job #] [user] ...]\n");
	exit(1);
E 2
}

/*
 * Do we want to include a file in the queue? (used by "scandir") We are looking
D 8
 * for files with following syntax: yy.ddd.hhhh. so the test is made to see if 
E 8
I 8
 * for files with following syntax: yyyy.ddd.hhhh. so the test is made to see if
E 8
 * the file name has three dots in it. This test will suffice since the only
 * other files in /usr/spool/at don't have any dots in their name.
 */
filewanted(direntry)
struct direct *direntry;
{
D 2
        int numdot = 0;                 /* number of dots in a filename */
        char *filename;                 /* filename we are looking at */
E 2
I 2
	int numdot = 0;			/* number of dots in a filename */
	char *filename;			/* filename we are looking at */
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
 * Is a command line argument a username? As noted above we will assume 
 * that an argument that is all digits means that it's a job number, not
 * a user's name. We choose to determine whether an argument is a user name
 * in this manner because then it's ok for someone to have digits in their 
 * user name.
 */
isusername(string)
char *string;
{
D 2
        char *ptr;                      /* pointer used for scanning string */
E 2
I 2
	char *ptr;			/* pointer used for scanning string */
E 2

D 2
        ptr = string;
        while (isdigit(*ptr))
                ++ptr;
        return((*ptr == '\0') ? 0 : 1);
E 2
I 2
	ptr = string;
	while (isdigit(*ptr))
		++ptr;
	return((*ptr == '\0') ? 0 : 1);
E 2
}

/*
 * Remove an entry from the queue. The access of the file is checked for
 * write permission (since all jobs are mode 644). If access is granted,
 * unlink the file. If the fflag (suppress announcements) is not set,
 * print the job number that we are removing and the result of the access
D 3
 * check (either "permission denied" or "removed"). If the super-user is
 * removing jobs, inform him/her who owns each file after it is removed.
 * If we are running interactively (iflag), prompt the user before we 
 * unlink the file.
E 3
I 3
 * check (either "permission denied" or "removed"). If we are running 
 * interactively (iflag), prompt the user before we unlink the file. If 
 * the super-user is removing jobs, inform him/her who owns each file before 
D 5
 * it is removed.
E 5
I 5
D 7
 * it is removed.  Return TRUE if file removed, else FALSE.
E 7
I 7
 * it is removed.
E 7
E 5
E 3
 */
I 5
D 7
int
E 5
D 3
removentry(filename,inode,uid)
E 3
I 3
removentry(filename,inode,user)
E 7
I 7
removentry(filename, inode, owner)
E 7
E 3
char *filename;
int inode;
D 3
int uid;
E 3
I 3
D 7
int user;
E 7
I 7
char *owner;
E 7
E 3
{

D 2
        char *getname();                /* get a user name using a uid */
E 2
I 2
D 3
	char *getname();		/* get a user name using a uid */
E 2


E 3
D 2
        if (!fflag)
                printf("%6d: ",inode);
E 2
I 2
	if (!fflag)
		printf("%6d: ",inode);
E 2

D 2
        if (access(filename,W_OK) < 0) {
                if (!fflag) {
                        printf("permission denied\n");
                }
        } else {
                if (iflag) {
                        if (user == SUPERUSER)
                                printf("  (owned by %s)\t",getname(uid));
                        printf("remove it? ");
                        if (!yes())
                                return;
                }
                if (unlink(filename) < 0) {
                        if (!fflag)
                                printf("unlink: Permission denied.\n");
E 2
I 2
D 3
	if (access(filename,W_OK) < 0) {
E 3
I 3
D 7
	if (!isowner(getname(user),filename) && user != SUPERUSER) {

E 3
		if (!fflag) {
			printf("permission denied\n");
		}
I 5
		return (0);
E 5
I 3

E 3
	} else {
		if (iflag) {
D 3
			if (user == SUPERUSER)
				printf("  (owned by %s)\t",getname(uid));
E 3
I 3
			if (user == SUPERUSER) {
				printf("\t(owned by ");
				powner(filename);
D 5
				printf(")");
E 5
I 5
				printf(") ");
E 5
			}
E 3
			printf("remove it? ");
			if (!yes())
D 5
				return;
E 5
I 5
				return (0);
E 5
		}
		if (unlink(filename) < 0) {
D 3
			if (!fflag)
				printf("unlink: Permission denied.\n");
E 2

E 3
I 3
			if (!fflag) {
D 5
				fputs("FATAL ERROR (unlink fails): ",stdout);
				fflush(stdout);
E 5
I 5
				fputs("could not remove\n", stdout);
E 5
				perror(filename);
			}
E 3
D 2
                        return;
                }
                if (!fflag && !iflag) {
                        printf("removed");
                        if (user == SUPERUSER)
                                printf("\t(owned by %s)",getname(uid));
                        printf("\n");
                }
        }
}
E 2
I 2
D 5
			return;
E 5
I 5
			return (0);
E 5
		}
D 3
		if (!fflag && !iflag) {
			printf("removed");
			if (user == SUPERUSER)
				printf("\t(owned by %s)",getname(uid));
			printf("\n");
		}
E 3
I 3
		if (!fflag && !iflag)
			printf("removed\n");
I 5
		return (1);
E 7
I 7
	if (iflag) {
		if (user == SUPERUSER && owner)
			printf("\t(owned by %s) ", owner);
		printf("remove? ");
		if (!yes())
			return;
E 7
E 5
E 3
	}
I 7
	if (unlink(filename) < 0)
		perror(filename);
	else if (!fflag && !iflag)
		printf("removed\n");
E 7
}
E 2

/*
I 3
D 7
 * See if "name" owns "job".
E 7
I 7
 * See if "name" owns job owned by "jobname".
E 7
 */
D 7
isowner(name,job)
E 7
I 7
isowner(name,jobname)
E 7
char *name;
D 7
char *job;
E 7
I 7
char *jobname;
E 7
{
D 5
	char buf[30];			/* buffer for 1st line of spoolfile 
E 5
I 5
D 7
	char buf[128];			/* buffer for 1st line of spoolfile 
E 5
					   header */
	FILE *infile;			/* I/O stream to spoolfile */
E 7

D 7
	if ((infile = fopen(job,"r")) == NULL) {
D 5
		fprintf(stderr,"Couldn't open spoolfile");
E 5
I 5
		fprintf(stderr,"Couldn't open spoolfile ");
E 5
		perror(job);
		return(0);
	}

D 5
	if (fscanf(infile,"# owner: %s\n",buf) != 1) {
E 5
I 5
	if (fscanf(infile,"# owner: %127s%*[^\n]\n",buf) != 1) {
E 5
		fclose(infile);
		return(0);
	}

D 5
	close(infile);
E 5
I 5
	fclose(infile);
E 5
	return((strcmp(name,buf) == 0) ? 1 : 0);
E 7
I 7
	return (strcmp(name,jobname) == 0);
E 7
}

/*
D 7
 * Print the owner of the job. This is stored on the first line of the
 * spoolfile. If we run into trouble getting the name, we'll just print "???".
E 7
I 7
 * Return the owner of the job. This is stored on the first line of the
 * spoolfile. If we run into trouble getting the name, we'll just return "???".
E 7
 */
D 7
powner(file)
E 7
I 7
char *
fowner(file)
E 7
char *file;
{
D 5
	char owner[80];				/* the owner */
E 5
I 5
D 7
	char owner[128];			/* the owner */
E 7
I 7
	static char owner[128];			/* the owner */
E 7
E 5
	FILE *infile;				/* I/O stream to spoolfile */

	/*
	 * Open the job file and grab the first line.
	 */

	if ((infile = fopen(file,"r")) == NULL) {
D 7
		printf("%s","???");
E 7
		perror(file);
D 7
		return;
E 7
I 7
		return ("???");
E 7
	}

D 5
	if (fscanf(infile,"# owner: %s",owner) != 1) {
E 5
I 5
	if (fscanf(infile,"# owner: %127s%*[^\n]\n",owner) != 1) {
E 5
D 7
		printf("%s","???");
E 7
D 5
		perror(file);
E 5
		fclose(infile);
D 7
		return;
E 7
I 7
		return ("???");
E 7
	}

	fclose(infile);
D 7
	printf("%s",owner);
E 7
I 7
	return (owner);
E 7

}

/*
E 3
 * Get answer to interactive prompts, eating all characters beyond the first
 * one. If a 'y' is typed, return 1.
 */
yes()
{
D 2
        char ch;                                /* dummy variable */
        char ch1;                               /* dummy variable */
E 2
I 2
	char ch;				/* dummy variable */
	char ch1;				/* dummy variable */
E 2

D 2
        ch = ch1 = getchar();
        while (ch1 != '\n' && ch1 != EOF)
                ch1 = getchar();
        return(ch == 'y');
E 2
I 2
	ch = ch1 = getchar();
	while (ch1 != '\n' && ch1 != EOF)
		ch1 = getchar();
I 5
	if (isupper(ch))
		ch = tolower(ch);
E 5
	return(ch == 'y');
E 2
}

/*
 * Get the uid of a person using his/her login name. Return -1 if no
 * such account name exists.
 */
getid(name)
char *name;
{

D 2
        struct passwd *pwdinfo;         /* password info structure */
        
        if ((pwdinfo = getpwnam(name)) == 0)
                return(-1);
E 2
I 2
	struct passwd *pwdinfo;		/* password info structure */
	
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
 * Get the full login name of a person using his/her user id.
 */
char *
getname(uid)
int uid;
{
D 2
        struct passwd *pwdinfo;                 /* password info structure */
        
E 2
I 2
	struct passwd *pwdinfo;			/* password info structure */
I 7
	char *logname, *getlogin();
E 7
	
E 2

D 2
        if ((pwdinfo = getpwuid(uid)) == 0)
                return("???");
        return(pwdinfo->pw_name);
E 2
I 2
D 7
	if ((pwdinfo = getpwuid(uid)) == 0)
		return("???");
E 7
I 7
	logname = getlogin();
	if (logname == NULL || (pwdinfo = getpwnam(logname)) == NULL ||
	    pwdinfo->pw_uid != uid)
		pwdinfo = getpwuid(uid);
	if (pwdinfo == 0) {
		fprintf(stderr, "no name for uid %d?\n", uid);
		exit(1);
	}
E 7
	return(pwdinfo->pw_name);
E 2
}
I 3
D 7

E 7
E 3
E 1
