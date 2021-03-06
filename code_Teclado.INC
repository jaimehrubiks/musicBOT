;**********************************************************************************
; LEETECLA
; Lee teclado
; Retorna: W: 0 si no hay tecla presionada, de lo contrario c�digo de tecla

LEETECLA:
				; Se hace unaLED verificaci�n r�pida de si
				; hay tecla presionada
	CLRF	TMP2		; Se inicializa registro de c�digo COD=0
	MOVLW	selca		; Selecciona todas las columnas simult�neamente
	MOVWF	PKYBD		;
	MOVLW	0F0h
	XORWF	PKYBD,W		; Se leen las columnas y si alguna tecla esta
				; presionada el resultado ser� distinto de 0
	BTFSC	STATUS,Z		;
	GOTO	LEETECRET	; Retorna, no hay teclas presionadas

	CLRF	TMP1		; Se inicializa registro de barrido BAR=1
	INCF	TMP1,F		; 

	MOVLW	selc1		; Se selecciona columna 1
	CALL	LEETEC1		;
	MOVLW	selc2		; Se selecciona columna 2
	CALL	LEETEC1		;
	MOVLW	selc3		; Se selecciona columna 3
	CALL	LEETEC1		;
	MOVLW	selc4		; Se selecciona columna 4
	CALL	LEETEC1		;
LEETECRET:
	MOVLW	selca		; Se dejan seleccionadas todas las columnas
	MOVWF	PKYBD		;
	MOVF	TMP2,W		; Se retorna c�digo en W
	RETURN			;
LEETEC1:
	MOVWF	PKYBD		; Se pone seleccionador de fila en el puerto
	MOVF	TMP2,F		; Se verifica que no ha sido recibida tecla
	BTFSS	STATUS,Z		;
	RETURN			; Tecla recibida previamente
	BTFSS	PKYBD,4		; Se verifica fila 1
	GOTO	LEETEC2		;
	INCF	TMP1,F		;
	BTFSS	PKYBD,5		; Se verifica fila 2
	GOTO	LEETEC2		;
	INCF	TMP1,F		;
	BTFSS	PKYBD,6		; Se verifica fila 3 
	GOTO	LEETEC2		;
	INCF	TMP1,F		;
	BTFSS	PKYBD,7		; Se verifica fila 4
	GOTO	LEETEC2		;
	INCF	TMP1,F		;
	RETURN			; No se encuentra ninguna fila presionada

LEETEC2:
	MOVF	TMP1,W		; Se ha descubierto una fila presionada y
	MOVWF	TMP2		; se guarda su c�digo
	RETURN			; Se retorna con el c�digo de fila en TMP2



;**********************************************************************************
; ELIMREB
; Elimina rebote de teclado
; Recibe:  W: c�digo leido de tecla, 0 no hay tecla
; Retorna: W: c�digo de tecla ya estable, 0 no hay tecla

ELIMREB:
	MOVWF	TMP1		; Se almacena temporalmente la tecla recibida
	XORWF	TEC_ant,W	; Se verifica si es igual a la tecla anterior
	BTFSC	STATUS,Z		;
	GOTO	ELIM_IG		;
				; Caso de tecla distinta
	MOVF	TMP1,W		; Se actualiza tecla anterior
	MOVWF	TEC_ant		;
	CLRF	TEC_numv		; Se inicializa contador de n�mero de veces
	RETLW	0		; Se indica 'no tecla'
ELIM_IG:				; Caso de tecla igual
	MOVLW	nminv		; Se verifica si es estable durante un 
	SUBWF	TEC_numv,W	; n�mero m�nimo de veces
	BTFSC	STATUS,Z		;
	GOTO	ELIM_EST		;
				; Caso a�n no estable
	INCF	TEC_numv,F	;
	RETLW	0		;
ELIM_EST:			; Caso estable
	MOVF	TMP1,W		;
	RETURN			;
	
	
;**********************************************************************************
; REPORTT
; Reporta una vez una tecla cuando se presiona
; Recibe:  W: c�digo leido y filtrado de tecla, 0 no hay tecla
; Retorna: W: c�digo de tecla, 0 no hay tecla
;          STATUS: flag Zero debidamente ajustado

REPORTT:
	IORLW	0		; Se verifica si hay tecla
	BTFSC	STATUS,Z		;
	GOTO	RE_NTEC		;
RE_TEC:
	BSF	STATUS,Z		; Se activa flag Zero, para indicar "no hay tecla"  
	BTFSC	TEC_flg,F_rep	; Tecla presionada, se verifica si fue reportada
	RETLW	0		; (RETLW 0 no ajusta el flag de Zero)

	BSF	TEC_flg,F_rep	; Se reporta tecla, marcando tecla reportada
	BCF	STATUS,Z		; Se limpia el flag de Zero indicando "hay tecla"
	RETURN			; Se retorna c�digo de tecla
RE_NTEC:
	BCF	TEC_flg,F_rep	; No hay tecla, se marca no reportado
	ANDLW	0		; Se retorna 0: tecla ya reportada (ajusta flag Z)
	RETURN			;


;**********************************************************************************
; INITTEC
; Inicializa puerto de teclado

INITTEC:
	BSF	STATUS,RP0		; Banco 1
	MOVLW	B'11110000'		; Configuraci�n de puerto B:
	MOVWF	PKYBD			;  RB7-RB4 entrada, RB3-RB0 salida
	BCF	OPTION_REG&7F,NOT_RBPU	;  Pull ups activados
	BCF	STATUS,RP0		; Banco 0
	MOVLW	selca			; Selecciona todas columnas
	MOVWF	PKYBD			;
	CLRF	TEC_ant			; Se inicializan variables
	CLRF	TEC_flg			;
	CLRF	TEC_numv			;
	RETURN	
