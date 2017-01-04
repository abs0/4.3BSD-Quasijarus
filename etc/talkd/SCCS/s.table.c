h20029
s 00010/00005/00205
d D 5.5 88/06/18 14:10:44 bostic 8 7
c install approved copyright notice
e
s 00009/00003/00201
d D 5.4 88/05/20 11:53:32 bostic 7 6
c add Berkeley specific header
e
s 00001/00000/00203
d D 5.3 87/09/04 17:07:12 mckusick 6 5
c need <sys/param.h> to get hton funcs (4.3BSD/etc/88)
e
s 00030/00043/00173
d D 5.2 86/03/13 17:13:15 mckusick 5 4
c new version from sam@monet.berkeley.edu
e
s 00007/00001/00209
d D 5.1 85/06/06 09:19:46 dist 4 3
c Add copyright
e
s 00014/00008/00196
d D 1.3 84/05/11 14:19:26 layer 3 2
c use debugout as the FILE * to print debug msgs
e
s 00153/00174/00051
d D 1.2 84/04/11 15:14:56 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00225/00000/00000
d D 1.1 84/04/11 15:03:10 karels 1 0
c date and time created 84/04/11 15:03:10 by karels
e
u
U
t
T
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 8
E 7
 */

E 4
I 1
D 2
/* $Header: /a/guest/moore/talk/RCS/table.c,v 1.9 83/07/06 00:11:38 moore Exp $ */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif
E 4
I 4
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 4
E 2

D 2
/* routines to handle insertion, deletion, etc on the table
   of requests kept by the daemon. Nothing fancy here, linear
   search on a double-linked list. A time is kept with each 
   entry so that overly old invitations can be eliminated.

   Consider this a mis-guided attempt at modularity
E 2
I 2
/*
 * Routines to handle insertion, deletion, etc on the table
 * of requests kept by the daemon. Nothing fancy here, linear
 * search on a double-linked list. A time is kept with each 
 * entry so that overly old invitations can be eliminated.
 *
 * Consider this a mis-guided attempt at modularity
E 2
 */
I 2
#include <stdio.h>
#include <sys/time.h>
I 5
#include <syslog.h>
I 6
#include <sys/param.h>
E 6
E 5
E 2

D 5
#include "ctl.h"
E 5
I 5
#include <protocols/talkd.h>
E 5
D 2
#include <sys/time.h>
E 2

D 2
#define MAX_ID 16000 /* << 2^15 so I don't have sign troubles */
E 2
I 2
#define MAX_ID 16000	/* << 2^15 so I don't have sign troubles */
E 2

D 2
#define NIL ( (TABLE_ENTRY *) 0)
E 2
I 2
#define NIL ((TABLE_ENTRY *)0)
E 2

D 2
extern int debug;
struct timeval tp;
struct timezone *txp;
E 2
I 2
extern	int debug;
struct	timeval tp;
struct	timezone *txp;
E 2

typedef struct table_entry TABLE_ENTRY;

struct table_entry {
D 2
    CTL_MSG request;
    long time;
    TABLE_ENTRY *next;
    TABLE_ENTRY *last;
E 2
I 2
	CTL_MSG request;
	long	time;
	TABLE_ENTRY *next;
	TABLE_ENTRY *last;
E 2
};

D 2
TABLE_ENTRY *table = NIL;
E 2
I 2
D 5
TABLE_ENTRY	*table = NIL;
E 5
I 5
TABLE_ENTRY *table = NIL;
E 5
E 2
CTL_MSG *find_request();
CTL_MSG *find_match();
D 2
char *malloc();
E 2
I 2
char	*malloc();
E 2

D 2
    /*
     * Look in the table for an invitation that matches the current
     * request looking for an invitation
     */

CTL_MSG *find_match(request)
CTL_MSG *request;
E 2
I 2
/*
 * Look in the table for an invitation that matches the current
 * request looking for an invitation
 */
CTL_MSG *
find_match(request)
D 5
	CTL_MSG *request;
