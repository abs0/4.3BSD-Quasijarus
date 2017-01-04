h09491
s 00001/00001/00134
d D 4.30 85/06/08 14:02:00 mckusick 36 35
c Add copyright
e
s 00012/00000/00123
d D 4.29 84/06/27 20:48:26 sam 35 34
c check in for karels -- add generic spl's (asm.sed now defunct)
e
s 00001/00001/00122
d D 4.28 83/12/30 00:46:32 mckusick 34 33
c properly perform spl1() requests
e
s 00002/00001/00121
d D 4.27 83/09/08 21:01:25 mckusick 33 32
c cleanup for ffs (kre)
e
s 00002/00000/00120
d D 4.26 82/10/31 01:04:25 root 32 31
c add ovbcopy
e
s 00001/00000/00119
d D 4.25 82/09/04 09:25:03 root 31 30
c setsoftclock added
e
s 00017/00006/00102
d D 4.24 82/07/15 20:41:28 kre 30 29
c sam: make blkclr() & strlen() operate when len > 64K
e
s 00001/00001/00107
d D 4.23 82/06/25 21:33:40 wnj 29 28
c change splimp to mfpr $18
e
s 00002/00000/00106
d D 4.22 82/06/24 23:43:01 sam 28 27
c define splimp
e
s 00009/00002/00097
d D 4.21 82/04/19 19:37:52 mckusic 27 26
c merge into new file system
e
s 00002/00000/00097
d D 4.20 82/02/27 14:54:18 wnj 26 25
c symbolic links
e
s 00001/00005/00096
d D 4.19 82/01/24 22:56:46 wnj 25 24
c put back like sam had it
e
s 00006/00000/00095
d D 4.18 82/01/24 18:32:29 wnj 24 23
c fix bug in bcmp
e
s 00002/00000/00093
d D 4.17 82/01/17 04:03:13 wnj 23 22
c spl1()
e
s 00006/00001/00087
d D 4.16 81/11/26 11:57:19 wnj 22 21
c before carry to arpavax
e
s 00000/00000/00088
d D 4.15 81/11/18 15:44:40 wnj 21 20
c more cleanup
e
s 00002/00002/00086
d D 4.14 81/11/16 14:20:12 wnj 20 19
c lint
e
s 00002/00000/00086
d D 4.13 81/11/14 16:42:45 wnj 19 18
c before header overlay
e
s 00005/00001/00081
d D 4.12 81/10/29 18:10:12 wnj 18 17
c before inserting beauty header files
e
s 00001/00001/00081
d D 4.11 81/10/18 10:01:57 wnj 17 16
c use movzwl r0,r0 instead of bicl2 (former is shorter!)
e
s 00016/00000/00066
d D 4.10 81/10/16 16:27:53 wnj 16 15
c macros for word/long reversal
e
s 00001/00001/00065
d D 4.9 81/04/15 02:19:38 wnj 15 14
c make spl7() be very high
e
s 00002/00000/00064
d D 4.8 81/03/11 21:50:09 wnj 14 13
c spl4 fixup
e
s 00002/00004/00062
d D 4.7 81/03/09 01:53:14 wnj 13 12
c kill spl1, working ffs
e
s 00007/00002/00059
d D 4.6 81/03/02 22:51:19 wnj 12 11
c ffs
e
s 00001/00001/00060
d D 4.5 81/02/08 18:34:51 wnj 11 10
c first working autoconf version
e
s 00002/00000/00059
d D 4.4 81/02/07 15:42:17 wnj 10 9
c add ffs
e
s 00003/00001/00056
d D 4.3 80/12/26 12:25:48 wnj 9 8
c kludge for spl6()
e
s 00001/00001/00056
d D 4.2 80/12/20 01:28:35 wnj 8 7
c booger spl6() expansion for pk0.c c2 weirdness
e
s 00000/00000/00057
d D 4.1 80/11/09 17:33:34 bill 7 6
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00001/00001/00056
d D 3.6 80/06/07 03:06:20 bill 6 5
c %G%
e
s 00004/00000/00053
d D 3.5 80/05/15 16:28:52 bill 5 4
c restore
e
s 00001/00006/00052
d D 3.4 80/05/09 14:06:42 bill 4 3
c restore version 3.2
e
s 00006/00001/00052
d D 3.3 80/05/09 13:48:28 bill 3 2
c make spl5=>spl6 so can easily use dz SAE
e
s 00001/00001/00052
d D 3.2 80/04/09 22:05:00 bill 2 1
c fix up incorporation of %H% %I% %M%
e
s 00053/00000/00000
d D 3.1 80/04/09 16:16:57 bill 1 0
c date and time created 80/04/09 16:16:57 by bill
e
u
U
t
T
I 1
D 2
s/%H% %I% %M%/%H% %I% %M%/
E 2
I 2
D 6
s,%H% %I% %M%,%H% %I% %M%,
E 6
I 6
D 13
s,%G% %I% %M%,%G% %I% %M%,
E 13
I 13
D 22
s,%E% %I% %M%,%E% %I% %M%,
E 22
I 22
D 36
s,%M% %I% %E%,%M% %I% %E%,
E 36
I 36
s,%W% (Berkeley) %G%,%W% (Berkeley) %G%,
E 36
E 22
E 13
E 6
E 2
s/calls	$0,_spl0/mfpr	$18,r0\
	mtpr	$0,$18/
