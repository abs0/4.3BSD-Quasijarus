h09671
s 00005/00000/00438
d D 1.11 2013/01/14 00:40:11 msokolov 11 10
c class ready-to-serve flag implemented
e
s 00001/00001/00437
d D 1.10 2013/01/06 07:04:00 msokolov 10 9
c MSDNS => FalconDNS
e
s 00001/00001/00437
d D 1.9 2011/12/25 05:53:28 msokolov 9 8
c allow comments on server lines after all IP addresses
e
s 00001/00135/00437
d D 1.8 2011/12/12 22:34:35 msokolov 8 7
c refresh logic hooked in, commands split off to nsanchorcmd.c
e
s 00020/00011/00552
d D 1.7 2011/12/12 22:15:00 msokolov 7 6
c NS-anchor validation code written
e
s 00133/00000/00430
d D 1.6 2011/12/11 07:15:25 msokolov 6 5
c delete-NS-anchor and reload-NS-anchor implemented
e
s 00050/00004/00380
d D 1.5 2011/12/11 06:29:35 msokolov 5 4
c prep for NS-anchor refresh logic
e
s 00001/00001/00383
d D 1.4 2011/10/28 05:59:18 msokolov 4 3
c fix core-dumping buglet
e
s 00163/00005/00221
d D 1.3 2011/10/28 04:27:10 msokolov 3 2
c NS-anchor installation fully implemented
e
s 00118/00000/00108
d D 1.2 2011/09/13 00:31:59 msokolov 2 1
c file reading: parsing implemented, action not yet
e
s 00108/00000/00000
d D 1.1 2011/09/12 06:12:04 msokolov 1 0
c date and time created 2011/09/12 06:12:04 by msokolov
e
u
U
t
T
I 1
/*
D 10
 * Michael Sokolov's Domain Name Server (MSDNS)
E 10
I 10
 * FalconDNS daemon by Michael Spacefalcon
E 10
 *
 * This module handles NS-anchor objects.
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 7
#include <sys/types.h>
E 7
I 7
#include <sys/param.h>
E 7
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include <ctype.h>
I 3
#include <strings.h>
E 3
I 2
#include "defs.h"
E 2
#include "class.h"
#include "dname.h"
#include "tree.h"
#include "nsrec.h"
#include "globals.h"
I 2
#include "selectloop.h"
E 2

extern u_char *myalloc();
extern struct node *alloc_new_node(), *node_findchild();

struct ns_anchor *
find_active_nsanchor(cl, dname)
	struct class *cl;
	register struct dname *dname;
{
	int depth;
	register struct node *n;
	register struct ns_rrset *ns;

	n = cl->c_root;
	depth = dname->dn_nlabels;
	while (n && depth--)
		n = node_findchild(&n->n_nzch, dname->dn_labels[depth], 0);
	if (!n)
		return(0);
	ns = n->n_ns;
	if (!ns)
		return(0);
	if (ns->ns_type == NSTYPE_ANCHOR)
		return((struct ns_anchor *)ns);
	else
		return(0);
}

I 2
void
delete_nsanchor(a)
	register struct ns_anchor *a;
{
	register struct node *n;

	n = a->nsa_node;
	if (n)
		n->n_ns = 0;
I 5
	a->nsa_node = 0;
	if (a->nsa_val_op)
		return;
	if (a->nsa_val_sched)
		timesched_discard(a->nsa_val_sched);
E 5
	free_ns_rrset(a);
}

E 2
D 7
static void
schedule_fileread(new)
E 7
I 7
void
schedule_nsanchor_fileread(new)
E 7
	struct ns_anchor *new;
{
	register struct ns_anchor *p, **pp;

	for (pp = &nsanchor_fileread_queue; p = *pp; pp = &p->nsa_next)
		;
	*pp = new;
I 11
	new->nsa_class->c_outstanding_loads++;
E 11
}

void
nsanchor_add_request(cl, domname, filename)
	struct class *cl;
	char *domname, *filename;
{
	struct dname dname;
	register struct ns_anchor *a;
	int malloclen, dnsize;
	register u_char *dp;

I 5
	if (!num_outbound_udp_sockets) {
		syslog(LOG_ERR,
	"%s: line %d: NS-anchor makes no sense without outbound-sockets",
			cl->c_filename, cl->c_fileread_lineno);
		return;
	}
E 5
	if (parse_ascii_dname(domname, &dname) < 0) {
		syslog(LOG_ERR,
			"%s: line %d: NS-anchor: invalid domain-name %s",
			cl->c_filename, cl->c_fileread_lineno, domname);
		return;
	}
	/* weed out reloads of unchanged existing anchors */
	a = find_active_nsanchor(cl, &dname);
