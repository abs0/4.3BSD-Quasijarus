h03300
s 00002/00002/00520
d D 5.13 87/10/22 10:45:31 bostic 30 29
c ANSI C; sprintf now returns an int.
e
s 00022/00012/00500
d D 5.12 87/03/29 16:23:38 karels 29 28
c I *like* newlines on messages; add -c to clear dump magic
e
s 00001/00001/00511
d D 5.11 87/02/23 17:40:07 mckusick 28 27
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00008/00003/00504
d D 5.10 87/01/08 20:32:40 karels 27 26
c do it anyway!
e
s 00043/00066/00464
d D 5.9 86/10/13 15:12:03 sam 26 25
c add tahoe stuff; consolidate common code in log+Perror
e
s 00053/00005/00477
d D 5.8 86/05/26 22:10:21 karels 25 24
c show error messages on stderr too
e
s 00004/00027/00478
d D 5.7 86/05/12 18:30:20 eric 24 23
c eliminate shutdownlog in favor of syslog
e
s 00001/00003/00504
d D 5.6 86/05/12 17:45:28 eric 23 22
c shutdownlog subsumed into syslog (as LOG_AUTH)
e
s 00120/00153/00387
d D 5.5 86/02/18 17:06:25 sam 22 21
c lots of mickey-mouse things; use syslog; compress nlist checks 
c into an array and a loop; use symbolic constants for open, lseek, access;
e
s 00014/00006/00526
d D 5.4 86/01/30 19:47:30 karels 21 20
c use larger buffer for those of us with swap and crash
c on same disk
e
s 00003/00004/00529
d D 5.3 86/01/09 14:27:35 mckusick 20 19
c better calculation of freespace
e
s 00006/00002/00527
d D 5.2 85/09/08 13:59:52 bloom 19 18
c portability cleanup, allow to work with core dumps which terminate when they
c reach the end of the partition
e
s 00014/00002/00515
d D 5.1 85/06/04 16:47:02 dist 18 17
c Add copyright
e
s 00001/00002/00516
d D 4.15 85/06/03 09:36:25 karels 17 16
c can get dumptime from specified system now
e
s 00098/00027/00420
d D 4.14 84/07/17 16:40:12 ralph 16 15
c added -v option, works correctly when given alt. system name.
e
s 00001/00001/00446
d D 4.13 83/07/02 00:19:23 sam 15 14
c include fixes
e
s 00003/00003/00444
d D 4.12 83/05/03 20:53:12 sam 14 13
c fix name conflict with kernel
e
s 00004/00004/00443
d D 4.11 83/03/21 11:25:44 sam 13 12
c read dumpsize from dump image instead of memory
e
s 00053/00084/00394
d D 4.10 83/02/21 00:28:39 sam 12 11
c merge of mods from sun now that system is changed
e
s 00001/00070/00477
d D 4.9 82/10/24 16:04:59 mckusick 11 8
i 10 9
c merge in mods from matisse
e
s 00082/00025/00370
d D 4.7.1.2 82/10/24 15:51:14 mckusick 10 9
c fixes per ark
e
s 00000/00000/00395
d D 4.7.1.1 82/10/24 15:49:21 mckusick 9 7
c branch-place-holder
e
s 00097/00027/00368
d D 4.8 82/10/21 14:21:24 sam 8 7
c new super block format, check for string termination, & lots more
e
s 00011/00004/00384
d D 4.7 81/05/20 17:47:02 root 7 6
c fix to have 3 args but kludged: should read dump* from argv[2] instead of /dev/kmem if argc > 2
e
s 00008/00003/00380
d D 4.6 81/05/20 16:40:51 root 6 5
c debug code
e
s 00002/00006/00381
d D 4.5 81/05/14 18:15:31 root 5 4
c version mismatch is a warning
e
s 00200/00283/00187
d D 4.4 81/04/28 00:45:44 root 4 3
c major cleanup
e
s 00008/00003/00462
d D 4.3 81/04/14 19:17:10 root 3 2
c make it work!
e
s 00004/00001/00461
d D 4.2 81/04/03 12:59:42 root 2 1
c fix to not double-save dumps
e
s 00462/00000/00000
d D 4.1 81/04/02 21:47:07 root 1 0
c date and time created 81/04/02 21:47:07 by root
e
u
U
f b 
t
T
I 18
/*
D 25
 * Copyright (c) 1980 Regents of the University of California.
E 25
I 25
 * Copyright (c) 1980,1986 Regents of the University of California.
E 25
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 18
I 12
#ifndef lint
E 12
I 4
D 18
static	char *sccsid = "%W% (Berkeley) %E%";
I 12
#endif
E 18
I 18
char copyright[] =
D 25
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 25
I 25
"%Z% Copyright (c) 1980,1986 Regents of the University of California.\n\
E 25
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 18

E 12
E 4
I 1
/*
D 4
 *	%M%	%I%	%E%
 * savecore dirname
 *	Written by Michael Toy (UCB)
 *	Program meant to be called from the /etc/rc file for saving the
 * dump of a crashed system.  If the core file has not already been saved
 * then save it in dirname (if there is at least minfree blocks on the
 * device the directory is on.)
 *	1) Make certain "dirname" exists
 *	2) Get dumpdev and dumplo from vmunix/kmem
 *	3) Find dump device name get time from core image
 *	4) Look in "dirname" generate a name se
 *		vmunix.n
 *		vmcore.n
 *	5) Check in "dirname"/minfree to be certain there is space
 *	6) Make entry in shutdown log with date and cause of crash
E 4
I 4
 * savecore
E 4
 */
I 16

E 16
D 12

E 12
#include <stdio.h>
#include <nlist.h>
#include <sys/param.h>
#include <sys/dir.h>
#include <sys/stat.h>
D 8
D 10
#include <sys/filsys.h>
E 10
I 10
#include <sys/fs.h>
E 10
E 8
I 8
D 11
#include <sys/fs.h>
E 11
E 8
D 15
#include <time.h>
E 15
I 15
#include <sys/time.h>
I 22
#include <sys/file.h>
D 25
#include <syslog.h>
E 25
I 25
#include <sys/syslog.h>
E 25
E 22
E 15

D 4
#define LEEWAY (60L*60L*24L*3L)	/* Maximum reasonable dump age diff (3 days )*/
#define eq(a,b) (strcmp(a,b)==0)
#define ok(number) (number&0x7fffffff)
E 4
I 4
#define	DAY	(60L*60L*24L)
#define	LEEWAY	(3*DAY)

#define eq(a,b) (!strcmp(a,b))
I 12
#ifdef vax
E 12
#define ok(number) ((number)&0x7fffffff)
I 12
#else
I 26
#ifdef tahoe
#define ok(number) ((number)&~0xc0000000)
#else
E 26
#define ok(number) (number)
#endif
I 26
#endif
E 26
E 12

E 4
D 23
#define SHUTDOWNLOG "/usr/adm/shutdownlog"
D 4
#define TRUE (1)
#define FALSE (0)
E 4

