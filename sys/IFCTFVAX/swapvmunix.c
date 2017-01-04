#include "../h/param.h"
#include "../h/conf.h"

dev_t	rootdev = makedev(9, 0);
dev_t	argdev  = makedev(9, 1);
dev_t	dumpdev = makedev(9, 9);

struct	swdevt swdevt[] = {
	{ makedev(9, 1),	0,	0 },	/* ra0b */
	{ makedev(9, 9),	0,	0 },	/* ra1b */
	{ 0, 0, 0 }
};
