;**********************************************************************************
; servo.asm
; Programa de control de servos
;**********************************************************************************


;**********************************************************************************
; SERVO_INIT:
; Inicializa puerto del servo

SERVO_INIT:
	BSF	STATUS, RP0		; Cambio a página de configuración de puertos

	BCF	P_SERVO,b_SERVO1		; se programa como salida
	BCF	P_SERVO,b_SERVO2

	BCF	STATUS, RP0		; Vuelta a página principal 0

	BCF	P_SERVO,b_SERVO1		; se pone servo a cero
	BCF	P_SERVO,b_SERVO2
	CLRF	SERVO1_VAL		; Valor inicial de servo a 0 (Izq)
	CLRF	SERVO2_VAL	
	CLRF	SERVO1_CNT		;
	CLRF	SERVO2_CNT

	RETURN

;**********************************************************************************
; SERVO()
; Posiciona el servo
; Recibe: W: valor de posición del servo (0-19) 0=>0º  19=>190º

SERVO1:
 	MOVWF	SERVO1_VAL	; Se transfiere valor a la variable correspondiente
	RETURN			;

SERVO2:
 	MOVWF	SERVO2_VAL	; Se transfiere valor a la variable correspondiente
	RETURN			;

;**********************************************************************************
; SERVO_CYC0:
; Inicializa ciclo de servo (inicio de pulso)
; Debe llamarse en la ranura 0 de la máquina de tiempo

SERVO1_CYC0:
	BSF	P_SERVO,b_SERVO1		; Se activa ciclo del servo
	MOVF	SERVO1_VAL,W		; Se inicializa contador de pulso para
	MOVWF	SERVO1_CNT		; contar el tiempo que estará a uno
	RETURN				;

SERVO2_CYC0:
	BSF	P_SERVO,b_SERVO2		; Se activa ciclo del servo
	MOVF	SERVO2_VAL,W		; Se inicializa contador de pulso para
	MOVWF	SERVO2_CNT		; contar el tiempo que estará a uno
	RETURN				;


;**********************************************************************************
; SERVO_CYC1:
; Ciclo de servo a uno '1'
; Debe llamarse en todas las ranuras desde la ranura correspondiente al
; ciclo mínimo (0.5ms: ranura 5 en caso de ranuras a 0.1ms) hasta la ranura
; anterior al ciclo máximo (2.4ms: ranura 23 en caso de ranuras a 0.1ms)

SERVO1_CYC1:
	MOVF	SERVO1_CNT,F		; Se averigua si llegó a cero
	BTFSC	STATUS,Z		;
	GOTO	SERVO1_CYC1_1		;
	DECF	SERVO1_CNT,F		; si no es cero, se decrementa el contador
	RETURN				;
SERVO1_CYC1_1:				; si ya en cero, se obliga a poner
	BCF	P_SERVO,b_SERVO1		; pulso a cero
	RETURN				;

SERVO2_CYC1:
	MOVF	SERVO2_CNT,F		; Se averigua si llegó a cero
	BTFSC	STATUS,Z		;
	GOTO	SERVO2_CYC1_1		;
	DECF	SERVO2_CNT,F		; si no es cero, se decrementa el contador
	RETURN				;
SERVO2_CYC1_1:				; si ya en cero, se obliga a poner
	BCF	P_SERVO,b_SERVO2		; pulso a cero
	RETURN				;

;**********************************************************************************
; SERVO_CYC2:
; Ciclo de servo apagado por exigencia independiente del valor solicitado
; Debe llamarse en la ranura correspondiente al ciclo máximo
; (2.4ms: ranura 24 en caso de ranuras a 0.1ms)

SERVO1_CYC2:
	BCF	P_SERVO,b_SERVO1		; pulso a cero se acabo el tiempo
	RETURN				;

SERVO2_CYC2:
	BCF	P_SERVO,b_SERVO2		; pulso a cero se acabo el tiempo
	RETURN				;