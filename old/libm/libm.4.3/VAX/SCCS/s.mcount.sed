h16145
s 00007/00000/00000
d D 1.1 85/05/23 17:08:16 miriam 1 0
c date and time created 85/05/23 17:08:16 by miriam
e
u
U
t
From Prof. Kahan at UC at Berkeley
T
I 1
s/.word	0x0.*$/&\
	.data\
1:\
	.long	0\
	.text\
	moval	1b,r0\
	jsb	mcount/
E 1
