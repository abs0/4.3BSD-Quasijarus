h03161
s 00003/00000/00588
d D 5.4 2011/12/24 05:55:38 msokolov 4 3
c decompress domain-names in RDATA of RFC 1183 types
e
s 00009/00003/00579
d D 5.3 2011/12/14 07:22:21 msokolov 3 2
c added -p option for non-standard port numbers
e
s 00228/00329/00354
d D 5.2 11/07/12 19:07:04 msokolov 2 1
c converted to binary format
e
s 00683/00000/00000
d D 5.1 04/01/26 00:14:24 msokolov 1 0
c First working version
e
u
U
t
T
I 1
/*
 * Zone transfer puller utility
 *
 * This program connects to a DNS server and requests an AXFR of a zone.  It
D 2
 * reads all resource records sent by the server, converts them into text form
 * specified in RFC 1035 (master file format) and outputs them on stdout.
E 2
I 2
 * reads all resource records sent by the server and stores them in an
 * MSDNS binary zone file.  (The output is written sequentially as AXFR
 * messages trickle in, and can go to stdout as well - but it's binary!)
 * The received RRs are processed lightly: we parse those fields where
 * compressed domain-names may exist and expand them, but otherwise we
 * write the received binary RRs w/o interpretation.
E 2
 *
I 2
 * This program may be invoked by the user, but it's also invoked by
 * the MSDNS core daemon when it needs to do an AXFR pull.  In this
 * case the output is directed to stdout even though it's actually
 * going to a file: mkstemp() is used, and it has to be managed by the
 * MSDNS process.  When we are invoked from MSDNS, we also have to use
 * syslog for errors, as stderr will be going to /dev/null.
 *
E 2
 * Written by Michael Sokolov, Quasijarus Project, IFCTF.
 */

#ifndef lint
D 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
I 2
static char sccsid[] = "%W% (IFCTF) %E%";
E 2
#endif

#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
I 2
#include <ctype.h>
E 2
#include <stdio.h>
#include <strings.h>
D 2
#include <ctype.h>
E 2
I 2
#include <syslog.h>
E 2

I 2
extern char *malloc();

E 2
int sock, debug, nodepermsg;
I 2
int errors_via_syslog;
E 2
u_char question[512];
int questionlen;
u_char msgbuf[65535];
int msglen;
int msgcnt, gotsoa;
I 2
FILE *outf;
E 2

D 2
u_char *processrr(), *getdname(), *printcharstring();
E 2
I 2
u_char *processrr(), *getdname(), *emitdnamem();
E 2

