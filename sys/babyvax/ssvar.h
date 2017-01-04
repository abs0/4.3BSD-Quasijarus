/*
 * ss driver kludge definitions
 * for dm-mimicking modem control handling
 *
 *	@(#)ssvar.h	7.1 (Berkeley) 3/22/04
 */

/* bits in dm lsr, copied from dmreg.h */
#define	DML_DSR		0000400		/* data set ready, not a real DM bit */
#define	DML_RNG		0000200		/* ring */
#define	DML_CAR		0000100		/* carrier detect */
#define	DML_CTS		0000040		/* clear to send */
#define	DML_SR		0000020		/* secondary receive */
#define	DML_ST		0000010		/* secondary transmit */
#define	DML_RTS		0000004		/* request to send */
#define	DML_DTR		0000002		/* data terminal ready */
#define	DML_LE		0000001		/* line enable */

/* virtual ss lsr bits = (ssmctl << 16) | ssmsr */
#define	SSL_LLBK	0x080000
#define	SSL_DTR		0x040000
#define	SSL_DSRS	0x020000
#define	SSL_RTS		0x010000
#define	SSL_SPDI	0x000800
#define	SSL_CD		0x000400
#define	SSL_DSR		0x000200
#define	SSL_CTS		0x000100
#define	SSL_RI		0x000004
#define	SSL_TMI		0x000001
