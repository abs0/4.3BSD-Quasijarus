h41619
s 00002/00003/00010
d D 4.2 83/08/11 21:07:44 sam 2 1
c standardize sccs keyword lines
e
s 00013/00000/00000
d D 4.1 83/02/11 15:44:59 rrh 1 0
c date and time created 83/02/11 15:44:59 by rrh
e
u
U
t
T
I 1
D 2
/*
 *	%W%	(Berkeley)	%E%
 */
E 2
I 2
/*	%M%	%I%	%E%	*/

E 2
extern int xxindent, xxval, newflag, xxmaxchars, xxbpertab;
extern int xxlineno;		/* # of lines already output */
#define xxtop	100		/* max size of xxstack */
extern int xxstind, xxstack[xxtop], xxlablast, xxt;
struct node
	{int op;
	char *lit;
	struct node *left;
	struct node *right;
	};
E 1
