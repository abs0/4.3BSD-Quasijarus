h47679
s 00002/00002/00012
d D 1.2 88/02/02 15:56:54 bostic 2 1
c sprintf doesn't return a pointer to it's first arg, anymore
e
s 00014/00000/00000
d D 1.1 88/02/02 15:43:40 bostic 1 0
c date and time created 88/02/02 15:43:40 by bostic
e
u
U
t
T
I 1
# include	"../hdr/defines.h"

SCCSID(@(#)newstats	2.1);

newstats(pkt,strp,ch)
register struct packet *pkt;
register char *strp;
register char *ch;
{
	char fivech[6];
	repeat(fivech,ch,5);
D 2
	putline(pkt,sprintf(strp,"%c%c %s/%s/%s\n",CTLCHAR,STATS,
					fivech,fivech,fivech),0);
E 2
I 2
	sprintf(strp,"%c%c %s/%s/%s\n",CTLCHAR,STATS,fivech,fivech,fivech);
	putline(pkt,strp);
E 2
}
E 1