I 23
s/calls	$0,_spl1/mfpr	$18,r0\
D 34
	mtpr	$0,$18/
E 34
I 34
	mtpr	$1,$18/
I 35
s/calls	$0,_splsoftclock/mfpr	$18,r0\
	mtpr	$0x8,$18/
E 35
E 34
E 23
I 18
s/calls	$0,_splnet/mfpr	$18,r0\
	mtpr	$0xc,$18/
I 28
D 29
s/calls	$0,_splimp/mfpr	$10,r0\
E 29
I 29
s/calls	$0,_splimp/mfpr	$18,r0\
E 29
	mtpr	$0x16,$18/
E 28
E 18
D 13
s/calls	$0,_spl1/mfpr	$18,r0\
	mtpr	$2,$18/
E 13
s/calls	$0,_spl4/mfpr	$18,r0\
	mtpr	$0x14,$18/
I 14
s/calls	r[0-9]*,_spl4/mfpr	$18,r0\
	mtpr	$0x14,$18/
I 35
s/calls	$0,_splbio/mfpr	$18,r0\
	mtpr	$0x15,$18/
s/calls	r[0-9]*,_splbio/mfpr	$18,r0\
	mtpr	$0x15,$18/
s/calls	$0,_spltty/mfpr	$18,r0\
	mtpr	$0x15,$18/
s/calls	r[0-9]*,_spltty/mfpr	$18,r0\
	mtpr	$0x15,$18/
E 35
E 14
I 3
D 4
s/^NOTE!!! - spl5() and spl6() are the same for a reason -- see clock.c//
E 4
E 3
s/calls	$0,_spl5/mfpr	$18,r0\
D 3
	mtpr	$0x15,$18/
E 3
I 3
D 4
	mtpr	$0x18,$18/
E 4
I 4
	mtpr	$0x15,$18/
I 12
s/calls	r[0-9]*,_spl5/mfpr	$18,r0\
	mtpr	$0x15,$18/
I 35
s/calls	$0,_splclock/mfpr	$18,r0\
	mtpr	$0x18,$18/
E 35
E 12
E 4
E 3
D 8
s/calls	$0,_spl6/mfpr	$18,r0\
E 8
I 8
D 9
s/calls	..,_spl6/mfpr	$18,r0\
E 9
I 9
s/calls	$0,_spl6/mfpr	$18,r0\
	mtpr	$0x18,$18/
s/calls	r[0-9]*,_spl6/mfpr	$18,r0\
E 9
E 8
	mtpr	$0x18,$18/
s/calls	$0,_spl7/mfpr	$18,r0\
D 15
	mtpr	$0x18,$18/
E 15
I 15
	mtpr	$0x1f,$18/
E 15
s/calls	$1,_splx/mfpr	$18,r0\
	mtpr	(sp)+,$18/
s/calls	$1,_mfpr/mfpr	(sp)+,r0/
s/calls	$2,_mtpr/mtpr	4(sp),(sp)\
	addl2	$8,sp/
I 31
s/calls	$0,_setsoftclock/mtpr	$0x8,$0x14/
E 31
s/calls	$1,_resume/ashl	$9,(sp)+,r0 \
	movpsl	-(sp) \
	jsb	_Resume/
s/calls	$3,_bcopy/movc3	8(sp),*(sp),*4(sp)\
	addl2	$12,sp/
I 32
s/calls	$3,_ovbcopy/movc3	8(sp),*(sp),*4(sp)\
	addl2	$12,sp/
E 32
I 19
s/calls	$2,_bzero/movc5	$0,(r0),$0,4(sp),*(sp)\
	addl2	$8,sp/
I 24
D 25
s/calls	$3,_bcmp/clrl	r0\
	cmpc3	8(sp),*(sp),*4(sp)\
	beql	1f\
	mnegl	$1,r0\
1:\
E 25
I 25
D 27
s/calls	$3,_bcmp/cmpc3	8(sp),*(sp),*4(sp)\
E 25
	addl2	$12,sp/
E 27
I 27
s/calls	$3,_bcmp/popr	$0x7\
	cmpc3	r2,(r0),(r1)/
E 27
I 26
s/calls	$3,_strncmp/cmpc3	8(sp),*(sp),*4(sp)\
	addl2	$12,sp/
I 27
D 30
s/calls	$2,_blkclr/movc5	$0,(sp),$0,4(sp),*(sp)+\
	addl2	$4,sp/
s/calls	$1,_strlen/movzwl	$65535,r2\
	locc	$0,r2,*(sp)+\
	subl3	r0,r2,r0/
