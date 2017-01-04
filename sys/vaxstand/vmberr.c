/*
 *	@(#)vmberr.c	7.3 (Berkeley) 2/7/04
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

#include "types.h"
#include "../mdec/vmb.h"

/*
 * Functional Discription:
 *	This routine is called when reporting errors returned from the
 *	VMB routines.  It prints a newline-terminated error message.
 *
 * Inputs:
 *	VMB error code
 *
 * Outputs:
 *	none
 *
 */
vmberr(code)
	int	code;
{
	switch (code&0xffff) {
	case SS$_PARITY:
		printf("Parity Error\n");
		break;
	case SS$_BUFBYTALI:
		printf("Invalid Buffer Alignment\n");
		break;
	case SS$_CTLRERR: 
		printf("Fatal Controller Error\n");
		break;
	case SS$_NOSUCHDEV:
		printf("No Such Device\n");
		break;
	case SS$_ENDOFFILE:
		printf("End Of File\n");
		break;
	case SS$_DEVOFFLINE:
		printf("Device Offline\n");
		break;
	default:
		printf("VMB error code %x\n", code);
	}
}
