
# line 1 "config.y"
typedef union  {
	char	*str;
	int	val;
	struct	file_list *file;
	struct	idlst *lst;
} YYSTYPE;
# define AND 257
# define ANY 258
# define ARGS 259
# define AT 260
# define COMMA 261
# define CONFIG 262
# define CONTROLLER 263
# define CPU 264
# define CSR 265
# define DEVICE 266
# define DISK 267
# define DRIVE 268
# define DST 269
# define DUMPS 270
# define EQUALS 271
# define FLAGS 272
# define HZ 273
# define IDENT 274
# define MACHINE 275
# define MAJOR 276
# define MASTER 277
# define MAXUSERS 278
# define MINOR 279
# define MINUS 280
# define NEXUS 281
# define NODE 282
# define ON 283
# define OPTIONS 284
# define MAKEOPTIONS 285
# define PRIORITY 286
# define PSEUDO_DEVICE 287
# define ROOT 288
# define SEMICOLON 289
# define SIZE 290
# define SLAVE 291
# define SWAP 292
# define TIMEZONE 293
# define TRACE 294
# define VECTOR 295
# define ID 296
# define NUMBER 297
# define FPNUMBER 298

# line 65 "config.y"

/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)config.y	5.11 (Berkeley) 3/20/04
 */

#include "config.h"
#include <ctype.h>
#include <stdio.h>

struct	device cur;
struct	device *curp = 0;
char	*temp_id;
char	*val_id;
char	*malloc();

#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern short yyerrflag;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
YYSTYPE yylval, yyval;
# define YYERRCODE 256

# line 497 "config.y"


yyerror(s)
	char *s;
{

	fprintf(stderr, "config: line %d: %s\n", yyline + 1, s);
}

/*
 * return the passed string in a new space
 */
char *
ns(str)
	register char *str;
{
	register char *cp;

	cp = malloc((unsigned)(strlen(str)+1));
	(void) strcpy(cp, str);
	return (cp);
}

/*
 * add a device to the list of devices
 */
newdev(dp)
	register struct device *dp;
{
	register struct device *np;

	np = (struct device *) malloc(sizeof *np);
	*np = *dp;
	np->d_next = 0;
	if (curp == 0)
		dtab = np;
	else
		curp->d_next = np;
	curp = np;
}

/*
 * note that a configuration should be made
 */
mkconf(sysname)
	char *sysname;
{
	register struct file_list *fl, **flp;

	fl = (struct file_list *) malloc(sizeof *fl);
	fl->f_type = SYSTEMSPEC;
	fl->f_needs = sysname;
	fl->f_rootdev = NODEV;
	fl->f_argdev = NODEV;
	fl->f_dumpdev = NODEV;
	fl->f_fn = 0;
	fl->f_next = 0;
	for (flp = confp; *flp; flp = &(*flp)->f_next)
		;
	*flp = fl;
	confp = flp;
}

struct file_list *
newswap()
{
	struct file_list *fl = (struct file_list *)malloc(sizeof (*fl));

	fl->f_type = SWAPSPEC;
	fl->f_next = 0;
	fl->f_swapdev = NODEV;
	fl->f_swapsize = 0;
	fl->f_needs = 0;
	fl->f_fn = 0;
	return (fl);
}

/*
 * Add a swap device to the system's configuration
 */
mkswap(system, fl, size)
	struct file_list *system, *fl;
	int size;
{
	register struct file_list **flp;
	char name[80];

	if (system == 0 || system->f_type != SYSTEMSPEC) {
		yyerror("\"swap\" spec precedes \"config\" specification");
		return;
	}
	if (size < 0) {
		yyerror("illegal swap partition size");
		return;
	}
	/*
	 * Append swap description to the end of the list.
	 */
	flp = &system->f_next;
	for (; *flp && (*flp)->f_type == SWAPSPEC; flp = &(*flp)->f_next)
		;
	fl->f_next = *flp;
	*flp = fl;
	fl->f_swapsize = size;
	/*
	 * If first swap device for this system,
	 * set up f_fn field to insure swap
	 * files are created with unique names.
	 */
	if (system->f_fn)
		return;
	if (eq(fl->f_fn, "generic"))
		system->f_fn = ns(fl->f_fn);
	else
		system->f_fn = ns(system->f_needs);
}

/*
 * find the pointer to connect to the given device and number.
 * returns 0 if no such device and prints an error message
 */
