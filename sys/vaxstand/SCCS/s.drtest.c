h17827
s 00017/00014/00069
d D 7.3 88/03/04 16:10:07 bostic 21 19
c use disklabels, not old drive description table
e
s 00016/00014/00069
d R 7.3 88/03/04 13:52:51 bostic 20 19
c use disklabels, not old drive description table
e
s 00010/00033/00073
d D 7.2 88/02/24 11:06:59 bostic 19 18
c fix headers; use machine independent routines for prompting
e
s 00001/00001/00105
d D 7.1 86/06/05 01:41:26 mckusick 18 17
c 4.3BSD release version
e
s 00007/00001/00099
d D 6.2 85/06/08 13:08:05 mckusick 17 16
c Add copyright
e
s 00000/00000/00100
d D 6.1 83/07/29 07:46:48 sam 16 15
c 4.2 distribution
e
s 00001/00001/00099
d D 4.13 83/05/03 12:39:07 helge 15 14
c print cylinder numbers instead of sector numbers
e
s 00002/00002/00098
d D 4.12 83/03/20 20:01:28 root 14 13
c screwed up debug stuff (sam)
e
s 00003/00002/00097
d D 4.11 83/03/02 13:29:25 sam 13 12
c finally get it right
e
s 00075/00038/00024
d D 4.10 83/03/01 23:47:39 sam 12 11
c cleanup
e
s 00006/00006/00056
d D 4.9 83/03/01 19:07:19 sam 11 10
c foolish me
e
s 00029/00019/00033
d D 4.8 83/02/20 16:27:53 helge 10 9
c cleanup
e
s 00001/00000/00051
d D 4.7 83/02/04 08:56:47 sam 9 8
c add SCCS keywords
e
s 00001/00001/00050
d D 4.6 83/02/04 08:55:58 sam 8 7
c pointer problem
e
s 00003/00002/00048
d D 4.5 83/02/03 16:43:12 helge 7 6
c cosmetic changes
e
s 00002/00002/00048
d D 4.4 83/01/29 13:35:36 helge 6 4
c minor changes
e
s 00002/00002/00048
d R 4.4 83/01/29 13:33:39 helge 5 4
c 
e
s 00009/00008/00041
d D 4.3 83/01/23 17:25:17 sam 4 3
c check in for Helge before cutting tape for Robert
e
s 00022/00049/00027
d D 4.2 83/01/17 10:53:20 helge 3 1
c more ioctl's & some bug fixes
e
s 00022/00049/00027
d R 4.2 83/01/16 14:39:14 helge 2 1
c bug fixes
e
s 00076/00000/00000
d D 4.1 82/12/26 18:53:14 sam 1 0
c date and time created 82/12/26 18:53:14 by sam
e
u
U
t
T
I 9
D 17
/*	%M%	%I%	%E%	*/
E 17
I 17
/*
D 18
 * Copyright (c) 1982 Regents of the University of California.
E 18
I 18
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 17
E 9
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3

I 11
/*
 * Standalone program to test a disk and driver
D 12
 * by reading the disk in CHUNK sector units.
E 12
I 12
 * by reading the disk a track at a time.
E 12
 */
E 11
D 3
/*
 * Standalone program to test a disk driver by reading
 * every sector on the disk in chunks of CHUNK.
E 3
I 3
D 19
#include "../h/param.h"
#include "../h/inode.h"
#include "../h/fs.h"
E 19
I 19
#include "param.h"
#include "inode.h"
#include "fs.h"
I 21
#include "disklabel.h"
E 21

E 19
#include "saio.h"

D 11
/* Standalone program to test a disk driver by reading every sector on
 * the disk in chunks of CHUNK.
E 3
 */
D 3
extern	struct hpst  {
	short nsect;
	short ntrak;
	short nspc;
	short ncyl;
	short *off;
} hpst[] ;
E 3

E 11
D 3
extern	struct upst  {
	short nsect;
	short ntrak;
	short nspc;
	short ncyl;
	short *off;
} upst[] ;
extern struct updevice;
extern struct hpdevice;
extern char up_type[];
extern char hp_type[];
E 3
I 3
D 12
#define CHUNK	32
E 12
#define SECTSIZ	512
E 3

I 4
D 12
char diskname[] = "xx(00,0)";
E 12
I 12
extern	int end;
char	*malloc();
D 19
char	*prompt();
E 19
E 12

E 4
D 3
#define CHUNK 32

