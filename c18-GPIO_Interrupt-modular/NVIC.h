/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       17 de abril de 2025
 * 
 * Código:      Header file del NVIC
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef NVIC_H                                                                      /*  Verificar si NVIC_H no ha sido definido previamente */
#define NVIC_H                                                                      /*  Definir NVIC_H para evitar inclusiones múltiples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * Nested Vectored Interrupt Controller (NVIC) registers                                pp146   Register map
 */

#define NVIC_EN1_R                  (*((volatile uint32_t *)0xE000E104))            /*  pp154   Interrupt 32-63 Set Enable */
#define NVIC_PRI12_R                (*((volatile uint32_t *)0xE000E430))            /*  pp159   Interrupt 48-51 Priority */


/*********************************************************************************
 * Macros de apoyo
 */

    // Bit fields in the NVIC_PRI12 register                                            pp159
#define NVIC_PRI12_INT51_M          0xE0000000                                      /*  Interrupt 51 Priority Mask */
#define NVIC_PRI12_INT50_M          0x00E00000                                      /*  Interrupt 50 Priority Mask */
#define NVIC_PRI12_INT49_M          0x0000E000                                      /*  Interrupt 49 Priority Mask */
#define NVIC_PRI12_INT48_M          0x000000E0                                      /*  Interrupt 48 Priority Mask */
#define NVIC_PRI12_INT51_S          29                                              /*  Interrupt 51 Priority Shift */
#define NVIC_PRI12_INT50_S          21                                              /*  Interrupt 50 Priority Shift */
#define NVIC_PRI12_INT49_S          13                                              /*  Interrupt 49 Priority Shift */
#define NVIC_PRI12_INT48_S          5                                               /*  Interrupt 48 Priority Shift */


/*********************************************************************************
 * Prototipos de funciones públicas
 */

void GPIOPortJ_Handler(void);                                                       /*  ISR del GPIO PortJ */


#endif
