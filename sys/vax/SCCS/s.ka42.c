h06981
s 00143/00000/00000
d D 7.1 04/03/19 22:52:52 msokolov 1 0
c date and time created 04/03/19 22:52:52 by msokolov
e
u
U
t
T
I 1
/*
 * KA42 support code
 * Written by Michael Sokolov without the spec, by guessing from other CVAX
 * systems and from KA410, and using pieces from BSD KA650 and Ultrix "KA420"
 * code.
 *
 * Also covers KA41, the small server variant of the KA42.  KA41 is probably
 * the most confusingly named module in all of DEC.  There is KA410 and there
 * is KA42.  And then comes a KA42 variant called KA41.  So we have both KA410
 * and KA41, the latter being a variant of KA42, not KA410.  How wonderful.
 *
 *	%W% (Berkeley) %G%
 */

#ifdef VAX3100

#include "param.h"
#include "time.h"
#include "kernel.h"
#include "systm.h"

#include "cpu.h"
#include "psl.h"
#include "mem.h"
#include "mtpr.h"
#include "cvax.h"
#include "ka42.h"
#include "../babyvax/bvreg.h"

extern int cvax_l2cache_size;

/*
 * XXX This is a kludge - using KA650 structures for a different CPU
 * But KA42's L2 cache is close enough to the 650's
 */
extern	struct pte KA650CBDmap[];
extern	struct pte KA650CACHEmap[];
extern	u_long ka650cbd;	/* CACR */

ka42_init()
{
	if (bv_regs.bvr_cfgtst & CFGTST_MULTU)
		printf("MicroVAX 3100 (KA41), CVAX ucode rev %d\n",
			cpusid.cpu_cvax.cp_urev);
	else
		printf("VAXstation 3100 (KA42), CVAX ucode rev %d\n",
			cpusid.cpu_cvax.cp_urev);
	bv_regs.bvr_par_ctl = PAR_CTL_CPEN | PAR_CTL_DPEN;
	if (bv_regs.bvr_cfgtst & CFGTST_CACHPR) {
		ioaccess(KA42_CACR_PHYSADDR, KA650CBDmap, NBPG);
		ioaccess(KA42_CACHEDIAG_PHYSADDR, KA650CACHEmap,
			 KA42_L2CACHE_SIZE);
		cvax_l2cache_size = KA42_L2CACHE_SIZE;
	}
	cvaxencache();
}

ka42_memnop()
{
	/* void */
}

u_int	cache1tag;
u_int	cache1data;
u_int	cdalerr;
u_int	cache2tag;

ka42_memerr()
{
	register char *cp = (char *)0;
	register int m;

	if (cvax_l2cache_size && ka650cbd & CACR_CPE) {
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
}

ka42_mchk(cmcf)
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
	} else if (i & CAER_MCD) {
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
			ka42_memerr();
			return (MCHK_RECOVERED);
		}
	}
	return (MCHK_PANIC);
}
#endif
E 1
