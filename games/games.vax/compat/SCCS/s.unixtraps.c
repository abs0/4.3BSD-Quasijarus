h07790
s 00178/00014/00657
d D 4.3 84/05/05 21:51:11 mckusick 4 3
c fixes from Lou Salkind at NYU
e
s 00301/00100/00370
d D 4.2 83/07/31 23:02:44 sam 3 2
c update to run under 4.2bsd; reformat to my style (or a reasonable 
c facimile thereof); major hacking on signal handling for 4.2 signal interface
e
s 00000/00000/00470
d D 4.1 82/05/12 11:14:31 rrh 2 1
c sync to release 4.1
e
s 00470/00000/00000
d D 1.1 82/05/12 11:03:43 rrh 1 0
c date and time created 82/05/12 11:03:43 by rrh
e
u
U
t
T
I 4
#ifndef	lint
E 4
I 1
D 3
#
static char sccsid[] = "	%M%	%I%	%E%	";
/*	Function to execute version 6 and version 7 UNIX system calls from
 *	compatability mode on UNIX-32V.
E 3
I 3
static char sccsid[] = "%W% %E%";
I 4
#endif
E 4

I 4
/* From Lou Salkind: compat/RCS/unixtraps.c,v 1.2 84/01/31 13:34:34 */

E 4
/*
 * Function to execute version 6 and version 7 UNIX system calls from
 * compatability mode on UNIX-32V.
E 3
 *	Art Wetzel	August 1979
 */
I 3

E 3
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
I 3
#include <sys/ioctl.h>
#include <sys/time.h>
I 4
#include <sys/dir.h>
E 4
E 3
#ifdef V6UNIX
#ifdef TRACE
#define	RTSNAME	"/../../../../usr/local/v6trc"
#else
#define	RTSNAME	"/../../../../usr/local/v6run"
#endif
#include "unix6sys.h"
#ifdef TRACE
#include "unix6sysn.h"
#endif
#endif
#ifdef V7UNIX
#ifdef TRACE
#define	RTSNAME	"/../../../../usr/local/v7trc"
#else
#define	RTSNAME	"/../../../../usr/local/v7run"
#endif
#include "unix7sys.h"
#ifdef TRACE
#include "unix7sysn.h"
#endif
#endif
#include "defs.h"
#define	CARRY	1
D 4
#define	MAXSARGS	25
E 4
I 4
#define	MAXSARGS	100
E 4
#ifdef V6UNIX
#define	ARGVLEN	512
#define	ENVLEN	0
#endif
#ifdef V7UNIX
#define	ARGVLEN	5120
#define	ENVLEN	1000
#endif
char	argvs[ARGVLEN+ENVLEN];
int	args[MAXSARGS];
I 3

E 3
/* 32v type stat structure */
extern struct	stat	stat32v;
I 3

E 3
/* place for times data so we can reverse the longs */
struct timebuf {
	long	t1;
	long	t2;
	long	t3;
	long	t4;
} timebuf;
I 3

E 3
/* place for pipe file descriptors */
int	pipes[2];
I 3

E 3
/* wait status */
int	wstatus;
I 3

E 3
#ifdef	V6UNIX
/* version 6 style stat structure */
struct v6nod {
	dev_t	majmin;
	ino_t	inumber;
	unsigned short	flags;
	unsigned char	nlinks;
	unsigned char	uid;
	unsigned char	gid;
	unsigned char	size0;
	unsigned short	size1;
	unsigned short	addr[8];
	long	actime;
	long	modtime;
} *v6stat;
#endif
I 3

#ifdef	V7UNIX
/* version 7 style stat structure */
struct	v7stat {
	dev_t	v7st_dev;
	u_short	v7st_ino;
	u_short v7st_mode;
	short  	v7st_nlink;
	short  	v7st_uid;
	short  	v7st_gid;
	dev_t	v7st_rdev;
	int	v7st_size;
	int	v7st_atime;
	int	v7st_mtime;
	int	v7st_ctime;
} statv7;

struct timeb {
	time_t	time;
	u_short	millitm;
	short	timezone;
	short	dstflag;
} timeb;
#endif

I 4
#define	NFILES	20
#define	ODSIZE	16

