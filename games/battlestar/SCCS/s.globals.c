h62791
s 00010/00005/00193
d D 5.2 88/06/19 14:11:17 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00187
d D 5.1 88/05/08 15:49:41 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00186
d D 1.3 85/04/24 15:31:01 edward 3 2
c copyright messages
e
s 00004/00002/00182
d D 1.2 84/11/28 18:30:22 edward 2 1
c Dave's changes
e
s 00184/00000/00000
d D 1.1 84/11/18 18:59:04 edward 1 0
c date and time created 84/11/18 18:59:04 by edward
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 4
I 4
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 5
E 4
 */

E 3
I 1
#ifndef lint
D 4
static char sccsid[] = "%W% %G%";
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4

#include "externs.h"

int WEIGHT = MAXWEIGHT;
int CUMBER = MAXCUMBER;

char *objdes[NUMOFOBJECTS] = {
	"There is a knife here",
	"There is an exquisitely crafted sword and scabbard here.",
	0,				/* can land from here */
	"There is a fierce woodsman here brandishing a heavy mallet.",
	"There is an unweildly two-handed sword here.",
	"There is a bloody meat cleaver here.",
	"A rusty broadsword is lying here.",
	"There is an ancient coat of finely woven mail here.",
	"There is a old dented helmet with an ostrich plume here.",
	"There is a shield of some native tribe here.",
	"The maid's body is lying here. She was murdered!",
	"There is a Viper ready for launch here.",
	"A kerosene lantern is burning luridly here.",
	"An old pair of shoes has been discarded here.",
	0,				/* cylon */
	"There is a pair of pajamas here.",
	"A kingly robe of royal purple and spun gold is draped here.",
	"There is a strange golden amulet on the floor here.",
	"A medallion of solid gold shimmers on the ground nearby.",
	"A talisman of gold is lying here.",
	"A dead woodsman has fallen here. He was savagely murdered.",
	"A heavy wooden mallet lies nearby.",
	"There is a laser pistol here.",
       "A flower-like young goddess is bathing in the hot mineral pools. She is \nwatching you, but continues to steep and sing softly.",
	"The goddess is reclining on a bed of ferns and studying you intently.",
	"There is a grenade here",
	"There is a length of heavy chain here.",
	"There is a stout rope here.",
	"There is a pair of Levi's here.",
	"A bloody mace is lying on the ground here.",
	"There is a shovel here.",
	"A long, sharp halberd is propped up here.",
	"There is a compass here",
	"Wreckage and smoldering debris from a crash litter the ground here.",
	"A woodland Elf armed with a shield and deadly halberd lunges toward you!",
	"I think I hear footsteps behind us.",
	"There are a few coins here.",
	"There are some matches here.",
       "An unctuous man in a white suit and a dwarf are standing here.",
       "There are some ripe papayas here.",
       "There is a ripe pineapple here.",
       "There are some kiwi fruit here.",
       "There are some coconuts here.",
       "There is a ripe mango here.",
       "There is a sparkling diamond ring here.",
       "There is a colorful pink potion in a small crystal vial here.",
       "A gold bracelet is on the ground here.",
       "A swarthy woman with stern features pulls you aside from the crowd,\n'I must talk to you -- but not here.  Meet me at midnight in the gardens.'",
D 2
       "The swarthy woman has been awiating you anxiousy. 'I must warn you that the\nIsland has anticipated your Quest.  You will not be welcomed. The Darkness is\nstrong where you must search.  Seek not the shadows save only at night, for\nthen are they the weakest.  In the mountains far from here a canyon winds\nwith ferns and streams and forgotten vines.  There you will go and take this\nrope.'",
       "Out from the shadows a figure leaps!  His black cape swirls around and he\nholds a laser sword at your chest.  'So, you have come to fulfill the Quest.\nHa! Your weapons are no match for me!'",
E 2
I 2
       "The swarthy woman has been awaiting you anxiousy. 'I must warn you that the\nIsland has anticipated your Quest.  You will not be welcomed. The Darkness is\nstrong where you must search.  Seek not the shadows save only at night, for\nthen are they the weakest.  In the mountains far from here a canyon winds\nwith ferns and streams and forgotten vines.  There you must go. Take this\nrope.'",
       "Out from the shadows a figure leaps!  His black cape swirls around, and he\nholds a laser sword at your chest.  'So, you have come to fulfill the Quest.\nHa! Your weapons are no match for me!'",
E 2
       "An old timer with one eye missing and no money for a drink sits at the bar.",
       "You are flying through an asteroid field!",
       "A planet is nearby.",
       "The ground is charred here.",
       "There is a thermonuclear warhead here.",
       "The fragile, beautiful young goddess lies here.  You murdered her horribly.",
       "The old timer is lying here.  He is dead.",
       "The native girl's body is lying here.",
       "A native girl is sitting here.",
       "A gorgeous white stallion is standing here.",
       "The keys are in the ignition.",
       "A pot of pearls and jewels is sitting here.",
       "A bar of solid gold is here.",
       "There is a 10 kilogram diamond block here."

};

