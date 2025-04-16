/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       16 de abril de 2025
 * 
 * Código:      Header file del GPIO
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef GPIO_H                                                                      /*  Verificar si GPIO_H no ha sido definido previamente */
#define GPIO_H                                                                      /*  Definir GPIO_H para evitar inclusiones mútliples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * General-Purpose Input/Output (GPIO) registers                                        pp757   Register map
 */

    /*  GPIO Port J (PortJ) */
#define GPIO_PORTJ_AHB_DATA_R       (*((volatile uint32_t *)0x40060004))            /*  pp759   GPIO Data >> PortJ[0] unmasked */
#define GPIO_PORTJ_AHB_DIR_R        (*((volatile uint32_t *)0x40060400))            /*  pp760   GPIO Direction */
#define GPIO_PORTJ_AHB_PUR_R        (*((volatile uint32_t *)0x40060510))            /*  pp776   GPIO Pull-Up Select */
#define GPIO_PORTJ_AHB_DEN_R        (*((volatile uint32_t *)0x4006051C))            /*  pp781   GPIO Digital Enable */

    /*  GPIO Port N (PortN) */
#define GPIO_PORTN_DATA_R           (*((volatile uint32_t *)0x40064008))            /*  pp759   GPIO Data >> PortN[1] unmasked */
#define GPIO_PORTN_DIR_R            (*((volatile uint32_t *)0x40064400))            /*  pp760   GPIO Direction */
#define GPIO_PORTN_DEN_R            (*((volatile uint32_t *)0x4006451C))            /*  pp781   GPIO Digital Enable */


/*********************************************************************************
 * Macros de apoyo
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

    /*  Control de los LED de usuario (Dn) */
#define LED_D1_Toggle()             (GPIO_PORTN_DATA_R ^= GPIO_PIN_1)               /*  Conmutación del LED D1 (PortN[1]) */

    /*  Lectura de los botones de usuario (SWn) */
#define SW1_Pressed                 (!(GPIO_PORTJ_AHB_DATA_R & GPIO_PIN_0))         /*  Lectura del SW1 (PortJ[0]) => Presionado */
#define SW1_Released                (GPIO_PORTJ_AHB_DATA_R & GPIO_PIN_0)            /*  Lectura del SW1 (PortJ[0]) => Liberado */


/*********************************************************************************
 * Prototipos de funciones públicas
 */

void GPIO_PortJ_Init(void);                                                         /*  Inicialización del GPIO PortJ */
void GPIO_PortN_Init(void);                                                         /*  Inicialización del GPIO PortN */


#endif
