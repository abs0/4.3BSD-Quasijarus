h50405
s 00002/00001/00064
d D 1.2 83/08/11 21:01:56 sam 2 1
c standardize sccs keyword lines
e
s 00065/00000/00000
d D 1.1 82/12/15 21:46:22 clemc 1 0
c date and time created 82/12/15 21:46:22 by clemc
e
u
U
t
Original BTL Ratfor System for 4.2
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
/*	%M%	%I%	%E%	*/

E 2
#include <stdio.h>
#include "y.tab.h"

#
#define	putbak(c)	*ip++ = c
/*	#define	getchr()	(ip>ibuf?*--ip: getc(infile[infptr]))	*/

#define	LET	1
#define	DIG	2
#define	CRAP	3
#define	COMMENT	'#'
#define	QUOTE	'"'

extern int	transfer;

#define	INDENT	3	/* indent delta */
#ifdef	gcos
#define	CONTFLD	6
#endif
#ifdef	unix
#define	CONTFLD	1
#endif
extern	int	contfld;	/* column for continuation char */
extern	int	contchar;
extern	int	dbg;
extern	int	yyval;
extern	int	*yypv;
extern	int	yylval;
extern	int	errorflag;

extern	char	comment[];	/* save input comments here */
extern	int	comptr;	/* next free slot in comment */
extern	int	printcom;	/* print comments, etc., if on */
extern	int	indent;	/* level of nesting for indenting */

extern	char	ibuf[];
extern	char	*ip;

extern	FILE	*outfil;	/* output file id */
extern	FILE	*infile[];
extern	char	*curfile[];
extern	int	infptr;
extern	int	linect[];

extern	char	fcname[];

extern	int	svargc;
extern	char	**svargv;

#define EOS 0
#define	HSHSIZ	101
struct	nlist {
	char	*name;
	char	*def;
	int	ydef;
	struct	nlist *next;
};

struct nlist	*lookup();
char	*install();
char	*malloc();
extern	char	*fcnloc;

extern	char	type[];
E 1
