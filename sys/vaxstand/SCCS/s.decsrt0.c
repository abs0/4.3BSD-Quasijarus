h01501
s 00002/00000/00296
d D 7.2 04/02/07 18:57:16 msokolov 2 1
c oops, missed .globl for _bootdev and _boothowto
e
s 00296/00000/00000
d D 7.1 04/02/07 13:18:37 msokolov 1 0
c date and time created 04/02/07 13:18:37 by msokolov
e
u
U
t
T
I 1
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

#define	LOCORE
#include "../vax/cpu.h"
#include "../vax/mtpr.h"
#include "../mdec/vmb.h"

/*
 * Startup code for standalone system
 * DEC entry version -- bootstraps UNIX world from DEC world
 */

	.globl	_end
	.globl	_edata
	.globl	_main
	.globl	__rtt
	.globl	_openfirst
I 2
	.globl	_boothowto
	.globl	_bootdev
E 2
	.globl	_ROM_r0
	.globl	_ROM_r1
	.globl	_ROM_r2
	.globl	_ROM_r3
	.globl	_ROM_r4
	.globl	_ROM_r5
	.globl	_ROM_r6
	.globl	_ROM_r7
	.globl	_ROM_fp

	.comm	_cpu,4
	.comm	_cpusid,4
	.comm	_cpusie,4
	.comm	_mode,4
	.comm	_vmb_info,4

	.set	HIGH,31		# mask for total disable

	.globl	entry
entry:	.long	0			# cannot be started at 0 or 2
	.word	0x00FF			# entry mask for calls entry at 4
	mtpr	$HIGH,$IPL		# just in case
	movl	$RELOC,sp
start:
	/*
	 * `entry' below generates a pc-relative reference to the
	 * code, so this works no matter where we are now.
	 * Clear bss segment *after* moving text and data.
	 */
	movc3	aedata,entry,(sp)
dclr:
	clrl	(r3)+
	cmpl	r3,$_end
	jlss	dclr
	jmp	*abegin
begin:
	addl3	$_end,$0x1FF,r0
	bicl2	$0x1FF,r0
	pushl	r0
	calls	$1,_setupscb
	calls	$0,_cpuid
/*
 * Functional Discription:
 *	This is the entry point for the boot and loader paths.  It is
 *	called from the decboot and tpdecboot bootblocks.
 *
 * STANDARD BOOT PATH,
 *	
 *	The bootblock calls _entry with:
 *
 * Inputs:
 *       4(ap) = mode of boot, VMB_BOOT, ROM_BOOT, TK50_BOOT
 *
 *    The next two args only if VMB mode boot:
 *       8(ap) = Address of VMB's RPB
 *      12(ap) = Address of VMB's argument list
 */
	movl    4(ap),_mode             # save the boot mode
	bitl    $ROM_BOOT,_mode         # were we booted via system ROMs
	jneq    rom_mode		# if so, proceed with ROM mode boot
/*
 * Branch here when booted via VMB.EXE.  Much initialization occurs here.
 * Information is save at the top of memory on an information stack.
 * A vmbinfo list is build which is passed through to main and
 * eventually to the kernel.
 */
vmb_mode:
        movl    8(ap),r11               # get the address of the RPB
        clrb    RPB$T_FILE(r11)         # clear the file name byte count
                                        # so the DIAG SUPER knows it's Ultrix
	moval	tmpinfo,r8		# initialize pointer
        /*
         * Size memory
         */
        movl    12(ap),r9		# get VMB's arg list
        cmpw    $VMB$Q_PFNMAP/4,VMB$L_ARGBYTCNT(r9)
                                        # is the extended map arg present?
        bgtr    1f                      # Branch if not
        movq    VMB$Q_PFNMAP(r9),RPB$Q_PFNMAP(r11)
                                        # otherwise, update the RPB
1:
        movl    RPB$Q_PFNMAP+4(r11),r6  # get the address of the PFNMAP
        movl    RPB$Q_PFNMAP(r11),r7    # get its size 
        clrl    r9                      # init good page counter
