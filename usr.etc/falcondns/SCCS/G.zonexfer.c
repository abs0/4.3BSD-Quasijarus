#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

int debug, sock;
u_char question[512];
int questionlen;
u_char inbuf[65535];
u_char msgbeg[16384+512];
u_long readsofar;

main(argc, argv)
	char **argv;
{
	register char **ap;
	struct sockaddr_in sin;
	char *zonename;
	int qclass = C_IN;

	ap = argv + 1;
	if (*ap && !strcmp(*ap, "-d")) {
		debug = 1;
		ap++;
	}
	sin.sin_family = AF_INET;
	if (!*ap) {
usage:		fprintf(stderr,
			"usage: %s [-d] source-ip zone-domain-name [class]\n",
			argv[0]);
		exit(1);
	}
	sin.sin_addr.s_addr = inet_addr(*ap++);
	if (sin.sin_addr.s_addr == INADDR_NONE)
		goto usage;
	sin.sin_port = htons(NAMESERVER_PORT);
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
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("socket");
		exit(1);
	}
	if (connect(sock, &sin, sizeof(sin)) < 0) {
		perror("connect");
		exit(1);
	}
	sendreq();
	gethdr();
	mainloop();
}

mkquestion(qname, qclass)
	char *qname;
	int qclass;
{
	register int i;
	register u_char *cp;

	i = dn_comp(qname, question, MAXDNAME, NULL, NULL);
	if (i < 0) {
		fprintf(stderr, "%s: invalid domain name\n", qname);
		exit(1);
	}
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
err:		perror("write to server");
		exit(1);
	}
	if (write(sock, &hdr, sizeof(hdr)) != sizeof(hdr))
		goto err;
	if (write(sock, question, questionlen) != questionlen)
		goto err;
}

readin(num, desc)
	register int num;
	char *desc;
{
	register int left, off, cc;

	for (left = num, off = 0; left; left -= cc, off += cc) {
		cc = read(sock, inbuf + off, left);
		if (cc < 0) {
			perror("read");
			exit(1);
		}
		if (cc == 0) {
			fprintf(stderr, "short read (%s)\n", desc);
			exit(1);
		}
	}
	if (readsofar < sizeof(msgbeg)) {
		cc = MAX(num, sizeof(msgbeg) - readsofar);
		bcopy(inbuf, msgbeg + readsofar, cc);
	}
	readsofar += num;
}

gethdr()
{
	register HEADER *hdr;

	readin(sizeof(u_short), "message length");
	if (debug)
		fprintf(stderr, "message length = %d\n",
			ntohs(*(u_short *)inbuf));
	readin(sizeof(HEADER), "response header");
	hdr = (HEADER *) inbuf;
	if (hdr->opcode != QUERY || !hdr->qr) {
		fprintf(stderr, "response to AXFR is not a proper response\n");
		exit(1);
	}
	switch (hdr->rcode) {
	case NOERROR:
		break;
	case FORMERR:
		fprintf(stderr, "AXFR failed: format error\n");
		exit(1);
	case SERVFAIL:
		fprintf(stderr, "AXFR failed: server failure\n");
		exit(1);
	case NXDOMAIN:
		fprintf(stderr, "AXFR failed: non-existent domain\n");
		exit(1);
	case NOTIMP:
		fprintf(stderr, "AXFR failed: not implemented\n");
		exit(1);
	case REFUSED:
		fprintf(stderr, "AXFR failed: refused\n");
		exit(1);
	default:
		fprintf(stderr, "AXFR failed: response code %d\n", hdr->rcode);
		exit(1);
	}
	if (hdr->tc) {
		fprintf(stderr, "Truncation flag set in AXFR response\n");
		exit(1);
	}
	if (debug)
		fprintf(stderr, "AA = %d\n", hdr->aa);
	if (ntohs(hdr->qdcount) != 1) {
		fprintf(stderr, "AXFR response: QDCOUNT=%d, expected 1\n",
			ntohs(hdr->qdcount));
		exit(1);
	}
	if (debug)
		fprintf(stderr, "ANCOUNT=%d, NSCOUNT=%d, ARCOUNT=%d\n",
			ntohs(hdr->ancount), ntohs(hdr->nscount),
			ntohs(hdr->arcount));
	readin(questionlen, "question echo");
	if (bcmp(question, inbuf, questionlen)) {
		fprintf(stderr, "Question echo differs from what was sent\n");
		exit(1);
	}
}

mainloop()
{
	register int c;
	register int type, class, rdlength;
	u_long ttl;
	register char *cp;

	for (;;) {	/* over all RRs in zone */
		/* RR starts with NAME */
		for (;;)	/* over labels of NAME */
			readin(1, "RR NAME label length octet");
			c = inbuf[0];
			switch (c & INDIR_MASK) {
			case 0:
				if (c)
					readin(c, "RR NAME label");
				printlabel(c, inbuf);
				if (c)
					continue;	/* get next label */
				else
					goto gotname;	/* double break */
			case INDIR_MASK:
				break;
			default:
				fprintf(stderr,
					"Invalid label length in RR NAME\n");
				exit(1);
			}
			c &= ~INDIR_MASK;
			readin(1, "low byte of pointer in RR NAME");
			c = (c << 8) | inbuf[0];
			if (c >= readsofar) {
				fprintf(stderr, "Forward pointer in RR NAME\n");
				exit(1);
			}
			backref(c);
			break;
		}
gotname:	readin(RRFIXEDSZ, "RRFIXEDSZ");
		cp = inbuf;
		GETSHORT(type, cp);
		GETSHORT(class, cp);
		GETLONG(ttl, cp);
		GETSHORT(rdlength, cp);
		printf(" %lu ", ttl);


}

backref(start)
	int start;
{
	register int ptr, sptr;
	register int c;

	for (sptr = start, ptr = sptr; ; ) {
		c = msgbeg[ptr++];
		switch (c & INDIR_MASK) {
		case 0:
			if (!c) {
				putchar('.');
				return;
			}
			if (ptr + c >= readsofar || ptr + c >= sizeof(msgbeg)) {
				fprintf(stderr, "backref ran out of msgbeg\n");
				exit(1);
			}
			printlabel(c, msgbeg + ptr);
			ptr += c;
			break;
		case INDIR_MASK:
			if (ptr >= readsofar || ptr >= sizeof(msgbeg)) {
				fprintf(stderr, "backref ran out of msgbeg\n");
				exit(1);
			}
			ptr = ((c&~INDIR_MASK) << 8) | msgbeg[ptr];
			if (ptr >= sptr) {
				fprintf(stderr, "Forward pointer in backref\n");
				exit(1);
			}
			sptr = ptr;
			break;
		default:
			fprintf(stderr, "Invalid label length in backref\n");
			exit(1);
		}
	}
}

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

printlabel(len, body)
	int len;
	char *body;
{
	register u_char *cp; *end;
	register int c;

	for (cp = body, end = cp + len; cp < end; cp++) {
		c = *cp;
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
}
