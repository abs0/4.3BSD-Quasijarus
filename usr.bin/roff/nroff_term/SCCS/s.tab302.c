h04189
s 00060/00000/00000
d D 4.1 83/08/05 13:34:58 sam 1 0
c date and time created 83/08/05 13:34:58 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/
#define INCH 240
/*
 * DTC 302 or 300s 10 pitch
 * nroff driving tables
 * width and code tables
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
/*twinit*/	"\033\006",
/*twrest*/	"\033\006",
/*twnl*/	"\015\n",
/*hlr*/		"\033H",
/*hlf*/		"\033h",
/*flr*/		"\032",
/*bdon*/	"\033E",
/*bdoff*/	"\033E",
/*ploton*/	"\006",
/*plotoff*/	"\033\006",
/*up*/		"\032",
/*down*/	"\n",
/*right*/	" ",
/*left*/	"\b",
/*codetab*/
#include "code.300"
E 1
