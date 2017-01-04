/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Reading the master configuration file
 * The TCP and UDP ACLs are also maintained here
 */

#ifndef lint
static char sccsid[] = "@(#)masterconf.c	1.34 (IFCTF) 2013/01/13";
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include <syslog.h>
#include <pwd.h>
#include "defs.h"
#include "globals.h"
#include "acl.h"
#include "query.h"

#define	MAX_USER_ACL_ENTRIES	5

struct aclentry tcpserv_acl[MAX_USER_ACL_ENTRIES+1];
struct aclentry udpserv_acl[MAX_USER_ACL_ENTRIES+1];
int tcpserv_acl_entries, udpserv_acl_entries;

static struct aclentry acl_default = {INADDR_ANY, INADDR_ANY, ACL_ALLOW_QUERY};

static char master_conf_filename[] = "master.conf";
static int lineno;

struct keyword {
	char	*kw;
	void	(*func)();
	caddr_t	miscptr;
	int	minval;
};

static void
handle_gen_bool(arg, entry)
	char *arg;
	struct keyword *entry;
{
	register char *cp, *np;
	int *var = (int *)entry->miscptr;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!*cp) {
err:		init_error(LOG_ERR,
			"%s: line %d: %s: boolean argument required\n",
			master_conf_filename, lineno, entry->kw);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	*cp = '\0';
	if (!strcmp(np, "true") || !strcmp(np, "yes") || !strcmp(np, "on") ||
	    !strcmp(np, "1")) {
		*var = 1;
		return;
	} else if (!strcmp(np, "false") || !strcmp(np, "no") ||
		   !strcmp(np, "off") || !strcmp(np, "0")) {
		*var = 0;
		return;
	} else
		goto err;
}

static void
handle_gen_num(arg, entry)
	char *arg;
	struct keyword *entry;
{
	register char *cp;
	int *var = (int *)entry->miscptr;
	register int val;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		init_error(LOG_ERR,
			"%s: line %d: %s: numeric argument required\n",
			master_conf_filename, lineno, entry->kw);
		return;
	}
	val = atoi(cp);
	if (val < entry->minval) {
		init_error(LOG_ERR, "%s: line %d: %s %d: invalid value\n",
			master_conf_filename, lineno, entry->kw, val);
		return;
	}
	*var = val;
}

static void
handle_class(args)
	char *args;
{
	register char *cp, *np;
	int class;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
err:		init_error(LOG_ERR,
			"%s: line %d: class declaration: syntax error\n",
			master_conf_filename, lineno);
		return;
	}
	for (np = cp; isdigit(*cp); cp++)
		;
	class = atoi(np);
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto err;
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	syslog(LOG_DEBUG, "attempting to register class id %d using file %s",
		class, np);
	register_class(class, np);
}

static void
handle_compresscp(args)
	char *args;
{
	register char *cp, *np;
	int accum = 0;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp || *cp == '#') {
badusage:	init_error(LOG_ERR,
	"%s: line %d: usage: compress-case-preserve {udp|tcp|axfr|no}...\n",
			master_conf_filename, lineno);
		return;
	}
	while (*cp) {
		if (*cp == '#')
			break;
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp) {
			*cp++ = '\0';
			while (isspace(*cp))
				cp++;
		}
		if (!strcmp(np, "udp"))
			accum |= QFLAGS_UDPSERV;
		else if (!strcmp(np, "tcp"))
			accum |= QFLAGS_TCPSERV;
		else if (!strcmp(np, "axfr"))
			accum |= QFLAGS_AXFR_CASEPRESERVE;
		else if (!strcmp(np, "no")) {
			if (accum || *cp && *cp != '#')
				goto badusage;
		} else
			goto badusage;
	}
	compress_case_preserve = accum;
}

static void
handle_ctlsocket(arg)
	char *arg;
{
	register char *cp, *np;

	if (initdone)
		return;
	for (cp = arg; isspace(*cp); cp++)
		;
	if (*cp && *cp != '#') {
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		*cp = '\0';
	} else
		np = 0;
	setup_control_socket(np);
}

static void
handle_outsockets(arg)
	char *arg;
{
	register char *cp;
	int num;

	if (initdone)
		return;
	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		fprintf(stderr, "%s: line %d: usage: outbound-sockets N\n",
			master_conf_filename, lineno);
		exit(1);
	}
	num = atoi(cp);
	if (num <= 0) {
		fprintf(stderr,
		"%s: line %d: outbound-sockets parameter must be >= 1\n",
			master_conf_filename, lineno);
		exit(1);
	}
	setup_udpout(num);
}

static void
handle_tcpserv(args)
	char *args;
{
	register char *cp, *np;
	u_long addr;
	int port;

	if (initdone)
		return;
	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp) {
badusage:	fprintf(stderr, "%s: line %d: usage: tcpserv bind.addr port\n",
			master_conf_filename, lineno);
		exit(1);
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	if (!strcmp(np, "*"))
		addr = INADDR_ANY;
	else {
		addr = inet_addr(np);
		if (addr == INADDR_NONE)
			goto badusage;
	}
	while (isspace(*cp))
		cp++;
	if (!isdigit(*cp))
		goto badusage;
	port = atoi(cp);
	setup_tcpserv(addr, port);
}

