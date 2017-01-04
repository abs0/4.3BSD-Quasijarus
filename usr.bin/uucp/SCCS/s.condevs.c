h58990
s 00001/00001/00575
d D 5.20 88/05/04 13:52:03 rick 20 19
c have acucntrl show site called instead of "uucp"
e
s 00012/00004/00564
d D 5.19 88/04/05 12:04:23 rick 19 18
c use syslog for errors, misc minor bug fixes
e
s 00000/00000/00568
d D 5.18 88/02/24 20:50:48 rick 18 17
c update sccsid
e
s 00003/00002/00565
d D 5.17 88/02/24 20:21:44 rick 17 16
c fix bad error message introduced in 4.3bsd
e
s 00003/00004/00564
d D 5.16 88/02/24 19:52:41 rick 16 15
c 
e
s 00004/00000/00564
d D 5.15 86/02/12 17:14:09 bloom 15 14
c New dialer
e
s 00008/00000/00556
d D 5.14 86/01/24 13:18:52 bloom 14 13
c still more fixes and changes from rick@seismo
e
s 00062/00008/00494
d D 5.13 86/01/06 15:01:17 bloom 13 12
c more fixes from rick adams
e
s 00057/00057/00445
d D 5.12 85/10/09 15:38:19 bloom 12 11
c still more fixes from rick@seismo
e
s 00019/00016/00483
d D 5.11 85/06/24 10:21:47 bloom 11 10
c more fixes from rick adams
e
s 00030/00019/00469
d D 5.10 85/06/19 18:11:43 bloom 10 9
c fixes from rick adams
e
s 00180/00066/00308
d D 5.9 85/04/10 15:18:56 ralph 9 8
c more changes from rick adams.
e
s 00144/01332/00230
d D 5.8 85/01/22 14:06:42 ralph 8 7
c bug fixes and changes from Rick Adams
e
s 00087/00007/01475
d D 5.7 84/08/30 16:14:22 ralph 7 6
c added network device NET
e
s 00008/00008/01474
d D 5.6 83/08/12 12:58:54 karels 6 5
c fixed vadic dial routine (needed more delays)
e
s 00001/00001/01481
d D 5.5 83/07/19 11:17:44 gray 5 4
c removed a register declaration so wont core dump on pdp11s
e
s 00002/00001/01480
d D 5.4 83/07/18 08:15:45 gray 4 3
c finish vadic expect() fixes
e
s 00007/00007/01474
d D 5.3 83/07/18 08:07:52 gray 3 2
c some fixes for the vadic dialer - essential!
e
s 00001/00001/01480
d D 5.2 83/07/02 18:24:33 sam 2 1
c include fixes
e
s 01481/00000/00000
d D 5.1 83/07/02 17:56:33 sam 1 0
c date and time created 83/07/02 17:56:33 by sam
e
u
U
t
T
I 1
#ifndef lint
D 19
static char sccsid[] = "%W% (Berkeley) %G%";
E 19
I 19
static char sccsid[] = "%W%	(Berkeley) %G%";
E 19
#endif

I 13
extern int errno;
extern char *sys_errlist[];

E 13
/*
 * Here are various dialers to establish the machine-machine connection.
 * conn.c/condevs.c was glued together by Mike Mitchell.
 * The dialers were supplied by many people, to whom we are grateful.
 *
 * ---------------------------------------------------------------------
 * NOTE:
 * There is a bug that occurs at least on PDP11s due to a limitation of
 * setjmp/longjmp.   If the routine that does a setjmp is interrupted
 * and longjmp-ed to,  it loses its register variables (on a pdp11).
 * What works is if the routine that does the setjmp
 * calls a routine and it is the *subroutine* that is interrupted.
D 8
 * 
E 8
I 8
 *
E 8
 * Anyway, in conclusion, condevs.c is plagued with register variables
 * that are used inside
 * 	if (setjmp(...)) {
 * 		....
 * 	}
D 8
 * 
 * THE FIX: In dnopn(), for example, delete the 'register' Devices *dev.
 * (That was causing a core dump; deleting register fixed it.)
 * Also for dnopn delete 'register' int dnf... .
 * In pkopn, delete 'register' flds... .
 * There may be others, especially mcm's version of hysopen.
 * You could just delete all references to register, that is safest.
 * This problem might not occur on 4.1bsd, I am not sure.
 * 	Tom Truscott
E 8
I 8
 *
 * THE FIX: Don't declare variables to be register
E 8
 */
D 8
#include <sys/types.h>
#include <errno.h>
#include <setjmp.h>
#include <signal.h>
#include <sgtty.h>
#include "uucp.h"
E 8

D 8
extern char devSel[];	/* name to pass to delock() in close */
extern int errno, next_fd;
extern jmp_buf Sjbuf;
extern int alarmtr();
int nulldev(), nodev(), Acuopn(), diropn(), dircls();
E 8
I 8
#include "condevs.h"
E 8

D 8
#ifdef DATAKIT
int dkopn();
#endif
#ifdef DN11
int dnopn(), dncls();
#endif
#ifdef HAYES
int hysopn(), hyscls();
#endif
#ifdef HAYESQ
int hysqopn(), hysqcls();  /* a version of hayes that doesn't use ret codes */
#endif
#ifdef DF02
int df2opn(), df2cls();
#endif
#ifdef PNET
int pnetopn();
#endif
#ifdef VENTEL
int ventopn(), ventcls();
#endif
#ifdef	UNET
#include <UNET/unetio.h>
#include <UNET/tcp.h>
int unetopn(), unetcls();
#endif UNET
I 7
#ifdef TCPNET
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#ifndef	IPPORT_UUCP
#define	IPPORT_UUCP	251
#endif	IPPORT_UUCP
int tcpopn(), tcpcls();
#endif TCPNET
E 7
#ifdef VADIC
int vadopn(), vadcls();
#endif VADIC
#ifdef	RVMACS
int rvmacsopn(), rvmacscls();
#endif
#ifdef MICOM
int micopn(), miccls();
#endif MICOM

E 8
struct condev condevs[] = {
D 8
{ "DIR", "direct", diropn, nulldev, dircls },
E 8
I 8
	{ "DIR", "direct", diropn, nulldev, dircls },
E 8
#ifdef DATAKIT
D 8
{ "DK", "datakit", dkopn, nulldev, nulldev },
#endif
E 8
I 8
	{ "DK", "datakit", dkopn, nulldev, nulldev },
#endif DATAKIT
E 8
#ifdef PNET
D 8
{ "PNET", "pnet", pnetopn, nulldev, nulldev },
#endif
#ifdef	UNET
{ "UNET", "UNET", unetopn, nulldev, unetcls },
#endif UNET
I 7
#ifdef	TCPNET
{ "NET", "tcpnet", tcpopn, nulldev, tcpcls },
#endif TCPNET
E 8
I 8
	{ "PNET", "pnet", pnetopn, nulldev, nulldev },
#endif PNET
#ifdef	UNETTCP
	{ "TCP", "TCP", unetopn, nulldev, unetcls },
#endif UNETTCP
#ifdef BSDTCP
	{ "TCP", "TCP", bsdtcpopn, nulldev, bsdtcpcls },
#endif BSDTCP
E 8
E 7
#ifdef MICOM
D 8
{ "MICOM", "micom", micopn, nulldev, miccls },
E 8
I 8
	{ "MICOM", "micom", micopn, nulldev, miccls },
E 8
#endif MICOM
#ifdef DN11
D 8
{ "ACU", "dn11", Acuopn, dnopn, dncls },
#endif
E 8
I 8
	{ "ACU", "dn11", Acuopn, dnopn, dncls },
#endif DN11
E 8
#ifdef HAYES
D 8
{ "ACU", "hayes", Acuopn, hysopn, hyscls },
E 8
I 8
D 10
	{ "ACU", "hayes", Acuopn, hysopn, hyscls },
E 10
I 10
	{ "ACU", "hayes", Acuopn, hyspopn, hyscls },
	{ "ACU", "hayespulse", Acuopn, hyspopn, hyscls },
	{ "ACU", "hayestone", Acuopn, hystopn, hyscls },
I 12
	{ "WATS", "hayestone", Acuopn, hystopn, hyscls },
E 12
E 10
E 8
#endif HAYES
I 14
#ifdef HAYES2400
	{ "ACU", "hayes2400", Acuopn, hyspopn24, hyscls24 },
	{ "ACU", "hayes2400pulse", Acuopn, hyspopn24, hyscls24 },
	{ "ACU", "hayes2400tone", Acuopn, hystopn24, hyscls24 },
#endif HAYES2400
E 14
#ifdef HAYESQ	/* a version of hayes that doesn't use result codes */
D 8
{ "ACU", "hayesq", Acuopn, hysqopn, hysqcls },
E 8
I 8
D 10
	{ "ACU", "hayesq", Acuopn, hysqopn, hysqcls },
E 8
#endif HATESQ
E 10
I 10
	{ "ACU", "hayesq", Acuopn, hysqpopn, hysqcls },
	{ "ACU", "hayesqpulse", Acuopn, hysqpopn, hysqcls },
	{ "ACU", "hayesqtone", Acuopn, hysqtopn, hysqcls },
#endif HAYESQ
I 14
#ifdef CDS224
	{ "ACU", "cds224", Acuopn, cdsopn224, cdscls224},
#endif CDS224
E 14
E 10
I 8
#ifdef NOVATION
	{ "ACU", "novation", Acuopn, novopn, novcls},
#endif NOVATION
E 8
#ifdef DF02
D 8
{ "ACU", "DF02", Acuopn, df2opn, df2cls },
#endif
E 8
I 8
	{ "ACU", "DF02", Acuopn, df2opn, df2cls },
#endif DF02
I 9
#ifdef DF112
	{ "ACU", "DF112P", Acuopn, df12popn, df12cls },
	{ "ACU", "DF112T", Acuopn, df12topn, df12cls },
#endif DF112
E 9
E 8
#ifdef VENTEL
D 8
{ "ACU", "ventel", Acuopn, ventopn, ventcls },
E 8
I 8
	{ "ACU", "ventel", Acuopn, ventopn, ventcls },
E 8
#endif VENTEL
I 9
#ifdef PENRIL
	{ "ACU", "penril", Acuopn, penopn, pencls },
#endif PENRIL
E 9
#ifdef VADIC
D 8
{ "ACU", "vadic", Acuopn, vadopn, vadcls },
E 8
I 8
	{ "ACU", "vadic", Acuopn, vadopn, vadcls },
E 8
#endif VADIC
I 8
#ifdef VA212
	{ "ACU", "va212", Acuopn, va212opn, va212cls },
#endif VA212
#ifdef VA811S
	{ "ACU", "va811s", Acuopn, va811opn, va811cls },
#endif VA811S
#ifdef VA820
	{ "ACU", "va820", Acuopn, va820opn, va820cls },
	{ "WATS", "va820", Acuopn, va820opn, va820cls },
D 12
	{ "LOCAL", "va820", Acuopn, va820opn, va820cls },
E 12
#endif VA820
E 8
#ifdef RVMACS
D 8
{ "ACU", "rvmacs", Acuopn, rvmacsopn, rvmacscls },
E 8
I 8
	{ "ACU", "rvmacs", Acuopn, rvmacsopn, rvmacscls },
E 8
#endif RVMACS
I 8
#ifdef VMACS
	{ "ACU", "vmacs", Acuopn, vmacsopn, vmacscls },
#endif VMACS
#ifdef SYTEK
	{ "SYTEK", "sytek", sykopn, nulldev, sykcls },
#endif SYTEK
I 15
#ifdef ATT2224
	{ "ACU", "att", Acuopn, attopn, attcls },	
#endif ATT2224

E 15
E 8

D 8
/* Insert new entries before this line */
{ NULL, NULL, NULL, NULL, NULL } };
E 8
I 8
	/* Insert new entries before this line */
	{ NULL, NULL, NULL, NULL, NULL }
};
E 8

