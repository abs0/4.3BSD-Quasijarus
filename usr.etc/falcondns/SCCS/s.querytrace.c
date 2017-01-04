h16199
s 00001/00000/00113
d D 1.3 2011/12/18 00:29:21 msokolov 3 2
c line-buffered trace files
e
s 00034/00002/00079
d D 1.2 2011/11/02 06:55:12 msokolov 2 1
c query trace adapted for nested queries
e
s 00081/00000/00000
d D 1.1 2011/10/30 02:23:26 msokolov 1 0
c date and time created 2011/10/30 02:23:26 by msokolov
e
u
U
t
T
I 1
/*
 * MSDNS debug feature: query trace
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
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

I 2
extern char *malloc();

E 2
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
I 3
	setlinebuf(trace_file);
E 3
}

void
query_trace_init(q)
	register struct query *q;
{
D 2
	register HEADER *hdr;
E 2
I 2
	HEADER *hdr;
	register struct querytrace *qt;
E 2

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
I 2
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
E 2
	} else
		q->q_trace = NULL;
D 2
	q->q_trace_index = 0;
E 2
I 2
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
E 2
}
E 1
