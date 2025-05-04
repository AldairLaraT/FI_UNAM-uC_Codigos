/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       16 de abril de 2025
 * 
 * Tema 07:     Interrupciones y resets
 * Código 15:   GPIO con interrupción
 * Descripción: Configuración de los GPIO del microcontrolador como entrada para 
 *              leer los SW de la tarjeta de desarrollo, empleando interrupciones.
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 */

/**
 * Nested Vectored Interrupt Controller (NVIC) registers                                pp146   Register map
 */

    // System Timer (SysTick) registers
#define NVIC_ST_CTRL_R              (*((volatile uint32_t *)0xE000E010))            /*  pp150   SysTick Control and Status */
#define NVIC_ST_RELOAD_R            (*((volatile uint32_t *)0xE000E014))            /*  pp152   SysTick Reload Value */
#define NVIC_ST_CURRENT_R           (*((volatile uint32_t *)0xE000E018))            /*  pp153   SysTick Current Value */

    // Nested Vectored Interrupt Controller (NVIC) registers
#define NVIC_EN1_R                  (*((volatile uint32_t *)0xE000E104))            /*  pp154   Interrupt 32-63 Set Enable */
#define NVIC_PRI12_R                (*((volatile uint32_t *)0xE000E430))            /*  pp159   Interrupt 48-51 Priority */

/**
 * System Control (SYSCTL) registers                                                    pp247   Register map
 */

#define SYSCTL_RCGCGPIO_R           (*((volatile uint32_t *)0x400FE608))            /*  pp382   GPIO Run Mode Clock Gating Control */
#define SYSCTL_PRGPIO_R             (*((volatile uint32_t *)0x400FEA08))            /*  pp499   GPIO Peripheral Ready */

/**
 * General-Purpose Input/Output (GPIO) registers                                        pp757   Register map
 */

    // GPIO Port F (PortF)
#define GPIO_PORTF_AHB_DATA_R       (*((volatile uint32_t *)0x4005D044))            /*  pp759   GPIO Data >> PortF[4, 0] unmasked */
#define GPIO_PORTF_AHB_DIR_R        (*((volatile uint32_t *)0x4005D400))            /*  pp760   GPIO Direction */
#define GPIO_PORTF_AHB_DEN_R        (*((volatile uint32_t *)0x4005D51C))            /*  pp781   GPIO Digital Enable */

    // GPIO Port J (PortJ)
#define GPIO_PORTJ_AHB_DATA_R       (*((volatile uint32_t *)0x4006000C))            /*  pp759   GPIO Data >> PortJ[1:0] unmasked */
#define GPIO_PORTJ_AHB_DIR_R        (*((volatile uint32_t *)0x40060400))            /*  pp760   GPIO Direction */
#define GPIO_PORTJ_AHB_IS_R         (*((volatile uint32_t *)0x40060404))            /*  pp761   GPIO Interrupt Sense */
#define GPIO_PORTJ_AHB_IBE_R        (*((volatile uint32_t *)0x40060408))            /*  pp762   GPIO Interrupt Both Edges */
#define GPIO_PORTJ_AHB_IEV_R        (*((volatile uint32_t *)0x4006040C))            /*  pp763   GPIO Interrupt Event */
#define GPIO_PORTJ_AHB_IM_R         (*((volatile uint32_t *)0x40060410))            /*  pp764   GPIO Interrupt Mask */
#define GPIO_PORTJ_AHB_ICR_R        (*((volatile uint32_t *)0x4006041C))            /*  pp769   GPIO Interrupt Clear */
#define GPIO_PORTJ_AHB_PUR_R        (*((volatile uint32_t *)0x40060510))            /*  pp776   GPIO Pull-Up Select */
#define GPIO_PORTJ_AHB_DEN_R        (*((volatile uint32_t *)0x4006051C))            /*  pp781   GPIO Digital Enable */

    // GPIO Port N (PortN)
