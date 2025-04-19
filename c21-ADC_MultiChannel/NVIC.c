/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Código:      Archivo fuente del NVIC
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "ADC.h"                                                                    /*  Macros para el uso de ADC */
#include "GPIO.h"                                                                   /*  Macros para el uso de GPIO */
#include "NVIC.h"                                                                   /*  Macros para el uso de NVIC */
#include "SysTick.h"                                                                /*  Macros para el uso de SysTick */


/*********************************************************************************
 * Variables globales
 */

extern uint32_t Bounce_Delay;
extern uint8_t LED_control_flag;
extern uint16_t ADC0_SS0_ain10;
extern uint16_t ADC0_SS0_ain17;
extern uint16_t temp_RawData;


/*********************************************************************************
 * Funciones
 */

void ADC0_SS0_Handler(void) {

    ADC0_SS0_ain10 = ADC0_SS0_FIFOread();                                           /*  ADC0 => SS0 -> Lectura del resultado de conversión */
    ADC0_SS0_ain17 = ADC0_SS0_FIFOread();                                           /*  ADC0 => SS0 -> Lectura del resultado de conversión */
    temp_RawData = ADC0_SS0_FIFOread();                                             /*  ADC0 => SS0 -> Lectura del resultado de conversión */

    ADC0_SS0_ClearFlags();                                                          /*  ADC0 => Limpieza de las banderas IN0 (ADCISC) y INR0 (ADCRIS) */
    ADC0_SS0_Initiate();                                                            /*  ADC0 => SS0 Initiate -> Begin sampling on SS0 */

}


void GPIOPortJ_Handler(void) {

    SysTick_OneShot_Init(Bounce_Delay);                                             /*  Inicialización del SysTick en modo OneShot para el retardo de rebote */
    SysTick_wait();                                                                 /*  Esperar a que el SysTick termine la cuenta */

    if (SW1_Pressed) {                                                              /*  Validación del SW1 */
        LED_control_flag = 0;
    }

    if (SW2_Pressed) {                                                              /*  Validación del SW2 */
        LED_control_flag = 1;
    }

    /*  Limpiar la bandera de interrupción (GPIOICR) */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => IC: Interrupt Clear -> Interrupt cleared */

}
