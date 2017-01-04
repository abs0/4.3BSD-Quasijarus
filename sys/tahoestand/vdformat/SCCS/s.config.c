h02574
s 00008/00001/00083
d D 1.5 88/06/14 18:51:26 bostic 5 4
c support 2361 super eagles; From: muller%sdcc7@ucsd.edu (Keith Muller)
e
s 00001/00001/00083
d D 1.4 88/05/04 09:31:08 karels 4 3
c correct number of bytes/track on eagle
e
s 00062/00016/00022
d D 1.3 87/11/23 15:28:28 karels 3 2
c working again, I think
e
s 00001/00000/00037
d D 1.2 86/11/04 21:24:06 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00037/00000/00000
d D 1.1 86/07/05 17:37:32 sam 1 0
c date and time created 86/07/05 17:37:32 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley/CCI) %G%";
#endif

/*
 * Drive configuration information.
 */
#include "vdfmt.h"

struct	flawpat defpats = {
	0x0264c993, 0x04c99326, 0x0993264c, 0x13264c98,
	0x264c9930, 0x4c993260, 0x993264c0, 0x3264c980,
	0x64c99300, 0xc9932600, 0x93264c00, 0x264c9800,
	0x4c993000, 0x99326000, 0x3264c000, 0x54c98000
};
D 3
struct	flawpat xfdpats = {
E 3
I 3
struct	flawpat cdcpats = {
E 3
	0x0d9b366c, 0x1b366cd8, 0x366cd9b0, 0x6cd9b360,
	0xd9b366c0, 0xb366cd80, 0x66cd9b00, 0xcd9b3600,
	0x9b366300, 0x366cd800, 0x6cd9b000, 0xd9b36000,
	0xb366c000, 0x66cd8000, 0xcd9b0000, 0x9b360000
};

D 3
struct	vdconfig vdconfig[] = {
    { "xsd", { 48, 24, 711 }, 0, 3600, 30240, &defpats,
      "515Mb CDC Winchester" },
    { "egl", { 44, 20, 842 }, 0, 3600, 27720, &defpats,
      "474Mb Fujitsu Eagle Winchester" },
    { "fuj", { 64, 10, 823 }, 0, 3600, 40960, &defpats,
      "360Mb Fujitsu Winchester" },
    { "xfd", { 32, 24, 711 }, 0, 3600, 20160, &xfdpats,
      "340Mb CDC Winchester" },
    { "smd", { 32, 19, 823 }, 0, 3600, 20160, &xfdpats,
      "300Mb CDC 9766" },
    { "fsd", { 32, 10, 823 }, 0, 3600, 20160, &xfdpats,
      "160Mb CDC Winchester" },
E 3
I 3
struct	disklabel vdproto[] = {
	{ DISKMAGIC, DTYPE_SMD, 0, "xsd", "newly formatted",
		512, 48, 24, 711, 48*24, 48*24*711,
		0, 0, 0, 3600, 1, 0, 0, 900, 0, 0,
		0, 30240, (long)&defpats, 0, 0, 0, 0, 0, 0, 0,
		DISKMAGIC, 0, 1, BBSIZE, SBSIZE,
		{ 48*24*711, 0 }
	},
	{ DISKMAGIC, DTYPE_SMD, 0, "ncc", "newly formatted",
		512, 66, 23, 850, 66*23, 66*23*850,
		0, 0, 0, 3600, 1, 0, 0, 900, 0, 0,
		0, 40960, (long)&defpats, 0, 0, 0, 0, 0, 0, 0,
		DISKMAGIC, 0, 1, BBSIZE, SBSIZE,
		{ 66*23*850, 0 }
	},
I 5
	{ DISKMAGIC, DTYPE_SMD, 0, "2361a", "newly formatted",
		512, 64, 20, 842, 64*20, 64*20*842,
		0, 0, 0, 3600, 1, 0, 0, 900, 0, 0,
		0, 40960, (long)&defpats, 0, 0, 0, 0, 0, 0, 0,
		DISKMAGIC, 0, 1, BBSIZE, SBSIZE,
		{ 64*20*842, 0 }
	},
E 5
	{ DISKMAGIC, DTYPE_SMD, 0, "egl", "newly formatted",
		512, 44, 20, 842, 44*20, 44*20*842,
		0, 0, 0, 3961, 1, 0, 0, 900, 0, 0,
D 4
		0, 27720, (long)&defpats, 0, 0, 0, 0, 0, 0, 0,
E 4
I 4
		0, 28160, (long)&defpats, 0, 0, 0, 0, 0, 0, 0,
E 4
		DISKMAGIC, 0, 1, BBSIZE, SBSIZE,
		{ 44*20*842, 0 }
	},
	{ DISKMAGIC, DTYPE_SMD, 0, "fuj", "newly formatted",
		512, 64, 10, 823, 64*10, 64*10*823,
		0, 0, 0, 3600, 1, 0, 0, 900, 0, 0,
		0, 40960, (long)&defpats, 0, 0, 0, 0, 0, 0, 0,
		DISKMAGIC, 0, 1, BBSIZE, SBSIZE,
		{ 64*10*823, 0 }
	},
	{ DISKMAGIC, DTYPE_SMD, 0, "xfd", "newly formatted",
		512, 32, 24, 711, 32*24, 32*24*711,
		0, 0, 0, 3600, 1, 0, 0, 900, 0, 0,
		0, 20160, (long)&cdcpats, 0, 0, 0, 0, 0, 0, 0,
		DISKMAGIC, 0, 1, BBSIZE, SBSIZE,
		{ 32*24*711, 0 }
	},

	{ DISKMAGIC, DTYPE_SMD, 0, "smd", "newly formatted",
		512, 32, 19, 823, 32*19, 32*19*823,
		0, 0, 0, 3600, 1, 0, 0, 900, 0, 0,
		0, 20160, (long)&cdcpats, 0, 0, 0, 0, 0, 0, 0,
		DISKMAGIC, 0, 1, BBSIZE, SBSIZE,
		{ 32*19*823, 0 }
	},
	{ DISKMAGIC, DTYPE_ESDI, 0, "mxd", "newly formatted",
		1024, 18, 15, 1224, 18*15, 18*15*1224,
		0, 0, 0, 3600, 1, 0, 0, 900, 0, 0,
		VD_ESDI, 20160, (long)&defpats, 0, 0, 0, 0, 0, 0, 0,
		DISKMAGIC, 0, 1, BBSIZE, SBSIZE,
		{ 18*15*1224, 0 }
	},
	{ DISKMAGIC, DTYPE_SMD, 0, "fsd", "newly formatted",
		512, 32, 10, 823, 32*10, 32*10*823,
		0, 0, 0, 3600, 1, 0, 0, 900, 0, 0,
		0, 20160, (long)&cdcpats, 0, 0, 0, 0, 0, 0, 0,
		DISKMAGIC, 0, 1, BBSIZE, SBSIZE,
		{ 32*10*823, 0 }
	},
E 3
};
D 3
int	ndrives = sizeof (vdconfig) / sizeof (vdconfig[0]);
I 2
int	smddrives = 3;			/* first 3 types are smd-e only */
E 3
I 3

int	ndrives = sizeof (vdproto) / sizeof (vdproto[0]);
D 5
int	smddrives = 4;			/* first 4 types are smd-e only */
E 5
I 5
int	smddrives = 5;			/* first 5 types are smd-e only */
E 5
E 3
E 2
E 1
