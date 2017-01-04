h46998
s 00011/00011/00082
d D 1.2 85/07/29 13:13:04 sam 2 1
c reverse order of mtpr args to promote vax compatibility
e
s 00093/00000/00000
d D 1.1 85/07/21 20:20:54 sam 1 0
c date and time created 85/07/21 20:20:54 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

D 2
#include "../machine/mtpr.h"
E 2
I 2
#include "../tahoe/mtpr.h"
E 2

spl0()
{
	register int oldipl;

	oldipl = mfpr(IPL);
D 2
	mtpr(0, IPL);
E 2
I 2
	mtpr(IPL, 0);
E 2
	return (oldipl);
}

spl1()
{
	register int oldipl;

	oldipl = mfpr(IPL);
D 2
	mtpr(1, IPL);
E 2
I 2
	mtpr(IPL, 1);
E 2
	return (oldipl);
}

splnet()
{
	register int oldipl;

	oldipl = mfpr(IPL);
D 2
	mtpr(0xC, IPL);
E 2
I 2
	mtpr(IPL, 0xC);
E 2
	return (oldipl);
}

spl8()
{
	register int oldipl;

	oldipl = mfpr(IPL);
D 2
	mtpr(0x10+8, IPL);
E 2
I 2
	mtpr(IPL, 0x10+8);
E 2
	return (oldipl);
}

#ifdef notdef	/* use splx() instead */
spl5()
{
	register int oldipl;

	oldipl = mfpr(IPL);
D 2
	mtpr(0x10+5, IPL);
E 2
I 2
	mtpr(IPL, 0x10+5);
E 2
	return (oldipl);
}

spl4()
{
	register int oldipl;

	oldipl = mfpr(IPL);
D 2
	mtpr(0x10+4, IPL);
E 2
I 2
	mtpr(IPL, 0x10+4);
E 2
	return (oldipl);
}

spl6()
{
	register int oldipl;

	oldipl = mfpr(IPL);
D 2
	mtpr(0x10+6, IPL);
E 2
I 2
	mtpr(IPL, 0x10+6);
E 2
	return (oldipl);
}
#endif

splimp()
{
	register int oldipl;

	oldipl = mfpr(IPL);
D 2
	mtpr(0x10+8, IPL);
E 2
I 2
	mtpr(IPL, 0x10+8);
E 2
	return (oldipl);
}

splsoftclock()
{
	register int oldipl;

	oldipl = mfpr(IPL);
D 2
	mtpr(8, IPL);
E 2
I 2
	mtpr(IPL, 8);
E 2
	return (oldipl);
}

splx(oldipl)
	int oldipl;
{

D 2
	mtpr(oldipl, IPL);
E 2
I 2
	mtpr(IPL, oldipl);
E 2
}
E 1
