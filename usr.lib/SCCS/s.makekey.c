h07046
s 00016/00001/00019
d D 5.1 85/06/06 09:54:26 dist 2 1
c Add copyright
e
s 00020/00000/00000
d D 4.1 80/10/01 17:27:24 bill 1 0
c date and time created 80/10/01 17:27:24 by bill
e
u
U
t
T
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 2
/*
 * You send it 10 bytes.
 * It sends you 13 bytes.
 * The transformation is expensive to perform
 * (a significant part of a second).
 */

char	*crypt();

main()
{
	char key[8];
	char salt[2];
	
	read(0, key, 8);
	read(0, salt, 2);
	write(1, crypt(key, salt), 13);
	return(0);
}
E 1
