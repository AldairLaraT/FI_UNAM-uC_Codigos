/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de mayo de 2025
 * 
 * Código:      Archivo de cabecera del UART
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef UART_H                                                                      /*  Verificar si UART_H no ha sido definido previamente */
#define UART_H                                                                      /*  Definir UART_H para evitar inclusiones múltiples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * Universal Asynchronous Receiver/Transmitter (UART) registers                         pp1173  Register map
 */

    /*  UART module 0 (UART0) */
#define UART0_DR_R                  (*((volatile uint32_t *)0x4000C000))            /*  pp1175  UART Data */
#define UART0_FR_R                  (*((volatile uint32_t *)0x4000C018))            /*  pp1180  UART Flag */
#define UART0_IBRD_R                (*((volatile uint32_t *)0x4000C024))            /*  pp1184  UART Integer Baud-Rate Divisor */
#define UART0_FBRD_R                (*((volatile uint32_t *)0x4000C028))            /*  pp1185  UART Fractional Baud-Rate Divisor */
#define UART0_LCRH_R                (*((volatile uint32_t *)0x4000C02C))            /*  pp1186  UART Line Control */
#define UART0_CTL_R                 (*((volatile uint32_t *)0x4000C030))            /*  pp1188  UART Control */
#define UART0_IFLS_R                (*((volatile uint32_t *)0x4000C034))            /*  pp1192  UART Interrupt FIFO Level Select */
#define UART0_IM_R                  (*((volatile uint32_t *)0x4000C038))            /*  pp1194  UART Interrupt Mask */
#define UART0_ICR_R                 (*((volatile uint32_t *)0x4000C044))            /*  pp1206  UART Interrupt Clear */
#define UART0_CC_R                  (*((volatile uint32_t *)0x4000CFC8))            /*  pp1213  UART Clock Configuration */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the UART_DR register                                               pp1175
#define UART_DR_OE                  0x00000800                                      /*  UART Overrun Error */
#define UART_DR_BE                  0x00000400                                      /*  UART Break Error */
#define UART_DR_PE                  0x00000200                                      /*  UART Parity Error */
#define UART_DR_FE                  0x00000100                                      /*  UART Framing Error */
#define UART_DR_DATA_M              0x000000FF                                      /*  Data Transmitted or Received mask */
#define UART_DR_DATA_S              0                                               /*  Data Transmitted or Received shift */

    // Bit fields in the UART_FR register                                               pp1180
#define UART_FR_RI                  0x00000100                                      /*  Ring Indicator */
#define UART_FR_TXFE                0x00000080                                      /*  UART Transmit FIFO Empty */
#define UART_FR_RXFF                0x00000040                                      /*  UART Receive FIFO Full */
#define UART_FR_TXFF                0x00000020                                      /*  UART Transmit FIFO Full */
#define UART_FR_RXFE                0x00000010                                      /*  UART Receive FIFO Empty */
#define UART_FR_BUSY                0x00000008                                      /*  UART Busy */
#define UART_FR_DCD                 0x00000004                                      /*  Data Carrier Detect */
#define UART_FR_DSR                 0x00000002                                      /*  Data Set Ready */
#define UART_FR_CTS                 0x00000001                                      /*  Clear To Send */

    // Bit fields in the UART_IBRD register                                             pp1184
#define UART_IBRD_DIVINT_M          0x0000FFFF                                      /*  Integer Baud-Rate Divisor mask */
#define UART_IBRD_DIVINT_S          0                                               /*  Integer Baud-Rate Divisor shift */

    // Bit fields in the UART_FBRD register                                             pp1185
#define UART_FBRD_DIVFRAC_M         0x0000003F                                      /*  Fractional Baud-Rate Divisor mask */
#define UART_FBRD_DIVFRAC_S         0                                               /*  Fractional Baud-Rate Divisor shift */

    // Bit fields in the UART_LCRH register                                             pp1186
