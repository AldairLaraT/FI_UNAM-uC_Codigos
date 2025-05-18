/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de mayo de 2025
 * 
 * Tema 09:     Periféricos
 * Código 26:   GPTM: Modo PWM
 * Descripción: Configuración del PWM con temporizadores, ajustando el ciclo de trabajo
 *              a partir de los botones SW1 y SW2 de la tarjeta de desarrollo.
 *              Periféricos utilizados:
 *              - GPIO PortJ => Lectura de los SW de la tarjeta de desarrollo (interrupción).
 *              - GPTM0A (One-Shot) => Retardo de rebote (polling).
 *              - GPTM2A (PWM) => GPIO PortM[0].
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

uint32_t PWM_DutyCycle;


/*********************************************************************************
 * Función principal
 */

int main(void) {

    GPIO_PortJ_Init();                                                              /*  Inicialización del GPIO PortJ */

    uint32_t Bounce_Delay = 400000;                                                 /*  Valor de carga para el retardo de rebote => 25ms (f = 16MHz) */
    GPTM0A_Init_OneShot(Bounce_Delay);                                              /*  Inicialización del GPTM0 (subtimer A) en modo One-Shot */

    GPIO_PortM0_Init_T2CCP0();                                                      /*  Inicialización del GPIO PortM[0] -> T2CCP0 */
    uint32_t PWM_frequency = 16000;                                                 /*  Frecuencia de 1kHz */
    PWM_DutyCycle = 8000;                                                           /*  Ciclo de trabajo del 50% */
    GPTM2A_Init_PWM(PWM_frequency, PWM_DutyCycle);                                  /*  Inicialización del GPTM2 (subtimer A) en modo PWM */
    GPTM2_A_Initiate();                                                             /*  GPTM2 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */

    while(1) {}
}
