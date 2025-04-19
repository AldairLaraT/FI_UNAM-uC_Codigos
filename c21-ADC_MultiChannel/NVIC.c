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

#include "GPIO.h"                                                                   /*  Macros para el uso de GPIO */
#include "NVIC.h"                                                                   /*  Macros para el uso de NVIC */
#include "SysTick.h"                                                                /*  Macros para el uso de SysTick */


/*********************************************************************************
 * Variables globales
 */

extern uint32_t Bounce_Delay;
extern uint8_t LED_control_flag;

/*********************************************************************************
 * Funciones
 */

void GPIOPortJ_Handler(void) {

    SysTick_OneShot_Init(Bounce_Delay);                                             /*  Inicialización del SysTick en modo OneShot para el retardo de rebote */
    SysTick_wait();                                                                 /*  Esperar a que el SysTick termine la cuenta */

    if (SW1_Pressed) {                                                              /*  Validación del SW1 */
        LED_control_flag = 0;
    }

    if (SW2_Pressed) {                                                              /*  Validación del SW2 */
        LED_control_flag = 1;
    }

    /*  Limpiar la bandera de interrupción (GPIOICR) */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => IC: Interrupt Clear -> Interrupt cleared */

}
