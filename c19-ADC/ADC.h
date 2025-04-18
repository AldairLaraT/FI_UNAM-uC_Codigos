/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Código:      Header file del ADC
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef ADC_H                                                                       /*  Verificar si ADC_H no ha sido definido previamente */
#define ADC_H                                                                       /*  Definir ADC_H para evitar inclusiones mútliples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * Analog-to-Digital Converter (ADC) registers                                          pp1073  Register map
 */

    /*  ADC module 0 (ADC0) */
#define ADC0_ACTSS_R                (*((volatile uint32_t *)0x40038000))            /*  pp1077  ADC Active Sample Sequencer */
#define ADC0_RIS_R                  (*((volatile uint32_t *)0x40038004))            /*  pp1079  ADC Raw Interrupt Status */
#define ADC0_IM_R                   (*((volatile uint32_t *)0x40038008))            /*  pp1082  ADC Interrupt Mask */
#define ADC0_ISC_R                  (*((volatile uint32_t *)0x4003800C))            /*  pp1085  ADC Interrupt Status and Clear */
#define ADC0_EMUX_R                 (*((volatile uint32_t *)0x40038014))            /*  pp1091  ADC Event Multiplexer Select */
#define ADC0_SSPRI_R                (*((volatile uint32_t *)0x40038020))            /*  pp1099  ADC Sample Sequencer Priority */
#define ADC0_PSSI_R                 (*((volatile uint32_t *)0x40038028))            /*  pp1103  ADC Processor Sample Sequence Initiate */
#define ADC0_SSMUX1_R               (*((volatile uint32_t *)0x40038060))            /*  pp1129  ADC Sample Sequence Input Multiplexer Select 1 */
#define ADC0_SSCTL1_R               (*((volatile uint32_t *)0x40038064))            /*  pp1130  ADC Sample Sequence Control 1 */
#define ADC0_SSFIFO1_R              (*((volatile uint32_t *)0x40038068))            /*  pp1118  ADC Sample Sequence Result FIFO 1 */
#define ADC0_SSEMUX1_R              (*((volatile uint32_t *)0x40038078))            /*  pp1137  ADC Sample Sequence Extended Input Multiplexer Select 1 */
#define ADC0_CC_R                   (*((volatile uint32_t *)0x40038FC8))            /*  pp1160  ADC Clock Configuration */


/*********************************************************************************
 * Macros de apoyo
 */

    // Bit fields in the ADC_ACTSS register                                             pp1077
#define ADC_ACTSS_BUSY              0x00010000                                      /*  ADC Busy */
#define ADC_ACTSS_ADEN3             0x00000800                                      /*  ADC SS3 DMA Enable */
#define ADC_ACTSS_ADEN2             0x00000400                                      /*  ADC SS2 DMA Enable */
#define ADC_ACTSS_ADEN1             0x00000200                                      /*  ADC SS1 DMA Enable */
#define ADC_ACTSS_ADEN0             0x00000100                                      /*  ADC SS1 DMA Enable */
#define ADC_ACTSS_ASEN3             0x00000008                                      /*  ADC SS3 Enable */
#define ADC_ACTSS_ASEN2             0x00000004                                      /*  ADC SS2 Enable */
#define ADC_ACTSS_ASEN1             0x00000002                                      /*  ADC SS1 Enable */
#define ADC_ACTSS_ASEN0             0x00000001                                      /*  ADC SS0 Enable */

    // Bit fields in the ADC_RIS register                                               pp1079
