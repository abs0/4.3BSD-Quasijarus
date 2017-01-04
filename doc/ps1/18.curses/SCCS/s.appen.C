h57212
s 00004/00003/00079
d D 6.1 86/04/23 23:47:42 mckusick 3 2
c Ken Arnold edits for document distributed with 4.3BSD
e
s 00000/00000/00082
d D 5.1 86/04/23 23:47:37 mckusick 2 1
c document distributed with 4.2BSD
e
s 00082/00000/00000
d D 4.1 86/04/23 23:47:33 mckusick 1 0
c document distributed with 4.1BSD
e
u
U
t
T
I 1
.\" Copyright (c) 1980 Regents of the University of California.
.\" All rights reserved.  The Berkeley software License Agreement
.\" specifies the terms and conditions for redistribution.
.\"
.\"	%W% (Berkeley) %G%
.\"
D 3
.ie t .he ''\fBAppendix C\fR''
E 3
I 3
.ie t .oh '\*(Ln Appendix C''PS1:18-%'
.eh 'PS1:18-%''\*(Ln Appendix C'
E 3
.el .he ''\fIAppendix C\fR''
.bp
.(x
.ti 0
.b "Appendix C"
.)x
.sh 1 "Examples" 1
.pp
Here we present a few examples
of how to use the package.
They attempt to be representative,
though not comprehensive.
.sh 1 "Screen Updating"
.pp
The following examples are intended to demonstrate
the basic structure of a program
using the screen updating sections of the package.
Several of the programs require calculational sections
which are irrelevant of to the example,
and are therefore usually not included.
It is hoped that the data structure definitions
give enough of an idea to allow understanding
of what the relevant portions do.
The rest is left as an exercise to the reader,
and will not be on the final.
.sh 2 "Twinkle"
.pp
This is a moderately simple program which prints
pretty patterns on the screen
that might even hold your interest for 30 seconds or more.
It switches between patterns of asterisks,
putting them on one by one in random order,
and then taking them off in the same fashion.
It is more efficient to write this
using only the motion optimization,
as is demonstrated below.
.(l I
.so twinkle1.gr
.)l
.sh 2 "Life"
.pp
D 3
This program plays the famous computer pattern game of life
E 3
I 3
This program fragment models the famous computer pattern game of life
E 3
(Scientific American, May, 1974).
The calculational routines create a linked list of structures
defining where each piece is.
Nothing here claims to be optimal,
merely demonstrative.
D 3
This program, however,
E 3
I 3
This code, however,
E 3
is a very good place to use the screen updating routines,
as it allows them to worry about what the last position looked like,
so you don't have to.
It also demonstrates some of the input routines.
.(l I
.so life.gr
.)l
.sh 1 "Motion optimization"
.pp
The following example shows how motion optimization
is written on its own.
Programs which flit from one place to another without
regard for what is already there
usually do not need the overhead of both space and time
associated with screen updating.
They should instead use motion optimization.
.sh 2 "Twinkle"
.pp
The
.b twinkle
program
is a good candidate for simple motion optimization.
Here is how it could be written
(only the routines that have been changed are shown):
.(l
.so twinkle2.gr
.)l
E 1
