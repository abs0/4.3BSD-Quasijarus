h15555
s 00001/00001/00037
d D 1.2 85/05/04 00:31:43 sam 2 1
c purge old crud
e
s 00038/00000/00000
d D 1.1 85/05/03 12:36:31 sam 1 0
c date and time created 85/05/03 12:36:31 by sam
e
u
U
t
T
I 1
# include	"../hdr/defines.h"

SCCSID(@(#)sinit	2.1);
/*
	Does initialization for sccs files and packet.
*/

sinit(pkt,file,openflag)
register struct packet *pkt;
register char *file;
{
	extern	char	*satoi();
	register char *p;

D 2
	zero(pkt,sizeof(*pkt));
E 2
I 2
	bzero(pkt,sizeof(*pkt));
E 2
	if (size(file) > FILESIZE)
		fatal("too long (co7)");
	if (!sccsfile(file))
		fatal("not an SCCS file (co1)");
	copy(file,pkt->p_file);
	pkt->p_wrttn = 1;
	pkt->do_chksum = 1;	/* turn on checksum check for getline */
	if (openflag) {
		pkt->p_iop = xfopen(file,0);
		setbuf(pkt->p_iop,pkt->p_buf);
		fstat(fileno(pkt->p_iop),&Statbuf);
		if (Statbuf.st_nlink > 1)
			fatal("more than one link (co3)");
		if ((p = getline(pkt)) == NULL || *p++ != CTLCHAR || *p++ != HEAD) {
			fclose(pkt->p_iop);
			fmterr(pkt);
		}
		p = satoi(p,&pkt->p_ihash);
		if (*p != '\n')
			fmterr(pkt);
	}
	pkt->p_chash = 0;
}
E 1
