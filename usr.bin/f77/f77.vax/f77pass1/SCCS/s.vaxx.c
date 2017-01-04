h57700
s 00052/00000/00000
d D 5.1 85/06/07 21:47:59 mckusick 1 0
c 4.3BSD beta release version
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

#include <stdio.h>
#include "defines.h"
#include "machdefs.h"



prchars(fp, s)
FILEP fp;
int *s;
{

fprintf(fp, ".byte 0%o,0%o\n", s[0], s[1]);
}



pruse(fp, s)
FILEP fp;
char *s;
{
fprintf(fp, "\t%s\n", s);
}



prskip(fp, k)
FILEP fp;
ftnint k;
{
fprintf(fp, "\t.space\t%ld\n", k);
}





prcomblock(fp, name)
FILEP fp;
char *name;
{
fprintf(fp, LABELFMT, name);
}
E 1
