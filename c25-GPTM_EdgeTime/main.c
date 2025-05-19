/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       17 de mayo de 2025
 * 
 * Tema 09:     Periféricos
 * Código 25:   GPTM: Modo Edge-Time
 * Descripción: Medición del tiempo entre dos eventos.
 *              Periféricos utilizados:
 *              - GPIO PortJ[0] => Lectura del SW1 de la tarjeta de desarrollo (interrupción).
 *              - GPIO PortN[1] => Control del LED D1 de la tarjeta de desarrollo.
 *              - GPTM0A (One-Shot) => Time-out (interrupción).
 *              - GPTM0B (Edge-Time) => GPIO PortL[5] (interrupción).
 *              - GPTM1A (One-Shot) => Retardo de rebote (polling).
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
 * Variables globales
 */

int TIMER0B_Flag = 0;
uint32_t TIMER0B_InitialValue;
uint32_t TIMER0B_FinalValue;
float Time_ms;                                                                      /*  Tiempo de reacción del usuario (ms) */


/*********************************************************************************
 * Función principal
 */

int main(void) {

	GPIO_PortJ_Init();                                                              /*  Inicialización del GPIO PortJ */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */

	uint32_t Bounce_Delay = 400000;                                                 /*  Valor de carga para el retardo de rebote => 25ms (f = 16MHz) */
    GPTM1A_Init_OneShot(Bounce_Delay);                                              /*  Inicialización del GPTM1 (subtimer A) en modo One-Shot */

    uint32_t TIMER_TimeoutValue = 0xFFFFFF;                                         /*  Valor de cuenta máximo => 1.0486s (f = 16MHz) */
    GPTM0A_Init_OneShot(TIMER_TimeoutValue);                                        /*  Inicialización del GPTM0 (subtimer A) en modo One-Shot */
    GPIO_PortL5_Init_T0CCP1();                                                      /*  Inicialización del GPIO PortL[5] -> T0CCP1 */
    GPTM0B_Init_EdgeTime(TIMER_TimeoutValue);                                       /*  Inicialización del GPTM0 (subtimer B) en modo Edge-Time */

    while(1) {}
}
