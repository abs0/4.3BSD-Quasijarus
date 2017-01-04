h20379
s 00001/00001/00041
d D 2.3 2012/08/04 20:40:00 msokolov 3 2
c comment fix
e
s 00001/00001/00041
d D 2.2 2012/07/23 07:46:53 msokolov 2 1
c use |- to def the charstrings
e
s 00042/00000/00000
d D 2.1 2012/07/23 06:35:04 msokolov 1 0
c TroffEmu-Special1.ps compiles
e
u
U
t
T
I 1
dnl	%W%	(Berkeley)	%E%
dnl
dnl We have recreated the original troff's rendition of the approxequal (\(~=)
dnl character by taking the /minus and /similar characters from Symbol,
dnl which just happen to have perfectly matching metrics, and combining
dnl them together like this:
dnl
D 3
dnl .ds ~= "\v'.098m'\z\(mi\v'-.098m'\v'-.087m'\(ap\v'.087m'"
E 3
I 3
dnl .ds ~= "\v'.098m'\z\(mi\v'-.098m'\v'-.087m'\(ap\v'.087m'
E 3
dnl
dnl In the TroffEmu-Special1 Type 1 font we achieve the same effect
dnl by having copied the charstring code for the two character pieces
dnl from Symbol, expanding all Subrs inline.  Hence our /approxequal
dnl charstring consists of the expanded /minus one from Symbol, the
dnl expanded /similar one from the same, and the necessary connecting
dnl motions.  Plus the combined hints.
dnl
/approxequal <
	11 549 hsbw
	% minus hint, adjusted
	135 55 hstem	% originally 233
	% tilde hints, adjusted
	464 46 vstem 13 55 vstem 321 49 hstem
	% start drawing the minus
	135 vmoveto	% originally 233
	% the following used to be subr 60
	524 hlineto 55 vlineto -524 hlineto closepath
	% we are now at (11,190) relative to the char origin
	% original tilde charstring starts the drawing at (492,307)
	% for us that point is (492,394)
	% hence we need to move from (11,190) to (492,394)
	481 204 rmoveto
	% the following used to be subr 62
	-19 -21 -35 -58 -121 38 rrcurveto
	-47 15 -57 30 -61 -5 rrcurveto
	-91 -7 -26 -49 -18 -22 rrcurveto
	% back to the /similar charstring
	41 -25 rlineto
	43 48 31 31 134 -47 rrcurveto
	88 -31 55 -9 57 27 rrcurveto
	44 21 12 31 7 9 rrcurveto closepath
	endchar
D 2
> readonly def
E 2
I 2
> |-
E 2
E 1
