h09211
s 00000/00032/00112
d D 1.3 88/05/31 08:45:05 karels 3 2
c get rid of private blk* routines, use (faster) libc versions
e
s 00024/00025/00120
d D 1.2 87/11/23 15:29:04 karels 2 1
c working again, I think
e
s 00145/00000/00000
d D 1.1 86/07/05 17:37:43 sam 1 0
c date and time created 86/07/05 17:37:43 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley/CCI) %G%";
#endif

#include	"vdfmt.h"
#include	"cmd.h"

/*
*/

to_track(daddr)
dskadr	daddr;
{
D 2
	return ((daddr.cylinder * CURRENT->vc_ntrak) + daddr.track);
E 2
I 2
	return ((daddr.cylinder * lab->d_ntracks) + daddr.track);
E 2
}


/*
*/

dskadr *from_track(trk)
int	trk;
{
	static dskadr	temp;

D 2
	temp.cylinder = trk / CURRENT->vc_ntrak;
	temp.track = trk % CURRENT->vc_ntrak;
E 2
I 2
	temp.cylinder = trk / lab->d_ntracks;
	temp.track = trk % lab->d_ntracks;
E 2
	temp.sector = 0;
	return &temp;
}


/*
*/

to_sector(daddr)
dskadr	daddr;
{
D 2
	return ((to_track(daddr) * CURRENT->vc_nsec) + daddr.sector);
E 2
I 2
	return ((to_track(daddr) * lab->d_nsectors) + daddr.sector);
E 2
}


/*
*/

dskadr *from_sector(sec)
unsigned int	sec;
{
	static dskadr	temp;

D 2
	temp = *from_track((int)(sec / CURRENT->vc_nsec));
	temp.sector = sec % CURRENT->vc_nsec;
E 2
I 2
	temp = *from_track((int)(sec / lab->d_nsectors));
	temp.sector = sec % lab->d_nsectors;
E 2
	return &temp;
}


/*
**
*/

print_unix_block(dskaddr)
dskadr	dskaddr;
{
	char	fs;
	int	blk;
D 2
	int	sec_per_blk=DEV_BSIZE / SECSIZ;
E 2
I 2
	register struct partition *pp;
E 2
			
	indent();
D 2
	blk = to_sector(dskaddr) / sec_per_blk;
E 2
I 2
	blk = to_sector(dskaddr);
E 2
	print("** Warning - Unable to relocate sector %d:\n",to_sector(dskaddr)); 
D 2
#ifdef notdef
E 2
	indent();
	print("to map out using BADSECT use the following values:\n");
	indent();
D 2
	for(fs = 0; fs < 8; fs++) {
E 2
I 2
	for(fs = 0; fs < lab->d_npartitions; fs++) {
E 2
		int	s, l;

D 2
		s = CURRENT->partition[fs].par_start;
		l = CURRENT->partition[fs].par_len;
E 2
I 2
		pp = &lab->d_partitions[fs];
		s = pp->p_offset;
		l = pp->p_size;
		if (pp->p_fsize == 0)
			pp->p_fsize = DEV_BSIZE;
E 2
		if((blk < (s+l)) && (blk >= s)) {
D 2
			print("On the '%c' Partition use block %d.\n",
			    fs+'a', blk-s);
E 2
I 2
			print("On the `%c' Partition use filesystem block %d.\n",
			    fs+'a', (blk - s) * lab->d_secsize / pp->p_fsize);
E 2
		}
	}
D 2
#endif
E 2
	exdent(3);
}

dskadr	*from_unix(par, block)
unsigned char	par;
unsigned int	block;
{
	unsigned int	sector;
	register int	fs;
I 2
	register struct partition *pp;
E 2
	static dskadr		dskaddr;

D 2
#ifdef notdef
E 2
	fs =  tolower(par) - 'a';
D 2
	if((fs < 8) && (block <= CURRENT->partition[fs].par_len))
		dskaddr = *from_sector(
		    (CURRENT->partition[fs].par_start + block) *
		     DEV_BSIZE/SECSIZE);
	else {
#endif
E 2
I 2
	if((fs < lab->d_npartitions) &&
	    (block <= (pp = &lab->d_partitions[fs])->p_size)) {
		if (pp->p_fsize == 0)
			pp->p_fsize = DEV_BSIZE;
		dskaddr = *from_sector(pp->p_offset +
		    block * pp->p_fsize / lab->d_secsize);
	} else {
E 2
		dskaddr.cylinder = -1;
		dskaddr.track = -1;
		dskaddr.sector = -1;
D 2
#ifdef notdef
E 2
	}
D 2
#endif
E 2
	return &dskaddr;
}
D 3


blkzero(addr, len)
register char	*addr;
register int	len;
{
	while(len--)
		*(addr++) = (char)0;
}


blkcopy(from, to, len)
register char	*from;
register char	*to;
register int	len;
{
	while(len--)
		*(to++) = *(from++);
}


boolean blkcmp(a, b, len)
register char	*a;
register char	*b;
register int	len;
{
	while(len--) {
		if(*(a++) != *(b++))
			return false;
	}
	return true;
}
E 3
D 2

E 2
E 1
