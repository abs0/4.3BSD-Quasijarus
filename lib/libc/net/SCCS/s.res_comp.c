h43127
s 00010/00006/00304
d D 6.14 88/06/27 17:14:11 bostic 25 24
c install approved copyright notice
e
s 00002/00000/00308
d D 6.13 88/03/13 19:05:01 bostic 24 23
c note that _getshort used by sendmail
e
s 00009/00003/00299
d D 6.12 88/03/07 21:17:17 bostic 23 22
c added Berkeley specific header
e
s 00004/00001/00298
d D 6.11 88/02/28 21:17:07 karels 22 21
c don't need to skip first dnptr in dn_find, it's already been skipped;
c make dn_find static
e
s 00021/00021/00278
d D 6.10 87/11/19 21:02:27 karels 21 20
c change dn_skip to dn_skipname with new arg for sanity checking;
c make things unsigned so don't need to strip
e
s 00010/00001/00289
d D 6.9 87/06/25 13:37:57 karels 20 19
c check for loops in compressed names
e
s 00002/00002/00288
d D 6.8 87/01/31 15:25:36 kjd 19 18
c change getshort() and getlong() to _getshort() and _getlong()
e
s 00005/00011/00285
d D 6.7 86/03/11 10:22:29 bloom 18 17
c preserve case
e
s 00002/00002/00294
d D 6.6 86/03/09 20:35:15 donn 17 16
c added LIBC_SCCS condition for sccs ids
e
s 00002/00002/00294
d D 6.5 86/02/18 21:43:04 kjd 16 15
c Fix for dn_find core dumping
e
s 00007/00007/00289
d D 6.4 86/02/07 18:38:04 karels 15 14
c make up out minds: second arg to dn_expand is ptr, is beyond msg
e
s 00010/00004/00286
d D 6.3 86/02/04 09:05:23 kjd 14 11
c Pass msglen to dn_expand
e
s 00010/00004/00286
d R 6.3 86/02/02 19:38:37 kjd 13 11
c pass msglen to db_expand
e
s 00102/00000/00290
d R 6.3 86/01/08 20:09:16 kjd 12 11
c add res_skip for skipping along packets and RR's
e
s 00009/00002/00281
d D 6.2 85/11/01 11:15:15 bloom 11 10
c performance improvements
e
s 00000/00000/00283
d D 6.1 85/10/31 15:29:28 kjd 10 9
c Freeze for November 1 network distribution
e
s 00006/00004/00277
d D 5.4 85/09/14 11:23:09 bloom 9 7
c return names in lower case, fix some lint problems
e
s 00003/00001/00280
d R 5.4 85/09/12 22:40:30 bloom 8 7
c lint -DDEBUG -u *.c > lint.out
e
s 00001/00001/00280
d D 5.3 85/07/29 17:57:45 kjd 7 6
c Move /usr/include/nameser.h to /usr/include/arpa/nameser.h
e
s 00007/00003/00274
d D 5.2 85/07/16 11:01:51 kjd 6 5
c Fix bug in getlong & Remove type declaration in putshort() & putlong()
e
s 00007/00006/00270
d D 5.1 85/05/30 12:05:04 dist 5 4
c Add copyright
e
s 00005/00001/00271
d D 4.4 85/04/01 15:10:48 ralph 4 3
c add copyright notice
e
s 00046/00000/00226
d D 4.3 85/03/27 14:58:19 ralph 3 2
c make more machine independent.
e
s 00046/00015/00180
d D 4.2 85/03/15 16:11:17 ralph 2 1
c changed single label to names not ending in '.' as local.
e
s 00195/00000/00000
d D 4.1 85/03/01 10:42:09 ralph 1 0
c date and time created 85/03/01 10:42:09 by ralph
e
u
U
t
T
I 1
D 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

E 5
I 4
/*
D 5
 * Copyright (c) 1985 Regents of the University of California
 *	All Rights Reserved
E 5
I 5
 * Copyright (c) 1985 Regents of the University of California.
D 23
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 23
I 23
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 25
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 25
I 25
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
E 25
E 23
E 5
 */
I 5

D 17
#ifndef lint
E 17
I 17
#if defined(LIBC_SCCS) && !defined(lint)
E 17
static char sccsid[] = "%W% (Berkeley) %G%";
D 17
#endif not lint
E 17
I 17
D 23
#endif LIBC_SCCS and not lint
E 23
I 23
#endif /* LIBC_SCCS and not lint */
E 23
E 17
E 5

