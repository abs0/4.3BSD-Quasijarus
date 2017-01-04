h06732
s 00003/00003/00070
d D 2.7 85/09/10 12:38:43 mckusick 9 8
c bmac moves to /usr/new/lib
e
s 00001/00001/00072
d D 2.6 85/06/10 06:23:50 garrison 8 7
c increased maximum size of refernce string.
e
s 00006/00008/00067
d D 2.5 84/10/12 17:34:19 rrh 7 6
c add -d flag to all programs, to change the /usr/lib/bmac directory 
c to whatever the user wants; default is /usr/lib/bmac
e
s 00004/00001/00071
d D 2.4 84/03/27 10:14:40 rrh 6 5
c When the [.$C$<fmt> citation.] format is used,
c print out the citation in the currently active format. This prevents
c changing the citation from affecting the entire file, which it used to
c do before.
e
s 00024/00003/00048
d D 2.3 84/01/29 14:53:10 rrh 5 4
c add ALGORITHMS!!!!! Maintain a hash table of references, and
c a hash table of definitions.  use registers. cut down on n^2 algorithms.
c use structures.  These mods made a 11 minute run be 1 minute long.; still
c may be bugs in this
e
s 00010/00001/00041
d D 2.2 83/09/23 15:39:43 garrison 4 3
c Included changes from Arizona
e
s 00000/00000/00042
d D 2.1 83/06/22 14:24:52 garrison 3 2
c Make new release before sending it to Arizona for new changes.
e
s 00003/00000/00039
d D 1.2 83/06/14 16:47:44 rrh 2 1
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00039/00000/00000
d D 1.1 83/06/06 11:47:25 garrison 1 0
c date and time created 83/06/06 11:47:25 by garrison
e
u
U
t
T
I 2
/*
 *	%W%	%G%
 */
E 2
I 1
/*   various arguments for bib and listrefs processors */

/* constants */

# define true  1
# define false 0
# define err  -1
D 8
# define REFSIZE 1024                /* maximum size of reference string    */
E 8
I 8
# define REFSIZE 2048                /* maximum size of reference string    */
E 8
I 4
# define MAXFIELD 512                /* maximum size of any field in referece*/
E 4

/* reference citation marker genrated in pass 1 */

# define CITEMARK (char) 02
# define CITEEND  (char) 03
I 6
# define FMTSTART (char) 04
# define FMTEND   (char) 05
E 6

/* file names */

        /* output of invert, input file for references */
# define INDXFILE "INDEX"
        /* pass1 reference collection file */
D 5
# define TMPREFFILE  "/usr/tmp/bibrXXXXXX"
E 5
I 5
# define TMPREFFILE  "/tmp/bibrXXXXXX"
E 5
        /* pass2 text collection file */
D 5
# define TMPTEXTFILE "/usr/tmp/bibpXXXXXX"
E 5
I 5
# define TMPTEXTFILE "/tmp/bibpXXXXXX"
E 5
        /* temp file used in invert */
D 5
# define INVTEMPFILE "/usr/tmp/invertXXXXXX"
E 5
I 5
# define INVTEMPFILE "/tmp/invertXXXXXX"
E 5
D 7
        /* common words */
# define COMFILE "/usr/lib/bmac/common"
        /* default system dictionary */
# define SYSINDEX "/usr/dict/papers/INDEX"
        /* where macro libraries live */
# define BMACLIB "/usr/lib/bmac"
        /* default style of references */
# define DEFSTYLE "/usr/lib/bmac/bib.stdsn"
E 7
I 7
# define SYSINDEX "/usr/dict/papers/INDEX"	/* default system dictionary */

D 9
# define N_BMACLIB "/usr/lib/bmac"		/* where macro libraries live */
# define N_COMFILE "/usr/lib/bmac/common"		/* common words */
# define N_DEFSTYLE "/usr/lib/bmac/bib.stdsn"	/* default style of refs */
E 9
I 9
# define N_BMACLIB "/usr/new/lib/bmac"		/* where macro libraries live */
# define N_COMFILE "/usr/new/lib/bmac/common"	/* common words */
# define N_DEFSTYLE "/usr/new/lib/bmac/bib.stdsn" /* default style of refs */
E 9
char BMACLIB[64], COMFILE[64], DEFSTYLE[64];
E 7

/* size limits */

	/* maximum number of characters in common file */
D 4
# define MAXCOMM 300
E 4
I 4
# define MAXCOMM 1000
E 4

char *malloc();
I 4

/* fix needed for systems where open [w]+ doesn't work */
# ifdef READWRITE

# define READ 1
# define WRITE 0

#endif
I 5
   /*
    *	Reference information
    */
   struct refinfo{
D 6
	char	*ri_ref;	/* actual value */
E 6
I 6
	char	*ri_ref;	/* actual value, base value */
E 6
	char	*ri_cite;	/* citation string */
I 6
	char	ri_disambig[2];	/* disambiguation string */
E 6
	int	ri_length;	/* length of reference string, plus null */
	long int ri_pos;	/* reference seek position */
	int	ri_n;		/* number of citation in pass1 */
	struct	refinfo	*ri_hp;	/* hash chain */
   };
   struct wordinfo{
	char	*wi_word;	/* actual word */
	char	*wi_def;	/* actual definition */
	int	wi_length;	/* word length */
	struct wordinfo *wi_hp;	/* hash chain */
   };
   int	strhash();
#define HASHSIZE	509

#define reg register
E 5
E 4
E 1
