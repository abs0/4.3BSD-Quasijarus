/*
 * Zone transfer puller utility
 *
 * This program connects to a DNS server and requests an AXFR of a zone.  It
 * reads all resource records sent by the server and stores them in an
 * MSDNS binary zone file.  (The output is written sequentially as AXFR
 * messages trickle in, and can go to stdout as well - but it's binary!)
 * The received RRs are processed lightly: we parse those fields where
 * compressed domain-names may exist and expand them, but otherwise we
 * write the received binary RRs w/o interpretation.
 *
 * This program may be invoked by the user, but it's also invoked by
 * the MSDNS core daemon when it needs to do an AXFR pull.  In this
 * case the output is directed to stdout even though it's actually
 * going to a file: mkstemp() is used, and it has to be managed by the
 * MSDNS process.  When we are invoked from MSDNS, we also have to use
 * syslog for errors, as stderr will be going to /dev/null.
 *
 * Written by Michael Sokolov, Quasijarus Project, IFCTF.
 */

#ifndef lint
static char sccsid[] = "@(#)zonexfer.c	5.4 (IFCTF) 2011/12/24";
#endif

#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <syslog.h>

extern char *malloc();

int sock, debug, nodepermsg;
int errors_via_syslog;
u_char question[512];
int questionlen;
u_char msgbuf[65535];
int msglen;
int msgcnt, gotsoa;
FILE *outf;

u_char *processrr(), *getdname(), *emitdnamem();

main(argc, argv)
	char **argv;
{
	struct sockaddr_in sin;
	int qclass = C_IN;
	int port = NAMESERVER_PORT;
	extern char *optarg;
	extern int optind;
	register int c;

	while ((c = getopt(argc, argv, "c:dnp:s")) != EOF)
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
		case 'p':
			if (!isdigit(optarg[0]))
				goto usage;
			port = atoi(optarg);
			continue;
		case 's':
			errors_via_syslog = 1;
			continue;
		default:
		usage:
			fprintf(stderr,
		"usage: %s [-cdnps] source-ip zone-domain-name outfile\n",
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
	}

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(argv[optind]);
	if (sin.sin_addr.s_addr == INADDR_NONE)
		goto usage;
	sin.sin_port = htons(port);
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

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		if (errors_via_syslog)
			syslog(LOG_ERR, "socket: %m");
		else
			perror("socket");
		exit(1);
	}
	if (connect(sock, &sin, sizeof(sin)) < 0) {
		if (errors_via_syslog)
			syslog(LOG_ERR, "connect to %s: %m", argv[optind]);
		else
			perror("connect");
		exit(1);
	}
	sendreq();
	for (;;) {
		getmsg();
		processmsg();
	}
}

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

mkquestion(qname, qclass)
	char *qname;
	int qclass;
{
	register int i;
	register u_char *cp;

	i = dn_comp(qname, question, MAXDNAME, NULL, NULL);
	if (i < 0)
		error(LOG_ERR, "%s: invalid domain name\n", qname);
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
err:		if (errors_via_syslog)
			syslog(LOG_ERR, "sending request: %m");
		else
			perror("write to server");
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
err:		if (errors_via_syslog)
			syslog(LOG_ERR, "read: %m");
		else
			perror("read");
		exit(1);
	}
	if (cc == 0) {
eof:		error(LOG_ERR, "EOF before end of zone transfer\n");
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
	if (msglen < sizeof(HEADER))
		error(LOG_ERR, "message shorter than header\n");
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
		error(LOG_ERR, "AXFR failed: format error\n");
	case SERVFAIL:
		error(LOG_ERR, "AXFR failed: server failure\n");
	case NXDOMAIN:
		error(LOG_ERR, "AXFR failed: non-existent domain\n");
	case NOTIMP:
		error(LOG_ERR, "AXFR failed: not implemented\n");
	case REFUSED:
		error(LOG_ERR, "AXFR failed: refused\n");
	default:
		error(LOG_ERR, "AXFR failed: response code %d\n", hdr->rcode);
	}
	if (hdr->tc)
		error(LOG_ERR, "Truncation flag set in AXFR response\n");
	qdcount = ntohs(hdr->qdcount);
	if (qdcount > 1)
		error(LOG_ERR, "AXFR response: QDCOUNT=%d, expected 1 or 0\n",
			qdcount);
	cp = (u_char *)(hdr + 1);
	end = msgbuf + msglen;
	if (qdcount) {
		if ((end-cp) < questionlen || bcmp(question, cp, questionlen))
			error(LOG_ERR,
				"Question echo differs from what was sent\n");
		cp += questionlen;
	}
	ancount = ntohs(hdr->ancount);
	if (!ancount)
		error(LOG_ERR, "message contains no RRs\n");
	for (i = 0; i < ancount; i++)
		cp = processrr(cp, end);
	if (++msgcnt == 1 && !gotsoa)
		error(LOG_ERR, "No SOA in first message of zone transfer\n");
}

