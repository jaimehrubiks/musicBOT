UNIDADES	EQU	20	; Variable UNIDADES
DECENAS		EQU	21	; Variable DECENAS
CENTENAS	EQU	22	; Variable CENTENAS
MILLARES	EQU	23	; Variable MILLARES
DECEMIL		EQU	24	; Variable DECEMIL
BINL		EQU	25	; Variable numero binario bits mas   sign
BINH		EQU	26	; Variable numero binario bits menos sign

CONT1		EQU	27	; Variable de conteo 1
CONT2		EQU	28	; Variable de conteo 2
CONT3		EQU	29	; Variable de conteo 3

UNIDSEG		EQU	2A	; Variable unidades de segundo
DECESEG		EQU	2B	; Variable decenas de segundo
UNIDMIN		EQU	2C	; Variable unidades de minuto
DECEMIN		EQU	2D	; Variable decenas de segundo

PTRMEN		EQU	2E	; Variable temporal para el puntero

TMP1		EQU	2F	; Variable temporal
TMP2		EQU	30	; Variable temporal

CAD0		EQU 	31	; Conversion AD: 8 bits menos significativos
CAD1		EQU 	32	; Conversion AD: 2 bits mas significativos

TEC_numv	EQU	33	; Teclado: número de veces estable
TEC_ant		EQU	34	; Teclado: tecla anterior
TEC_flg		EQU	35	; Teclado: flags de control
F_rep		EQU	0	; Teclado: flag de tecla reportada (bit 0)

NUMDIG		EQU	26	; Pantalla led: numero de digito mostrado


;_____ REGISTROS INTERRUPCIONES

SAVEPCL		EQU 7C	; Salvado de PLCATH
SAVEFSR		EQU 7D	; Salvado de FSR
SAVEST		EQU 7E	; Salvado de STATUS
SAVEW		EQU 7F	; Salvado de W

;_____ REGISTROS LCD

P_LCDen		EQU	PORTD		; Puerto de bit de enable(strobe) LCD
b_LCDen		EQU	4		;  bit de enable(strobe) LCD
P_LCDrw		EQU	PORTD		; Puerto de bit de read/write LCD
b_LCDrw		EQU	5		;  bit de read/write LCD
P_LCDdi		EQU	PORTD		; Puerto de bit de dato/instruccion LCD
b_LCDdi		EQU	6		;  bit de dato/instruccion LCD
P_LCDDA		EQU	PORTD		; Puerto de dato de LCD (4 bits menos significat.)

lcd_clr	EQU	b'00000001'	; LCD clear
cur_hm	EQU	b'00000010'	; Cursor to home
cur_sa	EQU	b'10000000'	; Cursor to indicated position
cur_on	EQU	b'00001010'	; Cursor on
cur_off	EQU	b'00001000'	; Cursor off
cur_rm	EQU	b'00010100'	; Cursor right move
cur_lm	EQU	b'00010000'	; Cursor left move
cur_l2	EQU	b'11000000'	; Cursor en segunda l?nea
cur_rma	EQU	b'00000110'	; Cursor auto right move
cur_lma	EQU	b'00000100'	; Cursor auto left move
cur_nor	EQU	b'00000110'	; Cursor auto-move normal (izq a dch)
cur_cal	EQU	b'00000111'	; Cursor auto-move calculadora (dch a izq)

klcdw	EQU	0FFh		; Constante para pausa

lcd_set	EQU	b'00101000'	; LCD: 4 bits, 2 l?neas, 5x7 puntos
lcd_mod	EQU	b'00000110'	; Movimiento del cursor hacia la derecha
lcd_on	EQU	b'00001100'	; Display on, cursor off, blink off
lcd_off	EQU	b'00001000'	; Display off
lcd_to	EQU	d'200'		; Time-out para display ocupado

;_____ REGISTROS TECLADO

PKYBD	EQU	PORTB		; El teclado ocupa el puerto B de 8 bits

selc1	EQU	B'00000111'	; Selección de columna 1
selc2	EQU	B'00001011'	; Selección de columna 2
selc3	EQU	B'00001101'	; Selección de columna 3
selc4	EQU	B'00001110'	; Selección de columna 4
selca	EQU	B'00000000'	; Selección de todas las columnas
nminv	EQU	10			; Numero mínimo de veces para detectar estabilidad

;_____ REGISTROS JAIME ENEKO

TICKS		EQU	40	;GENTICK
FLAGS		EQU	41	;GENTICK
eventoAscii	EQU	42	;TECLADO
eventoValor	EQU	43	;TECLADO

estado 		EQU	44	;
evento 		EQU	45	;

MEMCIF0		EQU	46
MEMCIF1		EQU	47
MEMCIF2		EQU	48
MEMCIF3		EQU	49

CLAVE0		EQU	4A
CLAVE1		EQU	4B
CLAVE2		EQU	4C
CLAVE3		EQU	4D

P_SERVO		EQU	PORTC
b_SERVO1	EQU	0
b_SERVO2	EQU	1	
SERVO1_VAL	EQU	50
SERVO1_CNT	EQU	51
SERVO2_VAL	EQU	52
SERVO2_CNT	EQU	53
RANURA		EQU	54
ACCION_P	EQU	55	;

tiempo_rotacion	EQU	d'10' ;SE CALCULARÁ PROBANDO
ac_alante	EQU	d'1'
ac_atras	EQU	d'2'
ac_derecha	EQU	d'3'
ac_izquierda	EQU	d'4'
ac_fin		EQU	d'5'


ACCIONES_S	EQU	60	;lista de acciones en pila desde 60 hasta 6F (un total de 8 acciones de momento)
ACCIONES_E	EQU	6F