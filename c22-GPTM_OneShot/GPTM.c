/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       03 de mayo de 2025
 * 
 * Código:      Archivo fuente del GPTM
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "GPTM.h"                                                                   /*  Archivo de cabecera del GPTM */
#include "NVIC.h"                                                                   /*  Archivo de cabecera del NVIC */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */


/*********************************************************************************
 * Funciones
 */

void GPTM0A_Init_OneShot(uint32_t LoadValue){

    /**
     * Configuración del GPTM
     */

    /*  Habilitar la señal de reloj del GPTM (RCGCGPTM) y esperar a que se estabilice (PRGPTM) */
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0;                                      /*  R0: GPTM0 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRTIMER_R & SYSCTL_PRTIMER_R0)) {}                              /*  R0: GPTM0 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 1: Deshabilitar el GPTM (GPTMCTL) */
    TIMER0_CTL_R &= ~TIMER_CTL_TAEN;                                                /*  GPTM0 => TAEN: GPTM Timer A Enable -> Disabled */

    /*  Paso 2: Configurar el modo de operación del GPTM (GPTMCFG) */
    TIMER0_CFG_R = ((TIMER0_CFG_R & ~TIMER_CFG_M) | TIMER_CFG_16_BIT);              /*  GPTM0 => GPTMCFG: GPTM Configuration -> 16-bit timer */

    /*  Paso 3: Configurar (GPTMTnMR) */
    /*  Paso 4: Seleccionar el modo (GPTMTnMR) */
    uint32_t reg = TIMER0_TAMR_R;
    reg &= ~TIMER_TAMR_TACDIR;                                                      /*  GPTM0 => TACDIR: GPTM Timer A Count Direction -> The timer counts down */
    reg = ((reg & ~TIMER_TAMR_TAMR_M) | TIMER_TAMR_TAMR_1_SHOT);                    /*  GPTM0 => TAMR: GPTM Timer A Mode -> One-Shot Timer mode */
    TIMER0_TAMR_R = reg;

    /*  Paso 5: Cargar el valor inicial del GPTM (GPTMTnILR) */
    /*  Si se utiliza el preescalador, cargar el valor inicial del GPTM (GPTMTnPR) */
    TIMER0_TAILR_R = (LoadValue & 0x0000FFFF);                                      /*  GPTM0 => TAILR: GPTM Timer A Interval Load */
    TIMER0_TAPR_R = ((LoadValue & 0x00FF0000) >> 16);                               /*  GPTM0 => TAPSR: GPTM Timer A Prescale */

    /*  Paso 6: Para uso de interrupción, desenmascarar la interrupción (GPTMIMR) */
    TIMER0_IMR_R &= ~TIMER_IMR_TATOIM;                                              /*  GPTM0 => TATOIM: GPTM Timer A Time-Out Interrupt Mask -> Interrupt masked */

    /**
     * Configuración de la interrupción
     */

    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    /*  Paso 2: Habilitar la interrupción (ENn) */

}


