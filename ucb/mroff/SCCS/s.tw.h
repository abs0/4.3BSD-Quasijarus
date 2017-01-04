h38426
s 00031/00000/00000
d D 5.1 04/09/08 16:42:03 msokolov 1 0
c first working version
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/* typewriter driving table structure*/
struct {
	int magic;
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
	char *codetab[512];
	char *zzz;
	} t;
E 1