D 4
	if (!strcmp(a->nsa_filename, filename))
E 4
I 4
	if (a && !strcmp(a->nsa_filename, filename))
E 4
		return;
	/* allocate new ns_anchor structure */
	dnsize = dn_spaceneeded(&dname);
	malloclen = sizeof(struct ns_anchor) + dnsize + strlen(domname) +
			strlen(filename) + 1;
	dp = myalloc(malloclen);
	if (!dp) {
		syslog(LOG_CRIT,
			"unable to allocate memory to create NS-anchor %s (%d)",
			domname, cl->c_class);
		return;
	}
	a = (struct ns_anchor *)dp;
	bzero(a, sizeof(struct ns_anchor));
	dp += sizeof(struct ns_anchor);
	dname_copy(&dname, dp);
	a->nsa_dname = (struct dname *)dp;
	dp += dnsize;
	strcpy(dp, domname);
	a->nsa_ascii_domname = (char *)dp;
	dp += strlen(domname) + 1;
	strcpy(dp, filename);
	a->nsa_filename = (char *)dp;
	/* minimal initialization */
	a->nsa_rrset.ns_type = NSTYPE_ANCHOR;
	a->nsa_class = cl;
I 7
	a->nsa_ttl_limit = INT_MAX;
E 7
I 3
	a->nsa_ttl_percent = NSANCHOR_DEFAULT_TTL_PERCENT;
	a->nsa_retry_interval = NSANCHOR_DEFAULT_RETRY_INTERVAL;
I 5
	a->nsa_warn_interval = NSANCHOR_DEFAULT_WARN_INTERVAL;
E 5
E 3
	/* stick it on the fileread queue! */
D 7
	schedule_fileread(a);
E 7
I 7
	schedule_nsanchor_fileread(a);
E 7
I 2
}

static
D 3
process_file_line(a, cp)
E 3
I 3
D 7
act_on_server_line(a, serv, addrs, naddrs)
E 7
I 7
act_on_server_line(a, serv, addrs, naddrs, aserv)
E 7
	register struct ns_anchor *a;
	register struct dname *serv;
	u_long *addrs;
	int naddrs;
I 7
	char *aserv;
E 7
{
	register struct nsrr *ind, **indp;
	register u_char *dp;

	for (indp = &a->nsa_rrset.ns_chain; ind = *indp;
	     indp = &ind->nsrr_next) {
		dp = (u_char *)ind + sizeof(struct nsrr);
D 5
		if (!dname_compare(dp, serv))
E 5
I 5
		if (!dname_compare((struct dname *)dp, serv))
E 5
			continue;
		syslog(LOG_ERR,
			"NS-anchor %s: line %d: same server host listed twice",
			a->nsa_filename, a->nsa_fileread_lineno);
		return(-1);
	}
	/* store new RR */
D 7
	dp = myalloc(sizeof(struct nsrr) + dn_spaceneeded(serv));
E 7
I 7
	dp = myalloc(sizeof(struct nsrr) + dn_spaceneeded(serv) +
			strlen(aserv) + 1);
E 7
	if (!dp) {
		syslog(LOG_CRIT,
			"unable to allocate memory to create NS-anchor %s (%d)",
			a->nsa_ascii_domname, a->nsa_class->c_class);
		return(-1);
	}
	ind = (struct nsrr *)dp;
	bzero(ind, sizeof(struct nsrr));
	dp += sizeof(struct nsrr);
	dname_copy(serv, dp);
I 7
	dp += dn_spaceneeded(serv);
E 7
	bcopy(addrs, ind->nsrr_addrs, naddrs * sizeof(u_long));
	ind->nsrr_addrcnt = naddrs;
I 7
	strcpy(dp, aserv);
	ind->nsrr_ascii = (char *)dp;
E 7
	*indp = ind;
	a->nsa_rrset.ns_count++;
	return(0);
}

