/*
 * This header file defines the format of pstroff ftXX files,
 * which replace the previous fwXX and fsXX.  The main motivation
 * for the change is to have just one file per font; that in turn
 * makes it easier to implement search paths.
 *
 * An ftXX file contains the following information:
 *
 * - width table identical to the old fwXX
 * - PostScript fetching code block identical to the old fsXX
 * - flag indicating Symbol special (no more hard-coded magic names!)
 * - optional definitions of non-standard named \(xx characters
 *
 *	@(#)fontinfo.h	5.2 (Berkeley) 2012/07/14
 */

/* Each ftXX file begins with this fixed header structure */

struct fontinfo_hdr {
	u_long	magic;
	u_long	width_offset;
	u_long	setup_offset;
	u_long	setup_len;
	u_long	lchars_offset;
	u_long	schars_offset;
	u_long	flags;
};

#define	FONTINFO_MAGIC	0x8000FDEF

#define	FONTINFO_FLAGS_SYMBOL	0x80000000
#define	FONTINFO_FLAGS_CWIDTH	0x40000000
#define	FONTINFO_FLAGS_NOLIG	0x20000000
#define	FONTINFO_FLAGS_CYRILLIC	0x00000002
#define	FONTINFO_FLAGS_ROMAN	0x00000001

/*
 * All information in an ftXX file other than the file header has
 * variable length (exception: the width table is always 512 bytes long)
 * and is found at variable offsets in the file.  Each section is a
 * contiguous binary blob, but the order of these sections isn't fixed.
 * Instead the file header contains a pointer to each section,
 * given as an offset from the beginning of the file.
 */

/*
 * The width and setup sections are mandatory.
 *
 * The width table is an array of 256 16-bit shorts, each giving
 * the spacing width of the character at the corresponding code point.
 * The widths are given in .001m units as per Adobe's convention.
 *
 * The setup section is an ASCII string with embedded newlines
 * which is to be emitted literally into pstroff output without
 * any further manipulation.  The length of this string is indicated
 * in two ways: the string is followed by a terminating NUL, and
 * its length is also given explicitly in the file header.
 */

/*
 * The two optional sections list "local" and "special" named characters.
 * Each such section, if present, begins with the following structure,
 * which is then immediately followed by an array of
 * {int charname; int charcode;} pairs.  The array is terminated
 * with a {0, 0} pair, and the count of actual definitions (not including
 * the terminator) is given in the nchars field.
 */
struct chardef_section {
	struct	chardef_section *next;	/* leave NULL in ftNN files */
	int	nchars;
};
