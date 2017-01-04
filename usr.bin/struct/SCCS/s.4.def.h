h46840
s 00002/00003/00011
d D 4.2 83/08/11 21:07:37 sam 2 1
c standardize sccs keyword lines
e
s 00014/00000/00000
d D 4.1 83/02/11 15:44:53 rrh 1 0
c date and time created 83/02/11 15:44:53 by rrh
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
#define YESTAB	TRUE
#define NOTAB	FALSE
#define TABOVER(n)	tabover(n,outfd)
#define OUTSTR(x)		fprintf(outfd,"%s",x)
#define OUTNUM(x)		fprintf(outfd,"%d",x)


extern LOGICAL *brace;
#define YESBRACE(v,i)	{ if (DEFINED(LCHILD(v,i))) brace[LCHILD(v,i)] = TRUE; }
#define NOBRACE(v,i)	{ if (DEFINED(LCHILD(v,i))) brace[LCHILD(v,i)] = FALSE; }
#define HASBRACE(v,i)	 ((DEFINED(LCHILD(v,i))) ? brace[LCHILD(v,i)] : TRUE)
E 1
