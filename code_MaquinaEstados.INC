;*********************************
;Maquina de estados para la practica 7
; ESTADOS: 9
; EVENTOS: 4 (digito , A ,  C , *) el resto de teclas 0
;*********************************


MAQEST:
	MOVF	estado,w
	CLRF	PCLATH			
	BSF	PCLATH,1		
	ADDWF	PCL,F
	GOTO	MAQEVE0
	GOTO	MAQEVE1
	GOTO	MAQEVE2
	
					
MAQEVE0:			;### ESTADO 0 : RECOGER ACCION ###
	MOVF	evento,w
	;CALL 	LEEEVENTO;
	ADDWF	PCL,F
	RETURN			;0 NADA
	GOTO	EST0EV1		;1 Acción de Adelante y Atrás
	GOTO	EST0EV2		;2 Acción de derecha  e Izquierda
	GOTO	EST0EV3		;3 Acción de Finalización
	RETURN			;4 Selección de Valores numéricos
				;5 Posible estado de Borrado de acción

EST0EV1:			;1 Acción de Adelante y Atrás
	CALL	COMPROBARESPACIO
	ADDLW	d'0'
	BTFSS	STATUS,Z
	RETURN			;Si es 1 (Z==0) está lleno
	CALL	IMPRIMIRVALOR	;Si es 0 (Z==1) seguimos
	CALL	INSERTARACCION
	INCF	estado,F
	RETURN

EST0EV2:
	CALL	COMPROBARESPACIO
	ADDLW	d'0'
	BTFSS	STATUS,Z
	RETURN			;Si es 1 (Z==0) está lleno
	CALL	IMPRIMIRVALOR	;Si es 0 (Z==1) seguimos
	CALL	INSERTARACCION
	;Mover a W el valor fijo de tiempo de giro + call insertar accion
	RETURN

EST0EV3:
	CALL	COMPROBARESPACIO
	ADDLW	d'0'
	BTFSS	STATUS,Z
	RETURN			;Si es 1 (Z==0) está lleno
	CALL	IMPRIMIRVALOR	;Si es 0 (Z==1) seguimos
	CALL	INSERTARACCION
	MOVLW	d'2'
	MOVWF	estado
	RETURN



MAQEVE1:			;### ESTADO 1 : RECOGER VALOR DE TIEMPO ###
	MOVF	evento,w
	;CALL 	LEEEVENTO;
	ADDWF	PCL,F
	RETURN			;0 NADA
	RETURN			;1 Acción de Adelante y Atrás
	RETURN			;2 Acción de derecha  e Izquierda
	RETURN			;3 Acción de Finalización
	GOTO	EST1EV4		;4 Selección de Valores numéricos
				;5 Posible estado de Borrado de acción

EST1EV4:
	CALL	IMPRIMIRVALOR	;Si es 0 (Z==1) seguimos
	CALL	INSERTARACCION
	MOVLW	d'0'
	MOVWF	estado
	RETURN



MAQEVE2:			;### ESTADO 2 : RECARGA ###
	MOVF	evento,w
	;CALL 	LEEEVENTO;
	ADDWF	PCL,F
	RETURN			;0 NADA
	GOTO	EST2EV1		;1 Acción de Adelante y Atrás
	GOTO	EST2EV2		;2 Acción de derecha  e Izquierda
	RETURN			;3 Acción de Finalización
	GOTO	EST2EV4		;4 Selección de Valores numéricos
				;5 Posible estado de Borrado de acción
; COMENTARIOS
EST2EV1:
	MOVLW	lcd_clr
	CALL	LCDIWR
	MOVLW	cur_hm
	CALL	LCDIWR
	RETURN
EST2EV2:
	MOVLW	ACCIONES_S
	MOVWF	ACCION_P
LOOPX:	MOVWF	FSR
	MOVF	INDF,W
	SUBLW	b'11111100'
	BTFSC	STATUS,Z
	RETURN
	MOVF	INDF,W
	CALL	LCDDWR
	INCF	ACCION_P,F
	MOVF	ACCION_P,W
	GOTO	LOOPX
	

EST2EV4:
	MOVLW	lcd_clr
	CALL	LCDIWR
	CALL	INITESTADOS
	RETURN	

;)	