u_char *
processrr(cp, end)
	register u_char *cp;
	u_char *end;
{
	u_char name[MAXDNAME], dname[MAXDNAME], *fix, newrdata[1024];
	int type, class;
	int rdlength;
	u_char *endrr;
	register u_char *nrdp;
	static char magic[] = "BINZONE\200";
	static int magic_written;
	u_short us;

	cp = getdname(cp, end, name);
	if (nodepermsg && !msgcnt && dnamecmp(name, question))
		error(LOG_ERR,
"First message of zone transfer describes node other than requested zone\n");
	if (nodepermsg && msgcnt && !dnamecmp(name, question))
		exit(0);	/* repeat, we're done */
	if ((end-cp) < RRFIXEDSZ)
		error(LOG_ERR, "RR fixed part overruns message\n");
	fix = cp;
	GETSHORT(type, cp);
	GETSHORT(class, cp);
	cp += 4;
	GETSHORT(rdlength, cp);
	if (type == T_SOA) {
		if (!gotsoa) {
			if (dnamecmp(name, question))
				error(LOG_ERR,
			"SOA describes node other than requested zone\n");
			gotsoa = 1;
		} else {
			if (!nodepermsg && !dnamecmp(name, question))
				exit(0);	/* finish on SOA repeat */
			error(LOG_ERR, "More than one SOA\n");
		}
	}
	endrr = cp + rdlength;
	if (endrr > end)
		error(LOG_ERR,
			"RDATA as indicated by RDLENGTH overruns message\n");
	if (!magic_written) {
		fwrite(magic, 1, 8, outf);
		magic_written = 1;
	}
	emitdnamef(name);
	fwrite(fix, 1, 8, outf);	/* everything but RDLENGTH */
	nrdp = newrdata;
	switch (type) {
	/* all the simple domain-name ones */
	case T_CNAME:
	case T_MB:
	case T_MD:
	case T_MF:
	case T_MG:
	case T_MR:
	case T_NS:
	case T_PTR:
		cp = getdname(cp, endrr, dname);
		nrdp = emitdnamem(dname, nrdp);
	new_rdata:
		us = htons(nrdp - newrdata);
		fwrite(&us, 1, 2, outf);
		fwrite(newrdata, 1, nrdp - newrdata, outf);
		break;
	case T_MINFO:
	case T_RP:
		cp = getdname(cp, endrr, dname);
		nrdp = emitdnamem(dname, nrdp);
		cp = getdname(cp, endrr, dname);
		nrdp = emitdnamem(dname, nrdp);
		goto new_rdata;
	case T_MX:
	case T_AFSDB:
	case T_RT:
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
	default:
		/* pass it through uninterpreted */
		us = htons(rdlength);
		fwrite(&us, 1, 2, outf);
		fwrite(cp, 1, rdlength, outf);
		cp += rdlength;
	}
	if (cp != endrr)
		warning(LOG_WARNING,
		"declared RDLENGTH doesn't match parsed RDATA length\n");
	return(endrr);
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
		if (cp >= end)
overrun:		error(LOG_ERR, "domain name overruns message\n");
		c = *cp++;
		switch (c & INDIR_MASK) {
		case 0:
			if ((end-cp) < c)
				goto overrun;
			dcnt += c + 1;
			if (dcnt > MAXDNAME) {
				error(LOG_ERR,
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
				error(LOG_ERR,
			"Forward/loop pointer in compressed domain name\n");
				exit(1);
			}
			backref(bp, dp, dcnt);
			return(cp);
		default:
			error(LOG_ERR,
		"Invalid label length octet in compressed domain name\n");
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
overrun:		error(LOG_ERR, "domain name overruns message\n");
			exit(1);
		}
		c = *ptr++;
		switch (c & INDIR_MASK) {
		case 0:
			if ((end-ptr) < c)
				goto overrun;
			dcnt += c + 1;
			if (dcnt > MAXDNAME) {
				error(LOG_ERR,
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
				error(LOG_ERR, "Forward pointer in backref\n");
				exit(1);
			}
			sptr = ptr;
			break;
		default:
			error(LOG_ERR, "Invalid label length in backref\n");
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

emitdnamef(dname)
	u_char *dname;
{
	register u_char *cp;
	register int len, i;

	cp = dname;
	while (len = *cp++) {
		putc(len, outf);
		for (i = 0; i < len; i++)
			putc(*cp++, outf);
	}
	putc(0, outf);
}

u_char *
emitdnamem(dname, dp)
	u_char *dname;
	register u_char *dp;
{
	register u_char *cp;
	register int len, i;

	cp = dname;
	while (len = *cp++) {
		*dp++ = len;
		for (i = 0; i < len; i++)
			*dp++ = *cp++;
	}
	*dp++ = '\0';
	return(dp);
}
