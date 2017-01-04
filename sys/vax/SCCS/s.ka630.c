h54247
s 00008/00034/00127
d D 7.9 04/03/18 19:26:43 msokolov 10 9
c a lot of crud went away thanks to generalisation
e
s 00001/00002/00160
d D 7.8 04/02/06 21:59:06 msokolov 9 8
c contrary to BSD and Ultrix cpu.h files MicroVAX II SID does NOT have
c hardware rev or ucode rev fields
e
s 00002/00001/00160
d D 7.7 04/01/03 18:11:23 msokolov 8 7
c new CPU ID logic
c move printing of "MicroVAX ..." banner to cpu_init routines in ka6??.c
e
s 00004/00003/00157
d D 7.6 88/11/08 17:35:28 tef 7 6
c avoid null pointer on machine check printf's
e
s 00004/00000/00156
d D 7.5 88/07/09 14:11:41 karels 6 5
c update copyrights
e
s 00112/00088/00044
d D 7.4 88/05/07 14:19:27 karels 5 4
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00004/00000/00128
d D 7.3 87/01/19 16:25:00 karels 4 3
c can't reset it if not set up
e
s 00005/00007/00123
d D 7.2 86/08/09 15:30:26 karels 3 2
c cleanups
e
s 00000/00000/00130
d D 7.1 86/06/05 00:44:14 mckusick 2 1
c 4.3BSD release version
e
s 00130/00000/00000
d D 6.1 86/04/22 11:30:59 kridle 1 0
c MicroVAX II Integration (KA630)
e
u
U
t
T
I 1
/*
I 6
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
E 6
 *	%W% (Berkeley) %G%
 */
D 5
#if defined(VAX630)
/* ka630.c routines for the ka630 clock chip... */
E 5
I 5

#ifdef VAX630
E 5
#include "param.h"
#include "time.h"
#include "kernel.h"
#include "vmmac.h"

#include "mtpr.h"
#include "cpu.h"
#include "clock.h"
#include "pte.h"
I 10
#include "78032.h"
E 10
#include "ka630.h"

/*
D 5
 * These two fuctions handle the tod clock
 * This code is defunct at the end of the century.
 * Will Unix still be here then??
E 5
I 5
 * 630-specific routines
E 5
 */
I 5
extern struct pte Clockmap[];
extern struct pte Ka630map[];
struct ka630clock ka630clock;
struct ka630cpu ka630cpu;
E 5

D 3
struct cldevice cldevice;
struct ka630cpu ka630cpu;
E 3
I 3
D 5
extern struct cldevice cldevice;
extern struct ka630cpu ka630cpu;
I 4
static int clkinit;
E 4
E 3

short dayyr[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, };
/* Starts the tod clock. Called from clkstart... */
ka630tod(base)
	time_t base;
E 5
I 5
ka630_init()
E 5
{
D 5
	register int tmp1, tmp2;
D 3
	struct pte *pte = &Clockmap[0];
E 3
	register struct cldevice *claddr = &cldevice;
	struct ka630cpu *ka630addr = &ka630cpu;
E 5
D 8

E 8
I 8
D 9
	printf("MicroVAX II (KA630), chip rev %d, ucode rev %d\n",
		cpusid.cpu_uv2.cp_hrev, cpusid.cpu_uv2.cp_urev);
E 9
I 9
	printf("MicroVAX II (KA630)\n");
E 9
E 8
D 5
	/* Enable system page for registers */
D 3
	*(int *)pte = PG_V|PG_KW|btop(0x200b8000);
	pte = &Ka630map[0];
	*(int *)pte = PG_V|PG_KW|btop(0x20080000);
	mtpr(TBIA, 0);
E 3
I 3
	ioaccess(0x200b8000, &Clockmap[0], sizeof(struct cldevice));
	ioaccess(0x20080000, &Ka630map[0], sizeof(struct ka630cpu));
I 4
	clkinit = 1;
E 5
I 5
	/*
	 * Map in the clock and the CPU.
	 */
	ioaccess((caddr_t)0x200b8000, &Clockmap[0], sizeof(struct ka630clock));
	ioaccess((caddr_t)0x20080000, &Ka630map[0], sizeof(struct ka630cpu));
E 5
E 4

E 3
	/*
D 5
	 * Clear restart and boot in progress flags in the CPMBX. This has
	 * nothing to do with the clock except that it the CPMBX reg. is a
	 * byte in the clock's ram.
E 5
I 5
D 10
	 * Clear restart and boot in progress flags in the CPMBX.
E 5
	 */
D 5
	claddr->cpmbx=(u_short)((claddr->cpmbx&KA630CLK_LANG)|KA630CLK_REBOOT);
E 5
I 5
	ka630clock.cpmbx = (ka630clock.cpmbx & KA630CLK_LANG) | KA630CLK_REBOOT;

E 5
	/*
E 10
D 5
	 * Enable memory parity error detection. again nothing to do with the
	 * tod clock except for being a convenient place.
E 5
I 5
	 * Enable memory parity error detection.
E 5
	 */
D 5
	ka630addr->ka630_mser = KA630MSER_PAREN;
E 5
I 5
	ka630cpu.ka630_mser = KA630MSER_PAREN;
}