#define ADC_RIS_INRDC               0x00010000                                      /*  Digital Comparator Raw Interrupt Status */
#define ADC_RIS_DMAINR3             0x00000800                                      /*  SS3 DMA Raw Interrupt Status */
#define ADC_RIS_DMAINR2             0x00000400                                      /*  SS2 DMA Raw Interrupt Status */
#define ADC_RIS_DMAINR1             0x00000200                                      /*  SS1 DMA Raw Interrupt Status */
#define ADC_RIS_DMAINR0             0x00000100                                      /*  SS0 DMA Raw Interrupt Status */
#define ADC_RIS_INR3                0x00000008                                      /*  SS3 Raw Interrupt Status */
#define ADC_RIS_INR2                0x00000004                                      /*  SS2 Raw Interrupt Status */
#define ADC_RIS_INR1                0x00000002                                      /*  SS1 Raw Interrupt Status */
#define ADC_RIS_INR0                0x00000001                                      /*  SS0 Raw Interrupt Status */

    // Bit fields in the ADC_IM register                                                pp1082
#define ADC_IM_DCONSS3              0x00080000                                      /*  Digital Comparator Interrupt on SS3 */
#define ADC_IM_DCONSS2              0x00040000                                      /*  Digital Comparator Interrupt on SS2 */
#define ADC_IM_DCONSS1              0x00020000                                      /*  Digital Comparator Interrupt on SS1 */
#define ADC_IM_DCONSS0              0x00010000                                      /*  Digital Comparator Interrupt on SS0 */
#define ADC_IM_DMAMASK3             0x00000800                                      /*  SS3 DMA Interrupt Mask */
#define ADC_IM_DMAMASK2             0x00000400                                      /*  SS2 DMA Interrupt Mask */
#define ADC_IM_DMAMASK1             0x00000200                                      /*  SS1 DMA Interrupt Mask */
#define ADC_IM_DMAMASK0             0x00000100                                      /*  SS0 DMA Interrupt Mask */
#define ADC_IM_MASK3                0x00000008                                      /*  SS3 Interrupt Mask */
#define ADC_IM_MASK2                0x00000004                                      /*  SS2 Interrupt Mask */
#define ADC_IM_MASK1                0x00000002                                      /*  SS1 Interrupt Mask */
#define ADC_IM_MASK0                0x00000001                                      /*  SS0 Interrupt Mask */

    // Bit fields in the ADC_ISC register                                               pp1085
#define ADC_ISC_DCINSS3             0x00080000                                      /*  Digital Comparator Interrupt Status on SS3 */
#define ADC_ISC_DCINSS2             0x00040000                                      /*  Digital Comparator Interrupt Status on SS2 */
#define ADC_ISC_DCINSS1             0x00020000                                      /*  Digital Comparator Interrupt Status on SS1 */
#define ADC_ISC_DCINSS0             0x00010000                                      /*  Digital Comparator Interrupt Status on SS0 */
#define ADC_ISC_DMAIN3              0x00000800                                      /*  SS3 DMA Interrupt Status and Clear */
#define ADC_ISC_DMAIN2              0x00000400                                      /*  SS2 DMA Interrupt Status and Clear */
#define ADC_ISC_DMAIN1              0x00000200                                      /*  SS1 DMA Interrupt Status and Clear */
#define ADC_ISC_DMAIN0              0x00000100                                      /*  SS0 DMA Interrupt Status and Clear */
#define ADC_ISC_IN3                 0x00000008                                      /*  SS3 Interrupt Status and Clear */
#define ADC_ISC_IN2                 0x00000004                                      /*  SS2 Interrupt Status and Clear */
#define ADC_ISC_IN1                 0x00000002                                      /*  SS1 Interrupt Status and Clear */
#define ADC_ISC_IN0                 0x00000001                                      /*  SS0 Interrupt Status and Clear */

    // Bit fields in the ADC_EMUX register                                              pp1091
