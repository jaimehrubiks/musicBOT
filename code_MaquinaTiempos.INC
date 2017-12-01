;**********************************************************************************
; maqtie1.asm
; Programa de maquina de tiempos, parte 1
; máquina de tiempos que debe ser instalada en posición específica
; no relocalizable
;**********************************************************************************


;**********************************************************************************
;** MAQTIE
;** Máquina de tiempos
;** Para optimizar tiempos, debe ser puesta en la subpágina 0 (000h-0FFh)
;** Debe llamarse desde una interrupción de tiempo


NumRan	EQU	d'200'			; 200 ranuras a 100us cada una 20ms

	;ORG	030			; Debe estar subpágina 0 para optimización en tiempo

MAQTIE:
	INCF	RANURA,F		; Se actualiza la ranura del tiempo
	MOVLW 	-NumRan			; Se verifica que no se haya
	ADDWF	RANURA,W		; superado el valor maximo
	BTFSC	STATUS,C		; de ranuras en caso contrario
	CLRF 	RANURA			; se inicialza

	MOVF	RANURA,W		;Se toma el numero de la ranura
	
	CLRF	PCLATH			; Funciona en direcciones 100-1FF
	BSF	PCLATH,1
	BSF	PCLATH,0
	ADDWF	PCL,F			;Se salta a la ranura correspondiente

	GOTO	SERVO1_CYC0		; Ranura 000 -> Inicio de ciclo del servo
	RETURN				; Ranura 001 ->
	RETURN				; Ranura 002 ->
	RETURN				; Ranura 003 ->
	RETURN				; Ranura 004 ->
	GOTO	SERVO1_CYC1		; Ranura 005 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 006 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 007 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 008 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 009 -> Ciclo del servo

	GOTO	SERVO1_CYC1		; Ranura 010 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 011 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 012 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 013 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 014 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 015 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 016 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 017 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 018 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 019 -> Ciclo del servo

	GOTO	SERVO1_CYC1		; Ranura 020 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 021 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 022 -> Ciclo del servo
	GOTO	SERVO1_CYC1		; Ranura 023 -> Ciclo del servo
	GOTO	SERVO1_CYC2		; Ranura 024 -> Fin de ciclo de servo (obligado)
	
	RETURN				; Ranura 025 ->
	RETURN				; Ranura 026 ->
	RETURN				; Ranura 027 ->
	RETURN				; Ranura 028 ->
	RETURN				; Ranura 029 ->

	RETURN				; Ranura 030 ->
	RETURN				; Ranura 031 ->
	RETURN				; Ranura 032 ->
	RETURN				; Ranura 033 ->
	RETURN				; Ranura 034 ->
	RETURN				; Ranura 035 ->
	RETURN				; Ranura 036 ->
	RETURN				; Ranura 037 ->
	RETURN				; Ranura 038 ->
	RETURN				; Ranura 039 ->

	RETURN				; Ranura 040 ->
	RETURN				; Ranura 041 ->
	RETURN				; Ranura 042 ->
	RETURN				; Ranura 043 ->
	RETURN				; Ranura 044 ->
	RETURN				; Ranura 045 ->
	RETURN				; Ranura 046 ->
	RETURN				; Ranura 047 ->
	RETURN				; Ranura 048 ->
	RETURN				; Ranura 049 ->

	RETURN				; Ranura 050 ->
	RETURN				; Ranura 051 ->
	RETURN				; Ranura 052 ->
	RETURN				; Ranura 053 ->
	RETURN				; Ranura 054 ->
	RETURN				; Ranura 055 ->
	RETURN				; Ranura 056 ->
	RETURN				; Ranura 057 ->
	RETURN				; Ranura 058 ->
	RETURN				; Ranura 059 ->

	RETURN				; Ranura 060 ->
	RETURN				; Ranura 061 ->
	RETURN				; Ranura 062 ->
	RETURN				; Ranura 063 ->
	RETURN				; Ranura 064 ->
	RETURN				; Ranura 065 ->
	RETURN				; Ranura 066 ->
	RETURN				; Ranura 067 ->
	RETURN				; Ranura 068 ->
	RETURN				; Ranura 069 ->

	RETURN				; Ranura 070 ->
	RETURN				; Ranura 071 ->
	RETURN				; Ranura 072 ->
	RETURN				; Ranura 073 ->
	RETURN				; Ranura 074 ->
	RETURN				; Ranura 075 ->
	RETURN				; Ranura 076 ->
	RETURN				; Ranura 077 ->
	RETURN				; Ranura 078 ->
	RETURN				; Ranura 079 ->

	RETURN				; Ranura 080 ->
	RETURN				; Ranura 081 ->
	RETURN				; Ranura 082 ->
	RETURN				; Ranura 083 ->
	RETURN				; Ranura 084 ->
	RETURN				; Ranura 085 ->
	RETURN				; Ranura 086 ->
	RETURN				; Ranura 087 ->
	RETURN				; Ranura 088 ->
	RETURN				; Ranura 089 ->

	RETURN				; Ranura 090 ->
	RETURN				; Ranura 091 ->
	RETURN				; Ranura 092 ->
	RETURN				; Ranura 093 ->
	RETURN				; Ranura 094 ->
	RETURN				; Ranura 095 ->
	RETURN				; Ranura 096 ->
	RETURN				; Ranura 097 ->
	RETURN				; Ranura 098 ->
	RETURN				; Ranura 099 ->

	RETURN				; Ranura 100 ->
	RETURN				; Ranura 101 ->
	RETURN				; Ranura 102 ->
	RETURN				; Ranura 103 ->
	RETURN				; Ranura 104 ->
	RETURN				; Ranura 105 ->
	RETURN				; Ranura 106 ->
	RETURN				; Ranura 107 ->
	RETURN				; Ranura 108 ->
	RETURN				; Ranura 109 ->

	RETURN				; Ranura 110 ->
	RETURN				; Ranura 111 ->
	RETURN				; Ranura 112 ->
	RETURN				; Ranura 113 ->
	RETURN				; Ranura 114 ->
	RETURN				; Ranura 115 ->
	RETURN				; Ranura 116 ->
	RETURN				; Ranura 117 ->
	RETURN				; Ranura 118 ->
	RETURN				; Ranura 119 ->

	RETURN				; Ranura 120 ->
	RETURN				; Ranura 121 ->
	RETURN				; Ranura 122 ->
	RETURN				; Ranura 123 ->
	RETURN				; Ranura 124 ->
	RETURN				; Ranura 125 ->
	RETURN				; Ranura 126 ->
	RETURN				; Ranura 127 ->
	RETURN				; Ranura 128 ->
	RETURN				; Ranura 129 ->

	RETURN				; Ranura 130 ->
	RETURN				; Ranura 131 ->
	RETURN				; Ranura 132 ->
	RETURN				; Ranura 133 ->
	RETURN				; Ranura 134 ->
	RETURN				; Ranura 135 ->
	RETURN				; Ranura 136 ->
	RETURN				; Ranura 137 ->
	RETURN				; Ranura 138 ->
	RETURN				; Ranura 139 ->

	RETURN				; Ranura 140 ->
	RETURN				; Ranura 141 ->
	RETURN				; Ranura 142 ->
	RETURN				; Ranura 143 ->
	RETURN				; Ranura 144 ->
	RETURN				; Ranura 145 ->
	RETURN				; Ranura 146 ->
	RETURN				; Ranura 147 ->
	RETURN				; Ranura 148 ->
	RETURN				; Ranura 149 ->

	RETURN				; Ranura 150 ->
	RETURN				; Ranura 151 ->
	RETURN				; Ranura 152 ->
	RETURN				; Ranura 153 ->
	RETURN				; Ranura 154 ->
	RETURN				; Ranura 155 ->
	RETURN				; Ranura 156 ->
	RETURN				; Ranura 157 ->
	RETURN				; Ranura 158 ->
	RETURN				; Ranura 159 ->

	RETURN				; Ranura 160 ->
	RETURN				; Ranura 161 ->
	RETURN				; Ranura 162 ->
	RETURN				; Ranura 163 ->
	RETURN				; Ranura 164 ->
	RETURN				; Ranura 165 ->
	RETURN				; Ranura 166 ->
	RETURN				; Ranura 167 ->
	RETURN				; Ranura 168 ->
	RETURN				; Ranura 169 ->

	RETURN				; Ranura 170 ->
	RETURN				; Ranura 171 ->
	RETURN				; Ranura 172 ->
	RETURN				; Ranura 173 ->
	RETURN				; Ranura 174 ->
	RETURN				; Ranura 175 ->
	RETURN				; Ranura 176 ->
	RETURN				; Ranura 177 ->
	RETURN				; Ranura 178 ->
	RETURN				; Ranura 179 ->

	RETURN				; Ranura 180 ->
	RETURN				; Ranura 181 ->
	RETURN				; Ranura 182 ->
	RETURN				; Ranura 183 ->
	RETURN				; Ranura 184 ->
	RETURN				; Ranura 185 ->
	RETURN				; Ranura 186 ->
	RETURN				; Ranura 187 ->
	RETURN				; Ranura 188 ->
	RETURN				; Ranura 189 ->

	RETURN				; Ranura 190 -> Generación de 1 seg
	RETURN				; Ranura 191 ->
	RETURN				; Ranura 192 ->
	RETURN				; Ranura 193 ->
	RETURN				; Ranura 194 ->
	RETURN				; Ranura 195 ->
	RETURN				; Ranura 196 ->
	RETURN				; Ranura 197 ->
	RETURN				; Ranura 198 ->
	RETURN
	;GOTO	GENTICK			; Ranura 199 -> Tick de 20ms para tiempo

