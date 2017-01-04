h41634
s 00002/00001/00036
d D 4.6 85/04/22 18:36:49 mckusick 6 5
c break up pipeline to reduce space needs in /tmp
e
s 00001/00000/00036
d D 4.5 85/03/24 18:24:14 serge 5 4
c chmod database world-readable after completion
e
s 00001/00001/00035
d D 4.4 83/07/21 12:06:06 mckusick 4 3
c generate complete database
e
s 00005/00004/00031
d D 4.3 83/07/21 11:22:57 mckusick 3 2
c move database to /usr/lib/find; restrict database to /usr
e
s 00001/00001/00034
d D 4.2 83/07/21 00:34:41 mckusick 2 1
c must use csh, not sh
e
s 00035/00000/00000
d D 4.1 83/07/21 00:15:12 mckusick 1 0
c date and time created 83/07/21 00:15:12 by mckusick
e
u
U
t
T
I 1
D 2
#! /bin/sh
E 2
I 2
#!/bin/csh -f
E 2
#
#	%W%	(Berkeley)	%E%
#
D 3
set LIBDIR = /usr/lib/find	# for subprograms
set FINDHONCHO = root		# for error messages
set FCODES = /etc/find.codes	# the database 
E 3
I 3
D 4
set SRCHPATHS = "/usr /bin /etc /lib"	# directories to be put in the database
E 4
I 4
set SRCHPATHS = "/"			# directories to be put in the database
E 4
set LIBDIR = /usr/lib/find		# for subprograms
set FINDHONCHO = root			# for error messages
set FCODES = /usr/lib/find/find.codes	# the database 
E 3

set path = ( $LIBDIR /usr/ucb /bin /usr/bin )
set bigrams = /tmp/f.bigrams$$
set filelist = /tmp/f.list$$
set errs = /tmp/f.errs$$

# Make a file list and compute common bigrams.
# Alphabetize '/' before any other char with 'tr'.
# If the system is very short of sort space, 'bigram' can be made
# smarter to accumulate common bigrams directly without sorting
# ('awk', with its associative memory capacity, can do this in several
# lines, but is too slow, and runs out of string space on small machines).

nice +10
D 3
find / -print | tr '/' '\001' | \
E 3
I 3
find ${SRCHPATHS} -print | tr '/' '\001' | \
E 3
   (sort -f; echo $status > $errs) | \
D 6
   tr '\001' '/' | tee $filelist | $LIBDIR/bigram | \
E 6
I 6
   tr '\001' '/' >$filelist
$LIBDIR/bigram <$filelist | \
E 6
   (sort; echo $status >> $errs) | uniq -c | sort -nr | \
   awk '{ if (NR <= 128) print $2 }' | tr -d '\012' > $bigrams

# code the file list

if { grep -s -v 0 $errs } then
	echo 'squeeze error: out of sort space' | mail $FINDHONCHO
else
	$LIBDIR/code $bigrams < $filelist > $FCODES
I 5
	chmod 644 $FCODES
E 5
	rm $bigrams $filelist $errs
endif
E 1
