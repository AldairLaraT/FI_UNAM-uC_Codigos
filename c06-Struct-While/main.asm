; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 05:      Programación estructurada en lenguaje ensamblador
; Código 06:    Estructuras de control: WHILE
; Descripción:  Construcción de la estructura de control WHILE en ensamblador.
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
        MOV  R1, #5             ; Variable de control

while   CMP  R1, #5             ; Condición
        BNE  fin

        ADD  R0, #10            ; Código del WHILE
        ADD  R0, #10

        B    while

fin     MOV  R2, R0             ; Fin del WHILE

end     B    end

        .end
