/*
 * These global variables represent the document's formatting requirements
 * extracted from the special header comments.
 *
 *	@(#)docreq.h	5.2	(Berkeley)	2012/07/23
 */

extern char *fontlist, *fontpath;
extern int languagelevel;
extern char *macros;
#define	MAX_PREPROCS	16	/* overkill */
extern char *preprocs[MAX_PREPROCS];
extern int npreprocs;
extern int pstfinish_req;
extern char *pstfinish_doc_opts;
extern int doc_text_bits;

#define	PSTFINISH_FULL		1
#define	PSTFINISH_GENTLE	2
