h59953
s 00001/00003/00044
d D 4.3 83/08/11 20:30:40 sam 3 2
c standardize sccs keyword lines
e
s 00006/00000/00041
d D 4.2 82/11/06 14:32:00 rrh 2 1
c Bill Jolitz @ Berkeley received this version from Lorindia Cherry
c around September 1981, as the ``most recent version''.  Deltas 
c seem to be progressive, rather than regressive, although the BTL sid for
c deroff.c is retrograde; this is probably a case of parallel development
e
s 00041/00000/00000
d D 4.1 82/11/06 13:47:33 rrh 1 0
c Oldest available version at Berkeley
e
u
U
t
T
I 1
D 3
/*
 *	%W%	(Berkeley)	%E%
 */
E 3
I 3
/*	%M%	%I%	%E%	*/
E 3
extern int part;
extern int style;
I 2
extern int topic;
E 2
extern int pastyle;
extern int lstyle;
extern int rstyle;
extern int estyle;
I 2
extern int nstyle;
extern int Nstyle;
E 2
extern int rthresh;
extern int lthresh;
extern int pstyle;
extern int count;
extern int sleng[50];
extern int numsent;
extern long letnonf;
extern long numnonf;
extern long vowel;
extern long numwds;
extern long twds;
extern long numlet;
extern int maxsent;
extern int maxindex;
extern int minindex;
extern int qcount;
extern int icount;
extern int minsent;
extern int simple;
extern int compound;
extern int compdx;
extern int complex;
extern int nomin;
extern int tobe;
extern int noun, infin, pron, aux, adv;
extern int passive;
extern int beg[15];
extern int prepc;
extern int conjc;
extern int verbc;
extern int tverbc;
extern int adj;
I 2
#define MAXPAR 20
extern int leng[];
extern sentno;
E 2
E 1
