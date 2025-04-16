/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       16 de abril de 2025
 * 
 * Tema 08:     Lenguaje C
 * Código 17:   GPIO: Input (modular)
 * Descripción: Configuración de los GPIO del microcontrolador como entrada para 
 *              leer los SW de la tarjeta de desarrollo.
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

uint32_t Bounce_Delay = 100000;                                                     /*  Valor de carga del SysTick para un retardo de rebote de 25ms (f = 4MHz) */


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortJ_Init();                                                              /*  Inicialización del GPIO PortJ */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */

    while(1) {

        while(SW1_Released) {}                                                      /*  Esperar mientras esté liberado el SW1 (PortJ[0]) */
        SysTick_OneShot_Init(Bounce_Delay);                                         /*  Inicialización del SysTick en modo OneShot para el retardo de rebote */
        SysTick_wait();                                                             /*  Esperar a que el SysTick termine la cuenta */

        LED_D1_Toggle();                                                            /*  Conmutación del LED D1 (PortN[1]) */

        while(SW1_Pressed) {}                                                       /*  Esperar mientras esté presionado el SW1 (PortJ[0]) */
        SysTick_OneShot_Init(Bounce_Delay);                                         /*  Inicialización del SysTick en modo OneShot para el retardo de rebote */
        SysTick_wait();                                                             /*  Esperar a que el SysTick termine la cuenta */

    }
}