#define GPIO_PORTN_DATA_R           (*((volatile uint32_t *)0x4006400C))            /*  pp759   GPIO Data >> PortN[1:0] unmasked */
#define GPIO_PORTN_DIR_R            (*((volatile uint32_t *)0x40064400))            /*  pp760   GPIO Direction */
#define GPIO_PORTN_DEN_R            (*((volatile uint32_t *)0x4006451C))            /*  pp781   GPIO Digital Enable */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the NVIC_ST_CTRL register                                          pp150
#define NVIC_ST_CTRL_COUNT          0x00010000                                      /*  Count Flag */
#define NVIC_ST_CTRL_CLK_SRC        0x00000004                                      /*  Clock Source */
#define NVIC_ST_CTRL_INTEN          0x00000002                                      /*  Interrupt Enable */
#define NVIC_ST_CTRL_ENABLE         0x00000001                                      /*  Enable */

    // Bit fields in the NVIC_ST_RELOAD register                                        pp152
#define NVIC_ST_RELOAD_M            0x00FFFFFF                                      /*  Reload Value Mask */
#define NVIC_ST_RELOAD_S            0                                               /*  Reload Value Shift */

    // Bit fields in the NVIC_ST_CURRENT register                                       pp153
#define NVIC_ST_CURRENT_M           0x00FFFFFF                                      /*  Current Value Mask */
#define NVIC_ST_CURRENT_S           0                                               /*  Current Value Shift */

    // Bit fields in the NVIC_PRI12 register                                            pp159
#define NVIC_PRI12_INT51_M          0xE0000000                                      /*  Interrupt 51 Priority Mask */
#define NVIC_PRI12_INT50_M          0x00E00000                                      /*  Interrupt 50 Priority Mask */
#define NVIC_PRI12_INT49_M          0x0000E000                                      /*  Interrupt 49 Priority Mask */
#define NVIC_PRI12_INT48_M          0x000000E0                                      /*  Interrupt 48 Priority Mask */
#define NVIC_PRI12_INT51_S          29                                              /*  Interrupt 51 Priority Shift */
#define NVIC_PRI12_INT50_S          21                                              /*  Interrupt 50 Priority Shift */
#define NVIC_PRI12_INT49_S          13                                              /*  Interrupt 49 Priority Shift */
#define NVIC_PRI12_INT48_S          5                                               /*  Interrupt 48 Priority Shift */

    // Bit fields in the SYSCTL_RCGCGPIO register                                       pp382
#define SYSCTL_RCGCGPIO_R14         0x00004000                                      /*  GPIO Port Q Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R13         0x00002000                                      /*  GPIO Port P Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R12         0x00001000                                      /*  GPIO Port N Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R11         0x00000800                                      /*  GPIO Port M Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R10         0x00000400                                      /*  GPIO Port L Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R9          0x00000200                                      /*  GPIO Port K Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R8          0x00000100                                      /*  GPIO Port J Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R7          0x00000080                                      /*  GPIO Port H Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R6          0x00000040                                      /*  GPIO Port G Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R5          0x00000020                                      /*  GPIO Port F Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R4          0x00000010                                      /*  GPIO Port E Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R3          0x00000008                                      /*  GPIO Port D Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R2          0x00000004                                      /*  GPIO Port C Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R1          0x00000002                                      /*  GPIO Port B Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R0          0x00000001                                      /*  GPIO Port A Run Mode Clock Gating Control */

    // Bit fields in the SYSCTL_PRGPIO register                                         pp499
#define SYSCTL_PRGPIO_R14           0x00004000                                      /*  GPIO Port Q Peripheral Ready */
#define SYSCTL_PRGPIO_R13           0x00002000                                      /*  GPIO Port P Peripheral Ready */
#define SYSCTL_PRGPIO_R12           0x00001000                                      /*  GPIO Port N Peripheral Ready */
#define SYSCTL_PRGPIO_R11           0x00000800                                      /*  GPIO Port M Peripheral Ready */
#define SYSCTL_PRGPIO_R10           0x00000400                                      /*  GPIO Port L Peripheral Ready */
#define SYSCTL_PRGPIO_R9            0x00000200                                      /*  GPIO Port K Peripheral Ready */
#define SYSCTL_PRGPIO_R8            0x00000100                                      /*  GPIO Port J Peripheral Ready */
#define SYSCTL_PRGPIO_R7            0x00000080                                      /*  GPIO Port H Peripheral Ready */
#define SYSCTL_PRGPIO_R6            0x00000040                                      /*  GPIO Port G Peripheral Ready */
#define SYSCTL_PRGPIO_R5            0x00000020                                      /*  GPIO Port F Peripheral Ready */
#define SYSCTL_PRGPIO_R4            0x00000010                                      /*  GPIO Port E Peripheral Ready */
#define SYSCTL_PRGPIO_R3            0x00000008                                      /*  GPIO Port D Peripheral Ready */
#define SYSCTL_PRGPIO_R2            0x00000004                                      /*  GPIO Port C Peripheral Ready */
#define SYSCTL_PRGPIO_R1            0x00000002                                      /*  GPIO Port B Peripheral Ready */
#define SYSCTL_PRGPIO_R0            0x00000001                                      /*  GPIO Port A Peripheral Ready */

    // Bit fields for the GPIO pin
