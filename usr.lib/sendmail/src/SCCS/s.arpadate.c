h40938
s 00003/00001/00228
d D 5.10 06/03/31 17:33:08 msokolov 33 32
c generate 4-digit years (RFC 1123)
e
s 00011/00009/00218
d D 5.9 88/06/30 14:58:19 bostic 32 31
c install approved copyright notice
e
s 00000/00015/00227
d D 5.8 88/04/01 16:50:36 bostic 31 30
c remove V6 #ifdefs
e
s 00016/00010/00226
d D 5.7 88/03/13 19:51:29 bostic 30 29
c add Berkeley specific header
e
s 00002/00004/00234
d D 5.6 88/03/13 18:21:56 bostic 29 28
c replace sameword with strcasecmp
e
s 00001/00002/00237
d D 5.5 87/03/18 15:27:05 bostic 28 27
c removed timezone call; tm structure now has zone entry.
e
s 00009/00008/00230
d D 5.4 86/01/09 15:18:50 eric 27 26
c apparently European timezones were wrong; thanks to Piet Beertema
c <mcvax!piet@seismo.CSS.GOV> for this one
e
s 00002/00000/00236
d D 5.3 85/06/08 10:26:40 eric 26 25
m 
c lint for 4.3 release
e
s 00000/00002/00236
d D 5.2 85/06/07 22:00:54 miriam 25 24
m 
c Resolve duplicate SccsId
e
s 00014/00000/00224
d D 5.1 85/06/07 14:28:06 dist 24 23
m 
c Add copyright
e
s 00037/00015/00187
d D 4.4 84/08/11 17:47:56 eric 23 22
m 
c Assorted changes from Guy Harris <rlgvax!guy>: mostly lint & USG
e
s 00052/00030/00150
d D 4.3 83/10/01 16:57:03 eric 22 21
m 
c clean up error handling in general; make sure that something gets logged
c in the transcript if the connection cannot be established; clean up Teus
c Hagen's mod to arpadate.c to match the sendmail coding style.
e
s 00040/00002/00140
d D 4.2 83/09/27 12:18:09 karels 21 20
m 
c mods for european dates (from mcvax!teus)
e
s 00000/00000/00142
d D 4.1 83/07/25 19:43:32 eric 20 19
m 
c 4.2 release version
e
s 00008/00009/00134
d D 3.13 83/07/13 10:37:46 eric 19 18
m 
c Delete "load limiting" for SMTP connections (a bad ethernet board can
c hang up all incoming mail); use sfgets in collect (same reason); check
c for I/O error in collect (from Bill Nowicki); switch date format to
c RFC822 style.
e
s 00001/00001/00142
d D 3.12 83/07/01 23:04:49 wnj 18 17
m 
c 
e
s 00003/00003/00140
d D 3.11 83/01/12 08:56:46 eric 17 16
m 144
c fix date format to be truly RFC822
e
s 00001/00000/00142
d D 3.10 82/11/13 18:13:03 eric 16 15
m 070
c move configuration to conf.h
e
s 00001/00001/00141
d D 3.9 81/12/06 12:37:12 eric 15 14
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00017/00081/00125
d D 3.8 81/12/05 14:13:28 eric 14 13
c insert SMTP "Mail-From:" line.
e
s 00001/00002/00205
d D 3.7 81/09/24 10:30:10 eric 13 11
c changes to work under a V6 system -- mostly compilation flags
e
s 00001/00000/00207
d D 3.6.1.1 81/09/23 18:22:39 eric 12 11
c break some configuration into conf.h -- simplifies makefile changes
c on different machines.  But there are still conditional libraries, so
c this may not be a good idea.....
e
s 00019/00008/00188
d D 3.6 81/09/06 19:47:35 eric 11 10
c cleanup, commenting, linting, etc.
e
s 00019/00018/00177
d D 3.5 81/04/20 14:45:00 eric 10 9
c change format to fit Kurt's standard
e
s 00073/00010/00122
d D 3.4 81/03/27 14:30:37 eric 9 8
c make more readable dates
e
s 00005/00000/00127
d D 3.3 81/03/11 10:45:01 eric 8 7
c general cleanup, esp. macro processor
e
s 00002/00002/00125
d D 3.2 81/03/07 14:25:11 eric 7 6
c ----- delivermail ==> postbox -----
e
s 00092/00016/00035
d D 3.1 81/03/04 09:33:42 eric 6 5
c install fancy header stuff
e
s 00000/00000/00051
d D 2.1 80/11/05 11:00:14 eric 5 4
c release 2
e
s 00002/00000/00049
d D 1.4 80/10/21 12:20:08 eric 4 3
c clean up type botches
e
s 00000/00010/00049
d D 1.3 80/08/02 13:48:17 eric 3 2
c cleaned up comments
e
s 00002/00000/00057
d D 1.2 80/07/25 22:02:32 eric 2 1
c add ID keywords
e
s 00057/00000/00000
d D 1.1 80/06/23 08:23:18 eric 1 0
e
u
U
f b 
f i 
t
T
I 24
/*
I 32
 * Copyright (c) 1983 Eric P. Allman
E 32
D 30
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 30
I 30
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 32
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 32
I 32
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
E 32
 */
