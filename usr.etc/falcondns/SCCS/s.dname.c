h27781
s 00003/00003/00179
d D 1.9 2013/01/06 08:15:46 msokolov 9 8
c s/dname_in_bailiwick/dname_is_under/
e
s 00000/00105/00182
d D 1.8 2011/12/02 05:48:57 msokolov 8 7
c extract_dname_from_msg() moved from dname.c to msgparse.c
e
s 00000/00017/00287
d D 1.7 2011/11/01 05:53:25 msokolov 7 6
c dname_of_node() split from dname.c into its own compilation unit
e
s 00040/00000/00264
d D 1.6 2011/10/29 21:22:53 msokolov 6 5
c dname_of_node() and dname_in_bailiwick() functions added
e
s 00015/00000/00249
d D 1.5 2011/07/18 00:21:45 msokolov 5 4
c label and dname printing functions
e
s 00135/00000/00114
d D 1.4 2011/07/15 07:41:33 msokolov 4 3
c extract_dname_from_msg() and dname_copy_discontig() implemented
e
s 00001/00001/00113
d D 1.3 2011/07/13 23:45:01 msokolov 3 2
c parse_ascii_dname: big oops
e
s 00082/00000/00032
d D 1.2 2011/07/13 22:06:17 msokolov 2 1
c ASCII parsing and dname comparison implemented
e
s 00032/00000/00000
d D 1.1 11/07/11 08:04:03 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
 * Utility functions for operating on struct dname objects.
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
I 2
#include <arpa/nameser.h>
#include <ctype.h>
I 5
#include <stdio.h>
E 5
E 2
#include "dname.h"
I 6
D 7
#include "tree.h"
E 7
E 6
I 2

/*
 * This function takes a domain-name in ASCII form (it comes from
 * our class definition files, but we require it to follow RFC 1035),
 * parses it and stores it in a struct dname.
 *
 * Return value:
 *  0 = success
 * -1 = ASCII domain-name violates some RFC 1035 rule
 */
parse_ascii_dname(asc, dn)
	register char *asc;
	struct dname *dn;
{
	register u_char *dp;
	u_char *lp;
	register int c, i;
	int lcount = 0;

	lp = dn->dn_buf;
	while (*asc) {
		if (*asc == '.') {
			asc++;
			continue;
		}
		dn->dn_labels[lcount] = lp;
		dp = lp;
		*dp++ = 0;
		while ((c = *asc++) && c != '.') {
D 3
			if (*lp++ >= MAXLABEL)
E 3
I 3
			if ((*lp)++ >= MAXLABEL)
E 3
				return(-1);
			if (dp - dn->dn_buf >= 255)
				return(-1);
			if (c == '\\') {
				if (!*asc)
					return(-1);
				if (isdigit(*asc)) {
					c = 0;
					for (i = 0; i < 3 && isdigit(*asc); i++)
						c = c*10 + *asc++ - '0';
				} else
					c = *asc++;
			}
			*dp++ = c;
		}
		if (!c)
			asc--;
		lcount++;
		lp = dp;
	}
	dn->dn_labels[lcount] = lp;
	*lp++ = 0;
	dn->dn_nlabels = lcount;
	dn->dn_stringlen = lp - dn->dn_buf;
	return(0);
}

/*
I 4
D 8
 * This static function is an assistant for extract_dname_from_msg(),
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
extract_dname_from_msg(dn, cp, endp, msgstart)
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
D 7
}

I 6
void
dname_of_node(n, dn)
	register struct node *n;
	register struct dname *dn;
{
	register int d;

	dn->dn_stringlen = 0;
	for (d = 0; n; n = n->n_parent) {
		dn->dn_labels[d] = (u_char *) n;
		dn->dn_stringlen += dn->dn_labels[d][0] + 1;
		d++;
	}
	dn->dn_nlabels = d - 1;
E 7
}

E 6
/*
E 8
E 4
 * This function compares two dnames in the proper case-insensitive manner.
 * Returns 1 if equal, 0 otherwise.
 */
