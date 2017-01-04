h04742
s 00001/00001/00113
d D 4.7 88/05/05 11:21:43 rick 7 6
c add sccsid
e
s 00001/00001/00113
d D 4.6 86/02/13 14:44:27 bloom 6 5
c let's get the defines right
e
s 00006/00001/00108
d D 4.5 86/02/12 17:18:20 bloom 5 4
c add new dialer
e
s 00008/00000/00101
d D 4.4 86/01/24 13:19:23 bloom 4 3
c still more fixes and changes from rick@seismo
e
s 00001/00001/00100
d D 4.3 85/06/19 18:16:11 bloom 3 2
c fix from rick adams
e
s 00009/00002/00092
d D 4.2 85/04/10 15:19:13 ralph 2 1
c more changes from rick adams.
e
s 00094/00000/00000
d D 4.1 85/01/22 13:49:25 ralph 1 0
c date and time created 85/01/22 13:49:25 by ralph
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*	%W%	(Berkeley)	%G%	*/
E 7

D 2
#include <sys/types.h>
E 2
I 2
#include "uucp.h"
E 2
#include <errno.h>
#include <setjmp.h>
#include <signal.h>
#include <sgtty.h>
D 2
#include "uucp.h"
E 2
#ifdef VMSDTR	/* Modem control on vms(works dtr) */
#include <eunice/eunice.h>
#define TT$M_MODEM	0x00200000 /* These should be in a '.h' somewhere */
#define SS$_NORMAL	0x00000001
#define IO$_SETMODE	0x00000023
#define IO$_SENSEMODE	0x00000027
#endif

extern char devSel[];	/* name to pass to delock() in close */
extern int errno, next_fd;
extern jmp_buf Sjbuf;
extern int alarmtr();
int nulldev(), nodev(), Acuopn(), diropn(), dircls();

#ifdef DATAKIT
int dkopn();
#endif DATAKIT

#ifdef DN11
int dnopn(), dncls();
#endif DN11

#ifdef HAYES
D 3
int hysopn(), hyscls();
E 3
I 3
int hyspopn(), hystopn(), hyscls();
E 3
#endif HAYES

I 4
#ifdef HAYES2400
D 6
int hyspopn24(), hystop24n(), hyscls();
E 6
I 6
int hyspopn24(), hystopn24(), hyscls24();
E 6
#endif HAYES2400

E 4
#ifdef HAYESQ
int hysqopn(), hysqcls();  /* a version of hayes that doesn't use ret codes */
#endif HAYESQ

#ifdef NOVATION
int novopn(), novcls();
#endif NOVATION
I 4

#ifdef CDS224
int cdsopn224(), cdscls224();
#endif CDs224
E 4

#ifdef DF02
int df2opn(), df2cls();
#endif DF02

I 2
#ifdef DF112
int df12popn(), df12topn(), df12cls();
#endif DF112

E 2
#ifdef PNET
int pnetopn();
#endif PNET

#ifdef VENTEL
int ventopn(), ventcls();
#endif VENTEL
I 2

#ifdef PENRIL
int penopn(), pencls();
#endif PENRIL
E 2

#ifdef	UNETTCP
#define TO_ACTIVE	0
int unetopn(), unetcls();
#endif UNETTCP

#ifdef BSDTCP
int bsdtcpopn(), bsdtcpcls();
#endif BSDTCP

#ifdef VADIC
int vadopn(), vadcls();
#endif VADIC

#ifdef VA212
int va212opn(), va212cls();
#endif VA212

#ifdef VA811S
int va811opn(), va811cls();
#endif VA811S

#ifdef VA820
int va820opn(), va820cls();
#endif VA820

#ifdef	RVMACS
int rvmacsopn(), rvmacscls();
#endif

#ifdef	VMACS
int vmacsopn(), vmacscls();
#endif

#ifdef MICOM
int micopn(), miccls();
#endif MICOM

#ifdef SYTEK
int sykopn(), sykcls();
D 5
#endif
E 5
I 5
#endif SYTEK

#ifdef ATT2224
int attopn(), attcls();
#endif	ATT2224

E 5
E 1