E 23
D 16
struct nlist nl[] = {
E 16
I 16
struct nlist current_nl[] = {	/* namelist for currently running system */
E 16
#define X_DUMPDEV	0
	{ "_dumpdev" },
#define X_DUMPLO	1
	{ "_dumplo" },
#define X_TIME		2
	{ "_time" },
D 12
#define X_PHYSMEM	3
	{ "_physmem" },
E 12
I 12
#define	X_DUMPSIZE	3
	{ "_dumpsize" },
E 12
#define X_VERSION	4
	{ "_version" },
#define X_PANICSTR	5
	{ "_panicstr" },
I 10
D 12
#define X_DOADUMP	6
	{ "_doadump" },
E 10
I 8
#define X_DOADUMP	6
	{ "_doadump" },
E 8
	{ 0 },
E 12
I 12
#define	X_DUMPMAG	6
	{ "_dumpmag" },
	{ "" },
E 12
};

I 16
struct nlist dump_nl[] = {	/* name list for dumped system */
	{ "_dumpdev" },		/* entries MUST be the same as */
	{ "_dumplo" },		/*	those in current_nl[]  */
	{ "_time" },
	{ "_dumpsize" },
	{ "_version" },
	{ "_panicstr" },
	{ "_dumpmag" },
	{ "" },
};

E 16
I 10
D 12
/*
 *	this magic number is found in the kernel at label "doadump"
 *
 *	It is derived as follows:
 *
 *		doadump:	nop			01
 *				nop			01
 *				bicl2 $...		ca
 *							8f
 *
 *	Thus, it is likely to be moderately stable, even across
 *	operating system releases.
 */
#define DUMPMAG 0x8fca0101

E 10
I 8
/*
 *	this magic number is found in the kernel at label "doadump"
 *
 *	It is derived as follows:
 *
 *		doadump:	nop			01
 *				nop			01
 *				bicl2 $...		ca
 *							8f
 *
 *	Thus, it is likely to be moderately stable, even across
 *	operating system releases.
 */
#define DUMPMAG 0x8fca0101

E 12
E 8
I 7
char	*system;
E 7
D 4
char *dirname;				/* Directory to save dumps in */
char *ddname;				/* Name of dump device */
char *find_dev();
int minfree;				/* Minimum free blocks on device */
dev_t dumpdev;				/* Dump device */
time_t dumptime;			/* Time the dump was taken */
int dumplo;				/* Where dump starts on dumpdev */
int physmem;				/* Amount of memory in machine */
time_t now;				/* Current date */
char *path(), *malloc();
char vers[80], core_vers[80];
char panic_mesg[80];
int panicstr;
int do_the_dump = TRUE;
E 4
I 4
char	*dirname;			/* directory to save dumps in */
char	*ddname;			/* name of dump device */
char	*find_dev();
dev_t	dumpdev;			/* dump device */
time_t	dumptime;			/* time the dump was taken */
int	dumplo;				/* where dump starts on dumpdev */
D 12
int	physmem;			/* amount of memory in machine */
E 12
I 12
int	dumpsize;			/* amount of memory dumped */
int	dumpmag;			/* magic number in dump */
E 12
time_t	now;				/* current date */
char	*path();
D 21
unsigned malloc();
E 21
I 21
char	*malloc();
E 21
char	*ctime();
char	vers[80];
char	core_vers[80];
char	panic_mesg[80];
int	panicstr;
D 6
int	do_the_dump = 1;
E 6
off_t	lseek();
off_t	Lseek();
I 16
int	Verbose;
I 27
int	force;
I 29
int	clear;
E 29
E 27
I 25
extern	int errno;
E 25
E 16
E 4

main(argc, argv)
D 4
char **argv;
int argc;
E 4
I 4
	char **argv;
	int argc;
E 4
{
I 22
	char *cp;
E 22
D 4
	if (argc != 2)
	{
E 4
I 4

I 16
D 22
	while ((argc > 1) && (argv[1][0] == '-')) {
		switch (argv[1][1]) {
E 22
I 22
	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		for (cp = &argv[0][1]; *cp; cp++) switch (*cp) {

I 27
		case 'f':
			force++;
			break;

E 27
E 22
		case 'v':
I 17
D 22
		case 'd':
E 17
			Verbose = 1;
E 22
I 22
			Verbose++;
E 22
			break;
I 22

I 29
		case 'c':
			clear++;
			break;

E 29
E 22
		default:
D 22
			fprintf(stderr, "savecore: illegal flag -%c\n",
				argv[1][1]);
E 22
I 22
		usage:
E 22
			fprintf(stderr,
D 22
				"usage: savecore [-v] dirname [ system ]\n");
E 22
I 22
D 27
			    "usage: savecore [-v] dirname [ system ]\n");
E 27
I 27
			    "usage: savecore [-f] [-v] dirname [ system ]\n");
E 27
E 22
			exit(1);
		}
D 22
		argc--;
		argv++;
E 22
I 22
		argc--, argv++;
E 22
	}
D 22

E 16
D 7
	if (argc != 2) {
E 4
		fprintf(stderr, "usage: savecore dirname\n");
E 7
I 7
	if (argc != 2 && argc != 3) {
D 16
		fprintf(stderr, "usage: savecore dirname [ system ]\n");
E 16
I 16
		fprintf(stderr, "usage: savecore [-v] dirname [ system ]\n");
E 22
I 22
	if (argc != 1 && argc != 2)
		goto usage;
	dirname = argv[0];
	if (argc == 2)
		system = argv[1];
D 23
	openlog("savecore", LOG_ODELAY, LOG_USER);
E 23
I 23
	openlog("savecore", LOG_ODELAY, LOG_AUTH);
E 23
	if (access(dirname, W_OK) < 0) {
I 25
D 26
		int oerrno = errno;

		perror(dirname);
		errno = oerrno;
E 25
		syslog(LOG_ERR, "%s: %m", dirname);
E 26
I 26
		Perror(LOG_ERR, "%s: %m", dirname);
E 26
E 22
E 16
E 7
		exit(1);
	}
D 22
	dirname = argv[1];
I 7
	if (argc == 3)
		system = argv[2];
E 7
D 4
	if (access(dirname, 2) < 0)
	{
E 4
I 4
	if (access(dirname, 2) < 0) {
E 4
		perror(dirname);
D 4
		exit(4);
E 4
I 4
		exit(1);
E 4
	}
E 22
D 4
	/*
	 * Now invoke the local dieties so that things get done
	 */
	time(&now);
E 4
I 4
D 8
D 10
	(void) time(&now);
E 10
I 10
D 11

E 10
E 8
I 8

E 11
E 8
E 4
	read_kmem();
D 8
D 10
	log_entry();
D 6
	if (do_the_dump && get_crashtime() && check_space())
E 6
I 6
	if (get_crashtime() && check_space())
E 6
		save_core();
I 6
	else
		exit(1);
E 10
I 10
D 22
	if (dump_exists()) {
		(void) time(&now);
		check_kmem();
		log_entry();
		if (get_crashtime() && check_space()) {
			save_core();
			clear_dump();
D 16
		} else
E 16
I 16
		} else {
			if (Verbose)
				fprintf(stderr, "No space or time\n");
E 16
			exit(1);
I 16
		}
E 22
I 22
	if (!dump_exists()) {
		if (Verbose)
			fprintf(stderr, "savecore: No dump exists.\n");
		exit(0);
E 22
E 16
	}
I 29
	if (clear) {
		clear_dump();
		exit(0);
	}
E 29
I 16
D 22
	else if (Verbose) {
		fprintf(stderr, "No dump exists\n");
	}
E 16
	return 0;
E 22
I 22
	(void) time(&now);
	check_kmem();
D 24
	log_entry();
E 24
I 24
	if (panicstr)
D 29
		syslog(LOG_CRIT, "reboot after panic: %s", panic_mesg);
E 29
I 29
		syslog(LOG_CRIT, "reboot after panic: %s\n", panic_mesg);
E 29
	else
D 29
		syslog(LOG_CRIT, "reboot");
E 29
I 29
		syslog(LOG_CRIT, "reboot\n");
E 29
E 24
D 27
	if (!get_crashtime() || !check_space())
E 27
I 27
	if ((!get_crashtime() || !check_space()) && !force)
E 27
		exit(1);
	save_core();
	clear_dump();
	exit(0);
E 22
E 10
E 8
I 8
D 11
	if (dump_exists()) {
		(void) time(&now);
		check_kmem();
		log_entry();
		if (get_crashtime() && check_space()) {
			save_core();
			clear_dump();
		} else
			exit(1);
	}
	return 0;
E 11
E 8
E 6
}

I 10
D 22
int
E 22
dump_exists()
{
	register int dumpfd;
	int word;

D 22
	dumpfd = Open(ddname, 0);
D 12
	Lseek(dumpfd, (off_t)(dumplo + ok(nl[X_DOADUMP].n_value)), 0);
E 12
I 12
D 16
	Lseek(dumpfd, (off_t)(dumplo + ok(nl[X_DUMPMAG].n_value)), 0);
E 16
I 16
	Lseek(dumpfd, (off_t)(dumplo + ok(dump_nl[X_DUMPMAG].n_value)), 0);
E 16
E 12
	Read(dumpfd, (char *)&word, sizeof word);
E 22
I 22
	dumpfd = Open(ddname, O_RDONLY);
	Lseek(dumpfd, (off_t)(dumplo + ok(dump_nl[X_DUMPMAG].n_value)), L_SET);
	Read(dumpfd, (char *)&word, sizeof (word));
E 22
	close(dumpfd);
I 16
D 22
	if (Verbose && (word != dumpmag)) {
E 22
I 22
	if (Verbose && word != dumpmag) {
E 22
D 19
		printf("dumplo = %d (%d bytes)\n", dumplo/512, dumplo);
E 19
I 19
		printf("dumplo = %d (%d bytes)\n", dumplo/DEV_BSIZE, dumplo);
E 19
		printf("magic number mismatch: %x != %x\n", word, dumpmag);
	}
E 16
D 11
	
E 11
D 12
	return (word == DUMPMAG);
E 12
I 12
	return (word == dumpmag);
E 12
}

clear_dump()
{
	register int dumpfd;
	int zero = 0;

D 22
	dumpfd = Open(ddname, 1);
D 12
	Lseek(dumpfd, (off_t)(dumplo + ok(nl[X_DOADUMP].n_value)), 0);
E 12
I 12
D 16
	Lseek(dumpfd, (off_t)(dumplo + ok(nl[X_DUMPMAG].n_value)), 0);
E 16
I 16
	Lseek(dumpfd, (off_t)(dumplo + ok(dump_nl[X_DUMPMAG].n_value)), 0);
E 16
E 12
	Write(dumpfd, (char *)&zero, sizeof zero);
E 22
I 22
	dumpfd = Open(ddname, O_WRONLY);
	Lseek(dumpfd, (off_t)(dumplo + ok(dump_nl[X_DUMPMAG].n_value)), L_SET);
	Write(dumpfd, (char *)&zero, sizeof (zero));
E 22
	close(dumpfd);
}

E 10
I 8
D 11
int
dump_exists()
{
	register int dumpfd;
	int word;

	dumpfd = Open(ddname, 0);
	Lseek(dumpfd, (off_t)(dumplo + ok(nl[X_DOADUMP].n_value)), 0);
	Read(dumpfd, (char *)&word, sizeof word);
	close(dumpfd);
	
	return (word == DUMPMAG);
}

clear_dump()
{
	register int dumpfd;
	int zero = 0;

	dumpfd = Open(ddname, 1);
	Lseek(dumpfd, (off_t)(dumplo + ok(nl[X_DOADUMP].n_value)), 0);
	Write(dumpfd, (char *)&zero, sizeof zero);
	close(dumpfd);
}

E 11
E 8
D 4
/*
 * find_dev
 *	Lookup a dev in the /dev directory, return the dev name
 */

char *find_dev(dev, type)
register dev_t dev;
register int type;
E 4
I 4
char *
find_dev(dev, type)
	register dev_t dev;
	register int type;
E 4
{
D 8
D 10
	register int dfd = Open("/dev", 0);
	struct direct dir;
E 10
I 10
	register DIR *dfd = opendir("/dev");
	struct direct *dir;
E 10
E 8
I 8
D 11
	register DIR *dfd = opendir("/dev");
	struct direct *dir;
E 11
E 8
	struct stat statb;
D 8
D 10
	static char devname[DIRSIZ + 1];
E 10
I 10
	static char devname[MAXPATHLEN + 1];
E 10
E 8
I 8
D 11
	static char devname[MAXPATHLEN + 1];
E 11
E 8
I 3
	char *dp;
E 3

	strcpy(devname, "/dev/");
D 4
	while(Read(dfd, &dir, sizeof dir) > 0)
	{
E 4
I 4
D 8
D 10
	while(Read(dfd, (char *)&dir, sizeof dir) > 0) {
E 4
		if (dir.d_ino == 0)
			continue;
		strncpy(devname + 5, dir.d_name, DIRSIZ);
		devname[DIRSIZ] = '\0';
E 10
I 10
	while ((dir = readdir(dfd))) {
		strcpy(devname + 5, dir->d_name);
E 10
E 8
I 8
D 11
	while ((dir = readdir(dfd))) {
		strcpy(devname + 5, dir->d_name);
E 11
E 8
D 4
		if (stat(devname, &statb))
E 4
I 4
		if (stat(devname, &statb)) {
E 4
			perror(devname);
D 4
		else
		{
			if ((statb.st_mode&S_IFMT) != type)
				continue;
			if (dev == statb.st_rdev)
			{
				close(dfd);
D 3
				return devname;
E 3
I 3
				dp = malloc(strlen(devname)+1);
				strcpy(dp, devname);
				return dp;
E 3
			}
E 4
I 4
			continue;
E 4
		}
I 4
		if ((statb.st_mode&S_IFMT) != type)
			continue;
		if (dev == statb.st_rdev) {
D 8
D 10
			close(dfd);
E 10
I 10
			closedir(dfd);
E 10
E 8
I 8
D 11
			closedir(dfd);
E 11
E 8
D 21
			dp = (char *)malloc(strlen(devname)+1);
E 21
I 21
			dp = malloc(strlen(devname)+1);
E 21
			strcpy(dp, devname);
D 22
			return dp;
E 22
I 22
			return (dp);
E 22
		}
E 4
	}
D 8
D 10
	close(dfd);
E 10
I 10
	closedir(dfd);
I 25
D 26
	fprintf(stderr, "Can't find device %d/%d\n", major(dev), minor(dev));
E 25
E 10
E 8
I 8
D 11
	closedir(dfd);
E 11
E 8
D 12
	fprintf(stderr, "Can't find device %d,%d\n", major(dev), minor(dev));
E 12
I 12
D 22
	fprintf(stderr, "savecore: Can't find device %d,%d\n",
		major(dev), minor(dev));
E 22
I 22
	syslog(LOG_ERR, "Can't find device %d/%d\n", major(dev), minor(dev));
E 26
I 26
	log(LOG_ERR, "Can't find device %d/%d\n", major(dev), minor(dev));
E 26
E 22
E 12
D 4
	exit(7);
E 4
I 4
	exit(1);
	/*NOTREACHED*/
E 4
}

I 22
int	cursyms[] =
    { X_DUMPDEV, X_DUMPLO, X_VERSION, X_DUMPMAG, -1 };
int	dumpsyms[] =
    { X_TIME, X_DUMPSIZE, X_VERSION, X_PANICSTR, X_DUMPMAG, -1 };
E 22
D 4
/*
 * Open
 *	Open and exit if open fails
 */

Open(name, rw)
char *name;
int rw;
{
	int fd;

	if ((fd = open(name, rw)) < 0)
	{
		perror(name);
		exit(2);
	}
	return fd;
}

/*
 * Read, like read but checks bad return codes
 */

Read(fd, buff, size)
int fd, size;
char *buff;
{
	int ret;

	if ((ret = read(fd, buff, size)) < 0)
	{
		perror("reading");
		exit(3);
	}
	return ret;
}

/*
 * Lseek
 *	A "safe" lseek
 */

long Lseek(fd, off, flag)
int fd, flag;
long off;
{
	long ret;

	if ((ret = lseek(fd, off, flag)) == -1L)
	{
		perror("lseek");
		exit(5);
	}
	return ret;
}

Create(file, mode)
char *file;
int mode;
{
	register int fd;

	if ((fd = creat(file, mode)) < 0)
	{
		perror(file);
		exit(9);
	}
	return fd;
}

Write(fd, buf, size)
int fd, size;
char *buf;
{
	if (write(fd, buf, size) < size)
	{
		perror("Writing");
		exit(10);
	}
}

/*
 * Get dumpdev and dumplo from kmem/vmunix
 */

E 4
read_kmem()
{
D 22
	int kmem;
	FILE *fp;
E 22
	register char *cp;
I 22
	FILE *fp;
E 22
I 16
	char *dump_sys;
I 22
	int kmem, i;
E 22
	
	dump_sys = system ? system : "/vmunix";
E 16
D 22

E 22
D 16
	nlist("/vmunix", nl);
D 4
	if (nl[X_DUMPDEV].n_value == 0)
	{
	    fprintf(stderr, "savecore: dumpdev not in namelist\n");
	    exit(6);
E 4
I 4
	if (nl[X_DUMPDEV].n_value == 0) {
E 16
I 16
	nlist("/vmunix", current_nl);
	nlist(dump_sys, dump_nl);
D 22

E 22
	/*
	 * Some names we need for the currently running system,
	 * others for the system that was running when the dump was made.
	 * The values obtained from the current system are used
	 * to look for things in /dev/kmem that cannot be found
	 * in the dump_sys namelist, but are presumed to be the same
	 * (since the disk partitions are probably the same!)
	 */
D 22
	if (current_nl[X_DUMPDEV].n_value == 0) {
E 16
D 12
		fprintf(stderr, "/vmunix: dumpdev not in namelist\n");
E 12
I 12
		fprintf(stderr, "savecore: /vmunix: dumpdev not in namelist\n");
E 12
		exit(1);
E 4
	}
D 4
	if (nl[X_DUMPLO].n_value == 0)
	{
	    fprintf(stderr, "savecore: dumplo not in namelist\n");
	    exit(6);
E 4
I 4
D 16
	if (nl[X_DUMPLO].n_value == 0) {
E 16
I 16
	if (current_nl[X_DUMPLO].n_value == 0) {
E 16
D 12
		fprintf(stderr, "/vmunix: dumplo not in namelist\n");
E 12
I 12
		fprintf(stderr, "savecore: /vmunix: dumplo not in namelist\n");
E 12
		exit(1);
E 4
	}
D 4
	if (nl[X_TIME].n_value == 0)
	{
	    fprintf(stderr, "savecore: time not in namelist\n");
	    exit(6);
E 4
I 4
D 16
	if (nl[X_TIME].n_value == 0) {
D 12
		fprintf(stderr, "/vmunix: time not in namelist\n");
E 12
I 12
		fprintf(stderr, "savecore: /vmunix: time not in namelist\n");
E 16
I 16
	if (dump_nl[X_TIME].n_value == 0) {
		fprintf(stderr, "savecore: %s: time not in namelist\n",
				dump_sys);
E 16
E 12
		exit(1);
E 4
	}
D 4
	if (nl[X_PHYSMEM].n_value == 0)
	{
		fprintf("savecore: physmem not in namelist\n");
		exit(6);
E 4
I 4
D 12
	if (nl[X_PHYSMEM].n_value == 0) {
		fprintf(stderr, "/vmunix: physmem not in namelist\n");
E 12
I 12
D 16
	if (nl[X_DUMPSIZE].n_value == 0) {
		fprintf(stderr, "savecore: /vmunix: dumpsize not in namelist\n");
E 16
I 16
	if (dump_nl[X_DUMPSIZE].n_value == 0) {
		fprintf(stderr, "savecore: %s: dumpsize not in namelist\n",
				dump_sys);
E 16
E 12
		exit(1);
E 4
	}
D 4
	if (nl[X_VERSION].n_value == 0)
	{
		fprintf("savecore: version not in namelist\n");
		exit(6);
E 4
I 4
D 16
	if (nl[X_VERSION].n_value == 0) {
D 12
		fprintf(stderr, "/vmunix: version not in namelist\n");
E 12
I 12
		fprintf(stderr, "savecore: /vmunix: version not in namelist\n");
E 16
I 16
	/* we need VERSION in both images */
	if (current_nl[X_VERSION].n_value == 0) {
		fprintf(stderr, "savecore: /vmunix: version not in namelist\n",
				dump_sys);
E 16
E 12
		exit(1);
E 4
	}
D 4
	if (nl[X_PANICSTR].n_value == 0)
	{
		fprintf("savecore: panicstr not in namelist\n");
		exit(6);
E 4
I 4
D 16
	if (nl[X_PANICSTR].n_value == 0) {
D 12
		fprintf(stderr, "/vmunix: panicstr not in namelist\n");
E 12
I 12
		fprintf(stderr, "savecore: /vmunix: panicstr not in namelist\n");
E 16
I 16
	if (dump_nl[X_VERSION].n_value == 0) {
		fprintf(stderr, "savecore: %s: version not in namelist\n",
				dump_sys);
E 16
E 12
		exit(1);
E 4
	}
I 10
D 12
	if (nl[X_DOADUMP].n_value == 0) {
		fprintf(stderr, "/vmunix: doadump not in namelist\n");
E 12
I 12
D 16
	if (nl[X_DUMPMAG].n_value == 0) {
E 16
I 16
	if (dump_nl[X_PANICSTR].n_value == 0) {
		fprintf(stderr, "savecore: %s: panicstr not in namelist\n",
				dump_sys);
		exit(1);
	}
	/* we need DUMPMAG in both images */
	if (current_nl[X_DUMPMAG].n_value == 0) {
E 16
		fprintf(stderr, "savecore: /vmunix: dumpmag not in namelist\n");
E 12
		exit(1);
	}
I 16
	if (dump_nl[X_DUMPMAG].n_value == 0) {
		fprintf(stderr, "savecore: %s: dumpmag not in namelist\n",
				dump_sys);
		exit(1);
	}
E 16
E 10
I 8
D 12
	if (nl[X_DOADUMP].n_value == 0) {
		fprintf(stderr, "/vmunix: doadump not in namelist\n");
		exit(1);
	}
E 12
E 8
	kmem = Open("/dev/kmem", 0);
D 4
	Lseek(kmem, nl[X_DUMPDEV].n_value, 0);
	Read(kmem, &dumpdev, sizeof dumpdev);
	Lseek(kmem, nl[X_DUMPLO].n_value, 0);
	Read(kmem, &dumplo, sizeof dumplo);
	Lseek(kmem, nl[X_PHYSMEM].n_value, 0);
	Read(kmem, &physmem, sizeof physmem);
	Lseek(kmem, nl[X_PANICSTR].n_value, 0);
	Read(kmem, &panicstr, sizeof panicstr);
E 4
I 4
D 16
	Lseek(kmem, (long)nl[X_DUMPDEV].n_value, 0);
E 16
I 16
	Lseek(kmem, (long)current_nl[X_DUMPDEV].n_value, 0);
E 22
I 22
	for (i = 0; cursyms[i] != -1; i++)
		if (current_nl[cursyms[i]].n_value == 0) {
I 25
D 26
			fprintf(stderr, "/vmunix: %s not in namelist",
E 26
I 26
D 29
			log(LOG_ERR, "/vmunix: %s not in namelist",
E 29
I 29
			log(LOG_ERR, "/vmunix: %s not in namelist\n",
E 29
E 26
			    current_nl[cursyms[i]].n_name);
E 25
D 26
			syslog(LOG_ERR, "/vmunix: %s not in namelist",
			    current_nl[cursyms[i]].n_name);
E 26
			exit(1);
		}
	for (i = 0; dumpsyms[i] != -1; i++)
		if (dump_nl[dumpsyms[i]].n_value == 0) {
I 25
D 26
			fprintf(stderr, "%s: %s not in namelist", dump_sys,
E 26
I 26
D 29
			log(LOG_ERR, "%s: %s not in namelist", dump_sys,
E 29
I 29
			log(LOG_ERR, "%s: %s not in namelist\n", dump_sys,
E 29
E 26
			    dump_nl[dumpsyms[i]].n_name);
E 25
D 26
			syslog(LOG_ERR, "%s: %s not in namelist", dump_sys,
			    dump_nl[dumpsyms[i]].n_name);
E 26
			exit(1);
		}
	kmem = Open("/dev/kmem", O_RDONLY);
	Lseek(kmem, (long)current_nl[X_DUMPDEV].n_value, L_SET);
E 22
E 16
D 12
	Read(kmem, (char *)&dumpdev, sizeof dumpdev);
E 12
I 12
	Read(kmem, (char *)&dumpdev, sizeof (dumpdev));
E 12
D 16
	Lseek(kmem, (long)nl[X_DUMPLO].n_value, 0);
E 16
I 16
D 22
	Lseek(kmem, (long)current_nl[X_DUMPLO].n_value, 0);
E 22
I 22
	Lseek(kmem, (long)current_nl[X_DUMPLO].n_value, L_SET);
E 22
E 16
D 12
	Read(kmem, (char *)&dumplo, sizeof dumplo);
	Lseek(kmem, (long)nl[X_PHYSMEM].n_value, 0);
	Read(kmem, (char *)&physmem, sizeof physmem);
E 12
I 12
	Read(kmem, (char *)&dumplo, sizeof (dumplo));
D 13
	Lseek(kmem, (long)nl[X_DUMPSIZE].n_value, 0);
	Read(kmem, (char *)&dumpsize, sizeof (dumpsize));
E 13
D 16
	Lseek(kmem, (long)nl[X_DUMPMAG].n_value, 0);
E 16
I 16
D 22
	Lseek(kmem, (long)current_nl[X_DUMPMAG].n_value, 0);
E 22
I 22
	Lseek(kmem, (long)current_nl[X_DUMPMAG].n_value, L_SET);
E 22
E 16
	Read(kmem, (char *)&dumpmag, sizeof (dumpmag));
E 12
E 4
D 19
	dumplo *= 512L;
E 19
I 19
	dumplo *= DEV_BSIZE;
E 19
	ddname = find_dev(dumpdev, S_IFBLK);
D 4
	/*
	 * Check for version mismatch
	 */
	if ((fp = fdopen(kmem, "r")) == NULL)
	{
E 4
I 4
D 22
	if ((fp = fdopen(kmem, "r")) == NULL) {
E 4
D 12
		fprintf(stderr, "Couldn't fdopen kmem\n");
E 12
I 12
		fprintf(stderr, "savecore: Couldn't fdopen kmem\n");
E 22
I 22
	fp = fdopen(kmem, "r");
	if (fp == NULL) {
D 26
		syslog(LOG_ERR, "Couldn't fdopen kmem");
E 26
I 26
D 29
		log(LOG_ERR, "Couldn't fdopen kmem");
E 29
I 29
		log(LOG_ERR, "Couldn't fdopen kmem\n");
E 29
E 26
E 22
E 12
D 4
		exit(11);
E 4
I 4
		exit(1);
E 4
	}
I 7
	if (system)
		return;
E 7
D 4
	fseek(fp, nl[X_VERSION].n_value, 0);
E 4
I 4
D 16
	fseek(fp, (long)nl[X_VERSION].n_value, 0);
E 16
I 16
D 22
	fseek(fp, (long)current_nl[X_VERSION].n_value, 0);
E 16
E 4
	fgets(vers, sizeof vers, fp);
E 22
I 22
	fseek(fp, (long)current_nl[X_VERSION].n_value, L_SET);
	fgets(vers, sizeof (vers), fp);
E 22
	fclose(fp);
I 10
}

D 13
check_kmem() {
E 13
I 13
check_kmem()
{
E 13
	FILE *fp;
	register char *cp;

E 10
I 8
D 11
}

check_kmem() {
	FILE *fp;
	register char *cp;

E 11
E 8
D 4
	if ((fp = fopen(ddname, "r")) == NULL)
	{
E 4
I 4
D 22
	if ((fp = fopen(ddname, "r")) == NULL) {
E 4
		perror(ddname);
E 22
I 22
	fp = fopen(ddname, "r");
	if (fp == NULL) {
I 25
D 26
		int oerrno = errno;

		perror(ddname);
		errno = oerrno;
E 25
		syslog(LOG_ERR, "%s: %m", ddname);
E 26
I 26
		Perror(LOG_ERR, "%s: %m", ddname);
E 26
E 22
D 4
		exit(12);
E 4
I 4
		exit(1);
E 4
	}
D 4
	fseek(fp, dumplo+ok(nl[X_VERSION].n_value), 0);
E 4
I 4
D 16
	fseek(fp, (off_t)(dumplo+ok(nl[X_VERSION].n_value)), 0);
E 16
I 16
D 22
	fseek(fp, (off_t)(dumplo+ok(dump_nl[X_VERSION].n_value)), 0);
E 16
E 4
	fgets(core_vers, sizeof core_vers, fp);
E 22
I 22
	fseek(fp, (off_t)(dumplo+ok(dump_nl[X_VERSION].n_value)), L_SET);
	fgets(core_vers, sizeof (core_vers), fp);
E 22
	fclose(fp);
D 4
	if (!eq(vers, core_vers))
	{
		fprintf(stderr, "Version mismatch:\n\t%sand\n\t%s",
				vers,core_vers);
		fprintf(stderr, "Core not saved\n");
		do_the_dump = FALSE;
E 4
I 4
D 5
	if (!eq(vers, core_vers)) {
		fprintf(stderr, "Vmunix version mismatch:\n\t%sand\n\t%s",
E 5
I 5
D 16
	if (!eq(vers, core_vers))
E 16
I 16
D 22
	if (!eq(vers, core_vers) && (system == 0))
E 22
I 22
D 29
	if (!eq(vers, core_vers) && system == 0)
E 22
E 16
D 12
		fprintf(stderr, "Warning: vmunix version mismatch:\n\t%sand\n\t%s",
E 5
		    vers,core_vers);
E 12
I 12
D 26
		fprintf(stderr,
E 26
I 26
		log(LOG_WARNING,
E 26
D 22
		   "savecore: Warning: vmunix version mismatch:\n\t%sand\n\t%s",
E 22
I 22
		   "Warning: vmunix version mismatch:\n\t%sand\n\t%s",
E 22
		   vers, core_vers);
E 29
I 29
	if (!eq(vers, core_vers) && system == 0) {
		log(LOG_WARNING, "Warning: vmunix version mismatch:\n");
		log(LOG_WARNING, "\t%s\n", vers);
		log(LOG_WARNING, "and\t%s\n", core_vers);
	}
E 29
I 25
D 26
		syslog(LOG_WARNING,
		   "Warning: vmunix version mismatch: %s and %s",
		   vers, core_vers);
E 26
E 25
E 12
D 5
		fprintf(stderr, "; image not saved\n");
		do_the_dump = 0;
E 4
		return;
	}
E 5
D 4
	/*
	 * Now check the panic string
	 */
	if (panicstr)
	{
		fp = fopen(ddname, "r");
		fseek(fp, dumplo + ok(panicstr));
E 4
I 4
	fp = fopen(ddname, "r");
D 16
	fseek(fp, (off_t)(dumplo + ok(nl[X_PANICSTR].n_value)), 0);
E 16
I 16
D 22
	fseek(fp, (off_t)(dumplo + ok(dump_nl[X_PANICSTR].n_value)), 0);
E 16
	fread((char *)&panicstr, sizeof panicstr, 1, fp);
E 22
I 22
	fseek(fp, (off_t)(dumplo + ok(dump_nl[X_PANICSTR].n_value)), L_SET);
	fread((char *)&panicstr, sizeof (panicstr), 1, fp);
E 22
	if (panicstr) {
D 22
		fseek(fp, dumplo + ok(panicstr), 0);
E 22
I 22
		fseek(fp, dumplo + ok(panicstr), L_SET);
E 22
E 4
		cp = panic_mesg;
		do
			*cp = getc(fp);
		while (*cp++);
D 4
		fclose(fp);
E 4
	}
I 4
	fclose(fp);
E 4
D 7
}	
E 7
I 7
}
E 7

D 4
/*
 * Now get the time of the crash
 */

 get_crashtime()
 {
E 4
I 4
get_crashtime()
{
E 4
	int dumpfd;
I 2
	time_t clobber = (time_t)0;
E 2

I 7
D 17
	if (system)
		return (1);
E 17
E 7
D 2
	dumpfd = Open(ddname, 0);
E 2
I 2
D 8
D 10
	dumpfd = Open(ddname, 2);
E 10
I 10
D 22
	dumpfd = Open(ddname, 0);
E 10
E 8
I 8
D 11
	dumpfd = Open(ddname, 0);
E 11
E 8
E 2
D 4
	Lseek(dumpfd, dumplo + ok(nl[X_TIME].n_value), 0);
	Read(dumpfd, &dumptime, sizeof dumptime);
I 2
	Lseek(dumpfd, dumplo + ok(nl[X_TIME].n_value), 0);
	Write(dumpfd, &clobber, sizeof clobber);
E 4
I 4
D 16
	Lseek(dumpfd, (off_t)(dumplo + ok(nl[X_TIME].n_value)), 0);
E 16
I 16
	Lseek(dumpfd, (off_t)(dumplo + ok(dump_nl[X_TIME].n_value)), 0);
E 22
I 22
	dumpfd = Open(ddname, O_RDONLY);
	Lseek(dumpfd, (off_t)(dumplo + ok(dump_nl[X_TIME].n_value)), L_SET);
E 22
E 16
	Read(dumpfd, (char *)&dumptime, sizeof dumptime);
D 8
D 10
	Lseek(dumpfd, (off_t)(dumplo + ok(nl[X_TIME].n_value)), 0);
	Write(dumpfd, (char *)&clobber, sizeof clobber);
E 10
E 8
E 4
E 2
	close(dumpfd);
I 3
D 6
	if (dumptime == 0)
E 6
I 6
D 12
	if (dumptime == 0) {
#ifdef DEBUG
		printf("dump time is 0\n");
#endif
E 6
D 4
		return FALSE;
E 4
I 4
		return 0;
I 6
	}
E 12
I 12
D 16
	if (dumptime == 0)
E 16
I 16
	if (dumptime == 0) {
		if (Verbose)
D 22
			printf("dump time not found\n");
E 22
I 22
D 27
			printf("Dump time not found.\n");
E 27
I 27
			printf("Dump time is zero.\n");
E 27
E 22
E 16
		return (0);
I 16
	}
E 16
E 12
E 6
E 4
E 3
	printf("System went down at %s", ctime(&dumptime));
	if (dumptime < now - LEEWAY || dumptime > now + LEEWAY) {
D 22
		printf("Dump time is unreasonable\n");
E 22
I 22
		printf("dump time is unreasonable\n");
E 22
D 4
		return FALSE;
	} else {
D 3
		printf("Dump time ok.\n");
E 3
		return TRUE;
E 4
I 4
D 12
		return 0;
E 12
I 12
		return (0);
E 12
E 4
	}
I 4
D 12
	return 1;
E 12
I 12
	return (1);
E 12
E 4
}

D 4
/*
 * Put a file name in the proper perspective
 */

char *path(file)
E 4
I 4
char *
path(file)
	char *file;
E 4
{
D 4
	register char *cp = malloc(strlen(file) + strlen(dirname) + 2);
E 4
I 4
D 21
	register char *cp = (char *)malloc(strlen(file) + strlen(dirname) + 2);
E 21
I 21
	register char *cp = malloc(strlen(file) + strlen(dirname) + 2);
E 21
E 4

D 4
	strcpy(cp, dirname);
	strcat(cp, "/");
	strcat(cp, file);
E 4
I 4
	(void) strcpy(cp, dirname);
	(void) strcat(cp, "/");
	(void) strcat(cp, file);
E 4
D 12
	return cp;
E 12
I 12
	return (cp);
E 12
}

D 4
/*
 * Check to make certain that there is enough space for this dump
 */

E 4
check_space()
{
	struct stat dsb;
	register char *ddev;
D 8
	register int dfd;
D 10
	struct filsys sblk;
E 10
I 10
D 11
	struct fs sblk;
E 11
E 10
E 8
I 8
D 14
	int dfd, freespace;
E 14
I 14
	int dfd, spacefree;
E 14
	struct fs fs;
E 8

D 4
	/*
	 * First find the number of free blocks
	 */
	stat(dirname, &dsb);
E 4
I 4
	if (stat(dirname, &dsb) < 0) {
I 25
D 26
		int oerrno = errno;

		perror(dirname);
		errno = oerrno;
E 25
D 22
		perror(dirname);
E 22
I 22
		syslog(LOG_ERR, "%s: %m", dirname);
E 26
I 26
		Perror(LOG_ERR, "%s: %m", dirname);
E 26
E 22
		exit(1);
	}
E 4
	ddev = find_dev(dsb.st_dev, S_IFBLK);
D 22
	dfd = Open(ddev, 0);
D 8
D 10
	Lseek(dfd, 1L<<BSHIFT, 0);
E 10
I 10
D 11
	Lseek(dfd, SBLOCK*MAXBSIZE, 0);
E 11
E 10
D 4
	Read(dfd, &sblk, sizeof sblk);
E 4
I 4
	Read(dfd, (char *)&sblk, sizeof sblk);
E 8
I 8
	Lseek(dfd, (long)(SBLOCK * DEV_BSIZE), 0);
	Read(dfd, (char *)&fs, sizeof fs);
E 22
I 22
	dfd = Open(ddev, O_RDONLY);
D 28
	Lseek(dfd, (long)(SBLOCK * DEV_BSIZE), L_SET);
E 28
I 28
	Lseek(dfd, SBOFF, L_SET);
E 28
	Read(dfd, (char *)&fs, sizeof (fs));
E 22
E 8
E 4
	close(dfd);
D 4
	/*
	 * Now check against maximum allowed
	 */
	if (read_number("minfree") > sblk.s_tfree)
	{
		fprintf(stderr, "*** Dump not done, not enough space ***\n");
		return FALSE;
E 4
I 4
D 8
D 10
	if (read_number("minfree") > sblk.s_tfree) {
E 10
I 10
D 11
	if (read_number("minfree") > sblk.fs_cstotal.cs_nbfree) {
E 10
E 8
I 8
	/*
	 * Minimum free space is in terms of kilobytes.
	 * We ignore the "percent free space to be maintained"
	 * parameter in the super block in the believe that a
	 * crash dump is more important than the (temporary)
	 * degradation in performance one might experience.
	 */
	freespace = (fs.fs_cstotal.cs_nbfree * fs.fs_bsize +
			fs.fs_cstotal.cs_nffree * fs.fs_fsize) / 1024;
E 11
I 11
D 14
	freespace = fs.fs_cstotal.cs_nbfree * fs.fs_bsize / 1024;
E 11
	if (read_number("minfree") > freespace) {
E 14
I 14
D 20
	spacefree = fs.fs_cstotal.cs_nbfree * fs.fs_bsize / 1024;
	if (read_number("minfree") > spacefree) {
E 20
I 20
D 22
	spacefree = freespace(&fs, fs.fs_minfree) * fs.fs_fsize / 1024;
	if (spacefree < read_number("minfree")) {
E 20
E 14
E 8
D 12
		fprintf(stderr, "Dump omitted, not enough space on device\n");
E 12
I 12
		fprintf(stderr,
		   "savecore: Dump omitted, not enough space on device\n");
E 22
I 22
 	spacefree = freespace(&fs, fs.fs_minfree) * fs.fs_fsize / 1024;
 	if (spacefree < read_number("minfree")) {
I 25
D 26
		printf("Dump omitted, not enough space on device");
E 25
		syslog(LOG_WARNING, "Dump omitted, not enough space on device");
E 26
I 26
D 29
		log(LOG_WARNING, "Dump omitted, not enough space on device");
E 29
I 29
		log(LOG_WARNING, "Dump omitted, not enough space on device\n");
E 29
E 26
E 22
E 12
		return (0);
E 4
	}
I 8
D 20
	if (fs.fs_cstotal.cs_nbfree * fs.fs_frag + fs.fs_cstotal.cs_nffree <
	    fs.fs_dsize * fs.fs_minfree / 100)
E 20
I 20
D 25
	if (freespace(&fs, fs.fs_minfree) < 0)
E 25
I 25
D 26
	if (freespace(&fs, fs.fs_minfree) < 0) {
		printf("Dump performed, but free space threshold crossed");
E 25
E 20
D 22
		fprintf(stderr,
			"Dump performed, but free space threshold crossed\n");
E 22
I 22
		syslog(LOG_WARNING,
E 26
I 26
	if (freespace(&fs, fs.fs_minfree) < 0)
		log(LOG_WARNING,
E 26
D 29
		    "Dump performed, but free space threshold crossed");
E 29
I 29
		    "Dump performed, but free space threshold crossed\n");
E 29
I 25
D 26
	}
E 26
E 25
E 22
E 8
D 4
	else
		return TRUE;
E 4
I 4
	return (1);
E 4
}

D 4
/*
 * Read a number from a file
 */

E 4
read_number(fn)
D 4
char *fn;
E 4
I 4
	char *fn;
E 4
{
	char lin[80];
	register FILE *fp;

D 22
	if ((fp = fopen(path(fn), "r")) == NULL)
E 22
I 22
	fp = fopen(path(fn), "r");
	if (fp == NULL)
E 22
D 12
		return 0;
E 12
I 12
		return (0);
E 12
D 4
	else
	{
		if (fgets(lin, 80, fp) == NULL)
		{
			fclose(fp);
			return 0;
		}
		else
		{
			fclose(fp);
			return atoi(lin);
		}
E 4
I 4
	if (fgets(lin, 80, fp) == NULL) {
		fclose(fp);
D 12
		return 0;
E 12
I 12
		return (0);
E 12
E 4
	}
I 4
	fclose(fp);
D 12
	return atoi(lin);
E 12
I 12
	return (atoi(lin));
E 12
E 4
}

I 21
#define	BUFPAGES	(256*1024/NBPG)		/* 1/4 Mb */

E 21
save_core()
{
	register int n;
D 4
	char buffer[BUFSIZ];
E 4
I 4
D 21
	char buffer[32*NBPG];
E 4
	register char *cp = buffer;
E 21
I 21
	register char *cp;
E 21
	register int ifd, ofd, bounds;
	register FILE *fp;

I 21
	cp = malloc(BUFPAGES*NBPG);
D 22
	if (cp == NULL) {
		fprintf(stderr, "can't malloc buffer\n");
E 22
I 22
	if (cp == 0) {
		fprintf(stderr, "savecore: Can't allocate i/o buffer.\n");
E 22
		return;
	}
E 21
	bounds = read_number("bounds");
D 4
	/*
	 * Copy the vmunix file
	 */
E 4
D 7
	ifd = Open("/vmunix", 0);
E 7
I 7
D 22
	ifd = Open(system?system:"/vmunix", 0);
E 22
I 22
	ifd = Open(system?system:"/vmunix", O_RDONLY);
E 22
E 7
D 8
D 10
	ofd = Create(path(sprintf(cp, "vmunix.%d", bounds)), 0666);
E 10
I 10
D 30
	sprintf(cp, "vmunix.%d", bounds);
E 30
I 30
	(void)sprintf(cp, "vmunix.%d", bounds);
E 30
	ofd = Create(path(cp), 0644);
E 10
E 8
I 8
D 11
	sprintf(cp, "vmunix.%d", bounds);
	ofd = Create(path(cp), 0644);
E 11
E 8
	while((n = Read(ifd, cp, BUFSIZ)) > 0)
		Write(ofd, cp, n);
	close(ifd);
	close(ofd);
D 4
	/*
	 * Make the core file
	 */
E 4
D 22
	ifd = Open(ddname, 0);
I 13
D 16
	Lseek(ifd, (off_t)(dumplo + ok(nl[X_DUMPSIZE].n_value)), 0);
E 16
I 16
	Lseek(ifd, (off_t)(dumplo + ok(dump_nl[X_DUMPSIZE].n_value)), 0);
E 22
I 22
	ifd = Open(ddname, O_RDONLY);
	Lseek(ifd, (off_t)(dumplo + ok(dump_nl[X_DUMPSIZE].n_value)), L_SET);
E 22
E 16
	Read(ifd, (char *)&dumpsize, sizeof (dumpsize));
E 13
D 8
D 10
	ofd = Create(path(sprintf(cp, "vmcore.%d", bounds)), 0666);
E 10
I 10
D 11
	sprintf(cp, "vmcore.%d", bounds);
	ofd = Create(path(cp), 0644);
E 11
E 10
E 8
I 8
D 30
	sprintf(cp, "vmcore.%d", bounds);
E 30
I 30
	(void)sprintf(cp, "vmcore.%d", bounds);
E 30
	ofd = Create(path(cp), 0644);
E 8
D 4
	Lseek(ifd, dumplo, 0);
D 3
	printf("Vmcore should be %d bytes long\n", NBPG * physmem);
E 3
I 3
	printf("Saving %d bytes of image in vmcore.%d\n",
	    NBPG * physmem, bounds);
E 3
	while(physmem > 0)
	{
		n = Read(ifd, cp, BUFSIZ);
E 4
I 4
D 22
	Lseek(ifd, (off_t)dumplo, 0);
E 22
I 22
	Lseek(ifd, (off_t)dumplo, L_SET);
E 22
D 12
	printf("Saving %d bytes of image in vmcore.%d\n", NBPG*physmem, bounds);
	while(physmem > 0) {
		n = Read(ifd, cp, (physmem > 32 ? 32 : physmem) * NBPG);
E 12
I 12
D 26
	printf("Saving %d bytes of image in vmcore.%d\n", NBPG*dumpsize,
		bounds);
I 25
	syslog(LOG_NOTICE, "Saving %d bytes of image in vmcore.%d\n",
		NBPG*dumpsize, bounds);
E 26
I 26
	log(LOG_NOTICE, "Saving %d bytes of image in vmcore.%d\n",
	    NBPG*dumpsize, bounds);
E 26
E 25
	while (dumpsize > 0) {
D 21
		n = Read(ifd, cp, (dumpsize > 32 ? 32 : dumpsize) * NBPG);
E 21
I 21
		n = Read(ifd, cp,
D 22
			(dumpsize > BUFPAGES ? BUFPAGES : dumpsize) * NBPG);
E 22
I 22
		    (dumpsize > BUFPAGES ? BUFPAGES : dumpsize) * NBPG);
E 22
E 21
I 19
		if (n == 0) {
D 25
			printf("WARNING: core may be incomplete\n");
E 25
I 25
D 26
			syslog(LOG_WARNING,
			    "WARNING: vmcore may be incomplete\n");
			printf("WARNING: vmcore may be incomplete\n");
E 26
I 26
D 29
			log(LOG_WARNING, "WARNING: vmcore may be incomplete");
E 29
I 29
			log(LOG_WARNING, "WARNING: vmcore may be incomplete\n");
E 29
E 26
E 25
			break;
		}
E 19
E 12
E 4
		Write(ofd, cp, n);
D 12
		physmem -= n/NBPG;
E 12
I 12
		dumpsize -= n/NBPG;
E 12
	}
	close(ifd);
	close(ofd);
	fp = fopen(path("bounds"), "w");
	fprintf(fp, "%d\n", bounds+1);
	fclose(fp);
I 21
	free(cp);
E 21
D 24
}

D 22
char *days[] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

E 22
I 22
char *days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
E 22
char *months[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
	"Oct", "Nov", "Dec"
};

log_entry()
{
	FILE *fp;
	struct tm *tm, *localtime();

D 22
	tm = localtime(&now);
E 22
D 4
	fp = fopen(SHUTDOWNLOG, "a");
E 4
I 4
	fp = fopen("/usr/adm/shutdownlog", "a");
	if (fp == 0)
		return;
E 4
D 22
	fseek(fp, 0L, 2);
E 22
I 22
	tm = localtime(&now);
	fseek(fp, 0L, L_XTND);
E 22
	fprintf(fp, "%02d:%02d  %s %s %2d, %4d.  Reboot", tm->tm_hour,
		tm->tm_min, days[tm->tm_wday], months[tm->tm_mon],
		tm->tm_mday, tm->tm_year + 1900);
	if (panicstr)
D 4
		fprintf(fp, " -- panic %s\n", panic_mesg);
E 4
I 4
		fprintf(fp, " after panic: %s\n", panic_mesg);
E 4
	else
		putc('\n', fp);
	fclose(fp);
E 24
I 4
}

/*
 * Versions of std routines that exit on error.
 */
D 22

E 22
Open(name, rw)
	char *name;
	int rw;
{
	int fd;

D 22
	if ((fd = open(name, rw)) < 0) {
		perror(name);
E 22
I 22
	fd = open(name, rw);
	if (fd < 0) {
I 25
D 26
		int oerrno = errno;

		perror(name);
		errno = oerrno;
E 25
		syslog(LOG_ERR, "%s: %m", name);
E 26
I 26
		Perror(LOG_ERR, "%s: %m", name);
E 26
E 22
		exit(1);
	}
D 22
	return fd;
E 22
I 22
	return (fd);
E 22
}

Read(fd, buff, size)
	int fd, size;
	char *buff;
{
	int ret;

D 22
	if ((ret = read(fd, buff, size)) < 0) {
		perror("read");
E 22
I 22
	ret = read(fd, buff, size);
	if (ret < 0) {
I 25
D 26
		int oerrno = errno;

		perror("read");
		errno = oerrno;
E 25
		syslog(LOG_ERR, "read: %m");
E 26
I 26
		Perror(LOG_ERR, "read: %m");
E 26
E 22
		exit(1);
	}
D 22
	return ret;
E 22
I 22
	return (ret);
E 22
}

off_t
Lseek(fd, off, flag)
	int fd, flag;
	long off;
{
	long ret;

D 22
	if ((ret = lseek(fd, off, flag)) == -1L) {
		perror("lseek");
E 22
I 22
	ret = lseek(fd, off, flag);
	if (ret == -1) {
I 25
D 26
		int oerrno = errno;

		perror("lseek");
		errno = oerrno;
E 25
		syslog(LOG_ERR, "lseek: %m");
E 26
I 26
		Perror(LOG_ERR, "lseek: %m");
E 26
E 22
		exit(1);
	}
D 22
	return ret;
E 22
I 22
	return (ret);
E 22
}

Create(file, mode)
	char *file;
	int mode;
{
	register int fd;

D 22
	if ((fd = creat(file, mode)) < 0) {
		perror(file);
E 22
I 22
	fd = creat(file, mode);
	if (fd < 0) {
I 25
D 26
		int oerrno = errno;

		perror(file);
		errno = oerrno;
E 25
		syslog(LOG_ERR, "%s: %m", file);
E 26
I 26
		Perror(LOG_ERR, "%s: %m", file);
E 26
E 22
		exit(1);
	}
D 22
	return fd;
E 22
I 22
	return (fd);
E 22
}

Write(fd, buf, size)
	int fd, size;
	char *buf;
D 13

E 13
{

	if (write(fd, buf, size) < size) {
I 25
D 26
		int oerrno = errno;

		perror("write");
		errno = oerrno;
E 25
D 22
		perror("write");
E 22
I 22
		syslog(LOG_ERR, "write: %m");
E 26
I 26
		Perror(LOG_ERR, "write: %m");
E 26
E 22
		exit(1);
	}
I 26
}

log(level, msg, a1, a2)
	int level;
	char *msg;
{

	fprintf(stderr, msg, a1, a2);
	syslog(level, msg, a1, a2);
}

Perror(level, msg, s)
	int level;
	char *msg;
{
	int oerrno = errno;
	
	perror(s);
	errno = oerrno;
	syslog(level, msg, s);
E 26
E 4
}
I 10
D 12


E 10
I 8


E 12
E 8
E 1
