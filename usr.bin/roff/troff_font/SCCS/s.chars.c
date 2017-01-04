h36045
s 00026/00000/00000
d D 4.1 82/06/07 15:52:09 rrh 1 0
c date and time created 82/06/07 15:52:09 by rrh
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif lint

extern char codetab[];
extern int chtab[];

main(){
	register i,j,k;

	for(i=040; i<(256); i++){
		j = codetab[i-040] & 0377;
		if(j & 0200)for(k=0; chtab[k] != 0; k =+ 2){
			if(chtab[k+1] == i){
				printf("%o \\(%c%c\n",
					j,
					chtab[k] & 0377,
					chtab[k]>>8 & 0377);
				break;
			}else if(i < 0177){
				printf("%o %c\n",j,i & 0177);
				break;
			}
		}
	}
}
E 1
