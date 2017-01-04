h15754
s 00014/00009/00491
d D 5.10 88/06/18 13:58:32 bostic 14 13
c install approved copyright notice
e
s 00012/00002/00488
d D 5.9 88/04/21 10:40:20 karels 13 12
c yet another option: -F follows from end
e
s 00010/00004/00480
d D 5.8 88/02/08 10:44:39 karels 12 11
c new copyrights
e
s 00009/00012/00475
d D 5.7 88/02/08 10:42:40 karels 11 10
c new imp headers
e
s 00001/00001/00486
d D 5.6 87/12/21 12:44:32 bostic 10 9
c make ANSI C compatible
e
s 00015/00007/00472
d D 5.5 86/05/30 11:17:18 karels 9 8
c check for truncated headers
e
s 00029/00015/00450
d D 5.4 86/05/05 19:31:57 karels 8 7
c update and correct; add -r to implog
e
s 00019/00007/00446
d D 5.3 85/06/06 22:28:35 karels 7 6
c remove old in_addr structure, update for class B, C nets
e
s 00002/00002/00451
d D 5.2 85/05/28 14:50:26 dist 6 5
c Add copyright
e
s 00013/00001/00440
d D 5.1 85/05/28 14:47:30 dist 5 4
c Add copyright
e
s 00001/00001/00440
d D 4.4 83/07/01 23:58:52 sam 4 3
c include fix
e
s 00003/00001/00438
d D 4.3 82/11/14 15:06:44 sam 3 2
c add sccsid stuff
e
s 00016/00015/00423
d D 4.2 82/11/14 15:04:36 sam 2 1
c conversion to 4.1c sys calls and directory structure + misc 
c 	cleanups
e
s 00438/00000/00000
d D 4.1 82/04/04 19:30:10 sam 1 0
c date and time created 82/04/04 19:30:10 by sam
e
u
U
t
T
I 5
/*
D 6
 * Copyright (c) 1980 Regents of the University of California.
E 6
I 6
D 12
 * Copyright (c) 1983 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
D 14
 * Copyright (c) 1983,1988 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 14
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
E 12
 */

E 5
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
D 3
/*	implog.c	4.1	82/04/04	*/
E 3
I 3
#ifndef lint
I 5
char copyright[] =
D 6
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 6
I 6
D 12
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 12
I 12
D 14
"%Z% Copyright (c) 1983,1988 Regents of the University of California.\n\
E 14
I 14
"%Z% Copyright (c) 1983, 1988 Regents of the University of California.\n\
E 14
E 12
E 6
 All rights reserved.\n";
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14

#ifndef lint
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif
E 5
I 5
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14
E 5
E 3
E 2

#include <stdio.h>
D 4
#include <time.h>
E 4
#include <signal.h>
#include <sgtty.h>
I 2

I 4
#include <sys/time.h>
E 4
E 2
#include <sys/types.h>
I 13
#include <sys/file.h>
E 13
#include <sys/stat.h>
#include <sys/socket.h>
D 2
#include <net/in.h>
E 2
I 2

I 11
#include <net/if.h>

E 11
#include <netinet/in.h>
I 11
#define	IMPMESSAGES
E 11
E 2
#define	IMPLEADERS
D 2
#include <net/if_imp.h>
E 2
I 2
#include <netimp/if_imp.h>
E 2

#define	min(a, b)	((a) < (b) ? (a) : (b))

u_char	buf[1024];
int	showdata = 1;
int	showcontents = 0;
I 8
int	rawheader = 0;
E 8
int	follow = 0;
I 13
int	skip = 0;
E 13
int	link = -1;
int	host = -1;
int	imp = -1;
int	packettype = -1;
extern	int errno;
int	log;
char	*logfile = "/usr/adm/implog";

/*
 * Socket address, internet style, with
 * unused space taken by timestamp and packet
 * size.
 */
struct sockstamp {
	short	sin_family;
	u_short	sin_port;
	struct	in_addr sin_addr;
	time_t	sin_time;
	int	sin_cc;
};
struct	sockstamp from;

