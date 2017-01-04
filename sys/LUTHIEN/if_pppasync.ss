.data
.comm	_cpuspeed,4
.comm	_bdevsw,0
.comm	_cdevsw,0
.comm	_linesw,0
.comm	_swdevt,0
.comm	_mbstat,540
.comm	_nmbclusters,4
.comm	_mfree,4
.comm	_mclfree,4
.comm	_mclrefcnt,257
.comm	_m_want,4
.comm	_buf,4
.comm	_buffers,4
.comm	_nbuf,4
.comm	_bufpages,4
.comm	_swbuf,4
.comm	_nswbuf,4
.comm	_bufhash,6144
.comm	_bfreelist,224
.comm	_bswlist,56
.comm	_bclnlist,4
.comm	_cp_time,16
.comm	_dk_ndrive,4
.comm	_dk_busy,4
.comm	_dk_time,32
.comm	_dk_seek,32
.comm	_dk_xfer,32
.comm	_dk_wds,32
.comm	_dk_mspw,32
.comm	_tk_nin,4
.comm	_tk_nout,4
.comm	_file,4
.comm	_fileNFILE,4
.comm	_nfile,4
.comm	_tthiwat,32
.comm	_ttlowat,32
.comm	_rawintrq,20
.comm	_ifnet,4
.comm	_pppasync_phw,24
.comm	_pppasync_dtr_hack,4
.text
LL0:
.align	1
.globl	_pppasync_init
_pppasync_init:.word	L108
.set	L108,0x0
.data
.text
movw	$2046,_pppasync_phw
movw	$2046,_pppasync_phw+2
movw	$1023,_pppasync_phw+4
moval	_pppasync_output,_pppasync_phw+8
moval	_pppasync_up,_pppasync_phw+12
moval	_pppasync_down,_pppasync_phw+16
moval	_pppasync_check,_pppasync_phw+20
ret
.align	1
.globl	_pppasync_topen
_pppasync_topen:.word	L113
.set	L113,0x800
.data
.text
movl	8(ap),r11
cmpb	71(r11),$5
jneq	L117
movl	$16,r0
ret
L117:
movl	$25,r0
ret
.align	1
.globl	_pppasync_attach
_pppasync_attach:.word	L119
.data	1
L131:
.ascii	"ppp%d\72 can't allocate async receive buffer\12\0"
.text
.set	L119,0xe00
.data
.text
movl	8(ap),r11
movl	12(ap),r10
calls	$0,_suser
tstl	r0
jneq	L124
movl	$1,r0
ret
L124:
cmpl	r10,$8
jlss	L125
movl	$6,r0
ret
L125:
mull3	$144,r10,r0
movab	_ppp_softc[r0],r9
cmpb	71(r11),$5
jneq	L126
cmpl	48(r11),r9
jneq	L126
L2000000:
clrl	r0
ret
L126:
cmpb	71(r11),$5
jneq	L127
L2000001:
movl	$16,r0
ret
L127:
tstl	84(r9)
jneq	L2000001
pushl	$1
pushl	$2
cvtwl	$2048,-(sp)
calls	$3,_malloc
movl	r0,128(r9)
tstl	128(r9)
jneq	L129
subl3	$_ppp_softc,r9,r0
divl3	$144,r0,-(sp)
pushal	L131
calls	$2,_printf
movl	$55,r0
ret
L129:
clrw	140(r9)
movw	$65535,138(r9)
moval	_pppasync_phw,84(r9)
movl	r11,88(r9)
movl	r9,48(r11)
cvtlb	$5,71(r11)
movw	_pppasync_phw,96(r9)
movw	_pppasync_phw+2,98(r9)
pushl	$3
pushl	r11
calls	$2,_ttyflush
jbr	L2000000
.align	1
.globl	_pppasync_tclose
_pppasync_tclose:.word	L134
.set	L134,0x800
.data
.text
subl2	$4,sp
movl	4(ap),r0
movl	48(r0),r11
	mfpr	$18,r0
	mtpr	$0xc,$18
