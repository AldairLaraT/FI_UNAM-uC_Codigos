/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Tema 09:     Periféricos
 * Código 21:   ADC: Múltiples canales con interrupción
 * Descripción: Configuración del ADC0, empleando el secuenciador de muestras SS0
 *              para leer el valor de dos potenciómetros con las entradas analógicas
 *              AIN10 (PB4) y AIN17 (PK1) y el sensor de temperatura embebido en el
 *              TIVA, empleando interrupciones para el ADC0 SS0 y el GPIO PortJ.
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */
#include "ADC.h"                                                                    /*  Archivo de cabecera del ADC */
#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "NVIC.h"                                                                   /*  Archivo de cabecera del NVIC */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */
#include "SysTick.h"                                                                /*  Archivo de cabecera del SysTick */


/*********************************************************************************
 * Variables globales
 */

uint8_t LED_control_flag = 0;
uint16_t LED_control;
uint16_t ADC0_SS0_ain10;
uint16_t ADC0_SS0_ain17;
uint16_t temp_RawData;
uint32_t Bounce_Delay = 100000;                                                     /*  Valor de carga del SysTick para un retardo de rebote de 25ms (f = 4MHz) */
float temperature;


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

    ADC0_SS0_Initiate();                                                            /*  ADC0 => SS0 Initiate -> Begin sampling on SS0 */

    while(1) {

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