static void
handle_udpserv(args)
	char *args;
{
	register char *cp, *np;
	u_long addr;
	int port;

	if (initdone)
		return;
	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp) {
badusage:	fprintf(stderr, "%s: line %d: usage: udpserv bind.addr port\n",
			master_conf_filename, lineno);
		exit(1);
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	if (!strcmp(np, "*"))
		addr = INADDR_ANY;
	else {
		addr = inet_addr(np);
		if (addr == INADDR_NONE)
			goto badusage;
	}
	while (isspace(*cp))
		cp++;
	if (!isdigit(*cp))
		goto badusage;
	port = atoi(cp);
	setup_udpserv(addr, port);
}

static void
handle_uid(arg)
	char *arg;
{
	register char *cp, *np;
	register struct passwd *pwd;

	if (initdone)
		return;
	if (geteuid()) {
		fprintf(stderr, "%s: line %d: uid line ignored: not root\n",
			master_conf_filename, lineno);
		return;
	}
	for (cp = arg; isspace(*cp); cp++)
		;
	if (!*cp) {
		fprintf(stderr, "%s: line %d: usage: uid {name|number}\n",
			master_conf_filename, lineno);
		exit(1);
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if (isdigit(np[0]))
		pwd = getpwuid(atoi(np));
	else
		pwd = getpwnam(np);
	if (!pwd) {
		fprintf(stderr, "%s: line %d: uid %s: no such user\n",
			master_conf_filename, lineno, np);
		exit(1);
	}
	setgid(pwd->pw_gid);
	initgroups(pwd->pw_name, pwd->pw_gid);
	setuid(pwd->pw_uid);
}

static
handle_acl_common(proto, args, entry)
	char *proto, *args;
	register struct aclentry *entry;
{
	register char *cp, *np, *mp;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp) {
syntaxerr:	init_error(LOG_ERR,
	"%s: line %d: usage: %s-acl ipaddr[/mask] {allow|deny} [options]\n",
			master_conf_filename, lineno, proto);
		return(0);
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto syntaxerr;
	*cp++ = '\0';
	mp = index(np, '/');
	if (mp)
		*mp++ = '\0';
	entry->acl_ipbase = inet_addr(np);
	if (entry->acl_ipbase == INADDR_NONE)
		goto syntaxerr;
	if (mp) {
		entry->acl_ipmask = inet_addr(mp);
		if (entry->acl_ipmask == INADDR_NONE)
			goto syntaxerr;
	} else
		entry->acl_ipmask = 0xFFFFFFFF;
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto syntaxerr;
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if (!strcmp(np, "allow"))
		entry->acl_perm = ACL_ALLOW_QUERY;
	else if (!strcmp(np, "deny")) {
		entry->acl_perm = 0;
		return(1);
	} else
		goto syntaxerr;
	for (;;) {
		while (isspace(*cp))
			cp++;
		if (!*cp || *cp == '#')
			return(1);
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		if (!strcmp(np, "rec"))
			entry->acl_perm |= ACL_ALLOW_RECURSE;
		else if (!strcmp(np, "axfr"))
			entry->acl_perm |= ACL_ALLOW_AXFR;
		else if (!strcmp(np, "idle"))
			entry->acl_perm |= ACL_ALLOW_IDLE;
		else
			init_error(LOG_ERR,
				"%s: line %d: ACL option %s not understood\n",
				master_conf_filename, lineno, np);
	}
}

static void
handle_tcp_acl(args)
	char *args;
{
	if (tcpserv_acl_entries >= MAX_USER_ACL_ENTRIES) {
		init_error(LOG_ERR,
	"%s: line %d: too many tcp-acl entries, the compiled limit is %d\n",
			master_conf_filename, lineno, MAX_USER_ACL_ENTRIES);
		return;
	}
	if (handle_acl_common("tcp", args, tcpserv_acl + tcpserv_acl_entries))
		tcpserv_acl_entries++;
}

static void
handle_udp_acl(args)
	char *args;
{
	if (udpserv_acl_entries >= MAX_USER_ACL_ENTRIES) {
		init_error(LOG_ERR,
	"%s: line %d: too many udp-acl entries, the compiled limit is %d\n",
			master_conf_filename, lineno, MAX_USER_ACL_ENTRIES);
		return;
	}
	if (handle_acl_common("udp", args, udpserv_acl + udpserv_acl_entries))
		udpserv_acl_entries++;
}

static struct keyword keyword_table[] = {
	{"AA-queries", handle_gen_bool, (caddr_t) &allow_aa_queries},
	{"cache-NS-tempfail", handle_gen_num, (caddr_t) &tempfail_cache_dur, 0},
	{"cache-sweep-interval", handle_gen_num,
		(caddr_t) &cache_sweep_interval, 0},
	{"child-race-timer", handle_gen_num, (caddr_t) &child_race_timer, 1},
	{"class", handle_class},
	{"compress-case-preserve", handle_compresscp},
	{"compress-new-RR-types", handle_gen_bool,
		(caddr_t) &compress_new_types},
	{"ctlsocket", handle_ctlsocket},
	{"echo-question", handle_gen_bool, (caddr_t) &echo_question},
	{"foreign-NS-retries-perserver", handle_gen_num,
		(caddr_t) &askforns_retries_perserver, 1},
	{"foreign-NS-retries-total", handle_gen_num,
		(caddr_t) &askforns_retries_total, 1},
	{"foreign-NS-timeout", handle_gen_num, (caddr_t) &askforns_timeout, 0},
	{"max-hash-chain", handle_gen_num, (caddr_t) &max_hash_chain, 1},
	{"max-nested-queries", handle_gen_num,
		(caddr_t) &max_nested_queries, 0},
	{"max-outbound-tcp", handle_gen_num, (caddr_t) &tcpqueue_limit, 1},
	{"norecurse-cached-answers", handle_gen_bool,
		(caddr_t) &norec_allow_cached_ans},
	{"norecurse-cached-referrals", handle_gen_bool,
		(caddr_t) &norec_allow_cached_ref},
	{"outbound-sockets", handle_outsockets},
	{"outbound-tcp-timeout", handle_gen_num,
		(caddr_t) &outbound_tcp_timeout, 1},
	{"tcp-acl", handle_tcp_acl},
	{"tcpserv", handle_tcpserv},
	{"tcpserv-max-conn", handle_gen_num, (caddr_t) &tcpserv_max_conn, 1},
	{"tcpserv-max-idle", handle_gen_num, (caddr_t) &tcpserv_max_idle, 0},
	{"tcpserv-send-timeout", handle_gen_num,
		(caddr_t) &tcpserv_send_timeout, 0},
	{"ttl-bump-CNAME", handle_gen_num, (caddr_t) &ttl_bump_cname, 0},
	{"ttl-bump-NS", handle_gen_num, (caddr_t) &ttl_bump_ns, 0},
	{"ttl-limit-data", handle_gen_num, (caddr_t) &ttl_limit_data, 0},
	{"ttl-limit-neg", handle_gen_num, (caddr_t) &ttl_limit_ncache, 0},
	{"ttl-limit-NS", handle_gen_num, (caddr_t) &ttl_limit_ns, 0},
	{"ttl-sensible-min", handle_gen_num, (caddr_t) &ttl_sensible_min, 1},
	{"udp-acl", handle_udp_acl},
	{"udpout-debug", handle_gen_bool, (caddr_t) &udpout_debug},
	{"udpserv", handle_udpserv},
	{"uid", handle_uid},
	{NULL, NULL}
};

read_master_config()
{
	FILE *f;
	char linebuf[FGETS_BUFSIZE];
	register char *cp, *np;
	register struct keyword *kwp;

	if (!initdone && !debug && (!getuid() || !geteuid()))
		masterconf_security_check();
	f = fopen(master_conf_filename, "r");
	if (!f) {
		syslog(LOG_CRIT, "fopen %s: %m", master_conf_filename);
		if (!initdone) {
			perror(master_conf_filename);
			exit(1);
		}
		return;
	}
	tcpserv_acl_entries = 0;
	udpserv_acl_entries = 0;
	for (lineno = 1; fgets(linebuf, sizeof linebuf, f); lineno++) {
		for (cp = linebuf; isspace(*cp); cp++)
			;
		if (!*cp || *cp == '#')
			continue;
		if (!isalpha(*cp)) {
			init_error(LOG_ERR, "%s: line %d: syntax error\n",
				master_conf_filename, lineno);
			continue;
		}
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		for (kwp = keyword_table; kwp->kw; kwp++)
			if (!strcmp(kwp->kw, np))
				break;
		if (kwp->func)
			kwp->func(cp, kwp);
		else {
			init_error(LOG_ERR,
				"%s: line %d: %s: unrecognized setting\n",
				master_conf_filename, lineno, np);
		}
	}
	fclose(f);
	bcopy(&acl_default, tcpserv_acl + tcpserv_acl_entries,
		sizeof(struct aclentry));
	bcopy(&acl_default, udpserv_acl + udpserv_acl_entries,
		sizeof(struct aclentry));
}

masterconf_security_check()
{
	struct stat st;

	if (lstat(master_conf_filename, &st) < 0) {
		perror(master_conf_filename);
		exit(1);
	}
	if ((st.st_mode & S_IFMT) != S_IFREG) {
		fprintf(stderr, "%s is not a regular file, refusing to run\n",
			master_conf_filename);
		exit(1);
	}
	if (st.st_uid) {
		fprintf(stderr, "%s is not owned by root, refusing to run\n",
			master_conf_filename);
		exit(1);
	}
	if (st.st_mode & 022) {
		fprintf(stderr, "%s is writable by non-root, refusing to run\n",
			master_conf_filename);
		exit(1);
	}
}
