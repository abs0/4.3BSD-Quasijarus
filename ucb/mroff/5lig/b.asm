%!PS-Adobe-3.0 Resource-Font
%%Title: @(#)b.asm	1.4 (Berkeley) 2010/09/13
%%BeginResource: font Troff5lig-Bold
11 dict begin
/FontInfo 10 dict dup begin
/version (1.4) readonly def
/Notice (Based on Adobe Garamond Bold Expert) readonly def
/FullName (Troff 5lig subset of Adobe Garamond Bold Expert) readonly def
/FamilyName (Adobe Garamond) readonly def
/Weight (Bold) readonly def
/isFixedPitch false def
/ItalicAngle 0 def
/UnderlinePosition -100 def
/UnderlineThickness 50 def
end readonly def
/FontName /Troff5lig-Bold def
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
/PaintType 0 def
/FontType 1 def
/FontMatrix [0.001 0 0 0.001 0 0] readonly def
/FontBBox{-159 -251 1062 715}readonly def
currentdict end
dup /Private 17 dict dup begin
/|-{readonly def}bind def
/|{readonly put}bind def
/BlueValues [ -16 0 428 442 386 393 626 640 715 715 ] |-
/OtherBlues [ 240 247 -269 -255 ] |-
/BlueScale 0.0479583 def
/MinFeature{16 16} |-
/StdVW [130] |-
/ForceBold true def
/password 5839 def
/lenIV -1 def
/Erode{
16.5  dup 3 -1 roll 0.1 mul exch 0.5 sub mul cvi sub dup mul
130  0 dtransform dup mul exch dup mul add
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
/Subrs 27 array
dup 0 < 3 0 callothersubr pop pop setcurrentpoint return > |
dup 1 < 0 1 callothersubr return > |
dup 2 < 0 2 callothersubr return > |
dup 3 < return > |
dup 4 < 1 3 callothersubr pop callsubr return > |
dup 5 <
	23 callsubr
	645 46 hstem
	return
	> |
dup 6 <
	18 callsubr
	708 7 hstem
	return
	> |
dup 7 <
	18 callsubr
	667 48 hstem
	return
	> |
dup 8 <
	16 callsubr
	645 46 hstem
	return
	> |
dup 9 <
	16 callsubr
	708 7 hstem
	return
	> |
dup 10 <
	16 callsubr
	667 48 hstem
	return
	> |
dup 11 <
	43 346 rmoveto
	23 2 -1 -27 hvcurveto
	-202 vlineto
	25 callsubr
	42 1 rmoveto
	2 callsubr
	41 hmoveto
	15 callsubr
	202 vlineto
	-4 27 9 1 21 0 rrcurveto
	99 hlineto
	23 2 -1 -27 hvcurveto
	-202 vlineto
	return
	> |
dup 12 <
	0 -72 -4 -8 -26 -4 rrcurveto
	22 callsubr
	110 hmoveto
	2 callsubr
	-78 2 rmoveto
	2 callsubr
	35 1 rmoveto
	2 callsubr
	43 hmoveto
	2 callsubr
	return
	> |
dup 13 <
	-22 -48 -6 -73 0 -19 rrcurveto
	20 callsubr
	closepath
	218 54 rmoveto
	-25 -1 1 27 hvcurveto
	9 vlineto
	173 55 35 41 vhcurveto
	44 0 23 -46 7 -30 rrcurveto
	-15 -52 -5 -60 0 -36 rrcurveto
	-17 -3 -4 -19 vhcurveto
	closepath return
	> |
dup 14 <
	9 6 0 21 -8 6 rrcurveto
	-16 2 rlineto
	-33 4 -4 8 0 72 rrcurveto
	162 vlineto
	0 41 2 42 3 32 rrcurveto
	-1 10 -8 5 -8 0 rrcurveto
	-26 -6 -67 -2 -72 0 rrcurveto
	-77 hlineto
	-24 -2 -1 26 hvcurveto
	56 vlineto
	149 39 35 33 vhcurveto
	24 0 18 -11 20 -34 rrcurveto
	9 -15 10 -24 8 -13 rrcurveto
	8 -13 18 -8 19 0 rrcurveto
	37 34 24 41 hvcurveto
	57 -65 46 -101 vhcurveto
	return
	> |
dup 15 <
	2 callsubr
	47 hmoveto
	2 callsubr
	40 -1 rmoveto
	2 callsubr
	29 -2 rmoveto
	2 callsubr
	50 263 -3 0 callsubr
	9 6 0 21 -8 6 rrcurveto
	-13 2 rlineto
	-33 4 -4 8 0 72 rrcurveto
	return
	> |
dup 16 <
	68 130 348 130 628 130 vstem3
	-3 34 hstem
	346 54 hstem
	return
	> |
dup 17 <
	2 callsubr
	41 hmoveto
	2 callsubr
	47 hmoveto
	2 callsubr
	40 -1 rmoveto
	2 callsubr
	29 -2 rmoveto
	2 callsubr
	50 543 -3 0 callsubr
	9 6 0 21 -8 6 rrcurveto
	-13 2 rlineto
	-33 4 -4 8 0 72 rrcurveto
	202 vlineto
	return
	> |
dup 18 <
	68 130 vstem
	247 7 vstem
	348 130 vstem
	530 7 vstem
	-3 34 hstem
	346 54 hstem
	return
	> |
dup 19 <
	0 -70 -4 -8 -33 -4 rrcurveto
	-16 -2 rlineto
	-8 -6 0 -23 9 -6 rrcurveto
	1 callsubr
	115 hmoveto
	2 callsubr
	-83 2 rmoveto
	2 callsubr
	42 1 rmoveto
	return
	> |
dup 20 <
	0 -13 -9 -6 -13 -7 rrcurveto
	-43 -22 rlineto
	-5 -5 2 -18 6 -4 rrcurveto
	return
	> |
dup 21 <
	27 1 1 25 vhcurveto
	97 hlineto
	24 3 0 -25 hvcurveto
	-205 vlineto
	12 callsubr
	43 hmoveto
	2 callsubr
	42 -1 rmoveto
	2 callsubr
	32 -2 rmoveto
	2 callsubr
	return
	> |
dup 22 <
	-16 -2 rlineto
	-8 -6 0 -21 9 -6 rrcurveto
	1 callsubr
	return
	> |
dup 23 <
	68 130 vstem
	247 7 vstem
	348 130 vstem
	547 7 vstem
	-3 34 hstem
	346 54 hstem
	return
	> |
dup 24 <
	173 44 43 39 vhcurveto
	45 22 -50 -31 hvcurveto
	-161 vlineto
	-25 -3 0 -24 vhcurveto
	closepath endchar return
	> |
dup 25 <
	0 -72 -4 -8 -33 -4 rrcurveto
	22 callsubr
	115 hmoveto
	2 callsubr
	-83 2 rmoveto
	2 callsubr
	return
	> |
dup 26 <
	9 6 0 23 -8 6 rrcurveto
	-16 2 rlineto
	-33 4 -4 8 0 70 rrcurveto
	446 vlineto
	return
	> |
|-
2 index /CharStrings 7 dict dup begin
/ff <
	16 591 hsbw
	23 callsubr
	663 52 hstem
	11 callsubr
	12 callsubr
	45 hmoveto
	2 callsubr
	42 -1 rmoveto
	2 callsubr
	47 -2 rmoveto
	2 callsubr
	50 563 -3 0 callsubr
	9 6 0 21 -8 6 rrcurveto
	-33 3 rlineto
	-33 3 -4 8 0 72 rrcurveto
	202 vlineto
	27 1 1 25 vhcurveto
	89 hlineto
	9 6 4 15 0 13 rrcurveto
	0 9 -2 8 -5 3 rrcurveto
	-95 hlineto
	-25 -1 1 27 hvcurveto
	113 vlineto
	93 16 29 26 vhcurveto
	12 0 16 -11 43 -55 rrcurveto
	7 -8 12 -10 21 0 rrcurveto
	34 24 21 33 hvcurveto
	52 -59 30 -58 vhcurveto
	-87 0 -48 -37 -19 -22 rrcurveto
	5 4 callsubr
	-27 26 -51 9 -39 0 rrcurveto
	-113 0 -61 -63 -31 -67 rrcurveto
	13 callsubr
	endchar
	> |-
/fi <
	16 566 hsbw
	18 callsubr
	665 50 hstem
	68 116 rmoveto
	25 callsubr
	38 1 rmoveto
	2 callsubr
	45 hmoveto
	15 callsubr
	204 vlineto
	25 2 1 24 vhcurveto
	72 hlineto
	49 3 -9 -78 hvcurveto
	-143 vlineto
	12 callsubr
	44 hmoveto
	2 callsubr
	41 -1 rmoveto
	2 callsubr
	32 -2 rmoveto
	2 callsubr
	50 546 -3 0 callsubr
	14 callsubr
	-113 0 -63 -58 -34 -73 rrcurveto
	-23 -49 -8 -64 0 -50 rrcurveto
	20 callsubr
	37 hlineto
	23 2 -1 -27 hvcurveto
	closepath endchar
	> |-
/fl <
	16 566 hsbw
	7 callsubr
	43 346 rmoveto
	23 2 -1 -27 hvcurveto
	-202 vlineto
	19 callsubr
	2 callsubr
	41 hmoveto
	15 callsubr
	202 vlineto
	21 callsubr
	50 546 -3 0 callsubr
	26 callsubr
	6 4 callsubr
	0 63 1 42 2 41 rrcurveto
	7 4 callsubr
	-4 5 -7 2 -6 0 rrcurveto
	-21 -12 -21 -10 -24 -8 rrcurveto
	-23 16 -31 14 -53 0 rrcurveto
	-94 0 -66 -53 -33 -70 rrcurveto
	-21 -45 -9 -68 0 -58 rrcurveto
	20 callsubr
	closepath
	218 54 rmoveto
	-25 -1 1 27 hvcurveto
	23 vlineto
	24 callsubr
	> |-
/ffi <
	16 846 hsbw
	16 callsubr
	665 50 hstem
	11 callsubr
	0 -72 -4 -8 -26 -4 rrcurveto
	22 callsubr
	108 hmoveto
	2 callsubr
	-76 2 rmoveto
	2 callsubr
	35 1 rmoveto
	17 callsubr
	27 2 1 24 vhcurveto
	72 hlineto
	49 3 -9 -78 hvcurveto
	-143 vlineto
	12 callsubr
	44 hmoveto
	2 callsubr
	42 -1 rmoveto
	2 callsubr
	31 -2 rmoveto
	2 callsubr
	50 826 -3 0 callsubr
	14 callsubr
	-89 0 -55 -37 -22 -22 rrcurveto
	8 4 callsubr
	-27 26 -52 9 -42 0 rrcurveto
	-114 0 -61 -63 -31 -67 rrcurveto
	13 callsubr
	endchar
	> |-
/ffl <
	16 846 hsbw
	10 callsubr
	11 callsubr
	19 callsubr
	17 callsubr
	21 callsubr
	50 826 -3 0 callsubr
	26 callsubr
	9 4 callsubr
	0 63 1 42 2 41 rrcurveto
	10 4 callsubr
	-4 5 -7 2 -6 0 rrcurveto
	-21 -12 -21 -10 -24 -8 rrcurveto
	-23 16 -32 14 -54 0 rrcurveto
	-76 0 -55 -37 -20 -22 rrcurveto
	8 4 callsubr
	-27 26 -51 9 -39 0 rrcurveto
	-113 0 -61 -63 -31 -67 rrcurveto
	13 callsubr
	178 hmoveto
	-25 -1 1 27 hvcurveto
	23 vlineto
	10 4 callsubr
	24 callsubr
	> |-
/threequartersemdash <
	0 750 hsbw
	0 750 vstem
	173 69 hstem
	242 vmoveto
	-69 vlineto
	750 hlineto
	69 vlineto
	closepath endchar
	> |-
/.notdef < 0 260 hsbw endchar > |-
end
end
readonly put
readonly put
dup/FontName get exch definefont pop
%%EndResource