main(argc, argv)
	char **argv;
{
D 2
	register char **ap;
E 2
	struct sockaddr_in sin;
D 2
	char *zonename;
E 2
	int qclass = C_IN;
I 3
	int port = NAMESERVER_PORT;
E 3
I 2
	extern char *optarg;
	extern int optind;
	register int c;
E 2

D 2
	ap = argv + 1;
	sin.sin_family = AF_INET;
	if (*ap && !strcmp(*ap, "-d")) {
		debug = 1;
		ap++;
E 2
I 2
D 3
	while ((c = getopt(argc, argv, "c:dns")) != EOF)
E 3
I 3
	while ((c = getopt(argc, argv, "c:dnp:s")) != EOF)
E 3
		switch (c) {
		case 'c':
			if (!isdigit(optarg[0]))
				goto usage;
			qclass = atoi(optarg);
			continue;
		case 'd':
			debug = 1;
			continue;
		case 'n':
			nodepermsg = 1;
			continue;
I 3
		case 'p':
			if (!isdigit(optarg[0]))
				goto usage;
			port = atoi(optarg);
			continue;
E 3
		case 's':
			errors_via_syslog = 1;
			continue;
		default:
		usage:
			fprintf(stderr,
D 3
		"usage: %s [-cdns] source-ip zone-domain-name outfile\n",
E 3
I 3
		"usage: %s [-cdnps] source-ip zone-domain-name outfile\n",
E 3
				argv[0]);
			exit(1);
		}
	if (argc - optind != 3)
		goto usage;

	if (errors_via_syslog) {
		char *ident;
		static char prefix[] = "AXFR pull ";
		int malloclen;

		malloclen = strlen(prefix) + strlen(argv[optind+1]) + 1;
		ident = malloc(malloclen);
		if (!ident) {
			syslog(LOG_DAEMON|LOG_CRIT,
			"zonexfer: malloc failure for openlog ident: %m");
			exit(1);
		}
		strcpy(ident, prefix);
		strcat(ident, argv[optind+1]);
		openlog(ident, 0, LOG_DAEMON);
E 2
	}
D 2
	if (*ap && !strcmp(*ap, "-n")) {
		nodepermsg = 1;
		ap++;
	}
	if (debug)
		setbuf(stdout, NULL);
	if (!*ap) {
usage:		fprintf(stderr,
			"usage: %s source-ip zone-domain-name [class]\n",
			argv[0]);
		exit(1);
	}
	sin.sin_addr.s_addr = inet_addr(*ap++);
E 2
I 2

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(argv[optind]);
E 2
	if (sin.sin_addr.s_addr == INADDR_NONE)
		goto usage;
D 3
	sin.sin_port = htons(NAMESERVER_PORT);
E 3
I 3
	sin.sin_port = htons(port);
E 3
D 2
	if (!*ap)
		goto usage;
	zonename = *ap++;
	if (*ap) {
		if (!isdigit(**ap))
			goto usage;
		qclass = atoi(*ap++);
		if (*ap)
			goto usage;
	}
	mkquestion(zonename, qclass);
E 2
I 2
	mkquestion(argv[optind+1], qclass);

	if (strcmp(argv[optind+2], "-")) {
		outf = fopen(argv[optind+2], "w");
		if (!outf) {
			if (errors_via_syslog)
				syslog(LOG_ERR, "open output file %s: %m",
					argv[optind+2]);
			else
				perror(argv[optind+2]);
			exit(1);
		}
	} else
		outf = stdout;

E 2
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
D 2
		perror("socket");
E 2
I 2
		if (errors_via_syslog)
			syslog(LOG_ERR, "socket: %m");
		else
			perror("socket");
E 2
		exit(1);
	}
	if (connect(sock, &sin, sizeof(sin)) < 0) {
D 2
		perror("connect");
E 2
I 2
		if (errors_via_syslog)
			syslog(LOG_ERR, "connect to %s: %m", argv[optind]);
		else
			perror("connect");
E 2
		exit(1);
	}
	sendreq();
	for (;;) {
		getmsg();
		processmsg();
	}
}

I 2
error(sev, msg, arg1, arg2, arg3, arg4, arg5, arg6)
	char *msg;
{
	if (errors_via_syslog)
		syslog(sev, msg, arg1, arg2, arg3, arg4, arg5, arg6);
	else
		fprintf(stderr, msg, arg1, arg2, arg3, arg4, arg5, arg6);
	exit(1);
}

warning(sev, msg, arg1, arg2, arg3, arg4, arg5, arg6)
	char *msg;
{
	if (errors_via_syslog)
		syslog(sev, msg, arg1, arg2, arg3, arg4, arg5, arg6);
	else
		fprintf(stderr, msg, arg1, arg2, arg3, arg4, arg5, arg6);
}

E 2
mkquestion(qname, qclass)
	char *qname;
	int qclass;
{
	register int i;
	register u_char *cp;

	i = dn_comp(qname, question, MAXDNAME, NULL, NULL);
D 2
	if (i < 0) {
		fprintf(stderr, "%s: invalid domain name\n", qname);
		exit(1);
	}
E 2
I 2
	if (i < 0)
		error(LOG_ERR, "%s: invalid domain name\n", qname);
E 2
	cp = question + i;
	PUTSHORT(T_AXFR, cp);
	PUTSHORT(qclass, cp);
	questionlen = cp - question;
}

sendreq()
{
	HEADER hdr;
	u_short reqlen;

	bzero(&hdr, sizeof(hdr));
	hdr.opcode = QUERY;
	hdr.qdcount = htons(1);
	reqlen = htons(sizeof(hdr) + questionlen);
	if (write(sock, &reqlen, sizeof(reqlen)) != sizeof(reqlen)) {
D 2
err:		perror("write to server");
E 2
I 2
err:		if (errors_via_syslog)
			syslog(LOG_ERR, "sending request: %m");
		else
			perror("write to server");
E 2
		exit(1);
	}
	if (write(sock, &hdr, sizeof(hdr)) != sizeof(hdr))
		goto err;
	if (write(sock, question, questionlen) != questionlen)
		goto err;
}