#define ADC_EMUX_EM3_M              0x0000F000                                      /*  SS3 Trigger Select Mask */
#define ADC_EMUX_EM3_PROCESSOR      0x00000000                                      /*  Processor (default) */
#define ADC_EMUX_EM3_COMP0          0x00001000                                      /*  Analog Comparator 0 */
#define ADC_EMUX_EM3_COMP1          0x00002000                                      /*  Analog Comparator 1 */
#define ADC_EMUX_EM3_COMP2          0x00003000                                      /*  Analog Comparator 2 */
#define ADC_EMUX_EM3_EXTERNAL       0x00004000                                      /*  External (GPIO Pins) */
#define ADC_EMUX_EM3_TIMER          0x00005000                                      /*  Timer */
#define ADC_EMUX_EM3_PWM0           0x00006000                                      /*  PWM generator 0 */
#define ADC_EMUX_EM3_PWM1           0x00007000                                      /*  PWM generator 1 */
#define ADC_EMUX_EM3_PWM2           0x00008000                                      /*  PWM generator 2 */
#define ADC_EMUX_EM3_PWM3           0x00009000                                      /*  PWM generator 3 */
#define ADC_EMUX_EM3_NEVER          0x0000E000                                      /*  Never Trigger */
#define ADC_EMUX_EM3_ALWAYS         0x0000F000                                      /*  Always (continuously sample) */
#define ADC_EMUX_EM2_M              0x00000F00                                      /*  SS2 Trigger Select Mask */
#define ADC_EMUX_EM2_PROCESSOR      0x00000000                                      /*  Processor (default) */
#define ADC_EMUX_EM2_COMP0          0x00000100                                      /*  Analog Comparator 0 */
#define ADC_EMUX_EM2_COMP1          0x00000200                                      /*  Analog Comparator 1 */
#define ADC_EMUX_EM2_COMP2          0x00000300                                      /*  Analog Comparator 2 */
#define ADC_EMUX_EM2_EXTERNAL       0x00000400                                      /*  External (GPIO Pins) */
#define ADC_EMUX_EM2_TIMER          0x00000500                                      /*  Timer */
#define ADC_EMUX_EM2_PWM0           0x00000600                                      /*  PWM generator 0 */
#define ADC_EMUX_EM2_PWM1           0x00000700                                      /*  PWM generator 1 */
#define ADC_EMUX_EM2_PWM2           0x00000800                                      /*  PWM generator 2 */
#define ADC_EMUX_EM2_PWM3           0x00000900                                      /*  PWM generator 3 */
#define ADC_EMUX_EM2_NEVER          0x00000E00                                      /*  Never Trigger */
#define ADC_EMUX_EM2_ALWAYS         0x00000F00                                      /*  Always (continuously sample) */
#define ADC_EMUX_EM1_M              0x000000F0                                      /*  SS1 Trigger Select Mask */
#define ADC_EMUX_EM1_PROCESSOR      0x00000000                                      /*  Processor (default) */
#define ADC_EMUX_EM1_COMP0          0x00000010                                      /*  Analog Comparator 0 */
#define ADC_EMUX_EM1_COMP1          0x00000020                                      /*  Analog Comparator 1 */
#define ADC_EMUX_EM1_COMP2          0x00000030                                      /*  Analog Comparator 2 */
#define ADC_EMUX_EM1_EXTERNAL       0x00000040                                      /*  External (GPIO Pins) */
#define ADC_EMUX_EM1_TIMER          0x00000050                                      /*  Timer */
#define ADC_EMUX_EM1_PWM0           0x00000060                                      /*  PWM generator 0 */
#define ADC_EMUX_EM1_PWM1           0x00000070                                      /*  PWM generator 1 */
#define ADC_EMUX_EM1_PWM2           0x00000080                                      /*  PWM generator 2 */
#define ADC_EMUX_EM1_PWM3           0x00000090                                      /*  PWM generator 3 */
#define ADC_EMUX_EM1_NEVER          0x000000E0                                      /*  Never Trigger */
#define ADC_EMUX_EM1_ALWAYS         0x000000F0                                      /*  Always (continuously sample) */
#define ADC_EMUX_EM0_M              0x0000000F                                      /*  SS0 Trigger Select Mask */
#define ADC_EMUX_EM0_PROCESSOR      0x00000000                                      /*  Processor (default) */
#define ADC_EMUX_EM0_COMP0          0x00000001                                      /*  Analog Comparator 0 */
#define ADC_EMUX_EM0_COMP1          0x00000002                                      /*  Analog Comparator 1 */
#define ADC_EMUX_EM0_COMP2          0x00000003                                      /*  Analog Comparator 2 */
#define ADC_EMUX_EM0_EXTERNAL       0x00000004                                      /*  External (GPIO Pins) */
#define ADC_EMUX_EM0_TIMER          0x00000005                                      /*  Timer */
#define ADC_EMUX_EM0_PWM0           0x00000006                                      /*  PWM generator 0 */
#define ADC_EMUX_EM0_PWM1           0x00000007                                      /*  PWM generator 1 */
#define ADC_EMUX_EM0_PWM2           0x00000008                                      /*  PWM generator 2 */
#define ADC_EMUX_EM0_PWM3           0x00000009                                      /*  PWM generator 3 */
#define ADC_EMUX_EM0_NEVER          0x0000000E                                      /*  Never Trigger */
#define ADC_EMUX_EM0_ALWAYS         0x0000000F                                      /*  Always (continuously sample) */

    // Bit fields in the ADC_SSPRI register                                             pp1099
