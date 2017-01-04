/*
 * struct dname represents a full domain name.  The domain name is
 * represented as a "thing in itself", i.e., just the sequence of labels,
 * without any references to our in-memory domain tree.  Our representation
 * is optimized to allow to us to do the following efficiently:
 *
 * - spit out the canonical form of the length-label binary string
 *   (called <domain-name> in RFC 1035), used when generating response packets;
 * - read the labels from right to left, used when searching for this
 *   domain node in our tree.
 *
 *	@(#)dname.h	1.1 (IFCTF) 2011/07/11
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
 * to left when looking for that domain in the tree.
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
 * Case issues: struct dname is meant to be case-preserving, i.e., not
 * canonicalized to either uppercase or lowercase.  It stores <domain-name>
 * objects as they come in via RR packets or text files.
 */

#define	dn_spaceneeded(dn)	(sizeof(int)*2 \
				  + sizeof(u_char *) * ((dn)->dn_nlabels+1) \
				  + (dn)->dn_stringlen)

#endif	/* include guard */
