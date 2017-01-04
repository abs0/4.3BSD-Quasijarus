dnl	@(#)bellsystem.m4	2.3	(Berkeley)	2012/03/09
/oldbell <

dnl This is the fruit of my first attempt at drawing the \(bs glyph
dnl back in 2004.  It looks good when magnified, but its "native" size
dnl is way too small - back in 2004 my intent was for this character
dnl to appear only on the ttcharset page of USD:25 and nowhere else,
dnl hence I was viewing it as "lip service".  Now (2010-2012) the goal
dnl is to render this character properly, in the size it was meant to
dnl have, hence this old rendition has become a poor fit.

	43 768 hsbw
	% hints for the circle
	637 53 vstem 0 53 vstem
	-17 53 hstem 620 53 hstem
	% hints for the bell
	305 80 vstem	% bell top and bottom tip
	132 61 vstem 497 61 vstem	% sides
	185 50 hstem	% bottom horizontal piece
	459 50 hstem	% top horizontal piece
	328 vmoveto
	47 callsubr
	53 hmoveto
	56 callsubr
	% trace outer contour of the bell
	% comments give coordinates relative to the centre
	332 -143 rmoveto 173 hlineto 97 vlineto	% at (213,-46)
	-15 0 -48 6 -3 30 rrcurveto	% ctl points (198,-46) and (150,-40)
	-12 129 rlineto	% slant rising from (147,-10) to (135,119)
	% need to curve to (83,181)
	-3 31 -23 31 -26 0 rrcurveto	% ctl points (132,150) and (109,181)
	-43 hlineto	% at (40,181)
	40 vlineto -80 hlineto -40 vlineto	% bell top
	% now do the other side (reverse the steps)
	-43 hlineto -26 0 -23 -31 -3 -31 rrcurveto -12 -129 rlineto
	-3 -30 -48 -6 -15 0 rrcurveto -97 vlineto 173 hlineto
	% bottom tip
	-50 vlineto 80 hlineto closepath	% end at (40,-193)
	% trace inner contour starting at (-152,-93)
	-192 100 rmoveto 18 vlineto	% at (-152,-75)
	25 0 27 25 3 40 rrcurveto	% ctl points (-127,-75) and (-100,-50)
	12 129 rlineto	% slant rising from (-97,-10) to (-85,119)
	1 9 5 3 16 0 rrcurveto	% ctl points (-84,128) and (-79,131)
	% at (-63,131) top of inner contour
	126 hlineto
	% do the other side
	16 0 5 -3 1 -9 rrcurveto 12 -129 rlineto 3 -40 27 -25 25 0 rrcurveto
	-18 vlineto closepath
	endchar
> |-
/bellsystem <

dnl This is going to be the new rendition of the \(bs character,
dnl intended to replace the "SuperSpecial" hack of scaling the old
dnl 2004 version.
dnl This time all metrics are done via m4 so they can be tweaked at will.

	63 1139 hsbw	% these can always be tweaked independently

define(`outerrad', 512)		% for the whole glyph
define(`outerdiam', eval(outerrad * 2))
define(`bottomy', -200)		% vertical positioning
define(`cinnerrad', 433)	% circle inner radius
define(`circlethick', eval(outerrad-cinnerrad))	% thickness of the circle stroke

	% hints for the circle
	0 circlethick vstem outerdiam -circlethick vstem
	bottomy circlethick hstem
	eval(bottomy + outerdiam) -circlethick hstem

dnl metrics for the bell (unsigned abs values)
define(`bellctrwid', 118)	% bell top and bottom tip, horiz width
define(`belltopheight', 59)	% y dim of the very top piece
define(`topplankthick', 75)	% thickness of the top plank
define(`ctrtotopplank', 194)	% from centre to inner edge of top plank
define(`bellbtmwid', 632)	% widest extent at bottom, full x width
define(`btmplankthick', 75)	% thickness of the bottom plank
define(`ctrtobtmplank', 138)	% from centre to inner edge of bottom plank
define(`sidewidth', 90)		% x width of the blocks at extremities
define(`sideheight', 144)	% y height of the ""
define(`btmtipheight', 75)	% y dim of the bottom tip

	% hstem hints for the bell
	eval(bottomy + outerrad - ctrtobtmplank) -btmplankthick hstem
	eval(bottomy + outerrad + ctrtotopplank) topplankthick hstem
	% vstem hints for the bell
	eval(outerrad - bellbtmwid/2) sidewidth vstem
	eval(outerrad + bellbtmwid/2) -sidewidth vstem
	eval(outerrad - bellctrwid/2) bellctrwid vstem

dnl Start drawing!  The outer contour of the circle comes first.
	eval(bottomy + outerrad) vmoveto

dnl m4 can't do the floating multiplication by (sqrt(2) - 1) * 4 / 3,
dnl so we have to do it manually.

define(`bezout', 283)		% from corner to ctl point
define(`bezrem', eval(outerrad-bezout))
	-bezout bezrem -bezrem bezout vhcurveto
	bezout bezrem bezrem bezout hvcurveto
	bezout -bezrem bezrem -bezout vhcurveto
	-bezout -bezrem -bezrem -bezout hvcurveto
	closepath

dnl now the inner contour of the circle

	circlethick hmoveto
define(`bezout', 239)
define(`bezrem', eval(cinnerrad-bezout))
	bezout bezrem bezrem bezout vhcurveto
	bezout bezrem -bezrem -bezout hvcurveto
	-bezout -bezrem -bezrem -bezout vhcurveto
	-bezout -bezrem bezrem bezout hvcurveto
	closepath

dnl Now draw the outer contour of the bell, starting at the
dnl lower left extremity.

	eval(cinnerrad - bellbtmwid/2) -eval(ctrtobtmplank + btmplankthick)
	rmoveto
	eval(bellbtmwid/2 - bellctrwid/2) hlineto
	-btmtipheight vlineto bellctrwid hlineto btmtipheight vlineto
	eval(bellbtmwid/2 - bellctrwid/2) hlineto
	sideheight vlineto

dnl the hard part begins: curves!
dnl definitions for the lower curve of the outer contour
dnl all definitions are given as unsigned absolute values
define(`lcurve_fullx', 98)	% full x extent from endpoint to endpoint
define(`lcurve_fully', 53)	% full y extent ""
define(`lcurve_botxctl', 22)	% x dist from bottom endpt to ctl pt
define(`lcurve_botyctl', 0)	% y dist ""
define(`lcurve_topxctl', 5)	% x dist from top endpt to ctl pt
define(`lcurve_topyctl', 44)	% y dist ""

dnl definitions for the upper curve of the outer contour
define(`ucurve_topx_fromctr', 123)	% from ctr to x coord of top endpt
dnl the rest have the same meaning as for the lower curve
define(`ucurve_fullx', 77)
define(`ucurve_fully', 92)
define(`ucurve_botxctl', 5)
define(`ucurve_botyctl', 46)
define(`ucurve_topxctl', 39)
define(`ucurve_topyctl', 0)

dnl now draw it!

	-lcurve_botxctl lcurve_botyctl
	-eval(lcurve_fullx - lcurve_botxctl - lcurve_topxctl)
	eval(lcurve_fully - lcurve_botyctl - lcurve_topyctl)
	-lcurve_topxctl lcurve_topyctl rrcurveto
	% rising slant
	eval((ucurve_topx_fromctr+ucurve_fullx) - (bellbtmwid/2-lcurve_fullx))
	eval(ctrtotopplank + ctrtobtmplank - (sideheight - btmplankthick)
		- lcurve_fully - ucurve_fully + topplankthick) rlineto
	% upper curve
	-ucurve_botxctl ucurve_botyctl
	-eval(ucurve_fullx - ucurve_botxctl - ucurve_topxctl)
	eval(ucurve_fully - ucurve_botyctl - ucurve_topyctl)
	-ucurve_topxctl ucurve_topyctl rrcurveto
	% bell top
	-eval(ucurve_topx_fromctr - bellctrwid/2) hlineto
	belltopheight vlineto -bellctrwid hlineto -belltopheight vlineto
	-eval(ucurve_topx_fromctr - bellctrwid/2) hlineto
	% reverse upper curve
	-ucurve_topxctl -ucurve_topyctl
	-eval(ucurve_fullx - ucurve_botxctl - ucurve_topxctl)
	-eval(ucurve_fully - ucurve_botyctl - ucurve_topyctl)
	-ucurve_botxctl -ucurve_botyctl rrcurveto
	% falling slant
	eval((ucurve_topx_fromctr+ucurve_fullx) - (bellbtmwid/2-lcurve_fullx))
	-eval(ctrtotopplank + ctrtobtmplank - (sideheight - btmplankthick)
		- lcurve_fully - ucurve_fully + topplankthick) rlineto
	% reverse lower curve
	-lcurve_topxctl -lcurve_topyctl
	-eval(lcurve_fullx - lcurve_botxctl - lcurve_topxctl)
	-eval(lcurve_fully - lcurve_botyctl - lcurve_topyctl)
	-lcurve_botxctl -lcurve_botyctl rrcurveto
	closepath

dnl Now draw the inner contour of the bell, starting at the
dnl lower left extremity.

	sidewidth -eval(sideheight - btmplankthick) rmoveto

dnl once again we need metrics for the curves
define(`straightvert_before_lcurve', 27)
define(`lcurve_fullx', 82)
define(`lcurve_fully', 96)
define(`lcurve_botxctl', 37)
define(`lcurve_botyctl', 0)
define(`lcurve_topxctl', 5)
define(`lcurve_topyctl', 59)

define(`ucurve_topx_fromctr', 93)
define(`ucurve_fullx', 33)
define(`ucurve_fully', 18)
define(`ucurve_botxctl', 2)
define(`ucurve_botyctl', 13)
define(`ucurve_topxctl', 24)
define(`ucurve_topyctl', 0)

dnl now draw it

	straightvert_before_lcurve vlineto
	% lower curve
	lcurve_botxctl lcurve_botyctl
	eval(lcurve_fullx - lcurve_botxctl - lcurve_topxctl)
	eval(lcurve_fully - lcurve_botyctl - lcurve_topyctl)
	lcurve_topxctl lcurve_topyctl rrcurveto
	% rising slant
	eval((bellbtmwid/2 - sidewidth - lcurve_fullx) -
		(ucurve_topx_fromctr + ucurve_fullx))
	eval(ctrtotopplank + ctrtobtmplank - straightvert_before_lcurve
		- lcurve_fully - ucurve_fully) rlineto
	% upper curve
	ucurve_botxctl ucurve_botyctl
	eval(ucurve_fullx - ucurve_botxctl - ucurve_topxctl)
	eval(ucurve_fully - ucurve_botyctl - ucurve_topyctl)
	ucurve_topxctl ucurve_topyctl rrcurveto
	% straight top
	eval(ucurve_topx_fromctr * 2) hlineto
	% reverse upper curve
	ucurve_topxctl -ucurve_topyctl
	eval(ucurve_fullx - ucurve_botxctl - ucurve_topxctl)
	-eval(ucurve_fully - ucurve_botyctl - ucurve_topyctl)
	ucurve_botxctl -ucurve_botyctl rrcurveto
	% falling slant
	eval((bellbtmwid/2 - sidewidth - lcurve_fullx) -
		(ucurve_topx_fromctr + ucurve_fullx))
	-eval(ctrtotopplank + ctrtobtmplank - straightvert_before_lcurve
		- lcurve_fully - ucurve_fully) rlineto
	% reverse lower curve
	lcurve_topxctl -lcurve_topyctl
	eval(lcurve_fullx - lcurve_botxctl - lcurve_topxctl)
	-eval(lcurve_fully - lcurve_botyctl - lcurve_topyctl)
	lcurve_botxctl -lcurve_botyctl rrcurveto
	-straightvert_before_lcurve vlineto
	closepath

dnl We are done!!!

	endchar

> |-
