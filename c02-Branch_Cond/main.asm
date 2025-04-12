; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 05:      Programación estructurada en lenguaje ensamblador
; Código 02:    Saltos condicionales
; Descripción:  Uso de las instrucciones de salto condicional.
;
; Tarjeta de desarrollo:        EK-TM4C1294XL Evaluation board
; ********************************************************************************


; ********************************************************************************
; Sección de directivas

        .global main            ; Declaración del archivo con la función principal (main)

        .data                   ; Sección para escribir en memoria de datos
counter .equ 1                  ; Declaración de la constante counter = 1
lap     .equ 5                  ; Declaración de la constante lap = 5

        .text                   ; Sección para escribir el código ejecutable (instrucciones)


; ********************************************************************************
; Sección de subrutinas


; ********************************************************************************
; Código principal

main:

        MOV  R1, #0             ; R1 = 0
loop2   MOV  R0, #0             ; R0 = 0

loop                            ; Etiqueta loop
        ADD  R0, #counter       ; R0 = R0 + counter
        CMP  R0, #lap           ; ¿R0 = #lap?
        BNE  loop               ; Si Z=0 => saltar a loop
        ADD  R1, #1             ; R1 = R1 + 1
        B    loop2              ; Saltar a loop2

        .end
