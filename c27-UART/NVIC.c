/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de mayo de 2025
 * 
 * Código:      Archivo fuente del NVIC
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "GPTM.h"                                                                   /*  Archivo de cabecera del GPTM */
#include "NVIC.h"                                                                   /*  Archivo de cabecera del NVIC */
#include "UART.h"                                                                   /*	Archivo de cabecera del UART */


/*********************************************************************************
 * Variables globales
 */


/*********************************************************************************
 * Funciones
 */

void UART0_Handler(void) {

    int UART_DataReceived[2];
    UART_DataReceived[1] = (UART0_DR_R & UART_DR_DATA_M);                   /*  UART0 => DATA: Data Transmitted or Received -> Reads the DATA that was received by the UART */
    UART_DataReceived[0] = (UART0_DR_R & UART_DR_DATA_M);                   /*  UART0 => DATA: Data Transmitted or Received -> Reads the DATA that was received by the UART */

    if (UART_DataReceived[1] == 68) {                                       /*  D en ASCII */
        if (UART_DataReceived[0] == 49) {                                   /*  1 en ASCII */
            LED_D1_Toggle();
        }
        else if (UART_DataReceived[0] == 50) {                              /*  2 en ASCII */
            LED_D2_Toggle();
        }
        else if (UART_DataReceived[0] == 51) {                              /*  3 en ASCII */
            LED_D3_Toggle();
        }
        else if (UART_DataReceived[0] == 52) {                              /*  4 en ASCII */
            LED_D4_Toggle();
        }
    }

    UART0_ICR_R |= UART_ICR_RXIC;                                           /*  UART0 => RXIC: Receive Interrupt Clear -> RXRIS bit (UARTRIS) and RXMIS bit (UARTMIS) cleared */
}


void GPIO_PortJ_Handler(void) {

    /*  Retardo de rebote */
    GPTM0_A_Initiate();                                                             /*  GPTM0 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */
    GPTM0_A_RawInterrupt_TimeOut_wait();                                            /*  GPTM0 => TATORIS: GPTM Timer A Time-Out Raw Interrupt -> Timer A has timed out */
    GPTM0_A_ClearFlags_TimeOut();                                                   /*  GPTM0 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */

    if (SW1_Pressed) {                                                              /*  Validación del SW1 */
        char message[] = "Hola se presiono el SW1 :)\n\r";
        int message_size = sizeof(message) / sizeof(message[0]) - 1;
        UART0_Transmit(message, message_size);                                      /*  Transmisión de datos a través de UART0 */
    }

    if (SW2_Pressed) {                                                              /*  Validación del SW2 */
        char message[] = "Hola se presiono el SW2 :D\n\r";
        int message_size = sizeof(message) / sizeof(message[0]) - 1;
        UART0_Transmit(message, message_size);                                      /*  Transmisión de datos a través de UART0 */
    }

    /*  Limpiar la bandera de interrupción (GPIOICR) */
    GPIO_PORTJ_AHB_ICR_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortJ[1:0] => IC: Interrupt Clear -> Interrupt cleared */
}