getmsg()
{
	u_short rawmsglen;
	register int cc, left, off;

	cc = read(sock, &rawmsglen, 2);
	if (cc < 0) {
D 2
err:		perror("read");
E 2
I 2
err:		if (errors_via_syslog)
			syslog(LOG_ERR, "read: %m");
		else
			perror("read");
E 2
		exit(1);
	}
	if (cc == 0) {
D 2
eof:		fprintf(stderr, "EOF before end of zone transfer\n");
E 2
I 2
eof:		error(LOG_ERR, "EOF before end of zone transfer\n");
E 2
		exit(1);
	}
	if (cc == 1) {
		cc = read(sock, &rawmsglen + 1, 1);
		if (cc < 0)
			goto err;
		if (cc == 0)
			goto eof;
	}
	msglen = ntohs(rawmsglen);
D 2
	if (msglen < sizeof(HEADER)) {
		fprintf(stderr, "message shorter than header\n");
		exit(1);
	}
E 2
I 2
	if (msglen < sizeof(HEADER))
		error(LOG_ERR, "message shorter than header\n");
E 2
	for (left = msglen, off = 0; left; left -= cc, off += cc) {
		cc = read(sock, msgbuf + off, left);
		if (cc < 0)
			goto err;
		if (cc == 0)
			goto eof;
	}
}

