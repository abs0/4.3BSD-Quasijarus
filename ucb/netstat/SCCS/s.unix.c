h55889
s 00012/00007/00114
d D 5.6 88/06/29 20:42:13 bostic 7 6
c install approved copyright notice
e
s 00009/00003/00112
d D 5.5 88/02/07 20:38:25 karels 6 5
c new copyrights
e
s 00010/00009/00105
d D 5.4 86/08/11 11:51:27 kupfer 5 4
c Some lint.
e
s 00006/00002/00108
d D 5.3 86/05/08 14:52:57 karels 4 3
c integrate unix domain, get the addresses right
e
s 00002/00002/00108
d D 5.2 86/02/01 19:23:14 mckusick 3 2
c unp_remaddr becomes unp_addr
e
s 00007/00001/00103
d D 5.1 85/06/04 15:47:30 dist 2 1
c Add copyright
e
s 00104/00000/00000
d D 1.1 84/06/03 11:13:27 sam 1 0
c date and time created 84/06/03 11:13:27 by sam
e
u
U
t
T
I 2
/*
D 6
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
D 7
 * Copyright (c) 1983,1988 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

E 2
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif
E 2
I 2
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 2

/*
 * Display protocol blocks in the unix domain.
 */
#include <sys/param.h>
#include <sys/protosw.h>
#include <sys/socket.h>
#include <sys/socketvar.h>
#include <sys/mbuf.h>
#include <sys/un.h>
#include <sys/unpcb.h>
#define	KERNEL
#include <sys/file.h>

int	Aflag;
int	kmem;
I 5
extern	char *calloc();
E 5

unixpr(nfileaddr, fileaddr, unixsw)
	off_t nfileaddr, fileaddr;
	struct protosw *unixsw;
{
	register struct file *fp;
	struct file *filep;
	struct socket sock, *so = &sock;

	if (nfileaddr == 0 || fileaddr == 0) {
		printf("nfile or file not in namelist.\n");
		return;
	}
	klseek(kmem, nfileaddr, L_SET);
D 5
	if (read(kmem, &nfile, sizeof (nfile)) != sizeof (nfile)) {
E 5
I 5
	if (read(kmem, (char *)&nfile, sizeof (nfile)) != sizeof (nfile)) {
E 5
		printf("nfile: bad read.\n");
		return;
	}
	klseek(kmem, fileaddr, L_SET);
D 5
	if (read(kmem, &filep, sizeof (filep)) != sizeof (filep)) {
E 5
I 5
	if (read(kmem, (char *)&filep, sizeof (filep)) != sizeof (filep)) {
E 5
		printf("File table address, bad read.\n");
		return;
	}
	file = (struct file *)calloc(nfile, sizeof (struct file));
	if (file == (struct file *)0) {
		printf("Out of memory (file table).\n");
		return;
	}
	klseek(kmem, (off_t)filep, L_SET);
D 5
	if (read(kmem, file, nfile * sizeof (struct file)) !=
E 5
I 5
	if (read(kmem, (char *)file, nfile * sizeof (struct file)) !=
E 5
	    nfile * sizeof (struct file)) {
		printf("File table read error.\n");
		return;
	}
	fileNFILE = file + nfile;
	for (fp = file; fp < fileNFILE; fp++) {
		if (fp->f_count == 0 || fp->f_type != DTYPE_SOCKET)
			continue;
D 5
		klseek(kmem, fp->f_data, L_SET);
		if (read(kmem, so, sizeof (*so)) != sizeof (*so))
E 5
I 5
		klseek(kmem, (off_t)fp->f_data, L_SET);
		if (read(kmem, (char *)so, sizeof (*so)) != sizeof (*so))
E 5
			continue;
		/* kludge */
		if (so->so_proto >= unixsw && so->so_proto <= unixsw + 2)
			if (so->so_pcb)
				unixdomainpr(so, fp->f_data);
	}
	free((char *)file);
}

static	char *socktype[] =
    { "#0", "stream", "dgram", "raw", "rdm", "seqpacket" };

unixdomainpr(so, soaddr)
	register struct socket *so;
	caddr_t soaddr;
{
	struct unpcb unpcb, *unp = &unpcb;
	struct mbuf mbuf, *m;
I 4
	struct sockaddr_un *sa;
E 4
	static int first = 1;

D 5
	klseek(kmem, so->so_pcb, L_SET);
	if (read(kmem, unp, sizeof (*unp)) != sizeof (*unp))
E 5
I 5
	klseek(kmem, (off_t)so->so_pcb, L_SET);
	if (read(kmem, (char *)unp, sizeof (*unp)) != sizeof (*unp))
E 5
		return;
D 3
	if (unp->unp_remaddr) {
E 3
I 3
	if (unp->unp_addr) {
E 3
		m = &mbuf;
D 3
		klseek(kmem, unp->unp_remaddr, L_SET);
E 3
I 3
D 5
		klseek(kmem, unp->unp_addr, L_SET);
E 3
		if (read(kmem, m, sizeof (*m)) != sizeof (*m))
E 5
I 5
		klseek(kmem, (off_t)unp->unp_addr, L_SET);
		if (read(kmem, (char *)m, sizeof (*m)) != sizeof (*m))
E 5
			m = (struct mbuf *)0;
I 4
		sa = mtod(m, struct sockaddr_un *);
E 4
	} else
		m = (struct mbuf *)0;
	if (first) {
I 4
		printf("Active UNIX domain sockets\n");
E 4
		printf(
D 4
"%-8.8s %-6.6s %-6.6s %-6.6s %8.8s %8.8s %8.8s %8.8s Remaddr\n",
E 4
I 4
"%-8.8s %-6.6s %-6.6s %-6.6s %8.8s %8.8s %8.8s %8.8s Addr\n",
E 4
		    "Address", "Type", "Recv-Q", "Send-Q",
		    "Inode", "Conn", "Refs", "Nextref");
		first = 0;
	}
	printf("%8x %-6.6s %6d %6d %8x %8x %8x %8x",
	    soaddr, socktype[so->so_type], so->so_rcv.sb_cc, so->so_snd.sb_cc,
	    unp->unp_inode, unp->unp_conn,
	    unp->unp_refs, unp->unp_nextref);
	if (m)
D 4
		printf(" %.*s", m->m_len, mtod(m, char *));
E 4
I 4
		printf(" %.*s", m->m_len - sizeof(sa->sun_family),
		    sa->sun_path);
E 4
	putchar('\n');
}
E 1