E 30
I 30
s/calls	$2,_blkclr/movl	(sp)+,r3\
	jbr	2f\
1:\
	subl2	r0,(sp)\
	movc5	$0,(r3),$0,r0,(r3)\
2:\
	movzwl	$65535,r0\
	cmpl	(sp),r0\
	jgtr	1b\
	movl	(sp)+,r0\
	movc5	$0,(r3),$0,r0,(r3)/
s/calls	$1,_strlen/movl	(sp),r1\
1:\
	locc	$0,$65535,(r1)\
	jeql	1b\
	subl3	(sp)+,r1,r0/
E 30
s/calls	$4,_scanc/popr	$0xf\
	scanc	r0,(r1),(r2),r3/
E 27
E 26
E 24
E 19
s/calls	$3,_copyin/jsb	_Copyin\
	addl2	$12,sp/
s/calls	$3,_copyout/jsb	_Copyout\
	addl2	$12,sp/
s/calls	$1,_fubyte/movl	(sp)+,r0 \
	jsb	_Fubyte/
s/calls	$1,_fuibyte/movl (sp)+,r0 \
	jsb	_Fubyte/
s/calls	$1,_fuword/movl (sp)+,r0 \
	jsb	_Fuword/
s/calls	$1,_fuiword/movl (sp)+,r0 \
	jsb	_Fuword/
s/calls	$2,_subyte/movl	(sp)+,r0 \
	movl	(sp)+,r1 \
	jsb	_Subyte/
s/calls	$2,_suibyte/movl (sp)+,r0 \
	movl	(sp)+,r1 \
	jsb	_Subyte/
s/calls	$2,_suword/movl (sp)+,r0 \
	movl	(sp)+,r1 \
	jsb	_Suword/
s/calls	$2,_suiword/movl (sp)+,r0 \
	movl	(sp)+,r1 \
	jsb	_Suword/
s/calls	$1,_setrq/movl	(sp)+,r0 \
	jsb	_Setrq/
s/calls	$1,_remrq/movl	(sp)+,r0 \
	jsb	_Remrq/
s/calls	$0,_swtch/movpsl	-(sp)\
	jsb	_Swtch/
I 5
s/calls	$1,_setjmp/movl	(sp)+,r0 \
	jsb	_Setjmp/
s/calls	$1,_longjmp/movl	(sp)+,r0 \
	jsb	_Longjmp/
I 10
D 11
s/calls	$1,_ffs/ffs	$0,$32,(sp)+,r0 \
E 11
I 11
D 12
s/calls	$1,_stupid/ffs	$0,$32,(sp)+,r0 \
E 11
	beql	1f; mnegl $1,r0; 1:/
E 12
I 12
D 13
s/calls	$1,_fumbug/ffs	$0,$32,(sp)+,r0 \
E 13
I 13
D 33
s/calls	$1,_ffs/ffs	$0,$32,(sp)+,r0 \
E 33
I 33
s/calls	$1,_ffs/movl	(sp)+,r1\
	ffs	$0,$32,r1,r0 \
E 33
E 13
	bneq	1f \
	mnegl	$1,r0 \
1: \
	incl	r0/
I 16
s/calls	$1,_htons/rotl	$8,(sp),r0\
	movb	1(sp),r0\
D 17
	bicl2	$~0xffff,r0\
E 17
I 17
	movzwl	r0,r0\
E 17
	addl2	$4,sp/
s/calls	$1,_ntohs/rotl	$8,(sp),r0\
	movb	1(sp),r0\
D 18
	bicl2	$~0xffff,r0\
E 18
I 18
	movzwl	r0,r0\
E 18
	addl2	$4,sp/
s/calls	$1,_htonl/rotl	$-8,(sp),r0\
	insv	r0,$16,$8,r0\
	movb	3(sp),r0\
	addl2	$4,sp/
s/calls	$1,_ntohl/rotl	$-8,(sp),r0\
	insv	r0,$16,$8,r0\
	movb	3(sp),r0\
	addl2	$4,sp/
I 18
D 20
s/calls	$2,_insque/insque	*(sp)+,*(sp)+/
s/calls	$1,_remque/remque	*(sp)+,r0/
E 20
I 20
s/calls	$2,__insque/insque	*(sp)+,*(sp)+/
s/calls	$1,__remque/remque	*(sp)+,r0/
I 22
s/calls	$2,__queue/movl	(sp)+,r0\
	movl	(sp)+,r1\
	insque	r1,*4(r0)/
s/calls	$1,__dequeue/movl	(sp)+,r0\
	remque	*(r0),r0/
E 22
E 20
E 18
E 16
E 12
E 10
E 5
I 3
D 4
s/calls	$1,_setjmp/movl	(sp)+,r0 \
	jsb	_Setjmp/
s/calls	$1,_longjmp/movl	(sp)+,r0 \
	jsb	_Longjmp/
E 4
E 3
E 1
