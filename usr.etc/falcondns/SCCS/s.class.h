h45757
s 00002/00000/00069
d D 1.6 2013/01/14 00:40:07 msokolov 6 5
c class ready-to-serve flag implemented
e
s 00001/00000/00068
d D 1.5 2013/01/13 15:31:41 msokolov 5 4
c duplicate query suppression implemented
e
s 00030/00001/00038
d D 1.4 2011/12/13 01:21:02 msokolov 4 3
c struct catalog moved from zone.h to class.h
c support for class file reloading and zone deletion
e
s 00002/00002/00037
d D 1.3 2011/07/14 22:51:48 msokolov 3 2
c daemonization better thought through
e
s 00004/00001/00035
d D 1.2 2011/07/13 19:23:15 msokolov 2 1
c we now read the class def file, although don't do anything with it yet
e
s 00036/00000/00000
d D 1.1 11/07/11 08:04:02 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
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
 *	%W% (IFCTF) %E%
 */

#ifndef	__CLASS_H
#define	__CLASS_H

D 3
#include "defs.h"
E 3
I 2
D 4
#include "zone.h"
E 4
I 4
#include <stdio.h>
E 4
E 2

I 4
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

E 4
struct class {
	int	c_class;
D 3
	char	c_filename[MAX_FILENAME+1];
E 3
I 3
	char	*c_filename;
E 3
	int	c_fileread_needed;
I 6
	int	c_ready_to_serve;
E 6
	struct	node *c_root;
D 2
	struct	node *c_zonemgmt_tree;
E 2
I 2
	struct	catalog c_catalog;
E 2
	struct	zone *c_zonelist;
	struct	class *c_next;
I 5
	struct	query **c_dupcatcher;
E 5
I 2
	FILE	*c_fileread;
	int	c_fileread_lineno;
I 4
	int	c_fileread_oldzones;
I 6
	int	c_outstanding_loads;
E 6
E 4
I 3
	/* the c_filename string is appended to the malloced chunk */
E 3
E 2
};

#endif	/* include guard */
E 1
