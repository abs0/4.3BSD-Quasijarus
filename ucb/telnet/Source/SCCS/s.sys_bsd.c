h31734
s 00000/00005/00610
d D 1.11 88/03/27 13:51:03 minshall 11 10
c Make it *compile* with -DTN3270.
e
s 00016/00000/00599
d D 1.10 88/03/08 10:30:59 bostic 10 9
c add Berkeley specific copyright
e
s 00016/00020/00583
d D 1.9 88/01/07 11:54:01 minshall 9 8
c Reduce extern's.
e
s 00001/00001/00602
d D 1.8 88/01/07 11:17:08 minshall 8 7
c Fix to not go into loop if tty disappears 
c (from Rick Adams <rick@seismo.css.gov>).
e
s 00003/00002/00600
d D 1.7 87/11/23 20:37:55 minshall 7 6
c Fixes from Dave Borman.
e
s 00002/00014/00600
d D 1.6 87/11/23 11:15:30 minshall 6 5
c Add in some changes from Dave Borman (borman@monet).
e
s 00051/00015/00563
d D 1.5 87/10/27 16:02:41 minshall 5 4
c Reformat somethings; get rid of "unix" comments and ifdefs;
c do some things which used to be done in tn (in command.c).
e
s 00267/00000/00311
d D 1.4 87/10/23 15:15:39 minshall 4 3
c Try to move system dependent stuff to system dependent files.
e
s 00003/00000/00308
d D 1.3 87/10/10 14:27:17 minshall 3 2
c This is the first version to get near rings.  It compiles,
c but doesn't work.
e
s 00007/00000/00301
d D 1.2 87/09/25 14:48:41 minshall 2 1
c Initialize term.*Char.
e
s 00301/00000/00000
d D 1.1 87/09/11 15:40:44 minshall 1 0
c date and time created 87/09/11 15:40:44 by minshall
e
u
U
t
T
I 1
/*
I 10
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

/*
E 10
 * The following routines try to encapsulate what is system dependent
 * (at least between 4.x and dos) which is used in telnet.c.
 */

#if	defined(unix)

#include <sys/ioctl.h>
I 3
#include <sys/types.h>
E 3
#include <sys/time.h>
I 4
#include <sys/socket.h>
E 4
#include <signal.h>
I 4
#include <errno.h>
E 4
I 3

#include "ring.h"
E 3

I 6
#include "fdset.h"

E 6
#include "defines.h"
#include "externs.h"
#include "types.h"
D 6

I 4
#ifndef	FD_SETSIZE
/*
 * The following is defined just in case someone should want to run
 * this telnet on a 4.2 system.
 *
 */

#define	FD_SET(n, p)	((p)->fds_bits[0] |= (1<<(n)))
#define	FD_CLR(n, p)	((p)->fds_bits[0] &= ~(1<<(n)))
#define	FD_ISSET(n, p)	((p)->fds_bits[0] & (1<<(n)))
#define FD_ZERO(p)	((p)->fds_bits[0] = 0)

#endif
E 6

E 4
int
I 4
	tout,			/* Output file descriptor */
	tin,			/* Input file descriptor */
	net,
E 4
	HaveInput;		/* There is input available to scan */

D 11
#if	defined(TN3270)
static char	tline[200];
char	*transcom = 0;	/* transparent mode command (default: none) */
#endif	/* defined(TN3270) */

E 11
static struct	tchars otc = { 0 }, ntc = { 0 };
static struct	ltchars oltc = { 0 }, nltc = { 0 };
static struct	sgttyb ottyb = { 0 }, nttyb = { 0 };

I 4
static fd_set ibits, obits, xbits;
E 4

I 4

init_sys()
{
    tout = fileno(stdout);
    tin = fileno(stdin);
    FD_ZERO(&ibits);
    FD_ZERO(&obits);
    FD_ZERO(&xbits);

    errno = 0;
}


E 4
D 9
TerminalWrite(fd, buf, n)
int	fd;
E 9
I 9
TerminalWrite(buf, n)
E 9
char	*buf;
int	n;
{
D 9
    return write(fd, buf, n);
E 9
I 9
    return write(tout, buf, n);
E 9
}

D 9
TerminalRead(fd, buf, n)
int	fd;
E 9
I 9
TerminalRead(buf, n)
E 9
char	*buf;
int	n;
{
D 9
    return read(fd, buf, n);
E 9
I 9
    return read(tin, buf, n);
E 9
}

