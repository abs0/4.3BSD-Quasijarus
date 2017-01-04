/*
 * The RFC 1034/1035 pair says that each class is a separate domain tree
 * with its own root and its own zone boundaries.  That's how we implement
 * the class notion.  Each class we know about is represented by a
 * struct class, which is allocated via malloc.  The global table of
 * classes is a static array of pointers to these structures; NULL pointers
 * are classes we don't know about.  The class ID is nominally a 16-bit
 * value, but all well-known values are small and 255 is the wildcard QCLASS,
 * so we cheat a bit and only support class values between 0 and 254
 * inclusive, so we can get away with a static array of pointers to all
 * possible classes.  Of course in normal Internet operation there is only
 * one class (IN) whose value is 1. :-)
 *
 * We also arrange our active class structures into a linked list for those
 * operations which need to iterate through all classes: this way we don't
 * have to plow through the mostly-empty array every time.
 *
 *	@(#)class.h	1.6 (IFCTF) 2013/01/14
 */

#ifndef	__CLASS_H
#define	__CLASS_H

#include <stdio.h>

/*
 * The comment in tree.h about us having only one tree contrary to
 * RFC 1035 recommendations is a partial truth.  We do in fact
 * maintain a separate catalog tree just like RFC 1035 recommends,
 * but it uses a different (greatly simplified) struct, and this catalog
 * tree is only used for zone management functions, i.e., it is NOT
 * used in query processing to decide whether or not we are authoritative.
 *
 * Our non-use of child hash tables in the catalog tree is a deliberate
 * simplification.  If we have a lot of zones, it would be possible to have
 * some nodes with a very high branching factor where a child hash table
 * would be of benefit.  However, the catalog tree is searched from
 * the root down only during the processing of class definition files,
 * and that is a one-time administrative operation, hence we can allow
 * it to be a little slower in return for simplicity.
 *
 * In the current implementation catalog nodes are only created
 * and never deleted, although a zone may be dropped from its catalog node.
 */

struct catalog {
	u_char	cat_labellen;
	u_char	cat_label[MAXLABEL];	/* canonicalized to uppercase */
	struct	catalog *cat_nextsib;
	struct	catalog *cat_firstchild;
	struct	zone *cat_zone;	/* is there a zone attached to this node? */
};

struct class {
	int	c_class;
	char	*c_filename;
	int	c_fileread_needed;
	int	c_ready_to_serve;
	struct	node *c_root;
	struct	catalog c_catalog;
	struct	zone *c_zonelist;
	struct	class *c_next;
	struct	query **c_dupcatcher;
	FILE	*c_fileread;
	int	c_fileread_lineno;
	int	c_fileread_oldzones;
	int	c_outstanding_loads;
	/* the c_filename string is appended to the malloced chunk */
};

#endif	/* include guard */
