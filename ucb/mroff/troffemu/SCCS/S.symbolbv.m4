h08482
s 00017/00006/00401
d D 2.2 2012/03/11 17:37:27 msokolov 2 1
c all 11 chars of the bv family are in boldvertical.m4
e
s 00407/00000/00000
d D 2.1 2012/03/10 04:05:24 msokolov 1 0
c date and time created 2012/03/10 04:05:24 by msokolov
e
u
U
t
T
I 1
dnl	%W%	(Berkeley)	%E%
I 2
dnl
dnl We could have used m4 includes to replicate the common parts
dnl between TroffEmu-Symbol and TroffEmu-SymbolBV, such that the two
dnl stay in sync automatically, yet each font resource file is fully
dnl self-contained like Type 1 fonts are supposed to be.
dnl
dnl However, the expectation is that documents troffed with -Tbv will
dnl inevitably get merged with those troffed with just -T, hence the
dnl final book product (such as the PS reprint of the original 4.3BSD
dnl USD book) will contain both TroffEmu-Symbol and TroffEmu-SymbolBV.
dnl Therefore, if we handle the common parts at the PostScript level
dnl rather than in m4, our final PS product will be shorter and will
dnl use less VM.  Hence that's what we do: we reuse the entire Private
dnl dictionary and the charstring bodies for all unchanged characters
dnl from TroffEmu-Symbol, which must already be in VM.
dnl Totally non-kosher for a Type 1 font, but...
dnl
E 2
%!PS-Adobe-3.0 Resource-Font
%%DocumentNeededResources: font TroffEmu-Symbol
%%BeginResource: font TroffEmu-SymbolBV
11 dict begin
/FontInfo 10 dict dup begin
/version (%I% %E%) readonly def
/Notice (Based on Adobe Symbol with 4.3BSD-Quasijarus troff modifications) readonly def
/FullName (Troff Emulation Symbol BV) readonly def
/FamilyName (Troff Emulation) readonly def
/Weight (Medium) readonly def
/ItalicAngle 0 def
/isFixedPitch false def
/UnderlinePosition -98 def
/UnderlineThickness 54 def
end readonly def
/FontName /TroffEmu-SymbolBV def
/Encoding 256 array
0 1 255 {1 `index' exch /.notdef put} for
dup 32 /space put
dup 33 /exclam put
dup 34 /universal put
dup 35 /numbersign put
dup 36 /existential put
dup 37 /percent put
dup 38 /ampersand put
dup 39 /suchthat put
dup 40 /parenleft put
dup 41 /parenright put
dup 42 /asteriskmath put
dup 43 /plus put
dup 44 /comma put
dup 45 /minus put
dup 46 /period put
dup 47 /slash put
dup 48 /zero put
dup 49 /one put
dup 50 /two put
dup 51 /three put
dup 52 /four put
dup 53 /five put
dup 54 /six put
dup 55 /seven put
dup 56 /eight put
dup 57 /nine put
dup 58 /colon put
dup 59 /semicolon put
dup 60 /less put
dup 61 /equal put
dup 62 /greater put
dup 63 /question put
dup 64 /congruent put
dup 65 /Alpha put
dup 66 /Beta put
dup 67 /Chi put
dup 68 /Delta put
dup 69 /Epsilon put
dup 70 /Phi put
dup 71 /Gamma put
dup 72 /Eta put
dup 73 /Iota put
dup 74 /theta1 put
dup 75 /Kappa put
dup 76 /Lambda put
dup 77 /Mu put
dup 78 /Nu put
dup 79 /Omicron put
dup 80 /Pi put
dup 81 /Theta put
dup 82 /Rho put
dup 83 /Sigma put
dup 84 /Tau put
dup 85 /Upsilon put
dup 86 /sigma1 put
dup 87 /Omega put
dup 88 /Xi put
dup 89 /Psi put
dup 90 /Zeta put
dup 91 /bracketleft put
dup 92 /therefore put
dup 93 /bracketright put
dup 94 /perpendicular put
dup 95 /underscore put
dup 96 /radicalex put
dup 97 /alpha put
dup 98 /beta put
dup 99 /chi put
dup 100 /delta put
dup 101 /epsilon put
dup 102 /phi put
dup 103 /gamma put
dup 104 /eta put
dup 105 /iota put
dup 106 /phi1 put
dup 107 /kappa put
dup 108 /lambda put
dup 109 /mu put
dup 110 /nu put
dup 111 /omicron put
dup 112 /pi put
dup 113 /theta put
dup 114 /rho put
dup 115 /sigma put
dup 116 /tau put
dup 117 /upsilon put
dup 118 /omega1 put
dup 119 /omega put
dup 120 /xi put
dup 121 /psi put
dup 122 /zeta put
dup 123 /braceleft put
dup 124 /bar put
dup 125 /braceright put
dup 126 /similar put
dup 161 /Upsilon1 put
dup 162 /minute put
dup 163 /lessequal put
dup 164 /fraction put
dup 165 /infinity put
dup 166 /florin put
dup 167 /club put
dup 168 /diamond put
dup 169 /heart put
dup 170 /spade put
dup 171 /arrowboth put
dup 172 /arrowleft put
dup 173 /arrowup put
dup 174 /arrowright put
dup 175 /arrowdown put
dup 176 /degree put
dup 177 /plusminus put
dup 178 /second put
dup 179 /greaterequal put
dup 180 /multiply put
dup 181 /proportional put
dup 182 /partialdiff put
dup 183 /bullet put
dup 184 /divide put
dup 185 /notequal put
dup 186 /equivalence put
dup 187 /approxequal put
dup 188 /ellipsis put
dup 189 /arrowvertex put
dup 190 /arrowhorizex put
dup 191 /carriagereturn put
dup 192 /aleph put
dup 193 /Ifraktur put
dup 194 /Rfraktur put
dup 195 /weierstrass put
dup 196 /circlemultiply put
dup 197 /circleplus put
dup 198 /emptyset put
dup 199 /intersection put
dup 200 /union put
dup 201 /propersuperset put
dup 202 /reflexsuperset put
dup 203 /notsubset put
dup 204 /propersubset put
dup 205 /reflexsubset put
dup 206 /element put
dup 207 /notelement put
dup 208 /angle put
dup 209 /gradient put
dup 210 /registerserif put
dup 211 /copyrightserif put
dup 212 /trademarkserif put
dup 213 /product put
dup 214 /radical put
dup 215 /dotmath put
dup 216 /logicalnot put
dup 217 /logicaland put
dup 218 /logicalor put
dup 219 /arrowdblboth put
dup 220 /arrowdblleft put
dup 221 /arrowdblup put
dup 222 /arrowdblright put
dup 223 /arrowdbldown put
dup 224 /lozenge put
dup 225 /angleleft put
dup 226 /registersans put
dup 227 /copyrightsans put
dup 228 /trademarksans put
dup 229 /summation put
dup 230 /parenlefttp put
dup 231 /parenleftex put
dup 232 /parenleftbt put
dup 233 /bracketlefttp put
dup 234 /boldvertical put
dup 235 /bracketleftbt put
dup 236 /bracelefttp put
dup 237 /braceleftmid put
dup 238 /braceleftbt put
dup 239 /boldvertical put
dup 240 /bellsystem put
dup 241 /angleright put
dup 242 /integral put
dup 243 /integraltp put
dup 244 /integralex put
dup 245 /integralbt put
dup 246 /parenrighttp put
dup 247 /parenrightex put
dup 248 /parenrightbt put
dup 249 /bracketrighttp put
dup 250 /boldvertical put
dup 251 /bracketrightbt put
dup 252 /bracerighttp put
dup 253 /bracerightmid put
dup 254 /bracerightbt put
readonly def
/PaintType 0 def
/FontType 1 def
/FontMatrix [0.001 0 0 0.001 0 0] readonly def
/FontBBox{-180 -293 1090 1010}readonly def
currentdict end
/TroffEmu-Symbol findfont
dup /Private get 2 `index' /Private 3 -1 roll put
/CharStrings get
188 dict begin
define(`ccopy', `dup 2 `index' exch get def')dnl
/.notdef ccopy
/space ccopy
/exclam ccopy
/universal ccopy
/numbersign ccopy
/existential ccopy
/percent ccopy
/ampersand ccopy
/suchthat ccopy
/parenleft ccopy
/parenright ccopy
/asteriskmath ccopy
/plus ccopy
/comma ccopy
/minus ccopy
/period ccopy
/slash ccopy
/zero ccopy
/one ccopy
/two ccopy
/three ccopy
/four ccopy
/five ccopy
/six ccopy
/seven ccopy
/eight ccopy
/nine ccopy
/colon ccopy
/semicolon ccopy
/less ccopy
/equal ccopy
/greater ccopy
/question ccopy
/congruent ccopy
/Alpha ccopy
/Beta ccopy
/Chi ccopy
/Delta ccopy
/Epsilon ccopy
/Phi ccopy
/Gamma ccopy
/Eta ccopy
/Iota ccopy
/theta1 ccopy
/Kappa ccopy
/Lambda ccopy
/Mu ccopy
/Nu ccopy
/Omicron ccopy
/Pi ccopy
/Theta ccopy
/Rho ccopy
/Sigma ccopy
/Tau ccopy
/Upsilon ccopy
/sigma1 ccopy
/Omega ccopy
/Xi ccopy
/Psi ccopy
/Zeta ccopy
/bracketleft ccopy
/therefore ccopy
/bracketright ccopy
/perpendicular ccopy
/underscore ccopy
/radicalex ccopy
/alpha ccopy
/beta ccopy
/chi ccopy
/delta ccopy
/epsilon ccopy
/phi ccopy
/gamma ccopy
/eta ccopy
/iota ccopy
/phi1 ccopy
/kappa ccopy
/lambda ccopy
/mu ccopy
/nu ccopy
/omicron ccopy
/pi ccopy
/theta ccopy
/rho ccopy
/sigma ccopy
/tau ccopy
/upsilon ccopy
/omega1 ccopy
/omega ccopy
/xi ccopy
/psi ccopy
/zeta ccopy
/braceleft ccopy
/bar ccopy
/braceright ccopy
/similar ccopy
/Upsilon1 ccopy
/minute ccopy
/lessequal ccopy
/fraction ccopy
/infinity ccopy
/florin ccopy
/club ccopy
/diamond ccopy
/heart ccopy
/spade ccopy
/arrowboth ccopy
/arrowleft ccopy
/arrowup ccopy
/arrowright ccopy
/arrowdown ccopy
/degree ccopy
/plusminus ccopy
/second ccopy
/greaterequal ccopy
/multiply ccopy
/proportional ccopy
/partialdiff ccopy
/bullet ccopy
/divide ccopy
/notequal ccopy
/equivalence ccopy
/approxequal ccopy
/ellipsis ccopy
/arrowvertex ccopy
/arrowhorizex ccopy
/carriagereturn ccopy
/aleph ccopy
/Ifraktur ccopy
/Rfraktur ccopy
/weierstrass ccopy
/circlemultiply ccopy
/circleplus ccopy
/emptyset ccopy
/intersection ccopy
/union ccopy
/propersuperset ccopy
/reflexsuperset ccopy
/notsubset ccopy
/propersubset ccopy
/reflexsubset ccopy
/element ccopy
/notelement ccopy
/angle ccopy
/gradient ccopy
/registerserif ccopy
/copyrightserif ccopy
/trademarkserif ccopy
/product ccopy
/radical ccopy
/dotmath ccopy
/logicalnot ccopy
/logicaland ccopy
/logicalor ccopy
/arrowdblboth ccopy
/arrowdblleft ccopy
/arrowdblup ccopy
/arrowdblright ccopy
/arrowdbldown ccopy
/lozenge ccopy
/angleleft ccopy
/registersans ccopy
/copyrightsans ccopy
/trademarksans ccopy
/summation ccopy
/parenlefttp ccopy
/parenleftex ccopy
/parenleftbt ccopy
/angleright ccopy
/integral ccopy
/integraltp ccopy
/integralex ccopy
/integralbt ccopy
/parenrighttp ccopy
/parenrightex ccopy
/parenrightbt ccopy
D 2
/bracelefttp ccopy
/braceleftmid ccopy
/braceleftbt ccopy
/bracerighttp ccopy
/bracerightmid ccopy
/bracerightbt ccopy
E 2
/bellsystem ccopy
pop
include(boldvertical.m4)dnl
dup currentdict end readonly /CharStrings exch put
dup /FontName get exch definefont pop
%%EndResource
E 1
