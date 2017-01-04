h44164
s 00041/00000/00000
d D 4.1 82/10/27 15:26:46 rrh 1 0
c date and time created 82/10/27 15:26:46 by rrh
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% %E%";
#endif not lint

#include "head.h"

STRING	regnames[] = {
	"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
	"r8", "r9", "r10","r11","ap", "fp", "sp", "pc"};

#ifndef SDB
/*
 *	These are defined/included in optab.c
 */
REGLIST reglist [] = {
		"p1lr", P1LR,
		"p1br",P1BR,
		"p0lr", P0LR,
		"p0br",P0BR,
		"ksp",KSP,
		"esp",ESP,
		"ssp",SSP,
		"psl", PSL,
		"pc", PC,
		"usp",USP,
		"fp", FP,
		"ap", AP,
		"r11", R11,
		"r10", R10,
		"r9", R9,
		"r8", R8,
		"r7", R7,
		"r6", R6,
		"r5", R5,
		"r4", R4,
		"r3", R3,
		"r2", R2,
		"r1", R1,
		"r0", R0,
};
#endif not SDB
E 1
