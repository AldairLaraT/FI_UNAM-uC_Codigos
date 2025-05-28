/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       27 de mayo de 2025
 * 
 * Código:      Archivo de cabecera del I2C
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef I2C_H                                                                       /*  Verificar si I2C_H no ha sido definido previamente */
#define I2C_H                                                                       /*  Definir I2C_H para evitar inclusiones múltiples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * Inter-Integrated Circuit (I2C) registers                                             pp1299  Register map
 */

    /*  I2C module 0 (I2C0) */
    // I2C Master
#define I2C0_MSA_R                  (*((volatile uint32_t *)0x40020000))            /*  pp1302  I2C Master Slave Address */
#define I2C0_MCS_R                  (*((volatile uint32_t *)0x40020004))            /*  pp1303  I2C Master Control/Status */
#define I2C0_MDR_R                  (*((volatile uint32_t *)0x40020008))            /*  pp1312  I2C Master Data */
#define I2C0_MTPR_R                 (*((volatile uint32_t *)0x4002000C))            /*  pp1313  I2C Master Timer Period */
#define I2C0_MRIS_R                 (*((volatile uint32_t *)0x40020014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C0_MICR_R                 (*((volatile uint32_t *)0x4002001C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C0_MCR_R                  (*((volatile uint32_t *)0x40020020))            /*  pp1326  I2C Master Configuration */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the I2C_MSA register                                               pp1302
#define I2C_MSA_SA_M                0x000000FE                                      /*  I2C Slave Address mask */
#define I2C_MSA_RS                  0x00000001                                      /*  Receive not send */
#define I2C_MSA_SA_S                1                                               /*  I2C Slave Address shift */

    // Bit fields in the I2C_MCS register                                               pp1303
#define I2C_MCS_ACTDMARX            0x80000000                                      /*  DMA RX Active Status */
#define I2C_MCS_ACTDMATX            0x40000000                                      /*  DMA TX Active Status */
#define I2C_MCS_CLKTO               0x00000080                                      /*  Clock Timeout Error */
#define I2C_MCS_BURST               0x00000040                                      /*  Burst Enable */
#define I2C_MCS_BUSBSY              0x00000040                                      /*  Bus Busy */
#define I2C_MCS_IDLE                0x00000020                                      /*  I2C Idle */
#define I2C_MCS_QCMD                0x00000020                                      /*  Quick Command */
#define I2C_MCS_ARBLST              0x00000010                                      /*  Arbitration Lost */
#define I2C_MCS_HS                  0x00000010                                      /*  High-Speed Enable */
#define I2C_MCS_ACK                 0x00000008                                      /*  Data Acknowledge Enable */
#define I2C_MCS_DATACK              0x00000008                                      /*  Acknowledge Data */
#define I2C_MCS_ADRACK              0x00000004                                      /*  Acknowledge Address */
#define I2C_MCS_STOP                0x00000004                                      /*  Generate STOP */
#define I2C_MCS_ERROR               0x00000002                                      /*  Error */
#define I2C_MCS_START               0x00000002                                      /*  Generate START */
#define I2C_MCS_RUN                 0x00000001                                      /*  I2C Master Enable */
#define I2C_MCS_BUSY                0x00000001                                      /*  I2C Busy */

    // Bit fields in the I2C_MDR register                                               pp1312
#define I2C_MDR_DATA_M              0x000000FF                                      /*  This byte contains the data transferred during a transaction mask */
#define I2C_MDR_DATA_S              0                                               /*  This byte contains the data transferred during a transaction shift */

    // Bit fields in the I2C_MTPR register                                              pp1313
#define I2C_MTPR_PULSEL_M           0x00070000                                      /*  Glitch Suppression Pulse Width mask */
#define I2C_MTPR_PULSEL_BYPASS      0x00000000                                      /*  Bypass */
#define I2C_MTPR_PULSEL_1           0x00010000                                      /*  1 clock */
#define I2C_MTPR_PULSEL_2           0x00020000                                      /*  2 clocks */
#define I2C_MTPR_PULSEL_3           0x00030000                                      /*  3 clocks */
#define I2C_MTPR_PULSEL_4           0x00040000                                      /*  4 clocks */
#define I2C_MTPR_PULSEL_8           0x00050000                                      /*  8 clocks */
#define I2C_MTPR_PULSEL_16          0x00060000                                      /*  16 clocks */
#define I2C_MTPR_PULSEL_31          0x00070000                                      /*  31 clocks */
#define I2C_MTPR_HS                 0x00000080                                      /*  High-Speed Enable */
#define I2C_MTPR_TPR_M              0x0000007F                                      /*  Timer Period mask */
#define I2C_MTPR_TPR_S              0                                               /*  Timer Period shift */

    // Bit fields in the I2C_MRIS register                                              pp1318