/*
 *
 */

int
D 5
TerminalAutoFlush()					/* unix */
E 5
I 5
TerminalAutoFlush()
E 5
{
#if	defined(LNOFLSH)
    int flush;

    ioctl(0, TIOCLGET, (char *)&flush);
    return !(flush&LNOFLSH);	/* if LNOFLSH, no autoflush */
#else	/* LNOFLSH */
    return 1;
#endif	/* LNOFLSH */
}

/*
 * TerminalSpecialChars()
 *
 * Look at an input character to see if it is a special character
 * and decide what to do.
 *
 * Output:
 *
 *	0	Don't add this character.
 *	1	Do add this character
 */

int
D 5
TerminalSpecialChars(c)			/* unix */
E 5
I 5
TerminalSpecialChars(c)
E 5
int	c;
{
D 5
    void doflush(), intp(), sendbrk();
E 5
I 5
    void xmitAO(), xmitEL(), xmitEC(), intp(), sendbrk();
E 5

    if (c == ntc.t_intrc) {
	intp();
	return 0;
    } else if (c == ntc.t_quitc) {
	sendbrk();
	return 0;
    } else if (c == nltc.t_flushc) {
	xmitAO();		/* Transmit Abort Output */
	return 0;
    } else if (!MODE_LOCAL_CHARS(globalmode)) {
	if (c == nttyb.sg_kill) {
	    xmitEL();
	    return 0;
	} else if (c == nttyb.sg_erase) {
	    xmitEC();		/* Transmit Erase Character */
	    return 0;
	}
    }
    return 1;
}


/*
 * Flush output to the terminal
 */
 
void
D 5
TerminalFlushOutput()				/* unix */
E 5
I 5
TerminalFlushOutput()
E 5
{
    (void) ioctl(fileno(stdout), TIOCFLUSH, (char *) 0);
}

void
D 5
TerminalSaveState()				/* unix */
E 5
I 5
TerminalSaveState()
E 5
{
    ioctl(0, TIOCGETP, (char *)&ottyb);
    ioctl(0, TIOCGETC, (char *)&otc);
    ioctl(0, TIOCGLTC, (char *)&oltc);

    ntc = otc;
    nltc = oltc;
    nttyb = ottyb;
I 2

    termEofChar = ntc.t_eofc;
    termEraseChar = nttyb.sg_erase;
    termFlushChar = nltc.t_flushc;
    termIntChar = ntc.t_intrc;
    termKillChar = nttyb.sg_kill;
    termQuitChar = ntc.t_quitc;
E 2
}

void
D 5
TerminalRestoreState()				/* unix */
E 5
I 5
TerminalRestoreState()
E 5
{
}

/*
 * TerminalNewMode - set up terminal to a specific mode.
 */


