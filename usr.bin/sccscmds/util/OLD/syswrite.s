# C library -- syswrite

# nwritten = syswrite(file, buffer, count);
#
# nwritten == -1 means error

	.set	syswrite,4
.globl	_syswrite
.globl  cerror

_syswrite:
	.word	0x0000
	chmk	$syswrite
	bcc 	noerror
	jmp 	cerror
noerror:
	ret
