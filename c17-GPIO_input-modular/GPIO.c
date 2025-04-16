/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       16 de abril de 2025
 * 
 * Código:      Archivo fuente del GPIO
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "GPIO.h"                                                                   /*  Macros para el uso de GPIO */
#include "SYSCTL.h"                                                                 /*  macros para el uso de SYSCTL */


/*********************************************************************************
 * Funciones
 */

void GPIO_PortJ_Init(void) {

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R8;                                        /*  PortJ => Habilitar y proveer de señal de reloj */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R8)) {}                                /*  PortJ => Esperar a que se estabilice la señal de reloj */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTJ_AHB_DIR_R &= ~GPIO_PIN_0;                                            /*  PortJ[0] => Data direction -> Input */

    /*  Paso 8: Configurar las resistencias de Pull-Up (GPIOPUR) o Pull-Down (GPIOPDR), o la función de Open Drain (GPIOODR) del GPIO */
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
