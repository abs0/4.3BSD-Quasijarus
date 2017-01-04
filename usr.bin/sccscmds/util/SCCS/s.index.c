h59000
s 00042/00000/00000
d D 5.1 01/05/27 20:24:09 msokolov 1 0
c taken from the Ultrix-32 V4.20 version of SCCS, needed for the new prs
e
u
U
t
T
I 1
#ifndef lint
static	char	*sccsid = "%W%	(Berkeley)	%G%";
#endif lint

/*
	If `s2' is a substring of `s1' return the offset of the first
	occurrence of `s2' in `s1',
	else return -1.
*/

/**********************************************************************
 *
 * 3Jul82
 *	Name conflict in 4.1BSD on 'index'.  Library dependence is made
 *	explicit.
 *						--jmcg
 *
 *********************************************************************/

libPW_index(as1,as2)
char *as1,*as2;
{
	register char *s1,*s2,c;
	int offset;

	s1 = as1;
	s2 = as2;
	c = *s2;

	while (*s1)
		if (*s1++ == c) {
			offset = s1 - as1 - 1;
			s2++;
			while ((c = *s2++) == *s1++ && c) ;
			if (c == 0)
				return(offset);
			s1 = offset + as1 + 1;
			s2 = as2;
			c = *s2;
		}
	 return(-1);
}
E 1
