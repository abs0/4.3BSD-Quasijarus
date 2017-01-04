h46802
s 00019/00014/00155
d D 5.11 2012/07/14 23:58:01 msokolov 11 10
c xinfo metachar range moved
e
s 00000/00004/00169
d D 5.10 2012/03/05 00:07:49 msokolov 10 9
c first restructuring steps for fcXX and .bd simulation
e
s 00001/00001/00172
d D 5.9 2012/02/16 07:05:50 msokolov 9 8
c put full A.D. year in \n(Yr
e
s 00004/00001/00169
d D 5.8 10/10/07 01:29:46 msokolov 8 7
c the SuperSpecial font is here
e
s 00001/00000/00169
d D 5.7 10/09/22 03:33:44 msokolov 7 6
c \(ci reimplemented via the procset
e
s 00004/00000/00165
d D 5.6 10/08/29 03:35:20 msokolov 6 5
c drawing operations added to pstroff
e
s 00001/00000/00164
d D 5.5 04/09/17 08:44:21 msokolov 5 4
c broke down and added baseline rule to the line drawing chars
e
s 00001/00002/00163
d D 5.4 04/09/15 07:03:41 msokolov 4 3
c replace the LX/HX pair of 16-bit metacharacters with one 32-bit metacharacter
e
s 00003/00003/00162
d D 5.3 04/09/11 22:44:04 msokolov 3 2
c too few bits were allotted for TMASK, not enough for our smaller units
c take advantage of 32 bits
e
s 00003/00000/00162
d D 5.2 04/09/09 08:07:28 msokolov 2 1
c do box drawing characters by adding line-drawn chars to Symbol
c (Type3-like chars added to a Type1 font)
e
s 00162/00000/00000
d D 5.1 04/09/08 16:42:03 msokolov 1 0
c first working version
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include <sys/param.h>
#undef CMASK			/* XXX */
#undef BIG			/* XXX */
#define MAXPTR (-1)		/* max value of any pointer variable */
#ifdef NROFF	/*NROFF*/
#define EM t.Em
#define HOR t.Hor
#define VERT t.Vert
#define INCH 240	/*increments per inch*/
#define SPS INCH/10	/*space size*/
#define SS INCH/10	/* " */
#define UNPAD 0240	/* ISO no-break space */
#define PO 0 /*page offset*/
#define ASCII 1
#define PTID 1
#define LG 0
#define DTAB 0	/*set at 8 Ems at init time*/
#define ICS 2*SPS
#define TEMP 256	/*65K*/
#endif
#ifndef NROFF	/*TROFF*/
#define	INCH	4320	/* troff resolution */
#define	SPS	200	/* space size at 10pt; 1/3 Em */
#define	SS	12	/* space size in 36ths of an em */
#define PO	INCH	/* default page offset 1 inch */
#define HOR	1
#define VERT	1
#define EM	(60*(pts&0377))
#define UNPAD 0240	/* ISO no-break space */
#define ASCII 0
#define PTID 1
#define LG 1
#define DTAB (INCH/2)
#define ICS 3*SPS
#define TEMP 512	/*128K*/
#endif

/*
 * In addition to our public character set (256 characters of the base font
 * + 256 characters of Symbol) we have some internal pseudo-characters
 * for our internal use, just like the classic [nt]roff.  We put them at the
 * control character positions in the upper (Symbol) half.  Note that unlike
 * the characters we've put at the control character positions in TroffEncoding
 * (which are visible and available to the user), these pseudo-characters are
D 11
 * invisible except to those reading the source (assuming no bugs), and since
 * the user cannot enter arbitrary characters with bit 8 set (only a few
 * approved ones through the \(xx mechanism), these pseudo-characters are
 * completely protected from the user.
E 11
I 11
 * invisible except to those reading the source (assuming no bugs):
 * the \Sxx mechanism (unlike \Xxx) only allows xx in the ranges 20-7F
 * and A0-FF, but not 00-1F or 80-9F.
E 11
 *
D 11
 * Pseudo-characters in the range 0x180-0x19F have the extra property that bits
 * outside CMASK are given special meaning and must not be messed with.  (This
 * corresponds to codes >=0370 in the classic [nt]roff.)
E 11
I 11
 * The range 0x100-0x11F is used for our internal functions that are
 * compiled into the code.  The range 0x180-0x19F is used for dynamic
 * allocations to user-defined special (i.e., current font-overriding)
 * named characters.
E 11
 */
#define	CFMINUS	0x101	/* current font minus */
#define NARSP	0x102	/* narrow space */
#define HNSP	0x103	/* half narrow space */
#define FILLER	0x104
#define PRESC	0x105
#define CONT	0x106
#define COLON	0x107
#define XPAR	0x108
#define FLSS	0x109
#define RPT	0x10A
#define TDELIM	0x10B
#define LEFT	0x10C
#define RIGHT	0x10D
#define OHC	0x10E
I 2
#define	UNDRULE	0x10F
#define	OVRRULE	0x110
#define	BOXRULE	0x111
I 5
#define	BASRULE	0x112
I 7
D 8
#define	CIRCLE	0x113
E 8
I 8
D 10
#define	SPECIAL_CI	0x113
#define	SPECIAL_BS	0x114
#define	SPECIAL_LH	0x115
#define	SPECIAL_RH	0x116
E 10
E 8
E 7
E 5
E 2
D 11
#define JREG	0x181
D 4
#define LX	0x182	/*low-order part of xlss*/
#define HX	0x183	/*High-order part of xlss*/
E 4
I 4
#define XLSS	0x182
I 6
#define	DRAWOP	0x183
#define	LINETO	0x184
#define	CURVETO	0x185
#define	DRAWFIN	0x186
E 11
I 11
/*
 * The following metacharacters have the extra property that bits outside
 * CMASK are given special meaning and must not be messed with.  (This hack
 * corresponds to codes >=0370 in the classic [nt]roff.)
 */
#define JREG	0x11A
#define XLSS	0x11B
#define	DRAWOP	0x11C
#define	LINETO	0x11D
#define	CURVETO	0x11E
#define	DRAWFIN	0x11F
E 11
E 6
E 4

D 11
#define	is_xinfo_char(i)	((i) >= 0x180 && (i) <= 0x19F)
E 11
I 11
#define	is_xinfo_char(i)	((i) >= 0x11A && (i) <= 0x11F)
E 11

#include <signal.h>
#define PS 10	/*default point size*/
#define FT 0	/*default font position*/
#define LL 65*INCH/10	/*line length; 39picas=6.5in*/
#define VS INCH/6	/*vert space; 12points*/
#ifdef VMUNIX
#define NN 528	/*number registers*/
#else
#define NN 132	/*number registers*/
#endif
/* #define NN 200	*/
D 9
#define NNAMES 15 /*predefined reg names*/
E 9
I 9
#define NNAMES 16 /*predefined reg names*/
E 9
#define NIF 15	/*if-else nesting*/
#define NS 64	/*name buffer*/
#define NTM 256	/*tm buffer*/
#define NEV 3	/*environments*/
#define EVLSZ 10	/*size of ev stack*/
/* #define EVS 4*256	*/
#ifdef VMUNIX
#define NM 600
#define EVS 6*256	/*environment size in words*/
#else
#define NM 300	/*requests + macros*/
#define EVS 3*256	/*environment size in words*/
#endif
#define DELTA 512	/*delta core bytes*/
#define NHYP 10	/*max hyphens per word*/
#define NHEX 128	/*byte size of exception word list*/
#define NTAB 35	/*tab stops*/
#define NSO 5	/*"so" depth*/
#ifdef VMUNIX
#define WDSIZE 340	/*word buffer size*/
#define LNSIZE 960	/*line buffer size*/
#else
#define WDSIZE 170	/*word buffer size*/
#define LNSIZE 480	/*line buffer size*/
#endif
/* #define LNSIZE 680	*/
#define NDI 5	/*number of diversions*/
#define MOT	0x80000000	/*motion character indicator*/
#define MOTV	0xE0000000	/*clear for motion part*/
#define VMOT	0x40000000	/*vert motion bit*/
#define NMOT	0x20000000	/* negative motion indicator*/
#define MMASK 0100000	/*macro mask indicator*/
#define CMASK	0x800001FF
#define ZBIT	0x200	/*zero width char*/
#define BMASK 0377
#define BYTE 8
#define IMP 004	/*impossible char*/
#define ESC 033
#define NTRAP 20	/*number of traps*/
#define NPN 20	/*numbers in "-o"*/
#define NPP 10	/*pads per field*/
#ifdef VMUNIX
#define FBUFSZ 1024
#else
#define FBUFSZ 256	/*field buf size words*/
#endif
#define OBUFSZ 8192	/*bytes*/
#define IBUFSZ 8192	/*bytes*/
#define NC 256	/*cbuf size words*/
#define NOV 10	/*number of overstrike chars*/
#define LEADER 001
#define TAB 011
D 3
#define TMASK  037777
#define RTAB 0100000
#define CTAB 0040000
E 3
I 3
#define TMASK	0x3FFFFFFF
#define RTAB	0x80000000
#define CTAB	0x40000000
E 3

#define PAIR(A,B) (A|(B<<BYTE))

#define BLK  128	/*alloc block words*/

#ifdef VMUNIX
#define	BIG 1024
#endif VMUNIX

#ifdef BIG
typedef long filep;
#define NBLIST BIG	/*allocation , BIG = 256 per 65k*/
#define BLKBITS 7	/*for BLK=128*/
#endif
#ifndef BIG
typedef unsigned filep;
#define NBLIST TEMP	/*allocation list, TEMP<=512*/
/* BLK*NBLIST<=65536 words, if filep=unsigned */
#define BLKBITS 0
#endif
E 1
