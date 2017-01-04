.sp
.SH
.ce
.LG
4.3BSD-Quasijarus1 changes
.SM
.sp
.IP \s+1\(bu\s0
.I Ftpd
can now automatically invoke
.IR gzcompat ,
so if, for example, you have file.Z on your FTP site
and someone requests to download file.gz, or vice-versa,
.I ftpd
will convert the file on the fly.
