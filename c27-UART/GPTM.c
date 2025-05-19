/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de mayo de 2025
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

void GPTM0A_Init_OneShot(uint32_t LoadValue) {

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
    TIMER0_TAILR_R = (LoadValue & 0x0000FFFF);                                      /*  GPTM0 => TAILR: GPTM Timer A Interval Load Register -> Loads the counter for Timer A */
    TIMER0_TAPR_R = ((LoadValue & 0x00FF0000) >> 16);                               /*  GPTM0 => TAPSR: GPTM Timer A Prescale -> Loads the prescaler for Timer A */

    /*  Paso 6: Para uso de interrupción, desenmascarar la interrupción (GPTMIMR) */
    TIMER0_IMR_R &= ~TIMER_IMR_TATOIM;                                              /*  GPTM0 => TATOIM: GPTM Timer A Time-Out Interrupt Mask -> Interrupt masked */

    /**
     * Configuración de la interrupción
     */

    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    /*  Paso 2: Habilitar la interrupción (ENn) */

}
