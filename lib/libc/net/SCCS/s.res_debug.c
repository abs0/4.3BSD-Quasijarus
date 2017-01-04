h23905
s 00010/00005/00478
d D 5.24 88/06/27 17:14:13 bostic 32 31
c install approved copyright notice
e
s 00051/00007/00432
d D 5.23 88/05/19 15:50:13 karels 31 30
c print times in human-readable form (from Nowicki)
e
s 00009/00003/00430
d D 5.22 88/03/07 21:17:19 bostic 30 29
c added Berkeley specific header
e
s 00004/00003/00429
d D 5.21 87/10/22 17:43:24 bostic 29 28
c ANSI C; sprintf now returns an int.
e
s 00002/00002/00430
d D 5.20 87/07/27 10:07:09 bostic 28 27
c DEBUG uses strings
e
s 00002/00004/00430
d D 5.19 87/06/30 11:22:52 karels 27 26
c nslookup uses the strings, put them in but make the names harder to hit
e
s 00024/00022/00410
d D 5.18 87/06/17 14:27:30 bostic 26 24
c opcodes/rcodes static, start with underscore; spaces to tabs
c only included on #ifdef DEBUG, #ifdef's to ANSI
e
s 00013/00013/00419
d D 5.17 87/01/31 15:25:38 kjd 24 23
c change getshort() and getlong() to _getshort() and _getlong()
e
s 00002/00000/00430
d D 5.16 86/12/03 11:33:00 kjd 23 22
c add new opcodes
e
s 00022/00002/00408
d D 5.15 86/11/10 15:36:11 kjd 22 21
c fixes for dynamic updates from Mike Schwartz@washington
e
s 00002/00000/00408
d D 5.14 86/09/16 15:27:33 kjd 21 20
c fix printing address class
e
s 00002/00002/00406
d D 5.13 86/03/09 20:35:34 donn 20 19
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00407
d D 5.12 86/02/07 18:38:11 karels 19 18
c make up out minds: second arg to dn_expand is ptr, is beyond msg
e
s 00001/00001/00407
d D 5.11 86/02/04 09:06:12 kjd 18 16
c Pass msglen to dn_expand
e
s 00001/00001/00407
d R 5.11 86/02/02 19:39:03 kjd 17 16
c pass msglen to dn_expand
e
s 00007/00003/00401
d D 5.10 86/01/18 09:11:30 kjd 16 15
c Fix to MX records
e
s 00009/00000/00395
d D 5.9 86/01/08 11:19:14 kjd 15 14
c Add MX record
e
s 00000/00004/00395
d D 5.8 85/12/01 18:29:42 kjd 14 13
c Not all the debug code gets ifdef'ed jim
e
s 00000/00002/00399
d D 5.7 85/11/01 11:47:02 kjd 13 10
c Freeze for Novebber 1 network distribution
e
s 00000/00002/00399
d R 5.7 85/11/01 11:41:03 kjd 12 10
c Freeze for November 1 network distribution
e
s 00000/00000/00401
d R 6.1 85/10/31 15:29:35 kjd 11 10
c Freeze for November 1 network distribution
e
s 00016/00002/00385
d D 5.6 85/09/14 11:19:33 bloom 10 9
c add ifdef DEBUG around debugging code
e
s 00002/00002/00385
d D 5.5 85/09/11 16:41:17 bloom 9 8
c reverse order of bit in WKS RR
e
s 00001/00001/00386
d D 5.4 85/08/02 10:55:56 kjd 8 7
c Clean up ttl printf in p_rr()
e
s 00078/00068/00309
d D 5.3 85/08/01 11:46:12 kjd 7 6
c Add routine fp_query that will print print the querys to a file
e
s 00001/00001/00376
d D 5.2 85/07/29 17:58:50 kjd 6 5
c Move /usr/include/nameser.h /usr/include/arpa/nameser.h
e
s 00007/00006/00370
d D 5.1 85/05/30 12:05:34 dist 5 4
c Add copyright
e
s 00005/00000/00371
d D 4.4 85/04/01 15:11:02 ralph 4 3
c add copyright notice
e
s 00024/00017/00347
d D 4.3 85/03/29 16:18:54 ralph 3 2
c added MINFO to p_rr()
e
s 00014/00014/00350
d D 4.2 85/03/27 14:58:23 ralph 2 1
c make more machine independent.
e
s 00364/00000/00000
d D 4.1 85/03/01 10:42:12 ralph 1 0
c date and time created 85/03/01 10:42:12 by ralph
e
u
U
t
T
I 1
D 5
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

