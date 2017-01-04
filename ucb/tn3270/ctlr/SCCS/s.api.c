h07919
s 00009/00018/00674
d D 3.2 88/03/28 12:34:05 bostic 17 16
c add Berkeley specific header
e
s 00000/00000/00692
d D 3.1 87/08/11 10:18:34 minshall 16 15
c New version numbering.
e
s 00025/00000/00667
d D 1.15 87/07/17 10:03:06 minshall 15 14
c Install sccs headers and copyright notices.
e
s 00003/00003/00664
d D 1.14 87/07/15 15:25:31 minshall 14 13
c New directory structure.
e
s 00001/00001/00666
d D 1.13 87/06/19 12:49:38 minshall 13 12
c Directory changes.
e
s 00007/00000/00660
d D 1.12 87/06/16 17:20:26 minshall 12 11
c Add PS_OR_OIA_MODIFIED (in the Unix environment).
e
s 00044/00028/00616
d D 1.11 87/06/16 12:40:38 minshall 11 10
c Validity check some more parameters, and a performance enhancement.
e
s 00008/00010/00636
d D 1.10 87/06/15 09:21:50 minshall 10 9
c We are writing a Unix version.  Also, avoid conflict with "access(2)".
e
s 00118/00002/00528
d D 1.9 87/05/28 17:29:13 minshall 9 8
c This version, with copy_string(), compiles and loads (on PC).
e
s 00045/00041/00485
d D 1.8 87/05/25 16:27:37 minshall 8 7
c Various fixes.  No copy string yet, though.
e
s 00065/00000/00461
d D 1.7 87/05/24 16:50:37 minshall 7 6
c Fix "write_keystroke" (untested).
e
s 00063/00080/00398
d D 1.6 87/05/24 14:36:06 minshall 6 5
c New OIA.
e
s 00005/00074/00473
d D 1.5 87/05/22 12:00:38 minshall 5 4
c This version compiles on the PC.
e
s 00080/00047/00467
d D 1.4 87/05/21 21:29:56 minshall 4 3
c This version compiles.
e
s 00246/00020/00268
d D 1.3 87/05/21 20:40:47 minshall 3 2
c A version (probably doesn't even compile).
e
s 00036/00000/00252
d D 1.2 87/05/21 11:28:01 minshall 2 1
c A version.
e
s 00252/00000/00000
d D 1.1 87/05/20 15:33:45 minshall 1 0
c date and time created 87/05/20 15:33:45 by minshall
e
u
U
t
T
I 1
/*
I 15
D 17
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 17
I 17
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 17
 *
D 17
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
E 17
I 17
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 17
#endif	/* not lint */
E 17
I 17
#endif /* not lint */
E 17

/*
E 15
 * This file implements the API used in the PC version.
 */

#include <stdio.h>
D 5
#include <dos.h>
#include <stdlib.h>
E 5

D 5
#include "spint.h"
E 5
#include "api.h"
D 5
#include "../general.h"
E 5
I 5
#include "../general/general.h"
E 5

I 9
D 13
#include "../ascii/disp_asc.h"
E 13
I 13
D 14
#include "../apilib/disp_asc.h"
E 14
I 14
#include "../api/disp_asc.h"
E 14
E 13

E 9
I 4
D 14
#include "../ctlr/screen.h"
I 6
#include "../ctlr/oia.h"
E 14
I 14
#include "screen.h"
#include "oia.h"
E 14

E 6
D 5
#include "../system/globals.h"
E 5
I 5
#include "../general/globals.h"
E 5
E 4

I 4
D 8
int ApiDisableInput = 0;

E 8
E 4
/*
I 6
 * General utility routines.
 */

#if	defined(MSDOS)
D 8
static int ourds = 0;		/* Safe */
E 8

I 8
#if	defined(LINT_ARGS)
static void movetous(char *, int, int, int);
static void movetothem(int, int, char *, int);
#endif	/* defined(LINT_ARGS) */

I 9
D 10
#define	access(foo,length)	(foo)
#define	unaccess(foo,goo,length)
E 10
I 10
D 11
#define	access_api(foo,length)	(foo)
#define	unaccess_api(foo,goo,length)
E 11
I 11
#define	access_api(foo,length,copyin)	(foo)
#define	unaccess_api(foo,goo,length,copyout)
E 11
E 10

E 9
E 8
static void
movetous(parms, es, di, length)
char *parms;
I 8
int es, di, length;
E 8
{
D 8
    if (ourds == 0) {
	struct SREGS sregs;
E 8
I 8
    char far *farparms = parms;
E 8

D 8
	segread(&sregs);
	ourds = sregs.ds;
    }
    movedata(es, di, ourds, (int)parms, length);
E 8
I 8
    movedata(es, di, (int) FP_SEG(farparms), (int) FP_OFF(farparms), length);
E 8
}

static void
D 8
movetothem(parms, es, di, length)
E 8
I 8
movetothem(es, di, parms, length)
int es, di;
char *parms;
int length;
E 8
{
D 8
    if (ourds == 0) {
	struct SREGS sregs;
E 8
I 8
    char far *farparms = parms;
E 8

D 8
	segread(&sregs);
	ourds = sregs.es;
    }
    movedata(ourds, (int)parms, es, di, length);
E 8
I 8
    movedata((int) FP_SEG(farparms), (int) FP_OFF(farparms), es, di, length);
E 8
}
#endif	/* defined(MSDOS) */

D 10
/* No Unix version yet... */

E 10
I 9
#if	defined(unix)
D 10
#define	access(f,l)	(f)
E 9

E 10
I 10
extern char *access_api(), *unaccess_api();
E 10
I 9
#endif	/* defined(unix) */

I 10

E 10
E 9
/*
E 6
 * Supervisor Services.
 */

static void
D 6
name_resolve(regs, sregs)
E 6
I 6
name_resolution(regs, sregs)
E 6
union REGS *regs;
struct SREGS *sregs;
{
I 2
D 3
    char buffer[9];
E 3
I 3
    NameResolveParms parms;
E 3

D 3
    movetous(buffer, sregs->es, regs->x.di, sizeof buffer-1);
E 3
I 3
    movetous((char *) &parms, sregs->es, regs->x.di, sizeof parms);
E 3

    regs->h.cl = 0;
D 3
    if (strcmp(buffer, NAME_SESSMGR) == 0) {
E 3
I 3
D 6
    if (strcmp((char *)&parms, NAME_SESSMGR) == 0) {
E 6
I 6
    if (memcmp((char *)&parms, NAME_SESSMGR, sizeof parms.gate_name) == 0) {
E 6
E 3
	regs->x.dx = GATE_SESSMGR;
D 3
    } else if (strcmp(buffer, NAME_KEYBOARD) == 0) {
E 3
I 3
D 6
    } else if (strcmp((char *)&parms, NAME_KEYBOARD) == 0) {
E 6
I 6
    } else if (memcmp((char *)&parms, NAME_KEYBOARD,
					sizeof parms.gate_name) == 0) {
E 6
E 3
	regs->x.dx = GATE_KEYBOARD;
D 3
    } else if (strcmp(buffer, NAME_COPY) == 0) {
E 3
I 3
D 6
    } else if (strcmp((char *)&parms, NAME_COPY) == 0) {
E 6
I 6
    } else if (memcmp((char *)&parms, NAME_COPY, sizeof parms.gate_name) == 0) {
E 6
E 3
	regs->x.dx = GATE_COPY;
D 3
    } else if (strcmp(buffer, NAME_OIAM) == 0) {
E 3
I 3
D 6
    } else if (strcmp((char *)&parms, NAME_OIAM) == 0) {
E 6
I 6
    } else if (memcmp((char *)&parms, NAME_OIAM, sizeof parms.gate_name) == 0) {
E 6
E 3
	regs->x.dx = GATE_OIAM;
    } else {
	regs->h.cl = 0x2e;	/* Name not found */
    }
    regs->h.ch = 0x12;
    regs->h.bh = 7;
E 2
}

/*
 * Session Information Services.
 */

static void
query_session_id(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
I 2
D 3
    char buffer[16];
E 3
I 3
    QuerySessionIdParms parms;
E 3

D 3
    movetous(buffer, sregs->es, regs->h.di, sizeof buffer);
E 3
I 3
    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);
E 3

D 3
    if (buffer[0] != 0) {
	regs->cl = 0x0c;
E 3
I 3
D 8
    if (parms.rc != 0) {
	regs->h.cl = 0x0c;
	return;
    }
    if (parms.option_code != 0x01) {
	regs->h.cl = 0x0d;	/* Invalid option code */
E 8
I 8
    if ((parms.rc != 0) || (parms.function_id != 0)) {
	parms.rc = 0x0c;
    } else if (parms.option_code != 0x01) {
	parms.rc = 0x0d;	/* Invalid option code */
E 8
    } else if (parms.data_code != 0x45) {
D 8
	regs->h.cl = 0x0b;
E 8
I 8
	parms.rc = 0x0b;
E 8
E 3
    } else {
D 3
	if (buffer[2] != 0x01) {
	    regs->h.cl = 0x0d;	/* Invalid option code */
	} else if (buffer[3] != 0x45) {
	    regs->h.cl = 0x0b;
E 3
I 3
D 4
	NameArrayList list;
E 4
I 4
	NameArray list;
E 4
	NameArrayElement element;

	movetous((char *)&list, FP_SEG(parms.name_array),
D 6
			    FP_OFFSET(parms.name_array), sizeof list);
E 6
I 6
			    FP_OFF(parms.name_array), sizeof list);
E 6
D 4
	if (list.length < 14) || (list.length > 170)) {
E 4
I 4
	if ((list.length < 14) || (list.length > 170)) {
E 4
	    parms.rc = 0x12;
D 4
	    regs.h.cl = 0x12;
E 4
I 4
D 8
	    regs->h.cl = 0x12;
E 8
E 4
E 3
	} else {
D 3
	    buffer[0] = 0;
	    buffer[1] = 0x6d;
E 3
I 3
	    list.number_matching_session = 1;
	    list.name_array_element.short_name = parms.data_code;
	    list.name_array_element.type = TYPE_DFT;
	    list.name_array_element.session_id = 23;
	    memcpy(list.name_array_element.long_name, "ONLYSESS",
			    sizeof list.name_array_element.long_name);
	    movetothem(FP_SEG(parms.name_array),
D 6
		FP_OFFSET(parms.name_array), (char *)&list, sizeof list);
E 6
I 6
		FP_OFF(parms.name_array), (char *)&list, sizeof list);
E 6
	    parms.rc = 0;
E 3
D 8
	    regs->h.cl = 0;
E 8
	}
    }
D 3
    movetothem(sregs->es, regs->h.di, sizeof buffer);
E 3
I 3
D 4
    parms.function_code = 0x6d;
E 4
I 4
D 8
    parms.function_id = 0x6d;
E 8
I 8
    parms.function_id = 0x6b;
E 8
E 4
    movetothem(sregs->es, regs->x.di, (char *)&parms, sizeof parms);
E 3
E 2
}

static void
query_session_parameters(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
I 3
    QuerySessionParametersParms parms;

    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);

D 4
    if (parms.rc[0] !=0) || (parms.function_id != 0)) {
E 4
I 4
    if ((parms.rc !=0) || (parms.function_id != 0)) {
E 4
D 8
	regs->h.cl = 0x0c;
	return;
    }
    if (parms.session_id != 23) {
D 4
	regs.h.cl = parms.rc = 0x02;
E 4
I 4
	regs->h.cl = parms.rc = 0x02;
E 8
I 8
	parms.rc = 0x0c;
    } else if (parms.session_id != 23) {
	parms.rc = 0x02;
E 8
E 4
    } else {
D 4
	regs.h.cl = parms.rc = 0;
E 4
I 4
D 8
	regs->h.cl = parms.rc = 0;
E 4
	parms.function_id = 0x6b;
E 8
I 8
	parms.rc = 0;
E 8
	parms.session_type = TYPE_DFT;
	parms.session_characteristics = 0;	/* Neither EAB nor PSS */
	parms.rows = MaxNumberLines;
	parms.columns = MaxNumberColumns;
	parms.presentation_space = 0;
    }
I 8
    parms.function_id = 0x6b;
E 8
D 4
    movetothem(sregs->es, regs.x.di, (char *)&parms, sizeof parms);
E 4
I 4
    movetothem(sregs->es, regs->x.di, (char *)&parms, sizeof parms);
E 4
E 3
}

static void
query_session_cursor(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
I 3
    QuerySessionCursorParms parms;

    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);

    if ((parms.rc != 0) || (parms.function_id != 0)) {
	parms.rc = 0x0c;
    } else if (parms.session_id != 23) {
	parms.rc = 0x02;
    } else {
	parms.rc = 0;
D 8
	parms.function_id = 0x6b;
E 8
	parms.cursor_type = CURSOR_BLINKING;	/* XXX what is inhibited? */
	parms.row_address = ScreenLine(CursorAddress);
	parms.column_address = ScreenLineOffset(CursorAddress);
    }

D 8
    movetothem(sregs->es, regs->x.di, sizeof parms);
E 8
I 8
    parms.function_id = 0x6b;
    movetothem(sregs->es, regs->x.di, (char *) &parms, sizeof parms);
E 8
E 3
}

/*
 * Keyboard Services.
 */


static void
connect_to_keyboard(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
I 3
    ConnectToKeyboardParms parms;

D 5
    movetous((char *)parms, sregs->es, regs->x.di, sizeof parms);
E 5
I 5
    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);
E 5

    if ((parms.rc != 0) || (parms.function_id != 0)) {
	parms.rc = 0x0c;
    } else if (parms.session_id != 23) {
	parms.rc = 0x02;
    } else if (parms.intercept_options != 0) {
	parms.rc = 0x01;
    } else {
	parms.rc = 0;
	parms.first_connection_identifier = 0;
    }
    parms.function_id = 0x62;

    movetothem(sregs->es, regs->x.di, (char *)&parms, sizeof parms);
E 3
}

