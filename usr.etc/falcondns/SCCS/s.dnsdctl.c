h21522
s 00006/00005/00089
d D 1.5 2013/01/12 08:20:52 msokolov 5 4
c this utility is now dnsdctl, controlling dnsd
e
s 00003/00002/00091
d D 1.4 2013/01/06 07:03:54 msokolov 4 3
c MSDNS => FalconDNS
e
s 00001/00001/00092
d D 1.3 2011/12/14 18:50:47 msokolov 3 2
c default pathname change
e
s 00005/00001/00088
d D 1.2 2011/07/16 06:14:17 msokolov 2 1
c newline on EOF
e
s 00089/00000/00000
d D 1.1 2011/07/16 06:07:36 msokolov 1 0
c date and time created 2011/07/16 06:07:36 by msokolov
e
u
U
t
T
I 1
/*
D 4
 * Michael Sokolov's Domain Name Server (MSDNS)
E 4
I 4
D 5
 * FalconDNS daemon by Michael Spacefalcon
E 5
I 5
 * FalconDNS software suite by Michael Spacefalcon
E 5
 * (previously called MSDNS)
E 4
 *
D 4
 * This little standalone utility connects to the MSDNS process via
E 4
I 4
D 5
 * This little standalone utility connects to the falcondns process via
E 4
 * the UNIX domain control socket and sends ASCII string commands to it.
E 5
I 5
 * This little standalone utility connects to the FalconDNS daemon (dnsd)
 * process via the UNIX domain control socket and sends ASCII string
 * commands to it.
E 5
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <sys/file.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "defs.h"

D 3
char default_ctlsocket[] = "/usr/local/domain/ctlsocket";
E 3
I 3
char default_ctlsocket[] = "/usr/adm/dns/ctlsocket";
E 3
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
D 5
	static char prompt[] = "MSDNS>";
E 5
I 5
	static char prompt[] = "dnsdctl> ";
E 5
I 2
	static char newline = '\n';
E 2
	register char *cp;

	for (;;) {
		if (doprompt)
D 5
			write(1, prompt, 6);
E 5
I 5
			write(1, prompt, 9);
E 5
D 2
		if (!fgets(buf, sizeof buf, stdin))
E 2
I 2
		if (!fgets(buf, sizeof buf, stdin)) {
			if (doprompt)
				write(1, &newline, 1);
E 2
			return;
I 2
		}
E 2
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
E 1
