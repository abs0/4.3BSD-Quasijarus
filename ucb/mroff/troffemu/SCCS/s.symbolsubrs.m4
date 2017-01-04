h32353
s 00147/00000/00000
d D 2.1 2012/03/07 23:50:47 msokolov 1 0
c new ambitious approach to TroffEmu-Symbol using m4
e
u
U
t
T
I 1
dnl	%W%	(Berkeley)	%E%
/Subrs 66 array
dup 0 < 3 0 callothersubr pop pop setcurrentpoint return > |
dup 1 < 0 1 callothersubr return > |
dup 2 < 0 2 callothersubr return > |
dup 3 < return > |
dnl
dnl Subrs 4 through 44 are all hints
dnl
dup 4 < 402 18 hstem 454 211 vstem return > |
dup 5 < -18 55 hstem 402 18 hstem 625 36 hstem
	0 92 vstem 158 80 vstem 392 58 vstem return > |
dup 6 < -18 77 hstem 402 18 hstem 454 211 vstem return > |
dup 7 < -18 55 hstem 625 36 hstem
	0 92 vstem 158 80 vstem 392 58 vstem return > |
dup 8 < 624 61 hstem 273 81 vstem return > |
dup 9 < -17 42 hstem 320 76 vstem return > |
dup 10 < -17 98 hstem 320 76 vstem return > |
dup 11 < -18 37 hstem 308 78 vstem return > |
dup 12 < 648 37 hstem 13 70 vstem 298 73 vstem return > |
dup 13 < -18 37 hstem 0 76 vstem 308 78 vstem return > |
dup 14 < 0 18 hstem 90 104 vstem return > |
dup 15 < 0 42 hstem 449 114 vstem return > |
dup 16 < 655 18 hstem 90 104 vstem 431 103 vstem return > |
dup 17 < 328 42 hstem 633 40 hstem 90 104 vstem 431 103 vstem return > |
dup 18 < 0 42 hstem 328 42 hstem 90 104 vstem 449 114 vstem return > |
dup 19 < 632 41 hstem 90 104 vstem return > |
dup 20 < 57 callsubr 90 104 vstem return > |
dup 21 < 0 18 hstem 632 41 hstem 90 104 vstem 526 103 vstem return > |
dup 22 < 297 45 hstem 633 40 hstem 90 104 vstem 426 109 vstem return > |
dup 23 < 461 26 hstem 563 17 vstem return > |
dup 24 < -18 34 hstem 461 37 hstem 0 104 vstem return > |
dup 25 < -15 71 hstem 461 26 hstem 563 17 vstem return > |
dup 26 < 420 595 10 div hstem return > |
dup 27 < -231 89 hstem 420 80 hstem return > |
dup 28 < 494 -20 hstem 174 119 vstem return > |
dup 29 < 421 78 hstem 0 16 vstem 174 119 vstem return > |
dup 30 < 444 70 hstem 121 85 vstem 65 callsubr return > |
dup 31 < 452 54 hstem 438 89 vstem return > |
dup 32 < 444 70 hstem 65 callsubr return > |
dup 33 < 21 -21 hstem 452 54 hstem 0 18 vstem 121 85 vstem return > |
dup 34 < 21 -21 hstem 265 3763 100 div vstem return > |
dup 35 < 64 callsubr 505 19 vstem return > |
dup 36 < -17 68 hstem 500 -20 hstem 28 86 vstem 321 86 vstem return > |
dup 37 < 470 17 hstem 313 63 vstem return > |
dup 38 < 488 12 hstem 313 63 vstem return > |
dup 39 < 470 17 hstem 80 133 vstem 313 63 vstem return > |
dup 40 < 488 12 hstem 80 133 vstem return > |
dup 41 < 4 -21 hstem 470 17 hstem 80 133 vstem 313 63 vstem return > |
dup 42 < 696 55 hstem 97 113 vstem return > |
dup 43 < -101 23 hstem 728 23 hstem 97 113 vstem return > |
dup 44 < -101 23 hstem 696 55 hstem 97 113 vstem 568 113 vstem return > |
dnl
dnl Actual drawing Subrs start here
dnl
dup 45 < -55 -35 -9 -55 vhcurveto
	-18 vlineto 284 hlineto 18 vlineto
	-55 -35 9 55 hvcurveto return > |
dup 46 < dotsection -31 25 -25 31 vhcurveto 31 25 25 31 hvcurveto
	31 -25 25 -31 vhcurveto -31 -25 -25 -31 hvcurveto
	closepath dotsection return > |
