h57595
s 00006/00002/00092
d D 5.1 85/04/30 14:05:06 dist 6 5
c Add copyright
e
s 00002/00007/00092
d D 4.5 83/06/30 07:59:03 rrh 5 4
c consolidate character buffer length definitions (manifest constants)
c into one place, with documentation
e
s 00000/00002/00099
d D 4.4 83/06/29 20:06:40 rrh 4 3
c DQ quoted strings no longer put into the temp file, but stored
c directly into the string spool; this fixes serious efficiency/size bugs
c in the temp files. DQ strings put into string pool with preceding 2 bytes
c indicating the length, with a trailing null byte not accounted for in the
c 2byte length; .asciz and .stabs change length and magically get null byte;
c all string moves (lookup and reader) done by subroutine call & movc3
e
s 00004/00002/00097
d D 4.3 82/02/14 16:36:13 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00000/00003/00099
d D 4.2 80/08/15 18:04:25 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 00102/00000/00000
d D 4.1 80/08/13 18:55:55 bill 1 0
c date and time created 80/08/13 18:55:55 by bill
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1980 Regents of the University of California */
/* "%Z%%M% %I% %G%" */
E 3
I 3
/*
D 6
 *	Copyright (c) 1982 Regents of the University of California
 *	%Z%%M% %I% %G%
E 6
I 6
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
E 6
 */
I 6

E 6
E 3
/*
 *	To speed up walks through symbols defined in a particular
 *	segment, we buil up a table of pointers into the symbol table
 *	and a table of delimiters for each segment.  The delimiter for
 *	the particular segment points to the first word in that segment.
 */

extern	struct	symtab	**symptrs;		/*dynamically allocated*/
extern	struct	symtab	**symdelim[NLOC + NLOC + 1];
extern	struct	symtab	**symptrub;
extern	int	nsyms;			/*number in the symbol table*/
extern	int	njxxx;			/*the number of jxxx entries in the table*/
extern	int	nforgotten;		/*how many entries erroneously entered*/
extern	int	nlabels;		/*how many labels in the symbol table*/
extern	int	hshused;		/*how many hash slots used*/

#define SEGITERATE(segno, start, end, copointer, walkpointer, ubpointer, direction) \
	for(copointer = start == 0? symdelim[segno]:start,\
	    ubpointer = end == 0 ? *symdelim[segno+1] : *(symdelim[segno]-1),\
	    walkpointer = *copointer;\
	    walkpointer != ubpointer;\
	    walkpointer = * direction copointer)

#define SYMITERATE(copointer, walkpointer) \
	for(copointer = symptrs, \
	    walkpointer = *copointer; \
	    copointer < symptrub; \
	    walkpointer = * ++ copointer)
/*
 *	Symbols are allocated in non contiguous chunks by extending
D 5
 *	the data area.  This way, it is extremely easy to
 *	allow virtual memory temporary files, change the length
 *	of NCPS, and allows for a much more flexible storage
 *	allocation
E 5
I 5
 *	the data area.
E 5
 */

#define SYMDALLOP	200
struct 	allocbox{
	struct		allocbox	*nextalloc;
	struct		symtab		symslots[SYMDALLOP];
D 2
#ifndef	FLEXNAMES
	char				symnames[SYMDALLOP * NCPS];
#endif
E 2
};

D 4
#ifdef FLEXNAMES
E 4
/*
D 5
 *	Names are allocated in a string pool.  String pools are linked
 *	together and are allocated dynamically by Calloc.
E 5
I 5
 *	Names are allocated in a dynamically extensible string pool.
E 5
 */
D 5
#define	STRPOOLDALLOP	NCPS
E 5
struct	strpool{
	struct	strpool	*str_next;
	int		str_nalloc;
	char		str_names[STRPOOLDALLOP];
};

extern	struct	strpool *strplhead;
D 4
#endif
E 4

extern	struct	allocbox	*allochead;
extern	struct	allocbox	*alloctail;
extern	struct	symtab		*nextsym;
extern	struct	allocbox	*newbox;
extern	char			*namebuffer;
extern	int			symsleft;

#define ALLOCQTY 	sizeof (struct allocbox)
/*
 *	Iterate through all symbols in the symbol table in declaration
 *	order
 */
#define DECLITERATE(allocwalk, walkpointer, ubpointer) \
	for(allocwalk = allochead; \
	    allocwalk != 0; \
	    allocwalk = allocwalk->nextalloc) \
		for (walkpointer = &allocwalk->symslots[0],\
		        ubpointer = &allocwalk->symslots[SYMDALLOP], \
		        ubpointer = ubpointer > ( (struct symtab *)alloctail) \
				 ? nextsym : ubpointer ;\
		     walkpointer < ubpointer; \
		     walkpointer++ )
/*
 *	The hash table is segmented, and dynamically extendable.
 *	We have a linked list of hash table segments; within each
 *	segment we use a quadratic rehash that touches no more than 1/2
 *	of the buckets in the hash table when probing.
 *	If the probe does not find the desired symbol, it moves to the
 *	next segment, or allocates a new segment.
 *
 *	Hash table segments are kept on the linked list with the first
 *	segment always first (that contains the reserved words) and
 *	the last added segment immediately after the first segment
 *	to hopefully gain something by locality of reference.
 */
struct hashdallop {
	int	h_nused;
	struct	hashdallop	*h_next;
	struct	symtab		*h_htab[NHASH];
};
E 1