#define UART_LCRH_SPS               0x00000080                                      /*  UART Stick Parity Select */
#define UART_LCRH_WLEN_M            0x00000060                                      /*  UART Word Length mask */
#define UART_LCRH_WLEN_5            0x00000000                                      /*  5 bits (default) */
#define UART_LCRH_WLEN_6            0x00000020                                      /*  6 bits */
#define UART_LCRH_WLEN_7            0x00000040                                      /*  7 bits */
#define UART_LCRH_WLEN_8            0x00000060                                      /*  8 bits */
#define UART_LCRH_FEN               0x00000010                                      /*  UART Enable FIFOs */
#define UART_LCRH_STP2              0x00000008                                      /*  UART Two Stop Bits Select */
#define UART_LCRH_EPS               0x00000004                                      /*  UART Even Parity Select */
#define UART_LCRH_PEN               0x00000002                                      /*  UART Parity Enable */
#define UART_LCRH_BRK               0x00000001                                      /*  UART Send Break */

    // Bit fields in the UART_CTL register                                              pp1188
#define UART_CTL_CTSEN              0x00008000                                      /*  Enable Clear To Send */
#define UART_CTL_RTSEN              0x00004000                                      /*  Enable Request to Send */
#define UART_CTL_RTS                0x00000800                                      /*  Request to Send */
#define UART_CTL_DTR                0x00000400                                      /*  Data Terminal Ready */
#define UART_CTL_RXE                0x00000200                                      /*  UART Receive Enable */
#define UART_CTL_TXE                0x00000100                                      /*  UART Transmit Enable */
#define UART_CTL_LBE                0x00000080                                      /*  UART Loop Back Enable */
#define UART_CTL_HSE                0x00000020                                      /*  High-Speed Enable */
#define UART_CTL_EOT                0x00000010                                      /*  End of Transmission */
#define UART_CTL_SMART              0x00000008                                      /*  ISO 7816 Smart Card Support */
#define UART_CTL_SIRLP              0x00000004                                      /*  UART SIR Low-Power Mode */
#define UART_CTL_SIREN              0x00000002                                      /*  UART SIR Enable */
#define UART_CTL_UARTEN             0x00000001                                      /*  UART Enable */

    // Bit fields in the UART_IFLS register                                             pp1192
#define UART_IFLS_RX_M              0x00000038                                      /*  UART Receive Interrupt FIFO Level Select mask */
#define UART_IFLS_RX1_8             0x00000000                                      /*  RX FIFO >= 1/8 full */
#define UART_IFLS_RX2_8             0x00000008                                      /*  RX FIFO >= 1/4 full */
#define UART_IFLS_RX4_8             0x00000010                                      /*  RX FIFO >= 1/2 full (default) */
#define UART_IFLS_RX6_8             0x00000018                                      /*  RX FIFO >= 3/4 full */
#define UART_IFLS_RX7_8             0x00000020                                      /*  RX FIFO >= 7/8 full */
#define UART_IFLS_TX_M              0x00000007                                      /*  UART Transmit Interrupt FIFO Level Select mask */
#define UART_IFLS_TX1_8             0x00000000                                      /*  TX FIFO <= 1/8 full */
#define UART_IFLS_TX2_8             0x00000001                                      /*  TX FIFO <= 1/4 full */
#define UART_IFLS_TX4_8             0x00000002                                      /*  TX FIFO <= 1/2 full (default) */
#define UART_IFLS_TX6_8             0x00000003                                      /*  TX FIFO <= 3/4 full */
#define UART_IFLS_TX7_8             0x00000004                                      /*  TX FIFO <= 7/8 full */

    // Bit fields in the UART_IM register                                               pp1194
