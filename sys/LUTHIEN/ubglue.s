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

	.globl	_Xdsvintr0
	.align	2
_Xdsvintr0:
	pushr	$0x3f
	incl	_fltintrcnt+(4*3)
	pushl	$0
	calls	$1,_dsvintr
	popr	$0x3f
	incl	_cnt+V_INTR
	rei

	.globl	_Xdzrint0
	.align	2
_Xdzrint0:
	pushr	$0x3f
	incl	_fltintrcnt+(4*4)
	pushl	$0
	calls	$1,_dzrint
	popr	$0x3f
	incl	_cnt+V_INTR
	rei

	.globl	_Xdzxint0
	.align	2
_Xdzxint0:
	pushr	$0x3f
	incl	_fltintrcnt+(4*5)
	movl	$0,r0
	jmp	dzdma


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
	.asciz	"dsv0"
	.asciz	"dzr0"
	.asciz	"dzx0"
_eintrnames:

	.globl	_intrcnt

	.globl	_eintrcnt
	.align 2
_intrcnt:
	.space	4 * 13
_fltintrcnt:
	.space	4 * 6
_eintrcnt:

	.text