#define ADC_SSPRI_SS3_M             0x00003000                                      /*  SS3 Priority Mask */
#define ADC_SSPRI_SS2_M             0x00000300                                      /*  SS2 Priority Mask */
#define ADC_SSPRI_SS1_M             0x00000030                                      /*  SS1 Priority Mask */
#define ADC_SSPRI_SS0_M             0x00000003                                      /*  SS0 Priority Mask */
#define ADC_SSPRI_SS3_S             12                                              /*  SS3 Priority Shift */
#define ADC_SSPRI_SS2_S             8                                               /*  SS2 Priority Shift */
#define ADC_SSPRI_SS1_S             4                                               /*  SS1 Priority Shift */
#define ADC_SSPRI_SS0_S             0                                               /*  SS0 Priority Shift */

    // Bit fields in the ADC_PSSI register                                              pp1103
#define ADC_PSSI_GSYNC              0x80000000                                      /*  Global Synchronize */
#define ADC_PSSI_SYNCWAIT           0x08000000                                      /*  Synchronize Wait */
#define ADC_PSSI_SS3                0x00000008                                      /*  SS3 Initiate */
#define ADC_PSSI_SS2                0x00000004                                      /*  SS2 Initiate */
#define ADC_PSSI_SS1                0x00000002                                      /*  SS1 Initiate */
#define ADC_PSSI_SS0                0x00000001                                      /*  SS0 Initiate */

    // Bit fields in the ADC_SSMUX1 register                                            pp1129
#define ADC_SSMUX1_MUX3_M           0x0000F000                                      /*  4th Sample Input Select Mask */
#define ADC_SSMUX1_MUX2_M           0x00000F00                                      /*  3rd Sample Input Select Mask */
#define ADC_SSMUX1_MUX1_M           0x000000F0                                      /*  2nd Sample Input Select Mask */
#define ADC_SSMUX1_MUX0_M           0x0000000F                                      /*  1st Sample Input Select Mask */
#define ADC_SSMUX1_MUX3_S           12                                              /*  4th Sample Input Select Shift */
#define ADC_SSMUX1_MUX2_S           8                                               /*  3rd Sample Input Select Shift */
#define ADC_SSMUX1_MUX1_S           4                                               /*  2nd Sample Input Select Shift */
#define ADC_SSMUX1_MUX0_S           0                                               /*  1st Sample Input Select Shift */

    // Bit fields in the ADC_SSCTL1 register                                            pp1130
