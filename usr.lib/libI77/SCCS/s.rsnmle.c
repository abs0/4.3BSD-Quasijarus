h02952
s 00001/00001/00610
d D 5.4 87/12/21 11:31:23 bostic 5 4
c make ANSI C compatible
e
s 00069/00058/00542
d D 5.3 85/08/28 19:31:55 jerry 4 3
c fix bugs in l_L, improve error reporting and recovery.
e
s 00082/00073/00518
d D 5.2 85/08/12 02:27:42 jerry 3 2
c fix bugs
e
s 00000/00000/00591
d D 5.1 85/07/30 16:51:32 jerry 2 1
c 
e
s 00591/00000/00000
d D 1.1 85/07/30 16:39:16 jerry 1 0
c date and time created 85/07/30 16:39:16 by jerry
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

/*
 *		name-list read
 */

#include "fio.h"
#include "lio.h"
#include "nmlio.h"
#include <ctype.h>

D 4
LOCAL char nml_rd[] = "namelist read";
E 4
I 4
LOCAL char *nml_rd;
E 4

static int ch;
I 3
LOCAL nameflag;
LOCAL	char var_name[VL+1];
E 3

#define SP 1
#define B  2
#define AP 4
#define EX 8
I 3
#define INTG 16
#define RL 32
#define LGC 64
#define IRL 		(INTG | RL | LGC )
E 3
#define isblnk(x)	(ltab[x+1]&B)	/* space, tab, newline */
#define issep(x)	(ltab[x+1]&SP)	/* space, tab, newline, comma */
#define isapos(x)	(ltab[x+1]&AP)	/* apost., quote mark */
#define isexp(x)	(ltab[x+1]&EX)	/* d, e, D, E */
I 3
#define isint(x)	(ltab[x+1]&INTG)	/* 0-9, plus, minus */
#define isrl(x)		(ltab[x+1]&RL)	/* 0-9, plus,  minus, period */
#define islgc(x)	(ltab[x+1]&LGC)	/* 0-9, period, t, f, T, F */
E 3

D 4
#define GETC(x) (x=t_getc())
E 4
I 4
#define GETC (ch=t_getc())
E 4
#define UNGETC() ungetc(ch,cf)

LOCAL char *lchar;
LOCAL double lx,ly;
LOCAL int ltype;
int t_getc(), ungetc();

LOCAL char ltab[128+1] =
{			0, 		/* offset one for EOF */
D 3
/*   0- 15 */	0,0,0,0,0,0,0,0,0,SP|B,SP|B,0,0,0,0,0, /* TAB,NEWLINE */
/*  16- 31 */	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/*  32- 47 */	SP|B,0,AP,0,0,0,0,AP,0,0,0,0,SP,0,0,0, /* space,",',comma */
/*  48- 63 */	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/*  64- 79 */	0,0,0,0,EX,EX,0,0,0,0,0,0,0,0,0,0,	/* D,E */
/*  80- 95 */	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/*  96-111 */	0,0,0,0,EX,EX,0,0,0,0,0,0,0,0,0,0,	/* d,e */
/* 112-127 */	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
E 3
I 3
/*   0- 15 */ 0,0,0,0,0,0,0,0,0,SP|B,SP|B,0,0,0,0,0, /* TAB,NEWLINE */
/*  16- 31 */ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/*  32- 47 */ SP|B,0,AP,0,0,0,0,AP,0,0,0,RL|INTG,SP,RL|INTG,RL|LGC,0, /* space,",',comma,., */
/*  48- 63 */ IRL,IRL,IRL,IRL,IRL,IRL,IRL,IRL,IRL,IRL,0,0,0,0,0,0, /* digits */
/*  64- 79 */ 0,0,0,0,EX,EX,LGC,0,0,0,0,0,0,0,0,0,	/* D,E,F */
/*  80- 95 */ 0,0,0,0,LGC,0,0,0,0,0,0,0,0,0,0,0,	/* T */
/*  96-111 */ 0,0,0,0,EX,EX,LGC,0,0,0,0,0,0,0,0,0,	/* d,e,f */
/* 112-127 */ 0,0,0,0,LGC,0,0,0,0,0,0,0,0,0,0,0		/* t */
E 3
};