struct device *
connect(dev, num)
	register char *dev;
	register int num;
{
	register struct device *dp;
	struct device *huhcon();

	if (num == QUES)
		return (huhcon(dev));
	for (dp = dtab; dp != 0; dp = dp->d_next) {
		if ((num != dp->d_unit) || !eq(dev, dp->d_name))
			continue;
		if (dp->d_type != CONTROLLER && dp->d_type != MASTER) {
			(void) sprintf(errbuf,
			    "%s connected to non-controller", dev);
			yyerror(errbuf);
			return (0);
		}
		return (dp);
	}
	(void) sprintf(errbuf, "%s %d not defined", dev, num);
	yyerror(errbuf);
	return (0);
}

/*
 * connect to an unspecific thing
 */
struct device *
huhcon(dev)
	register char *dev;
{
	register struct device *dp, *dcp;
	struct device rdev;
	int oldtype;

	/*
	 * First make certain that there are some of these to wildcard on
	 */
	for (dp = dtab; dp != 0; dp = dp->d_next)
		if (eq(dp->d_name, dev))
			break;
	if (dp == 0) {
		(void) sprintf(errbuf, "no %s's to wildcard", dev);
		yyerror(errbuf);
		return (0);
	}
	oldtype = dp->d_type;
	dcp = dp->d_conn;
	/*
	 * Now see if there is already a wildcard entry for this device
	 * (e.g. Search for a "uba ?")
	 */
	for (; dp != 0; dp = dp->d_next)
		if (eq(dev, dp->d_name) && dp->d_unit == -1)
			break;
	/*
	 * If there isn't, make one because everything needs to be connected
	 * to something.
	 */
	if (dp == 0) {
		dp = &rdev;
		init_dev(dp);
		dp->d_unit = QUES;
		dp->d_name = ns(dev);
		dp->d_type = oldtype;
		newdev(dp);
		dp = curp;
		/*
		 * Connect it to the same thing that other similar things are
		 * connected to, but make sure it is a wildcard unit
		 * (e.g. up connected to sc ?, here we make connect sc? to a
		 * uba?).  If other things like this are on the NEXUS or
		 * if they aren't connected to anything, then make the same
		 * connection, else call ourself to connect to another
		 * unspecific device.
		 */
		if (dcp == TO_NEXUS || dcp == 0)
			dp->d_conn = dcp;
		else
			dp->d_conn = connect(dcp->d_name, QUES);
	}
	return (dp);
}

init_dev(dp)
	register struct device *dp;
{

	dp->d_name = "OHNO!!!";
	dp->d_type = DEVICE;
	dp->d_conn = 0;
	dp->d_vec = 0;
	dp->d_addr = dp->d_pri = dp->d_flags = dp->d_dk = 0;
	dp->d_node = dp->d_slave = dp->d_drive = dp->d_unit = UNKNOWN;
}

/*
 * make certain that this is a reasonable type of thing to connect to a nexus
 */
check_nexus(dev, num)
	register struct device *dev;
	int num;
{

	switch (machine) {

	case MACHINE_VAX:
		/*
		 * With peripheral nexi, almost anything can now be connected
		 * to a VAX nexus.
		 */
		if (num != QUES)
			yyerror("can't give specific nexus numbers");
		break;

	case MACHINE_TAHOE:
		if (!eq(dev->d_name, "vba")) 
			yyerror("only vba's should be connected to the nexus");
		break;
	}
}

isadapter(name)
	register char *name;
{
	switch (machine) {
	case MACHINE_VAX:
		if (eq(name, "uba") || eq(name, "mba") || eq(name, "vaxbi") ||
		    eq(name, "xmi") || eq(name, "bva"))
			return(1);
		else
			return(0);
	case MACHINE_TAHOE:
		if (eq(name, "vba"))
			return(1);
		else
			return(0);
	}
}

/*
 * Check the timezone to make certain it is sensible
 */

check_tz()
{
	if (abs(timezone) > 12 * 60)
		yyerror("timezone is unreasonable");
	else
		hadtz = 1;
}

/*
 * Check system specification and apply defaulting
 * rules on root, argument, dump, and swap devices.
 */
