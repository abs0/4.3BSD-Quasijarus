h01141
s 00001/00001/00134
d D 1.15 2013/01/06 07:03:44 msokolov 15 14
c MSDNS => FalconDNS
e
s 00002/00000/00133
d D 1.14 2011/12/20 06:28:06 msokolov 14 13
c report-udp-tc command implemented
e
s 00004/00000/00129
d D 1.13 2011/12/15 02:43:10 msokolov 13 12
c refresh-zone and reload-zone added
e
s 00006/00000/00123
d D 1.12 2011/12/13 03:57:17 msokolov 12 11
c additional dump commands
e
s 00003/00000/00120
d D 1.11 2011/12/13 02:41:15 msokolov 11 10
c class reloading implemented
e
s 00002/00000/00118
d D 1.10 2011/12/12 22:53:42 msokolov 10 9
c refresh-NS-anchor command added
e
s 00004/00000/00114
d D 1.9 2011/12/11 07:15:24 msokolov 9 8
c delete-NS-anchor and reload-NS-anchor implemented
e
s 00002/00000/00112
d D 1.8 2011/12/11 06:46:13 msokolov 8 7
c cache-sweep-now command added
e
s 00001/00000/00111
d D 1.7 2011/12/11 04:47:58 msokolov 7 6
c schedule_cache_sweep() on master-config
e
s 00001/00001/00110
d D 1.6 2011/10/30 19:38:48 msokolov 6 5
c buglet
e
s 00002/00000/00109
d D 1.5 2011/10/30 02:28:51 msokolov 5 4
c query trace hooked in
e
s 00003/00001/00106
d D 1.4 2011/07/18 01:05:02 msokolov 4 3
c tree-dump command implemented
e
s 00004/00000/00103
d D 1.3 2011/07/16 23:40:42 msokolov 3 2
c duplicate ctlsocket line detection
e
s 00003/00002/00100
d D 1.2 2011/07/16 06:08:17 msokolov 2 1
c msdnsctl written
e
s 00102/00000/00000
d D 1.1 2011/07/16 03:41:43 msokolov 1 0
c date and time created 2011/07/16 03:41:43 by msokolov
e
u
U
t
T
I 1
/*
D 15
 * Michael Sokolov's Domain Name Server (MSDNS)
E 15
I 15
 * FalconDNS daemon by Michael Spacefalcon
E 15
 *
 * Control socket interface
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <syslog.h>
I 2
#include "defs.h"
E 2
#include "globals.h"
#include "selectloop.h"

I 8
extern void cache_sweep_cmd();
I 9
extern void cmd_delete_nsanchor();
I 12
extern void cmd_dump_node();
extern void cmd_dump_subtree();
E 12
E 9
E 8
I 4
extern void cmd_dump_tree();
I 12
extern void cmd_hash_info();
E 12
I 10
extern void cmd_refresh_nsanchor();
I 13
extern void cmd_refresh_zone();
E 13
I 11
extern void cmd_reload_class();
E 11
E 10
I 9
extern void cmd_reload_nsanchor();
I 13
extern void cmd_reload_zone();
I 14
extern void cmd_report_udp_tc();
E 14
E 13
E 9
I 5
extern void cmd_trace_query();
E 5

E 4
static int sock;

static void
handle_masterconf()
{
	syslog(LOG_NOTICE, "master-config reload requested");
	read_master_config();
	setup_class_linked_list();
I 7
	schedule_cache_sweep();
E 7
}

static struct cmd {
	char	*kw;
	void	(*func)();
} command_table[] = {
I 8
	{"cache-sweep-now", cache_sweep_cmd},
I 9
	{"delete-NS-anchor", cmd_delete_nsanchor},
I 12
	{"dump-subtree", cmd_dump_subtree},
E 12
E 9
E 8
D 4
	{"dump-tree", NULL},
E 4
I 4
	{"dump-tree", cmd_dump_tree},
I 12
	{"dump-tree-node", cmd_dump_node},
	{"hash-info", cmd_hash_info},
E 12
E 4
	{"master-config", handle_masterconf},
I 10
	{"refresh-NS-anchor", cmd_refresh_nsanchor},
I 11
	{"refresh-class", cmd_reload_class},
I 13
	{"refresh-zone", cmd_refresh_zone},
E 13
E 11
E 10
I 9
	{"reload-NS-anchor", cmd_reload_nsanchor},
I 11
	{"reload-class", cmd_reload_class},
I 13
	{"reload-zone", cmd_reload_zone},
I 14
	{"report-udp-tc", cmd_report_udp_tc},
E 14
E 13
E 11
E 9
I 5
	{"trace", cmd_trace_query},
E 5
	{NULL, NULL}
};

void
ctlsocket_read_handler()
{
D 2
	char command[256];
E 2
I 2
	char command[CTLSOCK_MAXMSG+1];
E 2
	int cmdlen;
	register char *cp;
	register struct cmd *kwp;

D 2
	cmdlen = recv(sock, command, sizeof(command) - 1, 0);
E 2
I 2
	cmdlen = recv(sock, command, CTLSOCK_MAXMSG, 0);
E 2
	if (cmdlen <= 0)
		return;
	command[cmdlen] = 0;
	syslog(LOG_DEBUG, "received control command: %s", command);
	if (!isalpha(command[0])) {
		syslog(LOG_ERR, "invalid input on the control socket");
		return;
	}
	for (cp = command; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	for (kwp = command_table; kwp->kw; kwp++)
		if (!strcmp(kwp->kw, command))
			break;
	if (kwp->func)
		kwp->func(cp);
	else
		syslog(LOG_ERR, "unknown or unimplemented command: %s",
			command);
}

void
setup_control_socket(pathname)
	char *pathname;
{
	struct sockaddr_un addr;

I 3
	if (sock) {
		fprintf(stderr, "msdns.conf: duplicate ctlsocket line\n");
		exit(1);
	}
E 3
	if (!pathname)
		pathname = "ctlsocket";
	if (strlen(pathname)+1 > sizeof(addr.sun_path)) {
		fprintf(stderr, "msdns: ctl socket pathname %s is too long\n",
			pathname);
		exit(1);
	}
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, pathname);
	sock = socket(PF_UNIX, SOCK_DGRAM, 0);
	if (sock < 0) {
		syslog(LOG_CRIT, "creating PF_UNIX dgram socket: %m");
		perror("PF_UNIX socket");
		exit(1);
	}
	unlink(pathname);
	if (bind(sock, &addr, sizeof addr) < 0) {
D 6
		syslog(LOG_ERR, "bind ctl socket to %s: %m");
E 6
I 6
		syslog(LOG_ERR, "bind ctl socket to %s: %m", pathname);
E 6
		perror("bind ctl socket");
		exit(1);
	}
	select_desc[sock].sel_read = ctlsocket_read_handler;
	FD_SET(sock, &select_for_read);
	if (sock > select_max_fd)
		select_max_fd = sock;
}
E 1
