/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       09 de mayo de 2025
 * 
 * Código:      Archivo fuente del GPIO
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "NVIC.h"                                                                   /*  Archivo de cabecera del NVIC */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */


/*********************************************************************************
 * Funciones
 */

void GPIO_PortL4_Init_T0CCP0(void) {

    /**
     * Configuración del GPIO
     */

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R10;                                       /*  R12: GPIO PortL Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R10)) {}                               /*  R12: GPIO PortL Peripheral Ready -> GPIO PortN is ready for access? */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTL_DIR_R &= ~GPIO_PIN_4;                                                /*  PortL[4] => DIR: Data direction -> Input */

    /*  Paso 3: Habilitar la función alterna del GPIO (GPIOAFSEL) */
    GPIO_PORTL_AFSEL_R |= GPIO_PIN_4;                                               /*  PortL[4] => AFSEL: Alternate Function Select -> Alternate hardware function */

    /*  Paso 4: Seleccionar la función alterna de hardware (GPIOPCTL) */
    GPIO_PORTL_PCTL_R = ((GPIO_PORTL_PCTL_R & ~0x000F0000) | (3 << 16));            /*  PortL[4] => PMC4: Port Mux Control 4 -> T0CCP0 */

    /*  Paso 5: Configurar como Open Drain (GPIOODR) o las resistencias de Pull-Up (GPIOPUR) / Pull-Down (GPIOPDR) */
    GPIO_PORTL_ODR_R &= ~GPIO_PIN_4;                                                /*  PortL[4] => ODE: Output Pad Open Drain Enable -> Disabled */
    GPIO_PORTL_PUR_R |= GPIO_PIN_4;                                                 /*  PortL[4] => PUE: Pad Weak Pull-Up Enable -> Enabled */
    GPIO_PORTL_PDR_R &= ~GPIO_PIN_4;                                                /*  PortL[4] => PDE: Pad Weak Pull-Down Enable -> Disabled */

    /*  Paso 9: Habilitar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTL_DEN_R |= GPIO_PIN_4;                                                 /*  PortL[4] => DEN: Digital Enable -> Enabled */

}


void GPIO_PortL5_Init_T0CCP1(void) {

    /**
     * Configuración del GPIO
     */

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R10;                                       /*  R12: GPIO PortL Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R10)) {}                               /*  R12: GPIO PortL Peripheral Ready -> GPIO PortN is ready for access? */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTL_DIR_R &= ~GPIO_PIN_5;                                                /*  PortL[5] => DIR: Data direction -> Input */

    /*  Paso 3: Habilitar la función alterna del GPIO (GPIOAFSEL) */
    GPIO_PORTL_AFSEL_R |= GPIO_PIN_5;                                               /*  PortL[5] => AFSEL: Alternate Function Select -> Alternate hardware function */

    /*  Paso 4: Seleccionar la función alterna de hardware (GPIOPCTL) */
    GPIO_PORTL_PCTL_R = ((GPIO_PORTL_PCTL_R & ~0x00F00000) | (3 << 20));            /*  PortL[5] => PMC5: Port Mux Control 5 -> T0CCP1 */

    /*  Paso 5: Configurar como Open Drain (GPIOODR) o las resistencias de Pull-Up (GPIOPUR) / Pull-Down (GPIOPDR) */
    GPIO_PORTL_ODR_R &= ~GPIO_PIN_5;                                                /*  PortL[5] => ODE: Output Pad Open Drain Enable -> Disabled */
    GPIO_PORTL_PUR_R |= GPIO_PIN_5;                                                 /*  PortL[5] => PUE: Pad Weak Pull-Up Enable -> Enabled */
    GPIO_PORTL_PDR_R &= ~GPIO_PIN_5;                                                /*  PortL[5] => PDE: Pad Weak Pull-Down Enable -> Disabled */

    /*  Paso 9: Habilitar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTL_DEN_R |= GPIO_PIN_5;                                                 /*  PortL[5] => DEN: Digital Enable -> Enabled */

}