s_rsne(a) namelist_arglist *a;
{
D 4
	int n, first;
E 4
I 4
	int n;
E 4
	struct namelistentry *entry;
	int nelem, vlen, vtype;
	char *nmlist_nm, *addr;
D 3
	char var_name[VL+1];
E 3

I 4
	nml_rd = "namelist read";
E 4
	reading = YES;
	formatted = NAMELIST;
	fmtbuf = "ext namelist io";
	if(n=c_le(a,READ)) return(n);
D 3
	l_first = YES;
E 3
	getn = t_getc;
	ungetn = ungetc;
	leof = curunit->uend;
D 3
	lcount = 0;
	ltype = NULL;
E 3
	if(curunit->uwrt && ! nowreading(curunit)) err(errflag, errno, nml_rd)

	/* look for " &namelistname " */
	nmlist_nm = a->namelist->namelistname;
D 4
	while(isblnk(GETC(ch))) ;
E 4
I 4
	while(isblnk(GETC)) ;
E 4
	/* check for "&end" (like IBM) or "$end" (like DEC) */
	if(ch != '&' && ch != '$') goto rderr;
	/* save it - write out using the same character as used on input */
	namelistkey_ = ch;
	while( *nmlist_nm )
D 4
		if( GETC(ch) != *nmlist_nm++ ) goto rderr;
	if(!isblnk(GETC(ch))) goto rderr;
	while(isblnk(GETC(ch))) ;
E 4
I 4
		if( GETC != *nmlist_nm++ ) 
			{
				nml_rd = "incorrect namelist name";
				goto rderr;
			}
	if(!isblnk(GETC)) goto rderr;
	while(isblnk(GETC)) ;
E 4
	if(leof) goto rderr;
	UNGETC();

D 4
	while( GETC(ch) != namelistkey_ )
E 4
I 4
	while( GETC != namelistkey_ )
E 4
	{
I 3
	    UNGETC();
E 3
	    /* get variable name */
D 3
	    if(rd_name(var_name)) goto rderr;
E 3
I 3
	    if(!nameflag && rd_name(var_name)) goto rderr;

E 3
	    entry = a->namelist->names;
	    /* loop through namelist entries looking for this variable name */
	    while( entry->varname[0] != 0 )
	    {
		if( strcmp(entry->varname, var_name) == 0 ) goto got_name;
		entry++;
	    }
I 4
	    nml_rd = "incorrect variable name";
E 4
	    goto rderr;
got_name:
D 3
	    if( n= get_pars( entry, &addr, &nelem, &vlen, &vtype ))
E 3
I 3
	    if( n = get_pars( entry, &addr, &nelem, &vlen, &vtype ))
E 3
							goto rderr_n;
D 3
		/*debug*/printf("var=%s, nelem=%x,vlen=%x,vtype=%x\n",
		/*debug*/	var_name, nelem, vlen, vtype);
E 3
D 4
	    while(isblnk(GETC(ch))) ;
E 4
I 4
	    while(isblnk(GETC)) ;
E 4
	    if(ch != '=') goto rderr;
I 3

	    nameflag = NO;
E 3
D 4
	    if(n = l_read( nelem, addr, vlen, vtype )) 
		{
rderr_n:
			err(n<0?endflag:errflag,n,nml_rd)
		}
	    while(isblnk(GETC(ch)));
	    if(ch == ',') while(isblnk(GETC(ch)));
E 4
I 4
	    if(n = l_read( nelem, addr, vlen, vtype )) goto rderr_n;
	    while(isblnk(GETC));
	    if(ch == ',') while(isblnk(GETC));
E 4
	    UNGETC();
	    if(leof) goto rderr;
	}
D 3
	printf("at end record looking for 'end'\n");
E 3
	/* check for 'end' after '&' or '$'*/
D 4
	if(GETC(ch)!='e' || GETC(ch)!='n' || GETC(ch)!='d' )
E 4
I 4
	if(GETC!='e' || GETC!='n' || GETC!='d' )
E 4
		goto rderr;
	/* flush to next input record */
flush:
D 4
	while(GETC(ch) != '\n' && ch != EOF);
E 4
I 4
	while(GETC != '\n' && ch != EOF);
E 4
	return(ch == EOF ? EOF : OK);

rderr:
	if(leof)
D 4
		err(endflag,EOF,nml_rd)
E 4
I 4
		n = EOF;
E 4
	else
D 4
		err(errflag,F_ERNMLIST,nml_rd)
	goto flush;
E 4
I 4
		n = F_ERNMLIST;
rderr_n:
	if(n == EOF ) err(endflag,EOF,nml_rd);
	/* flush after error in case restart I/O */
	if(ch != '\n')  while(GETC != '\n' && ch != EOF) ;
	err(errflag,n,nml_rd)
E 4
}

