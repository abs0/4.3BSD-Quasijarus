h05191
s 00002/00000/00086
d D 5.6 88/05/04 13:54:50 rick 6 5
c add definition of Now for new loggin routines
e
s 00021/00029/00065
d D 5.5 88/04/05 12:24:38 rick 5 4
c use syslog for errors, use getopt
e
s 00002/00002/00092
d D 5.4 85/06/23 13:46:36 bloom 4 3
c fixes from rick adams
e
s 00031/00025/00063
d D 5.3 85/04/10 15:22:30 ralph 3 2
c more changes from rick adams.
e
s 00000/00000/00088
d D 5.2 85/01/22 14:13:12 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00088/00000/00000
d D 5.1 83/07/02 17:57:54 sam 1 0
c date and time created 83/07/02 17:57:54 by sam
e
u
U
t
T
I 1
#ifndef lint
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
static char sccsid[] = "%W%	(Berkeley) %G%";
E 5
#endif

#include "uucp.h"

I 6
struct timeb Now;

E 6
D 5
#ifndef	SYSBUF
static char SYSBUF[BUFSIZ];
#endif

E 5
D 3
/*******
 *
 *	uulog  -  
 *
 *	options:
 *		-s  -  system name for search
 *		-u  -  user name for search
 *
 *	exit codes:
 *		0  -  normal
 *
 */

E 3
main(argc, argv)
char *argv[];
{
I 5
#ifndef LOGBYSITE
E 5
	FILE *plogf;
I 5
	char u[64], s[64];
#endif /* !LOGBYSITE */
E 5
D 3
	char *system, *user;
E 3
I 3
	char *sys, *user;
I 5
	int c;
	extern char *optarg;
	extern int optind;
E 5
E 3

D 3
	char buf[BUFSIZ], u[20], s[20];
E 3
I 3
D 5
	char buf[BUFSIZ], u[64], s[64];
E 5
I 5
	char buf[BUFSIZ];
E 5
E 3

D 5
	setbuf(stdout, SYSBUF);
E 5
	strcpy(Progname, "uulog");
D 3
	system = user = NULL;
E 3
I 3
	sys = user = NULL;
E 3

D 5

	while (argc>1 && argv[1][0] == '-') {
		switch (argv[1][1]) {
E 5
I 5
	while ((c = getopt(argc, argv, "s:u:")) != EOF)
		switch (c) {
E 5
		case 's':
D 3
			system = &argv[1][2];
			if (*system == NULL && argc > 2 && argv[2][0] != '-') {
				system = &argv[2][0];
E 3
I 3
D 5
			sys = &argv[1][2];
			if (*sys == NULL && argc > 2 && argv[2][0] != '-') {
				sys = &argv[2][0];
E 3
				argv++;
				argc--;
			}
E 5
I 5
			sys = optarg;
E 5
D 3
			if (strlen(system) > 7)
				system[7] = 0;
E 3
I 3
D 4
			if (strlen(sys) > 7)
				sys[7] = '\0';
E 4
I 4
			if (strlen(sys) > MAXBASENAME)
				sys[MAXBASENAME] = '\0';
E 4
			if (versys(&sys) != SUCCESS){
				fprintf(stderr,"uulog: unknown system %s\n", sys);
				sys = NULL;
			}
E 3
			break;
		case 'u':
D 5
			user = &argv[1][2];
			if (*user == NULL && argc > 2 && argv[2][0] != '-') {
				user = &argv[2][0];
				argv++;
				argc--;
			}
E 5
I 5
			user = optarg;
E 5
			break;
I 5
		case '?':
E 5
		default:
D 5
			printf("unknown flag %s\n", argv[1]); break;
E 5
I 5
			fprintf(stderr, "unknown flag %s\n", argv[optind-1]);
			break;
E 5
		}
D 5
		--argc;  argv++;
	}
E 5

D 5

E 5
D 3
	if (user == NULL && system == NULL) {
		fprintf(stderr, "usage: uulog [-u user] [-s system]\n");
E 3
I 3
	if (user == NULL && sys == NULL) {
		fprintf(stderr, "usage: uulog [-u user] [-s sys]\n");
E 3
		exit(1);
	}
D 3
/*	chmod(LOGFILE, 0666);	rm-ed by rti!trt */
E 3

I 3
#ifdef LOGBYSITE
	if (chdir(SPOOL) < 0) {
		perror(SPOOL);
		exit(1);
	}
	/* this program is really obsolete, this is a rude backward compat */
	if (user) {
		sprintf(buf, "exec cat LOG/uu*/* | egrep '^%s '", user);
		system(buf);
	}
	if (sys) {
		sprintf(buf,"exec cat LOG/uu*/%s", sys);
		system(buf);
	}
#else !LOGBYSITE
E 3
	plogf = fopen(LOGFILE, "r");
D 5
	ASSERT(plogf != NULL, "CAN NOT OPEN", LOGFILE, 0);
E 5
I 5
	if (plogf == NULL) {
		syslog(LOG_WARNING, "fopen(%s) failed: %m", LOGFILE);
		cleanup(1);
	}
E 5
	while (fgets(buf, BUFSIZ, plogf) != NULL) {
		sscanf(buf, "%s%s", u, s);
D 5
		if (user != NULL && !prefix(user, u))
E 5
I 5
		if (user != NULL && !(prefix(user, u) || prefix(u, user)))
E 5
			continue;
D 3
		if (system != NULL && !prefix(system, s))
E 3
I 3
D 5
		if (sys != NULL && !prefix(sys, s))
E 5
I 5
		if (sys != NULL && !(prefix(sys, s) || prefix(s, sys)))
E 5
E 3
			continue;
		fputs(buf, stdout);
		fflush(stdout);
	}
I 3
#endif !LOGBYSITE
E 3
	exit(0);
}

cleanup(code)
int code;
{
	exit(code);
}
E 1
