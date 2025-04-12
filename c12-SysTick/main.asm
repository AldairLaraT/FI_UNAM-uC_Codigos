; ********************************************************************************
; Universidad Nacional Autónoma de México (UNAM)
; Facultad de Ingeniería | Departamento de Electrónica
; 
; Asignatura:   Microprocesadores y Microcontroladores
; Profesor:     M.I. Christo Aldair Lara Tenorio
; Fecha:        12 de abril de 2025
; 
; Tema 06:      Puertos de entrada/salida
; Código 12:    Temporizador SysTick
; Descripción:  Configuración y uso del temporizador SysTick del procesador,
;               empleando lenguaje ensamblador.
;
; Tarjeta de desarrollo:        EK-TM4C1294XL Evaluation board
; ********************************************************************************


; ********************************************************************************
; Sección de directivas

        .global main

; Nested Vectored Interrupt Controller (NVIC) registers           pp146   Register map
        ; System Timer (SysTick) registers
NVIC_ST_CTRL_R          .field 0xE000E010,32                    ; pp150   SysTick Control and Status
NVIC_ST_RELOAD_R        .field 0xE000E014,32                    ; pp152   SysTick Reload Value
NVIC_ST_CURRENT_R       .field 0xE000E018,32                    ; pp153   SysTick Current Value

; System Control (SYSCTL) registers                               pp247   Register map
SYSCTL_RCGCGPIO_R       .field 0x400FE608,32                    ; pp382   GPIO Run Mode Clock Gating Control

; General-Purpose Input/Output (GPIO) registers                   pp757   Register map
        ; GPIO Port N (PortN)
GPIO_PORTN_DATA_R       .field 0x4006400C,32                    ; pp759   GPIO Data >> PortN[1,0] unmasked
GPIO_PORTN_DIR_R        .field 0x40064400,32                    ; pp760   GPIO Direction
GPIO_PORTN_DEN_R        .field 0x4006451C,32                    ; pp781   GPIO Digital Enable

; Constantes de apoyo
NVIC_ST_CTRL_COUNT      .EQU 0x00010000                         ; SysTick Count Flag
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


SysTick_Init
    ; 1. Cargar el valor de cuenta del SysTick (STRELOAD).
        LDR  R0, NVIC_ST_RELOAD_R
        MOV  R1, #0x0900
        MOVT R1, #0x003D
        STR  R1, [R0]

    ; 2. Limpiar el valor actual del SysTick (STCURRENT) al escribir cualquier valor.
        LDR  R0, NVIC_ST_CURRENT_R
        MOV  R1, #0x00
        STR  R1, [R0]

    ; 3. Configurar el SysTick para la operación requerida (STCTRL).
        LDR  R0, NVIC_ST_CTRL_R
        LDR  R1, [R0]
        ORR  R1, #0x01
        STR  R1, [R0]                           ; Habilitación del SysTick (f = 4MHz)

        BX   LR


SysTick_wait
        LDR  R0, NVIC_ST_CTRL_R
        LDR  R1, [R0]
        ANDS R1, #NVIC_ST_CTRL_COUNT
        BEQ  SysTick_wait                       ; ¿El SysTick ya terminó de contar? => ¿COUNT = 1?

        BX   LR


; ********************************************************************************
; Código principal

main:

        BL   GPIO_PortN_Init                    ; Subrutina de inicialización del GPIO PortN
        BL   SysTick_Init                       ; Subrutina de inicialización del SysTick

loop

        BL   SysTick_wait

        LDR  R0, GPIO_PORTN_DATA_R
        LDR  R1, [R0]
        EOR  R1, #LED1
        STR  R1, [R0]                           ; Conmutación del LED1

        BL   SysTick_wait

        LDR  R0, GPIO_PORTN_DATA_R
        LDR  R1, [R0]
        EOR  R1, #LED2
        STR  R1, [R0]                           ; Conmutación del LED2

        B    loop

        .end
