/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       27 de mayo de 2025
 * 
 * Tema 09:     Periféricos
 * Código 28:   I2C
 * Descripción: Configuración y uso del UART para transmitir y recibir datos a través de un terminal,
 *              con un baud-rate de 115200, palabras de 8 bits, sin bit de paridad, 1 bit de stop.
 *              Periféricos utilizados:
 *              - GPIO PortF[4,0] => Control de los LED D3 y D4 de la tarjeta de desarrollo.
 *              - GPIO PortJ[1:0] => Lectura de los SW SW1 y SW2 de la tarjeta de desarrollo (interrupción).
 *              - GPIO PortN[1:0] => Control de los LED D1 y D2 de la tarjeta de desarrollo.
 *              - GPTM0A (One-Shot) => Retardo de rebote (polling).
 *              - UART0 =>  PA1 -> Rx | PA0 -> Tx (interrupción).
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */
#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "I2C.h"                                                                    /*  Archivo de cabecera del I2C */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */


/*********************************************************************************
 * Función principal
 */

int main(void) {

    I2C0_Init();                                                                    /*  Inicialización del I2C0 */

    while(1) {}
}
