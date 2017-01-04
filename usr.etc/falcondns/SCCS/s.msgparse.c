h33421
s 00011/00011/00261
d D 1.6 2013/01/06 08:56:33 msokolov 6 5
c more sensible and consistent msgparse function naming:
c s/extract_dname_from_msg/msgparse_extract_dname/
c s/parse_incoming_rr/msgparse_rdata/
e
s 00001/00001/00271
d D 1.5 2013/01/06 07:04:06 msokolov 5 4
c MSDNS => FalconDNS
e
s 00003/00000/00269
d D 1.4 2011/12/23 07:36:28 msokolov 4 3
c parsing new RR types
e
s 00062/00000/00207
d D 1.3 2011/12/02 06:40:17 msokolov 3 2
c parse_incoming_rr() implemented
e
s 00135/00000/00072
d D 1.2 2011/12/02 05:48:58 msokolov 2 1
c extract_dname_from_msg() moved from dname.c to msgparse.c
e
s 00072/00000/00000
d D 1.1 2011/11/07 19:52:10 msokolov 1 0
c date and time created 2011/11/07 19:52:10 by msokolov
e
u
U
t
T
I 1
/*
D 5
 * Michael Sokolov's Domain Name Server (MSDNS)
E 5
I 5
 * FalconDNS daemon by Michael Spacefalcon
E 5
 *
 * Miscellaneous message parsing functions
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
I 2
#include "msgparse.h"
E 2

/*
I 2
D 6
 * This static function is an assistant for extract_dname_from_msg(),
E 6
I 6
 * This static function is an assistant for msgparse_extract_dname(),
E 6
 * see below.
 */
static
dname_from_msg_backref(dn, start, msgstart)
	register struct dname *dn;
	u_char *start;
	u_char *msgstart;
{
	register u_char *ptr, *sptr;
	register int c;

	for (sptr = start, ptr = sptr; ; ) {
		dn->dn_labels[dn->dn_nlabels] = ptr;
		c = *ptr++;
		switch (c & INDIR_MASK) {
		case 0:
			dn->dn_stringlen += c + 1;
			if (dn->dn_stringlen > MAXDNAME)
				return(0);
			if (!c)
				return(1);	 /* success! */
			ptr += c;
			dn->dn_nlabels++;
			continue;
		case INDIR_MASK:
			c = ((c&~INDIR_MASK) << 8) | *ptr;
			ptr = msgstart + c;
			if (ptr >= sptr)
				return(0);
			sptr = ptr;
			continue;
		default:
			return(0);
		}
	}
}

/*
 * This function extracts a domain-name from a DNS protocol message.
 *
 * The arguments are:
 * 1: pointer to struct dname where the booty should be stored
 * 2: pointer to wherever the domain-name is expected
 * 3: corresponding end-stop pointer (end of message or end of RDATA)
 * 4: pointer to the beginning of the message for handling backrefs
 *
 * The return value is a u_char * pointing past the parsed domain-name,
 * so that the subsequent data can be parsed.  0 return indicates an
 * error: invalid high bits, total length limit exceeded, or run into
 * the end-stop pointer.
 *
 * We have to handle label pointers/backrefs here, hence the msgstart
 * argument.  This function is also used in the process of extracting
 * dnames from RDATA in binary zone file loading, in that case
 * label pointers are disallowed and msgstart is 0.
 */
u_char *
D 6
extract_dname_from_msg(dn, cp, endp, msgstart)
E 6
I 6
msgparse_extract_dname(dn, cp, endp, msgstart)
E 6
	register struct dname *dn;
	register u_char *cp;
	u_char *endp, *msgstart;
{
	register int c;
	register u_char *bp;

	dn->dn_nlabels = 0;
	dn->dn_stringlen = 0;
	for (;;) {
		if (cp >= endp)
			return(0);
		dn->dn_labels[dn->dn_nlabels] = cp;
		c = *cp++;
		switch (c & INDIR_MASK) {
		case 0:
			if ((endp-cp) < c)
				return(0);
			dn->dn_stringlen += c + 1;
			if (dn->dn_stringlen > MAXDNAME)
				return(0);
			if (!c)
				return(cp);	 /* success! */
			cp += c;
			dn->dn_nlabels++;
			continue;
		case INDIR_MASK:
			if (!msgstart)
				return(0);
			if (cp >= endp)
				return(0);
			c = ((c&~INDIR_MASK) << 8) | *cp++;
			bp = msgstart + c;
			if (bp >= cp - 2)
				return(0);
			if (dname_from_msg_backref(dn, bp, msgstart))
				return(cp);
			else
				return(0);
		default:
			return(0);
		}
	}
}

