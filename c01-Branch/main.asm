; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 05:      Programación estructurada en lenguaje ensamblador
; Código 01:    Saltos incondicionales
; Descripción:  Uso de la instrucción de salto incondicional (branch).
;
; Tarjeta de desarrollo:        EK-TM4C1294XL Evaluation board
; ********************************************************************************


; ********************************************************************************
; Sección de directivas

        .global main            ; Declaración del archivo con la función principal (main)

        .data                   ; Sección para escribir en memoria de datos
counter .equ 1                  ; Declaración de la constante counter = 1

        .text                   ; Sección para escribir el código ejecutable (instrucciones)


; ********************************************************************************
; Sección de subrutinas


; ********************************************************************************
; Código principal

main:
        MOV  R0, #0             ; R0 = 0

loop                            ; Etiqueta loop
        ADD  R0, #counter       ; R0 = R0 + counter
        B    loop               ; Saltar a loop

end     B    end
        .end
