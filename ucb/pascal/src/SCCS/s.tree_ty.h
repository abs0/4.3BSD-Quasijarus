h54572
s 00007/00003/00327
d D 5.1 85/06/05 16:03:09 dist 8 7
c Add copyright
e
s 00000/00000/00330
d D 2.1 84/02/08 20:52:14 aoki 7 6
c synchronize to version 2
e
s 00011/00002/00319
d D 1.5 84/02/08 00:52:20 mckusick 6 5
c merge in conformant array code by Carol Nishizak
e
s 00001/00001/00320
d D 1.4 83/10/11 06:49:28 thien 5 3
c fixes for lint
e
s 00000/00000/00321
d R 1.4 83/10/11 06:48:24 thien 4 3
c 
e
s 00000/00000/00321
d D 1.3 83/09/19 07:08:53 thien 3 2
c changing to unlinted source
e
s 00314/00026/00007
d D 1.2 83/08/19 05:07:10 thien 2 1
c Changed for linting
e
s 00033/00000/00000
d D 1.1 83/07/05 16:27:36 thien 1 0
c date and time created 83/07/05 16:27:36 by thien
e
u
U
t
T
I 2
D 6
/* Copyright (c) 1979 Regents of the University of California */
E 6
I 6
D 8
/* Copyright (c) 1984 Regents of the University of California */
E 6
 
D 5
/* static char sccsid[]="@(#)tree_ty.h 1.2 7/1/83"; */
E 5
I 5
/* static char sccsid[]="%W%	(Berkeley)	%E%"; */
E 8
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 8
E 5

