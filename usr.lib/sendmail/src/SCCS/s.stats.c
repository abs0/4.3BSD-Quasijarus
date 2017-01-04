h61682
s 00011/00009/00095
d D 5.10 88/06/30 14:59:54 bostic 20 19
c install approved copyright notice
e
s 00016/00010/00088
d D 5.9 88/03/13 19:53:24 bostic 19 18
c add Berkeley specific header
e
s 00001/00014/00097
d D 5.8 86/05/02 16:28:24 bloom 18 17
c statistics structure moved to its own header file so it may be used by 
c aux/mailstats
e
s 00001/00009/00110
d D 5.7 86/01/05 18:48:42 eric 17 16
m 
c rewrite reply-to and resent-reply-to; save errorqueueu in qf file;
c some performance hacking; some alias handling cleanup; delete leading
c spaces from SMTP lines
e
s 00007/00004/00112
d D 5.6 85/09/19 01:25:38 eric 16 14
i 15
m 
c incorporate SMI changes -- still experimental
e
s 00005/00031/00102
d D 5.4.1.1 85/09/19 00:56:01 eric 15 13
m 
c SMI changes (somewhat)
e
s 00010/00002/00131
d D 5.5 85/07/25 14:12:08 miriam 14 13
m 
c If mail is received from an unparseable address, the q_mailer field 
c could be null.  Put in check to prevent referencing off a null pointer.
e
s 00003/00000/00130
d D 5.4 85/06/17 18:52:14 eric 13 12
m 
c From Bill Nowicki: fixes to the statistics
e
s 00002/00002/00128
d D 5.3 85/06/08 10:30:50 eric 12 11
m 
c lint for 4.3 release
e
s 00000/00002/00130
d D 5.2 85/06/07 22:20:01 miriam 11 10
m 
c Resolve duplicate SccsId
e
s 00014/00000/00118
d D 5.1 85/06/07 15:16:26 dist 10 9
m 
c Add copyright
e
s 00001/00001/00117
d D 4.2 84/08/11 16:54:50 eric 9 8
m 
c Changes from Greg Couch <ucsfcgl!gregc> for V7 compatibility and
c miscellaneous bug fixes; "clear" => "bzero" and "bmove" => "bcopy"
c throughout for consistency; bzero is now in bcopy.c (these are
c supplied by libc on 4.2bsd)
e
s 00000/00000/00118
d D 4.1 83/07/25 19:46:03 eric 8 7
m 
c 4.2 release version
e
s 00003/00000/00115
d D 3.7 83/04/17 17:15:43 eric 7 6
m 221
c fix bogus errno problems
e
s 00000/00002/00115
d D 3.6 83/03/26 14:27:26 eric 6 5
m 214
c changes from MRH for USG UNIX 5.0
e
s 00035/00000/00082
d D 3.5 82/11/28 00:24:21 eric 5 4
m 
c Many changes resulting from a complete code readthrough.  Most of these
c fix minor bugs or change the internal structure for clarity, etc.  There
c should be almost no externally visible changes (other than some cleaner
c error message printouts and the like).
e
s 00001/00001/00081
d D 3.4 81/12/06 12:40:34 eric 4 3
c cleanup so it will go through lint without any fancy grep -v's;
c change the way SCCS Id's are handled.
e
s 00000/00001/00082
d D 3.3 81/11/08 17:27:04 eric 3 2
c LINT
e
s 00008/00006/00075
d D 3.2 81/09/06 19:49:42 eric 2 1
c cleanup, commenting, linting, etc.
e
s 00081/00000/00000
d D 3.1 81/08/31 21:21:51 eric 1 0
c date and time created 81/08/31 21:21:51 by eric
e
u
U
f b 
f i 
t
T
I 10
/*
I 20
 * Copyright (c) 1983 Eric P. Allman
E 20
D 19
**  Sendmail
**  Copyright (c) 1983  Eric P. Allman
**  Berkeley, California
**
**  Copyright (c) 1983 Regents of the University of California.
**  All rights reserved.  The Berkeley software License Agreement
**  specifies the terms and conditions for redistribution.
*/
E 19
I 19
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *  Sendmail
 *  Copyright (c) 1983  Eric P. Allman
 *  Berkeley, California
E 20
I 20
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
E 20
 */
E 19

#ifndef lint
D 19
static char	SccsId[] = "%W% (Berkeley) %G%";
#endif not lint
E 19
I 19
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 19

E 10
I 1
# include "sendmail.h"
D 18

D 4
static char	SccsId[] =	"%W%	%G%";
E 4
I 4
D 11
SCCSID(%W%	%Y%	%G%);
E 4

E 11
/*
I 5
**  Statistics structure.
*/

struct statistics
{
	time_t	stat_itime;		/* file initialization time */
	short	stat_size;		/* size of this structure */
	long	stat_nf[MAXMAILERS];	/* # msgs from each mailer */
	long	stat_bf[MAXMAILERS];	/* kbytes from each mailer */
	long	stat_nt[MAXMAILERS];	/* # msgs to each mailer */
	long	stat_bt[MAXMAILERS];	/* kbytes to each mailer */
};
E 18
I 18
# include "mailstats.h"
E 18

