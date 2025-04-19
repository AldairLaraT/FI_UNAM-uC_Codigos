/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Tema 09:     Periféricos
 * Código 19:   ADC: Potenciómetro
 * Descripción: Configuración del ADC0, empleando el secuenciador de muestras SS1 
 *              para leer el valor de un potenciómetro con la entrada analógica 
 *              AIN10 (PB4) y encender los LED de la tarjeta de desarrollo.
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

uint16_t ADC0_SS1_ain10;


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortF_Init();                                                              /*  Inicialización del GPIO PortF */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */
    ADC0_SS1_Init();                                                                /*  Inicialización del ADC0 SS1 */

    uint16_t limit1 = 800;
    uint16_t limit2 = 1600;
    uint16_t limit3 = 2400;
    uint16_t limit4 = 3200;

    while(1) {

        ADC0_SS1_Initiate();                                                        /*  ADC0 => SS1 Initiate -> Begin sampling on SS1 */
        ADC0_SS1_RawInterrupt_wait();                                               /*  Esperar la interrupción cruda del ADC0 SS1 */
        ADC0_SS1_ain10 = ADC0_SS1_FIFOread();                                       /*  ADC0 => SS1 -> Lectura del resultado de conversión */
        ADC0_SS1_ClearFlags();                                                      /*  ADC0 => Limpieza de las banderas IN1 (ADCISC) y INR1 (ADCRIS) */

        if (ADC0_SS1_ain10 < limit1) {
            LED_D1_Off();
            LED_D2_Off();
            LED_D3_Off();
            LED_D4_Off();
        }
        else if (ADC0_SS1_ain10 < limit2) {
            LED_D1_On();
            LED_D2_Off();
            LED_D3_Off();
            LED_D4_Off();
        }
        else if (ADC0_SS1_ain10 < limit3) {
            LED_D1_On();
            LED_D2_On();
            LED_D3_Off();
            LED_D4_Off();
        }
        else if (ADC0_SS1_ain10 < limit4) {
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
