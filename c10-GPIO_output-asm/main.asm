; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 06:      Puertos de entrada/salida
; Código 10:    GPIO: Output
; Descripción:  Configuración de los GPIO del microcontrolador como salida para
;               encender los LED de la tarjeta de desarrollo, empleando lenguaje
;               ensamblador.
;
; Tarjeta de desarrollo:        EK-TM4C1294XL Evaluation board
; ********************************************************************************


; ********************************************************************************
; Sección de directivas

        .global main

; System Control (SYSCTL) registers                               pp247   Register map
SYSCTL_RCGCGPIO_R       .field 0x400FE608,32                    ; pp382   GPIO Run Mode Clock Gating Control

; General-Purpose Input/Output (GPIO) registers                   pp757   Register map
        ; GPIO Port N (PortN)
GPIO_PORTN_DATA_R       .field 0x4006400C,32                    ; pp759   GPIO Data >> PortN[1,0] unmasked
GPIO_PORTN_DIR_R        .field 0x40064400,32                    ; pp760   GPIO Direction
GPIO_PORTN_DEN_R        .field 0x4006451C,32                    ; pp781   GPIO Digital Enable

; Constantes de apoyo
LED1                    .EQU 0x2                                ; LED1 (PortN[1])
LED2                    .EQU 0x1                                ; LED0 (PortN[0])


; ********************************************************************************
; Sección de subrutinas

GPIO_PortN_Init
    ; 1. Habilitar la señal de reloj (RCGCGPIO) y esperar dos ciclos de instrucción
    ;    para que se estabilice.
        LDR  R0, SYSCTL_RCGCGPIO_R
        LDR  R1, [R0]
        ORR  R1, #0x1000
        STR  R1, [R0]                           ; Habilitación el reloj del PortN
        NOP                                     ; Esperar para que se estabilice el reloj del PortN
        NOP

    ; 2. Configurar la dirección del GPIO (GPIODIR).
        LDR  R0, GPIO_PORTN_DIR_R
        LDR  R1, [R0]
        ORR  R1, #0x03
        STR  R1, [R0]                           ; PortN[1,0] => Data direction -> Output

    ; 7. Configurar las funciones digitales (GPIODEN).
        LDR  R0, GPIO_PORTN_DEN_R
        LDR  R1, [R0]
        ORR  R1, #0x03
        STR  R1, [R0]                           ; PortN[1,0] => Digital functions -> Enabled

        BX   LR


; ********************************************************************************
; Código principal

main:

        BL   GPIO_PortN_Init                    ; Subrutina de inicialización del GPIO PortN

        LDR  R0, GPIO_PORTN_DATA_R              ; Apuntador del registro GPIODATA del PortN

loop

        LDR  R1, [R0]
        EOR  R1, #LED1
        STR  R1, [R0]                           ; Conmutación del LED1

        LDR  R1, [R0]
        EOR  R1, #LED2
        STR  R1, [R0]                           ; Conmutación del LED2

        B    loop

        .end