checksystemspec(fl)
	register struct file_list *fl;
{
	char buf[BUFSIZ];
	register struct file_list *swap;
	int generic;

	if (fl == 0 || fl->f_type != SYSTEMSPEC) {
		yyerror("internal error, bad system specification");
		exit(1);
	}
	swap = fl->f_next;
	generic = swap && swap->f_type == SWAPSPEC && eq(swap->f_fn, "generic");
	if (fl->f_rootdev == NODEV && !generic) {
		yyerror("no root device specified");
		exit(1);
	}
	/*
	 * Default swap area to be in 'b' partition of root's
	 * device.  If root specified to be other than on 'a'
	 * partition, give warning, something probably amiss.
	 */
	if (swap == 0 || swap->f_type != SWAPSPEC) {
		dev_t dev;

		swap = newswap();
		dev = fl->f_rootdev;
		if (minor(dev) & 07) {
			(void) sprintf(buf, 
"Warning, swap defaulted to 'b' partition with root on '%c' partition",
				(minor(dev) & 07) + 'a');
			yyerror(buf);
		}
		swap->f_swapdev =
		   makedev(major(dev), (minor(dev) &~ 07) | ('b' - 'a'));
		swap->f_fn = devtoname(swap->f_swapdev);
		mkswap(fl, swap, 0);
	}
	/*
	 * Make sure a generic swap isn't specified, along with
	 * other stuff (user must really be confused).
	 */
	if (generic) {
		if (fl->f_rootdev != NODEV)
			yyerror("root device specified with generic swap");
		if (fl->f_argdev != NODEV)
			yyerror("arg device specified with generic swap");
		if (fl->f_dumpdev != NODEV)
			yyerror("dump device specified with generic swap");
		return;
	}
	/*
	 * Default argument device and check for oddball arrangements.
	 */
	if (fl->f_argdev == NODEV)
		fl->f_argdev = swap->f_swapdev;
	if (fl->f_argdev != swap->f_swapdev)
		yyerror("Warning, arg device different than primary swap");
	/*
	 * Default dump device and warn if place is not a
	 * swap area or the argument device partition.
	 */
	if (fl->f_dumpdev == NODEV)
		fl->f_dumpdev = swap->f_swapdev;
	if (fl->f_dumpdev != swap->f_swapdev && fl->f_dumpdev != fl->f_argdev) {
		struct file_list *p = swap->f_next;

		for (; p && p->f_type == SWAPSPEC; p = p->f_next)
			if (fl->f_dumpdev == p->f_swapdev)
				return;
		(void) sprintf(buf, "Warning, orphaned dump device, %s",
			"do you know what you're doing");
		yyerror(buf);
	}
}

/*
 * Verify all devices specified in the system specification
 * are present in the device specifications.
 */
verifysystemspecs()
{
	register struct file_list *fl;
	dev_t checked[50], *verifyswap();
	register dev_t *pchecked = checked;

	for (fl = conf_list; fl; fl = fl->f_next) {
		if (fl->f_type != SYSTEMSPEC)
			continue;
		if (!finddev(fl->f_rootdev))
			deverror(fl->f_needs, "root");
		*pchecked++ = fl->f_rootdev;
		pchecked = verifyswap(fl->f_next, checked, pchecked);
#define	samedev(dev1, dev2) \
	((minor(dev1) &~ 07) != (minor(dev2) &~ 07))
		if (!alreadychecked(fl->f_dumpdev, checked, pchecked)) {
			if (!finddev(fl->f_dumpdev))
				deverror(fl->f_needs, "dump");
			*pchecked++ = fl->f_dumpdev;
		}
		if (!alreadychecked(fl->f_argdev, checked, pchecked)) {
			if (!finddev(fl->f_argdev))
				deverror(fl->f_needs, "arg");
			*pchecked++ = fl->f_argdev;
		}
	}
}

/*
 * Do as above, but for swap devices.
 */
dev_t *
verifyswap(fl, checked, pchecked)
	register struct file_list *fl;
	dev_t checked[];
	register dev_t *pchecked;
{

	for (;fl && fl->f_type == SWAPSPEC; fl = fl->f_next) {
		if (eq(fl->f_fn, "generic"))
			continue;
		if (alreadychecked(fl->f_swapdev, checked, pchecked))
			continue;
		if (!finddev(fl->f_swapdev))
			fprintf(stderr,
			   "config: swap device %s not configured", fl->f_fn);
		*pchecked++ = fl->f_swapdev;
	}
	return (pchecked);
}

/*
 * Has a device already been checked
 * for it's existence in the configuration?
 */
alreadychecked(dev, list, last)
	dev_t dev, list[];
	register dev_t *last;
{
	register dev_t *p;

	for (p = list; p < last; p++)
		if (samedev(*p, dev))
			return (1);
	return (0);
}