#define GPIO_PIN_7                  0x00000080                                      /*  GPIO pin 7 */
#define GPIO_PIN_6                  0x00000040                                      /*  GPIO pin 6 */
#define GPIO_PIN_5                  0x00000020                                      /*  GPIO pin 5 */
#define GPIO_PIN_4                  0x00000010                                      /*  GPIO pin 4 */
#define GPIO_PIN_3                  0x00000008                                      /*  GPIO pin 3 */
#define GPIO_PIN_2                  0x00000004                                      /*  GPIO pin 2 */
#define GPIO_PIN_1                  0x00000002                                      /*  GPIO pin 1 */
#define GPIO_PIN_0                  0x00000001                                      /*  GPIO pin 0 */

    /*  Lectura del estado del SysTick */
#define SysTick_wait()              while (!(NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT)) {}   /*  Esperar a que el SysTick termine la cuenta */

    /*  Control de los LED de usuario (Dn) */
#define LED_D1_Toggle()             (GPIO_PORTN_DATA_R ^= GPIO_PIN_1)               /*  Conmutación del LED D1 (PortN[1]) */
#define LED_D2_Toggle()             (GPIO_PORTN_DATA_R ^= GPIO_PIN_0)               /*  Conmutación del LED D2 (PortN[0]) */
#define LED_D3_Toggle()             (GPIO_PORTF_AHB_DATA_R ^= GPIO_PIN_4)           /*  Conmutación del LED D3 (PortF[4]) */
#define LED_D4_Toggle()             (GPIO_PORTF_AHB_DATA_R ^= GPIO_PIN_0)           /*  Conmutación del LED D4 (PortF[0]) */

    /*  Lectura de los botones de usuario (SWn) */
#define SW1_Pressed                 (!(GPIO_PORTJ_AHB_DATA_R & GPIO_PIN_0))         /*  Lectura del SW1 (PortJ[0]) => Presionado */
#define SW2_Pressed                 (!(GPIO_PORTJ_AHB_DATA_R & GPIO_PIN_1))         /*  Lectura del SW2 (PortJ[1]) => Presionado */


/*********************************************************************************
 * Variables globales
 */

uint32_t Bounce_Delay = 100000;                                                     /*  Valor de carga del SysTick para un retardo de rebote de 25ms (f = 4MHz) */
int cuenta = 0;


/*********************************************************************************
 * Funciones
 */

void GPIO_PortF_Init(void) {

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;                                        /*  PortF => Habilitar y proveer de señal de reloj */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)) {}                                /*  PortF => Esperar a que se estabilice la señal de reloj */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTF_AHB_DIR_R |= (GPIO_PIN_4 | GPIO_PIN_0);                              /*  PortF[4,0] => Data direction -> Output */

    /*  Paso 9: Configurar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTF_AHB_DEN_R |= (GPIO_PIN_4 | GPIO_PIN_0);                              /*  PortF[4,0] => Digital functions -> Enabled */

}


