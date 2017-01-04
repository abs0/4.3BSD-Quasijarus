h18801
s 00016/00004/00529
d D 1.4 10/09/13 01:06:23 msokolov 4 3
c make these characters accessible at their original expert code points as well
e
s 00064/00064/00469
d D 1.3 10/08/22 23:01:23 msokolov 3 2
c Subrs array compacted
e
s 00002/00001/00531
d D 1.2 10/08/22 20:50:53 msokolov 2 1
c threequartersemdash also accessible as emdash
c so that TroffEncoding can get to it
e
s 00532/00000/00000
d D 1.1 10/08/22 20:44:19 msokolov 1 0
c date and time created 10/08/22 20:44:19 by msokolov
e
u
U
t
T
I 1
%!PS-Adobe-3.0 Resource-Font
%%Title: %W% (Berkeley) %E%
D 4
%%DocumentNeededResources: encoding TroffEncoding
E 4
%%BeginResource: font Troff5lig-Regular
11 dict begin
/FontInfo 10 dict dup begin
/version (%I%) readonly def
/Notice (Based on Adobe Garamond Regular Expert) readonly def
/FullName (Troff 5lig subset of Adobe Garamond Regular Expert) readonly def
/FamilyName (Adobe Garamond) readonly def
/Weight (Regular) readonly def
/isFixedPitch false def
/ItalicAngle 0 def
/UnderlinePosition -100 def
/UnderlineThickness 50 def
end readonly def
/FontName /Troff5lig-Regular def
D 4
/Encoding TroffEncoding def
E 4
I 4
/Encoding 256 array
0 1 255 {1 index exch /.notdef put} for
dup 28 /ff put
dup 29 /ffi put
dup 30 /ffl put
dup 61 /threequartersemdash put
dup 86 /ff put
dup 87 /fi put
dup 88 /fl put
dup 89 /ffi put
dup 90 /ffl put
dup 136 /threequartersemdash put
dup 138 /fi put
dup 139 /fl put
readonly def
E 4
/PaintType 0 def
/FontType 1 def
/FontMatrix [0.001 0 0 0.001 0 0] readonly def
/FontBBox{-183 -246 955 715}readonly def
currentdict end
dup /Private 17 dict dup begin
/|-{readonly def}bind def
/|{readonly put}bind def
/BlueValues [ -14 0 434 448 386 393 633 640 715 715 ] |-
/OtherBlues [ 240 247 -243 -243 ] |-
/BlueScale 0.0479583 def
/MinFeature{16 16} |-
/StdHW [32] |-
/StdVW [76] |-
/ForceBold false def
/password 5839 def
/lenIV -1 def
/Erode{
9.5  dup 3 -1 roll 0.1 mul exch 0.5 sub mul cvi sub dup mul
76  0 dtransform dup mul exch dup mul add
le{pop pop 1.0 1.0}{pop pop 0.0 1.5}ifelse}def
/OtherSubrs 
[systemdict /internaldict known
{1183615869 systemdict /internaldict get exec
/FlxProc known {save true} {false} ifelse}
{userdict /internaldict known not {
userdict /internaldict
{count 0 eq
{/internaldict errordict /invalidaccess get exec} if
dup type /integertype ne
{/internaldict errordict /invalidaccess get exec} if
dup 1183615869 eq
{pop 0}
{/internaldict errordict /invalidaccess get exec}
ifelse
}
dup 14 get 1 25 dict put
bind executeonly put
} if
1183615869 userdict /internaldict get exec
/FlxProc known {save true} {false} ifelse}
ifelse
[
systemdict /internaldict known not
{ 100 dict /begin cvx /mtx matrix /def cvx } if
systemdict /currentpacking known {currentpacking true setpacking} if
{
systemdict /internaldict known {
1183615869 systemdict /internaldict get exec
dup /$FlxDict known not {
dup dup length exch maxlength eq
{ pop userdict dup /$FlxDict known not
{ 100 dict begin /mtx matrix def
dup /$FlxDict currentdict put end } if }
{ 100 dict begin /mtx matrix def
dup /$FlxDict currentdict put end }
ifelse
} if /$FlxDict get begin } if
grestore
/exdef {exch def} def
/dmin exch abs 100 div def
/epX exdef /epY exdef
/c4y2 exdef /c4x2 exdef /c4y1 exdef /c4x1 exdef /c4y0 exdef /c4x0 exdef
/c3y2 exdef /c3x2 exdef /c3y1 exdef /c3x1 exdef /c3y0 exdef /c3x0 exdef
/c1y2 exdef /c1x2 exdef /c2x2 c4x2 def /c2y2 c4y2 def
/yflag c1y2 c3y2 sub abs c1x2 c3x2 sub abs gt def
/PickCoords { 
{c1x0 c1y0 c1x1 c1y1 c1x2 c1y2 c2x0 c2y0 c2x1 c2y1 c2x2 c2y2}
{c3x0 c3y0 c3x1 c3y1 c3x2 c3y2 c4x0 c4y0 c4x1 c4y1 c4x2 c4y2}
ifelse
/y5 exdef /x5 exdef /y4 exdef /x4 exdef /y3 exdef /x3 exdef
/y2 exdef /x2 exdef /y1 exdef /x1 exdef /y0 exdef /x0 exdef
} def
mtx currentmatrix pop 
mtx 0 get abs .00001 lt mtx 3 get abs .00001 lt or
{/flipXY -1 def}
{mtx 1 get abs .00001 lt mtx 2 get abs .00001 lt or
{/flipXY 1 def}
{/flipXY 0 def}
ifelse }
ifelse
/erosion 1 def 
systemdict /internaldict known {
 1183615869 systemdict /internaldict get exec dup 
/erosion known
{/erosion get /erosion exch def}
{pop}
ifelse
} if
yflag
{flipXY 0 eq c3y2 c4y2 eq or
{false PickCoords}
{/shrink c3y2 c4y2 eq
{0}{c1y2 c4y2 sub c3y2 c4y2 sub div abs} ifelse def
/yshrink {c4y2 sub shrink mul c4y2 add} def
/c1y0 c3y0 yshrink def /c1y1 c3y1 yshrink def
/c2y0 c4y0 yshrink def /c2y1 c4y1 yshrink def
/c1x0 c3x0 def /c1x1 c3x1 def /c2x0 c4x0 def /c2x1 c4x1 def
/dY 0 c3y2 c1y2 sub round
dtransform flipXY 1 eq {exch} if pop abs def
dY dmin lt PickCoords
y2 c1y2 sub abs 0.001 gt {
c1x2 c1y2 transform flipXY 1 eq {exch} if 
/cx exch def /cy exch def
/dY 0 y2 c1y2 sub round dtransform flipXY 1 eq {exch}
if pop def
dY round dup 0 ne
{/dY exdef }
{pop dY 0 lt {-1}{1} ifelse /dY exdef}
ifelse
/erode PaintType 2 ne erosion 0.5 ge and def
erode {/cy cy 0.5 sub def} if
/ey cy dY add def 
/ey ey ceiling ey sub ey floor add def 
erode {/ey ey 0.5 add def} if 
ey cx flipXY 1 eq {exch} if itransform exch pop
y2 sub /eShift exch def
/y1 y1 eShift add def /y2 y2 eShift add def /y3 y3
eShift add def
} if
} ifelse
}
{flipXY 0 eq c3x2 c4x2 eq or
{false PickCoords }
{/shrink c3x2 c4x2 eq
{0}{c1x2 c4x2 sub c3x2 c4x2 sub div abs} ifelse def
/xshrink {c4x2 sub shrink mul c4x2 add} def
/c1x0 c3x0 xshrink def /c1x1 c3x1 xshrink def
/c2x0 c4x0 xshrink def /c2x1 c4x1 xshrink def
/c1y0 c3y0 def /c1y1 c3y1 def /c2y0 c4y0 def /c2y1 c4y1 def
/dX c3x2 c1x2 sub round 0 dtransform
flipXY -1 eq {exch} if pop abs def
dX dmin lt PickCoords
x2 c1x2 sub abs 0.001 gt {
c1x2 c1y2 transform flipXY -1 eq {exch} if
/cy exch def /cx exch def 
/dX x2 c1x2 sub round 0 dtransform flipXY -1 eq {exch} if pop def
dX round dup 0 ne
{/dX exdef}
{pop dX 0 lt {-1}{1} ifelse /dX exdef}
ifelse
/erode PaintType 2 ne erosion .5 ge and def
erode {/cx cx .5 sub def} if
/ex cx dX add def
/ex ex ceiling ex sub ex floor add def
erode {/ex ex .5 add def} if
ex cy flipXY -1 eq {exch} if itransform pop
x2 sub /eShift exch def
/x1 x1 eShift add def /x2 x2 eShift add def /x3 x3 eShift add def
} if
} ifelse
} ifelse
x2 x5 eq y2 y5 eq or
{x5 y5 lineto }
{x0 y0 x1 y1 x2 y2 curveto
x3 y3 x4 y4 x5 y5 curveto}
ifelse
epY epX 
}
systemdict /currentpacking known {exch setpacking} if 
/exec cvx /end cvx ] cvx
executeonly
exch
{pop true exch restore} 
{ 
systemdict /internaldict known not
{1183615869 userdict /internaldict get exec
exch /FlxProc exch put true}
{1183615869 systemdict /internaldict get exec
dup length exch maxlength eq
{false} 
{1183615869 systemdict /internaldict get exec
exch /FlxProc exch put true}
ifelse}
ifelse}
ifelse
{systemdict /internaldict known
{{1183615869 systemdict /internaldict get exec /FlxProc get exec}}
{{1183615869 userdict /internaldict get exec /FlxProc get exec}}
ifelse executeonly
} if
{gsave currentpoint newpath moveto} executeonly 
{currentpoint grestore gsave currentpoint newpath moveto}
executeonly 
{
systemdict /internaldict known not
{pop 3}
{1183615869 systemdict /internaldict get exec
 dup /startlock known
 {/startlock get exec}
 {dup /strtlck known
 {/strtlck get exec}
 {pop 3}
 ifelse}
 ifelse}
 ifelse
} executeonly
]|-
D 3
/Subrs 302 array
E 3
I 3
/Subrs 22 array
E 3
dup 0 < 3 0 callothersubr pop pop setcurrentpoint return > |
dup 1 < 0 1 callothersubr return > |
dup 2 < 0 2 callothersubr return > |
dup 3 < return > |
dup 4 < 1 3 callothersubr pop callsubr return > |
D 3
dup 41 <
	269 callsubr
