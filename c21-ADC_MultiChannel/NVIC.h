/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Código:      Archivo de cabecera del NVIC
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

#define NVIC_EN0_R                  (*((volatile uint32_t *)0xE000E100))            /*  pp154   Interrupt 0-31 Set Enable */
#define NVIC_EN1_R                  (*((volatile uint32_t *)0xE000E104))            /*  pp154   Interrupt 32-63 Set Enable */
#define NVIC_PRI3_R                 (*((volatile uint32_t *)0xE000E40C))            /*  pp159   Interrupt 12-15 Priority */
#define NVIC_PRI12_R                (*((volatile uint32_t *)0xE000E430))            /*  pp159   Interrupt 48-51 Priority */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the NVIC_PRI3 register                                             pp159
#define NVIC_PRI3_INT15_M           0xE0000000                                      /*  Interrupt 15 Priority mask */
#define NVIC_PRI3_INT14_M           0x00E00000                                      /*  Interrupt 14 Priority mask */
#define NVIC_PRI3_INT13_M           0x0000E000                                      /*  Interrupt 13 Priority mask */
#define NVIC_PRI3_INT12_M           0x000000E0                                      /*  Interrupt 12 Priority mask */
#define NVIC_PRI3_INT15_S           29                                              /*  Interrupt 15 Priority shift */
#define NVIC_PRI3_INT14_S           21                                              /*  Interrupt 14 Priority shift */
#define NVIC_PRI3_INT13_S           13                                              /*  Interrupt 13 Priority shift */
#define NVIC_PRI3_INT12_S           5                                               /*  Interrupt 12 Priority shift */

    // Bit fields in the NVIC_PRI12 register                                            pp159
#define NVIC_PRI12_INT51_M          0xE0000000                                      /*  Interrupt 51 Priority mask */
#define NVIC_PRI12_INT50_M          0x00E00000                                      /*  Interrupt 50 Priority mask */
#define NVIC_PRI12_INT49_M          0x0000E000                                      /*  Interrupt 49 Priority mask */
#define NVIC_PRI12_INT48_M          0x000000E0                                      /*  Interrupt 48 Priority mask */
#define NVIC_PRI12_INT51_S          29                                              /*  Interrupt 51 Priority shift */
#define NVIC_PRI12_INT50_S          21                                              /*  Interrupt 50 Priority shift */
#define NVIC_PRI12_INT49_S          13                                              /*  Interrupt 49 Priority shift */
#define NVIC_PRI12_INT48_S          5                                               /*  Interrupt 48 Priority shift */


/*********************************************************************************
 * Prototipos de funciones públicas
 */

void ADC0_SS0_Handler(void);                                                        /*  Interrupt 14 -> ADC0 Sequence 0 */
void GPIO_PortJ_Handler(void);                                                      /*  Interrupt 51 -> GPIO PortJ */


#endif                                                                              /*  NVIC_H */
