h63855
s 00015/00014/00338
d D 7.5 03/04/13 15:19:46 msokolov 13 12
c 8-bit ex
e
s 00013/00012/00339
d D 7.4 87/03/09 12:46:07 conrad 12 11
c make ex/vi work on vms
e
s 00001/00001/00350
d D 7.3 85/06/07 18:26:35 bloom 11 10
c fix sccsid and copyright for xstr
e
s 00010/00002/00341
d D 7.2 85/05/31 15:34:21 dist 10 9
c Add copyright
e
s 00001/00001/00342
d D 7.1 81/07/08 22:36:48 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00343
d D 6.1 80/10/19 01:23:25 mark 8 7
c preliminary release 3.6 10/18/80
e
s 00000/00000/00343
d D 5.1 80/08/20 16:18:11 mark 7 6
c Release 3.5, August 20, 1980
e
s 00001/00001/00342
d D 4.3 80/08/01 23:02:21 mark 6 5
c fixed pcc warning about printf string init
e
s 00004/00001/00339
d D 4.2 80/08/01 20:45:07 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00000/00000/00340
d D 4.1 80/08/01 00:21:26 mark 4 3
c release 3.4, June 24, 1980
e
s 00000/00000/00340
d D 3.1 80/07/31 23:46:44 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00340
d D 2.1 80/07/31 23:22:42 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00340/00000/00000
d D 1.1 80/07/31 23:01:16 mark 1 0
c date and time created 80/07/31 23:01:16 by mark
e
u
U
t
T
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 11
static char sccsid[] = "%W% (Berkeley) %G%";
E 11
I 11
static char *sccsid = "%W% (Berkeley) %G%";
E 11
D 12
#endif not lint

E 12
E 10
I 1
D 5
/* char printf_id[] = "@(#) printf.c:2.2 6/5/79";*/
E 5
I 5
/* The pwb version this is based on */
D 6
static char printf_id[] = "@(#) printf.c:2.2 6/5/79";
E 6
I 6
static char *printf_id = "@(#) printf.c:2.2 6/5/79";
E 6
D 10
/* The local sccs version within ex */
D 9
static char *sccsid = "%W% %G%";
E 9
I 9
static char *sccsid = "%W%	%G%";
E 10
E 9
E 5
D 12
#include "varargs.h"
E 12
I 12
#endif not lint

I 13
#include <sys/types.h>
E 13
#include <varargs.h>
 
E 12
/*
 * This version of printf is compatible with the Version 7 C
 * printf. The differences are only minor except that this
 * printf assumes it is to print through putchar. Version 7
 * printf is more general (and is much larger) and includes
 * provisions for floating point.
 */
D 12
 
E 12

#define MAXOCT	11	/* Maximum octal digits in a long */
#define MAXINT	32767	/* largest normal length positive integer */
#define BIG	1000000000  /* largest power of 10 less than an unsigned long */
#define MAXDIGS	10	/* number of digits in BIG */

static int width, sign, fill;

D 13
char *_p_dconv();
E 13
I 13
u_char *_p_dconv();
E 13

