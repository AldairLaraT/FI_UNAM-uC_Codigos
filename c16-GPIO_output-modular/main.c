/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       17 de abril de 2025
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
#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */
#include "SysTick.h"                                                                /*  Archivo de cabecera del SysTick */


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

        SysTick_wait();                                                             /*  SysTick => COUNT: Count Flag -> The SysTick timer has counted to 0 */
        LED_D1_Toggle();                                                            /*  Conmutación del LED D1 (PortN[1]) */

        SysTick_wait();                                                             /*  SysTick => COUNT: Count Flag -> The SysTick timer has counted to 0 */
        LED_D2_Toggle();                                                            /*  Conmutación del LED D2 (PortN[0]) */

    }
}
