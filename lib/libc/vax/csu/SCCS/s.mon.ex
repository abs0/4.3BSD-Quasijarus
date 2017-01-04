h39292
s 00002/00002/00013
d D 4.4 83/07/26 00:59:34 mckusick 7 6
c get rid of special case brk(); integrate into standard brk()
e
s 00013/00003/00002
d D 4.3 82/12/10 17:10:37 peter 6 5
c use ex scripts instead of /lib/cpp.
e
s 00001/00001/00004
d D 4.2 82/04/19 17:11:28 rrh 5 4
c Putting to bed; don't know the changes
e
s 00000/00000/00005
d D 4.1 81/11/29 23:32:23 mckusic 4 3
c renumber to version 4
e
s 00001/00001/00004
d D 1.3 81/11/12 14:48:37 mckusic 3 2
c "gmcrt0" becomes "gcrt0"; eliminate stdio in gcrt0.c
e
s 00001/00001/00004
d D 1.2 81/10/20 15:49:12 peter 2 1
c name change to confuse to innocent/
e
s 00005/00000/00000
d D 1.1 81/10/15 13:57:35 peter 1 0
c date and time created 81/10/15 13:57:35 by peter
e
u
U
t
T
I 1
D 2
/	forgot to run ex script on monitor.s/d
E 2
I 2
D 3
/	forgot to run ex script on gmcrt0.s/d
E 3
I 3
D 5
/	forgot to run ex script on gcrt0.s/d
E 5
I 5
D 6
/	forgot to run ex script/d
E 5
E 3
E 2
?	.word	?d
E 6
I 6
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
""
D 7
"	fix funny name for curbrk used by brk()"
g/_curbrk/s//curbrk/g
E 7
I 7
"	fix funny name for minbrk used by monstartup() to limit brk()"
g/_minbrk/s//minbrk/g
E 7
E 6
w
q
D 6
"%W% (Berkeley) %G%"
E 6
E 1
