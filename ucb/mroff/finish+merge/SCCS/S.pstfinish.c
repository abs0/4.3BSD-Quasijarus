h51965
s 00002/00002/00107
d D 5.5 2012/02/17 08:31:16 msokolov 5 4
c pass -l through to pstmerge
e
s 00008/00016/00101
d D 5.4 10/10/09 04:38:20 msokolov 4 3
c -F option added
c suck_in_stdin() reimplemented more efficiently
e
s 00021/00032/00096
d D 5.3 10/10/07 05:31:59 msokolov 3 2
c preliminary implementation of -L and -p
e
s 00006/00005/00122
d D 5.2 10/08/23 20:07:39 msokolov 2 1
c guard against extra child processes from the shell
e
s 00127/00000/00000
d D 5.1 10/08/23 18:47:33 msokolov 1 0
c date and time created 10/08/23 18:47:33 by msokolov
e
u
U
t
T
I 1
/*
 * This is a little front-end to pstmerge that can read from a pipe.
 * The intended use is that one can utilize the finishing functionality
 * of pstmerge rather than the merging function.
 *
 * Written by Michael Sokolov, Quasijarus Project,
 * International Free Computing Task Force.
 */

#ifndef lint
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %E%";
E 4
#endif

#include <sys/wait.h>
#include <stdio.h>

I 3
extern char *malloc();

E 3
char pstmerge_pathname[] = "/usr/ucb/pstmerge";
char temp_pathname[] = "/tmp/pstfinishXXXXXX";

D 3
int psout_omit_troffencoding;
int psout_8bit_strings;
int symbolbugfix;
char *pstmerge_argv[6];
E 3
I 3
char **options, **pstmerge_argv;
int noptions;
E 3

main(argc, argv)
	char **argv;
{
	register int i;
	extern int optind;
D 3
	extern char *optarg;
E 3

D 3
	while ((i = getopt(argc, argv, "8NS")) != EOF) {
		switch (i) {
		case '8':
			psout_8bit_strings = 1;
			break;
		case 'N':
			psout_omit_troffencoding = 1;
			break;
		case 'S':
			symbolbugfix = 1;
			break;
		case '?':
usage:			fprintf(stderr, "usage: %s [-8NS] [psfile]\n",
E 3
I 3
D 4
	while ((i = getopt(argc, argv, "8L:NSTip:")) != EOF) {
E 4
I 4
D 5
	while ((i = getopt(argc, argv, "8F:L:NSTip:")) != EOF) {
E 5
I 5
	while ((i = getopt(argc, argv, "8F:L:NSTl:ip:")) != EOF) {
E 5
E 4
		if (i == '?') {
D 4
usage:			fprintf(stderr, "usage: %s [-8LNSp] [psfile]\n",
E 4
I 4
D 5
usage:			fprintf(stderr, "usage: %s [-8FLNSp] [psfile]\n",
E 5
I 5
usage:			fprintf(stderr, "usage: %s [-8FLNSlp] [psfile]\n",
E 5
E 4
E 3
				argv[0]);
			exit(1);
		}
	}
I 3
	options = argv + 1;
	noptions = optind - 1;
E 3

	if (argv[optind]) {
		if (argv[optind+1])
			goto usage;
		/*
		 * since it's a named file rather than stdin,
		 * we can just exec pstmerge
		 */
		execv(pstmerge_pathname, argv);
		perror(pstmerge_pathname);
		exit(1);
	}
	/* working from stdin, don't care if it's a file or a pipe */
	suck_in_stdin();
D 3
	make_pstmerge_argv();
	i = run_pstmerge();
E 3
I 3
	i = make_pstmerge_argv() || run_pstmerge();
E 3
	unlink(temp_pathname);
	exit(i);
}

suck_in_stdin()
{
D 4
	int fd;
	register FILE *of;
	register int ch;
E 4
I 4
	register int fd, cc;
	char buf[8192];
E 4

	fd = mkstemp(temp_pathname);
	if (fd < 0) {
		perror("mkstemp");
		exit(1);
	}
D 4
	of = fdopen(fd, "w");
	if (!of) {
		perror("fdopen");
		close(fd);
		unlink(temp_pathname);
		exit(1);
	}
	while ((ch = getchar()) >= 0)
		putc(ch, of);
	fclose(of);
E 4
I 4
	while ((cc = read(0, buf, sizeof buf)) > 0)
		write(fd, buf, cc);
	close(fd);
E 4
}

make_pstmerge_argv()
{
D 3
	char **ap;

	ap = pstmerge_argv;
	*ap++ = "pstmerge";
	if (psout_8bit_strings)
		*ap++ = "-8";
	if (psout_omit_troffencoding)
		*ap++ = "-N";
	if (symbolbugfix)
		*ap++ = "-S";
	*ap++ = temp_pathname;
	*ap = NULL;
E 3
I 3
	pstmerge_argv = (char **)malloc(sizeof(char **) * (noptions+3));
	if (!pstmerge_argv) {
		perror("malloc");
		return(1);
	}
	pstmerge_argv[0] = "pstmerge";
	if (noptions)
		bcopy(options, pstmerge_argv+1, sizeof(char **) * noptions);
	pstmerge_argv[noptions+1] = temp_pathname;
	pstmerge_argv[noptions+2] = NULL;
	return(0);
E 3
}

run_pstmerge()
{
D 2
	int i;
E 2
I 2
	int pid;
E 2
	union wait w;

D 2
	i = vfork();
	if (i < 0) {
E 2
I 2
	pid = vfork();
	if (pid < 0) {
E 2
		perror("fork");
		return(1);
	}
D 2
	if (!i) {
E 2
I 2
	if (!pid) {
E 2
		execv(pstmerge_pathname, pstmerge_argv);
		perror(pstmerge_pathname);
		_exit(1);
	}
D 2
	wait(&w);
E 2
I 2
	while (wait(&w) != pid)
		;
E 2
	if (w.w_termsig)
		return(1);
	return(w.w_retcode);
}
E 1
