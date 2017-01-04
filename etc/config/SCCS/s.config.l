h29735
s 00002/00000/00175
d D 5.6 04/03/02 17:49:24 msokolov 20 19
c redesign handling of VAXBI and peripheral nexus devices
e
s 00010/00005/00165
d D 5.5 88/06/18 13:42:59 bostic 19 18
c install approved copyright notice
e
s 00008/00005/00162
d D 5.4 88/05/21 16:40:45 karels 18 17
c pretend bi's connect to nexi; delete unnecessary keywords
e
s 00001/00000/00166
d D 5.3 86/10/13 15:35:27 sam 17 16
c replace ancient sun support with tahoe support
e
s 00001/00000/00165
d D 5.2 86/04/18 14:24:47 karels 16 15
c add makeoptions (for uVaxII and other such needs)
e
s 00008/00001/00157
d D 5.1 85/05/08 11:58:56 dist 15 14
c Add copyright
e
s 00001/00001/00157
d D 1.14 83/05/18 12:17:31 sam 14 13
c accept upper case hex constants
e
s 00037/00010/00121
d D 1.13 83/05/18 00:19:26 sam 13 12
c dynamically create swap configuration files
e
s 00013/00015/00118
d D 1.12 82/10/25 00:58:37 root 12 11
c lint and cleanup
e
s 00003/00001/00130
d D 1.11 82/10/24 22:52:52 root 11 10
c fixes from sun
e
s 00000/00001/00131
d D 1.10 82/10/11 10:46:51 sam 10 9
c happily delete '@' as a synonym for 'at' (permission by kre)
e
s 00005/00001/00127
d D 1.9 82/07/21 22:32:08 kre 9 8
c allow comments other than at start of line;
c add '=' (for options with values); make @ a synonym for "at";
c pass unrecognized chars back to yacc as themselves (yacc knows
c about errors, & doesn't just print unknown crap on stdout).
e
s 00003/00000/00125
d D 1.8 81/05/18 01:30:27 root 8 7
c implement - timezones
e
s 00005/00000/00120
d D 1.7 81/04/02 17:45:17 toy 7 6
c Added quoated identifiers
e
s 00002/00000/00118
d D 1.6 81/03/31 16:35:12 toy 6 5
c Added MASTER and COMMA for option list
e
s 00006/00000/00112
d D 1.5 81/03/06 21:36:53 toy 5 4
c Bill's changes + some of mine
e
s 00001/00001/00111
d D 1.4 81/02/26 12:47:56 wnj 4 3
c stamp for sending to dec... still bugs in mkioconf.c
e
s 00001/00001/00111
d D 1.3 81/02/25 15:49:18 toy 3 2
c "tape" means device.
e
s 00004/00001/00108
d D 1.2 81/02/24 20:03:18 toy 2 1
c Restored version
e
s 00109/00000/00000
d D 1.1 81/02/24 19:58:38 toy 1 0
c date and time created 81/02/24 19:58:38 by toy
e
u
U
t
T
I 1
%{
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15

/*
 * Copyright (c) 1980 Regents of the University of California.
D 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 18
I 18
 * All rights reserved.
E 18
 *
I 18
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
 *
E 18
 *	%W% (Berkeley) %G%
 */
E 15

#include <ctype.h>
#include "y.tab.h"
#include "config.h"

#define tprintf if (do_trace) printf
I 2

D 12
int yylval;

E 12
E 2
/*
 * Key word table
 */

struct kt {
	char *kt_name;
	int kt_val;
} key_words[] = {
I 20
	{ "adapter",	CONTROLLER },
E 20
I 11
D 13
	"machine", MACHINE,
E 11
	"cpu", CPU, "ident", IDENT, "config", CONFIG, "options", OPTIONS,
	"device", DEVICE, "controller", CONTROLLER, "uba", UBA, "mba", MBA,
	"csr", CSR, "nexus", NEXUS, "drive", DRIVE, "vector", VECTOR,
	"pseudo-device", PSEUDO_DEVICE, "flags", FLAGS, "trace", TRACE,
D 3
	"disk", DISK, "tape", CONTROLLER, "slave", SLAVE, "at", AT,
E 3
I 3
	"disk", DISK, "tape", DEVICE, "slave", SLAVE, "at", AT,
I 5
	"hz", HZ, "timezone", TIMEZONE, "dst", DST, "maxusers", MAXUSERS,
I 6
D 11
	"master", MASTER,
E 11
I 11
	"master", MASTER, "priority", PRIORITY,
E 11
E 6
E 5
E 3
	0,0,
E 13
I 13
	{ "and",	AND },
	{ "args",	ARGS },
	{ "at",		AT },
	{ "config",	CONFIG },
	{ "controller",	CONTROLLER },
	{ "cpu",	CPU },
	{ "csr",	CSR },
	{ "device",	DEVICE },
	{ "disk",	DISK },
	{ "drive",	DRIVE },
	{ "dst",	DST },
	{ "dumps",	DUMPS },
	{ "flags",	FLAGS },
	{ "hz",		HZ },
	{ "ident",	IDENT },
	{ "machine",	MACHINE },
	{ "major",	MAJOR },
I 16
	{ "makeoptions", MAKEOPTIONS },
E 16
	{ "master",	MASTER },
	{ "maxusers",	MAXUSERS },
D 18
	{ "mba",	MBA },
E 18
	{ "minor",	MINOR },
	{ "nexus",	NEXUS },
I 20
	{ "node",	NODE },
E 20
	{ "on",		ON },
	{ "options",	OPTIONS },
	{ "priority",	PRIORITY },
	{ "pseudo-device",PSEUDO_DEVICE },
	{ "root",	ROOT },
	{ "size",	SIZE },
	{ "slave",	SLAVE },
	{ "swap",	SWAP },
	{ "tape",	DEVICE },
	{ "timezone",	TIMEZONE },
	{ "trace",	TRACE },
D 18
	{ "uba",	UBA },
I 17
	{ "vba",	VBA },
E 18
E 17
	{ "vector",	VECTOR },
	{ 0, 0 },
E 13
};
%}
D 2
WORD	[A-Za-z_]+
E 2
I 2
WORD	[A-Za-z_][-A-Za-z_]*
E 2
%%
{WORD}		{
			int i;

			if ((i = kw_lookup(yytext)) == -1)
			{
D 12
				yylval = (int) yytext;
E 12
I 12
				yylval.str = yytext;
E 12
				tprintf("id(%s) ", yytext);
				return ID;
			}
			tprintf("(%s) ", yytext);
			return i;
		}
I 7
\"[^"]+\"	{
			yytext[strlen(yytext)-1] = '\0';
