/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * The big daddy: the main select loop
 */

#ifndef lint
static char sccsid[] = "@(#)selectloop.c	1.17 (IFCTF) 2013/08/10";
#endif

#include <sys/types.h>
#include <sys/time.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <syslog.h>
#include "globals.h"
#include "selectloop.h"
#include "query.h"

extern char *malloc();
extern int errno;

extern struct query *take_query_from_queue();

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
	register struct timesched *tim;
	struct timeval tv;

	for (;;) {
		time(&current_time);
		while (tim = timesched_head) {
			if (tim->tim_time > current_time)
				break;
			timesched_head = tim->tim_next;
			if (timesched_head)
				timesched_head->tim_backptr = &timesched_head;
			tim->tim_func(tim->tim_arg);
			free(tim);
		}
		bcopy(&select_for_read, &rfds, sizeof(fd_set));
		bcopy(&select_for_write, &wfds, sizeof(fd_set));
		bcopy(&select_for_except, &xfds, sizeof(fd_set));
		if (queryqueue_head || cache_sweep_ptr || sigchild_flag ||
		    classes_needing_fileread && !class_fileread_inprogress ||
		    zones_needing_fileread && !zone_fileread_inprogress ||
		    nsanchor_fileread_queue && !nsanchor_fileread_inprogress ||
		    tcpqueue_waitq && tcpqueue_outstanding < tcpqueue_limit) {
			tv.tv_sec = 0;
			tv.tv_usec = 0;
			nready = select(select_max_fd + 1, &rfds, &wfds, &xfds,
					&tv);
		} else if (tim) {
			tv.tv_sec = tim->tim_time - current_time;
			if (zonexfer_children && tv.tv_sec > child_race_timer)
				tv.tv_sec = child_race_timer;
			tv.tv_usec = 0;
			nready = select(select_max_fd + 1, &rfds, &wfds, &xfds,
					&tv);
		} else if (zonexfer_children) {
			tv.tv_sec = child_race_timer;
			tv.tv_usec = 0;
			nready = select(select_max_fd + 1, &rfds, &wfds, &xfds,
					&tv);
		} else
			nready = select(select_max_fd + 1, &rfds, &wfds, &xfds,
					NULL);
		if (nready < 0) {
			if (errno == EINTR)
				continue;
			syslog(LOG_CRIT, "select error: %m");
			exit(1);
		}
		time(&current_time);
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
		if (queryqueue_head)
			query_queue_dispatch(take_query_from_queue());
		if (cache_sweep_ptr)
			cache_sweep_process();
		if (classes_needing_fileread && !class_fileread_inprogress)
			class_fileread_find();
		if (zones_needing_fileread && !zone_fileread_inprogress)
			zone_fileread_find();
		if (nsanchor_fileread_queue && !nsanchor_fileread_inprogress)
			nsanchor_fileread_start();
		if (tcpqueue_waitq && tcpqueue_outstanding < tcpqueue_limit)
			tcpqueue_start_connect();
		if (sigchild_flag) {
			sigchild_flag = 0;
			zonexfer_child_reaper();
		}
	}
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
}
