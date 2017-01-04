h38491
s 00001/00001/00157
d D 1.9 2013/01/12 08:27:10 msokolov 9 8
c call ourselves dnsd for syslog
e
s 00001/00001/00157
d D 1.8 2013/01/06 07:03:37 msokolov 8 7
c MSDNS => FalconDNS
e
s 00012/00000/00146
d D 1.7 2011/12/17 08:47:49 msokolov 7 6
c maximize memory limit
e
s 00007/00000/00139
d D 1.6 2011/12/15 02:55:24 msokolov 6 5
c sigchild_flag implemented
e
s 00015/00000/00124
d D 1.5 2011/12/14 01:48:44 msokolov 5 4
c need to ignore SIGPIPE for TCP
e
s 00002/00000/00122
d D 1.4 2011/12/11 04:46:35 msokolov 4 3
c initial schedule_cache_sweep()
e
s 00001/00001/00121
d D 1.3 2011/07/16 02:14:19 msokolov 3 2
c LOG_PID
e
s 00073/00001/00049
d D 1.2 2011/07/14 22:51:52 msokolov 2 1
c daemonization better thought through
e
s 00050/00000/00000
d D 1.1 11/07/11 08:04:05 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
D 8
 * Michael Sokolov's Domain Name Server (MSDNS)
E 8
I 8
 * FalconDNS daemon by Michael Spacefalcon
E 8
 *
D 2
 * The main function lives here
E 2
I 2
 * The main function lives here, along with some
 * initialization-related miscellany.
E 2
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 2
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/signal.h>
I 7
#include <sys/time.h>
#include <sys/resource.h>
E 7
E 2
#include <stdio.h>
#include <ctype.h>
#include <syslog.h>
#include "globals.h"

main(argc, argv)
	char **argv;
{
	char **ap;

I 2
	ensure_descs012();
E 2
	ap = argv + 1;
	if (*ap && ap[0][0] == '-') {
		if (ap[0][1] == 'd') {
			if (isdigit(ap[0][2]))
				debug = atoi(*ap + 2);
			else
				debug = 1;
		} else {
			fprintf(stderr, "%s: unknown option: %s\n", argv[0],
				*ap);
			exit(1);
		}
		ap++;
	}
	if (*ap)
		msdns_directory = *ap;
	else
		msdns_directory = default_msdns_directory;
	if (chdir(msdns_directory) < 0) {
		perror(msdns_directory);
		exit(1);
	}
D 3
	openlog("msdns", LOG_NDELAY, LOG_DAEMON);
E 3
I 3
D 9
	openlog("msdns", LOG_PID | LOG_NDELAY, LOG_DAEMON);
E 9
I 9
	openlog("dnsd", LOG_PID | LOG_NDELAY, LOG_DAEMON);
E 9
E 3
	init_selectloop_array();
	read_master_config();
	setup_class_linked_list();
I 2
	initdone = 1;
E 2

I 2
	if (!debug)
		daemonize();

I 5
	install_mandatory_sighandlers();
I 7
	maximize_memory_limit();
E 7
E 5
I 4
	time(&current_time);
	schedule_cache_sweep();
E 4
E 2
	select_loop();
I 2
}

ensure_descs012()
{
	register int fd;

loop:	fd = open("/dev/null", O_RDWR);
	if (fd < 0)
		return;
	if (fd < 2)
		goto loop;
	if (fd > 2)
		close(fd);
}

daemonize()
{
	register int i;
	struct sigvec sv;

	i = fork();
	if (i < 0) {
		perror("fork");
		exit(1);
	}
	if (i)
		exit(0);
	close(0);
	close(1);
	close(2);
	open("/dev/null", O_RDWR);
	dup(0);
	dup(0);
	i = open("/dev/tty", O_RDWR);
	if (i >= 0) {
		ioctl(i, TIOCNOTTY, NULL);
		close(i);
	}
	setpgrp(0, 0);
	sv.sv_handler = SIG_IGN;
	sv.sv_mask = 0;
	sv.sv_flags = 0;
	/*
	 * That's right, we ignore SIGHUP rather than install a handler.
	 * We'll use a control socket instead to command various
	 * in-flight reconfig operations: signals are a very poor
	 * IPC mechanism.
	 */
	sigvec(SIGHUP, &sv, NULL);
	sigvec(SIGINT, &sv, NULL);
	sigvec(SIGTSTP, &sv, NULL);
	sigvec(SIGTTIN, &sv, NULL);
	sigvec(SIGTTOU, &sv, NULL);
I 5
}

I 6
sigchild_handler()
{
	sigchild_flag = 1;
}

E 6
/*
 * This function installs those signal handlers which are mandatory
 * for our correct operation whether we daemonize or not.
 */
install_mandatory_sighandlers()
{
	struct sigvec sv;

	sv.sv_handler = SIG_IGN;
	sv.sv_mask = 0;
	sv.sv_flags = 0;
	sigvec(SIGPIPE, &sv, NULL);
I 6
	sv.sv_handler = sigchild_handler;
	sigvec(SIGCHLD, &sv, NULL);
I 7
}

maximize_memory_limit()
{
	struct rlimit lim;

	getrlimit(RLIMIT_DATA, &lim);
	lim.rlim_cur = lim.rlim_max;
	setrlimit(RLIMIT_DATA, &lim);
E 7
E 6
E 5
}

init_error(sev, msg, arg1, arg2, arg3, arg4, arg5, arg6)
	char *msg;
{
	syslog(sev, msg, arg1, arg2, arg3, arg4, arg5, arg6);
	if (!initdone) {
		fprintf(stderr, msg, arg1, arg2, arg3, arg4, arg5, arg6);
		exit(1);
	}
E 2
}
E 1
