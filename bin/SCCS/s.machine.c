h02331
s 00012/00012/00022
d D 5.4 88/06/18 13:13:26 bostic 4 3
c install approved copyright notice
e
s 00012/00005/00022
d D 5.3 87/12/22 12:22:12 bostic 3 2
c add Berkeley header
e
s 00004/00009/00023
d D 5.2 87/05/21 17:30:45 bostic 2 1
c use machine/machparam.h
e
s 00032/00000/00000
d D 5.1 86/07/26 22:17:19 sam 1 0
c date and time created 86/07/26 22:17:19 by sam
e
u
U
t
T
I 1
/*
D 4
 * Copyright (c) 1986 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1986 Regents of the University of California.
E 4
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

#ifndef lint
char copyright[] =
D 3
"@(#) Copyright (c) 1986 Regents of the University of California.\n\
E 3
I 3
D 4
"%Z% Copyright (c) 1986 Regents of the University of California.\n\
E 4
I 4
"%Z% Copyright (c) 1986 Regents of the University of California.\n\
E 4
E 3
 All rights reserved.\n";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */

E 3
D 4

E 4
I 2
#include <sys/param.h>
D 4

E 2
/*
 * machine -- print machine type
 */
E 4

D 2
main(argc,argv)
	char *argv[];
E 2
I 2
main()
E 2
{
D 2

#ifdef vax
	printf("vax\n");
#endif
#ifdef tahoe
	printf("tahoe\n");
#endif
E 2
I 2
	puts(MACHINE);
E 2
	exit(0);
}
E 1
