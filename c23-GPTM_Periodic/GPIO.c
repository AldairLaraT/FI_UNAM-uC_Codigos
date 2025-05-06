/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       03 de mayo de 2025
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

void GPIO_PortF_Init(void) {

    /**
     * Configuración del GPIO
     */

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;                                        /*  R5: GPIO PortF Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R5)) {}                                /*  R5: GPIO PortF Peripheral Ready -> GPIO PortN is ready for access? */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTF_AHB_DIR_R |= (GPIO_PIN_4 | GPIO_PIN_0);                              /*  PortF[4, 0] => DIR: Data direction -> Output */

    /*  Paso 3: Deshabilitar la función alterna del GPIO (GPIOAFSEL) */
    GPIO_PORTF_AHB_AFSEL_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                           /*  PortF[4, 0] => AFSEL: Alternate Function Select -> GPIO */

    /*  Paso 4: Configurar los modos de controlador extendidos (GPIOPC) */
    uint32_t reg = GPIO_PORTF_AHB_PC_R;
    reg &= ~(GPIO_PC_EDM4_M | GPIO_PC_EDM0_M);                                      /*  PortF[4, 0] => EDM: Extended Drive Mode -> Bits cleared */
    reg |= ((0 << GPIO_PC_EDM4_S) | (0 << GPIO_PC_EDM0_S));                         /*  PortF[4, 0] => EDM: Extended Drive Mode -> Drive values of 2, 4 and 8mA are maintained */
    GPIO_PORTF_AHB_PC_R = reg;

    /*  Paso 5: Configurar el driver de 4mA del GPIO (GPIODR4R) */
    GPIO_PORTF_AHB_DR4R_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                            /*  PortF[4, 0] => DRV4: Output Pad 4mA Drive Enable -> Controlled by GPIODR2R or GPIODR8R */

    /*  Paso 6: Configurar el driver de 8mA del GPIO (GPIODR8R) */
    GPIO_PORTF_AHB_DR8R_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                            /*  PortF[4, 0] => DRV8: Output Pad 8mA Drive Enable -> Controlled by GPIODR2R or GPIODR4R */

    /*  Paso 7: Configurar el driver de 12mA del GPIO (GPIODR12R) */
    GPIO_PORTF_AHB_DR12R_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                           /*  PortF[4, 0] => DRV12: Output Pad 12mA Drive Enable -> Controlled by GPIODR2R, GPIODR4R and/or GPIODR8R */

    /*  Paso 8: Configurar como Open Drain (GPIOODR) o las resistencias de Pull-Up (GPIOPUR) / Pull-Down (GPIOPDR) */
    GPIO_PORTF_AHB_ODR_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                             /*  PortF[4, 0] => ODE: Output Pad Open Drain Enable -> Disabled */
    GPIO_PORTF_AHB_PUR_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                             /*  PortF[4, 0] => PUE: Pad Weak Pull-Up Enable -> Disabled */
    GPIO_PORTF_AHB_PDR_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                             /*  PortF[4, 0] => PDE: Pad Weak Pull-Down Enable -> Disabled */

    /*  Paso 9: Habilitar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTF_AHB_DEN_R |= (GPIO_PIN_4 | GPIO_PIN_0);                              /*  PortF[4, 0] => DEN: Digital Enable -> Enabled */

    /*  Paso 10: Para uso de interrupción, configurar la sensibilidad (GPIOIS), el evento (GPIOIBE y GPIOIEV), limpiar la bandera de interrupción (GPIOICR) y desenmascarar la interrupción (GPIOIM) */
    GPIO_PORTF_AHB_IS_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                              /*  PortF[4, 0] => IS: Interrupt Sense -> Edge-sensitive */
    GPIO_PORTF_AHB_IBE_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                             /*  PortF[4, 0] => IBE: Interrupt Both Edges -> Controlled by GPIOIEV */
    GPIO_PORTF_AHB_IEV_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                             /*  PortF[4, 0] => IEV: Interrupt Event -> Falling edge */
    GPIO_PORTF_AHB_ICR_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                             /*  PortF[4, 0] => IC: Interrupt Clear -> Interrupt unaffected */
    GPIO_PORTF_AHB_IM_R &= ~(GPIO_PIN_4 | GPIO_PIN_0);                              /*  PortF[4, 0] => IME: Interrupt Mask Enable -> Interrupt masked */

    /**
     * Configuración de la interrupción
     */
    
    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    /*  Paso 2: Habilitar la interrupción (ENn) */

}


