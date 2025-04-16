/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       16 de abril de 2025
 * 
 * Tema 07:     Interrupciones y resets
 * Código 18:   GPIO con interrupción (modular)
 * Descripción: Configuración de los GPIO del microcontrolador como entrada para 
 *              leer los SW de la tarjeta de desarrollo, empleando interrupciones.
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */
#include "GPIO.h"                                                                   /*  Macros para el uso de GPIO */
#include "NVIC.h"                                                                   /*  Macros para el uso de NVIC */
#include "SYSCTL.h"                                                                 /*  Macros para el uso de SYSCTL */
#include "SysTick.h"                                                                /*  Macros para el uso de SysTick */


/*********************************************************************************
 * Variables globales
 */

uint32_t Bounce_Delay = 100000;                                                     /*  Valor de carga del SysTick para un retardo de rebote de 25ms (f = 4MHz) */
int cuenta = 0;


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortF_Init();                                                              /*  Inicialización del GPIO PortF */
    GPIO_PortJ_Init();                                                              /*  Inicialización del GPIO PortJ */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */

    int i;

    while(1) {

        for (i = 0; i < 700000; i++) {}                                             /*  Retardo aproximado de 500ms */
        LED_D1_Toggle();                                                            /*  Conmutación del LED D1 (PortN[1]) */

        for (i = 0; i < 700000; i++) {}                                             /*  Retardo aproximado de 500ms */
        LED_D2_Toggle();                                                            /*  Conmutación del LED D2 (PortN[0]) */

        for (i = 0; i < 700000; i++) {}                                             /*  Retardo aproximado de 500ms */
        LED_D3_Toggle();                                                            /*  Conmutación del LED D3 (PortF[4]) */

        for (i = 0; i < 700000; i++) {}                                             /*  Retardo aproximado de 500ms */
        LED_D4_Toggle();                                                            /*  Conmutación del LED D4 (PortF[0]) */

    }
}
