/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       16 de abril de 2025
 * 
 * Tema 08:     Lenguaje C
 * Código 14:   GPIO: Input
 * Descripción: Configuración de los GPIO del microcontrolador como entrada para 
 *              leer los SW de la tarjeta de desarrollo.
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


/**
 * System Control (SYSCTL) registers                                                    pp247   Register map
 */

#define SYSCTL_RCGCGPIO_R           (*((volatile uint32_t *)0x400FE608))            /*  pp382   GPIO Run Mode Clock Gating Control */
#define SYSCTL_PRGPIO_R             (*((volatile uint32_t *)0x400FEA08))            /*  pp499   GPIO Peripheral Ready */


/**
 * General-Purpose Input/Output (GPIO) registers                                        pp757   Register map
 */

    // GPIO Port J (PortJ)
#define GPIO_PORTJ_AHB_DATA_R       (*((volatile uint32_t *)0x40060004))            /*  pp759   GPIO Data >> PortJ[0] unmasked */
#define GPIO_PORTJ_AHB_DIR_R        (*((volatile uint32_t *)0x40060400))            /*  pp760   GPIO Direction */
#define GPIO_PORTJ_AHB_PUR_R        (*((volatile uint32_t *)0x40060510))            /*  pp776   GPIO Pull-Up Select */
#define GPIO_PORTJ_AHB_DEN_R        (*((volatile uint32_t *)0x4006051C))            /*  pp781   GPIO Digital Enable */

    // GPIO Port N (PortN)
#define GPIO_PORTN_DATA_R           (*((volatile uint32_t *)0x40064008))            /*  pp759   GPIO Data >> PortN[1] unmasked */
#define GPIO_PORTN_DIR_R            (*((volatile uint32_t *)0x40064400))            /*  pp760   GPIO Direction */
#define GPIO_PORTN_DEN_R            (*((volatile uint32_t *)0x4006451C))            /*  pp781   GPIO Digital Enable */


/*********************************************************************************
 * Macros de apoyo
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

    /*  Lectura de los botones de usuario (SWn) */
#define SW1_Pressed                 (!(GPIO_PORTJ_AHB_DATA_R & GPIO_PIN_0))         /*  Lectura del SW1 (PortJ[0]) => Presionado */
#define SW1_Released                (GPIO_PORTJ_AHB_DATA_R & GPIO_PIN_0)            /*  Lectura del SW1 (PortJ[0]) => Liberado */


/*********************************************************************************
 * Variables globales
 */

uint32_t Bounce_Delay = 100000;                                                     /*  Valor de carga del SysTick para un retardo de rebote de 25ms (f = 4MHz) */


/*********************************************************************************
 * Funciones
 */

void GPIO_PortJ_Init(void) {

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R8;                                        /*  PortJ => Habilitar y proveer de señal de reloj */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R8)) {}                                /*  PortJ => Esperar a que se estabilice la señal de reloj */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTJ_AHB_DIR_R &= ~GPIO_PIN_0;                                            /*  PortJ[0] => Data direction -> Input */

    /*  Paso 8: Configurar como Open Drain (GPIOODR) o las resistencias de Pull-Up (GPIOPUR) / Pull-Down (GPIOPDR) */
    GPIO_PORTJ_AHB_PUR_R |= GPIO_PIN_0;                                             /*  PortJ[0] => Pull-Up resistors -> Enabled */

    /*  Paso 9: Configurar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTJ_AHB_DEN_R |= GPIO_PIN_0;                                             /*  PortJ[0] => Digital functions -> Enabled */

}


void GPIO_PortN_Init(void) {

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;                                       /*  PortN => Habilitar y proveer de señal de reloj */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R12)) {}                               /*  PortN => Esperar a que se estabilice la señal de reloj */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTN_DIR_R |= GPIO_PIN_1;                                                 /*  PortN[1] => Data direction -> Output */

    /*  Paso 9: Configurar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTN_DEN_R |= GPIO_PIN_1;                                                 /*  PortN[1] => Digital functions -> Enabled */

}


void SysTick_OneShot_Init(uint32_t SysTick_Reload) {

    /*  Paso 1: Cargar el valor de cuenta del SysTick (STRELOAD) */
    NVIC_ST_RELOAD_R = (SysTick_Reload & NVIC_ST_RELOAD_M);

    /*  Paso 2: Limpiar el valor actual del SysTick (STCURRENT) al escribir cualquier valor */
    NVIC_ST_CURRENT_R = 0;

    /*  Paso 3: Configurar el SysTick para la operación requerida (STCTRL) */
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;                                          /*  Fuente de reloj de 4 MHz, Interrupción deshabilitada, Habilitación del SysTick */

    /*  Configurar el SysTick en modo OneShot */
    NVIC_ST_RELOAD_R = 0;                                                           /*  Limpiar el valor de cuenta del SysTick (STRELOAD) para deshabilitar al contador en el siguiente ciclo */

}


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortJ_Init();                                                              /*  Inicialización del GPIO PortJ */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */

    while(1) {

        while(SW1_Released) {}                                                      /*  Esperar mientras esté liberado el SW1 (PortJ[0]) */
        SysTick_OneShot_Init(Bounce_Delay);                                         /*  Inicialización del SysTick en modo OneShot para el retardo de rebote */
        SysTick_wait();                                                             /*  Esperar a que el SysTick termine la cuenta */

        LED_D1_Toggle();                                                            /*  Conmutación del LED D1 (PortN[1]) */

        while(SW1_Pressed) {}                                                       /*  Esperar mientras esté presionado el SW1 (PortJ[0]) */
        SysTick_OneShot_Init(Bounce_Delay);                                         /*  Inicialización del SysTick en modo OneShot para el retardo de rebote */
        SysTick_wait();                                                             /*  Esperar a que el SysTick termine la cuenta */

    }
}
