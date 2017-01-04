h56769
s 00002/00002/00016
d D 4.2 83/07/26 00:59:38 mckusick 2 1
c get rid of special case brk(); integrate into standard brk()
e
s 00018/00000/00000
d D 4.1 82/12/10 17:11:10 peter 1 0
c date and time created 82/12/10 17:11:10 by peter
e
u
U
t
T
I 1
"	%W% (Berkeley) %G%"
"	fix funny things done by mcount()"
"	fix its name, make it jsb'able, change registers to protect the caller"
g/_mcount/s//mcount/g
/mcount:/-
/.word/s/.word.*//
/the beginning of mcount()/mark a
/the end of mcount()/mark b
'a,'bs/r11/r5/g
'a,'bs/r10/r4/g
'a,'bs/r9/r3/g
'a,'bs/r8/r2/g
'a,'bs/r7/r1/g
""
D 2
"	fix funny name for curbrk used by brk()"
g/_curbrk/s//curbrk/g
E 2
I 2
"	fix funny name for minbrk used by monstartup() to limit brk()"
g/_minbrk/s//minbrk/g
E 2
w
q
E 1