E 4
#include <sys/types.h>
#include <stdio.h>
D 18
#include <ctype.h>
E 18
D 7
#include <nameser.h>
E 7
I 7
#include <arpa/nameser.h>
E 7
D 4

E 4
D 25

E 25
I 6

E 6
/*
D 2
 * Expand compressed domain name format to full domain name.
E 2
I 2
 * Expand compressed domain name 'comp_dn' to full domain name.
D 9
 * Expanded names are converted to upper case.
E 9
I 9
D 18
 * Expanded names are converted to lower case.
E 18
E 9
 * 'msg' is a pointer to the begining of the message,
I 15
 * 'eomorig' points to the first location after the message,
E 15
 * 'exp_dn' is a pointer to a buffer of size 'length' for the result.
E 2
 * Return size of compressed name or -1 if there was an error.
 */
D 14
dn_expand(msg, comp_dn, exp_dn, length)
E 14
I 14
D 15
dn_expand(msg, msglen, comp_dn, exp_dn, length)
E 14
	char *msg, *comp_dn, *exp_dn;
D 14
	int length;
E 14
I 14
	int length, msglen;
E 15
I 15
dn_expand(msg, eomorig, comp_dn, exp_dn, length)
D 21
	char *msg, *eomorig, *comp_dn, *exp_dn;
E 21
I 21
	u_char *msg, *eomorig, *comp_dn, *exp_dn;
E 21
	int length;