E 3
I 3
dup 5 <
	15 callsubr
E 3
	656 35 hstem
	return
	> |
D 3
dup 42 <
	279 callsubr
E 3
I 3
dup 6 <
	16 callsubr
E 3
	656 35 hstem
	return
	> |
D 3
dup 43 <
	279 callsubr
E 3
I 3
dup 7 <
	16 callsubr
E 3
	683 32 hstem
	return
	> |
D 3
dup 179 <
E 3
I 3
dup 8 <
E 3
	0 -72 -1 -10 -37 -5 rrcurveto
	-23 -3 rlineto
	-7 -5 2 -17 7 -3 rrcurveto
	1 callsubr
	96 hmoveto
D 3
	297 callsubr
E 3
I 3
	20 callsubr
E 3
	return
	> |
D 3
dup 199 <
E 3
I 3
dup 9 <
E 3
	-3 265 10 div hstem
	return
	> |
D 3
dup 201 <
E 3
I 3
dup 10 <
E 3
	65 112 rmoveto
D 3
	179 callsubr
E 3
I 3
	8 callsubr
E 3
	45 -2 rmoveto
	2 callsubr
	50 241 -3 0 callsubr
D 3
	288 callsubr
E 3
I 3
	18 callsubr
E 3
	-36 3 rlineto
	-36 3 -2 12 0 72 rrcurveto
	211 vlineto
	27 0 2 17 vhcurveto
	157 hlineto
	20 0 -2 -27 hvcurveto
	-211 vlineto
