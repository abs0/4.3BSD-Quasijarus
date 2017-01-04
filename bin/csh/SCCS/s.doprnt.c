h32198
s 00011/00006/00667
d D 5.5 88/06/18 13:14:40 bostic 6 5
c install approved copyright notice
e
s 00638/00451/00034
d D 5.4 88/06/05 10:48:11 bostic 5 4
c C version of doprnt from the C library, minor whacks
e
s 00004/00000/00481
d D 5.3 87/06/05 11:58:39 bostic 4 3
c ifdef'd for vax
e
s 00003/00003/00478
d D 5.2 85/06/06 13:09:05 edward 3 2
c cleaning up after bozos
e
s 00009/00001/00472
d D 5.1 85/06/04 11:14:05 dist 2 1
c Add copyright
e
s 00473/00000/00000
d D 4.1 80/10/09 12:39:58 bill 1 0
c date and time created 80/10/09 12:39:58 by bill
e
u
U
t
T
I 1
D 2
/* static char *sccsid = "%Z%%M% %I% %G%"; */
E 2
I 2
/*
D 5
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
E 3
I 3
 * All rights reserved.  The Berkeley Software License Agreement
E 3
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 6
E 5
 */

I 4
D 5
#ifdef vax

E 5
E 4
#ifndef lint
D 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3
I 3
D 5
	.ascii	"%W% (Berkeley) %G%"
E 5
I 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
D 6
#endif
E 6
I 6
#endif /* not lint */
E 6
E 3
E 2

D 5
	# C library -- conversions
E 5
I 5
#ifdef notdef
static char sccsid[] = "@(#)doprnt.c	5.32 (Berkeley) 6/3/88";
#endif
E 5

D 5
.globl	__doprnt
.globl	__strout
E 5
I 5
#include <sys/types.h>
#include <varargs.h>
#include <stdio.h>
#include <ctype.h>
E 5

D 5
#define flags r10
#define literb 0
#define liter 1
#define ndfndb 0
#define ndfnd 1
#define ljustb 1
#define ljust 2
#define zfillb 2
#define zfill 4
#define precb 3
#define prec 8
#define psignb 4
#define psign 16
#define gflagb 5
#define gflag 32
#define width r9
#define ndigit r8
#define fdesc -4(fp)
#define exp -8(fp)
#define sign -9(fp)
	.set one,010			# 1.0 in floating immediate
	.set ch.zer,'0			# cpp doesn't like single appostrophes
E 5
I 5
/* 11-bit exponent (VAX G floating point) is 308 decimal digits */
#define	MAXEXP		308
/* 128 bit fraction takes up 39 decimal digits; max reasonable precision */
#define	MAXFRACT	39
E 5

D 5
	.align	1
__doprnt:
	.word	0xfc0			# uses r11-r6
	subl2 $128,sp
	movl 4(ap),r11			# addr of format string
	movl 12(ap),fdesc		# output FILE ptr
	movl 8(ap),ap			# addr of first arg
loop:
	movl r11,r0			# current point in format
	bicl2 $liter,flags		# no literal characters yet
L1:	movb (r11)+,width		# next character of format
	beql L2				# end of format string
	cmpb width,$'%
	beql L2				# warning character
	bisl2 $liter,flags		# literal character
	jbr L1
L2:	blbc flags,L3			# bbc $literb,flags,L3 # no literals in format
	pushl fdesc			# file pointer
	pushl $0			# no left/right adjust
	pushl r0			# addr
	subl3 r0,r11,r1			# length
	subl3 $1,r1,-(sp)		# % or null not part of literal
	calls $4,__strout		# dump the literal
L3:
	blbs width,L4			# % is odd; end of format?
	ret				# yes
E 5
I 5
#define	DEFPREC		6
E 5

D 5
	# htab overlaps last 16 characters of ftab
ftab:	.byte	 0, 0, 0,'c,'d,'e,'f,'g, 0, 0, 0,'+,'l,'-,'.,'o
htab:	.byte	'0,'1,'2,'3,'4,'5,'6,'7,'8,'9,'a,'b,'c,'d,'e,'f
E 5
I 5
#define	BUF		(MAXEXP+MAXFRACT+1)	/* + decimal point */
E 5

D 5
L4:	movl sp,r5			# reset output buffer pointer
	clrq r9				# width; flags ljustb,ndfndb,zfillb
L4a:	movzbl (r11)+,r0		# supposed format
	extzv $0,$5,r0,r1		 # bottom 5 bits
L4b:	cmpb r0,ftab[r1]		# good enough?
	jneq L6				# no
L4c:	casel r1,$3,$22			# yes
L5:	.word charac-L5			# c
	.word decimal-L5		# d
	.word scien-L5			# e
	.word float-L5			# f
	.word general-L5		# g
	.word L6-L5			# h
	.word L6-L5			# i
	.word L6-L5			# j
	.word plus-L5			# +
	.word longorunsg-L5		# l
	.word minus-L5			# -
	.word dot-L5			# .
	.word octal-L5			# o
	.word gnum0-L5			# 0
	.word gnum-L5			# 1
	.word gnum-L5			# 2
	.word gnum-L5			# 3
	.word gnum-L5			# 4
	.word gnum-L5			# 5
	.word gnum-L5			# 6
	.word gnum-L5			# 7
	.word gnum-L5			# 8
	.word gnum-L5			# 9
