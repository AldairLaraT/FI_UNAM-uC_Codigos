; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 05:      Programación estructurada en lenguaje ensamblador
; Código 07:    Bloque IT
; Descripción:  Uso de la instrucción en ensamblador IT.
;
; Tarjeta de desarrollo:        EK-TM4C1294XL Evaluation board
; ********************************************************************************


; ********************************************************************************
; Sección de directivas

        .global main


; ********************************************************************************
; Sección de subrutinas


; ********************************************************************************
; Código principal

main:

        MOV   R0, #0x0000
        MOV   R1, #0xFFFF
        MOV   R3, #0

        ORRS  R2, R0, R1        ; Z = 0

        IT    NE                ; Bloque IT ¿Z=0?
        ADDNE R3, #1

        IT    EQ                ; Bloque IT ¿Z=1?
        ADDEQ R3, #0x10

        MOV   R3, #0
        ANDS  R2, R0, R1        ; Z = 1

        ITT   EQ                ; Bloque IR ¿Z=1?
        ADDEQ R3, #0x1
        ADDEQ R3, #0x10

        MOV   R3, #0

        ITTE  EQ                ; Bloque IR ¿Z=1?
        ADDEQ R3, #0x1
        ADDEQ R3, #0x10
        ADDNE R3, #0x100

        MOV   R3, #0

        ITETE EQ                ; Bloque IR ¿Z=1?
        ADDEQ R3, #0x1
        ADDNE R3, #0x10
        ADDEQ R3, #0x100
        ADDNE R3, #0x1000

end     B     end

        .end
