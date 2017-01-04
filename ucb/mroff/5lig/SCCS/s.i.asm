h35577
s 00016/00004/00547
d D 1.4 10/09/13 01:06:21 msokolov 4 3
c make these characters accessible at their original expert code points as well
e
s 00077/00077/00474
d D 1.3 10/08/22 23:10:36 msokolov 3 2
c Subrs array compacted
e
s 00002/00001/00549
d D 1.2 10/08/22 20:50:52 msokolov 2 1
c threequartersemdash also accessible as emdash
c so that TroffEncoding can get to it
e
s 00550/00000/00000
d D 1.1 10/08/22 20:44:18 msokolov 1 0
c date and time created 10/08/22 20:44:18 by msokolov
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
%%BeginResource: font Troff5lig-Italic
11 dict begin
/FontInfo 10 dict dup begin
/version (%I%) readonly def
/Notice (Based on Adobe Garamond Italic Expert) readonly def
/FullName (Troff 5lig subset of Adobe Garamond Italic Expert) readonly def
/FamilyName (Adobe Garamond) readonly def
/Weight (Regular) readonly def
/isFixedPitch false def
/ItalicAngle -18.5 def
/UnderlinePosition -100 def
/UnderlineThickness 50 def
end readonly def
/FontName /Troff5lig-Italic def
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
/FontBBox{-182 -269 875 715}readonly def
currentdict end
dup /Private 17 dict dup begin
/|-{readonly def}bind def
/|{readonly put}bind def
/BlueValues [ -14 0 422 436 389 393 715 715 ] |-
/OtherBlues [ 240 247 -269 -269 ] |-
/BlueScale 0.0479583 def
/MinFeature{16 16} |-
/StdVW [74] |-
/ForceBold false def
/password 5839 def
/lenIV -1 def
/Erode{
9.5  dup 3 -1 roll 0.1 mul exch 0.5 sub mul cvi sub dup mul
74  0 dtransform dup mul exch dup mul add
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
/Subrs 178 array
E 3
I 3
/Subrs 30 array
E 3
dup 0 < 3 0 callothersubr pop pop setcurrentpoint return > |
dup 1 < 0 1 callothersubr return > |
dup 2 < 0 2 callothersubr return > |
dup 3 < return > |
dup 4 < 1 3 callothersubr pop callsubr return > |
D 3
dup 45 <
E 3
I 3
dup 5 <
E 3
	861 56 vstem
	-245 41 hstem
	357 37 hstem
	681 34 hstem
	return
	> |
D 3
dup 46 <
E 3
I 3
dup 6 <
E 3
	861 56 vstem
	-269 41 hstem
	357 37 hstem
	661 30 hstem
	return
	> |
D 3
dup 47 <
E 3
I 3
dup 7 <
E 3
	423 81 vstem
	545 84 vstem
	-269 41 hstem
	-14 62 hstem
D 3
	144 callsubr
E 3
I 3
	21 callsubr
E 3
	return
	> |
D 3
dup 48 <
E 3
I 3
dup 8 <
E 3
	423 81 vstem
	629 76 vstem
D 3
	170 callsubr
E 3
I 3
	28 callsubr
E 3
	return
	> |
D 3
dup 49 <
E 3
I 3
dup 9 <
E 3
	666 81 vstem
	788 84 vstem
	-245 41 hstem
	7 -21 hstem
D 3
	144 callsubr
E 3
I 3
	21 callsubr
E 3
	return
	> |
D 3
dup 50 <
E 3
I 3
dup 10 <
E 3
	666 81 vstem
	788 84 vstem
	-269 41 hstem
	-14 62 hstem
D 3
	144 callsubr
E 3
I 3
	21 callsubr
E 3
	return
	> |
D 3
dup 51 <
E 3
I 3
dup 11 <
E 3
	666 81 vstem
	875 76 vstem
D 3
	170 callsubr
E 3
I 3
	28 callsubr
E 3
	return
	> |
D 3
dup 52 <
E 3
I 3
dup 12 <
E 3
	666 81 vstem
	788 84 vstem
	-269 41 hstem
	7 -21 hstem
	357 37 hstem
	661 30 hstem
	return
	> |
D 3
dup 53 <
E 3
I 3
dup 13 <
E 3
	679 70 vstem
	875 34 vstem
	-245 41 hstem
	-14 46 hstem
D 3
	144 callsubr
E 3
I 3
	21 callsubr
E 3
	return
	> |
D 3
dup 54 <
E 3
I 3
dup 14 <
E 3
	679 70 vstem
	875 34 vstem
	-269 41 hstem
	-14 46 hstem
	357 37 hstem
	661 30 hstem
	return
	> |
D 3
dup 55 <
E 3
I 3
dup 15 <
E 3
	679 70 vstem
	875 34 vstem
	-269 41 hstem
	-14 46 hstem
D 3
	144 callsubr
E 3
I 3
	21 callsubr
E 3
	return
	> |
D 3
dup 115 <
E 3
I 3
dup 16 <
E 3
	-20 0 -26 14 -14 23 rrcurveto
	-8 13 -7 8 -14 -12 rrcurveto
	-7 -6 -12 -6 0 -24 rrcurveto
	-17 19 -34 46 vhcurveto
	59 0 43 39 12 12 rrcurveto
	return
	> |
D 3
dup 118 <
	161 callsubr
E 3
I 3
dup 17 <
	26 callsubr
E 3
	82 hlineto
D 3
	158 callsubr
	115 callsubr
	146 callsubr
E 3
I 3
	25 callsubr
	16 callsubr
	22 callsubr
E 3
	closepath
	9 37 rmoveto
D 3
	162 callsubr
E 3
I 3
	27 callsubr
E 3
	endchar return
	> |
D 3
dup 126 <
E 3
I 3
dup 18 <
E 3
	170 hlineto
	-87 -256 rlineto
	-17 -51 -5 -18 0 -16 rrcurveto
	-16 9 -14 29 vhcurveto
	84 0 63 83 26 50 rrcurveto
	0 10 -6 5 -10 -1 rrcurveto
	-46 -52 -47 -49 -22 0 rrcurveto
	-12 0 -1 10 8 23 rrcurveto
	160 472 rlineto
	37 108 10 28 14 36 rrcurveto
	-7 6 rlineto
	-14 -5 -17 -9 -28 -18 rrcurveto
	-21 20 -31 12 -29 0 rrcurveto
	return
	> |
D 3
dup 128 <
	158 callsubr
E 3
I 3
dup 19 <
	25 callsubr
E 3
	-20 0 -26 14 -14 23 rrcurveto
	-8 13 -7 8 -14 -12 rrcurveto
	-7 -5 -12 -9 0 -22 rrcurveto
	-17 19 -34 46 vhcurveto
	59 0 43 39 12 12 rrcurveto
D 3
	146 callsubr
E 3
I 3
	22 callsubr
E 3
	return
	> |
D 3
dup 129 <
E 3
I 3
dup 20 <
E 3
	-39 -131 -38 -176 -47 -163 rrcurveto
	-21 -75 -25 -16 -18 0 rrcurveto
D 3
	115 callsubr
E 3
I 3
	16 callsubr
E 3
	20 20 30 55 30 97 rrcurveto
	39 127 32 121 38 131 rrcurveto
	return
	> |
D 3
dup 144 <
E 3
I 3
dup 21 <
E 3
	357 37 hstem
	685 30 hstem
	return
	> |
D 3
dup 146 <
E 3
I 3
dup 22 <
E 3
	21 19 30 55 28 90 rrcurveto
	33 110 29 111 32 111 rrcurveto
	9 30 8 32 6 17 rrcurveto
	return
	> |
D 3
dup 147 <
E 3
I 3
dup 23 <
E 3
	0 9 -5 7 -10 1 rrcurveto
	-34 -39 -53 -35 -17 0 rrcurveto
	-8 0 1 12 4 10 rrcurveto
	114 285 rlineto
	11 28 2 25 -21 0 rrcurveto
	-18 0 -50 -14 -65 0 rrcurveto
	-95 hlineto
	return
	> |
D 3
dup 156 <
E 3
I 3
dup 24 <
E 3
	137 hlineto
	36 0 2 -7 -9 -24 rrcurveto
	-118 -304 rlineto
	-4 -11 1 -9 6 -7 rrcurveto
	5 -6 6 -3 5 0 rrcurveto
	69 0 103 90 15 29 rrcurveto
	return
	> |
D 3
dup 158 <
E 3
I 3
dup 25 <
E 3
	-48 -163 -33 -172 -51 -167 rrcurveto
	-21 -68 -24 -15 -18 0 rrcurveto
	return
	> |
D 3
dup 161 <
E 3
I 3
dup 26 <
E 3
	4 44 -43 21 -49 0 rrcurveto
	-64 0 -52 -30 -43 -52 rrcurveto
	-48 -57 -28 -76 -24 -82 rrcurveto
	-88 hlineto
	-13 -9 -2 -19 10 -9 rrcurveto
	return
	> |
D 3
dup 162 <
E 3
I 3
dup 27 <
E 3
	32 110 22 47 22 38 rrcurveto
	29 50 36 22 35 0 rrcurveto
	34 0 35 -30 4 -47 rrcurveto
	-36 -64 -21 -59 -20 -67 rrcurveto
	closepath return
	> |
D 3
dup 170 <
E 3
I 3
dup 28 <
E 3
	-269 41 hstem
	7 -21 hstem
D 3
	144 callsubr
E 3
I 3
	21 callsubr
E 3
	return
	> |
D 3
dup 177 <
E 3
I 3
dup 29 <
E 3
	32 19 -22 -45 hvcurveto
	-18 11 -7 18 vhcurveto
	19 28 13 30 hvcurveto
	47 -45 32 -64 vhcurveto
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
	16 750 hsbw
	0 766 vstem
	181 49 hstem
	16 230 rmoveto
	-16 -49 rlineto
	750 hlineto
	16 49 rlineto
	closepath endchar
	> |-
I 2
D 4
/emdash threequartersemdash def
E 4
E 2
/ff <
	-145 504 hsbw
	861 56 vstem
	-269 41 hstem
	357 37 hstem
	681 34 hstem
	546 357 rmoveto
D 3
	45 4 callsubr
	129 callsubr
E 3
I 3
	5 4 callsubr
	20 callsubr
E 3
	123 hlineto
	15 7 2 19 -7 11 rrcurveto
	-124 hlineto
	38 136 31 64 25 34 rrcurveto
	24 33 25 20 29 0 rrcurveto
	26 36 -18 -60 hvcurveto
	0 -13 8 -7 13 7 rrcurveto
	16 9 19 20 0 31 rrcurveto
	39 -40 26 -42 vhcurveto
	-57 0 -57 -22 -58 -69 rrcurveto
	-2 2 rlineto
D 3
	46 4 callsubr
	118 callsubr
E 3
I 3
	6 4 callsubr
	17 callsubr
E 3
	> |-
/fi <
	-145 503 hsbw
	423 81 vstem
	545 84 vstem
D 3
	170 callsubr
E 3
I 3
	28 callsubr
E 3
	303 357 rmoveto
D 3
	128 callsubr
	156 callsubr
	47 4 callsubr
	147 callsubr
E 3
I 3
	19 callsubr
	24 callsubr
	7 4 callsubr
	23 callsubr
E 3
	26 83 27 88 46 63 rrcurveto
D 3
	48 4 callsubr
E 3
I 3
	8 4 callsubr
E 3
	28 37 33 20 33 0 rrcurveto
D 3
	177 callsubr
E 3
I 3
	29 callsubr
E 3
	-56 0 -56 -24 -54 -57 rrcurveto
	-56 -59 -36 -97 -25 -84 rrcurveto
	-86 hlineto
	-13 -8 -4 -19 10 -10 rrcurveto
	closepath endchar
	> |-
/fl <
	-145 489 hsbw
	436 70 vstem
	632 34 vstem
	-269 41 hstem
	-14 46 hstem
D 3
	144 callsubr
E 3
I 3
	21 callsubr
E 3
	228 394 rmoveto
	-13 -9 -4 -19 10 -9 rrcurveto
	82 hlineto
D 3
	128 callsubr
	126 callsubr
E 3
I 3
	19 callsubr
	18 callsubr
E 3
	-61 0 -54 -32 -42 -47 rrcurveto
	-53 -61 -32 -78 -30 -103 rrcurveto
	closepath
	72 hmoveto
	40 136 33 66 27 37 rrcurveto
	24 32 29 20 35 0 rrcurveto
	42 0 30 -36 -17 -48 rrcurveto
	-71 -207 rlineto
	closepath endchar
	> |-
/ffi <
	-145 746 hsbw
	788 84 vstem
D 3
	170 callsubr
E 3
I 3
	28 callsubr
E 3
	546 357 rmoveto
D 3
	49 4 callsubr
	129 callsubr
	156 callsubr
	50 4 callsubr
	147 callsubr
E 3
I 3
	9 4 callsubr
	20 callsubr
	24 callsubr
	10 4 callsubr
	23 callsubr
E 3
	26 83 28 92 46 59 rrcurveto
D 3
	51 4 callsubr
E 3
I 3
	11 4 callsubr
E 3
	30 37 31 20 35 0 rrcurveto
D 3
	177 callsubr
E 3
I 3
	29 callsubr
E 3
	-60 0 -62 -26 -57 -65 rrcurveto
	-2 2 rlineto
D 3
	52 4 callsubr
	118 callsubr
E 3
I 3
	12 4 callsubr
	17 callsubr
E 3
	> |-
/ffl <
	-145 732 hsbw
D 3
	55 callsubr
E 3
I 3
	15 callsubr
E 3
	303 357 rmoveto
D 3
	158 callsubr
	115 callsubr
	146 callsubr
E 3
I 3
	25 callsubr
	16 callsubr
	22 callsubr
E 3
	171 hlineto
D 3
	53 4 callsubr
	129 callsubr
	126 callsubr
E 3
I 3
	13 4 callsubr
	20 callsubr
	18 callsubr
E 3
	-50 0 -57 -22 -58 -69 rrcurveto
	-2 2 rlineto
D 3
	54 4 callsubr
	161 callsubr
E 3
I 3
	14 4 callsubr
	26 callsubr
E 3
	closepath
	163 37 rmoveto
D 3
	162 callsubr
E 3
I 3
	27 callsubr
E 3
	72 hmoveto
D 3
	55 4 callsubr
E 3
I 3
	15 4 callsubr
E 3
	40 140 29 62 30 38 rrcurveto
	25 31 33 20 31 0 rrcurveto
	42 0 30 -36 -17 -48 rrcurveto
	-71 -207 rlineto
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
