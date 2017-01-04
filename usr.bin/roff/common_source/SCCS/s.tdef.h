h32579
s 00001/00001/00148
d D 4.10 2012/02/16 07:22:29 msokolov 10 9
c put full A.D. year in \n(Yr
e
s 00001/00001/00148
d D 4.9 02/05/28 20:57:16 msokolov 9 8
c Y2K: make \n(yr really two digits as the manual says and add \n(cn for century
e
s 00004/00004/00145
d D 4.8 87/04/30 11:59:56 karels 8 7
c fix machparam, bogus includes
e
s 00003/00001/00146
d D 4.7 86/10/19 23:15:25 sam 7 6
c purge machine dependent constant
e
s 00002/00003/00145
d D 4.6 85/05/05 20:32:49 mckusick 6 5
c read and write in 8192 size blocks
e
s 00002/00003/00146
d D 4.5 83/08/11 21:26:33 sam 5 4
c standardize sccs keyword lines
e
s 00005/00000/00144
d D 4.4 83/06/22 16:34:58 rrh 4 3
c if VMUNIX, define BIG to 1024, to get larger allocations
e
s 00023/00008/00121
d D 4.3 83/06/22 16:33:40 rrh 3 2
c incorporate tdef.h.big, which jacks up the sizes for VMUNIX
e
s 00003/00003/00126
d D 4.2 82/06/14 15:57:18 mckusick 2 1
c fix up include files for new file system
e
s 00129/00000/00000
d D 4.1 82/06/07 15:44:55 rrh 1 0
c date and time created 82/06/07 15:44:55 by rrh
e
u
U
t
T
I 1
D 5
/*
 *	%W% %G%
 */
E 5
I 5
/*	%M%	%I%	%E%	*/

E 5
D 2
#include <pagsiz.h>
#define	BUFSIZ	BSIZE
#undef BMASK
E 2
I 2
D 3
#include <sys/param.h>
#define	BUFSIZ	MAXBSIZE
E 3
E 2
D 7
#define MAXPTR 0x7fffffff	/* max value of any pointer variable */
E 7
I 7
D 8
#include <machine/machparam.h>
#include <machine/vmparam.h>
#define MAXPTR (USRSTACK-1)	/* max value of any pointer variable */
E 8
I 8
#include <sys/param.h>
#undef CMASK			/* XXX */
#undef BIG			/* XXX */
#define MAXPTR (-1)		/* max value of any pointer variable */
E 8
E 7
#ifdef NROFF	/*NROFF*/
#define EM t.Em
#define HOR t.Hor
#define VERT t.Vert
#define INCH 240	/*increments per inch*/
#define SPS INCH/10	/*space size*/
#define SS INCH/10	/* " */
#define TRAILER 0
#define UNPAD 0227
#define PO 0 /*page offset*/
#define ASCII 1
#define PTID 1
#define LG 0
#define DTAB 0	/*set at 8 Ems at init time*/
#define ICS 2*SPS
#define TEMP 256	/*65K*/
#endif
#ifndef NROFF	/*TROFF*/
#define INCH 432	/*troff resolution*/
#define SPS 20	/*space size at 10pt; 1/3 Em*/
#define SS 12	/*space size in 36ths of an em*/
#define TRAILER 6048	/*144*14*3 = 14 inches*/
#define UNPAD 027
#define PO 416 /*page offset 26/27ths inch*/
#define HOR 1
#define VERT 3
#define EM (6*(pts&077))
#define ASCII 0
#define PTID 0
#define LG 1
#define DTAB (INCH/2)
#define ICS 3*SPS
#define TEMP 512	/*128K*/
#endif

#include <signal.h>
#define NARSP 0177	/*narrow space*/
#define HNSP 0226	/*half narrow space*/
#define PS 10	/*default point size*/
#define FT 0	/*default font position*/
#define LL 65*INCH/10	/*line length; 39picas=6.5in*/
#define VS INCH/6	/*vert space; 12points*/
D 3
/* #define NN 132	/*number registers*/
#define NN 528
E 3
I 3
#ifdef VMUNIX
#define NN 528	/*number registers*/
#else
#define NN 132	/*number registers*/
#endif
/* #define NN 200	*/
E 3
D 9
#define NNAMES 14 /*predefined reg names*/
E 9
I 9
D 10
#define NNAMES 15 /*predefined reg names*/
E 10
I 10
#define NNAMES 16 /*predefined reg names*/
E 10
E 9
#define NIF 15	/*if-else nesting*/
#define NS 64	/*name buffer*/
#define NTM 256	/*tm buffer*/
#define NEV 3	/*environments*/
#define EVLSZ 10	/*size of ev stack*/
D 3
#define EVS 3*256	/*environment size in words*/
E 3
/* #define EVS 4*256	*/
I 3
#ifdef VMUNIX
#define NM 600
#define EVS 6*256	/*environment size in words*/
#else
E 3
#define NM 300	/*requests + macros*/
I 3
#define EVS 3*256	/*environment size in words*/
#endif
E 3
#define DELTA 512	/*delta core bytes*/
#define NHYP 10	/*max hyphens per word*/
#define NHEX 128	/*byte size of exception word list*/
#define NTAB 35	/*tab stops*/
#define NSO 5	/*"so" depth*/
I 3
#ifdef VMUNIX
#define WDSIZE 340	/*word buffer size*/
#define LNSIZE 960	/*line buffer size*/
#else
E 3
#define WDSIZE 170	/*word buffer size*/
#define LNSIZE 480	/*line buffer size*/
I 3
#endif
E 3
/* #define LNSIZE 680	*/
#define NDI 5	/*number of diversions*/
#define DBL 0100000	/*double size indicator*/
#define MOT 0100000	/*motion character indicator*/
#define MOTV 0160000	/*clear for motion part*/
#define VMOT 0040000	/*vert motion bit*/
#define NMOT 0020000	/* negative motion indicator*/
#define MMASK 0100000	/*macro mask indicator*/
I 2
D 3
#undef	CMASK
E 3
E 2
#define CMASK 0100377
#define ZBIT 0400	/*zero width char*/
#define BMASK 0377
#define BYTE 8
#define IMP 004	/*impossible char*/
#define FILLER 037
#define PRESC 026
#define HX 0376	/*High-order part of xlss*/
#define LX 0375	/*low-order part of xlss*/
#define CONT 025
#define COLON 013
#define XPAR 030
#define ESC 033
#define FLSS 031
#define RPT 014
#define JREG 0374
#define NTRAP 20	/*number of traps*/
#define NPN 20	/*numbers in "-o"*/
#define T_PAD 0101	/*cat padding*/
#define T_INIT 0100
#define T_IESC 16 /*initial offset*/
#define T_STOP 0111
#define NPP 10	/*pads per field*/
I 3
#ifdef VMUNIX
#define FBUFSZ 1024
#else
E 3
#define FBUFSZ 256	/*field buf size words*/
D 3
#define OBUFSZ BUFSIZ	/*bytes*/
#define IBUFSZ BUFSIZ	/*bytes*/
E 3
I 3
#endif
D 6
#define OBUFSZ 512	/*bytes*/
#define IBUFSZ 512	/*bytes*/
E 6
I 6
#define OBUFSZ 8192	/*bytes*/
#define IBUFSZ 8192	/*bytes*/
E 6
E 3
#define NC 256	/*cbuf size words*/
#define NOV 10	/*number of overstrike chars*/
D 8
#define ZONE 5	/*5hrs for EST*/
E 8
#define TDELIM 032
#define LEFT 035
#define RIGHT 036
#define LEADER 001
#define TAB 011
#define TMASK  037777
#define RTAB 0100000
#define CTAB 0040000
#define OHC 024

#define PAIR(A,B) (A|(B<<BYTE))

#define BLK  128	/*alloc block words*/
I 4

#ifdef VMUNIX
#define	BIG 1024
#endif VMUNIX

E 4
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
D 6

E 6
E 1
