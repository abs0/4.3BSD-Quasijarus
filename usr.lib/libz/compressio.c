/*
 * This code has been derived from Jean-loup Gailly's zlib.
 * It has been integrated into Berkeley UNIX by Michael Sokolov
 *
 *	@(#)compressio.c	5.1 (Berkeley) 1/19/99
 */

/* This module handles I/O from/to compress -s files */

#include <stdio.h>

#include "zutil.h"

struct internal_state {int dummy;}; /* for buggy compilers */

#define Z_BUFSIZE 4096

#define ALLOC(size) malloc(size)
#define TRYFREE(p) {if (p) free(p);}

typedef struct comp_stream {
    z_stream stream;
    int      z_err;   /* error code for last stream operation */
    int      z_eof;   /* set if end of input file */
    FILE     *file;   /* .Z file */
    Byte     *inbuf;  /* input buffer */
    Byte     *outbuf; /* output buffer */
    uLong    crc;     /* crc32 of uncompressed data */
    char     *msg;    /* error message */
    char     mode;    /* 'w' or 'r' */
} comp_stream;


local compFile comp_open  OF((FILE *file, char mode, int level));
local int    get_byte     OF((comp_stream *s));
local int    destroy      OF((comp_stream *s));
local void   putLong      OF((FILE *file, uLong x));
local uLong  getLong      OF((comp_stream *s));

local compFile comp_open (file, mode, level)
    FILE *file;
    char mode;
    int  level;
{
    int err;
    comp_stream *s;

    if (!file) return Z_NULL;

    s = (comp_stream *)ALLOC(sizeof(comp_stream));
    if (!s) return Z_NULL;

    s->stream.zalloc = (alloc_func)0;
    s->stream.zfree = (free_func)0;
    s->stream.opaque = (voidpf)0;
    s->stream.next_in = s->inbuf = Z_NULL;
    s->stream.next_out = s->outbuf = Z_NULL;
    s->stream.avail_in = s->stream.avail_out = 0;
    s->file = file;
    s->mode = mode;
    s->z_err = Z_OK;
    s->z_eof = 0;
    s->crc = crc32(0L, Z_NULL, 0);
    s->msg = NULL;

    if (s->mode == 'w') {
        err = deflateInit2(&(s->stream), level,
                           Z_DEFLATED, -MAX_WBITS, DEF_MEM_LEVEL, 0);
        /* windowBits is passed < 0 to suppress zlib header */

        s->stream.next_out = s->outbuf = (Byte*)ALLOC(Z_BUFSIZE);

        if (err != Z_OK || s->outbuf == Z_NULL) {
            return destroy(s), (compFile)Z_NULL;
        }
    } else {
        err = inflateInit2(&(s->stream), -MAX_WBITS);
        s->stream.next_in  = s->inbuf = (Byte*)ALLOC(Z_BUFSIZE);

        if (err != Z_OK || s->inbuf == Z_NULL) {
            return destroy(s), (compFile)Z_NULL;
        }
    }
    s->stream.avail_out = Z_BUFSIZE;

    return (compFile)s;
}

compFile compress_open(file, level)
    FILE *file;
    int level;
{
    return comp_open(file, 'w', level);
}

compFile uncompress_open(file)
    FILE *file;
{
    return comp_open(file, 'r');
}

/* ===========================================================================
     Read a byte from a comp_stream; update next_in and avail_in. Return EOF
   for end of file.
   IN assertion: the stream s has been sucessfully opened for reading.
*/
local int get_byte(s)
    comp_stream *s;
{
    if (s->z_eof) return EOF;
    if (s->stream.avail_in == 0) {
	errno = 0;
	s->stream.avail_in = fread(s->inbuf, 1, Z_BUFSIZE, s->file);
	if (s->stream.avail_in == 0) {
	    s->z_eof = 1;
	    if (ferror(s->file)) s->z_err = Z_ERRNO;
	    return EOF;
	}
	s->stream.next_in = s->inbuf;
    }
    s->stream.avail_in--;
    return *(s->stream.next_in)++;
}

 /* ===========================================================================
 * Cleanup then free the given comp_stream. Return a zlib error code.
   Try freeing in the reverse order of allocations.
 */
local int destroy (s)
    comp_stream *s;
{
    int err = Z_OK;

    if (!s) return Z_STREAM_ERROR;

    TRYFREE(s->msg);

    if (s->stream.state != NULL) {
       if (s->mode == 'w') {
           err = deflateEnd(&(s->stream));
       } else if (s->mode == 'r') {
           err = inflateEnd(&(s->stream));
       }
    }
    if (s->z_err < 0) err = s->z_err;

    TRYFREE(s->inbuf);
    TRYFREE(s->outbuf);
    TRYFREE(s);
    return err;
}

