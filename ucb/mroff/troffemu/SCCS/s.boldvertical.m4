h10565
s 00011/00011/00301
d D 2.7 2012/07/23 07:46:52 msokolov 7 6
c use |- to def the charstrings
e
s 00030/00003/00282
d D 2.6 2012/03/11 18:29:30 msokolov 6 5
c bracerightmid implemented
e
s 00067/00000/00218
d D 2.5 2012/03/11 17:42:11 msokolov 5 4
c braceleftmid implemented
e
s 00037/00001/00181
d D 2.4 2012/03/11 04:59:43 msokolov 4 3
c braceright{tp,bt} implemented
e
s 00081/00000/00101
d D 2.3 2012/03/11 04:18:45 msokolov 3 2
c braceleft{tp,bt} implemented
e
s 00090/00041/00011
d D 2.2 2012/03/10 06:19:56 msokolov 2 1
c parameterized
e
s 00052/00000/00000
d D 2.1 2012/03/10 04:05:24 msokolov 1 0
c date and time created 2012/03/10 04:05:24 by msokolov
e
u
U
t
T
I 1
dnl	%W%	(Berkeley)	%E%
I 2
divert(-1)
% Definitions for all characters in the family

% Let's make the bv stem 110 units wide,
% centered in 250 unit spacing width.
% The spacing width of 1/4 em comes from the original width table
% in troff/tab3.c; the stem width has been inspired by the
% Varian/Versatec font times.s.36, which looks pretty good.
% Each pixel in a Varian/Versatec font made for point size 36
% corresponds to 10 units of ours.

