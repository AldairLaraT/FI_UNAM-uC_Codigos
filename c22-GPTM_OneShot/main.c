/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       03 de mayo de 2025
 * 
 * Tema 09:     Periféricos
 * Código 22:   GPTM: Modo One-Shot
 * Descripción: Juego de reacción con temporizadores.
 *              Periféricos utilizados:
 *              - GPIO PortJ => Lectura de los SW de la tarjeta de desarrollo (interrupción).
 *              - GPIO PortN => Control de los LED de la tarjeta de desarrollo.
 *              - GPTM0 (One-Shot) => Retardo de rebote (polling).
 *              - GPTM1 (One-Shot) => Retardo del LED indicador (interrupción).
 *              - GPTM2 (One-Shot) => Medición del tiempo de respuesta (interrupción).
 * 
 *              Reglas del juego:
 *              1. SW1 para iniciar el juego (encenderá el LED D1).
 *              2. En cuanto se apague el LED D1, presionar el SW2 lo más rápido posible.
 *              3. Los LED de la tarjeta de desarrollo indican el tiempo de reacción
 *                 del usuario.
 *              * Si se enciende el LED D4 ocurrió un error que solo podrá ser corregido
 *                con un RESET. Sucede si se presiona el SW2 antes de tiempo o si no se 
 *                presiona el SW2 después de un time-out.
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

uint16_t ReloadStep;                                                                /*  Valor para el retardo del LED indicador (TIMER1) */
uint32_t TIMER2_TimeoutValue = 32000000;                                            /*  Valor de cuenta máximo => 2s (f = 16MHz) para medir el tiempo de respuesta del usuario */
float ReactionTime_ms = 0;                                                          /*  Tiempo de reacción del usuario (ms) */


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortF_Init();                                                              /*  Inicialización del GPIO PortF */
    GPIO_PortJ_Init();                                                              /*  Inicialización del GPIO PortJ */
    GPIO_PortN_Init();                                                              /*  Inicialización del GPIO PortN */

    uint32_t Bounce_Delay = 400000;                                                 /*  Valor de carga para el retardo de rebote => 25ms (f = 16MHz) */
    GPTM0A_Init_OneShot(Bounce_Delay);                                              /*  Inicialización del GPTM0 (subtimer A) en modo One-Shot */

    GPTM2AB_Init_OneShot(TIMER2_TimeoutValue);                                      /*  Inicialización del GPTM2 (subtimers A y B concatenados) en modo One-Shot */

    uint8_t ReloadOffset = 16;                                                      /*  Incremento del valor de carga del TIMER1 */
    const uint16_t ReloadStepMin = 160;                                             /*  Límite inferior del valor de carga del TIMER1 */
    const uint16_t ReloadStepMax = 800;                                             /*  Límite superior del valor de carga del TIMER1 */

    GPTM1AB_Init_OneShot(0);                                                        /*  Inicialización del GPTM1 (subtimers A y B concatenados) en modo One-Shot */
    ReloadStep = ReloadStepMin;

    while(1) {

        ReloadStep += ReloadOffset;

        if (ReloadStep >= ReloadStepMax) {
            ReloadStep = ReloadStepMin;
        }
    }
}
