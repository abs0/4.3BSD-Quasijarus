h36977
s 00002/00003/00006
d D 4.2 83/08/11 21:07:33 sam 2 1
c standardize sccs keyword lines
e
s 00009/00000/00000
d D 4.1 83/02/11 15:44:38 rrh 1 0
c date and time created 83/02/11 15:44:38 by rrh
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
#define RECURSE(p,v,r)	{ for (r = 0; r < CHILDNUM(v); ++r) if (DEFINED(LCHILD(v,r))) p(LCHILD(v,r)); if (DEFINED(RSIB(v))) p(RSIB(v)); }

#define IFTHEN(v)		( NTYPE(v) == IFVX && !DEFINED(LCHILD(v,ELSE)))

#define BRK(v)	FATH(v)		/* lexical successor of v, for ITERVX only */
#define LABEL(v)	REACH(v)
E 1