static
process_server_line(a, cp)
E 3
	struct ns_anchor *a;
	register char *cp;
{
D 7
	register char *np;
E 7
I 7
	register char *np, *aserv;
E 7
	struct dname dname;
	u_long addrs[NS_MAX_ADDRESSES];
	int addrcnt;

	while (isspace(*cp))
		cp++;
D 3
	if (!*cp || *cp == '#')
		return(0);
E 3
I 3
	if (!*cp) {
		syslog(LOG_ERR,
			"NS-anchor %s: line %d: server line syntax error",
			a->nsa_filename, a->nsa_fileread_lineno);
		return(-1);
	}
E 3
D 7
	for (np = cp; *cp && !isspace(*cp); cp++)
E 7
I 7
	for (aserv = cp; *cp && !isspace(*cp); cp++)
E 7
		;
	if (*cp)
		*cp++ = '\0';
D 7
	if (parse_ascii_dname(np, &dname) < 0) {
E 7
I 7
	if (parse_ascii_dname(aserv, &dname) < 0) {
E 7
		syslog(LOG_ERR,
		    "NS-anchor %s: line %d: invalid name server domain-name",
			a->nsa_filename, a->nsa_fileread_lineno);
		return(-1);
	}
	for (addrcnt = 0; addrcnt < NS_MAX_ADDRESSES; addrcnt++) {
		while (isspace(*cp))
			cp++;
D 9
		if (!*cp)
E 9
I 9
		if (!*cp || *cp == '#')
E 9
			break;
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		addrs[addrcnt] = inet_addr(np);
		if (addrs[addrcnt] == INADDR_NONE) {
ip_expected:		syslog(LOG_ERR,
"NS-anchor %s: line %d: one or more IP addresses expected after domain-name",
				a->nsa_filename, a->nsa_fileread_lineno);
			return(-1);
		}
	}
	if (!addrcnt)
		goto ip_expected;
	/* parsing done, now need to act on what we've got */
D 3
	/* to be implemented */
	return(0);
E 3
I 3
D 7
	return(act_on_server_line(a, &dname, addrs, addrcnt));
E 7
I 7
	return(act_on_server_line(a, &dname, addrs, addrcnt, aserv));
E 7
E 3
}

I 3
static
D 5
process_file_line(a, cp)
E 5
I 5
process_tuning_line(a, kw, arg, var)
E 5
	struct ns_anchor *a;
I 5
	char *kw, *arg;
	int *var;
{
E 5
	register char *cp;
I 5
	register int val;

	for (cp = arg; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
		syslog(LOG_ERR,
		"NS-anchor %s: line %d: numeric argument expected after %s",
			a->nsa_filename, a->nsa_fileread_lineno, kw);
		return(-1);
	}
	val = atoi(cp);
	if (val <= 0) {
		syslog(LOG_ERR,
		"NS-anchor %s: line %d: %s argument must be greater than 0",
			a->nsa_filename, a->nsa_fileread_lineno, kw);
		return(-1);
	}
	*var = val;
	return(0);
}

static
process_file_line(a, cp)
	register struct ns_anchor *a;
	register char *cp;
E 5
{
	register char *np;

	while (isspace(*cp))
		cp++;
	if (!*cp || *cp == '#')
		return(0);
	if (!isalpha(*cp)) {
		syslog(LOG_ERR, "NS-anchor %s: line %d: unable to parse",
			a->nsa_filename, a->nsa_fileread_lineno);
		return(-1);
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if (!strcmp(np, "server"))
		return(process_server_line(a, cp));
I 7
	else if (!strcmp(np, "ttl-limit"))
		return(process_tuning_line(a, np, cp, &a->nsa_ttl_limit));
E 7
I 5
	else if (!strcmp(np, "ttl-percent"))
		return(process_tuning_line(a, np, cp, &a->nsa_ttl_percent));
	else if (!strcmp(np, "retry-interval"))
		return(process_tuning_line(a, np, cp, &a->nsa_retry_interval));
	else if (!strcmp(np, "warn-interval"))
		return(process_tuning_line(a, np, cp, &a->nsa_warn_interval));
E 5
	else {
		syslog(LOG_ERR,
			"NS-anchor %s: line %d: unknown keyword '%s'",
			a->nsa_filename, a->nsa_fileread_lineno, np);
		return(-1);
	}
}

E 3
static void
I 3
install_nsanchor(a)
	register struct ns_anchor *a;
{
	int depth;
	struct class *cl = a->nsa_class;
	register struct node *n, *ch;
	struct node_findaddchild_private_state st;
	static char rootlabel = 0;
	register struct ns_rrset *old;

	n = cl->c_root;
	if (!n) {
		n = alloc_new_node(cl, &rootlabel);
		if (!n) {
nomem:			syslog(LOG_CRIT,
		"unable to allocate memory to install NS-anchor %s (%d)",
				a->nsa_ascii_domname, cl->c_class);
			free_ns_rrset(a);
			return;
		}
		cl->c_root = n;
		n->n_backptr = &cl->c_root;
	}
	depth = a->nsa_dname->dn_nlabels;
	for (;;) {
		if (n->n_zone) {
			syslog(LOG_ERR,
				"NS-anchor %s (%d) conflicts with a zone",
				a->nsa_ascii_domname, cl->c_class);
			free_ns_rrset(a);
			return;
		}
		if (!depth--)
			break;
		ch = node_findchild(&n->n_nzch, a->nsa_dname->dn_labels[depth],
				    &st);
		if (!ch) {
			ch = alloc_new_node(cl, a->nsa_dname->dn_labels[depth]);
			if (!ch)
				goto nomem;
			if (node_addchild(&n->n_nzch, ch, &st) < 0) {
				free(ch);
				goto nomem;
			}
			ch->n_parent = n;
		}
		n = ch;
	}
	/* got the node, install the anchor */
	a->nsa_node = n;
	/*
	 * If the node already has an NS RRset, it must be either
	 * an old anchor or a cached referral.  We replace both.
	 */
	if (old = n->n_ns) {
		switch (old->ns_type) {
		case NSTYPE_ANCHOR:
			delete_nsanchor(old);
			break;
		case NSTYPE_CACHEDREF:
			free_ns_rrset(old);
			break;
		default:
			syslog(LOG_CRIT,
	"BUG in install_nsanchor(): existing NS RRset of unexpected type %d",
				old->ns_type);
			abort();
		}
	}
	n->n_ns = (struct ns_rrset *) a;
D 5
	syslog(LOG_DEBUG, "NS-anchor %s (%d) installed", a->nsa_ascii_domname,
		cl->c_class);
E 5
I 5
	syslog(LOG_INFO, "class %d: installed NS-anchor at %s", cl->c_class,
		a->nsa_ascii_domname);
I 11
	class_ready_check(cl);
E 11
E 5
D 8
	/* refresh logic will go here */
E 8
I 8
	nsanchor_start_refresh(a);
E 8
}

static void
E 3
file_read_handler(a)
	register struct ns_anchor *a;
{
	char linebuf[FGETS_BUFSIZE];
	register FILE *f;

	f = a->nsa_fileread;
	if (!fgets(linebuf, sizeof linebuf, f)) {
		FD_CLR(fileno(f), &select_for_read);
		fclose(f);
		a->nsa_fileread = 0;
		nsanchor_fileread_inprogress = 0;
I 11
		a->nsa_class->c_outstanding_loads--;
E 11
		syslog(LOG_DEBUG,
			"finished reading NS-anchor def file %s: %d lines",
			a->nsa_filename, a->nsa_fileread_lineno);
I 3
		if (!a->nsa_rrset.ns_count) {
			syslog(LOG_ERR, "NS-anchor %s: no servers defined!",
				a->nsa_filename);
			free_ns_rrset(a);
			return;
		}
		install_nsanchor(a);
E 3
		return;
	}
	a->nsa_fileread_lineno++;
	if (process_file_line(a, linebuf) < 0) {
		FD_CLR(fileno(f), &select_for_read);
		fclose(f);
		nsanchor_fileread_inprogress = 0;
I 11
		a->nsa_class->c_outstanding_loads--;
E 11
		free_ns_rrset(a);
		return;
	}
}

nsanchor_fileread_start()
{
	register struct ns_anchor *a;
	register FILE *f;
	register int fd;

	a = nsanchor_fileread_queue;
	nsanchor_fileread_queue = a->nsa_next;
	a->nsa_next = 0;
	f = fopen(a->nsa_filename, "r");
	if (!f) {
		syslog(LOG_ERR, "can't open NS-anchor file %s: %m",
			a->nsa_filename);
I 11
		a->nsa_class->c_outstanding_loads--;
E 11
		free(a);
		return(-1);
	}
	a->nsa_fileread = f;
	a->nsa_fileread_lineno = 0;
	fd = fileno(f);
	select_desc[fd].sel_read = file_read_handler;
	select_desc[fd].sel_opaque = (caddr_t) a;
	FD_SET(fd, &select_for_read);
	if (fd > select_max_fd)
		select_max_fd = fd;
	nsanchor_fileread_inprogress = 1;
	return(0);
E 2
D 8
}
I 6

void
cmd_delete_nsanchor(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2;
	int classnum;
	register struct class *cl;
	struct dname dname;
	register struct ns_anchor *a;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
badusage:	syslog(LOG_ERR, "usage: delete-NS-anchor class domain-name");
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg2 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR,
			"delete-NS-anchor: class %d not defined", classnum);
		return;
	}
	if (parse_ascii_dname(arg2, &dname) < 0)
		goto badusage;
	a = find_active_nsanchor(cl, &dname);
	if (!a) {
		syslog(LOG_ERR, "no active NS-anchor at %s in class %d", arg2,
			classnum);
		return;
	}
	delete_nsanchor(a);
	syslog(LOG_INFO, "class %d: NS-anchor at %s deleted by command",
		classnum, arg2);
}

