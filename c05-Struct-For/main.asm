; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 05:      Programación estructurada en lenguaje ensamblador
; Código 05:    Estructuras de control: FOR
; Descripción:  Construcción de la estructura de control FOR en ensamblador.
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

        MOV  R0, #0
        MOV  R1, #0             ; Inicio del contador

for     CMP  R1, #5             ; Condición
        BEQ  fin

        ADD  R0, #10            ; Código del FOR
        ADD  R0, #10

        ADD  R1, #1             ; Contador++
        B    for

fin     MOV  R2, R0             ; Fin del FOR

end     B    end

        .end