D 3
	179 callsubr
E 3
I 3
	8 callsubr
E 3
	41 -2 rmoveto
	2 callsubr
	50 505 -3 0 callsubr
D 3
	288 callsubr
E 3
I 3
	18 callsubr
E 3
	-32 3 rlineto
	-36 3 -2 12 0 72 rrcurveto
	return
	> |
D 3
dup 210 <
E 3
I 3
dup 11 <
E 3
	-98 0 -59 -66 -27 -58 rrcurveto
	-27 -55 -7 -66 0 -34 rrcurveto
D 3
	256 callsubr
E 3
I 3
	14 callsubr
E 3
	closepath
	103 71 rmoveto
	-29 0 1 27 hvcurveto
	5 vlineto
	2 105 9 124 109 0 rrcurveto
	return
	> |
D 3
dup 219 <
E 3
I 3
dup 12 <
E 3
	0 -72 -1 -10 -37 -5 rrcurveto
	-21 -3 rlineto
	-7 -5 2 -17 7 -3 rrcurveto
	1 callsubr
	94 hmoveto
D 3
	297 callsubr
E 3
I 3
	20 callsubr
E 3
	return
	> |
D 3
dup 244 <
	288 callsubr
E 3
I 3
dup 13 <
	18 callsubr
E 3
	-21 3 rlineto
	-36 5 -2 10 0 72 rrcurveto
	167 vlineto
	0 41 2 48 2 36 rrcurveto
	-2 3 -4 2 -4 0 rrcurveto
	-24 -9 -63 -6 -44 0 rrcurveto
	-112 hlineto
	-17 -2 6 25 hvcurveto
	11 vlineto
	return
	> |
