h39623
s 00002/00001/00009
d D 1.2 88/02/02 15:56:53 bostic 2 1
c sprintf doesn't return a pointer to it's first arg, anymore
e
s 00010/00000/00000
d D 1.1 88/02/02 15:42:30 bostic 1 0
c date and time created 88/02/02 15:42:30 by bostic
e
u
U
t
T
I 1
# include	"../hdr/defines.h"

SCCSID(@(#)fmterr	2.1);

fmterr(pkt)
register struct packet *pkt;
{
	fclose(pkt->p_iop);
D 2
	fatal(sprintf(Error,"format error at line %u (co4)",pkt->p_slnno));
E 2
I 2
	sprintf(Error,"format error at line %u (co4)",pkt->p_slnno);
	fatal(Error);
E 2
}
E 1
