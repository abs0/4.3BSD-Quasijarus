h33131
s 00000/00000/00019
d D 2.1 81/07/01 11:09:08 kurt 2 1
c Release to Heidi Stettner
e
s 00019/00000/00000
d D 1.1 80/10/08 09:50:15 kas 1 0
c date and time created 80/10/08 09:50:15 by kas
e
u
U
f b 
t
T
I 1
/*
 * Determine the leftmost index of the character
 * in the string.
 */

static char *SccsId = "%W% %G%";

char *
index(str, ch)
	char *str;
{
	register char *cp;
	register int c;

	for (c = ch, cp = str; *cp; cp++)
		if (*cp == c)
			return(cp);
	return(NOSTR);
}
E 1
