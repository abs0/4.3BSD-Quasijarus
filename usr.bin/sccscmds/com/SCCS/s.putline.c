h40204
s 00005/00005/00087
d D 1.2 87/02/15 16:42:34 lepreau 2 1
c modern syntax for asgops & inits; sccs keywords
e
s 00092/00000/00000
d D 1.1 85/05/03 12:36:28 sam 1 0
c date and time created 85/05/03 12:36:28 by sam
e
u
U
t
T
I 1
# include	"../hdr/defines.h"

D 2
SCCSID(@(#)putline	2.1.1.1);
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Routine to write out either the current line in the packet
	(if newline is zero) or the line specified by newline.
	A line is actually written (and the x-file is only
	opened) if pkt->p_upd is non-zero.  When the current line from 
	the packet is written, pkt->p_wrttn is set non-zero, and
	further attempts to write it are ignored.  When a line is
	read into the packet, pkt->p_wrttn must be turned off.
*/

int	Xcreate;
FILE	*Xiop;


putline(pkt,newline)
register struct packet *pkt;
char *newline;
{
	static char obf[BUFSIZ];
	char *xf;
	register char *p;

	if(pkt->p_upd == 0) return;

	if(!Xcreate) {
		stat(pkt->p_file,&Statbuf);
		xf = auxf(pkt->p_file,'x');
		Xiop = xfcreat(xf,Statbuf.st_mode);
		setbuf(Xiop,obf);
		chown(xf,Statbuf.st_uid,Statbuf.st_gid);
	}
	if (newline)
		p = newline;
	else {
		if(!pkt->p_wrttn++)
			p = pkt->p_line;
		else
			p = 0;
	}
	if (p) {
		fputs(p,Xiop);
		if (Xcreate)
			while (*p)
D 2
				pkt->p_nhash =+ *p++;
E 2
I 2
				pkt->p_nhash += *p++;
E 2
	}
	Xcreate = 1;
}


flushline(pkt,stats)
register struct packet *pkt;
register struct stats *stats;
{
	register char *p;
	char ins[6], del[6], unc[6], hash[6];

	if (pkt->p_upd == 0)
		return;
	putline(pkt,0);
	rewind(Xiop);

	if (stats) {
		sprintf(ins,"%05u",stats->s_ins);
		sprintf(del,"%05u",stats->s_del);
		sprintf(unc,"%05u",stats->s_unc);
		for (p = ins; *p; p++)
D 2
			pkt->p_nhash =+ (*p - '0');
E 2
I 2
			pkt->p_nhash += (*p - '0');
E 2
		for (p = del; *p; p++)
D 2
			pkt->p_nhash =+ (*p - '0');
E 2
I 2
			pkt->p_nhash += (*p - '0');
E 2
		for (p = unc; *p; p++)
D 2
			pkt->p_nhash =+ (*p - '0');
E 2
I 2
			pkt->p_nhash += (*p - '0');
E 2
	}

	sprintf(hash,"%5u",pkt->p_nhash&0xFFFF);
	zeropad(hash);
	fprintf(Xiop,"%c%c%s\n",CTLCHAR,HEAD,hash);
	if (stats)
		fprintf(Xiop,"%c%c %s/%s/%s\n",CTLCHAR,STATS,ins,del,unc);
	fclose(Xiop);
}


xrm(pkt)
struct packet *pkt;
{
	if (Xiop)
		fclose(Xiop);
	Xiop = Xcreate = 0;
}
E 1