processmsg()
{
	register HEADER *hdr;
	register u_char *cp, *end;
	int qdcount;
	register int ancount, i;

	if (debug) {
		printf("got message\n");
		for (i = 0; i < sizeof(HEADER); i++)
			printf(" %02X", msgbuf[i]);
		putchar('\n');
	}
	hdr = (HEADER *) msgbuf;
#if 0
	if (hdr->opcode != QUERY || !hdr->qr) {
		fprintf(stderr, "response to AXFR is not a proper response\n");
		exit(1);
	}
#endif
	switch (hdr->rcode) {
	case NOERROR:
		break;
	case FORMERR:
D 2
		fprintf(stderr, "AXFR failed: format error\n");
		exit(1);
E 2
I 2
		error(LOG_ERR, "AXFR failed: format error\n");
E 2
	case SERVFAIL:
D 2
		fprintf(stderr, "AXFR failed: server failure\n");
		exit(1);
E 2
I 2
		error(LOG_ERR, "AXFR failed: server failure\n");
E 2
	case NXDOMAIN:
D 2
		fprintf(stderr, "AXFR failed: non-existent domain\n");
		exit(1);
E 2
I 2
		error(LOG_ERR, "AXFR failed: non-existent domain\n");
E 2
	case NOTIMP:
D 2
		fprintf(stderr, "AXFR failed: not implemented\n");
		exit(1);
E 2
I 2
		error(LOG_ERR, "AXFR failed: not implemented\n");
E 2
	case REFUSED:
D 2
		fprintf(stderr, "AXFR failed: refused\n");
		exit(1);
E 2
I 2
		error(LOG_ERR, "AXFR failed: refused\n");
E 2
	default:
D 2
		fprintf(stderr, "AXFR failed: response code %d\n", hdr->rcode);
		exit(1);
E 2
I 2
		error(LOG_ERR, "AXFR failed: response code %d\n", hdr->rcode);
E 2
	}
D 2
	if (hdr->tc) {
		fprintf(stderr, "Truncation flag set in AXFR response\n");
		exit(1);
	}
E 2
I 2
	if (hdr->tc)
		error(LOG_ERR, "Truncation flag set in AXFR response\n");
E 2
	qdcount = ntohs(hdr->qdcount);
D 2
	if (qdcount > 1) {
		fprintf(stderr, "AXFR response: QDCOUNT=%d, expected 1 or 0\n",
E 2
I 2
	if (qdcount > 1)
		error(LOG_ERR, "AXFR response: QDCOUNT=%d, expected 1 or 0\n",
E 2
			qdcount);
D 2
		exit(1);
	}
E 2
	cp = (u_char *)(hdr + 1);
	end = msgbuf + msglen;
	if (qdcount) {
D 2
		if ((end-cp) < questionlen || bcmp(question, cp, questionlen)) {
			fprintf(stderr,
E 2
I 2
		if ((end-cp) < questionlen || bcmp(question, cp, questionlen))
			error(LOG_ERR,
E 2
				"Question echo differs from what was sent\n");
D 2
			exit(1);
		}
E 2
		cp += questionlen;
	}
	ancount = ntohs(hdr->ancount);
D 2
	if (!ancount) {
		fprintf(stderr, "message contains no RRs\n");
		exit(1);
	}
E 2
I 2
	if (!ancount)
		error(LOG_ERR, "message contains no RRs\n");
E 2
	for (i = 0; i < ancount; i++)
		cp = processrr(cp, end);
D 2
	if (++msgcnt == 1 && !gotsoa) {
		fprintf(stderr, "No SOA in first message of zone transfer\n");
		exit(1);
	}
E 2
I 2
	if (++msgcnt == 1 && !gotsoa)
		error(LOG_ERR, "No SOA in first message of zone transfer\n");
E 2
}

u_char *
processrr(cp, end)
D 2
	register u_char *cp, *end;
E 2
I 2
	register u_char *cp;
	u_char *end;
E 2
{
D 2
	u_char name[MAXDNAME], dname[MAXDNAME];
	u_long ttl, ul;
E 2
I 2
	u_char name[MAXDNAME], dname[MAXDNAME], *fix, newrdata[1024];
E 2
	int type, class;
	int rdlength;
D 2
	register u_char *endrr;
	register int i, c, m;
E 2
I 2
	u_char *endrr;
	register u_char *nrdp;
	static char magic[] = "BINZONE\200";
	static int magic_written;
	u_short us;
E 2

	cp = getdname(cp, end, name);
D 2
	if (nodepermsg && !msgcnt && dnamecmp(name, question)) {
		fprintf(stderr,
E 2
I 2
	if (nodepermsg && !msgcnt && dnamecmp(name, question))
		error(LOG_ERR,
E 2
"First message of zone transfer describes node other than requested zone\n");
D 2
		exit(1);
	}
E 2
	if (nodepermsg && msgcnt && !dnamecmp(name, question))
		exit(0);	/* repeat, we're done */
D 2
	if ((end-cp) < RRFIXEDSZ) {
		fprintf(stderr, "RR fixed part overruns message\n");
		exit(1);
	}
E 2
I 2
	if ((end-cp) < RRFIXEDSZ)
		error(LOG_ERR, "RR fixed part overruns message\n");
	fix = cp;
E 2
	GETSHORT(type, cp);
	GETSHORT(class, cp);
D 2
	GETLONG(ttl, cp);
E 2
I 2
	cp += 4;
E 2
	GETSHORT(rdlength, cp);
	if (type == T_SOA) {
		if (!gotsoa) {
D 2
			if (dnamecmp(name, question)) {
				fprintf(stderr,
E 2
I 2
			if (dnamecmp(name, question))
				error(LOG_ERR,
E 2
			"SOA describes node other than requested zone\n");
D 2
				exit(1);
			}
E 2
			gotsoa = 1;
		} else {
			if (!nodepermsg && !dnamecmp(name, question))
				exit(0);	/* finish on SOA repeat */
D 2
			fprintf(stderr, "More than one SOA\n");
			exit(1);
E 2
I 2
			error(LOG_ERR, "More than one SOA\n");
E 2
		}
	}
D 2
	printdname(name);
E 2
	endrr = cp + rdlength;
D 2
	if (endrr > end) {
		fprintf(stderr,
E 2
I 2
	if (endrr > end)
		error(LOG_ERR,
E 2
			"RDATA as indicated by RDLENGTH overruns message\n");
D 2
		exit(1);
E 2
I 2
	if (!magic_written) {
		fwrite(magic, 1, 8, outf);
		magic_written = 1;
E 2
	}
D 2
	if (ttl)
		printf(" %lu", ttl);
	putchar(' ');
	switch (class) {
	case C_IN:
		printf("IN");
		break;
	case C_CS:
		printf("CS");
		break;
	case C_CHAOS:
		printf("CH");
		break;
	case C_HS:
		printf("HS");
		break;
	default:
		printf("C%d", class);
	}
	putchar(' ');
E 2
I 2
	emitdnamef(name);
	fwrite(fix, 1, 8, outf);	/* everything but RDLENGTH */
	nrdp = newrdata;
E 2
	switch (type) {
I 2
	/* all the simple domain-name ones */
E 2
	case T_CNAME:
D 2
		printf("CNAME");
		goto domain;
	case T_HINFO:
		printf("HINFO ");
		cp = printcharstring(cp, end);
		putchar(' ');
		cp = printcharstring(cp, end);
		goto checkrdlen;
E 2
	case T_MB:
D 2
		printf("MB");
		goto domain;
E 2
	case T_MD:
D 2
		printf("MD");
		goto domain;
E 2
	case T_MF:
D 2
		printf("MF");
		goto domain;
E 2
	case T_MG:
D 2
		printf("MG");
		goto domain;
	case T_MINFO:
		printf("MINFO ");
		cp = getdname(cp, end, dname);
		printdname(dname);
		putchar(' ');
		cp = getdname(cp, end, dname);
		printdname(dname);
		goto checkrdlen;
E 2
	case T_MR:
D 2
		printf("MR");
		goto domain;
	case T_MX:
		printf("MX ");
		if ((end-cp) < sizeof(u_short)) {
miscoverrun:		fprintf(stderr, "RR misc data overruns message\n");
			exit(1);
		}
		GETSHORT(i, cp);
		printf("%d", i);
		goto domain;
E 2
	case T_NS:
D 2
		printf("NS");
		goto domain;
E 2
	case T_PTR:
D 2
		printf("PTR");
		goto domain;
	case T_SOA:
		printf("SOA ");
		cp = getdname(cp, end, dname);
		printdname(dname);
		putchar(' ');
		cp = getdname(cp, end, dname);
		printdname(dname);
		if ((end-cp) < sizeof(u_long) * 5)
			goto miscoverrun;
		for (i = 0; i < 5; i++) {
			GETLONG(ul, cp);
			printf(" %lu", ul);
		}
		goto checkrdlen;
	case T_TXT:
		printf("TXT (\n");
		if (!rdlength) {
			fprintf(stderr, "Zero-length TXT record\n");
			exit(1);
		}
		for (;;) {
			putchar('\t');
			cp = printcharstring(cp, end);
			putchar('\n');
			if (cp == endrr)
				break;
			if (cp > endrr) {
				fprintf(stderr,
	"A character-string in TXT record overruns the record length\n");
				exit(1);
			}
		}
		putchar('\t');
		putchar(')');
E 2
I 2
		cp = getdname(cp, endrr, dname);
		nrdp = emitdnamem(dname, nrdp);
	new_rdata:
		us = htons(nrdp - newrdata);
		fwrite(&us, 1, 2, outf);
		fwrite(newrdata, 1, nrdp - newrdata, outf);
E 2
		break;
D 2
	case T_A:
		if (class != C_IN)
			goto unknown;
		if ((end-cp) < 4)
			goto miscoverrun;
		printf("A %d.%d.%d.%d", *cp++, *cp++, *cp++, *cp++);
		goto checkrdlen;
	case T_WKS:
		if (class != C_IN)
			goto unknown;
		if (rdlength < 5 + 1 || rdlength > 5 + 8192) {
			fprintf(stderr, "WKS record has invalid length\n");
			exit(1);
		}
		printf("WKS %d.%d.%d.%d %d (\n", *cp++, *cp++, *cp++, *cp++,
			*cp++);
		for (i = 0; cp < endrr; ) {
			c = *cp++;
			if (!c) {
				i += 8;
				continue;
			}
			putchar('\t');
			for (m = 0x80; m; m >>= 1) {
				if (c & m)
					printf(" %d", i);
				i++;
			}
			putchar('\n');
		}
		putchar('\t');
		putchar(')');
		break;
	domain:
		putchar(' ');
		cp = getdname(cp, end, dname);
		printdname(dname);
	checkrdlen:
		if (cp != endrr) {
			fprintf(stderr,
				"RDLENGTH disagrees with record data\n");
			exit(1);
		}
		break;
E 2
I 2
	case T_MINFO:
I 4
	case T_RP:
E 4
		cp = getdname(cp, endrr, dname);
		nrdp = emitdnamem(dname, nrdp);
		cp = getdname(cp, endrr, dname);
		nrdp = emitdnamem(dname, nrdp);
		goto new_rdata;
	case T_MX:
I 4
	case T_AFSDB:
	case T_RT:
E 4
		*nrdp++ = *cp++;
		*nrdp++ = *cp++;
		cp = getdname(cp, endrr, dname);
		nrdp = emitdnamem(dname, nrdp);
		goto new_rdata;
	case T_SOA:
		cp = getdname(cp, endrr, dname);
		nrdp = emitdnamem(dname, nrdp);
		cp = getdname(cp, endrr, dname);
		nrdp = emitdnamem(dname, nrdp);
		bcopy(cp, nrdp, 20);
		cp += 20;
		nrdp += 20;
		goto new_rdata;
E 2
	default:
D 2
	unknown:
		printf("T%d", type);
		if (!rdlength)
			break;
		putchar(' ');
		putchar('(');
		for (i = 0; cp < endrr; i++) {
			if (i & 7)
				putchar(' ');
			else {
				putchar('\n');
				putchar('\t');
			}
			printf("%02X", *cp++);
		}
		putchar(' ');
		putchar(')');
E 2
I 2
		/* pass it through uninterpreted */
		us = htons(rdlength);
		fwrite(&us, 1, 2, outf);
		fwrite(cp, 1, rdlength, outf);
		cp += rdlength;
E 2
	}
D 2
	putchar('\n');
	return(cp);
E 2
I 2
	if (cp != endrr)
		warning(LOG_WARNING,
		"declared RDLENGTH doesn't match parsed RDATA length\n");
	return(endrr);
E 2
}

u_char *
getdname(cp, end, dbuf)
	register u_char *cp, *end;
	u_char *dbuf;
{
	register int c;
	register u_char *dp, *bp;
	register int dcnt;

	for (dp = dbuf, dcnt = 0; ; ) {
D 2
		if (cp >= end) {
overrun:		fprintf(stderr, "domain name overruns message\n");
			exit(1);
		}
E 2
I 2
		if (cp >= end)
overrun:		error(LOG_ERR, "domain name overruns message\n");
E 2
		c = *cp++;
		switch (c & INDIR_MASK) {
		case 0:
			if ((end-cp) < c)
				goto overrun;
			dcnt += c + 1;
			if (dcnt > MAXDNAME) {
D 2
				fprintf(stderr,
E 2
I 2
				error(LOG_ERR,
E 2
				"domain name longer than spec maximum\n");
				exit(1);
			}
			*dp++ = c;
			if (c) {
				bcopy(cp, dp, c);
				cp += c;
				dp += c;
			}
			break;
		case INDIR_MASK:
			if (cp >= end)
				goto overrun;
			c = ((c&~INDIR_MASK) << 8) | *cp++;
			bp = msgbuf + c;
			if (bp >= cp - 2) {
D 2
				fprintf(stderr,
E 2
I 2
				error(LOG_ERR,
E 2
			"Forward/loop pointer in compressed domain name\n");
				exit(1);
			}
			backref(bp, dp, dcnt);
			return(cp);
		default:
D 2
			fprintf(stderr,
E 2
I 2
			error(LOG_ERR,
E 2
		"Invalid label length octet in compressed domain name\n");
D 2
			exit(1);
E 2
		}
		if (!c)
			break;
	}
	return(cp);
}

backref(start, dp, dcnt)
	u_char *start;
	register u_char *dp;
	register int dcnt;
{
	register u_char *ptr, *sptr;
	register u_char *end = msgbuf + msglen;
	register int c;

	for (sptr = start, ptr = sptr; ; ) {
		if (ptr >= end) {
D 2
overrun:		fprintf(stderr, "domain name overruns message\n");
E 2
I 2
overrun:		error(LOG_ERR, "domain name overruns message\n");
E 2
			exit(1);
		}
		c = *ptr++;
		switch (c & INDIR_MASK) {
		case 0:
			if ((end-ptr) < c)
				goto overrun;
			dcnt += c + 1;
			if (dcnt > MAXDNAME) {
D 2
				fprintf(stderr,
E 2
I 2
				error(LOG_ERR,
E 2
				"domain name longer than spec maximum\n");
				exit(1);
			}
			*dp++ = c;
			if (c) {
				bcopy(ptr, dp, c);
				ptr += c;
				dp += c;
			} else
				return;
			break;
		case INDIR_MASK:
			if (ptr >= end)
				goto overrun;
			c = ((c&~INDIR_MASK) << 8) | *ptr;
			ptr = msgbuf + c;
			if (ptr >= sptr) {
D 2
				fprintf(stderr, "Forward pointer in backref\n");
E 2
I 2
				error(LOG_ERR, "Forward pointer in backref\n");
E 2
				exit(1);
			}
			sptr = ptr;
			break;
		default:
D 2
			fprintf(stderr, "Invalid label length in backref\n");
E 2
I 2
			error(LOG_ERR, "Invalid label length in backref\n");
E 2
			exit(1);
		}
	}
}

u_char labuctab[256] = {
	'\000', '\001', '\002', '\003', '\004', '\005', '\006', '\007',
	'\010', '\011', '\012', '\013', '\014', '\015', '\016', '\017',
	'\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
	'\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
	'\040', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
	'\050', '\051', '\052', '\053', '\054', '\055', '\056', '\057',
	'\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
	'\070', '\071', '\072', '\073', '\074', '\075', '\076', '\077',
	'\100', '\101', '\102', '\103', '\104', '\105', '\106', '\107',
	'\110', '\111', '\112', '\113', '\114', '\115', '\116', '\117',
	'\120', '\121', '\122', '\123', '\124', '\125', '\126', '\127',
	'\130', '\131', '\132', '\133', '\134', '\135', '\136', '\137',
	'\140', '\101', '\102', '\103', '\104', '\105', '\106', '\107',
	'\110', '\111', '\112', '\113', '\114', '\115', '\116', '\117',
	'\120', '\121', '\122', '\123', '\124', '\125', '\126', '\127',
	'\130', '\131', '\132', '\173', '\174', '\175', '\176', '\177',
	'\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
	'\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
	'\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
	'\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
	'\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
	'\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
	'\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
	'\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
	'\300', '\301', '\302', '\303', '\304', '\305', '\306', '\307',
	'\310', '\311', '\312', '\313', '\314', '\315', '\316', '\317',
	'\320', '\321', '\322', '\323', '\324', '\325', '\326', '\327',
	'\330', '\331', '\332', '\333', '\334', '\335', '\336', '\337',
	'\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
	'\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
	'\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
	'\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377'};

dnamecmp(dn1, dn2)
	u_char *dn1, *dn2;
{
	register u_char *dp1, *dp2;
	register int c, i;

	for (dp1 = dn1, dp2 = dn2; ; ) {
		c = *dp1++;
		if (c != *dp2++)
			return(1);
		if (!c)
			return(0);
		for (i = 0; i < c; i++)
			if (labuctab[*dp1++] != labuctab[*dp2++])
				return(1);
	}
}

D 2
char labchartab[256] = {
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

printdname(dname)
E 2
I 2
emitdnamef(dname)
E 2
	u_char *dname;
{
	register u_char *cp;
D 2
	register int c, len, i;
E 2
I 2
	register int len, i;
E 2

	cp = dname;
	while (len = *cp++) {
D 2
		for (i = 0; i < len; i++) {
			c = *cp++;
			switch (labchartab[c]) {
			case 1:
				putchar('\\');
				/*FALLTHRU*/
			case 0:
				putchar (c);
				break;
			default:
				printf("\\%03d", c);
			}
		}
		putchar('.');
E 2
I 2
		putc(len, outf);
		for (i = 0; i < len; i++)
			putc(*cp++, outf);
E 2
	}
I 2
	putc(0, outf);
E 2
}

u_char *
D 2
printcharstring(cp, end)
	register u_char *cp, *end;
E 2
I 2
emitdnamem(dname, dp)
	u_char *dname;
	register u_char *dp;
E 2
{
D 2
	register int len, i, c;
E 2
I 2
	register u_char *cp;
	register int len, i;
E 2

D 2
	if (cp >= end) {
overrun:	fprintf(stderr,
			"A character-string overruns the record length\n");
		exit(1);
E 2
I 2
	cp = dname;
	while (len = *cp++) {
		*dp++ = len;
		for (i = 0; i < len; i++)
			*dp++ = *cp++;
E 2
	}
D 2
	len = *cp++;
	if ((end-cp) < len)
		goto overrun;
	putchar('\"');
	for (i = 0; i < len; i++) {
		c = *cp++;
		if (isprint(c)) {
			if (c == '\"' || c == '\\')
				putchar('\\');
			putchar(c);
		} else
			printf("\\03d", c);
	}
	putchar('\"');
	return(cp);
E 2
I 2
	*dp++ = '\0';
	return(dp);
E 2
}
E 1
