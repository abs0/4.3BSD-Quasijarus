	.globl	_Xkdbintr0
	.align	2
_Xkdbintr0:
	pushr	$0x3f
	incl	_fltintrcnt+(4*0)
	pushl	$0
	calls	$1,_kdbintr
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
	.asciz	"kdb0"
_eintrnames:

	.globl	_intrcnt

	.globl	_eintrcnt
	.align 2
_intrcnt:
	.space	4 * 13
_fltintrcnt:
	.space	4 * 1
_eintrcnt:

	.text