D 12
printf(va_alist)
E 12
I 12
/* VARARGS */
ex_printf(va_alist)
E 12
	va_dcl
{
	va_list ap;
D 13
	register char *fmt;
	char fcode;
E 13
I 13
	register u_char *fmt;
	u_char fcode;
E 13
	int prec;
	int length,mask1,nbits,n;
	long int mask2, num;
D 13
	register char *bptr;
	char *ptr;
	char buf[134];
E 13
I 13
	register u_char *bptr;
	u_char *ptr;
	u_char buf[134];
E 13

	va_start(ap);
D 13
	fmt = va_arg(ap,char *);
E 13
I 13
	fmt = va_arg(ap,u_char *);
E 13
	for (;;) {
		/* process format string first */
		while ((fcode = *fmt++)!='%') {
			/* ordinary (non-%) character */
			if (fcode=='\0')
				return;
D 12
			putchar(fcode);
E 12
I 12
			ex_putchar(fcode);
E 12
		}
		/* length modifier: -1 for h, 1 for l, 0 for none */
		length = 0;
		/* check for a leading - sign */
		sign = 0;
		if (*fmt == '-') {
			sign++;
			fmt++;
		}
		/* a '0' may follow the - sign */
		/* this is the requested fill character */
		fill = 1;
		if (*fmt == '0') {
			fill--;
			fmt++;
		}
		
		/* Now comes a digit string which may be a '*' */
		if (*fmt == '*') {
			width = va_arg(ap, int);
			if (width < 0) {
				width = -width;
				sign = !sign;
			}
			fmt++;
		}
		else {
			width = 0;
			while (*fmt>='0' && *fmt<='9')
				width = width * 10 + (*fmt++ - '0');
		}
		
		/* maybe a decimal point followed by more digits (or '*') */
		if (*fmt=='.') {
			if (*++fmt == '*') {
				prec = va_arg(ap, int);
				fmt++;
			}
			else {
				prec = 0;
				while (*fmt>='0' && *fmt<='9')
					prec = prec * 10 + (*fmt++ - '0');
			}
		}
		else
			prec = -1;
		
		/*
		 * At this point, "sign" is nonzero if there was
		 * a sign, "fill" is 0 if there was a leading
		 * zero and 1 otherwise, "width" and "prec"
		 * contain numbers corresponding to the digit
		 * strings before and after the decimal point,
		 * respectively, and "fmt" addresses the next
		 * character after the whole mess. If there was
		 * no decimal point, "prec" will be -1.
		 */
		switch (*fmt) {
			case 'L':
			case 'l':
				length = 2;
				/* no break!! */
			case 'h':
			case 'H':
				length--;
				fmt++;
				break;
		}
		
		/*
		 * At exit from the following switch, we will
		 * emit the characters starting at "bptr" and
		 * ending at "ptr"-1, unless fcode is '\0'.
		 */
		switch (fcode = *fmt++) {
			/* process characters and strings first */
			case 'c':
				buf[0] = va_arg(ap, int);
				ptr = bptr = &buf[0];
				if (buf[0] != '\0')
					ptr++;
				break;
			case 's':
D 13
				bptr = va_arg(ap,char *);
E 13
I 13
				bptr = va_arg(ap,u_char *);
E 13
				if (bptr==0)
					bptr = "(null pointer)";
				if (prec < 0)
					prec = MAXINT;
				for (n=0; *bptr++ && n < prec; n++) ;
				ptr = --bptr;
				bptr -= n;
				break;
			case 'O':
				length = 1;
				fcode = 'o';
				/* no break */
			case 'o':
			case 'X':
			case 'x':
				if (length > 0)
					num = va_arg(ap,long);
				else
					num = (unsigned)va_arg(ap,int);
				if (fcode=='o') {
					mask1 = 0x7;
					mask2 = 0x1fffffffL;
					nbits = 3;
				}
				else {
					mask1 = 0xf;
					mask2 = 0x0fffffffL;
					nbits = 4;
				}
				n = (num!=0);
				bptr = buf + MAXOCT + 3;
				/* shift and mask for speed */
				do
				    if (((int) num & mask1) < 10)
					*--bptr = ((int) num & mask1) + 060;
				    else
					*--bptr = ((int) num & mask1) + 0127;
				while (num = (num >> nbits) & mask2);
				
				if (fcode=='o') {
					if (n)
						*--bptr = '0';
				}
				else
					if (!sign && fill <= 0) {
D 12
						putchar('0');
						putchar(fcode);
E 12
I 12
						ex_putchar('0');
						ex_putchar(fcode);
E 12
						width -= 2;
					}
					else {
						*--bptr = fcode;
						*--bptr = '0';
					}
				ptr = buf + MAXOCT + 3;
				break;
			case 'D':
			case 'U':
			case 'I':
				length = 1;
				fcode = fcode + 'a' - 'A';
				/* no break */
			case 'd':
			case 'i':
			case 'u':
				if (length > 0)
					num = va_arg(ap,long);
				else {
					n = va_arg(ap,int);
					if (fcode=='u')
						num = (unsigned) n;
					else
						num = (long) n;
				}
				if (n = (fcode != 'u' && num < 0))
					num = -num;
				/* now convert to digits */
				bptr = _p_dconv(num, buf);
				if (n)
					*--bptr = '-';
				if (fill == 0)
					fill = -1;
				ptr = buf + MAXDIGS + 1;
				break;
			default:
				/* not a control character, 
				 * print it.
				 */
				ptr = bptr = &fcode;
				ptr++;
				break;
			}
			if (fcode != '\0')
				_p_emit(bptr,ptr);
	}
	va_end(ap);
}