define(`spacingwidth', 250)
define(`bvstem', 110)

% Vertical span from -210 to 790, following the times.s.36 model.

define(`bvbottom', -210)
define(`bvtop', 790)
define(`bvyspan', eval(bvtop - bvbottom))

divert(0)dnl
E 2
/boldvertical <
D 2
	% Let's try making bv a 110 unit stem centered in
	% 250 unit spacing width,
	% which all other chars in this family will then match.
	% Vertical span from -210 to 790,
	% following the times.s.36 model.
	% (each pixel in times.s.36 corresponds to 10 units of ours)
	70 250 hsbw
	0 110 vstem
	-210 vmoveto 110 hlineto 1000 vlineto -110 hlineto closepath
	endchar
E 2
I 2
	eval((spacingwidth - bvstem) / 2) spacingwidth hsbw
	0 bvstem vstem
	bvbottom vmoveto bvstem hlineto bvyspan vlineto
	-bvstem hlineto
	closepath endchar
E 2
D 7
> readonly def
E 7
I 7
> |-
E 7
D 2
/bracketlefttp <
	% Let's try doing the square brackets like times.s.36,
	% but perfectly consistent/symmetric.
	%
	% hstem thickness: times.s.36 uses 4 pixels for lf and rf,
	% but 5 pixels for lc and rc.  It looks really thin,
	% so let's make it 50 units.
	%
	% Protrusion from the bv stem: times.s.36 goes 16 pix
	% to the left for rc and rf, but 17 pix to the right
	% for lc and lf.
	% We are trying to emulate the original spacing width of
	% 1/4em, so we only have 70 units of sidebearing on each side
	% of the bv stem.  I've tried 100 units of protrusion, but
	% it was barely visible, so let's try 120.
E 2
I 2
divert(-1)
% Definitions for the square bracket pieces: lc, lf, rc, rf
E 2

D 2
	70 250 hsbw 0 110 vstem 740 50 hstem
	-210 vmoveto 110 hlineto 950 vlineto 120 hlineto
	50 vlineto -230 hlineto closepath
	endchar
E 2
I 2
% Let's try doing them like times.s.36 does: an unchanged bv stem
% with a horizontal appendage in the respective corner which makes
% the whole glyph L-shaped.

% hstem thickness: times.s.36 uses 4 pixels for lf and rf,
% but 5 pixels for lc and rc.  It looks really thin, and
% Adobe's version is a 55 unit stroke throughout, so let's
% try 55 units as well.

define(`bracket_hstem_thick', 55)

% Protrusion from the bv stem: times.s.36 goes 16 pix
% to the left for rc and rf, but 17 pix to the right
% for lc and lf.
% We are trying to emulate the original spacing width of
% 1/4em, so we only have 70 units of sidebearing on each side
% of the bv stem.  I've tried 100 units of protrusion, but
% it was barely visible, so let's try 120.

define(`bracket_protrusion', 120)

divert(0)dnl
/bracketlefttp <
	eval((spacingwidth - bvstem) / 2) spacingwidth hsbw
	0 bvstem vstem
	bvtop -bracket_hstem_thick hstem
	bvbottom vmoveto bvstem hlineto
	eval(bvyspan - bracket_hstem_thick) vlineto
	bracket_protrusion hlineto
	bracket_hstem_thick vlineto
	-eval(bvstem + bracket_protrusion) hlineto
	closepath endchar
E 2
D 7
> readonly def
E 7
I 7
> |-
E 7
/bracketleftbt <
D 2
	70 250 hsbw 0 110 vstem -210 50 hstem
	-210 vmoveto 230 hlineto 50 vlineto -120 hlineto
	950 vlineto -110 hlineto closepath
	endchar
E 2
I 2
	eval((spacingwidth - bvstem) / 2) spacingwidth hsbw
	0 bvstem vstem
	bvbottom bracket_hstem_thick hstem
	bvbottom vmoveto
	eval(bvstem + bracket_protrusion) hlineto
	bracket_hstem_thick vlineto
	-bracket_protrusion hlineto
	eval(bvyspan - bracket_hstem_thick) vlineto
	-bvstem hlineto
	closepath endchar
E 2
D 7
> readonly def
E 7
I 7
> |-
E 7
/bracketrighttp <
D 2
	-50 250 hsbw 120 110 vstem 740 50 hstem
	740 vmoveto 120 hlineto -950 vlineto 110 hlineto
	1000 vlineto -230 hlineto closepath
	endchar
E 2
I 2
	eval((spacingwidth - bvstem) / 2 - bracket_protrusion) spacingwidth hsbw
	bracket_protrusion bvstem vstem
	bvtop -bracket_hstem_thick hstem
	eval(bvtop - bracket_hstem_thick) vmoveto
	bracket_protrusion hlineto
	-eval(bvyspan - bracket_hstem_thick) vlineto
	bvstem hlineto
	bvyspan vlineto
	-eval(bvstem + bracket_protrusion) hlineto
	closepath endchar
E 2
D 7
> readonly def
E 7
I 7
> |-
E 7
/bracketrightbt <
D 2
	-50 250 hsbw 120 110 vstem -210 50 hstem
	-160 vmoveto -50 vlineto 230 hlineto 1000 vlineto
	-110 hlineto -950 vlineto closepath
	endchar
E 2
I 2
	eval((spacingwidth - bvstem) / 2 - bracket_protrusion) spacingwidth hsbw
	bracket_protrusion bvstem vstem
	bvbottom bracket_hstem_thick hstem
	eval(bvbottom + bracket_hstem_thick) vmoveto
	-bracket_hstem_thick vlineto
	eval(bvstem + bracket_protrusion) hlineto
	bvyspan vlineto
	-bvstem hlineto
	-eval(bvyspan - bracket_hstem_thick) vlineto
	closepath endchar
E 2
D 7
> readonly def
E 7
I 7
> |-
E 7
I 3
divert(-1)
% Definitions for the curly brace endpieces: lt, lb, rt, rb

% Once again I am following the times.s.36 model in that
% each of these 4 chars is made by taking bv and replacing one end
% with the respective curved element.  The vertical extent
% of these curved elements is shorter than bv and the square bracket
% pieces: by 10 pix for lt and rt, by 9 pix for lb and rb.

% reduce the shortening to make it more like the Usenix print
define(`brace_y_short', 50)
define(`brace_yspan', eval(bvyspan - brace_y_short))

% Sharp ends: the times.s.36 reference isn't of much help as it's a
% raster bitmap and isn't even consistent with itself, i.e., the 4
% characters aren't exact x-flip and y-flip mirror images like I think
% they should be.
%
% The sharp ends of these curly braces could have been made like the
% piercing point of a hypodermic needle (thickness smoothly decreasing
% all the way to zero) by having the inner and outer curves come to
% the same endpoint with slightly different tangents or even with the
% same tangent.  But that approach doesn't seem to be generally
% accepted in the world of Type 1 fonts; instead the generally accepted
% approach for similar features (e.g., serifs) is to bring the feature
% to a finite minimum thickness which is subject to a stem hint.
% So let's try the finite minimum thickness approach as well.

D 4
define(`brace_end_hstem', 23)
E 4
I 4
define(`brace_end_hstem', 40)
E 4

% Curves: Adobe's Symbol version uses two directly adjoining rrcurveto's
% for each curve (inner and outer); the tangent meeting the vertical
% stem is vertical as expected, but the inner and outer curve tangents
% connecting to the "blunted sharp end" (a short vlineto segment)
% aren't horizontal.  That looks like a bit more work, so for our
% first version let's try using a simple {hv,vh}curve for each curve.

define(`brace_protrusion', 120)		% from edge of bv stem to bbox
define(`outcurve_yspan', 420)		% from bbox to join w/vlineto
define(`outcurve_vctl', 150)		% abs(endpt - ctlpt)
define(`outcurve_hctl', 100)		% ""
define(`incurve_yspan', eval(outcurve_yspan - brace_end_hstem))
define(`incurve_vctl', 120)
define(`incurve_hctl', 50)

divert(0)dnl
/bracelefttp <
	eval((spacingwidth - bvstem) / 2) spacingwidth hsbw
	0 bvstem vstem
	eval(bvtop - brace_y_short) -brace_end_hstem hstem
	bvbottom vmoveto bvstem hlineto
	eval(brace_yspan - brace_end_hstem - incurve_yspan) vlineto
	incurve_vctl
	eval(brace_protrusion - incurve_hctl)
	eval(incurve_yspan - incurve_vctl)
	incurve_hctl vhcurveto
	brace_end_hstem vlineto
	-outcurve_hctl
	-eval(bvstem + brace_protrusion - outcurve_hctl)
	-eval(outcurve_yspan - outcurve_vctl)
	-outcurve_vctl hvcurveto
	closepath endchar
D 7
> readonly def
E 7
I 7
> |-
E 7
/braceleftbt <
	eval((spacingwidth - bvstem) / 2) spacingwidth hsbw
	0 bvstem vstem
	eval(bvbottom + brace_y_short) brace_end_hstem hstem
	bvtop vmoveto
	-eval(brace_yspan - outcurve_yspan) vlineto
	-outcurve_vctl
	eval(bvstem + brace_protrusion - outcurve_hctl)
	-eval(outcurve_yspan - outcurve_vctl)
	outcurve_hctl vhcurveto
	brace_end_hstem vlineto
	-incurve_hctl
	-eval(brace_protrusion - incurve_hctl)
	eval(incurve_yspan - incurve_vctl)
	incurve_vctl hvcurveto
	eval(brace_yspan - brace_end_hstem - incurve_yspan) vlineto
I 4
	closepath endchar
D 7
> readonly def
E 7
I 7
> |-
E 7
/bracerighttp <
	eval((spacingwidth - bvstem) / 2 - brace_protrusion) spacingwidth hsbw
	brace_protrusion bvstem vstem
	eval(bvtop - brace_y_short) -brace_end_hstem hstem
	eval(bvtop - brace_y_short - brace_end_hstem) vmoveto
	incurve_hctl
	eval(brace_protrusion - incurve_hctl)
	-eval(incurve_yspan - incurve_vctl)
	-incurve_vctl hvcurveto
	-eval(brace_yspan - brace_end_hstem - incurve_yspan) vlineto
	bvstem hlineto
	eval(brace_yspan - outcurve_yspan) vlineto
	outcurve_vctl
	-eval(bvstem + brace_protrusion - outcurve_hctl)
	eval(outcurve_yspan - outcurve_vctl)
	-outcurve_hctl vhcurveto
	closepath endchar
D 7
> readonly def
E 7
I 7
> |-
E 7
/bracerightbt <
	eval((spacingwidth - bvstem) / 2 - brace_protrusion) spacingwidth hsbw
	brace_protrusion bvstem vstem
	eval(bvbottom + brace_y_short) brace_end_hstem hstem
	eval(bvbottom + brace_y_short) vmoveto
	outcurve_hctl
	eval(bvstem + brace_protrusion - outcurve_hctl)
	eval(outcurve_yspan - outcurve_vctl)
	outcurve_vctl hvcurveto
	eval(brace_yspan - outcurve_yspan) vlineto
	-bvstem hlineto
	-eval(brace_yspan - brace_end_hstem - incurve_yspan) vlineto
	-incurve_vctl
	-eval(brace_protrusion - incurve_hctl)
	-eval(incurve_yspan - incurve_vctl)
	-incurve_hctl vhcurveto
E 4
	closepath endchar
D 7
> readonly def
E 7
I 7
> |-
E 7
I 5
divert(-1)
% Definitions for the curly brace middle pieces: lk and rk

define(`brace_mid_hstem', 40)		% thickness in y dimension
define(`brace_mid_xthick', 30)		% "" in x dimension at thinnest point
define(`straightv_in', 375)		% from top/bottom to inner curve start

% The outer contour starts to curve closer to the centre than the inner
% one, thereby producing a smoother thinning.

define(`straightv_out', eval(straightv_in + 40))

% Once again, we'll make our job easier by using just one rrcurveto
% segment for each curve, although Adobe's Symbol uses two.
% But we'll use non-horizontal tangents at the centre.

define(`outcurve_yspan', eval((bvyspan - brace_mid_hstem) / 2 - straightv_out))
define(`outcurve_ctg_x', 57)
define(`outcurve_ctg_y', 14)
define(`outcurve_vctl', 50)

define(`incurve_xspan', eval(bvstem + brace_protrusion - brace_mid_xthick))
define(`incurve_yspan', eval(bvyspan / 2 - straightv_in))
define(`incurve_ctg_x', 91)
define(`incurve_ctg_y', 29)
D 6
define(`incurve_vctl', 115)
E 6
I 6
define(`incurve_vctl', 95)
E 6

divert(0)dnl
/braceleftmid <
	eval((spacingwidth - bvstem) / 2 - brace_protrusion) spacingwidth hsbw
	brace_protrusion bvstem vstem
	eval(bvbottom + straightv_out + outcurve_yspan) brace_mid_hstem hstem
	eval(bvbottom + straightv_out + outcurve_yspan) vmoveto
	% outer curve going down
	outcurve_ctg_x -outcurve_ctg_y
	eval(brace_protrusion - outcurve_ctg_x)
	-eval(outcurve_yspan - outcurve_ctg_y - outcurve_vctl)
	0 -outcurve_vctl rrcurveto
	% straight lines for the bottom half
	-straightv_out vlineto
	bvstem hlineto
	straightv_in vlineto
	% bottom inner curve going up and left
	0 incurve_vctl
	-eval(incurve_xspan - incurve_ctg_x)
	eval(incurve_yspan - incurve_ctg_y - incurve_vctl)
	-incurve_ctg_x incurve_ctg_y rrcurveto
	% the other inner curve follows immediately
	incurve_ctg_x incurve_ctg_y
	eval(incurve_xspan - incurve_ctg_x)
	eval(incurve_yspan - incurve_ctg_y - incurve_vctl)
	0 incurve_vctl rrcurveto
	% straight lines for the top half
	straightv_in vlineto
	-bvstem hlineto
	-straightv_out vlineto
	% the final outer curve
	0 -outcurve_vctl
	-eval(brace_protrusion - outcurve_ctg_x)
	-eval(outcurve_yspan - outcurve_ctg_y - outcurve_vctl)
	-outcurve_ctg_x -outcurve_ctg_y rrcurveto
	closepath endchar
D 7
> readonly def
E 7
I 7
> |-
E 7
/bracerightmid <
D 6
	% placeholder for now
	0 spacingwidth hsbw endchar
E 6
I 6
	eval((spacingwidth - bvstem) / 2) spacingwidth hsbw
	0 bvstem vstem
	eval(bvbottom + straightv_out + outcurve_yspan) brace_mid_hstem hstem
	bvbottom vmoveto bvstem hlineto straightv_out vlineto
	% rising outer curve for the bottom half
	0 outcurve_vctl
	eval(brace_protrusion - outcurve_ctg_x)
	eval(outcurve_yspan - outcurve_ctg_y - outcurve_vctl)
	outcurve_ctg_x outcurve_ctg_y rrcurveto
	% central hstem
	brace_mid_hstem vlineto
	% upper outer curve
	-outcurve_ctg_x outcurve_ctg_y
	-eval(brace_protrusion - outcurve_ctg_x)
	eval(outcurve_yspan - outcurve_ctg_y - outcurve_vctl)
	0 outcurve_vctl rrcurveto
	% straight lines for the upper half
	straightv_out vlineto -bvstem hlineto -straightv_in vlineto
	% inner curves
	0 -incurve_vctl
	eval(incurve_xspan - incurve_ctg_x)
	-eval(incurve_yspan - incurve_ctg_y - incurve_vctl)
	incurve_ctg_x -incurve_ctg_y rrcurveto
	% the other inner curve follows immediately
	-incurve_ctg_x -incurve_ctg_y
	-eval(incurve_xspan - incurve_ctg_x)
	-eval(incurve_yspan - incurve_ctg_y - incurve_vctl)
	0 -incurve_vctl rrcurveto
	closepath endchar
E 6
D 7
> readonly def
E 7
I 7
> |-
E 7
E 5
E 3
E 1
