/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Control commands dealing with NS-anchor objects
 */

#ifndef lint
static char sccsid[] = "@(#)nsanchorcmd.c	1.3 (IFCTF) 2013/01/06";
#endif

#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include <ctype.h>
#include <strings.h>
#include "defs.h"
#include "class.h"
#include "dname.h"
#include "nsrec.h"
#include "globals.h"

extern u_char *myalloc();
extern struct ns_anchor *find_active_nsanchor();

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
cmd_refresh_nsanchor(args)
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
badusage:	syslog(LOG_ERR, "usage: refresh-NS-anchor class domain-name");
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
			"refresh-NS-anchor: class %d not defined", classnum);
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
	if (a->nsa_val_op) {
		syslog(LOG_ERR, "refresh-NS-anchor: already in progress");
		return;
	}
	if (a->nsa_val_sched) {
		timesched_discard(a->nsa_val_sched);
		a->nsa_val_sched = 0;
	}
	nsanchor_start_refresh(a);
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
	na->nsa_ttl_limit = INT_MAX;
	na->nsa_ttl_percent = NSANCHOR_DEFAULT_TTL_PERCENT;
	na->nsa_retry_interval = NSANCHOR_DEFAULT_RETRY_INTERVAL;
	na->nsa_warn_interval = NSANCHOR_DEFAULT_WARN_INTERVAL;
	/* stick it on the fileread queue! */
	schedule_nsanchor_fileread(na);
}
