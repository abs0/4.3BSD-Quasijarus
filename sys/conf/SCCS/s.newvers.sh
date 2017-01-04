h50305
s 00002/00002/00016
d D 7.3 99/01/07 22:05:02 msokolov 10 9
c Started Quasijarus Project. This is now 4.3 BSD Quasijarus UNIX
e
s 00004/00004/00014
d D 7.2 89/04/25 10:09:35 mckusick 9 8
c do not use absolute pathname for echo
e
s 00001/00001/00017
d D 7.1 86/06/05 01:47:02 mckusick 8 7
c 4.3BSD release version
e
s 00004/00004/00014
d D 1.7 86/01/09 19:42:20 mckusick 7 6
c use /bin/echo (from Doug Kingston <mcvax!dpk@seismo.CSS.GOV>)
e
s 00009/00014/00009
d D 1.6 85/08/29 17:55:27 bloom 6 5
c fix 2 field timezones from date (from mcvax!jim)
e
s 00008/00001/00015
d D 1.5 85/06/08 12:07:16 mckusick 5 4
c Add copyright
e
s 00013/00005/00003
d D 1.4 85/06/03 08:38:47 karels 4 3
c separate sccs line
e
s 00003/00002/00005
d D 1.3 85/05/08 21:48:55 karels 3 2
c add sccs hack for what; bump version!
e
s 00001/00001/00006
d D 1.2 84/08/28 12:15:09 bloom 2 1
c Add info about who compiled the kernel and where
e
s 00007/00000/00000
d D 1.1 84/08/28 12:06:05 bloom 1 0
c date and time created 84/08/28 12:06:05 by bloom
e
u
U
t
T
I 1
D 5
#sccsid	%M%	%I%	%E%
E 5
I 5
#!/bin/sh -
#
D 8
# Copyright (c) 1980 Regents of the University of California.
E 8
I 8
# Copyright (c) 1980, 1986 Regents of the University of California.
E 8
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
E 5
D 6
if [ ! -r version ]; then echo 0 > version; fi
E 6
I 6
if [ ! -r version ]
then
D 7
	echo 0 > version
E 7
I 7
D 9
	/bin/echo 0 > version
E 9
I 9
	echo 0 > version
E 9
E 7
fi
E 6
touch version
D 4
awk '	{	version = $1 + 1; }\
D 3
END	{	printf "char version[] = \"4.2 BSD UNIX #%d: ", version > "vers.c";\
		printf "%d\n", version > "version"; }' < version
E 3
I 3
END	{	printf "static char sccs[4] = '"{'@', '(', '#', ')'}"';\n";\
		printf "char version[] = \"4.3 BSD UNIX #%d: ", version ;\
		printf "%d\n", version > "version"; }' > vers.c < version
E 3
D 2
echo `date`'\n";' >> vers.c
E 2
I 2
echo `date`'\n    '$USER'@'`hostname`':'`pwd`'\n";' >> vers.c
E 4
I 4
D 6
echo `cat version` ${USER-root} `pwd` `date` `hostname` | \
awk ' {
	version = $1 + 1; user = $2; host = $10; dir = $3; \
	date = $4 " " $5 " " $6 " " $7 " " $8 " " $9;
}\
END {
	printf "char sccs[] = \"@(#)4.3 BSD #%d: %s (%s@%s:%s)\\n\";\n",\
		version, date, user, host, dir ;\
	printf "char version[] = \"4.3 BSD UNIX #%d: %s\\n", \
		version, date; \
	printf "    %s@%s:%s\\n\";\n", user, host, dir;
	printf "%d\n", version > "version";
}' > vers.c
E 6
I 6
v=`cat version` u=${USER-root} d=`pwd` h=`hostname` t=`date`
D 7
( echo "char sccs[] = \"@(#)4.3 BSD #${v}: ${t} (${u}@${h}:${d})\\n\";" ;
  echo "char version[] = \"4.3 BSD UNIX #${v}: ${t}\\n    ${u}@${h}:${d}\\n\";"
E 7
I 7
D 9
( /bin/echo "char sccs[] = \"@(#)4.3 BSD #${v}: ${t} (${u}@${h}:${d})\\n\";" ;
  /bin/echo "char version[] = \"4.3 BSD UNIX #${v}: ${t}\\n    ${u}@${h}:${d}\\n\";"
E 9
I 9
D 10
( echo "char sccs[] = \"@(#)4.3 BSD #${v}: ${t} (${u}@${h}:${d})\\n\";" ;
  echo "char version[] = \"4.3 BSD UNIX #${v}: ${t}\\n    ${u}@${h}:${d}\\n\";"
E 10
I 10
( echo "char sccs[] = \"@(#)4.3 BSD Quasijarus #${v}: ${t} (${u}@${h}:${d})\\n\";" ;
  echo "char version[] = \"4.3 BSD Quasijarus UNIX #${v}: ${t}\\n    ${u}@${h}:${d}\\n\";"
E 10
E 9
E 7
) > vers.c
D 7
echo `expr ${v} + 1` > version
E 7
I 7
D 9
/bin/echo `expr ${v} + 1` > version
E 9
I 9
echo `expr ${v} + 1` > version
E 9
E 7
E 6
E 4
E 2
E 1