char *objsht[NUMOFOBJECTS] = {
	"knife",
	"fine sword",
	0,
	"Woodsman",
	"two-handed sword",
	"meat cleaver",
	"broadsword",
	"coat of mail",
	"plumed helmet",
	"shield",
	"maid's body",
	"viper",
	"lantern",
	"shoes",
	0,
	"pajamas",
	"robe",
	"amulet",
	"medallion",
	"talisman",
	"woodsman's body",
	"wooden mallet",
	"laser",
	0,
	0,
	"grenade",
	"chain",
	"rope",
	"levis",
	"mace",
	"shovel",
	"halberd",
	"compass",
	0,
	"Elf",
	0,
	"coins",
	"match book",
	0,
	"papayas",
	"pineapple",
	"kiwi",
	"coconuts",
	"mango",
	"ring",
	"potion",
	"bracelet",
	0,
	0,
	"Dark Lord",
	0,
	0,
	0,
	0,
	"warhead",
	"goddess's body",
	"old timer's body",
	"girl's body",
	0,
	"stallion",
	"car",
	"pot of jewels",
	"bar of gold",
	"diamond block"
};

char *ouch[NUMOFINJURIES] = {
	"some minor abrasions",
	"some minor lacerations",
	"a minor puncture wound",
	"a minor amputation",
	"a sprained wrist",
	"a fractured ankle and shattered kneecap",
	"a broken arm and dislocated shoulder",
	"a few broken ribs",
	"a broken leg and torn ligaments",
	"a broken back and ruptured spleen",
	"some deep incisions and a loss of blood",	
	"a fractured skull and mashed face",
	"a broken neck"
};

int objwt[NUMOFOBJECTS] = {
	1, 	5,	0,	10,	15,	2,	10,	10,
	3,	5,	50,	2500,	2,	1,	100,	1,	
	2,	1,	1,	1,	60,	10,	5,	0,
	50,	5,	15,	5,	1,	20,	10,	10,
	0,	0,	0,	0,	1,	0,	0,	1,
	1,	1,	2,	1,	0,	0,	0,	0,
	0,	0,	100,	0,	0,	0,	55,	47,
	50,	45,	45,	100,	2000,	30,	20,	10
};

int objcumber[NUMOFOBJECTS] = {
	1, 	5,	0,	150,	10,	1,	5,	2,
	2,	1,	5,	10,	1,	1,	10,	1,
	1,	1,	1,	1,	7,	5,	4,	0,
	0,	1,	1,	1,	1,	5,	4,	4,
	1,	0,	0,	0,	1,	0,	0,	1,
	1,	1,	3,	1,	0,	0,	1,	0,
	0,	0,	10,	0,	0,	0,	7,	8,
	10,	8,	8,	10,	10,	3,	1,	2
};

int win = 1;
int matchcount = 20;
I 2
int followgod = -1;
int followfight = -1;
E 2
E 1
