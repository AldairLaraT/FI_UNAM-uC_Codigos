; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 05:      Programación estructurada en lenguaje ensamblador
; Código 04:    Estructuras de control: SWITCH-CASE
; Descripción:  Construcción de la estructura de control SWITCH-CASE en ensamblador.
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
        MOV  R1, #2

inicio  CMP  R1, #1             ; Condición 1
        BEQ  caso1
        CMP  R1, #2             ; Condición 2
        BEQ  caso2
        B    else               ; Condición ELSE

caso1   ADD  R0, #1             ; Código del caso1
        B    fin

caso2   ADD  R0, #2             ; Código del caso2
        B    fin

else    ADD  R0, #3             ; Código del ELSE

fin     MOV  R2, R0             ; Fin del SWITCH-CASE

end     B    end

        .end
