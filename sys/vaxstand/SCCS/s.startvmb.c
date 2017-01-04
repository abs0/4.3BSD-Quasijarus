h25461
s 00067/00000/00000
d D 7.1 04/02/28 22:47:00 msokolov 1 0
c date and time created 04/02/28 22:47:00 by msokolov
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
 *                                                                      *
 *                      Copyright (c) 1985 by                           *
 *              Digital Equipment Corporation, Maynard, MA              *
 *                      All rights reserved.                            *
 *                                                                      *
 *   This software is furnished under a license and may be used and     *
 *   copied  only  in accordance with the terms of such license and     *
 *   with the  inclusion  of  the  above  copyright  notice.   This     *
 *   software  or  any  other copies thereof may not be provided or     *
 *   otherwise made available to any other person.  No title to and     *
 *   ownership of the software is hereby transferred.                   *
 *                                                                      *
 *   This software is  derived  from  software  received  from  the     *
 *   University    of   California,   Berkeley,   and   from   Bell     *
 *   Laboratories.  Use, duplication, or disclosure is  subject  to     *
 *   restrictions  under  license  agreements  with  University  of     *
 *   California and with AT&T.                                          *
 *                                                                      *
 *   The information in this software is subject to change  without     *
 *   notice  and should not be construed as a commitment by Digital     *
 *   Equipment Corporation.                                             *
 *                                                                      *
 *   Digital assumes no responsibility for the use  or  reliability     *
 *   of its software on equipment which is not supplied by Digital.     *
 *                                                                      *
 ************************************************************************/

/*
 * Functional Discription:
 *	This routine is called when ROM_BOOT is active and after
 *	VMB.EXE has beed loaded.  It restores the registers at boot
 *	time.  Bit 3 and Bit 16 get set R5 to force bootblock mode boot by
 *	VMB and to tell VMB not to drop out pages with CRD's.
 *	Assumes good memory was found.
 *
 * Inputs:
 *	none
 *
 * Outputs:
 *	none
 *
 */
        .text
        .globl  _start_vmb
_start_vmb:
        .word   0                       # don't care at this point
        movl    _ROM_r0,r0              # restore R0 for VMB
        movl    _ROM_r1,r1              # restore R1 for VMB
        movl    _ROM_r2,r2              # restore R2 for VMB
        bicl2   $0xfffc0000,r2          # Reduce 32-bit CSR to 18-bit
                                        # CSR that VMB expects

        movl    _ROM_r3,r3              # restore R3 for VMB
        movl    _ROM_r7,r7              # needed for calypso. this
					# restore  the CCA addr into r7.

	clrl	r4			# force bootblock 0
        movl    _ROM_r5,r5              # restore R5 for VMB
        bisl2   $0x10008,r5             # set bootblock mode bit 3 for VMB
                                        # and don't discard CRD pages
        movl    $0x200,sp               # restore sp for VMB
        jmp     *$0x200                 # startup VMB
E 1
