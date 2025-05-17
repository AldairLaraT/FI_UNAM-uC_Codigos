/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       17 de mayo de 2025
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

    /*  Habilitar la señal de reloj del GPTM (RCGCTIMER) y esperar a que se estabilice (PRTIMER) */
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0;                                      /*  R0: GPTM0 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRTIMER_R & SYSCTL_PRTIMER_R0)) {}                              /*  R0: GPTM0 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 1: Deshabilitar el GPTM (GPTMCTL) */
    TIMER0_CTL_R &= ~TIMER_CTL_TAEN;                                                /*  GPTM0 => TAEN: GPTM Timer A Enable -> Disabled */

    /*  Paso 2: Configurar el modo de operación del GPTM (GPTMCFG) */
    TIMER0_CFG_R = ((TIMER0_CFG_R & ~TIMER_CFG_M) | TIMER_CFG_16_BIT);              /*  GPTM0 => GPTMCFG: GPTM Configuration -> 16-bit timer */

    /*  Paso 3: Seleccionar el modo one-shot o periódico (GPTMTnMR) */
    /*  Paso 4: Configurar el modo de operación adecuado (GPTMTnMR) */
    uint32_t reg = TIMER0_TAMR_R;
    reg &= ~TIMER_TAMR_TACDIR;                                                      /*  GPTM0 => TACDIR: GPTM Timer A Count Direction -> The timer counts down */
    reg = ((reg & ~TIMER_TAMR_TAMR_M) | TIMER_TAMR_TAMR_1_SHOT);                    /*  GPTM0 => TAMR: GPTM Timer A Mode -> One-Shot Timer mode */
    TIMER0_TAMR_R = reg;

    /*  Paso 5: Cargar el valor inicial del GPTM (GPTMTnILR) */
    /*  Si se utiliza el preescalador, cargar el valor inicial del GPTM (GPTMTnPR) */
    TIMER0_TAILR_R = (LoadValue & 0x0000FFFF);                                      /*  GPTM0 => TAILR: GPTM Timer A Interval Load */
    TIMER0_TAPR_R = ((LoadValue & 0x00FF0000) >> 16);                               /*  GPTM0 => TAPSR: GPTM Timer A Prescale */

    /*  Paso 6: Para uso de interrupción, desenmascarar la interrupción (GPTMIMR) */
    TIMER0_IMR_R |= TIMER_IMR_TATOIM;                                               /*  GPTM0 => TATOIM: GPTM Timer A Time-Out Interrupt Mask -> Interrupt masked */

    /**
     * Configuración de la interrupción
     */

    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    reg = NVIC_PRI4_R;
    reg &= ~NVIC_PRI4_INT19_M;                                                      /*  Interrupt 19 (TIMER 0 subtimer A) => INTD: Interrupt Priority -> Bits cleared */
    reg |= (0 << NVIC_PRI4_INT19_S);                                                /*  Interrupt 19 (TIMER 0 subtimer A) => INTD: Interrupt Priority -> 0 */
    NVIC_PRI4_R = reg;

    /*  Paso 2: Habilitar la interrupción (ENn) */
    NVIC_EN0_R |= (1 << (19 - 0));                                                  /*  Interrupt 19 (TIMER 0 subtimer A) => INT: Interrupt Enable -> Enabled */

}