typedef struct /* T_FORU, T_FORD */
{
    int		line_no; 	/* line number of for */
    struct	tnode	*init_asg;	/* initialization */
    struct	tnode	*term_expr;	/* termination expresssion */
    struct	tnode	*for_stmnt;	/* for statement */
} FOR_NODE;
typedef struct  /* T_ASGN */
{
    int		line_no;	/* line number of := */
    struct	tnode	*lhs_var;
    struct	tnode	*rhs_expr;
} ASG_NODE;
#ifndef PTREE
typedef struct				/* T_VAR */
{
    int 		line_no;
    char		*cptr;
    struct tnode	*qual;		/* list node */
} VAR_NODE;
typedef struct		/* T_FIELD */
{
    char		*id_ptr;
    struct tnode	*other;		
} FIELD_NODE;
#else
typedef struct				/* T_VAR */
{
    int 		line_no;
    char		*cptr;
    struct tnode	*qual;
    struct nl		*nl_entry;
} VAR_NODE;
typedef struct		/* T_FIELD */
{
    char		*id_ptr;
    struct tnode	*other;		
    struct nl		*nl_entry;
} FIELD_NODE;
#endif
typedef struct				/* T_MOD, T_MULT, T_DIVD, T_DIV,
					   T_AND, T_ADD, T_SUB, T_OR,
					   T_EQ, T_LT, T_GT, T_NE, T_LE
					   T_GE, T_IN */
{
    int		const_tag;
    struct	tnode	*lhs;
    struct	tnode	*rhs;
} EXPR_NODE;
typedef struct			/* T_LISTPP */
{
    struct tnode *list;  /* check the types on these,
			    this is used in pclvalue and lvalue */
    struct tnode *next;
} LIST_NODE;
typedef struct			/* T_IF, T_IFEL, T_IFX */
{
    int           line_no;
    struct tnode *cond_expr;
    struct tnode *then_stmnt;
    struct tnode *else_stmnt;
} IF_NODE;
typedef struct			/* T_MINUS, T_PLUS, T_NOT */
{
    int		const_tag;
    struct tnode 	*expr;
} UN_EXPR;
typedef struct /* T_PDEC, T_FDEC, T_PROG */
{
    int	line_no;
    char	*id_ptr;
    struct tnode	*param_list;
    struct tnode	*type;
} P_DEC;
typedef struct	/* T_PVAL, T_PVAR */
{
    struct tnode	*id_list;
    struct tnode	*type;
} PARAM;
typedef struct		/* T_PFUNC, T_PPROC */
{
    struct tnode	*id_list,
			*type,
			*param_list;
    int			line_no;
} PFUNC_NODE;
typedef struct		/* T_NIL */
{
    int	const_tag;
} NIL_NODE;
typedef struct		/* T_STRNG, T_INT, T_FINT, T_BINT */
{
    int		const_tag;
    char	*cptr;
} CONST_NODE;
typedef struct		/* T_CSTRNG, T_ID, T_CFINT, T_CINT, T_CBINT */
{
    char	*cptr;
} CHAR_CONST;
typedef struct		/* T_PLUSC, T_MINUSC */
{
    struct tnode	*number;
} SIGN_CONST;
#ifdef PTREE
typedef struct
{
    int	line_no
    struct tnode	*type;
    struct nl		*nl_entry;
} COMP_TY;
#else
typedef struct		/* T_TYPACK, T_TYSCAL, T_TYFILE, T_TYSET, T_TYREC */
{
    int		  line_no;
    struct tnode *type;
} COMP_TY;
#endif
typedef struct		/* T_TYPTR */
{
    int			 line_no;
    struct tnode	*id_node;
} PTR_TY;
typedef struct		/* T_TYRANG */
{
    int			 line_no;
    struct tnode	*const1;
    struct tnode	*const2;
} RANG_TY;
D 6
typedef struct		/* T_TYARY */
E 6
I 6
typedef struct		/* T_TYCRANG */
E 6
{
    int			 line_no;
I 6
    struct tnode	*lwb_var;
    struct tnode	*upb_var;
    struct tnode	*type;
} CRANG_TY;
typedef struct		/* T_TYARY, T_TYCARY */
{
    int			 line_no;
E 6
    struct tnode	*type_list;
    struct tnode	*type;
} ARY_TY;
typedef struct		/* T_TYVARNT */
{
    int 		 line_no;
    struct tnode	*const_list;
    struct tnode	*fld_list;
} TYVARNT;
typedef struct		/* T_TYVARPT */
{
    int			 line_no;
    char		*cptr;
    struct tnode	*type_id;
    struct tnode	*var_list;
} VARPT;
typedef struct		/* T_CSTAT */
{
    int 		 line_no;
    struct tnode	*const_list;
    struct tnode	*stmnt;
} C_STMNT;
typedef struct		/* T_BSTL, T_BLOCK */
{
    int			line_no;
    struct tnode	*stmnt_list;
} STMNT_BLCK;
typedef struct		/* T_FLDLST */
{
    int 		line_no;
    struct tnode	*fix_list;
    struct tnode	*variant;
} FLDLST;
typedef struct		/* T_RFIELD */
{
    int			line_no;
    struct tnode	*id_list;
    struct tnode	*type;
} RFIELD;
typedef struct		/* T_LABEL */
{
    int 		line_no;
    char		*lbl_ptr;
    struct tnode	*stmnt;
} LABEL_NODE;
typedef struct		/* T_GOTO */
{
    int		line_no;
    char	*lbl_ptr;
} GOTO_NODE;
typedef struct		/* T_PCALL, T_FCALL */
{
    int			line_no;
    char		*proc_id;
    struct tnode	*arg;
} PCALL_NODE;
typedef struct		/* T_CASE, T_WHILE */
{
    int			line_no;
    struct tnode	*expr;
    struct tnode	*stmnt_list;
} WHI_CAS;
typedef struct		/* T_WITH */
{
    int			line_no;
    struct tnode	*var_list;
    struct tnode	*stmnt;
} WITH_NODE;
typedef struct		/* T_REPEAT */
{
    int			line_no;
    struct tnode	*stmnt_list;
    struct tnode	*term_expr;
} REPEAT;
typedef struct		/* T_RANG */
{
    struct tnode	*expr1;
    struct tnode	*expr2;
} RANG;
typedef struct		/* T_CSET */
{
    int			const_tag;
    struct tnode	*el_list;
} CSET_NODE;
typedef struct		/* T_ARY */
{
    struct tnode	*expr_list;
} ARY_NODE;
typedef struct		/* T_WEXPR */
{
    struct tnode	*expr1;
    struct tnode	*expr2;
    struct tnode	*expr3;
} WEXPR_NODE;
typedef struct		/* T_TYID */
{
    int			line_no;
    char		*idptr;
} TYID_NODE;
typedef struct		/* anything with linenumber in first field */
{
    int			line_no;
} LINED;