struct statistics	Stat;
D 15
extern long		kbytes();	/* for _bf, _bt */
E 15
I 15

#define ONE_K		1000		/* one thousand (twenty-four?) */
#define KBYTES(x)	(((x) + (ONE_K - 1)) / ONE_K)
E 15
/*
**  MARKSTATS -- mark statistics
*/

markstats(e, to)
	register ENVELOPE *e;
	register ADDRESS *to;
{
	if (to == NULL)
	{
D 14
		Stat.stat_nf[e->e_from.q_mailer->m_mno]++;
D 15
		Stat.stat_bf[e->e_from.q_mailer->m_mno] += kbytes(CurEnv->e_msgsize);
E 15
I 15
D 17
		Stat.stat_bf[e->e_from.q_mailer->m_mno] += KBYTES(CurEnv->e_msgsize);
E 15
E 14
I 14
D 16
		/* if is possible to get mail from an unparseable address,
		   in this case, the q_mailer field is null, so that the
		   indirection below causes a dereference of a NULL pointer.
E 16
I 16

		/*
		**  If is possible to get mail from an unparseable address,
		**  in this case, the q_mailer field is null, so that the
		**  indirection below causes a dereference of a NULL pointer.
E 16
		*/
I 16

E 16
		if (e->e_from.q_mailer != NULL )
E 17
I 17
		if (e->e_from.q_mailer != NULL)
E 17
		{
			Stat.stat_nf[e->e_from.q_mailer->m_mno]++;
			Stat.stat_bf[e->e_from.q_mailer->m_mno] +=
D 16
				kbytes(CurEnv->e_msgsize);
E 16
I 16
				KBYTES(CurEnv->e_msgsize);
E 16
		}
E 14
	}
	else
	{
		Stat.stat_nt[to->q_mailer->m_mno]++;
D 15
		Stat.stat_bt[to->q_mailer->m_mno] += kbytes(CurEnv->e_msgsize);
E 15
I 15
		Stat.stat_bt[to->q_mailer->m_mno] += KBYTES(CurEnv->e_msgsize);
E 15
	}
}
/*
E 5
**  POSTSTATS -- post statistics in the statistics file
**
**	Parameters:
**		sfile -- the name of the statistics file.
**
**	Returns:
**		none.
**
**	Side Effects:
**		merges the Stat structure with the sfile file.
*/

D 6
struct statistics	Stat;

E 6
poststats(sfile)
	char *sfile;
{
	register int fd;
	struct statistics stat;
I 2
D 12
	extern long lseek();
E 12
I 12
	extern off_t lseek();
E 12
D 3
	extern long time();
E 3
E 2

I 13
	if (sfile == NULL)
		return;

E 13
D 2
	time(&Stat.stat_itime);
E 2
I 2
	(void) time(&Stat.stat_itime);
E 2
	Stat.stat_size = sizeof Stat;

	fd = open(sfile, 2);
	if (fd < 0)
I 7
	{
		errno = 0;
E 7
		return;
I 7
	}
E 7
D 2
	if (read(fd, &stat, sizeof stat) == sizeof stat &&
E 2
I 2
	if (read(fd, (char *) &stat, sizeof stat) == sizeof stat &&
E 2
	    stat.stat_size == sizeof stat)
	{
		/* merge current statistics into statfile */
		register int i;

		for (i = 0; i < MAXMAILERS; i++)
		{
			stat.stat_nf[i] += Stat.stat_nf[i];
			stat.stat_bf[i] += Stat.stat_bf[i];
			stat.stat_nt[i] += Stat.stat_nt[i];
			stat.stat_bt[i] += Stat.stat_bt[i];
		}
	}
	else
D 2
		bmove(&Stat, &stat, sizeof stat);
E 2
I 2
D 9
		bmove((char *) &Stat, (char *) &stat, sizeof stat);
E 9
I 9
		bcopy((char *) &Stat, (char *) &stat, sizeof stat);
E 9
E 2

	/* write out results */
D 2
	lseek(fd, 0L, 0);
	write(fd, &stat, sizeof stat);
	close(fd);
E 2
I 2
D 12
	(void) lseek(fd, 0L, 0);
E 12
I 12
	(void) lseek(fd, (off_t) 0, 0);
E 12
	(void) write(fd, (char *) &stat, sizeof stat);
	(void) close(fd);
E 2
D 15
}
/*
**  KBYTES -- given a number, returns the number of Kbytes.
**
**	Used in statistics gathering of message sizes to try to avoid
**	wraparound (at least for a while.....)
**
**	Parameters:
**		bytes -- actual number of bytes.
**
**	Returns:
**		number of kbytes.
**
**	Side Effects:
**		none.
**
**	Notes:
**		This function is actually a ceiling function to
**			the nearest K.
**		Honestly folks, floating point might be better.
**			Or perhaps a "statistical" log method.
*/

long
kbytes(bytes)
	long bytes;
{
	return ((bytes + 999) / 1000);
E 15
}
E 1