E 30

#ifndef lint
D 30
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 30
I 30
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 30

E 24
I 16
# include "conf.h"
I 23
# ifdef USG
# include <time.h>
# else
E 23
E 16
I 12
# include "conf.h"
E 12
I 1
D 18
# include <time.h>
E 18
I 18
# include <sys/time.h>
E 18
I 6
D 31
# ifndef V6
E 31
# include <sys/types.h>
# include <sys/timeb.h>
D 23
# endif
E 23
I 23
D 31
# endif V6
E 31
# endif USG
E 23
I 13
# include "useful.h"
E 13
E 6

I 2
D 15
static char SccsId[] = "%W%	%G%";
E 15
I 15
D 25
SCCSID(%W%	%Y%	%G%);
E 15

E 25
I 23
D 31
# ifdef V6
# define OLDTIME
# endif V6
E 31
# ifdef USG
# define OLDTIME
# endif USG

E 23
E 2
/*
**  ARPADATE -- Create date in ARPANET format
**
**	Parameters:
D 6
**		none
E 6
I 6
**		ud -- unix style date string.  if NULL, one is created.
E 6
**
**	Returns:
**		pointer to an ARPANET date field
**
**	Side Effects:
**		none
**
**	WARNING:
**		date is stored in a local buffer -- subsequent
**		calls will overwrite.
I 8
**
**	Bugs:
**		Timezone is computed from local time, rather than
**		from whereever (and whenever) the message was sent.
**		To do better is very hard.
I 11
**
**		Some sites are now inserting the timezone into the
**		local date.  This routine should figure out what
**		the format is and work appropriately.
E 11
E 8
D 3
**
**	Requires:
**		time (sys)
**		ctime (sys)
**		strcpy (sys)
**		strcat (sys)
**		localtime (sys)
**
**	History:
**		1/15/80 -- written.
E 3
*/
D 13

I 6
D 11
# ifdef V6
# define DST_NAME	"PDT"
# define STD_NAME	"PST"
# endif

E 11
# define NULL		0
E 13

I 9
D 14
struct cvttab
{
	char	*old;
	char	*new;
};

struct cvttab	DowTab[] =
{
	"Sun",		"Sunday",
	"Mon",		"Monday",
	"Tue",		"Tuesday",
	"Wed",		"Wednesday",
	"Thu",		"Thursday",
	"Fri",		"Friday",
	"Sat",		"Saturday",
	NULL,		NULL
};

struct cvttab	MonthTab[] =
{
	"Jan",		"January",
	"Feb",		"February",
	"Mar",		"March",
	"Apr",		"April",
	"May",		"May",
	"Jun",		"June",
	"Jul",		"July",
	"Aug",		"August",
	"Sep",		"September",
	"Oct",		"October",
	"Nov",		"November",
	"Dec",		"December",
	NULL,		NULL
};