movl	r0,-4(fp)
pushl	r11
calls	$1,_pppreset
	movl	-4(fp),r0
	mtpr	r0,$18
clrl	84(r11)
movl	4(ap),r0
clrl	48(r0)
pushl	$2
pushl	128(r11)
calls	$2,_free
pushl	4(ap)
calls	$1,_ttywflush
movl	4(ap),r0
clrb	71(r0)
ret
.align	1
.globl	_pppasync_tioctl
_pppasync_tioctl:.word	L143
.set	L143,0x0
.data
.text
cmpl	8(ap),$1074033756
jneq	L147
movl	4(ap),r0
movl	48(r0),r0
cvtwl	4(r0),*12(ap)
clrl	r0
ret
L147:
mnegl	$1,r0
ret
.align	1
.globl	_pppasync_output
_pppasync_output:.word	L148
.data	1
L159:
.ascii	"mget\0"
.text
.set	L148,0xf00
.data
.text
subl2	$8,sp
movl	4(ap),r11
movl	8(ap),r10
movl	88(r11),r9
jbs	$4,64(r9),L152
pushl	r10
calls	$1,_m_freem
movl	$50,r0
ret
L152:
cmpl	4(r10),$16
jlssu	L99999
cmpl	4(r10),$128
jlssu	L154
L99999:
	mfpr	$18,r0
	mtpr	$0x16,$18
movl	r0,-8(fp)
movl	_mfree,r8
jeql	L156
tstw	10(r8)
jeql	L157
pushal	L159
calls	$1,_panic
L157:
cvtlw	$2,10(r8)
decw	_mbstat+28
incw	_mbstat+32
movl	(r8),_mfree
clrl	(r8)
movl	$12,4(r8)
jbr	L160
L156:
pushl	$2
pushl	$0
calls	$2,_m_more
movl	r0,r8
L160:
	movl	-8(fp),r0
	mtpr	r0,$18
tstl	r8
jneq	L161
L2000005:
pushl	r10
calls	$1,_m_freem
incl	72(r11)
movl	$55,r0
ret
L161:
movl	$16,4(r8)
clrw	8(r8)
movl	r10,(r8)
movl	r8,r10
L154:
movzbl	12(ap),r0
decl	4(r10)
movl	4(r10),r1
cvtlb	r0,(r10)[r1]
incw	8(r10)
bitl	$65280,12(ap)
jneq	L99998
jbs	$1,114(r11),L162
L99998:
ashl	$-8,12(ap),r0
decl	4(r10)
movl	4(r10),r1
cvtlb	r0,(r10)[r1]
incw	8(r10)
L162:
cmpl	12(ap),$49185
jeql	L99997
jlbs	114(r11),L163
L99997:
decl	4(r10)
movl	4(r10),r0
cvtlb	$3,(r10)[r0]
decl	4(r10)
movl	4(r10),r0
movb	$255,(r10)[r0]
addw2	$2,8(r10)
L163:
pushl	r10
calls	$1,_ccitt_addfcs16
tstl	r0
jneq	L2000005
	mfpr	$18,r0
	mtpr	$0x16,$18
movl	r0,-4(fp)
cmpl	28(r11),32(r11)
jlss	L166
incl	36(r11)
	movl	-4(fp),r0
	mtpr	r0,$18
jbr	L2000005
L166:
clrl	124(r10)
tstl	24(r11)
jneq	L167
movl	r10,20(r11)
jbr	L168
L167:
movl	24(r11),r0
movl	r10,124(r0)
L168:
movl	r10,24(r11)
incl	28(r11)
tstl	24(r9)
jneq	L169
	movl	-4(fp),r0
	mtpr	r0,$18
pushl	r9
calls	$1,_pppasync_start
jbr	L171
L169:
	movl	-4(fp),r0
	mtpr	r0,$18