deverror(systemname, devtype)
	char *systemname, *devtype;
{

	fprintf(stderr, "config: %s: %s device not configured\n",
		systemname, devtype);
}

/*
 * Look for the device in the list of
 * configured hardware devices.  Must
 * take into account stuff wildcarded.
 */
/*ARGSUSED*/
finddev(dev)
	dev_t dev;
{

	/* punt on this right now */
	return (1);
}
short yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
	};
# define YYNPROD 95
# define YYLAST 213
short yyact[]={

   8,  76,  77,  97,  98, 149,  24,  12,  15,  48,
   9,  11, 146, 144, 111, 143, 142,  20,  18,  14,
 141,  10,  22, 140, 138, 137,  46,  47,  16,  17,
 133,  13, 132,   7,  36,  89, 131,  21,   6, 130,
 123, 136, 102, 101,  94,  90,  49,  45, 147,  36,
  65,  86,  65,  44, 125,  59,  28, 127,  27,  26,
  85, 129,  25,  80, 148,  73,  58, 104,  71, 103,
  75, 126,  74,  72,  70,  63, 134, 106, 110, 121,
 128,  96,  39, 109,  57,  42, 108,  79,  56,  51,
  64,  30,  84,  35,  37,  40,  43,  61,  29, 124,
  87,  62, 105,  60,  55,  34,  54,  53,  52,  31,
  32,  33,  50,  23,  19,  41,  38,   5,   4,   3,
   2,   1, 107, 115, 112,  69, 118, 135,   0,  66,
  67,  68,   0,   0,   0,   0,   0,   0,   0,   0,
  78,   0,   0,   0,   0,  81,  82,  83,   0,  40,
   0,  43,   0,  95,  88, 100,   0,   0,  99,  91,
  92,  93,   0,   0, 122, 114, 117, 120, 113, 116,
 119,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0, 122, 139,   0,   0,   0,   0,   0,   0,   0,
   0,   0, 145 };
short yypact[]={

-1000,-1000,-256,-1000,-227,-230,-231,-1000,-233,-1000,
-1000,-1000,-1000,-1000,-247,-247,-247,-247,-243,-1000,
-250,-271,-251,-204,-247,-1000,-1000,-1000,-1000,-185,
-244,-185,-185,-185,-244,-1000,-1000,-1000,-187,-1000,
-203,-188,-1000,-206,-1000,-1000,-197,-199,-296,-1000,
-204,-1000,-1000,-1000,-1000,-1000,-220,-220,-220,-220,
-1000,-235,-1000,-246,-252,-1000,-235,-235,-235,-253,
-247,-293,-247,-293,-254,-255,-200,-202,-1000,-262,
-1000,-262,-262,-262,-1000,-247,-257,-211,-258,-261,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-1000,-265,-267,-181,-1000,-249,-1000,-1000,
-272,-273,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,
-1000,-1000,-247,-1000,-1000,-274,-277,-281,-282,-284,
-1000,-1000,-1000,-1000,-262,-1000,-285,-248,-215,-1000,
-1000,-1000,-1000,-1000,-1000,-1000,-1000,-1000,-292,-1000 };
short yypgo[]={

   0,  78,  81,  90,  79, 127,  86,  83, 126, 124,
 123, 122, 121, 120, 119, 118, 117, 116, 115, 114,
 113, 112,  89, 108, 107, 106, 104,  87, 102,  77,
  82,  85,  98,  97,  92,  91, 101, 100,  99 };
short yyr1[]={

   0,  12,  13,  13,  14,  14,  14,  14,  14,  16,
  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,
  16,  16,  16,  16,  16,  16,  16,  16,  16,  19,
  20,  21,  21,  22,  22,  22,  22,  23,  28,  28,
  29,  11,  11,  24,   9,   9,  25,  10,  10,  26,
   8,   8,   7,  27,  27,   5,   5,   6,   6,   6,
  17,  17,  30,  30,   2,   2,   1,  18,  18,  31,
   3,  15,  15,  15,  15,  15,  15,  32,  35,  33,
  33,  36,  36,  37,  37,  38,  38,  38,  38,  38,
  34,  34,  34,   4,   4 };
