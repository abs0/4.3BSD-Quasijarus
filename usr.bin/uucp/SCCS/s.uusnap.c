h55218
s 00005/00018/00309
d D 5.9 88/04/05 12:26:13 rick 9 8
c minor fix in handling D. files
e
s 00011/00002/00316
d D 5.8 88/02/24 20:04:59 rick 8 7
c increase array sizes and check for running off end
e
s 00001/00001/00317
d D 5.7 85/10/09 16:45:49 bloom 7 6
c bug fix from rick@seismo
e
s 00009/00003/00309
d D 5.6 85/06/24 10:39:33 bloom 6 5
c more fixes from rick adams
e
s 00028/00022/00284
d D 5.5 85/06/23 13:53:43 bloom 5 4
c fixes from rick adams
e
s 00001/00002/00305
d D 5.4 85/04/10 15:23:02 ralph 4 3
c more changes from rick adams.
e
s 00140/00112/00167
d D 5.3 85/01/22 14:13:31 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00001/00001/00278
d D 5.2 83/07/02 18:05:53 sam 2 1
c include fixes
e
s 00279/00000/00000
d D 5.1 83/07/02 17:58:01 sam 1 0
c date and time created 83/07/02 17:58:01 by sam
e
u
U
t
T
I 1
#ifndef lint
D 9
static char sccsid[] = "%W% (Berkeley) %G%";
E 9
I 9
static char sccsid[] = "%W%	(Berkeley) %G%";
E 9
#endif

/*
I 8
 * This file contains no ATT code and is not subject to the ATT
 * license provisions regarding redistribution.
 * 	Rick Adams 2/23/88
 */

/*
E 8
 *	Uusnap - displays a snapshot of the uucp system.
D 5
 *					RJKing WECo-MG6565 May 83
E 5
I 5
 *	originally by	RJKing WECo-MG6565 May 83
E 5
 */

#include "uucp.h"
D 4
#include <sys/types.h>
E 4
#include <sys/stat.h>
#ifdef	NDIR
#include "ndir.h"
#else
D 2
#include <dir.h>
E 2
I 2
#include <sys/dir.h>
E 2
#endif
I 6
#include <ctype.h>
E 6

D 9
#ifndef	SYSBUF
char SYSBUF[BUFSIZ];
#endif

E 9
D 8
#define	NSYSTEM	100				/* max # of systems queued */
E 8
I 8
#define	NSYSTEM	300				/* max # of systems queued */
E 8
D 3
#define	SPOOLDR	"/usr/spool/uucp"		/* Where STST files are */
#ifdef	UUDIR
#define	CMDSDIR	"/usr/spool/uucp/C."		/* Name of commands dir */
#define	DATADIR	"/usr/spool/uucp/D."		/* Name of data directory */
#define	XEQTDIR	"/usr/spool/uucp/X."		/* Name of execute dir */
#else
#define	CMDSDIR	"/usr/spool/uucp"		/* Name of commands dir */
#define	DATADIR	"/usr/spool/uucp"		/* Name of data directory */
#define	XEQTDIR	"/usr/spool/uucp"		/* Name of execute dir */
#endif
E 3

#define	CMDSLEN	5				/* Length of trailer */
#define	DATALEN	5				/* Length of trailer */
D 3
/* rti!trt: XEQTLEN was 0, for reverse search, but that did not work. */
E 3
#define	XEQTLEN	5				/* Length of trailer */
#define	NUMCTRS	3				/* # file types to count */
#define	CMDTYPE	0				/* Index into scnt.cntr */
#define	DATTYPE	1				/* Index into scnt.cntr */
#define	XEQTYPE	2				/* Index into scnt.cntr */

D 3
void	scandir(), getstst();
E 3
D 5
extern	char *index(), *rindex(), *strcpy(), *strncpy();;
extern	long atol();
extern	time_t	time();

E 5
struct	scnt {					/* System count structure */
D 5
		char	name[16];		/* Name of system */
E 5
I 5
		char	name[MAXBASENAME+1];	/* Name of system */
E 5
		short	cntr[NUMCTRS];		/* Count */
		char	stst[32];		/* STST Message */
D 3
		short	locked;			/* If LCK..sys present */
E 3
I 3
		time_t	locked;			/* If LCK..sys present */
E 3
		int	st_type;		/* STST Type */
		int	st_count;		/* STST Count */
		time_t	st_lastime;		/* STST Last time tried */
		time_t	st_retry;		/* STST Secs to retry */
	     };

