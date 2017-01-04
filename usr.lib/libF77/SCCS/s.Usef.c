h19058
s 00001/00002/00036
d D 1.3 87/09/14 14:57:59 bostic 3 2
c check first element in list; bug report 4.3BSD/usr.lib/58
e
s 00001/00001/00037
d D 1.2 85/08/01 17:28:55 bloom 2 1
c Fix sccsid line
e
s 00038/00000/00000
d D 1.1 85/07/30 16:44:08 jerry 1 0
c date and time created 85/07/30 16:44:08 by jerry
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
D 2
 *	%W%	%G%	*/
E 2
I 2
 *	%W%	%G%
E 2
 */

/*		returns '-f' if need to use -f to bypass C bug		*/

static char *needs_f[] = {
	"besj0_", "besj1_", "besjn_", "besy0_", "besy1_", "besyn_",
	"c_abs", "erf_", "erfc_", "r_abs", "r_acos", "r_asin",
	"r_atan", "r_atn2", "r_cos", "r_cosh", "r_exp", "r_imag",
	"r_int", "r_lg10", "r_log", "r_sign", "r_sin",
	"r_sinh", "r_sqrt", "r_tan", "r_tanh", "rand_", "random_",
	0,
	};

main(argc, argv)
int argc;
char **argv;
{
	char **ptr;

	argv++;
	ptr = needs_f;
	while( *ptr != 0 ) {
D 3
		ptr++;
		if( strcmp( *ptr, *argv ) == 0 )
E 3
I 3
		if( strcmp( *ptr++, *argv ) == 0 )
E 3
		{
			printf("-f");
			exit(0);
		}
	}
	printf(" ");
	exit(0);
}
E 1