L171:
clrl	r0
ret
.align	1
.globl	_pppasync_start
_pppasync_start:.word	L172
.data	1
L208:
.ascii	"mfree\0"
.text
.set	L172,0xf80
.data
.text
subl2	$28,sp
movl	4(ap),r11
movl	48(r11),r10
L179:
tstl	24(r11)
jleq	L180
pushl	r11
calls	$1,_ttstart
L180:
cmpl	24(r11),$1000
jleq	L182
ret
L182:
tstl	r10
jneq	L183
ret
L183:
cmpl	_cfreecount,$3046
jgeq	L184
tstl	24(r11)
jeql	L184
ret
L184:
	mfpr	$18,r0
	mtpr	$0x16,$18
movl	r0,-16(fp)
movl	20(r10),r9
jeql	L185
movl	124(r9),20(r10)
jneq	L186
clrl	24(r10)
L186:
clrl	124(r9)
decl	28(r10)
L185:
	movl	-16(fp),r0
	mtpr	r0,$18
tstl	r9
jneq	L187
ret
L187:
tstl	24(r11)
jneq	L188
addl3	$24,r11,-(sp)
cvtbl	$126,-(sp)
calls	$2,_putc
L188:
addl3	4(r9),r9,r0
cmpl	(r0),$566232063
jneq	L190
mnegl	$1,-24(fp)
jbr	L191
L190:
movl	108(r10),-24(fp)
L191:
tstl	-24(fp)
jeql	L195
pushl	-24(fp)
pushl	r11
pushl	r9
calls	$3,_pppasync_ugly_accm
L194:
addl3	$24,r11,-(sp)
cvtbl	$126,-(sp)
calls	$2,_putc
tstl	r0
jeql	L213
addl3	$24,r11,-(sp)
calls	$1,_unputc
addl3	$24,r11,-(sp)
cvtbl	$126,-(sp)
calls	$2,_putc
incl	76(r10)
jbr	L179
L99996:
movl	-8(fp),r0
L99995:
subl3	r0,r8,-12(fp)
jeql	L200
addl3	$24,r11,-(sp)
pushl	-12(fp)
pushl	r7
calls	$3,_b_to_q
tstl	r0
jneq	L198
subl2	-12(fp),r8
addl2	-12(fp),r7
L200:
tstl	r8
jeql	L197
addl3	$24,r11,-(sp)
cvtbl	$125,-(sp)
calls	$2,_putc
tstl	r0
jneq	L198
addl3	$24,r11,-(sp)
movzbl	(r7),r0
xorl3	$32,r0,-(sp)
calls	$2,_putc
tstl	r0
jeql	L205
addl3	$24,r11,-(sp)
calls	$1,_unputc
L198:
	mfpr	$18,r0
	mtpr	$0x16,$18
movl	r0,-28(fp)
tstw	10(r9)
jneq	L207
pushal	L208
calls	$1,_panic
L207:
cvtwl	10(r9),r0
decw	_mbstat+28[r0]
incw	_mbstat+28
clrw	10(r9)
cmpl	4(r9),$128
jlssu	L209
addl3	4(r9),r9,r0
bicl3	$1023,r0,-20(fp)
subl3	$_mbutl,-20(fp),r0
ashl	$-10,r0,r0
decb	_mclrefcnt[r0]
jneq	L209
movl	_mclfree,*-20(fp)
movl	-20(fp),_mclfree
incl	_mbstat+12
L209:
movl	(r9),-20(fp)
movl	_mfree,(r9)
clrl	4(r9)
clrl	124(r9)
movl	r9,_mfree
	movl	-28(fp),r0
	mtpr	r0,$18
