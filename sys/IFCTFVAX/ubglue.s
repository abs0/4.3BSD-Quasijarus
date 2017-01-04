	.globl	_Xtmscpintr0
	.align	2
_Xtmscpintr0:
	pushr	$0x3f
	incl	_fltintrcnt+(4*0)
	pushl	$0
	calls	$1,_tmscpintr
	popr	$0x3f
	incl	_cnt+V_INTR
	rei

	.globl	_Xudaintr0
	.align	2
_Xudaintr0:
	pushr	$0x3f
	incl	_fltintrcnt+(4*1)
	pushl	$0
	calls	$1,_udaintr
	popr	$0x3f
	incl	_cnt+V_INTR
	rei

	.globl	_Xqeintr0
	.align	2
_Xqeintr0:
	pushr	$0x3f
	incl	_fltintrcnt+(4*2)
	pushl	$0
	calls	$1,_qeintr
	popr	$0x3f
	incl	_cnt+V_INTR
	rei


	.globl	_intrnames

	.globl	_eintrnames
	.data
_intrnames:
	.asciz	"clock"
	.asciz	"cnr"
	.asciz	"cnx"
	.asciz	"tur"
	.asciz	"tux"
	.asciz	"mba0"
	.asciz	"mba1"
	.asciz	"mba2"
	.asciz	"mba3"
	.asciz	"uba0"
	.asciz	"uba1"
	.asciz	"uba2"
	.asciz	"uba3"
	.asciz	"tmscp0"
	.asciz	"uda0"
	.asciz	"qe0"
_eintrnames:

	.globl	_intrcnt

	.globl	_eintrcnt
	.align 2
_intrcnt:
	.space	4 * 13
_fltintrcnt:
	.space	4 * 3
_eintrcnt:

	.text
