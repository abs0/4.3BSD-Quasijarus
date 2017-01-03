#old = sbrk(increment);
#
#sbrk gets increment more core, and returns a pointer
#	to the beginning of the new core area
#
	.set	break,17
.globl	_sbrk
.globl _end
.globl  cerror

_sbrk:
	.word	0x0000
	pushl	nd
	addl3	nd,4(ap),-(sp)
	calls	$1,_brk
	tstl	r0
	beql	sbrkok
	jmp	cerror
sbrkok:	movl	(sp)+,r0
	ret

.globl	_brk
# brk(value)
# as described in man2.
# returns 0 for ok, -1 for error.

_brk:
	.word	0x0000
	chmk	$break
	bcc 	noerr2
	jmp 	cerror
noerr2:
	movl	4(ap),nd
	clrl	r0
	ret

	.data
nd:	.long	_end
