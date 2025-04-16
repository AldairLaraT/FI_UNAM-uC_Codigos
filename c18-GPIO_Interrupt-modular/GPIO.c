/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       15 de abril de 2025
 * 
 * Código:      Archivo fuente del GPIO
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "GPIO.h"                                                                   /*  Macros para el uso de GPIO */
#include "NVIC.h"                                                                   /*  Macros para el uso de NVIC */
#include "SYSCTL.h"                                                                 /*  Macros para el uso de SYSCTL */


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
    GPIO_PORTJ_AHB_DIR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1..0] => Data direction -> Input */

    /*  Paso 8: Configurar las resistencias de Pull-Up (GPIOPUR) o Pull-Down (GPIOPDR), o la función de Open Drain (GPIOODR) del GPIO */
    GPIO_PORTJ_AHB_PUR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1..0] => Pull-Up resistors -> Enabled */

    /*  Paso 9: Configurar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTJ_AHB_DEN_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1..0] => Digital functions -> Enabled */

    /*  Paso 10: Configurar la sensibilidad (GPIOIS), el evento (GPIOIBE y GPIOIEV) y desenmascarar la interrupción (GPIOIM) */
    GPIO_PORTJ_AHB_IS_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1..0] => Interrupt sense -> Edge-sensitive */
    GPIO_PORTJ_AHB_IBE_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1..0] => Interrupt both edges -> Controlled by the GPIOIEV register */
    GPIO_PORTJ_AHB_IEV_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1..0] => Interrupt event -> Falling edge triggers an interrupt */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1..0] => Interrupt is cleared (recomendado) */
    GPIO_PORTJ_AHB_IM_R |= (GPIO_PIN_1 | GPIO_PIN_0);                               /*  PortJ[1..0] => Interrupt mask -> Unmasked */

    /*  Configurar el nivel de prioridad de la interrupción (PRIn) */
    NVIC_PRI12_R = (NVIC_PRI12_R & ~NVIC_PRI12_INT51_M) | (0 << NVIC_PRI12_INT51_S);    /*  PortJ => Interrupt priority -> 0 */

    /*  Habilitar la interrupción (ENn) */
    NVIC_EN1_R |= 1 << (51 - 32);                                                   /*  Interrupt 51 (PortJ) => Enabled */

}


void GPIO_PortN_Init(void) {

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;                                       /*  PortN => Habilitar y proveer de señal de reloj */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R12)) {}                               /*  PortN => Esperar a que se estabilice la señal de reloj */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTN_DIR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                                  /*  PortN[1..0] => Data direction -> Output */

    /*  Paso 9: Configurar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTN_DEN_R |= (GPIO_PIN_1 | GPIO_PIN_0);                                  /*  PortN[1..0] => Digital functions -> Enabled */

}
