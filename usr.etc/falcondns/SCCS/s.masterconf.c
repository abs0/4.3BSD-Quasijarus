h16215
s 00000/00003/00550
d D 1.34 2013/01/13 22:03:50 msokolov 34 33
c NS-glue-answers and cache-max-rdlength tunable settings are no more
e
s 00004/00004/00549
d D 1.33 2013/01/13 07:02:38 msokolov 33 32
c new ttl-limit-neg setting, ttl-bump-{CNAME,NS} changed to numbers
e
s 00001/00001/00552
d D 1.32 2013/01/07 21:04:49 msokolov 32 31
c msdns.conf => master.conf
e
s 00001/00001/00552
d D 1.31 2013/01/06 07:03:39 msokolov 31 30
c MSDNS => FalconDNS
e
s 00028/00000/00525
d D 1.30 2011/12/26 01:46:12 msokolov 30 29
c msdns.conf security check implemented
e
s 00006/00004/00519
d D 1.29 2011/12/25 05:42:44 msokolov 29 28
c allow comments at the end of config lines
e
s 00002/00000/00521
d D 1.28 2011/12/23 07:43:01 msokolov 28 27
c compress-new-RR-types config setting
e
s 00004/00001/00517
d D 1.27 2011/12/22 05:52:15 msokolov 27 26
c ttl-limit tunable setting split into several
e
s 00001/00000/00517
d D 1.26 2011/12/18 08:27:21 msokolov 26 25
c cache-NS-tempfail tunable setting added
e
s 00001/00000/00516
d D 1.25 2011/12/17 08:29:07 msokolov 25 24
c child-race-timer tunable
e
s 00003/00001/00513
d D 1.24 2011/12/14 20:45:53 msokolov 24 23
c globals and tunable settings for the outbound TCP service
e
s 00014/00006/00500
d D 1.23 2011/12/14 18:57:22 msokolov 23 22
c allow * to specify INADDR_ANY for tcpserv and udpserv
e
s 00040/00002/00466
d D 1.22 2011/12/13 23:05:30 msokolov 22 21
c tcpserv implemented
e
s 00002/00000/00466
d D 1.21 2011/12/11 03:35:57 msokolov 21 20
c preparations for cache s
e
s 00025/00009/00441
d D 1.20 2011/12/10 06:01:19 msokolov 20 19
c legal minimums implemented for numeric settings
e
s 00005/00000/00445
d D 1.19 2011/12/08 05:15:36 msokolov 19 18
c configurable policy settings for caching/glue corner cases
e
s 00005/00000/00440
d D 1.18 2011/12/08 00:59:27 msokolov 18 17
c uid setting: check if we are root first
e
s 00036/00001/00404
d D 1.17 2011/12/08 00:50:28 msokolov 17 16
c uid setting implemented
e
s 00072/00237/00333
d D 1.16 2011/12/08 00:32:00 msokolov 16 15
c reorg without massive code duplication, using generic functions
e
s 00022/00000/00548
d D 1.15 2011/12/07 23:14:23 msokolov 15 14
c fixed 'fromlen' bug in udpout.c
c created udpout-debug apparatus in the process of chasing after that bug
e
s 00102/00000/00446
d D 1.14 2011/12/07 19:01:12 msokolov 14 13
c caching and TTL tunable settings
e
s 00054/00000/00392
d D 1.13 2011/12/01 05:49:36 msokolov 13 12
c foreign-NS-* settings implemented
e
s 00018/00000/00374
d D 1.12 2011/11/05 11:05:33 msokolov 12 11
c max-nested-queries setting implemented
e
s 00024/00014/00350
d D 1.11 2011/11/02 02:02:09 msokolov 11 10
c proper handling of multiple local IP addresses in udpserv
e
s 00021/00000/00343
d D 1.10 2011/11/01 23:40:01 msokolov 10 9
c outbound-sockets implemented
e
s 00040/00000/00303
d D 1.9 2011/11/01 03:32:20 msokolov 9 8
c compress-case-preserve setting implemented
e
s 00116/00000/00187
d D 1.8 2011/11/01 02:27:56 msokolov 8 7
c tcp-acl and udp-acl implemented
e
s 00025/00000/00162
d D 1.7 2011/10/30 19:40:02 msokolov 7 6
c udpserv is now live
e
s 00039/00000/00123
d D 1.6 2011/09/07 07:00:09 msokolov 6 5
c echo-question setting implemented
e
s 00020/00000/00103
d D 1.5 2011/07/16 03:43:30 msokolov 5 4
c ctlsocket mechanism implemented
e
s 00014/00010/00089
d D 1.4 2011/07/14 22:51:53 msokolov 4 3
c daemonization better thought through
e
s 00002/00001/00097
d D 1.3 2011/07/13 19:23:19 msokolov 3 2
c we now read the class def file, although don't do anything with it yet
e
s 00002/00000/00096
d D 1.2 11/07/11 16:43:03 msokolov 2 1
c a little debug aid
e
s 00096/00000/00000
d D 1.1 11/07/11 08:04:05 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
D 31
 * Michael Sokolov's Domain Name Server (MSDNS)
