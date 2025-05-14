/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       09 de mayo de 2025
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

    /*  SSI module 1 (SSI1) */
#define NVIC_EN0_R                  (*((volatile uint32_t *)0xE000E100))            /*  pp154   Interrupt 0-31 Set Enable */
#define NVIC_PRI4_R                 (*((volatile uint32_t *)0xE000E410))            /*  pp159   Interrupt 16-19 Priority */
#define NVIC_PRI5_R                 (*((volatile uint32_t *)0xE000E414))            /*  pp159   Interrupt 20-23 Priority */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the NVIC_EN0 register                                              pp154
#define NVIC_EN0_INT_M              0xFFFFFFFF                                      /*  Interrupt Enable mask */

    // Bit fields in the NVIC_PRI4 register                                             pp159
#define NVIC_PRI4_INT19_M           0xE0000000                                      /*  Interrupt 19 Priority mask */
#define NVIC_PRI4_INT18_M           0x00E00000                                      /*  Interrupt 18 Priority mask */
#define NVIC_PRI4_INT17_M           0x0000E000                                      /*  Interrupt 17 Priority mask */
#define NVIC_PRI4_INT16_M           0x000000E0                                      /*  Interrupt 16 Priority mask */
#define NVIC_PRI4_INT19_S           29                                              /*  Interrupt 19 Priority shift */
#define NVIC_PRI4_INT18_S           21                                              /*  Interrupt 18 Priority shift */
#define NVIC_PRI4_INT17_S           13                                              /*  Interrupt 17 Priority shift */
#define NVIC_PRI4_INT16_S           5                                               /*  Interrupt 16 Priority shift */

    // Bit fields in the NVIC_PRI5 register                                             pp159
#define NVIC_PRI5_INT23_M           0xE0000000                                      /*  Interrupt 23 Priority mask */
#define NVIC_PRI5_INT22_M           0x00E00000                                      /*  Interrupt 22 Priority mask */
#define NVIC_PRI5_INT21_M           0x0000E000                                      /*  Interrupt 21 Priority mask */
#define NVIC_PRI5_INT20_M           0x000000E0                                      /*  Interrupt 20 Priority mask */
#define NVIC_PRI5_INT23_S           29                                              /*  Interrupt 23 Priority shift */
#define NVIC_PRI5_INT22_S           21                                              /*  Interrupt 22 Priority shift */
#define NVIC_PRI5_INT21_S           13                                              /*  Interrupt 21 Priority shift */
#define NVIC_PRI5_INT20_S           5                                               /*  Interrupt 20 Priority shift */


/*********************************************************************************
 * Prototipos de funciones públicas
 */

void TIMER0_A_Handler(void);                                                        /*  Interrupt 19 -> TIMER 0 subtimer A */
void TIMER0_B_Handler(void);                                                        /*  Interrupt 20 -> TIMER 0 subtimer B */


#endif                                                                              /*  NVIC_H */
