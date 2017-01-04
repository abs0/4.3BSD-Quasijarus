h23555
s 00000/00000/00021
d D 2.1 84/02/08 20:29:29 aoki 6 5
c synchronize to version 2
e
s 00007/00000/00014
d D 1.4 81/01/26 17:02:32 mckusic 5 3
c change RV8, LRV8, and IND8 to use `struct' instead of `double' assignment
e
s 00001/00000/00014
d R 1.4 81/01/24 15:08:36 mckusic 4 3
c change "movd" instructions to "movq" to avoid `normalizing' records
e
s 00002/00000/00012
d D 1.3 81/01/10 18:25:02 mckusic 3 2
c add "ap" and "fp" notion, fix SUCC and PRED
e
s 00001/00001/00011
d D 1.2 81/01/07 20:33:36 mckusic 2 1
c fix sccs header
e
s 00012/00000/00000
d D 1.1 81/01/07 16:55:29 mckusick 1 0
c date and time created 81/01/07 16:55:29 by mckusick
e
u
U
t
T
I 1
D 2
s/"%Z%%M% %I% %G%"/&/
E 2
I 2
s,"%Z%%M% %I% %G%",&,
I 5
s/calls.\$0,_setup/.data\
	.align 2\
	.comm Ll1,8\
	.text/
E 5
E 2
s/calls.\$1,_push2/movw	(sp)+,(sp)/
/calls.\$1,_push4/d
/calls.\$2,_push8/d
I 5
/calls.\$2,_pushsze8/d
E 5
s/calls.\$1,_pushsp/subl2	(sp)+,sp\
	movl	sp,r0/
s/calls.\$0,_pop2/cvtwl	(sp)+,r0/
s/calls.\$0,_pop4/movl	(sp)+,r0/
s/calls.\$0,_pop8/movq	(sp)+,r0/
I 5
s/calls.\$0,_popsze8/movq	(sp)+,Ll1\
	movaq	Ll1,r0/
E 5
s/calls.\$1,_popsp/addl2	(sp)+,sp/
I 3
s/calls.\$0,_enableovrflo/bispsw	$0xe0/
s/calls.\$0,_disableovrflo/bicpsw	$0xe0/
E 3
s/*-4(fp)/(r11)/
s/-4(fp)/r11/
E 1
