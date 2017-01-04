h21537
s 00007/00000/00000
d D 1.1 86/08/01 08:56:16 sam 1 0
c date and time created 86/08/01 08:56:16 by sam
e
u
U
t
T
I 1
"	fix funny things done by mcount()"
"	fix its name
g/_mcount/s//mcount/g
"	fix funny name for minbrk used by monstartup() to limit brk()"
g/_minbrk/s//minbrk/g
w
q
E 1
