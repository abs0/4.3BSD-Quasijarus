/*
 * Michael Sokolov's Domain Name Server (MSDNS)
 *
 * This utility "disassembles" an MSDNS binary zone file back into the
 * RFC 1035 text format.  A serious attempt has been made at accepting
 * every possible set of binary RRs and producing a text file that
 * complies with RFC 1035 rules and would produce the same binary RRs
 * if recompiled - the original intent was to store AXFR pulls in text
 * form like BIND does.  However, if an unknown RR type is encountered,
 * it is dumped in a non-standard form.  Now that we have adopted a
 * binary zone format for on-disk storage, the intended use of this
 * utility is only for debugging.
 */

#ifndef lint
static char sccsid[] = "@(#)zonedump.c	1.2 (IFCTF) 2011/07/14";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <ctype.h>

FILE *inf;

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

/*
 * This function reads a domain-name from the binary input stream
 * and dumps it in text form on stdout.  The return value is the
 * number of bytes read from the binary input stream.
 *
 * If an EOF occurs immediately at the beginning, the function returns 0.
 * If an EOF occurs in the middle of the domain-name or if invalid
 * data are read, the process terminates with an error.
 */
process_dname()
{
	int lablen;
	u_long filepos;
	int totlen;
	register int i, c;

	filepos = ftell(inf);
	for (totlen = 0; ; ) {
		lablen = getc(inf);
		if (lablen < 0) {
			if (!totlen)
				return(0);
			fprintf(stderr, "EOF in a domain-name\n");
			exit(1);
		}
		totlen++;
		if (lablen & INDIR_MASK) {
			fprintf(stderr,
		"compressed domain-name encountered at file offset %lu\n",
				filepos);
			exit(1);
		}
		if (!lablen)
			break;
		for (i = 0; i < lablen; i++) {
			c = getc(inf);
			if (c < 0) {
				fprintf(stderr, "EOF in a domain-name label\n");
				exit(1);
			}
			totlen++;
			switch (labchartab[c]) {
			case 1:
				putchar('\\');
				/*FALLTHRU*/
			case 0:
				putchar(c);
				break;
			default:
				printf("\\%03d", c);
			}
		}
		putchar('.');
	}
	if (totlen == 1)	/* must be root */
		putchar('.');
	else if (totlen > 256)
		fprintf(stderr,
"Warning: domain-name at file offset %lu exceeds RFC limit (%d bytes long)\n",
			filepos, totlen);
	return(totlen);
}

/*
 * process_dname_eof() is like regular process_dname(),
 * but any EOF is an error.
 */
process_dname_eof()
{
	register int i;

	i = process_dname();
	if (i)
		return(i);
	fprintf(stderr, "EOF when domain-name expected in an RR\n");
	exit(1);
}

/*
 * This function reads a character-string from the binary input stream
 * and dumps it in text form on stdout.  The return value is the
 * number of bytes read from the binary input stream.
 *
 * An EOF is an error.
 */
process_charstring()
{
	int len;
	register int i, c;

	len = getc(inf);
	if (len < 0) {
badeof:		fprintf(stderr, "EOF in a character-string\n");
		exit(1);
	}
	putchar('"');
	for (i = 0; i < len; i++) {
		c = getc(inf);
		if (c < 0)
			goto badeof;
		if (isprint(c)) {
			if (c == '\"' || c == '\\')
				putchar('\\');
			putchar(c);
		} else
			printf("\\03d", c);
	}
	putchar('"');
	return(len + 1);
}

/*
 * This function reads an RR from the binary input stream and
 * dumps it in text form on stdout.
 *
 * EOF in the normal place between RRs causes exit(0).
 */