D 8
/***
E 8
I 8
/*
E 8
 *	nulldev		a null device (returns CF_DIAL)
 */
D 8
int nulldev()
E 8
I 8
nulldev()
E 8
{
D 8
	return(CF_DIAL);
E 8
I 8
	return CF_DIAL;
E 8
}

D 8
/***
E 8
I 8
/*
E 8
 *	nodev		a null device (returns CF_NODEV)
 */
D 8
int nodev()
E 8
I 8
nodev()
E 8
{
D 8
	return(CF_NODEV);
E 8
I 8
	return CF_NODEV;
E 8
}

D 8

E 8
/*
D 8
 * The first things in this file are the generic devices. 
E 8
 * Generic devices look through L-devices and call the CU_open routines for
D 8
 * appropriate devices.  Some things, like the Unet interface, or direct
 * connect, do not use the CU_open entry.  ACUs must search to find the'
E 8
I 8
 * appropriate devices.  Some things, like the tcp/ip interface, or direct
 * connect, do not use the CU_open entry.  ACUs must search to find the
E 8
 * right routine to call.
 */

D 8
/***
E 8
I 8
/*
E 8
 *	diropn(flds)	connect to hardware line
D 8
 *	char *flds[];
E 8
 *
 *	return codes:
D 8
 *		>0  -  file number  -  ok
E 8
I 8
 *		> 0  -  file number  -  ok
E 8
 *		FAIL  -  failed
 */
D 8

E 8
diropn(flds)
register char *flds[];
{
	register int dcr, status;
	struct Devices dev;
	char dcname[20];
	FILE *dfp;
I 8
#ifdef VMSDTR	/* Modem control on vms(works dtr) */
	int modem_control;
	short iosb[4]; 
	int sys$qiow();	/* use this for long reads on vms */
	int ret;
	long mode[2];
	modem_control = 0;
#endif
E 8
	dfp = fopen(DEVFILE, "r");
D 19
	ASSERT(dfp != NULL, "CAN'T OPEN", DEVFILE, 0);
E 19
I 19
	if (dfp == NULL) {
		syslog(LOG_ERR, "fopen(%s) failed: %m", DEVFILE);
		cleanup(FAIL);
	}
E 19
	while ((status = rddev(dfp, &dev)) != FAIL) {
I 8
#ifdef VMSDTR	/* Modem control on vms(works dtr) */
		/* If we find MOD in the device type field we go into action */
		if (strcmp(dev.D_type, "MOD") == SAME) {
			modem_control = 1;
		        DEBUG(7, "Setting Modem control to %d",modem_control);
		}
E 8
		if (strcmp(flds[F_CLASS], dev.D_class) != SAME)
I 8
				continue;
		/*
		 * Modem control on vms(works dtr) Take anything in MOD class.
	  	 * It probably should work differently anyway so we can have
		 *  multiple hardwired lines.
		 */
		if (!modem_control&&strcmp(flds[F_PHONE], dev.D_line) != SAME)
#else !VMSDTR
		if (strcmp(flds[F_CLASS], dev.D_class) != SAME)
E 8
			continue;
		if (strcmp(flds[F_PHONE], dev.D_line) != SAME)
I 8
#endif !VMSDTR
E 8
			continue;
		if (mlock(dev.D_line) != FAIL)
			break;
	}
	fclose(dfp);
	if (status == FAIL) {
		logent("DEVICE", "NO");
D 8
		return(CF_NODEV);
E 8
I 8
		return CF_NODEV;
E 8
	}

	sprintf(dcname, "/dev/%s", dev.D_line);
	if (setjmp(Sjbuf)) {
I 13
		DEBUG(4, "Open timed out\n", CNULL);
E 13
		delock(dev.D_line);
D 8
		return(FAIL);
E 8
I 8
		return CF_DIAL;
E 8
	}
	signal(SIGALRM, alarmtr);
D 13
	alarm(10);
E 13
I 13
	/* For PC Pursuit, it could take a while to call back */
	alarm( strcmp(flds[F_LINE], "PCP") ? 10 : MAXMSGTIME*4 );
E 13
	getnextfd();
	errno = 0;
I 8
D 13
        DEBUG(4,"Opening %s",dcname);
E 13
I 13
        DEBUG(4,"Opening %s\n",dcname);
E 13
E 8
	dcr = open(dcname, 2); /* read/write */
I 8
#ifdef VMSDTR	/* Modem control on vms(works dtr) */
	fflush(stdout);
	if (modem_control) { /* Did we have MOD in the device type field ? */
		/* Sense the current terminal setup and save it */
		if ((ret = sys$qiow(_$EFN,(fd_fab_pointer[dcr]->fab).fab$l_stv,
			IO$_SENSEMODE,iosb,0,0,mode,8,0,0,0,0))
				!= SS$_NORMAL) {
			DEBUG(7, "ret status on sense failed on Modem sense=%x<", ret);
			return CF_DIAL;
		}
		mode[1] |= TT$M_MODEM; /* Or in modem control(DTR) */
		/* Now set the new terminal characteristics */
		/* This is temporary and will go away when we let go of it */
		if ((ret = sys$qiow(_$EFN,(fd_fab_pointer[dcr]->fab).fab$l_stv,
			IO$_SETMODE,iosb,0,0,mode,8,0,0,0,0))
				!= SS$_NORMAL) {
			DEBUG(7, "ret status on sense failed on Modem setup=%x<", ret);
			return CF_DIAL;
		}
	}
#endif VMSDTR
E 8
	next_fd = -1;
D 13
	if (dcr < 0 && errno == EACCES)
		logent(dcname, "CAN'T OPEN");
E 13
	alarm(0);
	if (dcr < 0) {
I 13
		if (errno == EACCES)
			logent(dev.D_line, "CANT OPEN");
		DEBUG(4, "OPEN FAILED: errno %d\n", errno);
E 13
		delock(dev.D_line);
D 8
		return(FAIL);
E 8
I 8
		return CF_DIAL;
E 8
	}
	fflush(stdout);
D 10
	fixline(dcr, dev.D_speed);
E 10
I 10
D 13
	if (fixline(dcr, dev.D_speed) == FAIL)
E 13
I 13
	if (fixline(dcr, dev.D_speed) == FAIL) {
		DEBUG(4, "FIXLINE FAILED\n", CNULL);
E 13
		return CF_DIAL;
I 13
	}
E 13
E 10
	strcpy(devSel, dev.D_line);	/* for latter unlock */
	CU_end = dircls;
D 8
	return(dcr);
E 8
I 8
	return dcr;
E 8
}

dircls(fd)
register int fd;
{
	if (fd > 0) {
		close(fd);
		delock(devSel);
D 8
		}
E 8
	}
D 8

#ifdef DATAKIT

#include <dk.h>
#define DKTRIES 2