void GPIO_PortN_Init(void) {

    /**
     * Configuración del GPIO
     */

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;                                       /*  R12: GPIO PortN Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R12)) {}                               /*  R12: GPIO PortN Peripheral Ready -> GPIO PortN is ready for access? */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTN_DIR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                                  /*  PortN[1:0] => DIR: Data direction -> Output */

    /*  Paso 3: Deshabilitar la función alterna del GPIO (GPIOAFSEL) */
    GPIO_PORTN_AFSEL_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                               /*  PortN[1:0] => AFSEL: Alternate Function Select -> GPIO */

    /*  Paso 4: Configurar los modos de controlador extendidos (GPIOPC) */
    uint32_t reg = GPIO_PORTN_PC_R;
    reg &= ~(GPIO_PC_EDM1_M | GPIO_PC_EDM0_M);                                      /*  PortN[1:0] => EDM: Extended Drive Mode -> Bits cleared */
    reg |= ((0 << GPIO_PC_EDM1_S) | (0 << GPIO_PC_EDM0_S));                         /*  PortN[1:0] => EDM: Extended Drive Mode -> Drive values of 2, 4 and 8mA are maintained */
    GPIO_PORTN_PC_R = reg;

    /*  Paso 5: Configurar el driver de 4mA del GPIO (GPIODR4R) */
    GPIO_PORTN_DR4R_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                /*  PortN[1:0] => DRV4: Output Pad 4mA Drive Enable -> Controlled by GPIODR2R or GPIODR8R */

    /*  Paso 6: Configurar el driver de 8mA del GPIO (GPIODR8R) */
    GPIO_PORTN_DR8R_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                /*  PortN[1:0] => DRV8: Output Pad 8mA Drive Enable -> Controlled by GPIODR2R or GPIODR4R */

    /*  Paso 7: Configurar el driver de 12mA del GPIO (GPIODR12R) */
    GPIO_PORTN_DR12R_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                               /*  PortN[1:0] => DRV12: Output Pad 12mA Drive Enable -> Controlled by GPIODR2R, GPIODR4R and/or GPIODR8R */

    /*  Paso 8: Configurar como Open Drain (GPIOODR) o las resistencias de Pull-Up (GPIOPUR) / Pull-Down (GPIOPDR) */
    GPIO_PORTN_ODR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                 /*  PortN[1:0] => ODE: Output Pad Open Drain Enable -> Disabled */
    GPIO_PORTN_PUR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                 /*  PortN[1:0] => PUE: Pad Weak Pull-Up Enable -> Disabled */
    GPIO_PORTN_PDR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                 /*  PortN[1:0] => PDE: Pad Weak Pull-Down Enable -> Disabled */

    /*  Paso 9: Habilitar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTN_DEN_R |= (GPIO_PIN_1 | GPIO_PIN_0);                                  /*  PortN[1:0] => DEN: Digital Enable -> Enabled */

    /*  Paso 10: Para uso de interrupción, configurar la sensibilidad (GPIOIS), el evento (GPIOIBE y GPIOIEV), limpiar la bandera de interrupción (GPIOICR) y desenmascarar la interrupción (GPIOIM) */
    GPIO_PORTN_IS_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                  /*  PortN[1:0] => IS: Interrupt Sense -> Edge-sensitive */
    GPIO_PORTN_IBE_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                 /*  PortN[1:0] => IBE: Interrupt Both Edges -> Controlled by GPIOIEV */
    GPIO_PORTN_IEV_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                 /*  PortN[1:0] => IEV: Interrupt Event -> Falling edge */
    GPIO_PORTN_ICR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                 /*  PortN[1:0] => IC: Interrupt Clear -> Interrupt unaffected */
    GPIO_PORTN_IM_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                                  /*  PortN[1:0] => IME: Interrupt Mask Enable -> Interrupt masked */

    /**
     * Configuración de la interrupción
     */
    
    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    /*  Paso 2: Habilitar la interrupción (ENn) */

}