D 10
/* Start the real-time clock */
ka630_clkstartrt()
{

	mtpr(ICCS, ICCS_IE);
}

E 10
/* init system time from tod clock */
/* ARGSUSED */
ka630_clkread(base)
	time_t base;
{
	register struct ka630clock *claddr = &ka630clock;
	struct chiptime c;

E 5
	claddr->csr1 = KA630CLK_SET;
	while ((claddr->csr0 & KA630CLK_UIP) != 0)
		;
	/* If the clock is valid, use it. */
	if ((claddr->csr3 & KA630CLK_VRT) != 0 &&
	    (claddr->csr1 & KA630CLK_ENABLE) == KA630CLK_ENABLE) {
D 5
		/* Convert yr,mon,day,hr,min,sec to sec past Jan.1, 1970. */
		tmp2 = 0;
		for (tmp1 = 70; tmp1 < claddr->yr; tmp1++) {
			tmp2 += 365;
			/* I just luv leap years... */
			if (LEAPYEAR(tmp1))
				tmp2++;
		}
		tmp2 += (dayyr[claddr->mon-1]+claddr->day-1);
		if (LEAPYEAR(claddr->yr) && claddr->mon > 2)
			tmp2++;
		/* Finally got days past Jan. 1,1970. the rest is easy.. */
		time.tv_sec = tmp2*SECDAY+claddr->hr*HRSEC+
			claddr->min*MINSEC+claddr->sec;
		tmp1 = claddr->csr2;
E 5
I 5
		c.sec = claddr->sec;
		c.min = claddr->min;
		c.hour = claddr->hr;
		c.day = claddr->day;
		c.mon = claddr->mon;
		c.year = claddr->yr;
#ifndef lint
		{ int t = claddr->csr2; }	/* ??? */
#endif
E 5
		claddr->csr0 = KA630CLK_RATE;
		claddr->csr1 = KA630CLK_ENABLE;
D 5
	} else if (base < 5*SECYR) {
		printf("WARNING: preposterous time in file system\n");
		time.tv_sec = 6*SECYR+186*SECDAY+SECDAY/2;
		ka630stod();
	} else {
		printf("WARNING: Time set via file system\n");
		time.tv_sec = base;
		ka630stod();
E 5
I 5

		time.tv_sec = chiptotime(&c);
		return (time.tv_sec ? CLKREAD_OK : CLKREAD_BAD);
E 5
	}
I 5
	printf("WARNING: TOY clock invalid");
	return (CLKREAD_BAD);
E 5
}
I 5

