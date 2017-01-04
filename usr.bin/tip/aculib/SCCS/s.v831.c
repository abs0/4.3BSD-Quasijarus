h20682
s 00007/00001/00226
d D 5.1 85/04/30 12:54:38 dist 6 5
c Add copyright
e
s 00000/00002/00227
d D 4.5 83/06/25 02:10:14 sam 5 4
c remove #if's, now in a library
e
s 00003/00012/00226
d D 4.4 83/06/25 01:15:09 sam 4 3
c so much...clean up after ralph's merge of wendel and mo code;
c purge VMUNIX include since changes for signals make it no longer portable 
c to systems other than 4.2; fix ventel for no echo strapping; do setjmps 
c instead of assuming interrupted system calls; purge lcmd, if people use 
e
s 00007/00003/00231
d D 4.3 83/06/18 12:22:28 sam 3 2
c misc
e
s 00168/00184/00066
d D 4.2 83/06/15 17:35:23 ralph 2 1
c some changes/bug fixes from sam
e
s 00250/00000/00000
d D 4.1 83/06/15 12:04:30 ralph 1 0
c date and time created 83/06/15 12:04:30 by ralph
e
u
U
t
T
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 6
I 1
D 2
/*	831.c	4.1	83/5/10	*/
E 2
I 2
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif
E 6
I 6
#endif not lint
E 6
E 4
E 2

D 2
#if V831
E 2
I 2
D 5
#ifdef V831
E 5
E 2
/*
 * Routines for dialing up on Vadic 831
 */
D 2
#include "tip.h"
E 2
I 2
D 4
#include <sys/file.h>
E 4
#include <sys/time.h>

E 2
D 4
#include <setjmp.h>
#include <errno.h>
#include <sgtty.h>
D 2
#include <sys/file.h>
#include <time.h>
E 2

E 4
I 2
#include "tip.h"

E 2
D 4
static char *sccsid = "%W% %G%";

E 4
D 2
struct mx_leaves {
    char    *name;
    char    rack,modem;
} pdevs[] = {{"/dev/cua0",'4','0'}, {"/dev/cua1",'4','1'}, {0}};
E 2
I 2
int	v831_abort();
D 3
int	alarmtr();
E 3
I 3
static	int alarmtr();
E 3
extern	errno;
E 2

D 2
struct timeval zerotime = {0L, 0L};

#define unlike(a,b) (strcmp(a,b))
#define pc(x) (c = x, write(AC,&c,1))
#define ABORT	01
#define SI	017
#define STX	02
#define ETX	03

int v831_abort();

int alarmtr();

E 2
static jmp_buf jmpbuf;
static int child = -1;

v831_dialer(num, acu)
D 2
	char *num, *acu;
E 2
I 2
        char *num, *acu;
