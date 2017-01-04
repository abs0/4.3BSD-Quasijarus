h46340
s 00001/00001/00133
d D 1.5 2013/01/06 07:04:22 msokolov 5 4
c MSDNS => FalconDNS
e
s 00012/00011/00122
d D 1.4 2011/12/21 07:05:22 msokolov 4 3
c severity lowered to LOG_INFO for most TCP retry outcomes
e
s 00008/00002/00125
d D 1.3 2011/12/20 19:48:18 msokolov 3 2
c track and report outcomes of TCP retry attempts (after getting UDP TC)
e
s 00049/00000/00078
d D 1.2 2011/12/20 06:28:07 msokolov 2 1
c report-udp-tc command implemented
e
s 00078/00000/00000
d D 1.1 2011/12/20 06:01:40 msokolov 1 0
c date and time created 2011/12/20 06:01:40 by msokolov
e
u
U
t
T
I 1
/*
D 5
 * Michael Sokolov's Domain Name Server (MSDNS)
E 5
I 5
 * FalconDNS daemon by Michael Spacefalcon
E 5
 *
 * Stats reporting: tracking of interesting transient events
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <netinet/in.h>
I 2
#include <arpa/inet.h>
E 2
#include <arpa/nameser.h>
I 2
#include <ctype.h>
E 2
#include <stdio.h>
#include <syslog.h>
I 2
#include <time.h>
E 2
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
I 2
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
E 2
}

static void
D 4
stats_report_var(var, msg)
E 4
I 4
stats_report_var(sev, var, msg)
	int sev;
E 4
	register int *var;
	char *msg;
{
	if (*var) {
D 4
		syslog(LOG_NOTICE, msg, *var, *var > 1 ? "s" : "",
E 4
I 4
		syslog(sev, msg, *var, *var > 1 ? "s" : "",
E 4
			"since last cache sweep");
		*var = 0;
	}
}

stats_report()
{
D 4
	stats_report_var(&stats_incoming_udp_tc,
E 4
I 4
	stats_report_var(LOG_NOTICE, &stats_incoming_udp_tc,
E 4
			 "%d TC UDP response%s received %s");
D 3
	stats_report_var(&stats_incoming_tcp_tc,
			 "%d TC TCP response%s received %s");
E 3
I 3
D 4
	stats_report_var(&stats_tcpretry_success,
E 4
I 4
	stats_report_var(LOG_INFO, &stats_tcpretry_success,
E 4
			 "TCP retry succeeded %d time%s %s");
D 4
	stats_report_var(&stats_tcpretry_fail,
E 4
I 4
	stats_report_var(LOG_INFO, &stats_tcpretry_fail,
E 4
			 "TCP retry failed %d time%s %s");
D 4
	stats_report_var(&stats_tcpretry_tcagain,
E 4
I 4
	stats_report_var(LOG_NOTICE, &stats_tcpretry_tcagain,
E 4
			 "TCP retry produced another TC %d time%s %s");
D 4
	stats_report_var(&stats_tcpretry_badecho,
E 4
I 4
	stats_report_var(LOG_INFO, &stats_tcpretry_badecho,
E 4
			 "TCP retry returned bad query echo %d time%s %s");
E 3
D 4
	stats_report_var(&stats_outgoing_udp_tc,
E 4
I 4
	stats_report_var(LOG_NOTICE, &stats_outgoing_udp_tc,
E 4
			 "%d TC UDP response%s sent %s");
D 4
	stats_report_var(&stats_outgoing_tcp_tc,
E 4
I 4
	stats_report_var(LOG_NOTICE, &stats_outgoing_tcp_tc,
E 4
			 "%d TC TCP response%s sent %s");
D 4
	stats_report_var(&stats_local_ar_tc,
E 4
I 4
	stats_report_var(LOG_NOTICE, &stats_local_ar_tc,
E 4
			 "local AR failed to fit %d time%s %s");
D 4
	stats_report_var(&stats_fwd_ar_tc,
E 4
I 4
	stats_report_var(LOG_NOTICE, &stats_fwd_ar_tc,
E 4
			 "forwarded AR failed to fit %d time%s %s");
}
E 1
