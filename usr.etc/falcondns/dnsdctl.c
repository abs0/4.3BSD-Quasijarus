/*
 * FalconDNS software suite by Michael Spacefalcon
 * (previously called MSDNS)
 *
 * This little standalone utility connects to the FalconDNS daemon (dnsd)
 * process via the UNIX domain control socket and sends ASCII string
 * commands to it.
 */

#ifndef lint
static char sccsid[] = "@(#)dnsdctl.c	1.5 (IFCTF) 2013/01/12";
#endif

#include <sys/types.h>
#include <sys/file.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "defs.h"

char default_ctlsocket[] = "/usr/adm/dns/ctlsocket";
int sock, doprompt;

main(argc, argv)
	char **argv;
{
	char *pathname;
	struct sockaddr_un addr;

	ensure_descs012();
	if (argc >= 2)
		pathname = argv[1];
	else
		pathname = default_ctlsocket;
	if (strlen(pathname)+1 > sizeof(addr.sun_path)) {
		fprintf(stderr, "socket pathname is too long\n");
		exit(1);
	}
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, pathname);
	sock = socket(PF_UNIX, SOCK_DGRAM, 0);
	if (sock < 0) {
		perror("PF_UNIX socket");
		exit(1);
	}
	if (connect(sock, &addr, sizeof addr) < 0) {
		perror(pathname);
		exit(1);
	}
	doprompt = isatty(0);
	process_lines();
	exit(0);
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

process_lines()
{
	char buf[CTLSOCK_MAXMSG+1];
	static char prompt[] = "dnsdctl> ";
	static char newline = '\n';
	register char *cp;

	for (;;) {
		if (doprompt)
			write(1, prompt, 9);
		if (!fgets(buf, sizeof buf, stdin)) {
			if (doprompt)
				write(1, &newline, 1);
			return;
		}
		for (cp = buf; isspace(*cp); cp++)
			;
		if (!*cp)
			continue;
		if (!isalpha(*cp)) {
			fprintf(stderr, "Invalid input\n");
			continue;
		}
		send(sock, cp, strlen(cp), 0);
	}
}
