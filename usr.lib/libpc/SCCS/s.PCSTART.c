h13755
s 00004/00003/00095
d D 1.8 83/01/10 18:35:02 mckusick 8 7
c VAX => ADDR32
e
s 00001/00001/00097
d D 1.7 82/07/23 15:09:38 mckusick 7 6
c fix initialization of "input" file
e
s 00011/00001/00087
d D 1.6 82/02/02 23:39:22 mckusic 6 5
c signal EXCEPT() on SIGFPE if runtime tests are enabled
e
s 00000/00001/00088
d D 1.5 81/06/10 00:39:27 mckusic 5 4
c move the text of error messages from ERROR to the functions
c which generate them.
e
s 00004/00000/00085
d D 1.4 81/03/07 15:59:18 mckusic 4 3
c merge in onyx changes
e
s 00001/00000/00084
d D 1.3 81/01/16 16:35:06 mckusic 3 2
c Rewrite the random number generator
e
s 00001/00000/00083
d D 1.2 81/01/16 12:59:14 mckusic 2 1
c add extension to catch runtime errors
e
s 00083/00000/00000
d D 1.1 80/10/30 00:34:19 mckusick 1 0
c date and time created 80/10/30 00:34:19 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

I 6
#include <signal.h>
E 6
#include "h00vars.h"
I 6
#include "libpc.h"
E 6

/*
 * program variables
 */
struct display	_disply[MAXLVL];
int		_argc;
char		**_argv;
long		_stlim = 500000;
long		_stcnt = 0;
I 3
long		_seed = 1;
I 4
D 8
#ifdef VAX
E 8
I 8
#ifdef ADDR32
E 8
E 4
E 3
char		*_minptr = (char *)0x7fffffff;
I 4
D 8
#else
E 8
I 8
#endif ADDR32
#ifdef ADDR16
E 8
char		*_minptr = (char *)0xffff;
D 8
#endif VAX
E 8
I 8
#endif ADDR16
E 8
E 4
char		*_maxptr = (char *)0;
I 2
D 5
struct errentry _entry[MAXERRS];
E 5
E 2

/*
 * file record variables
 */
long		_filefre = PREDEF;
struct iorechd	_fchain = {
	0, 0, 0, 0,		/* only use fchain field */
	INPUT			/* fchain  */
};
struct iorec	*_actfile[MAXFILES] = {
	INPUT,
	OUTPUT,
	ERR
};

/*
 * standard files
 */
char		_inwin, _outwin, _errwin;
struct iorechd	input = {
	&_inwin,		/* fileptr */
	0,			/* lcount  */
	0x7fffffff,		/* llimit  */
	&_iob[0],		/* fbuf    */
	OUTPUT,			/* fchain  */
	STDLVL,			/* flev    */
	"standard input",	/* pfname  */
D 7
	FTEXT | FREAD | SYNC,	/* funit   */
E 7
I 7
	FTEXT|FREAD|SYNC|EOLN,	/* funit   */
E 7
	0,			/* fblk    */
	1			/* fsize   */
};
struct iorechd	output = {
	&_outwin,		/* fileptr */
	0,			/* lcount  */
	0x7fffffff,		/* llimit  */
	&_iob[1],		/* fbuf    */
	ERR,			/* fchain  */
	STDLVL,			/* flev    */
	"standard output",	/* pfname  */
	FTEXT | FWRITE | EOFF,	/* funit   */
	1,			/* fblk    */
	1			/* fsize   */
};
struct iorechd	_err = {
	&_errwin,		/* fileptr */
	0,			/* lcount  */
	0x7fffffff,		/* llimit  */
	&_iob[2],		/* fbuf    */
	FILNIL,			/* fchain  */
	STDLVL,			/* flev    */
	"Message file",		/* pfname  */
	FTEXT | FWRITE | EOFF,	/* funit   */
	2,			/* fblk    */
	1			/* fsize   */
};

D 6
PCSTART()
E 6
I 6
PCSTART(mode)
	int mode;
E 6
{
	/*
	 * necessary only on systems which do not initialize
	 * memory to zero
	 */

	struct iorec	**ip;

I 6
	/*
	 * if running with runtime tests enabled, give more
	 * coherent error messages for FPEs
	 */
	if (mode) {
		signal(SIGFPE, EXCEPT);
	}
E 6
	for (ip = &_actfile[3]; ip < &_actfile[MAXFILES]; *ip++ = FILNIL);
}
E 1
