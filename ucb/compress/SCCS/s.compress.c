h52218
s 00117/00060/01573
d D 5.11 03/01/30 09:50:38 msokolov 12 11
c clean up the strong compression code
e
s 00132/00006/01501
d D 5.10 99/01/19 20:16:32 msokolov 11 10
c add strong compression mode
e
s 00042/00029/01465
d D 5.9 86/05/11 14:05:32 lepreau 10 9
c if fail completely on any file, exit(1) at end; cleanup bg/fg check; small gould ifdef
e
s 00004/00001/01490
d D 5.8 86/01/10 22:07:32 donn 9 8
c Don't zap the output file before we're ready to compress/decompress --
c in particular don't unlink if we've asked the user about overwriting and
c they hit ^C instead of typing 'no'.
e
s 00002/00002/01489
d D 5.7 85/09/17 23:30:01 lepreau 8 6
c fix usage msg; -V puts out sccs id too
e
s 00001/00001/01490
d R 5.7 85/09/17 18:41:46 lepreau 7 6
c Add sccs id info to version() msg
e
s 00002/00001/01489
d D 5.6 85/09/17 16:18:07 lepreau 6 5
c merge in sid 5.4
e
s 00426/00384/01064
d D 5.5 85/09/17 15:43:11 lepreau 5 4
c Compress 4.0
e
s 00002/00001/01446
d D 5.4 85/08/27 09:56:50 bloom 4 3
c don't unlink output upon interupt if using zcat
e
s 00002/00002/01445
d D 5.3 85/06/16 20:07:58 mckusick 3 2
c minor fixes from ames!jaw
e
s 00137/00120/01310
d D 5.2 85/06/07 17:33:48 mckusick 2 1
c new version from jaw
e
s 01430/00000/00000
d D 5.1 85/06/06 18:47:36 mckusick 1 0
c 4.3 beta version
e
u
U
t
T
I 1
#ifndef lint
D 10
static char sccsid[] = "%W% (Berkeley) %G%";
E 10
I 10
static char sccsid[] = "@(#)compress.c	%W% (Berkeley) %G%";
E 10
#endif not lint

I 5
/* 
 * Compress - data compression program 
 */
E 5
I 2
#define	min(a,b)	((a>b) ? b : a)

E 2
/*
D 2
 * Set USERMEM to the maximum amount of physical user memory available
E 2
I 2
 * machine variants which require cc -Dmachine:  pdp11, z8000, pcxt
 */

D 5
/* Set USERMEM to the maximum amount of physical user memory available
E 5
I 5
/*
 * Set USERMEM to the maximum amount of physical user memory available
E 5
E 2
 * in bytes.  USERMEM is used to determine the maximum BITS that can be used
D 5
 * for compression.  If USERMEM is big enough, use fast compression algorithm.
E 5
I 5
 * for compression.
E 5
 *
 * SACREDMEM is the amount of physical memory saved for others; compress
 * will hog the rest.
 */
#ifndef SACREDMEM
#define SACREDMEM	0
#endif

I 2
#ifndef USERMEM
D 5
# define USERMEM 	750000	/* default user memory */
E 5
I 5
# define USERMEM 	450000	/* default user memory */
E 5
#endif

I 5
#ifdef interdata		/* (Perkin-Elmer) */
#define SIGNED_COMPARE_SLOW	/* signed compare is slower than unsigned */
#endif

E 5
E 2
#ifdef pdp11
# define BITS 	12	/* max bits/code for 16-bit machine */
# define NO_UCHAR	/* also if "unsigned char" functions as signed char */
I 2
D 5
# define SHORT_INT	/* ints are short */
E 5
E 2
# undef USERMEM 
D 2
#else !pdp11
# ifndef USERMEM
#  define USERMEM 750000	/* default user memory */
# endif
#endif !pdp11
E 2
I 2
D 5
#endif pdp11
E 5
I 5
#endif /* pdp11 */	/* don't forget to compile with -i */
E 5

#ifdef z8000
# define BITS 	12
D 5
# define SHORT_INT
E 5
# undef vax		/* weird preprocessor */
# undef USERMEM 
D 5
#endif z8000
E 5
I 5
#endif /* z8000 */
E 5

#ifdef pcxt
# define BITS   12
D 5
# define SHORT_INT
# define SMALL_STACK	/* at least for Latice C, sez Lauren */
E 5
# undef USERMEM
D 5
#endif pcxt
E 5
I 5
#endif /* pcxt */
E 5

E 2
D 5
/* 
 * Define FBITS for machines with several MB of physical memory, to use
 * table lookup for (b <= FBITS).  If FBITS is made too large, performance
 * will decrease due to increased swapping/paging.  Since the program minus
 * the fast lookup table is about a half Meg, we can allocate the rest of
 * available physical memory to the fast lookup table.
 * 
 * If FBITS is set to 12, a 2 MB array is allocated, but only 1 MB is
 * addressed for parity-free input (i.e. text).
 *
 * FBITS=10 yields 1/2 meg lookup table + 4K code memory
 * FBITS=11 yields 1 meg lookup table + 8K code memory
 * FBITS=12 yields 2 meg lookup table + 16K code memory
 * FBITS=13 yields 4 meg lookup table + 32K code memory
 *
 */

E 5
#ifdef USERMEM
D 5
# if USERMEM >= (2621440+SACREDMEM)
#  if USERMEM >= (4718592+SACREDMEM)
#   define FBITS		13
#   define PBITS	16
#  else 2.5M <= USERMEM < 4.5M
#   define FBITS		12
#   define PBITS	16
#  endif USERMEM <=> 4.5M
# else USERMEM < 2.5M
#  if USERMEM >= (1572864+SACREDMEM)
#   define FBITS		11
#   define PBITS	16
#  else USERMEM < 1.5M
#   if USERMEM >= (1048576+SACREDMEM)
#    define FBITS		10
#    define PBITS	16
#   else USERMEM < 1M
#    if USERMEM >= (631808+SACREDMEM)
#     define PBITS	16
E 5
I 5
# if USERMEM >= (433484+SACREDMEM)
#  define PBITS	16
# else
#  if USERMEM >= (229600+SACREDMEM)
#   define PBITS	15
#  else
#   if USERMEM >= (127536+SACREDMEM)
#    define PBITS	14
#   else
#    if USERMEM >= (73464+SACREDMEM)
#     define PBITS	13
E 5
#    else
D 5
#     if USERMEM >= (329728+SACREDMEM)
#      define PBITS	15
#     else
#      if USERMEM >= (178176+SACREDMEM)
#       define PBITS	14
#      else
#       if USERMEM >= (99328+SACREDMEM)
#        define PBITS	13
#       else
#        define PBITS	12
#       endif
#      endif
#     endif
E 5
I 5
#     define PBITS	12
E 5
#    endif
D 5
#    undef USERMEM
#   endif USERMEM <=> 1M
#  endif USERMEM <=> 1.5M
# endif USERMEM <=> 2.5M
#endif USERMEM
E 5
I 5
#   endif
#  endif
# endif
# undef USERMEM
#endif /* USERMEM */
E 5

#ifdef PBITS		/* Preferred BITS for this memory size */
# ifndef BITS
#  define BITS PBITS
# endif BITS
D 5
#endif PBITS
E 5
I 5
#endif /* PBITS */
E 5

#if BITS == 16
# define HSIZE	69001		/* 95% occupancy */
#endif
#if BITS == 15
# define HSIZE	35023		/* 94% occupancy */
#endif
#if BITS == 14
# define HSIZE	18013		/* 91% occupancy */
#endif
#if BITS == 13
# define HSIZE	9001		/* 91% occupancy */
#endif
D 2
#if BITS == 12
E 2
I 2
#if BITS <= 12
E 2
# define HSIZE	5003		/* 80% occupancy */
#endif
D 2
#if BITS == 11
# define HSIZE	2591		/* 79% occupancy */
#endif
#if BITS == 10
# define HSIZE	1291		/* 79% occupancy */
#endif
#if BITS == 9
# define HSIZE	691		/* 74% occupancy */
#endif
E 2
D 5
/* BITS < 9 will cause an error */
E 5

I 5
#ifdef M_XENIX			/* Stupid compiler can't handle arrays with */
# if BITS == 16			/* more than 65535 bytes - so we fake it */
#  define XENIX_16
# else
#  if BITS > 13			/* Code only handles BITS = 12, 13, or 16 */
#   define BITS	13
#  endif
# endif
#endif

E 5
/*
 * a code_int must be able to hold 2**BITS values of type int, and also -1
 */
#if BITS > 15
typedef long int	code_int;
#else
typedef int		code_int;
#endif

D 5
#ifdef interdata
E 5
I 5
#ifdef SIGNED_COMPARE_SLOW
E 5
typedef unsigned long int count_int;
typedef unsigned short int count_short;
#else
typedef long int	  count_int;
#endif

#ifdef NO_UCHAR
 typedef char	char_type;
D 5
#else UCHAR
E 5
I 5
#else
E 5
 typedef	unsigned char	char_type;
D 5
#endif UCHAR
E 5
I 5
#endif /* UCHAR */
E 5
char_type magic_header[] = { "\037\235" };	/* 1F 9D */
I 11
char_type magic_strong[] = { "\037\241" };	/* 1F A1 */
E 11

/* Defines for third byte of header */
#define BIT_MASK	0x1f
#define BLOCK_MASK	0x80
/* Masks 0x40 and 0x20 are free.  I think 0x20 should mean that there is
   a fourth header byte (for expansion).
*/
#define INIT_BITS 9			/* initial number of bits/code */

