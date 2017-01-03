#include "../h/param.h"
#include "../h/conf.h"

dev_t	rootdev = makedev(9, 24);
dev_t	argdev  = makedev(9, 25);
dev_t	dumpdev = makedev(9, 25);

struct	swdevt swdevt[] = {
	{ makedev(9, 25),	0,	0 },	/* ra3b */
	{ makedev(9, 9),	0,	0 },	/* ra1b */
	{ 0, 0, 0 }
};
