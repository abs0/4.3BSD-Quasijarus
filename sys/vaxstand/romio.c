/*
 *	@(#)romio.c	7.1 (Berkeley) 2/7/04
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
 *   The information in this software is subject to change  without	*
 *   notice  and should not be construed as a commitment by Digital	*
 *   Equipment Corporation.						*
 *									*
 *   Digital assumes no responsibility for the use  or  reliability	*
 *   of its software on equipment which is not supplied by Digital.	*
 *									*
 ************************************************************************/

	.globl	_romio
_romio:	.word   0x0FC0			# save r6 - r11
	/*
	 * ROM Style read
	 */
	movl	_ROM_r0,r0		# restore R0
	movl	_ROM_r1,r1		# restore R1
	movl	_ROM_r2,r2		# restore R2
	movl	_ROM_r3,r3		# restore R3
	movl	_ROM_r4,r4		# restore R4
	movl	_ROM_r6,r6		# restore R6
	movl	_ROM_r7,r7		# restore R7
	movl	12(ap),r8		# set up the LBN
	/*
	 * ALWAYS USE THE PAGE ALIGNED BUFFER BECAUSE OF A BUG IN THE
	 * 750 ROM UDA DRIVER.
	 *
	 * Since this driver is only used in bootdec for loading vmb.exe
	 * (which is loaded at 200), the page at 0 serves very well.
	 */

	clrl	r5			# KLUDGE
	pushl	fp			# save off fp and restore it after 
					# jump into ROM.

	movl	_ROM_fp,fp		# restore saved off fp (calypso).
	pushl	r5			# set transfer address
	jsb	(r6)			# do the read (1 512 Byte Sector)
	tstl	(sp)+			# pop address from stack
	movl	(sp)+,fp		# restore frame pointer (calypso).

	pushr	$0x01			# Save status in R0
	movl	20(ap),r8		# set transfer address
	/*
	 * MOVE THE DATA BACK TO THE REAL BUFFER ADDRESS
	 */
	movc3	$0x200,(r5),(r8) 	# Move the data back in to the
	popr	$0x01			# Restore status in R0 before returning
	ret				# R0 contains error