void
cmd_reload_nsanchor(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2;
	int classnum;
	register struct class *cl;
	struct dname dname;
	register struct ns_anchor *oa, *na;
	int malloclen, dnsize;
	register u_char *dp;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
badusage:	syslog(LOG_ERR, "usage: reload-NS-anchor class domain-name");
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg2 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR,
			"reload-NS-anchor: class %d not defined", classnum);
		return;
	}
	if (parse_ascii_dname(arg2, &dname) < 0)
		goto badusage;
	oa = find_active_nsanchor(cl, &dname);
	if (!oa) {
		syslog(LOG_ERR, "no active NS-anchor at %s in class %d", arg2,
			classnum);
		return;
	}
	/* allocate new ns_anchor structure */
	dnsize = dn_spaceneeded(oa->nsa_dname);
	malloclen = sizeof(struct ns_anchor) + dnsize +
			strlen(oa->nsa_ascii_domname) +
			strlen(oa->nsa_filename) + 1;
	dp = myalloc(malloclen);
	if (!dp) {
		syslog(LOG_ERR,
	"reload-NS-anchor: unable to allocate memory for new structure");
		return;
	}
	na = (struct ns_anchor *)dp;
	bzero(na, sizeof(struct ns_anchor));
	dp += sizeof(struct ns_anchor);
	dname_copy(oa->nsa_dname, dp);
	na->nsa_dname = (struct dname *)dp;
	dp += dnsize;
	strcpy(dp, oa->nsa_ascii_domname);
	na->nsa_ascii_domname = (char *)dp;
	dp += strlen(oa->nsa_ascii_domname) + 1;
	strcpy(dp, oa->nsa_filename);
	na->nsa_filename = (char *)dp;
	/* minimal initialization */
	na->nsa_rrset.ns_type = NSTYPE_ANCHOR;
	na->nsa_class = cl;
I 7
	na->nsa_ttl_limit = INT_MAX;
E 7
	na->nsa_ttl_percent = NSANCHOR_DEFAULT_TTL_PERCENT;
	na->nsa_retry_interval = NSANCHOR_DEFAULT_RETRY_INTERVAL;
	na->nsa_warn_interval = NSANCHOR_DEFAULT_WARN_INTERVAL;
	/* stick it on the fileread queue! */
D 7
	schedule_fileread(na);
E 7
I 7
	schedule_nsanchor_fileread(na);
E 8
E 7
}
E 6
E 1