#define ADC_SSCTL1_TS3              0x00008000                                      /*  4th Sample Temp Sensor Select */
#define ADC_SSCTL1_IE3              0x00004000                                      /*  4th Sample Interrupt Enable */
#define ADC_SSCTL1_END3             0x00002000                                      /*  4th Sample is End of Sequence */
#define ADC_SSCTL1_D3               0x00001000                                      /*  4th Sample Differential Input Select */
#define ADC_SSCTL1_TS2              0x00000800                                      /*  3rd Sample Temp Sensor Select */
#define ADC_SSCTL1_IE2              0x00000400                                      /*  3rd Sample Interrupt Enable */
#define ADC_SSCTL1_END2             0x00000200                                      /*  3rd Sample is End of Sequence */
#define ADC_SSCTL1_D2               0x00000100                                      /*  3rd Sample Differential Input Select */
#define ADC_SSCTL1_TS1              0x00000080                                      /*  2nd Sample Temp Sensor Select */
#define ADC_SSCTL1_IE1              0x00000040                                      /*  2nd Sample Interrupt Enable */
#define ADC_SSCTL1_END1             0x00000020                                      /*  2nd Sample is End of Sequence */
#define ADC_SSCTL1_D1               0x00000010                                      /*  2nd Sample Differential Input Select */
#define ADC_SSCTL1_TS0              0x00000008                                      /*  1st Sample Temp Sensor Select */
#define ADC_SSCTL1_IE0              0x00000004                                      /*  1st Sample Interrupt Enable */
#define ADC_SSCTL1_END0             0x00000002                                      /*  1st Sample is End of Sequence */
#define ADC_SSCTL1_D0               0x00000001                                      /*  1st Sample Differential Input Select */

    // Bit fields in the ADC_SSFIFO1 register                                           pp1118
#define ADC_SSFIFO1_DATA_M          0x00000FFF                                      /*  Conversion Result Data Mask */
#define ADC_SSFIFO1_DATA_S          0                                               /*  Conversion Result Data Shift */

    // Bit fields in the ADC_SSEMUX1 register                                           pp1137
#define ADC_SSEMUX1_EMUX3           0x00001000                                      /*  4th Sample Input Select (Upper Bit) */
#define ADC_SSEMUX1_EMUX2           0x00000100                                      /*  3rd Sample Input Select (Upper Bit) */
#define ADC_SSEMUX1_EMUX1           0x00000010                                      /*  2th Sample Input Select (Upper Bit) */
#define ADC_SSEMUX1_EMUX0           0x00000001                                      /*  1st Sample Input Select (Upper Bit) */

    // Bit fields in the ADC_CC register                                                pp1160
#define ADC_CC_CLKDIV_M             0x000003F0                                      /*  PLL VCO Clock Divisor Mask */
#define ADC_CC_CS_M                 0x0000000F                                      /*  ADC Clock Source Mask */
#define ADC_CC_CS_SYSPLL            0x00000000                                      /*  PLL VCO divided by CLKDIV */
#define ADC_CC_CS_PIOSC             0x00000001                                      /*  PIOSC */
#define ADC_CC_CS_MOSC              0x00000002                                      /*  MOSC */
#define ADC_CC_CLKDIV_S             4                                               /*  PLL VCO Clock Divisor Shift */

    /*  Habilitación del ADC */
#define ADC0_SS1_Initiate()         (ADC0_PSSI_R |= ADC_PSSI_SS1)                   /*  ADC0 => SS1 Initiate -> Begin sampling on SS1 */

    /*  Lectura del estado del ADC */
#define ADC0_SS1_RawInterrupt_wait()    while (!(ADC0_RIS_R & ADC_RIS_INR1)) {}     /*  Esperar la interrupción cruda del ADC0 SS1 */

    /*  Lectura del resultado de conversión */
#define ADC0_SS1_FIFOread()         (ADC0_SSFIFO1_R & ADC_SSFIFO1_DATA_M)           /*  ADC0 => SS1 -> Lectura del resultado de conversión */

    /*  Limpieza de las banderas INn (ADCISC) y INRn (ADCRIS) */
#define ADC0_SS1_ClearFlags()       (ADC0_ISC_R |= ADC_ISC_IN1)                     /*  ADC0 => Limpieza de las banderas IN1 (ADCISC) y INR1 (ADCRIS) */

/*********************************************************************************
 * Prototipos de funciones públicas
 */

void ADC0_SS1_Init();                                                               /*  Inicialización del ADC0 SS1 */


#endif