D 3
dup 256 <
E 3
I 3
dup 14 <
E 3
	0 -10 -7 -6 -8 -4 rrcurveto
	-43 -21 rlineto
	-4 -6 1 -9 6 -4 rrcurveto
	35 hlineto
	20 0 -2 -27 hvcurveto
	return
	> |
D 3
dup 269 <
E 3
I 3
dup 15 <
E 3
	65 74 vstem
	333 74 vstem
D 3
	199 callsubr
E 3
I 3
	9 callsubr
E 3
	352 42 hstem
	return
	> |
D 3
dup 279 <
E 3
I 3
dup 16 <
E 3
	65 74 333 74 601 74 vstem3
D 3
	199 callsubr
E 3
I 3
	9 callsubr
E 3
	352 42 hstem
	return
	> |
D 3
dup 281 <
E 3
I 3
dup 17 <
E 3
	-15 17 -36 27 -62 0 rrcurveto
D 3
	210 callsubr
E 3
I 3
	11 callsubr
E 3
	53 0 37 -40 9 -31 rrcurveto
	-17 -58 -8 -53 0 -62 rrcurveto
	-10 -7 -8 -8 vhcurveto
	closepath return
	> |
D 3
dup 288 <
E 3
I 3
dup 18 <
E 3
	7 3 2 17 -7 5 rrcurveto
	return
	> |
D 3
dup 292 <
E 3
I 3
dup 19 <
E 3
	209 vlineto
	24 2 7 17 vhcurveto
	125 hlineto
	43 7 -5 -61 hvcurveto
	-174 vlineto
D 3
	219 callsubr
E 3
I 3
	12 callsubr