3:      cmpb    (r6)+,$0xff             # is it 8 good pages ?
        bneq    1f                      # if not we're done
        addl2   $8,r9                   # 8 more good pages
        sobgtr  r7,3b                   # is this the end?
1:      
        ashl    $9,r9,INFO_MEMSIZ(r8)	# convert from pages and save
#define MEMSIZEADDR     0xf0000         /* Backward compatability on MVAX */
#define MAXMEMSIZE	1024*1024*512
#define BISPACE		(1024*1024)/2
        ashl    $9,r9,*$MEMSIZEADDR     # convert from pages

#ifdef notdef
	/*
	 * Ultrix V4.2 does the kludge below.  I don't understand why it is
	 * needed.  I will not uncomment this code until/unless someone
	 * explains to me why it is necessary.  What it being trashed, how,
	 * and why?
	 */

	/* 
	 * check if >511.5Mb of memory present.  If yes, back off to 511.5Mb to
	 * prevent trashing of common data. 
	 */
	cmpl	INFO_MEMSIZ(r8),$MAXMEMSIZE-BISPACE
	blssu	1f			# is mem size less than or eq to 511.5?

	movl	$MAXMEMSIZE-BISPACE,INFO_MEMSIZ(r8)	# reload total memory
	movl	$MAXMEMSIZE-BISPACE,*$MEMSIZEADDR	# ditto.
1:
#endif

        /*
         * set the info stack pointer (isp) to the top of memory.
         */
        movl    INFO_MEMSIZ(r8),isp 	# set isp to the top of memory
        /*
         * save the BOOT DRIVER
         */
        pushl   RPB$L_IOVEC(r11)        # push the address of the boot driver
        pushl   RPB$L_IOVECSZ(r11)      # push its size
        calls   $2,move_info            # move it
        movl    r0,INFO_BTDRBAS(r8)	# save its address
        movl    RPB$L_IOVECSZ(r11),INFO_BTDRSIZ(r8)
                                        # save its size
        /*
         * save the RPB
         */
        pushl   r11                     # push the address of the RPB
        pushl   $RPBSIZ                 # push its size
        calls   $2,move_info            # move it
        movl    r0,INFO_RPBBAS(r8)	# save its address
        movl    $RPBSIZ,INFO_RPBSIZ(r8)	# save its size
        movl    INFO_RPBBAS(r8),r11	# point to the moved RPB
        movl    INFO_BTDRBAS(r8),RPB$L_IOVEC(r11)
                                        # reset new RPB$L_IOVEC
        /*
         * Save the Arg list
         */
        movl    12(ap),r9              	# get the address passed
	ashl	$2,(r9),r10             # make arg count a bytecount
        addl3   $4,r10,r10              # Add 4 to include arg count itself
        pushl   r9                      # push address of VMB ARGLIST
        pushl   r10                     # push its size
        calls   $2,move_info            # move it
        movl    r0,INFO_VMBARGBAS(r8)	# save its address
	movl	r0,r9			# update r9 as a pointer to the
					# new location
        movl    r10,INFO_VMBARGSIZ(r8)	# save its size

	/*
	 * save VMB's version number
	 */
        movl    RPB$L_IOVEC(r11),r10    # point to the boot driver
	movzwl	BQO$W_VERSION(r10),INFO_VMBVERS(r8)
					# save VMB's version number
        /*
         * When booting a CI, a system page table is built after the 
         * end of the ucode, so space must be reserved.
         */
        cmpb    $BTD$K_HSCCI,RPB$B_DEVTYP(r11) # are we booting a CI/HSC?
        beql    1f                      # if so, allow for SPT
        cmpb    $BTD$K_BVPSSP,RPB$B_DEVTYP(r11) # are we booting an AIO?
        beql    1f                      # if so, allow for SPT
        cmpb    $BTD$K_AIE_TK50,RPB$B_DEVTYP(r11) # are we booting an AIE/TK50?
        beql    1f                      # if so, allow for SPT
	brb	2f			# if neither, then skip ahead