tstl	_m_want
jeql	L211
clrl	_m_want
pushal	_mfree
calls	$1,_wakeup
L211:
movl	-20(fp),r9
L195:
tstl	r9
jeql	L194
addl3	4(r9),r9,r7
cvtwl	8(r9),r8
L197:
tstl	r8
jleq	L198
	movl	r7,r5
	movl	r8,r4
	cvtbl	$125,r3
	locc	r3,r4,(r5)
movl	r0,-4(fp)
	movl	r7,r5
	movl	r8,r4
	cvtbl	$126,r3
	locc	r3,r4,(r5)
movl	r0,-8(fp)
cmpl	-4(fp),r0
jleq	L99996
movl	-4(fp),r0
jbr	L99995
L205:
incl	r7
decl	r8
jbr	L197
L213:
incl	68(r10)
jbr	L179
.align	1
.globl	_pppasync_ugly_accm
_pppasync_ugly_accm:.word	L215
.data	1
L229:
.ascii	"mfree\0"
.text
.set	L215,0xfc0
.data
.text
subl2	$8,sp
movl	4(ap),r11
movl	8(ap),r10
movl	12(ap),r9
L219:
tstl	r11
jeql	L220
addl3	4(r11),r11,r8
cvtwl	8(r11),r7
L221:
tstl	r7
jleq	L222
movzbl	(r8)+,r6
cmpl	r6,$32
jgeq	L99993
ashl	r6,$1,r0
mcoml	r0,r0
bicl3	r0,r9,r0
jneq	L99994
L99993:
cmpl	r6,$126
jeql	L99994
cmpl	r6,$125
jneq	L223
L99994:
addl3	$24,r10,-(sp)
cvtbl	$125,-(sp)
calls	$2,_putc
tstl	r0
jneq	L222
addl3	$24,r10,-(sp)
xorl3	$32,r6,-(sp)
calls	$2,_putc
tstl	r0
jeql	L226
addl3	$24,r10,-(sp)
calls	$1,_unputc
L222:
	mfpr	$18,r0
	mtpr	$0x16,$18
movl	r0,-8(fp)
tstw	10(r11)
jneq	L228
pushal	L229
calls	$1,_panic
L228:
cvtwl	10(r11),r0
decw	_mbstat+28[r0]
incw	_mbstat+28
clrw	10(r11)
cmpl	4(r11),$128
jlssu	L230
addl3	4(r11),r11,r0
bicl3	$1023,r0,-4(fp)
subl3	$_mbutl,-4(fp),r0
ashl	$-10,r0,r0
decb	_mclrefcnt[r0]
jneq	L230
movl	_mclfree,*-4(fp)
movl	-4(fp),_mclfree
incl	_mbstat+12
L230:
movl	(r11),-4(fp)
movl	_mfree,(r11)
clrl	4(r11)
clrl	124(r11)
movl	r11,_mfree
	movl	-8(fp),r0
	mtpr	r0,$18
tstl	_m_want
jeql	L232
clrl	_m_want
pushal	_mfree
calls	$1,_wakeup
L232:
movl	-4(fp),r11
jbr	L219
L223:
addl3	$24,r10,-(sp)
pushl	r6
calls	$2,_putc
tstl	r0
jneq	L222
L226:
decl	r7
jbr	L221
L220:
ret
.align	1
.globl	_pppasync_btom
_pppasync_btom:.word	L234
.data	1
L242:
.ascii	"mget\0"
.text
.set	L234,0xf00
.data
.text
subl2	$32,sp
movl	8(ap),r11
movl	4(ap),r9
clrl	-4(fp)
moval	-4(fp),-8(fp)
L238:
tstl	r11
jleq	L245
	mfpr	$18,r0
	mtpr	$0x16,$18
movl	r0,-16(fp)
movl	_mfree,r10
jeql	L240
tstw	10(r10)
jeql	L241
pushal	L242
calls	$1,_panic
L241:
cvtlw	$1,10(r10)
decw	_mbstat+28
incw	_mbstat+30
movl	(r10),_mfree
clrl	(r10)
movl	$12,4(r10)
jbr	L243
L240:
pushl	$1
pushl	$0
calls	$2,_m_more
movl	r0,r10
L243:
	movl	-16(fp),r0
	mtpr	r0,$18