static void
D 3
disable_input(regs, sregs)
E 3
I 3
disconnect_from_keyboard(regs, sregs)
E 3
union REGS *regs;
struct SREGS *sregs;
{
I 3
    DisconnectFromKeyboardParms parms;

    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);

    if ((parms.rc != 0) || (parms.function_id != 0)) {
	parms.rc = 0x0c;
    } else if (parms.session_id != 23) {
	parms.rc = 0x02;
    } else if (parms.connectors_task_id != 0) {
	parms.rc = 04;			/* XXX */
    } else {
	parms.rc = 0;
    }
    parms.function_id = 0x62;

    movetothem(sregs->es, regs->x.di, (char *)&parms, sizeof parms);
E 3
}

static void
write_keystroke(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
I 7
    WriteKeystrokeParms parms;

    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);

    if ((parms.rc != 0) || (parms.function_id != 0)) {
	parms.rc = 0x0c;
    } else if (parms.session_id != 23) {
	parms.rc = 0x02;
    } else if (parms.connectors_task_id != 0) {
	parms.rc = 0x04;
    } else {
	parms.number_of_keys_sent = 0;
	parms.rc = 0;
	if (parms.options == OPTION_SINGLE_KEYSTROKE) {
	    KeystrokeEntry *entry = &parms.keystroke_specifier.keystroke_entry;
	    
	    if (AcceptKeystroke(entry->scancode, entry->shift_state) == 0) {
		parms.rc = 0x10;		/* XXX needs 0x12 too! */
	    }
	    parms.number_of_keys_sent++;
	} else if (parms.options == OPTION_MULTIPLE_KEYSTROKES) {
	    KeystrokeList
		list,
		far *atlist = parms.keystroke_specifier.keystroke_list;
	    KeystrokeEntry
		entry[10],		/* 10 at a time */
		*ourentry,
		far *theirentry;
	    int
		todo;

	    movetous((char *)&list, FP_SEG(atlist),
				FP_OFF(atlist), sizeof *atlist);
	    todo = list.length/2;
	    ourentry = entry+(highestof(entry)+1);

	    while (todo) {
		if (ourentry > &entry[highestof(entry)]) {
		    int thistime;

		    thistime = todo;
		    if (thistime > numberof(entry)) {
			thistime = numberof(entry);
		    }
		    movetous((char *)entry, FP_SEG(theirentry),
			    FP_OFF(theirentry), thistime*sizeof *theirentry);
		    theirentry += thistime;
		    ourentry = entry;
		}
		if (AcceptKeystroke(ourentry->scancode,
						ourentry->shift_state) == 0) {
		    parms.rc = 0x10;		/* XXX needs 0x12 too! */
		    break;
		}
		parms.number_of_keys_sent++;
		ourentry++;
		todo--;
	    }
	} else {
	    parms.rc = 0x01;
	}
    }
    parms.function_id = 0x62;

    movetothem(sregs->es, regs->x.di, (char *)&parms, sizeof parms);
