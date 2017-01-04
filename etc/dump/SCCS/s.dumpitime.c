h40992
s 00052/00057/00208
d D 5.2 86/05/28 10:38:41 mckusick 15 14
c update /etc/dumpdates in place
e
s 00009/00001/00256
d D 5.1 85/06/05 08:45:26 dist 14 13
c Add copyright
e
s 00024/00007/00233
d D 1.13 84/03/28 19:03:30 mckusick 13 12
c better estimate for files with holes using "di_blocks"
e
s 00001/00000/00239
d D 1.12 83/09/13 18:26:58 mckusick 12 11
c initialize last dump time to the epoch (shannon)
e
s 00006/00002/00233
d D 1.11 83/06/15 15:11:32 sam 11 10
c defines changed
e
s 00001/00000/00234
d D 1.10 83/06/09 12:50:21 mckusick 10 9
c print out correct previous incremental number
e
s 00025/00044/00209
d D 1.9 83/05/19 19:26:05 mckusick 9 8
c introduce true locking on /etc/dumpdates; 
c get rid of -J option that converts from /etc/ddates to /etc/dumpdates
e
s 00006/00000/00247
d D 1.8 83/05/19 18:01:05 mckusick 8 7
c re-read /etc/dumpdates before updating it
e
s 00001/00001/00246
d D 1.7 82/12/02 17:52:19 mckusick 7 6
c fix to properly dump 4096/512 byte file systems
e
s 00001/00001/00246
d D 1.6 82/10/14 12:51:33 mckusick 6 5
c fix to properly dump file systems with 512 byte frags
e
s 00001/00001/00246
d D 1.5 82/02/25 14:55:58 mckusic 5 4
c use speed-up macros in fs.h
e
s 00012/00013/00235
d D 1.4 82/01/05 01:37:11 mckusic 4 3
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00004/00003/00244
d D 1.3 81/11/07 14:53:08 mckusic 3 2
c dump to "standard" (ie 1K file system) dump tapes
e
s 00010/00008/00237
d D 1.2 81/10/31 18:29:59 mckusic 2 1
c 8K only dump/restor
e
s 00245/00000/00000
d D 1.1 80/10/13 17:30:25 root 1 0
c date and time created 80/10/13 17:30:25 by root
e
u
U
t
T
I 1
D 14
static	char *sccsid = "%W% (Berkeley) %G%";
E 14
I 14
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 14
I 9

E 9
#include "dump.h"
I 9
#include <sys/file.h>
E 9

char *prdate(d)
	time_t d;
{
	char *p;

	if(d == 0)
		return("the epoch");
	p = ctime(&d);
	p[24] = 0;
	return(p);
}

struct	idates	**idatev = 0;
int	nidates = 0;
int	idates_in = 0;
struct	itime	*ithead = 0;