tstl	r10
jneq	L244
pushl	-4(fp)
calls	$1,_m_freem
clrl	-4(fp)
L245:
movl	-4(fp),r0
ret
L244:
movl	r11,-12(fp)
cmpl	r11,$512
jlss	L252
	mfpr	$18,r0
	mtpr	$0x16,$18
movl	r0,-32(fp)
tstl	_mclfree
jneq	L247
pushl	$0
pushl	$1
pushl	$1
calls	$3,_m_clalloc
L247:
movl	_mclfree,-28(fp)
jeql	L248
subl3	$_mbutl,-28(fp),r0
ashl	$-10,r0,r0
incb	_mclrefcnt[r0]
decl	_mbstat+12
movl	*-28(fp),_mclfree
L248:
	movl	-32(fp),r0
	mtpr	r0,$18
tstl	-28(fp)
jeql	L249
subl3	r10,-28(fp),4(r10)
movw	$1024,8(r10)
jbr	L250
L249:
cvtbw	$112,8(r10)
L250:
cmpw	8(r10),$1024
jneq	L252
cmpl	-12(fp),$1024
jgeq	L99992
movl	-12(fp),r0
jbr	L99991
L99992:
cvtwl	$1024,r0
L99991:
cvtlw	r0,8(r10)
bitl	$1023,r9
jneq	L254
addl3	4(r10),r10,r8
extzv	$0,$31,r9,r0
extzv	$9,$23,r0,r0
moval	_Sysmap[r0],-16(fp)
extzv	$0,$31,r8,r0
extzv	$9,$23,r0,r0
moval	_Sysmap[r0],-20(fp)
clrl	-24(fp)
L257:
cmpl	-24(fp),$2
jgeq	L259
movl	-20(fp),r0
movl	(r0),-28(fp)
movl	-16(fp),r0
movl	-20(fp),r1
movl	(r0),(r1)
addl2	$4,-20(fp)
moval	-28(fp),r0
movl	-16(fp),r1
movl	(r0),(r1)
addl2	$4,-16(fp)
	movl	r9,r5
	movl	$58,r4
	mtpr	r5,r4
addl2	$512,r9
	movl	r8,r5
	movl	$58,r4
	mtpr	r5,r4
addl2	$512,r8
incl	-24(fp)
jbr	L257
L252:
movl	$12,4(r10)
cmpl	-12(fp),$112
jleq	L99990
cvtbl	$112,r0
jbr	L99989
L99990:
movl	-12(fp),r0
L99989:
cvtlw	r0,8(r10)
L254:
	cvtwl	8(r10),r5
	addl3	4(r10),r10,r3
	movl	r9,r1
	movc3	r5,(r1),(r3)
