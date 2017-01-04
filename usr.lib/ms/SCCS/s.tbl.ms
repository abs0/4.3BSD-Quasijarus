h41414
s 00001/00000/00082
d D 1.3 90/06/02 17:47:40 karels 3 2
c reorg; insert keyworks
e
s 00001/00001/00081
d D 1.2 90/06/02 17:34:32 karels 2 1
c version distributed with 4.3BSD, dated Mar 11, 1985;
c fix in .B2 (box drawing)
e
s 00082/00000/00000
d D 1.1 90/06/02 17:25:58 karels 1 0
c ancillary file for tmac.s, extracted from there;
c version distributed with 4.2BSD, named "s.*", dated Jun 23, 1983
e
u
U
t
T
I 3
.\" %W% (Berkeley) %G%
E 3
I 1
.	\" TS - table start
.de TS
.br
.if !\\n(1T .RT
.ul 0
.ti \\n(.iu
.if t .sp .5
.if n .sp
.if \\$1H .TQ
.nr IX 1
..
.de TQ
.di TT
.nr IT 1
..
.	\" TH - end table header (begun with .TS H)
.de TH
.if \\n(.d>.5v .nr T. 0
.if \\n(.d>.5v .T# 0
.di
.nr TQ \\n(.i
.nr HT 1
.in 0
.mk #a
.mk #b
.mk #c
.mk #d
.mk #e
.mk #f
.TT
.in \\n(TQu
.mk #T
..
.	\" TE - table end
.de TE
.nr IX 0
.if \\n(IT>0 .if \\n(HT=0 \{\
.	di
.	nr UR \\n(.u
.	nf
.	TT
.	if \\n(UR>0 .fi
.\}
.nr IT 0
.nr HT 0
.sp \\n(DDu
.rm a+ b+ c+ d+ e+ f+ g+ h+ i+ j+ k+ l+ m+ n+
.rr a- b- c- d- e- f- g- h- i- j- k- l- m-
.rr a| b| c| d| e| f| g| h| i| j| k| l| m|
.rr 32 33 34 35 36 37 38 40 79 80 81 82
..
.	\" B1 - begin boxed text
.de B1
.br
.di BB
.nr BC 0
.if \\$1C .nr BC 1
.nr BE 1
..
.	\" B2 - end boxed text
.de B2
.br
.nr BI 1n
.if \\n(.$>0 .nr BI \\$1n
.di
.nr BE 0
.nr BW \\n(dl
.nr BH \\n(dn
.ne \\n(BHu+\\n(.Vu
.nr BQ \\n(.u
.nf
I 2
.nr BW +2*\\n(BI
E 2
.if \\n(BC>0 .in +(\\n(.lu-\\n(BWu)/2u
.in +\\n(BIu
.BB
.in -\\n(BIu
D 2
.nr BW +2*\\n(BI
E 2
.sp -1
\l'\\n(BWu\(ul'\L'-\\n(BHu'\l'|0\(ul'\h'|0'\L'\\n(BHu'
.if \\n(BC>0 .in -(\\n(.lu-\\n(BWu)/2u
.if \\n(BQ .fi
.br
..
E 1
