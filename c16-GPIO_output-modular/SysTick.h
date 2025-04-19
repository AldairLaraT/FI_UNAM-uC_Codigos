/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       17 de abril de 2025
 * 
 * Código:      Header file del SysTick
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef SysTick_H                                                                   /*  Verificar si SysTick_H no ha sido definido previamente */
#define SysTick_H                                                                   /*  Definir SysTick_H para evitar inclusiones múltiples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * System Timer (SysTick) registers                                                     pp146   Register map
 */

#define NVIC_ST_CTRL_R              (*((volatile uint32_t *)0xE000E010))            /*  pp150   SysTick Control and Status */
#define NVIC_ST_RELOAD_R            (*((volatile uint32_t *)0xE000E014))            /*  pp152   SysTick Reload Value */
#define NVIC_ST_CURRENT_R           (*((volatile uint32_t *)0xE000E018))            /*  pp153   SysTick Current Value */


/*********************************************************************************
 * Macros de apoyo
 */

    // Bit fields in the NVIC_ST_CTRL register                                          pp150
#define NVIC_ST_CTRL_COUNT          0x00010000                                      /*  Count Flag */
#define NVIC_ST_CTRL_CLK_SRC        0x00000004                                      /*  Clock Source */
#define NVIC_ST_CTRL_INTEN          0x00000002                                      /*  Interrupt Enable */
#define NVIC_ST_CTRL_ENABLE         0x00000001                                      /*  Enable */

    // Bit fields in the NVIC_ST_RELOAD register                                        pp152
#define NVIC_ST_RELOAD_M            0x00FFFFFF                                      /*  Reload Value Mask */
#define NVIC_ST_RELOAD_S            0                                               /*  Reload Value Shift */

    // Bit fields in the NVIC_ST_CURRENT register                                       pp153
#define NVIC_ST_CURRENT_M           0x00FFFFFF                                      /*  Current Value Mask */
#define NVIC_ST_CURRENT_S           0                                               /*  Current Value Shift */

    /*  Lectura del estado del SysTick */
#define SysTick_wait()              while (!(NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT)) {}   /*  Esperar a que el SysTick termine la cuenta */


/*********************************************************************************
 * Prototipos de funciones públicas
 */

void SysTick_Init(uint32_t SysTick_Reload);                                         /*  Inicialización del SysTick */


#endif
