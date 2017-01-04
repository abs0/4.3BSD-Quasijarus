h11175
s 00044/00000/00000
d D 4.1 82/12/18 15:10:34 sam 1 0
c date and time created 82/12/18 15:10:34 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif

#include "spell.h"
/* add entries to hash table for use by spell
   preexisting hash table is first argument
   words to be added are standard input
   if no hash table is given, create one from scratch
*/

main(argc,argv)
char **argv;
{
	register i, j;
	long h;
	register long *lp;
	char word[NW];
	register char *wp;

	if(!prime(argc,argv)) {
		fprintf(stderr,
		    "spellin: cannot initialize hash table\n");
		exit(1);
	}
	while (fgets(word, sizeof(word), stdin)) {
		for (i=0; i<NP; i++) {
			for (wp = word, h = 0, lp = pow2[i];
				 (j = *wp) != '\0'; ++wp, ++lp)
				h += j * *lp;
			h %= p[i];
			set(h);
		}
	}
#ifdef gcos
	freopen((char *)NULL, "wi", stdout);
#endif
	if (fwrite((char *)tab, sizeof(*tab), TABSIZE, stdout) != TABSIZE) {
		fprintf(stderr,
		    "spellin: trouble writing hash table\n");
		exit(1);
	}
	return(0);
}
E 1
