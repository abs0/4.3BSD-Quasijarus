/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Control socket interface
 */

#ifndef lint
static char sccsid[] = "@(#)ctlsock.c	1.15 (IFCTF) 2013/01/06";
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <syslog.h>
#include "defs.h"
#include "globals.h"
#include "selectloop.h"

extern void cache_sweep_cmd();
extern void cmd_delete_nsanchor();
extern void cmd_dump_node();
extern void cmd_dump_subtree();
extern void cmd_dump_tree();
extern void cmd_hash_info();
extern void cmd_refresh_nsanchor();
extern void cmd_refresh_zone();
extern void cmd_reload_class();
extern void cmd_reload_nsanchor();
extern void cmd_reload_zone();
extern void cmd_report_udp_tc();
extern void cmd_trace_query();

static int sock;

static void
handle_masterconf()
{
	syslog(LOG_NOTICE, "master-config reload requested");
	read_master_config();
	setup_class_linked_list();
	schedule_cache_sweep();
}

static struct cmd {
	char	*kw;
	void	(*func)();
} command_table[] = {
	{"cache-sweep-now", cache_sweep_cmd},
	{"delete-NS-anchor", cmd_delete_nsanchor},
	{"dump-subtree", cmd_dump_subtree},
	{"dump-tree", cmd_dump_tree},
	{"dump-tree-node", cmd_dump_node},
	{"hash-info", cmd_hash_info},
	{"master-config", handle_masterconf},
	{"refresh-NS-anchor", cmd_refresh_nsanchor},
	{"refresh-class", cmd_reload_class},
	{"refresh-zone", cmd_refresh_zone},
	{"reload-NS-anchor", cmd_reload_nsanchor},
	{"reload-class", cmd_reload_class},
	{"reload-zone", cmd_reload_zone},
	{"report-udp-tc", cmd_report_udp_tc},
	{"trace", cmd_trace_query},
	{NULL, NULL}
};

void
ctlsocket_read_handler()
{
	char command[CTLSOCK_MAXMSG+1];
	int cmdlen;
	register char *cp;
	register struct cmd *kwp;

	cmdlen = recv(sock, command, CTLSOCK_MAXMSG, 0);
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

	if (sock) {
		fprintf(stderr, "msdns.conf: duplicate ctlsocket line\n");
		exit(1);
	}
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
		syslog(LOG_ERR, "bind ctl socket to %s: %m", pathname);
		perror("bind ctl socket");
		exit(1);
	}
	select_desc[sock].sel_read = ctlsocket_read_handler;
	FD_SET(sock, &select_for_read);
	if (sock > select_max_fd)
		select_max_fd = sock;
}