dname_compare(dn1, dn2)
	struct dname *dn1, *dn2;
{
	register u_char **l1, **l2;
	register int i;
	int lcnt;

	if (dn1->dn_stringlen != dn2->dn_stringlen)
		return(0);
	lcnt = dn1->dn_nlabels;
	if (lcnt != dn2->dn_nlabels)
		return(0);
	l1 = dn1->dn_labels;
	l2 = dn2->dn_labels;
	for (i = 0; i < lcnt; i++)
		if (!label_match(*l1++, *l2++))
			return(0);
	return(1);
}
E 2

/*
I 6
D 9
 * This function returns 1 if the 1st dname argument is in the
 * "bailiwick" (djb's term) of the 2nd dname argument, 0 otherwise.
E 9
I 9
 * This function returns 1 if the 1st dname argument is either equal to
 * or a subdomain of the 2nd dname argument, 0 otherwise.
E 9
 */
D 9
dname_in_bailiwick(c, h)
E 9
I 9
dname_is_under(c, h)
E 9
	register struct dname *c, *h;
{
	register int cl, hl;

	cl = c->dn_nlabels;
	hl = h->dn_nlabels;
	if (cl < hl)
		return(0);
	while (hl) {
		cl--;
		hl--;
		if (!label_match(c->dn_labels[cl], h->dn_labels[hl]))
			return(0);
	}
	return(1);
}

/*
E 6
 * This function copies a struct dname to a new location, compacts it
 * in the process, and adjusts the pointers inside.
 */
dname_copy(dnsrc, newloc)
	register struct dname *dnsrc;
	u_char *newloc;
{
	register struct dname *newdn;
	register u_char *oldstr, *newstr;
	register int i;

	newdn = (struct dname *)newloc;
	newdn->dn_nlabels = dnsrc->dn_nlabels;
	newdn->dn_stringlen = dnsrc->dn_stringlen;
	oldstr = dnsrc->dn_labels[0];
	newstr = (u_char *)(newdn->dn_labels + newdn->dn_nlabels + 1);
	for (i = 0; i <= dnsrc->dn_nlabels; i++)
		newdn->dn_labels[i] = dnsrc->dn_labels[i] - oldstr + newstr;
	bcopy(oldstr, newstr, dnsrc->dn_stringlen);
I 4
}

/*
 * This function is just like dname_copy(), but the source dname
 * may have non-contiguously-stored labels.
 *
 * Discontiguous source dnames result from parsing a domain-name
 * out of a DNS protocol message where compression was used.
I 6
 * Also from dname_of_node() and similar functions.
E 6
 */
dname_copy_discontig(dnsrc, newloc)
	register struct dname *dnsrc;
	u_char *newloc;
{
	register struct dname *newdn;
	register u_char *dp;
	register int i, l;

	newdn = (struct dname *)newloc;
	newdn->dn_nlabels = dnsrc->dn_nlabels;
	newdn->dn_stringlen = dnsrc->dn_stringlen;
	dp = (u_char *)(newdn->dn_labels + newdn->dn_nlabels + 1);
	for (i = 0; i < dnsrc->dn_nlabels; i++) {
		newdn->dn_labels[i] = dp;
		l = dnsrc->dn_labels[i][0];
		*dp++ = l;
		bcopy(dnsrc->dn_labels[i]+1, dp, l);
		dp += l;
	}
	newdn->dn_labels[i] = dp;
	*dp = 0;
I 5
}

print_dname(dn, f)
	register struct dname *dn;
	register FILE *f;
{
	register int i;

	for (i = 0; i < dn->dn_nlabels; i++) {
		print_label(dn->dn_labels[i], f);
		putc('.', f);
	}
	if (!i)
		putc('.', f);
E 5
E 4
}
E 1
