h01874
s 00004/00002/00130
d D 4.3 85/01/25 17:08:31 ralph 3 2
c wait for makekey to finish before reading from pipe.
e
s 00044/00004/00088
d D 4.2 81/07/09 00:30:26 mckusic 2 1
c add -s flag for increased security
e
s 00092/00000/00000
d D 4.1 80/10/01 17:25:55 bill 1 0
c date and time created 80/10/01 17:25:55 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
I 2

E 2
/*
 *	A one-rotor machine designed along the lines of Enigma
 *	but considerably trivialized.
 */

#define ECHO 010
#include <stdio.h>
#define ROTORSZ 256
#define MASK 0377
char	t1[ROTORSZ];
char	t2[ROTORSZ];
char	t3[ROTORSZ];
I 2
char	deck[ROTORSZ];
E 2
char	*getpass();
I 2
char	buf[13];
E 2

setup(pw)
char *pw;
{
	int ic, i, k, temp, pf[2];
I 3
	int pid, wpid;
E 3
	unsigned random;
D 2
	char buf[13];
E 2
	long seed;

	strncpy(buf, pw, 8);
	while (*pw)
		*pw++ = '\0';
	buf[8] = buf[0];
	buf[9] = buf[1];
	pipe(pf);
D 3
	if (fork()==0) {
E 3
I 3
	if ((pid=fork())==0) {
E 3
		close(0);
		close(1);
		dup(pf[0]);
		dup(pf[1]);
		execl("/usr/lib/makekey", "-", 0);
		execl("/lib/makekey", "-", 0);
		exit(1);
	}
	write(pf[1], buf, 10);
D 3
	wait((int *)NULL);
E 3
I 3
	while ((wpid = wait((int *)NULL)) != -1 && wpid != pid)
	    ;
E 3
	if (read(pf[0], buf, 13) != 13) {
		fprintf(stderr, "crypt: cannot generate key\n");
		exit(1);
	}
	seed = 123;
	for (i=0; i<13; i++)
		seed = seed*buf[i] + i;
D 2
	for(i=0;i<ROTORSZ;i++)
E 2
I 2
	for(i=0;i<ROTORSZ;i++) {
E 2
		t1[i] = i;
I 2
		deck[i] = i;
	}
E 2
	for(i=0;i<ROTORSZ;i++) {
		seed = 5*seed + buf[i%13];
		random = seed % 65521;
		k = ROTORSZ-1 - i;
		ic = (random&MASK)%(k+1);
		random >>= 8;
		temp = t1[k];
		t1[k] = t1[ic];
		t1[ic] = temp;
		if(t3[k]!=0) continue;
		ic = (random&MASK) % k;
		while(t3[ic]!=0) ic = (ic+1) % k;
		t3[k] = ic;
		t3[ic] = k;
	}
	for(i=0;i<ROTORSZ;i++)
		t2[t1[i]&MASK] = i;
}

main(argc, argv)
char *argv[];
{
D 2
	register i, n1, n2;
E 2
I 2
	register i, n1, n2, nr1, nr2;
	int secureflg = 0;
E 2

I 2
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 's') {
		argc--;
		argv++;
		secureflg = 1;
	}
E 2
	if (argc != 2){
		setup(getpass("Enter key:"));
	}
	else
		setup(argv[1]);
	n1 = 0;
	n2 = 0;
I 2
	nr2 = 0;
E 2

	while((i=getchar()) >=0) {
D 2
		i = t2[(t3[(t1[(i+n1)&MASK]+n2)&MASK]-n2)&MASK]-n1;
E 2
I 2
		if (secureflg) {
			nr1 = deck[n1]&MASK;
			nr2 = deck[nr1]&MASK;
		} else {
			nr1 = n1;
		}
		i = t2[(t3[(t1[(i+nr1)&MASK]+nr2)&MASK]-nr2)&MASK]-nr1;
E 2
		putchar(i);
		n1++;
		if(n1==ROTORSZ) {
			n1 = 0;
			n2++;
			if(n2==ROTORSZ) n2 = 0;
I 2
			if (secureflg) {
				shuffle(deck);
			} else {
				nr2 = n2;
			}
E 2
		}
I 2
	}
}

shuffle(deck)
	char deck[];
{
	int i, ic, k, temp;
	unsigned random;
	static long seed = 123;

	for(i=0;i<ROTORSZ;i++) {
		seed = 5*seed + buf[i%13];
		random = seed % 65521;
		k = ROTORSZ-1 - i;
		ic = (random&MASK)%(k+1);
		temp = deck[k];
		deck[k] = deck[ic];
		deck[ic] = temp;
E 2
	}
}
E 1
