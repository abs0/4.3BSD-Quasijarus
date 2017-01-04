h61766
s 00006/00002/00013
d D 5.2 2012/07/23 01:12:15 msokolov 2 1
c updated for the recent changes to pstroff and pstfinish
e
s 00015/00000/00000
d D 5.1 10/10/09 18:56:50 msokolov 1 0
c written, compiles
e
u
U
t
T
I 1
/*
 * These global variables represent the document's formatting requirements
 * extracted from the special header comments.
 *
 *	%W%	(Berkeley)	%E%
 */

D 2
extern char *fontlist;
extern int notroffencoding;
E 2
I 2
extern char *fontlist, *fontpath;
E 2
extern int languagelevel;
extern char *macros;
#define	MAX_PREPROCS	16	/* overkill */
extern char *preprocs[MAX_PREPROCS];
extern int npreprocs;
extern int pstfinish_req;
I 2
extern char *pstfinish_doc_opts;
extern int doc_text_bits;

#define	PSTFINISH_FULL		1
#define	PSTFINISH_GENTLE	2
E 2
E 1
