/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       03 de mayo de 2025
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
#define NVIC_EN1_R                  (*((volatile uint32_t *)0xE000E104))            /*  pp154   Interrupt 32-63 Set Enable */
#define NVIC_DIS0_R                 (*((volatile uint32_t *)0xE000E180))            /*  pp155   Interrupt 0-31 Clear Enable */
#define NVIC_DIS1_R                 (*((volatile uint32_t *)0xE000E184))            /*  pp155   Interrupt 32-63 Clear Enable */
#define NVIC_PRI5_R                 (*((volatile uint32_t *)0xE000E414))            /*  pp159   Interrupt 20-23 Priority */
#define NVIC_PRI12_R                (*((volatile uint32_t *)0xE000E430))            /*  pp159   Interrupt 48-51 Priority */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the NVIC_EN0 register                                              pp154
#define NVIC_EN0_INT_M              0xFFFFFFFF                                      /*  Interrupt Enable mask */

    // Bit fields in the NVIC_EN1 register                                              pp154
#define NVIC_EN1_INT_M              0xFFFFFFFF                                      /*  Interrupt Enable mask */

    // Bit fields in the NVIC_DIS0 register                                             pp155
#define NVIC_DIS0_INT_M             0xFFFFFFFF                                      /*  Interrupt Disable mask */

    // Bit fields in the NVIC_DIS1 register                                             pp155
#define NVIC_DIS1_INT_M             0xFFFFFFFF                                      /*  Interrupt Disable mask */

    // Bit fields in the NVIC_PRI5 register                                             pp159
#define NVIC_PRI5_INT23_M           0xE0000000                                      /*  Interrupt 23 Priority mask */
#define NVIC_PRI5_INT22_M           0x00E00000                                      /*  Interrupt 22 Priority mask */
#define NVIC_PRI5_INT21_M           0x0000E000                                      /*  Interrupt 21 Priority mask */
#define NVIC_PRI5_INT20_M           0x000000E0                                      /*  Interrupt 20 Priority mask */
#define NVIC_PRI5_INT23_S           29                                              /*  Interrupt 23 Priority shift */
#define NVIC_PRI5_INT22_S           21                                              /*  Interrupt 22 Priority shift */
#define NVIC_PRI5_INT21_S           13                                              /*  Interrupt 21 Priority shift */
#define NVIC_PRI5_INT20_S           5                                               /*  Interrupt 20 Priority shift */

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

void TIMER1_A_Handler(void);                                                        /*  Interrupt 21 -> TIMER 1 subtimer A */
void TIMER2_A_Handler(void);                                                        /*  Interrupt 23 -> TIMER 2 subtimer A */
void GPIO_PortJ_Handler(void);                                                      /*  Interrupt 51 -> GPIO PortJ */


#endif                                                                              /*  NVIC_H */
