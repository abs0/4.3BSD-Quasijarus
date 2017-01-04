h23127
s 00010/00005/00079
d D 5.6 88/06/27 17:34:14 bostic 6 5
c install approved copyright notice
e
s 00009/00003/00075
d D 5.5 87/11/24 15:55:57 bostic 5 4
c Berkeley code, fix copyright
e
s 00018/00012/00060
d D 5.4 87/11/23 15:34:49 bostic 4 3
c should be unsigned chars as offsets into comparison table
e
s 00001/00001/00071
d D 5.3 87/08/03 17:17:50 bostic 3 2
c change strcasencmp to strncasecmp
e
s 00049/00028/00023
d D 5.2 87/07/02 14:41:58 bostic 2 1
c new version with case table lookup; ripped off from nameserver
e
s 00051/00000/00000
d D 5.1 87/07/02 09:10:33 bostic 1 0
c date and time created 87/07/02 09:10:33 by bostic
e
u
U
t
T
I 1
/*
D 5
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
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

#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif LIBC_SCCS and not lint
E 4
I 4
#endif /* LIBC_SCCS and not lint */
E 4

I 4
#include <sys/types.h>

E 4
D 2
#include <ctype.h>

E 2
/*
D 2
 * Compare strings:  s1>s2: >0  s1==s2: 0  s1<s2: <0
 * case insensitive
E 2
I 2
 * This array is designed for mapping upper and lower case letter
 * together for a case independent comparison.  The mappings are
 * based upon ascii character sequences.
E 2
 */
I 2
D 4
static char charmap[] = {
E 4
I 4
static u_char charmap[] = {
E 4
	'\000', '\001', '\002', '\003', '\004', '\005', '\006', '\007',
	'\010', '\011', '\012', '\013', '\014', '\015', '\016', '\017',
	'\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
	'\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
	'\040', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
	'\050', '\051', '\052', '\053', '\054', '\055', '\056', '\057',
	'\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
	'\070', '\071', '\072', '\073', '\074', '\075', '\076', '\077',
	'\100', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
	'\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
	'\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
	'\170', '\171', '\172', '\133', '\134', '\135', '\136', '\137',
	'\140', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
	'\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
	'\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
	'\170', '\171', '\172', '\173', '\174', '\175', '\176', '\177',
	'\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
	'\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
	'\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
	'\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
	'\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
	'\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
	'\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
	'\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
	'\300', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
	'\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
	'\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
	'\370', '\371', '\372', '\333', '\334', '\335', '\336', '\337',
	'\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
	'\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
	'\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
	'\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377',
};

E 2
strcasecmp(s1, s2)
D 2
	register char	*s1, *s2;
E 2
I 2
D 4
	register char *s1, *s2;
E 4
I 4
	char *s1, *s2;
E 4
E 2
{
D 2
	register char	c1, c2;
E 2
I 2
D 4
	register char *cm = charmap;
E 4
I 4
	register u_char	*cm = charmap,
			*us1 = (u_char *)s1,
			*us2 = (u_char *)s2;
E 4
E 2

D 2
	for (;; ++s1, ++s2) {
		c2 = isupper(*s2) ? tolower(*s2) : *s2;
		c1 = isupper(*s1) ? tolower(*s1) : *s1;
		if (c1 != c2)
			return(c1 - c2);
		if (!c1)
E 2
I 2
D 4
	while (cm[*s1] == cm[*s2++])
		if (*s1++ == '\0')
E 4
I 4
	while (cm[*us1] == cm[*us2++])
		if (*us1++ == '\0')
E 4
E 2
			return(0);
D 2
	}
E 2
I 2
D 4
	return(cm[*s1] - cm[*--s2]);
E 4
I 4
	return(cm[*us1] - cm[*--us2]);
E 4
E 2
}

D 2
/*
 * Compare strings (at most n bytes):  s1>s2: >0  s1==s2: 0  s1<s2: <0
 * case insensitive
 */
E 2
D 3
strcasencmp(s1, s2, n)
E 3
I 3
strncasecmp(s1, s2, n)
E 3
D 2
	register char	*s1, *s2;
	register int	n;
E 2
I 2
D 4
	register char *s1, *s2;
E 4
I 4
	char *s1, *s2;
E 4
	register int n;
E 2
{
D 2
	register char	c1, c2;
E 2
I 2
D 4
	register char *cm = charmap;
E 4
I 4
	register u_char	*cm = charmap,
			*us1 = (u_char *)s1,
			*us2 = (u_char *)s2;
E 4
E 2

D 2
	for (; n; ++s1, ++s2, --n) {
		c2 = isupper(*s2) ? tolower(*s2) : *s2;
		c1 = isupper(*s1) ? tolower(*s1) : *s1;
		if (c1 != c2)
			return(c1 - c2);
		if (!c1)
E 2
I 2
D 4
	while (--n >= 0 && cm[*s1] == cm[*s2++])
		if (*s1++ == '\0')
E 4
I 4
	while (--n >= 0 && cm[*us1] == cm[*us2++])
		if (*us1++ == '\0')
E 4
E 2
			return(0);
D 2
	}
	return(0);
E 2
I 2
D 4
	return(n < 0 ? 0 : cm[*s1] - cm[*--s2]);
E 4
I 4
	return(n < 0 ? 0 : cm[*us1] - cm[*--us2]);
E 4
E 2
}
E 1
