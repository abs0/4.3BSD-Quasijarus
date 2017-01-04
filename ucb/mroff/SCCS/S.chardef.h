h03860
s 00043/00000/00000
d D 5.1 2012/03/04 05:29:15 msokolov 1 0
c troffchar written, compiles
e
u
U
t
T
I 1
/*
 * PostScript Troff character set extension mechanism
 *
 * For each font NN the required files are fwNN and fsNN.
 * The third optional file fcNN facilitates character set extension.
 * This file may assign names to characters in this font
 * for local entry (allowing symbolic \(NN instead of numeric \Xnn,
 * but still meaningful only when this font is explicitly active),
 * declare global (special) named chars which act like multiple
 * special fonts in ditroff, or declare the present font as being
 * Symbol special.
 *
 * fcNN files are binary with the following structure:
 *
 * At the beginning: struct chardef_hdr, which contains a magic signature,
 * global flags, and pointers to the two optional sections.
 * Optional sections: one for local named chars, one for "special"
 * named chars; each may be located anywhere in the file on a 4-byte
 * boundary; the header contains pointers given as byte offsets from
 * the beginning of the file.
 *
 * Each optional section defining a set of named chars (local or global)
 * begins with struct chardef_section, which is then immediately followed
 * by an array of {int charname; int charcode;} pairs.
 *
 *	%W% (Berkeley) %E%
 */

struct chardef_hdr {
	u_long	magic;
	u_long	lchars_offset;
	u_long	schars_offset;
	u_long	flags;
};

#define	CHARDEF_MAGIC	0x8000CDEF

#define	CHARDEF_FLAGS_SYMBOL	0x80000000

struct chardef_section {
	struct	chardef_section *next;	/* leave NULL in fcNN files */
	int	nchars;
};
E 1
