/*
 * MSDNS debug feature: query trace
 */

#ifndef lint
static char sccsid[] = "@(#)querytrace.c	1.3 (IFCTF) 2011/12/18";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <syslog.h>
#include "class.h"
#include "dname.h"
#include "query.h"

extern char *malloc();

static struct dname trace_qname;
static FILE *trace_file;

void
cmd_trace_query(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2;

	/* cancel any previous pending trace first */
	if (trace_file) {
		fclose(trace_file);
		trace_file = NULL;
	}
	for (cp = args; isspace(*cp); cp++)
		;
	if (!*cp)
		return;
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp) {
		if (!strcmp(arg1, "off"))
			return;
badusage:	syslog(LOG_ERR, "usage: trace qname dumpfile");
		return;
	}
	for (arg2 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if (parse_ascii_dname(arg1, &trace_qname) < 0)
		goto badusage;
	trace_file = fopen(arg2, "w");
	if (!trace_file)
		syslog(LOG_ERR, "trace: %s: %m", arg2);
	setlinebuf(trace_file);
}

void
query_trace_init(q)
	register struct query *q;
{
	HEADER *hdr;
	register struct querytrace *qt;

	if (trace_file &&
	    dname_compare(&q->q_stages[0].qs_qname, &trace_qname)) {
		hdr = (HEADER *)q->q_msg;
		fputs("QNAME=", trace_file);
		print_dname(&q->q_stages[0].qs_qname, trace_file);
		fprintf(trace_file, "\nQCLASS=%d QTYPE=%d RD=%d RA=%d\n",
			q->q_class->c_class, q->q_type, hdr->rd, hdr->ra);
		fprintf(trace_file, "q_flags=%04x\n", q->q_flags);
		q->q_trace = trace_file;
		trace_file = NULL;
		qt = (struct querytrace *) malloc(sizeof(struct querytrace));
		if (!qt) {
			fputs("trace structure malloc failed!\n", q->q_trace);
			fclose(q->q_trace);
			q->q_trace = NULL;
			return;
		}
		q->q_trace_mgmt = qt;
		qt->qt_file = q->q_trace;
		qt->qt_refcount = 1;
		qt->qt_linearcount = 0;
		q->q_trace_index = 0;
	} else
		q->q_trace = NULL;
}

void
query_trace_free(q)
	struct query *q;
{
	register struct querytrace *qt;

	qt = q->q_trace_mgmt;
	if (--qt->qt_refcount > 0)
		return;
	if (qt->qt_refcount < 0) {
		syslog(LOG_CRIT, "BUG: qt_refcount decremented past zero");
		abort();
	}
	fputs("-- end of trace --\n", qt->qt_file);
	fclose(qt->qt_file);
	free(qt);
}