E 31
I 31
 * FalconDNS daemon by Michael Spacefalcon
E 31
 *
 * Reading the master configuration file
I 8
 * The TCP and UDP ACLs are also maintained here
E 8
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 30
#include <sys/stat.h>
E 30
I 8
#include <netinet/in.h>
#include <arpa/inet.h>
E 8
I 7
#include <arpa/nameser.h>
E 7
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
I 4
#include <syslog.h>
I 17
#include <pwd.h>
E 17
E 4
I 3
#include "defs.h"
E 3
#include "globals.h"
I 8
#include "acl.h"
I 9
#include "query.h"
E 9
E 8

I 8
#define	MAX_USER_ACL_ENTRIES	5

struct aclentry tcpserv_acl[MAX_USER_ACL_ENTRIES+1];
struct aclentry udpserv_acl[MAX_USER_ACL_ENTRIES+1];
int tcpserv_acl_entries, udpserv_acl_entries;

static struct aclentry acl_default = {INADDR_ANY, INADDR_ANY, ACL_ALLOW_QUERY};

E 8
D 32
static char master_conf_filename[] = "msdns.conf";
E 32
I 32
static char master_conf_filename[] = "master.conf";
E 32
static int lineno;

I 16
struct keyword {
	char	*kw;
	void	(*func)();
	caddr_t	miscptr;
I 20
	int	minval;
E 20
};

E 16
static void
I 16
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
I 20
	register int val;
E 20

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		init_error(LOG_ERR,
			"%s: line %d: %s: numeric argument required\n",
			master_conf_filename, lineno, entry->kw);
		return;
	}
D 20
	*var = atoi(cp);
E 20
I 20
	val = atoi(cp);
	if (val < entry->minval) {
		init_error(LOG_ERR, "%s: line %d: %s %d: invalid value\n",
			master_conf_filename, lineno, entry->kw, val);
		return;
	}
	*var = val;
E 20
}

