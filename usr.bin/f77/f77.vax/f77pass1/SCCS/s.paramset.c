h36843
s 00002/00002/00098
d D 5.2 88/01/03 15:57:21 bostic 2 1
c const is an ANSI C keyword
e
s 00100/00000/00000
d D 5.1 85/06/07 21:43:10 mckusick 1 0
c 4.3BSD beta release version
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
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

/*
 * paramset.c
 *
 * Routines for handling PARAMETER statements, f77 compiler, 4.2 BSD.
 *
 * $Log:	paramset.c,v $
 * Revision 3.2  84/10/13  03:52:03  donn
 * Setting a parameter variable to a nonconstant expression is an error;
 * previously a mere warning was emitted.  Also added a comment header.
 * 
 */

#include "defs.h"
#include "data.h"

/*	process the items in a PARAMETER statement	*/
paramset( param_item_nm, param_item_vl )
Namep param_item_nm;
expptr param_item_vl;
{
  if (param_item_nm->vstg != STGUNKNOWN && param_item_nm->vstg != STGCONST )
    dclerr("conflicting declarations", param_item_nm);
  else if (param_item_nm->vclass == CLUNKNOWN)
    param_item_nm->vclass = CLPARAM;
  else if ( param_item_nm->vclass == CLPARAM )
    dclerr("redefining PARAMETER value", param_item_nm );
  else
    dclerr("conflicting declarations", param_item_nm);

  if (param_item_nm->vclass == CLPARAM)
    {
      if (!ISCONST(param_item_vl))
	param_item_vl = fixtype(param_item_vl);

      if (param_item_nm->vtype == TYUNKNOWN)
	{
	  char c;

	  c = param_item_nm->varname[0];
	  if (c >= 'A' && c <= 'Z')
	    c = c - 'A';
	  else
	    c = c - 'a';
	  param_item_nm->vtype = impltype[c];
	  param_item_nm->vleng = ICON(implleng[c]);
	}
      if (param_item_nm->vtype == TYUNKNOWN)
	{ 
	  warn1("type undefined for %s",
		varstr(VL, param_item_nm->varname));
	  ((struct Paramblock *) (param_item_nm))->paramval = param_item_vl;
	}
      else
	{
	  extern int badvalue;
	  extern expptr constconv();
	  int type;
	  ftnint len;

	  type = param_item_nm->vtype;
	  if (type == TYCHAR)
	    {
	      if (param_item_nm->vleng != NULL)
D 2
		len = param_item_nm->vleng->constblock.const.ci;
E 2
I 2
		len = param_item_nm->vleng->constblock.constant.ci;
E 2
	      else if (ISCONST(param_item_vl) &&
			param_item_vl->constblock.vtype == TYCHAR)
		len = param_item_vl->constblock.vleng->
D 2
			constblock.const.ci;
E 2
I 2
			constblock.constant.ci;
E 2
	      else
		len = 1;
	    }
	  badvalue = 0;
	  if (ISCONST(param_item_vl))
	    {
	      ((struct Paramblock *) (param_item_nm))->paramval =
	        convconst(param_item_nm->vtype, len, param_item_vl);
	      if (type == TYLOGICAL)
		((struct Paramblock *) (param_item_nm))->paramval->
		  headblock.vtype = TYLOGICAL;
	      frexpr((tagptr) param_item_vl);
	    }
	  else
	    {
	      erri("%s set to a nonconstant",
		    varstr(VL, param_item_nm->varname));
	      ((struct Paramblock *) (param_item_nm))->paramval = param_item_vl;
	    }
	}
    }
}
E 1
