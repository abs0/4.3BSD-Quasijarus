h16845
s 00036/00025/00054
d D 5.6 88/04/05 12:25:39 rick 6 5
c use syslog for errors, use getopt
e
s 00001/00000/00078
d D 5.5 85/10/09 16:43:05 bloom 5 4
c add declaration of Now (from rick@seismo)
e
s 00005/00005/00073
d D 5.4 85/06/23 13:48:59 bloom 4 3
c fixes from rick adams
e
s 00019/00006/00059
d D 5.3 85/04/10 15:22:39 ralph 3 2
c more changes from rick adams.
e
s 00015/00002/00050
d D 5.2 85/01/22 14:13:18 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00052/00000/00000
d D 5.1 83/07/02 17:57:57 sam 1 0
c date and time created 83/07/02 17:57:57 by sam
e
u
U
t
T
I 1
#ifndef lint
D 6
static char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
static char sccsid[] = "%W%	(Berkeley) %G%";
E 6
#endif

/*
 * Poll named system(s).
 *
 * The poll occurs even if recent attempts have failed,
 * but not if L.sys prohibits the call (e.g. wrong time of day).
 *
D 6
 * AUTHOR
 *	Tom Truscott (rti!trt)
E 6
I 6
 * Original Author: Tom Truscott (rti!trt)
E 6
 */

#include "uucp.h"

I 3
int TransferSucceeded = 1;
I 5
struct timeb Now;
E 5

E 3
main(argc, argv)
D 6
register int argc;
register char **argv;
E 6
I 6
int argc;
char **argv;
E 6
{
I 2
D 6
	int ret;
E 6
	char wrkpre[MAXFULLNAME];
	char file[MAXFULLNAME];
I 3
D 4
	char grade = 'z';
E 4
I 4
	char grade = 'A';
E 4
	int nocall = 0;
I 6
	int c;
	char *sysname;
	extern char *optarg;
	extern int optind;
E 6
E 3

E 2
	if (argc < 2) {
D 3
		fprintf(stderr, "usage: uupoll system ...\n");
E 3
I 3
		fprintf(stderr, "usage: uupoll [-gX] [-n] system ...\n");
E 3
		cleanup(1);
	}

D 2
	chdir(Spool);
E 2
I 2
D 6
	ret = chdir(Spool);
	ASSERT(ret >= 0, "CHDIR FAILED", Spool, ret);
E 6
I 6
	if (chdir(Spool) < 0) {
		syslog(LOG_WARNING, "chdir(%s) failed: %m", Spool);
		cleanup(1);
	}
E 6
E 2
	strcpy(Progname, "uupoll");
	uucpname(Myname);

D 6
	for (--argc, ++argv; argc > 0; --argc, ++argv) {
		if (strcmp(argv[0], Myname) == SAME) {
E 6
I 6
	while ((c = getopt(argc, argv, "g:n")) != EOF)
		switch(c) {
			case 'g':
				grade = *optarg;
				break;
			case 'n':
				nocall++;
				break;
			case '?':
			default:
				fprintf(stderr, "unknown option %s\n",
					argv[optind-1]);
		}

	while(optind < argc) {
		sysname = argv[optind++];
		if (strcmp(sysname, Myname) == SAME) {
E 6
			fprintf(stderr, "This *is* %s!\n", Myname);
			continue;
		}
I 3
D 6
		if (strncmp(argv[0],"-g",2) == SAME) {
			grade = argv[0][2];
			continue;
		}
		if (strcmp(argv[0],"-n") == SAME) {
			nocall++;
			continue;
		}
E 6
E 3

D 3
		if (versys(argv[0])) {
E 3
I 3
D 6
		if (versys(&argv[0])) {
E 3
			fprintf(stderr, "%s: unknown system.\n", argv[0]);
E 6
I 6
		if (versys(&sysname)) {
			fprintf(stderr, "%s: unknown system.\n", sysname);
E 6
			continue;
		}
		/* Remove any STST file that might stop the poll */
D 2
		rmstat(argv[0]);
E 2
I 2
D 3
		sprintf(wrkpre, "LCK..%.7s", argv[0]);
E 3
I 3
D 4
		sprintf(wrkpre, "%s/LCK..%.7s", LOCKDIR, argv[0]);
E 4
I 4
D 6
		sprintf(wrkpre, "%s/LCK..%.*s", LOCKDIR, MAXBASENAME, argv[0]);
E 6
I 6
		sprintf(wrkpre, "%s/LCK..%.*s", LOCKDIR, MAXBASENAME, sysname);
E 6
E 4
E 3
		if (access(wrkpre, 0) < 0)
D 6
			rmstat(argv[0]);
D 4
		sprintf(wrkpre, "%c.%.7s", CMDPRE, argv[0]);
E 4
I 4
		sprintf(wrkpre, "%c.%.*s", CMDPRE, SYSNSIZE, argv[0]);
E 6
I 6
			rmstat(sysname);
		sprintf(wrkpre, "%c.%.*s", CMDPRE, SYSNSIZE, sysname);
E 6
E 4
		if (!iswrk(file, "chk", Spool, wrkpre)) {
D 3
			sprintf(file, "%s/%c.%.7szPOLL", subdir(Spool, CMDPRE),
				CMDPRE, argv[0]);
E 3
I 3
D 4
			sprintf(file, "%s/%c.%.7s%cPOLL", subdir(Spool, CMDPRE),
				CMDPRE, argv[0], grade);
E 4
I 4
			sprintf(file, "%s/%c.%.*s%cPOLL", subdir(Spool, CMDPRE),
D 6
				CMDPRE, SYSNSIZE, argv[0], grade);
E 6
I 6
				CMDPRE, SYSNSIZE, sysname, grade);
E 6
E 4
E 3
			close(creat(file, 0666));
		}
E 2
		/* Attempt the call */
D 3
		xuucico(argv[0]);
E 3
I 3
		if (!nocall)
D 6
			xuucico(argv[0]);
E 6
I 6
			xuucico(sysname);
E 6
E 3
	}
	cleanup(0);
}

cleanup(code)
int code;
{
	exit(code);
}
E 1
