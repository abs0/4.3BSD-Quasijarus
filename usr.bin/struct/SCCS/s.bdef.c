h30024
s 00008/00000/00000
d D 4.1 83/02/11 15:45:02 rrh 1 0
c date and time created 83/02/11 15:45:02 by rrh
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#define xxtop	100		/* max size of xxstack */
int xxindent, xxval, newflag, xxmaxchars, xxbpertab;
int xxlineno;		/* # of lines already output */
int xxstind, xxstack[xxtop], xxlablast, xxt;
E 1
