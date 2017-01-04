/*
 * Experimental support for synchronous and sync/async switchable
 * serial interfaces.
 *
 *	%W% (Berkeley) %E%
 */

#define	WIOCASYNCMODE	_IO(S, 0)
#define	WIOCHDLCENGAGE	_IOW(S, 1, struct hdlc_engage)
#define	WIOCSHUTDOWN	_IO(S, 2)
/* unfortunately some things will have to be device-dependent */
#define	WIOCDSV11MODES	_IOW(S, 3, int)

struct hdlc_engage {
	int	hdlc_app;
	int	hdlc_unit;
	int	hdlc_modes;
};

#define	HDLC_APP_USER		1
#define	HDLC_APP_FR		2
#define	HDLC_APP_PPP		3
#define	HDLC_APP_CISCO		4

#define	HDLC_MODE_IDLEFLAGS	1
#define	HDLC_MODE_CRC32		2
#define	HDLC_MODE_NRZI		4
#define	HDLC_MODE_IGNORECD	8
