h40802
s 00000/00000/00016
d D 4.1 82/05/12 11:13:57 rrh 2 1
c sync to release 4.1
e
s 00016/00000/00000
d D 1.1 82/05/12 11:03:21 rrh 1 0
c date and time created 82/05/12 11:03:21 by rrh
e
u
U
t
T
I 1
.data 0
	.asciz "	%M%	%I%	%E%	"
.text 0
	.set MEMSIZ,0x10000
	.text
	.globl _longspace
	.globl _shortspace
	.globl _bytespace
# set aside pdp11 memory space in nonprotected text segment at loc 0
_longspace:
_shortspace:
_bytespace:
	.space MEMSIZ
# put the memory size in a global variable for other uses
	.globl _memsiz
_memsiz:.long _memsiz
E 1
