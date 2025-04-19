/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Tema 09:     Periféricos
 * Código 18:   ADC: Dos canales
 * Descripción: Configuración del ADC0, empleando el secuenciador de muestras SS0
 *              para leer el valor de dos potenciómetros con las entradas analógicas
 *              AIN10 (PB4) y AIN17 (PK1).
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */
#include "ADC.h"                                                                    /*  Macros para el uso de ADC */
#include "GPIO.h"                                                                   /*  Macros para el uso de GPIO */
#include "NVIC.h"                                                                   /*  Macros para el uso de NVIC */
#include "SYSCTL.h"                                                                 /*  Macros para el uso de SYSCTL */
#include "SysTick.h"                                                                /*  Macros para el uso de SysTick */


/*********************************************************************************
 * Variables globales
 */

uint32_t Bounce_Delay = 100000;                                                     /*  Valor de carga del SysTick para un retardo de rebote de 25ms (f = 4MHz) */
uint16_t ADC0_SS0_ain10;
uint16_t ADC0_SS0_ain17;
float temperature;
uint8_t LED_control_flag = 0;
uint16_t LED_control;


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortF_Init();                                                              /*  Inicialización del GPIO PortF */
    GPIO_PortJ_Init();                                                              /*  Inicialización del GPIO PortJ */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */
    ADC0_SS0_Init();                                                                /*  Inicialización del ADC0 SS0 */

    uint16_t limit1 = 800;
    uint16_t limit2 = 1600;
    uint16_t limit3 = 2400;
    uint16_t limit4 = 3200;

    while(1) {

        ADC0_SS0_Initiate();                                                        /*  ADC0 => SS0 Initiate -> Begin sampling on SS0 */
        ADC0_SS0_RawInterrupt_wait();                                               /*  Esperar la interrupción cruda del ADC0 SS0 */
        ADC0_SS0_ain10 = ADC0_SS0_FIFOread();                                       /*  ADC0 => SS0 -> Lectura del resultado de conversión */
        ADC0_SS0_ain17 = ADC0_SS0_FIFOread();                                       /*  ADC0 => SS0 -> Lectura del resultado de conversión */
        uint16_t temp_RawData = ADC0_SS0_FIFOread();                                /*  ADC0 => SS0 -> Lectura del resultado de conversión */
        ADC0_SS0_ClearFlags();                                                      /*  ADC0 => Limpieza de las banderas IN0 (ADCISC) y INR0 (ADCRIS) */

        temperature = 147.5 - ((75 * (3.3 - 0) * temp_RawData) / 4096);             /*  pp1068  Conversión de los datos crudos (raw data) a °C */

        if (LED_control_flag == 0) {
            LED_control = ADC0_SS0_ain10;
        }
        else {
            LED_control = ADC0_SS0_ain17;
        }

        if (LED_control < limit1) {
            LED_D1_Off();
            LED_D2_Off();
            LED_D3_Off();
            LED_D4_Off();
        }
        else if (LED_control < limit2) {
            LED_D1_On();
            LED_D2_Off();
            LED_D3_Off();
            LED_D4_Off();
        }
        else if (LED_control < limit3) {
            LED_D1_On();
            LED_D2_On();
            LED_D3_Off();
            LED_D4_Off();
        }
        else if (LED_control < limit4) {
            LED_D1_On();
            LED_D2_On();
            LED_D3_On();
            LED_D4_Off();
        }
        else {
            LED_D1_On();
            LED_D2_On();
            LED_D3_On();
            LED_D4_On();
        }
    }
}