inititimes()
{
D 15
			FILE	*df;
	register	int	i;
	register	struct	itime	*itwalk;
I 9
			int fd;
E 15
I 15
	FILE *df;
E 15
E 9

D 15
	if (idates_in)
		return;
D 9
	if ( (df = fopen(increm, "r")) == NULL){
E 9
I 9
D 11
	if ((fd = open(increm, FSHLOCK|FRDONLY, 0600)) < 0) {
E 11
I 11
	fd = open(increm, O_RDONLY);
	if (fd < 0) {
E 15
I 15
	if ((df = fopen(increm, "r")) == NULL) {
E 15
E 11
		perror(increm);
		return;
	}
I 11
D 15
	(void) flock(fd, LOCK_SH);
E 11
	if ((df = fdopen(fd, "r")) == NULL) {
E 9
		nidates = 0;
		ithead = 0;
	} else {
		do{
			itwalk=(struct itime *)calloc(1,sizeof (struct itime));
			if (getrecord(df, &(itwalk->it_value)) < 0)
				break;
			nidates++;
			itwalk->it_next = ithead;
			ithead = itwalk;
		} while (1);
		fclose(df);
E 15
I 15
	(void) flock(fileno(df), LOCK_SH);
	readitimes(df);
	fclose(df);
}

readitimes(df)
	FILE *df;
{
	register	int	i;
	register	struct	itime	*itwalk;

	for (;;) {
		itwalk = (struct itime *)calloc(1, sizeof (struct itime));
		if (getrecord(df, &(itwalk->it_value)) < 0)
			break;
		nidates++;
		itwalk->it_next = ithead;
		ithead = itwalk;
E 15
	}

	idates_in = 1;
	/*
	 *	arrayify the list, leaving enough room for the additional
	 *	record that we may have to add to the idate structure
	 */
	idatev = (struct idates **)calloc(nidates + 1,sizeof (struct idates *));
D 15
	for (i = nidates-1, itwalk = ithead; i >= 0; i--, itwalk = itwalk->it_next)
E 15
I 15
	itwalk = ithead;
	for (i = nidates - 1; i >= 0; i--, itwalk = itwalk->it_next)
E 15
		idatev[i] = &itwalk->it_value;
}

getitime()
{
	register	struct	idates	*ip;
	register	int	i;
			char	*fname;

	fname = disk;
#ifdef FDEBUG
	msg("Looking for name %s in increm = %s for delta = %c\n",
		fname, increm, incno);
#endif
	spcl.c_ddate = 0;
I 12
	lastincno = '0';
E 12

	inititimes();
	/*
	 *	Go find the entry with the same name for a lower increment
	 *	and older date
	 */
D 15
	ITITERATE(i, ip){
		if(strncmp(fname, ip->id_name,
				sizeof (ip->id_name)) != 0)
E 15
I 15
	ITITERATE(i, ip) {
		if (strncmp(fname, ip->id_name, sizeof (ip->id_name)) != 0)
E 15
			continue;
		if (ip->id_incno >= incno)
			continue;
		if (ip->id_ddate <= spcl.c_ddate)
			continue;
		spcl.c_ddate = ip->id_ddate;
I 10
D 15
 		lastincno = ip->id_incno;
E 10
	} 
E 15
I 15
		lastincno = ip->id_incno;
	}
E 15
}

putitime()
{
	FILE		*df;
	register	struct	idates	*itwalk;
	register	int	i;
I 9
	int		fd;
E 9
	char		*fname;

	if(uflag == 0)
		return;
I 9
D 11
	if ((fd = open(temp, FCREATE|FEXLOCK|FRDWR, 0600)) < 0) {
E 11
I 11
D 15
	fd = open(temp, O_RDWR|O_CREAT, 0600);
	if (fd < 0) {
E 11
		perror(temp);
E 15
I 15
	if ((df = fopen(increm, "r+")) == NULL) {
		perror(increm);
E 15
		dumpabort();
	}
I 15
	fd = fileno(df);
E 15
I 11
	(void) flock(fd, LOCK_EX);
E 11
D 15
	if ((df = fdopen(fd, "w")) == NULL) {
		perror(temp);
		dumpabort();
	}
E 15
E 9
	fname = disk;
I 8
	free(idatev);
	idatev = 0;
	nidates = 0;
	ithead = 0;
	idates_in = 0;
D 15
	inititimes();
E 8

E 15
I 15
	readitimes(df);
	if (fseek(df,0L,0) < 0) {   /* rewind() was redefined in dumptape.c */
		perror("fseek");
		dumpabort();
	}
E 15
	spcl.c_ddate = 0;
	ITITERATE(i, itwalk){
		if (strncmp(fname, itwalk->id_name,
				sizeof (itwalk->id_name)) != 0)
			continue;
		if (itwalk->id_incno != incno)
			continue;
		goto found;
	}
	/*
	 *	construct the new upper bound;
	 *	Enough room has been allocated.
	 */
	itwalk = idatev[nidates] =
		(struct idates *)calloc(1, sizeof(struct idates));
	nidates += 1;
  found:
	strncpy(itwalk->id_name, fname, sizeof (itwalk->id_name));
	itwalk->id_incno = incno;
	itwalk->id_ddate = spcl.c_date;

D 9
	if ( (df = fopen(increm, "w")) == NULL){
		msg("Cannot open %s\n", increm);
		dumpabort();
	}
E 9
	ITITERATE(i, itwalk){
		recout(df, itwalk);
	}
D 9
	fclose(df);
E 9
I 9
D 15
	if (rename(temp, increm) < 0) {
		perror("rename");
		(void) unlink(temp);
E 15
I 15
	if (ftruncate(fd, ftell(df))) {
		perror("ftruncate");
E 15
		dumpabort();
	}
D 15
	(void) chmod(increm, 0644);
E 15
	(void) fclose(df);
E 9
	msg("level %c dump on %s\n", incno, prdate(spcl.c_date));
}

recout(file, what)
	FILE	*file;
	struct	idates	*what;
{
	fprintf(file, DUMPOUTFMT,
		what->id_name,
		what->id_incno,
		ctime(&(what->id_ddate))
	);
}

int	recno;
int getrecord(df, idatep)
	FILE	*df;
	struct	idates	*idatep;
{
	char		buf[BUFSIZ];

	recno = 0;
	if ( (fgets(buf, BUFSIZ, df)) != buf)
		return(-1);
	recno++;
	if (makeidate(idatep, buf) < 0)
		msg("Unknown intermediate format in %s, line %d\n",
D 9
			NINCREM, recno);
E 9
I 9
			increm, recno);
E 9

#ifdef FDEBUG
	msg("getrecord: %s %c %s\n",
		idatep->id_name, idatep->id_incno, prdate(idatep->id_ddate));
#endif
	return(0);
D 9
}

/*
 *	Convert from old format to new format
 *	Convert from /etc/ddate to /etc/dumpdates format
 */
o_nconvert()
{
	FILE	*oldfile;
	FILE	*newfile;
	struct	idates	idate;
	struct	idates	idatecopy;

	if( (newfile = fopen(NINCREM, "w")) == NULL){
		msg("%s: Can not open %s to update.\n", processname, NINCREM);
		Exit(X_ABORT);
	}
	if ( (oldfile = fopen(OINCREM, "r")) != NULL){
		while(!feof(oldfile)){
			if (fread(&idate, sizeof(idate), 1, oldfile) != 1)
				break;
			/*
			 *	The old format ddate did not have
			 *	the full special path name on it;
			 *	we add the prefix /dev/ to the
			 *	special name, although this may not be
			 *	always the right thing to do.
			 */
			idatecopy = idate;
			strcpy(idatecopy.id_name, "/dev/");
			strncat(idatecopy.id_name, idate.id_name,
				sizeof(idate.id_name) - sizeof ("/dev/"));
			recout(newfile, &idatecopy);
		}
	}
	fclose(oldfile);
	fclose(newfile);
E 9
}

time_t	unctime();

int makeidate(ip, buf)
	struct	idates	*ip;
	char	*buf;
{
	char	un_buf[128];

	sscanf(buf, DUMPINFMT, ip->id_name, &ip->id_incno, un_buf);
	ip->id_ddate = unctime(un_buf);
	if (ip->id_ddate < 0)
		return(-1);
	return(0);
}

I 2
/*
D 4
 * This is an estimation of the size of the file.
E 4
I 4
 * This is an estimation of the number of TP_BSIZE blocks in the file.
E 4
D 13
 * It assumes that there are no unallocated blocks; hence
 * the estimate may be high
E 13
I 13
 * It estimates the number of blocks in files with holes by assuming
 * that all of the blocks accounted for by di_blocks are data blocks
 * (when some of the blocks are usually used for indirect pointers);
 * hence the estimate may be high.
E 13
 */
E 2
est(ip)
	struct dinode *ip;
{
D 13
	long s;
E 13
I 13
	long s, t;
E 13

I 13
D 15
 	/*
 	 * ip->di_size is the size of the file in bytes.
 	 * ip->di_blocks stores the number of sectors actually in the file.
 	 * If there are more sectors than the size would indicate, this just
 	 *	means that there are indirect blocks in the file or unused
	 *	sectors in the last file block;	we can safely ignore these
E 15
I 15
	/*
	 * ip->di_size is the size of the file in bytes.
	 * ip->di_blocks stores the number of sectors actually in the file.
	 * If there are more sectors than the size would indicate, this just
	 *	means that there are indirect blocks in the file or unused
	 *	sectors in the last file block; we can safely ignore these
E 15
	 *	(s = t below).
D 15
 	 * If the file is bigger than the number of sectors would indicate,
 	 *	then the file has holes in it.  In this case we must use the
 	 *	block count to estimate the number of data blocks used, but
 	 *	we use the actual size for estimating the number of indirect
 	 *	dump blocks (t vs. s in the indirect block calculation).
 	 */
E 15
I 15
	 * If the file is bigger than the number of sectors would indicate,
	 *	then the file has holes in it.	In this case we must use the
	 *	block count to estimate the number of data blocks used, but
	 *	we use the actual size for estimating the number of indirect
	 *	dump blocks (t vs. s in the indirect block calculation).
	 */
E 15
E 13
	esize++;
D 3
	s = (ip->di_size + BSIZE-1) / BSIZE;
E 3
I 3
D 4
	s = (ip->di_size + FSIZE-1) / FSIZE;
E 3
	esize += s;
I 3
	s /= FRAG;
E 3
D 2
	if(s > NADDR-3) {
		/*
		 *	This code is only appproximate.
		 *	it totally estimates low on doubly and triply indirect
		 *	files.
		 */
		s -= NADDR-3;
		s = (s + (BSIZE/sizeof(daddr_t))-1) / (BSIZE/sizeof(daddr_t));
E 2
I 2
	if (s > NDADDR) {
		s -= NDADDR;
		if (s > BSIZE / sizeof(daddr_t))
			esize++;
		s = (s + (BSIZE/sizeof(daddr_t)) - 1) / (BSIZE/sizeof(daddr_t));
E 2
D 3
		esize += s;
E 3
I 3
		esize += s * FRAG;
E 4
I 4
D 13
	/* calc number of TP_BSIZE blocks */
D 5
	s = roundup(ip->di_size, sblock->fs_fsize) / TP_BSIZE;
E 5
I 5
D 7
	s = fragroundup(sblock, ip->di_size) / TP_BSIZE;
E 7
I 7
	s = howmany(ip->di_size, TP_BSIZE);
E 13
I 13
D 15
 	s = howmany(dbtob(ip->di_blocks), TP_BSIZE);
 	t = howmany(ip->di_size, TP_BSIZE);
 	if ( s > t )
 		s = t;
E 15
I 15
	s = howmany(dbtob(ip->di_blocks), TP_BSIZE);
	t = howmany(ip->di_size, TP_BSIZE);
	if ( s > t )
		s = t;
E 15
E 13
E 7
E 5
	if (ip->di_size > sblock->fs_bsize * NDADDR) {
D 13
		/* calc number of indirect blocks on the dump tape */
D 6
		s += howmany(s - NDADDR * BLKING(sblock) * sblock->fs_frag,
E 6
I 6
		s += howmany(s - NDADDR * sblock->fs_bsize / TP_BSIZE,
E 13
I 13
		/* calculate the number of indirect blocks on the dump tape */
		s += howmany(t - NDADDR * sblock->fs_bsize / TP_BSIZE,
E 13
E 6
			TP_NINDIR);
E 4
E 3
	}
I 4
	esize += s;
E 4
}

bmapest(map)
D 4
short *map;
E 4
I 4
	char *map;
E 4
{
	register i, n;

	n = -1;
D 4
	for(i=0; i<MSIZ; i++)
E 4
I 4
	for (i = 0; i < msiz; i++)
E 4
		if(map[i])
			n = i;
	if(n < 0)
		return;
I 4
	n++;
E 4
	esize++;
D 3
	esize += (n + (BSIZE/sizeof(short))-1) / (BSIZE/sizeof(short));
E 3
I 3
D 4
	esize += (n + (BSIZE/sizeof(short))-1) / (BSIZE/sizeof(short)) * FRAG;
E 4
I 4
	esize += howmany(n * sizeof map[0], TP_BSIZE);
E 4
E 3
}
E 1