static void
E 16
handle_class(args)
	char *args;
{
	register char *cp, *np;
	int class;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
D 4
err:		fprintf(stderr,
E 4
I 4
err:		init_error(LOG_ERR,
E 4
			"%s: line %d: class declaration: syntax error\n",
			master_conf_filename, lineno);
D 4
		exit(1);
E 4
I 4
		return;
E 4
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
I 2
D 4
	if (debug)
		printf("registering class id %d using file %s\n", class, np);
E 4
I 4
	syslog(LOG_DEBUG, "attempting to register class id %d using file %s",
		class, np);
E 4
E 2
	register_class(class, np);
}

I 5
static void
I 9
handle_compresscp(args)
	char *args;
{
	register char *cp, *np;
	int accum = 0;

	for (cp = args; isspace(*cp); cp++)
		;
D 29
	if (!*cp) {
E 29
I 29
	if (!*cp || *cp == '#') {
E 29
badusage:	init_error(LOG_ERR,
	"%s: line %d: usage: compress-case-preserve {udp|tcp|axfr|no}...\n",
			master_conf_filename, lineno);
		return;
	}
	while (*cp) {
I 29
		if (*cp == '#')
			break;
E 29
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
D 29
			if (accum || *cp)
E 29
I 29
			if (accum || *cp && *cp != '#')
E 29
				goto badusage;
		} else
			goto badusage;
	}
	compress_case_preserve = accum;
}

static void
E 9
handle_ctlsocket(arg)
	char *arg;
{
	register char *cp, *np;

	if (initdone)
		return;
	for (cp = arg; isspace(*cp); cp++)
		;
D 29
	if (*cp) {
E 29
I 29
	if (*cp && *cp != '#') {
E 29
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		*cp = '\0';
	} else
		np = 0;
	setup_control_socket(np);
}

I 6
D 16
static int
parse_boolean_arg(arg, var)
	register char *arg;
	int *var;
{
	if (!strcmp(arg, "true") || !strcmp(arg, "yes") || !strcmp(arg, "on")
	    || !strcmp(arg, "1")) {
		*var = 1;
		return(0);
	} else if (!strcmp(arg, "false") || !strcmp(arg, "no")
		   || !strcmp(arg, "off") || !strcmp(arg, "0")) {
		*var = 0;
		return(0);
	} else
		return(-1);
}

E 16
static void
D 16
handle_echoq(arg)
	char *arg;
{
	register char *cp, *np;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!*cp) {
err:		init_error(LOG_ERR,
		    "%s: line %d: echo-question: boolean argument required\n",
			master_conf_filename, lineno);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	*cp = '\0';
	if (parse_boolean_arg(np, &echo_question) < 0)
		goto err;
}

I 7
static void
I 13
handle_askforns_retries_perserver(arg)
	char *arg;
{
	register char *cp;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		init_error(LOG_ERR,
    "%s: line %d: foreign-NS-retries-perserver: numeric argument required\n",
			master_conf_filename, lineno);
		return;
	}
	askforns_retries_perserver = atoi(cp);
}

static void
handle_askforns_retries_total(arg)
	char *arg;
{
	register char *cp;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		init_error(LOG_ERR,
	"%s: line %d: foreign-NS-retries-total: numeric argument required\n",
			master_conf_filename, lineno);
		return;
	}
	askforns_retries_total = atoi(cp);
}

static void
handle_askforns_timeout(arg)
	char *arg;
{
	register char *cp;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		init_error(LOG_ERR,
		"%s: line %d: foreign-NS-timeout: numeric argument required\n",
			master_conf_filename, lineno);
		return;
	}
	askforns_timeout = atoi(cp);
}

static void
E 13
I 12
handle_maxnest(arg)
	char *arg;
{
	register char *cp;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		init_error(LOG_ERR,
		"%s: line %d: max-nested-queries: numeric argument required\n",
			master_conf_filename, lineno);
		return;
	}
	max_nested_queries = atoi(cp);
}

static void
E 16
E 12
I 10
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
I 20
	if (num <= 0) {
		fprintf(stderr,
		"%s: line %d: outbound-sockets parameter must be >= 1\n",
			master_conf_filename, lineno);
		exit(1);
	}
E 20
	setup_udpout(num);
}

static void
I 22
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
D 23
	addr = inet_addr(np);
	if (addr == INADDR_NONE)
		goto badusage;
E 23
I 23
	if (!strcmp(np, "*"))
		addr = INADDR_ANY;
	else {
		addr = inet_addr(np);
		if (addr == INADDR_NONE)
			goto badusage;
	}
E 23
	while (isspace(*cp))
		cp++;
	if (!isdigit(*cp))
		goto badusage;
	port = atoi(cp);
	setup_tcpserv(addr, port);
}

static void
E 22
I 15
D 16
handle_udpout_debug(arg)
	char *arg;
{
	register char *cp, *np;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!*cp) {
err:		init_error(LOG_ERR,
		    "%s: line %d: udpout-debug: boolean argument required\n",
			master_conf_filename, lineno);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	*cp = '\0';
	if (parse_boolean_arg(np, &udpout_debug) < 0)
		goto err;
}

static void
E 15
I 14
handle_maxrdlength(arg)
	char *arg;
{
	register char *cp;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		init_error(LOG_ERR,
		"%s: line %d: cache-max-rdlength: numeric argument required\n",
			master_conf_filename, lineno);
		return;
	}
	cache_max_rdlength = atoi(cp);
}

