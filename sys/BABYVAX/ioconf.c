#include "../machine/pte.h"
#include "../h/param.h"
#include "../h/buf.h"
#include "../h/map.h"
#include "../h/vm.h"

#include "../vaxmba/mbavar.h"
#include "../vaxuba/ubavar.h"


#define C (caddr_t)

extern struct uba_driver ssdriver;
extern Xssrint0(), Xssxint0();
int	 (*ssint0[])() = { Xssrint0, Xssxint0, 0 } ;

struct uba_ctlr ubminit[] = {
/*	 driver,	ctlr,	ubanum,	alive,	intr,	addr */
	0
};

struct uba_device ubdinit[] = {
	/* driver,  unit, ctlr,  ubanum, slave,   intr,    addr,    dk, flags*/
	0
};

struct uba_ctlr pnexminit[] = {
/*	 driver,	ctlr,	tie,	alive,	intr */
	0
};

struct uba_device pnexdinit[] = {
	/* driver,  unit, ctlr,  tie, slave,   intr,    addr,    dk, flags*/
	0
};

struct uba_ctlr bvaxminit[] = {
/*	 driver,	ctlr,	ubanum,	alive,	intr,	addr */
	0
};

struct uba_device bvaxdinit[] = {
	/* driver,  unit, ctlr,  ubanum, slave,   intr,    addr,    dk, flags*/
	{ &ssdriver,   0,    -1,    0,    -1,   ssint0, C 00     ,  0,  0xff },
	0
};
