/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * This module handles NS-anchor objects.
 */

#ifndef lint
static char sccsid[] = "@(#)nsanchor.c	1.11 (IFCTF) 2013/01/14";
#endif

#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include <ctype.h>
#include <strings.h>
#include "defs.h"
#include "class.h"
#include "dname.h"
#include "tree.h"
#include "nsrec.h"
#include "globals.h"
#include "selectloop.h"

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

void
delete_nsanchor(a)
	register struct ns_anchor *a;
{
	register struct node *n;

	n = a->nsa_node;
	if (n)
		n->n_ns = 0;
	a->nsa_node = 0;
	if (a->nsa_val_op)
		return;
	if (a->nsa_val_sched)
		timesched_discard(a->nsa_val_sched);
	free_ns_rrset(a);
}

void
schedule_nsanchor_fileread(new)
	struct ns_anchor *new;
{
	register struct ns_anchor *p, **pp;

	for (pp = &nsanchor_fileread_queue; p = *pp; pp = &p->nsa_next)
		;
	*pp = new;
	new->nsa_class->c_outstanding_loads++;
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

	if (!num_outbound_udp_sockets) {
		syslog(LOG_ERR,
	"%s: line %d: NS-anchor makes no sense without outbound-sockets",
			cl->c_filename, cl->c_fileread_lineno);
		return;
	}
	if (parse_ascii_dname(domname, &dname) < 0) {
		syslog(LOG_ERR,
			"%s: line %d: NS-anchor: invalid domain-name %s",
			cl->c_filename, cl->c_fileread_lineno, domname);
		return;
	}
	/* weed out reloads of unchanged existing anchors */
	a = find_active_nsanchor(cl, &dname);
	if (a && !strcmp(a->nsa_filename, filename))
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
	a->nsa_ttl_limit = INT_MAX;
	a->nsa_ttl_percent = NSANCHOR_DEFAULT_TTL_PERCENT;
	a->nsa_retry_interval = NSANCHOR_DEFAULT_RETRY_INTERVAL;
	a->nsa_warn_interval = NSANCHOR_DEFAULT_WARN_INTERVAL;
	/* stick it on the fileread queue! */
	schedule_nsanchor_fileread(a);
}

static
act_on_server_line(a, serv, addrs, naddrs, aserv)
	register struct ns_anchor *a;
	register struct dname *serv;
	u_long *addrs;
	int naddrs;
	char *aserv;
{
	register struct nsrr *ind, **indp;
	register u_char *dp;

	for (indp = &a->nsa_rrset.ns_chain; ind = *indp;
	     indp = &ind->nsrr_next) {
		dp = (u_char *)ind + sizeof(struct nsrr);
		if (!dname_compare((struct dname *)dp, serv))
			continue;
		syslog(LOG_ERR,
			"NS-anchor %s: line %d: same server host listed twice",
			a->nsa_filename, a->nsa_fileread_lineno);
		return(-1);
	}
	/* store new RR */
	dp = myalloc(sizeof(struct nsrr) + dn_spaceneeded(serv) +
			strlen(aserv) + 1);
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
	dp += dn_spaceneeded(serv);
	bcopy(addrs, ind->nsrr_addrs, naddrs * sizeof(u_long));
	ind->nsrr_addrcnt = naddrs;
	strcpy(dp, aserv);
	ind->nsrr_ascii = (char *)dp;
	*indp = ind;
	a->nsa_rrset.ns_count++;
	return(0);
}

static
process_server_line(a, cp)
	struct ns_anchor *a;
	register char *cp;
{
	register char *np, *aserv;
	struct dname dname;
	u_long addrs[NS_MAX_ADDRESSES];
	int addrcnt;

	while (isspace(*cp))
		cp++;
	if (!*cp) {
		syslog(LOG_ERR,
			"NS-anchor %s: line %d: server line syntax error",
			a->nsa_filename, a->nsa_fileread_lineno);
		return(-1);
	}
	for (aserv = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if (parse_ascii_dname(aserv, &dname) < 0) {
		syslog(LOG_ERR,
		    "NS-anchor %s: line %d: invalid name server domain-name",
			a->nsa_filename, a->nsa_fileread_lineno);
		return(-1);
	}
	for (addrcnt = 0; addrcnt < NS_MAX_ADDRESSES; addrcnt++) {
		while (isspace(*cp))
			cp++;
		if (!*cp || *cp == '#')
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
	return(act_on_server_line(a, &dname, addrs, addrcnt, aserv));
}

static
process_tuning_line(a, kw, arg, var)
	struct ns_anchor *a;
	char *kw, *arg;
	int *var;
{
	register char *cp;
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
	else if (!strcmp(np, "ttl-limit"))
		return(process_tuning_line(a, np, cp, &a->nsa_ttl_limit));
	else if (!strcmp(np, "ttl-percent"))
		return(process_tuning_line(a, np, cp, &a->nsa_ttl_percent));
	else if (!strcmp(np, "retry-interval"))
		return(process_tuning_line(a, np, cp, &a->nsa_retry_interval));
	else if (!strcmp(np, "warn-interval"))
		return(process_tuning_line(a, np, cp, &a->nsa_warn_interval));
	else {
		syslog(LOG_ERR,
			"NS-anchor %s: line %d: unknown keyword '%s'",
			a->nsa_filename, a->nsa_fileread_lineno, np);
		return(-1);
	}
}

static void
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
	syslog(LOG_INFO, "class %d: installed NS-anchor at %s", cl->c_class,
		a->nsa_ascii_domname);
	class_ready_check(cl);
	nsanchor_start_refresh(a);
}

static void
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
		a->nsa_class->c_outstanding_loads--;
		syslog(LOG_DEBUG,
			"finished reading NS-anchor def file %s: %d lines",
			a->nsa_filename, a->nsa_fileread_lineno);
		if (!a->nsa_rrset.ns_count) {
			syslog(LOG_ERR, "NS-anchor %s: no servers defined!",
				a->nsa_filename);
			free_ns_rrset(a);
			return;
		}
		install_nsanchor(a);
		return;
	}
	a->nsa_fileread_lineno++;
	if (process_file_line(a, linebuf) < 0) {
		FD_CLR(fileno(f), &select_for_read);
		fclose(f);
		nsanchor_fileread_inprogress = 0;
		a->nsa_class->c_outstanding_loads--;
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
		a->nsa_class->c_outstanding_loads--;
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
}