static void
handle_ttl_bumpcname(arg)
	char *arg;
{
	register char *cp, *np;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!*cp) {
err:		init_error(LOG_ERR,
		    "%s: line %d: ttl-bump-CNAME: boolean argument required\n",
			master_conf_filename, lineno);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	*cp = '\0';
	if (parse_boolean_arg(np, &ttl_bump_cname) < 0)
		goto err;
}

static void
handle_ttl_bumpns(arg)
	char *arg;
{
	register char *cp, *np;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!*cp) {
err:		init_error(LOG_ERR,
		    "%s: line %d: ttl-bump-NS: boolean argument required\n",
			master_conf_filename, lineno);
		return;
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	*cp = '\0';
	if (parse_boolean_arg(np, &ttl_bump_ns) < 0)
		goto err;
}

static void
handle_ttl_limit(arg)
	char *arg;
{
	register char *cp;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		init_error(LOG_ERR,
		"%s: line %d: ttl-limit: numeric argument required\n",
			master_conf_filename, lineno);
		return;
	}
	ttl_limit = atoi(cp);
}

static void
handle_ttl_sensiblemin(arg)
	char *arg;
{
	register char *cp;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		init_error(LOG_ERR,
		"%s: line %d: ttl-sensible-min: numeric argument required\n",
			master_conf_filename, lineno);
		return;
	}
	ttl_sensible_min = atoi(cp);
}

static void
E 16
E 14
E 10
D 11
handle_udpserv(arg)
	char *arg;
E 11
I 11
handle_udpserv(args)
	char *args;
E 11
{
D 11
	register char *cp;
E 11
I 11
	register char *cp, *np;
	u_long addr;
E 11
	int port;

	if (initdone)
		return;
D 11
	for (cp = arg; isspace(*cp); cp++)
E 11
I 11
	for (cp = args; isspace(*cp); cp++)
E 11
		;
D 11
	if (*cp) {
		if (!isdigit(*cp)) {
			fprintf(stderr, "%s: line %d: usage: udpserv [port]\n",
				master_conf_filename, lineno);
			exit(1);
		}
		port = atoi(cp);
	} else
		port = NAMESERVER_PORT;
	setup_udpserv(port);
E 11
I 11
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
D 23
	addr = inet_addr(np);
	if (addr == INADDR_NONE)
		goto badusage;
E 23
I 23
	if (!strcmp(np, "*"))
		addr = INADDR_ANY;
	else {
		addr = inet_addr(np);
		if (addr == INADDR_NONE)
			goto badusage;
	}
E 23
	while (isspace(*cp))
		cp++;
	if (!isdigit(*cp))
		goto badusage;
	port = atoi(cp);
	setup_udpserv(addr, port);
E 11
}

