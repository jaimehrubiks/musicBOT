;***********************************************
;ESCRMEN (MENS-mensaje)
;

ESCRMEN:
	MOVWF	PTRMEN

	MOVLW	lcd_clr			;Limpia e imprime en segunda linea:
	CALL	LCDIWR
	MOVLW	cur_sa+40h
	call	LCDIWR

ESCRMEN1:
	MOVF 	PTRMEN,W
	CALL 	TABMENS
	XORLW	0
	BTFSC	STATUS,Z
	GOTO	RESETCURSOR
	CALL 	LCDDWR
	INCF 	PTRMEN,F
	GOTO 	ESCRMEN1
RESETCURSOR:
	MOVLW	cur_hm
	CALL	LCDIWR
	RETURN

TABMENS:
	CLRF	PCLATH			; Funciona en direcciones 100-1FF
	BSF	PCLATH,1			;
	ADDWF	PCL,F
MENSAJE:
MEN_HELLO:
	RETLW	'R'
	RETLW 	'o'
	RETLW 	'b'
	RETLW 	'o'
	RETLW 	't'
	RETLW 	'!'
	RETLW	0

;***
;Eventos de las teclas
;***

TRATECLA1:	;Selección del evento. 
		; 1 - Evento de accion adelante y atras
		; 2 - Evento de acción derecha e izquierda
		; 3 - Evento de finalización
		; 4 - Seleccion de numeros
	
	CLRF	PCLATH			; Funciona en direcciones 100-1FF
	BSF	PCLATH,1			;

	ADDWF	PCL,F			;
	RETLW	0			; No tecla
	RETLW	1			;A
	RETLW	1			;B
	RETLW	0			;C
	RETLW	3			;D
	RETLW	4			;3
	RETLW	4			;6
	RETLW	4			;9
	RETLW	2			;#
	RETLW	4			;2
	RETLW	4			;5
	RETLW	4			;8
	RETLW	4			;0
	RETLW	4			;1
	RETLW	4			;4
	RETLW	4			;7
	RETLW	2			;*
	
TRATECLA2:
		;CONVERSION ASCII
	
	
	CLRF	PCLATH			; Funciona en direcciones 100-1FF
	BSF	PCLATH,1			;


	ADDWF	PCL,F			;
	RETLW	0			; No tecla
	RETLW	b'01011110'		;A
	RETLW	b'01011111'		;B
	RETLW	'C'			;C
	RETLW	b'11111100'		;D
	RETLW	'3'			;3
	RETLW	'6'			;6
	RETLW	'9'			;9
	RETLW	b'01111110'		;#
	RETLW	'2'			;2
	RETLW	'5'			;5
	RETLW	'8'			;8
	RETLW	'0'			;0
	RETLW	'1'			;1
	RETLW	'4'			;4
	RETLW	'7'			;7
	RETLW	b'01111111'		;*


TRATECLA3:
		;VALORES FIJOS
		;A-1 Adelante
		;B-2 Atrás
		;C-3 Derecha
		;D-4 Izquierda	
	
	CLRF	PCLATH			; Funciona en direcciones 100-1FF
	BSF	PCLATH,1			;


	ADDWF	PCL,F			;
	RETLW	0			; No tecla
	RETLW	ac_alante		;A
	RETLW	ac_atras		;B
	RETLW	'C'			;C
	RETLW	ac_fin			;D
	RETLW	3			;3
	RETLW	6			;6
	RETLW	9			;9
	RETLW	ac_derecha		;#
	RETLW	2			;2
	RETLW	5			;5
	RETLW	8			;8
	RETLW	0			;0
	RETLW	1			;1
	RETLW	4			;4
	RETLW	7			;7
	RETLW	ac_izquierda		;*