h62188
s 00001/00003/00094
d D 4.4 88/02/24 20:44:35 rick 4 3
c increase alarm timeout
e
s 00003/00002/00094
d D 4.3 86/06/07 08:29:39 bloom 3 2
c old changes that hadn't been delta'ed in
e
s 00012/00002/00084
d D 4.2 85/06/23 15:11:32 bloom 2 1
c fixes from rick adams
e
s 00086/00000/00000
d D 4.1 85/01/22 13:04:17 ralph 1 0
c date and time created 85/01/22 13:04:17 by ralph
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "../condevs.h"
D 4
#ifdef BSDTCP
E 4
I 2
#include <netdb.h>
E 2
#include <sys/socket.h>
#include <netinet/in.h>
D 2
#include <netdb.h>
E 2

/*
 *	bsdtcpopn -- make a tcp connection
 *
 *	return codes:
 *		>0 - file number - ok
 *		FAIL - failed
 */

bsdtcpopn(flds)
register char *flds[];
{
	struct servent *sp;
	struct hostent *hp;
	struct	sockaddr_in hisctladdr;
D 3
	int s, port;
E 3
I 3
	int s = -1, port;
E 3
	extern int errno;
	extern char *sys_errlist[];

	sp = getservbyname(flds[F_CLASS], "tcp");
	if (sp == NULL) {
		port = htons(atoi(flds[F_CLASS]));
		if (port == 0) {
			logent(_FAILED, "UNKNOWN PORT NUMBER");
			return CF_SYSTEM;
		}
	} else
		port = sp->s_port;
	DEBUG(4, "bsdtcpopn host %s, ", flds[F_PHONE]);
	DEBUG(4, "port %d\n", ntohs(port));
	if (setjmp(Sjbuf)) {
I 3
		bsdtcpcls(s);
E 3
		logent("tcpopen", "TIMEOUT");
		return CF_DIAL;
	}

	bzero((char *)&hisctladdr, sizeof (hisctladdr));
	hp = gethostbyname(flds[F_PHONE]);
	if (hp == NULL) {
		logent("tcpopen","UNKNOWN HOST");
		return CF_DIAL;
	}
	signal(SIGALRM, alarmtr);
D 4
	alarm(30);
E 4
I 4
	alarm(MAXMSGTIME*2);
E 4
	hisctladdr.sin_family = hp->h_addrtype;
D 2
	s = socket(hp->h_addrtype, SOCK_STREAM, 0, 0);
E 2
I 2
#ifdef BSD2_9
	s = socket(SOCK_STREAM, 0, &hisctladdr, 0);
#else BSD4_2
	s = socket(hp->h_addrtype, SOCK_STREAM, 0);
#endif BSD4_2
E 2
	if (s < 0)
		goto bad;
I 2
#ifndef BSD2_9
E 2
	if (bind(s, (char *)&hisctladdr, sizeof (hisctladdr), 0) < 0)
		goto bad;
I 2
#endif BSD2_9
E 2
	bcopy(hp->h_addr, (char *)&hisctladdr.sin_addr, hp->h_length);
	hisctladdr.sin_port = port;
I 2
#ifdef BSD2_9
	if (connect(s, (char *)&hisctladdr) < 0)
#else BSD4_2
E 2
	if (connect(s, (char *)&hisctladdr, sizeof (hisctladdr), 0) < 0)
I 2
#endif BSD4_2
E 2
		goto bad;
	alarm(0);
	CU_end = bsdtcpcls;
	return s;
bad:
	alarm(0);
D 3
	close(s);
E 3
I 3
	bsdtcpcls(s);
E 3
	DEBUG(5, "tcpopen failed: errno %d\n", errno);
	logent(sys_errlist[errno], _FAILED);
	return CF_DIAL;
}

/*
 * bsdtcpcls -- close tcp connection
 */
bsdtcpcls(fd)
register int fd;
{
	DEBUG(4, "TCP CLOSE called\n", 0);
	if (fd > 0) {
		close(fd);
		DEBUG(4, "closed fd %d\n", fd);
	}
}
D 4
#endif BSDTCP
E 4
E 1