dup 47 <
	% counter-clockwise circle of radius 345 starting at 180 deg
	-191 154 -154 191 vhcurveto 191 154 154 191 hvcurveto
	191 -154 154 -191 vhcurveto -191 -154 -154 -191 hvcurveto
	closepath return > |
dup 48 < 337 -17 rmoveto 82 0 74 26 58 48 rrcurveto
	97 80 26 113 0 86 rrcurveto
	0 82 -25 114 -98 79 rrcurveto
	-58 47 -76 27 -80 0 rrcurveto
	-80 0 -76 -27 -58 -47 rrcurveto
	-98 -79 -25 -114 0 -82 rrcurveto
	0 -86 26 -113 97 -80 rrcurveto
	58 -48 74 -26 82 0 rrcurveto closepath
	-168 571 rmoveto
	36 60 66 32 66 0 rrcurveto
	66 0 66 -32 36 -60 rrcurveto
	22 -34 8 -26 10 -42 rrcurveto
	20 -90 -4 -92 -16 -66 rrcurveto
	return > |
dup 49 < 190 -155 155 -190 vhcurveto
	-191 0 -155 -155 1 -190 rrcurveto
	-191 154 -154 191 vhcurveto
	190 1 155 153 0 191 rrcurveto closepath
	-40 hmoveto -169 -137 -136 -168 vhcurveto
	-169 -1 -136 137 0 168 rrcurveto
	-1 169 137 137 168 0 rrcurveto
	169 137 -137 -168 hvcurveto closepath
	return > |
dup 50 < 55 35 9 55 vhcurveto 18 vlineto -284 hlineto 63 callsubr return > |
dup 51 < 134 51 rmoveto
	-14 37 -56 39 -46 -38 rrcurveto
	-27 -22 -2 -71 61 -2 rrcurveto
	21 -1 30 24 -7 -44 rrcurveto
	-11 -69 -75 -26 -6 -13 rrcurveto
	-6 -15 6 -5 18 4 rrcurveto
	10 2 44 32 26 31 rrcurveto
	38 46 6 64 -10 27 rrcurveto closepath
	return > |
dup 52 < dotsection
	30 1 26 24 0 31 rrcurveto
	30 -26 26 -30 vhcurveto
	-31 -25 -26 -31 hvcurveto
	-30 25 -25 31 vhcurveto closepath
	dotsection return > |
dup 53 < dotsection
	-36 29 -29 36 vhcurveto
	36 29 29 36 hvcurveto
	36 -29 29 -36 vhcurveto
	-36 -29 -29 -36 hvcurveto closepath
	dotsection return > |
dup 54 < -12 -18 -23 -17 -16 -7 rrcurveto
	-34 -14 -25 -1 -20 6 rrcurveto
	-151 42 rlineto
	-73 20 -69 -22 -53 -70 rrcurveto
	43 -27 rlineto
	13 16 34 64 95 -27 rrcurveto
	150 -43 rlineto
	58 -17 81 25 39 66 rrcurveto closepath
	return > |
dup 55 < 47 callsubr
	40 hmoveto
	168 137 137 168 vhcurveto
	168 137 -137 -168 hvcurveto
	-168 -137 -137 -168 vhcurveto
	-168 -137 137 168 hvcurveto closepath
	endchar return > |
dup 56 <
	% clockwise circle of radius 292 starting at 180 deg
	161 131 131 161 vhcurveto 161 131 -131 -161 hvcurveto
	-161 -131 -131 -161 vhcurveto -161 -131 131 161 hvcurveto
	closepath return > |
dup 57 < 0 18 hstem 655 18 hstem return > |
dup 58 < 497 -230 rlineto 62 vlineto -433 199 rlineto 433 199 rlineto
	62 vlineto -497 -230 rlineto closepath endchar return > |
dup 59 < -497 230 rlineto -62 vlineto 433 -199 rlineto -433 -199 rlineto
	-62 vlineto 497 230 rlineto closepath endchar return > |
dup 60 < 524 hlineto 55 vlineto -524 hlineto closepath return > |
dup 61 < -526 hlineto -55 vlineto 526 hlineto closepath return > |
dup 62 < -19 -21 -35 -58 -121 38 rrcurveto
	-47 15 -57 30 -61 -5 rrcurveto
	-91 -7 -26 -49 -18 -22 rrcurveto
	return > |
dup 63 < -18 vlineto 55 35 -9 -55 hvcurveto return > |
dup 64 < -17 88 hstem 663 76 hstem 25 19 vstem 265 3763 100 div vstem return > |
dup 65 < 4175 10 div 88 vstem return > |
|-
E 1
