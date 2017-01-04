h06379
s 00006/00002/00168
d D 4.5 87/10/22 19:48:38 bostic 5 4
c ANSI C; sprintf now returns an int.
e
s 00006/00003/00164
d D 4.4 87/09/11 13:47:55 jak 4 3
c bugs caught by Sun and some clearerr-type problems I thought I'd fixed
e
s 00067/00007/00100
d D 4.3 86/05/15 17:58:49 bloom 3 2
c updates from John Kunze
e
s 00026/00017/00081
d D 4.2 83/04/25 23:59:11 mckusick 2 1
c 
e
s 00098/00000/00000
d D 4.1 83/02/24 12:56:10 mckusick 1 0
c date and time created 83/02/24 12:56:10 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include "stdio.h"
I 2
#include "sys/types.h"
I 5
#include "sys/file.h"
E 5
#include "sys/stat.h"
E 2
#include "lrnref.h"

I 3
char learnrc[100];

E 3
selsub(argc,argv)
char *argv[];
{
D 2
	char ans1[100], *cp;
E 2
I 2
	char ans1[100];
E 2
D 3
	static char ans2[30];
	static char dirname[20];
	static char subname[20];
I 2
	struct stat statbuf;
E 3
I 3
	static char ans2[40];
	static char dirname[40];
	static char subname[40];
	FILE *fp;
	char *getenv();
	char *home;
E 3
E 2

	if (argc > 1 && argv[1][0] == '-') {
		direct = argv[1]+1;
		argc--;
		argv++;
	}
D 2
	chknam(direct);
E 2
	if (chdir(direct) != 0) {
D 2
		fprintf(stderr, "can't cd to %s\,", direct);
E 2
I 2
		perror(direct);
		fprintf(stderr, "Selsub:  couldn't cd to non-standard directory\n");
E 2
		exit(1);
	}
	sname = argc > 1 ? argv[1] : 0;
D 2
	if (argc > 2)
E 2
I 2
	if (argc > 2) {
E 2
		strcpy (level=ans2, argv[2]);
I 2
		if (strcmp(level, "-") == 0)	/* no lesson name is - */
			ask = 1;
I 3
		else if (strcmp(level, "0") == 0)
			level = 0;
E 3
		else
D 3
			again = 1;	/* treat as if "again lesson" */
E 3
I 3
			again = 1;	/* treat as if "again" lesson */
E 3
	}
E 2
	else
		level = 0;
	if (argc > 3 )
		speed = atoi(argv[3]);
I 3
	if ((home = getenv("HOME")) != NULL) {
		sprintf(learnrc, "%s/.learnrc", home);
		if ((fp=fopen(learnrc, "r")) != NULL) {
			char xsub[40], xlev[40]; int xsp;
			fscanf(fp, "%s %s %d", xsub, xlev, &xsp);
			fclose(fp);
			if (*xsub && *xlev && xsp >= 0	/* all read OK */
			    && (argc == 2 && strcmp(sname, xsub) == 0
			      || argc <= 1)) {
				strcpy(sname = subname, xsub);
				strcpy(level = ans2, xlev);
				speed = xsp;
				again = 1;
	printf("[ Taking up where you left off last time:  learn %s %s.\n",
		sname, level);
	printf("%s\n  \"rm $HOME/.learnrc\", and re-enter with \"learn %s\". ]\n",
		"  To start this sequence over leave learn by typing \"bye\", then",
		sname);
			}
		}
	}
E 3
	if (!sname) {
		printf("These are the available courses -\n");
		list("Linfo");
		printf("If you want more information about the courses,\n");
		printf("or if you have never used 'learn' before,\n");
D 2
		printf("type 'return'; otherwise type the name of\n");
		printf("the course you want, followed by 'return'.\n");
E 2
I 2
		printf("press RETURN; otherwise type the name of\n");
		printf("the course you want, followed by RETURN.\n");
E 2
		fflush(stdout);
D 4
		gets(sname=subname);
E 4
I 4
		if (gets(sname=subname) == NULL)
			exit(0);
E 4
		if (sname[0] == '\0') {
			list("Xinfo");
			do {
				printf("\nWhich subject?  ");
				fflush(stdout);
D 4
				gets(sname=subname);
E 4
I 4
				if (gets(sname=subname) == NULL)
					exit(0);
E 4
			} while (sname[0] == '\0');
		}
	}
	chknam(sname);
I 2
D 3
	stat(sname, &statbuf);
	total = statbuf.st_size / 16 - 2;	/* size/dirsize-(.+..) */
E 3
I 3
	total = cntlessons(sname);
E 3
E 2
	if (!level) {
		printf("If you were in the middle of this subject\n");
		printf("and want to start where you left off, type\n");
		printf("the last lesson number the computer printed.\n");
D 2
		printf("To start at the beginning, just hit return.\n");
E 2
I 2
		printf("If you don't know the number, type in a word\n");
		printf("you think might appear in the lesson you want,\n");
		printf("and I will look for the first lesson containing it.\n");
		printf("To start at the beginning, just hit RETURN.\n");
E 2
		fflush(stdout);
D 4
		gets(ans2);
E 4
I 4
		if (gets(ans2) == NULL)
			exit(0);
E 4
		if (ans2[0]==0)
			strcpy(ans2,"0");
I 3
		else
			again = 1;
E 3
D 2
		for (cp=ans2; *cp; cp++)
			if (*cp == '(' || *cp == ' ')
				*cp= 0;
E 2
		level=ans2;
I 3
		getlesson();
E 3
	}

	/* make new directory for user to play in */
D 2
	if (chdir("play") != 0) {
		fprintf(stderr, "can't cd to playpen\n");
E 2
I 2
	if (chdir("/tmp") != 0) {
		perror("/tmp");
		fprintf(stderr, "Selsub:  couldn't cd to public directory\n");
E 2
		exit(1);
	}
	sprintf(dir=dirname, "pl%da", getpid());
	sprintf(ans1, "mkdir %s", dir);
	system(ans1);
	if (chdir(dir) < 0) {
D 2
		fprintf(stderr, "Couldn't create working directory.\nBye.\n");
E 2
I 2
		perror(dir);
		fprintf(stderr, "Selsub:  couldn't make play directory with %s.\nBye.\n", ans1);
E 2
		exit(1);
	}
	/* after this point, we have a working directory. */
	/* have to call wrapup to clean up */
D 5
	if (access(sprintf(ans1, "%s/%s/Init", direct, sname), 04)==0)
D 2
		if (system(sprintf(ans1, "%s/%s/Init %s", direct,sname, level)) != 0) {
E 2
I 2
		if (system(sprintf(ans1, "%s/%s/Init %s", direct, sname, level)) != 0) {
E 5
I 5
	(void)sprintf(ans1, "%s/%s/Init", direct, sname);
	if (access(ans1, R_OK)==0) {
		(void)sprintf(ans1, "%s/%s/Init %s", direct, sname, level);
		if (system(ans1) != 0) {
E 5
E 2
			printf("Leaving learn.\n");
			wrapup(1);
		}
I 5
	}
E 5
D 2
	if (level[0] == '-')	/* no lesson names start with - */
		ask = 1;
	start(level);
E 2
}

chknam(name)
char *name;
{
	if (access(name, 05) < 0) {
		printf("Sorry, there is no subject or lesson named %s.\nBye.\n", name);
		exit(1);
	}
I 3
}

#ifndef DIR
#include <sys/dir.h>
#endif

cntlessons(sname)	/* return number of entries in lesson directory; */
char *sname;		/* approximate at best since I don't count L0, Init */
{			/* and lessons skipped by good students */
#if BSD4_2
	struct direct dbuf;
	register struct direct *ep = &dbuf;	/* directory entry pointer */
	int n = 0;
	DIR *dp;

	if ((dp = opendir(sname)) == NULL) {
		perror(sname);
		wrapup(1);
	}
	for (ep = readdir(dp); ep != NULL; ep = readdir(dp)) {
		if (ep->d_ino != 0)
			n++;
	}
	closedir(dp);
	return n - 2;				/* minus . and .. */
#else
	struct stat statbuf;

	stat(sname, &statbuf);
	return statbuf.st_size / 16 - 2;
#endif
E 3
}
E 1
