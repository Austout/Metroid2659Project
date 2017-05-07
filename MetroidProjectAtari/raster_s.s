	xdef _setScreenMoveP

_setScreenMoveP:
	link a6,#0
	movem.l d0/a0,-(sp)
	move.w 8(a6),d0
	lea $00FF8201,a0
	movep.w d0,(a0)
	movem.l (sp)+,d0/a0
	unlk a6
	rts