/* ===========================================================================
     Reads the given number of uncompressed bytes from the compressed file.
   compread returns the number of bytes actually read (0 for end of file).
*/
int compread (file, buf, len)
    compFile file;
    voidp buf;
    unsigned len;
{
    comp_stream *s = (comp_stream*)file;
    Bytef *start = buf; /* starting point for crc computation */
    Byte  *next_out; /* == stream.next_out but not forced far (for MSDOS) */

    if (s == NULL || s->mode != 'r') return Z_STREAM_ERROR;

    if (s->z_err == Z_DATA_ERROR || s->z_err == Z_ERRNO) return -1;
    if (s->z_err == Z_STREAM_END) return 0;  /* EOF */

    s->stream.next_out = next_out = buf;
    s->stream.avail_out = len;

    while (s->stream.avail_out != 0) {

        if (s->stream.avail_in == 0 && !s->z_eof) {

            errno = 0;
            s->stream.avail_in = fread(s->inbuf, 1, Z_BUFSIZE, s->file);
            if (s->stream.avail_in == 0) {
                s->z_eof = 1;
		if (ferror(s->file)) {
		    s->z_err = Z_ERRNO;
		    break;
		}
            }
            s->stream.next_in = s->inbuf;
        }
        s->z_err = inflate(&(s->stream), Z_NO_FLUSH);

	if (s->z_err == Z_STREAM_END) {
	    /* Check CRC and original size */
	    s->crc = crc32(s->crc, start, (uInt)(s->stream.next_out - start));
	    start = s->stream.next_out;

	    if (getLong(s) != s->crc || getLong(s) != s->stream.total_out) {
		s->z_err = Z_DATA_ERROR;
	    }
	}
	if (s->z_err != Z_OK || s->z_eof) break;
    }
    s->crc = crc32(s->crc, start, (uInt)(s->stream.next_out - start));

    return (int)(len - s->stream.avail_out);
}

/* ===========================================================================
     Writes the given number of uncompressed bytes into the compressed file.
   compwrite returns the number of bytes actually written (0 in case of error).
*/
int compwrite (file, buf, len)
    compFile file;
    const voidp buf;
    unsigned len;
{
    comp_stream *s = (comp_stream*)file;

    if (s == NULL || s->mode != 'w') return Z_STREAM_ERROR;

    s->stream.next_in = buf;
    s->stream.avail_in = len;

    while (s->stream.avail_in != 0) {

        if (s->stream.avail_out == 0) {

            s->stream.next_out = s->outbuf;
            if (fwrite(s->outbuf, 1, Z_BUFSIZE, s->file) != Z_BUFSIZE) {
                s->z_err = Z_ERRNO;
                break;
            }
            s->stream.avail_out = Z_BUFSIZE;
        }
        s->z_err = deflate(&(s->stream), Z_NO_FLUSH);
        if (s->z_err != Z_OK) break;
    }
    s->crc = crc32(s->crc, buf, len);

    return (int)(len - s->stream.avail_in);
}

/* ===========================================================================
     Flushes all pending output into the compressed file. The parameter
   flush is as in the deflate() function.
     compflush should be called only when strictly necessary because it can
   degrade compression.
*/
int compflush (file, flush)
    compFile file;
    int flush;
{
    uInt len;
    int done = 0;
    comp_stream *s = (comp_stream*)file;

    if (s == NULL || s->mode != 'w') return Z_STREAM_ERROR;

    s->stream.avail_in = 0; /* should be zero already anyway */

    for (;;) {
        len = Z_BUFSIZE - s->stream.avail_out;

        if (len != 0) {
            if ((uInt)fwrite(s->outbuf, 1, len, s->file) != len) {
                s->z_err = Z_ERRNO;
                return Z_ERRNO;
            }
            s->stream.next_out = s->outbuf;
            s->stream.avail_out = Z_BUFSIZE;
        }
        if (done) break;
        s->z_err = deflate(&(s->stream), flush);

        /* deflate has finished flushing only when it hasn't used up
         * all the available space in the output buffer: 
         */
        done = (s->stream.avail_out != 0 || s->z_err == Z_STREAM_END);
 
        if (s->z_err != Z_OK && s->z_err != Z_STREAM_END) break;
    }
    fflush(s->file);
    return  s->z_err == Z_STREAM_END ? Z_OK : s->z_err;
}

/* ===========================================================================
   Outputs a long in LSB order to the given file
*/
local void putLong (file, x)
    FILE *file;
    uLong x;
{
    int n;
    for (n = 0; n < 4; n++) {
        fputc((int)(x & 0xff), file);
        x >>= 8;
    }
}

/* ===========================================================================
   Reads a long in LSB order from the given comp_stream. Sets 
*/
local uLong getLong (s)
    comp_stream *s;
{
    uLong x = (uLong)get_byte(s);
    int c;

    x += ((uLong)get_byte(s))<<8;
    x += ((uLong)get_byte(s))<<16;
    c = get_byte(s);
    if (c == EOF) s->z_err = Z_DATA_ERROR;
    x += ((uLong)c)<<24;
    return x;
}

/* ===========================================================================
     Flushes all pending output if necessary and deallocates all the
     (de)compression state.
*/
int compclose (file)
    compFile file;
{
    int err;
    comp_stream *s = (comp_stream*)file;

    if (s == NULL) return Z_STREAM_ERROR;

    if (s->mode == 'w') {
        err = compflush (file, Z_FINISH);
        if (err != Z_OK) return destroy(file);

        putLong (s->file, s->crc);
        putLong (s->file, s->stream.total_in);

    }
    return destroy(file);
}

/* ===========================================================================
     Returns the error message for the last error which occured on the
   given compressed file. errnum is set to zlib error number. If an
   error occured in the file system and not in the compression library,
   errnum is set to Z_ERRNO and the application may consult errno
   to get the exact error code.
*/
const char*  comperror (file, errnum)
    compFile file;
    int *errnum;
{
    char *m;
    comp_stream *s = (comp_stream*)file;

    if (s == NULL) {
        *errnum = Z_STREAM_ERROR;
        return (const char*)ERR_MSG(Z_STREAM_ERROR);
    }
    *errnum = s->z_err;
    if (*errnum == Z_OK) return (const char*)"";

    m =  (char*)(*errnum == Z_ERRNO ? zstrerror(errno) : s->stream.msg);

    if (m == NULL || *m == '\0') m = (char*)ERR_MSG(s->z_err);

    TRYFREE(s->msg);
    s->msg = (char*)ALLOC(strlen(m) + 1);
    strcpy(s->msg, m);
    return (const char*)s->msg;
}
