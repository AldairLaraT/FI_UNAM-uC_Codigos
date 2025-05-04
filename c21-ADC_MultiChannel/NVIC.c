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

#include "ADC.h"                                                                    /*  Archivo de cabecera del ADC */
#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "NVIC.h"                                                                   /*  Archivo de cabecera del NVIC */
#include "SysTick.h"                                                                /*  Archivo de cabecera del SysTick */


/*********************************************************************************
 * Variables globales
 */

extern uint8_t LED_control_flag;
extern uint16_t ADC0_SS0_ain10;
extern uint16_t ADC0_SS0_ain17;
extern uint16_t temp_RawData;
extern uint32_t Bounce_Delay;


/*********************************************************************************
 * Funciones
 */

void ADC0_SS0_Handler(void) {

    ADC0_SS0_ain10 = ADC0_SS0_FIFOread();                                           /*  ADC0 SS0 => DATA: Conversion Result Data */
    ADC0_SS0_ain17 = ADC0_SS0_FIFOread();                                           /*  ADC0 SS0 => DATA: Conversion Result Data */
    temp_RawData = ADC0_SS0_FIFOread();                                             /*  ADC0 SS0 => DATA: Conversion Result Data */

    ADC0_SS0_ClearFlags();                                                          /*  ADC0 => IN0: SS0 Interrupt Status and Clear -> IN0 bit (ADCISC) and INR0 bit (ADCRIS) cleared */
    ADC0_SS0_Initiate();                                                            /*  ADC0 => SS0 Initiate -> Begin sampling on SS0 */

}


void GPIO_PortJ_Handler(void) {

    SysTick_Init_OneShot(Bounce_Delay);                                             /*  Inicialización del SysTick en modo One-Shot para el retardo de rebote */
    SysTick_wait();                                                                 /*  SysTick => COUNT: Count Flag -> The SysTick timer has counted to 0 */

    if (SW1_Pressed) {                                                              /*  Validación del SW1 */
        LED_control_flag = 0;
    }

    if (SW2_Pressed) {                                                              /*  Validación del SW2 */
        LED_control_flag = 1;
    }

    /*  Limpiar la bandera de interrupción (GPIOICR) */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => IC: Interrupt Clear -> Interrupt cleared */

}