1:

	ashl	$2,VMB$L_HI_PFN(r9),r0 # How many bytes
        subl2   r0,isp                  # adjust the info stack pointer
	movl	isp,VMB$L_BVP_PGTBL(r9)	# BVP init routines look here
2:
        /*
         * Save the ucode - check the VMBARG List
         */
        tstl    VMB$Q_UCODE+4(r9)       # is there any ucode?
        beql    3f                      # if not, skip ahead
        pushl   VMB$Q_UCODE+4(r9)       # push its address
        pushl   VMB$Q_UCODE(r9)         # push its size
        calls   $2,move_info            # move it
        movl    r0,INFO_CIUCODBAS(r8)	# save its address
        movl    VMB$Q_UCODE(r9),INFO_CIUCODSIZ(r8)
                                        # save its size
        movl    r0,BQO$L_UCODE(r10)     # update the driver ucode pointer
        movl    INFO_VMBARGBAS(r8),r9	# get the new address of the arg list
        movl    r0,VMB$Q_UCODE+4(r9)    # point the vmbarglst at the ucode
3:
        /*
         * The vmb information list is built, now move it in front of
         * all the stuff saved.
         */
        clrl    -(sp)                   # request 1k align (by passing 3 args)
        pushal  tmpinfo                 # push the address
        pushl   $INFO_SIZE              # push its size
        calls   $3,move_info            # move it
	movl	r0,_vmb_info		# save address in the global location 
again:
	movl	$1,_openfirst
	calls	$0,_main
	jbr	again
/*
 * Branch here when booted via 750/8200 style boot ROMs.  Save the contents
 * of the GPR's as given to the bootblock.  They will eventually be
 * passed on to VMB.EXE.
 */
rom_mode:
	/*
	 * Save original ROM input parameters
	 */
	movc3	$20,20(fp),_ROM_r0
	movl	12(fp),_ROM_fp
	jbr	again

	.data
abegin:	.long	begin
aedata:	.long	_edata-RELOC
_bootdev:	.long	0
_boothowto:	.long	0
tmpinfo:                                # used to build vmb info list
        .space INFO_SIZE    		# a tmp work area needed to
					# build the vmbinfo list before
					# saving it too.
isp:	.long	0			# information stack pointer
_ROM_r0: .long	0
_ROM_r1: .long	0
_ROM_r2: .long	0
_ROM_r3: .long	0
_ROM_r4: .long	0
_ROM_r5: .long	0
_ROM_r6: .long	0
_ROM_r7: .long	0
_ROM_fp: .long	0

	.text
__rtt:
	.word	0x0
	halt

/*
 * Functional Discription:
 *	This routine builds a stack of information to be passed 
 *	through to the kernel.  The stack is built at the top of
 *	the contiguous portion of main memory.
 *
 *      The final call to move_info must force alignment on a 1k 
 *      boundary for consistency with kernel cmap structuring.
 *      Intermediate calls need only force page alignment.
 *
 * Inputs:
 *	4(ap) = size to be saved
 *	8(ap) = starting address of info to be saved
 *	[12(ap)] optional, forces 1k boundary alignment
 *
 * Outputs:
 *	address where information was stored
 *
 */
        .text
move_info:
	.word	0x1e                    # save r1 - r5
	subl2   4(ap),isp               # move the info stack down as needed
	movzwl  $0x1ff,r0               # assume page alignment
	cmpb    $3,(ap)                 # third arg present, 1k align requested
	bneq    1f                      # if not, skip ahead
	movzwl  $0x3ff,r0               # 1k alignment requested
1:	bicl2   r0,isp                  # align accordingly
	movc3   4(ap),*8(ap),*isp       # move information
	movl    isp,r0                  # address it was moved to
	ret                             # return
E 1