#define MAXSUBS 7

LOCAL
get_pars( entry, addr, nelem, vlen, vtype )
struct namelistentry *entry;
char	**addr;		/* beginning address to read into */
int	*nelem,		/* number of elements to read */
	*vlen,		/* length of elements */
	*vtype;		/* type of elements */
{
	int	offset, i, n,
		*dimptr,	/* points to dimensioning info */
		ndim,		/* number of dimensions */
		baseoffset,	/* offset of corner element */
		*span,		/* subscript span for each dimension */
		subs[MAXSUBS],	/* actual subscripts */
		subcnt = -1;	/* number of actual subscripts */


	/* get element size and base address */
	*vlen = entry->typelen;
	*addr = entry->varaddr;

	/* get type */
	switch ( *vtype = entry->type ) {
		case TYSHORT:
		case TYLONG:
		case TYREAL:
		case TYDREAL:
		case TYCOMPLEX:
		case TYDCOMPLEX:
		case TYLOGICAL:
		case TYCHAR:
			break;
		default:
D 3
		    fatal(F_ERSYS,"unknown type in wsnmle");
E 3
I 3
		    fatal(F_ERSYS,"unknown type in rsnmle");
E 3
	}

	/* get number of elements */
	dimptr = entry->dimp;
	if( dimptr==NULL )
	{		/* scalar */
		*nelem = 1;
		return(OK);
	}

D 4
	if( GETC(ch) != '(' ) 
E 4
I 4
	if( GETC != '(' ) 
E 4
	{		/* entire array */
		*nelem = dimptr[1];
		UNGETC();
		return(OK);
	}

	/* get element length, number of dimensions, base, span vector */
	ndim = dimptr[0];
	if(ndim<=0 || ndim>MAXSUBS) fatal(F_ERSYS,"illegal dimensions");
	baseoffset = dimptr[2];
	span = dimptr+3;

	/* get subscripts from input data */
	while(ch!=')') {
		if( ++subcnt > MAXSUBS-1 ) return F_ERNMLIST;
		if(n=get_int(&subs[subcnt])) return n;
D 4
		GETC(ch);
E 4
I 4
		GETC;
E 4
		if(leof) return EOF;
		if(ch != ',' && ch != ')') return F_ERNMLIST;
	}
	if( ++subcnt != ndim ) return F_ERNMLIST;
	
	offset = subs[ndim-1];
	for( i = ndim-2; i>=0; i-- )
		offset = subs[i] + span[i]*offset;
	offset -= baseoffset;
	*nelem = dimptr[1] - offset;
D 3
	printf("get_par: *nelem, dimptr[1], offset, baseoffset = %d %d %d %d\n",
			*nelem, dimptr[1], offset, baseoffset );
E 3
	if( offset < 0 || offset >= dimptr[1] )
		return F_ERNMLIST;
	*addr = *addr + (*vlen)*offset;
	return OK;
}

LOCAL
get_int(subval)
int *subval;
{
	int sign=0, value=0, cnt=0;

	/* look for sign */
D 4
	if(GETC(ch) == '-') sign = -1;
E 4
I 4
	if(GETC == '-') sign = -1;
E 4
	else if(ch == '+') ;
	else UNGETC();
	if(ch == EOF) return(EOF);

D 4
	while(isdigit(GETC(ch)))
E 4
I 4
	while(isdigit(GETC))
E 4
	{
		value = 10*value + ch-'0';
		cnt++;
	}
	UNGETC();
D 5
	if(ch == 'EOF') return EOF;
E 5
I 5
	if(ch == EOF) return EOF;
E 5
	if(cnt == 0 ) return F_ERNMLIST;
	if(sign== -1) value = -value;
	*subval = value;
	return OK;
}