E 7
I 3
/* XXX */
E 3
}

I 3

E 3
static void
I 3
disable_input(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
    DisableInputParms parms;

    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);

    if ((parms.rc != 0) || (parms.function_id != 0)) {
	parms.rc = 0x0c;
    } else if (parms.session_id != 23) {
	parms.rc = 0x02;
    } else if (parms.connectors_task_id != 0) {
	parms.rc = 0x04;
    } else {
D 8
	ApiDisableInput = 1;
E 8
I 8
	SetOiaApiInhibit(&OperatorInformationArea);
E 8
	parms.rc = 0;
    }
    parms.function_id = 0x62;

    movetothem(sregs->es, regs->x.di, (char *)&parms, sizeof parms);
}

static void
E 3
enable_input(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
I 3
    EnableInputParms parms;

    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);

    if ((parms.rc != 0) || (parms.function_id != 0)) {
	parms.rc = 0x0c;
    } else if (parms.session_id != 23) {
	parms.rc = 0x02;
    } else if (parms.connectors_task_id != 0) {
	parms.rc = 0x04;
    } else {
D 8
	ApiDisableInput = 0;
E 8
I 8
	ResetOiaApiInhibit(&OperatorInformationArea);
E 8
	parms.rc = 0;
    }
    parms.function_id = 0x62;

    movetothem(sregs->es, regs->x.di, (char *)&parms, sizeof parms);
