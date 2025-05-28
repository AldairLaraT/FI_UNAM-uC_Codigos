/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       27 de mayo de 2025
 * 
 * Código:      Archivo de cabecera del GPIO
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef GPIO_H                                                                      /*  Verificar si GPIO_H no ha sido definido previamente */
#define GPIO_H                                                                      /*  Definir GPIO_H para evitar inclusiones múLTiples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * General-Purpose Input/Output (GPIO) registers                                        pp755   Register map
 */

    /*  GPIO Port B (PortB) */
#define GPIO_PORTB_AHB_DIR_R        (*((volatile uint32_t *)0x40059400))            /*  pp760   GPIO Direction */
#define GPIO_PORTB_AHB_AFSEL_R      (*((volatile uint32_t *)0x40059420))            /*  pp770   GPIO Alternate Function Select */
#define GPIO_PORTB_AHB_ODR_R        (*((volatile uint32_t *)0x4005950C))            /*  pp775   GPIO Open Drain Select */
#define GPIO_PORTB_AHB_DEN_R        (*((volatile uint32_t *)0x4005951C))            /*  pp781   GPIO Digital Enable */
#define GPIO_PORTB_AHB_PCTL_R       (*((volatile uint32_t *)0x4005952C))            /*  pp787   GPIO Port Control */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields for the GPIO pin
#define GPIO_PIN_7                  0x00000080                                      /*  GPIO pin 7 */
#define GPIO_PIN_6                  0x00000040                                      /*  GPIO pin 6 */
#define GPIO_PIN_5                  0x00000020                                      /*  GPIO pin 5 */
#define GPIO_PIN_4                  0x00000010                                      /*  GPIO pin 4 */
#define GPIO_PIN_3                  0x00000008                                      /*  GPIO pin 3 */
#define GPIO_PIN_2                  0x00000004                                      /*  GPIO pin 2 */
#define GPIO_PIN_1                  0x00000002                                      /*  GPIO pin 1 */
#define GPIO_PIN_0                  0x00000001                                      /*  GPIO pin 0 */


/*********************************************************************************
 * Prototipos de funciones públicas
 */


#endif                                                                              /*  GPIO_H */
