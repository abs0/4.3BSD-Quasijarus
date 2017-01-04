'''	9144 Memorandum Macros - 11.5 of 8/5/77
'''	TROFF Version
.nr:a 0 1
.nr:b 0
.nr:c 0
.nr:d 0
.nr:e 0
.nr:f 0
.nr:g 0 1
.nr:h 1
.nr:u 0
.ds}2 Bell Laboratories
.ds- \-
.dsBU \s-2\(bu\s0
.dsF \v'-.4m'\s-3\\n+(:p\s0\v'.4m'
.dsHF 3 3 2 2 2 2 2
.dsRE ~|^`11.5
.dsRE 11.5
.nrAu 1
.nrCl 2
.nrDs 1v
.nrEc 0 1
.nrFg 0 1
.nrFs 1
.nrH1 0 1
.nrH2 0 1
.nrH3 0 1
.nrH4 0 1
.nrH5 0 1
.nrH6 0 1
.nrH7 0 1
.nrHb 2
.nrHi 1
.nrHs 2
.nrHu 2
.nrHy 1
.if!\nL .nrL 11i
.pl\nLu
.nrLi 4
.if!\nO .nrO .5i
.po\nOu
.if\nP .nrP -1
.nrP \nP 1
.nrPi 3
.nrPt 2
.if!\nS .nrS 10
.nrSi 3
.nrTb 0 1
.if!\nW .nrW 6.5i
.deB
.nr;F \\n(.f
.ft3
.if\\n(.$ .if!\\n(.$-1 \&\\$1
.if\\n(.$-1 \&\\$1\&\c
.if\\n(.$ .ft\\n(;F
.if\\n(.$-1 \&\\$2
..
.deEC
.)F Equation 2 \\n+(Ec "\\$1" "\\$2" 0\\$3
..
.deFG
.)F Figure 0 \\n+(Fg "\\$1" "\\$2" 0\\$3
..
.deHC
.ev0
.hc\\$1
.ev
.ev1
.hc\\$1
.ev
.ev2
.hc\\$1
.ev
..
.deH
.if\\n(:F .)D "H:missing FE"
.if\\n(:y .)D "H:missing DE"
.if!\\n(.$ .)D "H:missing arg"
.nr;0 0
.if\\$1-7 .nr;0 1
.if\w\\$1-\w'0'u .nr;0 1
.if\\n(;0 .)D "H:bad arg:\\$1"
.LC 0
.)R
.br
.nr;1 0\\$1
.if!0\\$1 .nr;1 \\n(Hu 
.if!\\n(;1 .)D "H:bad arg:\\$1"
.if2-\\n(;1 .nrH2 0 1
.if3-\\n(;1 .nrH3 0 1
.if4-\\n(;1 .nrH4 0 1
.if5-\\n(;1 .nrH5 0 1
.if6-\\n(;1 .nrH6 0 1
.if7-\\n(;1 .nrH7 0 1
.if2-\\n(;1 .if\\n(:S .)w
.if2-\\n(;1 .if\\n(:C .nr:p 0 1
.SP .5
.nr:u 0
.if\\n(;1-1 .nrH\\n(;1 +1 
.if!\\n(;1-1 .nr:u 1 
.if!\\n(;1-1 .SP 1
.if\\n(;1-1 .if\\n(Ej+1-\\n(;1 .bp
.if!\\n(;1-1 .if\\n(Ej+\\n(:S .bp
.if!\\n(;1-1 .if!\\n(:u-1 .nrH1 +1
.nr:u 0
.ds}0 \\n(H1.
.if0\\$1-1 .as}0 \\n(H2
.if0\\$1-2 .as}0 .\\n(H3
.if0\\$1-3 .as}0 .\\n(H4
.if0\\$1-4 .as}0 .\\n(H5
.if0\\$1-5 .as}0 .\\n(H6
.if0\\$1-6 .as}0 .\\n(H7
.if\\n(Ht .)I \\n(;1 \\n(H1 \\n(H2 \\n(H3 \\n(H4 \\n(H5 \\n(H6 \\n(H7
.if\\n(Ht .ds}0 \\*(}3.
.as}0 \ \ 
.if!0\\$1 .ds}0 
.nr;0 0
.if!\\n(;1-\\n(Hb .nr;0 1
.if!\\n(;1-\\n(Hs .nr;0 2
.ds}2
.if!\\n(;0 .if\w\\$2 .ds}2 \ \ 
.nr;3 2v
.HX \\n(;1 0\\$1 "\\$2\\$3"
.di>A
\&\\*(}0\\$2\\$3\\*(}2
.br
.di
.rm>A
.if\\n(;0-1 .nr;3 +.5v
.ne\\n(;3u+\\n(dnu+.5p-1v
.na
.)I \\n(;1 \\*(HF
.nr;3 1
.nr;3 \\*(}3
.ft\\n(;3
.nr:I \\n(.s
.if\\n(;3-2 .if\\n(;0 .ps-1
.nr;2 \w\\*(}0
.if\\n(;0 .in+\\n(;2u
.if\\n(;0 .ti-\\n(;2u
.nr;2 \\n(.i
.if!\\n(;1-\\n(Hc .if\\n(;0 .ce
\\*(}0\&\c
.if\\n(;0 \&\\$2\\$3
.if!\\n(;0 \&\\$2\\$3\\*(}2\&\c
.ft
.ps\\n(:Ip
.if\\n(;0 'in
.if!\\n(;1-\\n(Cl .if\w\\$2 .)E \\$1 "\\$2"
.SA
.if\\n(;0 .br
.if\\n(;0-1 .SP .5
.if\\n(;0*\\n(Hi*\\n(Pt .if!\\n(Hi-1+\\n(Pt-1 .ti+\\n(Pin
.if0\\$1*\\n(;0 .if\\n(Hi-1 .ti\\n(;2u
.nr:I 1
.HZ \\n(;1 0\\$1 "\\$2\\$3"
..
.deHM
.afH1 \\$1 1
.afH2 \\$2 1
.afH3 \\$3 1
.afH4 \\$4 1
.afH5 \\$5 1
.afH6 \\$6 1
.afH7 \\$7 1
..
.deHU
.if!\\n(.$ .)D "HU:missing arg"
.H 0 "\\$1" "\\$2"
..
.deI
.nr;F \\n(.f
.ft2
.if\\n(.$ .if!\\n(.$-1 \&\\$1
.if\\n(.$-1 \&\\$1\&\c
.if\\n(.$ .ft\\n(;F
.if\\n(.$-1 \&\\$2
..
.deLB
.if4-\\n(.$ .)D "LB:missing arg(s)"
.)L 0\\$1n 0\\$2n 0\\$3n "\\$4" "\\$5" "\\$6" "\\$7"
..
.de)L
.if\\n(:g-5 .)D "LB:too many nested lists"
.if\\n(:g .)A 
.if!\\n+(:g-1 .ds]b \\n(.i
.nr:b \\n(.iu+0\\$1u 
.nr:c \\n(.iu+0\\$2u 
.nr:d 0\\$3 
.nr:e 0\\$4 
.nr:f 0\\$6 
.if!\w\\$6 .nr:f 1
.ds]g \\$5
.if!\w\\$5 .ds]g \&
.if!\w\\$5 .if\\n(:e .ds]g 1
.nr:a 0 1
.if0\\$4 .af:a \\$5 1
.if0\\$7 .SP .5
.fi
.in\\n(:bu
.ti\\n(:bu
..
.deLC
.if\\n(:g-0\\$1 .)B
.if\\n(:g-0\\$1 .LC 0\\$1
..
.deLE
.if\\n(:I-1 .if\\n(nl-\\n(:J .nr:I 0
.if!\\n(:I-1 .nr:I 0
.if!\\n(:g .)D "LE:mismatched"
.if\\n(:g .)B
.if\\n(.$ .SP .5
.nr:J \\n(nl
..
.deLI 
.if!\\n(:g .)D "LI:no lists active" 
.if\\n(:f .SP .5
.in\\n(:bu
.if\\n(:f .if!\\n(:D .ne1v+.5p
.ds}0 \\*(]g
.if\\n(:e .ds}0 \\n+(:a.
.if\\n(:e-1 .ds}0 \\n(:a)
.if\\n(:e-2 .ds}0 (\\n(:a)
.if\\n(:e-3 .ds}0 [\\n(:a]
.if\\n(:e-4 .ds}0 <\\n(:a>
.if\\n(:e-5 .ds}0 {\\n(:a}
.if\\n(.$-1 .ds}0 \\$1\ \\*(}0
.if\\n(.$ .if!\\n(.$-1 .ds}0 \\$1
.nr;0 \w\\*(}0
.nr;1 \\n(:c
.if\\n(:d .nr;1 \\n(:bu-\\n(:du-\\n(;0u
.if!\\n(;1 .nr;1 0
.nr;0 \\n(:bu-\\n(;1u-\\n(;0u
.ti\\n(;1u
.if!\\n(;0 .nr;0 \w u
.if\w\\*(}0 \&\\*(}0\h\\n(;0u\&\c
..
.deAL
.if!\\n(.$-1 .)L \\n(Lin 0 \\n(Lin-\w'\0\0.'u 1 "\\$1"
.if\\n(.$-1 .if!\\n(.$-2 .LB 0\\$2 0 2 1 "\\$1"
.if\\n(.$-2 .if!\w\\$2 .)L \\n(Lin 0 \\n(Lin-\w'\0\0.'u 1 "\\$1" 0 1
.if\\n(.$-2 .if\w\\$2 .LB 0\\$2 0 2 1 "\\$1" 0 1
..
.deBL
.if!\\n(.$ .)L \\n(Pin 0 \\n(Pin-\w'\\*(BU'u 0 \\*(BU
.if\\n(.$ .if!\\n(.$-1 .LB 0\\$1 0 1 0 \\*(BU
.if\\n(.$-1 .if!\w\\$1 .)L \\n(Pin 0 \\n(Pin-\w'\\*(BU'u 0 \\*(BU 0 1
.if\\n(.$-1 .if\w\\$1 .LB 0\\$1 0 1 0 \\*(BU 0 1
..
.deDL
.if!\\n(.$ .)L \\n(Pin 0 \\n(Pin-\w'\\*(BU'u 0 \(em
.if\\n(.$ .if!\\n(.$-1 .LB 0\\$1 0 1 0 \(em
.if\\n(.$-1 .if!\w\\$1 .)L \\n(Pin 0 \\n(Pin-\w'\\*(BU'u 0 \(em 0 1
.if\\n(.$-1 .if\w\\$1 .LB 0\\$1 0 1 0 \(em 0 1
..
.deML
.if!\\n(.$ .)D "ML:missing arg"
.nr;0 \w\\$1u/3u/\\n(.su+1u
.if!\\n(.$-1 .LB \\n(;0 0 1 0 "\\$1"
.if\\n(.$-1 .if!\\n(.$-2 .LB 0\\$2 0 1 0 "\\$1"
.if\\n(.$-2 .if!\w\\$2 .LB \\n(;0 0 1 0 "\\$1" 0 1
.if\\n(.$-2 .if\w\\$2 .LB 0\\$2 0 1 0 "\\$1" 0 1
..
.deRL
.if!\\n(.$ .LB 6 0 2 4
.if\\n(.$ .if!\\n(.$-1 .LB 0\\$1 0 2 4
.if\\n(.$-1 .if!\w\\$1 .LB 6 0 2 4 1 0 1
.if\\n(.$-1 .if\w\\$1 .LB 0\\$1 0 2 4 1 0 1
..
.deVL
.if!\\n(.$ .)D "VL:missing arg"
.if!\\n(.$-2 .LB 0\\$1 0\\$2 0 0
.if\\n(.$-2 .LB 0\\$1 0\\$2 0 0 \& 0 1
..
.deP
.br
.nr;1 \\n(:J
.nr;2 \\n(nl
.SP .5
.if!\\n(:D .ne1v+.5p
.if!\\n(;1-\\n(:J .nr;2 \\n(;2-\\n(:J
.if\\n(;1-\\n(:J .nr;2 \\n(nl-\\n(:J
.nr:J \\n(;2
.if\\n(.$ .if0\\$1 .ti+\\n(Pin
.if!\\n(.$ .if\\n(Pt .if!\\n(Pt-1 .ti+\\n(Pin
.if!\\n(.$ .if\\n(Pt-1*\\n(:I .ti+\\n(Pin
.if!\\n(.$ .if\\n(Pt-1 .if!\\n(:I .if\\n(:J .ti+\\n(Pin
.nr:I 1
..
.deR
.ft1
..
.deS
.if!\\n(.$ .nr;0 \\n(:Q
.if\\n(.$ .if!\w\\$1 .nr;0 \\n(:Q
.if\w\\$1 .nr;0 \\n(:P
.if\w\\$1 .nr;0 \\$1
.if0\\$1-99 .nr;0 \\nS
.if!\\n(;0 .)D "S:bad arg \\$1"
.nr:Q \\n(:P
.nr:P \\n(;0
.ps\\n(:Pp
.vs\\n(.sp+2p
..
.depn
.rm]N
.if\\n(.$=1 .ds]N \\$1
..
.deSA
.if\\n(.$ .if\\$1-1 .)D "SA:bad arg:\\$1"
.if\\n(.$ .nr:h 0\\$1
'na
.if\\n(:h 'ad
..
.deSK
.br
.bp
.nr;0 0\\$1-1
.if\\n(;0+1 .rs
.if\\n(;0+1 .SK \\n(;0
..
.deSP
.br
.nr;4 1v
.if\\n(.$ .nr;4 \\$1v
.if\\n(nl-\\n(:N .nr:A 0
.if\\n(:N-\\n(nl .nr:A 0
.nr;4 -\\n(:Au
.if!\\n(:D .if\\n(;4 .sp\\n(;4u
.if!\\n(:D .if\\n(;4 .nr:A +\\n(;4u
.nr:N \\n(nl
.if\\n(:D .if\\n(.$ .sp\\$1v
.if\\n(:D .if!\\n(.$ .sp1v
..
.deTB
.)F TABLE 1 \\n+(Tb "\\$1" "\\$2" 0\\$3
..
.de)A
.af:a 1
.ds]a \\n(:a \\*(]a
.ds]b \\n(:b \\*(]b
.ds]c \\n(:c \\*(]c
.ds]d \\n(:d \\*(]d
.ds]e \\n(:e \\*(]e
.ds]f \\n(:f \\*(]f
.ds]h \\*(]g \\*(]h
..
.de)B
.br
.nr:g -1
.)C nr :a ]a \\*(]a
.)C nr :b ]b \\*(]b
'in\\n(:bu
'ti\\n(:bu
.)C nr :c ]c \\*(]c
.)C nr :d ]d \\*(]d
.)C nr :e ]e \\*(]e
.)C nr :f ]f \\*(]f
.)C ds ]g ]h \\*(]h
.af:a 1
.if\\n(:e .af:a \\*(]g
..
.de)C
.\\$1 \\$2 \\$4
.ds\\$3 \\$5 \\$6 \\$7 \\$8 \\$9
..
.de)D
.fl
.tmERROR:input line \\n(.c:\\$1
.if!\\nD .ex
..
.de)F
.nr;0 \w\\$5
.nr;1 0
.nr;1 0\\$6
.ds}0 \\$3
.if\\n(;0 .ds}0 \\$5\\$3
.if\\n(;1*\\n(;0 .ds}0 \\$3\\$5
.if\\n(;1-1*\\n(;0 .ds}0 \\$5
.ds}0 \\$1\ \\*(}0
.if\w\\$4 .as}0 .\ \ 
.nr;0 \w\\*(}0
.nr;1 \\n(.lu-\\n(;0u-\w\\$4u+1u
.if\\n(:B=0 .if\\n(;1 .ce
.if!\\n(;1 .fi
.if!\\n(;1 .in+\\n(;0u
.if!\\n(;1 .ti-\\n(;0u
\f3\\*(}0\fP\\$4
.if!\\n(;1 .in
..
.de)I
.nr;3 0\\$1+1
.ds}3 \\$\\n(;3
..
.deTL
.nr:D 2 
.nr;z 0 
.nr:V 0 
.nr:1 \\n(.i 
.ds>1 \\$1
.ds>2 \\$2
'nr;y 1
'de>T AU
..
.deAU
.nr:D 1 
.if!\\n(;y 'nf
.if\\n(;y .>9 
.rmTL
.ll\\nWu
.da>z
'ft3
.if\\n(;z .sp
\\$1
.if\\n(Au>0 \{.if\w\\$3 \\$3\ \&\c
.if\w\\$4 \\$4
.if\w\\$3 .if!\w\\$4 \&
.if\w\\$6 \\$6\ \&\c
.if\w\\$5 x\\$5
.if\w\\$6 .if!\w\\$5 \&\}
.if\\n(.$-6 \\$7
.if\\n(.$-7 \\$8
.if\\n(.$-8 \\$9
.br
'ft1
.di
.nr;z +\\n(dn
.nrdn 0
.am>A
\f3\\$1\\\\t\\$3\ \\$6\\\\t\\$5\fP
\\..
'in\\n(:1u
.if!\\n(:V .ds}v \\$3-\\$4-\\$2
.if\\n(:V .as}v /\\$2
.da>v
'ft3
.sp3
\\$1
.br
'ft1
.di
.nr:V +\\n(dnu
.nrdn 0
.am>4
.S +1
.ft2
\\$1
.br
.S \\nS
.ft1
.if\\\\n(:2 .sp.5v
.if\\\\n(:2 \\*(}2
.if\\\\n(:2 \\\\*(\\$3
.if\\\\n(:2 .sp.5v
.ds}z \\\\*(\\$3
\\..
..
.de>9
.di}z
'll\\nWu-34n
'nh
'na
'fi
'ft3
.>T
.ft1
.br
.if\w\\*(>1 \s8Case:\s0\h'|\w'\s8Case:\s0\ 'u'\f3\\*(>1\fP
.br
.if\w\\*(>2 \s8File:\s0\h'|\w'\s8Case:\s0\ 'u'\f3\\*(>2\fP
.br
.ll\\nWu
.di
.nr:9 \\n(dn 
.nrdn 0
.nr;y 0
'nf
.rm>9
..
.deOK
.nr:D 1 
.de>7
.ps-1
.if\\n(.$-0 \\$1
.if\\n(.$-1 \\$2
.if\\n(.$-2 \\$3
.if\\n(.$-3 \\$4
.if\\n(.$-4 \\$5
.if\\n(.$-5 \\$6
.if\\n(.$-6 \\$7
.if\\n(.$-7 \\$8
.if\\n(.$-8 \\$9
.ps
\\..
.rmOK
..
.deTM
.nr:D 1 
.de>8
.ft3
.if\\n(.$-0 \\$1
.if\\n(.$-1 \\$2
.if\\n(.$-2 \\$3
.if\\n(.$-3 \\$4
.if\\n(.$-4 \\$5
.if\\n(.$-5 \\$6
.if\\n(.$-6 \\$7
.if\\n(.$-7 \\$8
.if\\n(.$-8 \\$9
.ft1
\\..
.nr;x \\n(.$+1 
.rmTM
..
.deAS
.nr:D 2 
.rmTL
.nr:t 0\\$1 
.nr:3 5n
.if\\n(.$-1 .nr:3 0\\$2n 
'in\\n(:1u
'fi
.SA
'nh
'if\\n(Hy 'hy14
.di>3
.ll0u-2u*\\n(:3u+\\nWu
.ce
.ul
ABSTRACT
.SP 1.5
.ns
.nr:I 1
.rmAS
..
.deAE
.br
.di
'nf
'nh
.nr;3 \\n(dn
.ll\\nWu
'in\\n(:1u
.rmAE
..
.deMT
.nr:D 0 
.if!\\n(;y 'nf
.rmTL
.rmTM
.rmOK
.rmAS
.rmAE
.rmAF
.rmAU
.rmTL
.ll\\nWu
.rnTP >Y 
.in\\n(:1u
.rn>Y TP
.rn)K >Y
.if!\\n(.$ .>6
.if\\n(.$ .if\w\\$1u-\w'0'u .>6 "\\$1"
.if\\n(.$ .nr;y 0\\$1
.if\\n(.$ .if!\\n(;y .>6 ""
.if\\n(.$ .if\\n(;y-4 .>x 
.if\\n(.$ .if\\n(;y-3 .>5 "\\$2"
.if\\n(.$ .if\\n(;y-2 .>6 "ENGINEER'S NOTES"
.if\\n(.$ .if\\n(;y-1 .>6 "PROGRAMMER'S NOTES"
.if\\n(.$ .if\\n(;y .>6 "MEMORANDUM FOR FILE"
.)R
.S \\nS
.ft1
.ft1
.ta.5i 1i 1.5i 2i 2.5i 3i 3.5i 4i 4.5i 5i 5.5i 6i
.ns
.>Y
.rm>Y
.rmMT
..
.de>x
.rm>6
.rm>5
.rm)Y
.rm)X
.br
.rs
.sp12v
.in\\nWu-1.4i
.ti+6
\\*(DT
.sp2v
.rm>x
..
.de>6 
.rm>5
.rm>x
.rm)Y
.ta\\nWu-1.75i 
.br
.rs
.sp|1.1i-1v
\t\s36\(bs\s0
.vs.3i
.if\w\\*(}2 \t\s16\f3\\*(}2\fP\s0
.vs12p
.sp|1.9i
.mk:2
\s8subject:\s0
.rt-1
.in\w'\s8subject:\s0'u+1n
.}z
.br
.rt\\n(:2u
.in\\nWu-1.4i
.ps8
.ti-6n
date:
.ps
.rt-1
\f3\\*(DT\fP
.sp
.ps8
.ti-6n
from:
.ps
.rt-1
.ft3
.>z
.ft
.in\\n(:1u
.if\\n(;x .sp
.if\\n(;x .in\\nWu-1.4i
.if\\n(;x .ps8
.if\\n(;x .ti-6n
.if\\n(;x TM:
.if\\n(;x .ps
.if\\n(;x .rt-1
.if\\n(;x .>8
.if\\n(;x .in\\n(:1u
.br
.if\\n(:9u-\\n(;zu-2v-\\n(;xv .sp\\n(:9u-\\n(;zu-2v-\\n(;xv
.sp3
.if\\n(;3 .if!\\n(:t .in+\\n(:3u
.if\\n(;3 .if!\\n(:t .>3
.if\\n(;3 .if!\\n(:t .in-\\n(:3u
.if\\n(;3 .if!\\n(:t .sp3
.ns
.ne10
.ce
.ul
.if!\\n(.$ MEMORANDUM FOR FILE
.if\\n(.$ .if\w\\$1 \\$1
.SP 3 
.ce0
.ul0
.)X
.rm)X
.rm>6
..
.de>5
.rm>6
.rm>x
.rm)X
.br
.rs
.sp5
.in0
.dsPY "Piscataway, New Jersey 08854
.dsMH "Murray Hill, New Jersey 07974
.dsWH "Whippany, New Jersey 07981
.dsHO "Holmdel, New Jersey 07733
.dsRR "Piscataway, New Jersey 08854
'
.dsAK Norcross, GA 30071
.dsCP Piscataway, NJ 08854
.dsCH Chester, NJ 07930
.dsCB Columbus, OH 43213
.dsDR Denver, CO 80234
.dsIN Indianapolis, IN 46206
.dsIH Naperville, IL 60540
.dsMV North Andover, MA 01845
.dsRD Reading, PA 19604
.dsWV Warren, NJ 07060
.ll\\nWu
.fi
.na
.nh
.di>6
.ps+2
.vs\\n(.sp+4p
.ft3
.>T
.ps
.vs\\n(.sp+2p
.ft1
.br
.di
.nf
.ce1000
.>6
.nr:2 0
.if\w\\$1 .nr:2 1
.ul0
.sp.5v
.>4
.br
.if!\\n(:2 .sp.5v
.if!\\n(:2 \\*(}2
.if!\\n(:2 \\*(}z
.ce0
.sp
.if\\n(;3 .if!\\n(:t .in+\\n(:3u
.if\\n(;3 .if!\\n(:t .>3
.if\\n(;3 .if!\\n(:t .in-\\n(:3u
.if\\n(;3 .if!\\n(:t .sp
.ns
.br
.)Y
.rm)Y
.rm>6
.rmPY
.rmMH
.rmWH
.rmHO
.rmRR
'
.rmAK
.rmCP
.rmCH
.rmCB
.rmDR
.rmIN
.rmIH
.rmMV
.rmRD
.rmWV
.rmSG 
.rm)N
.rm)M
.deNS
.br
.di
.di>Y
\\..
.deNE
.br
.di
\\..
.rm>5
..
.de)K
.if\\n(:D .)D "check TL, AU, AS, AE, MT sequence"
.rm)X
.rm)Y
.rm>T
.rm>x
.rm>z
.rm>1
.rm>2
.rm>3
.rm>4
.rm>5
.rm>6
.rm>7
.rm>8
.rm>9
.rm}2
.rm}z
.rr;x 
.rr;y 
.rr;z 
.rr:D 
.rr:1 
.rr:2 
.rr:3 
.rr:9 
.rr;0
.rr;1 
.rr;2 
.rr;3 
.rmTL
.rmAU
.rmTM
.rmAF
.rmAS
.rmAE
.rmOK
.rm)K
..
.deSG
.if!\\n(:V .)D "SG:no authors"
.if\\n(:F .)D "SG:missing FE"
.if\\n(:y .)D "SG:missing DE"
.LC 0 
.)R 
.in0
.nf
.ls1
.in\\n(.lu-1.3i 
.ne\\n(:Vu+1v+.5p
.rs
.mk
.>v
.in
.if\w\\$1 .as}v -\\$1
.if\\n(.$-1 .rt
.if\\n(.$-1 .sp3
.if\\n(.$ .if!\\n(.$-1 .rt-1
.if\\n(.$ \\*(}v
.rm>v
.fi
..
.deNS
.if\\n(;n .)N 
.)R 
.nf
.ds}2 "Copy to
.nr;0 0\\$1
.if\w\\$1u-\w'\0\0'u .nr;0 10
.if\\n(;0 .ds}2 "Copy (with att.) to
.if\\n(;0-1 .ds}2 "Copy (without att.) to
.if\\n(;0-2 .ds}2 "Att.
.if\\n(;0-3 .ds}2 "Atts.
.if\\n(;0-4 .ds}2 "Enc.
.if\\n(;0-5 .ds}2 "Encs.
.if\\n(;0-6 .ds}2 "U.S.C.
.if\\n(;0-7 .ds}2 "Letter to
.if\\n(;0-8 .ds}2 "Memorandum to
.if\\n(;0-9 .ds}2 "Copy (\\$1) to
.ne3v+.5p
.sp.5v
\\*(}2 
.nr;0 \\n(.tu-3v 
.if!\\n(;0 See next page 
.if!\\n(;0 .bp
.if!\\n(;0 \\*(}2
.nr;n 1 
.di>Y
..
.de)N
.br
.di
.nr;n 0
.nr;0 \\n(dn-\\n(.t 
.if!\\n(;0 .>Y 
.if\\n(;0 .)M 
.rm>Y
..
.de)M
.de>Z  
Continued next page 
.sp1 
\\*(}2\ \*-\ cont'd
\\..
.nr;t \\n(nlu+\\n(.tu-1v
.wh\\n(;tu >Z
.>Y
.wh\\n(;tu
.rm>Z
..
.deNE
.if\\n(;n .)N
.)R 
..
.deND
.if!\\n(.$ .)D "ND:missing arg"
.dsDT "\\$1
..
.deAF
.ds}2 "\\$1
..
.de)h
'ev2
.)k
.)R
.if\\n(:S=0 .if\w\\*(]N>0 .nrP \\*(]N
.if\\n(:S=0 .if\w\\*(]N=0 .nrP +1
.if\\n(:S=0 .nr% \\nP
.rm]N
.if\\n(:S=1 .nrP +1
.if\\n(:u*\\n(:S .nrP 1 
.if\\n(:u .nrH1 +1 
.if\\n(:u .nr:u 2
'sp
.TP
.)R
'ev
.nr:I 2
.nr:J \\n(nl
'ns
'if\\n(:q .)l 
'nr:q 0
'if\\n(:z .)y 
.PX 
.mk;m
.nr:J \\n(nl
..
.de)f
.nr:N 0
'nrdn 0
'nr;y \\n(.pu-\\n(nlu-\\n(:mu
'if\\n(:s 'if\\n(;y .)o
'if\\n(:s 'if!\\n(;y .)m
'ch)f -\\n(:mu 
'nr:s 0
'nr:o \\n(:mu
'nr:O \\n(:mu
.if!\\n(;C 'bp
.if\\n(;C .nr;y \\n(;C 
.if\\n(;C .if\\n(;y-1 .)2 
.if\\n(;C .if!\\n(;y-1 .)1 
..
.dePH
.ds}t "\\$1
..
.deEH
.ds}e "\\$1
..
.deOH
.ds}o "\\$1
..
.dePF
.ds}b "\\$1
..
.deEF
.ds}f "\\$1
..
.deOF
.ds}p "\\$1
..
.deTP
.)K
'sp
.if!\\nP-1 .if\\nN 'sp
.if!\\nP-1 .if\\n(:S .tl\\*(}t
.if!\\nP-1 .if!\\nN .tl\\*(}t
.if\\nP-1 .tl\\*(}t
'ife 'tl\\*(}e
'ifo 'tl\\*(}o
'sp
..
.de)b
'ev2
.)R
.ife .tl\\*(}f
.ifo .tl\\*(}p
.if!\\nP-1 .if\\nN-1 .if!\\nN-2  .sp
.if!\\nP-1 .if\\nN .if!\\nN-1 .tl\\*(}t
.if!\\nP-1 .if\\nN-2 .tl\\*(}b
.if!\\nP-1 .if!\\nN .tl\\*(}b
.if\\nP-1 .tl\\*(}b
.if\\nC .tl\\*(]C
.)R
'ev
..
.de)2
.po\\nOu 
.nr;C 1 
'bp
..
.de)1
.rt\\n(;mu
.po+\\n(;ou 
.nr;C 2 
.nr:I 2
.nr:J \\n(nl
'ns
'if\\n(:q .)l 
'nr:q 0
'if\\n(:z .)y 
.nr:J \\n(nl
..
.de2C 
.br
.)R
.nr;C 1
.if!\\n(.$ .nr;l \\n(.lu*8u/17u 
.if!\\n(.$ .nr;o \\n(.lu*9u/17u 
.if\\n(.$ .nr;l \\$1u*1.3n
.if\\n(.$ .nr;o \\nWu-\\n(;lu
.ev1
.ll\\n(;lu
.lt\\n(;lu
.ev
.ll\\n(;lu
.lt\\n(;lu
.nr:L \\nW
.nrW \\n(.lu
.SP
.ns
.mk;m
..
.deFS
'nr:s +1 
'di
.if\\n(:D-1 .)D "FS:illegal inside TL or AS"
.if\\n(:F .)D "FS:missing FE"
.if\\n(:F .FE
.if\\n(:y .)D "FS:missing DE"
.if\\n(:y .DE
.nr:F 1
'ev1
'da>y
.nr:D 1
.)R
'nh
'if\\n(:i 'hy14
'ad
'if\\n(:j 'na
'ps-2
'vs\\n(.sp+2p
'if\\n(:s-1 'sp\\n(Fsu*3p
'if\\n(.$ 'ds}y \\$1\ 
'if!\\n(.$ 'ds}y \\*(]y.\ 
'if\\n(:k \\*(}y\&\c
'if!\\n(:k 'nr;z \w\0\0.\ 
'if!\\n(:k 'nr;y \w\\*(}y
'if!\\n(:k 'in+\\n(;zu
'if!\\n(:k 'if!\\n(:l 'ti-\\n(;zu
'if!\\n(:k 'if!\\n(:l 'if!\\n(;y-\\n(;z \\*(}y\h\\n(;zu-\\n(;yu\&\c
'if!\\n(:k 'if!\\n(:l 'if\\n(;y-\\n(;z \\*(}y\&\c
'if!\\n(:k 'if\\n(:l 'if\\n(;z-\\n(;y 'ti-\\n(;yu
'if!\\n(:k 'if\\n(:l 'if!\\n(;z-\\n(;y 'ti-\\n(;zu
'if!\\n(:k 'if\\n(:l \\*(}y\&\c
..
.deFE
.if!\\n(:F .)D "FE:no FS"
.br
'di
.nr:D 0
.)R
'ev
.nr:F 0
'if!\\n(:s-1 'nrdn +1v
'nr:o +\\n(dnu
'nr:O +\\n(dnu
.nrdn 0
'if!\\n(.pu-\\n(nlu-.5p-\\n(:ou 'nr:o \\n(.pu-\\n(nlu-.5p
'if!\\n(:ou-\\n(:mu 'nr:o \\n(:mu
'ch)f -\\n(:ou 
..
.de)o
'ev1
.)R
'ps-2
'vs\\n(.sp+2p
'nf
.ti0
.if!\n(.A .if!\\n(:n \l'60p'
.if\n(.A .if!\\n(:n __________
.if!\n(.A .if\\n(:n \l\\n(.lu
.if\n(.A .if\\n(:n _____________________________
'nr:n 0
.br
'ns
.>y
.br
'di
'rm>y
'nr:q \\n(dnu
'nrdn 0
'nr:s 0 
.)R
'ps
'vs\\n(.sp+2p
'ev
..
.de)n
'di>x
..
.de)m
'ev1
.)R
'ps-2
'vs\\n(.sp+2p
.nf
'di>w
.>y
.br
'di
'rm>y
'nr:q \\n(dn
'nrdn 0
'nr:s 0
'nr:n 1
.)R
'ps
'vs\\n(.sp+2p
'ev
..
.de)l
'nr:s 1
.nr:n 1
'di
'ev1
'da>y
.)R
'ps-2
'vs\\n(.sp+2p
'nh
'nf
'ns
.>x
.>w
.nr:F 1
.FE
'rm>x
'rm>w
..
.deFD
'nr:i 0 
'nr:j 0 
'nr:k 0 
'nr:l 0 
'nr;z 0
'if\\n(.$ 'nr;z \\$1
'if\\n(;z-11 'nr;z 0
'if\\n(;z-7 'nr:l 1
'if\\n(;z-7 'nr;z -8
'if\\n(;z-3 'nr:k 1
'if\\n(;z-3 'nr;z -4
'if\\n(;z-1 'nr:j 1
'if\\n(;z-1 'nr;z -2
'if\\n(;z 'nr:i 1
'if\\n(.$-1 .nr:C 1
..
.deDS
.nr:t 0
.)J "\\$1" "\\$2"
..
.deDF
.nr:t 1
.)J "\\$1" "\\$2"
..
.de)J
.nr;i \\n(.i
'di
.if\\n(:D-1 .)D "FS:illegal inside TL or AS"
.if\\n(:F .)D "DS:missing FE"
.if\\n(:F .FE
.if\\n(:y .)D "DS:missing DE"
.if\\n(:y .DE 
.nr:y 1 
.ev1 
.)R 
'di>0
.nr:D 1
.nr;z 0+0\\$1
.if!\\n(:t .if!\\n(;z-1 .ll-\\n(;iu
.if\\n(;z .if!\\n(;z-1 .in+\\n(Sin
.if\\n(;z-1 .ce9999
.if\\n(;z-1 .nr:B 1
.if\\n(;z-1 .nr:t +2 
.nr;z 0+0\\$2
.nf
.if\\n(;z .fi
..
.de)z
.rn)y >z 
.ev1
.SP .5
.)R 
'nf
'rs
.ds}z ?\\n+(:x 
.\\*(}z 
.rm\\*(}z 
.)R 
.if\\n(:I-1 .if\\n(nl-\\n(:J .nr:I 0
.if!\\n(:I-1 .nr:I 0
.SP .5
.nr:J \\n(nl
.ev
'nr:z -1 
'if!\\n(:z 'nr:w 0 1
'if!\\n(:z 'nr:x 0 1
.rn>z )y 
..
.de)y
'if\\n(:z 'ds}z \\*(]z\\n+(:x
'if\\n(:z 'nr:x -1 
'if\\n(:z 'nr;z \\*(}z 
'if\\n(:z 'nr;y \\n(.pu-\\n(:ou-\\n(nlu-\\n(;zu 
'if\\n(:z 'if\\n(;yu>1v 'if2-\\n(:I .br
'if\\n(:z 'if\\n(;yu>1v 'if!2-\\n(:I .if\\n(nlu-\\n(:Ju .br
'if\\n(:z 'if\\n(;yu>1v .)z 
..
.de)x
'nr:v \\n(:z
.)y
'if!\\n(:v-\\n(:z 'bp
'if!\\n(:v-\\n(:z .)z
..
.de)w
'if\\n(:z .)x
'if\\n(:z .)w
..
.de)u
.if!27-\\n+(:z .)D "DS:too many displays"
.rn>0 ?\\n+(:w 
'ds}z ?\\n(:w
'nr\\*(}z \\n(:0 
'if!\\n(:z-1 .)y
..
.de)t
.ti\\n(.iu
.if\\n(Ds .SP .5
.nf
.if\\n(:t-1 .in-\\n(;iu
.ne\\n(:0u+.5p-1v 
'rs
.>0 
.)R
.if\\n(:I-1 .if\\n(nl-\\n(:J .nr:I 0
.if!\\n(:I-1 .nr:I 0
.in\\n(;iu
.if\\n(Ds .SP .5
.nr:J \\n(nl
..
.deDE
.if!\\n(:y .)D "DE:no DS or DF active"
.ce0
.br
'di
.nr:D 0
.)R 
.ll\\nWu
.ev
'nr:0 \\n(dn 
'nrdn 0
.nr;x \\n(:t
.if\\n(:t-1 .nr;x -2
.if!\\n(;x .)t 
.if\\n(;x .)u 
.nr:y 0 
.fi	\" MS hack
..
.de)R
'fi
.SA
'nh
'if\\n(Hy 'hy14
'in0
'ti0
'ps\\n(:Pp
'vs\\n(.sp+2p
..
.de)q
.br
.LC 0
.if\\n(:F .FE
.if\\n(:y .DE 
.if\\n(;n .NE 
.nr;x 0 
\&\c
.)w 
\&
'nr:0 \\n(.pu+1v-\\n(nlu-\\n(:Ou
'if\\n(:s 'if!\\n(:0 'nr;x 1
'if\\n(:q 'nr;x 1
'if\\n(;x \&\c
'if\\n(;x 'bp
'if\\n(;x \&
.wh-.5p )k
..
.de)k
.po0
.lt7.5i
.ps8
.tl'_''_'
.po
.ps
.lt
..
.if\n(mo-0 .dsDT January
.if\n(mo-1 .dsDT February
.if\n(mo-2 .dsDT March
.if\n(mo-3 .dsDT April
.if\n(mo-4 .dsDT May
.if\n(mo-5 .dsDT June
.if\n(mo-6 .dsDT July
.if\n(mo-7 .dsDT August
.if\n(mo-8 .dsDT September
.if\n(mo-9 .dsDT October
.if\n(mo-10 .dsDT November
.if\n(mo-11 .dsDT December
.asDT " \n(dy, 19\n(yr
.nr:r .6i 
.nr:m .8i 
.ds]y \\n(:p
'nr:i 0 
'nr:j 0 
'nr:k 0 
'nr:l 0 
.nr:n 0 
.nr:p 0 1 
.nr:o 0 
.nr:z 0 1 
.nr:y 0 
.nr:x 0 1 
.af:x a
.nr:w 0 1 
.af:w a
.nr:F 0
.ds]z "\\\\n(?
.S \nS
'ev0
.)R
.ll\nWu
.lt\nWu
'ev
'ev1
.)R
.ll\nWu
.lt\nWu
'ev
'ev2
.)R
.ll\nWu
.lt\nWu
'ev
'wh0 )h
.nr:o \n(:mu 
.nr:O \n(:mu 
'wh-\n(:mu )f
'ch)f 15i
'wh-\n(:mu )n 
'ch)f -\n(:mu
'wh-\n(:ru )b
'em)q
.PH "''- \\\\nP -''
.if\nC .if\nC-2 .ds]C D\ R\ A\ F\ T
.if\nC .if\nC-2 .PF "''\\\\*(DT'' 
.if\nC .if!\nC-2 .if\nC-1 .ds]C ''DATE FILE COPY''
.if\nC .if!\nC-1 .ds]C ''OFFICIAL FILE COPY''
.if\nN-2  .nr:S 1
.if\nN-2  .PF "''\\\\n(H1-\\\\nP''"
.if\nN-2  .PH ""
.if\nD .PH "'\\*(RE line # \\\\n(.c'- \\\\nP -''
.if\nA .AF
.if\nB .if!\nB-2 .if!\nB-1 .so/usr/lib/tmac.mtoc
.if\nB .if!\nB-2 .if\nB-1 .so/usr/lib/tmac.mcs
.if\nB-2 .so/usr/lib/tmac.mtoc
.if\nB-2 .so/usr/lib/tmac.mcs
