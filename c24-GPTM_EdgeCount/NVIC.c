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
 * Funciones
 */

void TIMER0_A_Handler(void){

    GPTM0_A_ClearFlags_EdgeCount();                                                 /*  GPTM0 => CAMCINT: GPTM Timer A Capture Mode Match Interrupt Clear -> CAMRIS bit (GPTMRIS) and CAMMIS bit (GPTMMIS) cleared */

    LED_D1_Toggle();

}


void TIMER0_B_Handler(void){

    GPTM0_B_ClearFlags_EdgeCount();                                                 /*  GPTM0 => CBMCINT: GPTM Timer B Capture Mode Match Interrupt Clear -> CBMRIS bit (GPTMRIS) and CBMMIS bit (GPTMMIS) cleared */

    LED_D2_Toggle();

}
