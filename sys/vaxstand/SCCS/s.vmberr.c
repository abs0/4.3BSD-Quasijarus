h31998
s 00002/00000/00071
d D 7.3 04/02/07 18:35:00 msokolov 3 2
c vmb.h requires types.h now
e
s 00009/00017/00062
d D 7.2 04/02/07 17:14:49 msokolov 2 1
c oops, can't use sprintf
e
s 00079/00000/00000
d D 7.1 04/02/07 16:20:32 msokolov 1 0
c date and time created 04/02/07 16:20:32 by msokolov
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
 */

/************************************************************************
 *									*
 *			Copyright (c) 1985 by				*
 *		Digital Equipment Corporation, Maynard, MA		*
 *			All rights reserved.				*
 *									*
 *   This software is furnished under a license and may be used and	*
 *   copied  only  in accordance with the terms of such license and	*
 *   with the  inclusion  of  the  above  copyright  notice.   This	*
 *   software  or  any  other copies thereof may not be provided or	*
 *   otherwise made available to any other person.  No title to and	*
 *   ownership of the software is hereby transferred.			*
 *									*
 *   This software is  derived  from  software  received  from  the	*
 *   University    of   California,   Berkeley,   and   from   Bell	*
 *   Laboratories.  Use, duplication, or disclosure is  subject  to	*
 *   restrictions  under  license  agreements  with  University  of	*
 *   California and with AT&T.						*
 *									*
 *   The information in this software is subject to change  without	*
 *   notice  and should not be construed as a commitment by Digital	*
 *   Equipment Corporation.						*
 *									*
 *   Digital assumes no responsibility for the use  or  reliability	*
 *   of its software on equipment which is not supplied by Digital.	*
 *									*
 ************************************************************************/
I 3

#include "types.h"
E 3
#include "../mdec/vmb.h"

D 2
static char *errmsg;
static char errmsgbuf[40];

E 2
/*
 * Functional Discription:
 *	This routine is called when reporting errors returned from the
D 2
 *	VMB routines.  It returns a pointer to a string describing the 
 *	meaning of the input error code.
E 2
I 2
 *	VMB routines.  It prints a newline-terminated error message.
E 2
 *
 * Inputs:
 *	VMB error code
 *
 * Outputs:
D 2
 *	pointer to error message string
E 2
I 2
 *	none
E 2
 *
 */
D 2
char *
E 2
vmberr(code)
	int	code;
{
	switch (code&0xffff) {
	case SS$_PARITY:
D 2
		errmsg="Parity Error";
E 2
I 2
		printf("Parity Error\n");
E 2
		break;
	case SS$_BUFBYTALI:
D 2
		errmsg="Invalid Buffer Alignment";
E 2
I 2
		printf("Invalid Buffer Alignment\n");
E 2
		break;
	case SS$_CTLRERR: 
D 2
		errmsg="Fatal Controller Error";
E 2
I 2
		printf("Fatal Controller Error\n");
E 2
		break;
	case SS$_NOSUCHDEV:
D 2
		errmsg="No Such Device";
E 2
I 2
		printf("No Such Device\n");
E 2
		break;
	case SS$_ENDOFFILE:
D 2
		errmsg="End Of File";
E 2
I 2
		printf("End Of File\n");
E 2
		break;
	case SS$_DEVOFFLINE:
D 2
		errmsg="Device Offline";
E 2
I 2
		printf("Device Offline\n");
E 2
		break;
	default:
D 2
		sprintf(errmsgbuf, "VMB error code %x", code);
		errmsg=errmsgbuf;
		break;
E 2
I 2
		printf("VMB error code %x\n", code);
E 2
	}
D 2
	return(errmsg);
E 2
}
E 1