void
D 5
TerminalNewMode(fd_in, fd_out, f)			/* unix */
E 5
I 5
D 9
TerminalNewMode(fd_in, fd_out, f)
E 5
int	fd_in, fd_out;		/* File descriptor */
E 9
I 9
TerminalNewMode(f)
E 9
register int f;
{
    static int prevmode = 0;
    struct tchars *tc;
    struct tchars tc3;
    struct ltchars *ltc;
    struct sgttyb sb;
    int onoff;
    int old;
    struct	tchars notc2;
    struct	ltchars noltc2;
    static struct	tchars notc =	{ -1, -1, -1, -1, -1, -1 };
    static struct	ltchars noltc =	{ -1, -1, -1, -1, -1, -1 };

    globalmode = f;
    if (prevmode == f)
	return;
    old = prevmode;
    prevmode = f;
    sb = nttyb;

    switch (f) {

    case 0:
	onoff = 0;
	tc = &otc;
	ltc = &oltc;
	break;

    case 1:		/* remote character processing, remote echo */
    case 2:		/* remote character processing, local echo */
    case 6:		/* 3270 mode - like 1, but with xon/xoff local */
		    /* (might be nice to have "6" in telnet also...) */
	    sb.sg_flags |= CBREAK;
	    if ((f == 1) || (f == 6)) {
		sb.sg_flags &= ~(ECHO|CRMOD);
	    } else {
		sb.sg_flags |= ECHO|CRMOD;
	    }
	    sb.sg_erase = sb.sg_kill = -1;
	    if (f == 6) {
		tc = &tc3;
		tc3 = notc;
		    /* get XON, XOFF characters */
		tc3.t_startc = otc.t_startc;
		tc3.t_stopc = otc.t_stopc;
	    } else {
		/*
		 * If user hasn't specified one way or the other,
		 * then default to not trapping signals.
		 */
		if (!donelclchars) {
		    localchars = 0;
		}
		if (localchars) {
		    notc2 = notc;
		    notc2.t_intrc = ntc.t_intrc;
		    notc2.t_quitc = ntc.t_quitc;
		    tc = &notc2;
		} else {
		    tc = &notc;
		}
	    }
	    ltc = &noltc;
	    onoff = 1;
	    break;
    case 3:		/* local character processing, remote echo */
    case 4:		/* local character processing, local echo */
    case 5:		/* local character processing, no echo */
	    sb.sg_flags &= ~CBREAK;
	    sb.sg_flags |= CRMOD;
	    if (f == 4)
		sb.sg_flags |= ECHO;
	    else
		sb.sg_flags &= ~ECHO;
	    notc2 = ntc;
	    tc = &notc2;
	    noltc2 = oltc;
	    ltc = &noltc2;
	    /*
	     * If user hasn't specified one way or the other,
	     * then default to trapping signals.
	     */
	    if (!donelclchars) {
		localchars = 1;
	    }
	    if (localchars) {
		notc2.t_brkc = nltc.t_flushc;
		noltc2.t_flushc = -1;
	    } else {
		notc2.t_intrc = notc2.t_quitc = -1;
	    }
	    noltc2.t_suspc = escape;
	    noltc2.t_dsuspc = -1;
	    onoff = 1;
	    break;

    default:
	    return;
    }
D 9
    ioctl(fd_in, TIOCSLTC, (char *)ltc);
    ioctl(fd_in, TIOCSETC, (char *)tc);
    ioctl(fd_in, TIOCSETP, (char *)&sb);
E 9
I 9
    ioctl(tin, TIOCSLTC, (char *)ltc);
    ioctl(tin, TIOCSETC, (char *)tc);
    ioctl(tin, TIOCSETP, (char *)&sb);
E 9
#if	(!defined(TN3270)) || ((!defined(NOT43)) || defined(PUTCHAR))
D 9
    ioctl(fd_in, FIONBIO, (char *)&onoff);
    ioctl(fd_out, FIONBIO, (char *)&onoff);
E 9
I 9
    ioctl(tin, FIONBIO, (char *)&onoff);
    ioctl(tout, FIONBIO, (char *)&onoff);
E 9
#endif	/* (!defined(TN3270)) || ((!defined(NOT43)) || defined(PUTCHAR)) */
#if	defined(TN3270)
    if (noasynch == 0) {
D 9
	ioctl(fd_in, FIOASYNC, (char *)&onoff);
E 9
I 9
	ioctl(tin, FIOASYNC, (char *)&onoff);
E 9
    }
#endif	/* defined(TN3270) */

    if (MODE_LINE(f)) {
	void doescape();

	signal(SIGTSTP, doescape);
    } else if (MODE_LINE(old)) {
	signal(SIGTSTP, SIG_DFL);
	sigsetmask(sigblock(0) & ~(1<<(SIGTSTP-1)));
    }
}


int
NetClose(net)
int	net;
{
    return close(net);
}


void
D 5
NetNonblockingIO(fd, onoff)				/* unix */
E 5
I 5
NetNonblockingIO(fd, onoff)
E 5
int
	fd,
	onoff;
{
    ioctl(fd, FIONBIO, (char *)&onoff);
}

void
D 5
NetSigIO(fd, onoff)				/* unix */
E 5
I 5
NetSigIO(fd, onoff)
E 5
int
	fd,
	onoff;
{
    ioctl(fd, FIOASYNC, (char *)&onoff);	/* hear about input */
}

void
D 5
NetSetPgrp(fd)				/* unix */
E 5
I 5
NetSetPgrp(fd)
E 5
int fd;
{
    int myPid;

    myPid = getpid();
#if	defined(NOT43)
    myPid = -myPid;
#endif	/* defined(NOT43) */
    ioctl(fd, SIOCSPGRP, (char *)&myPid);	/* set my pid */
}
I 5