E 2
{
D 2
	extern errno;
	char *p, *q, phone[40];
	char char_rv;
	int lt, nw, connected = 1;
	register int timelim;
E 2
I 2
        int status, pid, connected = 1;
        register int timelim;
E 2

D 2
	if (boolean(value(VERBOSE)))
		printf("\nstarting call...");
E 2
I 2
        if (boolean(value(VERBOSE)))
                printf("\nstarting call...");
E 2
#ifdef DEBUG
D 2
	printf ("(acu=%s)", acu);
E 2
I 2
        printf ("(acu=%s)\n", acu);
E 2
#endif
D 2
	if ((AC = open(acu, FRDWR)) < 0) {
		if (errno == EBUSY)
			printf("line busy...");
		else
			printf("acu open error...");
		return (0);
	}
	if (setjmp(jmpbuf)) {
		kill(child, SIGKILL);
		close(AC);
		return (0);
	}
	signal(SIGALRM, alarmtr);
	timelim = 5 * strlen(num);
	alarm(timelim < 30 ? 30 : timelim);
	if ((child = fork()) == 0) {
		/*
		 * ignore this stuff for aborts
		 */
		signal(SIGALRM, SIG_IGN);
E 2
I 2
D 3
        if ((AC = open(acu, FRDWR)) < 0) {
E 3
I 3
        if ((AC = open(acu, O_RDWR)) < 0) {
E 3
                if (errno == EBUSY)
                        printf("line busy...");
                else
                        printf("acu open error...");
                return (0);
        }
        if (setjmp(jmpbuf)) {
                kill(child, SIGKILL);
                close(AC);
                return (0);
        }
        signal(SIGALRM, alarmtr);
        timelim = 5 * strlen(num);
        alarm(timelim < 30 ? 30 : timelim);
        if ((child = fork()) == 0) {
                /*
                 * ignore this stuff for aborts
                 */
                signal(SIGALRM, SIG_IGN);
E 2
		signal(SIGINT, SIG_IGN);
D 2
		signal(SIGQUIT, SIG_IGN);
		sleep(2);
		/*nw = write(AC, num, lt = strlen(num));*/
		char_rv = dialit (num, acu);
		exit(char_rv != 'A');
	}
	/*
	 * open line - will return on carrier
	 */
	if ((FD = open(DV, 2)) < 0) {
E 2
I 2
                signal(SIGQUIT, SIG_IGN);
                sleep(2);
                exit(dialit(num, acu) != 'A');
        }
        /*
         * open line - will return on carrier
         */
D 3
        if ((FD = open(DV, 2)) < 0) {
E 3
I 3
        if ((FD = open(DV, O_RDWR)) < 0) {
E 3
E 2
#ifdef DEBUG
D 2
		printf("(after open, errno=%d)", errno);
E 2
I 2
                printf("(after open, errno=%d)\n", errno);
E 2
#endif
D 2
		if (errno == EIO)
			printf("lost carrier...");
		else
			printf("dialup line open failed...");
		alarm(0);
		kill(child, SIGKILL);
		close(AC);
		return (0);
	}
	alarm(0);
	/*ioctl(AC, TIOCHPCL, 0);*/
	signal(SIGALRM, SIG_DFL);
	while ((nw = wait(&lt)) != child && nw != -1)
		;
	fflush(stdout);
	/*close(AC);*/
	if (lt != 0) {
		close(AC);
		return (0);
	}
	return (1);
E 2
I 2
                if (errno == EIO)
                        printf("lost carrier...");
                else
                        printf("dialup line open failed...");
                alarm(0);
                kill(child, SIGKILL);
                close(AC);
                return (0);
        }
        alarm(0);
#ifdef notdef
        ioctl(AC, TIOCHPCL, 0);
#endif
        signal(SIGALRM, SIG_DFL);
        while ((pid = wait(&status)) != child && pid != -1)
                ;
        if (status) {
                close(AC);
                return (0);
        }
        return (1);
E 2
}

I 3
static
E 3
alarmtr()
{
I 3

E 3
D 2
	alarm(0);
	longjmp(jmpbuf, 1);
E 2
I 2
        alarm(0);
        longjmp(jmpbuf, 1);
E 2
}

/*
 * Insurance, for some reason we don't seem to be
 *  hanging up...
 */
v831_disconnect()
{
D 2
	struct sgttyb cntrl;
	sleep(2);
E 2
I 2
        struct sgttyb cntrl;

        sleep(2);
E 2
D 4
#ifdef VMUNIX
E 4
#ifdef DEBUG
D 2
	printf ("[disconnect: FD=%d]", FD);
E 2
I 2
        printf("[disconnect: FD=%d]\n", FD);
E 2
#endif
D 2
	if (FD > 0)
	{
		ioctl (FD, TIOCCDTR, 0);
		ioctl (FD, TIOCGETP, &cntrl);
		cntrl.sg_ispeed = 0;
		cntrl.sg_ospeed = 0;
		ioctl (FD, TIOCSETP, &cntrl);
		ioctl (FD, TIOCNXCL, (struct sgttyb *)NULL);
	}
E 2
I 2
        if (FD > 0) {
                ioctl(FD, TIOCCDTR, 0);
                ioctl(FD, TIOCGETP, &cntrl);
                cntrl.sg_ispeed = cntrl.sg_ospeed = 0;
                ioctl(FD, TIOCSETP, &cntrl);
                ioctl(FD, TIOCNXCL, (struct sgttyb *)NULL);
        }
E 2
D 4
#endif
E 4
D 2
	close(FD);
E 2
I 2
        close(FD);
E 2
}

v831_abort()
{
I 3

E 3
#ifdef DEBUG
D 2
	printf ("[abort: AC=%d]", AC);
E 2
I 2
        printf("[abort: AC=%d]\n", AC);
E 2
#endif
D 2
	sleep(2);
	if (child > 0)
		kill(child, SIGKILL);
	if (AC > 0)
		ioctl (FD, TIOCNXCL, (struct sgttyb *)NULL);
		close(AC);
E 2
I 2
        sleep(2);
        if (child > 0)
                kill(child, SIGKILL);
        if (AC > 0)
                ioctl(FD, TIOCNXCL, (struct sgttyb *)NULL);
                close(AC);
E 2
D 4
#ifdef VMUNIX
E 4
D 2
	if (FD > 0)
		ioctl(FD, TIOCCDTR, 0);
E 2
I 2
        if (FD > 0)
                ioctl(FD, TIOCCDTR, 0);
E 2
D 4
#endif
E 4
D 2
	close(FD);
E 2
I 2
        close(FD);
E 2
}
D 5
#endif
E 5

D 2
static struct sgttyb cntrl;
dialit(string, acu)
register char *string;
char *acu;
{
	char c, cc, *sanitize();
	int i;
	register struct mx_leaves *lp = pdevs;
	int test;
	int nfds, fdsmask;
E 2
I 2
/*
 * Sigh, this probably must be changed at each site.
 */
struct vaconfig {
	char	*vc_name;
	char	vc_rack;
	char	vc_modem;
} vaconfig[] = {
	{ "/dev/cua0",'4','0' },
	{ "/dev/cua1",'4','1' },
	{ 0 }
};
E 2

D 2
	string = sanitize(string);
#ifdef DEBUG
	printf ("(dial string=%s)", string);
#endif
	if(*string=='<' && string[1]==0) {
		return('Z');
	}
E 2
I 2
#define pc(x)	(c = x, write(AC,&c,1))
#define ABORT	01
#define SI	017
#define STX	02
#define ETX	03
E 2

I 3
static
E 3
D 2
	while(test = unlike(lp->name,acu))
	    if(lp->name==0) {
		printf("Unable to locate dialer (%s)\n", acu);
		return('K');
	    } else lp++;
E 2
I 2
dialit(phonenum, acu)
	register char *phonenum;
	char *acu;
{
        register struct vaconfig *vp;
	struct sgttyb cntrl;
        char c, *sanitize();
        int i, two = 2;
E 2

D 2

	gtty (AC,&cntrl);	/* set raw, -echo, 2400 Baud */
	cntrl.sg_ispeed = cntrl.sg_ospeed = B2400;
	cntrl.sg_flags = RAW | EVENP | ODDP;
	stty (AC,&cntrl);

	/* check for characters waiting from dialer (throw them away) */

	fdsmask = 1<<AC;
E 2
I 2
        phonenum = sanitize(phonenum);
E 2
#ifdef DEBUG
D 2
	printf ("{select returns=%d}", select (20, &fdsmask, 0, 0, &zerotime));
E 2
I 2
        printf ("(dial phonenum=%s)\n", phonenum);
E 2
#endif
D 2

	pc (STX); pc (lp->rack); pc (lp->modem);
	for (;*string && *string!='<'; string++)
	{
#ifdef DEBUG
	    printf ("%c", *string);
#endif
	    pc(*string);
E 2
I 2
        if (*phonenum == '<' && phonenum[1] == 0)
                return ('Z');
	for (vp = vaconfig; vp->vc_name; vp++)
		if (strcmp(vp->vc_name, acu) == 0)
			break;
	if (vp->vc_name == 0) {
		printf("Unable to locate dialer (%s)\n", acu);
		return ('K');
E 2
	}
D 2
	pc(SI); pc(ETX);

	sleep (1);
	i = read (AC, &c, 1);
E 2
I 2
        ioctl(AC, TIOCGETP, &cntrl);
        cntrl.sg_ispeed = cntrl.sg_ospeed = B2400;
        cntrl.sg_flags = RAW | EVENP | ODDP;
        ioctl(AC, TIOCSETP, &cntrl);
	ioctl(AC, TIOCFLUSH, &two);
        pc(STX);
	pc(vp->vc_rack);
	pc(vp->vc_modem);
	while (*phonenum && *phonenum != '<')
		pc(*phonenum++);
        pc(SI);
	pc(ETX);
        sleep(1);
        i = read(AC, &c, 1);
E 2
#ifdef DEBUG
D 2
	printf ("read response of %d chars, char = %c\n", i, c);
	printf ("and errno is %d\n", errno);
E 2
I 2
        printf("read %d chars, char=%c, errno %d\n", i, c, errno);
E 2
#endif
I 2
        if (i != 1)
		c = 'M';
        if (c == 'B' || c == 'G') {
                char cc, oc = c;
E 2

D 2
	if (i !=1) c = 'M';
	if (c=='B' || c=='G') {
		char oc = c;
		pc(ABORT);
		read (AC, &cc, 1);
E 2
I 2
                pc(ABORT);
                read(AC, &cc, 1);
E 2
#ifdef DEBUG
D 2
		printf ("abort response=%c\n", cc);
E 2
I 2
                printf("abort response=%c\n", cc);
E 2
#endif
D 2
		c = oc;
		v831_disconnect ();
	}

	close(AC);
E 2
I 2
                c = oc;
                v831_disconnect();
        }
        close(AC);
E 2
#ifdef DEBUG
D 2
	printf ("dialit: returns %c\n", c);
E 2
I 2
        printf("dialit: returns %c\n", c);
E 2
#endif
D 2
	return(c);
E 2
I 2
        return (c);
E 2
}
D 2
char *
sanitize(string)
register char *string;
E 2
I 2

static char *
sanitize(s)
	register char *s;
E 2
{
D 2
	static char buf[512];
	register char *cp = buf;
	for(;*string; string++) {
	    switch(*string) {
	    case '0': case '1': case '2': case '3': case '4':
	    case '5': case '6': case '7': case '8': case '9': case '<':
		*cp++ = *string;
		break;
	    case '_':
		*cp++ = '=';
		break;
	    }
E 2
I 2
        static char buf[128];
        register char *cp;

        for (cp = buf; *s; s++) {
		if (!isdigit(*s) && *s == '<' && *s != '_')
			continue;
		if (*s == '_')
			*s = '=';
		*cp++ = *s;
E 2
	}
D 2
	*cp++ = 0;
	return(buf);
E 2
I 2
        *cp++ = 0;
        return (buf);
E 2
}
E 1