E 3
main()
{
D 3
	char buf[50], buffer[CHUNK*512];
E 3
I 3
D 12
	char buf[50], buffer[CHUNK*SECTSIZ];
E 3
D 10
	int unit,fd,chunk,j;
E 10
I 10
	int unit, fd, chunk, j, hc = 0;
E 12
I 12
D 21
	char *cp, *bp;
	int fd, tracksize, debug;
	register int sector, lastsector;
E 12
E 10
D 3
	register struct upst *st;
E 3
I 3
	struct st st;
E 21
I 21
	register int fd, sector, lastsector, tracksize;
	register char *bp;
	struct disklabel dl;
	int debug;
E 21
E 3
D 12
	register i;
E 12

D 7
	printf("Testprogram for stand-alone hp or up driver\n");
E 7
I 7
D 12
	printf("Testprogram for stand-alone hp or up driver\n\n");
I 10
	printf("Is the console terminal a hard-copy device (y/n)? ");
	gets(buf);
	if (*buf == 'y')
		hc = 1;
E 10
E 7
askunit:
D 4
	printf("Enter device name (e.g, hp(0,0) ) or q to quit >");
E 4
I 4
D 10
	printf("Enter disk name [ type(adapter,unit), e.g, hp(1,3) ] > ");
E 10
I 10
D 11
	printf("Enter disk name [ type(adapter,unit), e.g, hp(1,3) ] ? ");
E 11
I 11
	printf("Enter disk name [type(adapter,unit), e.g, hp(1,3)] ? ");
E 11
E 10
E 4
	gets(buf);
D 4
	unit = (int)*(buf+3) - '0';
	if (unit <0 || unit > 3 ) {
		printf("unit number out of range\n");
		goto askunit;
	}
	if ((fd=open(buf,0)) < 0) {
D 3
		printf("Can't open %s \n",buf);
E 3
I 3
	     printf("Can't open %s \n",buf);
E 4
I 4
D 10
	unit = (*(buf+3) - '0')*8 + *(buf+5)-'0';
	diskname[0] = *buf;
	diskname[1] = *(buf+1);
	diskname[3] = '0' + unit/10;
	diskname[4] = '0' + unit%10;
	if ((fd=open(diskname,0)) < 0) {
E 10
I 10
	unit = (*(buf + 3) - '0')*8 + *(buf + 5) - '0';
	diskname[0] = *buf;	
	diskname[1] = *(buf + 1);
	diskname[3] = '0' + (unit / 10);
	diskname[4] = '0' + (unit % 10);
	if ((fd = open(diskname, 0)) < 0) {
E 10
E 4
E 3
		goto askunit;
	}
E 12
I 12
	printf("Testprogram for stand-alone driver\n\n");
again:
D 19
	cp = prompt("Enable debugging (1=bse, 2=ecc, 3=bse+ecc)? ");
	debug = atoi(cp);
E 19
I 19
D 21
	debug = getdebug("Enable debugging (1=bse, 2=ecc, 3=bse+ecc)? ");
E 21
I 21
	debug = getdebug("Enable debugging (0=none, 1=bse, 2=ecc, 3=bse+ecc)? ");
E 21
E 19
	if (debug < 0)
		debug = 0;
D 19
	fd = getdevice();
E 19
I 19
	fd = getfile("Device to read?", 2);
E 19
E 12
D 3
	switch(*buf) {
E 3
I 3
D 10
	ioctl(fd,SAIODEVDATA,&st);
E 10
I 10
D 14
	ioctl(fd, SAIODEVDATA, &st);
E 14
I 14
D 21
	ioctl(fd, SAIODEVDATA, (char *)&st);
E 21
I 21
	ioctl(fd, SAIODEVDATA, &dl);
E 21
E 14
E 10
E 3
D 7

E 7
I 7
	printf("Device data: #cylinders=%d, #tracks=%d, #sectors=%d\n",
D 8
		st->ncyl, st->ntrak, st->nsect);
E 8
I 8
D 21
		st.ncyl, st.ntrak, st.nsect);
E 21
I 21
		dl.d_ncylinders, dl.d_ntracks, dl.d_nsectors);
E 21
E 8
E 7
D 3
	case 'u':
		st = &upst[up_type[unit]];
		break;

	case 'h':
		st = (struct upst *)&hpst[hp_type[unit]];
		break;

	default:
		printf("Illegal device name\n");
		goto askunit;
	}

	chunk = st->nsect;
	printf("Testing %s\n",buf);
E 3
I 3
D 10
	chunk = st.nsect*SECTSIZ;
E 10
I 10
D 12
	chunk = st.nsect * SECTSIZ;
E 10
D 6
	printf("Testing %s, chunk size is %d\n",buf, chunk);
E 6
I 6
	printf("Testing %s, chunk size is %d bytes\n",buf, chunk);
E 6
E 3
D 10
	printf("Start ...Make sure %s is online\n",buf);
	lseek(fd,0,0);
D 3
	for (i=0;i < st->ncyl;i++) {
		for (j=8;j<st->ntrak+8;j++) {
			lseek(fd,(i*st->nspc+((j%st->ntrak)*st->nsect))*512,0);
			read(fd,buffer, chunk*512);
		}
		printf("%d\015",i);
E 3
I 3
	for (i=0;i < st.ncyl*st.ntrak; i++) {
/*		for (j=8;j<st.ntrak+8;j++) {
			lseek(fd,(i*st.nspc+((j%st.ntrak)*st.nsect))*SECTSIZ,0);
*/
			read(fd,buffer, chunk);
/*		}					*/
D 6
		if (i%st.ntrak == 0) printf("%d\r",i/st.ntrak);
E 6
I 6
		if (i%(st.ntrak*5) == 0) printf("%d\r",i/st.ntrak);
E 10
I 10
	printf("Start ...Make sure %s is online\n", buf);
E 12
I 12
D 14
	ioctl(fd, SAIODEBUG, &debug);
E 14
I 14
	ioctl(fd, SAIODEBUG, (char *)debug);
E 14
D 21
	tracksize = st.nsect * SECTSIZ;
E 21
I 21
	tracksize = dl.d_nsectors * SECTSIZ;
E 21
I 13
	bp = malloc(tracksize);
E 13
	printf("Reading in %d byte records\n", tracksize);
	printf("Start ...make sure drive is on-line\n");
E 12
D 19
	lseek(fd, 0, 0);
E 19
I 19
	lseek(fd, 0, L_SET);
E 19
D 12
	for (i = 0; i < st.ncyl * st.ntrak; i++) {
		read(fd, buffer, chunk);
		if ((i % (st.ntrak*5)) == 0) {
			int x = i / st.ntrak;
E 12
I 12
D 13
	lastsector = st.ncyl * st.ntrak;
	for (sector = 0; sector < lastsector; sector++) {
E 13
I 13
D 21
	lastsector = st.ncyl * st.nspc;
	for (sector = 0; sector < lastsector; sector += st.nsect) {
E 13
		if (sector && (sector % (st.nspc * 10)) == 0)
D 15
			printf("sector %d\n", sector);
E 15
I 15
			printf("cylinder %d\n", sector/st.nspc);
E 21
I 21
	lastsector = dl.d_ncylinders * dl.d_secpercyl;
	for (sector = 0; sector < lastsector; sector += dl.d_nsectors) {
		if (sector && (sector % (dl.d_secpercyl * 10)) == 0)
			printf("cylinder %d\n", sector/dl.d_secpercyl);
E 21
E 15
		read(fd, bp, tracksize);
	}
	goto again;
I 21
	/*NOTREACHED*/
E 21
}
E 12

I 21
static
E 21
D 12
			if (!hc)
				printf("%d\r", x);
			else {
				printf(".");
D 11
				if ((x + 1 % 25) == 0)
E 11
I 11
				if (x && (x % 125) == 0)
E 11
					printf(". %d\n", x);
			}
		}
E 12
I 12
D 19
/*
 * Prompt and verify a device name from the user.
 */
getdevice()
{
	register char *cp;
	register struct devsw *dp;
	int fd;

top:
	cp = prompt("Device to read? ");
	if ((fd = open(cp, 2)) < 0) {
		printf("Known devices are: ");
		for (dp = devsw; dp->dv_name; dp++)
			printf("%s ",dp->dv_name);
		printf("\n");
		goto top;
E 12
E 10
E 6
E 3
	}
D 12
	goto askunit;
E 12
I 12
	return (fd);
}

char *
prompt(msg)
E 19
I 19
getdebug(msg)
E 19
	char *msg;
{
D 19
	static char buf[132];
E 19
I 19
	char buf[132];
E 19

	printf("%s", msg);
	gets(buf);
D 19
	return (buf);
E 19
I 19
	return (atoi(buf));
E 19
}

/*
 * Allocate memory on a page-aligned address.
 * Round allocated chunk to a page multiple to
 * ease next request.
 */
D 21
char *
E 21
I 21
static char *
E 21
malloc(size)
	int size;
{
D 21
	char *result;
E 21
	static caddr_t last = 0;
I 21
	char *result;
E 21

	if (last == 0)
		last = (caddr_t)(((int)&end + 511) & ~0x1ff);
	size = (size + 511) & ~0x1ff;
	result = (char *)last;
	last += size;
	return (result);
E 12
}
E 1
