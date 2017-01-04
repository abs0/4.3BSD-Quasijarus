h23859
s 00018/00000/00120
d D 7.3 04/03/20 00:00:34 msokolov 3 2
c add CPMBX functions
e
s 00037/00000/00083
d D 7.2 04/03/18 23:25:16 msokolov 2 1
c wrote early serial console code, compiles
e
s 00083/00000/00000
d D 7.1 04/03/18 19:05:48 msokolov 1 0
c started work on BabyVAX support (compiles, but no console yet)
e
u
U
t
T
I 1
/*
 * BabyVAX support core code
 *
 *	%W% (Berkeley) %G%
 */

#include "param.h"
#include "time.h"
#include "kernel.h"
#include "vmmac.h"

#include "../vax/mtpr.h"
#include "../vax/cpu.h"
#include "../vax/clock.h"
#include "../vax/pte.h"

#include "bvreg.h"
I 2
#include "ssreg.h"
E 2

I 2
extern (*v_putc)();

babyvax_sercons_putc(c)
	register int c;
{
	register int timo;

	timo = 30000;
	/*
	 * Try waiting for the console tty to come ready,
	 * otherwise give up after a reasonable time.
	 */
	while ((bv_regs.bvr_sercsr & SSCSR_TRDY) == 0)
		if(--timo == 0)
			break;
	if (c == 0)
		return;
	bv_regs.bvr_sertdr = c&0xFF;
	if (c == '\n')
		babyvax_sercons_putc('\r');
	babyvax_sercons_putc(0);
}

E 2
babyvax_early_init()
{
	*(int *)&Babyvaxmap[0] = PG_V | PG_KW | btop(0x20020000);
	*(int *)&Babyvaxmap[1] = PG_V | PG_KW | btop(0x20080000);
	*(int *)&Babyvaxmap[2] = PG_V | PG_KW | btop(0x20090000);
	*(int *)&Babyvaxmap[3] = PG_V | PG_KW | btop(0x200A0000);
	*(int *)&Babyvaxmap[4] = PG_V | PG_KW | btop(0x200B0000);
	*(int *)&Babyvaxmap[5] = PG_V | PG_KW | btop(0x200C0000);
	*(int *)&Babyvaxmap[6] = PG_V | PG_KW | btop(0x200E0000);
	*(int *)&Babyvaxmap[7] = PG_V | PG_KW | btop(0x200F0000);
	mtpr(TBIA, 0);
	bv_regs.bvr_ioreset = 0;
I 2
	/* Early-initialise the serial console (before ss driver is up) */
	bv_regs.bvr_sercsr = SSCSR_CLR;
	while (bv_regs.bvr_sercsr & SSCSR_CLR)
		;
	if (bv_regs.bvr_cfgtst & CFGTST_L3CON) {
		bv_regs.bvr_serlpr = SSLPR_CONS | 3;
		bv_regs.bvr_sertcr = 1 << 3;
	} else {
		bv_regs.bvr_serlpr = SSLPR_CONS | 0;
		bv_regs.bvr_sertcr = 1 << 0;
	}
	bv_regs.bvr_sercsr = SSCSR_MSE;
	v_putc = babyvax_sercons_putc;
E 2
}

I 3
babyvax_clear_biprip()
{
	bv_regs.bvr_cpmbx &= ~(CPMBX_BIP | CPMBX_RIP);
}

babyvax_set_haltact(c)
	int c;
{
	bv_regs.bvr_cpmbx &= ~CPMBX_HLTACT;
	bv_regs.bvr_cpmbx |= c << CPMBX_HLTACT_SHIFT;
}

babyvax_halt()
{
	babyvax_set_haltact(3);
	asm("halt");
}

E 3
/* init system time from tod clock */
/* ARGSUSED */
babyvax_clkread(base)
	time_t base;
{
	struct chiptime c;
	int s;

	if (bv_regs.bvr_toycsrb & (TOYCSRB_DM|TOYCSRB_24HR|TOYCSRB_DSE) !=
	    (TOYCSRB_DM|TOYCSRB_24HR)) {
		printf("WARNING: watch chip in wrong mode");
		return(CLKREAD_BAD);
	}
	if (bv_regs.bvr_toycsrb & TOYCSRB_SET) {
		printf("WARNING: watch chip stuck in SET mode");
		return(CLKREAD_BAD);
	}
	if ((bv_regs.bvr_toycsra & TOYCSRA_DVX) != TOYCSRA_SET) {
		printf("WARNING: watch chip time base divisor wrong");
		return(CLKREAD_BAD);
	}
	s = splhigh();
	while (bv_regs.bvr_toycsra & TOYCSRA_UIP)
		;
	c.sec = bv_regs.bvr_toysecs >> 2;
	c.min = bv_regs.bvr_toymins >> 2;
	c.hour = bv_regs.bvr_toyhours >> 2;
	c.day = bv_regs.bvr_toyday >> 2;
	c.mon = bv_regs.bvr_toymonth >> 2;
	c.year = bv_regs.bvr_toyyear >> 2;
	splx(s);
	time.tv_sec = chiptotime(&c);
	return (time.tv_sec ? CLKREAD_OK : CLKREAD_BAD);
}

/* Set the time of day clock, called via. stime system call.. */
babyvax_clkwrite()
{
	struct chiptime c;

	timetochip(&c);
	bv_regs.bvr_toycsrb = TOYCSRB_SET | TOYCSRB_DM | TOYCSRB_24HR;
	bv_regs.bvr_toycsra = TOYCSRA_SET;
	bv_regs.bvr_toysecs = c.sec << 2;
	bv_regs.bvr_toymins = c.min << 2;
	bv_regs.bvr_toyhours = c.hour << 2;
	bv_regs.bvr_toyday = c.day << 2;
	bv_regs.bvr_toymonth = c.mon << 2;
	bv_regs.bvr_toyyear = c.year << 2;
	bv_regs.bvr_toycsrb = TOYCSRB_DM | TOYCSRB_24HR;
}
E 1
