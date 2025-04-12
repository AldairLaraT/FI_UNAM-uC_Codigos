; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 05:      Programación estructurada en lenguaje ensamblador
; Código 08:    Manejo del stack
; Descripción:  Uso de las instrucciones PUSH y POP para manejo del Stack.
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

        MOV  R1, #0x1111
        MOV  R5, #0

        PUSH {R1}               ; Almacenar el contenido de R1 en el Stack
        POP  {R5}               ; Cargar el último dato almacenado en el Stack en R5

        NOP

        MOV  R1, #0x2222
        MOV  R2, #0x3333
        MOV  R3, #0x4444
        MOV  R5, #0
        MOV  R6, #0
        MOV  R7, #0

        PUSH {R1,R2,R3}         ; Almacenar el contenido de R1, R2 y R3 en el Stack
        POP  {R5,R6,R7}         ; Cargar los últimos 3 datos almacenados en el Stack en R5, R6 y R7

        NOP

        MOV  R1, #0x5555
        MOV  R2, #0x6666
        MOV  R3, #0x7777
        MOV  R4, #0x8888
        MOV  R5, #0
        MOV  R6, #0
        MOV  R7, #0
        MOV  R8, #0

        PUSH {R1-R4}            ; Almacenar el contenido de R1, R2, R3 y R4 en el Stack
        POP  {R5-R8}            ; Cargar los últimos 4 datos almacenados en el Stack en R5, R6, R7 y R8

end     B    end

        .end