/*
E 2
D 6
 * This function is a stripped-down version of extract_dname_from_msg()
E 6
I 6
 * This function is a stripped-down version of msgparse_extract_dname()
E 6
 * which simply skips over a domain-name in a protocol message
 * without actually extracting it into a struct dname.  It understands
 * pointers/backrefs, but encountering one simply means that the end
 * of the compressed domain-name to be skipped over has been found,
 * hence this function doesn't actually follow those backrefs and
 * doesn't need a pointer to the beginning of the message.
 *
 * The arguments are:
 * 1: pointer to wherever the domain-name is expected
 * 2: corresponding end-stop pointer (end of message or end of RDATA)
 *
 * The return value is a u_char * pointing past the parsed domain-name,
 * so that the subsequent data can be parsed.  0 return indicates an
 * error: invalid high bits or run into the end-stop pointer.
 */
u_char *
msgparse_skip_dname(cp, endp)
	register u_char *cp;
	u_char *endp;
{
	register int c;

	for (;;) {
		if (cp >= endp)
			return(0);
		c = *cp++;
		if (!c)
			return(cp);		/* success! */
		switch (c & INDIR_MASK) {
		case 0:
			cp += c;
			continue;
		case INDIR_MASK:
			if (cp >= endp)
				return(0);
			return(cp + 1);
		default:
			return(0);
		}
	}
}

msgparse_get_rrfix(cp, fix)
	register u_char *cp;
	register struct rrfixed *fix;
{
	register u_long t;

	GETSHORT(t, cp);
	fix->type = t;
	GETSHORT(t, cp);
	fix->class = t;
	GETLONG(t, cp);
	fix->ttl = t;
	GETSHORT(t, cp);
	fix->rdlength = t;
I 2
}

/*
 * This function extracts an RR from a DNS protocol response message
 * and fills a parsedrr structure with the owner dname, RR fixed part
 * in easy-to-access form (aligned and in host byte order) and a
 * pointer to unparsed RDATA.
 *
 * The arguments and return value of this function
D 6
 * are just like extract_dname_from_msg()
E 6
I 6
 * are just like msgparse_extract_dname()
E 6
 */
u_char *
msgparse_extract_rr(prr, cp, endp, msgstart)
	register struct parsedrr *prr;
	register u_char *cp;
	u_char *endp, *msgstart;
{
D 6
	cp = extract_dname_from_msg(&prr->prr_owner, cp, endp, msgstart);
E 6
I 6
	cp = msgparse_extract_dname(&prr->prr_owner, cp, endp, msgstart);
E 6
	if (!cp)
		return(0);
	if (cp > endp - RRFIXEDSZ)
		return(0);
	msgparse_get_rrfix(cp, &prr->prr_fix);
	cp += RRFIXEDSZ;
	prr->prr_rdata = cp;
	cp += prr->prr_fix.rdlength;
	if (cp > endp)
		return(0);
	return(cp);
E 2
}
I 3

/*
 * This function operates on an incoming RR captured in a parsedrr
 * struct: it examines the RR type and parses RDATA if necessary.
 *
 * Return value:
 *   1 = parsed successfully
 *   0 = type unknown or doesn't need parsing
 *  -1 = parsing attempted and failed
 */
D 6
parse_incoming_rr(rr, msgstart)
E 6
I 6
msgparse_rdata(rr, msgstart)
E 6
	register struct parsedrr *rr;
	u_char *msgstart;
{
	register u_char *cp, *endp;

	cp = rr->prr_rdata;
	endp = cp + rr->prr_fix.rdlength;
	switch (rr->prr_fix.type) {
	case T_NS:
	case T_MD:
	case T_MF:
	case T_CNAME:
	case T_MB:
	case T_MG:
	case T_MR:
	case T_PTR:
	generic_dname:
D 6
		cp = extract_dname_from_msg(&rr->prr_rdata_dn[0], cp, endp,
E 6
I 6
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[0], cp, endp,
E 6
					    msgstart);
	check_end:
		if (cp == endp)
			return(1);
		else
			return(-1);
	case T_MX:
I 4
	case T_AFSDB:
	case T_RT:
E 4
		cp += 2;
		goto generic_dname;
	case T_MINFO:
I 4
	case T_RP:
E 4
D 6
		cp = extract_dname_from_msg(&rr->prr_rdata_dn[0], cp, endp,
E 6
I 6
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[0], cp, endp,
E 6
					    msgstart);
		if (!cp)
			return(-1);
D 6
		cp = extract_dname_from_msg(&rr->prr_rdata_dn[1], cp, endp,
E 6
I 6
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[1], cp, endp,
E 6
					    msgstart);
		goto check_end;
	case T_SOA:
D 6
		cp = extract_dname_from_msg(&rr->prr_rdata_dn[0], cp, endp,
E 6
I 6
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[0], cp, endp,
E 6
					    msgstart);
		if (!cp)
			return(-1);
D 6
		cp = extract_dname_from_msg(&rr->prr_rdata_dn[1], cp, endp,
E 6
I 6
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[1], cp, endp,
E 6
					    msgstart);
		if (!cp)
			return(-1);
		rr->prr_rdata_misc = cp;
		cp += 20;
		goto check_end;
	default:
		return(0);
	}
}
E 3
E 1
