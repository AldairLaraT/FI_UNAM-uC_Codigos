; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 05:      Programación estructurada en lenguaje ensamblador
; Código 09:    Subrutinas
; Descripción:  Programación y manejo de subrutinas en ensamblador.
;
; Tarjeta de desarrollo:        EK-TM4C1294XL Evaluation board
; ********************************************************************************


; ********************************************************************************
; Sección de directivas

        .global main


; ********************************************************************************
; Sección de subrutinas

subrutina1                      ; Inicio de subrutina1
        ADD  R1, #1
        ADD  R1, #1
        ADD  R1, #1

        BX   LR                 ; Retorno al código principal


subrutina2                      ; Inicio de subrutina2
        ADD  R2, #2
        ADD  R2, #2
        ADD  R2, #2

        BX   LR                 ; Retorno al código principal


; ********************************************************************************
; Código principal

main:

        MOV  R1, #0
        MOV  R2, #0

loop
        NOP
        NOP
        NOP

        BL   subrutina1         ; Llamado de subrutina1

        NOP
        NOP
        NOP

        BL   subrutina2         ; Llamado de subrutina2

        NOP
        NOP
        NOP

        B    loop

        .end