/***
 *	dkopn(flds)	make datakit connection
 *
 *	return codes:
 *		>0 - file number - ok
 *		FAIL - failed
 */

dkopn(flds)
char *flds[];
{
	int dkphone;
	register char *cp;
	register ret, i;

	if (setjmp(Sjbuf))
		return(FAIL);

	signal(SIGALRM, alarmtr);
	dkphone = 0;
	cp = flds[F_PHONE];
	while(*cp)
		dkphone = 10 * dkphone + (*cp++ - '0');
	DEBUG(4, "dkphone (%d) ", dkphone);
	for (i = 0; i < DKTRIES; i++) {
		getnextfd();
		ret = dkdial(D_SH, dkphone, 0);
		next_fd = -1;
		DEBUG(4, "dkdial (%d)\n", ret);
		if (ret > -1)
			break;
	}
	return(ret);
E 8
}
D 8
#endif
E 8

D 8
#ifdef PNET
E 8
D 9
/***
D 8
 *	pnetopn(flds)
 *
 *	call remote machine via Purdue network
 *	use dial string as host name, speed as socket number
 * Author: Steve Bellovin
 */

pnetopn(flds)
char *flds[];
{
	int fd;
	int socket;
	register char *cp;

	fd = pnetfile();
	DEBUG(4, "pnet fd - %d\n", fd);
	if (fd < 0) {
		logent("AVAILABLE DEVICE", "NO");
		return(CF_NODEV);
	}
	socket = 0;
	for (cp = flds[F_CLASS]; *cp; cp++)
		socket = 10*socket + (*cp - '0');
	DEBUG(4, "socket - %d\n", socket);
	if (setjmp(Sjbuf)) {
		DEBUG(4, "pnet timeout  - %s\n", flds[F_PHONE]);
		return(FAIL);
	}
	signal(SIGALRM, alarmtr);
	DEBUG(4, "host - %s\n", flds[F_PHONE]);
	alarm(15);
	if (pnetscon(fd, flds[F_PHONE], socket) < 0) {
		DEBUG(4, "pnet connect failed - %s\n", flds[F_PHONE]);
		return(FAIL);
	}
	alarm(0);
	return(fd);
}
#endif	PNET

#ifdef UNET
/***
 *	unetopn -- make UNET (tcp-ip) connection
 *
 *	return codes:
 *		>0 - file number - ok
 *		FAIL - failed
 */

/* Default port of uucico server */
#define	DFLTPORT	33

unetopn(flds)
register char *flds[];
{
	register int ret, port;
	int unetcls();

	port = atoi(flds[F_PHONE]);
	if (port <= 0 || port > 255)
		port = DFLTPORT;
	DEBUG(4, "unetopn host %s, ", flds[F_NAME]);
	DEBUG(4, "port %d\n", port);
	if (setjmp(Sjbuf)) {
		logent("tcpopen", "TIMEOUT");
		endhnent();	/* see below */
		return(CF_DIAL);
	}
	signal(SIGALRM, alarmtr);
	alarm(30);
	ret = tcpopen(flds[F_NAME], port, 0, TO_ACTIVE, "rw");
	alarm(0);
	endhnent();	/* wave magic wand at 3com and incant "eat it, bruce" */
	if (ret < 0) {
		DEBUG(5, "tcpopen failed: errno %d\n", errno);
		logent("tcpopen", "FAILED");
		return(CF_DIAL);
	}
	CU_end = unetcls;
	return(ret);
}

/*
 * unetcls -- close UNET connection.
 */
unetcls(fd)
register int fd;
{
	DEBUG(4, "UNET CLOSE called\n", 0);
	if (fd > 0) {
		/* disable this until a timeout is put in
		if (ioctl(fd, UIOCCLOSE, STBNULL))
			logent("UNET CLOSE", "FAILED");
		 */
		close(fd);
		DEBUG(4, "closed fd %d\n", fd);
	}
}
#endif UNET

I 7
#ifdef	TCPNET
/***
 *	tcpopn - establish a network connection to the remote system
 *
 *	return codes:
 *		>= 0	file descriptor for remote connection
 *		FAIL	unable to establish remote connection
 */

tcpopn(flds)
char	*flds[];
{
	register struct hostent	*hp;
	struct sockaddr_in	hisaddr;
	int		nfd, port;
	extern int	errno;
	int  tcpcls();

	hp = gethostbyname(flds[F_NAME]);
	if (hp == NULL) {
		DEBUG(4, "netcall: Unknown host (%s)\n", flds[F_NAME]);
		logent(flds[F_NAME], "Unknown Host");
		return FAIL;
	}
	port = atoi(flds[F_PHONE]);
	if (port == 0)
		port = IPPORT_UUCP;
	bzero((char *)&hisaddr, sizeof(hisaddr));
	bcopy(hp->h_addr, (char *)&hisaddr.sin_addr, hp->h_length);
	hisaddr.sin_family = hp->h_addrtype;
	hisaddr.sin_port = htons(port);
	DEBUG(4, "Connect to %s ", hp->h_name);
	DEBUG(4, "port %d... ", port);
	nfd = socket(hp->h_addrtype, SOCK_STREAM, 0);
	if (nfd < 0) {
		DEBUG(4, "failed, no local sockets (%d)\n", errno);
		return FAIL;
	}
	if (connect(nfd, (char *)&hisaddr, sizeof(hisaddr)) < 0) {
		DEBUG(4, "failed, connect error (%d)\n", errno);
		return FAIL;
	}
	DEBUG(4, "succeeded\n", 0);
	CU_end = tcpcls;
	return nfd;
}

/*
 * tcpcls -- close TCP connection.
 */
tcpcls(fd)
register int fd;
{
	DEBUG(4, "TCP CLOSE called\n", 0);
	if (fd > 0) {
		/* disable this until a timeout is put in
		if (ioctl(fd, UIOCCLOSE, STBNULL))
			logent("TCP CLOSE", "FAILED");
		 */
		close(fd);
		DEBUG(4, "closed fd %d\n", fd);
	}
}
#endif	TCPNET

E 7
#ifdef MICOM

/*
 *	micopn: establish connection through a micom.
 *	Returns descriptor open to tty for reading and writing.
 *	Negative values (-1...-7) denote errors in connmsg.
 *	Be sure to disconnect tty when done, via HUPCL or stty 0.
 */
micopn(flds)
register char *flds[];
{
	extern errno;
	char *rindex(), *fdig(), dcname[20];
	int dh, ok = 0, speed;
	register struct condev *cd;
	register FILE *dfp;
	struct Devices dev;

	dfp = fopen(DEVFILE, "r");
	ASSERT(dfp != NULL, "Can't open", DEVFILE, 0);

	signal(SIGALRM, alarmtr);
	dh = -1;
	for(cd = condevs; ((cd->CU_meth != NULL)&&(dh < 0)); cd++) {
		if (snccmp(flds[F_LINE], cd->CU_meth) == SAME) {
			fseek(dfp, (off_t)0, 0);
			while(rddev(dfp, &dev) != FAIL) {
				if (strcmp(flds[F_CLASS], dev.D_class) != SAME)
					continue;
				if (snccmp(flds[F_LINE], dev.D_type) != SAME)
					continue;
				if (mlock(dev.D_line) == FAIL)
					continue;

				sprintf(dcname, "/dev/%s", dev.D_line);
				getnextfd();
				alarm(10);
				if (setjmp(Sjbuf)) {
					delock(dev.D_line);
					logent(dev.D_line,"micom open TIMEOUT");
					dh = -1;
					break;
					}
				dh = open(dcname, 2);
				alarm(0);
				next_fd = -1;
				if (dh > 0) {
					break;
					}
				devSel[0] = '\0';
				delock(dev.D_line);
				}
			}
		}
	fclose(dfp);
	if (dh < 0)
		return(CF_NODEV);

	speed = atoi(fdig(flds[F_CLASS]));
	fixline(dh, speed);
	sleep(1);

	/* negotiate with micom */
	if (speed != 4800)	/* damn their eyes! */
		write(dh, "\r", 1);
	else
		write(dh, " ", 1);
		
	DEBUG(4, "wanted %s ", "NAME");
	ok = expect("NAME", dh);
	DEBUG(4, "got %s\n", ok ? "?" : "that");
	if (ok == 0) {
		write(dh, flds[F_PHONE], strlen(flds[F_PHONE]));
		sleep(1);
		write(dh, "\r", 1);
		DEBUG(4, "wanted %s ", "GO");
		ok = expect("GO", dh);
		DEBUG(4, "got %s\n", ok ? "?" : "that");
	}

	if (ok != 0) {
		if (dh > 2)
			close(dh);
		DEBUG(4, "micom failed\n", "");
		delock(dev.D_line);
		return(CF_DIAL);
	} else
		DEBUG(4, "micom ok\n", "");

	CU_end = cd->CU_clos;
	strcat(devSel, dev.D_line);	/* for later unlock */
	return(dh);

}

miccls(fd)
register int fd;
{

	if (fd > 0) {
		close(fd);
		delock(devSel);
		}
	}
#endif MICOM

/***
E 8
 *	Acuopn - open an ACU and dial the number.  The condevs table
 *		will be searched until a dialing unit is found that is
 *		free.
E 9
I 9
/*
 *	open an ACU and dial the number.  The condevs table
 *	will be searched until a dialing unit is found that is free.
E 9
 *
 *	return codes:	>0 - file number - o.k.
 *			FAIL - failed
 */
