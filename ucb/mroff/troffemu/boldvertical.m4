dnl	@(#)boldvertical.m4	2.7	(Berkeley)	2012/07/23
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
/boldvertical <
	eval((spacingwidth - bvstem) / 2) spacingwidth hsbw
	0 bvstem vstem
	bvbottom vmoveto bvstem hlineto bvyspan vlineto
	-bvstem hlineto
	closepath endchar
> |-
divert(-1)
% Definitions for the square bracket pieces: lc, lf, rc, rf

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
> |-
/bracketleftbt <
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
> |-
/bracketrighttp <
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
> |-
/bracketrightbt <
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
> |-
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

define(`brace_end_hstem', 40)

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
> |-
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
	closepath endchar
> |-
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
> |-
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
	closepath endchar
> |-
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
define(`incurve_vctl', 95)

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
> |-
/bracerightmid <
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
> |-