#define UART_IM_DMATXIM             0x00020000                                      /*  Transmit DMA Interrupt Mask */
#define UART_IM_DMARXIM             0x00010000                                      /*  Receive DMA Interrupt Mask */
#define UART_IM_9BITIM              0x00001000                                      /*  9-Bit Mode Interrupt Mask */
#define UART_IM_EOTIM               0x00000800                                      /*  End of Transmission Interrupt Mask */
#define UART_IM_OEIM                0x00000400                                      /*  UART Overrun Error Interrupt Mask */
#define UART_IM_BEIM                0x00000200                                      /*  UART Break Error Interrupt Mask */
#define UART_IM_PEIM                0x00000100                                      /*  UART Parity Error Interrupt Mask */
#define UART_IM_FEIM                0x00000080                                      /*  UART Framing Error Interrupt Mask */
#define UART_IM_RTIM                0x00000040                                      /*  UART Receive Time-Out Interrupt Mask */
#define UART_IM_TXIM                0x00000020                                      /*  UART Transmit Interrupt Mask */
#define UART_IM_RXIM                0x00000010                                      /*  UART Receive Interrupt Mask */
#define UART_IM_DSRMIM              0x00000008                                      /*  UART Data Set Ready Modem Interrupt Mask */
#define UART_IM_DCDMIM              0x00000004                                      /*  UART Data Carrier Detect Modem Interrupt Mask */
#define UART_IM_CTSMIM              0x00000002                                      /*  UART Clear to Send Modem Interrupt Mask */
#define UART_IM_RIMIM               0x00000001                                      /*  UART Ring Indicator Modem Interrupt Mask */

    // Bit fields in the UART_ICR register                                              pp1206
#define UART_ICR_DMATXIC            0x00020000                                      /*  Transmit DMA Interrupt Clear */
#define UART_ICR_DMARXIC            0x00010000                                      /*  Receive DMA Interrupt Clear */
#define UART_ICR_9BITIC             0x00001000                                      /*  9-Bit Mode Interrupt Clear */
#define UART_ICR_EOTIC              0x00000800                                      /*  End of Transmission Interrupt Clear */
#define UART_ICR_OEIC               0x00000400                                      /*  Overrun Error Interrupt Clear */
#define UART_ICR_BEIC               0x00000200                                      /*  Break Error Interrupt Clear */
#define UART_ICR_PEIC               0x00000100                                      /*  Parity Error Interrupt Clear */
#define UART_ICR_FEIC               0x00000080                                      /*  Framing Error Interrupt Clear */
#define UART_ICR_RTIC               0x00000040                                      /*  Receive Time-Out Interrupt Clear */
#define UART_ICR_TXIC               0x00000020                                      /*  Transmit Interrupt Clear */
#define UART_ICR_RXIC               0x00000010                                      /*  Receive Interrupt Clear */
#define UART_ICR_DSRMIC             0x00000008                                      /*  UART Data Set Ready Modem Interrupt Clear */
#define UART_ICR_DCDMIC             0x00000004                                      /*  UART Data Carrier Detect Modem Interrupt Clear */
#define UART_ICR_CTSMIC             0x00000002                                      /*  UART Clear to Send Modem Interrupt Clear */
#define UART_ICR_RIMIC              0x00000001                                      /*  UART Ring Indicator Modem Interrupt Clear */

    // Bit fields in the UART_CC register                                               pp1213
#define UART_CC_CS_M                0x0000000F                                      /*  UART Baud Clock Source mask */
#define UART_CC_CS_SYSCLK           0x00000000                                      /*  System clock (based on clock source and divisor factor) */
#define UART_CC_CS_PIOSC            0x00000005                                      /*  PIOSC */

    /*  Lectura de los botones de usuario (SWn) */
#define UART0_DataTransmit()        while (!(UART0_FR_R & UART_FR_TXFE)) {}         /*  UART0 => TXFE: UART Transmit FIFO Empty -> The transmitter has data to transmit */


/*********************************************************************************
 * Prototipos de funciones públicas
 */

void UART0_Init();                                                                  /*  Inicialización del UART0 */
void UART0_Transmit(char message[], int message_size);                              /*  Transmisión de datos a través de UART0 */


#endif                                                                              /*  UART_H */
