" ex script for fixing book covers
"	@(#)fixcover.ex	5.1 (Berkeley) 04/10/22
/^%%Pages: (atend)$/c
%%DocumentNeededResources: font Times-Roman Times-Italic Times-Bold Symbol
.
mark a
/^%%Pages:/m 'a
wq
