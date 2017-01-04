h24754
s 00146/00000/00000
d D 7.1 04/03/01 15:06:30 msokolov 1 0
c date and time created 04/03/01 15:06:30 by msokolov
e
u
U
t
T
I 1
/*
 * VAX tape boot block for distribution tapes
 * for booting the distribution tape on MicroVAXen and via VMB.EXE
 *
 *	%W% (Berkeley) %G%
 */

#include "vmb.h"

/*
 * All other tape bootblocks display the '=' prompt, get the name of the
 * standalone program to load, load the program from the tape, and run it (and
 * repeat the process if the program returns).  We do it differently for VMB
 * booting: we run a special program included in the tp archive called tpdisp
 * that performs those functions for us instead.  tpdisp is built with the full
 * standalone system framework.  We have relegated most of our work to tpdisp
 * because we want the following functionality from the full standalone system
 * framework:
 *
 * o The magic in decsrt0.c to capture VMB and make it available to the UNIX
 *   standalone system.
 *
 * o Full cpuid logic and support for alternate consoles for machines without
 *   standard VAX console IPRs.
 *
 * o tpdisp's decsrt0.c sets up a working SCB that the rest of the standalone
 *   system can use until full boot.
 *
 * This bootblock supports both VMB.EXE and MicroVAX VMB booting, but is
 * optimised for MicroVAX VMB.  MicroVAX VMB loads the entire first tape file
 * before we gain control, so we don't need to read the tape to load tpdisp,
 * it's already in memory.  We just need to find it using the tp directory
 * (which is also already in memory) and jump to it.  We don't even need to move
 * it since it relocates itself to its working location from any starting
 * location.
 *
 * VMB.EXE on the other hand loads only the first block.  Rather than write a
 * different code path that reads the tp directory, skips to the tpdisp file
 * and reads the file, I have taken the simpler approach to just read the rest
 * of the first tape file and fall into the MicroVAX VMB code path.  This is
 * effectively an optimisation for the more commonly needed MicroVAX booting.
 *
 * Since the entire first tape file is always loaded before tpdisp is run,
 * tpdisp can be placed anywhere in the tp archive without making it any faster.
 * We normally put it at the end so that other things which can make better use
 * of being first get the advantage.
 *
 * We do not support the entry point at offset 0C for 750/8200-style boot ROMs.
 * 750 and 8200 boot ROMs do not boot tapes, but this mechanism is apparently
 * used on VAX 6000 for the "console" TK70.  I don't fully understand how it
 * works, and in any case we have no VAX 6000 support at all right now.  We will
 * deal with this when we get to supporting VAX 6000.
 */

	.set	BNUM,44		/* tp dir offset for start block no. */
	.set	ENTSIZ,64	/* size of 1 TP dir entry, bytes */
	.set	DIRSTART,1	/* start block of directory in the archive */
	.set	NUMDIR,24	/* no. of dir blocks on tape */
	.set	ENTBLK,8	/* no. of dir entries per tape block */
	.set	NBOOTBLKS,7	/* # of boot blocks before tp archive */

	.text
start:

/*
 * MicroVAX VMB TAPE BOOT ENTRY
 */
/*00*/	brb	mvax_start

/* 
 * VMB.EXE ENTRY
 */
/*02*/	brb	vmb_start

/*04*/	.long	0
/*08*/	.long	0

/*
 * 11/750 STYLE ROM ENTRY not supported
 */
/*0c*/	halt; halt

/*
 * VMB MODE Boots have the following inputs
 *	
 *	r10 = base address of secondary bootstrap
 *	r11 = physical address of base of RPB
 *	AP  = physical address of the VMB ARG list
 *	SP  = current stack pointer (physical)
 *	PR$_SCBB = physical address of SCB
 */
vmb_start:
	movl	RPB$L_IOVEC(r11),r7	# Compute address of bootdriver
	addl2	BQO$L_QIO(r7),r7
	moval	start+0x200,r5		# start right after ourselves
1:	pushl	r11			# Push address of RPB
	pushl	$PHYSMODE		# Physical read mode
	pushl	$IO$_READLBLK		# Read logical block function
	pushl	$0			# block number (ignored for tape)
	pushl	$0x200			# one block at a time
	pushl	r5			# Address of buffer
	calls	$6,(r7)			# Call bootstrap QIO routine
	addl2	$0x200,r5		# advance ptr
	blbs	r0,1b			# keep reading if OK
	cmpw	r0,$SS$_ENDOFFILE	# stop at end of tape file
	beql	mvax_start		# fall into MicroVAX code path when done
	halt				# Halt on I/O error

mvax_start:
/*
 * At this point we are booted via VMB (either kind) and the entire first tape
 * file is in memory contiguous with us.  Find tpdisp in the tp directory.
 */
	addl3	$(NBOOTBLKS+DIRSTART)*BLKSIZ,r10,r5
	clrl	r6
1:	movl	r5,r0
	moval	tpdisp,r1
2:	movb	(r1)+,r2
	cmpb	(r0)+,r2
	jneq	3f
	tstb	r2
	jneq	2b
	jbr	4f			# found it
3:	addl2	$ENTSIZ,r5
	jaoblss	$ENTBLK*NUMDIR,r6,1b
	halt				# not found
4:	movzwl	BNUM(r5),r0
	addl2	$NBOOTBLKS,r0
	ashl	$9,r0,r0		# from blocks to bytes
	addl2	r10,r0
/*
 * R0 now points to the tpdisp program.  We invoke it with calls using the same
 * convention as used between decboot and bootdec.  But first flush the I-stream
 * with REI just to be safe.
 */
	movpsl	-(sp)
	pushal	1f
	rei
1:	pushl	ap			# pass the address of the VMB arglist
	pushl	r11			# RPB is pointed to by r11
	pushl	$TK50_BOOT|VMB_BOOT	# Tell the next image how to boot
	calls	$3,4(r0)		# Call the startup code
	halt				# Die

	.data
tpdisp:	.asciz	"tpdisp"
E 1