/*
 * Various signal handling routines.
 */
E 5

I 5
D 9
void
E 9
I 9
static void
E 9
deadpeer()
{
	setcommandmode();
	longjmp(peerdied, -1);
}
E 5

I 4
D 9
void
E 9
I 9
static void
E 9
I 5
intr()
{
    if (localchars) {
	intp();
	return;
    }
    setcommandmode();
    longjmp(toplevel, -1);
}

D 9
void
E 9
I 9
static void
E 9
intr2()
{
    if (localchars) {
	sendbrk();
	return;
    }
}

D 9
void
E 9
I 9
static void
E 9
doescape()
{
    command(0);
}

void
E 5
sys_telnet_init()
{
D 5
#if	defined(TN3270) && defined(unix)
E 5
I 5
#if	defined(TN3270)
E 5
    int myPid;
#endif	/* defined(TN3270) */

I 5
    signal(SIGINT, intr);
    signal(SIGQUIT, intr2);
    signal(SIGPIPE, deadpeer);

E 5
    setconnmode();

    NetNonblockingIO(net, 1);

#if	defined(TN3270)
    if (noasynch == 0) {			/* DBX can't handle! */
	NetSigIO(net, 1);
	NetSetPgrp(net);
    }
#endif	/* defined(TN3270) */

#if	defined(SO_OOBINLINE)
    SetSockOpt(net, SOL_SOCKET, SO_OOBINLINE, 1);
#endif	/* defined(SO_OOBINLINE) */
}

/*
 * Process rings -
 *
 *	This routine tries to fill up/empty our various rings.
 *
 *	The parameter specifies whether this is a poll operation,
 *	or a block-until-something-happens operation.
 *
 *	The return value is 1 if something happened, 0 if not.
 */

