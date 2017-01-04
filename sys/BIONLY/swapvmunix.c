#include "../h/param.h"
#include "../h/conf.h"

dev_t	rootdev = makedev(16, 0);
dev_t	argdev  = makedev(16, 1);
dev_t	dumpdev = makedev(16, 1);

struct	swdevt swdevt[] = {
	{ makedev(16, 1),	0,	0 },	/* kra0b */
	{ 0, 0, 0 }
};