E 3
	30 -2 rmoveto
	2 callsubr
	return
	> |
D 3
dup 297 <
E 3
I 3
dup 20 <
E 3
	2 callsubr
	-66 2 rmoveto
	2 callsubr
	30 1 rmoveto
	2 callsubr
	36 hmoveto
	2 callsubr
	35 hmoveto
	2 callsubr
	29 -1 rmoveto
	2 callsubr
	return
	> |
D 3
dup 301 <
E 3
I 3
dup 21 <
E 3
	26 0 39 -17 29 -49 rrcurveto
	5 -8 7 -7 14 0 rrcurveto
	15 26 11 30 hvcurveto
	42 -56 36 -68 vhcurveto
	return
	> |
|-
D 2
2 index /CharStrings 7 dict dup begin
E 2
I 2
D 4
2 index /CharStrings 8 dict dup begin
E 4
I 4
2 index /CharStrings 7 dict dup begin
E 4
E 2
/threequartersemdash <
	0 750 hsbw
	0 750 vstem
	181 49 hstem
	230 vmoveto
	-49 vlineto
	750 hlineto
	49 vlineto
	closepath endchar
	> |-
I 2
D 4
/emdash threequartersemdash def
E 4
E 2
/ff <
	30 558 hsbw
D 3
	269 callsubr
E 3
I 3
	15 callsubr
E 3
	676 39 hstem
D 3
	201 callsubr
E 3
I 3
	10 callsubr
E 3
	211 vlineto
	27 0 2 17 vhcurveto
	107 hlineto
	11 4 7 28 -11 10 rrcurveto
	-114 hlineto
	-17 0 1 27 hvcurveto
	29 vlineto
	0 65 6 63 17 43 rrcurveto
	14 34 25 20 33 0 rrcurveto
	31 0 29 -23 18 -21 rrcurveto
	8 -9 6 -4 10 0 rrcurveto
	18 18 16 20 hvcurveto
	36 -43 24 -52 vhcurveto
	-66 0 -59 -37 -24 -31 rrcurveto
D 3
	41 4 callsubr
	281 callsubr
E 3
I 3
	5 4 callsubr
	17 callsubr
E 3
	endchar
	> |-
/fi <
	30 522 hsbw
D 3
	269 callsubr
E 3
I 3
	15 callsubr
E 3
	677 38 hstem
	65 112 rmoveto
D 3
	179 callsubr
E 3
I 3
	8 callsubr
E 3
	41 -2 rmoveto
	2 callsubr
	50 237 -3 0 callsubr
D 3
	288 callsubr
E 3
I 3
	18 callsubr
E 3
	-32 3 rlineto
	-36 3 -2 12 0 72 rrcurveto
D 3
	292 callsubr
E 3
I 3
	19 callsubr
E 3
	50 494 -3 0 callsubr
D 3
	244 callsubr
E 3
I 3
	13 callsubr
E 3
	155 36 86 78 vhcurveto
D 3
	301 callsubr
E 3
I 3
	21 callsubr
E 3
	-112 0 -61 -84 -21 -51 rrcurveto
	-23 -53 -8 -58 0 -57 rrcurveto
D 3
	256 callsubr
E 3
I 3
	14 callsubr
E 3
	closepath endchar
	> |-
/fl <
	30 522 hsbw
D 3
	269 callsubr
E 3
I 3
	15 callsubr
E 3
	683 32 hstem
	314 352 rmoveto
	18 1 -3 -17 hvcurveto
	-220 vlineto
D 3
	179 callsubr
E 3
I 3
	8 callsubr
E 3
	33 -2 rmoveto
	2 callsubr
	50 497 -3 0 callsubr
D 3
	288 callsubr
E 3
I 3
	18 callsubr