E 5
I 5
#ifdef CSH_WHACKS
#define	PUTC(ch)	(void) putc(ch, fp)
#else
#include "sh.h"
#define	PUTC(c)		{ ch = c; CSHPUTCHAR; }
#endif
E 5

D 5
L6:	jbcs $5,r0,L4b			# capitals same as small
	cmpb r0,$'s
	jeql string
	cmpb r0,$'x
	jeql hex
	cmpb r0,$'u
	jeql unsigned
	cmpb r0,$'r
	jeql remote
	movzbl -1(r11),r0		# orginal "format" character
	cmpb r0,$'*
	jeql indir
L9:	movb r0,(r5)+			# print the unfound character
	jbr prbuf
E 5
I 5
#define	ARG() \
	_ulong = flags&LONGINT ? va_arg(argp, long) : \
	    flags&SHORTINT ? va_arg(argp, short) : va_arg(argp, int);
E 5

D 5
nulstr:
	.byte '(,'n,'u,'l,'l,'),0
E 5
I 5
#define	todigit(c)	((c) - '0')
#define	tochar(n)	((n) + '0')
E 5

D 5
string:
	movl ndigit,r0
	jbs $precb,flags,L20		# max length was specified
	mnegl $1,r0			# default max length
L20:	movl (ap)+,r2			# addr first byte
	bneq L21
	movab nulstr,r2
L21:	locc $0,r0,(r2)			# find the zero at the end
	movl r1,r5			# addr last byte +1
	movl r2,r1			# addr first byte
	jbr prstr
E 5
I 5
/* have to deal with the negative buffer count kludge */
#define	NEGATIVE_COUNT_KLUDGE
E 5

I 5
#define	LONGINT		0x01		/* long integer */
#define	LONGDBL		0x02		/* long double; unimplemented */
#define	SHORTINT	0x04		/* short integer */
#define	ALT		0x08		/* alternate form */
#define	LADJUST		0x10		/* left adjustment */
#define	ZEROPAD		0x20		/* zero (as opposed to blank) pad */
#define	HEXPREFIX	0x40		/* add 0x or 0X prefix */
E 5

D 5
longorunsg:
	movb (r11)+,r0
	cmpb r0,$'o
	jeql loct
	cmpb r0,$'x
	jeql lhex
	cmpb r0,$'d
	jeql long
	cmpb r0,$'u
	jeql lunsigned
	decl r11
	jbr unsigned
