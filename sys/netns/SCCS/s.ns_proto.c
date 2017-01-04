h32737
s 00011/00006/00066
d D 7.3 88/06/29 17:13:36 bostic 9 8
c install approved copyright notice
e
s 00010/00004/00062
d D 7.2 88/01/20 15:15:30 sklower 8 7
c Change licensing/use notice.
e
s 00001/00001/00065
d D 7.1 86/06/05 00:38:03 mckusick 7 6
c 4.3BSD release version
e
s 00003/00004/00063
d D 6.6 86/03/04 19:30:31 sklower 6 5
c Silence Lint.
e
s 00001/00001/00066
d D 6.5 86/02/03 17:40:57 sklower 5 4
c Correct erroneous copyright information.
e
s 00003/00003/00064
d D 6.4 85/09/06 17:07:57 sklower 4 3
c imp routines fixed, ctlinputs now look for sockaddrs in the
c appropriate family.  Should be just like 6.2.
e
s 00003/00003/00064
d D 6.3 85/08/09 11:46:38 sklower 3 2
c remove reference to ctlinput temporarily since the 
e
s 00007/00001/00060
d D 6.2 85/06/08 12:51:44 mckusick 2 1
c Add copyright
e
s 00061/00000/00000
d D 6.1 85/05/30 19:11:06 sklower 1 0
c date and time created 85/05/30 19:11:06 by sklower
e
u
U
t
T
I 1
D 2
/*      %M%     %I%     %E%     */
E 2
I 2
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
D 7
 * Copyright (c) 1984, 1985 Regents of the University of California.
E 7
I 7
D 8
 * Copyright (c) 1984, 1985, 1986 Regents of the University of California.
E 7
E 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.
 * All rights reserved.
E 8
 *
D 8
 *	%W% (Berkeley) %G%
E 8
I 8
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 9
 *
D 9
 *      %W% (Berkeley) %G%
E 9
I 9
 *	%W% (Berkeley) %G%
E 9
E 8
 */
E 2

#include "param.h"
#include "socket.h"
#include "protosw.h"
#include "domain.h"
#include "mbuf.h"

#include "ns.h"

/*
 * NS protocol family: IDP, ERR, PE, SPP, ROUTE.
 */
D 6
int	ns_init(), ns_ctlinput();
E 6
I 6
int	ns_init();
E 6
int	idp_input(), idp_output(), idp_ctlinput(), idp_usrreq();
D 6
int	idp_raw_usrreq();
int	idp_init(), idp_slowtimo(), idp_drain(), idp_ctloutput();
E 6
I 6
int	idp_raw_usrreq(), idp_ctloutput();
E 6
int	spp_input(), spp_ctlinput();
int	spp_usrreq(), spp_usrreq_sp(), spp_ctloutput();
D 6
int	spp_init(), spp_fasttimo(), spp_slowtimo(), spp_drain();
E 6
I 6
int	spp_init(), spp_fasttimo(), spp_slowtimo();
E 6
extern	int raw_usrreq();

extern	struct domain nsdomain;

struct protosw nssw[] = {
{ 0,		&nsdomain,	0,		0,
  0,		idp_output,	0,		0,
  0,
  ns_init,	0,		0,		0,
},
{ SOCK_DGRAM,	&nsdomain,	0,		PR_ATOMIC|PR_ADDR,
D 3
  0,		0,		idp_ctlinput,	idp_ctloutput,
E 3
I 3
D 4
  0,		0,		0,		idp_ctloutput,
E 4
I 4
  0,		0,		idp_ctlinput,	idp_ctloutput,
E 4
E 3
  idp_usrreq,
  0,		0,		0,		0,
},
{ SOCK_STREAM,	&nsdomain,	NSPROTO_SPP,	PR_CONNREQUIRED|PR_WANTRCVD,
D 3
  spp_input,	0,		spp_ctlinput,	spp_ctloutput,
E 3
I 3
D 4
  spp_input,	0,		0,		spp_ctloutput,
E 4
I 4
  spp_input,	0,		spp_ctlinput,	spp_ctloutput,
E 4
E 3
  spp_usrreq,
  spp_init,	spp_fasttimo,	spp_slowtimo,	0,
},
{ SOCK_SEQPACKET,&nsdomain,	NSPROTO_SPP,	PR_CONNREQUIRED|PR_WANTRCVD|PR_ATOMIC,
D 3
  spp_input,	0,		spp_ctlinput,	spp_ctloutput,
E 3
I 3
D 4
  spp_input,	0,		0,		spp_ctloutput,
E 4
I 4
  spp_input,	0,		spp_ctlinput,	spp_ctloutput,
E 4
E 3
  spp_usrreq_sp,
  0,		0,		0,		0,
},
{ SOCK_RAW,	&nsdomain,	NSPROTO_RAW,	PR_ATOMIC|PR_ADDR,
  idp_input,	idp_output,	0,		idp_ctloutput,
  idp_raw_usrreq,
  0,		0,		0,		0,
},
{ SOCK_RAW,	&nsdomain,	NSPROTO_ERROR,	PR_ATOMIC|PR_ADDR,
  idp_ctlinput,	idp_output,	0,		idp_ctloutput,
  idp_raw_usrreq,
  0,		0,		0,		0,
},
};

struct domain nsdomain =
    { AF_NS, "network systems", 0, 0, 0, 
      nssw, &nssw[sizeof(nssw)/sizeof(nssw[0])] };

E 1