void GPIO_PortJ_Init(void) {

    /**
     * Configuración del GPIO
     */

    /*  Paso 1: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R8;                                        /*  R8: GPIO PortJ Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R8)) {}                                /*  R8: GPIO PortJ Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 2: Configurar la dirección del GPIO (GPIODIR) */
    GPIO_PORTJ_AHB_DIR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1:0] => DIR: Data direction -> Input */

    /*  Paso 3: Deshabilitar la función alterna del GPIO (GPIOAFSEL) */
    GPIO_PORTJ_AHB_AFSEL_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                           /*  PortJ[1:0] => AFSEL: Alternate Function Select -> GPIO */

    /*  Paso 4: Configurar los modos de controlador extendidos (GPIOPC) */
    uint32_t reg = GPIO_PORTJ_AHB_PC_R;
    reg &= ~(GPIO_PC_EDM1_M | GPIO_PC_EDM0_M);                                      /*  PortJ[1:0] => EDM: Extended Drive Mode -> Bits cleared */
    reg |= ((0 << GPIO_PC_EDM1_M) | (0 << GPIO_PC_EDM0_S));                         /*  PortJ[1:0] => EDM: Extended Drive Mode -> Drive values of 2, 4 and 8mA are maintained */
    GPIO_PORTJ_AHB_PC_R = reg;

    /*  Paso 5: Configurar el driver de 4mA del GPIO (GPIODR4R) */
    GPIO_PORTJ_AHB_DR4R_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                            /*  PortJ[1:0] => DRV4: Output Pad 4mA Drive Enable -> Controlled by GPIODR2R or GPIODR8R */

    /*  Paso 6: Configurar el driver de 8mA del GPIO (GPIODR8R) */
    GPIO_PORTJ_AHB_DR8R_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                            /*  PortJ[1:0] => DRV8: Output Pad 8mA Drive Enable -> Controlled by GPIODR2R or GPIODR4R */

    /*  Paso 7: Configurar el driver de 12mA del GPIO (GPIODR12R) */
    GPIO_PORTJ_AHB_DR12R_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                           /*  PortJ[1:0] => DRV12: Output Pad 12mA Drive Enable -> Controlled by GPIODR2R, GPIODR4R and/or GPIODR8R */

    /*  Paso 8: Configurar como Open Drain (GPIOODR) o las resistencias de Pull-Up (GPIOPUR) / Pull-Down (GPIOPDR) */
    GPIO_PORTJ_AHB_ODR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1:0] => ODE: Output Pad Open Drain Enable -> Disabled */
    GPIO_PORTJ_AHB_PUR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => PUE: Pad Weak Pull-Up Enable -> Enabled */
    GPIO_PORTJ_AHB_PDR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1:0] => PDE: Pad Weak Pull-Down Enable -> Disabled */

    /*  Paso 9: Habilitar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTJ_AHB_DEN_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => DEN: Digital Enable -> Enabled */

    /*  Paso 10: Para uso de interrupción, configurar la sensibilidad (GPIOIS), el evento (GPIOIBE y GPIOIEV), limpiar la bandera de interrupción (GPIOICR) y desenmascarar la interrupción (GPIOIM) */
    GPIO_PORTJ_AHB_IS_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => IS: Interrupt Sense -> Edge-sensitive */
    GPIO_PORTJ_AHB_IBE_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1:0] => IBE: Interrupt Both Edges -> Controlled by GPIOIEV */
    GPIO_PORTJ_AHB_IEV_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortJ[1:0] => IEV: Interrupt Event -> Falling edge */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => IC: Interrupt Clear -> Interrupt cleared */
    GPIO_PORTJ_AHB_IM_R |= (GPIO_PIN_1 | GPIO_PIN_0);                               /*  PortJ[1:0] => IME: Interrupt Mask Enable -> Interrupt unmasked */

    /**
     * Configuración de la interrupción
     */
    
    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    reg = NVIC_PRI12_R;
    reg &= ~NVIC_PRI12_INT51_M;                                                     /*  Interrupt 51 (PortJ) => INTD: Interrupt Priority -> Bits cleared */
    reg |= (0 << NVIC_PRI12_INT51_S);                                               /*  Interrupt 51 (PortJ) => INTD: Interrupt Priority -> 0 */
    NVIC_PRI12_R = reg;

    /*  Paso 2: Habilitar la interrupción (ENn) */
    NVIC_EN1_R |= (1 << (51 - 32));                                                 /*  Interrupt 51 (PortJ) => INT: Interrupt Enable -> Enabled */
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
