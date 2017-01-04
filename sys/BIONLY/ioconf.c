#include "../machine/pte.h"
#include "../h/param.h"
#include "../h/buf.h"
#include "../h/map.h"
#include "../h/vm.h"

#include "../vaxmba/mbavar.h"
#include "../vaxuba/ubavar.h"


#define C (caddr_t)

extern struct uba_driver kdbdriver;
extern Xkdbintr0();
int	 (*kdbint0[])() = { Xkdbintr0, 0 } ;

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
	{ &kdbdriver,	0,	-1,	0,	kdbint0 },
	0
};

struct uba_device pnexdinit[] = {
	/* driver,  unit, ctlr,  tie, slave,   intr,    addr,    dk, flags*/
	{ &kdbdriver,   0,     0,  -1,     0,        0, C 0x0,  1,  0x0 },
	{ &kdbdriver,   1,     0,  -1,     1,        0, C 0x0,  1,  0x0 },
	{ &kdbdriver,   2,     0,  -1,     2,        0, C 0x0,  1,  0x0 },
	{ &kdbdriver,   3,     0,  -1,     3,        0, C 0x0,  1,  0x0 },
	0
};
