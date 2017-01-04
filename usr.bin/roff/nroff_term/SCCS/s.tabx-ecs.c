h10229
s 00060/00000/00000
d D 4.1 83/08/05 13:35:39 sam 1 0
c date and time created 83/08/05 13:35:39 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/
#define INCH 240
/*
 * DIABLO 630 10 pitch ECS
 * nroff driving table (extended character set)
 * not tested with any wheel
 * by Bill Tuthill, ucbvax!g:tut, 15dec82
 */
struct {
	int bset;
	int breset;
	int Hor;
	int Vert;
	int Newline;
	int Char;
	int Em;
	int Halfline;
	int Adj;
	char *twinit;
	char *twrest;
	char *twnl;
	char *hlr;
	char *hlf;
	char *flr;
	char *bdon;
	char *bdoff;
	char *ploton;
	char *plotoff;
	char *up;
	char *down;
	char *right;
	char *left;
	char *codetab[256-32];
	int zzz;
	} t = {
/*bset*/	0,
/*breset*/	0177420,
/*Hor*/		INCH/60,
/*Vert*/	INCH/48,
/*Newline*/	INCH/6,
/*Char*/	INCH/10,
/*Em*/		INCH/10,
/*Halfline*/	INCH/12,
/*Adj*/		INCH/10,
/*twinit*/	"\0334",
/*twrest*/	"\0334",
/*twnl*/	"\r\n",
/*hlr*/		"\033D",
/*hlf*/		"\033U",
/*flr*/		"\033\n",
/*bdon*/	"\033W",
/*bdoff*/	"\033&",
/*ploton*/	"\0333",
/*plotoff*/	"\0334",
/*up*/		"\033\n",
/*down*/	"\n",
/*right*/	" ",
/*left*/	"\b",
/*codetab*/
#include "code.x-ecs"
E 1
