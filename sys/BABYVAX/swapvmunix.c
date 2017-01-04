#include "../h/param.h"
#include "../h/conf.h"

dev_t	rootdev = makedev(2, 0);
dev_t	argdev  = makedev(2, 1);
dev_t	dumpdev = makedev(2, 1);

struct	swdevt swdevt[] = {
	{ makedev(2, 1),	0,	0 },	/* up0b */
	{ 0, 0, 0 }
};
