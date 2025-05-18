/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       03 de mayo de 2025
 * 
 * Código:      Archivo fuente del NVIC
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "GPTM.h"                                                                   /*  Archivo de cabecera del GPTM */
#include "NVIC.h"                                                                   /*  Archivo de cabecera del NVIC */


/*********************************************************************************
 * Variables globales
 */

extern uint16_t ReloadStep;
extern uint32_t TIMER2_TimeoutValue;
extern float ReactionTime_ms;


/*********************************************************************************
 * Funciones
 */

void TIMER1_A_Handler(void){

    GPTM1_A_ClearFlags_TimeOut();                                                   /*  GPTM1 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */

    LED_D1_Off();

    TIMER2_TAILR_R = TIMER2_TimeoutValue;                                           /*  GPTM2 => TAILR: GPTM Timer A Interval Load Register -> Loads the counter for Timer A */
    GPTM2_A_Initiate();                                                             /*  GPTM2 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */
}


void TIMER2_A_Handler(void){

    GPTM2_A_ClearFlags_TimeOut();                                                   /*  GPTM2 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */

    LED_D4_On();

    NVIC_DIS0_R |= (1 << (21 - 0));                                                 /*  Interrupt 21 (TIMER 1 subtimer A) => INT: Interrupt Disable -> INT bit (EN0) cleared */
    NVIC_DIS0_R |= (1 << (23 - 0));                                                 /*  Interrupt 23 (TIMER 2 subtimer A) => INT: Interrupt Disable -> INT bit (EN0) cleared */
    NVIC_DIS1_R |= (1 << (51 - 32));                                                /*  Interrupt 51 (PortJ) => INT: Interrupt Disable -> INT bit (EN1) cleared */
}


void GPIO_PortJ_Handler(void){

    /*  Retardo de rebote */
    GPTM0_A_Initiate();                                                             /*  GPTM0 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */
    GPTM0_A_RawInterrupt_TimeOut_wait();                                            /*  GPTM0 => TATORIS: GPTM Timer A Time-Out Raw Interrupt -> Timer A has timed out */
    GPTM0_A_ClearFlags_TimeOut();                                                   /*  GPTM0 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */

    if (SW1_Pressed) {                                                              /*  Validación del SW1 */
        LED_D1_On();
        LED_D2_Off();
        LED_D3_Off();
        LED_D4_Off();

        uint32_t TIMER1_Reload = ReloadStep * 100000;
        TIMER1_TAILR_R = (TIMER1_Reload & TIMER_TAILR_M);                           /*  GPTM1 => TAILR: GPTM Timer A Interval Load Register -> Loads the counter for Timer A */
        GPTM1_A_Initiate();                                                         /*  GPTM1 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */
    }

    if (SW2_Pressed) {                                                              /*  Validación del SW2 */
        GPTM2_A_Stop();                                                             /*  GPTM2 => TAEN: GPTM Timer A Enable -> Disabled */
        uint32_t TIMER2_CurrentValue = TIMER2_TAR_R;                                /*  GPTM2 => TAR: GPTM Timer A Register -> Returns the current value of the GPTM Timer A Count Register */
        TIMER2_TAV_R = 0;                                                           /*  GPTM2 => TAV: GPTM Timer A Value -> Loads the GPTMTAR on the next clock cycle */

        ReactionTime_ms = (float)TIMER2_CurrentValue / 16000;

        if (ReactionTime_ms == 0) {
            LED_D1_Off();
            LED_D4_On();
            NVIC_DIS0_R |= (1 << (21 - 0));                                         /*  Interrupt 21 (TIMER 1 subtimer A) => INT: Interrupt Disable -> INT bit (EN0) cleared */
            NVIC_DIS0_R |= (1 << (23 - 0));                                         /*  Interrupt 23 (TIMER 2 subtimer A) => INT: Interrupt Disable -> INT bit (EN0) cleared */
            NVIC_DIS1_R |= (1 << (51 - 32));                                        /*  Interrupt 51 (PortJ) => INT: Interrupt Disable -> INT bit (EN1) cleared */
        }
        else if (ReactionTime_ms < 180) {
            LED_D1_On();
            LED_D2_On();
            LED_D3_On();
            LED_D4_On();
        }
        else if (ReactionTime_ms < 220) {
            LED_D1_On();
            LED_D2_On();
            LED_D3_On();
        }
        else if (ReactionTime_ms < 260) {
            LED_D1_On();
            LED_D2_On();
        }
        else if (ReactionTime_ms < 300) {
            LED_D1_On();
        }
    }

    /*  Limpiar la bandera de interrupción (GPIOICR) */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => IC: Interrupt Clear -> Interrupt cleared */
}