E 2
I 1
struct tnode
{
    int tag;
    union
    {
D 2
	struct FOR_NODE
	{
	    int		line_no; 	/* line number of for */
	    struct	tnode	*init_asg;	/* initialization */
	    struct	tnode	*term_expr;	/* termination expresssion */
	    struct	tnode	*for_stmnt;	/* for statement */
	} for_node;
	struct ASG_NODE
	{
	    int		line_no;	/* line number of := */
	    struct	tnode	*lhs_var;
	    struct	tnode	*rhs_expr;
	} asg_node;
	struct VAR_NODE
	{
	    int 	line_no;
	    char	*cptr;
	    struct	tnode	*qual;
	    struct	tnode	*fields;
	} var_node;
	struct EXPR_NODE
	{
	    int		const_tag;
	    struct	tnode	*lhs;
	    struct	tnode	*rhs;
	} expr_node;
E 2
I 2
	FOR_NODE	t_for_node;	
	ASG_NODE	t_asg_node;
	VAR_NODE	t_var_node;
	EXPR_NODE	t_expr_node;
	LIST_NODE	t_list_node;
	IF_NODE		t_if_node;
	UN_EXPR		t_un_expr;
	P_DEC		t_p_dec;
	PARAM		t_param;
	PFUNC_NODE	t_pfunc_node;
	NIL_NODE	t_nil_node;
	CONST_NODE	t_const_node;
	CHAR_CONST	t_char_const;
	SIGN_CONST	t_sign_const;
	COMP_TY		t_comp_ty;
	PTR_TY		t_ptr_ty;
	RANG_TY		t_rang_ty;
I 6
	CRANG_TY	t_crang_ty;
E 6
	ARY_TY		t_ary_ty;
	VARPT		t_varpt;
	TYVARNT		t_tyvarnt;
	C_STMNT		t_c_stmnt;
	STMNT_BLCK	t_stmnt_blck;
	FLDLST		t_fldlst;
	RFIELD		t_rfield;
	LABEL_NODE	t_label_node;
	PCALL_NODE	t_pcall_node;
	WHI_CAS		t_whi_cas;
	WITH_NODE	t_with_node;
	REPEAT		t_repeat;
	RANG		t_rang;
	CSET_NODE	t_cset_node;
	ARY_NODE	t_ary_node;
	WEXPR_NODE	t_wexpr_node;
	FIELD_NODE	t_field_node;
	TYID_NODE	t_tyid_node;
	LINED		t_lined;
	GOTO_NODE	t_goto_node;
E 2
    } tree_ele;
};
I 2

#define	for_node		tree_ele.t_for_node	
#define	asg_node		tree_ele.t_asg_node
#define	var_node		tree_ele.t_var_node
#define	expr_node		tree_ele.t_expr_node
#define	list_node tree_ele.t_list_node
#define	if_node			tree_ele.t_if_node
#define	un_expr			tree_ele.t_un_expr
#define	p_dec			tree_ele.t_p_dec
#define	param			tree_ele.t_param
#define	pfunc_node		tree_ele.t_pfunc_node
#define	nil_node		tree_ele.t_nil_node
#define	const_node		tree_ele.t_const_node
#define	char_const		tree_ele.t_char_const
#define	sign_const		tree_ele.t_sign_const
#define	comp_ty			tree_ele.t_comp_ty
#define	ptr_ty			tree_ele.t_ptr_ty
#define	rang_ty			tree_ele.t_rang_ty
I 6
#define	crang_ty		tree_ele.t_crang_ty
E 6
#define	ary_ty			tree_ele.t_ary_ty
#define	varpt			tree_ele.t_varpt
#define	tyvarnt			tree_ele.t_tyvarnt
#define	c_stmnt			tree_ele.t_c_stmnt
#define	stmnt_blck		tree_ele.t_stmnt_blck
#define	fldlst			tree_ele.t_fldlst
#define	rfield			tree_ele.t_rfield
#define	label_node		tree_ele.t_label_node
#define	pcall_node		tree_ele.t_pcall_node
#define	whi_cas			tree_ele.t_whi_cas
#define	with_node		tree_ele.t_with_node
#define	repeat			tree_ele.t_repeat
#define	rang			tree_ele.t_rang
#define	cset_node		tree_ele.t_cset_node
#define	ary_node		tree_ele.t_ary_node
#define	wexpr_node		tree_ele.t_wexpr_node
#define	field_node		tree_ele.t_field_node
#define	tyid_node		tree_ele.t_tyid_node
#define	lined			tree_ele.t_lined
#define	goto_node		tree_ele.t_goto_node
E 2
E 1
