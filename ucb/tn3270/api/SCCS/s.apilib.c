h62360
s 00009/00018/00381
d D 3.2 88/03/28 13:46:37 bostic 12 11
c add Berkeley specific header
e
s 00000/00000/00399
d D 3.1 87/08/11 10:17:32 minshall 11 10
c New version numbering.
e
s 00025/00000/00374
d D 1.10 87/07/17 10:01:23 minshall 10 9
c Install sccs headers and copyright notices.
e
s 00001/00001/00373
d D 1.9 87/07/15 15:24:25 minshall 9 8
c New directory structure
e
s 00001/00001/00373
d D 1.8 87/07/03 11:51:03 minshall 8 7
c Remove offending trailing characters on #endif directive.
e
s 00020/00000/00354
d D 1.7 87/06/16 17:17:49 minshall 7 6
c api_ps_or_oia_modified() added.
e
s 00019/00017/00335
d D 1.6 87/06/15 23:26:21 minshall 6 5
c Cut down on number of protocol exchanges by passing parm data 
c over with the initial parameters.
e
s 00016/00000/00336
d D 1.5 87/06/15 14:55:15 minshall 5 4
c Name changes, send/receive sequence numbers, conversation flow, 
c api_exch_flush().
e
s 00013/00000/00323
d D 1.4 87/06/11 15:02:10 minshall 4 3
c Interim (compiling) version.
e
s 00006/00006/00317
d D 1.3 87/05/25 16:26:37 minshall 3 2
c This version works better than the last.
e
s 00281/00042/00042
d D 1.2 87/05/25 10:04:24 minshall 2 1
c Yet another cut (this one runs on the PC).
e
s 00084/00000/00000
d D 1.1 87/05/25 08:55:58 minshall 1 0
c date and time created 87/05/25 08:55:58 by minshall
e
u
U
t
T
I 10
/*
D 12
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 12
I 12
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 12
 *
D 12
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 12
I 12
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif	/* not lint */
E 12
I 12
#endif /* not lint */
E 12

E 10
I 1
D 2
#define	LINT_ARGS
#include <stdio.h>

E 2
D 9
#include "../api/api.h"
E 9
I 9
#include "../ctlr/api.h"
E 9

D 2
int api_sup_errno = 0;
E 2
I 2
#include "apilib.h"
E 2

int
I 2
    api_sup_errno = 0,			/* Supervisor error number */
    api_sup_fcn_id = 0,			/* Supervisor function id (0x12) */
    api_fcn_errno = 0,			/* Function error number */
    api_fcn_fcn_id = 0;			/* Function ID (0x6b, etc.) */

static int
    gate_sessmgr = 0,
    gate_keyboard = 0,
    gate_copy = 0,
    gate_oiam = 0;

/*
 * Issue an API request, with reg structures supplied by the caller.
 *
 * Only certain routines need this (supervisor services come to mind).
 */

D 6
int
api_issue_regs(ah, al, bh, bl, cx, dx, parms, regs, sregs)
E 6
I 6
static int
api_issue_regs(ah, al, bh, bl, cx, dx, parms, length, regs, sregs)
E 6
int		ah, al, bh, bl, cx, dx;
char 		*parms;
I 6
int		length;
E 6
union REGS 	*regs;
struct SREGS 	*sregs;
{
    char far *ourseg = parms;

    regs->h.ah = ah;
    regs->h.al = al;
    regs->h.bh = bh;
    regs->h.bl = bl;
    regs->x.cx = cx;
    regs->x.dx = dx;
    sregs->es = (int) FP_SEG(ourseg);
    regs->x.di = (int) FP_OFF(ourseg);

I 4
#if	defined(MSDOS)
E 4
    int86x(API_INTERRUPT_NUMBER, regs, regs, sregs);
I 4
#endif	/* defined(MSDOS) */
#if	defined(unix)
D 6
    api_exch_api(regs, sregs);
E 6
I 6
    api_exch_api(regs, sregs, parms, length);
E 6
#endif	/* defined(unix) */

E 4
    if (regs->h.cl != 0) {
	api_sup_errno = regs->h.cl;
	return -1;
    } else {
	return 0;
    }
}


/*
 * Issue an API request without requiring caller to supply
 * registers.  Most routines use this.
 */

I 6
static int
api_issue(ah, al, bh, bl, cx, dx, parms, length)
E 6
int
E 2
D 6
api_issue(ah, al, bh, bl, cx, dx, parms)
int
E 6
    ah,
    al,
    bh,
    bl,
    cx,
    dx;