D 8

E 8
char devSel[20];	/* used for later unlock() */

Acuopn(flds)
register char *flds[];
{
D 9
    char phone[MAXPH+1];
    register struct condev *cd;
D 8
    register int fd;
E 8
I 8
    register int fd, acustatus;
E 8
    register FILE *dfp;
    struct Devices dev;
I 8
    int retval = CF_NODEV;
E 9
I 9
	char phone[MAXPH+1];
	register struct condev *cd;
	register int fd, acustatus;
	register FILE *dfp;
	struct Devices dev;
	int retval = CF_NODEV;
I 11
D 12
	char nobrand[MAXPH];
E 12
I 12
	char nobrand[MAXPH], *line;
E 12
E 11
E 9
E 8

D 9
    exphone(flds[F_PHONE], phone);
    devSel[0] = '\0';
    DEBUG(4, "Dialing %s\n", phone);
    dfp = fopen(DEVFILE, "r");
    ASSERT(dfp != NULL, "Can't open", DEVFILE, 0);
E 9
I 9
	exphone(flds[F_PHONE], phone);
I 12
	if (snccmp(flds[F_LINE], "LOCAL") == SAME)
		line = "ACU";
	else
		line = flds[F_LINE];
E 12
	devSel[0] = '\0';
I 11
	nobrand[0] = '\0';
E 11
	DEBUG(4, "Dialing %s\n", phone);
	dfp = fopen(DEVFILE, "r");
D 19
	ASSERT(dfp != NULL, "Can't open", DEVFILE, 0);
E 19
I 19
	if (dfp == NULL) {
		syslog(LOG_ERR, "fopen(%s) failed: %m", DEVFILE);
		cleanup(FAIL);
	}
E 19
E 9

I 8
D 9
    acustatus = 0;	/* none found, none locked */
E 8
    for(cd = condevs; cd->CU_meth != NULL; cd++) {
	if (snccmp(flds[F_LINE], cd->CU_meth) == SAME) {
D 8
	    fseek(dfp, (off_t)0, 0);
E 8
I 8
	    rewind(dfp);
E 8
	    while(rddev(dfp, &dev) != FAIL) {
I 8
		/*
		 * for each ACU L.sys line, try at most twice
		 * (TRYCALLS) to establish carrier.  The old way tried every
		 * available dialer, which on big sites takes forever!
		 * Sites with a single auto-dialer get one try.
		 * Sites with multiple dialers get a try on each of two
		 * different dialers.
		 * To try 'harder' to connect to a remote site,
		 * use multiple L.sys entries.
		 */
		if (acustatus > TRYCALLS)
			continue;
E 8
		if (strcmp(flds[F_CLASS], dev.D_class) != SAME)
		    continue;
		if (snccmp(flds[F_LINE], dev.D_type) != SAME)
		    continue;
		if (dev.D_brand[0] == '\0')
		    logent("Acuopn","No 'brand' name on ACU");
		else if (snccmp(dev.D_brand, cd->CU_brand) != SAME)
		    continue;
I 8
		if (acustatus < 1)
			acustatus = 1;	/* has been found */
E 8
		if (mlock(dev.D_line) == FAIL)
		    continue;
E 9
I 9
	acustatus = 0;	/* none found, none locked */
D 12
	for(cd = condevs; cd->CU_meth != NULL; cd++) {
		if (snccmp(flds[F_LINE], cd->CU_meth) == SAME) {
			rewind(dfp);
			while(rddev(dfp, &dev) != FAIL) {
			/*
			 * for each ACU L.sys line, try at most twice
			 * (TRYCALLS) to establish carrier.  The old way tried every
			 * available dialer, which on big sites takes forever!
			 * Sites with a single auto-dialer get one try.
			 * Sites with multiple dialers get a try on each of two
			 * different dialers.
			 * To try 'harder' to connect to a remote site,
			 * use multiple L.sys entries.
			 */
			if (acustatus > TRYCALLS)
				continue;
			if (strcmp(flds[F_CLASS], dev.D_class) != SAME)
				continue;
			if (snccmp(flds[F_LINE], dev.D_type) != SAME)
				continue;
			if (dev.D_brand[0] == '\0') {
				logent("Acuopn","No 'brand' name on ACU");
				continue;
			}
D 11
			for(cd = condevs; cd->CU_meth != NULL; cd++) {
				if (snccmp(flds[F_LINE], cd->CU_meth) == SAME
					&& snccmp(dev.D_brand, cd->CU_brand) == SAME)
					break;
			}
			if (cd->CU_meth == NULL) {
				logent(dev.D_brand,"unsupported ACU type");
E 11
I 11
			if (snccmp(dev.D_brand, cd->CU_brand) != SAME) {
E 12
I 12
	while (rddev(dfp, &dev) != FAIL) {
		/*
		 * for each ACU L.sys line, try at most twice
		 * (TRYCALLS) to establish carrier.  The old way tried every
		 * available dialer, which on big sites takes forever!
		 * Sites with a single auto-dialer get one try.
		 * Sites with multiple dialers get a try on each of two
		 * different dialers.
		 * To try 'harder' to connect to a remote site,
		 * use multiple L.sys entries.
		 */
		if (acustatus > TRYCALLS)
			break;
		if (strcmp(flds[F_CLASS], dev.D_class) != SAME)
			continue;
		if (snccmp(line, dev.D_type) != SAME)
			continue;
		if (dev.D_brand[0] == '\0') {
			logent("Acuopn","No 'brand' name on ACU");
			continue;
		}
		for(cd = condevs; cd->CU_meth != NULL; cd++) {
			if (snccmp(line, cd->CU_meth) == SAME) {
D 19
				if (snccmp(dev.D_brand, cd->CU_brand) == SAME) 
E 19
I 19
				if (snccmp(dev.D_brand, cd->CU_brand) == SAME) {
					nobrand[0] = '\0';
E 19
					break;
I 19
				}
E 19
E 12
				strncpy(nobrand, dev.D_brand, sizeof nobrand);
E 11
D 12
				continue;
E 12
			}
I 12
		}
E 12
E 9

I 17
		if (acustatus < 1)
			acustatus = 1;	/* has been found */

E 17
D 9
		DEBUG(4, "Using %s\n", cd->CU_brand);
I 8
		acustatus++;
E 8
		fd = (*(cd->CU_open))(phone, flds, &dev);
		if (fd > 0) {
		    CU_end = cd->CU_clos;   /* point CU_end at close func */
		    fclose(dfp);
		    strcpy(devSel, dev.D_line);   /* save for later unlock() */
D 8
		    return(fd);
E 8
I 8
		    return fd;
E 8
		    }
		delock(dev.D_line);
I 8
		retval = CF_DIAL;
E 9
I 9
D 11
			if (acustatus < 1)
				acustatus = 1;	/* has been found */
E 11
D 10
			if (mlock(dev.D_line) == FAIL)
E 10
I 10
D 12
			if (mlock(dev.D_line) == FAIL) {
				acustatus++;
E 10
				continue;
I 10
			}
I 11
			if (acustatus < 1)
				acustatus = 1;	/* has been found */
E 12
I 12
D 16
		if (mlock(dev.D_line) == FAIL) {
			acustatus++;
E 16
I 16
		if (mlock(dev.D_line) == FAIL)
E 16
			continue;
D 16
		}
E 16
I 16

E 16
D 17
		if (acustatus < 1)
			acustatus = 1;	/* has been found */
E 17
E 12
E 11
E 10
#ifdef DIALINOUT
D 10
			if (snccmp("inout", dev.D_calldev) == SAME
				&& disable(dev.D_line) == FAIL) {
E 10
I 10
#ifdef ALLACUINOUT
D 11
			if (
E 11
I 11
D 12
			if (1) {
E 12
I 12
		if (1) {
E 12
E 11
#else !ALLACUINOUT
D 11
			if (snccmp("inout", dev.D_calldev) == SAME &&
E 11
I 11
D 12
			if (snccmp("inout", dev.D_calldev) == SAME) {
E 12
I 12
		if (snccmp("inout", dev.D_calldev) == SAME) {
E 12
E 11
#endif !ALLACUINOUT
D 11
				disable(dev.D_line) == FAIL) {
E 11
I 11
D 12
				if (disable(dev.D_line) == FAIL) {
E 11
E 10
					delock(dev.D_line);
					continue;
D 11
			}
E 11
I 11
				}
			}  else
				reenable();
E 11
#endif DIALINOUT

			DEBUG(4, "Using %s\n", cd->CU_brand);
			acustatus++;
			fd = (*(cd->CU_open))(phone, flds, &dev);
			if (fd > 0) {
				CU_end = cd->CU_clos;   /* point CU_end at close func */
				fclose(dfp);
				strcpy(devSel, dev.D_line);   /* save for later unlock() */
				return fd;
			} else
E 12
I 12
			if (disable(dev.D_line) == FAIL) {
E 12
				delock(dev.D_line);
D 12
			retval = CF_DIAL;
E 12
I 12
				continue;
E 12
			}
E 9
E 8
D 12
		}
E 12
I 12
		}  else
			reenable();
#endif DIALINOUT

		DEBUG(4, "Using %s\n", cd->CU_brand);
		acustatus++;
		fd = (*(cd->CU_open))(phone, flds, &dev);
		if (fd > 0) {
			CU_end = cd->CU_clos;   /* point CU_end at close func */
			fclose(dfp);
			strcpy(devSel, dev.D_line);   /* save for later unlock() */
			return fd;
		} else
			delock(dev.D_line);
		retval = CF_DIAL;
E 12
D 9
	    }
E 9
	}
D 9
    fclose(dfp);
D 8
    return(FAIL);
    }

#ifdef DN11

/***
 *	dnopn(ph, flds, dev)	dial remote machine
 *	char *ph;
 *	char *flds[];
 *	struct Devices *dev;
 *
 *	return codes:
 *		file descriptor  -  succeeded
 *		FAIL  -  failed
 */

dnopn(ph, flds, dev)
char *ph;
char *flds[];
struct Devices *dev;
{
	char dcname[20], dnname[20], phone[MAXPH+2], c = 0;
#ifdef	SYSIII
	struct termio ttbuf;
#endif
	int dnf, dcf;
	int nw, lt, pid, status;
	unsigned timelim;

	sprintf(dnname, "/dev/%s", dev->D_calldev);
	errno = 0;
	
	if (setjmp(Sjbuf)) {
		logent(dnname, "CAN'T OPEN");
		DEBUG(4, "%s Open timed out\n", dnname);
		return(CF_NODEV);
	}
	signal(SIGALRM, alarmtr);
	getnextfd();
	alarm(10);
	dnf = open(dnname, 1);
	alarm(0);
	next_fd = -1;
	if (dnf < 0 && errno == EACCES) {
		logent(dnname, "CAN'T OPEN");
		logent("DEVICE", "NO");
		return(CF_NODEV);
		}
	/* rti!trt: avoid passing acu file descriptor to children */
	fioclex(dnf);

	sprintf(dcname, "/dev/%s", dev->D_line);
	sprintf(phone, "%s%s", ph, ACULAST);
	DEBUG(4, "dc - %s, ", dcname);
	DEBUG(4, "acu - %s\n", dnname);
	pid = 0;
	if (setjmp(Sjbuf)) {
		logent("DIALUP DN write", "TIMEOUT");
		if (pid)
			kill(pid, 9);
		delock(dev->D_line);
		if (dnf)
			close(dnf);
		return(FAIL);
	}
	signal(SIGALRM, alarmtr);
	timelim = 5 * strlen(phone);
	alarm(timelim < 30 ? 30 : timelim);
	if ((pid = fork()) == 0) {
		sleep(2);
		fclose(stdin);
		fclose(stdout);
#ifdef	TIOCFLUSH
		ioctl(dnf, TIOCFLUSH, STBNULL);
#endif
		nw = write(dnf, phone, lt = strlen(phone));
		if (nw != lt) {
			logent("DIALUP ACU write", "FAILED");
			exit(1);
		}
		DEBUG(4, "ACU write ok%s\n", "");
		exit(0);
	}
	/*  open line - will return on carrier */
	/* RT needs a sleep here because it returns immediately from open */

#if RT
	sleep(15);
#endif

	getnextfd();
	errno = 0;
	dcf = open(dcname, 2);
	next_fd = -1;
	if (dcf < 0 && errno == EACCES)
		logent(dcname, "CAN'T OPEN");
	DEBUG(4, "dcf is %d\n", dcf);
	if (dcf < 0) {
		logent("DIALUP LINE open", "FAILED");
		alarm(0);
		kill(pid, 9);
		close(dnf);
		delock(dev->D_line);
		return(FAIL);
	}
	/* brl-bmd.351 (Doug Kingston) says the next ioctl is unneeded . */
/*	ioctl(dcf, TIOCHPCL, STBNULL);*/
	while ((nw = wait(&lt)) != pid && nw != -1)
		;
#ifdef	SYSIII
	ioctl(dcf, TCGETA, &ttbuf);
	if(!(ttbuf.c_cflag & HUPCL)) {
		ttbuf.c_cflag |= HUPCL;
		ioctl(dcf, TCSETA, &ttbuf);
	}
#endif
	alarm(0);
	fflush(stdout);
	fixline(dcf, dev->D_speed);
	DEBUG(4, "Fork Stat %o\n", lt);
	if (lt != 0) {
		close(dcf);
		if (dnf)
			close(dnf);
		delock(dev->D_line);
		return(FAIL);
	}
	return(dcf);
E 8
I 8
    if (acustatus == 0)
	logent("L-devices", "No appropriate ACU");
    if (acustatus == 1)
	logent("DEVICE", "NO");
    return retval;
E 9
I 9
	fclose(dfp);
D 11
	if (acustatus == 0)
		logent("L-devices", "No appropriate ACU");
E 11
I 11
	if (acustatus == 0) {
		if (nobrand[0])
			logent(nobrand, "unsupported ACU type");
		else
			logent("L-devices", "No appropriate ACU");
	}
E 11
	if (acustatus == 1)
		logent("DEVICE", "NO");
	return retval;
E 9
E 8
}

D 8
/***
 *	dncls()		close dn type call unit
 *
 *	return codes:	None
 */
dncls(fd)
register int fd;
{
	if (fd > 0) {
		close(fd);
		sleep(5);
		delock(devSel);
		}
}
#endif DN11

#ifdef DF02
/***
 *	df2opn(ph, flds, dev)	dial remote machine
 *	char *ph;
 *	char *flds[];
 *	struct Devices *dev;
 *
 *	return codes:
 *		file descriptor  -  succeeded
 *		FAIL  -  failed
 *
 *	Modified 9/28/81 by Bill Shannon (DEC)
 *	Changed to use DEC DF02 or DF03 ACU
 */


df2opn(ph, flds, dev)
char *ph;
char *flds[];
struct Devices *dev;
{
	char dcname[20], dnname[20], phone[MAXPH+2], c = 0;
#ifdef	SYSIII
	struct termio ttbuf;
#endif
	int dcf, dnf;
	int nw, lt, pid, st, status;
	unsigned timelim;

	sprintf(dnname, "/dev/%s", dev->D_calldev);
	if (setjmp(Sjbuf)) {
		logent(dnname, "CAN'T OPEN");
		DEBUG(4, "%s Open timed out\n", dnname);
		return(CF_NODEV);
	}
	signal(SIGALRM, alarmtr);
	getnextfd();
	errno = 0;
	alarm(10);
	dnf = open(dnname, 2 );
	alarm(0);
	next_fd = -1;
	if (dnf < 0 && errno == EACCES) {
		logent(dnname, "CAN'T OPEN");
		delock(dev->D_line);
		logent("DEVICE", "NO");
		return(CF_NODEV);
		}
	/* rti!trt: avoid passing acu file descriptor to children */
	fioclex(dnf);

	sprintf(dcname, "/dev/%s", dev->D_line);
	fixline(dnf, dev->D_speed);
	sprintf(phone, "\02%s", ph);
	DEBUG(4, "dc - %s, ", dcname);
	DEBUG(4, "acu - %s\n", dnname);
	pid = 0;
	if (setjmp(Sjbuf)) {
		logent("DIALUP DN write", "TIMEOUT");
		if (pid)
			kill(pid, 9);
		delock(dev->D_line);
		if (dnf)
			close(dnf);
		return(FAIL);
	}
	signal(SIGALRM, alarmtr);
	timelim = 5 * strlen(phone);
	alarm(timelim < 30 ? 30 : timelim);
	if ((pid = fork()) == 0) {
		sleep(2);
		fclose(stdin);
		fclose(stdout);
#ifdef	TIOCFLUSH
		ioctl(dnf, TIOCFLUSH, STBNULL);
#endif
		write(dnf, "\01", 1);
		sleep(1);
		nw = write(dnf, phone, lt = strlen(phone));
		if (nw != lt) {
			logent("DIALUP ACU write", "FAILED");
			exit(1);
		}
		DEBUG(4, "ACU write ok%s\n", "");
		exit(0);
	}
	/*  open line - will return on carrier */
	/* RT needs a sleep here because it returns immediately from open */

#if RT
	sleep(15);
#endif

	if (read(dnf, &c, 1) != 1 || c != 'A')
		dcf = -1;
	else
		dcf = 0;
	DEBUG(4, "dcf is %d\n", dcf);
	if (dcf < 0) {
		logent("DIALUP LINE open", "FAILED");
		alarm(0);
		kill(pid, 9);
		close(dnf);
		delock(dev->D_line);
		return(FAIL);
	}
	dcf = dnf;
	dnf = 0;
	/* brl-bmd.351 (Doug Kingston) says the next ioctl is unneeded . */
/*	ioctl(dcf, TIOCHPCL, STBNULL);*/
	while ((nw = wait(&lt)) != pid && nw != -1)
		;
#ifdef	SYSIII
	ioctl(dcf, TCGETA, &ttbuf);
	if(!(ttbuf.c_cflag & HUPCL)) {
		ttbuf.c_cflag |= HUPCL;
		ioctl(dcf, TCSETA, &ttbuf);
	}
#endif
	alarm(0);
	fflush(stdout);
	fixline(dcf, dev->D_speed);
	DEBUG(4, "Fork Stat %o\n", lt);
	if (lt != 0) {
		close(dcf);
		if (dnf)
			close(dnf);
		delock(dev->D_line);
		return(FAIL);
	}
	return(dcf);
}

E 8
I 8
D 9
#if defined(VENTEL) || defined(NOVATION)
E 9
I 9
D 13
#if defined(VENTEL) || defined(NOVATION) || defined(DF112)
E 13
E 9
E 8
/*
D 8
 * df2cls()	close the DF02/DF03 call unit
 *
 *	return codes: none
 */

df2cls(fd)
register int fd;
{
	if (fd > 0) {
		close(fd);
		sleep(5);
		delock(devSel);
		}
}
#endif DF02

#ifdef HAYES
/***
 *	hysopn(telno, flds, dev) connect to hayes smartmodem
 *	char *flds[], *dev[];
 *
 *	return codes:
 *		>0  -  file number  -  ok
 *		CF_DIAL,CF_DEVICE  -  failed
 */
/*
 * Define HAYSTONE if you have touch tone dialing.
 */
/*#define HAYSTONE	*/

hysopn(telno, flds, dev)
char *telno;
char *flds[];
struct Devices *dev;
{
	int	dh = -1;
	extern errno;
	char dcname[20];

	sprintf(dcname, "/dev/%s", dev->D_line);
	DEBUG(4, "dc - %s\n", dcname);
	if (setjmp(Sjbuf)) {
		DEBUG(1, "timeout hayes open %s\n", dcname);
		logent("hayes open", "TIMEOUT");
		if (dh >= 0)
			close(dh);
		delock(dev->D_line);
		return(CF_DIAL);
	}
	signal(SIGALRM, alarmtr);
	getnextfd();
	alarm(10);
	dh = open(dcname, 2); /* read/write */
	alarm(0);

	/* modem is open */
	next_fd = -1;
	if (dh >= 0) {
		fixline(dh, dev->D_speed);
#ifdef HAYSTONE
		write(dh, "\rATDT", 5);
#else
		write(dh, "\rATDP", 5);
#endif
		write(dh, telno, strlen(telno));
		write(dh, "\r", 1);

		if (expect("CONNECT", dh) != 0) {
			logent("HSM no carrier", "FAILED");
			strcpy(devSel, dev->D_line);
			hyscls(dh);
			return(CF_DIAL);
		}

	}
	if (dh < 0) {
		DEBUG(4, "hayes failed\n", "");
		delock(dev->D_line);
	}
	DEBUG(4, "hayes ok\n", "");
	return(dh);
}

hyscls(fd)
int fd;
{
	char dcname[20];
	struct sgttyb hup, sav;

	if (fd > 0) {
		sprintf(dcname, "/dev/%s", devSel);
		DEBUG(4, "Hanging up fd = %d\n", fd);
/*
 * code to drop DTR -- change to 0 baud then back to default.
 */
		gtty(fd, &hup);
		gtty(fd, &sav);
		hup.sg_ispeed = B0;
		hup.sg_ospeed = B0;
		stty(fd, &hup);
		sleep(2);
		stty(fd, &sav);
/*
 * now raise DTR -- close the device & open it again.
 */
		sleep(2);
		close(fd);
		sleep(2);
		fd = open(dcname, 2);
/*
 * Since we have a getty sleeping on this line, when it wakes up it sends
 * all kinds of garbage to the modem.  Unfortunatly, the modem likes to
 * execute the previous command when it sees the garbage.  The previous
 * command was to dial the phone, so let's make the last command reset
 * the modem.
 */
		sleep(2);
		write(fd, "\rATZ\r", 5);
		close(fd);
		delock(devSel);
		}
	}

#endif HAYES

#ifdef HAYESQ
/*
 * New dialout routine to work with Hayes' SMART MODEM
 * 13-JUL-82, Mike Mitchell
 * Modified 23-MAR-83 to work with Tom Truscott's (rti!trt)
 * version of UUCP	(ncsu!mcm)
 *
 * The modem should be set to NOT send any result codes to
 * the system (switch 3 up, 4 down). This end will figure out
 * what is wrong.
 *
 * I had lots of problems with the modem sending
 * result codes since I am using the same modem for both incomming and
 * outgoing calls.  I'd occasionally miss the result code (getty would
 * grab it), and the connect would fail.  Worse yet, the getty would
 * think the result code was a user name, and send garbage to it while
 * it was in the command state.  I turned off ALL result codes, and hope
 * for the best.  99% of the time the modem is in the correct state.
 * Occassionally it doesn't connect, or the phone was busy, etc., and
 * uucico sits there trying to log in.  It eventually times out, calling
 * clsacu() in the process, so it resets itself for the next attempt.
 */

/*
 * Define HAYSTONE if touch-tone dialing is to be used.  If it is not defined,
 * Pulse dialing is assumed.
 */
/*#define HAYSTONE*/

hysqopn(telno, flds, dev)
D 5
register char *telno, *flds[];
E 5
I 5
char *telno, *flds[];
E 5
struct Devices *dev;
{
	char dcname[20], phone[MAXPH+10], c = 0;
#ifdef	SYSIII
	struct termio ttbuf;
#endif
	int status, dnf;
	unsigned timelim;

	signal(SIGALRM, alarmtr);
	sprintf(dcname, "/dev/%s", dev->D_line);

	getnextfd();
	if (setjmp(Sjbuf)) {
		delock(dev->D_line);
		logent("DEVICE", "NO");
		DEBUG(4, "Open timed out %s", dcname);
		return(CF_NODEV);
		}
	alarm(10);

	if ((dnf = open(dcname, 2)) <= 0) {
		delock(dev->D_line);
		logent("DEVICE", "NO");
		DEBUG(4, "Can't open %s", dcname);
		return(CF_NODEV);
		}

	alarm(0);
	next_fd = -1;
	fixline(dnf, dev->D_speed);
	DEBUG(4, "Hayes port - %s, ", dcname);

#ifdef HAYSTONE
	sprintf(phone, "\rATDT%s\r", telno);
#else
	sprintf(phone, "\rATDP%s\r", telno);
#endif

	write(dnf, phone, strlen(phone));

/* calculate delay time for the other system to answer the phone.
 * Default is 15 seconds, add 2 seconds for each comma in the phone
 * number.
 */
	timelim = 150;
	while(*telno) {
		c = *telno++;
		if (c == ',')
			timelim += 20;
		else {
#ifdef HAYSTONE
			timelim += 2;	/* .2 seconds per tone */
			}
#else
			if (c == '0') timelim += 10;   /* .1 second per digit */
			else if (c > '0' && c <= '9')
				timelim += (c - '0');
			}
#endif
		}
	alarm(timelim/10);
	if (setjmp(Sjbuf) == 0) {
		read(dnf, &c, 1);
		alarm(0);
		}

	return(dnf);
	}

hysqcls(fd)
int fd;
{
	char dcname[20];
	struct sgttyb hup, sav;

	if (fd > 0) {
		sprintf(dcname, "/dev/%s", devSel);
		DEBUG(4, "Hanging up fd = %d\n", fd);
/*
 * code to drop DTR -- change to 0 baud then back to default.
 */
		gtty(fd, &hup);
		gtty(fd, &sav);
		hup.sg_ispeed = B0;
		hup.sg_ospeed = B0;
		stty(fd, &hup);
		sleep(2);
		stty(fd, &sav);
/*
 * now raise DTR -- close the device & open it again.
 */
		sleep(2);
		close(fd);
		sleep(2);
		fd = open(dcname, 2);
/*
 * Since we have a getty sleeping on this line, when it wakes up it sends
 * all kinds of garbage to the modem.  Unfortunatly, the modem likes to
 * execute the previous command when it sees the garbage.  The previous
 * command was to dial the phone, so let's make the last command reset
 * the modem.
 */
		sleep(2);
		write(fd, "\rATZ\r", 5);
		close(fd);
		delock(devSel);
		}
	}

#endif HAYESQ

#ifdef	VENTEL
ventopn(telno, flds, dev)
char *flds[], *telno;
struct Devices *dev;
{
	int	dh;
	int	i, ok = -1;
	char dcname[20];

	sprintf(dcname, "/dev/%s", dev->D_line);
	if (setjmp(Sjbuf)) {
		DEBUG(1, "timeout ventel open\n", "");
		logent("ventel open", "TIMEOUT");
		if (dh >= 0)
			close(dh);
		delock(dev->D_line);
		return(CF_NODEV);
	}
	signal(SIGALRM, alarmtr);
	getnextfd();
	alarm(10);
	dh = open(dcname, 2);
	next_fd = -1;
	if (dh < 0) {
		DEBUG(4,"%s\n", errno == 4 ? "no carrier" : "can't open modem");
		delock(dev->D_line);
		return(errno == 4 ? CF_DIAL : CF_NODEV);
	}

	/* modem is open */
	fixline(dh, dev->D_speed);

	/* translate - to % and = to & for VenTel */
	DEBUG(4, "calling %s -> ", telno);
	for (i = 0; i < strlen(telno); ++i) {
		switch(telno[i]) {
		case '-':	/* delay */
			telno[i] = '%';
			break;
		case '=':	/* await dial tone */
			telno[i] = '&';
			break;
		case '<':
			telno[i] = '%';
			break;
		}
	}
	DEBUG(4, "%s\n", telno);
	sleep(1);
	for(i = 0; i < 5; ++i) {	/* make up to 5 tries */
 		slowrite(dh, "\r\r");/* awake, thou lowly VenTel! */

		DEBUG(4, "wanted %s ", "$");
		ok = expect("$", dh);
		DEBUG(4, "got %s\n", ok ? "?" : "that");
		if (ok != 0)
			continue;
 		slowrite(dh, "K");	/* "K" (enter number) command */
		DEBUG(4, "wanted %s ", "DIAL: ");
		ok = expect("DIAL: ", dh);
		DEBUG(4, "got %s\n", ok ? "?" : "that");
		if (ok == 0)
			break;
	}

	if (ok == 0) {
 		slowrite(dh, telno); /* send telno, send \r */
 		slowrite(dh, "\r");
		DEBUG(4, "wanted %s ", "ONLINE");
		ok = expect("ONLINE!", dh);
		DEBUG(4, "got %s\n", ok ? "?" : "that");
	}
	if (ok != 0) {
		if (dh > 2)
			close(dh);
		DEBUG(4, "venDial failed\n", "");
		return(CF_DIAL);
	} else
		DEBUG(4, "venDial ok\n", "");
	return(dh);
}


/*
E 8
D 10
 * uucpdelay:  delay execution for numerator/denominator seconds.
E 10
I 10
 * intervaldelay:  delay execution for numerator/denominator seconds.
E 10
 */

#ifdef INTERVALTIMER
D 10
#define uucpdelay(num,denom) intervaldelay(1000000*num/denom)
E 10
D 2
#include <time.h>
E 2
I 2
#include <sys/time.h>
E 2
D 10
catch alarm sig
SIGALRM
struct itimerval itimerval;
itimerval.itimer_reload =
itimerval.rtime.itimer_interval =
itimerval.rtime.itimer_value =
settimer(ITIMER_REAL, &itimerval);
pause();
alarm comes in
turn off timer.
E 10
I 10
#define uucpdelay(num,denom) intervaldelay(num,denom)
intervaldelay(num,denom)
int num, denom;
{
	struct timeval tv;
	tv.tv_sec = num / denom;
	tv.tv_usec = (num * 1000000L / denom ) % 1000000L;
	(void) select (0, (int *)0, (int *)0, (int *)0, &tv);
}
E 10
#endif INTERVALTIMER

#ifdef FASTTIMER
#define uucpdelay(num,denom) nap(60*num/denom)
/*	Sleep in increments of 60ths of second.	*/
nap (time)
D 9
	register int time;
E 9
I 9
register int time;
E 9
{
	static int fd;

	if (fd == 0)
		fd = open (FASTTIMER, 0);

	read (fd, 0, time);
}
#endif FASTTIMER

#ifdef FTIME
#define uucpdelay(num,denom) ftimedelay(1000*num/denom)
D 9
#include <sys/timeb.h>
E 9
ftimedelay(n)
{
	static struct timeb loctime;
I 8
	register i = loctime.millitm;

E 8
	ftime(&loctime);
D 8
	{register i = loctime.millitm;
	   while (abs((int)(loctime.millitm - i))<n) ftime(&loctime);
	}
E 8
I 8
	while (abs((int)(loctime.millitm - i))<n) ftime(&loctime)
		;
E 8
}
#endif FTIME

#ifdef BUSYLOOP
#define uucpdelay(num,denom) busyloop(CPUSPEED*num/denom)
#define CPUSPEED 1000000	/* VAX 780 is 1MIPS */
#define	DELAY(n)	{ register long N = (n); while (--N > 0); }
busyloop(n)
D 8
	{
E 8
I 8
{
E 8
	DELAY(n);
D 8
	}
E 8
I 8
}
E 8
#endif BUSYLOOP

slowrite(fd, str)
register char *str;
{
D 8
	DEBUG(6, "slowrite ", "");
E 8
I 8
	DEBUG(6, "slowrite ", CNULL);
E 8
	while (*str) {
		DEBUG(6, "%c", *str);
D 13
		uucpdelay(1,10);	/* delay 1/10 second */
E 13
I 13
		uucpdelay(1, 10);	/* delay 1/10 second */
E 13
		write(fd, str, 1);
		str++;
D 8
		}
	DEBUG(6, "\n", "");
}


ventcls(fd)
int fd;
{

	if (fd > 0) {
		close(fd);
		sleep(5);
		delock(devSel);
		}
}
#endif VENTEL

#ifdef VADIC

/*
 *	vadopn: establish dial-out connection through a Racal-Vadic 3450.
 *	Returns descriptor open to tty for reading and writing.
 *	Negative values (-1...-7) denote errors in connmsg.
 *	Be sure to disconnect tty when done, via HUPCL or stty 0.
 */

vadopn(telno, flds, dev)
char *telno;
char *flds[];
struct Devices *dev;
{
	int	dh = -1;
D 4
	int	i, ok, er = 0;
E 4
I 4
	int	i, ok, er = 0, delay;
E 4
	extern errno;
	char dcname[20];
I 7
	char ntelno[64];
E 7

	sprintf(dcname, "/dev/%s", dev->D_line);
	if (setjmp(Sjbuf)) {
		DEBUG(1, "timeout vadic open\n", "");
		logent("vadic open", "TIMEOUT");
		if (dh >= 0)
			close(dh);
		delock(dev->D_line);
		return(CF_NODEV);
E 8
	}
D 8
	signal(SIGALRM, alarmtr);
	getnextfd();
	alarm(10);
	dh = open(dcname, 2);
	alarm(0);

	/* modem is open */
	next_fd = -1;
	if (dh < 0) {
		delock(dev->D_line);
		return(CF_NODEV);
		}
	fixline(dh, dev->D_speed);

I 7
/* add a delay at the end of the number for the local phone switch */
	sprintf(ntelno, "%s=", telno);
E 7
D 6
/* translate - to % and = to & for VenTel */
E 6
I 6
/* translate - to K for Vadic */
E 6
D 7
	DEBUG(4, "calling %s -> ", telno);
E 7
I 7
	DEBUG(4, "calling %s -> ", ntelno);
E 7
I 4
	delay = 0;
E 4
D 7
	for (i = 0; i < strlen(telno); ++i) {
		switch(telno[i]) {
E 7
I 7
	for (i = 0; i < strlen(ntelno); ++i) {
		switch(ntelno[i]) {
E 7
		case '=':	/* await dial tone */
I 6
		case '-':	/* delay */
E 6
		case '<':
D 7
			telno[i] = 'K';
E 7
I 7
			ntelno[i] = 'K';
E 7
I 6
			delay += 5;
E 6
			break;
		}
	}
D 7
	DEBUG(4, "%s\n", telno);
E 7
I 7
	DEBUG(4, "%s\n", ntelno);
E 7
D 6
	sleep(1);
E 6
	for(i = 0; i < 5; ++i) {	/* make 5 tries */
		/* wake up Vadic */
D 6
		write(dh, "\005\r", 2);
E 6
I 6
		sendthem("\005\\d", dh);
E 6
		DEBUG(4, "wanted %s ", "*");
		ok = expect("*", dh);
		DEBUG(4, "got %s\n", ok ? "?" : "that");
		if (ok != 0)
			continue;

D 6
		write(dh, "D\r", 2); /* "D" (enter number) command */
E 6
I 6
		sendthem("D\\d", dh);	/* "D" (enter number) command */
E 6
D 3
		DEBUG(4, "wanted %s ", "NUMBER?");
		ok = expect("NUMBER?", dh);
E 3
I 3
		DEBUG(4, "wanted %s ", "NUMBER?\\r\\n");
		ok = expect("NUMBER?\r\n", dh);
E 3
		DEBUG(4, "got %s\n", ok ? "?" : "that");
		if (ok != 0)
			continue;

	/* send telno, send \r */
D 6
		write(dh, telno, strlen(telno));
		sleep(1);
		write(dh, "\r", 1);
E 6
I 6
D 7
		sendthem(telno, dh);
E 6
		ok = expect(telno, dh);
E 7
I 7
		sendthem(ntelno, dh);
		ok = expect(ntelno, dh);
E 7
I 3
		if (ok == 0)
			ok = expect("\r\n", dh);
E 3
		DEBUG(4, "got %s\n", ok ? "?" : "that");
		if (ok != 0)
			continue;

D 6
		write(dh, "\r", 1); /* confirm number */
E 6
I 6
		sendthem("", dh); /* confirm number */
E 6
		DEBUG(4, "wanted %s ", "DIALING: ");
		ok = expect("DIALING: ", dh);
		DEBUG(4, "got %s\n", ok ? "?" : "that");
		if (ok == 0)
			break;
	}

	if (ok == 0) {
D 3
		/* send telno, send \r */
		write(dh, telno, strlen(telno));
		write(dh, "\r", 1);
		DEBUG(4, "wanted %s ", "ON LINE");
		ok = expect("ON LINE", dh);
E 3
I 3
		sleep(10 + delay);	/* give vadic some time */
		DEBUG(4, "wanted ON LINE\\r\\n ", 0);
		ok = expect("ON LINE\r\n", dh);
E 3
		DEBUG(4, "got %s\n", ok ? "?" : "that");
	}

	if (ok != 0) {
I 6
		sendthem("I\\d", dh);	/* back to idle */
E 6
		if (dh > 2)
			close(dh);
		DEBUG(4, "vadDial failed\n", "");
		delock(dev->D_line);
		return(CF_DIAL);
	}
	DEBUG(4, "vadic ok\n", "");
	return(dh);
E 8
I 8
	DEBUG(6, "\n", CNULL);
E 8
}
D 8

vadcls(fd) {

	if (fd > 0) {
		close(fd);
		sleep(5);
		delock(devSel);
		}
	}

#endif VADIC

#ifdef	RVMACS
/*
 * Racal-Vadic 'RV820' MACS system with 831 adaptor.
 * A typical 300 baud L-devices entry is
 *	ACU /dev/tty10 /dev/tty11,48 300 rvmacs
 * where tty10 is the communication line (D_Line),
 * tty11 is the dialer line (D_calldev),
 * the '4' is the dialer address + modem type (viz. dialer 0, Bell 103),
 * and the '8' is the communication port (they are 1-indexed).
 * BUGS:
 * Only tested with one dialer, one modem
 * uses common speed for dialer and communication line.
 * UNTESTED
 */

#define	STX	02	/* Access Adaptor */
#define	ETX	03	/* Transfer to Dialer */
#define	SI	017	/* Buffer Empty (end of phone number) */
#define	SOH	01	/* Abort */

rvmacsopn(ph, flds, dev)
char *ph, *flds[];
struct Devices *dev;
{
	register int va, i, child;
	register char *p;
	char c, acu[20], com[20];

	child = -1;
	if ((p = index(dev->D_calldev, ',')) == NULL) {
		DEBUG(2, "No dialer/modem specification\n", 0);
		goto failret;
	}
	*p++ = '\0';
	if (setjmp(Sjbuf)) {
		logent("rvmacsopn", "TIMEOUT");
		i = CF_DIAL;
		goto ret;
	}
	DEBUG(4, "STARTING CALL\n", 0);
	sprintf(acu, "/dev/%s", dev->D_calldev);
	getnextfd();
	signal(SIGALRM, alarmtr);
	alarm(30);
	if ((va = open(acu, 2)) < 0) {
		logent(acu, "CAN'T OPEN");
		i = CF_NODEV;
		goto ret;
	}
	fixline(va, dev->D_speed);

	p_chwrite(va, STX);	/* access adaptor */
	i = *p++ - '0';
	if (i < 0 || i > 7) {
		logent(p-1, "Bad dialer address/modem type\n");
		goto failret;
	}
	p_chwrite(va, i);		/* Send Dialer Address Digit */
	i = *p - '0';
	if (i <= 0 || i > 14) {
		logent(p-1, "Bad modem address\n");
		goto failret;
	}
	p_chwrite(va, i-1);	/* Send Modem Address Digit */
	write(va, ph, strlen(ph));	/* Send Phone Number */
	p_chwrite(va, SI);	/* Send Buffer Empty */
	p_chwrite(va, ETX);	/* Initiate Call */
	sprintf(com, "/dev/%s", dev->D_line);

	/* create child to open comm line */
	if ((child = fork()) == 0) {
		signal(SIGINT, SIG_DFL);
		open(com, 0);
		sleep(5);
		exit(1);
	}

	if (read(va, &c, 1) != 1) {
		logent("ACU READ", "FAILED");
		goto failret;
	}
	switch(c) {
	case 'A':
		/* Fine! */
		break;
	case 'B':
		DEBUG(2, "CALL ABORTED\n", 0);
		goto failret;
	case 'D':
		DEBUG(2, "Dialer format error\n", 0);
		goto failret;
	case 'E':
		DEBUG(2, "Dialer parity error\n", 0);
		goto failret;
	case 'F':
		DEBUG(2, "Phone number too long\n", 0);
		goto failret;
	case 'G':
		DEBUG(2, "Busy signal\n", 0);
		goto failret;
	default:
		DEBUG(2, "Unknown MACS return code '%c'\n", i);
		goto failret;
	}
	/*
	 * open line - will return on carrier
	 */
	if ((i = open(com, 2)) < 0) {
		if (errno == EIO)
			logent("carrier", "LOST");
		else
			logent("dialup open", "FAILED");
		goto failret;
	}
	fixline(i, dev->D_speed);
	goto ret;
failret:
	i = CF_DIAL;
ret:
	alarm(0);
	if (child != -1)
		kill(child, SIGKILL);
	close(va);
	return(i);
}

rvmacscls(fd)
register int fd;
{
	DEBUG(2, "MACS close %d\n", fd);
	p_chwrite(fd, SOH);
/*	ioctl(fd, TIOCCDTR, NULL);*/
	close(fd);
}
#endif
E 8
I 8
D 9
#endif VENTEL || NOVATION
E 9
I 9
D 13
#endif VENTEL || NOVATION || DF112
E 13
I 13

#define BSPEED B150

/*
 *	send a break
 */
genbrk(fn, bnulls)
register int fn, bnulls;
{
#ifdef	USG
	if (ioctl(fn, TCSBRK, STBNULL) < 0)
		DEBUG(5, "break TCSBRK %s\n", sys_errlist[errno]);
#else	!USG
# ifdef	TIOCSBRK
	if (ioctl(fn, TIOCSBRK, STBNULL) < 0)
		DEBUG(5, "break TIOCSBRK %s\n", sys_errlist[errno]);
# ifdef	TIOCCBRK
	uucpdelay(bnulls, 10);
	if (ioctl(fn, TIOCCBRK, STBNULL) < 0)
		DEBUG(5, "break TIOCCBRK %s\n", sys_errlist[errno]);
# endif TIOCCBRK
	DEBUG(4, "ioctl %f second break\n", (float) bnulls/10 );
# else !TIOCSBRK
	struct sgttyb ttbuf;
	register int sospeed;

	if (ioctl(fn, TIOCGETP, &ttbuf) < 0)
		DEBUG(5, "break TIOCGETP %s\n", sys_errlist[errno]);
	sospeed = ttbuf.sg_ospeed;
	ttbuf.sg_ospeed = BSPEED;
	if (ioctl(fn, TIOCSETP, &ttbuf) < 0)
		DEBUG(5, "break TIOCSETP %s\n", sys_errlist[errno]);
	if (write(fn, "\0\0\0\0\0\0\0\0\0\0\0\0", bnulls) != bnulls) {
badbreak:
		logent(sys_errlist[errno], "BAD WRITE genbrk");
		alarm(0);
		longjmp(Sjbuf, 3);
	}
	ttbuf.sg_ospeed = sospeed;
	if (ioctl(fn, TIOCSETP, &ttbuf) < 0)
		DEBUG(5, "break ioctl %s\n", sys_errlist[errno]);
	if (write(fn, "@", 1) != 1)
		goto badbreak;
	DEBUG(4, "sent BREAK nulls - %d\n", bnulls);
#endif !TIOCSBRK
#endif !USG
}

E 13

#ifdef DIALINOUT
/* DIALIN/OUT CODE (WLS) */
/*
 * disable and reenable:  allow a single line to be use for dialin/dialout
 *
 */

char enbdev[16];

disable(dev)
register char *dev;
{
	register char *rdev;

	/* strip off directory prefixes */
	rdev = dev;
	while (*rdev)
		rdev++;
	while (--rdev >= dev && *rdev != '/')
		;
	rdev++;

	if (enbdev[0]) {
		if (strcmp(enbdev, rdev) == SAME)
			return SUCCESS;	/* already disabled */
		delock(enbdev);
		reenable();		/* else, reenable the old one */
	}
	DEBUG(4, "Disable %s\n", rdev);
	if (enbcall("disable", rdev) == FAIL)
		return FAIL;
D 12
	logent(rdev, "DISABLED LOGIN");
E 12
	strcpy(enbdev, rdev);
	return SUCCESS;
}

reenable()
{
D 11
	if (enbdev[0] == NULL)
E 11
I 11
	if (enbdev[0] == '\0')
E 11
		return;
	DEBUG(4, "Reenable %s\n", enbdev);
	(void) enbcall("enable", enbdev);
D 12
	logent(enbdev, "REENABLED LOGIN");
E 12
	enbdev[0] = '\0';
}

enbcall(type, dev)
char *type, *dev;
{
	int pid;
	register char *p;
	int fildes[2];
	int status;
	FILE *fil;
	char buf[80];
	
	fflush(stderr);
	fflush(stdout);
	pipe(fildes);
	if ((pid = fork()) == 0) {
		DEBUG(4, DIALINOUT, CNULL);
		DEBUG(4, " %s", type);
		DEBUG(4, " %s\n", dev);
		close(fildes[0]);
		close(0); close(1); close(2);
		open("/dev/null",0);
		dup(fildes[1]); dup(fildes[1]);
		setuid(geteuid());	/* for chown(uid()) in acu program */
D 20
		execl(DIALINOUT, "acu", type, dev, 0);
E 20
I 20
		execl(DIALINOUT, "acu", type, dev, Rmtname, (char *)0);
E 20
		exit(-1);
	}
	if (pid<0)
		return FAIL;

	close(fildes[1]);
	fil = fdopen(fildes[0],"r");
	if (fil!=NULL) {
I 10
#ifdef BSD4_2
E 10
		setlinebuf(fil);
I 10
#endif BSD4_2
E 10
		while (fgets(buf, sizeof buf, fil) != NULL) {
			p = buf + strlen(buf) - 1;
			if (*p == '\n')
				*p = '\0';
D 16
			logent(buf,"ACUCNTRL:");
E 16
I 16
			DEBUG(4, "ACUCNTRL: %s\n", buf);
E 16
		}
	}
	while(wait(&status) != pid)
		;
	fclose(fil);
	return status ? FAIL : SUCCESS;
}
#endif DIALINOUT
E 9
E 8
E 1