I 17
static void
handle_uid(arg)
	char *arg;
{
	register char *cp, *np;
	register struct passwd *pwd;

	if (initdone)
		return;
I 18
	if (geteuid()) {
		fprintf(stderr, "%s: line %d: uid line ignored: not root\n",
			master_conf_filename, lineno);
		return;
	}
E 18
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

E 17
I 8
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
D 29
		if (!*cp)
E 29
I 29
		if (!*cp || *cp == '#')
E 29
			return(1);
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		if (!strcmp(np, "rec"))
			entry->acl_perm |= ACL_ALLOW_RECURSE;
		else if (!strcmp(np, "axfr"))
			entry->acl_perm |= ACL_ALLOW_AXFR;
I 22
		else if (!strcmp(np, "idle"))
			entry->acl_perm |= ACL_ALLOW_IDLE;
E 22
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

E 8
E 7
E 6
E 5
D 16
static struct keyword {
	char	*kw;
	void	(*func)();
} keyword_table[] = {
I 14
	{"cache-max-rdlength", handle_maxrdlength},
E 16
I 16
static struct keyword keyword_table[] = {
I 27
	{"AA-queries", handle_gen_bool, (caddr_t) &allow_aa_queries},
E 27
I 19
D 34
	{"NS-glue-answers", handle_gen_bool, (caddr_t) &nsglue_answers},
E 34
I 26
	{"cache-NS-tempfail", handle_gen_num, (caddr_t) &tempfail_cache_dur, 0},
E 26
E 19
D 20
	{"cache-max-rdlength", handle_gen_num, (caddr_t) &cache_max_rdlength},
E 20
I 20
D 34
	{"cache-max-rdlength", handle_gen_num,
		(caddr_t) &cache_max_rdlength, 0},
E 34
I 21
	{"cache-sweep-interval", handle_gen_num,
		(caddr_t) &cache_sweep_interval, 0},
I 25
	{"child-race-timer", handle_gen_num, (caddr_t) &child_race_timer, 1},
E 25
E 21
E 20
E 16
E 14
	{"class", handle_class},
I 9
	{"compress-case-preserve", handle_compresscp},
I 28
	{"compress-new-RR-types", handle_gen_bool,
		(caddr_t) &compress_new_types},
E 28
E 9
I 5
	{"ctlsocket", handle_ctlsocket},
I 6
D 16
	{"echo-question", handle_echoq},
I 13
	{"foreign-NS-retries-perserver", handle_askforns_retries_perserver},
	{"foreign-NS-retries-total", handle_askforns_retries_total},
	{"foreign-NS-timeout", handle_askforns_timeout},
E 16
I 16
	{"echo-question", handle_gen_bool, (caddr_t) &echo_question},
	{"foreign-NS-retries-perserver", handle_gen_num,
D 20
		(caddr_t) &askforns_retries_perserver},
E 20
I 20
		(caddr_t) &askforns_retries_perserver, 1},
E 20
	{"foreign-NS-retries-total", handle_gen_num,
D 20
		(caddr_t) &askforns_retries_total},
	{"foreign-NS-timeout", handle_gen_num, (caddr_t) &askforns_timeout},
E 16
I 14
	{"max-hash-chain", NULL},
E 14
E 13
I 12
D 16
	{"max-nested-queries", handle_maxnest},
E 16
I 16
	{"max-nested-queries", handle_gen_num, (caddr_t) &max_nested_queries},
E 20
I 20
		(caddr_t) &askforns_retries_total, 1},
	{"foreign-NS-timeout", handle_gen_num, (caddr_t) &askforns_timeout, 0},
	{"max-hash-chain", handle_gen_num, (caddr_t) &max_hash_chain, 1},
	{"max-nested-queries", handle_gen_num,
		(caddr_t) &max_nested_queries, 0},
E 20
E 16
I 14
D 24
	{"max-outbound-tcp", NULL},
E 24
I 24
	{"max-outbound-tcp", handle_gen_num, (caddr_t) &tcpqueue_limit, 1},
E 24
I 19
	{"norecurse-cached-answers", handle_gen_bool,
		(caddr_t) &norec_allow_cached_ans},
	{"norecurse-cached-referrals", handle_gen_bool,
		(caddr_t) &norec_allow_cached_ref},
E 19
E 14
E 12
I 10
	{"outbound-sockets", handle_outsockets},
I 24
	{"outbound-tcp-timeout", handle_gen_num,
		(caddr_t) &outbound_tcp_timeout, 1},
E 24
E 10
I 8
	{"tcp-acl", handle_tcp_acl},
D 22
	{"tcpserv", NULL},
I 14
	{"tcpserv-max-conn", NULL},
E 22
I 22
	{"tcpserv", handle_tcpserv},
	{"tcpserv-max-conn", handle_gen_num, (caddr_t) &tcpserv_max_conn, 1},
	{"tcpserv-max-idle", handle_gen_num, (caddr_t) &tcpserv_max_idle, 0},
	{"tcpserv-send-timeout", handle_gen_num,
		(caddr_t) &tcpserv_send_timeout, 0},
E 22
D 16
	{"ttl-bump-CNAME", handle_ttl_bumpcname},
	{"ttl-bump-NS", handle_ttl_bumpns},
	{"ttl-limit", handle_ttl_limit},
	{"ttl-sensible-min", handle_ttl_sensiblemin},
E 16
I 16
D 33
	{"ttl-bump-CNAME", handle_gen_bool, (caddr_t) &ttl_bump_cname},
	{"ttl-bump-NS", handle_gen_bool, (caddr_t) &ttl_bump_ns},
E 33
I 33
	{"ttl-bump-CNAME", handle_gen_num, (caddr_t) &ttl_bump_cname, 0},
	{"ttl-bump-NS", handle_gen_num, (caddr_t) &ttl_bump_ns, 0},
E 33
D 20
	{"ttl-limit", handle_gen_num, (caddr_t) &ttl_limit},
	{"ttl-sensible-min", handle_gen_num, (caddr_t) &ttl_sensible_min},
E 20
I 20
D 27
	{"ttl-limit", handle_gen_num, (caddr_t) &ttl_limit, 0},
E 27
I 27
	{"ttl-limit-data", handle_gen_num, (caddr_t) &ttl_limit_data, 0},
I 33
	{"ttl-limit-neg", handle_gen_num, (caddr_t) &ttl_limit_ncache, 0},
E 33
	{"ttl-limit-NS", handle_gen_num, (caddr_t) &ttl_limit_ns, 0},
D 33
	{"ttl-limit-NSneg", handle_gen_num, (caddr_t) &ttl_limit_nsneg, 0},
E 27
	{"ttl-sensible-min", handle_gen_num, (caddr_t) &ttl_sensible_min, 0},
E 33
I 33
	{"ttl-sensible-min", handle_gen_num, (caddr_t) &ttl_sensible_min, 1},
E 33
E 20
E 16
E 14
	{"udp-acl", handle_udp_acl},
I 15
D 16
	{"udpout-debug", handle_udpout_debug},
E 16
I 16
	{"udpout-debug", handle_gen_bool, (caddr_t) &udpout_debug},
E 16
E 15
E 8
I 7
	{"udpserv", handle_udpserv},
I 14
D 17
	{"uid", NULL},
E 17
I 17
	{"uid", handle_uid},
E 17
E 14
E 7
E 6
E 5
	{NULL, NULL}
};