E 5
/* Set the time of day clock, called via. stime system call.. */
D 5
ka630stod()
E 5
I 5
ka630_clkwrite()
E 5
{
D 5
	register int tmp1, tmp3;
	register struct cldevice *claddr = &cldevice;
	long tmp2, tmp4;
E 5
I 5
	register struct ka630clock *claddr = &ka630clock;
	struct chiptime c;
	int s;
E 5

I 4
D 5
	if (clkinit == 0)
		return;
E 5
I 5
	timetochip(&c);
	s = splhigh();
E 5
E 4
	claddr->csr1 = KA630CLK_SET;
	while ((claddr->csr0 & KA630CLK_UIP) != 0)
		;
D 5
	/* The reverse of above, sec. past Jan. 1,1970 to yr, mon... */
	tmp2 = time.tv_sec/HRSEC;
	tmp4 = tmp2 = tmp2/24;
	tmp1 = 69;
	while (tmp2 >= 0) {
		tmp3 = tmp2;
		tmp2 -= 365;
		tmp1++;
		if (LEAPYEAR(tmp1))
			tmp2--;
	}
	/* Got the year... */
	claddr->yr = tmp1;
	tmp1 = -1;
	do {
		tmp2 = tmp3-dayyr[++tmp1];
		if (LEAPYEAR(claddr->yr) && tmp1 > 1)
			tmp2--;
	} while (tmp2 >= 0);
	/* Finally, got the rest... */
	claddr->mon = tmp1;
	claddr->day = tmp3-dayyr[tmp1-1]+1;
	if (LEAPYEAR(claddr->yr) && tmp1 > 2)
		claddr->day--;
	tmp2 = time.tv_sec-(tmp4*SECDAY);
	claddr->hr = tmp2/HRSEC;
	tmp2 = tmp2%HRSEC;
	claddr->min = tmp2/MINSEC;
	tmp2 = tmp2%MINSEC;
	claddr->sec = tmp2;
	tmp1 = claddr->csr2;
	tmp1 = claddr->csr3;
E 5
I 5
	claddr->sec = c.sec;
	claddr->min = c.min;
	claddr->hr = c.hour;
	claddr->day = c.day;
	claddr->mon = c.mon;
	claddr->yr = c.year;
#ifndef lint
	{ int t = claddr->csr2; }	/* ??? */
	{ int t = claddr->csr3; }	/* ??? */
#endif
E 5
	claddr->csr0 = KA630CLK_RATE;
	claddr->csr1 = KA630CLK_ENABLE;
I 5
	splx(s);
}

ka630_memnop()
{

	/* void */
}

D 10
#define NMC630	10
char *mc630[] = {
	0,		"immcr (fsd)",	"immcr (ssd)",	"fpu err 0",
	"fpu err 7",	"mmu st(tb)",	"mmu st(m=0)",	"pte in p0",
	"pte in p1",	"un intr id",
};

struct mc630frame {
	int	mc63_bcnt;		/* byte count == 0xc */
	int	mc63_summary;		/* summary parameter */
	int	mc63_mrvaddr;		/* most recent vad */
	int	mc63_istate;		/* internal state */
	int	mc63_pc;		/* trapped pc */
	int	mc63_psl;		/* trapped psl */
};

E 10
ka630_mchk(cmcf)
	caddr_t cmcf;
{
	register struct ka630cpu *ka630addr = &ka630cpu;
D 10
	register struct mc630frame *mcf = (struct mc630frame *)cmcf;
	register u_int type = mcf->mc63_summary;
E 10
I 10
	register struct mcuv2frame *mcf = (struct mcuv2frame *)cmcf;
	register u_int type = mcf->mcuv2_summary;
	extern char *mcuv2[];
E 10

D 7
	printf("machine check %x: %s\n", type,
	    type < NMC630 ? mc630[type] : "???");
	printf("\tvap %x istate %x pc %x psl %x\n",
E 7
I 7
	printf("machine check %x", type);
D 10
	if (type < NMC630 && mc630[type])
		printf(": %s", mc630[type]);
E 10
I 10
	if (type < NMCUV2 && mcuv2[type])
		printf(": %s", mcuv2[type]);
E 10
	printf("\n\tvap %x istate %x pc %x psl %x\n",
E 7
D 10
	    mcf->mc63_mrvaddr, mcf->mc63_istate,
	    mcf->mc63_pc, mcf->mc63_psl);
E 10
I 10
	    mcf->mcuv2_mrvaddr, mcf->mcuv2_istate,
	    mcf->mcuv2_pc, mcf->mcuv2_psl);
E 10
	if (ka630addr->ka630_mser & KA630MSER_MERR) {
		printf("\tmser=0x%x ", ka630addr->ka630_mser);
		if (ka630addr->ka630_mser & KA630MSER_CPUER)
			printf("page=%d", ka630addr->ka630_cear);
		if (ka630addr->ka630_mser & KA630MSER_DQPE)
			printf("page=%d", ka630addr->ka630_dear);
		printf("\n");
	}
	return (MCHK_PANIC);
E 5
}
#endif
E 1
