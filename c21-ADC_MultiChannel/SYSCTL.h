/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
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

#define SYSCTL_PLLFREQ0_R           (*((volatile uint32_t *)0x400FE160))            /*  pp292   PLL Frequency 0 */
#define SYSCTL_PLLSTAT_R            (*((volatile uint32_t *)0x400FE168))            /*  pp294   PLL Status */
#define SYSCTL_RCGCGPIO_R           (*((volatile uint32_t *)0x400FE608))            /*  pp382   GPIO Run Mode Clock Gating Control */
#define SYSCTL_RCGCADC_R            (*((volatile uint32_t *)0x400FE638))            /*  pp396   ADC Run Mode Clock Gating Control */
#define SYSCTL_PRGPIO_R             (*((volatile uint32_t *)0x400FEA08))            /*  pp499   GPIO Peripheral Ready */
#define SYSCTL_PRADC_R              (*((volatile uint32_t *)0x400FEA38))            /*  pp515   ADC Peripheral Ready */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the SYSCTL_PLLFREQ0 register                                       pp292
#define SYSCTL_PLLFREQ0_PLLPWR      0x00800000                                      /*  PLL Power */
#define SYSCTL_PLLFREQ0_MFRAC_M     0x000FFC00                                      /*  PLL M Fractional Value mask */
#define SYSCTL_PLLFREQ0_MINT_M      0x000003FF                                      /*  PLL M Integer Value mask */
#define SYSCTL_PLLFREQ0_MFRAC_S     10                                              /*  PLL M Fractional Value shift */
#define SYSCTL_PLLFREQ0_MINT_S      0                                               /*  PLL M Integer Value shift */

    // Bit fields in the SYSCTL_PLLSTAT register                                        pp294
#define SYSCTL_PLLSTAT_LOCK         0x00000001                                      /*  PLL Lock */

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

    // Bit fields in the SYSCTL_RCGCADC register                                        pp396
#define SYSCTL_RCGCADC_R1           0x00000002                                      /*  ADC Module 1 Run Mode Clock Gating Control */
#define SYSCTL_RCGCADC_R0           0x00000001                                      /*  ADC Module 0 Run Mode Clock Gating Control */

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

    // Bit fields in the SYSCTL_PRADC register                                          pp515
#define SYSCTL_PRADC_R1             0x00000002                                      /*  ADC Module 1 Peripheral Ready */
#define SYSCTL_PRADC_R0             0x00000001                                      /*  ADC Module 0 Peripheral Ready */


/*********************************************************************************
 * Prototipos de funciones públicas
 */


#endif                                                                              /*  SYSCTL_H */