E 5
I 5
	register CTL_MSG *request;
E 5
E 2
{
D 2
    TABLE_ENTRY *ptr;
    long current_time;
E 2
I 2
D 5
	TABLE_ENTRY *ptr;
I 3
	extern FILE *debugout;
E 5
I 5
	register TABLE_ENTRY *ptr;
E 5
E 3
	long current_time;
E 2

D 2
    gettimeofday(&tp, &txp);
    current_time = tp.tv_sec;

    ptr = table;

    if (debug) {
	printf("Entering Look-Up with : \n");
	print_request(request);
    }

    while (ptr != NIL) {

	if ( (ptr->time - current_time) > MAX_LIFE ) {
		/* the entry is too old */
	    if (debug) printf("Deleting expired entry : \n");
	    if (debug) print_request(&ptr->request);
	    delete(ptr);
	    ptr = ptr->next;
	    continue;
E 2
I 2
	gettimeofday(&tp, &txp);
	current_time = tp.tv_sec;
D 5
	if (debug) {
D 3
		printf("Entering Look-Up with : \n");
E 3
I 3
		fprintf(debugout, "Entering Look-Up with : \n");
E 3
		print_request(request);
E 2
	}
E 5
I 5
	if (debug)
		print_request("find_match", request);
E 5
D 2

	if (debug) print_request(&ptr->request);

	if ( strcmp(request->l_name, ptr->request.r_name) == 0 &&
	     strcmp(request->r_name, ptr->request.l_name) == 0 &&
	     ptr->request.type == LEAVE_INVITE ) {
	    return(&ptr->request);
E 2
I 2
	for (ptr = table; ptr != NIL; ptr = ptr->next) {
		if ((ptr->time - current_time) > MAX_LIFE) {
			/* the entry is too old */
D 3
			if (debug)
				printf("Deleting expired entry : \n");
			if (debug)
E 3
I 3
D 5
			if (debug) {
				fprintf(debugout
					,"Deleting expired entry : \n");
E 3
				print_request(&ptr->request);
I 3
			}
E 5
I 5
			if (debug)
				print_request("deleting expired entry",
				    &ptr->request);
E 5
E 3
			delete(ptr);
			continue;
		}
		if (debug)
D 5
			print_request(&ptr->request);
E 5
I 5
			print_request("", &ptr->request);
E 5
		if (strcmp(request->l_name, ptr->request.r_name) == 0 &&
		    strcmp(request->r_name, ptr->request.l_name) == 0 &&
		     ptr->request.type == LEAVE_INVITE)
			return (&ptr->request);
E 2
	}
D 2
	
	ptr = ptr->next;
    }
    
    return((CTL_MSG *) 0);
E 2
I 2
	return ((CTL_MSG *)0);
E 2
}

D 2
    /*
     * look for an identical request, as opposed to a complimentary
     * one as find_match does 
     */

CTL_MSG *find_request(request)
CTL_MSG *request;
E 2
I 2
/*
 * Look for an identical request, as opposed to a complimentary
 * one as find_match does 
 */
CTL_MSG *
find_request(request)
D 5
	CTL_MSG *request;
E 5
I 5
	register CTL_MSG *request;
E 5
E 2
{
D 2
    TABLE_ENTRY *ptr;
    long current_time;
E 2
I 2
D 5
	TABLE_ENTRY *ptr;
I 3
	extern FILE *debugout;
E 5
I 5
	register TABLE_ENTRY *ptr;
E 5
E 3
	long current_time;
E 2

D 2
    gettimeofday(&tp, &txp);
    current_time = tp.tv_sec;

	/* See if this is a repeated message, and check for
	   out of date entries in the table while we are it.
E 2
I 2
	gettimeofday(&tp, &txp);
	current_time = tp.tv_sec;
	/*
	 * See if this is a repeated message, and check for
	 * out of date entries in the table while we are it.
E 2
	 */
D 2

    ptr = table;

    if (debug) {
	printf("Entering find_request with : \n");
	print_request(request);
    }

    while (ptr != NIL) {

	if ( (ptr->time - current_time) > MAX_LIFE ) {
		/* the entry is too old */
	    if (debug) printf("Deleting expired entry : \n");
	    if (debug) print_request(&ptr->request);
	    delete(ptr);
	    ptr = ptr->next;
	    continue;
E 2
I 2
D 5
	if (debug) {
D 3
		printf("Entering find_request with : \n");
E 3
I 3
		fprintf(debugout, "Entering find_request with : \n");
E 3
		print_request(request);
E 2
	}
E 5
I 5
	if (debug)
		print_request("find_request", request);
E 5
D 2

	if (debug) print_request(&ptr->request);

	if ( strcmp(request->r_name, ptr->request.r_name) == 0 &&
	     strcmp(request->l_name, ptr->request.l_name) == 0 &&
	     request->type == ptr->request.type &&
	     request->pid == ptr->request.pid) {
	    
		/* update the time if we 'touch' it */
	    ptr->time = current_time;
	    return(&ptr->request);
E 2
I 2
	for (ptr = table; ptr != NIL; ptr = ptr->next) {
		if ((ptr->time - current_time) > MAX_LIFE) {
			/* the entry is too old */
D 5
			if (debug) {
D 3
				printf("Deleting expired entry : \n");
E 3
I 3
				fprintf(debugout
					, "Deleting expired entry : \n");
E 3
				print_request(&ptr->request);
			}
E 5
I 5
			if (debug)
				print_request("deleting expired entry",
				    &ptr->request);
E 5
			delete(ptr);
			continue;
		}
		if (debug)
D 5
			print_request(&ptr->request);
E 5
I 5
			print_request("", &ptr->request);
E 5
		if (strcmp(request->r_name, ptr->request.r_name) == 0 &&
		    strcmp(request->l_name, ptr->request.l_name) == 0 &&
		    request->type == ptr->request.type &&
		    request->pid == ptr->request.pid) {
			/* update the time if we 'touch' it */
			ptr->time = current_time;
			return (&ptr->request);
		}
E 2
	}
D 2

	ptr = ptr->next;
    }

    return((CTL_MSG *) 0);
E 2
I 2
	return ((CTL_MSG *)0);
E 2
}

insert_table(request, response)
D 2
CTL_MSG *request;
CTL_RESPONSE *response;
E 2
I 2
	CTL_MSG *request;
	CTL_RESPONSE *response;
E 2
{
D 2
    TABLE_ENTRY *ptr;
    long current_time;
E 2
I 2
D 5
	TABLE_ENTRY *ptr;
E 5
I 5
	register TABLE_ENTRY *ptr;
E 5
	long current_time;
E 2

D 2
    gettimeofday(&tp, &txp);
    current_time = tp.tv_sec;

    response->id_num = request->id_num = new_id();

E 2
I 2
	gettimeofday(&tp, &txp);
	current_time = tp.tv_sec;
D 5
	response->id_num = request->id_num = new_id();
E 5
I 5
	request->id_num = new_id();
	response->id_num = htonl(request->id_num);
E 5
E 2
	/* insert a new entry into the top of the list */
D 2
    
    ptr = (TABLE_ENTRY *) malloc(sizeof(TABLE_ENTRY));

    if (ptr == NIL) {
	print_error("malloc in insert_table");
    }

    ptr->time = current_time;
    ptr->request = *request;

    ptr->next = table;
    if (ptr->next != NIL) {
	ptr->next->last = ptr;
    }
    ptr->last = NIL;
    table = ptr;
E 2
I 2
	ptr = (TABLE_ENTRY *)malloc(sizeof(TABLE_ENTRY));
	if (ptr == NIL) {
D 5
		fprintf(stderr, "malloc in insert_table");
		exit(1);
E 5
I 5
		syslog(LOG_ERR, "insert_table: Out of memory");
		_exit(1);
E 5
	}
	ptr->time = current_time;
	ptr->request = *request;
	ptr->next = table;
	if (ptr->next != NIL)
		ptr->next->last = ptr;
	ptr->last = NIL;
	table = ptr;
E 2
}

D 2
    /* generate a unique non-zero sequence number */

E 2
I 2
/*
 * Generate a unique non-zero sequence number
 */
E 2
new_id()
{
D 2
    static int current_id = 0;
E 2
I 2
	static int current_id = 0;
E 2

D 2
    current_id = (current_id + 1) % MAX_ID;

E 2
I 2
	current_id = (current_id + 1) % MAX_ID;
E 2
	/* 0 is reserved, helps to pick up bugs */
D 2

    if (current_id == 0) current_id = 1;

    return(current_id);
E 2
I 2
	if (current_id == 0)
		current_id = 1;
	return (current_id);
E 2
}

D 2
    /* delete the invitation with id 'id_num' */

E 2
I 2
/*
 * Delete the invitation with id 'id_num'
 */
E 2
delete_invite(id_num)
D 2
int id_num;
E 2
I 2
	int id_num;
E 2
{
D 2
    TABLE_ENTRY *ptr;
E 2
I 2
D 5
	TABLE_ENTRY *ptr;
I 3
	extern FILE *debugout;
E 5
I 5
	register TABLE_ENTRY *ptr;
E 5
E 3
E 2

D 2
    ptr = table;
E 2
I 2
	ptr = table;
E 2
D 5

E 5
D 2
    if (debug) printf("Entering delete_invite with %d\n", id_num);

    while (ptr != NIL && ptr->request.id_num != id_num) {
	if (debug) print_request(&ptr->request);
	ptr = ptr->next;
    }
	
    if (ptr != NIL) {
	delete(ptr);
	return(SUCCESS);
    }
    
    return(NOT_HERE);
E 2
I 2
	if (debug)
D 3
		printf("Entering delete_invite with %d\n", id_num);
E 3
I 3
D 5
		fprintf(debugout,"Entering delete_invite with %d\n", id_num);
E 5
I 5
		syslog(LOG_DEBUG, "delete_invite(%d)", id_num);
E 5
E 3
	for (ptr = table; ptr != NIL; ptr = ptr->next) {
		if (ptr->request.id_num == id_num)
			break;
		if (debug)
D 5
			print_request(&ptr->request);
E 5
I 5
			print_request("", &ptr->request);
E 5
	}
	if (ptr != NIL) {
		delete(ptr);
		return (SUCCESS);
	}
	return (NOT_HERE);
E 2
}

D 2
    /* classic delete from a double-linked list */

E 2
I 2
/*
 * Classic delete from a double-linked list
 */
E 2
delete(ptr)
D 2
TABLE_ENTRY *ptr;
E 2
I 2
D 5
	TABLE_ENTRY *ptr;
E 5
I 5
	register TABLE_ENTRY *ptr;
E 5
E 2
{
I 3
D 5
	extern FILE *debugout;
E 5
E 3
D 2
    if (debug) printf("Deleting : ");
    if (debug) print_request(&ptr->request);
E 2

D 2
    if (table == ptr) {
	table = ptr->next;
    } else if (ptr->last != NIL) {
	ptr->last->next = ptr->next;
    }

    if (ptr->next != NIL) {
	ptr->next->last = ptr->last;
    }

    free((char *) ptr);
E 2
I 2
D 5
	if (debug) {
D 3
		printf("Deleting : ");
E 3
I 3
		fprintf(debugout, "Deleting : ");
E 3
		print_request(&ptr->request);
	}
E 5
I 5
	if (debug)
		print_request("delete", &ptr->request);
E 5
	if (table == ptr)
		table = ptr->next;
	else if (ptr->last != NIL)
		ptr->last->next = ptr->next;
	if (ptr->next != NIL)
		ptr->next->last = ptr->last;
	free((char *)ptr);
E 2
}
E 1
