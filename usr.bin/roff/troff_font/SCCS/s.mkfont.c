h35155
s 00002/00002/00105
d D 4.3 88/02/16 09:01:59 bostic 3 2
c GNU fixes for multi char constants
e
s 00001/00001/00106
d D 4.2 87/09/11 08:17:18 bostic 2 1
c get rid of old assignment operator
e
s 00107/00000/00000
d D 4.1 82/06/07 15:53:05 rrh 1 0
c date and time created 82/06/07 15:53:05 by rrh
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif lint

#include "mkfont1.c"

/*
  this program takes 102 width values
  (one per line) in the order provided bu Graphic
  Systems and prepares a C-compileable width table.
*/
char ibuf[512];
int id;
int width[102];
int ascii[102];
int zero;
int emw, hyw;
int xxx;

main(argc,argv)
int argc;
char **argv;
{
	register i, j;
	register char *p;

	while((--argc > 0) && ((++argv)[0][0]=='-')){
		switch(argv[0][1]){
			default:
				continue;
		}
	}
	if(argc){
		if((id=open(argv[0],0)) < 0){
			printf("Cannot open: %s.\n",argv[0]);
			exit(1);
		}
	}
	j = read(id,ibuf,512);
	p = ibuf;
	for(i=0; i<102; i++){
		width[i] = atoi(p);
		while(*p++ != '\n');
	}
	for(i=0; i<102; i++){
		if(font[i].name < 0177){
			ascii[i] = font[i].name;
		}else{
D 2
			for(j=0; chtab[j] != 0; j =+ 2){
E 2
I 2
			for(j=0; chtab[j] != 0; j += 2){
E 2
				if(font[i].name == chtab[j])break;
			}
			ascii[i] = chtab[j+1] & 0377;
D 3
			if(chtab[j] == 'hy')hyw = width[i];
			if(chtab[j] == 'em')emw = width[i];
E 3
I 3
			if(chtab[j] == PAIR('h','y')) hyw = width[i];
			if(chtab[j] == PAIR('e','m')) emw = width[i];
E 3
		}
	}
	printf("char XXw[256-32] {\t/*XX*/\n");
	for(i=040; i<256; i++){
		if(i == 0377){
			printf("0};\n");
			break;
		}
		if(i == 0177){
			printf("6,\t %s\n",nametab[i-040]);
			continue;
		}
		if(i == 0226){
			printf("3,\t %s\n",nametab[i-040]);
			continue;
		}
		if(i == ' '){
			printf("12,\t %s\n",nametab[i-040]);
			continue;
		}
		if(i == '-'){
			printf("%d,\t %s\n",hyw,nametab[i-040]);
			continue;
		}
		for(j=0; j<102; j++){
			if(ascii[j] == i)break;
		}
		if(j == 102){
			printf("0,");
			zero++;
			if(nametab[i-040]){
				printf("\t %s\n",nametab[i-040]);
				zero = 0;
			}else if(i < 0177){
				printf("\t /*%c*/\n",i);
				zero = 0;
			}
			if(zero && !((i+1)%8)){
				printf("\n");
				zero = 0;
			}
		}else{
			if(zero){
				zero = 0;
				printf("\n");
			}
			printf("%d",width[j]);
			if(font[j].ctval)printf("+0%d00, ",font[j].ctval);
			else printf(",\t ");
			printf("%s\n",nametab[i-040]);
		}
	}
}
E 1
