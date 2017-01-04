h36299
s 00024/00000/00000
d D 7.1 04/03/06 01:49:54 msokolov 1 0
c date and time created 04/03/06 01:49:54 by msokolov
e
u
U
t
T
I 1
/*
 * BI device table matching device types to drivers
 *
 *	%W% (Berkeley) %G%
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
E 1
