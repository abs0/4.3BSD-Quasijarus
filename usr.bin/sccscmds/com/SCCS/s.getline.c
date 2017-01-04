h29109
s 00002/00002/00043
d D 1.2 87/02/15 16:42:29 lepreau 2 1
c modern syntax for asgops & inits; sccs keywords
e
s 00045/00000/00000
d D 1.1 87/02/15 16:36:03 lepreau 1 0
c date and time created 87/02/15 16:36:03 by lepreau
e
u
U
t
T
I 1
#include	"../hdr/defines.h"

D 2
SCCSID(@(#)getline	2.1.1.1);
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Routine to read a line into the packet.  The main reason for
	it is to make sure that pkt->p_wrttn gets turned off,
	and to increment pkt->p_slnno.
*/

getline(pkt)
register struct packet *pkt;
{
	register int n;
	register char *p;

	if(pkt->p_wrttn==0)
		putline(pkt,0);
	if ((n = fgets(pkt->p_line,sizeof(pkt->p_line),pkt->p_iop)) != NULL) {
		pkt->p_slnno++;
		pkt->p_wrttn = 0;
		for (p = pkt->p_line; *p; )
D 2
			pkt->p_chash =+ *p++;
E 2
I 2
			pkt->p_chash += *p++;
E 2
	}
	else {
		if (!pkt->p_reopen) {
			fclose(pkt->p_iop);
			pkt->p_iop = 0;
		}
		if (!pkt->p_chkeof)
			fatal("premature eof (co5)");
		if (pkt->do_chksum && (pkt->p_chash ^ pkt->p_ihash)&0xFFFF)
			fatal("corrupted file (co6)");
		if (pkt->p_reopen) {
			fseek(pkt->p_iop,0L,0);
			pkt->p_reopen = 0;
			pkt->p_slnno = 0;
			pkt->p_ihash = 0;
			pkt->p_chash = 0;
			pkt->p_nhash = 0;
			pkt->p_keep = 0;
			pkt->do_chksum = 0;
		}
	}
	return(n);
}
E 1
