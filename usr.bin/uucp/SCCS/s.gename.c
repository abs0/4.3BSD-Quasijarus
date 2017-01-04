h26607
s 00002/00003/00082
d D 5.7 88/04/05 12:05:21 rick 7 6
c use syslog for errors
e
s 00037/00051/00048
d D 5.6 85/10/09 16:02:26 bloom 6 5
c still more fixes from rick@seismo
e
s 00023/00019/00076
d D 5.5 85/06/19 19:07:51 bloom 5 4
c fix from rick adams
e
s 00005/00006/00090
d D 5.4 85/01/22 14:08:22 ralph 4 3
c bug fixes and changes from Rick Adams
e
s 00001/00001/00095
d D 5.3 84/08/30 16:23:54 ralph 3 2
c added network device NET
e
s 00004/00003/00092
d D 5.2 83/07/19 11:21:19 gray 2 1
c cast (time_t) and lseek(fd,0L...) for pdp11s
e
s 00095/00000/00000
d D 5.1 83/07/02 17:56:48 sam 1 0
c date and time created 83/07/02 17:56:48 by sam
e
u
U
t
T
I 1
#ifndef lint
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
static char sccsid[] = "%W%	(Berkeley) %G%";
E 7
#endif

#include "uucp.h"
I 2
D 5
#include <sys/types.h>
E 5
E 2

#define SEQLEN 4
I 6
#define SLOCKTIME 10L
#define SLOCKTRIES 5
/*
 * the alphabet can be anything, but if it's not in ascii order,
 * sequence ordering is not preserved
 */
static char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
E 6

I 6
#ifdef BSD4_2
#include <sys/file.h>
#endif BSD4_2

E 6
D 5
/*******
 *	gename(pre, sys, grade, file)	generate file name
 *	char grade, *sys, pre, *file;
 *
 *	return codes:  none
E 5
I 5
/*LINTLIBRARY*/

/*
 *	generate file name
E 5
 */
D 4

E 4
gename(pre, sys, grade, file)
char pre, *sys, grade, *file;
{
D 3
	static char sqnum[5];
E 3
I 3
D 4
	static char sqnum[SEQLEN+1];
E 4
I 4
D 6
	static char sqnum[5];
E 4
E 3

	getseq(sqnum);
D 5
	sprintf(file, "%c.%.7s%c%.*s", pre, sys, grade, SEQLEN, sqnum);
E 5
I 5
	sprintf(file,"%c.%.*s%c%.*s", pre, SYSNSIZE, sys, grade, SEQLEN, sqnum);
E 5
	DEBUG(4, "file - %s\n", file);
D 4
	return;
E 4
}

D 5

E 5
#define SLOCKTIME 10L
#define SLOCKTRIES 5

D 5
/*******
 *	getseq(snum)	get next sequence number
 *	char *snum;
 *
 *	return codes:  none
E 5
I 5
/*
 *	get next sequence number
E 5
 */