E 15
E 14
{
D 21
	register char *cp, *dn;
E 21
I 21
	register u_char *cp, *dn;
E 21
	register int n, c;
D 14
	char *eom;
E 14
I 14
D 15
	char *eom, *eomorig;
E 15
I 15
D 21
	char *eom;
E 21
I 21
	u_char *eom;
E 21
E 15
E 14
D 2
	int len = 0;
E 2
I 2
D 20
	int len = -1;
E 20
I 20
	int len = -1, checked = 0;
E 20
E 2

	dn = exp_dn;
	cp = comp_dn;
	eom = exp_dn + length - 1;
I 14
D 15
	eomorig = msg + msglen - 1;
E 15
E 14
	/*
	 * fetch next label in domain name
	 */
	while (n = *cp++) {
		/*
		 * Check for indirection
		 */
		switch (n & INDIR_MASK) {
		case 0:
D 2
			if (dn != exp_dn)
E 2
I 2
			if (dn != exp_dn) {
				if (dn >= eom)
					return (-1);
E 2
				*dn++ = '.';
I 2
			}
E 2
			if (dn+n >= eom)
				return (-1);
I 20
			checked += n + 1;
E 20
D 14
			while (--n >= 0)
E 14
I 14
			while (--n >= 0) {
E 14
D 9
				if (islower(c = *cp++))
					*dn++ = toupper(c);
E 9
I 9
D 18
				if (isupper(c = *cp++))
					*dn++ = tolower(c);
E 9
D 2
				else
E 2
I 2
				else {
					if (c == '.') {
						if (dn+n+1 >= eom)
							return (-1);
						*dn++ = '\\';
					}
E 2
					*dn++ = c;
E 18
I 18
				if ((c = *cp++) == '.') {
					if (dn+n+1 >= eom)
						return (-1);
					*dn++ = '\\';
E 18
I 2
				}
I 18
				*dn++ = c;
E 18
I 14
D 15
				if (cp > eomorig)	/* out of range */
E 15
I 15
				if (cp >= eomorig)	/* out of range */
E 15
					return(-1);
			}
E 14
E 2
			break;

		case INDIR_MASK:
D 2
			if (len == 0)
E 2
I 2
			if (len < 0)
E 2
				len = cp - comp_dn + 1;
			cp = msg + (((n & 0x3f) << 8) | (*cp & 0xff));
I 14
D 15
			if (cp < msg || cp > eomorig)	/* out of range */
E 15
I 15
			if (cp < msg || cp >= eomorig)	/* out of range */
E 15
				return(-1);
I 20
			checked += 2;
			/*
			 * Check for loops in the compressed name;
			 * if we've looked at the whole message,
			 * there must be a loop.
			 */
			if (checked >= eomorig - msg)
				return (-1);
E 20
E 14
			break;

		default:
			return (-1);			/* flag error */
		}
	}
	*dn = '\0';
D 2
	if (len == 0)
E 2
I 2
	if (len < 0)
E 2
		len = cp - comp_dn;
	return (len);
}

/*
D 2
 * Compress domain name. Return the size of the compressed name or -1.
 * Dnptrs is a list of pointers to previous compressed names. dnptrs[0]
E 2
I 2
 * Compress domain name 'exp_dn' into 'comp_dn'.
 * Return the size of the compressed name or -1.
 * 'length' is the size of the array pointed to by 'comp_dn'.
 * 'dnptrs' is a list of pointers to previous compressed names. dnptrs[0]
E 2
 * is a pointer to the beginning of the message. The list ends with NULL.
I 2
 * 'lastdnptr' is a pointer to the end of the arrary pointed to
 * by 'dnptrs'. Side effect is to update the list of pointers for
 * labels inserted into the message as we compress the name.
 * If 'dnptr' is NULL, we don't try to compress names. If 'lastdnptr'
 * is NULL, we don't update the list.
E 2
 */
dn_comp(exp_dn, comp_dn, length, dnptrs, lastdnptr)
D 21
	char *exp_dn, *comp_dn;
E 21
I 21
	u_char *exp_dn, *comp_dn;
E 21
	int length;
D 21
	char **dnptrs, **lastdnptr;
E 21
I 21
	u_char **dnptrs, **lastdnptr;
E 21
{
D 21
	register char *cp, *dn;
E 21
I 21
	register u_char *cp, *dn;
E 21
	register int c, l;
D 21
	char **cpp, **lpp, *sp, *eob;
	char *msg;
E 21
I 21
	u_char **cpp, **lpp, *sp, *eob;
	u_char *msg;
E 21

	dn = exp_dn;
	cp = comp_dn;
D 11
	eob = comp_dn + length;
E 11
I 11
	eob = cp + length;
E 11
	if (dnptrs != NULL) {
		if ((msg = *dnptrs++) != NULL) {
			for (cpp = dnptrs; *cpp != NULL; cpp++)
				;
			lpp = cpp;	/* end of list to search */
		}
	} else
		msg = NULL;
	for (c = *dn++; c != '\0'; ) {
		/* look to see if we can use pointers */
		if (msg != NULL) {
			if ((l = dn_find(dn-1, msg, dnptrs, lpp)) >= 0) {
				if (cp+1 >= eob)
					return (-1);
				*cp++ = (l >> 8) | INDIR_MASK;
D 16
				*cp++ = l;
E 16
I 16
				*cp++ = l % 256;
E 16
				return (cp - comp_dn);
			}
			/* not found, save it */
			if (lastdnptr != NULL && cpp < lastdnptr-1) {
				*cpp++ = cp;
				*cpp = NULL;
			}
		}
		sp = cp++;	/* save ptr to length byte */
		do {
			if (c == '.') {
				c = *dn++;
				break;
			}
I 2
			if (c == '\\') {
				if ((c = *dn++) == '\0')
					break;
			}
E 2
			if (cp >= eob)
				return (-1);
			*cp++ = c;
		} while ((c = *dn++) != '\0');
D 2
		if ((l = cp - sp - 1) <= 0 || l > MAXLABEL)
E 2
I 2
		/* catch trailing '.'s but not '..' */
		if ((l = cp - sp - 1) == 0 && c == '\0') {
			cp--;
			break;
		}
		if (l <= 0 || l > MAXLABEL)
E 2
			return (-1);
		*sp = l;
	}
	if (cp >= eob)
		return (-1);
	*cp++ = '\0';
	return (cp - comp_dn);
}

/*
D 2
 * Skip over a compressed domain name. Return the size.
E 2
I 2
 * Skip over a compressed domain name. Return the size or -1.
E 2
 */
D 2
dn_skip(buf)
	char *buf;
E 2
I 2
D 21
dn_skip(comp_dn)
	char *comp_dn;
E 21
I 21
dn_skipname(comp_dn, eom)
	u_char *comp_dn, *eom;
E 21
E 2
{
D 21
	register char *cp;
E 21
I 21
	register u_char *cp;
E 21
	register int n;

D 2
	cp = buf;
E 2
I 2
	cp = comp_dn;
E 2
D 21
	while (n = *cp++) {
E 21
I 21
	while (cp < eom && (n = *cp++)) {
E 21
		/*
		 * check for indirection
		 */
		switch (n & INDIR_MASK) {
		case 0:		/* normal case, n == len */
			cp += n;
			continue;
		default:	/* illegal type */
			return (-1);
		case INDIR_MASK:	/* indirection */
			cp++;
		}
		break;
	}
D 2
	return (cp - buf);
E 2
I 2
	return (cp - comp_dn);
E 2
}

/*
 * Search for expanded name from a list of previously compressed names.
 * Return the offset from msg if found or -1.
I 22
 * dnptrs is the pointer to the first name on the list,
 * not the pointer to the start of the message.
E 22
 */
I 22
static
E 22
dn_find(exp_dn, msg, dnptrs, lastdnptr)
D 21
	char *exp_dn, *msg;
	char **dnptrs, **lastdnptr;
E 21
I 21
	u_char *exp_dn, *msg;
	u_char **dnptrs, **lastdnptr;
E 21
{
D 21
	register char *dn, *cp, **cpp;
E 21
I 21
	register u_char *dn, *cp, **cpp;
E 21
	register int n;
D 21
	char *sp;
E 21
I 21
	u_char *sp;
E 21

D 16
	for (cpp = dnptrs; cpp < lastdnptr; cpp++) {
E 16
I 16
D 22
	for (cpp = dnptrs + 1; cpp < lastdnptr; cpp++) {
E 22
I 22
	for (cpp = dnptrs; cpp < lastdnptr; cpp++) {
E 22
E 16
		dn = exp_dn;
		sp = cp = *cpp;
		while (n = *cp++) {
			/*
			 * check for indirection
			 */
			switch (n & INDIR_MASK) {
			case 0:		/* normal case, n == len */
D 2
				while (--n >= 0)
E 2
I 2
				while (--n >= 0) {
					if (*dn == '\\')
						dn++;
E 2
					if (*dn++ != *cp++)
						goto next;
I 2
				}
E 2
				if ((n = *dn++) == '\0' && *cp == '\0')
					return (sp - msg);
				if (n == '.')
					continue;
				goto next;

			default:	/* illegal type */
				return (-1);

			case INDIR_MASK:	/* indirection */
D 21
				cp = msg + (((n & 0x3f) << 8) | (*cp & 0xff));
E 21
I 21
				cp = msg + (((n & 0x3f) << 8) | *cp);
E 21
			}
		}
		if (*dn == '\0')
			return (sp - msg);
	next:	;
	}
	return (-1);
}
I 3

/*
 * Routines to insert/extract short/long's. Must account for byte
 * order and non-alignment problems. This code at least has the
 * advantage of being portable.
I 24
 *
 * used by sendmail.
E 24
 */

u_short
D 19
getshort(msgp)
E 19
I 19
_getshort(msgp)
E 19
D 21
	char *msgp;
E 21
I 21
	u_char *msgp;
E 21
{
	register u_char *p = (u_char *) msgp;
I 11
#ifdef vax
	/*
	 * vax compiler doesn't put shorts in registers
	 */
	register u_long u;
#else
E 11
I 9
	register u_short u;
I 11
#endif
E 11
E 9

D 9
	return ((*p++ << 8) | *p);
E 9
I 9
	u = *p++ << 8;
D 11
	return (u | *p);
E 11
I 11
	return ((u_short)(u | *p));
E 11
E 9
}

u_long
D 19
getlong(msgp)
E 19
I 19
_getlong(msgp)
E 19
D 21
	char *msgp;
E 21
I 21
	u_char *msgp;
E 21
{
	register u_char *p = (u_char *) msgp;
I 6
	register u_long u;
E 6

D 6
	return ((((((*p++ << 8) | *p++) << 8) | *p++) << 8) | *p);
E 6
I 6
	u = *p++; u <<= 8;
	u |= *p++; u <<= 8;
	u |= *p++; u <<= 8;
	return (u | *p);
E 6
}

D 6
u_short
E 6
I 6

E 6
putshort(s, msgp)
	register u_short s;
D 21
	register char *msgp;
E 21
I 21
	register u_char *msgp;
E 21
{

	msgp[1] = s;
	msgp[0] = s >> 8;
}

D 6
u_long
E 6
putlong(l, msgp)
	register u_long l;
D 21
	register char *msgp;
E 21
I 21
	register u_char *msgp;
E 21
{

	msgp[3] = l;
	msgp[2] = (l >>= 8);
	msgp[1] = (l >>= 8);
	msgp[0] = l >> 8;
}
E 3
E 1
