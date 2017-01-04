/*
 * Copyright (c) 1988 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Mt. Xinu.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)ka650.c	7.9 (Berkeley) 3/19/04
 */

#if VAX650

/*
 * vax650-specific code.
 */

#include "param.h"
#include "time.h"
#include "kernel.h"
#include "systm.h"

#include "cpu.h"
#include "psl.h"
#include "mem.h"
#include "mtpr.h"
#include "cvax.h"
#include "ka650.h"

extern int cvax_l2cache_size;

ka650_init()
{
	switch (cpusie.sys6xx.sys_subtype) {
	case SIE_SYSSUBTYPE_KA650:
		printf("\
MicroVAX 3500/3600 (KA650), CVAX ucode rev %d, ROM version %d.%d\n",
			cpusid.cpu_cvax.cp_urev,
			cpusie.sys6xx.sys_version >> 4,
			cpusie.sys6xx.sys_version & 0xF);
		cvax_l2cache_size = KA650_CACHESIZE;
		break;
	case SIE_SYSSUBTYPE_KA640:
		printf("\
MicroVAX 3300/3400 (KA640), CVAX ucode rev %d, ROM version %d.%d\n",
			cpusid.cpu_cvax.cp_urev,
			cpusie.sys6xx.sys_version >> 4,
			cpusie.sys6xx.sys_version & 0xF);
		break;
	case SIE_SYSSUBTYPE_KA655:
		printf("\
MicroVAX 3800/3900 (KA655), CVAX ucode rev %d, ROM version %d.%d\n",
			cpusid.cpu_cvax.cp_urev,
			cpusie.sys6xx.sys_version >> 4,
			cpusie.sys6xx.sys_version & 0xF);
		cvax_l2cache_size = KA650_CACHESIZE;
		break;
	case SIE_SYSSUBTYPE_KA660:
		printf("VAX 4200 (KA660), SOC ucode rev %d, ROM version %d.%d\n",
			cpusid.cpu_cvax.cp_urev,
			cpusie.sys6xx.sys_version >> 4,
			cpusie.sys6xx.sys_version & 0xF);
		break;
	default:
		printf("VAX650-style unknown board\n");
	}

	ioaccess(KA650_MERR, KA650MERRmap, sizeof(ka650merr));
	ioaccess(KA650_CBD, KA650CBDmap, sizeof(ka650cbd));
	ioaccess(KA650_SSC, KA650SSCmap, sizeof(ka650ssc));
	ioaccess(KA650_IPCR, KA650IPCRmap, sizeof(ka650ipcr));
	ioaccess(KA650_CACHE, KA650CACHEmap, KA650_CACHESIZE);
	cvaxencache();
	if (ctob(physmem) > ka650merr.merr_qbmbr) {
		printf("physmem(0x%x) > qbmbr(0x%x)\n",
		    ctob(physmem), ka650merr.merr_qbmbr);
		panic("qbus map unprotected");
	}
}

ka650_memnop()
{
	/* void */
}

ka650_memerr()
{
	register char *cp = (char *)0;
	register int m;
	extern u_int cache2tag;

	if (cvax_l2cache_size && ka650cbd.cbd_cacr & CACR_CPE) {
		printf("cache 2 tag parity error: ");
		if (time.tv_sec - cache2tag < 7) {
			cvaxdiscache();
			printf("cacheing disabled\n");
		} else {
			cache2tag = time.tv_sec;
			printf("flushing cache\n");
			cvaxencache();
		}
	}
	m = ka650merr.merr_errstat;
	ka650merr.merr_errstat = MEM_EMASK;
	if (m & MEM_CDAL) {
		cp = "Bus Parity";
	} else if (m & MEM_RDS) {
		cp = "Hard ECC";
	} else if (m & MEM_CRD) {
		cp = "Soft ECC";
	}
	if (cp) {
		printf("%sMemory %s Error: page 0x%x\n",
			(m & MEM_DMA) ? "DMA " : "", cp,
			(m & MEM_PAGE) >> MEM_PAGESHFT);
	}
}

u_int	cache1tag;
u_int	cache1data;
u_int	cdalerr;
u_int	cache2tag;

ka650_mchk(cmcf)
	caddr_t cmcf;
{
	register struct mcvaxframe *mcf = (struct mcvaxframe *)cmcf;
	register u_int type = mcf->mcvax_summary;
	register u_int i;
	extern char *mcvax[];

	printf("machine check %x", type);
	if (type >= 0x80 && type <= 0x83)
		type -= (0x80 + 11);
	if (type < NMCVAX && mcvax[type])
		printf(": %s", mcvax[type]);
	printf("\n\tvap %x istate1 %x istate2 %x pc %x psl %x\n",
	    mcf->mcvax_mrvaddr, mcf->mcvax_istate1, mcf->mcvax_istate2,
	    mcf->mcvax_pc, mcf->mcvax_psl);
	printf("dmaser=0x%b qbear=0x%x dmaear=0x%x\n",
	    ka650merr.merr_dser, DMASER_BITS, ka650merr.merr_qbear,
	    ka650merr.merr_dear);
	ka650merr.merr_dser = DSER_CLEAR;

	i = mfpr(CAER);
	mtpr(CAER, CAER_MCC | CAER_DAT | CAER_TAG);
	if (i & CAER_MCC) {
		printf("cache 1 ");
		if (i & CAER_DAT) {
			printf("data");
			i = cache1data;
			cache1data = time.tv_sec;
		}
		if (i & CAER_TAG) {
			printf("tag");
			i = cache1tag;
			cache1tag = time.tv_sec;
		}
	} else if ((i & CAER_MCD) || (ka650merr.merr_errstat & MEM_CDAL)) {
		printf("CDAL");
		i = cdalerr;
		cdalerr = time.tv_sec;
	}
	if (time.tv_sec - i < 7) {
		cvaxdiscache();
		printf(" parity error:  cacheing disabled\n");
	} else {
		printf(" parity error:  flushing cache\n");
		cvaxencache();
	}
	/*
	 * May be able to recover if type is 1-4, 0x80 or 0x81, but
	 * only if FPD is set in the saved PSL, or bit VCR in Istate2
	 * is clear.
	 */
	if ((type > 0 && type < 5) || type == 11 || type == 12) {
		if ((mcf->mcvax_psl & PSL_FPD)
		    || !(mcf->mcvax_istate2 & IS2_VCR)) {
			ka650_memerr();
			return (MCHK_RECOVERED);
		}
	}
	return (MCHK_PANIC);
}
#endif
