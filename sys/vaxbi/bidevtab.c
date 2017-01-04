/*
 * BI device table matching device types to drivers
 *
 *	@(#)bidevtab.c	7.1 (Berkeley) 3/6/04
 */

#include "kra.h"

#include "param.h"
#include "buf.h"
#include "../vaxuba/ubavar.h"
#include "bireg.h"
#include "bivar.h"

#if KDB
extern struct uba_driver kdbdriver;
#endif

struct bi_devtab bi_devtab[] = {
#if KDB
	{BIDT_KDB50, 1, &kdbdriver},
#endif
	{0, 0, 0}
};