main(argc, argv)
	char *argv[];
{
	struct stat b;
D 13
	int size;
E 13
I 13
	off_t size;
E 13
	char *cp;
I 7
	int hostfrom, impfrom;
E 7

	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		if (strcmp(*argv, "-D") == 0) {
			showdata = 0;
			argv++, argc--;
			continue;
		}
		if (strcmp(*argv, "-f") == 0) {
			follow++;
			argv++, argc--;
			continue;
		}
I 13
		if (strcmp(*argv, "-F") == 0) {
			skip++;
			follow++;
			argv++, argc--;
			continue;
		}
E 13
		if (strcmp(*argv, "-c") == 0) {
			showcontents++;
			argv++, argc--;
			continue;
		}
I 8
		if (strcmp(*argv, "-r") == 0) {
			rawheader++;
			argv++, argc--;
			continue;
		}
E 8
		if (strcmp(*argv, "-l") == 0) {
			argc--, argv++;
			if (argc > 0) {
				link = atoi(*argv);
				argc--, argv++;
			} else
				link = IMPLINK_IP;
			continue;
		}
		if (strcmp(*argv, "-h") == 0) {
			argc--, argv++;
			if (argc < 1) {
				printf("-h: missing host #\n");
				exit(2);
			}
			host = atoi(*argv);
			argv++, argc--;
			continue;
		}
		if (strcmp(*argv, "-i") == 0) {
			argc--, argv++;
			if (argc < 1) {
				printf("-i: missing imp #\n");
				exit(2);
			}
			imp = atoi(*argv);
			argv++, argc--;
			continue;
		}
		if (strcmp(*argv, "-t") == 0) {
			argc--, argv++;;
			if (argc < 1) {
				printf("-t: missing packet type\n");
				exit(2);
			}
			packettype = atoi(*argv);
			argv++, argc--;;
			continue;
		}
D 2
		printf("usage: prlog [ -D ] [ -c ] [ -f ] [-h #] [-i #] [ -t # ] [-l [#]] [logfile]\n");
E 2
I 2
D 8
		printf("usage: implog [ -D ] [ -c ] [ -f ] [-h #] [-i #] [ -t # ] [-l [#]] [logfile]\n");
E 8
I 8
D 13
		printf("usage: implog [ -D ] [ -c ] [ -f ] [ -r ] [-h #] [-i #] [ -t # ] [-l [#]] [logfile]\n");
E 13
I 13
		printf("usage: implog [ -D ] [ -c ] [ -f ] [ -F ] [ -r ] [-h #] [-i #] [ -t # ] [-l [#]] [logfile]\n");
E 13
E 8
E 2
		exit(2);
	}
	if (argc > 0)
		logfile = argv[0];
	log = open(logfile, 0);
	if (log < 0) {
		perror(logfile);
		exit(1);
	}
	fstat(log, &b);
	size = b.st_size;
I 13
	if (skip)
		(void) lseek(log, size, L_SET);
