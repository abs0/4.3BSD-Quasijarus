h45766
s 00002/00003/00028
d D 4.2 83/08/11 21:26:40 sam 2 1
c standardize sccs keyword lines
e
s 00031/00000/00000
d D 4.1 82/06/07 15:44:57 rrh 1 0
c date and time created 82/06/07 15:44:57 by rrh
e
u
U
t
T
I 1
D 2
/*
 *	%W% %G%
 */
E 2
I 2
/*	%M%	%I%	%E%	*/

E 2
/* typewriter driving table structure*/
struct {
	int bset;
	int breset;
	int Hor;
	int Vert;
	int Newline;
	int Char;
	int Em;
	int Halfline;
	int Adj;
	char *twinit;
	char *twrest;
	char *twnl;
	char *hlr;
	char *hlf;
	char *flr;
	char *bdon;
	char *bdoff;
	char *ploton;
	char *plotoff;
	char *up;
	char *down;
	char *right;
	char *left;
	char *codetab[256-32];
	char *zzz;
	} t;
E 1