E 5
I 4
/*
D 5
 * Copyright (c) 1985 Regents of the University of California
 *	All Rights Reserved
E 5
I 5
 * Copyright (c) 1985 Regents of the University of California.
D 30
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 30
I 30
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 32
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 32
I 32
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
E 32
E 30
E 5
 */
I 5

D 20
#ifndef lint
E 20
I 20
#if defined(LIBC_SCCS) && !defined(lint)
E 20
static char sccsid[] = "%W% (Berkeley) %G%";
D 20
#endif not lint
E 20
I 20
D 30
#endif LIBC_SCCS and not lint
E 30
I 30
#endif /* LIBC_SCCS and not lint */
E 30
E 20
E 5

I 10
#if defined(lint) && !defined(DEBUG)
#define DEBUG
#endif

E 10
E 4
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
D 6
#include <nameser.h>
E 6
I 6
#include <arpa/nameser.h>
E 6

D 31
extern char *p_cdname(), *p_rr(), *p_type(), *p_class();
E 31
I 31
extern char *p_cdname(), *p_rr(), *p_type(), *p_class(), *p_time();
E 31
extern char *inet_ntoa();

D 26
char *opcodes[] = {
E 26
I 26
D 27
#ifdef DEBUG
static char *_opcodes[] = {
E 27
I 27
char *_res_opcodes[] = {
E 27
E 26
	"QUERY",
	"IQUERY",
	"CQUERYM",
	"CQUERYU",
	"4",
	"5",
	"6",
	"7",
	"8",
D 22
	"9",
	"10",
E 22
	"UPDATEA",
	"UPDATED",
I 23
	"UPDATEDA",
E 23
	"UPDATEM",
I 23
	"UPDATEMA",
E 23
	"ZONEINIT",
	"ZONEREF",
};

D 26
char *rcodes[] = {
E 26
I 26
D 27
static char *_rcodes[] = {
E 27
I 27
char *_res_resultcodes[] = {
E 27
E 26
	"NOERROR",
	"FORMERR",
	"SERVFAIL",
	"NXDOMAIN",
	"NOTIMP",
	"REFUSED",
	"6",
	"7",
	"8",
	"9",
	"10",
	"11",
	"12",
	"13",
	"14",
	"NOCHANGE",
};
I 26
D 27
#endif
E 27
E 26

I 7
p_query(msg)
	char *msg;
{
I 10
#ifdef DEBUG
E 10
	fp_query(msg,stdout);
I 10
#endif
E 10
}

E 7
/*
 * Print the contents of a query.
 * This is intended to be primarily a debugging routine.
 */
D 3
p_query(buf)
	char *buf;
E 3
I 3
D 7
p_query(msg)
E 7
I 7
fp_query(msg,file)
E 7
	char *msg;
I 7
	FILE *file;
E 7
E 3
{
I 10
#ifdef DEBUG
E 10
	register char *cp;
	register HEADER *hp;
	register int n;

	/*
	 * Print header fields.
	 */
D 3
	hp = (HEADER *)buf;
	cp = buf + sizeof(HEADER);
E 3
I 3
	hp = (HEADER *)msg;
	cp = msg + sizeof(HEADER);
E 3
D 7
	printf("HEADER:\n");
	printf("\topcode = %s", opcodes[hp->opcode]);
	printf(", id = %d", ntohs(hp->id));
	printf(", rcode = %s\n", rcodes[hp->rcode]);
	printf("\theader flags: ");
E 7
I 7
	fprintf(file,"HEADER:\n");
D 26
	fprintf(file,"\topcode = %s", opcodes[hp->opcode]);
E 26
I 26
D 28
	fprintf(file,"\topcode = %s", _opcodes[hp->opcode]);
E 28
I 28
	fprintf(file,"\topcode = %s", _res_opcodes[hp->opcode]);
E 28
E 26
	fprintf(file,", id = %d", ntohs(hp->id));
D 26
	fprintf(file,", rcode = %s\n", rcodes[hp->rcode]);
E 26
I 26
D 28
	fprintf(file,", rcode = %s\n", _rcodes[hp->rcode]);
E 28
I 28
	fprintf(file,", rcode = %s\n", _res_resultcodes[hp->rcode]);
E 28
E 26
	fprintf(file,"\theader flags: ");
E 7
	if (hp->qr)
D 7
		printf(" qr");
E 7
I 7
		fprintf(file," qr");
E 7
	if (hp->aa)
D 7
		printf(" aa");
E 7
I 7
		fprintf(file," aa");
E 7
	if (hp->tc)
D 7
		printf(" tc");
E 7
I 7
		fprintf(file," tc");
E 7
	if (hp->rd)
D 7
		printf(" rd");
E 7
I 7
		fprintf(file," rd");
E 7
	if (hp->ra)
D 7
		printf(" ra");
E 7
I 7
		fprintf(file," ra");
E 7
	if (hp->pr)
D 7
		printf(" pr");
	printf("\n\tqdcount = %d", ntohs(hp->qdcount));
	printf(", ancount = %d", ntohs(hp->ancount));
	printf(", nscount = %d", ntohs(hp->nscount));
	printf(", arcount = %d\n\n", ntohs(hp->arcount));
E 7
I 7
		fprintf(file," pr");
	fprintf(file,"\n\tqdcount = %d", ntohs(hp->qdcount));
	fprintf(file,", ancount = %d", ntohs(hp->ancount));
	fprintf(file,", nscount = %d", ntohs(hp->nscount));
	fprintf(file,", arcount = %d\n\n", ntohs(hp->arcount));
E 7
	/*
	 * Print question records.
	 */
	if (n = ntohs(hp->qdcount)) {
D 7
		printf("QUESTIONS:\n");
E 7
I 7
		fprintf(file,"QUESTIONS:\n");
E 7
		while (--n >= 0) {
D 7
			printf("\t");
D 3
			cp = p_cdname(cp, buf);
E 3
I 3
			cp = p_cdname(cp, msg);
E 7
I 7
			fprintf(file,"\t");
			cp = p_cdname(cp, msg, file);
E 7
E 3
			if (cp == NULL)
				return;
D 2
			printf(", type = %s", p_type(ntohs(*(u_short *)cp)));
E 2
I 2
D 7
			printf(", type = %s", p_type(getshort(cp)));
E 7
I 7
D 24
			fprintf(file,", type = %s", p_type(getshort(cp)));
E 24
I 24
			fprintf(file,", type = %s", p_type(_getshort(cp)));
E 24
E 7
E 2
			cp += sizeof(u_short);
D 2
			printf(", class = %s\n\n", p_class(ntohs(*(u_short *)cp)));
E 2
I 2
D 7
			printf(", class = %s\n\n", p_class(getshort(cp)));
E 7
I 7
D 24
			fprintf(file,", class = %s\n\n", p_class(getshort(cp)));
E 24
I 24
			fprintf(file,", class = %s\n\n", p_class(_getshort(cp)));
E 24
E 7
E 2
			cp += sizeof(u_short);
		}
	}
	/*
	 * Print authoritative answer records
	 */
	if (n = ntohs(hp->ancount)) {
D 7
		printf("ANSWERS:\n");
E 7
I 7
		fprintf(file,"ANSWERS:\n");
E 7
		while (--n >= 0) {
D 7
			printf("\t");
D 3
			cp = p_rr(cp, buf);
E 3
I 3
			cp = p_rr(cp, msg);
E 7
I 7
			fprintf(file,"\t");
			cp = p_rr(cp, msg, file);
E 7
E 3
			if (cp == NULL)
				return;
		}
	}
	/*
	 * print name server records
	 */
	if (n = ntohs(hp->nscount)) {
D 7
		printf("NAME SERVERS:\n");
E 7
I 7
		fprintf(file,"NAME SERVERS:\n");
E 7
		while (--n >= 0) {
D 7
			printf("\t");
D 3
			cp = p_rr(cp, buf);
E 3
I 3
			cp = p_rr(cp, msg);
E 7
I 7
			fprintf(file,"\t");
			cp = p_rr(cp, msg, file);
E 7
E 3
			if (cp == NULL)
				return;
		}
	}
	/*
	 * print additional records
	 */
	if (n = ntohs(hp->arcount)) {
D 7
		printf("ADDITIONAL RECORDS:\n");
E 7
I 7
		fprintf(file,"ADDITIONAL RECORDS:\n");
E 7
		while (--n >= 0) {
D 7
			printf("\t");
D 3
			cp = p_rr(cp, buf);
E 3
I 3
			cp = p_rr(cp, msg);
E 7
I 7
			fprintf(file,"\t");
			cp = p_rr(cp, msg, file);
E 7
E 3
			if (cp == NULL)
				return;
		}
	}
I 10
#endif
E 10
}

char *
D 3
p_cdname(cp, buf)
	char *cp, *buf;
E 3
I 3
D 7
p_cdname(cp, msg)
E 7
I 7
p_cdname(cp, msg, file)
E 7
	char *cp, *msg;
I 7
	FILE *file;
E 7
E 3
{
I 10
#ifdef DEBUG
E 10
	char name[MAXDNAME];
	int n;

D 3
	if ((n = dn_expand(buf, cp, name, sizeof(name))) < 0)
E 3
I 3
D 18
	if ((n = dn_expand(msg, cp, name, sizeof(name))) < 0)
E 18
I 18
D 19
	if ((n = dn_expand(msg, 512, cp, name, sizeof(name))) < 0)
E 19
I 19
	if ((n = dn_expand(msg, msg + 512, cp, name, sizeof(name))) < 0)
E 19
E 18
E 3
		return (NULL);
	if (name[0] == '\0') {
		name[0] = '.';
		name[1] = '\0';
	}
D 7
	fputs(name, stdout);
E 7
I 7
	fputs(name, file);
E 7
	return (cp + n);
I 10
#endif
E 10
}

/*
 * Print resource record fields in human readable form.
 */
char *
D 3
p_rr(cp, buf)
	char *cp, *buf;
E 3
I 3
D 7
p_rr(cp, msg)
E 7
I 7
p_rr(cp, msg, file)
E 7
	char *cp, *msg;
I 7
	FILE *file;
E 7
E 3
{
I 10
#ifdef DEBUG
E 10
	int type, class, dlen, n, c;
	struct in_addr inaddr;
	char *cp1;

D 3
	if ((cp = p_cdname(cp, buf)) == NULL)
E 3
I 3
D 7
	if ((cp = p_cdname(cp, msg)) == NULL)
E 7
I 7
	if ((cp = p_cdname(cp, msg, file)) == NULL)
E 7
E 3
		return (NULL);			/* compression error */
D 2
	printf("\n\ttype = %s", p_type(type = ntohs(*(u_short *)cp)));
E 2
I 2
D 7
	printf("\n\ttype = %s", p_type(type = getshort(cp)));
E 7
I 7
D 24
	fprintf(file,"\n\ttype = %s", p_type(type = getshort(cp)));
E 24
I 24
	fprintf(file,"\n\ttype = %s", p_type(type = _getshort(cp)));
E 24
E 7
E 2
	cp += sizeof(u_short);
D 2
	printf(", class = %s", p_class(class = ntohs(*(u_short *)cp)));
E 2
I 2
D 7
	printf(", class = %s", p_class(class = getshort(cp)));
E 7
I 7
D 24
	fprintf(file,", class = %s", p_class(class = getshort(cp)));
E 24
I 24
	fprintf(file,", class = %s", p_class(class = _getshort(cp)));
E 24
E 7
E 2
	cp += sizeof(u_short);
D 2
	printf(", ttl = %d", ntohl(*(u_int *)cp));
E 2
I 2
D 7
	printf(", ttl = %ld", getlong(cp));
E 7
I 7
D 8
	fprintf(file,", ttl = %ld", getlong(cp));
E 8
I 8
D 24
	fprintf(file,", ttl = %u", getlong(cp));
E 24
I 24
D 31
	fprintf(file,", ttl = %u", _getlong(cp));
E 31
I 31
	fprintf(file,", ttl = %s", p_time(cp));
E 31
E 24
E 8
E 7
E 2
	cp += sizeof(u_long);
D 2
	printf(", dlen = %d\n", dlen = ntohs(*(u_short *)cp));
E 2
I 2
D 7
	printf(", dlen = %d\n", dlen = getshort(cp));
E 7
I 7
D 24
	fprintf(file,", dlen = %d\n", dlen = getshort(cp));
E 24
I 24
	fprintf(file,", dlen = %d\n", dlen = _getshort(cp));
E 24
E 7
E 2
	cp += sizeof(u_short);
	cp1 = cp;
	/*
	 * Print type specific data, if appropriate
	 */
	switch (type) {
	case T_A:
		switch (class) {
		case C_IN:
D 2
			inaddr.s_addr = *(u_long *)cp;
E 2
I 2
			bcopy(cp, (char *)&inaddr, sizeof(inaddr));
E 2
			if (dlen == 4) {
D 7
				printf("\tinternet address = %s\n",
E 7
I 7
				fprintf(file,"\tinternet address = %s\n",
E 7
					inet_ntoa(inaddr));
				cp += dlen;
			} else if (dlen == 7) {
D 7
				printf("\tinternet address = %s",
E 7
I 7
				fprintf(file,"\tinternet address = %s",
E 7
					inet_ntoa(inaddr));
D 7
				printf(", protocol = %d", cp[4]);
				printf(", port = %d\n",
E 7
I 7
				fprintf(file,", protocol = %d", cp[4]);
				fprintf(file,", port = %d\n",
E 7
					(cp[5] << 8) + cp[6]);
				cp += dlen;
			}
			break;
I 21
		default:
			cp += dlen;
E 21
		}
		break;
	case T_CNAME:
	case T_MB:
I 16
#ifdef OLDRR
E 16
	case T_MD:
	case T_MF:
I 16
#endif /* OLDRR */
E 16
	case T_MG:
	case T_MR:
	case T_NS:
	case T_PTR:
D 7
		printf("\tdomain name = ");
D 3
		cp = p_cdname(cp, buf);
E 3
I 3
		cp = p_cdname(cp, msg);
E 3
		printf("\n");
E 7
I 7
		fprintf(file,"\tdomain name = ");
		cp = p_cdname(cp, msg, file);
		fprintf(file,"\n");
E 7
		break;

	case T_HINFO:
		if (n = *cp++) {
D 7
			printf("\tCPU=%.*s\n", n, cp);
E 7
I 7
			fprintf(file,"\tCPU=%.*s\n", n, cp);
E 7
			cp += n;
		}
		if (n = *cp++) {
D 7
			printf("\tOS=%.*s\n", n, cp);
E 7
I 7
			fprintf(file,"\tOS=%.*s\n", n, cp);
E 7
			cp += n;
		}
		break;

	case T_SOA:
D 7
		printf("\torigin = ");
D 3
		cp = p_cdname(cp, buf);
E 3
I 3
		cp = p_cdname(cp, msg);
E 3
		printf("\n\tmail addr = ");
D 3
		cp = p_cdname(cp, buf);
E 3
I 3
		cp = p_cdname(cp, msg);
E 3
D 2
		printf("\n\tserial=%d", ntohl(*(u_long *)cp));
E 2
I 2
		printf("\n\tserial=%ld", getlong(cp));
E 7
I 7
		fprintf(file,"\torigin = ");
		cp = p_cdname(cp, msg, file);
		fprintf(file,"\n\tmail addr = ");
		cp = p_cdname(cp, msg, file);
D 24
		fprintf(file,"\n\tserial=%ld", getlong(cp));
E 24
I 24
		fprintf(file,"\n\tserial=%ld", _getlong(cp));
E 24
E 7
E 2
		cp += sizeof(u_long);
D 2
		printf(", refresh=%d", ntohl(*(u_long *)cp));
E 2
I 2
D 7
		printf(", refresh=%ld", getlong(cp));
E 7
I 7
D 24
		fprintf(file,", refresh=%ld", getlong(cp));
E 24
I 24
D 31
		fprintf(file,", refresh=%ld", _getlong(cp));
E 31
I 31
		fprintf(file,", refresh=%s", p_time(cp));
E 31
E 24
E 7
E 2
		cp += sizeof(u_long);
D 2
		printf(", retry=%d", ntohl(*(u_long *)cp));
E 2
I 2
D 7
		printf(", retry=%ld", getlong(cp));
E 7
I 7
D 24
		fprintf(file,", retry=%ld", getlong(cp));
E 24
I 24
D 31
		fprintf(file,", retry=%ld", _getlong(cp));
E 31
I 31
		fprintf(file,", retry=%s", p_time(cp));
E 31
E 24
E 7
E 2
		cp += sizeof(u_long);
D 2
		printf(", expire=%d", ntohl(*(u_long *)cp));
E 2
I 2
D 7
		printf(", expire=%ld", getlong(cp));
E 7
I 7
D 24
		fprintf(file,", expire=%ld", getlong(cp));
E 24
I 24
D 31
		fprintf(file,", expire=%ld", _getlong(cp));
E 31
I 31
		fprintf(file,", expire=%s", p_time(cp));
E 31
E 24
E 7
E 2
		cp += sizeof(u_long);
D 2
		printf(", min=%d\n", ntohl(*(u_long *)cp));
E 2
I 2
D 7
		printf(", min=%ld\n", getlong(cp));
E 7
I 7
D 24
		fprintf(file,", min=%ld\n", getlong(cp));
E 24
I 24
D 31
		fprintf(file,", min=%ld\n", _getlong(cp));
E 31
I 31
		fprintf(file,", min=%s\n", p_time(cp));
E 31
E 24
E 7
E 2
		cp += sizeof(u_long);
I 3
		break;

I 15
	case T_MX:
D 16
		fprintf(file,"\tname = ");
E 16
I 16
D 24
		fprintf(file,"\tpreference = %ld,",getshort(cp));
E 24
I 24
		fprintf(file,"\tpreference = %ld,",_getshort(cp));
E 24
		cp += sizeof(u_short);
		fprintf(file," name = ");
E 16
		cp = p_cdname(cp, msg, file);
D 16
		fprintf(file,", preference = %ld",getlong(cp));
		cp += sizeof(u_long);
E 16
		break;

E 15
	case T_MINFO:
D 7
		printf("\trequests = ");
		cp = p_cdname(cp, msg);
		printf("\n\terrors = ");
		cp = p_cdname(cp, msg);
E 7
I 7
		fprintf(file,"\trequests = ");
		cp = p_cdname(cp, msg, file);
		fprintf(file,"\n\terrors = ");
		cp = p_cdname(cp, msg, file);
E 7
E 3
		break;

	case T_UINFO:
D 7
		printf("\t%s\n", cp);
E 7
I 7
		fprintf(file,"\t%s\n", cp);
E 7
		cp += dlen;
		break;

	case T_UID:
	case T_GID:
		if (dlen == 4) {
D 2
			printf("\t%d\n", ntohl(*(int *)cp));
E 2
I 2
D 7
			printf("\t%ld\n", getlong(cp));
E 7
I 7
D 24
			fprintf(file,"\t%ld\n", getlong(cp));
E 24
I 24
			fprintf(file,"\t%ld\n", _getlong(cp));
E 24
E 7
E 2
			cp += sizeof(int);
		}
		break;

	case T_WKS:
		if (dlen < sizeof(u_long) + 1)
			break;
D 2
		inaddr.s_addr = *(u_long *)cp;
E 2
I 2
		bcopy(cp, (char *)&inaddr, sizeof(inaddr));
E 2
		cp += sizeof(u_long);
D 7
		printf("\tinternet address = %s, protocol = %d\n\t",
E 7
I 7
		fprintf(file,"\tinternet address = %s, protocol = %d\n\t",
E 7
			inet_ntoa(inaddr), *cp++);
		n = 0;
		while (cp < cp1 + dlen) {
			c = *cp++;
			do {
D 9
				if (c & 1)
E 9
I 9
 				if (c & 0200)
E 9
D 7
					printf(" %d", n);
E 7
I 7
					fprintf(file," %d", n);
E 7
D 9
				c >>= 1;
E 9
I 9
 				c <<= 1;
E 9
			} while (++n & 07);
		}
D 7
		putchar('\n');
E 7
I 7
		putc('\n',file);
E 7
		break;

I 22
#ifdef ALLOW_T_UNSPEC
D 26
        case T_UNSPEC:
                {
                        int NumBytes = 8;
                        char *DataPtr;
                        int i;
E 26
I 26
	case T_UNSPEC:
		{
			int NumBytes = 8;
			char *DataPtr;
			int i;
E 26

D 26
                        if (dlen < NumBytes) NumBytes = dlen;
                        fprintf(file, "\tFirst %d bytes of hex data:",
                                NumBytes);
                        for (i = 0, DataPtr = cp; i < NumBytes; i++, DataPtr++)
                                fprintf(file, " %x", *DataPtr);
                        fputs("\n", file);
                        cp += dlen;
                }
                break;
#endif ALLOW_T_UNSPEC
E 26
I 26
			if (dlen < NumBytes) NumBytes = dlen;
			fprintf(file, "\tFirst %d bytes of hex data:",
				NumBytes);
			for (i = 0, DataPtr = cp; i < NumBytes; i++, DataPtr++)
				fprintf(file, " %x", *DataPtr);
			fputs("\n", file);
			cp += dlen;
		}
		break;
#endif /* ALLOW_T_UNSPEC */
E 26

E 22
	default:
D 7
		printf("\t???\n");
E 7
I 7
		fprintf(file,"\t???\n");
E 7
		cp += dlen;
	}
	if (cp != cp1 + dlen)
D 7
		printf("packet size error (%#x != %#x)\n", cp, cp1+dlen);
	printf("\n");
E 7
I 7
		fprintf(file,"packet size error (%#x != %#x)\n", cp, cp1+dlen);
	fprintf(file,"\n");
E 7
	return (cp);
I 10
#endif
E 10
}

D 31
static	char nbuf[20];
E 31
I 31
static	char nbuf[40];
E 31
D 29
extern	char *sprintf();
E 29

/*
 * Return a string for the type
 */
char *
p_type(type)
	int type;
{
D 10

E 10
I 10
D 14
#ifdef DEBUG
E 14
E 10
	switch (type) {
	case T_A:
		return("A");
	case T_NS:		/* authoritative server */
		return("NS");
I 16
#ifdef OLDRR
E 16
	case T_MD:		/* mail destination */
		return("MD");
	case T_MF:		/* mail forwarder */
		return("MF");
I 16
#endif /* OLDRR */
E 16
	case T_CNAME:		/* connonical name */
		return("CNAME");
	case T_SOA:		/* start of authority zone */
		return("SOA");
	case T_MB:		/* mailbox domain name */
		return("MB");
	case T_MG:		/* mail group member */
		return("MG");
I 15
	case T_MX:		/* mail routing info */
		return("MX");
E 15
	case T_MR:		/* mail rename name */
		return("MR");
	case T_NULL:		/* null resource record */
		return("NULL");
	case T_WKS:		/* well known service */
		return("WKS");
	case T_PTR:		/* domain name pointer */
		return("PTR");
	case T_HINFO:		/* host information */
		return("HINFO");
	case T_MINFO:		/* mailbox information */
		return("MINFO");
	case T_AXFR:		/* zone transfer */
		return("AXFR");
	case T_MAILB:		/* mail box */
		return("MAILB");
	case T_MAILA:		/* mail address */
		return("MAILA");
	case T_ANY:		/* matches any type */
		return("ANY");
	case T_UINFO:
		return("UINFO");
	case T_UID:
		return("UID");
	case T_GID:
		return("GID");
I 22
#ifdef ALLOW_T_UNSPEC
D 26
        case T_UNSPEC:
                return("UNSPEC");
#endif ALLOW_T_UNSPEC
E 26
I 26
	case T_UNSPEC:
		return("UNSPEC");
#endif /* ALLOW_T_UNSPEC */
E 26
E 22
	default:
D 29
		return (sprintf(nbuf, "%d", type));
E 29
I 29
		(void)sprintf(nbuf, "%d", type);
		return(nbuf);
E 29
	}
I 10
D 14
#endif
E 14
E 10
}

/*
 * Return a mnemonic for class
 */
char *
p_class(class)
	int class;
{
I 10
D 14
#ifdef DEBUG
E 14
E 10

	switch (class) {
	case C_IN:		/* internet class */
		return("IN");
D 13
	case C_CS:		/* csnet class */
		return("CS");
E 13
	case C_ANY:		/* matches any class */
		return("ANY");
	default:
D 29
		return (sprintf(nbuf, "%d", class));
E 29
I 29
		(void)sprintf(nbuf, "%d", class);
		return(nbuf);
E 29
	}
I 31
}

/*
 * Return a mnemonic for a time to live
 */
char
*p_time(value)
	u_long value;
{
	int secs, mins, hours;
	register char *p;

	secs = value % 60;
	value /= 60;
	mins = value % 60;
	value /= 60;
	hours = value % 24;
	value /= 24;

#define	PLURALIZE(x)	x, (x == 1) ? "" : "s"
	p = nbuf;
	if (value) {
		(void)sprintf(p, "%d day%s", PLURALIZE(value));
		while (*++p);
	}
	if (hours) {
		if (p != nbuf)
			*p++ = ' ';
		(void)sprintf(p, "%d hour%s", PLURALIZE(hours));
		while (*++p);
	}
	if (mins) {
		if (p != nbuf)
			*p++ = ' ';
		(void)sprintf(p, "%d min%s", PLURALIZE(mins));
		while (*++p);
	}
	if (secs) {
		if (p != nbuf)
			*p++ = ' ';
		(void)sprintf(p, "%d sec%s", PLURALIZE(secs));
		while (*++p);
	}
	return(nbuf);
E 31
I 10
D 14
#endif
E 14
E 10
}
I 7
D 10

E 10
E 7
E 1
