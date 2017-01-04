h56660
s 00001/00000/00058
d D 1.8 82/08/29 21:32:51 mckusick 8 7
c remove restriction on files in dynamic structures
e
s 00004/00000/00054
d D 1.7 82/02/08 20:41:25 mckusic 7 6
c add ATAN.c, COS.c, EXP.c, and SIN.c to allow for runtime checking
e
s 00001/00000/00053
d D 1.6 82/02/02 23:15:23 mckusic 6 5
c add EXCEPT()
e
s 00001/00001/00052
d D 1.5 81/06/17 00:02:58 mckusic 5 4
c change return value of TELL
e
s 00000/00002/00053
d D 1.4 81/04/01 22:01:53 mckusic 4 3
c FCALL and FRTN no longer return values
e
s 00004/00004/00051
d D 1.3 81/03/19 01:18:50 mckusic 3 2
c change RELG to RELT
e
s 00048/00004/00007
d D 1.2 81/03/07 16:06:56 mckusic 2 1
c merge in onyx changes
e
s 00011/00000/00000
d D 1.1 81/01/06 18:21:52 mckusick 1 0
c date and time created 81/01/06 18:21:52 by mckusick
e
u
U
t
T
I 1
/* Copyright (c) 1979 Regents of the University of California */

D 2
/* static 	char sccsid[] = "%Z%%M% %I% %G%"; */
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 2

I 2
extern FILE *ACTFILE();
extern long *ADDT();
I 7
extern double ATAN();
E 7
extern long CARD();
extern char CHR();
extern long CLCK();
I 7
extern double COS();
E 7
extern long *CTTOT();
extern long ERROR();
I 6
extern int EXCEPT();
I 7
extern double EXP();
E 7
E 6
extern long EXPO();
extern char *FNIL();
D 4
extern long FCALL();
E 4
extern struct formalrtn *FSAV();
D 4
extern long FRET();
E 4
extern struct iorec *GETNAME();
extern bool IN();
extern bool INCT();
E 2
extern double LN();
D 2
extern double SQRT();
E 2
I 2
extern long MAX();
extern long *MULT();
extern char *NAM();
extern char *NIL();
extern long PRED();
I 8
extern struct iorec *PFCLOSE();
E 8
E 2
extern double RANDOM();
I 2
extern char READC();
extern long READ4();
extern long READE();
E 2
extern double READ8();
D 2
extern char *FNIL();
E 2
I 2
extern bool RELNE();
extern bool RELEQ();
extern bool RELSLT();
extern bool RELSLE();
extern bool RELSGT();
extern bool RELSGE();
D 3
extern bool RELGLT();
extern bool RELGLE();
extern bool RELGGT();
extern bool RELGGE();
E 3
I 3
extern bool RELTLT();
extern bool RELTLE();
extern bool RELTGT();
extern bool RELTGE();
E 3
extern long ROUND();
extern long RANG4();
extern long RSNG4();
extern long SCLCK();
extern long SEED();
I 7
extern double SIN();
E 7
extern double SQRT();
extern long SUBSC();
extern long SUBSCZ();
extern long *SUBT();
extern long SUCC();
D 5
extern long TELL();
E 5
I 5
extern struct seekptr TELL();
E 5
extern bool TEOF();
extern bool TEOLN();
extern long TRUNC();
E 2
extern struct iorec *UNIT();
D 2
extern struct formalrtn *FSAV();
E 2
E 1