void GPTM0B_Init_EdgeTime(uint32_t LoadValue){

    /**
     * Configuración del GPTM
     */

    /*  Habilitar la señal de reloj del GPTM (RCGCTIMER) y esperar a que se estabilice (PRTIMER) */
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0;                                      /*  R0: GPTM0 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRTIMER_R & SYSCTL_PRTIMER_R0)) {}                              /*  R0: GPTM0 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 1: Deshabilitar el GPTM (GPTMCTL) */
    TIMER0_CTL_R &= ~TIMER_CTL_TBEN;                                                /*  GPTM0 => TBEN: GPTM Timer B Enable -> Disabled */

    /*  Paso 2: Configurar el modo de operación del GPTM (GPTMCFG) */
    TIMER0_CFG_R = ((TIMER0_CFG_R & ~TIMER_CFG_M) | TIMER_CFG_16_BIT);              /*  GPTM0 => GPTMCFG: GPTM Configuration -> 16-bit timer */

    /*  Paso 3: Configurar el modo captura (GPTMTnMR) */
    uint32_t reg = TIMER0_TBMR_R;
    reg |= TIMER_TBMR_TBCDIR;                                                       /*  GPTM0 => TBCDIR: GPTM Timer B Count Direction -> The timer counts up */
    reg &= ~TIMER_TBMR_TBAMS;                                                       /*  GPTM0 => TBAMS: GPTM Timer B Alternate Mode Select -> Capture or compare mode is enabled */
    reg |= TIMER_TBMR_TBCMR;                                                        /*  GPTM0 => TBCMR: GPTM Timer B Capture Mode -> Edge-Time mode */
    reg = ((reg & ~TIMER_TBMR_TBMR_M) | TIMER_TBMR_TBMR_CAP);                       /*  GPTM0 => TBMR: GPTM Timer B Mode -> Capture mode */
    TIMER0_TBMR_R = reg;

    /*  Paso 4: Configurar el tipo de eventos de captura del GPTM (GPTMCTL) */
    TIMER0_CTL_R = ((TIMER0_CTL_R & ~TIMER_CTL_TBEVENT_M) | TIMER_CTL_TBEVENT_NEG); /*  GPTM0 => TBEVENT: GPTM Timer B Event Mode -> Negative edge */

    /*  Paso 5: Cargar el valor del preescalador (GPTMTnPR) */
    TIMER0_TBPR_R = ((LoadValue & 0x00FF0000) >> 16);                               /*  GPTM0 => TBPSR: GPTM Timer B Prescale */

    /*  Paso 6: Cargar el valor inicial (GPTMTnILR) */
    TIMER0_TBILR_R = (LoadValue & 0x0000FFFF);                                      /*  GPTM0 => TBILR: GPTM Timer B Interval Load */

    /*  Paso 7: Para uso de interrupción, desenmascarar la interrupción (GPTMIMR) */
    TIMER0_IMR_R |= TIMER_IMR_CBEIM;                                                /*  GPTM0 => CBEIM: GPTM Timer B Capture Mode Event Interrupt Mask -> Interrupt unmasked */

    /**
     * Configuración de la interrupción
     */

    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    reg = NVIC_PRI5_R;
    reg &= ~NVIC_PRI5_INT20_M;                                                      /*  Interrupt 20 (TIMER 0 subtimer B) => INTA: Interrupt Priority -> Bits cleared */
    reg |= (0 << NVIC_PRI5_INT20_S);                                                /*  Interrupt 20 (TIMER 0 subtimer B) => INTA: Interrupt Priority -> 0 */
    NVIC_PRI5_R = reg;

    /*  Paso 2: Habilitar la interrupción (ENn) */
    NVIC_EN0_R |= (1 << (20 - 0));                                                  /*  Interrupt 20 (TIMER 0 subtimer B) => INT: Interrupt Enable -> Enabled */

}


void GPTM1A_Init_OneShot(uint32_t LoadValue){

    /**
     * Configuración del GPTM
     */

    /*  Habilitar la señal de reloj del GPTM (RCGCTIMER) y esperar a que se estabilice (PRTIMER) */
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R1;                                      /*  R1: GPTM1 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRTIMER_R & SYSCTL_PRTIMER_R1)) {}                              /*  R1: GPTM1 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 1: Deshabilitar el GPTM (GPTMCTL) */
    TIMER1_CTL_R &= ~TIMER_CTL_TAEN;                                                /*  GPTM1 => TAEN: GPTM Timer A Enable -> Disabled */

    /*  Paso 2: Configurar el modo de operación del GPTM (GPTMCFG) */
    TIMER1_CFG_R = ((TIMER1_CFG_R & ~TIMER_CFG_M) | TIMER_CFG_16_BIT);              /*  GPTM1 => GPTMCFG: GPTM Configuration -> 16-bit timer */

    /*  Paso 3: Seleccionar el modo one-shot o periódico (GPTMTnMR) */
    /*  Paso 4: Configurar el modo de operación adecuado (GPTMTnMR) */
    uint32_t reg = TIMER1_TAMR_R;
    reg &= ~TIMER_TAMR_TACDIR;                                                      /*  GPTM1 => TACDIR: GPTM Timer A Count Direction -> The timer counts down */
    reg = ((reg & ~TIMER_TAMR_TAMR_M) | TIMER_TAMR_TAMR_1_SHOT);                    /*  GPTM1 => TAMR: GPTM Timer A Mode -> One-Shot Timer mode */
    TIMER1_TAMR_R = reg;

    /*  Paso 5: Cargar el valor inicial del GPTM (GPTMTnILR) */
    /*  Si se utiliza el preescalador, cargar el valor inicial del GPTM (GPTMTnPR) */
    TIMER1_TAILR_R = (LoadValue & 0x0000FFFF);                                      /*  GPTM1 => TAILR: GPTM Timer A Interval Load */
    TIMER1_TAPR_R = ((LoadValue & 0x00FF0000) >> 16);                               /*  GPTM1 => TAPSR: GPTM Timer A Prescale */

    /*  Paso 6: Para uso de interrupción, desenmascarar la interrupción (GPTMIMR) */
    TIMER1_IMR_R &= ~TIMER_IMR_TATOIM;                                              /*  GPTM1 => TATOIM: GPTM Timer A Time-Out Interrupt Mask -> Interrupt masked */

    /**
     * Configuración de la interrupción
     */

    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    /*  Paso 2: Habilitar la interrupción (ENn) */

}
