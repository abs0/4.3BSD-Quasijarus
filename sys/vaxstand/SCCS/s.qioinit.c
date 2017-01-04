h52714
s 00072/00000/00000
d D 7.1 04/02/07 14:15:56 msokolov 1 0
c date and time created 04/02/07 14:15:56 by msokolov
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
 */

#define LOCORE
#include "../vax/mtpr.h"
#include "../mdec/vmb.h"

	.comm	_qioentry,4
	.lcomm	kludge,4

/*
 * Functional Discription:
 *	This routine is called to initialize the selected boot device.
 *	If no arg is passed, the current drive is initialized.
 *
 * Inputs:
 *	OPTIONAL:
 *	4(ap) = new unit number
 *
 * Outputs:
 *	status returned from the init routine
 *		or
 *	1 for devices which do not have an init routine
 *
 */
	.text
	.globl	_qioinit
_qioinit:
        .word   0x3c0                   # save R6 - R9
        movl    _vmb_info,r8     	# get the info structure
        movl    INFO_RPBBAS(r8),r9      # required by init routines
        tstb    (ap)                    # any args passed (new unit)
        beql    1f                      # no, skip ahead
        movw    4(ap),RPB$W_UNIT(r9)    # plug in a new unit number
        movzwl  4(ap),RPB$L_BOOTR3(r9)  # plug in a new unit number
1:	movl    RPB$L_IOVEC(r9),r7      # move RPB$L_IOVEC to r0
        addl3   r7,BQO$L_QIO(r7),_qioentry # Compute address of QIO routine
        movzbl  $1,r0                   # assume success
        tstl    BQO$L_UNIT_INIT(r7)     # is there an init routine?
        beql    4f                      # if not go on
        addl3   r7,BQO$L_UNIT_INIT(r7),r6 # figure its entry point
/*
 * KLUDGE (for [T]MSCP controller types) to force total controller 
 * initialization, otherwise we wait an awful long time for 
 * initialization to complete.
 */
#define IP      0
#define SA      2
        tstb    kludge                  # have we done this once?
        bneq    2f                      # if so, skip it to save time
        cmpb    $BTD$K_UDA,RPB$B_DEVTYP(r9) # is this a uda/qda/kda?
        beql    1f                      # yes, go hit it
        cmpb    $BTD$K_TK50,RPB$B_DEVTYP(r9) # is this a TK50 controller?
        beql    1f                      # yes, go hit it
        brb     2f                      # proceed with normal init
1:
        movl    RPB$L_CSRPHY(r9),r7     # get the IP register address
        clrw    IP(r7)                  # poke it to make it step
1:
        movw    SA(r7),r0               # get the status registe
        bitw    $0xfe00,SA(r7)          # is something active?
        beql    1b                      # if not, wait until there is
        incb    kludge                  # mark it done
/*
 * END OF KLUDGE
 */
2:
        mfpr    $SCBB,r7                # required by BDA driver
        callg   *INFO_VMBARGBAS(r8),(r6) # do it
4:
        ret                             # r0 = status
E 1
