; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 06:      Puertos de entrada/salida
; Código 11:    GPIO: Input
; Descripción:  Configuración de los GPIO del microcontrolador como entrada para
;               leer los SW de la tarjeta de desarrollo, empleando lenguaje
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
        ; GPIO Port J (PortJ)
GPIO_PORTJ_AHB_DATA_R   .field 0x40060004,32                    ; pp759   GPIO Data >> PortJ[0] unmasked
GPIO_PORTJ_AHB_DIR_R    .field 0x40060400,32                    ; pp760   GPIO Direction
GPIO_PORTJ_AHB_PUR_R    .field 0x40060510,32                    ; pp776   GPIO Pull-Up Select
GPIO_PORTJ_AHB_DEN_R    .field 0x4006051C,32                    ; pp781   GPIO Digital Enable
        ; GPIO Port N (PortN)
GPIO_PORTN_DATA_R       .field 0x40064008,32                    ; pp759   GPIO Data >> PortN[1] unmasked
GPIO_PORTN_DIR_R        .field 0x40064400,32                    ; pp760   GPIO Direction
GPIO_PORTN_DEN_R        .field 0x4006451C,32                    ; pp781   GPIO Digital Enable

; Constantes de apoyo
SW1                     .EQU 0x0                                ; SW1 (PortJ[0]) pressed
LED1                    .EQU 0x2                                ; LED1 (PortN[1])


; ********************************************************************************
; Sección de subrutinas

GPIO_PortJ_Init
    ; 1. Habilitar la señal de reloj (RCGCGPIO) y esperar dos ciclos de instrucción
    ;    para que se estabilice.
        LDR  R0, SYSCTL_RCGCGPIO_R
        LDR  R1, [R0]
        ORR  R1, #0x0100
        STR  R1, [R0]                           ; Habilitación el reloj del PortJ
        NOP                                     ; Espera a que se estabilice el reloj del PortJ
        NOP

    ; 2. Configurar la dirección del GPIO (GPIODIR).
        LDR  R0, GPIO_PORTJ_AHB_DIR_R
        LDR  R1, [R0]
        BIC  R1, #0x01
        STR  R1, [R0]                           ; PortJ[0] => Data direction -> Input

    ; 6. Habilitar las resistencias de pull-up (GPIOPUR) o de pull-down (GPIOPDR),
    ;    o configurar como drenaje abierto (GPIODIR).
        LDR  R0, GPIO_PORTJ_AHB_PUR_R
        LDR  R1, [R0]
        ORR  R1, #0x01
        STR  R1, [R0]                           ; PortJ[0] => Pull-Up resistors -> Enabled

    ; 7. Configurar las funciones digitales (GPIODEN).
        LDR  R0, GPIO_PORTJ_AHB_DEN_R
        LDR  R1, [R0]
        ORR  R1, #0x01
        STR  R1, [R0]                           ; PortJ[0] => Digital functions -> Enabled

        BX   LR


GPIO_PortN_Init
    ; 1. Habilitar la señal de reloj (RCGCGPIO) y esperar dos ciclos de instrucción
    ;    para que se estabilice.
        LDR  R0, SYSCTL_RCGCGPIO_R
        LDR  R1, [R0]
        ORR  R1, #0x1000
        STR  R1, [R0]                           ; Habilitación el reloj del PortN
        NOP                                     ; Espera a que se estabilice el reloj del PortN
        NOP

    ; 2. Configurar la dirección del GPIO (GPIODIR).
        LDR  R0, GPIO_PORTN_DIR_R
        LDR  R1, [R0]
        ORR  R1, #0x02
        STR  R1, [R0]                           ; PortN[1] => Data direction -> Output

    ; 7. Configurar las funciones digitales (GPIODEN).
        LDR  R0, GPIO_PORTN_DEN_R
        LDR  R1, [R0]
        ORR  R1, #0x02
        STR  R1, [R0]                           ; PortN[1] => Digital functions -> Enabled

        BX   LR


retardo
        MOV  R4, #0xD054                        ; Retardo aproximado de 10ms
        MOVT R4, #0x0000
wait
        SUBS R4, #1
        BNE  wait

        BX   LR


; ********************************************************************************
; Código principal

main:

        BL   GPIO_PortJ_Init                    ; Subrutina de inicialización del GPIO PortJ
        BL   GPIO_PortN_Init                    ; Subrutina de inicialización del GPIO PortN

        LDR  R0, GPIO_PORTJ_AHB_DATA_R          ; Apuntador del registro GPIODATA del PortJ
        LDR  R1, GPIO_PORTN_DATA_R              ; Apuntador del registro GPIODATA del PortN

loop
        LDR  R2, [R0]                           ; Lectura del SW1
        CMP  R2, #SW1
        BNE  loop
        BL   retardo

        LDR  R2, [R0]                           ; Lectura del SW1 para validar si fue presionado
        CMP  R2, #SW1
        BNE  loop

        LDR  R2, [R1]
        EOR  R2, #LED1
        STR  R2, [R1]                           ; Conmutación del LED1

        B    loop

        .end
