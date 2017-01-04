/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Miscellaneous message parsing functions
 */

#ifndef lint
static char sccsid[] = "@(#)msgparse.c	1.6 (IFCTF) 2013/01/06";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include "msgparse.h"

/*
 * This static function is an assistant for msgparse_extract_dname(),
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
msgparse_extract_dname(dn, cp, endp, msgstart)
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
 * This function is a stripped-down version of msgparse_extract_dname()
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
}

/*
 * This function extracts an RR from a DNS protocol response message
 * and fills a parsedrr structure with the owner dname, RR fixed part
 * in easy-to-access form (aligned and in host byte order) and a
 * pointer to unparsed RDATA.
 *
 * The arguments and return value of this function
 * are just like msgparse_extract_dname()
 */
u_char *
msgparse_extract_rr(prr, cp, endp, msgstart)
	register struct parsedrr *prr;
	register u_char *cp;
	u_char *endp, *msgstart;
{
	cp = msgparse_extract_dname(&prr->prr_owner, cp, endp, msgstart);
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
}

/*
 * This function operates on an incoming RR captured in a parsedrr
 * struct: it examines the RR type and parses RDATA if necessary.
 *
 * Return value:
 *   1 = parsed successfully
 *   0 = type unknown or doesn't need parsing
 *  -1 = parsing attempted and failed
 */
msgparse_rdata(rr, msgstart)
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
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[0], cp, endp,
					    msgstart);
	check_end:
		if (cp == endp)
			return(1);
		else
			return(-1);
	case T_MX:
	case T_AFSDB:
	case T_RT:
		cp += 2;
		goto generic_dname;
	case T_MINFO:
	case T_RP:
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[0], cp, endp,
					    msgstart);
		if (!cp)
			return(-1);
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[1], cp, endp,
					    msgstart);
		goto check_end;
	case T_SOA:
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[0], cp, endp,
					    msgstart);
		if (!cp)
			return(-1);
		cp = msgparse_extract_dname(&rr->prr_rdata_dn[1], cp, endp,
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