/*
D 2
 * compress.c - File compression ala IEEE Computer June 1984.
E 2
I 2
 * compress.c - File compression ala IEEE Computer, June 1984.
E 2
 *
D 10
 * Authors:	Spencer W. Thomas	(decvax!harpo!utah-cs!utah-gr!thomas)
E 10
I 10
 * Authors:	Spencer W. Thomas	(decvax!utah-cs!thomas)
E 10
 *		Jim McKie		(decvax!mcvax!jim)
 *		Steve Davies		(decvax!vax135!petsd!peora!srd)
 *		Ken Turkowski		(decvax!decwrl!turtlevax!ken)
 *		James A. Woods		(decvax!ihnp4!ames!jaw)
 *		Joe Orost		(decvax!vax135!petsd!joe)
 *
D 2
 * $Header: compress.c,v 3.0 84/11/27 11:50:00 joe Exp $
E 2
I 2
D 5
 * $Header: compress.c,v 3.2 85/06/06 21:53:24 jaw Exp $
E 5
I 5
 * $Header: compress.c,v 4.0 85/07/30 12:50:00 joe Release $
E 5
E 2
 * $Log:	compress.c,v $
I 5
 * Revision 4.0  85/07/30  12:50:00  joe
 * Removed ferror() calls in output routine on every output except first.
 * Prepared for release to the world.
 * 
 * Revision 3.6  85/07/04  01:22:21  joe
 * Remove much wasted storage by overlaying hash table with the tables
 * used by decompress: tab_suffix[1<<BITS], stack[8000].  Updated USERMEM
 * computations.  Fixed dump_tab() DEBUG routine.
 *
 * Revision 3.5  85/06/30  20:47:21  jaw
 * Change hash function to use exclusive-or.  Rip out hash cache.  These
 * speedups render the megamemory version defunct, for now.  Make decoder
 * stack global.  Parts of the RCS trunks 2.7, 2.6, and 2.1 no longer apply.
 *
 * Revision 3.4  85/06/27  12:00:00  ken
 * Get rid of all floating-point calculations by doing all compression ratio
 * calculations in fixed point.
 *
 * Revision 3.3  85/06/24  21:53:24  joe
 * Incorporate portability suggestion for M_XENIX.  Got rid of text on #else
 * and #endif lines.  Cleaned up #ifdefs for vax and interdata.
 *
E 5
I 2
 * Revision 3.2  85/06/06  21:53:24  jaw
 * Incorporate portability suggestions for Z8000, IBM PC/XT from mailing list.
 * Default to "quiet" output (no compression statistics).
 *
 * Revision 3.1  85/05/12  18:56:13  jaw
 * Integrate decompress() stack speedups (from early pointer mods by McKie).
 * Repair multi-file USERMEM gaffe.  Unify 'force' flags to mimic semantics
 * of SVR2 'pack'.  Streamline block-compress table clear logic.  Increase 
 * output byte count by magic number size.
 * 
E 2
 * Revision 3.0   84/11/27  11:50:00  petsd!joe
 * Set HSIZE depending on BITS.  Set BITS depending on USERMEM.  Unrolled
D 2
 * loops in clear routines.  Added "-C" flag for 2.0 compatability.  Used
E 2
I 2
 * loops in clear routines.  Added "-C" flag for 2.0 compatibility.  Used
E 2
 * unsigned compares on Perkin-Elmer.  Fixed foreground check.
 *
 * Revision 2.7   84/11/16  19:35:39  ames!jaw
 * Cache common hash codes based on input statistics; this improves
 * performance for low-density raster images.  Pass on #ifdef bundle
 * from Turkowski.
 *
 * Revision 2.6   84/11/05  19:18:21  ames!jaw
 * Vary size of hash tables to reduce time for small files.
 * Tune PDP-11 hash function.
 *
 * Revision 2.5   84/10/30  20:15:14  ames!jaw
 * Junk chaining; replace with the simpler (and, on the VAX, faster)
 * double hashing, discussed within.  Make block compression standard.
 *
 * Revision 2.4   84/10/16  11:11:11  ames!jaw
 * Introduce adaptive reset for block compression, to boost the rate
 * another several percent.  (See mailing list notes.)
 *
 * Revision 2.3   84/09/22  22:00:00  petsd!joe
 * Implemented "-B" block compress.  Implemented REVERSE sorting of tab_next.
 * Bug fix for last bits.  Changed fwrite to putchar loop everywhere.
 *
 * Revision 2.2   84/09/18  14:12:21  ames!jaw
 * Fold in news changes, small machine typedef from thomas,
 * #ifdef interdata from joe.
 *
 * Revision 2.1   84/09/10  12:34:56  ames!jaw
 * Configured fast table lookup for 32-bit machines.
 * This cuts user time in half for b <= FBITS, and is useful for news batching
 * from VAX to PDP sites.  Also sped up decompress() [fwrite->putc] and
 * added signal catcher [plus beef in writeerr()] to delete effluvia.
 *
 * Revision 2.0   84/08/28  22:00:00  petsd!joe
 * Add check for foreground before prompting user.  Insert maxbits into
 * compressed file.  Force file being uncompressed to end with ".Z".
 * Added "-c" flag and "zcat".  Prepared for release.
 *
 * Revision 1.10  84/08/24  18:28:00  turtlevax!ken
 * Will only compress regular files (no directories), added a magic number
 * header (plus an undocumented -n flag to handle old files without headers),
 * added -f flag to force overwriting of possibly existing destination file,
 * otherwise the user is prompted for a response.  Will tack on a .Z to a
 * filename if it doesn't have one when decompressing.  Will only replace
 * file if it was compressed.
 *
 * Revision 1.9  84/08/16  17:28:00  turtlevax!ken
 * Removed scanargs(), getopt(), added .Z extension and unlimited number of
 * filenames to compress.  Flags may be clustered (-Ddvb12) or separated
 * (-D -d -v -b 12), or combination thereof.  Modes and other status is
 * copied with copystat().  -O bug for 4.2 seems to have disappeared with
 * 1.8.
 *
 * Revision 1.8  84/08/09  23:15:00  joe
 * Made it compatible with vax version, installed jim's fixes/enhancements
 *
 * Revision 1.6  84/08/01  22:08:00  joe
 * Sped up algorithm significantly by sorting the compress chain.
 *
 * Revision 1.5  84/07/13  13:11:00  srd
 * Added C version of vax asm routines.  Changed structure to arrays to
 * save much memory.  Do unsigned compares where possible (faster on
 * Perkin-Elmer)
 *
 * Revision 1.4  84/07/05  03:11:11  thomas
 * Clean up the code a little and lint it.  (Lint complains about all
 * the regs used in the asm, but I'm not going to "fix" this.)
 *
 * Revision 1.3  84/07/05  02:06:54  thomas
 * Minor fixes.
 *
 * Revision 1.2  84/07/05  00:27:27  thomas
 * Add variable bit length output.
 *
 */
D 5
#ifndef lint
D 2
static char rcs_ident[] = "$Header: compress.c,v 3.0 84/11/27 11:50:00 joe Exp$";
E 2
I 2
D 3
static char rcs_ident[] = "$Header: compress.c,v 3.1 85/05/12 18:56:13 jaw Exp $";
E 3
I 3
static char rcs_ident[] = "$Header: compress.c,v 3.2 85/05/12 18:56:13 jaw Exp $";
E 3
E 2
#endif !lint
E 5
I 5
static char rcs_ident[] = "$Header: compress.c,v 4.0 85/07/30 12:50:00 joe Release $";
E 5

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
I 10
#ifdef notdef
#include <sys/ioctl.h>
#endif
I 11
#include <zlib.h>
E 11
E 10

#define ARGVAL() (*++(*argv) || (--argc && *++argv))

int n_bits;				/* number of bits/code */
int maxbits = BITS;			/* user settable max # bits/code */
code_int maxcode;			/* maximum code, given n_bits */
code_int maxmaxcode = 1 << BITS;	/* should NEVER generate this code */
#ifdef COMPATIBLE		/* But wrong! */
# define MAXCODE(n_bits)	(1 << (n_bits) - 1)
D 5
#else COMPATIBLE
E 5
I 5
#else
E 5
# define MAXCODE(n_bits)	((1 << (n_bits)) - 1)
D 5
#endif COMPATIBLE
E 5
I 5
#endif /* COMPATIBLE */
E 5

D 5
/*
 * One code could conceivably represent (1<<BITS) characters, but
 * to get a code of length N requires an input string of at least
 * N*(N-1)/2 characters.  With 5000 chars in the stack, an input
 * file would have to contain a 25Mb string of a single character.
 * This seems unlikely.
 */
D 2
#ifdef pdp11
E 2
I 2
#ifdef SHORT_INT
E 2
# define MAXSTACK    5000		/* size of output stack */
D 2
#else !pdp11
E 2
I 2
#else !SHORT_INT
E 2
# define MAXSTACK    8000		/* size of output stack */
D 2
#endif !pdp11
E 2
I 2
#endif !SHORT_INT
E 5
I 5
#ifdef XENIX_16
count_int htab0[8192];
count_int htab1[8192];
count_int htab2[8192];
count_int htab3[8192];
count_int htab4[8192];
count_int htab5[8192];
count_int htab6[8192];
count_int htab7[8192];
count_int htab8[HSIZE-65536];
count_int * htab[9] = {
	htab0, htab1, htab2, htab3, htab4, htab5, htab6, htab7, htab8 };
E 5
E 2

I 5
#define htabof(i)	(htab[(i) >> 13][(i) & 0x1fff])
unsigned short code0tab[16384];
unsigned short code1tab[16384];
unsigned short code2tab[16384];
unsigned short code3tab[16384];
unsigned short code4tab[16384];
unsigned short * codetab[5] = {
	code0tab, code1tab, code2tab, code3tab, code4tab };

#define codetabof(i)	(codetab[(i) >> 14][(i) & 0x3fff])

#else	/* Normal machine */
I 10

#ifdef sel	/* gould base register braindamage */
/*NOBASE*/
E 10
E 5
count_int htab [HSIZE];
unsigned short codetab [HSIZE];
I 10
/*NOBASE*/
#else
count_int htab [HSIZE];
unsigned short codetab [HSIZE];
#endif sel

E 10
I 5
#define htabof(i)	htab[i]
#define codetabof(i)	codetab[i]
#endif	/* XENIX_16 */
E 5
code_int hsize = HSIZE;			/* for dynamic table sizing */
count_int fsize;

D 5
#define tab_prefix	codetab		/* prefix code for this entry */
char_type  	tab_suffix[1<<BITS];	/* last char in this entry */
E 5
I 5
/*
 * To save much memory, we overlay the table used by compress() with those
 * used by decompress().  The tab_prefix table is the same size and type
 * as the codetab.  The tab_suffix table needs 2**BITS characters.  We
 * get this from the beginning of htab.  The output stack uses the rest
 * of htab, and contains characters.  There is plenty of room for any
 * possible stack (stack used to be 8000 characters).
 */
E 5

D 5
#ifdef USERMEM
short ftable [(1 << FBITS) * 256];
count_int fcodemem [1 << FBITS];
#endif USERMEM
E 5
I 5
#define tab_prefixof(i)	codetabof(i)
#ifdef XENIX_16
# define tab_suffixof(i)	((char_type *)htab[(i)>>15])[(i) & 0x7fff]
# define de_stack		((char_type *)(htab2))
#else	/* Normal machine */
# define tab_suffixof(i)	((char_type *)(htab))[i]
# define de_stack		((char_type *)&tab_suffixof(1<<BITS))
#endif	/* XENIX_16 */
E 5

code_int free_ent = 0;			/* first unused entry */
D 10
int exit_stat = 0;
E 10
I 10
int exit_stat = 0;			/* per-file status */
int perm_stat = 0;			/* permanent status */
E 10

code_int getcode();

