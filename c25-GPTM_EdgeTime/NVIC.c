/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       17 de mayo de 2025
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

extern int TIMER0B_Flag;
extern uint32_t TIMER0B_InitialValue;
extern uint32_t TIMER0B_FinalValue;
extern float Time_ms;


/*********************************************************************************
 * Funciones
 */

void TIMER0_A_Handler(void){

    GPTM0_A_ClearFlags_TimeOut();                                                   /*  GPTM0 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */

    TIMER0_CTL_R &= ~TIMER_CTL_TBEN;                                                /*  GPTM0 => TBEN: GPTM Timer B Enable -> Disabled */
    TIMER0_TBV_R = 0;

    LED_D1_Off();

}


void TIMER0_B_Handler(void){

    /*  Retardo de rebote */
    GPTM1_A_Initiate();                                                             /*  GPTM1 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */
    GPTM1_A_RawInterrupt_TimeOut_wait();                                            /*  GPTM1 => TATORIS: GPTM Timer A Time-Out Raw Interrupt -> Timer A has timed out */
    GPTM1_A_ClearFlags_TimeOut();                                                   /*  GPTM1 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */

    GPTM0_B_ClearFlags_EdgeTime();                                                  /*  GPTM0 => CBECINT: GPTM Timer B Capture Mode Event Interrupt Clear -> CBERIS bit (GPTMRIS) and CBEMIS bit (GPTMMIS) cleared */

    if (TIMER0B_Flag == 0) {
        TIMER0B_InitialValue = TIMER0_TBR_R;
        TIMER0B_Flag = 1;
    } else {
        TIMER0B_FinalValue = TIMER0_TBR_R;
        Time_ms = ((TIMER0B_FinalValue - TIMER0B_InitialValue) * (62.5)) / 1000000;
        TIMER0B_Flag = 0;
    }

}


void GPIO_PortJ_Handler(void){

    /*  Retardo de rebote */
    GPTM1_A_Initiate();                                                             /*  GPTM1 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */
    GPTM1_A_RawInterrupt_TimeOut_wait();                                            /*  GPTM1 => TATORIS: GPTM Timer A Time-Out Raw Interrupt -> Timer A has timed out */
    GPTM1_A_ClearFlags_TimeOut();                                                   /*  GPTM1 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */

    LED_D1_On();
    GPTM0_B_Initiate();                                                             /*  GPTM0 => TBEN: GPTM Timer B Enable -> Enabled and begins counting */
    GPTM0_A_Initiate();                                                             /*  GPTM0 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */

    /*  Limpiar la bandera de interrupción (GPIOICR) */
    GPIO_PORTJ_AHB_ICR_R |= GPIO_PIN_0;                                             /*  PortJ[0] => IC: Interrupt Clear -> Interrupt cleared */
}