E 3
}

/*
 * Copy Services.
 */

I 9
D 11
copy_subroutine(target, source, parms, what_is_user)
E 11
I 11
static
copy_subroutine(target, source, parms, what_is_user, length)
E 11
BufferDescriptor *target, *source;
CopyStringParms *parms;
int what_is_user;
#define	USER_IS_TARGET	0
#define	USER_IS_SOURCE	1
{
#define	TARGET_NO_EAB		1
#define	SOURCE_NO_EAB		2
#define	TARGET_PC		4
#define	SOURCE_PC		8
#define	NO_FIELD_ATTRIBUTES	16
    int needtodo = 0;
D 11
    int length;
E 11
    int access_length;
    char far *input;
    char far *output;
    char far *access_pointer;

    if ((target->characteristics^source->characteristics)
		    &CHARACTERISTIC_EAB) {
	if (target->characteristics&CHARACTERISTIC_EAB) {
	    needtodo |= TARGET_NO_EAB;	/* Need to bump for EAB in target */
	} else {
	    needtodo |= SOURCE_NO_EAB;	/* Need to bump for EAB in source */
	}
    }
    if (target->session_type != source->session_type) {
	if (target->session_type == TYPE_PC) {
	    needtodo |= TARGET_PC;	/* scan codes to PC */
	} else {
	    needtodo |= SOURCE_PC;	/* PC to scan codes */
	}
    }
    if ((parms->copy_mode&COPY_MODE_FIELD_ATTRIBUTES) == 0) {
	needtodo |= NO_FIELD_ATTRIBUTES;
    }
D 11
    access_length = length = parms->source_end-source->begin;
E 11
I 11
    access_length = length;
E 11
    if (what_is_user == USER_IS_TARGET) {
	if (target->characteristics&CHARACTERISTIC_EAB) {
	    access_length *= 2;
	}
	input = (char far *) &Host[source->begin];
	access_pointer = target->buffer;
D 10
	output = access(target->buffer, access_length);
E 10
I 10
D 11
	output = access_api(target->buffer, access_length);
E 11
I 11
	output = access_api(target->buffer, access_length, 0);
E 11
E 10
    } else {
	if (source->characteristics&CHARACTERISTIC_EAB) {
	    access_length *= 2;
	}
	access_pointer = source->buffer;
D 10
	input = access(source->buffer, access_length);
E 10
I 10
D 11
	input = access_api(source->buffer, access_length);
E 11
I 11
	input = access_api(source->buffer, access_length, 1);
E 11
E 10
	output = (char far *) &Host[target->begin];
    }
    while (length--) {
	if (needtodo&TARGET_PC) {
	    *output++ = disp_asc[*input++];
	} else if (needtodo&SOURCE_PC) {
	    *output++ = asc_disp[*input++];
	} else {
	    *output++ = *input++;
	}
	if (needtodo&TARGET_NO_EAB) {
	    *input++;
	} else if (needtodo&SOURCE_NO_EAB) {
	    *output++ = 0;		/* Should figure out good EAB? */
	}
    }
    if (what_is_user == USER_IS_TARGET) {
D 10
	unaccess(target->buffer, access_pointer, access_length);
E 10
I 10
D 11
	unaccess_api(target->buffer, access_pointer, access_length);
E 11
I 11
	unaccess_api(target->buffer, access_pointer, access_length, 1);
E 11
E 10
    } else {
D 10
	unaccess(source->buffer, access_pointer, access_length);
E 10
I 10
D 11
	unaccess_api(source->buffer, access_pointer, access_length);
E 11
I 11
	unaccess_api(source->buffer, access_pointer, access_length, 0);
E 11
E 10
    }
}


