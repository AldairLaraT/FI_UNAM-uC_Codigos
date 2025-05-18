/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de mayo de 2025
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

extern uint32_t PWM_DutyCycle;


/*********************************************************************************
 * Funciones
 */

void GPIO_PortJ_Handler(void){

    /*  Retardo de rebote */
    GPTM0_A_Initiate();                                                             /*  GPTM0 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */
    GPTM0_A_RawInterrupt_TimeOut_wait();                                            /*  GPTM0 => TATORIS: GPTM Timer A Time-Out Raw Interrupt -> Timer A has timed out */
    GPTM0_A_ClearFlags_TimeOut();                                                   /*  GPTM0 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */

    if (SW1_Pressed) {                                                              /*  Validación del SW1 */
        if (PWM_DutyCycle < 14400) {
            PWM_DutyCycle += 1600;                                                  /*  Incremento del 10% del ciclo de trabajo */
        }
    }

    if (SW2_Pressed) {                                                              /*  Validación del SW2 */
        if (PWM_DutyCycle > 1600) {
            PWM_DutyCycle -= 1600;                                                  /*  Decremento del 10% del ciclo de trabajo */
        }
    }

    TIMER2_TAMATCHR_R = (PWM_DutyCycle & 0x0000FFFF);                               /*  GPTM2 => TAMR: GPTM Timer A Match Register */
    TIMER2_TAPMR_R = ((PWM_DutyCycle & 0x00FF0000) >> 16);                          /*  GPTM2 => TAPSMR: GPTM Timer A Prescale Match */

    /*  Limpiar la bandera de interrupción (GPIOICR) */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => IC: Interrupt Clear -> Interrupt cleared */
}
