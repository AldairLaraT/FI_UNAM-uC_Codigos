/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Tema 09:     Periféricos
 * Código 20:   ADC: Sensor de temperatura del TIVA
 * Descripción: Configuración del ADC1, empleando el secuenciador de muestras SS2
 *              para leer el valor del sensor de temperatura embebido en el TIVA.
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */
#include "ADC.h"                                                                    /*  Archivo de cabecera del ADC */
#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */
#include "SysTick.h"                                                                /*  Archivo de cabecera del SysTick */


/*********************************************************************************
 * Variables globales
 */

float temperature;


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortF_Init();                                                              /*  Inicialización del GPIO PortF */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */
    ADC1_SS2_Init();                                                                /*  Inicialización del ADC1 SS2 */

    uint32_t SysTick_Reload = 4000000;                                              /*  Valor de carga del SysTick (f = 4MHz) */
    SysTick_Init(SysTick_Reload);                                                   /*  Inicialización del SysTick */

    float temp_limit1 = 36.0f;
    float temp_limit2 = 37.0f;
    float temp_limit3 = 38.0f;
    float temp_limit4 = 39.0f;

    while(1) {

        ADC1_SS2_Initiate();                                                        /*  ADC0 => SS2 Initiate -> Begin sampling on SS2 */
        ADC1_SS2_RawInterrupt_wait();                                               /*  ADC1 => INR2: SS2 Raw Interrupt Status -> A sample has completed conversion */
        uint16_t temp_RawData = ADC1_SS2_FIFOread();                                /*  ADC1 SS2 => DATA: Conversion Result Data */
        ADC1_SS2_ClearFlags();                                                      /*  ADC1 => IN2: SS2 Interrupt Status and Clear -> IN2 bit (ADCISC) and INR2 bit (ADCRIS) cleared */

        temperature = 147.5 - ((75 * (3.3 - 0) * temp_RawData) / 4096);             /*  pp1068  Conversión de los datos crudos (raw data) a °C */

        if (temperature < temp_limit1) {
            LED_D1_Off();
            LED_D2_Off();
            LED_D3_Off();
            LED_D4_Off();
        }
        else if (temperature < temp_limit2) {
            LED_D1_On();
            LED_D2_Off();
            LED_D3_Off();
            LED_D4_Off();
        }
        else if (temperature < temp_limit3) {
            LED_D1_On();
            LED_D2_On();
            LED_D3_Off();
            LED_D4_Off();
        }
        else if (temperature < temp_limit4) {
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

        SysTick_wait()                                                              /*  SysTick => COUNT: Count Flag -> The SysTick timer has counted to 0 */

    }
}
