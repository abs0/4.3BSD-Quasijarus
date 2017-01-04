h36355
s 00000/00027/00155
d D 1.17 2013/08/10 07:11:39 msokolov 17 16
c external queries bypass the queue
e
s 00006/00000/00176
d D 1.16 2013/01/13 15:31:42 msokolov 16 15
c duplicate query suppression implemented
e
s 00004/00000/00172
d D 1.15 2013/01/07 20:17:02 msokolov 15 14
c tcpserv revamped for multiple simultaneous queries on one connection
e
s 00001/00001/00171
d D 1.14 2013/01/06 07:03:41 msokolov 14 13
c MSDNS => FalconDNS
e
s 00007/00000/00165
d D 1.13 2011/12/17 08:24:38 msokolov 13 12
c workaround for the child exit race condition
e
s 00005/00001/00160
d D 1.12 2011/12/17 08:09:38 msokolov 12 11
c child reaping tied in, still has a possible race condition
e
s 00002/00002/00159
d D 1.11 2011/12/17 06:37:58 msokolov 11 10
c tcpqueue revamped
e
s 00004/00001/00157
d D 1.10 2011/12/14 22:48:24 msokolov 10 9
c tcpqueue tied in
e
s 00003/00001/00155
d D 1.9 2011/12/11 04:44:11 msokolov 9 8
c cache sweep tied in
e
s 00010/00007/00146
d D 1.8 2011/11/02 01:25:59 msokolov 8 7
c more careful handling of serialized activities
e
s 00029/00001/00124
d D 1.7 2011/10/30 20:13:26 msokolov 7 6
c query queue dispatch
e
s 00002/00000/00123
d D 1.6 2011/10/28 04:45:56 msokolov 6 5
c NS-anchor fileread hooked in
e
s 00048/00001/00075
d D 1.5 2011/07/18 05:15:50 msokolov 5 4
c timesched mechanism implemented
e
s 00002/00000/00074
d D 1.4 2011/07/16 01:20:54 msokolov 4 3
c zone_fileread_find() hooked in
e
s 00001/00000/00073
d D 1.3 2011/07/15 19:21:34 msokolov 3 2
c current_time added
e
s 00002/00000/00071
d D 1.2 2011/07/13 19:23:20 msokolov 2 1
c we now read the class def file, although don't do anything with it yet
e
s 00071/00000/00000
d D 1.1 11/07/11 08:04:07 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
D 14
 * Michael Sokolov's Domain Name Server (MSDNS)
E 14
I 14
 * FalconDNS daemon by Michael Spacefalcon
E 14
 *
 * The big daddy: the main select loop
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 5
#include <sys/time.h>
E 5
#include <sys/errno.h>
I 7
#include <netinet/in.h>
E 7
#include <stdio.h>
#include <syslog.h>
#include "globals.h"
#include "selectloop.h"
I 7
#include "query.h"
E 7

extern char *malloc();
extern int errno;

I 7
extern struct query *take_query_from_queue();

E 7
init_selectloop_array()
{
	int nfds, array_size;
	struct selectloop_desc *array;

	nfds = getdtablesize();
	array_size = sizeof(struct selectloop_desc) * nfds;
	array = (struct selectloop_desc *)malloc(array_size);
	if (!array) {
		perror("msdns: malloc failure initializing the select array");
		exit(1);
	}
	select_desc = array;
}