cvtwl	8(r10),r0
addl2	r0,r9
L259:
movl	r10,*-8(fp)
movl	r10,-8(fp)
cvtwl	8(r10),r0
subl2	r0,r11
jbr	L238
.align	1
.globl	_pppasync_input
_pppasync_input:.word	L262
.set	L262,0xf00
.data
.text
subl2	$4,sp
movl	4(ap),r11
movl	8(ap),r10
incl	_tk_nin
movl	48(r10),r9
jneq	L266
ret
L266:
movzbl	r11,r11
cmpl	r11,$126
jneq	L267
tstw	140(r9)
jneq	L268
ret
L268:
cmpw	140(r9),$4
jneq	L99988
cmpw	136(r9),$3
jlss	L99988
cmpw	138(r9),$61624
jeql	L269
L99988:
clrw	140(r9)
movw	$65535,138(r9)
L2000009:
incl	64(r9)
ret
L269:
cvtwl	136(r9),r0
subl3	$2,r0,-(sp)
pushl	128(r9)
calls	$2,_pppasync_btom
movl	r0,r8
clrw	140(r9)
movw	$65535,138(r9)
tstl	r8
jeql	L2000009
incl	60(r9)
movzwl	142(r9),-(sp)
pushl	r8
pushl	r9
calls	$3,_pppinput
ret
L267:
jbc	$15,140(r9),L272
bicw2	$-32768,140(r9)
xorl2	$32,r11
L273:
movzwl	138(r9),r0
extzv	$8,$24,r0,r0
movzwl	138(r9),r1
xorl2	r11,r1
movzbl	r1,r1
movzwl	_ccitt_fcs16tab[r1],r1
xorl2	r1,r0
cvtlw	r0,138(r9)
cvtwl	140(r9),r0
casel	r0,$0,$4
L2000010:
.word	L277-L2000010
.word	L285-L2000010
.word	L279-L2000010
.word	L282-L2000010
.word	L283-L2000010
ret
L272:
cmpl	r11,$125
jneq	L273
bisw2	$-32768,140(r9)
ret
L277:
cmpl	r11,$255
jneq	L279
cvtlw	$1,140(r9)
ret
L279:
jlbc	r11,L280
clrw	142(r9)
L282:
bisw2	r11,142(r9)
cvtlw	$4,140(r9)
movl	128(r9),132(r9)
clrw	136(r9)
ret
L280:
ashl	$8,r11,r0
cvtlw	r0,142(r9)
cvtlw	$3,140(r9)
ret
L283:
cmpw	136(r9),$2048
jlss	L284
cvtlw	$5,140(r9)
ret
L284:
cvtlb	r11,*132(r9)
incl	132(r9)
incw	136(r9)
ret
L285:
cmpl	r11,$3
jneq	L286
cvtlw	$2,140(r9)
jbr	L287
L286:
cvtlw	$5,140(r9)
L287:
ret
.align	1
.globl	_pppasync_up
_pppasync_up:.word	L290
.set	L290,0xc00
.data
.text
movl	4(ap),r11
movl	88(r11),r10
pushl	$536900729
cvtwl	56(r10),-(sp)
cvtwl	56(r10),r0
extzv	$8,$24,r0,r0
movzbl	r0,r0
mull2	$44,r0
movl	_cdevsw+16(r0),r0
calls	$2,(r0)
ret
.align	1
.globl	_pppasync_down
_pppasync_down:.word	L294
.set	L294,0xc00
.data
.text
movl	4(ap),r11
tstl	_pppasync_dtr_hack
jeql	L298
clrl	_pppasync_dtr_hack
ret
L298:
movl	88(r11),r10
pushl	$536900728
cvtwl	56(r10),-(sp)
cvtwl	56(r10),r0
extzv	$8,$24,r0,r0
movzbl	r0,r0
mull2	$44,r0
movl	_cdevsw+16(r0),r0
calls	$2,(r0)
ret
.align	1
.globl	_pppasync_check
_pppasync_check:.word	L299
.set	L299,0xc00
.data
.text
movl	4(ap),r11
movl	88(r11),r10
bicl3	$-17,64(r10),r0
ret
.align	1
.globl	_pppasync_modem
_pppasync_modem:.word	L304
.set	L304,0x800
.data
.text
movl	4(ap),r11
tstl	8(ap)
jeql	L308
bisl2	$16,64(r11)
tstl	48(r11)
jeql	L311
pushl	48(r11)
calls	$1,_pppup
jbr	L311
L308:
bicl2	$16,64(r11)
movl	$1,_pppasync_dtr_hack
tstl	48(r11)
jeql	L312
pushl	48(r11)
calls	$1,_pppdown
jbr	L314
L312:
clrl	_pppasync_dtr_hack
L314:
movl	_pppasync_dtr_hack,8(ap)
clrl	_pppasync_dtr_hack
L311:
movl	8(ap),r0
ret