void GPIO_PortJ_Init(void) {

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R8;                                        /*  PortJ => Habilitar y proveer de señal de reloj */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R8)) {}                                /*  PortJ => Esperar a que se estabilice la señal de reloj */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTJ_AHB_DIR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1:0] => Data direction -> Input */

    /*  Paso 8: Configurar como Open Drain (GPIOODR) o las resistencias de Pull-Up (GPIOPUR) / Pull-Down (GPIOPDR) */
    GPIO_PORTJ_AHB_PUR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => Pull-Up resistors -> Enabled */

    /*  Paso 9: Configurar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTJ_AHB_DEN_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => Digital functions -> Enabled */

    /*  Paso 10: Para uso de interrupción, configurar la sensibilidad (GPIOIS), el evento (GPIOIBE y GPIOIEV), limpiar la bandera de interrupción (GPIOICR) y desenmascarar la interrupción (GPIOIM) */
    GPIO_PORTJ_AHB_IS_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => Interrupt sense -> Edge-sensitive */
    GPIO_PORTJ_AHB_IBE_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1:0] => Interrupt both edges -> Controlled by the GPIOIEV register */
    GPIO_PORTJ_AHB_IEV_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1:0] => Interrupt event -> Falling edge triggers an interrupt */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => Interrupt is cleared (recomendado) */
    GPIO_PORTJ_AHB_IM_R |= (GPIO_PIN_1 | GPIO_PIN_0);                               /*  PortJ[1:0] => Interrupt mask -> Unmasked */

    /**
     * Configuración de la interrupción
     */

    /*  Configurar el nivel de prioridad de la interrupción (PRIn) */
    NVIC_PRI12_R = (NVIC_PRI12_R & ~NVIC_PRI12_INT51_M) | (0 << NVIC_PRI12_INT51_S);    /*  PortJ => Interrupt priority -> 0 */

    /*  Habilitar la interrupción (ENn) */
    NVIC_EN1_R |= (1 << (51 - 32));                                                 /*  Interrupt 51 (PortJ) => Enabled */

}


void GPIO_PortN_Init(void) {

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;                                       /*  PortN => Habilitar y proveer de señal de reloj */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R12)) {}                               /*  PortN => Esperar a que se estabilice la señal de reloj */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTN_DIR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                                  /*  PortN[1:0] => Data direction -> Output */

    /*  Paso 9: Configurar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTN_DEN_R |= (GPIO_PIN_1 | GPIO_PIN_0);                                  /*  PortN[1:0] => Digital functions -> Enabled */

}


void SysTick_Init_OneShot(uint32_t SysTick_Reload) {

    /*  Paso 1: Cargar el valor de cuenta del SysTick (STRELOAD) */
    NVIC_ST_RELOAD_R = (SysTick_Reload & NVIC_ST_RELOAD_M);

    /*  Paso 2: Limpiar el valor actual del SysTick (STCURRENT) al escribir cualquier valor */
    NVIC_ST_CURRENT_R = 0;

    /*  Paso 3: Configurar el SysTick para la operación requerida (STCTRL) */
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;                                          /*  Fuente de reloj de 4 MHz, Interrupción deshabilitada, Habilitación del SysTick */

    /*  Configurar el SysTick en modo One-Shot */
    NVIC_ST_RELOAD_R = 0;                                                           /*  Limpiar el valor de cuenta del SysTick (STRELOAD) para deshabilitar al contador en el siguiente ciclo */

}


void GPIOPortJ_Handler(void) {

    SysTick_Init_OneShot(Bounce_Delay);                                             /*  Inicialización del SysTick en modo One-Shot para el retardo de rebote */
    SysTick_wait();                                                                 /*  Esperar a que el SysTick termine la cuenta */

    if (SW1_Pressed) {                                                              /*  Validación del SW1 */
        cuenta += 1;
    }

    if (SW2_Pressed) {                                                              /*  Validación del SW2 */
        cuenta -= 1;
    }

    /*  Limpiar la bandera de interrupción */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1,0] => Interrupt is cleared */

}


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortF_Init();                                                              /*  Inicialización del GPIO PortF */
    GPIO_PortJ_Init();                                                              /*  Inicialización del GPIO PortJ */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */

    int i;

    while(1) {

        for (i = 0; i < 700000; i++) {}                                             /*  Retardo aproximado de 500ms */
        LED_D1_Toggle();                                                            /*  Conmutación del LED D1 (PortN[1]) */

        for (i = 0; i < 700000; i++) {}                                             /*  Retardo aproximado de 500ms */
        LED_D2_Toggle();                                                            /*  Conmutación del LED D2 (PortN[0]) */

        for (i = 0; i < 700000; i++) {}                                             /*  Retardo aproximado de 500ms */
        LED_D3_Toggle();                                                            /*  Conmutación del LED D3 (PortF[4]) */

        for (i = 0; i < 700000; i++) {}                                             /*  Retardo aproximado de 500ms */
        LED_D4_Toggle();                                                            /*  Conmutación del LED D4 (PortF[0]) */

    }
}