Usage() {
#ifdef DEBUG
D 2
fprintf(stderr,"Usage: compress [-dDvqfFc] [-b maxbits] [file ...]\n");
E 2
I 2
D 11
fprintf(stderr,"Usage: compress [-dDVfc] [-b maxbits] [file ...]\n");
E 11
I 11
fprintf(stderr,"Usage: compress [-dDVfcs] [-b maxbits] [-l level] [file ...]\n");
E 11
E 2
}
int debug = 0;
D 5
#else DEBUG
D 2
fprintf(stderr,"Usage: compress [-dfFqc] [-b maxbits] [file ...]\n");
E 2
I 2
fprintf(stderr,"Usage: compress [-dfvc] [-b maxbits] [file ...]\n");
E 5
I 5
#else
D 8
fprintf(stderr,"Usage: compress [-dfvcV] [-b maxbits] [file ...]\n");
E 8
I 8
D 11
fprintf(stderr,"Usage: compress [-fvc] [-b maxbits] [file ...]\n");
E 11
I 11
fprintf(stderr,"Usage: compress [-fvcs] [-b maxbits] [-l level] [file ...]\n");
E 11
E 8
E 5
E 2
}
D 5
#endif DEBUG
E 5
I 5
#endif /* DEBUG */
E 5
D 2
int nomagic = 0;	/* Use a 2 byte magic number header, unless old file */
E 2
I 2
int nomagic = 0;	/* Use a 3-byte magic number header, unless old file */
E 2
int zcat_flg = 0;	/* Write output on stdout, suppress messages */
I 9
int precious = 1;	/* Don't unlink output file on interrupt */
E 9
D 2
int quiet = 0;		/* don't tell me about compression */
E 2
I 2
int quiet = 1;		/* don't tell me about compression */
E 2

/*
 * block compression parameters -- after all codes are used up,
 * and compression rate changes, start over.
 */
int block_compress = BLOCK_MASK;
int clear_flg = 0;
D 5
double ratio = 0.0;	/* compression ratio for last block */
E 5
I 5
long int ratio = 0;
E 5
#define CHECK_GAP 10000	/* ratio check interval */
count_int checkpoint = CHECK_GAP;
/*
 * the next two codes should not be changed lightly, as they must not
 * lie within the contiguous general code space.
 */ 
#define FIRST	257	/* first free entry */
#define	CLEAR	256	/* table clear output code */

int force = 0;
char ofname [100];
#ifdef DEBUG
int verbose = 0;
D 5
#endif DEBUG
E 5
I 5
#endif /* DEBUG */
E 5
D 10
int (*bgnd_flag)();
E 10
I 10
int (*oldint)();
int bgnd_flag;
E 10

I 2
D 5
int nfiles = 0;		/* number of files processed */
E 5
I 5
int do_decomp = 0;
E 5

I 11
int strong_comp = 0;
int strong_level = Z_DEFAULT_COMPRESSION;

E 11
E 2
/*****************************************************************
 * TAG( main )
 *
 * Algorithm from "A Technique for High Performance Data Compression",
 * Terry A. Welch, IEEE Computer Vol 17, No 6 (June 1984), pp 8-19.
 *
D 2
 * Usage: compress [-dfFqc] [-b bits] [file ...]
E 2
I 2
 * Usage: compress [-dfvc] [-b bits] [file ...]
E 2
 * Inputs:
 *	-d:	    If given, decompression is done instead.
 *
 *      -c:         Write output on stdout, don't remove original.
 *
I 11
 *      -s:         Use the strong compression algorithm and file format
 *                  instead of the standard one.
 *
E 11
 *      -b:         Parameter limits the max number of bits/code.
 *
I 11
 *      -l:         Parameters sets the compression level for -s.
 *
E 11
 *	-f:	    Forces output file to be generated, even if one already
D 2
 *		    exists; if -f is not used, the user will be prompted if
 *		    the stdin is a tty, otherwise, the output file will not
 *		    be overwritten.
E 2
I 2
 *		    exists, and even if no space is saved by compressing.
 *		    If -f is not used, the user will be prompted if stdin is
 *		    a tty, otherwise, the output file will not be overwritten.
E 2
 *
D 2
 *	-F:	    Forces output file to be generated, even if no space is
 *		    saved by compressing.
E 2
I 2
 *      -v:	    Write compression statistics
E 2
 *
D 2
 *	-q:	    No output, unless error
 *
E 2
 * 	file ...:   Files to be compressed.  If none specified, stdin
 *		    is used.
 * Outputs:
 *	file.Z:	    Compressed form of file with same mode, owner, and utimes
 * 	or stdout   (if stdin used as input)
 *
 * Assumptions:
 *	When filenames are given, replaces with the compressed version
D 2
 *	(.Z suffix) only if the file decreased in size.
E 2
I 2
 *	(.Z suffix) only if the file decreases in size.
E 2
 * Algorithm:
 * 	Modified Lempel-Ziv method (LZW).  Basically finds common
 * substrings and replaces them with a variable size code.  This is
 * deterministic, and can be done on the fly.  Thus, the decompression
D 2
 * procedure needs no input table, but tracks the way the table was
 * built.
E 2
I 2
 * procedure needs no input table, but tracks the way the table was built.
E 2
 */
I 5

E 5
D 2

