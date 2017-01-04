h27658
s 00019/00019/00081
d D 4.7 87/11/17 17:23:32 bostic 7 6
c change %D to %ld; make lint happy
e
s 00042/00002/00058
d D 4.6 87/10/31 20:39:39 karels 6 5
c add -l to print whole rusage
e
s 00002/00002/00058
d D 4.5 83/07/01 23:56:53 wnj 5 4
c include problems
e
s 00002/00000/00058
d D 4.4 83/06/02 18:03:38 sam 4 3
c just looking
e
s 00033/00055/00025
d D 4.3 82/11/14 16:34:10 sam 3 2
c convert to 4.1c sys calls and directory layout
e
s 00003/00004/00077
d D 4.2 80/10/10 00:59:35 bill 2 1
c minor formatting fixup
e
s 00081/00000/00000
d D 4.1 80/10/01 17:28:56 bill 1 0
c date and time created 80/10/01 17:28:56 by bill
e
u
U
t
T
I 4
#ifndef lint
E 4
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
static	char *sccsid = "%W% (Berkeley) %G%";
I 4
#endif
E 4
E 2
D 3
/* time command */
E 3

I 3
/*
 * time
 */
E 3
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
D 3
#include <sys/times.h>
E 3
I 3
D 5
#include <time.h>
#include <resource.h>
E 5
I 5
#include <sys/time.h>
#include <sys/resource.h>
E 5
E 3

D 3
extern int errno;
extern char *sys_errlist[];

E 3
main(argc, argv)
D 3
char **argv;
E 3
I 3
	int argc;
	char **argv;
E 3
{
D 3
	struct tms buffer, obuffer;
E 3
D 6
	int status;
E 6
I 6
	int status, lflag = 0;
E 6
D 3
	register p;
	time_t before, after;
E 3
I 3
	register int p;
	struct timeval before, after;
	struct rusage ru;
E 3

D 3
	if(argc<=1)
E 3
I 3
	if (argc<=1)
E 3
		exit(0);
I 6
	if (strcmp(argv[1], "-l") == 0) {
		lflag++;
		argc--;
		argv++;
	}
E 6
D 3
	time(&before);
E 3
I 3
D 7
	gettimeofday(&before, 0);
E 7
I 7
	gettimeofday(&before, (struct timezone *)NULL);
E 7
E 3
	p = fork();
D 3
	if(p == -1) {
		fprintf(stderr, "Try again.\n");
E 3
I 3
	if (p < 0) {
		perror("time");
E 3
		exit(1);
	}
D 3
	if(p == 0) {
E 3
I 3
	if (p == 0) {
E 3
		execvp(argv[1], &argv[1]);
D 3
		fprintf(stderr, "%s: %s\n", argv[1], sys_errlist[errno]);
E 3
I 3
		perror(argv[1]);
E 3
		exit(1);
	}
D 7
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
E 7
I 7
	(void)signal(SIGINT, SIG_IGN);
	(void)signal(SIGQUIT, SIG_IGN);
E 7
D 3
	times(&obuffer);
	while(wait(&status) != p)
		times(&obuffer);
	time(&after);
	if((status&0377) != 0)
		fprintf(stderr,"Command terminated abnormally.\n");
	times(&buffer);
D 2
	fprintf(stderr,"\n");
E 2
	printt("real", (after-before) * 60);
	printt("user", buffer.tms_cutime - obuffer.tms_cutime);
	printt("sys ", buffer.tms_cstime - obuffer.tms_cstime);
E 3
I 3
	while (wait3(&status, 0, &ru) != p)
		;
D 7
	gettimeofday(&after, 0);
E 7
I 7
	gettimeofday(&after, (struct timezone *)NULL);
E 7
	if ((status&0377) != 0)
		fprintf(stderr, "Command terminated abnormally.\n");
	after.tv_sec -= before.tv_sec;
	after.tv_usec -= before.tv_usec;
	if (after.tv_usec < 0)
		after.tv_sec--, after.tv_usec += 1000000;
	printt("real", &after);
	printt("user", &ru.ru_utime);
	printt("sys ", &ru.ru_stime);
E 3
I 2
	fprintf(stderr, "\n");
I 6
	if (lflag) {
		int hz = 100;			/* XXX */
		long ticks;

		ticks = hz * (ru.ru_utime.tv_sec + ru.ru_stime.tv_sec) +
		     hz * (ru.ru_utime.tv_usec + ru.ru_stime.tv_usec) / 1000000;
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_maxrss, "maximum resident set size");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_ixrss / ticks, "average shared memory size");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_idrss / ticks, "average unshared data size");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_isrss / ticks, "average unshared stack size");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_minflt, "page reclaims");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_majflt, "page faults");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_nswap, "swaps");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_inblock, "block input operations");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_oublock, "block output operations");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_msgsnd, "messages sent");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_msgrcv, "messages received");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_nsignals, "signals received");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_nvcsw, "voluntary context switches");
D 7
		fprintf(stderr, "%10D  %s\n",
E 7
I 7
		fprintf(stderr, "%10ld  %s\n",
E 7
			ru.ru_nivcsw, "involuntary context switches");
	}
E 6
E 2
D 3
	exit(status>>8);
E 3
I 3
	exit (status>>8);
E 3
}

D 3
char quant[] = { 6, 10, 10, 6, 10, 6, 10, 10, 10 };
char *pad  = "000      ";
char *sep  = "\0\0.\0:\0:\0\0";
char *nsep = "\0\0.\0 \0 \0\0";

printt(s, a)
char *s;
long a;
E 3
I 3
printt(s, tv)
	char *s;
	struct timeval *tv;
E 3
{
D 3
	char digit[9];
	register i;
	char c;
	int nonzero;
E 3

D 3
	for(i=0; i<9; i++) {
		digit[i] = a % quant[i];
		a /= quant[i];
	}
D 2
	fprintf(stderr,s);
E 2
	nonzero = 0;
	while(--i>0) {
		c = digit[i]!=0 ? digit[i]+'0':
		    nonzero ? '0':
		    pad[i];
		if (c)
		fprintf(stderr,"%c",c);
		nonzero |= digit[i];
		c = nonzero?sep[i]:nsep[i];
		if (c)
		fprintf(stderr,"%c",c);
	}
D 2
	fprintf(stderr,"\n");
E 2
I 2
	fprintf(stderr," %s ",s);
E 3
I 3
D 6
	fprintf(stderr, "%9d.%01d %s ", tv->tv_sec, tv->tv_usec/100000, s);
E 6
I 6
D 7
	fprintf(stderr, "%9d.%02d %s ", tv->tv_sec, tv->tv_usec/10000, s);
E 7
I 7
	fprintf(stderr, "%9ld.%02ld %s ", tv->tv_sec, tv->tv_usec/10000, s);
E 7
E 6
E 3
E 2
}
E 1
