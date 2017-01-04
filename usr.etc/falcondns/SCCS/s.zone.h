h19059
s 00001/00001/00051
d D 1.14 2011/12/17 06:37:59 msokolov 14 13
c tcpqueue revamped
e
s 00002/00001/00050
d D 1.13 2011/12/16 06:14:39 msokolov 13 12
c minor fixes in preparation for secondary zone refresh support
e
s 00007/00000/00044
d D 1.12 2011/12/15 01:02:33 msokolov 12 11
c additions for remote/secondary zones
e
s 00003/00029/00041
d D 1.11 2011/12/13 01:21:03 msokolov 11 10
c struct catalog moved from zone.h to class.h
c support for class file reloading and zone deletion
e
s 00001/00000/00069
d D 1.10 2011/10/31 07:18:50 msokolov 10 9
c n_zonehead and n_nextinzone implemented
e
s 00000/00001/00069
d D 1.9 2011/09/08 01:27:53 msokolov 9 8
c z_catnode: unused member deleted
e
s 00001/00002/00069
d D 1.8 2011/07/18 05:54:12 msokolov 8 7
c basic refresh logic implemented
e
s 00001/00002/00070
d D 1.7 2011/07/17 00:38:20 msokolov 7 6
c label case handling rethought slightly
e
s 00002/00001/00070
d D 1.6 2011/07/16 01:18:44 msokolov 6 5
c zone loading code complete
e
s 00002/00001/00069
d D 1.5 2011/07/15 23:51:43 msokolov 5 4
c #include <stdio.h> internally, flag change
e
s 00001/00000/00069
d D 1.4 2011/07/14 04:23:15 msokolov 4 3
c reworking structures for zone loading
e
s 00009/00004/00060
d D 1.3 2011/07/13 23:13:06 msokolov 3 2
c started zone management implementation
e
s 00010/00007/00054
d D 1.2 2011/07/13 19:23:21 msokolov 2 1
c we now read the class def file, although don't do anything with it yet
e
s 00061/00000/00000
d D 1.1 2011/07/13 17:41:25 msokolov 1 0
c date and time created 2011/07/13 17:41:25 by msokolov
e
u
U
t
T
I 1
/*
 * MSDNS zone management structures
 *
 *	%W% (IFCTF) %E%
 */

#ifndef	__ZONE_H
#define	__ZONE_H

I 5
#include <stdio.h>
E 5
#include "defs.h"

struct zone {
I 11
	int	z_refcount;	/* AXFR-out ops need to hold it from deletion */
E 11
	struct	class *z_class;
D 3
	char	z_ascii_domname[MAX_ASCII_DOMNAME+1];
I 2
	struct	dname *z_dname;	/* appended to the same malloced chunk */
E 3
I 3
	/* the following two are appended to the same */
	/* malloced chunk after the struct itself */
	char	*z_ascii_domname;
	struct	dname *z_dname;
I 11
	struct	catalog *z_catnode;
E 11
E 3
E 2
D 9
	struct	catalog *z_catnode;
E 9
	char	z_filename[MAX_FILENAME+1];
	int	z_flags;
D 3
	struct	zone *z_next_per_class;
E 3
I 3
	struct	zone *z_next_perclass;
	struct	zone **z_backref_perclass;
E 3
	struct	zone *z_next_global;
I 3
	struct	zone **z_backref_global;
E 3
	struct	node *z_activetree;
	struct	node *z_tree_inprogress;	/* being read from file */
	FILE	*z_fileread;
I 4
	int	z_fileread_rrcount;
I 10
	struct	node *z_fileread_lastnode;
E 10
E 4
	time_t	z_file_mtime;
D 8
	time_t	z_nextrefresh;
	time_t	z_expire;
E 8
I 8
	struct	timesched *z_refresh;
I 12
	/* remote/secondary zone support */
	u_long	z_fromaddr_config;
	u_long	z_fromaddr_current;
	struct	query *z_mname_query;
D 14
	struct	tcpqueue *z_soa_check;
E 14
I 14
	struct	tcpquery *z_soa_check;
E 14
	int	z_puller_pid;
D 13
	char	z_temp_filename[MAX_FILENAME+1];
E 13
I 13
	char	z_temp_filename[16];
E 13
E 12
E 8
};

/* z_flags definitions */
#define	Z_FILEREAD_NEEDED		0x8000
D 5
#define	Z_FILEREAD_INPROGRESS		0x4000
E 5
I 5
D 6
#define	Z_ZOMBIE			0x0004
E 6
I 6
#define	Z_LOAD_FAILED			0x4000
#define	Z_LOST_IN_MALLOC		0x2000
I 13
#define	Z_RETRYING			0x0008
E 13
I 11
#define	Z_DEL_CANDIDATE			0x0004
E 11
E 6
E 5
#define	Z_EXPIRED			0x0002
#define	Z_REMOTE			0x0001
D 11

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
I 2
 *
 * In the current implementation catalog nodes are only created
 * and never deleted, although a zone may be dropped from its catalog node.
E 2
 */

struct catalog {
D 2
	u_char	c_labellen;
	u_char	c_label_uc[MAXLABEL];	/* uppercase */
	u_char	c_label_cp[MAXLABEL];	/* case-preserving */
	struct	catalog *c_parent;
	struct	catalog *c_nextsib;
	struct	catalog *c_firstchild;
	struct	zone *c_zone;	/* is there a zone attached to this node? */
E 2
I 2
	u_char	cat_labellen;
D 3
	u_char	cat_label[MAXLABEL];	/* converted to uppercase */
E 3
I 3
D 7
	u_char	cat_label_uc[MAXLABEL];	/* uppercase */
	u_char	cat_label_cp[MAXLABEL];	/* case-preserving */
E 7
I 7
	u_char	cat_label[MAXLABEL];	/* canonicalized to uppercase */
E 7
E 3
	struct	catalog *cat_parent;
	struct	catalog *cat_nextsib;
	struct	catalog *cat_firstchild;
	struct	zone *cat_zone;	/* is there a zone attached to this node? */
E 2
};
E 11

#endif	/* include guard */
E 1
