h55814
s 00011/00001/00090
d D 4.2 85/06/07 21:40:36 miriam 6 5
m 
c Add copyright
e
s 00000/00000/00091
d D 4.1 83/07/25 19:42:48 eric 5 4
m 
c 4.2 release version
e
s 00000/00000/00091
d D 3.1 81/03/07 14:25:15 eric 4 3
c ----- delivermail ==> postbox -----
e
s 00000/00000/00091
d D 2.1 80/11/05 11:00:20 eric 3 2
c release 2
e
s 00002/00000/00089
d D 1.2 80/07/25 22:02:41 eric 2 1
c add ID keywords
e
s 00089/00000/00000
d D 1.1 80/06/23 08:23:22 eric 1 0
e
u
U
f b 
f i 
t
T
I 1
/
I 6
/  Sendmail
/  Copyright (c) 1983  Eric P. Allman
/  Berkeley, California
/
/  Copyright (c) 1983 Regents of the University of California.
/  All rights reserved.  The Berkeley software License Agreement
/  specifies the terms and conditions for redistribution.
/
/	%W% (Berkeley) %G%
/
/
E 6
/  BMOVE -- block move
/
I 2
D 6
/	%W%	%G%
E 6
/
E 2
/	This is a highly optimized version of the old C-language
/	bmove routine; it's function (should be) identical.
/	It uses a fancy algorithm to move words instead of bytes
/	whenever possible.
/
/	In C the routine is:
/		char *bmove(a, b, l)
/		char	*a, *b;
/		int	l;
/		{
/			register int	n;
/			register char	*p, *q;
/			p = a;
/			q = b;
/			n = l;
/			while (n--)
/				*q++ = *p++;
/			return (q);
/		}
/
/	Parameters:
/		a [4(sp)] -- source area
/		b [6(sp)] -- target area
/		l [10(sp)] -- byte count
/
/	Returns:
/		Pointer to end of target area.
/
/	History:
/		3/14/79 [rse] -- added odd to odd case
/		2/9/78 [bob] -- converted from "C"
/
/

.globl	_bmove

_bmove:
	mov	r2,-(sp)	/ save r2
	mov	4(sp),r1	/ get src address
	mov	6(sp),r0	/ get dst address

	/ determine whether to use word or byte move
	mov	r0,r2		/ r2 will reflect the three cases
	bic	$177776,r2	/ keep only last bit of dst
	ror	4(sp)		/ get least significant bit of src
	adc	r2		/ add it in.
	beq	wordm		/ both on even boundary
	dec	r2		/ check for odd case
	bgt	wordodd		/ both on odd boundary

	mov	10(sp),r2	/ get count
	beq	done
bytem:
	movb	(r1)+,(r0)+	/ copy next byte
	sob	r2,bytem	/ branch until done
	br	done

wordm:
	mov	10(sp),r2	/ get count
wordt:
	beq	done
	asr	r2		/ get word count
	bcs	odd		/ count was odd
even:
	mov	(r1)+,(r0)+	/ copy word
	sob	r2,even		/ more to do if non-zero
	br	done

wordodd:
	mov	10(sp),r2	/ get count
	beq	done
	movb	(r1)+,(r0)+	/ copy byte
	dec	r2		/ dec count
	br	wordt		/ now treat as an even word move

odd:
	beq	odd2		/ special case of count = 1
odd1:
	mov	(r1)+,(r0)+	/ copy word
	sob	r2,odd1		/ continue
odd2:
	movb	(r1)+,(r0)+	/ count was odd. do last one

done:
	mov	(sp)+,r2	/ restore r2
	rts	pc		/ return
E 1