process_rr()
{
	struct rrfixed fix;
	int parse_rdlength;
	u_short miscshort;
	u_long misclong;
	struct in_addr ipv4;
	register int i, c, p, m;
	int wkslen;

	if (!process_dname())
		exit(0);
	if (fread(&fix, 1, RRFIXEDSZ, inf) != RRFIXEDSZ) {
		fprintf(stderr, "EOF in RR fixed part\n");
		exit(1);
	}
	fix.type = ntohs(fix.type);
	fix.class = ntohs(fix.class);
	fix.ttl = ntohl(fix.ttl);
	fix.rdlength = ntohs(fix.rdlength);
	if (fix.ttl)
		printf(" %lu", fix.ttl);
	putchar(' ');
	switch (fix.class) {
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
		printf("Class%d", fix.class);
	}
	putchar(' ');
	parse_rdlength = 0;
	switch (fix.type) {
	case T_CNAME:
		printf("CNAME");
	domain:
		putchar(' ');
		parse_rdlength += process_dname_eof();
		break;
	case T_HINFO:
		printf("HINFO ");
		parse_rdlength += process_charstring();
		putchar(' ');
		parse_rdlength += process_charstring();
		break;
	case T_MB:
		printf("MB");
		goto domain;
	case T_MD:
		printf("MD");
		goto domain;
	case T_MF:
		printf("MF");
		goto domain;
	case T_MG:
		printf("MG");
		goto domain;
	case T_MINFO:
		printf("MINFO ");
		parse_rdlength += process_dname_eof();
		putchar(' ');
		parse_rdlength += process_dname_eof();
		break;
	case T_MR:
		printf("MR");
		goto domain;
	case T_MX:
		if (fread(&miscshort, 1, 2, inf) != 2) {
			fprintf(stderr, "EOF reading the MX preference\n");
			exit(1);
		}
		printf("MX %d", ntohs(miscshort));
		parse_rdlength += 2;
		goto domain;
	case T_NS:
		printf("NS");
		goto domain;
	case T_PTR:
		printf("PTR");
		goto domain;
	case T_SOA:
		printf("SOA ");
		parse_rdlength += process_dname_eof();
		putchar(' ');
		parse_rdlength += process_dname_eof();
		for (i = 0; i < 5; i++) {
			if (fread(&misclong, 1, 4, inf) != 4) {
				fprintf(stderr, "EOF reading SOA numbers\n");
				exit(1);
			}
			parse_rdlength += 4;
			printf(" %lu", ntohl(misclong));
		}
		break;
	case T_TXT:
		printf("TXT (\n");
		while (parse_rdlength < fix.rdlength) {
			putchar('\t');
			parse_rdlength += process_charstring();
			putchar('\n');
		}
		putchar('\t');
		putchar(')');
		break;
	case T_A:
		if (fix.class != C_IN)
			goto unknown;
		if (fread(&ipv4, 1, 4, inf) != 4) {
			fprintf(stderr, "EOF reading A record RDATA\n");
			exit(1);
		}
		parse_rdlength += 4;
		printf("A %s", inet_ntoa(ipv4));
		break;
	case T_WKS:
		if (fix.class != C_IN)
			goto unknown;
		if (fix.rdlength < 5 + 1 || fix.rdlength > 5 + 8192) {
			fprintf(stderr, "WKS record has invalid length\n");
			exit(1);
		}
		if (fread(&ipv4, 1, 4, inf) != 4) {
wks_eof:		fprintf(stderr, "EOF reading WKS record RDATA\n");
			exit(1);
		}
		parse_rdlength += 4;
		c = getc(inf);
		if (c < 0)
			goto wks_eof;
		parse_rdlength++;
		printf("WKS %s %d (\n", inet_ntoa(ipv4), c);
		wkslen = fix.rdlength - 5;
		for (p = i = 0; i < wkslen; i++) {
			c = getc(inf);
			if (c < 0)
				goto wks_eof;
			parse_rdlength++;
			if (!c) {
				p += 8;
				continue;
			}
			putchar('\t');
			for (m = 0x80; m; m >>= 1) {
				if (c & m)
					printf(" %d", p);
				p++;
			}
			putchar('\n');
		}
		putchar('\t');
		putchar(')');
		break;
	default:
	unknown:
		printf("Type%d", fix.type);
		if (!fix.rdlength)
			break;
		putchar(' ');
		putchar('(');
		for (i = 0; i < fix.rdlength; i++) {
			if (i & 7)
				putchar(' ');
			else {
				putchar('\n');
				putchar('\t');
			}
			c = getc(inf);
			if (c < 0) {
				fprintf(stderr, "EOF in unknown RDATA\n");
				exit(1);
			}
			parse_rdlength++;
			printf("%02X", c);
		}
		putchar(' ');
		putchar(')');
	}
	putchar('\n');
	if (parse_rdlength != fix.rdlength) {
		fprintf(stderr,
	"Parsed RDATA length (%d) disagrees with declared RDLENGTH (%d)\n",
			parse_rdlength, fix.rdlength);
		exit(1);
	}
}

main(argc, argv)
	char **argv;
{
	static char magic[] = "BINZONE\200";
	char verbuf[8];

	if (argc != 2) {
		fprintf(stderr, "usage: %s binfile\n", argv[0]);
		exit(1);
	}
	inf = fopen(argv[1], "r");
	if (!inf) {
		perror(argv[1]);
		exit(1);
	}
	if (fread(verbuf, 1, 8, inf) != 8 || bcmp(verbuf, magic, 8)) {
		fprintf(stderr, "%s is not an MSDNS binary zone file\n");
		exit(1);
	}
	for (;;)
		process_rr();
}