short yyr2[]={

   0,   1,   2,   0,   2,   2,   2,   1,   2,   2,
   2,   2,   2,   2,   1,   2,   2,   4,   3,   2,
   4,   3,   3,   5,   4,   3,   5,   4,   2,   2,
   2,   2,   1,   1,   1,   1,   1,   3,   3,   1,
   2,   1,   1,   3,   1,   1,   3,   1,   1,   3,
   1,   1,   4,   1,   0,   2,   0,   1,   2,   3,
   3,   1,   1,   3,   1,   1,   1,   3,   1,   3,
   1,   4,   4,   4,   4,   3,   4,   3,   0,   2,
   0,   3,   3,   2,   0,   2,   2,   2,   2,   2,
   2,   2,   0,   1,   2 };
short yychk[]={

-1000, -12, -13, -14, -15, -16, 294, 289, 256, 266,
 277, 267, 263, 287, 275, 264, 284, 285, 274, -19,
 273, 293, 278, -20, 262, 289, 289, 289, 289, -32,
 -35, -32, -32, -32, -35,  -1, 296,  -1, -17, -30,
  -1, -18, -31,  -1, 296, 297, 297, 298, 280, 297,
 -21, -22, -23, -24, -25, -26, 292, 288, 270, 259,
  -1, -33, -36, 260,  -3, 296, -33, -33, -33,  -3,
 261, 271, 261, 271, 269, 269, 297, 298, -22, -27,
 283, -27, -27, -27, -34, 295, 286, -37,  -3, 281,
 297, -34, -34, -34, 297, -30,  -2, 296, 297, -31,
  -2, 297, 297, 269, 269, -28, -29, -11,  -6,  -7,
  -1, 276,  -9,  -6,  -7, -10,  -6,  -7,  -8,  -6,
  -7,  -4,  -1, 297, -38, 265, 282, 268, 291, 272,
 297, 297, 297, 297, 257,  -5, 290, 297, 297,  -4,
 297, 297, 297, 297, 297, -29, 297, 296, 279, 297 };
short yydef[]={

   3,  -2,   1,   2,   0,   0,   0,   7,   0,  78,
  78,  78,  78,  78,   0,   0,   0,   0,   0,  14,
   0,   0,   0,   0,   0,   4,   5,   6,   8,  80,
   0,  80,  80,  80,   0,   9,  66,  10,  11,  61,
  62,  12,  68,   0,  13,  15,  16,  19,   0,  28,
  29,  32,  33,  34,  35,  36,  54,  54,  54,  54,
  30,  92,  84,   0,   0,  70,  92,  92,  92,  75,
   0,   0,   0,   0,  18,  21,  22,  25,  31,   0,
  53,   0,   0,   0,  71,   0,   0,  79,   0,   0,
  77,  72,  73,  74,  76,  60,  63,  64,  65,  67,
  69,  17,  20,  24,  27,  37,  39,  56,  41,  42,
  57,   0,  43,  44,  45,  46,  47,  48,  49,  50,
  51,  90,  93,  91,  83,   0,   0,   0,   0,   0,
  81,  82,  23,  26,   0,  40,   0,  58,   0,  94,
  85,  86,  87,  88,  89,  38,  55,  59,   0,  52 };
#ifndef lint
static char yaccpar_sccsid[] = "@(#)yaccpar	4.1	(Berkeley)	2/11/83";
#endif not lint

#
# define YYFLAG -1000
# define YYERROR goto yyerrlab
# define YYACCEPT return(0)
# define YYABORT return(1)

/*	parser for yacc output	*/

#ifdef YYDEBUG
int yydebug = 0; /* 1 for debugging */
#endif
YYSTYPE yyv[YYMAXDEPTH]; /* where the values are stored */
int yychar = -1; /* current input token number */
int yynerrs = 0;  /* number of errors */
short yyerrflag = 0;  /* error recovery flag */

