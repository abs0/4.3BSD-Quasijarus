dnl	@(#)troffemu.m4	5.5	(Berkeley)	2010/09/28
%!PS-Adobe-3.0 Resource-Font
%%LanguageLevel: 1
%%DocumentNeededResources: encoding TroffEncoding
%%+ font romanfont-troff expertfont
%%BeginResource: font newfontname
15 dict begin
/FontName /newfontname def
/FontType 3 def
/rd {readonly def} bind def
/FontMatrix [.001 0 0 .001 0 0] rd
/FontBBox [fontbbox] rd
/Encoding TroffEncoding def
/BuildChar {
	1 `index' /Encoding get exch get
	1 `index' /BuildGlyph get exec
} bind def
/BuildGlyph {
	exch begin
	CharProcs 1 `index' known {
		CharProcs 1 `index' get
	} {
		CharProcs /.notdef get
	} `ifelse'
	exec
	end
} bind def
256 dict begin
dnl Define each character name to [code wx wy llx lly urx ury]
include(metricsfile)dnl
currentdict end
readonly /CharMetrics exch def
256 dict begin
	/.notdef {
		pop 0 0 0 0 0 0 setcachedevice
	} bind def
	/.fromroman {
		CharMetrics exch get cvx exec setcachedevice
		buf 0 3 -1 roll put
		RF setfont 0 0 moveto buf show
	} bind def
	/.fromexpert {
		CharMetrics exch get cvx exec setcachedevice
		buf 0 3 -1 roll put
		EF setfont 0 0 moveto buf show
	} bind def
	/trademark /.fromroman load def
	/bullet /.fromroman load def
	/guilsinglleft /.fromroman load def
	/guilsinglright /.fromroman load def
	/perthousand /.fromroman load def
	/quotedblbase /.fromroman load def
	/quotedblleft /.fromroman load def
	/quotedblright /.fromroman load def
	/quotesinglbase /.fromroman load def
	/quotesingle /.fromroman load def
	/ff /.fromexpert load def
	/ffi /.fromexpert load def
	/ffl /.fromexpert load def
	/space /.fromroman load def
	/exclam /.fromroman load def
	/quotedbl /.fromroman load def
	/numbersign /.fromroman load def
	/dollar /.fromroman load def
	/percent /.fromroman load def
	/ampersand /.fromroman load def
	/quoteright /.fromroman load def
	/parenleft /.fromroman load def
	/parenright /.fromroman load def
	/asterisk /.fromroman load def
	/plus /.fromroman load def
	/comma /.fromroman load def
	/minus /.fromroman load def
	/period /.fromroman load def
	/slash /.fromroman load def
	/zero /.fromroman load def
	/one /.fromroman load def
	/two /.fromroman load def
	/three /.fromroman load def
	/four /.fromroman load def
	/five /.fromroman load def
	/six /.fromroman load def
	/seven /.fromroman load def
	/eight /.fromroman load def
	/nine /.fromroman load def
	/colon /.fromroman load def
	/semicolon /.fromroman load def
	/less /.fromroman load def
	/equal /.fromroman load def
	/greater /.fromroman load def
	/question /.fromroman load def
	/at /.fromroman load def
	/A /.fromroman load def
	/B /.fromroman load def
	/C /.fromroman load def
	/D /.fromroman load def
	/E /.fromroman load def
	/F /.fromroman load def
	/G /.fromroman load def
	/H /.fromroman load def
	/I /.fromroman load def
	/J /.fromroman load def
	/K /.fromroman load def
	/L /.fromroman load def
	/M /.fromroman load def
	/N /.fromroman load def
	/O /.fromroman load def
	/P /.fromroman load def
	/Q /.fromroman load def
	/R /.fromroman load def
	/S /.fromroman load def
	/T /.fromroman load def
	/U /.fromroman load def
	/V /.fromroman load def
	/W /.fromroman load def
	/X /.fromroman load def
	/Y /.fromroman load def
	/Z /.fromroman load def
	/bracketleft /.fromroman load def
	/backslash /.fromroman load def
	/bracketright /.fromroman load def
	/asciicircum /.fromroman load def
	/underscore /.fromroman load def
	/quoteleft /.fromroman load def
	/a /.fromroman load def
	/b /.fromroman load def
	/c /.fromroman load def
	/d /.fromroman load def
	/e /.fromroman load def
	/f /.fromroman load def
	/g /.fromroman load def
	/h /.fromroman load def
	/i /.fromroman load def
	/j /.fromroman load def
	/k /.fromroman load def
	/l /.fromroman load def
	/m /.fromroman load def
	/n /.fromroman load def
	/o /.fromroman load def
	/p /.fromroman load def
	/q /.fromroman load def
	/r /.fromroman load def
	/s /.fromroman load def
	/t /.fromroman load def
	/u /.fromroman load def
	/v /.fromroman load def
	/w /.fromroman load def
	/x /.fromroman load def
	/y /.fromroman load def
	/z /.fromroman load def
	/braceleft /.fromroman load def
	/bar /.fromroman load def
	/braceright /.fromroman load def
	/asciitilde /.fromroman load def
	/dagger /.fromroman load def
	/daggerdbl /.fromroman load def
	/ellipsis /.fromroman load def
	/Ydieresis /.fromroman load def
	/Lslash /.fromroman load def
	/OE /.fromroman load def
	/Scaron /.fromroman load def
	/Zcaron /.fromroman load def
	/endash /.fromroman load def
	/fi /.fromroman load def
	/fl /.fromroman load def
	/lslash /.fromroman load def
	/oe /.fromroman load def
	/scaron /.fromroman load def
	/zcaron /.fromroman load def
	/dotlessi /.fromroman load def
	/grave /.fromroman load def
	/acute /.fromroman load def
	/circumflex /.fromroman load def
	/tilde /.fromroman load def
	/macron /.fromroman load def
	/breve /.fromroman load def
	/dotaccent /.fromroman load def
	/dieresis /.fromroman load def
	/florin /.fromroman load def
	/ring /.fromroman load def
	/cedilla /.fromroman load def
	/fraction /.fromroman load def
	/hungarumlaut /.fromroman load def
	/ogonek /.fromroman load def
	/caron /.fromroman load def
	/exclamdown /.fromroman load def
	/cent /.fromroman load def
	/sterling /.fromroman load def
	/currency /.fromroman load def
	/yen /.fromroman load def
	/brokenbar /.fromroman load def
	/section /.fromroman load def
	/copyright /.fromroman load def
	/ordfeminine /.fromroman load def
	/guillemotleft /.fromroman load def
	/logicalnot /.fromroman load def
	/hyphen /.fromroman load def
	/registered /.fromroman load def
	/degree /.fromroman load def
	/plusminus /.fromroman load def
	/twosuperior /.fromroman load def
	/threesuperior /.fromroman load def
	/mu /.fromroman load def
	/paragraph /.fromroman load def
	/periodcentered /.fromroman load def
	/onesuperior /.fromroman load def
	/ordmasculine /.fromroman load def
	/guillemotright /.fromroman load def
	/onequarter /.fromroman load def
	/onehalf /.fromroman load def
	/threequarters /.fromroman load def
	/questiondown /.fromroman load def
	/Agrave /.fromroman load def
	/Aacute /.fromroman load def
	/Acircumflex /.fromroman load def
	/Atilde /.fromroman load def
	/Adieresis /.fromroman load def
	/Aring /.fromroman load def
	/AE /.fromroman load def
	/Ccedilla /.fromroman load def
	/Egrave /.fromroman load def
	/Eacute /.fromroman load def
	/Ecircumflex /.fromroman load def
	/Edieresis /.fromroman load def
	/Igrave /.fromroman load def
	/Iacute /.fromroman load def
	/Icircumflex /.fromroman load def
	/Idieresis /.fromroman load def
	/Eth /.fromroman load def
	/Ntilde /.fromroman load def
	/Ograve /.fromroman load def
	/Oacute /.fromroman load def
	/Ocircumflex /.fromroman load def
	/Otilde /.fromroman load def
	/Odieresis /.fromroman load def
	/multiply /.fromroman load def
	/Oslash /.fromroman load def
	/Ugrave /.fromroman load def
	/Uacute /.fromroman load def
	/Ucircumflex /.fromroman load def
	/Udieresis /.fromroman load def
	/Yacute /.fromroman load def
	/Thorn /.fromroman load def
	/germandbls /.fromroman load def
	/agrave /.fromroman load def
	/aacute /.fromroman load def
	/acircumflex /.fromroman load def
	/atilde /.fromroman load def
	/adieresis /.fromroman load def
	/aring /.fromroman load def
	/ae /.fromroman load def
	/ccedilla /.fromroman load def
	/egrave /.fromroman load def
	/eacute /.fromroman load def
	/ecircumflex /.fromroman load def
	/edieresis /.fromroman load def
	/igrave /.fromroman load def
	/iacute /.fromroman load def
	/icircumflex /.fromroman load def
	/idieresis /.fromroman load def
	/eth /.fromroman load def
	/ntilde /.fromroman load def
	/ograve /.fromroman load def
	/oacute /.fromroman load def
	/ocircumflex /.fromroman load def
	/otilde /.fromroman load def
	/odieresis /.fromroman load def
	/divide /.fromroman load def
	/oslash /.fromroman load def
	/ugrave /.fromroman load def
	/uacute /.fromroman load def
	/ucircumflex /.fromroman load def
	/udieresis /.fromroman load def
	/yacute /.fromroman load def
	/thorn /.fromroman load def
	/ydieresis /.fromroman load def
	/square {
		pop 750 0 0 0 680 680 setcachedevice
		newpath
		0 0 moveto 680 0 rlineto 0 680 rlineto -680 0 rlineto closepath
		ifelse(squaretype,hollow,
			`50 50 moveto 0 580 rlineto 580 0 rlineto
			0 -580 rlineto closepath',`dnl')
		fill
	} bind def
	/emdash {
		pop 1000 0 125 173 907 242 setcachedevice
		EF setfont 125 0 moveto c3D show
	} bind def
currentdict end
readonly /CharProcs exch def
/RF /romanfont-troff findfont 1000 scalefont def
/EF /expertfont findfont 1000 scalefont def
/buf ( ) def
/c3D (=) rd
FontName currentdict end
definefont pop
%%EndResource