E 13
again:
	while (read(log, (char *)&from, sizeof(from)) == sizeof(from)) {
		if (from.sin_family == 0) {
			printf("restarted: %.24s\n", ctime(&from.sin_time));
			continue;
		}
D 7
		if (host >= 0 && from.sin_addr.s_host != host) {
E 7
I 7
		if (host >= 0) {
			long addr = ntohs(from.sin_addr.s_addr);

			if (IN_CLASSA(addr)) {
				hostfrom = ((addr>>16) & 0xFF);
				impfrom = addr & 0xFF;
			} else if (IN_CLASSB(addr)) {
				hostfrom = ((addr>>8) & 0xFF);
				impfrom = addr & 0xFF;
			} else {
				hostfrom = ((addr>>4) & 0xF);
				impfrom = addr & 0xF;
			}
		}
		if (host >= 0 && hostfrom != host) {
E 7
			lseek(log, from.sin_cc, 1);
			continue;
		}
D 7
		if (imp >= 0) {
			from.sin_addr.s_imp = ntohs(from.sin_addr.s_imp);
			if (from.sin_addr.s_imp != imp) {
				lseek(log, from.sin_cc, 1);
				continue;
			}
E 7
I 7
		if (imp >= 0 && impfrom != imp) {
			lseek(log, from.sin_cc, 1);
			continue;
E 7
		}
		process(log, &from);
	}
	while (follow) {
		fflush(stdout);
		sleep(5);
		fstat(log, &b);
		if (b.st_size > size) {
			size = b.st_size;
			goto again;
		}
	}
}

int	impdata(), impbadleader(), impdown(), impnoop();
int	imprfnm(), impincomplete(), imphostdead(), imphostunreach();
int	impbaddata(), impreset(), impretry(), impnotify(), imptrying();
int	impready(), impundef();

struct	messages {
	u_char	m_type;		/* type of message */
	int	(*m_func)();	/* routine to process message */
} mtypes[] = {
	{ IMPTYPE_DATA,		impdata },
	{ IMPTYPE_BADLEADER,	impbadleader },
	{ IMPTYPE_DOWN,		impdown },
	{ IMPTYPE_NOOP,		impnoop },
	{ IMPTYPE_RFNM,		imprfnm },
	{ IMPTYPE_INCOMPLETE,	impincomplete },
	{ IMPTYPE_HOSTDEAD,	imphostdead },
	{ IMPTYPE_HOSTUNREACH,	imphostunreach },
	{ IMPTYPE_BADDATA,	impbaddata },
	{ IMPTYPE_RESET,	impreset },
	{ IMPTYPE_RETRY,	impretry },
	{ IMPTYPE_NOTIFY,	impnotify },
	{ IMPTYPE_TRYING,	imptrying },
	{ IMPTYPE_READY,	impready },
	{ -1,			impundef }
};

/*
 * Print a packet.
 */
process(l, f)
	int l;
	struct sockstamp *f;
{
	register struct messages *mp;
	struct imp_leader *ip;
I 8
	int (*fn)();
E 8

	if (read(l, (char *)buf, f->sin_cc) != f->sin_cc) {
		perror("read");
		return;
	}
	ip = (struct imp_leader *)buf;
D 2
#if vax
	ip->il_imp = ntohs(ip->il_imp);
#endif
E 2
I 2
D 9
	ip->il_imp = ntohs((u_short)ip->il_imp);
E 9
I 9
	ip->il_imp = ntohs(ip->il_imp);
E 9
E 2
D 8
	for (mp = mtypes; mp->m_type != -1; mp++)
		if (mp->m_type == ip->il_mtype)
			break;
	if (mp->m_type == IMPTYPE_DATA) {
E 8
I 8
	if (ip->il_format != IMP_NFF)
		fn = impundef;
	else {
D 10
		for (mp = mtypes; mp->m_type != -1; mp++)
E 10
I 10
		for (mp = mtypes; mp->m_type != (u_char)-1; mp++)
E 10
			if (mp->m_type == ip->il_mtype)
				break;
		fn = mp->m_func;
	}
	if (ip->il_mtype == IMPTYPE_DATA) {
E 8
		if (link >= 0 && ip->il_link != link)
			return;
		if (!showdata)
			return;
	}
D 8
	if (packettype >= 0 && mp->m_type != packettype)
E 8
I 8
	if (packettype >= 0 && ip->il_mtype != packettype)
E 8
		return;
	printf("%.24s: ", ctime(&f->sin_time));
I 9
	if (f->sin_cc < sizeof(struct control_leader))
		printf("(truncated header, %d bytes): ", f->sin_cc);
E 9
D 8
	(*mp->m_func)(ip, f->sin_cc);
E 8
I 8
	(*fn)(ip, f->sin_cc);
D 9
	if (rawheader && fn != impundef)
E 9
I 9
	if (rawheader && fn != impundef) {
		putchar('\t');
E 9
		impundef(ip, f->sin_cc);
I 9
	}
E 9
E 8
}

impdata(ip, cc)
	register struct imp_leader *ip;
{
D 2
	printf("<%d/%d, DATA, link=", ip->il_host, ntohs(ip->il_imp));
E 2
I 2
D 8
	printf("<%d/%d, DATA, link=", ip->il_host, ntohs((u_short)ip->il_imp));
E 8
I 8
	printf("<DATA, source=%d/%d, link=", ip->il_host, (u_short)ip->il_imp);
E 8
E 2
	if (ip->il_link == IMPLINK_IP)
		printf("ip,");
	else
		printf("%d,", ip->il_link);
D 2
	printf(" len=%d bytes>\n", ntohs(ip->il_length) >> 3);
E 2
I 2
	printf(" len=%d bytes>\n", ntohs((u_short)ip->il_length) >> 3);
E 2
	if (showcontents) {
		register u_char *cp = ((u_char *)ip) + sizeof(*ip);
		register int i;

		i = (ntohs(ip->il_length) >> 3) - sizeof(struct imp_leader);
		cc = min(i, cc);
		printf("data: (%d bytes)", cc);
		for (i = 0; i < cc; i++, cp++) {
			if (i % 25 == 0)
				printf("\n");
			printf("%02x ", *cp);
		}
		putchar('\n');
	}
}

char *badleader[] = {
	"error flip-flop set",
	"message < 80 bits",
	"illegal type field",
	"opposite leader type"
};

impbadleader(ip)
	register struct imp_leader *ip;
{
	printf("bad leader: ");
	if (ip->il_subtype > IMPLEADER_OPPOSITE)
		printf("%x\n", ip->il_subtype);
	else
		printf("%s\n", badleader[ip->il_subtype]);
}

D 11
char *down[] = {
	"in 30 secs",
	"for hardware pm",
	"for software reload",
	"for emergency restart"
};

E 11
impdown(ip)
	register struct imp_leader *ip;
{
	int tdown, tbackup;

D 11
	printf("imp going down %s", down[ip->il_link & IMP_DMASK]);
	tdown = ((ip->il_link >> 2) & 0xf) * 5;
	if (ip->il_link & IMP_DMASK)
E 11
I 11
	printf("imp going down %s", impmessage[ip->il_link & IMP_DMASK]);
	tdown = ((ip->il_link >> IMPDOWN_WHENSHIFT) & IMPDOWN_WHENMASK) *
	    IMPDOWN_WHENUNIT;
	if ((ip->il_link & IMP_DMASK) != IMPDOWN_GOING)
E 11
		printf(" in %d minutes", tdown);
D 11
	tbackup = ip->il_subtype * 5;
E 11
I 11
	tbackup = ip->il_subtype * IMPDOWN_WHENUNIT;
E 11
	printf(": back up ");
	if (tbackup)
		printf("%d minutes\n", tbackup);
	else
		printf("immediately\n");
}

impnoop(ip)
	register struct imp_leader *ip;
{
D 2
	printf("noop: host %d, imp %d\n", ip->il_host, ntohs(ip->il_imp));
E 2
I 2
	printf("noop: host %d, imp %d\n", ip->il_host,
D 8
		ntohs((u_short)ip->il_imp));
E 8
I 8
		(u_short)ip->il_imp);
E 8
E 2
}

imprfnm(ip)
	register struct imp_leader *ip;
{
	printf("rfnm: htype=%x, source=%d/%d, link=",
		ip->il_htype, ip->il_host, ip->il_imp);
	if (ip->il_link == IMPLINK_IP)
		printf("ip,");
	else
D 8
		printf("%x,", ip->il_link);
E 8
I 8
		printf("%d,", ip->il_link);
E 8
	printf(" subtype=%x\n", ip->il_subtype);
}

char *hostdead[] = {
D 2
	"???",
E 2
I 2
	"#0",
E 2
	"ready-line negated",
	"tardy receiving messages",
	"ncc doesn't know host",
	"imp software won't allow messages",
	"host down for scheduled pm",
	"host down for hardware work",
	"host down for software work",
	"host down for emergency restart",
	"host down because of power outage",
	"host stopped at a breakpoint",
	"host down due to hardware failure",
	"host not scheduled to be up",
D 2
	"???",
	"???",
E 2
I 2
	"#13",
	"#14",
E 2
	"host in the process of coming up"
};

imphostdead(ip)
	register struct imp_leader *ip;
{
D 8
	printf("host dead: ");
E 8
I 8
	printf("host %d/%d dead: ", ip->il_host, ip->il_imp);
E 8
	if (ip->il_link & IMP_DMASK)
D 11
		printf("down %s, ", down[ip->il_link & IMP_DMASK]);
E 11
I 11
		printf("down %s, ", impmessage[ip->il_link & IMP_DMASK]);
E 11
	if (ip->il_subtype <= IMPHOST_COMINGUP)
		printf("%s\n", hostdead[ip->il_subtype]);
	else
		printf("subtype=%x\n", ip->il_subtype);
}

char *hostunreach[] = {
	"destination imp can't be reached",
	"destination host isn't up",
	"host doesn't support long leader",
	"communication is prohibited"
};

imphostunreach(ip)
	register struct imp_leader *ip;
{
D 8
	printf("host unreachable: ");
E 8
I 8
	printf("host %d/%d unreachable: ", ip->il_host, ip->il_imp);
E 8
	if (ip->il_subtype <= IMPREACH_PROHIBITED)
		printf("%s\n", hostunreach[ip->il_subtype]);
	else
		printf("subtype=%x\n", ip->il_subtype);
}

impbaddata(ip)
	register struct imp_leader *ip;
{
	printf("error in data: htype=%x, source=%d/%d, link=",
		ip->il_htype, ip->il_host, ip->il_imp);
	if (ip->il_link == IMPLINK_IP)
		printf("ip, ");
	else
D 8
		printf("%x, ", ip->il_link);
E 8
I 8
		printf("%d, ", ip->il_link);
E 8
	printf("subtype=%x\n", ip->il_subtype);
}

char *incomplete[] = {
	"host didn't take data fast enough",
	"message was too long",
	"message transmission time > 15 seconds",
	"imp/circuit failure",
	"no resources within 15 seconds",
	"source imp i/o failure during receipt"
};

impincomplete(ip)
	register struct imp_leader *ip;
{
	printf("incomplete: htype=%x, source=%d/%d, link=",
		ip->il_htype, ip->il_host, ip->il_imp);
	if (ip->il_link == IMPLINK_IP)
		printf("ip,");
	else
D 8
		printf("%x,", ip->il_link);
E 8
I 8
		printf("%d,", ip->il_link);
E 8
	if (ip->il_subtype <= IMPCOMPLETE_IMPIO)
		printf(" %s\n", incomplete[ip->il_subtype]);
	else
		printf(" subtype=%x\n", ip->il_subtype);
}

impreset(ip)
	register struct imp_leader *ip;
{
	printf("reset complete\n");
}

char *retry[] = {
	"imp buffer wasn't available",
	"connection block unavailable"
};

impretry(ip)
	register struct imp_leader *ip;
{
	printf("refused, try again: ");
	if (ip->il_subtype <= IMPRETRY_BLOCK)
		printf("%s\n", retry[ip->il_subtype]);
	else
		printf("subtype=%x\n", ip->il_subtype);
}

char *notify[] = {
D 2
	"???",
	"???",
E 2
I 2
	"#0",
	"#1",
E 2
	"connection not available",
	"reassembly space not available at destination",
	"message number not available",
	"transaction block for message not available"
};

impnotify(ip)
	register struct imp_leader *ip;
{
	printf("refused, will notify: ");
	if (ip->il_subtype <= 5)
		printf("%s\n", notify[ip->il_subtype]);
	else
		printf("subtype=%x\n", ip->il_subtype);
}

imptrying(ip)
	register struct imp_leader *ip;
{
	printf("refused, still trying\n");
}

impready(ip)
	register struct imp_leader *ip;
{
	printf("ready\n");
}

D 9
impundef(ip)
E 9
I 9
impundef(ip, len)
E 9
	register struct imp_leader *ip;
{
	printf("<fmt=%x, net=%x, flags=%x, mtype=", ip->il_format,
		ip->il_network, ip->il_flags);
D 9
	printf("%x, htype=%x, host=%x, imp=%x, link=", ip->il_mtype,
		ip->il_htype, ip->il_host, ip->il_imp);
E 9
I 9
	printf("%x, htype=%x,\n\t host=%d(x%x), imp=%d(x%x), link=",
		ip->il_mtype, ip->il_htype, ip->il_host, ip->il_host,
		ip->il_imp, ip->il_imp);
E 9
	if (ip->il_link == IMPLINK_IP)
		printf("ip,");
	else
D 8
		printf("%x,", ip->il_link);
E 8
I 8
D 9
		printf("%d,", ip->il_link);
E 8
	printf(" subtype=%x>\n", ip->il_subtype);
E 9
I 9
		printf("%d (x%x),", ip->il_link, ip->il_link);
	printf(" subtype=%x", ip->il_subtype);
	if (len >= sizeof(struct imp_leader) && ip->il_length)
		printf(" len=%d bytes", ntohs((u_short)ip->il_length) >> 3);
	printf(">\n");
E 9
}
E 1
