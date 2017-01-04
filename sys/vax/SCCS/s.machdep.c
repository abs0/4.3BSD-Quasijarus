h51693
s 00002/00002/01046
d D 7.22 05/08/25 01:33:52 msokolov 190 189
c microtime:	check for tv_usec overflow needs to be >= 1000000, not >
e
s 00018/00000/01030
d D 7.21 04/03/20 00:01:16 msokolov 189 188
c BabyVAX CPMBX functions
e
s 00077/00005/00953
d D 7.20 04/03/18 19:19:22 msokolov 188 187
c add BabyVAX support (beginnings thereof)
c a few other todo closures and fixes along the way
e
s 00046/00000/00912
d D 7.19 04/01/08 05:36:01 msokolov 187 186
c add sigemu syscall
e
s 00004/00003/00908
d D 7.18 03/05/03 13:35:42 msokolov 186 185
c sigreturn:	don't allow PSL<CM> on CPUs w/o compat mode (res op fault)
c also sigreturn and osigcleanup need only user read access to arguments
e
s 00000/00007/00911
d D 7.17 88/09/22 06:39:13 tef 185 184
c console scratchpad space already reserved in locore.s - don't do twice
e
s 00025/00002/00893
d D 7.16 88/09/06 13:31:48 tef 184 183
c do halts and reboots properly on ka650 processor
e
s 00007/00005/00888
d D 7.15 88/08/27 07:01:20 tef 183 182
c Add support for microvax 3000.
e
s 00002/00004/00891
d D 7.14 88/05/26 09:37:28 karels 182 181
c lint
e
s 00001/00001/00894
d D 7.13 88/05/19 15:21:40 karels 181 180
c rename KDB => KADB
e
s 00095/00522/00800
d D 7.12 88/05/07 14:19:47 karels 180 179
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00003/00004/01319
d D 7.11 88/04/23 13:01:31 karels 179 177
c add msgbufmapped
e
s 00000/00000/01311
d D 7.9.1.2 87/12/15 16:20:53 karels 178 176
i 177
c new branch for tahoe release (add 7.10)
e
s 00002/00000/01321
d D 7.10 87/12/10 18:43:56 karels 177 175
c watch out for bogus combinations of vax options with compat mode
e
s 00000/00000/01309
d D 7.9.1.1 87/11/30 10:51:21 karels 176 175
x 174 172
c branch for tahoe release (no malloc)
e
s 00030/00000/01291
d D 7.9 87/10/23 11:03:40 bostic 175 174
c add time of day register routine; (Chris Torek)
e
s 00008/00000/01283
d D 7.8 87/08/07 15:56:26 marc 174 173
c changes for qdss support
e
s 00003/00001/01280
d D 7.7 87/06/30 23:35:20 karels 173 172
c don't trip over locked inodes, etc, freeing text
e
s 00004/00000/01277
d D 7.6 87/06/20 12:16:48 mckusick 172 171
c allocation of malloc map and usage structure; kmem initialization
e
s 00011/00009/01266
d D 7.5 87/04/02 16:34:33 karels 171 170
c minor fixes on boot sync
e
s 00003/00003/01272
d D 7.4 87/02/26 18:08:51 karels 170 169
c do reboot more flexibly
e
s 00020/00000/01255
d D 7.3 87/02/21 11:19:05 karels 169 168
c kdb (for sam; untested); misc.
e
s 00011/00001/01244
d D 7.2 86/08/09 15:13:21 karels 168 167
c qvss console hack
e
s 00001/00001/01244
d D 7.1 86/06/05 00:44:40 mckusick 167 166
c 4.3BSD release version
e
s 00000/00001/01245
d D 6.30 86/06/02 14:36:37 karels 166 165
c lint
e
s 00001/00001/01245
d D 6.29 86/05/27 15:19:58 karels 165 164
c typo
e
s 00055/00003/01191
d D 6.28 86/04/22 10:49:47 kridle 164 163
c Added MicroVAX II Support (KA630)
e
s 00000/00001/01194
d D 6.27 86/03/04 19:19:41 karels 163 162
c lint
e
s 00001/00001/01194
d D 6.26 86/02/23 23:06:43 karels 162 161
c lint
e
s 00001/00001/01194
d D 6.25 86/02/20 21:26:53 karels 161 160
c rename nch to avoid name conflict
e
s 00031/00002/01164
d D 6.24 86/02/20 20:42:45 karels 160 157
c modify microtime to handle pending clock ticks,
c prevent time from going backward during correction
c (instead guarantee unique and monotonically increasing timestamps);
c lint
e
s 00030/00002/01164
d R 6.24 86/02/20 09:56:22 karels 159 157
c modify microtime to handle pending clock ticks,
c prevent time from going backward during correction
c (instead guarantee unique and monotonically increasing timestamps);
c lint
e
s 00030/00002/01164
d R 6.24 86/02/19 22:02:23 karels 158 157
c modify microtime to handle pending clock ticks,
c prevent time from going backward during correction
c (instead guarantee unique and monotonically increasing timestamps);
e
s 00014/00007/01152
d D 6.23 86/01/13 17:53:12 karels 157 156
c flush text cache and resynch todr clock on boot;
c fix and use microtime; more spl[67]'s bite the dust
e
s 00037/00005/01122
d D 6.22 85/09/16 20:59:48 karels 156 155
c rearrange tocons bits for 8600 support; let's get the useracc
c RW flag right (maybe use symbolic defn's?)
e
s 00076/00015/01051
d D 6.21 85/09/07 22:45:53 bloom 155 154
c 8600 cleanup, add defines for constants, improve memory error handling
e
s 00033/00027/01033
d D 6.20 85/09/04 08:17:26 karels 154 153
c mbcluster map is full-sized now; rearrange cpu-specific setup
e
s 00126/00022/00934
d D 6.19 85/08/05 18:51:09 bloom 153 152
c add support for 8600
e
s 00002/00002/00954
d D 6.18 85/07/29 10:57:01 bloom 152 151
c TBIA is docummented as "must be zero"
e
s 00001/00001/00955
d D 6.17 85/07/02 18:04:40 mckusick 151 150
c spelling
e
s 00007/00001/00949
d D 6.16 85/06/08 13:42:48 mckusick 150 149
c Add copyright
e
s 00018/00000/00932
d D 6.15 85/06/03 08:47:19 karels 149 148
c move setregs to machine-dependent dir
e
s 00000/00014/00932
d D 6.14 85/04/28 17:56:03 karels 148 147
c move icode to locore, as asm instead of hex; exit if can't exec init
e
s 00089/00070/00857
d D 6.13 85/03/11 16:12:50 mckusick 147 146
c new signal code to push all context onto the signal stack
e
s 00007/00002/00920
d D 6.12 85/03/03 17:22:10 mckusick 146 145
c only allocate 5% of memory to the buffer pool after the first 2M
e
s 00092/00064/00830
d D 6.11 85/03/01 14:03:50 karels 145 144
c rearrange physical layout of kernel (buffers last, so 1:1)
e
s 00022/00015/00872
d D 6.10 84/12/20 15:07:11 karels 144 143
c fixes for 730 memerrors; wait a bit longer for sync; minor fixup
c for 750 tbuf parity machinechecks
e
s 00008/00010/00879
d D 6.9 84/09/05 17:43:02 karels 143 142
c sigmask macro is in signal.h;
c splnet instead of spl1 in boot (don't panic again if from net);
c printf("syncing... before update, so we see it if the update faults
e
s 00029/00029/00860
d D 6.8 84/08/28 18:09:52 bloom 142 141
c Change to includes.  No more ../h
e
s 00001/00001/00888
d D 6.7 84/08/03 12:07:10 karels 141 140
c In boot, only spl1() if syncing
e
s 00000/00001/00889
d D 6.6 84/07/08 15:32:57 sam 140 139
c nami.h now included by user.,h
e
s 00005/00002/00885
d D 6.5 84/03/22 15:26:52 karels 139 138
c distinguish hard memory errors from soft ecc's on 750's
e
s 00039/00017/00848
d D 6.4 84/02/02 11:32:00 karels 138 137
c support for M780E (from salkind@nyu)
e
s 00002/00000/00863
d D 6.3 84/01/03 23:45:36 mckusick 137 136
c add system wide cacheing of path names in namei() (from kre)
e
s 00004/00004/00859
d D 6.2 83/10/02 11:53:53 sam 136 135
c boot ignores INVAL buffers when waiting for sync
e
s 00000/00000/00863
d D 6.1 83/08/20 15:31:19 sam 135 134
c 4.2 distribution
e
s 00034/00028/00829
d D 4.88 83/08/20 15:30:46 sam 134 132
c rewrite sendsig to eliminate pushing stuff by hand
e
s 00000/00000/00857
d R 6.1 83/08/14 19:59:47 sam 133 132
c 4.2 distribution
e
s 00056/00025/00801
d D 4.87 83/08/14 14:30:43 sam 132 130
c correct handling of signal stack
e
s 00000/00000/00826
d R 6.1 83/07/29 07:20:22 sam 131 130
c 4.2 distribution
e
s 00002/00000/00824
d D 4.86 83/07/20 23:37:52 sam 130 129
c this could be dangerous, but otherwise new config stuff meaningless
e
s 00004/00002/00820
d D 4.85 83/07/09 19:08:43 kre 129 128
c fix syndrome report for 750 mem errs (do it 730 way)
e
s 00005/00002/00817
d D 4.84 83/07/09 01:15:45 sam 128 127
c insure longword aligned access for 730
e
s 00000/00002/00819
d D 4.83 83/06/19 15:27:54 root 127 126
c take out notdef now that I'm not working on matisse's console
e
s 00003/00005/00818
d D 4.82 83/06/19 15:26:57 root 126 125
c avoid restarting on hard errors
e
s 00001/00001/00822
d D 4.81 83/06/13 23:02:09 sam 125 124
c lint
e
s 00016/00013/00807
d D 4.80 83/06/09 22:02:04 sam 124 123
c "final" sigvec interface?
e
s 00056/00014/00764
d D 4.79 83/06/02 15:59:42 sam 123 122
c new signals
e
s 00000/00016/00778
d D 4.78 83/05/21 15:58:18 sam 122 121
c purge mush
e
s 00002/00002/00792
d D 4.77 83/05/18 02:09:43 sam 121 120
c support multiple variable sized swap areas (some from shannon)
e
s 00003/00000/00791
d D 4.76 83/02/21 00:24:22 sam 120 119
c mods to make savecore more machine independent
e
s 00001/00001/00790
d D 4.75 83/02/11 08:08:11 sam 119 117
c remove /usr/include dependencies
e
s 00001/00001/00790
d R 4.75 83/02/10 21:58:05 sam 118 117
c remove /usr/include dependencies
e
s 00026/00003/00765
d D 4.74 83/01/16 16:10:10 mckusick 117 116
c handle boundry conditions in allocating buffers
e
s 00003/00000/00765
d D 4.73 83/01/12 17:16:16 sam 116 115
c bill broke vax with sun mods
e
s 00004/00003/00761
d D 4.72 82/12/17 11:56:18 sam 115 114
c sun merge
e
s 00035/00013/00729
d D 4.71 82/11/13 22:58:28 sam 114 113
c merge of 4.1b with 4.1c
e
s 00013/00000/00729
d D 4.70 82/11/03 01:23:05 root 113 112
c add physstrat; typo in locore.s
e
s 00000/00107/00729
d D 4.69 82/10/31 15:28:42 root 112 111
c clock routines to clock.c
e
s 00000/00000/00836
d D 4.68 82/10/23 10:08:38 root 111 110
c more lint
e
s 00004/00003/00832
d D 4.67 82/10/21 23:56:43 root 110 109
c lint
e
s 00002/00012/00833
d D 4.66 82/10/20 02:46:00 root 109 108
c lint
e
s 00001/00001/00844
d D 4.65 82/10/20 01:37:19 root 108 107
c lint
e
s 00009/00008/00836
d D 4.64 82/10/13 22:14:30 root 107 106
c rearrange header files
e
s 00002/00002/00842
d D 4.63 82/10/05 22:52:36 root 106 105
c correct comments
e
s 00002/00002/00842
d D 4.62 82/10/04 20:51:55 root 105 104
c back to gmt in clock
e
s 00039/00012/00805
d D 4.61 82/09/04 09:31:46 root 104 103
c more time stuff done here
e
s 00008/00000/00809
d D 4.60 82/08/13 00:28:56 root 103 102
c handle tbuf parity errors
e
s 00002/00002/00807
d D 4.59 82/07/22 21:53:49 kre 102 101
c typos in comments
e
s 00021/00000/00788
d D 4.58 82/07/22 21:52:20 kre 101 100
c mush, dis quotas
e
s 00006/00004/00782
d D 4.57 82/07/15 20:29:50 root 100 99
c keep time in machine as localtime to keep vims happy
e
s 00060/00000/00726
d D 4.56 82/06/26 22:16:32 sam 99 98
c memlog for trendata boards (from lucas)
e
s 00000/00000/00726
d D 4.55 82/06/14 23:20:55 root 98 95
i 97 96
c update to new file system
e
s 00005/00005/00720
d D 4.52.1.2 82/06/14 23:16:24 root 97 96
c update to new file system
e
s 00000/00000/00725
d D 4.52.1.1 82/06/14 23:15:25 root 96 93
c branch-place-holder
e
s 00020/00020/00706
d D 4.54 82/05/26 15:39:10 sam 95 94
c 7ZZ -> 730
e
s 00002/00001/00724
d D 4.53 82/05/19 15:58:16 sam 94 93
c rminit had wrong parameter
e
s 00009/00004/00716
d D 4.52 82/03/15 04:47:13 wnj 93 92
c shutdown; clear suid; get/set hostname; nbio in state not options fixes
e
s 00001/00000/00719
d D 4.51 82/02/08 23:20:15 root 92 91
c add call to memerr in case mchk was due to memory problem
e
s 00001/00001/00718
d D 4.50 82/01/17 04:03:25 wnj 91 90
c use spl1() not spl4()
e
s 00019/00006/00700
d D 4.49 82/01/16 20:59:19 wnj 90 89
c clean crashes! 
e
s 00001/00001/00705
d D 4.48 81/12/09 20:52:49 wnj 89 88
c fix to mbmap init
e
s 00003/00002/00703
d D 4.47 81/11/29 22:21:50 wnj 88 87
c weekend editing
e
s 00003/00003/00702
d D 4.46 81/11/20 14:42:59 wnj 87 86
c more lint
e
s 00000/00008/00705
d D 4.45 81/11/14 16:43:08 wnj 86 85
c before header overlay
e
s 00010/00019/00703
d D 4.44 81/11/08 16:52:45 wnj 85 84
c BBNNET->INET, no more contab
e
s 00001/00001/00721
d D 4.43 81/11/07 11:09:31 wnj 84 83
c fixes per shannon
e
s 00004/00003/00718
d D 4.42 81/10/29 20:53:22 wnj 83 82
c s/bbnnet/inet/
e
s 00001/00000/00720
d D 4.41 81/10/29 18:10:16 wnj 82 81
c before inserting beauty header files
e
s 00000/00001/00720
d D 4.40 81/10/17 16:15:00 wnj 81 80
c no more freetab for net
e
s 00000/00001/00721
d D 4.39 81/10/16 16:46:42 wnj 80 79
c don't allocate work queue
e
s 00003/00002/00719
d D 4.38 81/08/31 00:57:44 wnj 79 78
c variable size message buffer
e
s 00018/00001/00703
d D 4.37 81/05/12 17:18:34 root 78 77
c add tcp/ip
e
s 00008/00001/00696
d D 4.36 81/05/09 22:36:22 root 77 76
c send SIGILL not SIGKILL when can't send sig
e
s 00002/00000/00695
d D 4.35 81/05/05 21:51:16 wnj 76 75
c set reboot flag to prevent re-dumps
e
s 00002/00000/00693
d D 4.34 81/04/28 02:58:13 root 75 74
c allocate ports
e
s 00002/00002/00691
d D 4.33 81/04/22 12:01:24 wnj 74 73
c fix 2 bugs: 1 in machine check printout and one in ps restored after dorti that caused movc3's interrupted by signal delivery to restart rather than FPD
e
s 00007/00000/00686
d D 4.32 81/04/17 17:52:57 wnj 73 72
c new timeout structure (linked lists)
e
s 00002/00002/00684
d D 4.31 81/04/13 20:33:56 root 72 71
c allocate space for ecmap
e
s 00000/00001/00686
d D 4.30 81/04/03 00:15:57 root 71 70
c Moved version out to vers.s
e
s 00020/00020/00667
d D 4.29 81/04/03 00:06:43 root 70 69
c s/730/7ZZ/
e
s 00071/00009/00616
d D 4.28 81/03/21 15:31:50 wnj 69 68
c add 730 support
e
s 00016/00002/00609
d D 4.27 81/03/17 17:01:04 wnj 68 67
c make nubuf and nswbuf patchable
e
s 00002/00000/00609
d D 4.26 81/03/17 05:49:33 wnj 67 66
c restore lost panic: %s line, and also sys pt too small
e
s 00000/00000/00609
d D 4.25 81/03/09 01:47:29 wnj 66 65
c lint and a few minor fixed
e
s 00004/00007/00605
d D 4.24 81/03/09 00:32:40 wnj 65 64
c lint
e
s 00002/00001/00610
d D 4.23 81/03/08 16:18:25 wnj 64 63
c uba.h --> ubavar.h+ubareg.h
e
s 00004/00004/00607
d D 4.22 81/03/06 11:38:06 wnj 63 62
c reformat messages
e
s 00095/00047/00516
d D 4.21 81/03/03 11:04:57 wnj 62 61
c new mcr (via interrupts); fp status passed thru
e
s 00008/00005/00555
d D 4.20 81/02/28 14:46:46 wnj 61 60
c alloc tables at boot time version
e
s 00005/00003/00555
d D 4.19 81/02/27 17:44:47 wnj 60 59
c dynamic allocation kernel
e
s 00054/00009/00504
d D 4.18 81/02/27 02:39:23 wnj 59 58
c before compiling dynamic version
e
s 00000/00002/00513
d D 4.17 81/02/26 21:56:22 wnj 58 57
c clean up conditional machinecheck stuff
e
s 00064/00043/00451
d D 4.16 81/02/26 04:26:10 wnj 57 56
c added 750 macheck code... FASTVAX XXX
e
s 00003/00002/00491
d D 4.15 81/02/25 23:30:34 wnj 56 55
c get rid of VAX==???
e
s 00045/00000/00448
d D 4.14 81/02/25 14:48:03 wnj 55 54
c first version with new machine check code
e
s 00001/00001/00447
d D 4.13 81/02/16 20:50:04 wnj 54 53
c use HZ not 60
e
s 00039/00044/00409
d D 4.12 81/02/15 12:18:16 wnj 53 52
c many changes for autoconf
e
s 00016/00009/00437
d D 4.11 81/02/08 18:34:34 wnj 52 51
c first working autoconf version
e
s 00002/00002/00444
d D 4.10 81/02/08 01:02:22 wnj 51 50
c 
e
s 00001/00001/00445
d D 4.9 81/02/08 00:50:15 wnj 50 49
c fixed up version format
e
s 00017/00030/00429
d D 4.8 81/02/08 00:48:40 wnj 49 48
c 
e
s 00041/00026/00418
d D 4.7 81/02/07 14:33:08 wnj 48 47
c panic fixups, auto dumping code
e
s 00007/00017/00437
d D 4.6 81/02/04 03:00:07 wnj 47 46
c fixed up boot codes
e
s 00000/00004/00454
d D 4.5 81/01/20 19:54:16 toy 46 45
c Removed #ifdef silliness.  (MCT)
e
s 00012/00004/00446
d D 4.4 81/01/15 19:35:29 wnj 45 44
c fixes for saved msgbuf through crashes
e
s 00038/00009/00412
d D 4.3 80/12/16 15:57:48 wnj 44 43
c comet changes
e
s 00004/00002/00417
d D 4.2 80/11/11 13:12:01 bill 43 42
c move f01 when haltingmove f01 when halting
e
s 00033/00011/00386
d D 4.1 80/11/10 15:25:31 bill 42 35
c bootstrap fixups and lint
e
s 00001/00001/00416
d R 4.4 80/11/10 00:41:27 bill 41 40
c minor lint
e
s 00001/00001/00416
d R 4.3 80/11/10 00:17:24 bill 40 39
c more lint
e
s 00017/00007/00400
d R 4.2 80/11/09 23:02:00 bill 39 38
c minor lint
e
s 00015/00005/00392
d R 4.1 80/11/09 17:32:01 bill 38 35
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00001/00000/00398
d R 3.36 80/10/22 22:19:11 bill 37 36
c forgot to include mount.h
e
s 00001/00000/00397
d R 3.35 80/10/22 22:17:24 bill 36 35
c force root filesystem to be updated when time changed
e
s 00001/00001/00396
d D 3.34 80/10/22 09:34:05 bill 35 34
c jul 4
e
s 00001/00001/00396
d D 3.33 80/10/21 22:20:09 bill 34 33
c rewording
e
s 00005/00002/00392
d D 3.32 80/10/21 22:11:48 bill 33 32
c cleanup clkinit
e
s 00004/00000/00390
d D 3.31 80/10/20 15:20:35 bill 32 31
c avoid negative times in clock
e
s 00000/00000/00390
d D 3.30 80/10/20 00:57:32 bill 31 30
c nbuf=100, device code with .h files
e
s 00000/00000/00390
d D 3.29 80/10/13 09:19:19 bill 30 29
c new iostat; mba changes
e
s 00000/00000/00390
d D 3.28 80/10/11 14:08:13 bill 29 28
c cpu % and link fix
e
s 00003/00006/00387
d D 3.27 80/10/02 19:30:18 bill 28 27
c reformat
e
s 00035/00002/00358
d D 3.26 80/10/02 10:40:39 bill 27 26
c first attempt at reboot stuff
e
s 00000/00000/00360
d D 3.25 80/09/30 12:44:35 bill 26 25
c exit+ttynew minor fixes
e
s 00000/00000/00360
d D 3.24 80/09/26 13:14:08 bill 25 24
c new signal stuff, tty hiwat and lowat
e
s 00000/00000/00360
d D 3.23 80/09/23 09:40:41 bill 24 23
c restart signal stuff; hp driver fix
e
s 00003/00000/00357
d D 3.22 80/09/19 17:41:53 bill 23 22
c add bug comments
e
s 00000/00000/00357
d D 3.21 80/09/19 16:39:23 bill 22 21
c force new version; tty driver fixes and up MOL patch
e
s 00071/00024/00286
d D 3.20 80/09/16 09:31:50 bill 21 20
c 3.20 with clock, TIOCSTI, bufunhash fix dz break fix, RM05 tablesold sys call removal
c more memory controller registers
e
s 00002/00002/00308
d D 3.19 80/09/12 09:37:26 bill 20 19
c bug fix on time set try again
e
s 00008/00004/00302
d D 3.18 80/09/12 09:31:53 bill 19 17
c lost|gain 1/2 year
e
s 00008/00004/00302
d R 3.18 80/09/12 09:25:25 bill 18 17
c say lost|gained on 1/2 year
e
s 00018/00001/00288
d D 3.17 80/09/11 09:53:23 bill 17 16
c new clock stuff
e
s 00000/00000/00289
d D 3.16 80/09/08 09:18:44 bill 16 15
c new c compiler version
e
s 00000/00001/00289
d D 3.15 80/08/27 08:42:11 bill 15 14
c delete debugging printf
e
s 00018/00002/00272
d D 3.14 80/08/27 08:36:20 bill 14 13
c buffers allocated in sysmap
e
s 00000/00001/00274
d D 3.13 80/07/29 09:13:54 bill 13 12
c 
e
s 00000/00000/00275
d D 3.12 80/07/19 20:01:42 bill 12 11
c about time
e
s 00000/00000/00275
d D 3.11 80/07/06 20:36:57 bill 11 10
c working shared page cache
e
s 00000/00002/00275
d D 3.10 80/06/24 19:31:57 bill 10 9
c now has multi-disk paging
e
s 00030/00000/00247
d D 3.9 80/06/22 12:28:45 bill 9 8
c add unhang()
e
s 00001/00001/00246
d D 3.8 80/06/07 02:46:02 bill 8 7
c %H%->%G%
e
s 00001/00002/00246
d D 3.7 80/05/24 19:43:40 bill 7 6
c new sig stuff
e
s 00047/00002/00201
d D 3.6 80/05/18 11:33:32 bill 6 5
c first new signal system
e
s 00003/00003/00200
d D 3.5 80/05/15 16:59:00 bill 5 4
c new signal names
e
s 00002/00002/00201
d D 3.4 80/05/08 10:21:50 bill 4 3
c VOID=>void
e
s 00001/00001/00202
d D 3.3 80/05/08 10:04:27 bill 3 2
c boot with /etc/init, not /etc/init.vm
e
s 00001/00001/00202
d D 3.2 80/04/12 17:59:55 bill 2 1
c maxmem=2M for benchmarking
e
s 00203/00000/00000
d D 3.1 80/04/09 16:03:23 bill 1 0
c date and time created 80/04/09 16:03:23 by bill
e
u
U
f b 
t
T
I 1
D 8
/*	%M%	%I%	%H%	*/
E 8
I 8
D 53
/*	%M%	%I%	%G%	*/
E 53
I 53
D 150
/*	%M%	%I%	%E%	*/
E 150
I 150
/*
D 167
 * Copyright (c) 1982 Regents of the University of California.
E 167
I 167
D 168
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 168
I 168
D 180
 * Copyright (c) 1982 Regents of the University of California.
E 180
I 180
 * Copyright (c) 1982,1986,1988 Regents of the University of California.
E 180
E 168
E 167
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 150
E 53
I 14
D 17
extern cmap,ecmap;
E 17
E 14
E 8

I 115
D 142
#include "../machine/reg.h"
#include "../machine/pte.h"
#include "../machine/psl.h"
E 142
I 142
D 180
#include "reg.h"
#include "pte.h"
#include "psl.h"
E 142

E 180
E 115
D 142
#include "../h/param.h"
#include "../h/systm.h"
I 78
D 85
#ifdef BBNNET
D 83
#include "../bbnnet/net.h"
I 82
#include "../bbnnet/host.h"
E 82
#include "../bbnnet/ucb.h"
E 83
I 83
#include "../inet/inet.h"
#include "../inet/inet_systm.h"
#include "../inet/inet_host.h"
#include "../h/socket.h"
E 83
#endif BBNNET
E 85
I 85
D 86
#ifdef INET
#include "../net/inet.h"
#include "../net/inet_systm.h"
#include "../net/inet_host.h"
#endif INET
E 86
E 85
E 78
#include "../h/dir.h"
#include "../h/user.h"
I 104
#include "../h/kernel.h"
E 104
#include "../h/map.h"
D 115
#include "../h/reg.h"
D 107
#include "../h/mtpr.h"
D 104
#include "../h/clock.h"
E 104
I 104
#include "../vax/clock.h"
E 107
E 104
#include "../h/pte.h"
E 115
#include "../h/vm.h"
#include "../h/proc.h"
D 115
#include "../h/psl.h"
E 115
I 53
#include "../h/buf.h"
E 53
I 9
D 64
#include "../h/uba.h"
E 64
I 64
D 107
#include "../h/ubavar.h"
#include "../h/ubareg.h"
E 64
I 27
#include "../h/cons.h"
E 107
#include "../h/reboot.h"
I 48
#include "../h/conf.h"
I 52
D 53
#include "../h/buf.h"
E 53
I 53
D 107
#include "../h/mem.h"
#include "../h/cpu.h"
E 107
I 59
#include "../h/inode.h"
#include "../h/file.h"
#include "../h/text.h"
#include "../h/clist.h"
#include "../h/callout.h"
#include "../h/cmap.h"
E 59
E 53
E 52
D 119
#include <frame.h>
E 119
I 75
D 85
#include "../h/port.h"
E 85
I 85
#include "../h/mbuf.h"
E 85
I 76
D 107
#include "../h/rpb.h"
E 107
I 79
#include "../h/msgbuf.h"
I 137
D 140
#include "../h/nami.h"
E 140
E 137
I 101
#include "../h/quota.h"
E 142
I 142
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
I 180
#include "malloc.h"
E 180
#include "map.h"
#include "vm.h"
#include "proc.h"
#include "buf.h"
#include "reboot.h"
#include "conf.h"
#include "inode.h"
#include "file.h"
#include "text.h"
#include "clist.h"
#include "callout.h"
#include "cmap.h"
#include "mbuf.h"
#include "msgbuf.h"
#include "quota.h"
I 172
D 180
#include "malloc.h"
E 180
E 172
E 142
I 107

I 180
#include "reg.h"
#include "pte.h"
#include "psl.h"
E 180
I 119
D 142
#include "../vax/frame.h"
E 119
D 112
#include "../vax/clock.h"
E 112
#include "../vax/cons.h"
#include "../vax/cpu.h"
#include "../vax/mem.h"
#include "../vax/mtpr.h"
#include "../vax/rpb.h"
E 142
I 142
#include "frame.h"
I 160
#include "clock.h"
E 160
#include "cons.h"
#include "cpu.h"
I 188
#include "cpucond.h"
E 188
#include "mem.h"
#include "mtpr.h"
#include "rpb.h"
I 164
#include "ka630.h"
I 184
#include "ka650.h"
E 184
I 180

E 180
E 164
E 142
#include "../vaxuba/ubavar.h"
#include "../vaxuba/ubareg.h"
E 107
E 101
E 79
E 76
E 75
E 48
E 27
E 9

I 188
#include "../mdec/vmb.h"

E 188
D 6
char	version[] = "VM/UNIX (Berkeley Version 3.1) 4/2/80 \n";
E 6
I 6
D 42
char	version[] = "VM/UNIX (Berkeley Version %I%) %H% \n";
E 42
I 42
D 44
char	version[] = "VM/UNIX (Berkeley Version %I%) %G% \n";
E 44
I 44
D 48
char	version[] = "VM/UNIX (Berkeley Version 4.1) 11/10/80 \n";
E 48
I 48
D 65
int	coresw = 0;
int	printsw = 0;

E 65
D 49
char	version[] = "VM/UNIX (Berkeley Version %M%) %E% \n";
E 49
I 49
D 50
char	version[] = "VM/UNIX (Berkeley Version %I%) %D% \n";
E 50
I 50
D 63
char	version[] = "VM/UNIX (Berkeley Version %I%) %E% %U% \n";
E 63
I 63
D 69
char	version[] = "VAX/UNIX (Berkeley Version %I%) %E% %U% \n";
E 69
I 69
D 71
char	version[] = "VAX/UNIX (Berkeley Version 4.27) 81/03/17 17:01:04 \n";
E 71
E 69
E 63
E 50
E 49
E 48
E 44
E 42
E 6
D 148
int	icode[] =
{
D 44
	0x9f19af9f,	/* pushab [&"init.vm",0]; pushab */
	0x02dd09af,	/* "/etc/init.vm"; pushl $2 */
E 44
I 44
	0x9f19af9f,	/* pushab [&"init",0]; pushab */
	0x02dd09af,	/* "/etc/init"; pushl $2 */
E 44
	0xbc5c5ed0,	/* movl sp,ap; chmk */
	0x2ffe110b,	/* $exec; brb .; "/ */
	0x2f637465,	/* etc/ */
D 27
	0x74696e69,	/* init */
D 3
	0x006d762e,	/* .vm";  0 */
E 3
I 3
D 6
	0x00000000,	/* \0\0\0";  0 */	/* was .vm" */
E 6
I 6
	0x006d762e,	/* .vm";  0 */
E 27
I 27
	0x74696e69,	/* init" */
	0x00000000,	/* \0\0\0";  0 */
E 27
E 6
E 3
	0x00000014,	/* [&"init", */
	0x00000000,	/* 0] */
};
int	szicode = sizeof(icode);
I 101

E 148
D 114
#if	MUSH
E 114
I 114
D 122
#ifdef MUSH
E 114
int	mcode[] =
{
	0x9f19af9f,	/* pushab [&"mush",0]; pushab */
	0x02dd09af,	/* "/etc/mush"; pushl $2 */
	0xbc5c5ed0,	/* movl sp,ap; chmk */
	0x2f01bc0b,	/* $exec; chmk $exit; "/ */
	0x2f637465,	/* etc/ */
	0x6873756d,	/* mush" */
	0x00000000,	/* \0\0\0";  0 */
	0x00000014,	/* [&"mush", */
	0x00000000,	/* 0] */
};
int	szmcode = sizeof(mcode);
#endif
E 101
D 62
int	memchk();
E 62
 
E 122
/*
I 68
 * Declare these as initialized data so we can patch them.
 */
D 145
int	nbuf = 0;
E 145
int	nswbuf = 0;
I 145
#ifdef	NBUF
int	nbuf = NBUF;
#else
int	nbuf = 0;
#endif
#ifdef	BUFPAGES
int	bufpages = BUFPAGES;
#else
E 145
I 117
int	bufpages = 0;
I 145
#endif
I 179
int	msgbufmapped;		/* set when safe to use msgbuf */
E 179
E 145
E 117

/*
I 188
 * Set up when using the VMB boot path for CI support and dump support
 */
int	*ci_ucode = 0;		/* If present, points to CI ucode */
int	ci_ucodesz = 0;		/* If present, size of CI ucode */
int	*vmbinfo = 0;		/* gets a physical address set in locore
				   which is passed in by the VMB boot path */

/*
E 188
E 68
 * Machine-dependent startup code
 */
startup(firstaddr)
I 59
	int firstaddr;
E 59
{
	register int unixsize;
I 14
D 65
	register int i;
E 65
I 65
	register unsigned i;
E 65
	register struct pte *pte;
I 114
D 180
	int mapaddr, j;
E 180
I 180
	int mapaddr, j, n;
E 180
E 114
I 59
	register caddr_t v;
I 117
	int maxbufs, base, residual;
I 188
	int vmbinfosz;
E 188
D 163
	extern char etext;
E 163
E 117
E 59
E 14

I 188
	if (vmbinfo) {
		mapaddr = btop(vmbinfo);
		vmbinfosz = MAX(physmem - mapaddr, 128);
		pte = vmbinfomap;
		for (i=0; i<vmbinfosz; i++)
			*(int *) pte++ = PG_V | PG_KW | (mapaddr + i);
		mtpr(TBIA, 0);
		if (vmb_info.ciucodebas && vmb_info.ciucodesiz) {
			ci_ucode = (int *)&vmb_info +
				(vmb_info.ciucodebas - vmbinfo);
			ci_ucodesz = vmb_info.ciucodesiz;
		}
	}

E 188
I 164
D 183
#if VAX630
E 183
I 183
D 185
#if VAX630 || VAX650
E 183
E 164
	/*
I 164
 	 * Leave last 5k of phys. memory as console work area.
	 */
D 183
	if (cpu == VAX_630)
E 183
I 183
	if (cpu == VAX_630 || cpu == VAX_650)
E 183
		maxmem -= 10;
#endif
E 185
	/*
E 164
I 45
	 * Initialize error message buffer (at end of core).
	 */
D 79
	maxmem -= CLSIZE;
E 79
I 79
	maxmem -= btoc(sizeof (struct msgbuf));
E 79
	pte = msgbufmap;
D 79
	for (i = 0; i < CLSIZE; i++)
E 79
I 79
	for (i = 0; i < btoc(sizeof (struct msgbuf)); i++)
E 79
		*(int *)pte++ = PG_V | PG_KW | (maxmem + i);
D 152
	mtpr(TBIA, 1);
E 152
I 152
	mtpr(TBIA, 0);
I 179
	msgbufmapped = 1;
E 179
E 152

I 168
D 183
#if VAX630
E 183
I 183
#ifdef QBA
E 183
#include "qv.h"
#if NQV > 0
	/*
	 * redirect console to qvss if it exists
	 */
D 182
	if (!qvcons_init())
		printf("qvss not initialized\n");
E 182
I 182
	qvcons_init();
E 182
I 174
#endif 
#include "qd.h"
#if NQD > 0
	/*
	 * redirect console to qdss if it exists
	 */
D 182
	if (!qdcons_init())
		printf("qdss not initialized\n");
E 182
I 182
	qdcons_init();
E 182
E 174
#endif
#endif
I 169

I 188
#if NEED_BABYVAX_SUPPORT
	switch (cpu) {
	case VAX_410:
	case VAX_3100:
		/* establishes BabyVAX console among other early init */
		babyvax_early_init();
		break;
	}
#endif

E 188
D 181
#ifdef KDB
E 181
I 181
#ifdef KADB
E 181
	kdb_init();
#endif
E 169
E 168
	/*
E 45
	 * Good {morning,afternoon,evening,night}.
	 */
I 45
	printf(version);
D 145
	printf("real mem  = %d\n", ctob(maxmem));
E 45
D 52

E 52
I 52
	
E 52
I 45
D 47

E 45
I 44
#if VAX==780
E 47
I 47
	/*
D 48
	 */			/* Bell labs style comment */
E 48
I 48
D 52
	 * Clear warm-restart inhibit flag.
	 */
E 48
E 47
E 44
I 42
	tocons(TXDB_CWSI);
I 44
D 47
#endif
#if VAX==750
	tocons(TXDB_CCSF);
#endif
E 47
I 47
	tocons(TXDB_CCSI);

E 47
E 44
E 42
D 45
	printf(version);
	printf("real mem  = %d\n", ctob(maxmem));

E 45
	/*
E 52
D 14
	 * Allow for the u. area of process 0.
E 14
I 14
D 59
	 * Allow for the u. area of process 0 and its (single)
	 * page of page tables.
E 59
I 59
D 114
	 * First determine how many buffers are reasonable.
D 97
	 * Current alg is 32 per megabyte, with min of 32.
E 97
I 97
	 * Current alg is 16 per megabyte, with min of 16.
E 114
I 114
	 * Determine how many buffers to allocate.
	 * Use 10% of memory, with min of 16.
E 114
E 97
	 * We allocate 1/2 as many swap buffer headers as file i/o buffers.
E 59
E 14
	 */
I 117
	maxbufs = ((SYSPTSIZE * NBPG) - (5 * (int)(&etext - 0x80000000))) /
	    MAXBSIZE;
	if (bufpages == 0)
		bufpages = (physmem * NBPG) / 10 / CLBYTES;
E 117
I 14
D 15
	printf("firstaddr %X unixsize %X, cmap %X, ecmap %X\n", firstaddr, unixsize, cmap, ecmap);
E 15
E 14
D 59
	unixsize = (firstaddr+UPAGES+1);
E 59
I 59
D 68
	nbuf = (32 * physmem) / btoc(1024*1024); if (nbuf < 32) nbuf = 32;
D 60
	nswbuf = nbuf / 2;
E 60
I 60
	nswbuf = (nbuf / 2) &~ 1;	/* force even */
E 68
I 68
	if (nbuf == 0) {
D 97
		nbuf = (32 * physmem) / btoc(1024*1024);
		if (nbuf < 32)
			nbuf = 32;
E 97
I 97
D 114
		nbuf = (16 * physmem) / btoc(1024*1024);
E 114
I 114
D 117
		nbuf = ((physmem * NBPG) / 10) / (2 * CLBYTES);
E 117
I 117
		nbuf = bufpages / 2;
E 117
E 114
		if (nbuf < 16)
			nbuf = 16;
I 117
		if (nbuf > maxbufs)
			nbuf = maxbufs;
E 117
E 97
	}
I 117
	if (bufpages > nbuf * (MAXBSIZE / CLBYTES))
		bufpages = nbuf * (MAXBSIZE / CLBYTES);
E 117
	if (nswbuf == 0) {
		nswbuf = (nbuf / 2) &~ 1;	/* force even */
		if (nswbuf > 256)
			nswbuf = 256;		/* sanity */
	}
E 145
I 145
	printf("real mem  = %d\n", ctob(physmem));
E 145
E 68
E 60
E 59
I 14

	/*
D 59
	 * Initialze buffers
E 59
I 59
	 * Allocate space for system data structures.
I 114
	 * The first available real memory address is in "firstaddr".
D 145
	 * As pages of memory are allocated, "firstaddr" is incremented.
E 145
	 * The first available kernel virtual address is in "v".
	 * As pages of kernel virtual memory are allocated, "v" is incremented.
I 145
	 * As pages of memory are allocated and cleared,
	 * "firstaddr" is incremented.
E 145
	 * An index into the kernel page table corresponding to the
	 * virtual memory address maintained in "v" is kept in "mapaddr".
E 114
E 59
	 */
I 114
D 145
	mapaddr = firstaddr;
E 145
E 114
D 59
	pte = bufmap;
	for (i = 0; i < NBUF * CLSIZE; i++)
		*(int *)pte++ = PG_V | PG_KW | unixsize++;
E 59
I 59
D 180
	v = (caddr_t)(0x80000000 | (firstaddr * NBPG));
E 180
I 180
	v = (caddr_t)(KERNBASE | (firstaddr * NBPG));
E 180
#define	valloc(name, type, num) \
D 145
	    (name) = (type *)(v); (v) = (caddr_t)((name)+(num))
E 145
I 145
	    (name) = (type *)v; v = (caddr_t)((name)+(num))
E 145
#define	valloclim(name, type, num, lim) \
D 145
	    (name) = (type *)(v); (v) = (caddr_t)((lim) = ((name)+(num)))
D 97
	valloc(buffers, char, BSIZE*nbuf);
E 97
I 97
	valloc(buffers, char, MAXBSIZE * nbuf);
I 114
D 117
	for (i = 0; i < nbuf; i++) {
		for (j = 0; j < 2 * CLSIZE; j++) {
E 117
I 117
	base = bufpages / nbuf;
	residual = bufpages % nbuf;
	for (i = 0; i < residual; i++) {
		for (j = 0; j < (base + 1) * CLSIZE; j++) {
E 117
			*(int *)(&Sysmap[mapaddr+j]) = PG_V | PG_KW | firstaddr;
			clearseg((unsigned)firstaddr);
			firstaddr++;
		}
		mapaddr += MAXBSIZE / NBPG;
	}
I 117
	for (i = residual; i < nbuf; i++) {
		for (j = 0; j < base * CLSIZE; j++) {
			*(int *)(&Sysmap[mapaddr+j]) = PG_V | PG_KW | firstaddr;
			clearseg((unsigned)firstaddr);
			firstaddr++;
		}
		mapaddr += MAXBSIZE / NBPG;
	}
E 117
E 114
E 97
	valloc(buf, struct buf, nbuf);
	valloc(swbuf, struct buf, nswbuf);
E 145
I 145
	    (name) = (type *)v; v = (caddr_t)((lim) = ((name)+(num)))
E 145
I 60
D 121
	valloc(swsize, short, nswbuf);	/* note: nswbuf is even */
	valloc(swpf, int, nswbuf);
E 121
E 60
	valloclim(inode, struct inode, ninode, inodeNINODE);
	valloclim(file, struct file, nfile, fileNFILE);
	valloclim(proc, struct proc, nproc, procNPROC);
	valloclim(text, struct text, ntext, textNTEXT);
I 75
D 85
	valloc(port, struct port, nport);
E 85
E 75
	valloc(cfree, struct cblock, nclist);
	valloc(callout, struct callout, ncallout);
D 60
	valloc(swapmap, struct map, nproc * 4);
E 60
I 60
D 61
	valloc(swapmap, struct map, nswapmap = nproc * 4);
E 60
	valloc(argmap, struct map, 25);
E 61
I 61
	valloc(swapmap, struct map, nswapmap = nproc * 2);
	valloc(argmap, struct map, ARGMAPSIZE);
E 61
	valloc(kernelmap, struct map, nproc);
D 78

E 78
I 78
D 85
#ifdef BBNNET
	valloc(netmap, struct map, nnetpages/2);
D 81
	valloc(freetab, struct pfree, nnetpages);
E 81
D 80
	valloclim(workfree, struct work, nwork, workNWORK);
E 80
	valloclim(contab, struct ucb, nnetcon, conNCON);
E 85
I 85
D 88
	valloc(mbmap, struct map, nmbpages/2);
E 88
I 88
	valloc(mbmap, struct map, nmbclusters/4);
I 137
D 161
	valloc(nch, struct nch, nchsize);
E 161
I 161
	valloc(namecache, struct namecache, nchsize);
I 172
	valloc(kmemmap, struct map, ekmempt - kmempt);
	valloc(kmemusage, struct kmemusage, ekmempt - kmempt);
E 172
E 161
E 137
I 101
D 114
#if	QUOTA
E 114
I 114
#ifdef QUOTA
E 114
	valloclim(quota, struct quota, nquota, quotaNQUOTA);
	valloclim(dquot, struct dquot, ndquot, dquotNDQUOT);
#endif
I 145
	
E 145
E 101
E 88
D 86
#ifdef INET
E 85
	valloclim(host, struct host, nhost, hostNHOST);
D 85
#endif BBNNET
E 85
I 85
#endif INET
E 86
E 85
E 78
	/*
D 145
	 * Now allocate space for core map
E 145
I 145
	 * Determine how many buffers to allocate.
D 146
	 * Use 10% of memory, with min of 16.
E 146
I 146
	 * Use 10% of memory for the first 2 Meg, 5% of the remaining
	 * memory. Insure a minimum of 16 buffers.
E 146
	 * We allocate 1/2 as many swap buffer headers as file i/o buffers.
	 */
	if (bufpages == 0)
D 146
		bufpages = physmem / 10 / CLSIZE;
E 146
I 146
D 153
		if (physmem < (2 * 1024 * 1024))
E 153
I 153
		if (physmem < (2 * 1024 * CLSIZE))
E 153
			bufpages = physmem / 10 / CLSIZE;
		else
D 153
			bufpages =
			    ((2 * 1024 * 1024) / 5 + physmem / 5) / CLSIZE;
E 153
I 153
			bufpages = ((2 * 1024 * CLSIZE + physmem) / 20) / CLSIZE;
E 153
E 146
	if (nbuf == 0) {
		nbuf = bufpages / 2;
		if (nbuf < 16)
			nbuf = 16;
	}
	if (nswbuf == 0) {
		nswbuf = (nbuf / 2) &~ 1;	/* force even */
		if (nswbuf > 256)
			nswbuf = 256;		/* sanity */
	}
	valloc(swbuf, struct buf, nswbuf);

	/*
	 * Now the amount of virtual memory remaining for buffers
	 * can be calculated, estimating needs for the cmap.
	 */
D 180
	ncmap = (maxmem*NBPG - ((int)v &~ 0x80000000)) /
E 180
I 180
	ncmap = (maxmem*NBPG - ((int)v &~ KERNBASE)) /
E 180
		(CLBYTES + sizeof(struct cmap)) + 2;
	maxbufs = ((SYSPTSIZE * NBPG) -
D 180
	    ((int)(v + ncmap * sizeof(struct cmap)) - 0x80000000)) /
E 180
I 180
	    ((int)(v + ncmap * sizeof(struct cmap)) - KERNBASE)) /
E 180
		(MAXBSIZE + sizeof(struct buf));
	if (maxbufs < 16)
		panic("sys pt too small");
	if (nbuf > maxbufs) {
		printf("SYSPTSIZE limits number of buffers to %d\n", maxbufs);
		nbuf = maxbufs;
	}
	if (bufpages > nbuf * (MAXBSIZE / CLBYTES))
		bufpages = nbuf * (MAXBSIZE / CLBYTES);
	valloc(buf, struct buf, nbuf);

	/*
	 * Allocate space for core map.
E 145
I 114
	 * Allow space for all of phsical memory minus the amount 
	 * dedicated to the system. The amount of physical memory
	 * dedicated to the system is the total virtual memory of
D 145
	 * the system minus the space in the buffers which is not
	 * allocated real memory.
E 145
I 145
	 * the system thus far, plus core map, buffer pages,
	 * and buffer headers not yet allocated.
	 * Add 2: 1 because the 0th entry is unused, 1 for rounding.
E 145
E 114
	 */
D 114
	ncmap = (physmem*NBPG - ((int)v &~ 0x80000000)) /
E 114
I 114
D 145
	ncmap = (physmem*NBPG - ((int)v &~ 0x80000000) +
		(nbuf * (MAXBSIZE - 2 * CLBYTES))) /
E 114
		    (NBPG*CLSIZE + sizeof (struct cmap));
E 145
I 145
D 180
	ncmap = (maxmem*NBPG - ((int)(v + bufpages*CLBYTES) &~ 0x80000000)) /
E 180
I 180
	ncmap = (maxmem*NBPG - ((int)(v + bufpages*CLBYTES) &~ KERNBASE)) /
E 180
		(CLBYTES + sizeof(struct cmap)) + 2;
E 145
	valloclim(cmap, struct cmap, ncmap, ecmap);
I 67
D 72
	if ((((int)ecmap)&~0x80000000) > SYSPTSIZE*NBPG)
E 72
I 72
D 145
	if ((((int)(ecmap+1))&~0x80000000) > SYSPTSIZE*NBPG)
E 72
		panic("sys pt too small");
E 145
E 67

	/*
D 145
	 * Clear allocated space, and make r/w entries
E 145
I 145
	 * Clear space allocated thus far, and make r/w entries
E 145
	 * for the space in the kernel map.
	 */
D 60
	unixsize = btoc((int)ecmap);
E 60
I 60
D 72
	unixsize = btoc((int)ecmap &~ 0x80000000);
E 72
I 72
D 145
	unixsize = btoc((int)(ecmap+1) &~ 0x80000000);
E 72
E 60
D 114
	if (unixsize >= physmem - 8*UPAGES)
		panic("no memory");
	pte = &Sysmap[firstaddr];
	for (i = firstaddr; i < unixsize; i++) {
		*(int *)(&Sysmap[i]) = PG_V | PG_KW | i;
		clearseg(i);
E 114
I 114
	for (i = mapaddr; i < unixsize; i++) {
		*(int *)(&Sysmap[i]) = PG_V | PG_KW | firstaddr;
E 145
I 145
D 180
	unixsize = btoc((int)v &~ 0x80000000);
E 180
I 180
	unixsize = btoc((int)v &~ KERNBASE);
E 180
	while (firstaddr < unixsize) {
		*(int *)(&Sysmap[firstaddr]) = PG_V | PG_KW | firstaddr;
E 145
		clearseg((unsigned)firstaddr);
		firstaddr++;
E 114
	}
I 145

	/*
	 * Now allocate buffers proper.  They are different than the above
	 * in that they usually occupy more virtual memory than physical.
	 */
	v = (caddr_t) ((int)(v + PGOFSET) &~ PGOFSET);
	valloc(buffers, char, MAXBSIZE * nbuf);
	base = bufpages / nbuf;
	residual = bufpages % nbuf;
	mapaddr = firstaddr;
D 180
	for (i = 0; i < residual; i++) {
		for (j = 0; j < (base + 1) * CLSIZE; j++) {
E 180
I 180
	for (i = 0; i < nbuf; i++) {
		n = (i < residual ? base + 1 : base) * CLSIZE;
		for (j = 0; j < n; j++) {
E 180
			*(int *)(&Sysmap[mapaddr+j]) = PG_V | PG_KW | firstaddr;
			clearseg((unsigned)firstaddr);
			firstaddr++;
		}
		mapaddr += MAXBSIZE / NBPG;
	}
D 180
	for (i = residual; i < nbuf; i++) {
		for (j = 0; j < base * CLSIZE; j++) {
			*(int *)(&Sysmap[mapaddr+j]) = PG_V | PG_KW | firstaddr;
			clearseg((unsigned)firstaddr);
			firstaddr++;
		}
		mapaddr += MAXBSIZE / NBPG;
	}
E 180

D 180
	unixsize = btoc((int)v &~ 0x80000000);
E 180
I 180
	unixsize = btoc((int)v &~ KERNBASE);
E 180
E 145
I 114
	if (firstaddr >= physmem - 8*UPAGES)
		panic("no memory");
E 114
E 59
D 145
	mtpr(TBIA, 1);
E 145
I 145
D 152
	mtpr(TBIA, 1);			/* After we just cleared it all! */
E 152
I 152
	mtpr(TBIA, 0);			/* After we just cleared it all! */
E 152
E 145
D 45

E 45
D 46
#ifdef ERNIE
E 14
	if (coresw)
D 2
		maxmem = 2048;
E 2
I 2
		maxmem = 4096;
I 14
#endif
E 46
E 14
E 2

	/*
I 73
	 * Initialize callouts
	 */
	callfree = callout;
	for (i = 1; i < ncallout; i++)
		callout[i-1].c_next = &callout[i];

	/*
E 73
D 59
	 * Initialize maps.
E 59
I 59
D 61
	 * Initialize memory allocator and
	 * related maps.
E 61
I 61
	 * Initialize memory allocator and swap
	 * and user page table maps.
	 *
	 * THE USER PAGE TABLE MAP IS CALLED ``kernelmap''
	 * WHICH IS A VERY UNDESCRIPTIVE AND INCONSISTENT NAME.
E 61
E 59
	 */
D 114
	meminit(unixsize, maxmem);
E 114
I 114
	meminit(firstaddr, maxmem);
E 114
D 14
	maxmem -= (unixsize+1);
E 14
I 14
	maxmem = freemem;
E 14
	printf("avail mem = %d\n", ctob(maxmem));
I 117
	printf("using %d buffers containing %d bytes of memory\n",
		nbuf, bufpages * CLBYTES);
E 117
D 10
	mfree(swapmap, nswap - CLSIZE, CLSIZE);
E 10
D 61
	mfree(kernelmap, USRPTSIZE, 1);
E 61
I 61
D 110
	rminit(kernelmap, USRPTSIZE, 1, "usrpt", nproc);
I 78
D 85

#ifdef BBNNET
	/*
	 * Initialize network buffer management map.
	 */
	rminit(netmap, nnetpages-1, 1, "netpage", nnetpages/2);
#endif BBNNET
E 85
I 85
D 88
	rminit(mbmap, nmbpages-1, 1, "mbpages", nmbpages/2);
E 88
I 88
D 89
	rminit(mbmap, nmbclusters-1, 1, "mbclusters", nmbclusters/4);
E 89
I 89
D 94
	rminit(mbmap, nmbclusters-CLSIZE, CLSIZE, "mbclusters", nmbclusters/4);
E 94
I 94
	rminit(mbmap, (nmbclusters - 1) * CLSIZE, CLSIZE, "mbclusters",
		nmbclusters/4);
E 110
I 110
	rminit(kernelmap, (long)USRPTSIZE, (long)1,
	    "usrpt", nproc);
D 154
	rminit(mbmap, (long)((nmbclusters - 1) * CLSIZE), (long)CLSIZE,
E 154
I 154
	rminit(mbmap, (long)(nmbclusters * CLSIZE), (long)CLSIZE,
E 154
	    "mbclusters", nmbclusters/4);
I 172
	kmeminit();	/* now safe to do malloc/free */
E 172
E 110
E 94
E 89
E 88
E 85
E 78
E 61
D 10
	swplo--;
E 10
D 13
	mbainit();
E 13
D 52
	ubainit();
E 52
I 52

	/*
I 154
	 * Set up CPU-specific registers, cache, etc.
	 */
	initcpu();

	/*
I 169
	 * Set up buffers, so they can be used to read disk labels.
	 */
	bhinit();
	binit();

	/*
E 169
E 154
	 * Configure the system.
	 */
	configure();
I 153
D 154
	switch (cpu) {
E 154
E 153

I 153
D 154
	case VAX_780:
		setcache(0x200000);
		break;
	case VAX_750:
	case VAX_730:
		setcache(0);
		break;
	case VAX_8600:
		setcache(3);
		break;
	}

#if VAX8600
E 154
E 153
	/*
I 153
D 154
	 * Enable Fbox on 8600 if it exists
	 */
	if ((cpu == VAX_8600) && ((mfpr(ACCS) & 0xff) != 0))
		mtpr(ACCS, 0x8000);
#endif
	/*
E 154
E 153
	 * Clear restart inhibit flags.
	 */
D 188
	tocons(TXDB_CWSI);
	tocons(TXDB_CCSI);
E 188
I 188
	switch (cpu) {
#if VAX630
	case VAX_630:
		ka630clock.cpmbx &= ~(KA630CLK_RSTRT | KA630CLK_BOOT);
		break;
#endif
#if VAX650
	case VAX_650:
		ka650ssc.ssc_cpmbx &= ~(CPMB650_RIP | CPMB650_BIP);
		break;
#endif
I 189
#if NEED_BABYVAX_SUPPORT
	case VAX_410:
	case VAX_3100:
		babyvax_clear_biprip();
		break;
#endif
E 189
	default:
		tocons(TXDB_CWSI);
		tocons(TXDB_CCSI);
	}
E 188
D 62

D 53
	ubainit();		/* GROT */
E 53
E 52
D 54
	timeout(memchk, (caddr_t)0, 60);	/* it will pick its own intvl */
E 54
I 54
D 59
	timeout(memchk, (caddr_t)0, HZ);	/* it will pick its own intvl */
E 59
I 59
	timeout(memchk, (caddr_t)0, hz);	/* it will pick its own intvl */
E 62
E 59
E 54
D 112
}

D 109
/*
 * set up a physical address
 * into users virtual address space.
 */
sysphys()
{

	if(!suser())
		return;
	u.u_error = EINVAL;
}

E 109
I 104
clockstart()
{

	clkstart();
}

clockset()
{

	clkset();
}

E 104
/*
D 21
 * Start clock
E 21
I 21
 * Initialze the clock, based on the time base which is, e.g.
 * from a filesystem.  Base provides the time to within six months,
 * and the time of year clock provides the rest.
E 21
 */
D 21
clkstart()
{

	mtpr(NICR, -16667);	/* 16.667 milli-seconds */
	mtpr(ICCS, ICCS_RUN+ICCS_IE+ICCS_TRANS+ICCS_INT+ICCS_ERR);
}

clkreld()
{

	mtpr(ICCS, ICCS_RUN+ICCS_IE+ICCS_INT+ICCS_ERR);
I 17
}

E 21
D 104
clkinit(base)
E 104
I 104
clockinit(base)
E 104
D 21
time_t base;
E 21
I 21
	time_t base;
E 21
{
I 21
	register unsigned todr = mfpr(TODR);
E 21
I 19
	long deltat;
I 21
	int year = YRREF;
E 21
E 19

I 32
	if (base < 5*SECYR) {
D 33
		printf("WARNING: the date is silly; reset it!\n");
		base = 6*SECYR + 212*SECDAY + SECDAY/2;
E 33
I 33
D 34
		printf("WARNING: silly date in file system");
E 34
I 34
		printf("WARNING: preposterous time in file system");
E 34
D 35
		time = 6*SECYR + 212*SECDAY + SECDAY/2;
E 35
I 35
D 104
		time = 6*SECYR + 186*SECDAY + SECDAY/2;
E 104
I 104
		time.tv_sec = 6*SECYR + 186*SECDAY + SECDAY/2;
E 104
E 35
		clkset();
		goto check;
E 33
	}
E 32
D 19
	for (time = ((unsigned)mfpr(TODR))/100; time < base; time += SECYR)
E 19
I 19
D 21
	for (time = ((unsigned)mfpr(TODR))/100; time < base - SECYR/2; time += SECYR)
E 19
		;
	clkset();
E 21
I 21
	/*
	 * Have been told that VMS keeps time internally with base TODRZERO.
	 * If this is correct, then this routine and VMS should maintain
	 * the same date, and switching shouldn't be painful.
I 48
D 100
	 * (Unfortunately, VMS keeps local time, so when you run UNIX
	 * and VMS, VMS runs on GMT...).
E 100
I 100
D 106
	 * We must correct for the fact that VMS keeps local time
	 * while UNIX wants GMT.
E 106
I 106
	 * (Unfortunately, VMS keeps local time, so when you run UNIX
	 * and VMS, VMS runs on GMT...).
E 106
E 100
E 48
	 */
	if (todr < TODRZERO) {
D 63
		printf("WARNING: todr too small (battery backup failed?)");
E 63
I 63
		printf("WARNING: todr too small");
E 63
D 104
		time = base;
E 104
I 104
		time.tv_sec = base;
E 104
		/*
		 * Believe the time in the file system for lack of
		 * anything better, resetting the TODR.
		 */
		clkset();
		goto check;
	}
	/*
	 * Sneak to within 6 month of the time in the filesystem,
	 * by starting with the time of the year suggested by the TODR,
	 * and advancing through succesive years.  Adding the number of
	 * seconds in the current year takes us to the end of the current year
	 * and then around into the next year to the same position.
	 */
D 100
	for (time = (todr-TODRZERO)/100; time < base-SECYR/2; time += SECYR) {
E 100
I 100
D 104
	time = (todr-TODRZERO)/100 + timezone*60;
	while (time < base-SECYR/2) {
E 104
I 104
D 105
	time.tv_sec = (todr-TODRZERO)/100 + timezone*60;
E 105
I 105
	time.tv_sec = (todr-TODRZERO)/100;
E 105
	while (time.tv_sec < base-SECYR/2) {
E 104
E 100
		if (LEAPYEAR(year))
D 104
			time += SECDAY;
E 104
I 104
			time.tv_sec += SECDAY;
E 104
		year++;
I 100
D 104
		time += SECYR;
E 104
I 104
		time.tv_sec += SECYR;
E 104
E 100
	}

	/*
	 * See if we gained/lost two or more days;
	 * if so, assume something is amiss.
	 */
E 21
D 19
	if (time - base >= SECDAY*2)
		printf("warning: lost %d days; check the date\n",
		    (time-base) / SECDAY);
E 19
I 19
D 104
	deltat = time - base;
E 104
I 104
	deltat = time.tv_sec - base;
E 104
	if (deltat < 0)
		deltat = -deltat;
D 20
	if ((deltat < 0 ? -deltat : deltat) >= 2*SECDAY)
E 20
I 20
D 21
	if (deltat >= 2*SECDAY)
E 20
		printf("warning: %s %d days; check the date\n",
D 20
		    deltat < 0 ? "lost" : "gained", deltat / SECDAY);
E 20
I 20
		    time < base ? "lost" : "gained", deltat / SECDAY);
E 21
I 21
	if (deltat < 2*SECDAY)
		return;
	printf("WARNING: clock %s %d days",
D 104
	    time < base ? "lost" : "gained", deltat / SECDAY);
E 104
I 104
	    time.tv_sec < base ? "lost" : "gained", deltat / SECDAY);
E 104
check:
	printf(" -- CHECK AND RESET THE DATE!\n");
E 21
E 20
E 19
}

I 21
/*
 * Reset the TODR based on the time value; used when the TODR
 * has a preposterous value and also when the time is reset
 * by the stime system call.  Also called when the TODR goes past
 * TODRZERO + 100*(SECYEAR+2*SECDAY) (e.g. on Jan 2 just after midnight)
 * to wrap the TODR around.
 */
E 21
clkset()
{
I 21
	int year = YRREF;
	unsigned secyr;
D 100
	unsigned yrtime = time;
E 100
I 100
D 104
	unsigned yrtime = time - timezone*60;
E 104
I 104
D 105
	unsigned yrtime = time.tv_sec - timezone*60;
E 105
I 105
	unsigned yrtime = time.tv_sec;
E 105
E 104
E 100
E 21

D 21
	mtpr(TODR, ((unsigned)time%SECYR)*100);
E 21
I 21
	/*
	 * Whittle the time down to an offset in the current year,
	 * by subtracting off whole years as long as possible.
	 */
	for (;;) {
		secyr = SECYR;
		if (LEAPYEAR(year))
			secyr += SECDAY;
		if (yrtime < secyr)
			break;
		yrtime -= secyr;
		year++;
	}
	mtpr(TODR, TODRZERO + yrtime*100);
E 112
E 21
E 17
}

#ifdef PGINPROF
/*
 * Return the difference (in microseconds)
 * between the  current time and a previous
 * time as represented  by the arguments.
 * If there is a pending clock interrupt
 * which has not been serviced due to high
 * ipl, return error code.
 */
vmtime(otime, olbolt, oicr)
	register int otime, olbolt, oicr;
{

	if (mfpr(ICCS)&ICCS_INT)
		return(-1);
	else
D 104
		return(((time-otime)*60 + lbolt-olbolt)*16667 + mfpr(ICR)-oicr);
E 104
I 104
		return(((time.tv_sec-otime)*60 + lbolt-olbolt)*16667 + mfpr(ICR)-oicr);
E 104
}
#endif

I 9
D 49
#ifdef TRACE
E 49
E 9
/*
I 149
 * Clear registers on exec
 */
setregs(entry)
	u_long entry;
{
#ifdef notdef
	register int *rp;

	/* should pass args to init on the stack */
	/* should also fix this code before using it, it's wrong */
	/* wanna clear the scb? */
	for (rp = &u.u_ar0[0]; rp < &u.u_ar0[16];)
		*rp++ = 0;
#endif
	u.u_ar0[PC] = entry + 2;
}

/*
E 149
I 9
D 49
 * Put the current time into the trace,
 * in fractional seconds (i.e. 12345 means the
 * current time is ``n.12345'' for some n.
 */
ttime()
{

	trace("%d ", (lbolt*16667 + mfpr(ICR)));
}
#endif

/*
E 49
E 9
D 123
 * Send an interrupt to process
E 123
I 123
 * Send an interrupt to process.
E 123
I 23
 *
D 102
 * SHOULD CHANGE THIS TO PASS ONE MORE WORK SO THAT ALL INFORMATION
E 102
I 102
D 123
 * SHOULD CHANGE THIS TO PASS ONE MORE WORD SO THAT ALL INFORMATION
E 102
 * PROVIDED BY HARDWARE IS AVAILABLE TO THE USER PROCESS.
E 123
I 123
 * Stack is set up to allow sigcode stored
 * in u. to call routine, followed by chmk
D 147
 * to sigcleanup routine below.  After sigcleanup
D 132
 * resets the signal mask and the notion of
 * onsigstack, it returns to user who then
 * unwinds with the rei at the bottom of sigcode.
E 132
I 132
 * resets the signal mask and the stack, it
 * returns to user who then unwinds with the
 * rei at the bottom of sigcode.
E 147
I 147
 * to sigreturn routine below.  After sigreturn
 * resets the signal mask, the stack, the frame 
 * pointer, and the argument pointer, it returns
 * to the user specified pc, psl.
E 147
E 132
E 123
E 23
 */
D 123
sendsig(p, n)
I 42
	int (*p)();
E 123
I 123
D 124
sendsig(p, sig, mask)
	int (*p)(), sig, mask;
E 124
I 124
D 143
sendsig(p, sig, sigmask)
	int (*p)(), sig, sigmask;
E 143
I 143
sendsig(p, sig, mask)
	int (*p)(), sig, mask;
E 143
E 124
E 123
E 42
{
D 132
	register int *usp, *regs;
E 132
I 132
D 134
	register int *usp, *regs, *osp;
E 134
I 134
D 147
	register struct sigcontext *scp;	/* know to be r11 */
E 147
I 147
	register struct sigcontext *scp;
E 147
	register int *regs;
	register struct sigframe {
		int	sf_signum;
		int	sf_code;
		struct	sigcontext *sf_scp;
		int	(*sf_handler)();
I 147
		int	sf_argcount;
E 147
		struct	sigcontext *sf_scpcopy;
D 147
	} *fp;					/* known to be r9 */
E 147
I 147
	} *fp;
E 147
E 134
E 132
I 123
D 124
	int oonsigstack;
E 124
I 124
	int oonstack;
E 124
E 123

	regs = u.u_ar0;
D 123
	usp = (int *)regs[SP];
D 57
#ifdef FASTVAX
E 57
	usp -= 5;
E 123
I 123
D 124
	oonsigstack = u.u_onsigstack;
	if (!u.u_onsigstack && u.u_sigstack) {
		usp = (int *)u.u_sigstack;
		u.u_onsigstack = 1;
E 124
I 124
	oonstack = u.u_onstack;
I 132
D 134
	osp = (int *)regs[SP];
E 134
I 134
D 147
	scp = (struct sigcontext *)regs[SP] - 1;
E 147
I 147
	/*
	 * Allocate and validate space for the signal handler
	 * context. Note that if the stack is in P0 space, the
	 * call to grow() is a nop, and the useracc() check
	 * will fail if the process has not already allocated
	 * the space with a `brk'.
	 */
E 147
E 134
E 132
D 143
#define	mask(s)	(1<<((s)-1))
	if (!u.u_onstack && (u.u_sigonstack & mask(sig))) {
E 143
I 143
	if (!u.u_onstack && (u.u_sigonstack & sigmask(sig))) {
E 143
D 134
		usp = (int *)u.u_sigsp;
E 134
I 134
D 147
		fp = (struct sigframe *)u.u_sigsp - 1;
E 147
I 147
		scp = (struct sigcontext *)u.u_sigsp - 1;
E 147
E 134
		u.u_onstack = 1;
E 124
	} else
D 132
		usp = (int *)regs[SP];
	usp -= 8;
E 132
I 132
D 134
		usp = osp - 5;
E 134
I 134
D 147
		fp = (struct sigframe *)scp - 1;
E 134
	/*
D 134
	 * Must build signal context on stack to be returned to
E 134
I 134
	 * Must build signal handler context on stack to be returned to
E 134
	 * so that rei instruction in sigcode will pop ps and pc
	 * off correct stack.  The remainder of the signal state
	 * used in calling the handler must be placed on the stack
	 * on which the handler is to operate so that the calls
	 * in sigcode will save the registers and such correctly.
	 */
D 134
	osp -= 5;
	if (!oonstack && (int)osp <= USRSTACK - ctob(u.u_ssize))
		(void) grow((unsigned)osp);
E 134
I 134
	if (!oonstack && (int)fp <= USRSTACK - ctob(u.u_ssize)) 
E 147
I 147
		scp = (struct sigcontext *)regs[SP] - 1;
	fp = (struct sigframe *)scp - 1;
	if ((int)fp <= USRSTACK - ctob(u.u_ssize)) 
E 147
D 162
		grow((unsigned)fp);
E 162
I 162
		(void)grow((unsigned)fp);
E 162
E 134
D 147
	;
#ifndef lint
	asm("probew $3,$20,(r9)");
	asm("jeql bad");
#else
D 134
	if (useracc((caddr_t)osp, 20, 1))
E 134
I 134
	if (useracc((caddr_t)fp, sizeof (struct sigframe), 1))
E 134
		goto bad;
#endif
D 134
	usp -= 5;
E 132
E 123
D 124
	if ((int)usp <= USRSTACK - ctob(u.u_ssize))
E 124
I 124
	if (!u.u_onstack && (int)usp <= USRSTACK - ctob(u.u_ssize))
E 124
D 4
		VOID grow((unsigned)usp);
E 4
I 4
		(void) grow((unsigned)usp);
E 134
I 134
	if (!u.u_onstack && (int)scp <= USRSTACK - ctob(u.u_ssize))
		grow((unsigned)scp);
E 134
E 4
	;			/* Avoid asm() label botch */
I 42
#ifndef lint
E 42
D 123
	asm("probew $3,$20,(r11)");
E 123
I 123
D 132
	asm("probew $3,$32,(r11)");
E 132
I 132
	asm("probew $3,$20,(r11)");
E 132
E 123
	asm("beql bad");
I 42
#else
D 123
	if (useracc((caddr_t)usp, 0x20, 1))
E 123
I 123
D 132
	if (useracc((caddr_t)usp, 32, 1))
E 132
I 132
D 134
	if (useracc((caddr_t)usp, 20, 1))
E 134
I 134
	if (useracc((caddr_t)scp, sizeof (struct sigcontext), 1))
E 134
E 132
E 123
		goto bad;
#endif
E 147
I 147
D 156
	if (useracc((caddr_t)fp, sizeof (*fp) + sizeof (*scp), 1) == 0) {
E 156
I 156
	if (useracc((caddr_t)fp, sizeof (*fp) + sizeof (*scp), B_WRITE) == 0) {
E 156
		/*
		 * Process has trashed its stack; give it an illegal
		 * instruction to halt it in its tracks.
		 */
		u.u_signal[SIGILL] = SIG_DFL;
		sig = sigmask(SIGILL);
		u.u_procp->p_sigignore &= ~sig;
		u.u_procp->p_sigcatch &= ~sig;
		u.u_procp->p_sigmask &= ~sig;
		psignal(u.u_procp, SIGILL);
		return;
	}
	/* 
	 * Build the argument list for the signal handler.
	 */
E 147
E 42
D 123
	*usp++ = n;
D 5
	*usp++ = n == SIGINS ? u.u_cfcode : 0;
E 5
I 5
D 62
	*usp++ = n == SIGILL ? u.u_cfcode : 0;
E 62
I 62
	if (n == SIGILL || n == SIGFPE) {
E 123
I 123
D 134
	*usp++ = sig;
E 134
I 134
	fp->sf_signum = sig;
E 134
	if (sig == SIGILL || sig == SIGFPE) {
E 123
D 134
		*usp++ = u.u_code;
E 134
I 134
		fp->sf_code = u.u_code;
E 134
		u.u_code = 0;
	} else
D 134
		*usp++ = 0;
I 123
D 125
	*usp++ = (int)(usp + 2);
E 125
I 125
D 132
	*usp = (int)(usp + 2); usp++;
E 132
I 132
	*usp++ = (int)osp;
E 132
E 125
E 123
E 62
E 5
D 42
	*usp++ = p;
E 42
I 42
	*usp++ = (int)p;
E 134
I 134
		fp->sf_code = 0;
	fp->sf_scp = scp;
	fp->sf_handler = p;
E 134
I 123
D 132
	/* struct sigcontext used for the inward return */
D 124
	*usp++ = oonsigstack;
	*usp++ = mask;
E 124
I 124
	*usp++ = oonstack;
	*usp++ = sigmask;
E 124
E 123
E 42
	*usp++ = regs[PC];
	*usp++ = regs[PS];
D 123
	regs[SP] = (int)(usp - 5);
E 123
I 123
	regs[SP] = (int)(usp - 8);
E 132
I 132
	/*
D 147
	 * Duplicate the pointer to the sigcontext structure.
	 * This one doesn't get popped by the ret, and is used 
D 134
	 * by sigcleanup to reset the stack as well as locate
	 * the information for reseting the signal state on
	 * inward return.
E 134
I 134
	 * by sigcleanup to reset the signal state on inward return.
E 147
I 147
	 * Build the calls argument frame to be used to call sigreturn
E 147
E 134
	 */
I 147
	fp->sf_argcount = 1;
E 147
D 134
	*usp++ = (int)osp;
E 134
I 134
	fp->sf_scpcopy = scp;
E 134
D 147
	/* sigcontext goes on previous stack */
E 147
I 147
	/*
	 * Build the signal context to be used by sigreturn.
	 */
E 147
D 134
	*osp++ = oonstack;
	*osp++ = sigmask;
	*osp = (int)(osp + 1); osp++;
	*osp++ = regs[PC];
	*osp++ = regs[PS];
	regs[SP] = (int)(usp - 5);
E 134
I 134
	scp->sc_onstack = oonstack;
D 143
	scp->sc_mask = sigmask;
E 143
I 143
	scp->sc_mask = mask;
E 143
D 147
	/* setup rei */
	scp->sc_sp = (int)&scp->sc_pc;
E 147
I 147
	scp->sc_sp = regs[SP];
	scp->sc_fp = regs[FP];
	scp->sc_ap = regs[AP];
E 147
	scp->sc_pc = regs[PC];
	scp->sc_ps = regs[PS];
	regs[SP] = (int)fp;
E 134
E 132
E 123
D 57
#else
D 4
	VOID grow((unsigned)(usp-5));
E 4
I 4
	(void) grow((unsigned)(usp-5));
E 4
	if (suword((caddr_t)--usp, regs[PS]))
		goto bad;
	if (suword((caddr_t)--usp, regs[PC]))
		goto bad;
D 42
	if (suword((caddr_t)--usp, p))
E 42
I 42
	if (suword((caddr_t)--usp, (int)p))
E 42
		goto bad;
D 5
	if (suword((caddr_t)--usp, n==SIGINS ? u.u_cfcode : 0))
E 5
I 5
	if (suword((caddr_t)--usp, n==SIGILL ? u.u_cfcode : 0))
E 5
		goto bad;
	if (suword((caddr_t)--usp, n))
		goto bad;
	regs[SP] = (int)usp;
#endif
E 57
	regs[PS] &= ~(PSL_CM|PSL_FPD);
	regs[PC] = (int)u.u_pcb.pcb_sigc;
	return;
D 147

D 57
#ifdef FASTVAX
E 57
asm("bad:");
D 57
#endif
E 57
bad:
D 53
	printf("%d: cant send signal\n", u.u_procp->p_pid);
E 53
D 5
	psignal(u.u_procp, SIGKIL);
E 5
I 5
D 77
	psignal(u.u_procp, SIGKILL);
E 77
I 77
	/*
	 * Process has trashed its stack; give it an illegal
	 * instruction to halt it in its tracks.
	 */
	u.u_signal[SIGILL] = SIG_DFL;
D 123
	u.u_procp->p_siga0 &= ~(1<<(SIGILL-1));
	u.u_procp->p_siga1 &= ~(1<<(SIGILL-1));
E 123
I 123
D 124
	sig = 1 << (SIGILL - 1);
E 124
I 124
D 143
	sig = mask(SIGILL);
E 143
I 143
	sig = sigmask(SIGILL);
E 143
E 124
	u.u_procp->p_sigignore &= ~sig;
	u.u_procp->p_sigcatch &= ~sig;
	u.u_procp->p_sigmask &= ~sig;
E 123
	psignal(u.u_procp, SIGILL);
E 147
E 77
I 6
}

I 123
/*
D 147
 * Routine to cleanup state after a signal
E 147
I 147
 * System call to cleanup state after a signal
E 147
 * has been taken.  Reset signal mask and
D 132
 * notion of on signal stack from context
 * left there by sendsig (above).  Pop these
 * values in preparation for rei which follows
 * return from this routine.
E 132
I 132
 * stack state from context left by sendsig (above).
D 147
 * Pop these values in preparation for rei which
 * follows return from this routine.
E 147
I 147
 * Return to previous pc and psl as specified by
 * context left by sendsig. Check carefully to
 * make sure that the user has not modified the
D 151
 * psl to gain improper priviledges or to cause
E 151
I 151
D 153
 * psl to gain improper privileges or to cause
E 153
I 153
 * psl to gain improper priviledges or to cause
E 153
E 151
 * a machine fault.
E 147
E 132
 */
D 147
sigcleanup()
E 147
I 147
sigreturn()
E 147
{
I 147
	struct a {
		struct sigcontext *sigcntxp;
	};
E 147
D 132
	register int *usp = (int *)u.u_ar0[SP];
E 132
I 132
	register struct sigcontext *scp;
I 147
	register int *regs = u.u_ar0;
E 147
E 132

I 132
D 147
	scp = (struct sigcontext *)fuword((caddr_t)u.u_ar0[SP]);
E 147
I 147
	scp = ((struct a *)(u.u_ap))->sigcntxp;
D 156
	if (useracc((caddr_t)scp, sizeof (*scp), 0) == 0)
E 156
I 156
D 186
	if (useracc((caddr_t)scp, sizeof (*scp), B_WRITE) == 0)
E 186
I 186
	if (useracc((caddr_t)scp, sizeof (*scp), B_READ) == 0)
E 186
E 156
		return;
	if ((scp->sc_ps & (PSL_MBZ|PSL_IPL|PSL_IS)) != 0 ||
	    (scp->sc_ps & (PSL_PRVMOD|PSL_CURMOD)) != (PSL_PRVMOD|PSL_CURMOD) ||
	    ((scp->sc_ps & PSL_CM) &&
D 186
	     (scp->sc_ps & (PSL_FPD|PSL_DV|PSL_FU|PSL_IV)) != 0)) {
E 186
I 186
	     (!cpu_has_compat_mode ||
	      (scp->sc_ps & (PSL_FPD|PSL_DV|PSL_FU|PSL_IV)) != 0))) {
E 186
		u.u_error = EINVAL;
		return;
	}
	u.u_eosys = JUSTRETURN;
	u.u_onstack = scp->sc_onstack & 01;
	u.u_procp->p_sigmask = scp->sc_mask &~
	    (sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP));
	regs[FP] = scp->sc_fp;
	regs[AP] = scp->sc_ap;
	regs[SP] = scp->sc_sp;
	regs[PC] = scp->sc_pc;
	regs[PS] = scp->sc_ps;
}

/* XXX - BEGIN 4.2 COMPATIBILITY */
/*
 * Compatibility with 4.2 chmk $139 used by longjmp()
 */
osigcleanup()
{
	register struct sigcontext *scp;
	register int *regs = u.u_ar0;

	scp = (struct sigcontext *)fuword((caddr_t)regs[SP]);
E 147
	if ((int)scp == -1)
		return;
E 132
D 147
#ifndef lint
I 134
	/* only probe 12 here because that's all we need */
E 134
D 132
	asm("prober $3,$8,(r11)");
E 132
I 132
	asm("prober $3,$12,(r11)");
E 132
	asm("bnequ 1f; ret; 1:");
#else
D 132
	if (useracc((caddr_t)usp, 8, 0))
E 132
I 132
	if (useracc((caddr_t)scp, sizeof (*scp), 0))
E 147
I 147
D 156
	if (useracc((caddr_t)scp, 3 * sizeof (int), 0) == 0)
E 156
I 156
D 186
	if (useracc((caddr_t)scp, 3 * sizeof (int), B_WRITE) == 0)
E 186
I 186
	if (useracc((caddr_t)scp, 3 * sizeof (int), B_READ) == 0)
E 186
E 156
E 147
E 132
		return;
D 147
#endif
E 147
D 124
	u.u_onsigstack = *usp++ & 01;
	u.u_procp->p_sigmask = *usp++;
E 124
I 124
D 132
	u.u_onstack = *usp++ & 01;
E 132
I 132
	u.u_onstack = scp->sc_onstack & 01;
E 132
D 147
	u.u_procp->p_sigmask =
D 132
	    *usp++ &~ (mask(SIGKILL)|mask(SIGCONT)|mask(SIGSTOP));
E 124
	u.u_ar0[SP] = (int)usp;
E 132
I 132
D 143
	    scp->sc_mask &~ (mask(SIGKILL)|mask(SIGCONT)|mask(SIGSTOP));
E 143
I 143
	    scp->sc_mask &~ (sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP));
E 143
	u.u_ar0[SP] = scp->sc_sp;
E 147
I 147
	u.u_procp->p_sigmask = scp->sc_mask &~
	    (sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP));
	regs[SP] = scp->sc_sp;
E 147
E 132
}
I 147
/* XXX - END 4.2 COMPATIBILITY */
E 147
I 124
D 143
#undef mask
E 143
E 124

I 187
/*
 * Emulate exception signal.  Reset the process to the specified state like
 * sigreturn and then simulate the occurrence of an exception causing the
 * specified signal with the specified code.  Only SIGILL and SIGFPE supported
 * currently, this may change in the future.
 */
sigemu()
{
	struct a {
		struct sigcontext *sigcntxp;
		int sig;
		int code;
	};
	register struct sigcontext *scp;
	register int sig;
	register int *regs = u.u_ar0;

	scp = ((struct a *)(u.u_ap))->sigcntxp;
	if (useracc((caddr_t)scp, sizeof (*scp), B_READ) == 0)
		return;
	if ((scp->sc_ps & (PSL_MBZ|PSL_IPL|PSL_IS)) != 0 ||
	    (scp->sc_ps & (PSL_PRVMOD|PSL_CURMOD)) != (PSL_PRVMOD|PSL_CURMOD) ||
	    ((scp->sc_ps & PSL_CM) &&
	     (!cpu_has_compat_mode ||
	      (scp->sc_ps & (PSL_FPD|PSL_DV|PSL_FU|PSL_IV)) != 0))) {
		u.u_error = EINVAL;
		return;
	}
	sig = ((struct a *)(u.u_ap))->sig;
	if (sig != SIGILL && sig != SIGFPE) {
		u.u_error = EINVAL;
		return;
	}
	u.u_eosys = JUSTRETURN;
	u.u_onstack = scp->sc_onstack & 01;
	u.u_procp->p_sigmask = scp->sc_mask &~
	    (sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP));
	regs[FP] = scp->sc_fp;
	regs[AP] = scp->sc_ap;
	regs[SP] = scp->sc_sp;
	regs[PC] = scp->sc_pc;
	regs[PS] = scp->sc_ps;
	u.u_code = ((struct a *)(u.u_ap))->code;
	psignal(u.u_procp, sig);
}

E 187
#ifdef notdef
E 123
dorti()
{
D 48
	struct frame {
		int	handler;
		unsigned int
			psw:16,
			mask:12,
			:1,
			s:1,
			spa:2;
		int	savap;
		int	savfp;
		int	savpc;
	} frame;
E 48
I 48
	struct frame frame;
E 48
	register int sp;
	register int reg, mask;
	extern int ipcreg[];
D 7
	int n;
E 7

	(void) copyin((caddr_t)u.u_ar0[FP], (caddr_t)&frame, sizeof (frame));
	sp = u.u_ar0[FP] + sizeof (frame);
D 48
	u.u_ar0[PC] = frame.savpc;
	u.u_ar0[FP] = frame.savfp;
	u.u_ar0[AP] = frame.savap;
	mask = frame.mask;
E 48
I 48
	u.u_ar0[PC] = frame.fr_savpc;
	u.u_ar0[FP] = frame.fr_savfp;
	u.u_ar0[AP] = frame.fr_savap;
	mask = frame.fr_mask;
E 48
	for (reg = 0; reg <= 11; reg++) {
		if (mask&1) {
D 42
			u.u_ar0[ipcreg[reg]] = fuword(sp);
E 42
I 42
			u.u_ar0[ipcreg[reg]] = fuword((caddr_t)sp);
E 42
			sp += 4;
		}
		mask >>= 1;
	}
D 48
	sp += frame.spa;
	u.u_ar0[PS] = (u.u_ar0[PS] & 0xffff0000) | frame.psw;
	if (frame.s)
E 48
I 48
	sp += frame.fr_spa;
	u.u_ar0[PS] = (u.u_ar0[PS] & 0xffff0000) | frame.fr_psw;
	if (frame.fr_s)
E 48
D 7
		sp += 4 + (fuword(sp) & 0xff) << 2;
E 7
I 7
D 42
		sp += 4 + 4 * (fuword(sp) & 0xff);
E 42
I 42
		sp += 4 + 4 * (fuword((caddr_t)sp) & 0xff);
E 42
E 7
	/* phew, now the rei */
D 42
	u.u_ar0[PC] = fuword(sp);
E 42
I 42
	u.u_ar0[PC] = fuword((caddr_t)sp);
E 42
	sp += 4;
D 42
	u.u_ar0[PS] = fuword(sp);
E 42
I 42
	u.u_ar0[PS] = fuword((caddr_t)sp);
E 42
	sp += 4;
D 74
	u.u_ar0[PS] |= PSL_CURMOD|PSL_PRVMOD;
E 74
I 74
	u.u_ar0[PS] |= PSL_USERSET;
E 74
	u.u_ar0[PS] &= ~PSL_USERCLR;
I 177
	if (u.u_ar0[PS] & PSL_CM)
		u.u_ar0[PS] &= ~PSL_CM_CLR;
E 177
I 33
	u.u_ar0[SP] = (int)sp;
E 33
E 6
E 5
}
I 123
#endif
E 123

/*
D 62
 * Check memory controller for memory parity errors
E 62
I 62
D 180
 * Memenable enables the memory controlle corrected data reporting.
E 180
I 180
 * Memenable enables memory controller corrected data reporting.
E 180
 * This runs at regular intervals, turning on the interrupt.
 * The interrupt is turned off, per memory controller, when error
 * reporting occurs.  Thus we report at most once per memintvl.
E 62
 */
D 53
#define	MEMINTVL	(60*60*10)		/* 10 minutes */
E 53
int	memintvl = MEMINTVL;

I 44
D 49
#if VAX==780
E 44
#define	MHIERR	0x20000000
#define	MERLOG	0x10000000
I 44
#else
#define	MUNCORR	0xc0000000
#define	MCORERR	0x40000000
#define	MERLOG	(MUNCORR|MCORERR)
#endif
E 49
I 49
D 53
#define	M780_HIERR	0x20000000
#define	M780_ERLOG	0x10000000
#define	M750_UNCORR	0xc0000000
#define	M750_CORERR	0x40000000
D 51
#define	M750_ERLOG	(MUNCORR|MCORERR)
E 51
I 51
#define	M750_ERLOG	(M750_UNCORR|M750_CORERR)
E 51
E 49
E 44

E 53
I 44
D 49

E 49
E 44
D 62
memchk()
E 62
I 62
memenable()
E 62
{
I 49
D 53
	register int c;
E 53
I 53
D 180
	register struct mcr *mcr;
	register int m;
E 180
E 53
D 62
	int error;
E 62

I 164
D 180
#if VAX630
	if (cpu == VAX_630)
		return;
#endif
E 164
I 155
#ifdef	VAX8600
	if (cpu == VAX_8600) {
		M8600_ENA;
	} else
#endif
E 155
E 49
I 44
D 53
#if VAX==780
E 44
D 49
	register int c = mcr[2];
E 49
I 49
	error = mcr[2] & M780_ERLOG;
E 49
I 44
#else
D 49
	register int c = mcr[0];
E 49
I 49
	error = mcr[0] & M750_ERLOG;
E 53
I 53
	for (m = 0; m < nmcr; m++) {
		mcr = mcraddr[m];
D 138
		switch (cpu) {
E 138
I 138
		switch (mcrtype[m]) {
E 138
#if VAX780
D 138
		case VAX_780:
D 62
			error = mcr->mc_reg[2] & M780_ERLOG;
E 62
I 62
			M780_ENA(mcr);
E 138
I 138
		case M780C:
			M780C_ENA(mcr);
E 138
E 62
			break;
I 138
		case M780EL:
			M780EL_ENA(mcr);
			break;
		case M780EU:
			M780EU_ENA(mcr);
			break;
E 138
E 53
E 49
#endif
E 44
D 49

	if (c & MERLOG) {
E 49
I 49
D 53
	if (error) {
		printf("MEMERR: %x %x %x\n", mcr[0], mcr[1], mcr[2]);
E 49
D 21
		printf("MEMERR: %X\n", c);
E 21
I 21
D 44
		printf("MEMERR: mcra %X mcrb %X mcrc %X\n", mcr[0],
		    mcr[1], c);
E 44
I 44
#if VAX==780
D 49
		printf("MEMERR: mcra %X mcrb %X mcrc %X\n", mcr[0], mcr[1], c);
E 44
E 21
		mcr[2] = (MERLOG|MHIERR);
E 49
I 49
D 51
		mcr[2] = M780_ERLOG|M780_MHIERR;
E 51
I 51
		mcr[2] = M780_ERLOG|M780_HIERR;
E 51
E 49
I 44
#else
D 49
		printf("MEMERR: csr0 %X csr1 %X csr2 %X\n", c, mcr[1], mcr[2]);
E 49
		mcr[0] = MERLOG;
E 53
I 53
#if VAX750
D 138
		case VAX_750:
E 138
I 138
		case M750:
E 138
D 62
			error = mcr->mc_reg[0] & M750_ERLOG;
E 62
I 62
			M750_ENA(mcr);
E 62
			break;
E 53
#endif
I 69
D 70
#if VAX730
		case VAX_730:
			M730_ENA(mcr);
E 70
I 70
D 95
#if VAX7ZZ
		case VAX_7ZZ:
			M7ZZ_ENA(mcr);
E 95
I 95
#if VAX730
D 138
		case VAX_730:
E 138
I 138
		case M730:
E 138
			M730_ENA(mcr);
E 95
E 70
			break;
#endif
E 69
E 44
D 53
	}
I 49
#if VAX==750
	mcr[1] = 0;		/* report errors */
E 53
I 53
D 62
		default:
			error = 0;
E 62
		}
D 62
		if (error)
			printf("MEMERR %d: %x %x %x\n", m,
			    mcr->mc_reg[0], mcr->mc_reg[1], mcr->mc_reg[2]);
E 62
I 62
	}
E 180
I 180
	(*cpuops->cpu_memenable)();
E 180
	if (memintvl > 0)
D 129
		timeout(memenable, (caddr_t)0, memintvl);
E 129
I 129
		timeout(memenable, (caddr_t)0, memintvl*hz);
E 129
}

/*
 * Memerr is the interrupt routine for corrected read data
 * interrupts.  It looks to see which memory controllers have
 * unreported errors, reports them, and disables further
 * reporting for a time on those controller.
 */
memerr()
{
I 155
D 180
#ifdef VAX8600
	register int reg11;	/* known to be r11 below */
#endif
E 155
	register struct mcr *mcr;
	register int m;
E 180

I 164
D 180
#if VAX630
	if (cpu == VAX_630)
		return;
#endif
E 164
I 155
#ifdef VAX8600
	if (cpu == VAX_8600) {
		int mdecc, mear, mstat1, mstat2, array;

		/*
		 * Scratchpad registers in the Ebox must be read by
		 * storing their ID number in ESPA and then immediately
		 * reading ESPD's contents with no other intervening
		 * machine instructions!
		 *
		 * The asm's below have a number of constants which
		 * are defined correctly in mem.h and mtpr.h.
		 */
I 160
#ifdef lint
		reg11 = 0;
#else
E 160
		asm("mtpr $0x27,$0x4e; mfpr $0x4f,r11");
I 160
#endif
E 160
		mdecc = reg11;	/* must acknowledge interrupt? */
		if (M8600_MEMERR(mdecc)) {
			asm("mtpr $0x2a,$0x4e; mfpr $0x4f,r11");
			mear = reg11;
			asm("mtpr $0x25,$0x4e; mfpr $0x4f,r11");
			mstat1 = reg11;
			asm("mtpr $0x26,$0x4e; mfpr $0x4f,r11");
			mstat2 = reg11;
			array = M8600_ARRAY(mear);

			printf("mcr0: ecc error, addr %x (array %d) syn %x\n",
				M8600_ADDR(mear), array, M8600_SYN(mdecc));
			printf("\tMSTAT1 = %b\n\tMSTAT2 = %b\n",
				    mstat1, M8600_MSTAT1_BITS,
				    mstat2, M8600_MSTAT2_BITS);
			M8600_INH;
		}
	} else
#endif
E 155
	for (m = 0; m < nmcr; m++) {
		mcr = mcraddr[m];
E 62
D 138
		switch (cpu) {
E 138
I 138
		switch (mcrtype[m]) {
E 138
#if VAX780
D 138
		case VAX_780:
D 62
			mcr->mc_reg[2] = M780_ERLOG|M780_HIERR;
E 62
I 62
			if (M780_ERR(mcr)) {
E 138
I 138
		case M780C:
			if (M780C_ERR(mcr)) {
E 138
D 63
				printf("memerr mcr%d addr %x syn %x\n",
E 63
I 63
				printf("mcr%d: soft ecc addr %x syn %x\n",
E 63
D 138
				    m, M780_ADDR(mcr), M780_SYN(mcr));
E 138
I 138
				    m, M780C_ADDR(mcr), M780C_SYN(mcr));
E 138
I 99
#ifdef TRENDATA
				memlog(m, mcr);
#endif
E 99
D 138
				M780_INH(mcr);
E 138
I 138
				M780C_INH(mcr);
E 138
			}
E 62
			break;
I 138

		case M780EL:
			if (M780EL_ERR(mcr)) {
				printf("mcr%d: soft ecc addr %x syn %x\n",
				    m, M780EL_ADDR(mcr), M780EL_SYN(mcr));
				M780EL_INH(mcr);
			}
			break;

		case M780EU:
			if (M780EU_ERR(mcr)) {
				printf("mcr%d: soft ecc addr %x syn %x\n",
				    m, M780EU_ADDR(mcr), M780EU_SYN(mcr));
				M780EU_INH(mcr);
			}
			break;
E 138
E 53
#endif
I 53
#if VAX750
D 138
		case VAX_750:
E 138
I 138
		case M750:
E 138
D 62
			mcr->mc_reg[0] = M750_ERLOG;
			mcr->mc_reg[1] = 0;
E 62
I 62
			if (M750_ERR(mcr)) {
I 129
				struct mcr amcr;
				amcr.mc_reg[0] = mcr->mc_reg[0];
E 129
I 121
D 127
#ifdef notdef
E 127
E 121
D 63
				printf("memerr mcr%d addr %x syn %x\n",
E 63
I 63
D 139
				printf("mcr%d: soft ecc addr %x syn %x\n",
E 63
D 129
				    m, M750_ADDR(mcr), M750_SYN(mcr));
E 129
I 129
				    m, M750_ADDR(&amcr), M750_SYN(&amcr));
E 139
I 139
				printf("mcr%d: %s",
				    m, (amcr.mc_reg[0] & M750_UNCORR) ?
				    "hard error" : "soft ecc");
				printf(" addr %x syn %x\n",
				    M750_ADDR(&amcr), M750_SYN(&amcr));
E 139
E 129
I 121
D 127
#endif
E 127
E 121
				M750_INH(mcr);
			}
E 62
			break;
#endif
I 69
D 70
#if VAX730
		case VAX_730:
			if (M730_ERR(mcr)) {
E 70
I 70
D 95
#if VAX7ZZ
		case VAX_7ZZ:
			if (M7ZZ_ERR(mcr)) {
E 95
I 95
#if VAX730
D 128
		case VAX_730:
			if (M730_ERR(mcr)) {
E 128
I 128
D 138
		case VAX_730: {
E 138
I 138
		case M730: {
E 138
D 144
			register int mcreg = mcr->mc_reg[1];
E 144
I 144
			struct mcr amcr;
E 144

D 144
			if (mcreg & M730_CRD) {
E 128
E 95
E 70
				struct mcr amcr;
				amcr.mc_reg[0] = mcr->mc_reg[0];
				printf("mcr%d: soft ecc addr %x syn %x\n",
D 70
				    m, M730_ADDR(&amcr), M730_SYN(&amcr));
				M730_INH(mcr);
E 70
I 70
D 95
				    m, M7ZZ_ADDR(&amcr), M7ZZ_SYN(&amcr));
				M7ZZ_INH(mcr);
E 95
I 95
				    m, M730_ADDR(&amcr), M730_SYN(&amcr));
E 144
I 144
			/*
			 * Must be careful on the 730 not to use invalid
			 * instructions in I/O space, so make a copy;
			 */
			amcr.mc_reg[0] = mcr->mc_reg[0];
			amcr.mc_reg[1] = mcr->mc_reg[1];
			if (M730_ERR(&amcr)) {
				printf("mcr%d: %s",
				    m, (amcr.mc_reg[1] & M730_UNCORR) ?
				    "hard error" : "soft ecc");
				printf(" addr %x syn %x\n",
				    M730_ADDR(&amcr), M730_SYN(&amcr));
E 144
				M730_INH(mcr);
E 95
E 70
			}
			break;
I 128
		}
E 128
#endif
E 69
		}
	}
E 180
I 180
	(*cpuops->cpu_memerr)();
E 180
E 53
E 49
D 62
	if (memintvl > 0)
		timeout(memchk, (caddr_t)0, memintvl);
E 62
}
I 99

D 180
#ifdef TRENDATA
E 180
/*
D 180
 * Figure out what chip to replace on Trendata boards.
 * Assumes all your memory is Trendata or the non-Trendata
 * memory never fails..
 */
struct {
	u_char	m_syndrome;
	char	m_chip[4];
} memlogtab[] = {
	0x01,	"C00",	0x02,	"C01",	0x04,	"C02",	0x08,	"C03",
	0x10,	"C04",	0x19,	"L01",	0x1A,	"L02",	0x1C,	"L04",
	0x1F,	"L07",	0x20,	"C05",	0x38,	"L00",	0x3B,	"L03",
	0x3D,	"L05",	0x3E,	"L06",	0x40,	"C06",	0x49,	"L09",
	0x4A,	"L10",	0x4c,	"L12",	0x4F,	"L15",	0x51,	"L17",
	0x52,	"L18",	0x54,	"L20",	0x57,	"L23",	0x58,	"L24",
	0x5B,	"L27",	0x5D,	"L29",	0x5E,	"L30",	0x68,	"L08",
	0x6B,	"L11",	0x6D,	"L13",	0x6E,	"L14",	0x70,	"L16",
	0x73,	"L19",	0x75,	"L21",	0x76,	"L22",	0x79,	"L25",
	0x7A,	"L26",	0x7C,	"L28",	0x7F,	"L31",	0x80,	"C07",
	0x89,	"U01",	0x8A,	"U02",	0x8C,	"U04",	0x8F,	"U07",
	0x91,	"U09",	0x92,	"U10",	0x94,	"U12",	0x97, 	"U15",
	0x98,	"U16",	0x9B,	"U19",	0x9D,	"U21",	0x9E, 	"U22",
	0xA8,	"U00",	0xAB,	"U03",	0xAD,	"U05",	0xAE,	"U06",
	0xB0,	"U08",	0xB3,	"U11",	0xB5,	"U13",	0xB6,	"U14",
	0xB9,	"U17",	0xBA,	"U18",	0xBC,	"U20",	0xBF,	"U23",
	0xC1,	"U25",	0xC2,	"U26",	0xC4,	"U28",	0xC7,	"U31",
	0xE0,	"U24",	0xE3,	"U27",	0xE5,	"U29",	0xE6,	"U30"
};

memlog (m, mcr)
	int m;
	struct mcr *mcr;
{
	register i;

D 138
	switch (cpu) {
E 138
I 138
	switch (mcrtype[m]) {
E 138

#if VAX780
D 138
	case VAX_780:
E 138
I 138
	case M780C:
E 138
	for (i = 0; i < (sizeof (memlogtab) / sizeof (memlogtab[0])); i++)
D 138
		if ((u_char)(M780_SYN(mcr)) == memlogtab[i].m_syndrome) {
E 138
I 138
		if ((u_char)(M780C_SYN(mcr)) == memlogtab[i].m_syndrome) {
E 138
			printf (
	"mcr%d: replace %s chip in %s bank of memory board %d (0-15)\n",
				m,
				memlogtab[i].m_chip,
D 138
				(M780_ADDR(mcr) & 0x8000) ? "upper" : "lower",
				(M780_ADDR(mcr) >> 16));
E 138
I 138
				(M780C_ADDR(mcr) & 0x8000) ? "upper" : "lower",
				(M780C_ADDR(mcr) >> 16));
E 138
			return;
		}
	printf ("mcr%d: multiple errors, not traceable\n", m);
	break;
#endif
	}
}
#endif
E 99

/*
E 180
 * Invalidate single all pte's in a cluster
 */
tbiscl(v)
	unsigned v;
{
	register caddr_t addr;		/* must be first reg var */
	register int i;

	asm(".set TBIS,58");
	addr = ptob(v);
	for (i = 0; i < CLSIZE; i++) {
#ifdef lint
		mtpr(TBIS, addr);
#else
		asm("mtpr r11,$TBIS");
#endif
		addr += NBPG;
I 9
	}
}
D 21

E 21
I 21
  
I 44
D 53
#if VAX==780
E 44
E 21
int	hangcnt;

unhang()
{
	register struct uba_regs *up = (struct uba_regs *)UBA0;

	if (up->uba_sr == 0)
		return;
	hangcnt++;
	if (hangcnt > 5*HZ) {
		hangcnt = 0;
		printf("HANG ");
		ubareset();
E 9
	}
I 27
}
I 44
#endif
E 44

E 53
int	waittime = -1;

D 65
boot(panic, arghowto)
	int panic, arghowto;
E 65
I 65
D 170
boot(paniced, arghowto)
	int paniced, arghowto;
E 170
I 170
D 180
boot(arghowto)
	int arghowto;
E 170
E 65
{
E 180
I 180
boot(howto)
E 180
	register int howto;		/* r11 == how to boot */
I 180
{
E 180
	register int devtype;		/* r10 == major of root dev */
I 173
	extern char *panicstr;
E 173

I 87
D 171
#ifdef lint
I 88
	howto = 0; devtype = 0;
E 88
D 90
	printf("howto %d, devtype %d\n", howto, devtype);
E 90
I 90
	printf("howto %d, devtype %d\n", arghowto, devtype);
E 90
#endif
E 171
I 90
D 91
	(void) spl4();
E 91
I 91
D 141
	(void) spl1();
E 141
E 91
E 90
E 87
D 180
	howto = arghowto;
E 180
D 28
	printf("howto %d\n", howto);
E 28
D 52
	if ((howto&RB_NOSYNC)==0 && waittime < 0) {
E 52
I 52
	if ((howto&RB_NOSYNC)==0 && waittime < 0 && bfreelist[0].b_forw) {
I 171
		register struct buf *bp;
		int iter, nbusy;

E 171
I 90
D 93
		register int cnt;
		register struct buf *bp;
		int iter, nbusy;
E 93
E 90
E 52
		waittime = 0;
I 141
D 143
		(void) spl1();
E 141
D 90
		update();
E 90
I 90
D 108
		update(1);
E 108
I 108
		update();
E 143
I 143
		(void) splnet();
E 143
E 108
E 90
D 28
		printf("updating (wait");
		while (++waittime <= 10) {
			printf(".");
E 28
I 28
		printf("syncing disks... ");
I 157
		/*
		 * Release inodes held by texts before update.
		 */
D 173
		xumount(NODEV);
E 173
I 173
		if (panicstr == 0)
			xumount(NODEV);
E 173
E 157
I 143
		update();
E 143
D 90
		while (++waittime <= 5)
E 28
			sleep((caddr_t)&lbolt, PZERO);
E 90
I 90
D 93
		for (iter = 0; iter < 10; iter++) {
E 93
I 93
D 144
#ifdef notdef
I 136
		DELAY(10000000);
#else
E 144
E 136
D 171
		{ register struct buf *bp;
		  int iter, nbusy;
E 171

D 136
		  for (iter = 0; iter < 10; iter++) {
E 136
I 136
D 171
		  for (iter = 0; iter < 20; iter++) {
E 171
I 171
		for (iter = 0; iter < 20; iter++) {
E 171
E 136
E 93
			nbusy = 0;
			for (bp = &buf[nbuf]; --bp >= buf; )
D 136
				if (bp->b_flags & B_BUSY)
E 136
I 136
				if ((bp->b_flags & (B_BUSY|B_INVAL)) == B_BUSY)
E 136
					nbusy++;
			if (nbusy == 0)
				break;
			printf("%d ", nbusy);
I 144
			DELAY(40000 * iter);
E 144
I 93
D 171
		  }
E 171
E 93
		}
I 93
D 136
#else
		DELAY(10000000);
E 136
D 144
#endif
E 144
E 93
E 90
D 28
		}
		printf(") done\n");
E 28
I 28
D 171
		printf("done\n");
E 171
I 171
		if (nbusy)
			printf("giving up\n");
		else
			printf("done\n");
E 171
I 157
		/*
		 * If we've been adjusting the clock, the todr
		 * will be out of synch; adjust it now.
		 */
		resettodr();
E 157
E 28
	}
	splx(0x1f);			/* extreme priority */
	devtype = major(rootdev);
D 42
	if ((howto&RB_HALT)==0) {
		while ((mfpr(TXCS)&TXCS_RDY) == 0)
			continue;
		mtpr(TXDB, panic == RB_PANIC ? TXDB_AUTOR : TXDB_BOOT);
E 42
I 42
D 43
	if ((howto&RB_HALT))
E 43
I 43
D 44
	if ((howto&RB_HALT)) {
		tocons(0xf01);
E 44
I 44
D 47
#if VAX==780
E 47
D 48
	if (howto&RB_HALT)
E 44
E 43
D 47
		tocons(TXDB_WSI);
E 47
I 47
		tocons(TXDB_DONE);
E 47
D 43
	else if (panic == RB_PANIC)
E 43
I 43
D 44
	} else if (panic == RB_PANIC)
E 44
I 44
	else if (panic == RB_PANIC)
E 44
E 43
D 47
		;			/* sent TXDB_CWSI at boot */
	else {
I 43
D 44
		tocons(0xf01);
E 44
E 43
		tocons(TXDB_WSI);
		tocons(TXDB_BOOT);	/* defboo.cmd, not restar.cmd */
E 42
	}
I 44
#endif
#if VAX==750
	if (howto&RB_HALT)
		;
E 47
I 47
		;			/* cold or warm start */
E 47
	else
E 48
I 48
	if (howto&RB_HALT) {
I 184
		switch (cpu) {

E 184
I 180
D 188
		/* 630 can be told to halt, but how? */
E 188
I 188
#if VAX630
		case VAX_630:
			ka630clock.cpmbx |= KA630CLK_HALT;
			asm("halt");
#endif
E 188
I 184
#if VAX650
		case VAX_650:
D 188
			ka650ssc.ssc_cpmbx &= ~CPMB650_HALTACT;
E 188
			ka650ssc.ssc_cpmbx |= CPMB650_HALT;
			asm("halt");
#endif
I 189
#if NEED_BABYVAX_SUPPORT
		case VAX_410:
		case VAX_3100:
			babyvax_halt();
#endif
E 189
		}
E 184
E 180
		printf("halting (in tight loop); hit\n\t^P\n\tHALT\n\n");
D 180
		mtpr(IPL, 0x1f);
E 180
		for (;;)
			;
	} else {
D 65
		if (panic == RB_PANIC)
E 65
I 65
D 90
		if (paniced == RB_PANIC)
E 65
			doadump();
E 90
I 90
D 170
		if (paniced == RB_PANIC) {
E 170
I 170
D 180
		if (howto & RB_DUMP) {
E 170
D 156
			doadump();		/* TXDB_BOOT's itsself */
E 156
I 156
			doadump();		/* TXDB_BOOT's itself */
E 156
			/*NOTREACHED*/
		}
E 90
E 48
		tocons(TXDB_BOOT);
E 180
I 180
		if (howto & RB_DUMP)
			doadump();
		vaxboot();
E 180
I 48
	}
E 48
I 47
D 56
#if VAX==750
E 47
	{ asm("movl r11,r5"); }		/* where boot flags go on comet */
E 56
I 56
D 69
#if VAX750
	if (cpu == VAX_750)
E 69
I 69
D 70
#if defined(VAX750) || defined(VAX730)
E 70
I 70
D 95
#if defined(VAX750) || defined(VAX7ZZ)
E 95
I 95
D 164
#if defined(VAX750) || defined(VAX730)
E 95
E 70
D 155
	if (cpu != VAX_780)
E 155
I 155
	if (cpu == VAX_750 || cpu == VAX_730)
E 164
I 164
D 180
#if defined(VAX750) || defined(VAX730) || defined(VAX630)
	if (cpu == VAX_750 || cpu == VAX_730 || cpu == VAX_630)
E 164
E 155
E 69
		{ asm("movl r11,r5"); }		/* boot flags go in r5 */
E 56
#endif
E 44
	for (;;)
		asm("halt");
E 180
I 171
#ifdef lint
D 180
	printf("howto %d, devtype %d\n", arghowto, devtype);
E 180
I 180
	devtype = devtype;
E 180
#endif
E 171
I 42
D 87
#ifdef lint
	printf("howto %d, devtype %d\n", howto, devtype);
#endif
E 87
	/*NOTREACHED*/
}

I 180
/*
 * Reboot after panic or via reboot system call.  Note that r11
 * and r10 must already have the proper boot values (`call by voodoo').
 */
vaxboot()
{

	switch (cpu) {

#ifdef VAX8200
	case VAX_8200:
		/*
		 * TXDB_BOOT erases memory!  Instead we set the `did
		 * a dump' flag in the rpb.
		 */
		*(int *)&Sysmap[0] &= ~PG_PROT;
		*(int *)&Sysmap[0] |= PG_KW;
		mtpr(TBIS, &rpb);
		rpb.rp_flag = 1;
		break;
#endif

I 184
D 188
#ifdef VAX650
E 188
I 188
#if VAX630
	case VAX_630:
		/* set boot-on-halt flag in "console mailbox" */
		ka630clock.cpmbx &= ~KA630CLK_HLTACT;
		ka630clock.cpmbx |= KA630CLK_REBOOT;
		break;
#endif

#if VAX650
E 188
	case VAX_650:
		/* set boot-on-halt flag in "console mailbox" */
		ka650ssc.ssc_cpmbx &= ~CPMB650_HALTACT;
		ka650ssc.ssc_cpmbx |= CPMB650_REBOOT;
I 189
		break;
#endif

#if NEED_BABYVAX_SUPPORT
	case VAX_410:
	case VAX_3100:
		babyvax_set_haltact(2);
E 189
		break;
#endif

E 184
	default:
		tocons(TXDB_BOOT);
	}

	/*
	 * Except on 780s and 8600s, boot flags go in r5.  SBI
	 * VAXen do not care, so copy boot flags to r5 always.
	 */
	asm("movl r11,r5");
	for (;;) {
		asm("halt");
	}
}

E 180
tocons(c)
{
I 156
D 180
	register oldmask;
E 180
I 180
	register int oldmask;
E 180
E 156

D 156
	while ((mfpr(TXCS)&TXCS_RDY) == 0)
E 156
I 156
	while (((oldmask = mfpr(TXCS)) & TXCS_RDY) == 0)
E 156
		continue;
I 156

	switch (cpu) {

D 164
#if VAX780 || VAX750 || VAX730
E 164
I 164
D 180
#if VAX780 || VAX750 || VAX730 || VAX630
E 180
I 180
D 183
#if VAX8200 || VAX780 || VAX750 || VAX730 || VAX630
E 183
I 183
D 184
#if VAX8200 || VAX780 || VAX750 || VAX730 || VAX630 || VAX650
E 184
I 184
#if VAX8200 || VAX780 || VAX750 || VAX730 || VAX630
E 184
E 183
	case VAX_8200:
E 180
E 164
	case VAX_780:
	case VAX_750:
	case VAX_730:
I 164
	case VAX_630:
I 183
D 184
	case VAX_650:
E 184
E 183
E 164
		c |= TXDB_CONS;
		break;
#endif

#if VAX8600
	case VAX_8600:
		mtpr(TXCS, TXCS_LCONS | TXCS_WMASK);
		while ((mfpr(TXCS) & TXCS_RDY) == 0)
			continue;
		break;
I 184
#endif

#if VAX650
	case VAX_650:
		/* everything is a real console terminal character on ka650 */
		return;
E 184
#endif
	}

E 156
	mtpr(TXDB, c);
I 156

#if VAX8600
	switch (cpu) {

	case VAX_8600:
		while ((mfpr(TXCS) & TXCS_RDY) == 0)
			continue;
		mtpr(TXCS, oldmask | TXCS_WMASK);
		break;
	}
#endif
I 180
#ifdef lint
	oldmask = oldmask;
#endif
E 180
E 156
I 48
}

I 120
int	dumpmag = 0x8fca0101;	/* magic number for savecore */
int	dumpsize = 0;		/* also for savecore */
E 120
/*
 * Doadump comes here after turning off memory management and
 * getting on the dump stack, either when called above, or by
 * the auto-restart code.
 */
dumpsys()
{

I 76
	rpb.rp_flag = 1;
I 179
	msgbufmapped = 0;
E 179
I 169
	if (dumpdev == NODEV)
		return;
E 169
I 130
D 179
#ifdef notdef
E 130
E 76
	if ((minor(dumpdev)&07) != 1)
		return;
I 130
#endif
E 179
I 169
	/*
	 * For dumps during autoconfiguration,
	 * if dump device has already configured...
	 */
	if (dumplo == 0 && bdevsw[major(dumpdev)].d_psize)
		dumplo = (*bdevsw[major(dumpdev)].d_psize)(dumpdev) - physmem;
	if (dumplo < 0)
		dumplo = 0;
E 169
E 130
I 120
	dumpsize = physmem;
E 120
	printf("\ndumping to dev %x, offset %d\n", dumpdev, dumplo);
D 53
	printf("dump %s\n", (*bdevsw[major(dumpdev)].d_dump)(dumpdev) ? "failed" : "succeeded");
E 53
I 53
D 62
	printf("dump %s\n",
	    (*bdevsw[major(dumpdev)].d_dump)(dumpdev) ?
		"failed" : "succeeded");
E 62
I 62
	printf("dump ");
	switch ((*bdevsw[major(dumpdev)].d_dump)(dumpdev)) {

	case ENXIO:
		printf("device bad\n");
		break;

	case EFAULT:
		printf("device not ready\n");
		break;

	case EINVAL:
		printf("area improper\n");
		break;

	case EIO:
		printf("i/o error");
		break;

	default:
		printf("succeeded");
		break;
	}
E 62
E 53
E 48
E 42
E 27
}
I 55

I 62
/*
 * Machine check error recovery code.
D 180
 * Print out the machine check frame and then give up.
E 180
 */
I 153
D 180
#if VAX8600
D 155
#define NMC8600	6
E 155
I 155
#define NMC8600	7
E 155
char *mc8600[] = {
	"unkn type",	"fbox error",	"ebox error",	"ibox error",
D 155
	"mbox error",	"tbuf error"
E 155
I 155
	"mbox error",	"tbuf error",	"mbox 1D error"
E 155
};
I 155
/* codes for above */
#define	MC_FBOX		1
#define	MC_EBOX		2
#define	MC_IBOX		3
#define	MC_MBOX		4
#define	MC_TBUF		5
#define	MC_MBOX1D	6
E 180
I 180
machinecheck(cmcf)
	caddr_t cmcf;
{
E 180

D 180
/* error bits */
#define	MBOX_FE		0x8000		/* Mbox fatal error */
#define	FBOX_SERV	0x10000000	/* Fbox service error */
#define	IBOX_ERR	0x2000		/* Ibox error */
#define	EBOX_ERR	0x1e00		/* Ebox error */
#define	MBOX_1D		0x81d0000	/* Mbox 1D error */
#define EDP_PE		0x200
E 155
#endif
E 180
I 180
	if ((*cpuops->cpu_mchk)(cmcf) == MCHK_RECOVERED)
		return;
	(*cpuops->cpu_memerr)();
	panic("mchk");
}
E 180
I 155

E 155
E 153
I 69
#if defined(VAX780) || defined(VAX750)
E 69
E 62
D 58
#if VAX780
E 58
D 180
char *mc780[] = {
E 180
I 180
/*
 * These strings are shared between the 780 and 750 machine check code
 * in ka780.c and ka730.c.
 */
char *mc780750[16] = {
E 180
	"cp read",	"ctrl str par",	"cp tbuf par",	"cp cache par",
	"cp rdtimo", 	"cp rds",	"ucode lost",	0,
	0,		0,		"ib tbuf par",	0,
	"ib rds",	"ib rd timo",	0,		"ib cache par"
I 188
};
#endif

#if NEED_UV2_SUPPORT
/*
 * These strings are shared between ka630.c and ka410.c.  Since both use
 * the same 78032 CPU chip, machine checks are obviously identical.
 */
char *mcuv2[] = {
	0,		"immcr (fsd)",	"immcr (ssd)",	"fpu err 0",
	"fpu err 7",	"mmu st(tb)",	"mmu st(m=0)",	"pte in p0",
	"pte in p1",	"un intr id",
E 188
};
I 103
D 126
#define	MC780_TBPAR	2
#define	MC750_TBPAR	2
E 126
I 126
D 144
#define	MC750_TBPAR	4
E 144
I 144
D 180
#define MC750_TBERR	2		/* type code of cp tbuf par */
#define	MC750_TBPAR	4		/* tbuf par bit in mcesr */
E 180
E 144
E 126
E 103
I 69
#endif
I 155

E 155
D 70
#if VAX730
#define	NMC730	12
char *mc730[] = {
E 70
I 70
D 95
#if VAX7ZZ
#define	NMC7ZZ	12
char *mc7ZZ[] = {
E 95
I 95
D 180
#if VAX730
#define	NMC730	12
char *mc730[] = {
E 95
E 70
	"tb par",	"bad retry",	"bad intr id",	"cant write ptem",
	"unkn mcr err",	"iib rd err",	"nxm ref",	"cp rds",
	"unalgn ioref",	"nonlw ioref",	"bad ioaddr",	"unalgn ubaddr",
};
I 103
D 126
#define	MC730_TBPAR	0
E 126
E 103
#endif
I 164
#if VAX630
#define NMC630	10
extern struct ka630cpu ka630cpu;
char *mc630[] = {
	0,		"immcr (fsd)",	"immcr (ssd)",	"fpu err 0",
	"fpu err 7",	"mmu st(tb)",	"mmu st(m=0)",	"pte in p0",
	"pte in p1",	"un intr id",
};
#endif
E 164
E 69

E 180
I 62
/*
D 69
 * Frame for a 780
E 69
I 69
D 180
 * Frame for each cpu
E 69
 */
E 62
struct mc780frame {
D 57
	int	mc7_bcnt;
	int	mc7_summary;
	int	mc7_cpues;
	int	mc7_upc;
	int	mc7_vaviba;
	int	mc7_dreg;
	int	mc7_tber0;
	int	mc7_tber1;
	int	mc7_timo;
	int	mc7_parity;
	int	mc7_sbier;
	int	mc7_pc;
	int	mc7_psl;
E 57
I 57
D 62
	int	mc8_bcnt;
	int	mc8_summary;
	int	mc8_cpues;
	int	mc8_upc;
	int	mc8_vaviba;
	int	mc8_dreg;
	int	mc8_tber0;
	int	mc8_tber1;
	int	mc8_timo;
	int	mc8_parity;
	int	mc8_sbier;
	int	mc8_pc;
	int	mc8_psl;
E 62
I 62
D 69
	int	mc8_bcnt;		/* byte count == 28 */
E 69
I 69
	int	mc8_bcnt;		/* byte count == 0x28 */
E 69
	int	mc8_summary;		/* summary parameter (as above) */
	int	mc8_cpues;		/* cpu error status */
	int	mc8_upc;		/* micro pc */
	int	mc8_vaviba;		/* va/viba register */
	int	mc8_dreg;		/* d register */
	int	mc8_tber0;		/* tbuf error reg 0 */
	int	mc8_tber1;		/* tbuf error reg 1 */
	int	mc8_timo;		/* timeout address divided by 4 */
	int	mc8_parity;		/* parity */
	int	mc8_sbier;		/* sbi error register */
	int	mc8_pc;			/* trapped pc */
	int	mc8_psl;		/* trapped psl */
E 62
E 57
};
I 57
struct mc750frame {
D 62
	int	mc5_bcnt;
	int	mc5_summary;
	int	mc5_va;
	int	mc5_errpc;
E 62
I 62
D 69
	int	mc5_bcnt;		/* byte count == 28 */
E 69
I 69
	int	mc5_bcnt;		/* byte count == 0x28 */
E 69
	int	mc5_summary;		/* summary parameter (as above) */
	int	mc5_va;			/* virtual address register */
	int	mc5_errpc;		/* error pc */
E 62
	int	mc5_mdr;
D 62
	int	mc5_svmode;
	int	mc5_rdtimo;
	int	mc5_tbgpar;
	int	mc5_cacherr;
	int	mc5_buserr;
	int	mc5_mcesr;
	int	mc5_pc;
	int	mc5_psl;
E 62
I 62
	int	mc5_svmode;		/* saved mode register */
	int	mc5_rdtimo;		/* read lock timeout */
	int	mc5_tbgpar;		/* tb group parity error register */
	int	mc5_cacherr;		/* cache error register */
	int	mc5_buserr;		/* bus error register */
	int	mc5_mcesr;		/* machine check status register */
	int	mc5_pc;			/* trapped pc */
	int	mc5_psl;		/* trapped psl */
E 62
};
I 69
D 70
struct mc730frame {
E 70
I 70
D 95
struct mc7ZZframe {
E 95
I 95
struct mc730frame {
E 95
E 70
	int	mc3_bcnt;		/* byte count == 0xc */
	int	mc3_summary;		/* summary parameter */
	int	mc3_parm[2];		/* parameter 1 and 2 */
	int	mc3_pc;			/* trapped pc */
	int	mc3_psl;		/* trapped psl */
};
I 164
struct mc630frame {
	int	mc63_bcnt;		/* byte count == 0xc */
	int	mc63_summary;		/* summary parameter */
	int	mc63_mrvaddr;		/* most recent vad */
	int	mc63_istate;		/* internal state */
	int	mc63_pc;			/* trapped pc */
	int	mc63_psl;		/* trapped psl */
};
E 164
I 153
struct mc8600frame {
	int	mc6_bcnt;		/* byte count == 0x58 */
	int	mc6_ehmsts;
	int	mc6_evmqsav;
	int	mc6_ebcs;
	int	mc6_edpsr;
	int	mc6_cslint;
	int	mc6_ibesr;
	int	mc6_ebxwd1;
	int	mc6_ebxwd2;
	int	mc6_ivasav;
	int	mc6_vibasav;
	int	mc6_esasav;
	int	mc6_isasav;
	int	mc6_cpc;
	int	mc6_mstat1;
	int	mc6_mstat2;
	int	mc6_mdecc;
	int	mc6_merg;
	int	mc6_cshctl;
	int	mc6_mear;
	int	mc6_medr;
	int	mc6_accs;
	int	mc6_cses;
	int	mc6_pc;			/* trapped pc */
	int	mc6_psl;		/* trapped psl */
};
E 153
E 69
E 57

D 57
machinecheck(mcf)
	register struct mc780frame *mcf;
E 57
I 57
machinecheck(cmcf)
	caddr_t cmcf;
E 57
{
D 57
	register int type = mcf->mc7_summary;
	register int sbifs;
E 57
I 57
D 69
	register int type = ((struct mc780frame *)cmcf)->mc8_summary;
E 69
I 69
	register u_int type = ((struct mc780frame *)cmcf)->mc8_summary;
E 69
E 57

D 69
	printf("machine check %x: %s%s\n", type, mc780[type&0xf],
	    (type&0xf0) ? " abort" : " fault"); 
E 69
I 69
	printf("machine check %x: ", type);
E 69
D 57
	printf("\tcpues %x upc %x va/viba %x dreg %x tber %x %x\n",
	   mcf->mc7_cpues, mcf->mc7_upc, mcf->mc7_vaviba,
	   mcf->mc7_dreg, mcf->mc7_tber0, mcf->mc7_tber1);
	sbifs = mfpr(SBIFS);
	printf("\ttimo %x parity %x sbier %x pc %x psl %x sbifs %x\n",
	   mcf->mc7_timo*4, mcf->mc7_parity, mcf->mc7_sbier,
	   mcf->mc7_pc, mcf->mc7_psl, sbifs);
	mtpr(SBIFS, sbifs &~ 0x2000000);
	mtpr(SBIER, mfpr(SBIER) | 0x70c0);
E 57
I 57
	switch (cpu) {
D 153
#if VAX780
I 69
	case VAX_780:
#endif
#if VAX750
	case VAX_750:
#endif
#if defined(VAX780) || defined(VAX750)
D 74
		printf("%s%s\n", type, mc780[type&0xf],
E 74
I 74
		printf("%s%s\n", mc780[type&0xf],
E 74
		    (type&0xf0) ? " abort" : " fault"); 
		break;
#endif
D 70
#if VAX730
	case VAX_730:
		if (type < NMC730)
			printf("%s", mc730[type]);
E 70
I 70
D 95
#if VAX7ZZ
	case VAX_7ZZ:
		if (type < NMC7ZZ)
			printf("%s", mc7ZZ[type]);
E 95
I 95
#if VAX730
	case VAX_730:
		if (type < NMC730)
			printf("%s", mc730[type]);
E 153
I 153
#if VAX8600
	case VAX_8600: {
		register struct mc8600frame *mcf = (struct mc8600frame *)cmcf;

D 155
		if (mcf->mc6_ebcs & 0x8000)
			mcf->mc6_ehmsts |= 0x4;
		else if (mcf->mc6_ehmsts & 0x10000000)
			mcf->mc6_ehmsts |= 0x1;
		else if (mcf->mc6_ebcs & 0x1e00)	
			if (mcf->mc6_ebcs & 0x200)
				mcf->mc6_ehmsts |= 0x4;
E 155
I 155
		if (mcf->mc6_ebcs & MBOX_FE)
			mcf->mc6_ehmsts |= MC_MBOX;
		else if (mcf->mc6_ehmsts & FBOX_SERV)
			mcf->mc6_ehmsts |= MC_FBOX;
		else if (mcf->mc6_ebcs & EBOX_ERR) {
			if (mcf->mc6_ebcs & EDP_PE)
				mcf->mc6_ehmsts |= MC_MBOX;
E 155
			else
D 155
				mcf->mc6_ehmsts |= 0x2;
		else if (mcf->mc6_ehmsts & 0x2000)
			mcf->mc6_ehmsts |= 0x3;
		if (!(mcf->mc6_ehmsts & 0xf) && (mcf->mc6_mstat1 & 0xf00))
			mcf->mc6_ehmsts |= 0x5;
E 155
I 155
				mcf->mc6_ehmsts |= MC_EBOX;
		} else if (mcf->mc6_ehmsts & IBOX_ERR)
			mcf->mc6_ehmsts |= MC_IBOX;
		else if (mcf->mc6_mstat1 & M8600_TB_ERR)
			mcf->mc6_ehmsts |= MC_TBUF;
		else if ((mcf->mc6_cslint & MBOX_1D) == MBOX_1D)
			mcf->mc6_ehmsts |= MC_MBOX1D;

E 155
		type = mcf->mc6_ehmsts & 0x7;
		if (type < NMC8600)
			printf("machine check %x: %s", type, mc8600[type]);
E 153
E 95
E 70
		printf("\n");
I 153
		printf("\tehm.sts %x evmqsav %x ebcs %x edpsr %x cslint %x\n",
		    mcf->mc6_ehmsts, mcf->mc6_evmqsav, mcf->mc6_ebcs,
		    mcf->mc6_edpsr, mcf->mc6_cslint);
		printf("\tibesr %x ebxwd %x %x ivasav %x vibasav %x\n",
		    mcf->mc6_ibesr, mcf->mc6_ebxwd1, mcf->mc6_ebxwd2,
		    mcf->mc6_ivasav, mcf->mc6_vibasav);
		printf("\tesasav %x isasav %x cpc %x mstat %x %x mdecc %x\n",
		    mcf->mc6_esasav, mcf->mc6_isasav, mcf->mc6_cpc,
		    mcf->mc6_mstat1, mcf->mc6_mstat2, mcf->mc6_mdecc);
		printf("\tmerg %x cshctl %x mear %x medr %x accs %x cses %x\n",
		    mcf->mc6_merg, mcf->mc6_cshctl, mcf->mc6_mear,
		    mcf->mc6_medr, mcf->mc6_accs, mcf->mc6_cses);
		printf("\tpc %x psl %x\n", mcf->mc6_pc, mcf->mc6_psl);
		mtpr(EHSR, 0);
E 153
		break;
I 153
	};
E 153
#endif
D 153
	}
	switch (cpu) {
E 153
#if VAX780
E 69
	case VAX_780: {
		register struct mc780frame *mcf = (struct mc780frame *)cmcf;
I 153

E 153
		register int sbifs;
I 153
		printf("%s%s\n", mc780[type&0xf],
		    (type&0xf0) ? " abort" : " fault"); 
E 153
		printf("\tcpues %x upc %x va/viba %x dreg %x tber %x %x\n",
		   mcf->mc8_cpues, mcf->mc8_upc, mcf->mc8_vaviba,
		   mcf->mc8_dreg, mcf->mc8_tber0, mcf->mc8_tber1);
		sbifs = mfpr(SBIFS);
		printf("\ttimo %x parity %x sbier %x pc %x psl %x sbifs %x\n",
		   mcf->mc8_timo*4, mcf->mc8_parity, mcf->mc8_sbier,
		   mcf->mc8_pc, mcf->mc8_psl, sbifs);
		/* THE FUNNY BITS IN THE FOLLOWING ARE FROM THE ``BLACK */
D 102
		/* BOOK AND SHOULD BE PUT IN AN ``sbi.h'' */
E 102
I 102
		/* BOOK'' AND SHOULD BE PUT IN AN ``sbi.h'' */
E 102
		mtpr(SBIFS, sbifs &~ 0x2000000);
		mtpr(SBIER, mfpr(SBIER) | 0x70c0);
		break;
	}
#endif
#if VAX750
	case VAX_750: {
		register struct mc750frame *mcf = (struct mc750frame *)cmcf;
I 144
D 153
		int mcsr = mfpr(MCSR);
E 153

I 153
		int mcsr = mfpr(MCSR);
		printf("%s%s\n", mc780[type&0xf],
		    (type&0xf0) ? " abort" : " fault"); 
E 153
		mtpr(TBIA, 0);
		mtpr(MCESR, 0xf);
E 144
D 84
		printf("\tva %x errpc %x mdr %x smr %x tbgpar %x cacherr %x\n",
E 84
I 84
		printf("\tva %x errpc %x mdr %x smr %x rdtimo %x tbgpar %x cacherr %x\n",
E 84
		    mcf->mc5_va, mcf->mc5_errpc, mcf->mc5_mdr, mcf->mc5_svmode,
		    mcf->mc5_rdtimo, mcf->mc5_tbgpar, mcf->mc5_cacherr);
		printf("\tbuserr %x mcesr %x pc %x psl %x mcsr %x\n",
		    mcf->mc5_buserr, mcf->mc5_mcesr, mcf->mc5_pc, mcf->mc5_psl,
D 144
		    mfpr(MCSR));
I 69
		mtpr(MCESR, 0xf);
I 103
D 126
		if ((type&0xf)==MC750_TBPAR) {
			printf("tbuf par!?!: flushing and returning\n");
E 126
I 126
		if ((mcf->mc5_mcesr&0xf) == MC750_TBPAR) {
E 144
I 144
		    mcsr);
		if (type == MC750_TBERR && (mcf->mc5_mcesr&0xe) == MC750_TBPAR){
E 144
			printf("tbuf par: flushing and returning\n");
E 126
D 144
			mtpr(TBIA, 0);
E 144
			return;
		}
E 103
		break;
		}
#endif
D 70
#if VAX730
	case VAX_730: {
		register struct mc730frame *mcf = (struct mc730frame *)cmcf;
E 70
I 70
D 95
#if VAX7ZZ
	case VAX_7ZZ: {
		register struct mc7ZZframe *mcf = (struct mc7ZZframe *)cmcf;
E 95
I 95
#if VAX730
	case VAX_730: {
		register struct mc730frame *mcf = (struct mc730frame *)cmcf;
I 153

		if (type < NMC730)
			printf("%s", mc730[type]);
		printf("\n");
E 153
E 95
E 70
		printf("params %x,%x pc %x psl %x mcesr %x\n",
		    mcf->mc3_parm[0], mcf->mc3_parm[1],
		    mcf->mc3_pc, mcf->mc3_psl, mfpr(MCESR));
E 69
		mtpr(MCESR, 0xf);
I 164
		break;
		}
#endif
#if VAX630
	case VAX_630: {
		register struct ka630cpu *ka630addr = &ka630cpu;
		register struct mc630frame *mcf = (struct mc630frame *)cmcf;
		printf("vap %x istate %x pc %x psl %x\n",
		    mcf->mc63_mrvaddr, mcf->mc63_istate,
		    mcf->mc63_pc, mcf->mc63_psl);
		if (ka630addr->ka630_mser & KA630MSER_MERR) {
			printf("mser=0x%x ",ka630addr->ka630_mser);
			if (ka630addr->ka630_mser & KA630MSER_CPUER)
				printf("page=%d",ka630addr->ka630_cear);
			if (ka630addr->ka630_mser & KA630MSER_DQPE)
				printf("page=%d",ka630addr->ka630_dear);
			printf("\n");
		}
E 164
		break;
		}
#endif
	}
I 92
	memerr();
E 92
E 57
	panic("mchk");
I 104
}

I 160
/*
E 180
 * Return the best possible estimate of the time in the timeval
 * to which tvp points.  We do this by reading the interval count
 * register to determine the time remaining to the next clock tick.
 * We must compensate for wraparound which is not yet reflected in the time
 * (which happens when the ICR hits 0 and wraps after the splhigh(),
 * but before the mfpr(ICR)).  Also check that this time is no less than
 * any previously-reported time, which could happen around the time
 * of a clock adjustment.  Just for fun, we guarantee that the time
 * will be greater than the value obtained by a previous call.
 */
E 160
I 109
D 157
#ifdef notdef
E 157
E 109
microtime(tvp)
D 157
	struct timeval *tvp;
E 157
I 157
	register struct timeval *tvp;
E 157
{
D 157
	int s = spl7();
E 157
I 157
	int s = splhigh();
I 160
D 166
	extern int adjtimedelta, tickadj;
E 166
	static struct timeval lasttime;
	register long t;
E 160
E 157

D 157
	tvp->tv_sec = time.tv_sec;
	tvp->tv_usec = (lbolt+1)*16667 + mfpr(ICR);
E 157
I 157
	*tvp = time;
D 160
	tvp->tv_usec += tick + mfpr(ICR);
E 157
	while (tvp->tv_usec > 1000000) {
E 160
I 160
	t =  mfpr(ICR);
	if (t < -tick / 2 && (mfpr(ICCS) & ICCS_INT))
		t += tick;
	tvp->tv_usec += tick + t;
D 190
	if (tvp->tv_usec > 1000000) {
E 190
I 190
	if (tvp->tv_usec >= 1000000) {
E 190
E 160
		tvp->tv_sec++;
		tvp->tv_usec -= 1000000;
	}
I 160
	if (tvp->tv_sec == lasttime.tv_sec &&
	    tvp->tv_usec <= lasttime.tv_usec &&
D 165
	    (tvp->tv_usec = lasttime.tv_sec + 1) > 1000000) {
E 165
I 165
D 190
	    (tvp->tv_usec = lasttime.tv_usec + 1) > 1000000) {
E 190
I 190
	    (tvp->tv_usec = lasttime.tv_usec + 1) >= 1000000) {
E 190
E 165
		tvp->tv_sec++;
		tvp->tv_usec -= 1000000;
	}
	lasttime = *tvp;
E 160
	splx(s);
E 104
}
I 109
D 157
#endif
E 157
I 113

D 180
physstrat(bp, strat, prio)
	struct buf *bp;
	int (*strat)(), prio;
{
	int s;

	(*strat)(bp);
I 116
	/* pageout daemon doesn't wait for pushed pages */
	if (bp->b_flags & B_DIRTY)
		return;
E 116
D 157
	s = spl6();
E 157
I 157
	s = splbio();
E 157
	while ((bp->b_flags & B_DONE) == 0)
		sleep((caddr_t)bp, prio);
	splx(s);
I 153
}

E 180
D 154
setcache(val)
int val;
E 154
I 154
initcpu()
E 154
{
D 154
	switch(cpu) {
E 154
I 154
	/*
	 * Enable cache.
	 */
	switch (cpu) {

I 180
#if VAX8600
	case VAX_8600:
		mtpr(CSWP, 3);
		break;
#endif
#if VAX8200
	case VAX_8200:
		mtpr(CADR, 0);
		break;
#endif
E 180
E 154
#if VAX780
	case VAX_780:
D 154
		mtpr(SBIMT, val);
E 154
I 154
		mtpr(SBIMT, 0x200000);
E 154
		break;
#endif
#if VAX750
	case VAX_750:
D 154
		mtpr(CADR, val);
E 154
I 154
		mtpr(CADR, 0);
E 154
		break;
#endif
D 180
#if VAX8600
	case VAX_8600:
D 154
		mtpr(CSWP, val);
E 154
I 154
		mtpr(CSWP, 3);
E 154
		break;
I 154
#endif
E 180
	default:
		break;
	}

	/*
	 * Enable floating point accelerator if it exists
	 * and has control register.
	 */
	switch(cpu) {

#if VAX8600 || VAX780
D 180
	case VAX_780:
E 180
	case VAX_8600:
I 180
	case VAX_780:
E 180
		if ((mfpr(ACCS) & 0xff) != 0) {
			printf("Enabling FPA\n");
			mtpr(ACCS, 0x8000);
		}
E 154
#endif
	default:
		break;
	}
E 153
}
I 175

/*
D 180
 * Return a reasonable approximation to a time-of-day register.
E 180
I 180
 * Return a reasonable approximation of the time of day register.
E 180
 * More precisely, return a number that increases by one about
 * once every ten milliseconds.
 */
todr()
{
I 180

E 180
	switch (cpu) {

D 183
#if VAX8600 || VAX8200 || VAX780 || VAX750 || VAX730
E 183
I 183
#if VAX8600 || VAX8200 || VAX780 || VAX750 || VAX730 || VAX650
E 183
	case VAX_8600:
D 180
	/* case VAX_8200: */
E 180
I 180
	case VAX_8200:
E 180
	case VAX_780:
	case VAX_750:
	case VAX_730:
I 183
	case VAX_650:
E 183
		return (mfpr(TODR));
#endif

#if VAX630
	case VAX_630:
		/* XXX crude */
		{ static int t; DELAY(10000); return (++t); }
#endif

	default:
		panic("todr");
	}
	/* NOTREACHED */
}
E 175
E 113
E 109
D 58
#endif
E 58
E 55
E 1