read_master_config()
{
	FILE *f;
D 3
	char linebuf[256];
E 3
I 3
	char linebuf[FGETS_BUFSIZE];
E 3
	register char *cp, *np;
	register struct keyword *kwp;

I 30
	if (!initdone && !debug && (!getuid() || !geteuid()))
		masterconf_security_check();
E 30
	f = fopen(master_conf_filename, "r");
	if (!f) {
D 4
		perror(master_conf_filename);
		exit(1);
E 4
I 4
		syslog(LOG_CRIT, "fopen %s: %m", master_conf_filename);
		if (!initdone) {
			perror(master_conf_filename);
			exit(1);
		}
		return;
E 4
	}
I 8
	tcpserv_acl_entries = 0;
	udpserv_acl_entries = 0;
E 8
	for (lineno = 1; fgets(linebuf, sizeof linebuf, f); lineno++) {
		for (cp = linebuf; isspace(*cp); cp++)
			;
		if (!*cp || *cp == '#')
			continue;
		if (!isalpha(*cp)) {
D 4
			fprintf(stderr, "%s: line %d: syntax error\n",
E 4
I 4
			init_error(LOG_ERR, "%s: line %d: syntax error\n",
E 4
				master_conf_filename, lineno);
D 4
			exit(1);
E 4
I 4
			continue;
E 4
		}
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		for (kwp = keyword_table; kwp->kw; kwp++)
			if (!strcmp(kwp->kw, np))
				break;
		if (kwp->func)
D 16
			kwp->func(cp);
E 16
I 16
			kwp->func(cp, kwp);
E 16
		else {
D 4
			fprintf(stderr,
E 4
I 4
			init_error(LOG_ERR,
E 4
				"%s: line %d: %s: unrecognized setting\n",
D 16
				master_conf_filename, lineno);
E 16
I 16
				master_conf_filename, lineno, np);
E 16
D 4
			exit(1);
E 4
		}
	}
	fclose(f);
I 8
	bcopy(&acl_default, tcpserv_acl + tcpserv_acl_entries,
		sizeof(struct aclentry));
	bcopy(&acl_default, udpserv_acl + udpserv_acl_entries,
		sizeof(struct aclentry));
I 30
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
E 30
E 8
}
E 1