/* _p_dconv converts the unsigned long integer "value" to
 * printable decimal and places it in "buffer", right-justified.
 * The value returned is the address of the first non-zero character,
 * or the address of the last character if all are zero.
 * The result is NOT null terminated, and is MAXDIGS characters long,
 * starting at buffer[1] (to allow for insertion of a sign).
 *
 * This program assumes it is running on 2's complement machine
 * with reasonable overflow treatment.
 */
D 13
char *
E 13
I 13
u_char *
E 13
_p_dconv(value, buffer)
	long value;
D 13
	char *buffer;
E 13
I 13
	u_char *buffer;
E 13
{
D 13
	register char *bp;
E 13
I 13
	register u_char *bp;
E 13
	register int svalue;
	int n;
	long lval;
	
	bp = buffer;
	
	/* zero is a special case */
	if (value == 0) {
		bp += MAXDIGS;
		*bp = '0';
		return(bp);
	}
	
	/* develop the leading digit of the value in "n" */
	n = 0;
	while (value < 0) {
		value -= BIG;	/* will eventually underflow */
		n++;
	}
	while ((lval = value - BIG) >= 0) {
		value = lval;
		n++;
	}
	
	/* stash it in buffer[1] to allow for a sign */
	bp[1] = n + '0';
	/*
	 * Now develop the rest of the digits. Since speed counts here,
	 * we do it in two loops. The first gets "value" down until it
	 * is no larger than MAXINT. The second one uses integer divides
	 * rather than long divides to speed it up.
	 */
	bp += MAXDIGS + 1;
	while (value > MAXINT) {
		*--bp = (int)(value % 10) + '0';
		value /= 10;
	}
	
	/* cannot lose precision */
	svalue = value;
	while (svalue > 0) {
		*--bp = (svalue % 10) + '0';
		svalue /= 10;
	}
	
	/* fill in intermediate zeroes if needed */
	if (buffer[1] != '0') {
		while (bp > buffer + 2)
			*--bp = '0';
		--bp;
	}
	return(bp);
}

/*
 * This program sends string "s" to putchar. The character after
 * the end of "s" is given by "send". This allows the size of the
 * field to be computed; it is stored in "alen". "width" contains the
 * user specified length. If width<alen, the width will be taken to
 * be alen. "sign" is zero if the string is to be right-justified
 * in the field, nonzero if it is to be left-justified. "fill" is
 * 0 if the string is to be padded with '0', positive if it is to be
 * padded with ' ', and negative if an initial '-' should appear before
 * any padding in right-justification (to avoid printing "-3" as
 * "000-3" where "-0003" was intended).
 */
_p_emit(s, send)
D 13
	register char *s;
	char *send;
E 13
I 13
	register u_char *s;
	u_char *send;
E 13
{
D 13
	char cfill;
E 13
I 13
	u_char cfill;
E 13
	register int alen;
	int npad;
	
	alen = send - s;
	if (alen > width)
		width = alen;
	cfill = fill>0? ' ': '0';
	
	/* we may want to print a leading '-' before anything */
	if (*s == '-' && fill < 0) {
D 12
		putchar(*s++);
E 12
I 12
		ex_putchar(*s++);
E 12
		alen--;
		width--;
	}
	npad = width - alen;
	
	/* emit any leading pad characters */
	if (!sign)
		while (--npad >= 0)
D 12
			putchar(cfill);
E 12
I 12
			ex_putchar(cfill);
E 12
			
	/* emit the string itself */
	while (--alen >= 0)
D 12
		putchar(*s++);
E 12
I 12
		ex_putchar(*s++);
E 12
		
	/* emit trailing pad characters */
	if (sign)
		while (--npad >= 0)
D 12
			putchar(cfill);
E 12
I 12
			ex_putchar(cfill);
E 12
}
E 1
