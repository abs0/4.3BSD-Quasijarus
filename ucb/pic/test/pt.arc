.nf
This should be a circle
.PS
arc;arc;arc;arc
.PE
This should be a wave
.PS
arc; arc cw; arc cw; arc
.PE
This should be an oval
.PS
arc; arc; line left; arc; arc; line right
.PE
This should be a ()
.PS
arc from 0,0 to 0,1.0 rad 1.0
arc from 0,1.0 to 0,0 rad 1.0
.PE
This ought to be the same
.PS
arc to 0,1.0 rad 1.
arc to 0,0
.PE
Arc down with arrow
.PS
arc cw ->
.PE
Arc up with arrow
.PS
arc ->
.PE
.bp
.ps 18
.vs 24
.PS
A: circle radius .50i "A"
circle radius .4i at A
move to A.e
move right 2i
B: circle radius .50i "B"
move down 1.5i from B.s
C: circle radius .50i "C"
move left 2i from C.w
D: circle radius .50i "D"
arc -> cw from A.e + 0,.1i to B.w + 0,.1i radius 3i
"a" at last arc.c + 0,3i + .1i
arc -> cw from B.w - 0,.1i to A.e - 0,.1i radius 3i
"a" at last arc.c - 0,3i - .1i
arc -> cw from D.e + 0,.1i to C.w + 0,.1i radius 3i
"a" at last arc.c + 0,3i + .1i
arc -> cw from C.w - 0,.1i to D.e - 0,.1i radius 3i
"a" at last arc.c - 0,3i - .1i
arc -> from A.s - .3i,0 to D.n - .3i,0 radius 3i
"b" at last arc.c - 3i + .2i,0
arc -> from D.n + .3i,0 to A.s + .3i,0 radius 3i
"b" at last arc.c + 3i + .2i,0
arc -> from B.s - .3i,0 to C.n - .3i,0 radius 3i
"b" at last arc.c - 3i + .2i,0
arc -> from C.n + .3i,0 to B.s + .3i,0 radius 3i
"b" at last arc.c + 3i + .2i,0
.PE
.PS 6i
A: circle radius .50i "A"
arrow "i" above
circle same "B"
arrow "g" above
circle same "C"
arrow "e" above
circle same "D"
arrow "\en" above
E: circle same "E"
circle radius .4i at E
.PE
