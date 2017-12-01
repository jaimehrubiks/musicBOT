;**********************************************************************************
; Configuraci�n de tiempo de timer 2								;Se usa el timer 2 para servos, calculado a 100us que *200 ranuras da 20ms de periodo

prescal2		EQU	d'4'	; Valor del prescaler (1,4,16)
rperiod			EQU	d'25'	; Valor en el registro de per�odo (0-256)
postscal		EQU	d'1'	; Valor calculado para el postscaler (1-16)


;*******************************************************************************
; INTERR
; Atenci�n a interrupciones. 

INTERR:				; Salvado general de registros
	ORG	004		; Direcci�n de Interrupcion

	MOVWF	SAVEW		;  el registro W
	MOVF	STATUS,W		;  el Status
	CLRF	STATUS		;   
	MOVWF	SAVEST		;
	MOVF	FSR,W		;  el registro indirecto FSR
	MOVWF	SAVEFSR		;		
	MOVF	PCLATH,W		;  el registro PCLATH
	MOVWF	SAVEPCL		;
	CLRF	PCLATH		; Se trabajar�n interrupciones en primera pagina		
  ;******************* Interrupci�n por timer2
INTTMR2:				
	BTFSS	PIR1,TMR2IF	; Comprueba si es interrupci�n por TMR2
	GOTO	SIGINT		;  si no lo es, busca otra posible interrupci�n
				; Caso que hay interrupci�n por TMR2
	BCF	PIR1,TMR2IF	; Se resetea interrupcion para prox. vez

;**********************************************************
;*** Insertar aqu� la rutina de atenci�n a Timer 2      ***
;**********************************************************
	;CALL	GENTICK
	CALL	MAQTIE

	GOTO	RETINT		;
SIGINT:
  ;******************* Fin interrupci�n por timer2

RETINT:				; Recuperaci�n general de registros y retorno
	MOVF	SAVEPCL,W	;  el registro PCLATH
	MOVWF	PCLATH		;
	MOVF	SAVEFSR,W	;  el registro indirecto FSR
	MOVWF	FSR		;
	MOVF	SAVEST,W		;  el Status
	MOVWF	STATUS		;
	SWAPF	SAVEW,F		;  el registro W
	SWAPF	SAVEW,W		;
	RETFIE			;

;*******************************************************************************
; INITTMR2
; Inicializaci�n del timer 2 

INITTMR2:			; Inicializaci�n timer 2
				; Se escribe constante de configuraci�n
	MOVLW	((prescal2/4)&3) | (prescal2/8) | (postscal-1)*8 | 4
	MOVWF	T2CON		;

	BSF	STATUS,RP0	; Banco 1
	MOVLW	rperiod-1	; Se escribe valor de comparaci�n de timer 2
	MOVWF	PR2&7F		;
	BSF	PIE1&7F,TMR2IE	; Se habilita interrupci�n por timer 2
	BSF	INTCON,PEIE	;
	BCF	STATUS,RP0	; Banco 0

	BCF	PIR1,TMR2IF	; Se borra posible flag de interrupci�n
	BSF	T2CON,TMR2ON	; Se enciende el temporizador
	RETURN			;