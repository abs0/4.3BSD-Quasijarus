h01659
s 00010/00005/00073
d D 5.2 88/06/19 14:11:15 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00067
d D 5.1 88/05/08 15:49:40 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00066
d D 1.3 85/04/24 15:30:57 edward 3 2
c copyright messages
e
s 00023/00018/00043
d D 1.2 85/04/23 10:03:58 edward 2 1
c use macros in place of literal constants
e
s 00061/00000/00000
d D 1.1 84/11/18 19:10:35 edward 1 0
c date and time created 84/11/18 19:10:35 by edward
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 4
I 4
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 */

E 3
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% %G%";
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4

#include <stdio.h>
#include <ctype.h>

char *
getcom(buf, size, prompt, error)
	char *buf;
	int size;
	char *prompt, *error;
{
	for (;;) {
		fputs(prompt, stdout); 
D 2
		if (fgets(buf, size, stdin) == 0)
			exit(1);
E 2
I 2
		if (fgets(buf, size, stdin) == 0) {
			clearerr(stdin);
			continue;
		}
E 2
		while (isspace(*buf))
			buf++;
		if (*buf)
			break;
		if (error)
			puts(error);
	}
	return (buf);
}

I 2

/*
 * shifts to UPPERCASE if flag > 0, lowercase if flag < 0,
 * and leaves it unchanged if flag = 0
 */
E 2
char *
getword(buf1, buf2, flag)
D 2
	char *buf1, *buf2;
E 2
I 2
	register char *buf1, *buf2;
	register flag;
E 2
{
D 2
	/* shifts to UPPERCASE if flag > 0, lowercase if    */
	/* flag < 0, and leaves it unchanged if flag = 0    */

E 2
	while (isspace(*buf1))
		buf1++;
	if (*buf1 != ',') {
		if (!*buf1) {
			*buf2 = 0;
			return (0);
		}
		while (*buf1 && !isspace(*buf1) && *buf1 != ',')
D 2
			*buf2++ = shift(*buf1++, flag);
E 2
I 2
			if (flag < 0)
				if (isupper(*buf1))
					*buf2++ = tolower(*buf1++);
				else
					*buf2++ = *buf1++;
			else if (flag > 0)
				if (islower(*buf1))
					*buf2++ = toupper(*buf1++);
				else
					*buf2++ = *buf1++;
			else
				*buf2++ = *buf1++;
E 2
	} else
		*buf2++ = *buf1++;
	*buf2 = 0;
	while (isspace(*buf1))
		buf1++;
	return (*buf1 ? buf1 : 0);
D 2
}

shift(c, flg)
	char c;
	int flg;
{
	if (flg < 0)
		return isupper(c) ? tolower(c) : c;
	if (flg > 0)
		return islower(c) ? toupper(c) : c;
	return c;
E 2
}
E 1