E 5
I 5
_doprnt(fmt0, argp, fp)
	u_char *fmt0;
	va_list argp;
	register FILE *fp;
{
	register u_char *fmt;	/* format string */
	register int ch;	/* character from fmt */
	register int cnt;	/* return value accumulator */
	register int n;		/* random handy integer */
	register char *t;	/* buffer pointer */
	double _double;		/* double precision arguments %[eEfgG] */
	u_long _ulong;		/* integer arguments %[diouxX] */
	int base;		/* base for [diouxX] conversion */
	int dprec;		/* decimal precision in [diouxX] */
	int fieldsz;		/* field size expanded by sign, etc */
	int flags;		/* flags as above */
	int fpprec;		/* `extra' floating precision in [eEfgG] */
	int prec;		/* precision from format (%.3d), or -1 */
	int realsz;		/* field size expanded by decimal precision */
	int size;		/* size of converted field or string */
	int width;		/* width from format (%8d), or 0 */
	char sign;		/* sign prefix (+ - or \0) */
	char *digs;		/* digits for [diouxX] conversion */
	char buf[BUF];		/* space for %c, %[diouxX], %[eEfgG] */
E 5

D 5
loct:
octal:
	movl $30,r2			# init position
	movl $3,r3			# field width
	movl $10,r4			# result length -1
	jbr L10
E 5
I 5
	if (fp->_flag & _IORW) {
		fp->_flag |= _IOWRT;
		fp->_flag &= ~(_IOEOF|_IOREAD);
	}
	if ((fp->_flag & _IOWRT) == 0)
		return (EOF);
E 5

D 5
lhex:
hex:
	movl $28,r2			# init position
	movl $4,r3			# field width
	movl $7,r4			# result length -1
L10:	mnegl r3,r6			# increment
	clrl r1
	movl (ap)+,r0			# fetch arg
L11:	extzv r2,r3,r0,r1		# pull out a digit
	movb htab[r1],(r5)+		# convert to character
L12:	acbl $0,r6,r2,L11		# continue until done
	clrb (r5)			# flag end
	skpc $'0,r4,(sp)		# skip over leading zeroes
	jbr prstr
E 5
I 5
	fmt = fmt0;
	digs = "0123456789abcdef";
	for (cnt = 0;; ++fmt) {
#ifdef CSH_WHACKS
		n = fp->_cnt;
		for (t = (char *)fp->_ptr; (ch = *fmt) && ch != '%';
		     ++cnt, ++fmt)
			if (--n < 0
#ifdef NEGATIVE_COUNT_KLUDGE
			    && (!(fp->_flag & _IOLBF) || -n >= fp->_bufsiz)
#endif
			    || ch == '\n' && fp->_flag & _IOLBF) {
				fp->_cnt = n;
				fp->_ptr = t;
				(void) _flsbuf((u_char)ch, fp);
				n = fp->_cnt;
				t = (char *)fp->_ptr;
			} else
				*t++ = ch;
		fp->_cnt = n;
		fp->_ptr = t;
#else
		if ((ch = *fmt) && ch != '%') {
			CSHPUTCHAR;
			continue;
		}
#endif
		if (!ch)
			return (cnt);
E 5

D 5
patdec:					# editpc pattern for decimal printing
	.byte 0xA9			# eo$float 9
	.byte 0x01			# eo$end_float
	.byte 0x91			# eo$move 1
	.byte 0				# eo$end
E 5
I 5
		flags = dprec = fpprec = width = 0;
		prec = -1;
		sign = '\0';
E 5

D 5
long:
decimal:
	cvtlp (ap)+,$10,(sp)		# 10 digits max
L14:	editpc $10,(sp),patdec,8(sp)	# ascii at 8(sp); r5=end+1
	skpc $' ,$10,8(sp)		# skip leading blanks; r1=first
E 5
I 5
rflag:		switch (*++fmt) {
		case ' ':
			sign = ' ';
			goto rflag;
		case '#':
			flags |= ALT;
			goto rflag;
		case '*':
			/*
			 * ``A negative field width argument is taken as a
			 * - flag followed by a  positive field width.''
			 *	-- ANSI X3J11
			 * They don't exclude field widths read from args.
			 */
			if ((width = va_arg(argp, int)) >= 0)
				goto rflag;
			width = -width;
			/* FALLTHROUGH */
		case '-':
			flags |= LADJUST;
			goto rflag;
		case '+':
			sign = '+';
			goto rflag;
		case '.':
			if (*++fmt == '*')
				n = va_arg(argp, int);
			else {
				n = 0;
				while (isascii(*fmt) && isdigit(*fmt))
					n = 10 * n + todigit(*fmt++);
				--fmt;
			}
			prec = n < 0 ? -1 : n;
			goto rflag;
		case '0':
			/*
			 * ``Note that 0 is taken as a flag, not as the
			 * beginning of a field width.''
			 *	-- ANSI X3J11
			 */
			flags |= ZEROPAD;
			goto rflag;
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			n = 0;
			do {
				n = 10 * n + todigit(*fmt);
			} while (isascii(*++fmt) && isdigit(*fmt));
			width = n;
			--fmt;
			goto rflag;
		case 'L':
			flags |= LONGDBL;
			goto rflag;
		case 'h':
			flags |= SHORTINT;
			goto rflag;
		case 'l':
			flags |= LONGINT;
			goto rflag;
		case 'c':
			*(t = buf) = va_arg(argp, int);
			size = 1;
			sign = '\0';
			goto pforw;
		case 'D':
			flags |= LONGINT;
			/*FALLTHROUGH*/
		case 'd':
		case 'i':
			ARG();
			if ((long)_ulong < 0) {
				_ulong = -_ulong;
				sign = '-';
			}
			base = 10;
			goto number;
		case 'e':
		case 'E':
		case 'f':
		case 'g':
		case 'G':
			_double = va_arg(argp, double);
			/*
			 * don't bother to do unrealistic precision; just
			 * pad it with zeroes later.  This keeps buffer size
			 * rational.
			 */
			if (prec > MAXFRACT) {
				if (*fmt != 'g' && *fmt != 'G' || (flags&ALT))
					fpprec = prec - MAXFRACT;
				prec = MAXFRACT;
			}
			else if (prec == -1)
				prec = DEFPREC;
			if (_double < 0) {
				sign = '-';
				_double = -_double;
			}
			/*
			 * _cvt may have to round up past the "start" of the
			 * buffer, i.e. ``intf("%.2f", (double)9.999);'';
			 * if the first char isn't NULL, it did.
			 */
			*buf = NULL;
			size = _cvt(_double, prec, flags, *fmt, buf,
			    buf + sizeof(buf));
			t = *buf ? buf : buf + 1;
			goto pforw;
		case 'n':
			if (flags & LONGINT)
				*va_arg(argp, long *) = cnt;
			else if (flags & SHORTINT)
				*va_arg(argp, short *) = cnt;
			else
				*va_arg(argp, int *) = cnt;
			break;
		case 'O':
			flags |= LONGINT;
			/*FALLTHROUGH*/
		case 'o':
			ARG();
			base = 8;
			goto nosign;
		case 'p':
			/*
			 * ``The argument shall be a pointer to void.  The
			 * value of the pointer is converted to a sequence
			 * of printable characters, in an implementation-
			 * defined manner.''
			 *	-- ANSI X3J11
			 */
			/* NOSTRICT */
			_ulong = (u_long)va_arg(argp, void *);
			base = 16;
			goto nosign;
		case 's':
			if (!(t = va_arg(argp, char *)))
				t = "(null)";
			if (prec >= 0) {
				/*
				 * can't use strlen; can only look for the
				 * NUL in the first `prec' characters, and
				 * strlen() will go further.
				 */
				char *p, *memchr();
E 5

D 5
prstr:			# r1=addr first byte; r5=addr last byte +1
	cvtbl $' ,-(sp)			# blank fill
	jbc $zfillb,flags,L15
	cvtbl $'0,(sp)			# zero fill
L15:	pushl fdesc			# FILE
	subl2 r1,r5			# r5=actual length=end+1-first
	subl3 r5,width,r0		# if >0, how much to fill
	bgeq L24
	clrl r0				# no fill
L24:	jbs $ljustb,flags,L25
	mnegl r0,r0
L25:	pushl r0			# fill count
	pushl r1			# addr first byte
	pushl r5			# length
	calls $5,__strout
	jbr	loop
E 5
I 5
				if (p = memchr(t, 0, prec)) {
					size = p - t;
					if (size > prec)
						size = prec;
				} else
					size = prec;
			} else
				size = strlen(t);
			sign = '\0';
			goto pforw;
		case 'U':
			flags |= LONGINT;
			/*FALLTHROUGH*/
		case 'u':
			ARG();
			base = 10;
			goto nosign;
		case 'X':
			digs = "0123456789ABCDEF";
			/* FALLTHROUGH */
		case 'x':
			ARG();
			base = 16;
			/* leading 0x/X only if non-zero */
			if (flags & ALT && _ulong != 0)
				flags |= HEXPREFIX;
E 5

D 5
pone:	.byte	0x1C			# packed 1
	
unsigned:
lunsigned:
	extzv $1,$31,(ap),r0		# right shift logical 1 bit
	cvtlp r0,$10,(sp)		# convert [n/2] to packed
	movp $10,(sp),8(sp)		# copy packed
	addp4 $10,8(sp),$10,(sp)	# 2*[n/2] in packed, at (sp)
	blbc (ap)+,L14			# n was even
	addp4 $1,pone,$10,(sp)		# n was odd
	jbr L14
E 5
I 5
			/* unsigned conversions */
nosign:			sign = '\0';
			/*
			 * ``... diouXx conversions ... if a precision is
			 * specified, the 0 flag will be ignored.''
			 *	-- ANSI X3J11
			 */
number:			if ((dprec = prec) >= 0)
				flags &= ~ZEROPAD;
E 5

D 5
charac:
	movl $4,r0			# chars per word
L18:	movb (ap)+,(r5)+		# transfer char
	bneq L19
	decl r5				# omit null characters
L19:	sobgtr r0,L18
E 5
I 5
			/*
			 * ``The result of converting a zero value with an
			 * explicit precision of zero is no characters.''
			 *	-- ANSI X3J11
			 */
			t = buf + BUF;
			if (_ulong != 0 || prec != 0) {
				do {
					*--t = digs[_ulong % base];
					_ulong /= base;
				} while (_ulong);
				digs = "0123456789abcdef";
				if (flags & ALT && base == 8 && *t != '0')
					*--t = '0'; /* octal leading 0 */
			}
			size = buf + BUF - t;
E 5

D 5
prbuf:
	movl sp,r1			# addr first byte
	jbr prstr
E 5
I 5
pforw:
			/*
			 * All reasonable formats wind up here.  At this point,
			 * `t' points to a string which (if not flags&LADJUST)
			 * should be padded out to `width' places.  If
			 * flags&ZEROPAD, it should first be prefixed by any
			 * sign or other prefix; otherwise, it should be blank
			 * padded before the prefix is emitted.  After any
			 * left-hand padding and prefixing, emit zeroes
			 * required by a decimal [diouxX] precision, then print
			 * the string proper, then emit zeroes required by any
			 * leftover floating precision; finally, if LADJUST,
			 * pad with blanks.
			 */
E 5

D 5
plus:	bisl2 $psign,flags		# always print sign for floats
	jbr L4a
minus:	bisl2 $ljust,flags		# left justification, please
	jbr L4a
gnum0:	jbs $ndfndb,flags,gnum
	jbs $precb,flags,gnump		# ignore when reading precision
	bisl2 $zfill,flags		# leading zero fill, please
gnum:	jbs $precb,flags,gnump
	moval (width)[width],width	# width *= 5;
	movaw -ch.zer(r0)[width],width	# width = 2*witdh + r0 - '0';
	jbr gnumd
gnump:	moval (ndigit)[ndigit],ndigit	# ndigit *= 5;
	movaw -ch.zer(r0)[ndigit],ndigit # ndigit = 2*ndigit + r0 - '0';
gnumd:	bisl2 $ndfnd,flags		# digit seen
	jbr L4a
dot:	clrl ndigit			# start on the precision
	bisl2 $prec,flags
	bicl2 $ndfnd,flags
	jbr L4a
indir:	movl (ap)+,ndigit		# width specified by parameter
	jbr gnumd
remote:	movl (ap)+,ap
	movl (ap)+,r11
	jbr loop
E 5
I 5
			/*
			 * compute actual size, so we know how much to pad
			 * fieldsz excludes decimal prec; realsz includes it
			 */
			fieldsz = size + fpprec;
			if (sign)
				fieldsz++;
			if (flags & HEXPREFIX)
				fieldsz += 2;
			realsz = dprec > fieldsz ? dprec : fieldsz;
E 5

D 5
float:
	bsbw fltcvt
fltg:	jbs $ndfndb,flags,float1
	movl $6,ndigit			# default # digits to right of decpt.
float1:	addl3 exp,ndigit,r7
	movl r7,r6			# for later "underflow" checking
	bgeq fxplrd
	clrl r7				# poor programmer planning
fxplrd:	cmpl r7,$31			# expressible in packed decimal?
	bleq fnarro			# yes
	movl $31,r7
fnarro:	subl3 $17,r7,r0			# where to round
	ashp r0,$17,(sp),$5,r7,16(sp)	# do it
	bvc fnovfl
	# band-aid for microcode error (spurious overflow)
	clrl r0				# assume even length result
	jlbc r7,fleven			# right
	movl $4,r0			# odd length result
fleven:	cmpv r0,$4,16(sp),$0		# top digit zero iff true overflow
	bneq fnovfl
	# end band-aid
	aobleq $0,r6,fnovfl		# if "underflow" then jump
	movl r7,r0
	incl exp
	incl r7
	ashp r0,$1,pone,$0,r7,16(sp)
	ashl $-1,r7,r0			# displ to last byte
	bisb2 sign,16(sp)[r0]		# insert sign
fnovfl:
	movc3 $4,patsci,(sp)
	clrl r6				# # digits moved so far
	movl exp,r0
	bleq fexpng
	bsbb patmov			# digits to left of decpt.
fexpng:	tstl ndigit
	jeql fnodp
	movc3 $2,fpatdp,(r3)
	tstl exp
	bgeq fxppos
	addl3 exp,ndigit,r6
	bgeq  flfakl
	clrl r6				# it's all fill
flfakl:	subl3 r6,$31,r6			# fake length for patmov
flfill:	movc3 $2,fpatzf,(r3)		# zero fill to right of dec.pt
fxppos:	movl ndigit,r0
	bsbb patmov
fnodp:	sobgeq r6,fledit		# must move at least 1 digit
	movl $31,r6			# none moved; fake it
	aobleq $1,ndigit,flfill		# with a one-character zero fill
fledit:	editpc r7,16(sp),(sp),32(sp)
	jbr prflt
E 5
I 5
			/* right-adjusting blank padding */
			if ((flags & (LADJUST|ZEROPAD)) == 0 && width)
				for (n = realsz; n < width; n++)
					PUTC(' ');
			/* prefix */
			if (sign)
				PUTC(sign);
			if (flags & HEXPREFIX) {
				PUTC('0');
				PUTC((char)*fmt);
			}
			/* right-adjusting zero padding */
			if ((flags & (LADJUST|ZEROPAD)) == ZEROPAD)
				for (n = realsz; n < width; n++)
					PUTC('0');
			/* leading zeroes from decimal precision */
			for (n = fieldsz; n < dprec; n++)
				PUTC('0');
E 5

D 5
patexp:	.byte	0x03			# eo$set_signif
	.byte	0x44,'e			# eo$insert 'e
	.byte	0x42,'+			# eo$load_plus '+
	.byte	0x04			# eo$store_sign
	.byte	0x92			# eo$move 2
	.byte	0			# eo$end
patsci:	.byte	0x42,'+			# eo$load_plus '+
	.byte	0x03			# eo$set_signif
	.byte	0x04			# eo$store_sign
	.byte	0x91			# eo$move 1
fpatdp:	.byte	0x44,'.			# eo$insert '.
fpatzf:	.byte	0x40,'0			# eo$load_fill '0
E 5
I 5
			/* the string or number proper */
#ifdef CSH_WHACKS
			if (fp->_cnt - (n = size) >= 0 &&
			    (fp->_flag & _IOLBF) == 0) {
				fp->_cnt -= n;
				bcopy(t, (char *)fp->_ptr, n);
				fp->_ptr += n;
			} else
				while (--n >= 0)
#else
			for (n = size; --n >= 0;)
#endif
					PUTC(*t++);
			/* trailing f.p. zeroes */
			while (--fpprec >= 0)
				PUTC('0');
			/* left-adjusting padding (always blank) */
			if (flags & LADJUST)
				for (n = realsz; n < width; n++)
					PUTC(' ');
			/* finally, adjust cnt */
			cnt += width > realsz ? width : realsz;
			break;
		case '\0':	/* "%?" prints ?, unless ? is NULL */
			return (cnt);
		default:
			PUTC((char)*fmt);
			cnt++;
		}
	}
	/* NOTREACHED */
}
E 5

