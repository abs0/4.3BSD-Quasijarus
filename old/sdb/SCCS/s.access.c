h46242
s 00000/00000/00161
d D 4.2 82/08/17 13:24:15 rrh 2 1
c Changed the data types for the sdb class characters to be unsigned
c characters; this fixed a bug that prevented the arguments to a function
c from being printed symbolically.  The fix was done globally; it is not
c known if the "fix" fixed other bugs
e
s 00161/00000/00000
d D 4.1 80/10/09 23:57:05 bill 1 0
c date and time created 80/10/09 23:57:05 by bill
e
u
U
t
T
I 1
static	char sccsid[] = "%Z%%M% %I% %G%";
#
/*
 *
 *	UNIX debugger
 *
 */

#include "head.h"
struct user u;


MSG		BADDAT;
MSG		BADTXT;
MAP		txtmap;
MAP		datmap;
STRING		errflg;
int		errno;

INT		pid;




/* file handling and access routines */

int dmask[5] = {0, 0xff, 0xffff, 0xffffff, 0xffffffff};

/* get data at loc using descriptor format d */
long
getval(loc, d, space)
ADDR loc;
char d; {
	register int val;
	
	val = get(loc, space);
	val &= dmask[dtol(d)];
	return(val);
}

/* put value at loc using descriptor format d */
putval(loc, d, value)
ADDR loc; char d; long value; {
	register long val;
	
	val = get(loc, DSP);
	val = (val & !dmask[dtol(d)]) | (value & dmask[dtol(d)]);
	put(loc, DSP, val);
}

/* put value in named register using descriptor format d */
putreg(reg, d, value)
ADDR reg; char d; long value; {
	register long val;
	
	val = *(ADDR *)(((ADDR)&u)+R0+WORDSIZE*reg);
	val = (val & !dmask[dtol(d)]) | (value & dmask[dtol(d)]);
	*(ADDR *)(((ADDR)&u)+R0+WORDSIZE*reg) = val;
}

put(adr,space,value)
L_INT	adr;
{
	access(WT,adr,space,value);
}

POS	get(adr, space)
L_INT		adr;
{
	return(access(RD,adr,space,0));
}


access(mode,adr,space,value)
L_INT	adr;
{
	INT	pmode,rd,file;
	ADDR	w;
	if (debug) 
		printf("access(mode=%d,adr=%d,space=%d,value=%d) with pid %d\n",
			mode, adr, space, value, pid);
	rd = mode==RD;

	IF space == NSP THEN return(0); FI

	IF pid		/* tracing on? */
	THEN
#ifndef vax
		IF adr&01 ANDF !rd THEN error(ODDADR); FI
#endif
	     pmode = (space&DSP?(rd?RDUSER:WDUSER):(rd?RIUSER:WIUSER));
	     w = ptrace(pmode, pid, adr, value);
	     if (debug)
		printf("ptrace(%d,%d,%d,%d) = %d with error=%d\n",
			pmode, pid, adr, value, w, errno);
#ifndef vax
	     IF adr&01
	     THEN w1 = ptrace(pmode, pid, shorten(adr+1), value);
		  w = (w>>8)&LOBYTE | (w1<<8);
	     FI
#endif
	     IF errno
	     THEN errflg = (space&DSP ? BADDAT : BADTXT);
	     FI
	     return(w);
	FI
	w = 0;
	IF !chkmap(&adr,space)
	THEN return(0);
	FI
	file=(space&DSP?datmap.ufd:txtmap.ufd);
	if (longseek(file,adr)==0 ||
	   (rd ? read(file,&w,sizeof(w)) : write(file,&value,sizeof(w))) < 1)
		errflg=(space&DSP?BADDAT:BADTXT);
	return(w);

}

chkmap(adr,space)
	REG L_INT	*adr;
	REG INT		space;
{
	REG MAPPTR amap;
	amap=((space&DSP?&datmap:&txtmap));
	IF space&STAR ORF !within(*adr,amap->b1,amap->e1)
	THEN if (within(*adr,amap->b2,amap->e2))
		*adr += (amap->f2)-(amap->b2);
	     else {
		errflg=(space&DSP?BADDAT:BADTXT); return(0);
	     }
	ELSE *adr += (amap->f1)-(amap->b1);
	FI
	return(1);
}

within(adr,lbd,ubd)
POS	adr, lbd, ubd;
{
	return(adr>=lbd && adr<ubd);
}

/* ------------ */
POS	chkget(n, space)
L_INT		n;
{
#ifndef vax
	REG INT		w;
#else
	REG L_INT	w;
#endif

	w = get(n, space);
	chkerr();
	return(w);
}

POS bchkget(n, space) 
L_INT	n;
{
	return(chkget(n, space) & LOBYTE);
}
E 1
