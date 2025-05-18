/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       09 de mayo de 2025
 * 
 * Tema 09:     Periféricos
 * Código 24:   GPTM: Modo Edge-Count
 * Descripción: Captura de eventos con interrupción a través de dos botones.
 *              Periféricos utilizados:
 *              - TIMER0A (Edge-Count) => GPIO PortL[4] (interrupción)
 *              - TIMER0B (Edge-Count) => GPIO PortL[5] (interrupción)
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */
#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "GPTM.h"                                                                   /*  Archivo de cabecera del GPTM */
#include "NVIC.h"                                                                   /*  Archivo de cabecera del NVIC */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */

    GPIO_PortL4_Init_T0CCP0();                                                      /*  Inicialización del GPIO PortL[4] -> T0CCP0 */
    GPTM0A_Init_EdgeCount(20, 5);                                                   /*  Inicialización del GPTM0 (subtimer A) en modo Edge-Count */
    GPTM0_A_Initiate();                                                             /*  GPTM0 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */

    GPIO_PortL5_Init_T0CCP1();                                                      /*  Inicialización del GPIO PortL[5] -> T0CCP1 */
    GPTM0B_Init_EdgeCount(20, 5);                                                   /*  Inicialización del GPTM0 (subtimer B) en modo Edge-Count */
    GPTM0_B_Initiate();                                                             /*  GPTM0 => TBEN: GPTM Timer B Enable -> Enabled and begins counting */

    while(1) {}
}
