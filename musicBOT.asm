; -------------------------------------------------------
; NOMBRE:               "PROYECTO FINAL"
; DESCRIPCION:          ""
; AUTORES:              "Jaime y Eneko"
; RUTINAS:              ""
; -------------------------------------------------------


	INCLUDE "P16F887.INC"
	LIST P = 16F887


;Registros y variables
	INCLUDE	"code_Definiciones.INC"

;Arranque del sistema
	ORG	003h
	GOTO	INIT

;Atención a la interrupcion
	ORG     004h         
	INCLUDE	"code_Interrupt.INC"


;Inicializaciones
;-------------------------------------------------------

INIT:
	CALL	INITPORTS
	CALL	INITLCD
	CALL 	INITTEC
	;CALL	INITCRONO
	CALL	INITESTADOS
	CALL	INITTMR2
	CALL	INITLED
	BSF	INTCON,GIE
	
	MOVLW	b'01111110'
	CALL	LCDDWR
	MOVLW	'D'
	CALL	LCDDWR	

	CALL	SERVO_INIT

;Bucle principal

MAIN:	
	CALL	LEETECLA
	CALL	ELIMREB
	CALL	REPORTT
	CALL	ENVEVENTO

	CALL	MAQEST
	GOTO	MAIN

;-------------------------------------------------------


;#####	Tablas de traducción:
	ORG	200h;
	INCLUDE	"code_tablas.INC"

;#####	Maquina de estados
	INCLUDE "code_MaquinaEstados.INC"

;#####	Máquina de tiempos para SERVOS
	ORG	300h;
	INCLUDE	"code_MaquinaTiempos.INC"


;#####	Otras rutinas
	ORG	400h;

;Teclado
	INCLUDE	"code_Teclado.INC"
;Lcd
	INCLUDE	"code_Lcd.INC"
;Servos
	INCLUDE	"code_Servos.INC"
	
		

;Funciones de pila de acciones
COMPROBARESPACIO:		;Devuelve 1 si no queda espacio en la pila
	MOVF	ACCION_P,W
	SUBLW	ACCIONES_E-2
	BTFSS	STATUS,C
	RETLW	1
	RETLW	0

INSERTARACCION:
	MOVF	ACCION_P,W
	MOVWF	FSR
	MOVF	eventoValor,W	;ALERTAA!!!! HAY QUE CAMBIARLO POR eventoValor
	MOVWF	INDF
	INCF	ACCION_P,F
	RETURN

OBTENERACCION:
	MOVLW	ACCION_P
	MOVWF	FSR
	MOVF	INDF,W
	INCF	ACCION_P,F
	RETURN

IMPRIMIRVALOR:
	MOVF	eventoAscii,W
	CALL	LCDDWR
	RETURN


;***************************************************** Arreglada!
; INITPORTS (PIC16F88X)
; Inicializa puertos en procesadores de la serie 88X

INITPORTS:
	BSF	STATUS,RP0 	; Cambio de banco
	BSF 	STATUS,RP1 	;
	CLRF	ANSEL&7F        ; Puerto A digital para PIC16F88x
	CLRF 	ANSELH&7F 	; Puerto B digital para PIC16F88x
	BCF 	STATUS,RP0 	; Cambio de banco
	BCF 	STATUS,RP1 	;
	RETURN			;


;***************************************************** 
; OTROS
;

INITESTADOS:			;Reinicia la máquina de estados
	MOVLW	d'0'
	MOVWF	estado
	MOVLW	d'0'
	MOVWF	evento
	MOVLW	ACCIONES_S
	MOVWF	ACCION_P

	MOVLW	lcd_clr
	CALL	LCDIWR
	MOVLW	cur_hm
	CALL	LCDIWR
	
	RETURN

ENVEVENTO:
	MOVWF	TMP1
	CALL	TRATECLA3
	MOVWF	eventoValor

	MOVF	TMP1,W
	CALL	TRATECLA1
	MOVWF	evento

	MOVF	TMP1,W
	CALL	TRATECLA2
	MOVWF	eventoAscii
	RETURN


INITLED:
	CLRF	PORTC
	BSF	STATUS,RP0
	BCF	TRISC,0
	BCF	STATUS,RP0

LEDON:
	BSF	PORTC,0
	RETURN
LEDOFF:
	BCF	PORTC,0
	RETURN
			
	
LEEEVENTO:
	MOVF	evento,W
	BTFSS	STATUS,Z	;Es Tecla 0?
	RETURN			;Si Si tecla != 0 devolvemos la tecla
	BTFSS	FLAGS,0		;Es tick 1?
	RETLW	0		;Si es 0 devolvemos 0
	BCF	FLAGS,0		;Si es 1 el tick, lo desactivamos
	RETLW	4		;Y Devolvemos evento 4
	
		




	END