char *parms;
I 6
int length;				/* Length of parms */
E 6
{
    union REGS regs;
    struct SREGS sregs;
D 2
    static int oures = 0;
E 2

D 2
    if (oures == 0) {
	segread(&sregs);
	oures = sregs.es;
    }
    regs.h.ah = ah;
    regs.h.al = al;
    regs.h.bh = bh;
    regs.h.bl = bl;
    regs.x.cx = cx;
    regs.x.dx = dx;
    sregs.es = oures;
    regs.x.di = (int) parms;

    int86x(API_INTERRUPT_NUMBER, &regs, &regs, &sregs);
    if (regs.h.cl != 0) {
	api_sup_errno = regs.h.cl;
	return -1;
    } else {
	return 0;
    }
E 2
I 2
D 6
    return api_issue_regs(ah, al, bh, bl, cx, dx, parms, &regs, &sregs);
E 6
I 6
    return api_issue_regs(ah, al, bh, bl, cx, dx, parms, length, &regs, &sregs);
E 6
E 2
}
I 2

/*
 * Supervisor Services
 */
E 2

D 2

E 2
int
api_name_resolve(name)
char *name;
{
    NameResolveParms parms;
    int i;
    union REGS regs;
    struct SREGS sregs;
D 2
    static int oures = 0;
E 2

    for (i = 0; i < sizeof parms.gate_name; i++) {
	if (*name) {
	    parms.gate_name[i] = *name++;
	} else {
	    parms.gate_name[i] = ' ';
	}
    }

D 2
    if (oures == 0) {
	segread(&sregs);
	oures = sregs.es;
E 2
I 2
D 6
    if (api_issue_regs(NAME_RESOLUTION, 0, 0, 0, 0, 0, &parms, &regs, &sregs)
E 6
I 6
    if (api_issue_regs(NAME_RESOLUTION, 0, 0, 0, 0, 0, &parms, sizeof parms, &regs, &sregs)
E 6
		    == -1) {
	return -1;
    } else {
	return regs.x.dx;
E 2
    }
D 2
    regs.h.ah = NAME_RESOLUTION;
    regs.h.al = 0;
    regs.h.bh = 0;
    regs.h.bl = 0;
    regs.x.cx = 0;
    regs.x.dx = 0;
    sregs.es = oures;
    regs.x.di = (int) &parms;
E 2
I 2
}
I 7

#if	defined(unix)
/*
 * Block until the oia or ps is modified.
 */

int
api_ps_or_oia_modified()
{
    union REGS regs;
    struct SREGS sregs;

    if (api_issue_regs(PS_OR_OIA_MODIFIED, 0, 0, 0, 0, 0, 0, 0, &regs, &sregs)
		    == -1) {
	return -1;
    } else {
	return 0;
    }
}
#endif	/* defined(unix) */
E 7

/*
 * Session Information Services
 */
E 2

D 2
    int86x(API_INTERRUPT_NUMBER, &regs, &regs, &sregs);
    if (regs.h.cl != 0) {
	api_sup_errno = regs.h.cl;
E 2
I 2
D 3
api_query_sesion_id(parms)
E 3
I 3
api_query_session_id(parms)
E 3
QuerySessionIdParms *parms;
{
    if (api_issue(0x09, QUERY_SESSION_ID, 0x80, 0x20, 0,
D 6
					gate_sessmgr, (char *)parms) == -1) {
E 6
I 6
					gate_sessmgr, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
E 2
	return -1;
I 2
    } else if (parms->rc == 0) {
	return 0;
E 2
    } else {
D 2
	return regs.x.dx;
E 2
I 2
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
E 2
    }
I 2
}


D 3
api_query_session_parms(parms)
E 3
I 3
api_query_session_parameters(parms)
E 3
QuerySessionParametersParms *parms;
{
D 3
    if (api_issue(0x09, QUERY_SESSION_PARMS, 0x80, 0x20, 0,
E 3
I 3
    if (api_issue(0x09, QUERY_SESSION_PARAMETERS, 0x80, 0x20, 0,
E 3
D 6
					gate_sessmgr, (char *)parms) == -1) {
E 6
I 6
			    gate_sessmgr, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
	return -1;
    } else if (parms->rc == 0) {
	return 0;
    } else {
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
    }
}

api_query_session_cursor(parms)
QuerySessionCursorParms *parms;
{
D 3
    if (api_issue(0x09, QUERY_SESSION_CURSOR, 0x80, 0x20, 0,
E 3
I 3
    if (api_issue(0x09, QUERY_SESSION_CURSOR, 0x80, 0x20, 0xff,
E 3
D 6
					gate_sessmgr, (char *)parms) == -1) {
E 6
I 6
			gate_sessmgr, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
	return -1;
    } else if (parms->rc == 0) {
	return 0;
    } else {
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
    }
}

/*
 * Keyboard Services
 */

api_connect_to_keyboard(parms)
ConnectToKeyboardParms *parms;
{
    if (api_issue(0x09, CONNECT_TO_KEYBOARD, 0x80, 0x20, 0,
D 6
					gate_keyboard, (char *)parms) == -1) {
E 6
I 6
			gate_keyboard, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
	return -1;
    } else if (parms->rc == 0) {
	return 0;
    } else {
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
    }
}


api_disconnect_from_keyboard(parms)
DisconnectFromKeyboardParms *parms;
{
    if (api_issue(0x09, DISCONNECT_FROM_KEYBOARD, 0x80, 0x20, 0,
D 6
					gate_keyboard, (char *)parms) == -1) {
E 6
I 6
			gate_keyboard, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
	return -1;
    } else if (parms->rc == 0) {
	return 0;
    } else {
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
    }
}


api_write_keystroke(parms)
WriteKeystrokeParms *parms;
{
    if (api_issue(0x09, WRITE_KEYSTROKE, 0x80, 0x20, 0,
D 6
					gate_keyboard, (char *)parms) == -1) {
E 6
I 6
			gate_keyboard, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
	return -1;
    } else if (parms->rc == 0) {
	return 0;
    } else {
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
    }
}


api_disable_input(parms)
DisableInputParms *parms;
{
    if (api_issue(0x09, DISABLE_INPUT, 0x80, 0x20, 0,
D 6
					gate_keyboard, (char *)parms) == -1) {
E 6
I 6
			gate_keyboard, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
	return -1;
    } else if (parms->rc == 0) {
	return 0;
    } else {
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
    }
}

api_enable_input(parms)
EnableInputParms *parms;
{
    if (api_issue(0x09, ENABLE_INPUT, 0x80, 0x20, 0,
D 6
					gate_keyboard, (char *)parms) == -1) {
E 6
I 6
			gate_keyboard, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
	return -1;
    } else if (parms->rc == 0) {
	return 0;
    } else {
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
    }
}

/*
 * Copy Services
 */

api_copy_string(parms)
CopyStringParms *parms;
{
D 3
    if (api_issue(0x09, COPY_STRING, 0x80, 0x20, 0,
E 3
I 3
    if (api_issue(0x09, COPY_STRING, 0x80, 0x20, 0xff,
E 3
D 6
					    gate_copy, (char *)parms) == -1) {
E 6
I 6
			    gate_copy, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
	return -1;
    } else if (parms->rc == 0) {
	return 0;
    } else {
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
    }
}

/*
 * Operator Information Area Services
 */

api_read_oia_group(parms)
ReadOiaGroupParms *parms;
{
D 3
    if (api_issue(0x09, READ_OIA_GROUP, 0x80, 0x20, 0,
E 3
I 3
    if (api_issue(0x09, READ_OIA_GROUP, 0x80, 0x20, 0xff,
E 3
D 6
					    gate_oiam, (char *)parms) == -1) {
E 6
I 6
			    gate_oiam, (char *)parms, sizeof *parms) == -1) {
E 6
	api_fcn_errno = 0;
	api_fcn_fcn_id = 0;
	return -1;
    } else if (parms->rc == 0) {
	return 0;
    } else {
	api_fcn_errno = parms->rc;
	api_fcn_fcn_id = parms->function_id;
	return -1;
    }
}

/*
I 5
 * The "we are done" routine.  This gets called last.
 */

api_finish()
{
#if	defined(unix)
    if (api_close_api() == -1) {
	return -1;
    } else {
	return 0;
    }
#endif	/* defined(unix) */
}


/*
E 5
 * The initialization routine.  Be sure to call this first.
 */

api_init()
{
    union REGS regs;
    struct SREGS sregs;

I 4
#if	defined(MSDOS)
E 4
    regs.h.ah = 0x35;
    regs.h.al = API_INTERRUPT_NUMBER;
    intdosx(&regs, &regs, &sregs);

    if ((regs.x.bx == 0) && (sregs.es == 0)) {
	return 0;		/* Interrupt not being handled */
    }
I 4
D 8
#endif	defined(MSDOS)
E 8
I 8
#endif	/* defined(MSDOS) */
E 8
#if	defined(unix)
    if (api_open_api(0) == -1) {
	return 0;
    }
#endif	/* defined(unix) */
E 4

    gate_sessmgr = api_name_resolve("SESSMGR");
    gate_keyboard = api_name_resolve("KEYBOARD");
    gate_copy = api_name_resolve("COPY");
    gate_oiam = api_name_resolve("OIAM");

    if ((gate_sessmgr == gate_keyboard) ||
	(gate_sessmgr == gate_copy) ||
	(gate_sessmgr == gate_oiam) ||
	(gate_keyboard == gate_copy) ||
	(gate_keyboard == gate_oiam) ||
	(gate_copy == gate_oiam)) {
	    return 0;		/* Interrupt doesn't seem correct */
    }
    return 1;
E 2
}
E 1
