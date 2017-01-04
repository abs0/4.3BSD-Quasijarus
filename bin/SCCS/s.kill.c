h56766
s 00001/00001/00074
d D 4.4 86/04/20 02:26:28 lepreau 5 4
c allow negative pids to match kernel code.
e
s 00008/00008/00067
d D 4.3 85/06/07 13:51:06 serge 4 2
c updated signal names;  allow kill -0
e
s 00008/00008/00067
d R 4.3 85/02/14 15:50:38 serge 3 2
c updated signal names;  allow kill -0
e
s 00037/00003/00038
d D 4.2 80/10/10 00:48:08 bill 2 1
c kill -NMAE
e
s 00041/00000/00000
d D 4.1 80/10/01 17:27:13 bill 1 0
c date and time created 80/10/01 17:27:13 by bill
e
u
U
t
T
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
static	char *sccsid = "%W% (Berkeley) %G%";
E 2
/*
 * kill - send signal to process
 */

#include <signal.h>
I 2
#include <ctype.h>
E 2

I 2
char *signm[] = { 0,
"HUP", "INT", "QUIT", "ILL", "TRAP", "IOT", "EMT", "FPE",	/* 1-8 */
D 4
"KILL", "BUS", "SEGV", "SYS", "PIPE", "ALRM", "TERM", 0,	/* 9-16 */
"STOP", "TSTP", "CONT", "CHLD", "TTIN", "TTOU", "TINT", "XCPU",	/* 17-24 */
"XFSZ", 0, 0, 0, 0, 0, 0, 0,					/* 25-31 */
E 4
I 4
"KILL", "BUS", "SEGV", "SYS", "PIPE", "ALRM", "TERM", "URG",	/* 9-16 */
"STOP", "TSTP", "CONT", "CHLD", "TTIN", "TTOU", "IO", "XCPU",	/* 17-24 */
"XFSZ", "VTALRM", "PROF", "WINCH", 0, "USR1", "USR2", 0,	/* 25-31 */
E 4
};

E 2
main(argc, argv)
char **argv;
{
	register signo, pid, res;
	int errlev;
	extern char *sys_errlist[];
	extern errno;

	errlev = 0;
	if (argc <= 1) {
	usage:
D 2
		printf("usage: kill [ -signo ] pid ...\n");
E 2
I 2
		printf("usage: kill [ -sig ] pid ...\n");
		printf("for a list of signals: kill -l\n");
E 2
		exit(2);
	}
	if (*argv[1] == '-') {
D 2
		signo = atoi(argv[1]+1);
E 2
I 2
		if (argv[1][1] == 'l') {
D 4
			for (signo = 1; signo <= NSIG; signo++) {
E 4
I 4
			for (signo = 0; signo <= NSIG; signo++) {
E 4
				if (signm[signo])
					printf("%s ", signm[signo]);
				if (signo == 16)
					printf("\n");
			}
			printf("\n");
			exit(0);
		} else if (isdigit(argv[1][1])) {
			signo = atoi(argv[1]+1);
D 4
			if (signo < 1 || signo > NSIG) {
E 4
I 4
			if (signo < 0 || signo > NSIG) {
E 4
				printf("kill: %s: number out of range\n",
				    argv[1]);
				exit(1);
			}
		} else {
			char *name = argv[1]+1;
D 4
			for (signo = 1; signo <= NSIG; signo++)
			if (signm[signo] && !strcmp(signm[signo], name))
				goto foundsig;
E 4
I 4
			for (signo = 0; signo <= NSIG; signo++)
				if (signm[signo] && !strcmp(signm[signo], name))
					goto foundsig;
E 4
			printf("kill: %s: unknown signal; kill -l lists signals\n", name);
			exit(1);
foundsig:
			;
		}
E 2
		argc--;
		argv++;
	} else
		signo = SIGTERM;
	argv++;
	while (argc > 1) {
D 5
		if (**argv<'0' || **argv>'9')
E 5
I 5
		if (!(isdigit(**argv) || **argv == '-'))
E 5
			goto usage;
		res = kill(pid = atoi(*argv), signo);
		if (res<0) {
			printf("%u: %s\n", pid, sys_errlist[errno]);
			errlev = 1;
		}
		argc--;
		argv++;
	}
	return(errlev);
}
E 1