#define I2C_MRIS_RXFFRIS            0x00000800                                      /*  Receive FIFO Full Raw Interrupt Status */
#define I2C_MRIS_TXFERIS            0x00000400                                      /*  Transmit FIFO Empty Raw Interrupt Status */
#define I2C_MRIS_RXRIS              0x00000200                                      /*  Receive FIFO Request Raw Interrupt Status */
#define I2C_MRIS_TXRIS              0x00000100                                      /*  Transmit Request Raw Interrupt Status */
#define I2C_MRIS_ARBLOSTRIS         0x00000080                                      /*  Arbitration Lost Raw Interrupt Status */
#define I2C_MRIS_STOPRIS            0x00000040                                      /*  STOP Detection Raw Interrupt Status */
#define I2C_MRIS_STARTRIS           0x00000020                                      /*  START Detection Raw Interrupt Status */
#define I2C_MRIS_NACKRIS            0x00000010                                      /*  Address/Data NACK Raw Interrupt Status */
#define I2C_MRIS_DMATXRIS           0x00000008                                      /*  Transmit DMA Raw Interrupt Status */
#define I2C_MRIS_DMARXRIS           0x00000004                                      /*  Receive DMA Raw Interrupt Status */
#define I2C_MRIS_CLKRIS             0x00000002                                      /*  Clock Timeout Raw Interrupt Status */
#define I2C_MRIS_RIS                0x00000001                                      /*  Master Raw Interrupt Status */

    // Bit fields in the I2C_MICR register                                              pp1324
#define I2C_MICR_RXFFIC             0x00000800                                      /*  Receive FIFO Full Interrupt Clear */
#define I2C_MICR_TXFEIC             0x00000400                                      /*  Transmit FIFO Empty Interrupt Clear */
#define I2C_MICR_RXIC               0x00000200                                      /*  Receive FIFO Request Interrupt Clear */
#define I2C_MICR_TXIC               0x00000100                                      /*  Transmit FIFO Request Interrupt Clear */
#define I2C_MICR_ARBLOSTIC          0x00000080                                      /*  Arbitration Lost Interrupt Clear */
#define I2C_MICR_STOPIC             0x00000040                                      /*  STOP Detection Interrupt Clear */
#define I2C_MICR_STARTIC            0x00000020                                      /*  START Detection Interrupt Clear */
#define I2C_MICR_NACKIC             0x00000010                                      /*  Address/Data NACK Interrupt Clear */
#define I2C_MICR_DMATXIC            0x00000008                                      /*  Transmit DMA Interrupt Clear */
#define I2C_MICR_DMARXIC            0x00000004                                      /*  Receive DMA Interrupt Clear */
#define I2C_MICR_CLKIC              0x00000002                                      /*  Clock Timeout Interrupt Clear */
#define I2C_MICR_IC                 0x00000001                                      /*  Master Interrupt Clear */

    // Bit fields in the I2C_MCR register                                               pp1326
#define I2C_MCR_SFE                 0x00000020                                      /*  I2C Slave Function Enable */
#define I2C_MCR_MFE                 0x00000010                                      /*  I2C Master Function Enable */
#define I2C_MCR_LPBK                0x00000001                                      /*  I2C Loopback */

    /*  Lectura del estado del I2C */
#define I2C0_BUSY_wait()            while (I2C0_MCS_R & I2C_MCS_BUSY) {}            /*  I2C0 => BUSY: I2C Busy -> The controller is busy */
#define I2C0_RawInterrupt_wait()    while (!(I2C0_MRIS_R & I2C_MRIS_RIS)) {}        /*  I2C0 => RIS: Master Raw Interrupt Status -> A master interrupt is pending */

    /*  Limpieza de la bandera RIS (I2CMRIS) */
#define I2C0_ClearFlags()           (I2C0_MICR_R |= I2C_MICR_IC)                    /*  I2C0 => IC: Master Interrupt Clear -> RIS bit (I2CMRIS) and MIS bit (I2CMMIS) cleared */

    /*  Lectura de error en la última operación (I2CMCS) */
#define I2C0_ErrorFlag              (I2C0_MCS_R & I2C_MCS_ERROR)                    /*  I2C0 => ERROR: Error -> An error occurred on the last operation */


/*********************************************************************************
 * Prototipos de funciones públicas
 */

void I2C0_Init(void);                                                               /*  Inicialización del I2C0 */
int I2C0_MasterBUSY(void);                                                          /*  I2C0 => Esperar a que termine la última operación */
void I2C0_Transmit(uint8_t SlaveAddress, uint8_t StartPointer, uint8_t Data[], int index);      /*  I2C0 => Transmisión de datos */
void I2C0_Receive(uint8_t SlaveAddress, uint8_t StartPointer, uint8_t RawData[], int index);    /*  I2C0 => Recepción de datos */


#endif                                                                              /*  I2C_H */