yyparse() {

	short yys[YYMAXDEPTH];
	short yyj, yym;
	register YYSTYPE *yypvt;
	register short yystate, *yyps, yyn;
	register YYSTYPE *yypv;
	register short *yyxi;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyps= &yys[-1];
	yypv= &yyv[-1];

 yystack:    /* put a state and value onto the stack */

#ifdef YYDEBUG
	if( yydebug  ) printf( "state %d, char 0%o\n", yystate, yychar );
#endif
		if( ++yyps> &yys[YYMAXDEPTH] ) { yyerror( "yacc stack overflow" ); return(1); }
		*yyps = yystate;
		++yypv;
		*yypv = yyval;

 yynewstate:

	yyn = yypact[yystate];

	if( yyn<= YYFLAG ) goto yydefault; /* simple state */

	if( yychar<0 ) if( (yychar=yylex())<0 ) yychar=0;
	if( (yyn += yychar)<0 || yyn >= YYLAST ) goto yydefault;

	if( yychk[ yyn=yyact[ yyn ] ] == yychar ){ /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if( yyerrflag > 0 ) --yyerrflag;
		goto yystack;
		}

 yydefault:
	/* default state action */

	if( (yyn=yydef[yystate]) == -2 ) {
		if( yychar<0 ) if( (yychar=yylex())<0 ) yychar = 0;
		/* look through exception table */

		for( yyxi=yyexca; (*yyxi!= (-1)) || (yyxi[1]!=yystate) ; yyxi += 2 ) ; /* VOID */

		while( *(yyxi+=2) >= 0 ){
			if( *yyxi == yychar ) break;
			}
		if( (yyn = yyxi[1]) < 0 ) return(0);   /* accept */
		}

	if( yyn == 0 ){ /* error */
		/* error ... attempt to resume parsing */

		switch( yyerrflag ){

		case 0:   /* brand new error */

			yyerror( "syntax error" );
		yyerrlab:
			++yynerrs;

		case 1:
		case 2: /* incompletely recovered error ... try again */

			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */

			while ( yyps >= yys ) {
			   yyn = yypact[*yyps] + YYERRCODE;
			   if( yyn>= 0 && yyn < YYLAST && yychk[yyact[yyn]] == YYERRCODE ){
			      yystate = yyact[yyn];  /* simulate a shift of "error" */
			      goto yystack;
			      }
			   yyn = yypact[*yyps];

			   /* the current yyps has no shift onn "error", pop stack */

#ifdef YYDEBUG
			   if( yydebug ) printf( "error recovery pops state %d, uncovers %d\n", *yyps, yyps[-1] );
#endif
			   --yyps;
			   --yypv;
			   }

			/* there is no state on the stack with an error shift ... abort */

	yyabort:
			return(1);


		case 3:  /* no shift yet; clobber input char */

#ifdef YYDEBUG
			if( yydebug ) printf( "error recovery discards char %d\n", yychar );
#endif

			if( yychar == 0 ) goto yyabort; /* don't discard EOF, quit */
			yychar = -1;
			goto yynewstate;   /* try again in the same state */

			}

		}

	/* reduction by production yyn */

#ifdef YYDEBUG
		if( yydebug ) printf("reduce %d\n",yyn);
#endif
		yyps -= yyr2[yyn];
		yypvt = yypv;
		yypv -= yyr2[yyn];
		yyval = yypv[1];
		yym=yyn;
			/* consult goto table to find next state */
		yyn = yyr1[yyn];
		yyj = yypgo[yyn] + *yyps + 1;
		if( yyj>=YYLAST || yychk[ yystate = yyact[yyj] ] != -yyn ) yystate = yyact[yypgo[yyn]];
		switch(yym){
			
case 1:
# line 99 "config.y"
 { verifysystemspecs(); } break;
case 4:
# line 110 "config.y"
 { newdev(&cur); } break;
case 6:
# line 114 "config.y"
 { do_trace = !do_trace; } break;
case 9:
# line 122 "config.y"
 {
		if (!strcmp(yypvt[-0].str, "vax")) {
			machine = MACHINE_VAX;
			machinename = "vax";
		} else if (!strcmp(yypvt[-0].str, "tahoe")) {
			machine = MACHINE_TAHOE;
			machinename = "tahoe";
		} else
			yyerror("Unknown machine type");
	      } break;
case 10:
# line 133 "config.y"
 {
		struct cputype *cp =
		    (struct cputype *)malloc(sizeof (struct cputype));
		cp->cpu_name = ns(yypvt[-0].str);
		cp->cpu_next = cputype;
		cputype = cp;
		free(temp_id);
	      } break;
case 13:
# line 146 "config.y"
 { ident = ns(yypvt[-0].str); } break;
case 15:
# line 150 "config.y"
 { yyerror("HZ specification obsolete; delete"); } break;
case 16:
# line 152 "config.y"
 { timezone = 60 * yypvt[-0].val; check_tz(); } break;
case 17:
# line 154 "config.y"
 { timezone = 60 * yypvt[-2].val; dst = yypvt[-0].val; check_tz(); } break;
case 18:
# line 156 "config.y"
 { timezone = 60 * yypvt[-1].val; dst = 1; check_tz(); } break;
case 19:
# line 158 "config.y"
 { timezone = yypvt[-0].val; check_tz(); } break;
case 20:
# line 160 "config.y"
 { timezone = yypvt[-2].val; dst = yypvt[-0].val; check_tz(); } break;
case 21:
# line 162 "config.y"
 { timezone = yypvt[-1].val; dst = 1; check_tz(); } break;
case 22:
# line 164 "config.y"
 { timezone = -60 * yypvt[-0].val; check_tz(); } break;
case 23:
# line 166 "config.y"
 { timezone = -60 * yypvt[-2].val; dst = yypvt[-0].val; check_tz(); } break;
case 24:
# line 168 "config.y"
 { timezone = -60 * yypvt[-1].val; dst = 1; check_tz(); } break;
case 25:
# line 170 "config.y"
 { timezone = -yypvt[-0].val; check_tz(); } break;
case 26:
# line 172 "config.y"
 { timezone = -yypvt[-2].val; dst = yypvt[-0].val; check_tz(); } break;
case 27:
# line 174 "config.y"
 { timezone = -yypvt[-1].val; dst = 1; check_tz(); } break;
case 28:
# line 176 "config.y"
 { maxusers = yypvt[-0].val; } break;
case 29:
# line 180 "config.y"
 { checksystemspec(*confp); } break;
case 30:
# line 185 "config.y"
 { mkconf(yypvt[-0].str); } break;
case 40:
# line 211 "config.y"
 { mkswap(*confp, yypvt[-1].file, yypvt[-0].val); } break;
case 41:
# line 216 "config.y"
 {
			struct file_list *fl = newswap();

			if (eq(yypvt[-0].str, "generic"))
				fl->f_fn = yypvt[-0].str;
			else {
				fl->f_swapdev = nametodev(yypvt[-0].str, 0, 'b');
				fl->f_fn = devtoname(fl->f_swapdev);
			}
			yyval.file = fl;
		} break;
case 42:
# line 228 "config.y"
 {
			struct file_list *fl = newswap();

			fl->f_swapdev = yypvt[-0].val;
			fl->f_fn = devtoname(yypvt[-0].val);
			yyval.file = fl;
		} break;
case 43:
# line 239 "config.y"
 {
			struct file_list *fl = *confp;

			if (fl && fl->f_rootdev != NODEV)
				yyerror("extraneous root device specification");
			else
				fl->f_rootdev = yypvt[-0].val;
		} break;
case 44:
# line 251 "config.y"
 { yyval.val = nametodev(yypvt[-0].str, 0, 'a'); } break;
case 46:
# line 257 "config.y"
 {
			struct file_list *fl = *confp;

			if (fl && fl->f_dumpdev != NODEV)
				yyerror("extraneous dump device specification");
			else
				fl->f_dumpdev = yypvt[-0].val;
		} break;
case 47:
# line 270 "config.y"
 { yyval.val = nametodev(yypvt[-0].str, 0, 'b'); } break;
case 49:
# line 276 "config.y"
 {
			struct file_list *fl = *confp;

			if (fl && fl->f_argdev != NODEV)
				yyerror("extraneous arg device specification");
			else
				fl->f_argdev = yypvt[-0].val;
		} break;
case 50:
# line 288 "config.y"
 { yyval.val = nametodev(yypvt[-0].str, 0, 'b'); } break;
case 52:
# line 294 "config.y"
 { yyval.val = makedev(yypvt[-2].val, yypvt[-0].val); } break;
case 55:
# line 304 "config.y"
 { yyval.val = yypvt[-0].val; } break;
case 56:
# line 306 "config.y"
 { yyval.val = 0; } break;
case 57:
# line 311 "config.y"
 { yyval.str = yypvt[-0].str; } break;
case 58:
# line 313 "config.y"
 {
			char buf[80];

			(void) sprintf(buf, "%s%d", yypvt[-1].str, yypvt[-0].val);
			yyval.str = ns(buf); free(yypvt[-1].str);
		} break;
case 59:
# line 320 "config.y"
 {
			char buf[80];

			(void) sprintf(buf, "%s%d%s", yypvt[-2].str, yypvt[-1].val, yypvt[-0].str);
			yyval.str = ns(buf); free(yypvt[-2].str);
		} break;
case 62:
# line 336 "config.y"
 {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns(yypvt[-0].str);
		op->op_next = opt;
		op->op_value = 0;
		opt = op;
		free(temp_id);
	      } break;
case 63:
# line 345 "config.y"
 {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns(yypvt[-2].str);
		op->op_next = opt;
		op->op_value = ns(yypvt[-0].str);
		opt = op;
		free(temp_id);
		free(val_id);
	      } break;
case 64:
# line 357 "config.y"
 { yyval.str = val_id = ns(yypvt[-0].str); } break;
case 65:
# line 359 "config.y"
 {
		char nb[16];
	        (void) sprintf(nb, "%d", yypvt[-0].val);
		yyval.str = val_id = ns(nb);
	      } break;
case 66:
# line 368 "config.y"
 { yyval.str = temp_id = ns(yypvt[-0].str); } break;
case 69:
# line 379 "config.y"
 {
		struct opt *op = (struct opt *)malloc(sizeof (struct opt));
		op->op_name = ns(yypvt[-2].str);
		op->op_next = mkopt;
		op->op_value = ns(yypvt[-0].str);
		mkopt = op;
		free(temp_id);
		free(val_id);
	      } break;
case 70:
# line 391 "config.y"
 { yyval.str = ns(yypvt[-0].str); } break;
case 71:
# line 396 "config.y"
 { cur.d_type = DEVICE; } break;
case 72:
# line 398 "config.y"
 { cur.d_type = MASTER; } break;
case 73:
# line 400 "config.y"
 { cur.d_dk = 1; cur.d_type = DEVICE; } break;
case 74:
# line 402 "config.y"
 { cur.d_type = CONTROLLER; } break;
case 75:
# line 404 "config.y"
 {
		cur.d_name = yypvt[-0].str;
		cur.d_type = PSEUDO_DEVICE;
		} break;
case 76:
# line 409 "config.y"
 {
		cur.d_name = yypvt[-1].str;
		cur.d_type = PSEUDO_DEVICE;
		cur.d_slave = yypvt[-0].val;
		} break;
case 77:
# line 417 "config.y"
 {
		cur.d_name = yypvt[-1].str;
		if (eq(yypvt[-1].str, "mba"))
			seen_mba = 1;
		else if (eq(yypvt[-1].str, "uba"))
			seen_uba = 1;
		else if (eq(yypvt[-1].str, "bva"))
			seen_bva = 1;
		else if (eq(yypvt[-1].str, "vba"))
			seen_vba = 1;
		cur.d_unit = yypvt[-0].val;
		} break;
case 78:
# line 432 "config.y"
 { init_dev(&cur); } break;
case 81:
# line 442 "config.y"
 {
		if (isadapter(cur.d_name)) {
			(void) sprintf(errbuf,
				"%s must be connected to a nexus", cur.d_name);
			yyerror(errbuf);
		}
		cur.d_conn = connect(yypvt[-1].str, yypvt[-0].val);
		} break;
case 82:
# line 451 "config.y"
 { check_nexus(&cur, yypvt[-0].val); cur.d_conn = TO_NEXUS; } break;
case 85:
# line 461 "config.y"
 { cur.d_addr = yypvt[-0].val; } break;
case 86:
# line 463 "config.y"
 { cur.d_node = yypvt[-0].val; } break;
case 87:
# line 465 "config.y"
 { cur.d_drive = yypvt[-0].val; } break;
case 88:
# line 467 "config.y"
 {
		if (cur.d_conn != 0 && cur.d_conn != TO_NEXUS &&
		    cur.d_conn->d_type == MASTER)
			cur.d_slave = yypvt[-0].val;
		else
			yyerror("can't specify slave--not to master");
		} break;
case 89:
# line 475 "config.y"
 { cur.d_flags = yypvt[-0].val; } break;
case 90:
# line 479 "config.y"
 { cur.d_vec = yypvt[-0].lst; } break;
case 91:
# line 481 "config.y"
 { cur.d_pri = yypvt[-0].val; } break;
case 93:
# line 487 "config.y"
 {
		struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
		a->id = yypvt[-0].str; a->id_next = 0; yyval.lst = a;
		} break;
case 94:
# line 491 "config.y"

		{
		struct idlst *a = (struct idlst *)malloc(sizeof(struct idlst));
	        a->id = yypvt[-1].str; a->id_next = yypvt[-0].lst; yyval.lst = a;
		} break;
		}
		goto yystack;  /* stack new state and value */

	}