E 2
main( argc, argv )
register int argc; char **argv;
{
D 5
    int do_decomp = 0;
E 5
    int overwrite = 0;	/* Do not overwrite unless given -f flag */
    char tempname[100];
    char **filelist, **fileptr;
D 2
    char *cp, *rindex();
E 2
I 2
    char *cp, *rindex(), *malloc();
E 2
    struct stat statbuf;
D 5
    extern onintr();
E 5
I 5
    extern onintr(), oops();
E 5

D 10

D 5
    if ( (bgnd_flag = signal ( SIGINT, SIG_IGN )) != SIG_IGN )
E 5
I 5
    if ( (bgnd_flag = signal ( SIGINT, SIG_IGN )) != SIG_IGN ) {
E 10
I 10
    /* This bg check only works for sh. */
    if ( (oldint = signal ( SIGINT, SIG_IGN )) != SIG_IGN ) {
E 10
E 5
	signal ( SIGINT, onintr );
I 5
	signal ( SIGSEGV, oops );
    }
E 5
D 10

E 10
I 10
    bgnd_flag = oldint != SIG_DFL;
#ifdef notdef     /* This works for csh but we don't want it. */
    { int tgrp;
    if (bgnd_flag == 0 && ioctl(2, TIOCGPGRP, (char *)&tgrp) == 0 &&
      getpgrp(0) != tgrp)
	bgnd_flag = 1;
    }
#endif
    
E 10
#ifdef COMPATIBLE
    nomagic = 1;	/* Original didn't have a magic number */
D 5
#endif COMPATIBLE
E 5
I 5
#endif /* COMPATIBLE */
E 5

    filelist = fileptr = (char **)(malloc(argc * sizeof(*argv)));
    *filelist = NULL;

    if((cp = rindex(argv[0], '/')) != 0) {
	cp++;
    } else {
	cp = argv[0];
    }
    if(strcmp(cp, "uncompress") == 0) {
	do_decomp = 1;
    } else if(strcmp(cp, "zcat") == 0) {
	do_decomp = 1;
	zcat_flg = 1;
    }

#ifdef BSD4_2
    /* 4.2BSD dependent - take it out if not */
    setlinebuf( stderr );
D 5
#endif BSD4_2
E 5
I 5
#endif /* BSD4_2 */
E 5

    /* Argument Processing
     * All flags are optional.
     * -D => debug
I 2
D 5
     * -V => debug verbose
E 5
I 5
     * -V => print Version; debug verbose
E 5
E 2
     * -d => do_decomp
D 2
     * -v => verbose
E 2
I 2
     * -v => unquiet
E 2
     * -f => force overwrite of output file
     * -n => no header: useful to uncompress old files
I 11
     * -s => strong_comp=1
E 11
     * -b maxbits => maxbits.  If -b is specified, then maxbits MUST be
     *	    given also.
I 11
     * -l level => strong_level.  If -l is specified, then level MUST be
     *      given also.
E 11
     * -c => cat all output to stdout
D 2
     * -C => generate output compatable with compress 2.0.
E 2
I 2
     * -C => generate output compatible with compress 2.0.
E 2
     * if a string is left, must be an input filename.
     */
    for (argc--, argv++; argc > 0; argc--, argv++) {
	if (**argv == '-') {	/* A flag argument */
	    while (*++(*argv)) {	/* Process all flags in this arg */
		switch (**argv) {
#ifdef DEBUG
		    case 'D':
			debug = 1;
			break;
D 2
		    case 'v':
E 2
I 2
		    case 'V':
E 2
			verbose = 1;
I 5
			version();
E 5
			break;
D 5
#endif DEBUG
E 5
I 5
#else
		    case 'V':
			version();
			break;
#endif /* DEBUG */
E 5
I 2
		    case 'v':
			quiet = 0;
			break;
E 2
		    case 'd':
			do_decomp = 1;
			break;
		    case 'f':
I 2
		    case 'F':
E 2
			overwrite = 1;
I 2
			force = 1;
E 2
			break;
		    case 'n':
			nomagic = 1;
			break;
		    case 'C':
			block_compress = 0;
			break;
I 11
		    case 's':
			strong_comp = 1;
			break;
E 11
		    case 'b':
			if (!ARGVAL()) {
			    fprintf(stderr, "Missing maxbits\n");
			    Usage();
			    exit(1);
			}
			maxbits = atoi(*argv);
			goto nextarg;
I 11
		    case 'l':
			if (!ARGVAL()) {
			    fprintf(stderr, "Missing level\n");
			    Usage();
			    exit(1);
			}
			strong_level = atoi(*argv);
			goto nextarg;
E 11
		    case 'c':
			zcat_flg = 1;
			break;
		    case 'q':
			quiet = 1;
			break;
D 2
		    case 'F':
			force = 1;
			break;
E 2
		    default:
			fprintf(stderr, "Unknown flag: '%c'; ", **argv);
			Usage();
			exit(1);
		}
	    }
	}
	else {		/* Input file name */
	    *fileptr++ = *argv;	/* Build input file list */
	    *fileptr = NULL;
D 5
	    /* goto nextarg; */
E 5
I 5
	    /* process nextarg; */
E 5
	}
	nextarg: continue;
    }

    if(maxbits < INIT_BITS) maxbits = INIT_BITS;
    if (maxbits > BITS) maxbits = BITS;
I 11
    if (strong_level > Z_BEST_COMPRESSION) strong_level = Z_BEST_COMPRESSION;
E 11
    maxmaxcode = 1 << maxbits;
I 11
    if (nomagic)
	strong_comp = 0;
E 11

    if (*filelist != NULL) {
	for (fileptr = filelist; *fileptr; fileptr++) {
	    exit_stat = 0;
D 10
	    if (do_decomp != 0) {			/* DECOMPRESSION */
E 10
I 10
	    if (do_decomp) {			/* DECOMPRESSION */
E 10
		/* Check for .Z suffix */
		if (strcmp(*fileptr + strlen(*fileptr) - 2, ".Z") != 0) {
		    /* No .Z: tack one on */
		    strcpy(tempname, *fileptr);
		    strcat(tempname, ".Z");
		    *fileptr = tempname;
		}
		/* Open input file */
		if ((freopen(*fileptr, "r", stdin)) == NULL) {
D 10
			perror(*fileptr); continue;
E 10
I 10
		    perror(*fileptr);
		    perm_stat = 1;
		    continue;
E 10
		}
I 11
#ifndef COMPATIBLE
E 11
		/* Check the magic number */
		if (nomagic == 0) {
D 11
		    if ((getchar() != (magic_header[0] & 0xFF))
		     || (getchar() != (magic_header[1] & 0xFF))) {
E 11
I 11
		    char_type magic[2];

		    magic[0] = getchar();
		    magic[1] = getchar();
		    if ((magic[0] == magic_strong[0])
		     && (magic[1] == magic_strong[1])) {
			strong_comp = 1;
			goto strong_file;
		    }
		    strong_comp = 0;
		    if ((magic[0] != magic_header[0])
		     || (magic[1] != magic_header[1])) {
E 11
			fprintf(stderr, "%s: not in compressed format\n",
			    *fileptr);
		    continue;
		    }
		    maxbits = getchar();	/* set -b from file */
		    block_compress = maxbits & BLOCK_MASK;
		    maxbits &= BIT_MASK;
		    maxmaxcode = 1 << maxbits;
		    if(maxbits > BITS) {
			fprintf(stderr,
			"%s: compressed with %d bits, can only handle %d bits\n",
			*fileptr, maxbits, BITS);
			continue;
		    }
I 11
strong_file: ;
E 11
		}
I 11
#endif
E 11
		/* Generate output filename */
		strcpy(ofname, *fileptr);
		ofname[strlen(*fileptr) - 2] = '\0';  /* Strip off .Z */
	    } else {					/* COMPRESSION */
		if (strcmp(*fileptr + strlen(*fileptr) - 2, ".Z") == 0) {
D 2
		    fprintf(stderr, "%s: already has .Z suffix -- no change\n",
E 2
I 2
		    	fprintf(stderr, "%s: already has .Z suffix -- no change\n",
E 2
			    *fileptr);
		    continue;
		}
		/* Open input file */
		if ((freopen(*fileptr, "r", stdin)) == NULL) {
D 10
		    perror(*fileptr); continue;
E 10
I 10
		    perror(*fileptr);
		    perm_stat = 1;
		    continue;
E 10
		}
		stat ( *fileptr, &statbuf );
		fsize = (long) statbuf.st_size;
		/*
D 5
		 * tune hash table size for small files -- ad hoc
E 5
I 5
		 * tune hash table size for small files -- ad hoc,
		 * but the sizes match earlier #defines, which
		 * serve as upper bounds on the number of output codes. 
E 5
		 */
D 2
#if HSIZE > 5003
E 2
I 2
		hsize = HSIZE;
E 2
		if ( fsize < (1 << 12) )
D 2
		    hsize = 5003;
#if HSIZE > 9001
E 2
I 2
		    hsize = min ( 5003, HSIZE );
E 2
		else if ( fsize < (1 << 13) )
D 2
		    hsize = 9001;
#if HSIZE > 18013
E 2
I 2
		    hsize = min ( 9001, HSIZE );
E 2
		else if ( fsize < (1 << 14) )
D 2
		    hsize = 18013;
#if HSIZE > 35023
E 2
I 2
		    hsize = min ( 18013, HSIZE );
E 2
		else if ( fsize < (1 << 15) )
D 2
		    hsize = 35023;
E 2
I 2
		    hsize = min ( 35023, HSIZE );
E 2
		else if ( fsize < 47000 )
D 2
		    hsize = 50021;
#endif HSIZE > 35023
#endif HSIZE > 18013
#endif HSIZE > 9001
		else
#endif HSIZE > 5003
		    hsize = HSIZE;
E 2
I 2
		    hsize = min ( 50021, HSIZE );

E 2
		/* Generate output filename */
		strcpy(ofname, *fileptr);
#ifndef BSD4_2		/* Short filenames */
		if ((cp=rindex(ofname,'/')) != NULL)	cp++;
		else					cp = ofname;
		if (strlen(cp) > 12) {
		    fprintf(stderr,"%s: filename too long to tack on .Z\n",cp);
		    continue;
		}
D 5
#endif  BSD4_2		/* Long filenames allowed */
E 5
I 5
#endif  /* BSD4_2		Long filenames allowed */
E 5
		strcat(ofname, ".Z");
	    }
	    /* Check for overwrite of existing file */
	    if (overwrite == 0 && zcat_flg == 0) {
		if (stat(ofname, &statbuf) == 0) {
		    char response[2];
		    response[0] = 'n';
		    fprintf(stderr, "%s already exists;", ofname);
D 10
		    if (foreground()) {
E 10
I 10
		    if (bgnd_flag == 0 && isatty(2)) {
E 10
D 2
			fprintf(stderr, " do you wish to overwrite (y or n)? ",
E 2
I 2
			fprintf(stderr, " do you wish to overwrite %s (y or n)? ",
E 2
			ofname);
			fflush(stderr);
			read(2, response, 2);
			while (response[1] != '\n') {
			    if (read(2, response+1, 1) < 0) {	/* Ack! */
				perror("stderr"); break;
			    }
			}
		    }
		    if (response[0] != 'y') {
			fprintf(stderr, "\tnot overwritten\n");
			continue;
		    }
		}
	    }
	    if(zcat_flg == 0) {		/* Open output file */
		if (freopen(ofname, "w", stdout) == NULL) {
		    perror(ofname);
I 10
		    perm_stat = 1;
E 10
		    continue;
		}
I 9
		precious = 0;
E 9
		if(!quiet)
			fprintf(stderr, "%s: ", *fileptr);
	    }

	    /* Actually do the compression/decompression */
	    if (do_decomp == 0)	compress();
#ifndef DEBUG
	    else			decompress();
D 5
#else   DEBUG
E 5
I 5
#else
E 5
	    else if (debug == 0)	decompress();
	    else			printcodes();
	    if (verbose)		dump_tab();
D 5
#endif DEBUG
E 5
I 5
#endif /* DEBUG */
E 5
	    if(zcat_flg == 0) {
		copystat(*fileptr, ofname);	/* Copy stats */
I 9
		precious = 1;
E 9
D 5
		if(exit_stat || (!quiet))
E 5
I 5
		if((exit_stat == 1) || (!quiet))
E 5
			putc('\n', stderr);
	    }
	}
    } else {		/* Standard input */
	if (do_decomp == 0) {
		compress();
I 5
#ifdef DEBUG
		if(verbose)		dump_tab();
#endif /* DEBUG */
E 5
		if(!quiet)
			putc('\n', stderr);
	} else {
I 11
#ifndef COMPATIBLE
E 11
	    /* Check the magic number */
	    if (nomagic == 0) {
D 11
		if ((getchar()!=(magic_header[0] & 0xFF))
		 || (getchar()!=(magic_header[1] & 0xFF))) {
E 11
I 11
		char_type magic[2];

		magic[0] = getchar();
		magic[1] = getchar();
		if ((magic[0] == magic_strong[0])
		 && (magic[1] == magic_strong[1])) {
		    strong_comp = 1;
		    goto strong_stdin;
		}
		strong_comp = 0;
		if ((magic[0] != magic_header[0])
		 || (magic[1] != magic_header[1])) {
E 11
		    fprintf(stderr, "stdin: not in compressed format\n");
		    exit(1);
		}
		maxbits = getchar();	/* set -b from file */
		block_compress = maxbits & BLOCK_MASK;
		maxbits &= BIT_MASK;
		maxmaxcode = 1 << maxbits;
		fsize = 100000;		/* assume stdin large for USERMEM */
		if(maxbits > BITS) {
			fprintf(stderr,
			"stdin: compressed with %d bits, can only handle %d bits\n",
			maxbits, BITS);
			exit(1);
		}
I 11
strong_stdin: ;
E 11
	    }
I 11
#endif
E 11
#ifndef DEBUG
	    decompress();
D 5
#else   DEBUG
E 5
I 5
#else
E 5
	    if (debug == 0)	decompress();
	    else		printcodes();
	    if (verbose)	dump_tab();
D 5
#endif DEBUG
E 5
I 5
#endif /* DEBUG */
E 5
	}
    }
D 10
    exit(exit_stat);
E 10
I 10
    exit(perm_stat ? perm_stat : exit_stat);
E 10
}

static int offset;
long int in_count = 1;			/* length of input */
long int bytes_out;			/* length of compressed output */
long int out_count = 0;			/* # of codes output (for debugging) */

D 5
#define HOG_CHECK ((count_int) 2000)	/* Number of chars to read b4 check */
#define MAX_CACHE ((count_int) 1<<BITS) /* Next line is this constant too */
unsigned short hashcache [1<<BITS];	/* common hash short circuit cache */
count_int cfreq [256];			/* character counts */
#ifndef vax
 char chog;				/* most common character from input */
# define CHOG	' '			/* Assume space is most frequent */
#else 
 int chog;				/* char arith slow on VAX */
# define CHOG	(int) ' '		/* Assume space is most frequent */
#endif
int cstat_flg = 0;			/* on after determining char hog */

E 5
/*
 * compress stdin to stdout
 *
D 5
 * Algorithm:  on large machines, for maxbits <= FBITS, use fast direct table
 * lookup on the prefix code / next character combination.  For smaller code
 * size, use open addressing modular division double hashing (no chaining), ala
 * Knuth vol. 3, sec. 6.4 Algorithm D, along with G. Knott's relatively-prime
 * secondary probe.  Do block compression with an adaptive reset, whereby the
 * code table is cleared when the compression ratio decreases, but after the
 * table fills.  The variable-length output codes are re-sized at this point,
 * and a special CLEAR code is generated for the decompressor.  For the
 * megamemory version, the sparse array is cleared indirectly through a
 * "shadow" output code history.  Late additions: for the hashing code,
 * construct the table according to file size for noticeable speed improvement
 * on small files.  Also detect and cache codes associated with the most
 * common character to bypass hash calculation on these codes (a characteristic
 * of highly-compressable raster images).  Please direct questions about this
 * implementation to ames!jaw.
E 5
I 5
 * Algorithm:  use open addressing double hashing (no chaining) on the 
 * prefix code / next character combination.  We do a variant of Knuth's
 * algorithm D (vol. 3, sec. 6.4) along with G. Knott's relatively-prime
 * secondary probe.  Here, the modular division first probe is gives way
 * to a faster exclusive-or manipulation.  Also do block compression with
 * an adaptive reset, whereby the code table is cleared when the compression
 * ratio decreases, but after the table fills.  The variable-length output
 * codes are re-sized at this point, and a special CLEAR code is generated
 * for the decompressor.  Late addition:  construct the table according to
 * file size for noticeable speed improvement on small files.  Please direct
 * questions about this implementation to ames!jaw.
E 5
 */

D 5

E 5
compress() {
    register long fcode;
    register code_int i = 0;
    register int c;
    register code_int ent;
I 5
#ifdef XENIX_16
    register code_int disp;
#else	/* Normal machine */
E 5
    register int disp;
I 5
#endif
E 5
    register code_int hsize_reg;
I 5
    register int hshift;
E 5

#ifndef COMPATIBLE
I 11
    if (strong_comp) {
D 12
	compFile cf;
	char buf[4096];
	int len, err;

E 12
	putchar(magic_strong[0]); putchar(magic_strong[1]);
	if(ferror(stdout))
		writeerr();
D 12
	cf = compress_open(stdout, strong_level);
	if (cf == NULL) {
	    fprintf(stderr, "compress: not enough memory for strong compression state info\n");
	    unlink(ofname);
	    exit(1);
	}
	for (;;) {
	    len = fread(buf, 1, sizeof(buf), stdin);
	    if (len < 0) {
		perror("compress: fread");
		unlink(ofname);
		exit(1);
	    }
	    if (len == 0)
		break;
	    if (compwrite(cf, buf, len) != len) {
		fprintf(stderr, "compress: compwrite: %s\n", comperror(cf, &err));
		unlink(ofname);
		exit(1);
	    }
	}
	if (compclose(cf) != Z_OK) {
	    fprintf(stderr, "compress: compclose: %s\n", comperror(cf, &err));
	    unlink(ofname);
	    exit(1);
	}
E 12
I 12
	strong_compress();
E 12
	return;
    }

E 11
    if (nomagic == 0) {
	putchar(magic_header[0]); putchar(magic_header[1]);
	putchar((char)(maxbits | block_compress));
I 5
	if(ferror(stdout))
		writeerr();
E 5
    }
D 5
#endif COMPATIBLE
E 5
I 5
#endif /* COMPATIBLE */
E 5

    offset = 0;
D 2
    bytes_out = 0;
E 2
I 2
    bytes_out = 3;		/* includes 3-byte header mojo */
E 2
    out_count = 0;
    clear_flg = 0;
D 5
    ratio = 0.0;
E 5
I 5
    ratio = 0;
E 5
    in_count = 1;
    checkpoint = CHECK_GAP;
    maxcode = MAXCODE(n_bits = INIT_BITS);
    free_ent = ((block_compress) ? FIRST : 256 );
I 5

E 5
    ent = getchar ();

D 5
#ifdef USERMEM
if ( maxbits <= FBITS && (fsize >= 30000) ) {	/* use hashing on small files */
E 5
I 5
    hshift = 0;
    for ( fcode = (long) hsize;  fcode < 65536L; fcode *= 2L )
    	hshift++;
    hshift = 8 - hshift;		/* set hash code range bound */
E 5

I 2
D 5
    if ( nfiles++ > 0 ) 			/* clear table between files */
	cl_sparse ();

E 2
    while ( (c = getchar()) != (unsigned) EOF ) {
	in_count++;
	fcode = (long) (((long) c << maxbits) + ent);
D 2
	if ( ftable [fcode] != 0 )	/* test for code in "string" table */
E 2
I 2
	if ( ftable [fcode] != 0 )		/* test for code in "string" table */
E 2
	    ent = ftable [fcode];
	else {
	    output ( (code_int) ent );
	    out_count++;
	    ent = c;
	    if ( free_ent >= maxmaxcode ) {	
	        if ( (count_int)in_count < checkpoint || (!block_compress) ) 
		    continue;
		else {
D 2
		    clear ();
E 2
I 2
		    cl_block ();
E 2
		    i = 0;
		}
	    } else {				/* put code in table */
		ftable [fcode] = (short) free_ent++;
D 2
		fcodemem [i++] = fcode;	/* memorize for block compression */
E 2
I 2
		fcodemem [i++] = fcode;		/* memorize for block compression */
E 2
	    }
	}
    }
    goto fin;
}
#endif USERMEM

    chog = CHOG;		/* assumed character for the hog */
    cstat_flg = 0;
E 5
    hsize_reg = hsize;
D 2
    cl_hash(hsize_reg);		/* clear hash tables */
E 2
I 2
D 5
    cl_hash( (count_int) hsize_reg);		/* clear hash tables */
E 5
I 5
    cl_hash( (count_int) hsize_reg);		/* clear hash table */
E 5
E 2

I 5
#ifdef SIGNED_COMPARE_SLOW
E 5
    while ( (c = getchar()) != (unsigned) EOF ) {
I 5
#else
    while ( (c = getchar()) != EOF ) {
#endif
E 5
	in_count++;
D 5
	if ( cstat_flg == 0 ) {
	    cfreq [c]++; 	/* gather frequencies at start of input */
	    if ( (count_int)in_count >  HOG_CHECK ) {
	    	cstat_flg = 1;
		chog = hogtally();	/* compute char hog */
		if(chog != CHOG) 	/* fixup for wrong assumption */
D 2
		    creset( (count_int) free_ent );
E 2
I 2
		    cl_cache( (count_int) free_ent );
E 2
	    }
	}
	if ( c == chog )
	    if ( (i = hashcache [ent]) ) {	/* cache -> code */
	    	ent = i;
	    	continue;
	    }
E 5
	fcode = (long) (((long) c << maxbits) + ent);
D 2
#ifdef pdp11
E 2
I 2
D 5
#ifdef SHORT_INT
E 2
	i = (((c + 12347) * ent) & 077777) % HSIZE;	/* avoid 'lrem' call */
D 2
#else !pdp11
E 2
I 2
#else !SHORT_INT
E 2
	i = fcode % hsize_reg;			/* division hashing */
D 2
#endif pdp11
E 2
I 2
#endif SHORT_INT
E 5
I 5
 	i = ((c << hshift) ^ ent);	/* xor hashing */
E 5
E 2

D 5
	if ( htab [i] == fcode ) {
	    ent = codetab [i];
E 5
I 5
	if ( htabof (i) == fcode ) {
	    ent = codetabof (i);
E 5
	    continue;
D 5
	} else if ( (long)htab [i] < 0 )	/* empty slot */
E 5
I 5
	} else if ( (long)htabof (i) < 0 )	/* empty slot */
E 5
	    goto nomatch;
D 5
	disp = hsize_reg - i;		/* secondary hash (G. Knott) */
E 5
I 5
 	disp = hsize_reg - i;		/* secondary hash (after G. Knott) */
E 5
	if ( i == 0 )
	    disp = 1;
probe:
	if ( (i -= disp) < 0 )
	    i += hsize_reg;

D 5
	if ( htab [i] == fcode ) {
	    ent = codetab [i];
E 5
I 5
	if ( htabof (i) == fcode ) {
	    ent = codetabof (i);
E 5
	    continue;
	}
D 5
	if ( (long)htab [i] > 0 ) 
E 5
I 5
	if ( (long)htabof (i) > 0 ) 
E 5
	    goto probe;
nomatch:
	output ( (code_int) ent );
	out_count++;
D 5
#ifdef interdata
E 5
I 5
 	ent = c;
#ifdef SIGNED_COMPARE_SLOW
E 5
	if ( (unsigned) free_ent < (unsigned) maxmaxcode) {
#else
	if ( free_ent < maxmaxcode ) {
#endif
D 5
	    if ( c == chog )		/* code -> cache */
	        hashcache [ent] = free_ent;
	      				/* code -> hashtable */
	    codetab [i] = free_ent++;
	    htab [i] = fcode;
E 5
I 5
 	    codetabof (i) = free_ent++;	/* code -> hashtable */
	    htabof (i) = fcode;
E 5
	}
	else if ( (count_int)in_count >= checkpoint && block_compress )
D 2
	    clear ();
E 2
I 2
	    cl_block ();
E 2
D 5
	ent = c;
E 5
    }
D 5
fin:
E 5
    /*
     * Put out the final code.
     */
    output( (code_int)ent );
    out_count++;
    output( (code_int)-1 );

    /*
     * Print out stats on stderr
     */
    if(zcat_flg == 0 && !quiet) {
#ifdef DEBUG
	fprintf( stderr,
D 5
	"%ld chars in, %ld codes (%ld bytes) out, compression factor %g\n",
		in_count, out_count, bytes_out,
		(double)in_count / (double)bytes_out );
	fprintf( stderr, "\tCompression as in compact: %5.2f%%\n",
		100.0 * ( in_count - bytes_out ) / (double) in_count );
	fprintf( stderr, "\tLargest code was %d (%d bits)\n", free_ent - 1, n_bits );
#else DEBUG
	fprintf( stderr, "Compression: %5.2f%%",
		100.0 * ( in_count - bytes_out ) / (double) in_count );
#endif DEBUG
E 5
I 5
		"%ld chars in, %ld codes (%ld bytes) out, compression factor: ",
		in_count, out_count, bytes_out );
	prratio( stderr, in_count, bytes_out );
	fprintf( stderr, "\n");
	fprintf( stderr, "\tCompression as in compact: " );
	prratio( stderr, in_count-bytes_out, in_count );
	fprintf( stderr, "\n");
	fprintf( stderr, "\tLargest code (of last block) was %d (%d bits)\n",
		free_ent - 1, n_bits );
#else /* !DEBUG */
	fprintf( stderr, "Compression: " );
	prratio( stderr, in_count-bytes_out, in_count );
#endif /* DEBUG */
E 5
    }
    if(bytes_out > in_count)	/* exit(2) if no savings */
	exit_stat = 2;
    return;
}

/*****************************************************************
 * TAG( output )
 *
 * Output the given code.
 * Inputs:
 * 	code:	A n_bits-bit integer.  If == -1, then EOF.  This assumes
 *		that n_bits =< (long)wordsize - 1.
 * Outputs:
 * 	Outputs code to the file.
 * Assumptions:
 *	Chars are 8 bits long.
 * Algorithm:
 * 	Maintain a BITS character long buffer (so that 8 codes will
 * fit in it exactly).  Use the VAX insv instruction to insert each
 * code in turn.  When the buffer fills up empty it and start over.
 */

static char buf[BITS];

#ifndef vax
char_type lmask[9] = {0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00};
char_type rmask[9] = {0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff};
D 5
#endif !vax
E 5
I 5
#endif /* vax */
E 5

output( code )
code_int  code;
{
#ifdef DEBUG
    static int col = 0;
D 5
#endif DEBUG
E 5
I 5
#endif /* DEBUG */
E 5

    /*
     * On the VAX, it is important to have the register declarations
     * in exactly the order given, or the asm will break.
     */
    register int r_off = offset, bits= n_bits;
    register char * bp = buf;

I 5
#ifdef DEBUG
	if ( verbose )
	    fprintf( stderr, "%5d%c", code,
		    (col+=6) >= 74 ? (col = 0, '\n') : ' ' );
#endif /* DEBUG */
E 5
    if ( code >= 0 ) {
#ifdef vax
D 2
	/* VAX DEPENDENT!! Implementation on other machines may be
	 * difficult.
E 2
I 2
D 5
	/* VAX DEPENDENT!! Implementation on other machines may be difficult.
E 5
I 5
	/* VAX DEPENDENT!! Implementation on other machines is below.
E 5
E 2
	 *
	 * Translation: Insert BITS bits from the argument starting at
	 * offset bits from the beginning of buf.
	 */
D 5
	0;	/* C compiler bug ?? */
E 5
I 5
	0;	/* Work around for pcc -O bug with asm and if stmt */
E 5
	asm( "insv	4(ap),r11,r10,(r9)" );
D 5
#else not a vax
E 5
I 5
#else /* not a vax */
E 5
D 2
/* WARNING: byte/bit numbering on the vax is simulated by the following code
*/
E 2
I 2
/* 
 * byte/bit numbering on the VAX is simulated by the following code
 */
E 2
	/*
	 * Get to the first byte.
	 */
	bp += (r_off >> 3);
	r_off &= 7;
	/*
	 * Since code is always >= 8 bits, only need to mask the first
	 * hunk on the left.
	 */
	*bp = (*bp & rmask[r_off]) | (code << r_off) & lmask[r_off];
	bp++;
	bits -= (8 - r_off);
	code >>= 8 - r_off;
	/* Get any 8 bit parts in the middle (<=1 for up to 16 bits). */
	if ( bits >= 8 ) {
	    *bp++ = code;
	    code >>= 8;
	    bits -= 8;
	}
	/* Last bits. */
	if(bits)
	    *bp = code;
D 5
#endif vax
E 5
I 5
#endif /* vax */
E 5
	offset += n_bits;
	if ( offset == (n_bits << 3) ) {
	    bp = buf;
	    bits = n_bits;
	    bytes_out += bits;
	    do
		putchar(*bp++);
	    while(--bits);
D 5
	    if (ferror(stdout))
		writeerr();
E 5
	    offset = 0;
	}
D 5
#ifdef DEBUG
	if ( verbose )
	    fprintf( stderr, "%5d%c", code,
		    (col+=6) >= 74 ? (col = 0, '\n') : ' ' );
#endif DEBUG
E 5

	/*
	 * If the next entry is going to be too big for the code size,
	 * then increase it, if possible.
	 */
	if ( free_ent > maxcode || (clear_flg > 0))
	{
	    /*
	     * Write the whole buffer, because the input side won't
	     * discover the size increase until after it has read it.
	     */
	    if ( offset > 0 ) {
		if( fwrite( buf, 1, n_bits, stdout ) != n_bits)
			writeerr();
		bytes_out += n_bits;
	    }
	    offset = 0;

	    if ( clear_flg ) {
    	        maxcode = MAXCODE (n_bits = INIT_BITS);
	        clear_flg = 0;
	    }
	    else {
	    	n_bits++;
	    	if ( n_bits == maxbits )
		    maxcode = maxmaxcode;
	    	else
		    maxcode = MAXCODE(n_bits);
	    }
#ifdef DEBUG
	    if ( debug ) {
		fprintf( stderr, "\nChange to %d bits\n", n_bits );
		col = 0;
	    }
D 5
#endif DEBUG
E 5
I 5
#endif /* DEBUG */
E 5
	}
    } else {
	/*
	 * At EOF, write the rest of the buffer.
	 */
	if ( offset > 0 )
	    fwrite( buf, 1, (offset + 7) / 8, stdout );
	bytes_out += (offset + 7) / 8;
	offset = 0;
	fflush( stdout );
#ifdef DEBUG
	if ( verbose )
	    fprintf( stderr, "\n" );
D 5
#endif DEBUG
E 5
I 5
#endif /* DEBUG */
E 5
	if( ferror( stdout ) )
		writeerr();
    }
}

I 2
D 5
#ifdef SMALL_STACK
    char_type stack[MAXSTACK];
#endif
E 5
I 5
/*
 * Decompress stdin to stdout.  This routine adapts to the codes in the
 * file building the "string" table on-the-fly; requiring no table to
 * be stored in the compressed file.  The tables used herein are shared
 * with those of the compress() routine.  See the definitions above.
 */
E 5

E 2
decompress() {
D 2
    register int stack_top = MAXSTACK;
    register code_int code, oldcode, incode;
E 2
I 2
    register char_type *stackp;
E 2
    register int finchar;
D 2
    char stack[MAXSTACK];
E 2
I 2
    register code_int code, oldcode, incode;
I 11

#ifndef COMPATIBLE
    if (strong_comp) {
D 12
	compFile cf;
	char buf[4096];
	int len, err;

	cf = uncompress_open(stdin);
	if (cf == NULL) {
	    fprintf(stderr, "uncompress: not enough memory for strong compression state info\n");
	    unlink(ofname);
	    exit(1);
	}
	for (;;) {
	    len = compread(cf, buf, sizeof(buf));
	    if (len < 0) {
		fprintf(stderr, "uncompress: compread: %s\n", comperror(cf, &err));
		unlink(ofname);
		exit(1);
	    }
	    if (len == 0)
		break;
	    if (fwrite(buf, 1, len, stdout) != len) {
		perror("compress: fwrite");
		unlink(ofname);
		exit(1);
	    }
	}
	if (compclose(cf) != Z_OK) {
	    fprintf(stderr, "compress: compclose: %s\n", comperror(cf, &err));
	    unlink(ofname);
	    exit(1);
	}
E 12
I 12
	strong_decompress();
E 12
	return;
    }
#endif /* COMPATIBLE */
E 11
E 2

I 2
D 5
#ifndef SMALL_STACK
    char_type stack[MAXSTACK];
#endif

E 5
E 2
    /*
     * As above, initialize the first 256 entries in the table.
     */
    maxcode = MAXCODE(n_bits = INIT_BITS);
    for ( code = 255; code >= 0; code-- ) {
D 5
	tab_prefix[code] = 0;
	tab_suffix[code] = (char_type)code;
E 5
I 5
	tab_prefixof(code) = 0;
	tab_suffixof(code) = (char_type)code;
E 5
    }
    free_ent = ((block_compress) ? FIRST : 256 );

    finchar = oldcode = getcode();
I 5
    if(oldcode == -1)	/* EOF already? */
	return;			/* Get out of here */
E 5
    putchar( (char)finchar );		/* first code must be 8 bits = char */
I 2
D 5
    stackp = &stack[0];
E 5
I 5
    if(ferror(stdout))		/* Crash if can't write */
	writeerr();
    stackp = de_stack;
E 5
E 2

D 5
    while ( (code = getcode()) != -1 ) {
E 5
I 5
    while ( (code = getcode()) > -1 ) {
E 5

	if ( (code == CLEAR) && block_compress ) {
D 2
	    for ( code = 255; code > 0; code -= 4 ) {
		tab_prefix [code-3] = 0;
		tab_prefix [code-2] = 0;
		tab_prefix [code-1] = 0;
		tab_prefix [code] = 0;
	    }
E 2
I 2
	    for ( code = 255; code >= 0; code-- )
D 5
		tab_prefix[code] = 0;
E 5
I 5
		tab_prefixof(code) = 0;
E 5
E 2
	    clear_flg = 1;
	    free_ent = FIRST - 1;
	    if ( (code = getcode ()) == -1 )	/* O, untimely death! */
		break;
	}
	incode = code;
	/*
	 * Special case for KwKwK string.
	 */
	if ( code >= free_ent ) {
D 2
	    stack[--stack_top] = finchar;
E 2
I 2
            *stackp++ = finchar;
E 2
	    code = oldcode;
	}

	/*
	 * Generate output characters in reverse order
	 */
D 5
#ifdef interdata
E 5
I 5
#ifdef SIGNED_COMPARE_SLOW
E 5
	while ( ((unsigned long)code) >= ((unsigned long)256) ) {
D 5
#else !interdata
E 5
I 5
#else
E 5
	while ( code >= 256 ) {
D 5
#endif interdata
D 2
	    stack[--stack_top] = tab_suffix[code];
E 2
I 2
	    *stackp++ = tab_suffix[code];
E 2
	    code = tab_prefix[code];
E 5
I 5
#endif
	    *stackp++ = tab_suffixof(code);
	    code = tab_prefixof(code);
E 5
	}
D 2
	stack[--stack_top] = finchar = tab_suffix[code];
E 2
I 2
D 5
	*stackp++ = finchar = tab_suffix[code];
E 5
I 5
	*stackp++ = finchar = tab_suffixof(code);
E 5
E 2

	/*
	 * And put them out in forward order
	 */
D 2
	for ( ; stack_top < MAXSTACK; stack_top++ )
		putchar(stack[stack_top]);
E 2
I 2
D 5
	while ( --stackp > &stack[0] )
	    putchar ( *stackp );
	putchar ( *stackp );
E 2
	if (ferror(stdout))
		writeerr ( );
E 5
I 5
	do
	    putchar ( *--stackp );
	while ( stackp > de_stack );
E 5
D 2
	stack_top = MAXSTACK;
E 2

	/*
	 * Generate the new entry.
	 */
	if ( (code=free_ent) < maxmaxcode ) {
D 5
	    tab_prefix[code] = (unsigned short)oldcode;
	    tab_suffix[code] = finchar;
E 5
I 5
	    tab_prefixof(code) = (unsigned short)oldcode;
	    tab_suffixof(code) = finchar;
E 5
	    free_ent = code+1;
	} 
	/*
	 * Remember previous code.
	 */
	oldcode = incode;
    }
    fflush( stdout );
    if(ferror(stdout))
	writeerr();
}

D 2

E 2
/*****************************************************************
 * TAG( getcode )
 *
 * Read one code from the standard input.  If EOF, return -1.
 * Inputs:
 * 	stdin
 * Outputs:
 * 	code or -1 is returned.
 */

code_int
getcode() {
    /*
     * On the VAX, it is important to have the register declarations
     * in exactly the order given, or the asm will break.
     */
    register code_int code;
    static int offset = 0, size = 0;
    static char_type buf[BITS];
    register int r_off, bits;
    register char_type *bp = buf;

    if ( clear_flg > 0 || offset >= size || free_ent > maxcode ) {
	/*
	 * If the next entry will be too big for the current code
	 * size, then we must increase the size.  This implies reading
	 * a new buffer full, too.
	 */
	if ( free_ent > maxcode ) {
	    n_bits++;
	    if ( n_bits == maxbits )
		maxcode = maxmaxcode;	/* won't get any bigger now */
	    else
		maxcode = MAXCODE(n_bits);
	}
	if ( clear_flg > 0) {
    	    maxcode = MAXCODE (n_bits = INIT_BITS);
	    clear_flg = 0;
	}
	size = fread( buf, 1, n_bits, stdin );
	if ( size <= 0 )
	    return -1;			/* end of file */
	offset = 0;
	/* Round size down to integral number of codes */
	size = (size << 3) - (n_bits - 1);
    }
    r_off = offset;
    bits = n_bits;
#ifdef vax
    asm( "extzv   r10,r9,(r8),r11" );
D 5
#else not a vax
E 5
I 5
#else /* not a vax */
E 5
	/*
	 * Get to the first byte.
	 */
	bp += (r_off >> 3);
	r_off &= 7;
	/* Get first part (low order bits) */
#ifdef NO_UCHAR
	code = ((*bp++ >> r_off) & rmask[8 - r_off]) & 0xff;
D 5
#else  NO_UCHAR
E 5
I 5
#else
E 5
	code = (*bp++ >> r_off);
D 5
#endif NO_UCHAR
E 5
I 5
#endif /* NO_UCHAR */
E 5
	bits -= (8 - r_off);
	r_off = 8 - r_off;		/* now, offset into code word */
	/* Get any 8 bit parts in the middle (<=1 for up to 16 bits). */
	if ( bits >= 8 ) {
#ifdef NO_UCHAR
	    code |= (*bp++ & 0xff) << r_off;
D 5
#else  NO_UCHAR
E 5
I 5
#else
E 5
	    code |= *bp++ << r_off;
D 5
#endif NO_UCHAR
E 5
I 5
#endif /* NO_UCHAR */
E 5
	    r_off += 8;
	    bits -= 8;
	}
	/* high order bits. */
	code |= (*bp & rmask[bits]) << r_off;
D 5
#endif vax
E 5
I 5
#endif /* vax */
E 5
    offset += n_bits;

    return code;
}

char *
rindex(s, c)		/* For those who don't have it in libc.a */
register char *s, c;
{
	char *p;
	for (p = NULL; *s; s++)
	    if (*s == c)
		p = s;
	return(p);
}

#ifdef DEBUG
printcodes()
{
    /*
D 2
     * Just print out codes from input file.  Mostly for debugging.
E 2
I 2
     * Just print out codes from input file.  For debugging.
E 2
     */
    code_int code;
    int col = 0, bits;

    bits = n_bits = INIT_BITS;
    maxcode = MAXCODE(n_bits);
    free_ent = ((block_compress) ? FIRST : 256 );
    while ( ( code = getcode() ) >= 0 ) {
	if ( (code == CLEAR) && block_compress ) {
   	    free_ent = FIRST - 1;
   	    clear_flg = 1;
	}
	else if ( free_ent < maxmaxcode )
	    free_ent++;
	if ( bits != n_bits ) {
	    fprintf(stderr, "\nChange to %d bits\n", n_bits );
	    bits = n_bits;
	    col = 0;
	}
	fprintf(stderr, "%5d%c", code, (col+=6) >= 74 ? (col = 0, '\n') : ' ' );
    }
    putc( '\n', stderr );
    exit( 0 );
}

I 5
code_int sorttab[1<<BITS];	/* sorted pointers into htab */

E 5
dump_tab()	/* dump string table */
{
D 5
    register int i;
E 5
I 5
    register int i, first;
E 5
    register ent;
D 5
    char stack[4 * MAXSTACK];	/* \nnn makes it 4 times bigger */
    int stack_top = 4 * MAXSTACK;
E 5
I 5
#define STACK_SIZE	15000
    int stack_top = STACK_SIZE;
    register c;
E 5

D 5
    for ( i = 0; i < free_ent; i++ ) {
	ent = i;
	if ( isascii(tab_suffix[ent]) && isprint(tab_suffix[ent]) )
	    fprintf( stderr, "%5d: %5d/'%c'  \"",
			ent, tab_prefix[ent], tab_suffix[ent] );
	else
	    fprintf( stderr, "%5d: %5d/\\%03o \"",
			ent, tab_prefix[ent], tab_suffix[ent] );
	stack[--stack_top] = '\n';
	stack[--stack_top] = '"';
	for ( ; ent != NULL;
		ent = (ent >= FIRST ? tab_prefix[ent] : NULL) ) {
	    if ( isascii(tab_suffix[ent]) && isprint(tab_suffix[ent]) )
		stack[--stack_top] = tab_suffix[ent];
	    else {
		switch( tab_suffix[ent] ) {
		case '\n': stack[--stack_top] = 'n'; break;
		case '\t': stack[--stack_top] = 't'; break;
		case '\b': stack[--stack_top] = 'b'; break;
		case '\f': stack[--stack_top] = 'f'; break;
		case '\r': stack[--stack_top] = 'r'; break;
		default:
		    stack[--stack_top] = '0' + tab_suffix[ent] % 8;
		    stack[--stack_top] = '0' + (tab_suffix[ent] / 8) % 8;
		    stack[--stack_top] = '0' + tab_suffix[ent] / 64;
		    break;
E 5
I 5
    if(do_decomp == 0) {	/* compressing */
	register int flag = 1;

	for(i=0; i<hsize; i++) {	/* build sort pointers */
		if((long)htabof(i) >= 0) {
			sorttab[codetabof(i)] = i;
E 5
		}
D 5
		stack[--stack_top] = '\\';
	    }
E 5
	}
D 5
	fwrite( &stack[stack_top], 1, 4 * MAXSTACK - stack_top, stderr );
	stack_top = 4 * MAXSTACK;
E 5
I 5
	first = block_compress ? FIRST : 256;
	for(i = first; i < free_ent; i++) {
		fprintf(stderr, "%5d: \"", i);
		de_stack[--stack_top] = '\n';
		de_stack[--stack_top] = '"';
		stack_top = in_stack((htabof(sorttab[i])>>maxbits)&0xff, 
                                     stack_top);
		for(ent=htabof(sorttab[i]) & ((1<<maxbits)-1);
		    ent > 256;
		    ent=htabof(sorttab[ent]) & ((1<<maxbits)-1)) {
			stack_top = in_stack(htabof(sorttab[ent]) >> maxbits,
						stack_top);
		}
		stack_top = in_stack(ent, stack_top);
		fwrite( &de_stack[stack_top], 1, STACK_SIZE-stack_top, stderr);
	   	stack_top = STACK_SIZE;
	}
   } else if(!debug) {	/* decompressing */

       for ( i = 0; i < free_ent; i++ ) {
	   ent = i;
	   c = tab_suffixof(ent);
	   if ( isascii(c) && isprint(c) )
	       fprintf( stderr, "%5d: %5d/'%c'  \"",
			   ent, tab_prefixof(ent), c );
	   else
	       fprintf( stderr, "%5d: %5d/\\%03o \"",
			   ent, tab_prefixof(ent), c );
	   de_stack[--stack_top] = '\n';
	   de_stack[--stack_top] = '"';
	   for ( ; ent != NULL;
		   ent = (ent >= FIRST ? tab_prefixof(ent) : NULL) ) {
	       stack_top = in_stack(tab_suffixof(ent), stack_top);
	   }
	   fwrite( &de_stack[stack_top], 1, STACK_SIZE - stack_top, stderr );
	   stack_top = STACK_SIZE;
       }
E 5
    }
}
D 5
#endif DEBUG
E 5

D 5
/*****************************************************************
 * TAG( writeerr )
 *
 * Exits with a message.  We only check for write errors often enough
 * to avoid a lot of "file system full" messages, not on every write.
 * ferror() check after fflush will catch any others (I trust).
 *
 */
E 5
I 5
int
in_stack(c, stack_top)
	register c, stack_top;
{
	if ( (isascii(c) && isprint(c) && c != '\\') || c == ' ' ) {
	    de_stack[--stack_top] = c;
	} else {
	    switch( c ) {
	    case '\n': de_stack[--stack_top] = 'n'; break;
	    case '\t': de_stack[--stack_top] = 't'; break;
	    case '\b': de_stack[--stack_top] = 'b'; break;
	    case '\f': de_stack[--stack_top] = 'f'; break;
	    case '\r': de_stack[--stack_top] = 'r'; break;
	    case '\\': de_stack[--stack_top] = '\\'; break;
	    default:
	 	de_stack[--stack_top] = '0' + c % 8;
	 	de_stack[--stack_top] = '0' + (c / 8) % 8;
	 	de_stack[--stack_top] = '0' + c / 64;
	 	break;
	    }
	    de_stack[--stack_top] = '\\';
	}
	return stack_top;
}
#endif /* DEBUG */
I 12

/* Strong compression mode. These are just hooks into zlib. */

strong_compress()
{
	register compFile cf;
	register char *buf;
	register int len, buflen;
	struct stat stbuf;
	int err;
	char *errmsg;

	cf = compress_open(stdout, strong_level);
	if (cf == NULL) {
	    fprintf(stderr,
	     "compress: not enough memory for strong compression state info\n");
	    unlink(ofname);
	    exit(1);
	}
	fstat(0, &stbuf);
	buflen = stbuf.st_blksize;
	buf = malloc(buflen);
	if (buf == NULL) {
	    fprintf(stderr,
		"compress: not enough memory for strong compression buffer\n");
	    unlink(ofname);
	    exit(1);
	}
	for (;;) {
	    len = read(0, buf, buflen);
	    if (len < 0) {
		perror(zcat_flg ? "stdin" : quiet ? "input" : NULL);
		unlink(ofname);
		exit(1);
	    }
	    if (len == 0)
		break;
	    compwrite(cf, buf, len);
	    errmsg = comperror(cf, &err);
	    if (err != Z_OK) {
		fprintf(stderr, "%s: %s\n", ofname, errmsg);
		unlink ( ofname );
		exit ( 1 );
	    }
	}
	free(buf);
	if (compclose(cf) != Z_OK) {
		fprintf(stderr, "%s: %s\n", ofname, comperror(cf, &err));
		unlink ( ofname );
		exit ( 1 );
	}
}

strong_decompress()
{
	register compFile cf;
	register char *buf;
	register int len, buflen;
	struct stat stbuf;
	int err;
	char *errmsg;
	long pos;

	cf = uncompress_open(stdin);
	if (cf == NULL) {
	    fprintf(stderr,
	   "uncompress: not enough memory for strong compression state info\n");
	    unlink(ofname);
	    exit(1);
	}
	fstat(1, &stbuf);
	buflen = stbuf.st_blksize;
	buf = malloc(buflen);
	if (buf == NULL) {
	    fprintf(stderr,
	      "uncompress: not enough memory for strong compression buffer\n");
	    unlink(ofname);
	    exit(1);
	}
	for (;;) {
	    len = compread(cf, buf, buflen);
	    if (len > 0) {
		if (write(1, buf, len) != len)
		    writeerr();
	    }
	    errmsg = comperror(cf, &err);
	    if (err == Z_STREAM_END)
		break;
	    if (err != Z_OK) {
		if (err == Z_ERRNO) {
		    perror(zcat_flg ? "stdin" : quiet ? "input" : NULL);
		    unlink(ofname);
		    exit(1);
		} else {
		    fprintf(stderr, "%s\n", errmsg);
		    unlink(ofname);
		    exit(1);
		}
	    }
	}
	free(buf);
	fstat(0, &stbuf);
	if ((stbuf.st_mode & S_IFMT) == S_IFREG) {
	    pos = ftell(stdin);
	    if (pos < stbuf.st_size)
		fprintf(stderr,
	  "warning: compressed data ends at %ld, appendage follows (ignored)\n",
			pos);
	}
	if (compclose(cf) != Z_OK) {
	    fprintf(stderr, "%s\n", comperror(cf, &err));
	    unlink(ofname);
	    exit(1);
	}
}
E 12
E 5

writeerr()
{
    perror ( ofname );
    unlink ( ofname );
    exit ( 1 );
}

copystat(ifname, ofname)
char *ifname, *ofname;
{
    struct stat statbuf;
    int mode;
    time_t timep[2];

    fclose(stdout);
    if (stat(ifname, &statbuf)) {		/* Get stat on input file */
	perror(ifname);
	return;
    }
    if ((statbuf.st_mode & S_IFMT/*0170000*/) != S_IFREG/*0100000*/) {
	if(quiet)
D 2
		fprintf(stderr, "%s: ", ifname);
E 2
I 2
	    	fprintf(stderr, "%s: ", ifname);
E 2
	fprintf(stderr, " -- not a regular file: unchanged");
	exit_stat = 1;
I 10
	perm_stat = 1;
E 10
    } else if (statbuf.st_nlink > 1) {
	if(quiet)
D 2
		fprintf(stderr, "%s: ", ifname);
E 2
I 2
	    	fprintf(stderr, "%s: ", ifname);
E 2
	fprintf(stderr, " -- has %d other links: unchanged",
		statbuf.st_nlink - 1);
	exit_stat = 1;
I 10
	perm_stat = 1;
E 10
D 2
    } else if (exit_stat == 2 && (!force)) { /* No compression: remove file.Z */
E 2
I 2
D 5
    } else if (exit_stat == 2 && (!force) && !quiet) { /* No compression: remove file.Z */
E 2
	fprintf(stderr, " -- file unchanged");
E 5
I 5
    } else if (exit_stat == 2 && (!force)) { /* No compression: remove file.Z */
	if(!quiet)
		fprintf(stderr, " -- file unchanged");
E 5
    } else {			/* ***** Successful Compression ***** */
	exit_stat = 0;
	mode = statbuf.st_mode & 07777;
	if (chmod(ofname, mode))		/* Copy modes */
	    perror(ofname);
	chown(ofname, statbuf.st_uid, statbuf.st_gid);	/* Copy ownership */
	timep[0] = statbuf.st_atime;
	timep[1] = statbuf.st_mtime;
	utime(ofname, timep);	/* Update last accessed and modified times */
	if (unlink(ifname))	/* Remove input file */
	    perror(ifname);
	if(!quiet)
		fprintf(stderr, " -- replaced with %s", ofname);
	return;		/* Successful return */
    }

    /* Unsuccessful return -- one of the tests failed */
    if (unlink(ofname))
	perror(ofname);
}
D 10
/*
 * This routine returns 1 if we are running in the foreground and stderr
 * is a tty.
 */
foreground()
{
	if(bgnd_flag) {	/* background? */
		return(0);
	} else {			/* foreground */
		if(isatty(2)) {		/* and stderr is a tty */
			return(1);
		} else {
			return(0);
		}
	}
}
E 10

onintr ( )
{
D 4
    unlink ( ofname );
E 4
I 4
D 5
    if (!zcat_flg)
	unlink ( ofname );
E 5
I 5
D 6
    unlink ( ofname );
E 6
I 6
D 9
    if (!zcat_flg)
E 9
I 9
    if (!precious)
E 9
	unlink ( ofname );
E 6
E 5
E 4
    exit ( 1 );
}

I 5
oops ( )	/* wild pointer -- assume bad input */
{
D 10
    if ( do_decomp == 1 ) 
E 10
I 10
    if ( do_decomp ) 
E 10
    	fprintf ( stderr, "uncompress: corrupt input\n" );
    unlink ( ofname );
    exit ( 1 );
}

E 5
D 2
clear ()		/* table clear for block compress */
E 2
I 2
cl_block ()		/* table clear for block compress */
E 2
{
D 2
    register code_int i;
    register count_int *p, *endp;
    register unsigned short *q;

E 2
D 5
#ifdef DEBUG
	if(debug)
    		fprintf ( stderr, "count: %ld ratio: %f\n", in_count,
     		(double) in_count / (double) bytes_out );
#endif DEBUG
E 5
I 5
    register long int rat;
E 5

    checkpoint = in_count + CHECK_GAP;
D 5
    if ( (double) in_count / (double) bytes_out > ratio )
	ratio = (double) in_count / (double) bytes_out;
    else {
	ratio = 0.0;
#ifdef USERMEM
	if ( maxbits <= FBITS ) 		/* sparse array clear */
D 2
	    for ( i = (1 << maxbits) - 1; i >= 0; i-- )
		ftable [fcodemem [i]] = 0;	/* indirect thru "shadow" */
E 2
I 2
	    cl_sparse ();
E 2
	else 
#endif USERMEM					/* hash table clear */
	{
D 2
	    endp = &htab [hsize];
	    for ( p = &htab [0], q = &codetab [0]; p < endp; ) {
		*p++ = -1;
		*q++ = 0;
	    }
	    creset ( MAX_CACHE );
E 2
I 2
	    cl_hash ( (count_int) hsize );
E 5
I 5
#ifdef DEBUG
	if ( debug ) {
    		fprintf ( stderr, "count: %ld, ratio: ", in_count );
     		prratio ( stderr, in_count, bytes_out );
		fprintf ( stderr, "\n");
E 5
E 2
	}
I 5
#endif /* DEBUG */

    if(in_count > 0x007fffff) {	/* shift will overflow */
	rat = bytes_out >> 8;
	if(rat == 0) {		/* Don't divide by zero */
	    rat = 0x7fffffff;
	} else {
	    rat = in_count / rat;
	}
    } else {
	rat = (in_count << 8) / bytes_out;	/* 8 fractional bits */
    }
    if ( rat > ratio ) {
	ratio = rat;
    } else {
	ratio = 0;
#ifdef DEBUG
	if(verbose)
		dump_tab();	/* dump string table */
#endif
 	cl_hash ( (count_int) hsize );
E 5
	free_ent = FIRST;
	clear_flg = 1;
	output ( (code_int) CLEAR );
#ifdef DEBUG
	if(debug)
    		fprintf ( stderr, "clear\n" );
D 5
#endif DEBUG
E 5
I 5
#endif /* DEBUG */
E 5
    }
}

D 2
creset ( n )	/* clear hash cache */
E 2
I 2
D 5
cl_cache ( n )			/* clear hash cache */
E 2
    register count_int n;	/* clear at least this many entries */
{
    register count_int i;
    register unsigned short *hash_p;
    register unsigned short zero = 0;
D 2
    static int nfiles = 0;
E 2

D 2
    if ( nfiles++ == 0 )	/* No clear needed if first time */
E 2
I 2
    if ( nfiles++ == 0 )	/* no clear needed if first time */
E 2
	return;
    n = (n+15) & (-16);
    hash_p = hashcache + n;
D 2
    for ( i = n; i > 0; i -=16 ) {
E 2
I 2
    for ( i = n; i > 0; i -=16 ) {  /* can do BSD bzero(3) or Sys V memset(3) */
E 2
	*(hash_p-16) = zero;
	*(hash_p-15) = zero;
	*(hash_p-14) = zero;
	*(hash_p-13) = zero;
	*(hash_p-12) = zero;
	*(hash_p-11) = zero;
	*(hash_p-10) = zero;
	*(hash_p-9) = zero;
	*(hash_p-8) = zero;
	*(hash_p-7) = zero;
	*(hash_p-6) = zero;
	*(hash_p-5) = zero;
	*(hash_p-4) = zero;
	*(hash_p-3) = zero;
	*(hash_p-2) = zero;
	*(hash_p-1) = zero;
	hash_p -= 16;
    }
}

hogtally ()	/* compute character code hog */
{
    register int i, most;

    for ( i = most = 0; i < 256; i++ )
	if ( cfreq [i] >= cfreq [most] )
	    most = i;
    return ( most );
}

D 2
cl_hash(hsize)
	register int hsize;
E 2
I 2
cl_hash(hsize)		/* clear hash cache, re-init code table */
E 5
I 5
cl_hash(hsize)		/* reset code table */
E 5
	register count_int hsize;
E 2
{
I 5
#ifndef XENIX_16	/* Normal machine */
E 5
	register count_int *htab_p = htab+hsize;
I 5
#else
	register j;
	register long k = hsize;
	register count_int *htab_p;
#endif
E 5
D 2
	register int i;
E 2
I 2
D 3
	register count_int i;
E 3
I 3
	register long i;
E 3
E 2
	register long m1 = -1;

D 2
	/* clear hashcache */
#define	min(a,b)	((a>b) ? b : a)
	creset( min((count_int)hsize, MAX_CACHE) );
E 2
I 2
D 5
	cl_cache( min((count_int)hsize, MAX_CACHE) );
E 2

E 5
I 5
#ifdef XENIX_16
    for(j=0; j<=8 && k>=0; j++,k-=8192) {
	i = 8192;
	if(k < 8192) {
		i = k;
	}
	htab_p = &(htab[j][i]);
	i -= 16;
	if(i > 0) {
#else
E 5
	i = hsize - 16;
D 5
	do {
E 5
I 5
#endif
 	do {				/* might use Sys V memset(3) here */
E 5
		*(htab_p-16) = m1;
		*(htab_p-15) = m1;
		*(htab_p-14) = m1;
		*(htab_p-13) = m1;
		*(htab_p-12) = m1;
		*(htab_p-11) = m1;
		*(htab_p-10) = m1;
		*(htab_p-9) = m1;
		*(htab_p-8) = m1;
		*(htab_p-7) = m1;
		*(htab_p-6) = m1;
		*(htab_p-5) = m1;
		*(htab_p-4) = m1;
		*(htab_p-3) = m1;
		*(htab_p-2) = m1;
		*(htab_p-1) = m1;
		htab_p -= 16;
	} while ((i -= 16) >= 0);
I 5
#ifdef XENIX_16
	}
    }
#endif
E 5
    	for ( i += 16; i > 0; i-- )
		*--htab_p = m1;
}
I 2

D 5
#ifdef USERMEM
cl_sparse ( )	/* clear sparse table indirectly thru "shadow" array */
E 5
I 5
prratio(stream, num, den)
FILE *stream;
long int num, den;
E 5
{
D 5
	register code_int i;
E 5
I 5
	register int q;			/* Doesn't need to be long */
E 5

D 5
    	for ( i = (1 << maxbits) - 1; i >= 0; i-- )
	    ftable [fcodemem [i]] = 0;
E 5
I 5
	if(num > 214748L) {		/* 2147483647/10000 */
		q = num / (den / 10000L);
	} else {
		q = 10000L * num / den;		/* Long calculations, though */
	}
	if (q < 0) {
		putc('-', stream);
		q = -q;
	}
	fprintf(stream, "%d.%02d%%", q / 100, q % 100);
E 5
}
D 5
#endif USERMEM
E 5
I 5

version()
{
D 8
	fprintf(stderr, "%s\n", rcs_ident);
E 8
I 8
	fprintf(stderr, "%s, Berkeley %I% %G%\n", rcs_ident);
E 8
	fprintf(stderr, "Options: ");
#ifdef vax
	fprintf(stderr, "vax, ");
#endif
#ifdef NO_UCHAR
	fprintf(stderr, "NO_UCHAR, ");
#endif
#ifdef SIGNED_COMPARE_SLOW
	fprintf(stderr, "SIGNED_COMPARE_SLOW, ");
#endif
#ifdef XENIX_16
	fprintf(stderr, "XENIX_16, ");
#endif
#ifdef COMPATIBLE
	fprintf(stderr, "COMPATIBLE, ");
#endif
#ifdef DEBUG
	fprintf(stderr, "DEBUG, ");
#endif
#ifdef BSD4_2
	fprintf(stderr, "BSD4_2, ");
#endif
	fprintf(stderr, "BITS = %d\n", BITS);
}
E 5
E 2
E 1