D 5
	# construct pattern at (r3) to move  r0  digits in  editpc;
	#  r6  digits already moved for this number
patmov:
	movb $0x90,r2			# eo$move
	subl3 r6,$31,r1			# # digits remaining in packed
	addl2 r0,r6
	cmpl r0,r1			# enough digits remaining?
	bleq patsml			# yes
	tstl exp			# zero 'fill'; before or after rest?
	bgeq pataft			# after
	pushl r1			# # digits remaining
	movb $0x80,r2			# eo$fill
	subl3 $31,r6,r0			# number of fill bytes
	bsbb patsml			# recursion!
	movl (sp)+,r0
	movb $0x90,r2			# eo$move
	jbr patsml
pataft:	movl r1,r0			# last of the 31
	bsbb patsml			# recursion!
	subl3 $31,r6,r0			# number of fill bytes
	movb $0x80,r2			# eo$fill
patsml:	tstl r0
	bleq patzer			# DEC doesn't like repetition counts of 0
	mnegl $15,r1			# 15 digits at a time
	subl2 r1,r0			# counteract acbl
	jbr pattst
patmlp:	bisb3 r2,$15,(r3)+		# 15
pattst:	acbl $16,r1,r0,patmlp		# until <= 15 left
	bisb3 r2,r0,(r3)+		# rest