off_t	olseek();

struct odirect {
	u_short	od_ino;
	char	od_name[14];
};

struct fdflags {
	DIR	*fd_dirp;
	struct odirect	fd_od;
	off_t	fd_offset;
} fdflags[NFILES];

E 4
E 3
/* do the trap stuff for the trap with code */
D 3
dotrap(code) int code; {
E 3
I 3
dotrap(code)
	int code;
{
E 3
	register unsigned short *argp, *savp, *savep;
	register int i, j, indirflg;
	register char *avp, *oavp;
	extern sigcatch();
	extern errno;
I 4
	extern int sigtrapped;
	DIR *dp;
E 4
I 3

I 4
	sigtrapped = 0;
E 4
E 3
	/* clear out condition codes of psl */
	psl &= ~017;
	/* special case of indirect sys call */
D 3
	if(code == 0) {
E 3
I 3
	if (code == 0) {
E 3
		/* remember this was indirect */
		indirflg = 1;
		/* point to args */
		argp = (unsigned short *)*(pc++);
		/* code for indirect sys call */
		code = *argp++;
		/* is it legit */
D 3
		if(code>>8 != TRAPS) {
E 3
I 3
		if (code>>8 != TRAPS) {
E 3
			fprintf(stderr,"Bad indirect sys call at 0x%x\n",pc-2);
			pc++;
			/* set carry flag */
			psl |= CARRY;
			regs[0] = -1;
			return(-1);
		}
		code &= 0377;
D 3
	}
	else {
E 3
I 3
	} else {
E 3
		/* remember this was not indirect */
		indirflg = 0;
		/* point to args */
		argp = pc;
	}
	/* check if code too high or bad sys code */
D 3
	if(code >= NSYSTRAPS || sysargs[code][0] == ILLSYS) {
E 3
I 3
	if (code >= NSYSTRAPS || sysargs[code][0] == ILLSYS) {
E 3
		fprintf(stderr,"Unimplimented trap %d at 0x%x\n",code,argp);
		/* set carry bit */
		psl |= CARRY;
		regs[0] = -1;
		return(-1);
	}
	/* copy args to known locations */
	i=0;
D 3
	for(j=0; j<sysargs[code][0]; j++) args[i++] = regs[j];
	for(j=0; j<(sysargs[code][1]); j++) args[i++] = *argp++;
E 3
I 3
	for (j=0; j<sysargs[code][0]; j++)
		args[i++] = regs[j];
	for (j=0; j<(sysargs[code][1]); j++)
		args[i++] = *argp++;
E 3
#ifdef TRACE
	fprintf(stderr,"pid %d ",getpid());
D 3
	if(indirflg) fprintf(stderr,"indirect ");
	fprintf(stderr,"%s (%d) from 0%o with %d args",sysnames[code],code,pc-1,i);
	for(j=0; j<i; j++)
E 3
I 3
	if (indirflg)
		fprintf(stderr,"indirect ");
	fprintf(stderr, "%s (%d) from 0%o with %d args",
	    sysnames[code], code, pc-1, i);
	for (j=0; j<i; j++)
E 3
		fprintf(stderr," 0%o",args[j]);
D 3
	if(code==OPEN||code==STAT||code==CREAT||code==EXEC||code==UNLNK||code==LINK||code==CHDIR||code==MKNOD)
E 3
I 3
	if (code==OPEN || code==STAT || code==CREAT || code==EXEC || 
	    code==UNLNK || code==LINK || code==CHDIR || code==MKNOD)
E 3
		fprintf(stderr," (%s)",args[0]);
#ifdef V7UNIX
D 3
	if(code==EXECE)
E 3
I 3
	if (code==EXECE)
E 3
		fprintf(stderr," (%s)",args[0]);
#endif
D 3
	if(code==LINK)
E 3
I 3
	if (code==LINK)
E 3
		fprintf(stderr," (%s)",args[1]);
#endif
	/* go do whatever sys call it is */
D 3
	switch(code) {
	case	FORK:
E 3
I 3
	switch (code) {
	case FORK:
E 3
		/* indirect forks return pids on both sides - must do here */
		/* this is possibly a bug in 32V */
		i = fork();
		break;
D 3
	case	WAIT:
E 3
I 3

	case WAIT:
E 3
		i = wait(&wstatus);
		args[0] = i;
		args[1] = wstatus;
		break;
D 3
	case	EXEC:
E 3
I 3

	case EXEC:
E 3
#ifdef V7UNIX
D 3
	case	EXECE:
E 3
I 3
	case EXECE:
E 3
#endif
		/*
		 *  have to do a lot of junk here to fix up an argv
		 *  for execute since (1) the pdp-11 argv consists of 16
		 *  bit pointers and (2) the argv itself is in the
		 *  pdp-11 program space where it would get clobbered
		 *  when a new program is read in and before its
		 *  argv is set up.
		 */
		avp = &argvs[0];
		savp = (unsigned short *)args[1];
#ifdef	V6UNIX
D 3
		for(i=1; args[i] = *savp++; i++)
			if(args[i] == 0177777) break;
E 3
I 3
		for (i=1; args[i] = *savp++; i++)
			if (args[i] == 0177777)
				break;
E 3
#ifdef	TRACE
D 3
			else fprintf(stderr,"argv[%d]%s ",i-1,args[i]);
E 3
I 3
			else
				fprintf(stderr,"argv[%d]%s ",i-1,args[i]);
E 3
#endif
#endif
#ifdef	V7UNIX
		savep = (unsigned short *)args[2];
D 3
		for(i=1; args[i] = *savp++; i++)
E 3
I 3
		for (i=1; args[i] = *savp++; i++)
E 3
#ifdef	TRACE
			fprintf(stderr,"argv[%d]%s ",i-1,args[i]);
#else
			;
#endif
#endif
D 3
		if(stat(args[0], &stat32v)) {
E 3
I 3
		if (stat(args[0], &stat32v)) {
E 3
			/* return error here if file does not exist */
#ifdef	TRACE
			fprintf(stderr," does not exist\n");
#endif
			i = -1;
			break;
		}
		/* must have execute permission */
D 3
		if(stat32v.st_mode & (S_IEXEC>>6)) goto experm;
		if(stat32v.st_mode & (S_IEXEC>>3)) {
			if(stat32v.st_gid == getegid()) goto experm;
			if(geteuid() == 0) goto experm;
E 3
I 3
		if (stat32v.st_mode & (S_IEXEC>>6))
			goto experm;
		if (stat32v.st_mode & (S_IEXEC>>3)) {
			if (stat32v.st_gid == getegid())
				goto experm;
			if (geteuid() == 0)
				goto experm;
E 3
		}
D 3
		if(stat32v.st_mode & S_IEXEC) {
			if(stat32v.st_uid == geteuid()) goto experm;
			if(geteuid() == 0) goto experm;
E 3
I 3
		if (stat32v.st_mode & S_IEXEC) {
			if (stat32v.st_uid == geteuid())
				goto experm;
			if (geteuid() == 0)
				goto experm;
E 3
		}
		/* return failure if no exec permision allowed */
		i = -1;
experm:
		/* can't exec a directory */
D 3
		if(stat32v.st_mode & S_IFDIR)
E 3
I 3
		if ((stat32v.st_mode&S_IFMT) == S_IFDIR)
E 3
			i = -1;
D 3
		if(i == -1) break;
E 3
I 3
		if (i == -1)
			break;
E 3
		args[i] = 0;
D 3
		for(j=0; j<i; j++) {
E 3
I 3
D 4
		for (j=0; j<i; j++) {
E 4
I 4
		for (j=1; j<i; j++) {
E 4
E 3
			oavp = (char *)args[j];
			args[j] = (int)avp;
D 3
			while(*avp++ = *oavp++) ;
E 3
I 3
			while (*avp++ = *oavp++)
				;
E 3
		}
#ifdef V7UNIX
D 3
		if(code == EXECE) {
			for(j = ++i; args[j] = *savep++; j++) ;
			for( ; j>i; j--) {
E 3
I 3
		if (code == EXECE) {
			for (j = ++i; args[j] = *savep++; j++)
				;
D 4
			for ( ; j > i; j--) {
E 3
				oavp = (char *)args[j];
E 4
I 4
			for (j = i; oavp = (char *)args[j]; j++) {
E 4
				args[j] = (int)avp;
D 3
				while(*avp++ = *oavp++) ;
E 3
I 3
				while (*avp++ = *oavp++)
					;
E 3
			}
		}
#endif
		/* SETUID and SETGID files must be started with a fresh RTS */
D 3
		if(stat32v.st_mode & S_ISGID || stat32v.st_mode & S_ISUID) {
E 3
I 3
		if (stat32v.st_mode & S_ISGID || stat32v.st_mode & S_ISUID) {
E 3
			/* should add a check here for good magic # in header */
			args[1] = args[0];
			args[0] = (int)RTSNAME;
#ifdef TRACE
			fprintf(stderr," SETUID-GID");
#endif
D 3
			if(args[i])
E 3
I 3
			if (args[i])
E 3
				i = execve(args[0], &args[0], &args[i]);
			else
				i = execv(args[0], &args[0]);
			fprintf(stderr,"can't exec %s\n",RTSNAME);
			break;
		}
		i = execute(args[0], &args[1], &args[i]);
		/* shouldn't get here if exec works */
		break;
D 3
	case	SEEK:
E 3
I 3

	case SEEK:
E 3
#ifdef	V6UNIX
		/* fix up negative offsets */
D 3
		if(args[2] != 0 && args[2] != 3)
			if(args[1] >= 32768) args[1] -= 65536;
		if(args[2] <= 2)
E 3
I 3
		if (args[2] != 0 && args[2] != 3)
			if (args[1] >= 32768)
				args[1] -= 65536;
		if (args[2] <= 2)
E 3
D 4
			i = lseek(args[0], args[1], args[2]);
E 4
I 4
			i = olseek(args[0], args[1], args[2]);
E 4
		else
D 4
			i = lseek(args[0], args[1]*512, args[2]-3);
E 4
I 4
			i = olseek(args[0], args[1]*512, args[2]-3);
E 4
D 3
		if(i != -1) i = 0;
E 3
I 3
		if (i != -1)
			i = 0;
E 3
#endif
#ifdef	V7UNIX
D 4
		i = lseek(args[0], (args[1]<<16)|(args[2]&0177777), args[3]);
E 4
I 4
		i = olseek(args[0], (args[1]<<16)|(args[2]&0177777), args[3]);
E 4
#endif
		break;
I 3

E 3
D 4
#ifdef	V6UNIX
E 4
D 3
	case	MKNOD:
E 3
I 3
	case MKNOD:
E 3
D 4
		/* version 6 uses allocated bit which means regular file here */
D 3
		if(args[1] & S_IFBLK)
E 3
I 3
		if (args[1] & S_IFBLK)
E 3
			args[1] &= ~S_IFREG;
		i = mknod(args[0], args[1], args[2]);
		break;
E 4
I 4
		if ((args[1] & S_IFMT) == S_IFDIR)
			i = mkdir(args[0], args[1] & 0777);
		else {
#ifdef	V6UNIX
			/*
			 * version 6 uses allocated bit which
			 * means regular file here
			 */
			if (args[1] & S_IFBLK)
				args[1] &= ~S_IFREG;
E 4
#endif	
I 4
			i = mknod(args[0], args[1], args[2]);
		}
		break;
E 4
D 3
	case	PIPE:
E 3
I 3

	case PIPE:
E 3
		i = pipe(pipes);
		args[0] = pipes[0];
		args[1] = pipes[1];
		break;
I 3

E 3
#ifdef	V6UNIX
D 3
	case	TELL:
E 3
I 3
	case TELL:
E 3
		i = lseek(args[0], 0L, 1);
		break;
I 3

	case STTY:
		i = stty(args[0], args[1]);
		break;

	case GTTY:
		i = gtty(args[0], args[1]);
		break;
E 3
#endif
D 3
	case	STAT:
	case	FSTAT:
E 3
I 3

I 4
	/* HAVE TO FAKE THE SIZE OF DIRECTORIES */

E 4
	case STAT:
		i = stat(args[0], &stat32v);
		goto allstat;

	case FSTAT:
E 3
		/* do the syscall to a local stat buffer */
D 3
		i = syscall(code, args[0], &stat32v);
E 3
I 3
		i = fstat(args[0], &stat32v);

	allstat:
E 3
		/* reverse the longs */
		stat32v.st_size = longrev(stat32v.st_size);
		stat32v.st_atime = longrev(stat32v.st_atime);
		stat32v.st_mtime = longrev(stat32v.st_mtime);
		stat32v.st_ctime = longrev(stat32v.st_ctime);
#ifdef V7UNIX
I 3
		statv7.v7st_dev = stat32v.st_dev;
		statv7.v7st_ino = stat32v.st_ino;
		statv7.v7st_mode = stat32v.st_mode;
		statv7.v7st_nlink = stat32v.st_nlink;
		statv7.v7st_uid = stat32v.st_uid;
		statv7.v7st_gid = stat32v.st_gid;
		statv7.v7st_rdev = stat32v.st_rdev;
		statv7.v7st_size = stat32v.st_size;
		statv7.v7st_atime = stat32v.st_atime;
		statv7.v7st_mtime = stat32v.st_mtime;
		statv7.v7st_ctime = stat32v.st_ctime;
E 3
		/* copy out otherwise unchanged stat buffer */
		/* in two pieces with st_size as the breaking point */
		/* note that st_rdev is a short but due to alingnmemt */
		/* problems the rest of the structure is out of sync */
D 3
		j = (int)((char *)(&stat32v.st_size)-(char *)(&stat32v.st_dev));
		bcopy(&stat32v, args[1], j);
		bcopy(&stat32v.st_size, args[1]+j-2, sizeof(struct stat)-j);
E 3
I 3
		j = (int)((char *)(&statv7.v7st_size) -
		    (char *)(&statv7.v7st_dev));
		bcopy(&statv7, args[1], j);
		bcopy(&statv7.v7st_size, args[1]+j-2, sizeof(struct v7stat)-j);
E 3
#endif
#ifdef	V6UNIX
		/* point to user area as v6stat structure */
		v6stat = (struct v6nod *)args[1];
		/* copy out piece by piece */
		v6stat->majmin = stat32v.st_dev;
		v6stat->inumber = stat32v.st_ino;
		v6stat->flags = stat32v.st_mode;
		v6stat->nlinks = (unsigned char)stat32v.st_nlink;
		v6stat->uid = (unsigned char)stat32v.st_uid;
		v6stat->gid = (unsigned char)stat32v.st_gid;
		/* note size already reversed */
		v6stat->size0 = (unsigned char)(stat32v.st_size & 0377);
		v6stat->size1 = (unsigned short)(stat32v.st_size>>16);
		v6stat->actime = stat32v.st_atime;
		v6stat->modtime = stat32v.st_mtime;
		/* patch up flags */
		/* for now just set 100000 bit if not a plain file */
D 3
		if(v6stat->flags & 060000)
E 3
I 3
		if (v6stat->flags & 060000)
E 3
			v6stat->flags |= 0100000;
#endif
		break;
D 3
	case	TIMES:
E 3
I 3

	case TIMES:
E 3
		i = times(&timebuf);
		timebuf.t2 = longrev(timebuf.t2) + timebuf.t1;
		timebuf.t3 = longrev(timebuf.t3);
		timebuf.t4 = longrev(timebuf.t4);
		bcopy(&timebuf.t2,args[0],sizeof(struct timebuf)-sizeof(long));
		break;
I 3

E 3
#ifdef	V6UNIX
D 3
	case	SLEEP:
E 3
I 3
	case SLEEP:
E 3
		/* do a sleep function - what about pwb which has alarm? */
		sleep(args[0]);
		break;
#endif
D 3
	case	GETUID:
E 3
I 3

	case GETUID:
E 3
		args[0] = getuid();
		args[1] = geteuid();
#ifdef V6UNIX
D 3
		i = args[1]<<8 | args[0];
E 3
I 3
		i = args[1]<<8 | (args[0] & 0377);
E 3
#endif
		break;
D 3
	case	GETGID:
E 3
I 3

	case GETGID:
E 3
		args[0] = getgid();
		args[1] = getegid();
#ifdef V6UNIX
D 3
		i = args[1]<<8 | args[0];
E 3
I 3
		i = args[1]<<8 | (args[0] & 0377);
E 3
#endif
		break;
D 3
#ifdef V6UNIX
	case	SETUID:
	case	SETGID:
E 3
I 3

E 3
		/* uids and gids are 8 bits in version 6 */
D 3
		i = syscall(code,args[0]&0377);
		break;
E 3
I 3
	case SETUID:
	case SETGID:
#ifdef V6UNIX
		args[0] &= 0377;
E 3
#endif
D 3
	case	SIG:
E 3
I 3
		if (code == SETUID)
			i = setuid(args[0]);
		else
			i = setgid(args[0]);
		break;

	case SIG:
E 3
		/* if it is a good signal code */
D 3
		if(args[0] <= NSIG) {
E 3
I 3
		if (args[0] <= NSIG) {
E 3
			/* get the current signal value */
			i = sigvals[args[0]];
			/* reset the signal to the new value */
			sigvals[args[0]] = args[1];
			/* actually do signal except don't reset SIGILL */
D 3
			if(args[0] != SIGILL) {
				if(args[1] == (int)SIG_DFL || args[1] & (int)SIG_IGN) {
					if((int)signal(args[0],args[1]) == -1)
E 3
I 3
			if (args[0] != SIGILL) {
				if (args[1] == (int)SIG_DFL ||
				    args[1] & (int)SIG_IGN) {
					if ((int)signal(args[0],args[1]) == -1)
E 3
						i = -1;
				} else {
D 3
					if((int)signal(args[0], sigcatch) == -1)
E 3
I 3
					if ((int)signal(args[0],sigcatch) == -1)
E 3
						i = -1;
				}
			}
D 3
		}
		else i = -1;
E 3
I 3
		} else
			i = -1;
E 3
		break;
D 3
	case	BRK:
E 3
I 3

	case BRK:
E 3
		/* brk is successful unless we run over the stack */
I 3
		/* NB: this assumes register usage which need not be used */
E 3
		i = 0;
D 3
		if(args[0] >= regs[6]) i = -1;
E 3
I 3
		if (args[0] >= regs[6])
			i = -1;
E 3
		break;
I 3

	/*
	 * the next bunch are to cope with sys calls removed from 4.2
	 */
	case TIME:
		i = time(0);
		break;

	case STIME: {
		struct timeval tv;

		tv.tv_usec = 0;
		tv.tv_sec = (args[0] & 0xffff) | ((args[1] & 0xffff) << 16);
		i = settimeofday(&tv);
		break;
	}

	case NICE:
		i = nice(args[0]);
		break;

#ifdef V7UNIX
	case ALARM:
		i = alarm(args[0]);
		break;

	case PAUSE:
		i = pause();
		break;

	case UTIME:
		i = utime(args[0], args[1]);
		break;

	case FTIME:
		i = ftime(&timeb);
		timeb.time = longrev(timeb.time);
		bcopy(&timeb, args[0], sizeof timeb - 2);
		break;

	case IOCTL:
		args[1] = mapioctl(args[1]);
		if (args[1] == 0)
			i = -1;
		else
			i = ioctl(args[0], args[1], args[2]);
		break;
#endif

E 3
#ifdef	V6UNIX
D 3
	case	PWBSYS:
E 3
I 3
	case PWBSYS:
E 3
		/* ignore pwbsys for now */
D 3
		switch(args[2]) {
		case	UNAME:
E 3
I 3
		switch (args[2]) {
		case UNAME:
E 3
#ifdef	TRACE
			fprintf(stderr,"UNAME with %d %d\n",args[0],args[1]);
#endif
			strcpy(args[0],"pwbname");
			i = 0;
			break;
D 3
		case	UDATA:
E 3
I 3

		case UDATA:
E 3
#ifdef	TRACE
			fprintf(stderr,"UDATA with %d %d\n",args[0],args[1]);
#endif
			i = 0;
			break;
D 3
		case	USTAT:
E 3
I 3

		case USTAT:
E 3
fprintf(stderr,"USTAT with %d %d\n",args[0],args[1]);
			i = 0;
			break;
D 3
		case	UTIME:
E 3
I 3

		case UTIME:
E 3
fprintf(stderr,"UTIME with %d %d\n",args[0],args[1]);
			i = 0;
			break;
		default:
fprintf(stderr,"bad PWBSYS %d\n",args[3]);
			i = -1;
			break;
		}
		break;
#endif
I 3

E 3
	default:
		/*
		 *	Many sys calls are easily done here since most
		 *	system call codes are the same on version 6 and 7 UNIX
		 *	as they are here.
		 */
		i = syscall(code,args[0],args[1],args[2],args[3],args[4]);
#ifdef V6UNIX
D 3
		/* allow read write access to created files for(IDIS v6 mod) */
		if(code==CREAT) {
E 3
I 3
		/* allow read write access to created files for (IDIS v6 mod) */
		if (code==CREAT) {
E 3
			/* get actual file mode after create */
			fstat(i, &stat32v);
			close(i);
			/* ensure read/write access to owner */
			chmod(args[0], 0644);
			i = open(args[0], 2);
			/* change mode back the way it was */
			chmod(args[0], stat32v.st_mode);
		}
#endif
		break;
I 4
	case OPEN:
		/*
		 * check if we are opening a directory
		 */
		if (stat(args[0], &stat32v) >= 0  &&
		    ((stat32v.st_mode & S_IFMT) == S_IFDIR) &&
		    ((dp = opendir(args[0])) != NULL)) {
#ifdef DTRACE
			fprintf(stderr,"open directory fd %d\n", i);
#endif
			i = dp->dd_fd;
			fdflags[i].fd_dirp = dp;
			fdflags[i].fd_offset = 0;
		} else
			i = open(args[0], args[1]);
		break;
	case CLOSE:
		i = close(args[0]);
		if (i >= 0 && fdflags[args[0]].fd_dirp) {
			closedir(fdflags[args[0]].fd_dirp);
			fdflags[args[0]].fd_dirp = 0;
		}
		break;
	case READ:
		if ((unsigned)args[0] < NFILES && fdflags[args[0]].fd_dirp)
			i = oread(args[0], args[1], args[2]);
		else
			i = read(args[0], args[1], args[2]);
		break;
E 4
	}
#ifdef TRACE
	fprintf(stderr," sys val -> 0%o\n",i);
#endif
	/* set carry bit if sys error */
D 3
	if(i == -1)
E 3
I 3
	if (i == -1)
E 3
		psl |= CARRY;
	/* if not an indirect sys call, adjust the pc */
D 3
	if(indirflg == 0)
E 3
I 3
D 4
	if (indirflg == 0)
E 4
I 4
	if (!indirflg && !sigtrapped)
E 4
E 3
		pc = argp;
	/* do alternate return on one side of fork */
D 3
	if(code == FORK && i != 0)
E 3
I 3
	if (code == FORK && i != 0)
E 3
		pc++;
	/* do the various return value formats */
D 3
	switch(sysargs[code][2]) {
	case	NORMRET:
E 3
I 3
	switch (sysargs[code][2]) {
	case NORMRET:
E 3
		/* normal case only one return value in r0 */
		regs[0] = i;
		break;
D 3
	case	LONGRET:
E 3
I 3
	case LONGRET:
E 3
		/* return a long in r0 - r1 as in time */
		regs[1] = i;
		regs[0] = i >> 16;
		break;
D 3
	case	TWORET:
E 3
I 3
	case TWORET:
E 3
		/* return two ints in r0 - r1 as in pipe */
D 3
		if(i == -1)
E 3
I 3
		if (i == -1)
E 3
			regs[0] = i;
		else {
			regs[1] = args[1];
			regs[0] = args[0];
		}
		break;
	}
D 3
	if(i== -1)
E 3
I 3
	if (i== -1)
E 3
		regs[0] = errno;
}
D 3
long longrev(l) long l; {
E 3
I 3

long
longrev(l)
	long l;
{
E 3
	/* function to reverse the halves of a long */
	union {
		long	lng;
		short	s[2];
	} u;
	register short t;
	u.lng = l;
	t = u.s[0];
	u.s[0] = u.s[1];
	u.s[1] = t;
	return(u.lng);
I 3
}

/*
 * Note: these tables are sorted by
 * ioctl "code" (in ascending order).
 */
int fctls[] = { FIOCLEX, FIONCLEX, FIOASYNC, FIONBIO, FIONREAD, 0 };
int tctls[] = {
	TIOCGETD, TIOCSETD, TIOCHPCL, TIOCMODG, TIOCMODS,
	TIOCGETP, TIOCSETP, TIOCSETN, TIOCEXCL, TIOCNXCL,
	TIOCFLUSH,TIOCSETC, TIOCGETC, TIOCREMOTE,TIOCMGET,
	TIOCMBIC, TIOCMBIS, TIOCMSET, TIOCSTART,TIOCSTOP,
	TIOCPKT,  TIOCNOTTY,TIOCSTI,  TIOCOUTQ, TIOCGLTC,
	TIOCSLTC, TIOCSPGRP,TIOCGPGRP,TIOCCDTR, TIOCSDTR,
	TIOCCBRK, TIOCSBRK, TIOCLGET, TIOCLSET, TIOCLBIC,
	TIOCLBIS, 0
};

/*
 * Map an old style ioctl command to new.
 */
mapioctl(cmd)
	int cmd;
{
	register int *map, c;

	switch ((cmd >> 8) & 0xff) {

	case 'f':
		map = fctls;
		break;

	case 't':
		map = tctls;
		break;

	default:
		return (0);
	}
	while ((c = *map) && (c&0xff) < (cmd&0xff))
		map++;
	if (c && (c&0xff) == (cmd&0xff))
		return (c);
	return (0);
I 4
}

/*
 * emulate a read of n bytes on an old style directory
 */
oread(fd, buf, count)
int fd, count;
char *buf;
{
	struct fdflags *fp;
	struct direct *dp;
	DIR *dirp;
	struct odirect *odp;
	register int nleft = count;
	int dir_off;
	int i;

	fp = &fdflags[fd];
	dirp = fp->fd_dirp;
	odp = &fp->fd_od;
	if (dirp == NULL)
		return(-1);
	dir_off = fp->fd_offset % ODSIZE;
	if (dir_off) {
		i = ODSIZE - dir_off;
		if (nleft < i)
			i = nleft;
		bcopy((caddr_t)odp + dir_off, buf, i);
		fp->fd_offset += i;
		if (i == nleft)
			return(i);
		buf += i;
		nleft -= i;
	}
	while (nleft >= ODSIZE) {
		if ((dp = readdir(dirp)) == NULL)
			return(count - nleft);
		odp->od_ino = dp->d_ino;
		strncpy(odp->od_name, dp->d_name, 14);
		bcopy((caddr_t)odp, buf, ODSIZE);
		fp->fd_offset += ODSIZE;
		buf += ODSIZE;
		nleft -= ODSIZE;
	}
	if (nleft > 0) {
		if ((dp = readdir(dirp)) == NULL)
			return(count - nleft);
		odp->od_ino = dp->d_ino;
		strncpy(odp->od_name, dp->d_name, 14);
		bcopy((caddr_t)odp, buf, nleft);
		fp->fd_offset += nleft;
		/* nleft = 0; */
	}
	return(count);
}

/*
 * emulate the lseek system call
 */
off_t
olseek(fd, n, whence)
int fd, whence;
off_t n;
{
	struct fdflags *fp;
	char buf[512];
	off_t newpos;
	int i, j;

	if ((unsigned)fd >= NFILES)
		return(-1);
	fp = &fdflags[fd];
	/*
	 * the system can handle everything
	 * except directory files
	 */
	if (fp->fd_dirp == NULL)
		return(lseek(fd, n, whence));
	switch (whence) {
	case 0:
		newpos = n;
		break;
	case 1:
		newpos = fp->fd_offset + n;
		break;
	case 2:		/* not yet implemented */
	default:
		return(-1);
	}
	if (newpos < 0)
		return(-1);
	if (newpos < fp->fd_offset) {
		rewinddir(fdflags[fd].fd_dirp);
		fp->fd_offset = 0;
	}
	i = newpos - fp->fd_offset;
	while (i > 0) {
		j = i < 512 ? i : 512;
		if (oread(fd, buf, j) != j)
			break;
		i -= j;
	}
	return(fp->fd_offset);
E 4
E 3
}
E 1