D 12
			yylval = (int) yytext + 1;
E 12
I 12
D 13
			yylval.val = yytext + 1;
E 13
I 13
			yylval.str = yytext + 1;
E 13
E 12
			return ID;
		}
E 7
0[0-7]*		{
D 12
			yylval = octal(yytext);
			tprintf("#O:%o ", yylval);
E 12
I 12
			yylval.val = octal(yytext);
			tprintf("#O:%o ", yylval.val);
E 12
			return NUMBER;
		}
D 14
0x[0-9a-f]+	{
E 14
I 14
0x[0-9a-fA-F]+	{
E 14
D 12
			yylval = hex(yytext);
			tprintf("#X:%x ", yylval);
E 12
I 12
			yylval.val = hex(yytext);
			tprintf("#X:%x ", yylval.val);
E 12
			return NUMBER;
		}
[1-9][0-9]*	{
D 12
			yylval = atoi(yytext);
			tprintf("#D:%d ", yylval);
E 12
I 12
			yylval.val = atoi(yytext);
			tprintf("#D:%d ", yylval.val);
E 12
			return NUMBER;
I 5
		}
[0-9]"."[0-9]*	{
D 12
			float atof();
			yylval = (int) (60 * atof(yytext) + 0.5);
E 12
I 12
			double atof();
			yylval.val = (int) (60 * atof(yytext) + 0.5);
E 12
			return FPNUMBER;
E 5
		}
I 8
"-"		{
			return MINUS;
		}
E 8
"?"		{
D 12
			yylval = -1;
E 12
I 12
			yylval.val = -1;
E 12
			tprintf("? ");
			return NUMBER;
		}
\n/[ \t]	{
			yyline++;
			tprintf("\n... ");
		}
\n		{
			yyline++;
			tprintf("\n");
			return SEMICOLON;
		}
D 9
^#.*		{	/* Ignored (comment) */;	}
E 9
I 9
#.*		{	/* Ignored (comment) */;	}
E 9
[ \t]*		{	/* Ignored (white space) */;	}
";"		{	return SEMICOLON;		}
I 6
","		{	return COMMA;			}
I 9
"="		{	return EQUALS;			}
I 11
"@"		{	return AT;			}
E 11
D 10
"@"		{	return AT;			}
E 10
.		{	return yytext[0];		}

E 9
E 6
%%
/*
 * kw_lookup
 *	Look up a string in the keyword table.  Returns a -1 if the
 *	string is not a keyword otherwise it returns the keyword number
 */

kw_lookup(word)
register char *word;
{
	register struct kt *kp;

	for (kp = key_words; kp->kt_name != 0; kp++)
		if (eq(word, kp->kt_name))
			return kp->kt_val;
	return -1;
}

/*
 * Number conversion routines
 */

octal(str)
char *str;
{
	int num;

D 12
	sscanf(str, "%o", &num);
E 12
I 12
	(void) sscanf(str, "%o", &num);
E 12
	return num;
}

hex(str)
char *str;
{
	int num;

D 4
	sscanf(str, "%x", &num);
E 4
I 4
D 12
	sscanf(str+2, "%x", &num);
E 12
I 12
	(void) sscanf(str+2, "%x", &num);
E 12
E 4
	return num;
}
E 1
