/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de mayo de 2025
 * 
 * Código:      Archivo de cabecera del SYSCTL
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef SYSCTL_H                                                                    /*  Verificar si SYSCTL_H no ha sido definido previamente */
#define SYSCTL_H                                                                    /*  Definir SYSCTL_H para evitar inclusiones múltiples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * System Control (SYSCTL) registers                                                    pp247   Register map
 */

#define SYSCTL_RCGCTIMER_R          (*((volatile uint32_t *)0x400FE604))            /*  pp380   16/32-Bit General-Purpose Timer Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R           (*((volatile uint32_t *)0x400FE608))            /*  pp382   General-Purpose Input/Output Run Mode Clock Gating Control */
#define SYSCTL_PRTIMER_R            (*((volatile uint32_t *)0x400FEA04))            /*  pp497   16/32-Bit General-Purpose Timer Peripheral Ready */
#define SYSCTL_PRGPIO_R             (*((volatile uint32_t *)0x400FEA08))            /*  pp499   General-Purpose Input/Output Peripheral Ready */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the SYSCTL_RCGCTIMER register                                      pp380
#define SYSCTL_RCGCTIMER_R7         0x00000080                                      /*  16/32-Bit General-Purpose Timer 7 Run Mode Clock Gating Control */
#define SYSCTL_RCGCTIMER_R6         0x00000040                                      /*  16/32-Bit General-Purpose Timer 6 Run Mode Clock Gating Control */
#define SYSCTL_RCGCTIMER_R5         0x00000020                                      /*  16/32-Bit General-Purpose Timer 5 Run Mode Clock Gating Control */
#define SYSCTL_RCGCTIMER_R4         0x00000010                                      /*  16/32-Bit General-Purpose Timer 4 Run Mode Clock Gating Control */
#define SYSCTL_RCGCTIMER_R3         0x00000008                                      /*  16/32-Bit General-Purpose Timer 3 Run Mode Clock Gating Control */
#define SYSCTL_RCGCTIMER_R2         0x00000004                                      /*  16/32-Bit General-Purpose Timer 2 Run Mode Clock Gating Control */
#define SYSCTL_RCGCTIMER_R1         0x00000002                                      /*  16/32-Bit General-Purpose Timer 1 Run Mode Clock Gating Control */
#define SYSCTL_RCGCTIMER_R0         0x00000001                                      /*  16/32-Bit General-Purpose Timer 0 Run Mode Clock Gating Control */

    // Bit fields in the SYSCTL_RCGCGPIO register                                       pp382
#define SYSCTL_RCGCGPIO_R14         0x00004000                                      /*  GPIO Port Q Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R13         0x00002000                                      /*  GPIO Port P Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R12         0x00001000                                      /*  GPIO Port N Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R11         0x00000800                                      /*  GPIO Port M Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R10         0x00000400                                      /*  GPIO Port L Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R9          0x00000200                                      /*  GPIO Port K Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R8          0x00000100                                      /*  GPIO Port J Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R7          0x00000080                                      /*  GPIO Port H Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R6          0x00000040                                      /*  GPIO Port G Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R5          0x00000020                                      /*  GPIO Port F Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R4          0x00000010                                      /*  GPIO Port E Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R3          0x00000008                                      /*  GPIO Port D Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R2          0x00000004                                      /*  GPIO Port C Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R1          0x00000002                                      /*  GPIO Port B Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R0          0x00000001                                      /*  GPIO Port A Run Mode Clock Gating Control */

    // Bit fields in the SYSCTL_PRTIMER register                                        pp497
#define SYSCTL_PRTIMER_R7           0x00000080                                      /*  16/32-Bit General-Purpose Timer 7 Peripheral Ready */
#define SYSCTL_PRTIMER_R6           0x00000040                                      /*  16/32-Bit General-Purpose Timer 6 Peripheral Ready */
#define SYSCTL_PRTIMER_R5           0x00000020                                      /*  16/32-Bit General-Purpose Timer 5 Peripheral Ready */
#define SYSCTL_PRTIMER_R4           0x00000010                                      /*  16/32-Bit General-Purpose Timer 4 Peripheral Ready */
#define SYSCTL_PRTIMER_R3           0x00000008                                      /*  16/32-Bit General-Purpose Timer 3 Peripheral Ready */
#define SYSCTL_PRTIMER_R2           0x00000004                                      /*  16/32-Bit General-Purpose Timer 2 Peripheral Ready */
#define SYSCTL_PRTIMER_R1           0x00000002                                      /*  16/32-Bit General-Purpose Timer 1 Peripheral Ready */
#define SYSCTL_PRTIMER_R0           0x00000001                                      /*  16/32-Bit General-Purpose Timer 0 Peripheral Ready */

    // Bit fields in the SYSCTL_PRGPIO register                                         pp499
#define SYSCTL_PRGPIO_R14           0x00004000                                      /*  GPIO Port Q Peripheral Ready */
#define SYSCTL_PRGPIO_R13           0x00002000                                      /*  GPIO Port P Peripheral Ready */
#define SYSCTL_PRGPIO_R12           0x00001000                                      /*  GPIO Port N Peripheral Ready */
#define SYSCTL_PRGPIO_R11           0x00000800                                      /*  GPIO Port M Peripheral Ready */
#define SYSCTL_PRGPIO_R10           0x00000400                                      /*  GPIO Port L Peripheral Ready */
#define SYSCTL_PRGPIO_R9            0x00000200                                      /*  GPIO Port K Peripheral Ready */
#define SYSCTL_PRGPIO_R8            0x00000100                                      /*  GPIO Port J Peripheral Ready */
#define SYSCTL_PRGPIO_R7            0x00000080                                      /*  GPIO Port H Peripheral Ready */
#define SYSCTL_PRGPIO_R6            0x00000040                                      /*  GPIO Port G Peripheral Ready */
#define SYSCTL_PRGPIO_R5            0x00000020                                      /*  GPIO Port F Peripheral Ready */
#define SYSCTL_PRGPIO_R4            0x00000010                                      /*  GPIO Port E Peripheral Ready */
#define SYSCTL_PRGPIO_R3            0x00000008                                      /*  GPIO Port D Peripheral Ready */
#define SYSCTL_PRGPIO_R2            0x00000004                                      /*  GPIO Port C Peripheral Ready */
#define SYSCTL_PRGPIO_R1            0x00000002                                      /*  GPIO Port B Peripheral Ready */
#define SYSCTL_PRGPIO_R0            0x00000001                                      /*  GPIO Port A Peripheral Ready */


/*********************************************************************************
 * Prototipos de funciones públicas
 */


#endif                                                                              /*  SYSCTL_H */
