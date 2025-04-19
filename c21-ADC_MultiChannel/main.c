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
#include "SYSCTL.h"                                                                 /*  Macros para el uso de SYSCTL */


/*********************************************************************************
 * Variables globales
 */

uint16_t ADC0_SS0_ain10;
uint16_t ADC0_SS0_ain17;
float temperature;


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortF_Init();                                                              /*  Inicialización del GPIO PortF */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */
    ADC0_SS0_Init();                                                                /*  Inicialización del ADC0 SS0 */

    while(1) {

        ADC0_SS0_Initiate();                                                        /*  ADC0 => SS0 Initiate -> Begin sampling on SS0 */
        ADC0_SS0_RawInterrupt_wait();                                               /*  Esperar la interrupción cruda del ADC0 SS0 */
        ADC0_SS0_ain10 = ADC0_SS0_FIFOread();                                       /*  ADC0 => SS0 -> Lectura del resultado de conversión */
        ADC0_SS0_ain17 = ADC0_SS0_FIFOread();                                       /*  ADC0 => SS0 -> Lectura del resultado de conversión */
        uint16_t temp_RawData = ADC0_SS0_FIFOread();                                /*  ADC0 => SS0 -> Lectura del resultado de conversión */
        ADC0_SS0_ClearFlags();                                                      /*  ADC0 => Limpieza de las banderas IN0 (ADCISC) y INR0 (ADCRIS) */

        temperature = 147.5 - ((75 * (3.3 - 0) * temp_RawData) / 4096);             /*  pp1068  Conversión de los datos crudos (raw data) a °C */

    }
}