void GPTM1AB_Init_OneShot(uint32_t LoadValue){

    /**
     * Configuración del GPTM
     */

    /*  Habilitar la señal de reloj del GPTM (RCGCGPTM) y esperar a que se estabilice (PRGPTM) */
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R1;                                      /*  R1: GPTM1 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRTIMER_R & SYSCTL_PRTIMER_R1)) {}                              /*  R1: GPTM1 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 1: Deshabilitar el GPTM (GPTMCTL) */
    TIMER1_CTL_R &= ~TIMER_CTL_TAEN;                                                /*  GPTM1 => TAEN: GPTM Timer A Enable -> Disabled */

    /*  Paso 2: Configurar el modo de operación del GPTM (GPTMCFG) */
    TIMER1_CFG_R = ((TIMER1_CFG_R & ~TIMER_CFG_M) | TIMER_CFG_32_BIT_TIMER);        /*  GPTM1 => GPTMCFG: GPTM Configuration -> 32-bit timer */

    /*  Paso 3: Configurar (GPTMTnMR) */
    /*  Paso 4: Seleccionar el modo (GPTMTnMR) */
    uint32_t reg = TIMER1_TAMR_R;
    reg |= TIMER_TAMR_TACDIR;                                                       /*  GPTM1 => TACDIR: GPTM Timer A Count Direction -> The timer counts up */
    reg = ((reg & ~TIMER_TAMR_TAMR_M) | TIMER_TAMR_TAMR_1_SHOT);                    /*  GPTM1 => TAMR: GPTM Timer A Mode -> One-Shot Timer mode */
    TIMER1_TAMR_R = reg;

    /*  Paso 5: Cargar el valor inicial del GPTM (GPTMTnILR) */
    /*  Si se utiliza el preescalador, cargar el valor inicial del GPTM (GPTMTnPR) */
    TIMER1_TAILR_R = (LoadValue & TIMER_TAILR_M);                                   /*  GPTM1 => TAILR: GPTM Timer A Interval Load */

    /*  Paso 6: Para uso de interrupción, desenmascarar la interrupción (GPTMIMR) */
    TIMER1_IMR_R |= TIMER_IMR_TATOIM;                                              /*  GPTM1 => TATOIM: GPTM Timer A Time-Out Interrupt Mask -> Interrupt unmasked */

    /**
     * Configuración de la interrupción
     */

    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    reg = NVIC_PRI5_R;
    reg &= ~NVIC_PRI5_INT21_M;
    reg |= (1 << NVIC_PRI5_INT21_S);
    NVIC_PRI5_R = reg;

    /*  Paso 2: Habilitar la interrupción (ENn) */
    NVIC_EN0_R |= (1 << (21 - 0));

}


void GPTM2AB_Init_OneShot(uint32_t LoadValue){

    /**
     * Configuración del GPTM
     */

    /*  Habilitar la señal de reloj del GPTM (RCGCGPTM) y esperar a que se estabilice (PRGPTM) */
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R2;                                      /*  R2: GPTM2 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRTIMER_R & SYSCTL_PRTIMER_R2)) {}                              /*  R2: GPTM2 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 1: Deshabilitar el GPTM (GPTMCTL) */
    TIMER2_CTL_R &= ~TIMER_CTL_TAEN;                                                /*  GPTM2 => TAEN: GPTM Timer A Enable -> Disabled */

    /*  Paso 2: Configurar el modo de operación del GPTM (GPTMCFG) */
    TIMER2_CFG_R = ((TIMER2_CFG_R & ~TIMER_CFG_M) | TIMER_CFG_32_BIT_TIMER);        /*  GPTM2 => GPTMCFG: GPTM Configuration -> 32-bit timer */

    /*  Paso 3: Configurar (GPTMTnMR) */
    /*  Paso 4: Seleccionar el modo (GPTMTnMR) */
    uint32_t reg = TIMER2_TAMR_R;
    reg |= TIMER_TAMR_TACDIR;                                                       /*  GPTM2 => TACDIR: GPTM Timer A Count Direction -> The timer counts up */
    reg = ((reg & ~TIMER_TAMR_TAMR_M) | TIMER_TAMR_TAMR_1_SHOT);                    /*  GPTM2 => TAMR: GPTM Timer A Mode -> One-Shot Timer mode */
    TIMER2_TAMR_R = reg;

    /*  Paso 5: Cargar el valor inicial del GPTM (GPTMTnILR) */
    /*  Si se utiliza el preescalador, cargar el valor inicial del GPTM (GPTMTnPR) */
    TIMER2_TAILR_R = (LoadValue & TIMER_TAILR_M);                                   /*  GPTM2 => TAILR: GPTM Timer A Interval Load */

    /*  Paso 6: Para uso de interrupción, desenmascarar la interrupción (GPTMIMR) */
    TIMER2_IMR_R |= TIMER_IMR_TATOIM;                                               /*  GPTM2 => TATOIM: GPTM Timer A Time-Out Interrupt Mask -> Interrupt unmasked */

    /**
     * Configuración de la interrupción
     */

    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    reg = NVIC_PRI5_R;
    reg &= ~NVIC_PRI5_INT23_M;
    reg |= (2 << NVIC_PRI5_INT23_S);
    NVIC_PRI5_R = reg;

    /*  Paso 2: Habilitar la interrupción (ENn) */
    NVIC_EN0_R |= (1 << (23 - 0));

}
