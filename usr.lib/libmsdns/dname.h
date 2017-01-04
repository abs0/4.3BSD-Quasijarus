/*
 * struct dname is a versatile representation of <domain-name> objects
 * initially invented for use inside the MSDNS core daemon, but now factored
 * out into libmsdns for possible reuse by other components of the MSDNS
 * solution.
 *
 * It will be documented in dname(3x).
 *
 *	@(#)dname.h	1.1 (IFCTF) 2011/12/27
 */

#ifndef	__DNAME_H
#define	__DNAME_H

struct dname {
	int	dn_nlabels;		/* total # of labels, not counting */
					/* the final null label */
	int	dn_stringlen;		/* length of canonical binary string, */
					/* including the terminating null */
	u_char	*dn_labels[128];	/* pointers to each label from left */
					/* to right, such that dn_labels[0] */
					/* points to the beginning of the */
					/* full binary string and */
					/* dn_labels[dn_nlabels] points to */
					/* the terminating null */
	u_char	dn_buf[256];		/* RFC 1035 is unclear on whether or */
					/* not the 255 octet limit includes */
					/* the terminating null */
};

/*
 * The idea behind struct dname is that the <domain-name> binary string
 * from RFC 1035 is stored literally intact, such that it can be instantly
 * regurgitated, but an additional array of pointers is created which
 * addresses the labels and allows them to be read efficiently from right
 * to left when looking for that domain in a tree.
 *
 * The C definition of the structure above is deceiving in that it is
 * compactable.  Initially a struct dname is filled out (usually in stack-
 * allocated storage) exactly as the C struct is defined, but when it's
 * transferred into longer-term malloced storage, it gets compacted in that
 * the dn_labels[] array is shrunk to just the needed size.  Therefore, the
 * full binary string must be accessed as dn_labels[0] rather than dn_buf.
 * The compaction is performed in dname_copy(); the intended usage is that
 * one first calls dname_spaceneeded() as part of malloc size calculation,
 * then mallocs the longer-term buffer, then calls dname_copy().
 *
 * Also note that sometimes the dn_labels[] pointers will point to data
 * entirely outside of the struct dname itself, e.g., in a parsed incoming
 * DNS message, and may be contiguous or discontiguous.  However, the
 * dn_stringlen member should be set correctly even for an external
 * discontiguous dname: dn_spaceneeded() macro uses it, and other dname
 * consumers "have the right" to use it too.  Maintaining dn_stringlen
 * in incoming dname parsers also makes it easy to enforce the total domain
 * name length limit.
 *
 * Case issues: struct dname is meant to be case-preserving, i.e., not
 * canonicalized to either uppercase or lowercase.  It stores <domain-name>
 * objects as they come in via RR packets or text files.
 */

#define	dn_spaceneeded(dn)	(sizeof(int)*2 \
				  + sizeof(u_char *) * ((dn)->dn_nlabels+1) \
				  + (dn)->dn_stringlen)

/* Table for canonicalizing domain name labels to uppercase */
extern u_char dns_label_uc_table[256];

#endif	/* include guard */
