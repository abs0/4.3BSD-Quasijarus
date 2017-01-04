/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Stats reporting: tracking of interesting transient events
 */

#ifndef lint
static char sccsid[] = "@(#)stats.c	1.5 (IFCTF) 2013/01/06";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <ctype.h>
#include <stdio.h>
#include <syslog.h>
#include <time.h>
#include "class.h"
#include "dname.h"
#include "query.h"
#include "globals.h"

#define	MAXLOG_UDP_TC_RESPONSES		10

static struct udptclog {
	time_t	time;
	struct	dname qname;
	int	qtype;
	int	qclass;
	struct	dname resp_dname;
	struct	in_addr resp_ip;
} udptclog[MAXLOG_UDP_TC_RESPONSES];
static int logged_udp_tc_resp;

log_udp_tc_response(q, srvdn, sin)
	register struct query *q;
	struct dname *srvdn;
	struct sockaddr_in *sin;
{
	register struct udptclog *log;

	if (logged_udp_tc_resp >= MAXLOG_UDP_TC_RESPONSES)
		return(-1);
	log = udptclog + logged_udp_tc_resp;
	log->time = current_time;
	dname_copy(&q->q_stages[0].qs_qname, &log->qname);
	log->qtype = q->q_type;
	log->qclass = q->q_class->c_class;
	dname_copy(srvdn, &log->resp_dname);
	bcopy(&sin->sin_addr, &log->resp_ip, sizeof(struct in_addr));
	logged_udp_tc_resp++;
}

void
cmd_report_udp_tc(args)
	char *args;
{
	register char *cp, *np;
	register FILE *f;
	register int i;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp) {
		syslog(LOG_ERR, "usage: report-udp-tc <filename>");
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	f = fopen(np, "w");
	if (!f) {
		syslog(LOG_ERR, "report-udp-tc: %s: %m", np);
		return;
	}
	if (!logged_udp_tc_resp) {
		fputs("UDP TC response log is empty\n", f);
		fclose(f);
		return;
	}
	for (i = 0; i < logged_udp_tc_resp; i++) {
		fputs("TC response received at ", f);
		fputs(asctime(gmtime(&udptclog[i].time)), f);
		fputs("QNAME=", f);
		print_dname(&udptclog[i].qname, f);
		fprintf(f, " QTYPE=%d QCLASS=%d\n", udptclog[i].qtype,
			udptclog[i].qclass);
		fputs("received from ", f);
		fputs(inet_ntoa(udptclog[i].resp_ip), f);
		fputs(" (", f);
		print_dname(&udptclog[i].resp_dname, f);
		fputs(")\n\n", f);
	}
	fprintf(f, "total UDP TC responses logged: %d\n", logged_udp_tc_resp);
	fclose(f);
	logged_udp_tc_resp = 0;
}

static void
stats_report_var(sev, var, msg)
	int sev;
	register int *var;
	char *msg;
{
	if (*var) {
		syslog(sev, msg, *var, *var > 1 ? "s" : "",
			"since last cache sweep");
		*var = 0;
	}
}

stats_report()
{
	stats_report_var(LOG_NOTICE, &stats_incoming_udp_tc,
			 "%d TC UDP response%s received %s");
	stats_report_var(LOG_INFO, &stats_tcpretry_success,
			 "TCP retry succeeded %d time%s %s");
	stats_report_var(LOG_INFO, &stats_tcpretry_fail,
			 "TCP retry failed %d time%s %s");
	stats_report_var(LOG_NOTICE, &stats_tcpretry_tcagain,
			 "TCP retry produced another TC %d time%s %s");
	stats_report_var(LOG_INFO, &stats_tcpretry_badecho,
			 "TCP retry returned bad query echo %d time%s %s");
	stats_report_var(LOG_NOTICE, &stats_outgoing_udp_tc,
			 "%d TC UDP response%s sent %s");
	stats_report_var(LOG_NOTICE, &stats_outgoing_tcp_tc,
			 "%d TC TCP response%s sent %s");
	stats_report_var(LOG_NOTICE, &stats_local_ar_tc,
			 "local AR failed to fit %d time%s %s");
	stats_report_var(LOG_NOTICE, &stats_fwd_ar_tc,
			 "forwarded AR failed to fit %d time%s %s");
}
