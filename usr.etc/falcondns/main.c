/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * The main function lives here, along with some
 * initialization-related miscellany.
 */

#ifndef lint
static char sccsid[] = "@(#)main.c	1.9 (IFCTF) 2013/01/12";
#endif

#include <sys/types.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/signal.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <ctype.h>
#include <syslog.h>
#include "globals.h"

main(argc, argv)
	char **argv;
{
	char **ap;

	ensure_descs012();
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
	openlog("dnsd", LOG_PID | LOG_NDELAY, LOG_DAEMON);
	init_selectloop_array();
	read_master_config();
	setup_class_linked_list();
	initdone = 1;

	if (!debug)
		daemonize();

	install_mandatory_sighandlers();
	maximize_memory_limit();
	time(&current_time);
	schedule_cache_sweep();
	select_loop();
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
}

sigchild_handler()
{
	sigchild_flag = 1;
}

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
	sv.sv_handler = sigchild_handler;
	sigvec(SIGCHLD, &sv, NULL);
}

maximize_memory_limit()
{
	struct rlimit lim;

	getrlimit(RLIMIT_DATA, &lim);
	lim.rlim_cur = lim.rlim_max;
	setrlimit(RLIMIT_DATA, &lim);
}

init_error(sev, msg, arg1, arg2, arg3, arg4, arg5, arg6)
	char *msg;
{
	syslog(sev, msg, arg1, arg2, arg3, arg4, arg5, arg6);
	if (!initdone) {
		fprintf(stderr, msg, arg1, arg2, arg3, arg4, arg5, arg6);
		exit(1);
	}
}
