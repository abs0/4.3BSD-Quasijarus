#include "../machine/pte.h"
#include "../h/param.h"
#include "../h/buf.h"
#include "../h/map.h"
#include "../h/vm.h"

#include "../vaxmba/mbavar.h"
#include "../vaxuba/ubavar.h"


#define C (caddr_t)

extern struct uba_driver udadriver;
extern Xudaintr0();
int	 (*udaint0[])() = { Xudaintr0, 0 } ;
extern struct uba_driver qedriver;
extern Xqeintr0();
int	 (*qeint0[])() = { Xqeintr0, 0 } ;
extern struct uba_driver dhudriver;
extern Xdhurint0(), Xdhuxint0();
int	 (*dhuint0[])() = { Xdhurint0, Xdhuxint0, 0 } ;

struct uba_ctlr ubminit[] = {
/*	 driver,	ctlr,	ubanum,	alive,	intr,	addr */
	{ &udadriver,	0,	'?',	0,	udaint0, C 0172150 },
	0
};

struct uba_device ubdinit[] = {
	/* driver,  unit, ctlr,  ubanum, slave,   intr,    addr,    dk, flags*/
	{ &udadriver,   0,     0,  '?',     0,        0, C 00     ,  1,  0x0 },
	{ &qedriver,   0,    -1,  '?',    -1,   qeint0, C 0174440,  0,  0x0 },
	{ &dhudriver,   0,    -1,  '?',    -1,   dhuint0, C 0160440,  0,  0x2 },
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