int
process_rings(netin, netout, netex, ttyin, ttyout, poll)
int poll;		/* If 0, then block until something to do */
{
    register int c;
		/* One wants to be a bit careful about setting returnValue
		 * to one, since a one implies we did some useful work,
		 * and therefore probably won't be called to block next
		 * time (TN3270 mode only).
		 */
    int returnValue = 0;
    static struct timeval TimeValue = { 0 };

    if (netout) {
	FD_SET(net, &obits);
    } 
    if (ttyout) {
	FD_SET(tout, &obits);
    }
#if	defined(TN3270)
    if (ttyin) {
	FD_SET(tin, &ibits);
    }
#else	/* defined(TN3270) */
    if (ttyin) {
	FD_SET(tin, &ibits);
    }
#endif	/* defined(TN3270) */
#if	defined(TN3270)
    if (netin) {
	FD_SET(net, &ibits);
    }
#   else /* !defined(TN3270) */
    if (netin) {
	FD_SET(net, &ibits);
    }
#   endif /* !defined(TN3270) */
    if (netex) {
	FD_SET(net, &xbits);
    }
    if ((c = select(16, &ibits, &obits, &xbits,
			(poll == 0)? (struct timeval *)0 : &TimeValue)) < 0) {
	if (c == -1) {
		    /*
		     * we can get EINTR if we are in line mode,
		     * and the user does an escape (TSTP), or
		     * some other signal generator.
		     */
	    if (errno == EINTR) {
		return 0;
	    }
#	    if defined(TN3270)
		    /*
		     * we can get EBADF if we were in transparent
		     * mode, and the transcom process died.
		    */
	    if (errno == EBADF) {
			/*
			 * zero the bits (even though kernel does it)
			 * to make sure we are selecting on the right
			 * ones.
			*/
		FD_ZERO(&ibits);
		FD_ZERO(&obits);
		FD_ZERO(&xbits);
		return 0;
	    }
#	    endif /* defined(TN3270) */
		    /* I don't like this, does it ever happen? */
	    printf("sleep(5) from telnet, after select\r\n");
D 5
#if	defined(unix)
E 5
	    sleep(5);
D 5
#endif	/* defined(unix) */
E 5
	}
	return 0;
    }

    /*
     * Any urgent data?
     */
    if (FD_ISSET(net, &xbits)) {
	FD_CLR(net, &xbits);
	SYNCHing = 1;
	ttyflush(1);	/* flush already enqueued data */
    }

    /*
     * Something to read from the network...
     */
    if (FD_ISSET(net, &ibits)) {
	int canread;

	FD_CLR(net, &ibits);
	canread = ring_empty_consecutive(&netiring);
#if	!defined(SO_OOBINLINE)
	    /*
	     * In 4.2 (and some early 4.3) systems, the
	     * OOB indication and data handling in the kernel
	     * is such that if two separate TCP Urgent requests
	     * come in, one byte of TCP data will be overlaid.
	     * This is fatal for Telnet, but we try to live
	     * with it.
	     *
	     * In addition, in 4.2 (and...), a special protocol
	     * is needed to pick up the TCP Urgent data in
	     * the correct sequence.
	     *
	     * What we do is:  if we think we are in urgent
	     * mode, we look to see if we are "at the mark".
	     * If we are, we do an OOB receive.  If we run
	     * this twice, we will do the OOB receive twice,
	     * but the second will fail, since the second
	     * time we were "at the mark", but there wasn't
	     * any data there (the kernel doesn't reset
	     * "at the mark" until we do a normal read).
	     * Once we've read the OOB data, we go ahead
	     * and do normal reads.
	     *
	     * There is also another problem, which is that
	     * since the OOB byte we read doesn't put us
	     * out of OOB state, and since that byte is most
	     * likely the TELNET DM (data mark), we would
	     * stay in the TELNET SYNCH (SYNCHing) state.
	     * So, clocks to the rescue.  If we've "just"
	     * received a DM, then we test for the
	     * presence of OOB data when the receive OOB
	     * fails (and AFTER we did the normal mode read
	     * to clear "at the mark").
	     */
	if (SYNCHing) {
	    int atmark;

	    ioctl(net, SIOCATMARK, (char *)&atmark);
	    if (atmark) {
		c = recv(net, netiring.supply, canread, MSG_OOB);
		if ((c == -1) && (errno == EINVAL)) {
		    c = recv(net, netiring.supply, canread, 0);
		    if (clocks.didnetreceive < clocks.gotDM) {
			SYNCHing = stilloob(net);
		    }
		}
	    } else {
		c = recv(net, netiring.supply, canread, 0);
	    }
	} else {
	    c = recv(net, netiring.supply, canread, 0);
	}
	settimer(didnetreceive);
#else	/* !defined(SO_OOBINLINE) */
	c = recv(net, netiring.supply, canread, 0);
#endif	/* !defined(SO_OOBINLINE) */
	if (c < 0 && errno == EWOULDBLOCK) {
	    c = 0;
	} else if (c <= 0) {
	    return -1;
	}
	if (netdata) {
	    Dump('<', netiring.supply, c);
	}
D 7
	ring_supplied(&netiring, c);
E 7
I 7
	if (c)
	    ring_supplied(&netiring, c);
E 7
	returnValue = 1;
    }

    /*
     * Something to read from the tty...
     */
    if (FD_ISSET(tin, &ibits)) {
	FD_CLR(tin, &ibits);
D 9
	c = TerminalRead(tin, ttyiring.supply,
			ring_empty_consecutive(&ttyiring));
E 9
I 9
	c = TerminalRead(ttyiring.supply, ring_empty_consecutive(&ttyiring));
E 9
	if (c < 0 && errno == EWOULDBLOCK) {
	    c = 0;
	} else {
D 5
#if	defined(unix)
E 5
	    /* EOF detection for line mode!!!! */
D 8
	    if (c == 0 && MODE_LOCAL_CHARS(globalmode)) {
E 8
I 8
	    if ((c == 0) && MODE_LOCAL_CHARS(globalmode) && isatty(tin)) {
E 8
			/* must be an EOF... */
		*ttyiring.supply = termEofChar;
		c = 1;
	    }
D 5
#endif	/* defined(unix) */
E 5
	    if (c <= 0) {
		return -1;
	    }
I 7
	    ring_supplied(&ttyiring, c);
E 7
	}
D 7
	ring_supplied(&ttyiring, c);
E 7
	returnValue = 1;		/* did something useful */
    }

    if (FD_ISSET(net, &obits)) {
	FD_CLR(net, &obits);
	returnValue |= netflush();
    }
    if (FD_ISSET(tout, &obits)) {
	FD_CLR(tout, &obits);
	returnValue |= ttyflush(SYNCHing|flushout);
    }

    return returnValue;
}
E 4
#endif	/* defined(unix) */
E 1