E 14
E 9
E 6
I 4
char *
E 4
D 6
arpadate()
E 6
I 6
arpadate(ud)
	register char *ud;
E 6
{
D 6
	register char *ud;	/* the unix date */
	long t;
	extern struct tm *localtime();
E 6
	register char *p;
I 6
	register char *q;
E 6
	static char b[40];
I 4
	extern char *ctime();
I 6
	register int i;
I 9
D 14
	struct cvttab *c;
E 14
E 9
	extern struct tm *localtime();
I 22
	extern bool fconvert();
E 22
D 23
# ifdef V6
E 23
I 23
# ifdef OLDTIME
E 23
	long t;
I 11
D 23
	extern char *StdTimezone, *DstTimezone;
E 23
	extern long time();
E 11
D 23
# else
E 23
I 23
# else OLDTIME
E 23
	struct timeb t;
	extern struct timeb *ftime();
D 28
	extern char *timezone();
E 28
D 23
# endif
E 23
I 23
# endif OLDTIME
D 31
# ifdef V6
	extern char *StdTimezone, *DstTimezone;
# endif V6
E 31
# ifdef USG
	extern char *tzname[2];
# endif USG
E 23
E 6
E 4

I 11
	/*
	**  Get current time.
	**	This will be used if a null argument is passed and
	**	to resolve the timezone.
	*/

E 11
I 6
D 23
# ifdef V6
E 23
I 23
# ifdef OLDTIME
E 23
E 6
D 11
	time(&t);
E 11
I 11
	(void) time(&t);
E 11
D 6
	ud = ctime(&t);
E 6
I 6
	if (ud == NULL)
		ud = ctime(&t);
# else
	ftime(&t);
	if (ud == NULL)
		ud = ctime(&t.time);
D 23
# endif
E 23
I 23
# endif OLDTIME
E 23
E 6

I 11
	/*
	**  Crack the UNIX date line in a singularly unoriginal way.
	*/

E 11
D 6
	ud[3] = ud[7] = ud[10] = ud[19] = ud[24] = '\0';
E 6
I 6
	q = b;

I 19
	p = &ud[0];		/* Mon */
	*q++ = *p++;
	*q++ = *p++;
	*q++ = *p++;
	*q++ = ',';
	*q++ = ' ';

E 19
D 9
	p = &ud[0];		/* Mon */
	*q++ = *p++;
	*q++ = *p++;
	*q++ = *p++;
	*q++ = ',';
	*q++ = ' ';
E 9
I 9
D 10
	p = NULL;		/* Mon */
	for (c = DowTab; c->old != NULL; c++)
	{
		if (strncmp(&ud[0], c->old, 3) == 0)
		{
			p = c->new;
			break;
		}
	}
	if (p != NULL)
	{
		while (*p != '\0')
			*q++ = *p++;
		*q++ = ',';
		*q++ = ' ';
	}
E 9

E 10
E 6
	p = &ud[8];		/* 16 */
	if (*p == ' ')
		p++;
D 6
	strcpy(b, p);
	strcat(b, " ");
	strcat(b, &ud[4]);	/* Sep */
	strcat(b, " ");
	strcat(b, &ud[20]);	/* 1979 */
	strcat(b, " ");
	strcat(b, &ud[11]);	/* 01:03:52 */
E 6
I 6
	else
		*q++ = *p++;
	*q++ = *p++;
D 7
	*q++ = '-';
E 7
I 7
D 14
	*q++ = ' ';
E 14
I 14
D 17
	*q++ = '-';
E 17
I 17
	*q++ = ' ';
E 17
E 14
E 7

D 9
	p = &ud[4];		/* Sep */
	*q++ = *p++;
	*q++ = *p++;
	*q++ = *p++;
E 9
I 9
D 14
	p = NULL;		/* Sep */
	for (c = MonthTab; c->old != NULL; c++)
	{
		if (strncmp(&ud[4], c->old, 3) == 0)
		{
			p = c->new;
			break;
		}
	}
	if (p != NULL)
	{
		while (*p != '\0')
			*q++ = *p++;
	}
	else
	{
		p = &ud[4];
		*q++ = *p++;
		*q++ = *p++;
		*q++ = *p++;
	}
E 9
D 7
	*q++ = '-';
E 7
I 7
	*q++ = ' ';
E 14
I 14
	p = &ud[4];		/* Sep */
	*q++ = *p++;
	*q++ = *p++;
	*q++ = *p++;
D 17
	*q++ = '-';
E 17
I 17
	*q++ = ' ';
E 17
E 14
E 7

D 14
	p = &ud[20];		/* 1979 */
	for (i = 4; i > 0; i--)
		*q++ = *p++;
E 14
I 14
D 19
	p = &ud[22];		/* 1979 */
E 19
I 19
D 33
	p = &ud[22];		/* 79 */
E 33
I 33
	p = &ud[20];		/* 1979 */
	*q++ = *p++;
	*q++ = *p++;
E 33
E 19
	*q++ = *p++;
	*q++ = *p++;
E 14
	*q++ = ' ';

	p = &ud[11];		/* 01:03:52 */
D 10
	for (i = 8; i > 0; i--)
E 10
I 10
D 14
	for (i = 5; i > 0; i--)
E 14
I 14
	for (i = 8; i > 0; i--)
E 14
E 10
		*q++ = *p++;

				/* -PST or -PDT */
D 31
# ifdef V6
E 6
	if (localtime(&t)->tm_isdst)
D 6
		strcat(b, "-PDT");
E 6
I 6
D 11
		p = DST_NAME;
E 11
I 11
		p = DstTimezone;
E 11
E 6
	else
D 6
		strcat(b, "-PST");
E 6
I 6
D 11
		p = STD_NAME;
E 11
I 11
		p = StdTimezone;
E 11
# else
E 31
I 23
# ifdef USG
	if (localtime(&t)->tm_isdst)
		p = tzname[1];
	else
		p = tzname[0];
# else
E 23
D 28
	p = timezone(t.timezone, localtime(&t.time)->tm_isdst);
E 28
I 28
	p = localtime(&t.time)->tm_zone;
E 28
I 23
# endif USG
E 23
D 31
# endif V6
E 31
D 21
	if (p[3] != '\0')
E 21
I 21
D 22
	if ( (strncmp(p,"GMT",3)==0 || strncmp(p,"gmt",3)==0) && p[3] != '\0')
E 22
I 22
	if ((strncmp(p, "GMT", 3) == 0 || strncmp(p, "gmt", 3) == 0) &&
	    p[3] != '\0')
E 22
E 21
	{
		/* hours from GMT */
		p += 3;
		*q++ = *p++;
		if (p[1] == ':')
			*q++ = '0';
		else
			*q++ = *p++;
		*q++ = *p++;
		p++;		/* skip ``:'' */
		*q++ = *p++;
		*q++ = *p++;
I 21
		*q = '\0';
E 21
	}
D 22
	else
I 21
	if( !fconvert(p,q) )
E 22
I 22
	else if (!fconvert(p, q))
E 22
E 21
	{
D 17
		*q++ = '-';
E 17
I 17
		*q++ = ' ';
E 17
		*q++ = *p++;
		*q++ = *p++;
		*q++ = *p++;
I 21
		*q = '\0';
E 21
I 10
	}
D 19

D 14
	p = NULL;		/* Mon */
	for (c = DowTab; c->old != NULL; c++)
	{
		if (strncmp(&ud[0], c->old, 3) == 0)
		{
			p = c->new;
			break;
		}
	}
	if (p != NULL)
	{
		*q++ = ' ';
		*q++ = '(';
		while (*p != '\0')
			*q++ = *p++;
		*q++ = ')';
E 10
	}
E 14
I 14
	p = &ud[0];		/* Mon */
	*q++ = ' ';
	*q++ = '(';
	*q++ = *p++;
	*q++ = *p++;
	*q++ = *p++;
	*q++ = ')';
E 19
E 14

D 21
	*q = '\0';
E 21
D 14

E 14
E 6
	return (b);
I 21
}
I 22
/*
**  FCONVERT -- convert foreign timezones to ARPA timezones
**
**	This routine is essentially from Teus Hagen.
**
**	Parameters:
**		a -- timezone as returned from UNIX.
**		b -- place to put ARPA-style timezone.
**
**	Returns:
**		TRUE -- if a conversion was made (and b was filled in).
**		FALSE -- if this is not a recognized local time.
**
**	Side Effects:
**		none.
*/
E 22

