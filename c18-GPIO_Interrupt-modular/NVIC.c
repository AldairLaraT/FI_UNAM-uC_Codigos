/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       17 de abril de 2025
 * 
 * Código:      Archivo fuente del NVIC
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "NVIC.h"                                                                   /*  Archivo de cabecera del NVIC */
#include "SysTick.h"                                                                /*  Archivo de cabecera del SysTick */


/*********************************************************************************
 * Variables globales
 */

extern uint32_t Bounce_Delay;
extern int cuenta;


/*********************************************************************************
 * Funciones
 */

void GPIO_PortJ_Handler(void) {

    SysTick_Init_OneShot(Bounce_Delay);                                             /*  Inicialización del SysTick en modo OneShot para el retardo de rebote */
    SysTick_wait();                                                                 /*  SysTick => COUNT: Count Flag -> The SysTick timer has counted to 0 */

    if (SW1_Pressed) {                                                              /*  Validación del SW1 */
        cuenta += 1;
    }

    if (SW2_Pressed) {                                                              /*  Validación del SW2 */
        cuenta -= 1;
    }

    /*  Limpiar la bandera de interrupción (GPIOICR) */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => IC: Interrupt Clear -> Interrupt cleared */

}
