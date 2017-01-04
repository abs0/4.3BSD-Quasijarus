h20937
s 00002/00002/00578
d D 5.4 04/09/17 08:51:44 msokolov 4 3
c add baseline rule (mapped to '_')
e
s 00004/00000/00576
d D 5.3 04/09/13 02:13:55 msokolov 3 2
c compile with -DCOL8 to get tabcol8
e
s 00006/00006/00570
d D 5.2 04/09/09 19:15:01 msokolov 2 1
c add renditions for new line drawing characters
e
s 00576/00000/00000
d D 5.1 04/09/08 17:03:33 msokolov 1 0
c date and time created 04/09/08 17:03:33 by msokolov
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/
#define INCH 240
/*
 * LPR or CRT 10 Pitch
 * nroff driving table
 * no reverse or half line feeds
 * by UCB Computer Center
 *
 * Modified for nroff8 by Michael Sokolov
 */
struct {
	int magic;
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
	char *codetab[512];
	int zzz;
	} t = {
/*magic*/	0x6E380000,
/*bset*/	0,
/*breset*/	0,
/*Hor*/		INCH/10,
/*Vert*/	INCH/6,
/*Newline*/	INCH/6,
/*Char*/	INCH/10,
/*Em*/		INCH/10,
/*Halfline*/	INCH/12,
/*Adj*/		INCH/10,
/*twinit*/	"",
/*twrest*/	"",
/*twnl*/	"\n",
/*hlr*/		"",
/*hlf*/		"",
I 3
#ifdef COL8
/*flr*/		"\0337",
#else
E 3
/*flr*/		"",
I 3
#endif
E 3
/*bdon*/	"",
/*bdoff*/	"",
/*ploton*/	"",
/*plotoff*/	"",
/*up*/		"",
/*down*/	"",
/*right*/	"",
/*left*/	"",
/*codetab*/
"\000",		/*00*/
"\000",		/*01*/
"\000",		/*02*/
"\000",		/*03*/
"\000",		/*04*/
"\000",		/*05*/
"\004(tm)",	/*06 trademark*/
"\001o\b+",	/*07 bullet*/
"\000",		/*08*/
"\000",		/*09*/
"\000",		/*0A*/
"\000",		/*0B*/
"\000",		/*0C*/
"\000",		/*0D*/
"\000",		/*0E*/
"\000",		/*0F*/
"\001<",	/*10 guilsinglleft*/
"\001>",	/*11 guilsinglright*/
"\000",		/*12*/
"\000",		/*13*/
"\000",		/*14*/
"\001\"",	/*15 quotedblbase*/
"\001\"",	/*16 quotedblleft*/
"\001\"",	/*17 quotedblright*/
"\001\'",	/*18 quotesinglbase*/
"\001\'",	/*19 quotesingle*/
"\000",		/*1A*/
"\000",		/*1B*/
"\000",		/*1C*/
"\000",		/*1D*/
"\000",		/*1E*/
"\000",		/*1F*/
"\001 ",	/*space*/
"\001!",	/*!*/
"\001\"",	/*"*/
"\001#",	/*#*/
"\001$",	/*$*/
"\001%",	/*%*/
"\001&",	/*&*/
"\001'",	/*' close*/
"\001(",	/*(*/
"\001)",	/*)*/
"\001*",	/***/
"\001+",	/*+*/
"\001,",	/*,*/
"\001-",	/*-*/
"\001.",	/*.*/
"\001/",	/*/*/
"\2010",	/*0*/
"\2011",	/*1*/
"\2012",	/*2*/
"\2013",	/*3*/
"\2014",	/*4*/
"\2015",	/*5*/
"\2016",	/*6*/
"\2017",	/*7*/
"\2018",	/*8*/
"\2019",	/*9*/
"\001:",	/*:*/
"\001;",	/*;*/
"\001<",	/*<*/
"\001=",	/*=*/
"\001>",	/*>*/
"\001?",	/*?*/
"\001@",	/*@*/
"\201A",	/*A*/
"\201B",	/*B*/
"\201C",	/*C*/
"\201D",	/*D*/
"\201E",	/*E*/
"\201F",	/*F*/
"\201G",	/*G*/
"\201H",	/*H*/
"\201I",	/*I*/
"\201J",	/*J*/
"\201K",	/*K*/
"\201L",	/*L*/
"\201M",	/*M*/
"\201N",	/*N*/
"\201O",	/*O*/
"\201P",	/*P*/
"\201Q",	/*Q*/
"\201R",	/*R*/
"\201S",	/*S*/
"\201T",	/*T*/
"\201U",	/*U*/
"\201V",	/*V*/
"\201W",	/*W*/
"\201X",	/*X*/
"\201Y",	/*Y*/
"\201Z",	/*Z*/
"\001[",	/*[*/
"\001\\",	/*\*/
"\001]",	/*]*/
"\001^",	/*^*/
"\001_",	/*_*/
"\001`",	/*` open*/
"\201a",	/*a*/
"\201b",	/*b*/
"\201c",	/*c*/
"\201d",	/*d*/
"\201e",	/*e*/
"\201f",	/*f*/
"\201g",	/*g*/
"\201h",	/*h*/
"\201i",	/*i*/
"\201j",	/*j*/
"\201k",	/*k*/
"\201l",	/*l*/
"\201m",	/*m*/
"\201n",	/*n*/
"\201o",	/*o*/
"\201p",	/*p*/
"\201q",	/*q*/
"\201r",	/*r*/
"\201s",	/*s*/
"\201t",	/*t*/
"\201u",	/*u*/
"\201v",	/*v*/
"\201w",	/*w*/
"\201x",	/*x*/
"\201y",	/*y*/
"\201z",	/*z*/
"\001{",	/*{*/
"\001|",	/*|*/
"\001}",	/*}*/
"\001~",	/*~*/
"\000",		/*DEL*/
"\001|\b-",	/*80 dagger*/
"\001|\b=",	/*81 dbl dagger*/
"\003...",	/*82 ellipsis*/
"\201Y\b\250",	/*83 Ydieresis*/
"\201L\b/",	/*84 Lslash*/
"\202OE",	/*85 OE*/
"\201S",	/*86 Scaron*/
"\201Z",	/*87 Zcaron*/
"\001-",	/*88 emdash*/
D 4
"\001-",	/*89 emdash*/
E 4
I 4
"\001-",	/*89 endash*/
E 4
"\202fi",	/*8A fi*/
"\202fl",	/*8B fl*/
"\201l\b/",	/*8C lslash*/
"\202oe",	/*8D oe*/
"\201s",	/*8E scaron*/
"\201z",	/*8F zcaron*/
"\201i",	/*90 dotlessi*/
"\001`",	/*91 grave*/
"\001\'",	/*92 acute*/
"\001^",	/*93 circumflex*/
"\001~",	/*94 tilde*/
"\001\257",	/*95 macron => ISO*/
"\001^",	/*96 breve*/
"\000",		/*97 dotaccent*/
"\001\250",	/*98 dieresis => ISO*/
"\001f",	/*99 florin*/
"\001\260",	/*9A ring*/
"\001\270",	/*9B cedilla => ISO*/
"\001/",	/*9C fraction*/
"\001\"",	/*9D hungarumlaut*/
"\000",		/*9E ogonek*/
"\000", 	/*9F caron*/
"\001 ",	/*A0 ISO meta-space => regular space*/
"\001\241",	/*A1 ISO*/
"\001\242",	/*A2 ISO*/
"\001\243",	/*A3 ISO*/
"\001\244",	/*A4 ISO*/
"\001\245",	/*A5 ISO*/
"\001\246",	/*A6 ISO*/
"\001\247",	/*A7 ISO*/
"\001\250",	/*A8 ISO*/
"\001\251",	/*A9 ISO*/
"\001\252",	/*AA ISO*/
"\001\253",	/*AB ISO*/
"\001\254",	/*AC ISO*/
"\001-",	/*AD ISO soft hyphen => regular hyphen/minus*/
"\001\256",	/*AE ISO*/
"\001\257",	/*AF ISO*/
"\001\260",	/*B0 ISO*/
"\001\261",	/*B1 ISO*/
"\001\262",	/*B2 ISO*/
"\001\263",	/*B3 ISO*/
"\001\264",	/*B4 ISO*/
"\001\265",	/*B5 ISO*/
"\001\266",	/*B6 ISO*/
"\001\267",	/*B7 ISO*/
"\001\270",	/*B8 ISO*/
"\001\271",	/*B9 ISO*/
"\001\272",	/*BA ISO*/
"\001\273",	/*BB ISO*/
"\001\274",	/*BC ISO*/
"\001\275",	/*BD ISO*/
"\001\276",	/*BE ISO*/
"\001\277",	/*BF ISO*/
"\201\300",	/*C0 ISO*/
"\201\301",	/*C1 ISO*/
"\201\302",	/*C2 ISO*/
"\201\303",	/*C3 ISO*/
"\201\304",	/*C4 ISO*/
"\201\305",	/*C5 ISO*/
"\201\306",	/*C6 ISO*/
"\201\307",	/*C7 ISO*/
"\201\310",	/*C8 ISO*/
"\201\311",	/*C9 ISO*/
"\201\312",	/*CA ISO*/
"\201\313",	/*CB ISO*/
"\201\314",	/*CC ISO*/
"\201\315",	/*CD ISO*/
"\201\316",	/*CE ISO*/
"\201\317",	/*CF ISO*/
"\201\320",	/*D0 ISO*/
"\201\321",	/*D1 ISO*/
"\201\322",	/*D2 ISO*/
"\201\323",	/*D3 ISO*/
"\201\324",	/*D4 ISO*/
"\201\325",	/*D5 ISO*/
"\201\326",	/*D6 ISO*/
"\001\327",	/*D7 ISO*/
"\201\330",	/*D8 ISO*/
"\201\331",	/*D9 ISO*/
"\201\332",	/*DA ISO*/
"\201\333",	/*DB ISO*/
"\201\334",	/*DC ISO*/
"\201\335",	/*DD ISO*/
"\201\336",	/*DE ISO*/
"\201\337",	/*DF ISO*/
"\201\340",	/*E0 ISO*/
"\201\341",	/*E1 ISO*/
"\201\342",	/*E2 ISO*/
"\201\343",	/*E3 ISO*/
"\201\344",	/*E4 ISO*/
"\201\345",	/*E5 ISO*/
"\201\346",	/*E6 ISO*/
"\201\347",	/*E7 ISO*/
"\201\350",	/*E8 ISO*/
"\201\351",	/*E9 ISO*/
"\201\352",	/*EA ISO*/
"\201\353",	/*EB ISO*/
"\201\354",	/*EC ISO*/
"\201\355",	/*ED ISO*/
"\201\356",	/*EE ISO*/
"\201\357",	/*EF ISO*/
"\201\360",	/*F0 ISO*/
"\201\361",	/*F1 ISO*/
"\201\362",	/*F2 ISO*/
"\201\363",	/*F3 ISO*/
"\201\364",	/*F4 ISO*/
"\201\365",	/*F5 ISO*/
"\201\366",	/*F6 ISO*/
"\001\367",	/*F7 ISO*/
"\201\370",	/*F8 ISO*/
"\201\371",	/*F9 ISO*/
"\201\372",	/*FA ISO*/
"\201\373",	/*FB ISO*/
"\201\374",	/*FC ISO*/
"\201\375",	/*FD ISO*/
"\201\376",	/*FE ISO*/
"\201\377",	/*FF ISO*/
"\000",		/*S 00*/
"\001-",	/*S 01 current font minus*/
"\000",		/*S 02 narrow space*/
"\000",		/*S 03 half narrow space*/
"\000",		/*S 04*/
"\000",		/*S 05*/
"\000",		/*S 06*/
"\000",		/*S 07*/
"\000",		/*S 08*/
"\000",		/*S 09*/
"\000",		/*S 0A*/
"\000",		/*S 0B*/
"\000",		/*S 0C*/
"\000",		/*S 0D*/
"\000",		/*S 0E*/
D 2
"\000",		/*S 0F*/
"\000",		/*S 10*/
"\000",		/*S 11*/
E 2
I 2
"\001_",	/*S 0F underrule*/
"\001~",	/*S 10 overrule*/
"\001|",	/*S 11 box rule*/
E 2
D 4
"\000",		/*S 12*/
E 4
I 4
"\001_",	/*S 12 baseline rule*/
E 4
"\000",		/*S 13*/
"\000",		/*S 14*/
"\000",		/*S 15*/
"\000",		/*S 16*/
"\000",		/*S 17*/
"\000",		/*S 18*/
"\000",		/*S 19*/
"\000",		/*S 1A*/
"\000",		/*S 1B*/
"\000",		/*S 1C*/
"\000",		/*S 1D*/
"\000",		/*S 1E*/
"\000",		/*S 1F*/
"\001 ",	/*Sspace*/
"\001!",	/*S!*/
"\001\"",	/*S"*/
"\001#",	/*S#*/
"\001$",	/*S$*/
"\001%",	/*S%*/
"\001&",	/*S&*/
"\001'",	/*S' close*/
"\001(",	/*S(*/
"\001)",	/*S)*/
"\001*",	/*S**/
"\001+",	/*S+*/
"\001,",	/*S,*/
"\001-",	/*S-*/
"\001.",	/*S.*/
"\001/",	/*S/*/
"\2010",	/*S0*/
"\2011",	/*S1*/
"\2012",	/*S2*/
"\2013",	/*S3*/
"\2014",	/*S4*/
"\2015",	/*S5*/
"\2016",	/*S6*/
"\2017",	/*S7*/
"\2018",	/*S8*/
"\2019",	/*S9*/
"\001:",	/*S:*/
"\001;",	/*S;*/
"\001<",	/*S<*/
"\001=",	/*S=*/
"\001>",	/*S>*/
"\001?",	/*S?*/
"\001@",	/*S@*/
"\201A",	/*SA*/
"\201B",	/*SB*/
"\201X",	/*SC*/
"\202/\b_\\\b_",/*SD*/
"\201E",	/*SE*/
"\201O\b|",	/*SF*/
"\201I\b~",	/*SG*/
"\201H",	/*SH*/
"\201I",	/*SI*/
"\201J",	/*SJ*/
"\201K",	/*SK*/
"\202/\\",	/*SL*/
"\201M",	/*SM*/
"\201N",	/*SN*/
"\201O",	/*SO*/
"\202TT",	/*SP*/
"\201O\b-",	/*SQ*/
"\201P",	/*SR*/
"\201>\b_\b~",	/*SS*/
"\201T",	/*ST*/
"\201Y",	/*SU*/
"\201V",	/*SV*/
"\201O\b_",	/*SW*/
"\201=\b_",	/*SX*/
"\201U\b|",	/*SY*/
"\201Z",	/*SZ*/
"\001[",	/*S[*/
"\001\\",	/*S\*/
"\001]",	/*S]*/
"\001^",	/*S^*/
"\001_",	/*S_*/
D 2
"\001~",	/*S` open (root en)*/
E 2
I 2
"\001~",	/*S` open (radical extension)*/
E 2
"\201o\b(",	/*Sa*/
"\2018\b|",	/*Sb*/
"\201x",	/*Sc*/
"\201d\b`",	/*Sd*/
"\201C\b-",	/*Se*/
"\201o\b|",	/*Sf*/
"\201>\b/",	/*Sg*/
"\201n",	/*Sh*/
"\201i",	/*Si*/
"\201j",	/*Sj*/
"\201k",	/*Sk*/
"\201,\b\\",	/*Sl*/
"\201u",	/*Sm*/
"\201v",	/*Sn*/
"\201o",	/*So*/
"\202i\b~i\b~",	/*Sp*/
"\201o\b-",	/*Sq*/
"\201p",	/*Sr*/
"\201o\b~",	/*Ss*/
"\201i\b~",	/*St*/
"\201u",	/*Su*/
"\201v",	/*Sv*/
"\201w",	/*Sw*/
"\201x",	/*Sx*/
"\201u\b|",	/*Sy*/
"\201z",	/*Sz*/
"\001{",	/*S{*/
"\001|",	/*S|*/
"\001}",	/*S}*/
"\001~",	/*S~*/
"\000",		/*SDEL*/
"\000",		/*S 80*/
"\000",		/*S 81*/
"\000",		/*S 82*/
"\000",		/*S 83*/
"\000",		/*S 84*/
"\000",		/*S 85*/
"\000",		/*S 86*/
"\000",		/*S 87*/
"\000",		/*S 88*/
"\000",		/*S 89*/
"\000",		/*S 8A*/
"\000",		/*S 8B*/
"\000",		/*S 8C*/
"\000",		/*S 8D*/
"\000",		/*S 8E*/
"\000",		/*S 8F*/
"\000",		/*S 90*/
"\000",		/*S 91*/
"\000",		/*S 92*/
"\000",		/*S 93*/
"\000",		/*S 94*/
"\000",		/*S 95*/
"\000",		/*S 96*/
"\000",		/*S 97*/
"\000",		/*S 98*/
"\000",		/*S 99*/
"\000",		/*S 9A*/
"\000",		/*S 9B*/
"\000",		/*S 9C*/
"\000",		/*S 9D*/
"\000",		/*S 9E*/
"\000",		/*S 9F*/
"\000",		/*S A0*/
"\201Y",	/*S A1 Upsilon1*/
"\001\'",	/*S A2*/
"\001<\b_",	/*S A3 <=*/
"\001/",	/*S A4*/
"\002oo",	/*S A5 infinity*/
"\001f",	/*S A6*/
"\000",		/*S A7*/
"\000",		/*S A8*/
"\000",		/*S A9*/
"\000",		/*S AA*/
"\000",		/*S AB*/
"\002<-",	/*S AC left arrow*/
"\001|\b^",	/*S AD up arrow*/
"\002->",	/*S AE right arrow*/
"\001|\bv",	/*S AF down arrow*/
"\001\260",	/*S B0 degree => ISO*/
"\001\261",	/*S B1 plusminus => ISO*/
"\001\"",	/*S B2*/
"\001>\b_",	/*S B3 >=*/
"\001\327",	/*S B4 multiply => ISO*/
"\002oc",	/*S B5 proportional to*/
"\001o\b`",	/*S B6 partial derivative*/
"\001o\b+",	/*S B7 bullet*/
"\001\367",	/*S B8 divide => ISO*/
"\001=\b/",	/*S B9 not equal*/
"\001=\b_",	/*S BA identically equal*/
"\001~\b_",	/*S BB approx =*/
"\003...",	/*S BC ellipsis*/
D 2
"\001|",	/*S BD box rule*/
"\001-",	/*S BE*/
E 2
I 2
"\001|",	/*S BD vertical arrow extension*/
"\001-",	/*S BE horizontal arrow extension*/
E 2
"\000",		/*S BF*/
"\000",		/*S C0*/
"\000",		/*S C1*/
"\000",		/*S C2*/
"\000",		/*S C3*/
"\001O\b\327",	/*S C4 x in circle*/
"\001O\b+",	/*S C5 + in circle*/
"\001O\b/",	/*S C6 empty set*/
"\002(\b_)\b_",	/*S C7 intersection*/
"\002(\b~)\b~",	/*S C8 union*/
"\002=)",	/*S C9 proper superset*/
"\002=\b_)",	/*S CA improper superset*/
"\000",		/*S CB not subset*/
"\002(=",	/*S CC proper subset*/
"\002(=\b_",	/*S CD improper subset*/
"\001<\b-",	/*S CE member of*/
"\000",		/*S CF not member of*/
"\000",		/*S D0 angle*/
"\002\\\b~/\b~",/*S D1 gradient*/
"\001\256",	/*S D2 registered => ISO*/
"\001\251",	/*S D3 copyright => ISO*/
"\004(tm)",	/*S D4 trademark*/
"\002TT",	/*S D5 product*/
"\001v\b/",	/*S D6 radical*/
"\001\267",	/*S D7 dotmath => ISO periodcentered*/
"\001\254",	/*S D8 logical not => ISO*/
"\000",		/*S D9*/
"\000",		/*S DA*/
"\000",		/*S DB*/
"\002<=",	/*S DC*/
"\000",		/*S DD*/
"\002=>",	/*S DE*/
"\000",		/*S DF*/
"\000",		/*S E0*/
"\001<",	/*S E1*/
"\001\256",	/*S E2 registered => ISO*/
"\001\251",	/*S E3 copyright => ISO*/
"\004(tm)",	/*S E4 trademark*/
"\001>\b_\b~",	/*S E5 sum*/
"\001|",	/*S E6*/
"\001|",	/*S E7*/
"\001|",	/*S E8*/
"\001|",	/*S E9*/
"\001|",	/*S EA*/
"\001|",	/*S EB*/
"\001|",	/*S EC*/
"\001|",	/*S ED*/
"\001|",	/*S EE*/
"\001|",	/*S EF*/
"\000",		/*S F0*/
"\001|",	/*S F1*/
"\001|",	/*S F2*/
"\001|",	/*S F3*/
"\001|",	/*S F4*/
"\001|",	/*S F5*/
"\001|",	/*S F6*/
"\001|",	/*S F7*/
"\001|",	/*S F8*/
"\001|",	/*S F9*/
"\001|",	/*S FA*/
"\001|",	/*S FB*/
"\001|",	/*S FC*/
"\001|",	/*S FD*/
"\001|",	/*S FE*/
"\000"		/*S FF*/
};
E 1