static
getseq(snum)
register char *snum;
{
	/*
	 * the alphabet can be anything, but if it's not in ascii order,
	 * sequence ordering is not preserved
	 */
	char	*alphabet =
	    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
E 6
	register int i, fd;
I 6
	static char snum[5];
E 6
D 5
	static char *lastchar;
E 5
I 5
	static char *lastchar = NULL;
E 5

	if (lastchar == NULL || (snum[SEQLEN-1] = *(lastchar++)) == '\0') {
I 6
#ifndef BSD4_2
E 6
		for (i = 0; i < SLOCKTRIES; i++) {
D 2
			if (!ulockf(SEQLOCK, SLOCKTIME))
E 2
I 2
D 5
			if (!ulockf(SEQLOCK, (time_t)SLOCKTIME))
E 5
I 5
			if (!ulockf(SEQLOCK, SLOCKTIME))
E 5
E 2
				break;
			sleep(5);
		}

D 2
		ASSERT(i < SLOCKTRIES, "CAN NOT GET %s", "", SEQLOCK);
E 2
I 2
D 4
		ASSERT(i < SLOCKTRIES, "CAN NOT GET", "SEQLOCK", 0);
E 4
I 4
D 5
		ASSERT(i < SLOCKTRIES, "CAN NOT GET", SEQLOCK, 0);
E 5
I 5
		if (i >= SLOCKTRIES) {
D 6
			int alphalen;
E 6
			logent(SEQLOCK, "CAN NOT LOCK");
D 6
			alphalen = strlen(alphabet);
			srand((int)time((time_t *)0));
			for (i=1;i<SEQLEN;i++)
				*snum++ = alphabet[rand() % alphalen];
			lastchar = alphabet;
			*snum = *lastchar++;
			return;
E 6
I 6
			goto getrandseq;
E 6
		}
I 6
#endif !BSD4_2
E 6
E 5
E 4
E 2

		if ((fd = open(SEQFILE, 2)) >= 0) {
D 6
			int alphalen;
			register char	*p;
			char *index();

			alphalen = strlen(alphabet);
E 6
I 6
			register char *p;
#ifdef BSD4_2
			flock(fd, LOCK_EX);
#endif !BSD4_2
E 6
			read(fd, snum, SEQLEN);
I 4
D 6
			/* initialize rand() for possible use */
			srand((int)time((time_t *)0));
E 6
E 4
			/* increment the penultimate character */
			for (i = SEQLEN - 2; i >= 0; --i) {
D 6
				if ((p = index(alphabet, snum[i])) == NULL) {
D 4
					/* drastic but effective */
					snum[i] = alphabet[alphalen - 1];
E 4
I 4
					p = &alphabet[rand() % alphalen];
E 4
					DEBUG(6, "bad seqf: %s\n", snum);
				}
				if (++p < &alphabet[alphalen]) {
E 6
I 6
				if ((p = index(alphabet, snum[i])) == NULL)
					goto getrandseq;
				if (++p < &alphabet[sizeof alphabet - 1]) {
E 6
					snum[i] = *p;
					break;
				} else		/* carry */
					snum[i] = alphabet[0];	/* continue */
			}
			snum[SEQLEN-1] = alphabet[0];
		} else {
I 6
D 7
			extern int errno;
E 7
I 7
			syslog(LOG_WARNING, "open(%s) failed: %m", SEQFILE);
E 7
			fd = creat(SEQFILE, 0666);
getrandseq:		srand((int)time((time_t *)0));
D 7
			assert(SEQFILE, "is missing or trashed\n", errno);
E 7
E 6
D 5
			if ((fd = creat(SEQFILE, 0666)) < 0)
				return(FAIL);
E 5
			for (i = 0; i < SEQLEN; i++)
D 6
				snum[i] = alphabet[0];
I 5
			if ((fd = creat(SEQFILE, 0666)) < 0)
				return;
E 6
I 6
				snum[i] = alphabet[rand() % (sizeof alphabet - 1)];
			snum[SEQLEN-1] = alphabet[0];
E 6
E 5
		}

D 2
		lseek(fd, 0, 0);
E 2
I 2
D 6
		lseek(fd, 0L, 0);
E 2
		write(fd, snum, SEQLEN);
		close(fd);
E 6
I 6
		if (fd >= 0) {
			lseek(fd, 0L, 0);
			write(fd, snum, SEQLEN);
			close(fd);
		}
#ifndef BSD4_2
E 6
		rmlock(SEQLOCK);
I 6
#endif !BSD4_2
E 6
		lastchar = alphabet + 1;
	}
D 5
	return(0);
E 5
I 5
D 6
	return;
E 6
I 6
	sprintf(file,"%c.%.*s%c%.*s", pre, SYSNSIZE, sys, grade, SEQLEN, snum);
	DEBUG(4, "file - %s\n", file);
E 6
E 5
}
E 1