select_loop()
{
	fd_set rfds, wfds, xfds;
	register int nready, i;
	register struct selectloop_desc *desc;
I 5
	register struct timesched *tim;
	struct timeval tv;
E 5

	for (;;) {
I 5
		time(&current_time);
E 5
I 2
D 8
		if (classes_needing_fileread && !class_fileread_inprogress)
			class_fileread_find();
I 4
		if (zones_needing_fileread && !zone_fileread_inprogress)
			zone_fileread_find();
I 6
		if (nsanchor_fileread_queue && !nsanchor_fileread_inprogress)
			nsanchor_fileread_start();
E 8
E 6
I 5
		while (tim = timesched_head) {
			if (tim->tim_time > current_time)
				break;
			timesched_head = tim->tim_next;
			if (timesched_head)
				timesched_head->tim_backptr = &timesched_head;
			tim->tim_func(tim->tim_arg);
			free(tim);
		}
E 5
E 4
E 2
		bcopy(&select_for_read, &rfds, sizeof(fd_set));
		bcopy(&select_for_write, &wfds, sizeof(fd_set));
		bcopy(&select_for_except, &xfds, sizeof(fd_set));
D 5
		nready = select(select_max_fd + 1, &rfds, &wfds, &xfds, NULL);
E 5
I 5
D 7
		if (tim) {
E 7
I 7
D 8
		if (queryqueue_head) {
E 8
I 8
D 9
		if (queryqueue_head ||
E 9
I 9
D 12
		if (queryqueue_head || cache_sweep_ptr ||
E 12
I 12
		if (queryqueue_head || cache_sweep_ptr || sigchild_flag ||
E 12
E 9
		    classes_needing_fileread && !class_fileread_inprogress ||
		    zones_needing_fileread && !zone_fileread_inprogress ||
D 10
		    nsanchor_fileread_queue && !nsanchor_fileread_inprogress) {
E 10
I 10
		    nsanchor_fileread_queue && !nsanchor_fileread_inprogress ||
D 11
		    tcpqueue_head && tcpqueue_outstanding < tcpqueue_limit) {
E 11
I 11
		    tcpqueue_waitq && tcpqueue_outstanding < tcpqueue_limit) {
E 11
E 10
E 8
			tv.tv_sec = 0;
			tv.tv_usec = 0;
			nready = select(select_max_fd + 1, &rfds, &wfds, &xfds,
					&tv);
		} else if (tim) {
E 7
			tv.tv_sec = tim->tim_time - current_time;
I 13
			if (zonexfer_children && tv.tv_sec > child_race_timer)
				tv.tv_sec = child_race_timer;
			tv.tv_usec = 0;
			nready = select(select_max_fd + 1, &rfds, &wfds, &xfds,
					&tv);
		} else if (zonexfer_children) {
			tv.tv_sec = child_race_timer;
E 13
			tv.tv_usec = 0;
			nready = select(select_max_fd + 1, &rfds, &wfds, &xfds,
					&tv);
		} else
			nready = select(select_max_fd + 1, &rfds, &wfds, &xfds,
					NULL);
E 5
		if (nready < 0) {
			if (errno == EINTR)
				continue;
			syslog(LOG_CRIT, "select error: %m");
			exit(1);
		}
I 3
		time(&current_time);
E 3
		desc = select_desc;
		for (i = 0; i <= select_max_fd; i++, desc++) {
			if (FD_ISSET(i, &rfds)) {
				desc->sel_read(desc->sel_opaque);
				nready--;
			}
			if (FD_ISSET(i, &wfds)) {
				desc->sel_write(desc->sel_opaque);
				nready--;
			}
			if (FD_ISSET(i, &xfds)) {
				desc->sel_except(desc->sel_opaque);
				nready--;
			}
			if (nready <= 0)
				break;
		}
I 7
		if (queryqueue_head)
			query_queue_dispatch(take_query_from_queue());
I 9
		if (cache_sweep_ptr)
			cache_sweep_process();
E 9
I 8
		if (classes_needing_fileread && !class_fileread_inprogress)
			class_fileread_find();
		if (zones_needing_fileread && !zone_fileread_inprogress)
			zone_fileread_find();
		if (nsanchor_fileread_queue && !nsanchor_fileread_inprogress)
			nsanchor_fileread_start();
I 10
D 11
		if (tcpqueue_head && tcpqueue_outstanding < tcpqueue_limit)
E 11
I 11
		if (tcpqueue_waitq && tcpqueue_outstanding < tcpqueue_limit)
E 11
			tcpqueue_start_connect();
I 12
		if (sigchild_flag) {
			sigchild_flag = 0;
			zonexfer_child_reaper();
		}
E 12
E 10
E 8
E 7
	}
I 5
}

time_schedule(newt)
	register struct timesched *newt;
{
	register struct timesched *t, **pp;

	for (pp = &timesched_head; t = *pp; pp = &t->tim_next)
		if (t->tim_time >= newt->tim_time)
			break;
	newt->tim_next = t;
	if (t)
		t->tim_backptr = &newt->tim_next;
	*pp = newt;
	newt->tim_backptr = pp;
}

timesched_discard(t)
	register struct timesched *t;
{
	register struct timesched *next;

	next = t->tim_next;
	if (next)
		next->tim_backptr = t->tim_backptr;
	*t->tim_backptr = next;
	free(t);
I 7
}
D 17

query_queue_dispatch(q)
	register struct query *q;
{
	switch (q->q_state) {
	case QSTATE_STAGE:
		query_stage_process(q);
		return;
	case QSTATE_COMPLETE:
I 15
		if (!(q->q_flags & QFLAGS_INTERNAL)) {
			query_response_wrapup(q);
			q->q_state = QSTATE_RSPOUT;
I 16
			if (q->q_dupcatch_backptr) {
				*q->q_dupcatch_backptr = q->q_dupcatch_next;
				if (q->q_dupcatch_next)
					q->q_dupcatch_next->q_dupcatch_backptr =
						q->q_dupcatch_backptr;
			}
E 16
		}
E 15
		q->q_callwhendone(q);
		return;
	default:
		syslog(LOG_CRIT, "BUG: bad state %d in query_queue_dispatch()",
			q->q_state);
		abort();
	}
E 7
E 5
}
E 17
E 1