D 22
/* convert foreign identifications to some ARPA interpretable form */
/* with dst we put the time zone one hour ahead */
struct foreign { 
E 22
I 22
/* UNIX to arpa conversion table */
struct foreign
{
E 22
	char *f_from; 
	char *f_to; 
D 22
} foreign[] = {
	{"eet", " -0200"}, /* eastern europe */
	{"met", " -0100"}, /* middle europe */
	{"wet", " GMT"},   /* western europe, and what for australia? */
	{"eet dst", " -0300"}, /* daylight saving times */
	{"met dst", " -0200"},
	{"wet dst", " -0100"},
	{NULL, NULL}
E 22
};

D 22
fconvert( a, b ) register char *a; char *b;
{	register struct foreign *euptr;
	register char *ptr;
	extern makelower();
E 22
I 22
D 27
static struct foreign Foreign[] =
E 27
I 27
static struct foreign	Foreign[] =
E 27
{
D 23
	{ "eet",	" -0200" },	/* eastern europe */
	{ "met",	" -0100" },	/* middle europe */
	{ "wet",	" GMT"   },	/* western europe */
	{ "eet dst",	" -0300" },	/* daylight saving times */
	{ "met dst",	" -0200" },
	{ "wet dst",	" -0100" },
E 23
I 23
D 27
	{ "EET",	" -0200" },	/* eastern europe */
	{ "MET",	" -0100" },	/* middle europe */
	{ "WET",	" GMT"   },	/* western europe */
	{ "EET DST",	" -0300" },	/* daylight saving times */
	{ "MET DST",	" -0200" },
	{ "WET DST",	" -0100" },
E 27
I 27
	{ "EET",	"+0200" },	/* eastern europe */
	{ "MET",	"+0100" },	/* middle europe */
	{ "WET",	"GMT"   },	/* western europe */
	{ "EET DST",	"+0300" },	/* daylight saving times */
	{ "MET DST",	"+0200" },
	{ "WET DST",	"+0100" },
E 27
E 23
	{ NULL,		NULL	 }
};
E 22

D 22
/* for news:	for ( ptr = a; *ptr; ptr++ )
		if ( isupper(*ptr) )
			*ptr = tolower( *ptr );
*/
	makelower( a );
	for ( euptr = &foreign[0]; euptr->f_from != NULL; euptr++ )
		if ( strcmp(euptr->f_from, a) == 0 )
		{	ptr = euptr->f_to;
			while ( *ptr )
				*b++ = *ptr++;
E 22
I 22
bool
fconvert(a, b)
	register char *a;
D 29
	char *b;
E 29
I 29
	register char *b;
E 29
{
	register struct foreign *euptr;
	register char *p;

D 23
	makelower(a);
E 23
	for (euptr = Foreign; euptr->f_from != NULL; euptr++)
	{
I 26
D 29
		extern bool sameword();

E 26
D 23
		if (strcmp(euptr->f_from, a) == 0)
E 23
I 23
		if (sameword(euptr->f_from, a))
E 29
I 29
		if (!strcasecmp(euptr->f_from, a))
E 29
E 23
		{
			p = euptr->f_to;
D 27
			while (*p)
E 27
I 27
			*b++ = ' ';
			while (*p != '\0')
E 27
				*b++ = *p++;
E 22
			*b = '\0';
D 22
			return 1;
E 22
I 22
			return (TRUE);
E 22
		}
D 22
	return 0;
E 22
I 22
	}
	return (FALSE);
E 22
E 21
}
E 1
