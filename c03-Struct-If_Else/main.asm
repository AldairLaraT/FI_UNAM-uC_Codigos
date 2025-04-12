; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 05:      Programación estructurada en lenguaje ensamblador
; Código 03:    Estructuras de control: IF-ELSE
; Descripción:  Construcción de la estructura de control IF-ELSE en ensamblador.
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
        MOV  R1, #5

inicio  CMP  R1, #5             ; Condición
        BNE  else

if      ADD  R0, #1             ; Código del IF
        ADD  R0, #1
        B    fin

else    ADD  R0, #2             ; Código del ELSE
        ADD  R0, #2

fin     MOV  R2, R0             ; Fin del IF-ELSE

end     B    end

        .end