LOCAL
rd_name(ptr)
char *ptr;
{
	/* read a variable name from the input stream */
	char *init = ptr-1;

D 3
	if(!isalpha(ch)) {
E 3
I 3
D 4
	if(!isalpha(GETC(ch))) {
E 4
I 4
	if(!isalpha(GETC)) {
E 4
E 3
		UNGETC();
		return(ERROR);
	}
	*ptr++ = ch;
D 4
	while(isalnum(GETC(ch))) 
E 4
I 4
	while(isalnum(GETC)) 
E 4
	{
		if(ptr-init > VL ) return(ERROR);
		*ptr++ = ch;
	}
	*ptr = '\0';
	UNGETC();
	return(OK);
}

LOCAL
t_getc()
{	int ch;
	static newline = YES;
rd:
	if(curunit->uend) {
		leof = EOF;
		return(EOF);
	}
	if((ch=getc(cf))!=EOF)
	{
		if(ch == '\n') newline = YES;
		else if(newline==YES) 
		{	/* skip first character on each line for namelist */
			newline = NO;
			goto rd;
		}
		return(ch);
	}
	if(feof(cf))
	{	curunit->uend = YES;
		leof = EOF;
	}
	else clearerr(cf);
	return(EOF);
}

LOCAL
l_read(number,ptr,len,type) ftnint number,type; flex *ptr; ftnlen len;
{	int i,n;
	double *yy;
	float *xx;
I 3

	lcount = 0;
E 3
	for(i=0;i<number;i++)
	{
		if(leof) return EOF;
D 3
		if(l_first)
		{	l_first = NO;
			while(isblnk(GETC(ch)));	/* skip blanks */
			UNGETC();
		}
		else if(lcount==0)		/* repeat count == 0 ? */
		{	ERRNM(t_sep());  /* look for non-blank, allow 1 comma */
		}
		if(!lr_comm())
E 3
I 3
		if(lcount==0)
E 3
		{
I 3
			ltype = NULL;
			if(i!=0)
			{	/* skip to comma */
D 4
				while(isblnk(GETC(ch)));
E 4
I 4
				while(isblnk(GETC));
E 4
				if(leof) return(EOF);
				if(ch == namelistkey_) 
				{	UNGETC();
					return(OK);
				}
				if(ch != ',' ) return(F_ERNMLIST);
			}
E 3
D 4
			while(isblnk(GETC(ch)));
E 4
I 4
			while(isblnk(GETC));
E 4
I 3
			if(leof) return(EOF);
E 3
			UNGETC();
D 3
			if(ch == namelistkey_ ) return(OK);
E 3
I 3
			if(i!=0 && ch == namelistkey_) return(OK);
E 3

			switch((int)type)
			{
			case TYSHORT:
			case TYLONG:
I 3
				if(!isint(ch)) return(OK);
				ERRNM(l_R(1));
				break;
E 3
			case TYREAL:
			case TYDREAL:
I 3
				if(!isrl(ch)) return(OK);
E 3
				ERRNM(l_R(1));
				break;
			case TYCOMPLEX:
			case TYDCOMPLEX:
I 3
				if(!isdigit(ch) && ch!='(') return(OK);
E 3
				ERRNM(l_C());
				break;
			case TYLOGICAL:
I 3
				if(!islgc(ch)) return(OK);
E 3
				ERRNM(l_L());
I 3
				if(nameflag) return(OK);
E 3
				break;
			case TYCHAR:
I 3
				if(!isdigit(ch) && !isapos(ch)) return(OK);
E 3
				ERRNM(l_CHAR());
				break;
			}
D 3
		}
E 3
		
D 3
 		/* peek at next character;should be separator or namelistkey_ */
 		GETC(ch); UNGETC();
		printf("l_read: peek at %c %x\n", ch, ch);
		if(!issep(ch) && (ch != namelistkey_)) 
E 3
I 3
			if(leof) return(EOF);
 			/* peek at next character -
				should be separator or namelistkey_ */
D 4
 			GETC(ch); UNGETC();
E 4
I 4
 			GETC; UNGETC();
E 4
			if(!issep(ch) && (ch != namelistkey_)) 
E 3
			return( leof?EOF:F_ERNMLIST );
I 3
		}
E 3
 
D 3
		if(ltype) switch((int)type)
E 3
I 3
		if(!ltype) return(F_ERNMLIST);
		switch((int)type)
E 3
		{
		case TYSHORT:
			ptr->flshort=lx;
			break;
		case TYLOGICAL:
			if(len == sizeof(short))
				ptr->flshort = lx;
			else
				ptr->flint = lx;
			break;
		case TYLONG:
			ptr->flint=lx;
			break;
		case TYREAL:
			ptr->flreal=lx;
			break;
		case TYDREAL:
			ptr->fldouble=lx;
			break;
		case TYCOMPLEX:
			xx=(float *)ptr;
			*xx++ = ly;
			*xx = lx;
			break;
		case TYDCOMPLEX:
			yy=(double *)ptr;
			*yy++ = ly;
			*yy = lx;
			break;
		case TYCHAR:
			b_char(lchar,(char *)ptr,len);
			break;
		}
		if(lcount>0) lcount--;
		ptr = (flex *)((char *)ptr + len);
	}
	if(lcount>0) return F_ERNMLIST;
	return(OK);
}

LOCAL
D 3
lr_comm()
{	int ch;
	if(lcount) return(lcount);
	ltype=NULL;
	while(isblnk(GETC(ch)));
	UNGETC();
	if(ch==',')
	{	lcount=1;
		return(lcount);
	}
	return(OK);
}

LOCAL
E 3
get_repet()
D 4
{	char ch;
E 4
I 4
{
E 4
	double lc;
D 4
	if(isdigit(GETC(ch)))
E 4
I 4
	if(isdigit(GETC))
E 4
	{	UNGETC();
		rd_int(&lc);
		lcount = (int)lc;
D 4
		if(GETC(ch)!='*')
E 4
I 4
		if(GETC!='*')
E 4
			if(leof) return(EOF);
			else return(F_ERREPT);
	}
	else
	{	lcount = 1;
		UNGETC();
	}
	return(OK);
}

LOCAL
l_R(flg) int flg;
{	double a,b,c,d;
	int da,db,dc,dd;
D 4
	int i,ch,sign=0;
E 4
I 4
	int i,sign=0;
E 4
	a=b=c=d=0;
	da=db=dc=dd=0;

	if( flg )		/* real */
	{
		da=rd_int(&a);	/* repeat count ? */
D 4
		if(GETC(ch)=='*')
E 4
I 4
		if(GETC=='*')
E 4
		{
			if (a <= 0.) return(F_ERNREP);
			lcount=(int)a;
			db=rd_int(&b);	/* whole part of number */
		}
		else
		{	UNGETC();
			db=da;
			b=a;
			lcount=1;
		}
	}
	else		   /* complex */
	{
		db=rd_int(&b);
	}

D 4
	if(GETC(ch)=='.' && isdigit(GETC(ch)))
E 4
I 4
	if(GETC=='.' && isdigit(GETC))
E 4
	{	UNGETC();
		dc=rd_int(&c);	/* fractional part of number */
	}
	else
	{	UNGETC();
		dc=0;
		c=0.;
	}
D 4
	if(isexp(GETC(ch)))
E 4
I 4
	if(isexp(GETC))
E 4
		dd=rd_int(&d);	/* exponent */
	else if (ch == '+' || ch == '-')
	{	UNGETC();
		dd=rd_int(&d);
	}
	else
	{	UNGETC();
		dd=0;
	}
	if(db<0 || b<0)
	{	sign=1;
		b = -b;
	}
	for(i=0;i<dc;i++) c/=10.;
	b=b+c;
	if (dd > 0)
	{	for(i=0;i<d;i++) b *= 10.;
		for(i=0;i< -d;i++) b /= 10.;
	}
	lx=sign?-b:b;
	ltype=TYLONG;
	return(OK);
}

LOCAL
rd_int(x) double *x;
D 4
{	int ch,sign=0,i=0;
E 4
I 4
{	int sign=0,i=0;
E 4
	double y=0.0;
D 4
	if(GETC(ch)=='-') sign = -1;
E 4
I 4
	if(GETC=='-') sign = -1;
E 4
	else if(ch=='+') sign=0;
	else UNGETC();
D 4
	while(isdigit(GETC(ch)))
E 4
I 4
	while(isdigit(GETC))
E 4
	{	i++;
		y=10*y + ch-'0';
	}
	UNGETC();
	if(sign) y = -y;
	*x = y;
	return(y==0.0?sign:i); /* 0:[+]&&y==0, -1:-&&y==0, >0:#digits&&y!=0 */
}

LOCAL
l_C()
D 4
{	int ch,n;
E 4
I 4
{	int n;
E 4
	if(n=get_repet()) return(n);		/* get repeat count */
D 4
	if(GETC(ch)!='(') err(errflag,F_ERNMLIST,"no (")
	while(isblnk(GETC(ch)));
E 4
I 4
	if(GETC!='(') err(errflag,F_ERNMLIST,"no (")
	while(isblnk(GETC));
E 4
	UNGETC();
	l_R(0);		/* get real part */
	ly = lx;
D 3
	if(t_sep()) return(EOF);
E 3
I 3
D 4
	while(isblnk(GETC(ch)));  /* get comma */
E 4
I 4
	while(isblnk(GETC));  /* get comma */
E 4
	if(leof) return(EOF);
	if(ch!=',') return(F_ERNMLIST);
D 4
	while(isblnk(GETC(ch)));
E 4
I 4
	while(isblnk(GETC));
E 4
	UNGETC();
	if(leof) return(EOF);
E 3
	l_R(0);		/* get imag part */
D 4
	while(isblnk(GETC(ch)));
E 4
I 4
	while(isblnk(GETC));
E 4
	if(ch!=')') err(errflag,F_ERNMLIST,"no )")
	ltype = TYCOMPLEX;
	return(OK);
}

LOCAL
l_L()
{
D 3
	int ch,n;
	if(n=get_repet()) return(n);		/* get repeat count */
	if(GETC(ch)=='.') GETC(ch);
E 3
I 3
D 4
	int n;
	if(!isdigit(ch) && ch != '.')
E 4
I 4
	int n, keychar=ch, scanned=NO;
	if(ch=='f' || ch=='F' || ch=='t' || ch=='T')
E 4
	{
I 4
		scanned=YES;
E 4
		if(rd_name(var_name))
			return(leof?EOF:F_ERNMLIST);
D 4
		while(isblnk(GETC(ch)));
E 4
I 4
		while(isblnk(GETC));
		UNGETC();
E 4
		if(ch == '=' || ch == '(')
		{  	/* found a name, not a value */
D 4
			UNGETC();
E 4
			nameflag = YES;
			return(OK);
		}
	}
	else
	{
		if(n=get_repet()) return(n);		/* get repeat count */
D 4
		if(GETC(ch)=='.') GETC(ch);
E 4
I 4
		if(GETC=='.') GETC;
		keychar = ch;
E 4
	}
E 3
D 4
	switch(ch)
E 4
I 4
	switch(keychar)
E 4
	{
	case 't':
	case 'T':
		lx=1;
		break;
	case 'f':
	case 'F':
		lx=0;
		break;
	default:
D 3
		if(issep(ch))
		{	UNGETC();
			lx=0;
			return(OK);
		}
		else if(ch==EOF) return(EOF);
E 3
I 3
		if(ch==EOF) return(EOF);
E 3
		else	err(errflag,F_ERNMLIST,"logical not T or F");
	}
	ltype=TYLOGICAL;
D 4
	while(!issep(GETC(ch)) && ch!=EOF) ;
	UNGETC();
E 4
I 4
	if(scanned==NO)
	{
		while(!issep(GETC) && ch!=EOF) ;
		UNGETC();
	}
E 4
	if(ch == EOF ) return(EOF);
	return(OK);
}

#define BUFSIZE	128
LOCAL
l_CHAR()
D 4
{	int ch,size,i,n;
E 4
I 4
{	int size,i,n;
E 4
	char quote,*p;
	if(n=get_repet()) return(n);		/* get repeat count */
D 4
	if(isapos(GETC(ch))) quote=ch;
E 4
I 4
	if(isapos(GETC)) quote=ch;
E 4
	else if(ch == EOF) return EOF;
	else return F_ERNMLIST;
	ltype=TYCHAR;
	if(lchar!=NULL) free(lchar);
	size=BUFSIZE-1;
	p=lchar=(char *)malloc(BUFSIZE);
	if(lchar==NULL) return (F_ERSPACE);
	for(i=0;;)
D 4
	{	while( GETC(ch)!=quote && ch!='\n' && ch!=EOF && ++i<size )
E 4
I 4
	{	while( GETC!=quote && ch!='\n' && ch!=EOF && ++i<size )
E 4
				*p++ = ch;
		if(i==size)
		{
		newone:
			size += BUFSIZE;
			lchar=(char *)realloc(lchar, size+1);
			if(lchar==NULL) return( F_ERSPACE );
			p=lchar+i-1;
			*p++ = ch;
		}
		else if(ch==EOF) return(EOF);
		else if(ch=='\n')
		{	if(*(p-1) == '\\') *(p-1) = ch;
		}
D 4
		else if(GETC(ch)==quote)
E 4
I 4
		else if(GETC==quote)
E 4
		{	if(++i<size) *p++ = ch;
			else goto newone;
		}
		else
		{	UNGETC();
			*p = '\0';
			return(OK);
		}
	}
D 3
}

LOCAL
t_sep()
{
	int ch;
	while(isblnk(GETC(ch)));
	if(leof) return(EOF);
	if(issep(ch)) while(isblnk(GETC(ch)));
	if(leof) return(EOF);
	UNGETC();
	return(OK);
E 3
}
E 1
