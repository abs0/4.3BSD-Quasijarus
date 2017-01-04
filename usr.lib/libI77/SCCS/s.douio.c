h28549
s 00007/00001/00066
d D 5.1 85/06/07 23:44:12 kre 5 4
c Add copyright
e
s 00004/00002/00063
d D 1.4 85/05/21 19:24:25 libs 4 3
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00004/00001/00061
d D 1.3 85/05/02 22:09:15 libs 3 2
c flush record on error if err= specified.
e
s 00002/00002/00060
d D 1.2 81/02/20 18:27:58 dlw 2 1
c changed to F_ER codes. DLW
e
s 00062/00000/00000
d D 1.1 81/02/18 18:01:06 dlw 1 0
c date and time created 81/02/18 18:01:06 by dlw
e
u
U
t
T
I 1
/*
D 5
char id_douio[] = "%W%";
E 5
I 5
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
 *
I 5
 *	%W%	%G%
 */

/*
E 5
 * unformatted external i/o
 */

#include "fio.h"

D 4
char *eor = "eor/uio";
char *uio = "uio";
E 4
I 4
LOCAL char *eor = "eor/uio";
LOCAL char *uio = "uio";
E 4

I 4
LOCAL
E 4
do_us(number,ptr,len) ftnint *number; ftnlen len; char *ptr;  /* sequential */
{
	if(reading)
	{
		recpos += *number * len;
D 3
		if (recpos > reclen)
E 3
I 3
		if (recpos > reclen) {
			recpos -= *number * len;
			e_rsue(); /* in case tries another read */
E 3
D 2
			err(errflag,110,eor);
E 2
I 2
			err(errflag,F_EREREC,eor);
I 3
		}
E 3
E 2

		if (fread(ptr,(int)len,(int)(*number),cf) != *number)
			return(due_err(uio));
	}
	else
	{
		reclen += *number * len;
		fwrite(ptr,(int)len,(int)(*number),cf);
	}
	return(OK);
}

do_uio(number,ptr,len) ftnint *number; ftnlen len; char *ptr;
{
	if(sequential)
		return(do_us(number,ptr,len));
	else
		return(do_ud(number,ptr,len));
}

I 4
LOCAL
E 4
do_ud(number,ptr,len) ftnint *number; ftnlen len; char *ptr;  /* direct */
{
	recpos += *number * len;
	if(recpos > curunit->url && curunit->url!=1)
D 2
		err(errflag,110,eor);
E 2
I 2
		err(errflag,F_EREREC,eor);
E 2
	if(reading)
	{
		if (fread(ptr, (int)len, (int)(*number), cf) != *number)
			return(due_err(uio));
	}
	else
		fwrite(ptr,(int)len,(int)(*number),cf);
	return(OK);
}

due_err(s) char *s;
{
	if(feof(cf))
		err(endflag,EOF,s)
	else
	{	clearerr(cf);
		err(errflag,errno,s)
	}
}
E 1