E 9
static void
D 3
disconnect_from_keyboard(regs, sregs)
E 3
I 3
copy_string(regs, sregs)
E 3
union REGS *regs;
struct SREGS *sregs;
{
D 3
}
E 3
I 3
    CopyStringParms parms;
D 9
    BufferDescriptor *target, *source;
E 9
I 9
    BufferDescriptor *target = &parms.target, *source = &parms.source;
    int length;
E 9
E 3

I 3
    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);

I 11
    length = 1+parms.source_end-source->begin;
E 11
    if ((parms.rc != 0) || (parms.function_id !=0)) {
	parms.rc = 0x0c;
I 9
    } else if (target->session_id == 0) {	/* Target is buffer */
	if (source->session_id != 23) {		/* A no-no */
	    parms.rc = 0x2;
	} else {
D 11
	    if ((source->characteristics == target->characteristics) &&
E 11
I 11
	    if ((source->begin < 0) || (source->begin > highestof(Host))) {
		parms.rc = 0x06;		/* invalid source definition */
	    } else {
		if ((source->begin+length) > highestof(Host)) {
		    length = highestof(Host)-source->begin;
		    parms.rc = 0x0f;	/* Truncate */
		}
	        if ((source->characteristics == target->characteristics) &&
E 11
		    (source->session_type == target->session_type)) {
D 11
		length = parms.source_end-source->begin;
		if (source->characteristics&CHARACTERISTIC_EAB) {
		    length *= 2;
E 11
I 11
		    if (source->characteristics&CHARACTERISTIC_EAB) {
			length *= 2;
		    }
		    movetothem( (int) FP_SEG(target->buffer),
			    (int) FP_OFF(target->buffer),
			    (char *)&Host[source->begin], length);
		} else {
		    copy_subroutine(target, source, &parms,
							USER_IS_TARGET, length);
E 11
		}
D 11
		movetothem( (int) FP_SEG(target->buffer),
			(int) FP_OFF(target->buffer),
			(char *)&Host[source->begin], length);
	    } else {
		copy_subroutine(target, source, &parms, USER_IS_TARGET);
E 11
	    }
	}
    } else if (source->session_id != 0) {
	    parms.rc = 0xd;
    } else {
D 11
	if ((source->characteristics == target->characteristics) &&
		(source->session_type == target->session_type)) {
	    length = parms.source_end-source->begin;
	    if (source->characteristics&CHARACTERISTIC_EAB) {
		length *= 2;
	    }
	    movetous((char *)&Host[target->begin],
			(int) FP_SEG(source->buffer),
			(int) FP_OFF(source->buffer), length);
E 11
I 11
	if ((target->begin < 0) || (source->begin > highestof(Host))) {
	    parms.rc = 0x07;		/* invalid source definition */
E 11
	} else {
D 11
	    copy_subroutine(target, source, &parms, USER_IS_SOURCE);
E 11
I 11
	    if ((source->begin+length) > highestof(Host)) {
		length = highestof(Host)-source->begin;
		parms.rc = 0x0f;	/* Truncate */
	    }
	    if ((source->characteristics == target->characteristics) &&
		    (source->session_type == target->session_type)) {
		if (source->characteristics&CHARACTERISTIC_EAB) {
		    length *= 2;
		}
		movetous((char *)&Host[target->begin],
			    (int) FP_SEG(source->buffer),
			    (int) FP_OFF(source->buffer), length);
	    } else {
		copy_subroutine(target, source, &parms, USER_IS_SOURCE, length);
	    }
E 11
	}
E 9
    }
D 9
    /* XXX do something! */
E 9
D 5
    movetothem(sregs->es, regs->x.di, (char *)parms, sizeof parms);
E 5
I 5
    movetothem(sregs->es, regs->x.di, (char *)&parms, sizeof parms);
E 5
}
E 3
/*
 * Operator Information Area Services.
 */

static void
read_oia_group(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
I 3
    ReadOiaGroupParms parms;

    movetous((char *)&parms, sregs->es, regs->x.di, sizeof parms);

    if ((parms.rc != 0) || (parms.function_id != 0)) {
	parms.rc = 0x0c;
    } else if (parms.session_id != 23) {
	parms.rc = 0x02;
    } else {
	int group = parms.oia_group_number;
D 6
	char far *where = parms.oia_buffer;
E 6
I 6
	char *from;
	int size;
E 6

D 6
	switch (group) {
	case OIA_ALL_GROUPS:
	case OIA_ONLINE_OWNERSHIP:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_CHARACTER_SELECTION:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_SHIFT_STATE:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_PSS_GROUP_1:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_HIGHLIGHT_GROUP_1:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_COLOR_GROUP_1:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_INSERT:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_INPUT_INHIBITED:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_PSS_GROUP_2:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_HIGHLIGHT_GROUP_2:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_COLOR_GROUP_2:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
D 5
	case OIA_COMMUNICATION_ERROR_REMINDER:
E 5
I 5
	case OIA_COMM_ERROR_REMINDER:
E 5
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_PRINTER_STATUS:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_AUTOKEY_PLAY_RECORD_STATUS:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_AUTOKEY_ABORT_PAUSE_STATUS:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */
	case OIA_ENLARGE_STATE:
	    if (group != OIA_ALL_GROUPS) {
		break;
	    } /* else, fall through */

	    /* oops, we are done! */
	    break;
	default:
	    break;
E 6
I 6
D 8
	if (group > API_OIA_LAST_LEGAL_GROUP) {
E 8
I 8
	if ((group != API_OIA_ALL_GROUPS) &&
		((group > API_OIA_LAST_LEGAL_GROUP) || (group < 0))) {
E 8
	} else {
	    if (group == API_OIA_ALL_GROUPS) {
		size = API_OIA_BYTES_ALL_GROUPS;
		from = (char *)&OperatorInformationArea;
	    } else if (group == API_OIA_INPUT_INHIBITED) {
		size = sizeof OperatorInformationArea.input_inhibited;
		from = (char *)&OperatorInformationArea.input_inhibited[0];
	    } else {
		size = 1;
		from = ((char *)&OperatorInformationArea)+group;
	    }
	    movetothem(FP_SEG(parms.oia_buffer), FP_OFF(parms.oia_buffer),
			from, size);
E 6
I 4
	}
E 4
    }
D 4
    parms->function_id = 0x6d;
E 4
I 4
    parms.function_id = 0x6d;
E 4
    movetothem(sregs->es, regs->x.di, (char *)&parms, sizeof parms);
E 3
}

static void
unknown_op(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
    regs->h.ch = 0x12;
    regs->h.cl = 0x05;
}


handle_api(regs, sregs)
union REGS *regs;
struct SREGS *sregs;
{
    if (regs->h.ah == NAME_RESOLUTION) {
	name_resolution(regs, sregs);
I 12
#if	defined(unix)
    } else if (regs->h.ah == PS_OR_OIA_MODIFIED) {
	while ((oia_modified == 0) && (ps_modified == 0)) {
	    (void) Scheduler(1);
	}
	oia_modified = ps_modified = 0;
#endif	/* defined(unix) */
E 12
I 4
    } else if (regs->h.ah != 0x09) {
	regs->h.ch = 0x12;
	regs->h.cl = 0x0f;		/* XXX Invalid environmental access */
    } else if (regs->x.bx != 0x8020) {
	regs->h.ch = 0x12;
	regs->h.cl = 0x08;		/* XXX Invalid wait specified */
    } else if (regs->h.ch != 0) {
D 8
	regs->h.ch = 0x12;
	regs->h.cl = 0x07;		/* XXX Invalid reply specified */
E 8
I 8
	regs->x.cx = 0x1206;		/* XXX Invalid priority */
E 8
E 4
    } else {
	switch (regs->x.dx) {
	case GATE_SESSMGR:
	    switch (regs->h.al) {
	    case QUERY_SESSION_ID:
D 4
		query_session_id(regs, sregs);
E 4
I 4
		if (regs->h.cl != 0) {
I 8
		    regs->x.cx = 0x1206;
E 8
		} else {
I 8
		    regs->x.cx = 0x1200;
E 8
		    query_session_id(regs, sregs);
		}
E 4
		break;
D 8
	    case QUERY_SESSION_PARMS:
E 8
I 8
	    case QUERY_SESSION_PARAMETERS:
E 8
D 4
		query_session_parms(regs, sregs);
E 4
I 4
		if (regs->h.cl != 0) {
I 8
		    regs->x.cx = 0x1206;
E 8
		} else {
I 8
		    regs->x.cx = 0x1200;
E 8
D 6
		    query_session_parms(regs, sregs);
E 6
I 6
		    query_session_parameters(regs, sregs);
E 6
		}
E 4
		break;
	    case QUERY_SESSION_CURSOR:
D 4
		query_session_cursor(regs, sregs);
E 4
I 4
		if (regs->h.cl != 0xff) {
I 8
		    regs->x.cx = 0x1206;
E 8
		} else {
I 8
		    regs->x.cx = 0x1200;
E 8
		    query_session_cursor(regs, sregs);
		}
E 4
		break;
	    default:
		unknown_op(regs, sregs);
		break;
	    }
	    break;
	case GATE_KEYBOARD:
D 4
	    switch (regs->h.al) {
	    case CONNECT_TO_KEYBOARD:
		connect_to_keyboard(regs, sregs);
		break;
	    case DISABLE_INPUT:
		disable_input(regs, sregs);
		break;
	    case WRITE_KEYSTROKE:
		write_keystroke(regs, sregs);
		break;
	    case ENABLE_INPUT:
		enable_input(regs, sregs);
		break;
	    case DISCONNECT_FROM_KEYBOARD:
		disconnect_from_keyboard(regs, sregs);
		break;
	    default:
		unknown_op(regs, sregs);
		break;
E 4
I 4
	    if (regs->h.cl != 00) {
I 8
		regs->x.cx = 0x1206;
E 8
	    } else {
I 8
		regs->x.cx = 0x1200;
E 8
		switch (regs->h.al) {
		case CONNECT_TO_KEYBOARD:
		    connect_to_keyboard(regs, sregs);
		    break;
		case DISABLE_INPUT:
		    disable_input(regs, sregs);
		    break;
		case WRITE_KEYSTROKE:
		    write_keystroke(regs, sregs);
		    break;
		case ENABLE_INPUT:
		    enable_input(regs, sregs);
		    break;
		case DISCONNECT_FROM_KEYBOARD:
		    disconnect_from_keyboard(regs, sregs);
		    break;
		default:
		    unknown_op(regs, sregs);
		    break;
		}
E 4
	    }
	    break;
	case GATE_COPY:
D 4
	    switch (regs->h.al) {
	    case COPY_STRING:
		copy_string(regs, sregs);
		break;
	    default:
		unknown_op(regs, sregs);
		break;
E 4
I 4
	    if (regs->h.cl != 0xff) {
I 8
		regs->x.cx = 0x1206;
E 8
	    } else {
I 8
		regs->x.cx = 0x1200;
E 8
		switch (regs->h.al) {
		case COPY_STRING:
		    copy_string(regs, sregs);
		    break;
		default:
		    unknown_op(regs, sregs);
		    break;
		}
E 4
	    }
	    break;
	case GATE_OIAM:
D 4
	    switch (regs->h.al) {
	    case READ_OIA_GROUP:
		read_oia_group(regs, sregs);
		break;
	    default:
		unknown_op(regs, sregs);
		break;
E 4
I 4
	    if (regs->h.cl != 0xff) {
I 8
		regs->x.cx = 0x1206;
E 8
	    } else {
I 8
		regs->x.cx = 0x1200;
E 8
		switch (regs->h.al) {
		case READ_OIA_GROUP:
		    read_oia_group(regs, sregs);
		    break;
		default:
		    unknown_op(regs, sregs);
		    break;
		}
E 4
	    }
	    break;
	default:
D 4
	    unknown_op(regs, sregs);
E 4
I 4
	    regs->h.ch = 0x12;
	    regs->h.cl = 0x34;		/* Invalid GATE entry */
E 4
	    break;
	}
    }
D 5
}


/*
 * Called from telnet.c to fork a lower command.com.  We
 * use the spint... routines so that we can pick up
 * interrupts generated by application programs.
 */


int
shell(argc,argv)
int	argc;
char	*argv[];
{
    Spint spinted;
D 4
    static char command[256];
E 4
I 4
    char command[256];
E 4

    ClearElement(spinted);
    spinted.int_no = API_INTERRUPT_NUMBER;
    if (argc == 1) {
	command[0] = 0;
    } else {
	char *cmdptr;
	int length;

	argc--;
	argv++;
	strcpy(command, " /c");
	cmdptr = command+strlen(command);
	while (argc) {
	    if ((cmdptr+strlen(*argv)) >= (command+sizeof command)) {
		fprintf(stderr, "Argument list too long at argument *%s*.\n",
			    *argv);
		return 0;
	    }
	    *cmdptr++ = ' ';		/* Blank separators */
	    strcpy(cmdptr, *argv);
	    cmdptr += strlen(cmdptr);
	    argc--;
	    argv++;
	}
	length = strlen(command)-1;
	if (length < 0) {
	    length = 0;
	}
	command[0] = length;
    }

    /*
     * spint_start() returns when either the command has finished, or when
     * the required interrupt comes in.  In the latter case, the appropriate
     * thing to do is to process the interrupt, and then return to
     * the interrupt issuer by calling spint_continue().
     */
    spint_start(command, &spinted);
    while (spinted.done == 0) {
	/* Process request */
	handle_api(&spinted.regs, &spinted.sregs);
	spint_continue(&spinted);
    }
    if (spinted.rc != 0) {
	fprintf(stderr, "Process generated a return code of 0x%x.\n",
								spinted.rc);
    }
    return 0;
E 5
}
E 1
