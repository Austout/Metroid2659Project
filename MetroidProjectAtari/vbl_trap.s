		xdef	_trap0_vbl,_trapIKBR
		xref 	_setVsync,_addBuff,_addTime
		
		
MFPBYTE: equ $FFFFFA11
IKBRREAD: equ $00FFFC02

_trap0_vbl:	
	link a6,#0
	movem.l d0/a0,-(sp)
	clr.l d0
	move.w #1,d0
	move.w d0,-(sp)
	jsr _setVsync
	move.w (sp)+,d0
	jsr _addTime
	movem.l (sp)+,d0/a0
	unlk a6
	rte
	
_trapIKBR:
	link a6,#0
	movem.l d0/a0-1,-(sp)
	lea IKBRREAD,a0
	clr.l d0
	move.b (a0),d0
	move.w d0,-(sp)
	jsr _addBuff
	move.w (sp)+,d0
	lea $FFFFFA11,a1
	and.b #$BF,(a1)
	movem.l (sp)+,d0/a0-1
	unlk a6
	rte