int	sndx;					/* Number of systems */
struct	scnt	sys[NSYSTEM];			/* Systems queued */
I 3
int xqtisrunning = 0;
E 3

main()
D 9
{	register int i, j, nlen = 0;
E 9
I 9
{	
	register int i, j, nlen = 0;
E 9
	time_t	curtime, t;

D 9
	setbuf(stdout, SYSBUF);
E 9
	scandir(CMDSDIR, "C.", CMDSLEN, NULL, CMDTYPE);
	scandir(DATADIR, "D.", DATALEN, NULL, DATTYPE);
	scandir(XEQTDIR, "X.", XEQTLEN, 'X', XEQTYPE);
D 3
	getstst(SPOOLDR);
E 3
I 3
	getstst(SPOOL);
E 3
	time(&curtime);
	for(i=0; i<sndx; ++i)
		if((j = strlen(sys[i].name)) > nlen)
			nlen = j;
D 3
	for(i=0; i<sndx; ++i)
	{	printf("%-*.*s ", nlen, nlen, sys[i].name);
E 3
I 3
	for(i=0; i<sndx; ++i) {
		t = (sys[i].st_lastime +sys[i].st_retry) - curtime;

		/* decide if STST text is worth printing */
		if (-t < ONEDAY*2 && sys[i].st_type == SS_WRONGTIME) {
			sys[i].stst[0] = '\0';
			if (sys[i].cntr[0]+sys[i].cntr[1]+sys[i].cntr[2] == 0)
				continue;	/* ignore entire line */
		}

		printf("%-*.*s ", nlen, nlen, sys[i].name);
E 3
		if(sys[i].cntr[CMDTYPE])
			printf("%3.d Cmd%s ", sys[i].cntr[CMDTYPE],
				sys[i].cntr[CMDTYPE]>1?"s":" ");
D 3
		else	printf("   ---   ");
E 3
I 3
		else
			printf("   ---   ");
E 3
		if(sys[i].cntr[DATTYPE])
			printf("%3.d Data ", sys[i].cntr[DATTYPE]);
D 3
		else	printf("   ---   ");
E 3
I 3
		else
			printf("   ---   ");
E 3
		if(sys[i].cntr[XEQTYPE])
			printf("%3.d Xqt%s ", sys[i].cntr[XEQTYPE],
				sys[i].cntr[XEQTYPE]>1?"s":" ");
D 3
		else	printf("   ---   ");
		if(*sys[i].stst == NULL)
		{	if(sys[i].locked)
E 3
I 3
		else
			printf("   ---   ");
		if(*sys[i].stst == NULL || sys[i].locked > sys[i].st_lastime) {
			if(sys[i].locked)
E 3
				printf("LOCKED\n");
D 3
			else	printf("\n");
E 3
I 3
			else
				printf("\n");
E 3
			continue;
		}
		printf("%s  ", sys[i].stst);
D 3
		if(sys[i].st_type == SS_INPROGRESS)
		{	printf("\n");
E 3
I 3
		/* decide if STST info is worth pursuing */
		if (-t < ONEDAY*2 && (sys[i].st_count == 0
		  || sys[i].st_type == SS_WRONGTIME
		  || (sys[i].st_type == SS_INPROGRESS && sys[i].locked))) {
			printf("\n");
E 3
			continue;
		}
		t = (sys[i].st_lastime +sys[i].st_retry) - curtime;
D 3
		if(t <= 0)
			printf("Retry time reached  ");
		else
		{	if(t < 60)
				printf("Retry time %ld sec%s  ", (long)(t%60),
E 3
I 3
		if (-t < ONEDAY*2 && sys[i].st_type != SS_FAIL)
			t = 0;

		if (sys[i].st_count > MAXRECALLS)
			printf("at MAX RECALLS");
		else if (-t >= ONEDAY*2)
			printf("%ld days ago", (long)-t/ONEDAY);
		else if (t <= 0)
			printf("Retry time reached");
		else if (t < 60)
			printf("Retry time %ld sec%s", (long)(t%60),
E 3
					(t%60)!=1? "s": "");
D 3
			else	printf("Retry time %ld min%s  ", (long)(t/60),
					(t/60)!=1? "s": "");
		}
E 3
I 3
		else
			printf("Retry time %ld min%s", (long)(t/60),
				(t/60)!=1? "s": "");
E 3
		if(sys[i].st_count > 1)
D 3
			printf("Count: %d\n", sys[i].st_count);
		else	printf("\n");
E 3
I 3
			printf(" Count: %d\n", sys[i].st_count);
		else
			printf("\n");
E 3
	}
I 3
	if (xqtisrunning)
		printf("\nUuxqt is running\n");
E 3
	exit(0);
}
D 3
void scandir(dnam, prfx, flen, fchr, type)
E 3
I 3

scandir(dnam, prfx, flen, fchr, type)
E 3
char *dnam, *prfx, fchr;
D 3
{	register int i, plen;
E 3
I 3
{
D 5
	register int i, plen;
E 3
	char	fnam[MAXNAMLEN+1];
E 5
	register struct direct *dentp;
	register DIR *dirp;
I 5
	register int i, fnamlen, plen;
	char	fnam[MAXNAMLEN+1];
E 5

	plen = strlen(prfx);
D 3
	if(chdir(dnam) < 0)
	{	perror(dnam);
E 3
I 3
	if(chdir(dnam) < 0) {
		perror(dnam);
E 3
		exit(1);
	}
D 3
	if ((dirp = opendir(".", "r")) == NULL)
	{	perror(dnam);
E 3
I 3
	if ((dirp = opendir(".")) == NULL) {
		perror(dnam);
E 3
		exit(1);
	}
D 3
	while((dentp = readdir(dirp)) != NULL)
	{	if(*dentp->d_name == '.' || dentp->d_ino == 0)
E 3
I 3
	while((dentp = readdir(dirp)) != NULL) {
		if(*dentp->d_name == '.')
E 3
			continue;
		if(strncmp(dentp->d_name, prfx, plen) != SAME) {
D 3
#ifdef	UUDIR
E 3
			fprintf(stderr, "strange file (%s) in %s\n",
				dentp->d_name, dnam);
D 3
#endif
E 3
			continue;
		}
		strcpy(fnam, &dentp->d_name[plen]);
D 5
		i = strlen(fnam);
		if(flen > 0)
			fnam[i -flen] = NULL;
		else
D 3
		for(; i>0; --i)
		{	if(fnam[i] == fchr)
			{	fnam[i] = NULL;
				break;
E 3
I 3
			for(; i>0; --i) {
				if(fnam[i] == fchr) {
					fnam[i] = NULL;
E 5
I 5
		fnamlen = strlen(fnam);
		if(flen > 0) {
I 6
D 9
			char c;
E 9
E 6
			fnamlen -= flen;
D 6
			if (type == DATTYPE && (fnam[fnamlen] != 'S' && fnam[fnamlen] != 'B')) {
E 6
I 6
D 9
			c = fnam[fnamlen];
			if (islower(c))
				c = toupper(c);
			if (type == DATTYPE && (c != 'S' && c != 'B')) {
E 6
				fnamlen -= 2;	/* For Honey DanBer */
				fnam[fnamlen] = NULL;
			} else {
				fnam[fnamlen] = NULL;
				fnamlen = MAXBASENAME; /* yes, after = NULL*/
			}
E 9
I 9
			fnam[fnamlen] = NULL;
			fnamlen = MAXBASENAME; /* yes, after = NULL*/
E 9
		} else {
			for(; fnamlen>0; --fnamlen) {
				if(fnam[fnamlen] == fchr) {
					fnam[fnamlen] = NULL;
E 5
					break;
				}
E 3
			}
I 5
			fnamlen = MAXBASENAME;
		}
E 5
D 3
		}
		for(i=0; i<sndx; ++i)
		{	if(strcmp(fnam, sys[i].name) == SAME)
			{	++sys[i].cntr[type];
E 3
I 3
		for(i=0; i<sndx; ++i) {
D 5
			if(strcmp(fnam, sys[i].name) == SAME) {
E 5
I 5
			if(strncmp(fnam, sys[i].name, fnamlen) == SAME) {
E 5
				++sys[i].cntr[type];
E 3
				break;
			}
		}
D 3
		if(i == sndx)
		{	strcpy(sys[i].name, fnam);
E 3
I 3
		if(i == sndx) {
			strcpy(sys[i].name, fnam);
E 3
			++sys[i].cntr[type];
D 8
			++sndx;
E 8
I 8
			if(++sndx >=  NSYSTEM) {
				sndx = NSYSTEM-1;
				fprintf(stderr,"Too many system names.\n");
			}
E 8
		}
	}
	closedir(dirp);
}
D 3
void getstst(sdir)
E 3
I 3

getstst(sdir)
E 3
char *sdir;
D 3
{	register int i, csys;
E 3
I 3
{
	register int i, csys;
E 3
	register char *tp;
	char	fnam[MAXNAMLEN+1], buff[128];
	register struct	direct *dentp;
	register DIR *dirp;
	register FILE *st;
I 3
	struct stat stbuf;
I 6
	long atol();
E 6
E 3

D 3
	if(chdir(sdir) < 0)
	{	perror(sdir);
E 3
I 3
	if (chdir(sdir) < 0) {
		perror(sdir);
E 3
		exit(1);
	}
D 3
	if((dirp = opendir(".", "r")) == NULL)
	{	perror(sdir);
E 3
I 3
D 4
	if ((dirp = opendir(".")) == NULL) {
E 4
I 4
	if ((dirp = opendir(LOCKDIR)) == NULL) {
E 4
		perror(sdir);
E 3
		exit(1);
	}
D 3
	while((dentp = readdir(dirp)) != NULL)
	{	if(dentp->d_ino == 0)
E 3
I 3
	while ((dentp = readdir(dirp)) != NULL) {
D 7
		if (strcmp(dentp->d_name, X_LOCK) == SAME) {
E 7
I 7
		if (strcmp(&dentp->d_name[5], X_LOCK) == SAME) {
E 7
			xqtisrunning++;
E 3
			continue;
D 3
		if(strncmp(dentp->d_name, "LCK..", 5) == SAME)
		{	if(strncmp(&dentp->d_name[5], "tty", 3) == SAME ||
E 3
I 3
		}
		if(strncmp(dentp->d_name, "LCK..", 5) == SAME) {
			if(strncmp(&dentp->d_name[5], "tty", 3) == SAME ||
E 3
			   strncmp(&dentp->d_name[5], "cul", 3) == SAME)
				continue;
			strcpy(fnam, dentp->d_name);
D 3
			for(csys=0; csys<sndx; ++csys)
			{	if(strcmp(&fnam[5], sys[csys].name) == SAME)
E 3
I 3
			for(csys=0; csys<sndx; ++csys) {
D 5
				if(strcmp(&fnam[5], sys[csys].name) == SAME)
E 5
I 5
				if(strncmp(&fnam[5], sys[csys].name, SYSNSIZE)
					== SAME)
E 5
E 3
					break;
			}
I 5
			strcpy(sys[csys].name, &fnam[5]);
E 5
D 3
			if(csys == sndx)
			{	strcpy(sys[csys].name, &fnam[5]);
E 3
I 3
			if(csys == sndx) {
D 5
				strcpy(sys[csys].name, &fnam[5]);
E 5
E 3
				++sndx;
			}
D 3
			++sys[csys].locked;
E 3
I 3
			if (stat(fnam, &stbuf) < 0)
				sys[csys].locked = 1;
			else
				sys[csys].locked = stbuf.st_mtime;
E 3
			continue;
		}
D 3
		if(strncmp(dentp->d_name, "STST.", 5) == SAME)
		{	strcpy(fnam, dentp->d_name);
			for(csys=0; csys<sndx; ++csys)
			{	if(strcmp(&fnam[5], sys[csys].name) == SAME)
					break;
			}
			if(csys == sndx)
			{	strcpy(sys[csys].name, &fnam[5]);
				++sndx;
			}
			if((st = fopen(fnam, "r")) == NULL)
			{	strncpy(sys[csys].stst, "",
					sizeof(sys[csys].stst));
				continue;
			}
			strncpy(buff, "", sizeof(buff));
			fgets(buff, sizeof(buff), st);
			fclose(st);
			if(tp = rindex(buff, ' '))
				*tp = NULL;		/* drop system name */
			else	continue;
			for(i=0, tp=buff;  i<4;  ++i, ++tp)
				if((tp = index(tp, ' ')) == NULL)
					break;
			if(i != 4)
				continue;
			strncpy(sys[csys].stst, tp, sizeof(sys[csys].stst));
			tp = buff;
			sys[csys].st_type = atoi(tp);
			tp = index(tp+1, ' ');
			sys[csys].st_count = atoi(tp+1);
			tp = index(tp+1, ' ');
			sys[csys].st_lastime = (time_t)atol(tp+1);
			tp = index(tp+1, ' ');
			sys[csys].st_retry = (time_t)atol(tp+1);
		}
E 3
	}
	closedir(dirp);
I 3
	if (chdir("STST") < 0) {
		perror("STST");
		exit(1);
	}
	if ((dirp = opendir(".")) == NULL) {
		perror("STST");
		exit(1);
	}
	while ((dentp = readdir(dirp)) != NULL) {
		if(*dentp->d_name == '.')
			continue;
		strcpy(fnam, dentp->d_name);
		for(csys=0; csys<sndx; ++csys) {
D 5
			if(strcmp(fnam, sys[csys].name) == SAME)
E 5
I 5
			if(strncmp(fnam, sys[csys].name, SYSNSIZE) == SAME)
E 5
				break;
		}
I 5
		strcpy(sys[csys].name, fnam);
E 5
		if(csys == sndx) {
D 5
			strcpy(sys[csys].name, fnam);
E 5
			++sndx;
		}
		if((st = fopen(fnam, "r")) == NULL) {
D 5
			strncpy(sys[csys].stst, "", sizeof(sys[csys].stst));
E 5
I 5
			sys[csys].stst[0] = '\0';
E 5
			continue;
		}
D 5
		strncpy(buff, "", sizeof(buff));
E 5
I 5
		buff[0] = '\0';
E 5
		fgets(buff, sizeof(buff), st);
		fclose(st);
		if(tp = rindex(buff, ' '))
			*tp = NULL;		/* drop system name */
		else
			continue;
		for(i=0, tp=buff;  i<4;  ++i, ++tp)
			if((tp = index(tp, ' ')) == NULL)
				break;
		if(i != 4)
			continue;
		strncpy(sys[csys].stst, tp, sizeof(sys[csys].stst));
		tp = buff;
		sys[csys].st_type = atoi(tp);
		tp = index(tp+1, ' ');
		sys[csys].st_count = atoi(tp+1);
		tp = index(tp+1, ' ');
D 6
		sys[csys].st_lastime = (time_t)atol(tp+1);
E 6
I 6
		sys[csys].st_lastime = atol(tp+1);
E 6
		tp = index(tp+1, ' ');
D 6
		sys[csys].st_retry = (time_t)atol(tp+1);
E 6
I 6
		sys[csys].st_retry = atol(tp+1);
E 6
	}
E 3
}
D 3
/* @(#)index.c	4.1 (Berkeley) 12/21/80 */
E 3
/*
 * Return the ptr in sp at which the character c appears;
 * NULL if not found
 */

D 3

E 3
char *
index(sp, c)
register char *sp, c;
{
	do {
		if (*sp == c)
D 3
			return(sp);
E 3
I 3
			return sp;
E 3
	} while (*sp++);
D 3
	return(NULL);
E 3
I 3
	return NULL;
E 3
}

D 3
/* @(#)rindex.c	4.1 (Berkeley) 12/21/80 */
E 3
/*
 * Return the ptr in sp at which the character c last
 * appears; NULL if not found
*/

D 3

E 3
char *
rindex(sp, c)
register char *sp, c;
{
	register char *r;

	r = NULL;
	do {
		if (*sp == c)
			r = sp;
	} while (*sp++);
D 3
	return(r);
E 3
I 3
	return r;
E 3
}
E 1