patzer:	clrb (r3)			# eo$end
	rsb
E 5
I 5
static
_cvt(number, prec, flags, fmtch, startp, endp)
	double number;
	register int prec;
	int flags;
	u_char fmtch;
	char *startp, *endp;
{
	register char *p, *t;
	double fract, integer, tmp, modf();
	int dotrim, expcnt, gformat;
	char *exponent(), *eround(), *fround();
E 5

D 5
scien:
	bsbw fltcvt			# get packed digits
scig:	incl ndigit
	jbs $ndfndb,flags,L23
	movl $7,ndigit
L23:	subl3 $17,ndigit,r0		# rounding position
	ashp r0,$17,(sp),$5,ndigit,16(sp) # shift and round
	bvc snovfl
	# band-aid for microcode error (spurious overflow)
	clrl r0				# assume even length result
	jlbc ndigit,sceven		# right
	movl $4,r0			# odd length result
sceven:	cmpv r0,$4,16(sp),$0		# top digit zero iff true overflow
	bneq snovfl
	# end band-aid
	incl exp			# rounding overflowed to 100...
	subl3 $1,ndigit,r0
	ashp r0,$1,pone,$0,ndigit,16(sp)
	ashl $-1,ndigit,r0		# displ to last byte
	bisb2 sign,16(sp)[r0]		# insert sign
snovfl:
	jbc $gflagb,flags,enotg		# not %g format
 # find trailing zeroes in packed number
	ashl $-1,ndigit,r0
	addl2 r3,r0			# addr of l.s.digit and sign
	movl $4,r1			# bit position of digit
	movl ndigit,r7			# current length of packed
	jbr gtz
gtz1:	xorl2 $4,r1			# position of next digit
	bneq gtz			# same byte
	decl r0				# different byte
gtz:	cmpv r1,$4,(r0),$0		# a trailing zero?
	jneq gntz
	sobgtr r7,gtz1
	incl r7
gntz:					# r7: minimum width of fraction
	cmpl exp,$-4
	jleq eg				# small exponents use %e
	subl3 r7,exp,r0
	cmpl $5,r0
	jleq eg				# so do (w+5) <= exp
	tstl r0				# rest use %f
	jleq fg				# did we trim too many trailing zeroes?
	movl exp,r7			# yes
fg:	subl3 ndigit,r7,r0
	ashp r0,ndigit,16(sp),$0,r7,(sp)
	movp r7,(sp),16(sp)
	subl3 exp,r7,ndigit		# correct ndigit for %f
	jbr fnovfl
eg:	subl3 ndigit,r7,r0
	ashp r0,ndigit,16(sp),$0,r7,(sp)
	movp r7,(sp),16(sp)
	movl r7,ndigit			# packed number has been trimmed
enotg:
	movc3 $7,patsci,(sp)
	movl $1,r6			# 1P
	subl3 $1,ndigit,r0		# digits after dec.pt
	bsbw patmov
	editpc ndigit,16(sp),(sp),32(sp)	# 32(sp)->result, r5->(end+1)
	decl exp			# compensate: 1 digit left of dec.pt
	cvtlp exp,$2,(sp)		# exponent
	editpc $2,(sp),patexp,(r5)
prflt:	movab 32(sp),r1
	jbs $psignb,flags,prflt1
	cmpb (r1)+,$'+
	beql prflt1
	decl r1
prflt1:	skpc $' ,$63,(r1)
	jbr prstr
E 5
I 5
	dotrim = expcnt = gformat = 0;
	fract = modf(number, &integer);
E 5

D 5
general:
	jbcs $gflagb,flags,scien
	jbr scien			# safety net
E 5
I 5
	/* get an extra slot for rounding. */
	t = ++startp;
E 5

D 5
	# convert double-floating at (ap) to 17-digit packed at (sp),
	# set 'sign' and 'exp', advance ap.
fltcvt:
	clrb sign
	movd (ap)+,r5
	jeql fzero
	bgtr fpos
	mnegd r5,r5
	incb sign
fpos:
	extzv $7,$8,r5,r2		# exponent of 2
	movaw -0600(r2)[r2],r2		# unbias and mult by 3
	bgeq epos
	subl2 $9,r2
epos:	divl2 $10,r2
	bsbb expten
	cmpd r0,r5
	bgtr ceil
	incl r2
ceil:	movl r2,exp
	mnegl r2,r2
	cmpl r2,$29			# 10^(29+9) is all we can handle
	bleq getman
	muld2 ten16,r5
	subl2 $16,r2
getman:	addl2 $9,r2			# -ceil(log10(x)) + 9
	bsbb expten
	emodd r0,r4,r5,r0,r5		# (r0+r4)*r5; r0=int, r5=frac
fz1:	cvtlp r0,$9,16(sp)		# leading 9 digits
	ashp $8,$9,16(sp),$0,$17,4(sp)	# as top 9 of 17
	emodd ten8,$0,r5,r0,r5
	cvtlp r0,$8,16(sp)		# trailing 8 digits
	addp4 $8,16(sp),$17,4(sp)	# combine leading and trailing
	bisb2 sign,12(sp)		# and insert sign
	rsb
fzero:	clrl r0
	movl $1,exp		# 0.000e+00 and 0.000 rather than 0.000e-01 and .000
	jbr fz1
E 5
I 5
	/*
	 * get integer portion of number; put into the end of the buffer; the
	 * .01 is added for modf(356.0 / 10, &integer) returning .59999999...
	 */
	for (p = endp - 1; integer; ++expcnt) {
		tmp = modf(integer / 10, &integer);
		*p-- = tochar((int)((tmp + .01) * 10));
	}
	switch(fmtch) {
	case 'f':
		/* reverse integer into beginning of buffer */
		if (expcnt)
			for (; ++p < endp; *t++ = *p);
		else
			*t++ = '0';
		/*
		 * if precision required or alternate flag set, add in a
		 * decimal point.
		 */
		if (prec || flags&ALT)
			*t++ = '.';
		/* if requires more precision and some fraction left */
		if (fract) {
			if (prec)
				do {
					fract = modf(fract * 10, &tmp);
					*t++ = tochar((int)tmp);
				} while (--prec && fract);
			if (fract)
				startp = fround(startp, t - 1, fract);
		}
		for (; prec--; *t++ = '0');
		break;
	case 'e':
	case 'E':
eformat:	if (expcnt) {
			*t++ = *++p;
			if (prec || flags&ALT)
				*t++ = '.';
			/* if requires more precision and some integer left */
			for (; prec && ++p < endp; --prec)
				*t++ = *p;
			/*
			 * if done precision and more of the integer component,
			 * round using it; adjust fract so we don't re-round
			 * later.
			 */
			if (!prec && ++p < endp) {
				startp = eround(startp, t - 1, (double)0,
				    *p, &expcnt);
				fract = 0;
			}
			/* adjust expcnt for digit in front of decimal */
			--expcnt;
		}
		/* until first fractional digit, decrement exponent */
		else if (fract) {
			/* adjust expcnt for digit in front of decimal */
			for (expcnt = -1;; --expcnt) {
				fract = modf(fract * 10, &tmp);
				if (tmp)
					break;
			}
			*t++ = tochar((int)tmp);
			if (prec || flags&ALT)
				*t++ = '.';
		}
		else {
			*t++ = '0';
			if (prec || flags&ALT)
				*t++ = '.';
		}
		/* if requires more precision and some fraction left */
		if (fract) {
			if (prec)
				do {
					fract = modf(fract * 10, &tmp);
					*t++ = tochar((int)tmp);
				} while (--prec && fract);
			if (fract)
				startp = eround(startp, t - 1, fract,
				    (char)0, &expcnt);
		}
		/* if requires more precision */
		for (; prec--; *t++ = '0');
E 5

D 5
	# return 10^r2 as a double float in r0||r1 and 8 extra bits of precision in r4
	# preserve r2, r5||r6
expten:
	movd $one,r0			# begin computing 10^exp10
	clrl r4				# bit counter
	movad ten1,r3			# table address
	tstl r2
	bgeq e10lp
	mnegl r2,r2			# get absolute value
	jbss $6,r2,e10lp		# flag as negative
e10lp:	jbc r4,r2,el1			# want this power?
	muld2 (r3),r0			# yes
el1:	addl2 $8,r3			# advance to next power
	aobleq $5,r4,e10lp		# through 10^32
	jbcc $6,r2,el2			# correct for negative exponent
	divd3 r0,$one,r0		# by taking reciprocal
	mnegl r2,r2
el2:	clrl r4				# 8 extra bits of precision
	rsb
E 5
I 5
		/* unless alternate flag, trim any g/G format trailing 0's */
		if (gformat && !(flags&ALT)) {
			while (t > startp && *--t == '0');
			if (*t == '.')
				--t;
			++t;
		}
		t = exponent(t, expcnt, fmtch);
		break;
	case 'g':
	case 'G':
		/* a precision of 0 is treated as a precision of 1. */
		if (!prec)
			++prec;
		/*
		 * ``The style used depends on the value converted; style e
		 * will be used only if the exponent resulting from the
		 * conversion is less than -4 or greater than the precision.''
		 *	-- ANSI X3J11
		 */
		if (expcnt > prec || !expcnt && fract && fract < .0001) {
			/*
			 * g/G format counts "significant digits, not digits of
			 * precision; for the e/E format, this just causes an
			 * off-by-one problem, i.e. g/G considers the digit
			 * before the decimal point significant and e/E doesn't
			 * count it as precision.
			 */
			--prec;
			fmtch -= 2;		/* G->E, g->e */
			gformat = 1;
			goto eformat;
		}
		/*
		 * reverse integer into beginning of buffer,
		 * note, decrement precision
		 */
		if (expcnt)
			for (; ++p < endp; *t++ = *p, --prec);
		else
			*t++ = '0';
		/*
		 * if precision required or alternate flag set, add in a
		 * decimal point.  If no digits yet, add in leading 0.
		 */
		if (prec || flags&ALT) {
			dotrim = 1;
			*t++ = '.';
		}
		else
			dotrim = 0;
		/* if requires more precision and some fraction left */
		if (fract) {
			if (prec) {
				do {
					fract = modf(fract * 10, &tmp);
					*t++ = tochar((int)tmp);
				} while(!tmp);
				while (--prec && fract) {
					fract = modf(fract * 10, &tmp);
					*t++ = tochar((int)tmp);
				}
			}
			if (fract)
				startp = fround(startp, t - 1, fract);
		}
		/* alternate format, adds 0's for precision, else trim 0's */
		if (flags&ALT)
			for (; prec--; *t++ = '0');
		else if (dotrim) {
			while (t > startp && *--t == '0');
			if (*t != '.')
				++t;
		}
	}
	return(t - startp);
}
E 5

