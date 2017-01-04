h44145
s 00000/00000/00049
d D 5.1 85/07/30 16:51:30 jerry 2 1
c 
e
s 00049/00000/00000
d D 1.1 85/07/30 16:38:47 jerry 1 0
c date and time created 85/07/30 16:38:47 by jerry
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
 *
 *	%W%	%G%
 */

/*	header for namelist I/O */

#define ERRNM(x)	if(n=(x)) return(n);
#define VL		16	/* variable name length from f77pass1/defs.h */

extern char namelistkey_;

typedef struct
{
	char namelistname[VL+4];	/* 4 for padding */
	struct namelistentry
		{
		char varname[VL+4];	/* 4 for padding */
		char *varaddr;
		short int type;
		short int typelen;
		/*
		 * If dimp is not null, then the corner element of the array is
		 * at varaddr.  However,  the element with subscripts:
		 * (i1,...,in) is at
		 *
		 *	varaddr - dimp->baseoffset + sizeoftype *
		 *			((i1-1)+span[0]*((i2-1)+span[1]*...)
		 */
		int *dimp;	/* dimension info: (null means scalar)
					*dimp: numb. of dim.,
					dimp[0]: number of dimensions
					dimp[1]: total number of elements,
					dimp[2]: base offset,
					dimp[3]: span of 1st dimension
					dimp[4]: span of 2nd dimension
						...			 */
		} names[1];	/* actually one per name in the namelist */
} Namelist;

typedef struct
{	flag cierr;
	ftnint ciunit;
	flag ciend;
	Namelist *namelist;
} namelist_arglist;
E 1
