/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       16 de abril de 2025
 * 
 * Tema 08:     Lenguaje C
 * Código 16:   GPIO: Output (modular)
 * Descripción: Configuración de los GPIO del microcontrolador como salida para 
 *              encender los LED de la tarjeta de desarrollo.
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */
#include "GPIO.h"                                                                   /*  Macros para el uso de GPIO */
#include "SYSCTL.h"                                                                 /*  Macros para el uso de SYSCTL */
#include "SysTick.h"                                                                /*  Macros para el uso de SysTick */


/*********************************************************************************
 * Variables globales
 */

uint32_t SysTick_Reload;                                                            /*  Valor de carga del SysTick */


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */
    SysTick_Init(4000000);                                                          /*  Inicialización del SysTick */

    while (1) {

        SysTick_wait();                                                             /*  Esperar a que el SysTick termine la cuenta */
        LED_D1_Toggle();                                                            /*  Conmutación del LED D1 (PortN[1]) */

        SysTick_wait();                                                             /*  Esperar a que el SysTick termine la cuenta */
        LED_D2_Toggle();                                                            /*  Conmutación del LED D2 (PortN[0]) */

    }
}