D 5
	# powers of ten
	.align	2
ten1:	.word	0x4220,0,0,0
ten2:	.word	0x43c8,0,0,0
ten4:	.word	0x471c,0x4000,0,0
ten8:	.word	0x4dbe,0xbc20,0,0
ten16:	.word	0x5b0e,0x1bc9,0xbf04,0
ten32:	.word	0x759d,0xc5ad,0xa82b,0x70b6
E 5
I 5
static char *
fround(start, end, fract)
	register char *start, *end;
	double fract;
{
	double tmp;
E 5
I 4

D 5
#endif /* vax */
E 5
I 5
	(void)modf(fract * 10, &tmp);
	if (tmp > 4)
		for (;; --end) {
			if (*end == '.')
				--end;
			if (++*end <= '9')
				break;
			*end = '0';
			/* add extra digit to round past buffer beginning */
			if (end == start) {
				*--end = '1';
				--start;
				break;
			}
		}
	return(start);
}

static char *
eround(start, end, fract, ch, exp)
	register char *start, *end;
	double fract;
	char ch;
	int *exp;
{
	double tmp;

	if (fract)
		(void)modf(fract * 10, &tmp);
	else
		tmp = todigit(ch);
	if (tmp > 4)
		for (;; --end) {
			if (*end == '.')
				--end;
			if (++*end <= '9')
				break;
			*end = '0';
			/* increment exponent to round past buffer beginning */
			if (end == start) {
				*end = '1';
				++*exp;
				break;
			}
		}
	return(start);
}

static char *
exponent(p, exp, fmtch)
	register char *p;
	register int exp;
	u_char fmtch;
{
	register char *t;
	char expbuf[MAXEXP];

	*p++ = fmtch;
	if (exp < 0) {
		exp = -exp;
		*p++ = '-';
	}
	else
		*p++ = '+';
	t = expbuf + MAXEXP;
	if (exp > 9) {
		do {
			*--t = tochar(exp % 10);
		} while ((exp /= 10) > 9);
		*--t = tochar(exp);
		for (; t < expbuf + MAXEXP; *p++ = *t++);
	}
	else {
		*p++ = '0';
		*p++ = tochar(exp);
	}
	return(p);
}
E 5
E 4
E 1