E 3
	-24 3 rlineto
	-36 5 -2 10 0 72 rrcurveto
	450 vlineto
	0 43 1 62 2 44 rrcurveto
	-3 2 -3 2 -6 0 rrcurveto
	-8 -8 -14 -14 -4 -4 rrcurveto
	-29 18 -32 8 -32 0 rrcurveto
	-107 0 -58 -75 -22 -54 rrcurveto
	-23 -56 -4 -55 0 -63 rrcurveto
D 3
	256 callsubr
E 3
I 3
	14 callsubr
E 3
	-211 vlineto
D 3
	179 callsubr
E 3
I 3
	8 callsubr
E 3
	40 -2 rmoveto
	2 callsubr
	50 236 -3 0 callsubr
D 3
	288 callsubr
E 3
I 3
	18 callsubr
E 3
	-31 3 rlineto
	-36 3 -2 12 0 72 rrcurveto
	209 vlineto
	31 1 0 18 vhcurveto
	closepath
	175 62 rmoveto
	-18 -4 -2 -15 vhcurveto
	-156 hlineto
	-17 -2 1 20 hvcurveto
	31 vlineto
	84 5 153 111 vhcurveto
	27 0 23 -18 11 -14 rrcurveto
	12 -16 5 -26 0 -34 rrcurveto
	closepath endchar
	> |-
/ffi <
	30 790 hsbw
D 3
	279 callsubr
E 3
I 3
	16 callsubr
E 3
	677 38 hstem
D 3
	201 callsubr
	292 callsubr
E 3
I 3
	10 callsubr
	19 callsubr
E 3
	50 762 -3 0 callsubr
D 3
	244 callsubr
E 3
I 3
	13 callsubr
E 3
	159 36 82 78 vhcurveto
D 3
	301 callsubr
E 3
I 3
	21 callsubr
E 3
	-76 0 -58 -37 -26 -32 rrcurveto
D 3
	42 4 callsubr
E 3
I 3
	6 4 callsubr
E 3
	-13 18 -40 27 -62 0 rrcurveto
D 3
	210 callsubr
E 3
I 3
	11 callsubr
E 3
	53 0 38 -40 9 -32 rrcurveto
	-18 -57 -8 -53 0 -62 rrcurveto
	-10 -7 -8 -8 vhcurveto
	closepath endchar
	> |-
/ffl <
	30 789 hsbw
D 3
	43 callsubr
	201 callsubr
E 3
I 3
	7 callsubr
	10 callsubr
E 3
	209 vlineto
	31 1 0 18 vhcurveto
	156 hlineto
	18 1 -3 -17 hvcurveto
	-220 vlineto
D 3
	219 callsubr
E 3
I 3
	12 callsubr
E 3
	32 -2 rmoveto
	2 callsubr
	50 764 -3 0 callsubr
D 3
	288 callsubr
E 3
I 3
	18 callsubr
E 3
	-23 3 rlineto
	-36 5 -2 10 0 72 rrcurveto
	450 vlineto
	0 43 1 62 2 44 rrcurveto
	-4 4 -3 0 -5 0 rrcurveto
	-8 -8 -14 -14 -4 -4 rrcurveto
	-29 18 -32 8 -36 0 rrcurveto
	-66 0 -57 -37 -24 -31 rrcurveto
D 3
	42 4 callsubr
	281 callsubr
E 3
I 3
	6 4 callsubr
	17 callsubr
E 3
	283 20 rmoveto
	-18 -4 -2 -15 vhcurveto
	-156 hlineto
	-17 -2 1 20 hvcurveto
	31 vlineto
D 3
	43 4 callsubr
E 3
I 3
	7 4 callsubr
E 3
	84 5 153 111 vhcurveto
	27 0 21 -15 13 -17 rrcurveto
	12 -16 5 -26 0 -34 rrcurveto
	closepath endchar
	> |-
/.notdef < 0 250 hsbw endchar > |-
end
end
readonly put
readonly put
dup/FontName get exch definefont pop
%%EndResource
E 1
