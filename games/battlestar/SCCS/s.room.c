h54005
s 00010/00005/00200
d D 5.2 88/06/19 14:11:31 bostic 5 4
c install approved copyright notice
e
s 00011/00005/00194
d D 5.1 88/05/08 15:49:56 bostic 4 3
c add Berkeley header; yank to 5.1
e
s 00006/00000/00193
d D 1.3 85/04/24 15:32:30 edward 3 2
c copyright messages
e
s 00005/00005/00188
d D 1.2 84/11/28 18:31:17 edward 2 1
c Dave's changes
e
s 00193/00000/00000
d D 1.1 84/11/18 18:59:18 edward 1 0
c date and time created 84/11/18 18:59:18 by edward
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

writedes()
{
	int compass;
	register char *p;
	register c;

	printf("\n\t%s\n", location[position].name);
D 2
	if (beenthere[position]++ < 3) {
E 2
I 2
	if (beenthere[position] < 3) {
E 2
		compass = NORTH;
		for (p = location[position].desc; c = *p++;)
			if (c != '-' && c != '*' && c != '+')
				putchar(c);
			else {
				if (c != '*')
					printf(truedirec(compass, c));
				compass++;
			}
	}
}

printobjs()
{
I 2
	register unsigned int *p = location[position].objects;
E 2
	register n;

	printf("\n");
D 2
	for (n = 0; n < NUMOFOBJECTS; n++) {
		if (testbit(location[position].objects, n) && objdes[n])
			printf("%s\n", objdes[n]);
	}
E 2
I 2
	for (n = 0; n < NUMOFOBJECTS; n++)
		if (testbit(p, n) && objdes[n])
			puts(objdes[n]);
E 2
}

whichway(here)
struct room here;
{
	switch(direction) {

		case NORTH:
			left = here.west;
			right = here.east;
			ahead = here.north;
			back = here.south;
			break;
		
		case SOUTH:
			left = here.east;
			right = here.west;
			ahead = here.south;
			back = here.north;
			break;

		case EAST:
			left = here.north;
			right = here.south;
			ahead = here.east;
			back = here.west;
			break;

		case WEST:
			left = here.south;
			right = here.north;
			ahead = here.west;
			back = here.east;
			break;

	}
}

char *
truedirec(way, option)
int way;
char option;
{
	switch(way) {

		case NORTH:
			switch(direction) {
				case NORTH:
					return("ahead");
				case SOUTH:
					return(option == '+' ? "behind you" : "back");
				case EAST:
					return("left");
				case WEST:
					return("right");
			}

		case SOUTH:
			switch(direction) {
				case NORTH:
					return(option == '+' ? "behind you" : "back");
				case SOUTH:
					return("ahead");
				case EAST:
					return("right");
				case WEST:
					return("left");
			}

		case EAST:
			switch(direction) {
				case NORTH:
					return("right");
				case SOUTH:
					return("left");
				case EAST:
					return("ahead");
				case WEST:	
					return(option == '+' ? "behind you" : "back");
			}

		case WEST:
			switch(direction) {
				case NORTH:
					return("left");
				case SOUTH:
					return("right");
				case EAST:
					return(option == '+' ? "behind you" : "back");
				case WEST:
					return("ahead");
			}

		default:
			printf("Error: room %d.  More than four directions wanted.", position);
			return("!!");
      }
}

newway(thisway)
int thisway;
{
	switch(direction){

		case NORTH:
			switch(thisway){
				case LEFT:
					direction = WEST;
					break;
				case RIGHT:
					direction = EAST;
					break;
				case BACK:
					direction = SOUTH;
					break;
			}
			break;
		case SOUTH:
			switch(thisway){
				case LEFT:
					direction = EAST;
					break;
				case RIGHT:
					direction = WEST;
					break;
				case BACK:
					direction = NORTH;
					break;
			}
			break;
		case EAST:
			switch(thisway){
				case LEFT:
					direction = NORTH;
					break;
				case RIGHT:
					direction = SOUTH;
					break;
				case BACK:
					direction = WEST;
					break;
			}
			break;
		case WEST:
			switch(thisway){
				case LEFT:
					direction = SOUTH;
					break;
				case RIGHT:
					direction = NORTH;
					break;
				case BACK:
					direction = EAST;
					break;
			}
			break;
      }
}
E 1
