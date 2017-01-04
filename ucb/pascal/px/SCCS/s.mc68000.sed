h61327
s 00000/00000/00024
d D 2.1 84/02/08 20:29:33 aoki 3 2
c synchronize to version 2
e
s 00004/00002/00020
d D 1.2 83/01/22 01:08:41 mckusick 2 1
c fix-ups...
e
s 00022/00000/00000
d D 1.1 83/01/12 15:12:03 mckusick 1 0
c date and time created 83/01/12 15:12:03 by mckusick
e
u
U
t
T
I 1
s,"%Z%%M% %I% %G%",&,
s/jbsr._setup/.bss\
	.even\
D 2
Xl1:	.skip	4\
E 2
I 2
Xl1:	.skip	8\
E 2
	.text/
s/jbsr._push2/subql	#2,sp/
s/jbsr._push4/subql	#4,sp/
s/jbsr._push8/subql	#8,sp/
s/jbsr._pushsze8/subql	#8,sp/
s/jbsr._pushsp/subl	sp@,sp\
D 2
	movl	sp,d0/
E 2
I 2
	movl	sp,d0\
	addql	#4,d0\
	tstb	sp@(-100)/
E 2
s/jbsr._pop2/movw	sp@+,d0\
	extl	d0/
s/jbsr._pop4/movl	sp@+,d0/
s/jbsr._pop8/movl	sp@+,d0\
	movl	sp@+,d1/
s/jbsr._popsze8/movl	sp@+,Xl1\
	movl	sp@+,Xl1+4\
	movl	#Xl1,d0/
s/jbsr._popsp/addl	sp@,sp/
/jbsr._enableovrflo/d
/jbsr._disableovrflo/d
E 1
