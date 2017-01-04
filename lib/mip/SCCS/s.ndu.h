h54907
s 00002/00002/00077
d D 4.2 87/12/10 00:14:57 donn 2 1
c utah rcsid 1.2 86/11/14 19:09:55: Fix dpn and fpn so that they conform to
c the member layout used elsewhere.
e
s 00079/00000/00000
d D 4.1 85/03/19 13:02:05 ralph 1 0
c date and time created 85/03/19 13:02:05 by ralph
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/*
 * This file defines the basic tree node data structure for the PCC.
 */

union ndu {
	struct {		/* interior node */
		int	op;
		int	rall;
		TWORD	type;
		int	su;
#ifndef FLEXNAMES
		char	name[NCHNAM];
#else
		char	*name;
		int	stalign;
#endif
		NODE	*left;
		NODE	*right;
	} in;
	struct {		/* terminal node */
		int	op;
		int	rall;
		TWORD	type;
		int	su;
#ifndef FLEXNAMES
		char	name[NCHNAM];
#else
		char	*name;
		int	stalign;
#endif
		CONSZ	lval;
		int	rval;
	} tn;
	struct {		/* branch node */
		int	op;
		int	rall;
		TWORD	type;
		int	su;
		int	label;		/* for use with branching */
	} bn;
	struct {		/* structure node */
		int	op;
		int	rall;
		TWORD	type;
		int	su;
		int	stsize;		/* sizes of structure objects */
		int	stalign;	/* alignment of structure objects */
	} stn;
	struct {		/* front node */
		int	op;
		int	cdim;
		TWORD	type;
		int	csiz;
	} fn;
	/*
	 * This structure is used when a double precision
	 * floating point constant is being computed
	 */
	struct {			/* DCON node */
		int	op;
D 2
		TWORD	type;
E 2
		int	cdim;
I 2
		TWORD	type;
E 2
		int	csiz;
		double	dval;
	} dpn;
	/*
	 * This structure is used when a single precision
	 * floating point constant is being computed
	 */
	struct {			/* FCON node */
		int	op;
D 2
		TWORD	type;
E 2
		int	cdim;
I 2
		TWORD	type;
E 2
		int	csiz;
		float	fval;
	} fpn;
};
E 1
