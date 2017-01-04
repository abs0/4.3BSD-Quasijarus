h63591
s 00011/00005/00076
d D 5.6 88/06/18 14:00:53 bostic 8 7
c install approved copyright notice
e
s 00009/00003/00072
d D 5.5 88/02/23 15:25:14 bostic 7 6
c add Berkeley specific header
e
s 00007/00000/00068
d D 5.4 86/04/19 20:23:18 karels 6 5
c recognize by complain about names starting with numbers
e
s 00003/00003/00065
d D 5.3 86/04/16 15:54:04 karels 5 4
c allow lower case
e
s 00000/00006/00068
d D 5.2 85/06/21 19:18:20 mckusick 4 3
c botched copyright
e
s 00013/00001/00061
d D 5.1 85/05/28 14:12:50 dist 3 2
c add copyright
e
s 00004/00001/00058
d D 4.2 85/02/25 09:30:22 ralph 2 1
c don't loop forever if hostname is one char long.
e
s 00059/00000/00000
d D 4.1 82/10/20 21:26:52 sam 1 0
c date and time created 82/10/20 21:26:52 by sam
e
u
U
t
T
I 1
%{
I 8

E 8
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

E 3
#ifndef lint
I 3
D 4
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 4
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif
E 3
I 3
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 3

#include "y.tab.h"
#include "htable.h"
%}

BLANK	[ \t]
DIGIT	[0-9]
D 5
ALPHA	[A-Z]
ANUM	[0-9A-Z]
NAMECHR	[0-9A-Z./-]
E 5
I 5
ALPHA	[A-Za-z]
ANUM	[0-9A-Za-z]
NAMECHR	[0-9A-Za-z./-]
E 5

%%
"NET"		{
			yylval.number = KW_NET;
			return (KEYWORD);
		}

"GATEWAY"	{
			yylval.number = KW_GATEWAY;
			return (KEYWORD);
		}

"HOST"		{
			yylval.number = KW_HOST;
			return (KEYWORD);
		}

{ALPHA}{NAMECHR}*{ANUM}	{
			yylval.namelist = newname(yytext);
			return (NAME);
		}

D 2
{ALPHA}		return (NAME);
E 2
I 2
{ALPHA}		{
			yylval.namelist = newname(yytext);
			return (NAME);
		}
E 2

I 6
{DIGIT}+{ALPHA}{NAMECHR}* {
			fprintf(stderr, "Warning: nonstandard name \"%s\"\n",
				yytext);
			yylval.namelist = newname(yytext);
			return (NAME);
		}

E 6
{DIGIT}+	{
			yylval.number = atoi(yytext);
			return (NUMBER);
		}

"."		return ('.');
":"		return (':');
","		return (',');
"/"		return ('/');
";".*		;
"\n"{BLANK}+	;
{BLANK}+	;
"\n"		return (END);
.		fprintf(stderr, "Illegal char: '%s'\n", yytext);

%%

yywrap()
{
	return (1);
}
E 1
