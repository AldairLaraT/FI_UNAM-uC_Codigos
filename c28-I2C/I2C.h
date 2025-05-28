/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       [] de [] de []
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
#define I2C0_MIMR_R                 (*((volatile uint32_t *)0x40020010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C0_MRIS_R                 (*((volatile uint32_t *)0x40020014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C0_MMIS_R                 (*((volatile uint32_t *)0x40020018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C0_MICR_R                 (*((volatile uint32_t *)0x4002001C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C0_MCR_R                  (*((volatile uint32_t *)0x40020020))            /*  pp1326  I2C Master Configuration */
#define I2C0_MCLKOCNT_R             (*((volatile uint32_t *)0x40020024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C0_MBMON_R                (*((volatile uint32_t *)0x4002002C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C0_MBLEN_R                (*((volatile uint32_t *)0x40020030))            /*  pp1329  I2C Master Burst Length */
#define I2C0_MBCNT_R                (*((volatile uint32_t *)0x40020034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C0_SOAR_R                 (*((volatile uint32_t *)0x40020800))            /*  pp1331  I2C Slave Own Address */
#define I2C0_SCSR_R                 (*((volatile uint32_t *)0x40020804))            /*  pp1332  I2C Slave Control/Status */
#define I2C0_SDR_R                  (*((volatile uint32_t *)0x40020808))            /*  pp1335  I2C Slave Data */
#define I2C0_SIMR_R                 (*((volatile uint32_t *)0x4002080C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C0_SRIS_R                 (*((volatile uint32_t *)0x40020810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C0_SMIS_R                 (*((volatile uint32_t *)0x40020814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C0_SICR_R                 (*((volatile uint32_t *)0x40020818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C0_SOAR2_R                (*((volatile uint32_t *)0x4002081C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C0_SACKCTL_R              (*((volatile uint32_t *)0x40020820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C0_FIFODATA_R             (*((volatile uint32_t *)0x40020F00))            /*  pp1348  I2C FIFO Data */
#define I2C0_FIFOCTL_R              (*((volatile uint32_t *)0x40020F04))            /*  pp1350  I2C FIFO Control */
#define I2C0_FIFOSTATUS_R           (*((volatile uint32_t *)0x40020F08))            /*  pp1352  I2C FIFO Status */
#define I2C0_PP_R                   (*((volatile uint32_t *)0x40020FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C0_PC_R                   (*((volatile uint32_t *)0x40020FC4))            /*  pp1355  I2C Peripheral Configuration */

    /*  I2C module 1 (I2C1) */
    // I2C Master
#define I2C1_MSA_R                  (*((volatile uint32_t *)0x40021000))            /*  pp1302  I2C Master Slave Address */
#define I2C1_MCS_R                  (*((volatile uint32_t *)0x40021004))            /*  pp1303  I2C Master Control/Status */
#define I2C1_MDR_R                  (*((volatile uint32_t *)0x40021008))            /*  pp1312  I2C Master Data */
#define I2C1_MTPR_R                 (*((volatile uint32_t *)0x4002100C))            /*  pp1313  I2C Master Timer Period */
#define I2C1_MIMR_R                 (*((volatile uint32_t *)0x40021010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C1_MRIS_R                 (*((volatile uint32_t *)0x40021014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C1_MMIS_R                 (*((volatile uint32_t *)0x40021018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C1_MICR_R                 (*((volatile uint32_t *)0x4002101C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C1_MCR_R                  (*((volatile uint32_t *)0x40021020))            /*  pp1326  I2C Master Configuration */
#define I2C1_MCLKOCNT_R             (*((volatile uint32_t *)0x40021024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C1_MBMON_R                (*((volatile uint32_t *)0x4002102C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C1_MBLEN_R                (*((volatile uint32_t *)0x40021030))            /*  pp1329  I2C Master Burst Length */
#define I2C1_MBCNT_R                (*((volatile uint32_t *)0x40021034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C1_SOAR_R                 (*((volatile uint32_t *)0x40021800))            /*  pp1331  I2C Slave Own Address */
#define I2C1_SCSR_R                 (*((volatile uint32_t *)0x40021804))            /*  pp1332  I2C Slave Control/Status */
#define I2C1_SDR_R                  (*((volatile uint32_t *)0x40021808))            /*  pp1335  I2C Slave Data */
#define I2C1_SIMR_R                 (*((volatile uint32_t *)0x4002180C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C1_SRIS_R                 (*((volatile uint32_t *)0x40021810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C1_SMIS_R                 (*((volatile uint32_t *)0x40021814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C1_SICR_R                 (*((volatile uint32_t *)0x40021818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C1_SOAR2_R                (*((volatile uint32_t *)0x4002181C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C1_SACKCTL_R              (*((volatile uint32_t *)0x40021820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C1_FIFODATA_R             (*((volatile uint32_t *)0x40021F00))            /*  pp1348  I2C FIFO Data */
#define I2C1_FIFOCTL_R              (*((volatile uint32_t *)0x40021F04))            /*  pp1350  I2C FIFO Control */
#define I2C1_FIFOSTATUS_R           (*((volatile uint32_t *)0x40021F08))            /*  pp1352  I2C FIFO Status */
#define I2C1_PP_R                   (*((volatile uint32_t *)0x40021FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C1_PC_R                   (*((volatile uint32_t *)0x40021FC4))            /*  pp1355  I2C Peripheral Configuration */

    /*  I2C module 2 (I2C2) */
    // I2C Master
#define I2C2_MSA_R                  (*((volatile uint32_t *)0x40022000))            /*  pp1302  I2C Master Slave Address */
#define I2C2_MCS_R                  (*((volatile uint32_t *)0x40022004))            /*  pp1303  I2C Master Control/Status */
#define I2C2_MDR_R                  (*((volatile uint32_t *)0x40022008))            /*  pp1312  I2C Master Data */
#define I2C2_MTPR_R                 (*((volatile uint32_t *)0x4002200C))            /*  pp1313  I2C Master Timer Period */
#define I2C2_MIMR_R                 (*((volatile uint32_t *)0x40022010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C2_MRIS_R                 (*((volatile uint32_t *)0x40022014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C2_MMIS_R                 (*((volatile uint32_t *)0x40022018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C2_MICR_R                 (*((volatile uint32_t *)0x4002201C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C2_MCR_R                  (*((volatile uint32_t *)0x40022020))            /*  pp1326  I2C Master Configuration */
#define I2C2_MCLKOCNT_R             (*((volatile uint32_t *)0x40022024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C2_MBMON_R                (*((volatile uint32_t *)0x4002202C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C2_MBLEN_R                (*((volatile uint32_t *)0x40022030))            /*  pp1329  I2C Master Burst Length */
#define I2C2_MBCNT_R                (*((volatile uint32_t *)0x40022034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C2_SOAR_R                 (*((volatile uint32_t *)0x40022800))            /*  pp1331  I2C Slave Own Address */
#define I2C2_SCSR_R                 (*((volatile uint32_t *)0x40022804))            /*  pp1332  I2C Slave Control/Status */
#define I2C2_SDR_R                  (*((volatile uint32_t *)0x40022808))            /*  pp1335  I2C Slave Data */
#define I2C2_SIMR_R                 (*((volatile uint32_t *)0x4002280C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C2_SRIS_R                 (*((volatile uint32_t *)0x40022810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C2_SMIS_R                 (*((volatile uint32_t *)0x40022814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C2_SICR_R                 (*((volatile uint32_t *)0x40022818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C2_SOAR2_R                (*((volatile uint32_t *)0x4002281C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C2_SACKCTL_R              (*((volatile uint32_t *)0x40022820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C2_FIFODATA_R             (*((volatile uint32_t *)0x40022F00))            /*  pp1348  I2C FIFO Data */
#define I2C2_FIFOCTL_R              (*((volatile uint32_t *)0x40022F04))            /*  pp1350  I2C FIFO Control */
#define I2C2_FIFOSTATUS_R           (*((volatile uint32_t *)0x40022F08))            /*  pp1352  I2C FIFO Status */
#define I2C2_PP_R                   (*((volatile uint32_t *)0x40022FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C2_PC_R                   (*((volatile uint32_t *)0x40022FC4))            /*  pp1355  I2C Peripheral Configuration */

    /*  I2C module 3 (I2C3) */
    // I2C Master
#define I2C3_MSA_R                  (*((volatile uint32_t *)0x40023000))            /*  pp1302  I2C Master Slave Address */
#define I2C3_MCS_R                  (*((volatile uint32_t *)0x40023004))            /*  pp1303  I2C Master Control/Status */
#define I2C3_MDR_R                  (*((volatile uint32_t *)0x40023008))            /*  pp1312  I2C Master Data */
#define I2C3_MTPR_R                 (*((volatile uint32_t *)0x4002300C))            /*  pp1313  I2C Master Timer Period */
#define I2C3_MIMR_R                 (*((volatile uint32_t *)0x40023010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C3_MRIS_R                 (*((volatile uint32_t *)0x40023014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C3_MMIS_R                 (*((volatile uint32_t *)0x40023018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C3_MICR_R                 (*((volatile uint32_t *)0x4002301C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C3_MCR_R                  (*((volatile uint32_t *)0x40023020))            /*  pp1326  I2C Master Configuration */
#define I2C3_MCLKOCNT_R             (*((volatile uint32_t *)0x40023024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C3_MBMON_R                (*((volatile uint32_t *)0x4002302C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C3_MBLEN_R                (*((volatile uint32_t *)0x40023030))            /*  pp1329  I2C Master Burst Length */
#define I2C3_MBCNT_R                (*((volatile uint32_t *)0x40023034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C3_SOAR_R                 (*((volatile uint32_t *)0x40023800))            /*  pp1331  I2C Slave Own Address */
#define I2C3_SCSR_R                 (*((volatile uint32_t *)0x40023804))            /*  pp1332  I2C Slave Control/Status */
#define I2C3_SDR_R                  (*((volatile uint32_t *)0x40023808))            /*  pp1335  I2C Slave Data */
#define I2C3_SIMR_R                 (*((volatile uint32_t *)0x4002380C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C3_SRIS_R                 (*((volatile uint32_t *)0x40023810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C3_SMIS_R                 (*((volatile uint32_t *)0x40023814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C3_SICR_R                 (*((volatile uint32_t *)0x40023818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C3_SOAR2_R                (*((volatile uint32_t *)0x4002381C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C3_SACKCTL_R              (*((volatile uint32_t *)0x40023820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C3_FIFODATA_R             (*((volatile uint32_t *)0x40023F00))            /*  pp1348  I2C FIFO Data */
#define I2C3_FIFOCTL_R              (*((volatile uint32_t *)0x40023F04))            /*  pp1350  I2C FIFO Control */
#define I2C3_FIFOSTATUS_R           (*((volatile uint32_t *)0x40023F08))            /*  pp1352  I2C FIFO Status */
#define I2C3_PP_R                   (*((volatile uint32_t *)0x40023FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C3_PC_R                   (*((volatile uint32_t *)0x40023FC4))            /*  pp1355  I2C Peripheral Configuration */

    /*  I2C module 4 (I2C4) */
    // I2C Master
#define I2C4_MSA_R                  (*((volatile uint32_t *)0x400C0000))            /*  pp1302  I2C Master Slave Address */
#define I2C4_MCS_R                  (*((volatile uint32_t *)0x400C0004))            /*  pp1303  I2C Master Control/Status */
#define I2C4_MDR_R                  (*((volatile uint32_t *)0x400C0008))            /*  pp1312  I2C Master Data */
#define I2C4_MTPR_R                 (*((volatile uint32_t *)0x400C000C))            /*  pp1313  I2C Master Timer Period */
#define I2C4_MIMR_R                 (*((volatile uint32_t *)0x400C0010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C4_MRIS_R                 (*((volatile uint32_t *)0x400C0014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C4_MMIS_R                 (*((volatile uint32_t *)0x400C0018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C4_MICR_R                 (*((volatile uint32_t *)0x400C001C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C4_MCR_R                  (*((volatile uint32_t *)0x400C0020))            /*  pp1326  I2C Master Configuration */
#define I2C4_MCLKOCNT_R             (*((volatile uint32_t *)0x400C0024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C4_MBMON_R                (*((volatile uint32_t *)0x400C002C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C4_MBLEN_R                (*((volatile uint32_t *)0x400C0030))            /*  pp1329  I2C Master Burst Length */
#define I2C4_MBCNT_R                (*((volatile uint32_t *)0x400C0034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C4_SOAR_R                 (*((volatile uint32_t *)0x400C0800))            /*  pp1331  I2C Slave Own Address */
#define I2C4_SCSR_R                 (*((volatile uint32_t *)0x400C0804))            /*  pp1332  I2C Slave Control/Status */
#define I2C4_SDR_R                  (*((volatile uint32_t *)0x400C0808))            /*  pp1335  I2C Slave Data */
#define I2C4_SIMR_R                 (*((volatile uint32_t *)0x400C080C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C4_SRIS_R                 (*((volatile uint32_t *)0x400C0810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C4_SMIS_R                 (*((volatile uint32_t *)0x400C0814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C4_SICR_R                 (*((volatile uint32_t *)0x400C0818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C4_SOAR2_R                (*((volatile uint32_t *)0x400C081C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C4_SACKCTL_R              (*((volatile uint32_t *)0x400C0820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C4_FIFODATA_R             (*((volatile uint32_t *)0x400C0F00))            /*  pp1348  I2C FIFO Data */
#define I2C4_FIFOCTL_R              (*((volatile uint32_t *)0x400C0F04))            /*  pp1350  I2C FIFO Control */
#define I2C4_FIFOSTATUS_R           (*((volatile uint32_t *)0x400C0F08))            /*  pp1352  I2C FIFO Status */
#define I2C4_PP_R                   (*((volatile uint32_t *)0x400C0FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C4_PC_R                   (*((volatile uint32_t *)0x400C0FC4))            /*  pp1355  I2C Peripheral Configuration */

    /*  I2C module 5 (I2C5) */
    // I2C Master
#define I2C5_MSA_R                  (*((volatile uint32_t *)0x400C1000))            /*  pp1302  I2C Master Slave Address */
#define I2C5_MCS_R                  (*((volatile uint32_t *)0x400C1004))            /*  pp1303  I2C Master Control/Status */
#define I2C5_MDR_R                  (*((volatile uint32_t *)0x400C1008))            /*  pp1312  I2C Master Data */
#define I2C5_MTPR_R                 (*((volatile uint32_t *)0x400C100C))            /*  pp1313  I2C Master Timer Period */
#define I2C5_MIMR_R                 (*((volatile uint32_t *)0x400C1010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C5_MRIS_R                 (*((volatile uint32_t *)0x400C1014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C5_MMIS_R                 (*((volatile uint32_t *)0x400C1018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C5_MICR_R                 (*((volatile uint32_t *)0x400C101C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C5_MCR_R                  (*((volatile uint32_t *)0x400C1020))            /*  pp1326  I2C Master Configuration */
#define I2C5_MCLKOCNT_R             (*((volatile uint32_t *)0x400C1024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C5_MBMON_R                (*((volatile uint32_t *)0x400C102C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C5_MBLEN_R                (*((volatile uint32_t *)0x400C1030))            /*  pp1329  I2C Master Burst Length */
#define I2C5_MBCNT_R                (*((volatile uint32_t *)0x400C1034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C5_SOAR_R                 (*((volatile uint32_t *)0x400C1800))            /*  pp1331  I2C Slave Own Address */
#define I2C5_SCSR_R                 (*((volatile uint32_t *)0x400C1804))            /*  pp1332  I2C Slave Control/Status */
#define I2C5_SDR_R                  (*((volatile uint32_t *)0x400C1808))            /*  pp1335  I2C Slave Data */
#define I2C5_SIMR_R                 (*((volatile uint32_t *)0x400C180C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C5_SRIS_R                 (*((volatile uint32_t *)0x400C1810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C5_SMIS_R                 (*((volatile uint32_t *)0x400C1814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C5_SICR_R                 (*((volatile uint32_t *)0x400C1818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C5_SOAR2_R                (*((volatile uint32_t *)0x400C181C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C5_SACKCTL_R              (*((volatile uint32_t *)0x400C1820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C5_FIFODATA_R             (*((volatile uint32_t *)0x400C1F00))            /*  pp1348  I2C FIFO Data */
#define I2C5_FIFOCTL_R              (*((volatile uint32_t *)0x400C1F04))            /*  pp1350  I2C FIFO Control */
#define I2C5_FIFOSTATUS_R           (*((volatile uint32_t *)0x400C1F08))            /*  pp1352  I2C FIFO Status */
#define I2C5_PP_R                   (*((volatile uint32_t *)0x400C1FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C5_PC_R                   (*((volatile uint32_t *)0x400C1FC4))            /*  pp1355  I2C Peripheral Configuration */

    /*  I2C module 6 (I2C6) */
    // I2C Master
#define I2C6_MSA_R                  (*((volatile uint32_t *)0x400C2000))            /*  pp1302  I2C Master Slave Address */
#define I2C6_MCS_R                  (*((volatile uint32_t *)0x400C2004))            /*  pp1303  I2C Master Control/Status */
#define I2C6_MDR_R                  (*((volatile uint32_t *)0x400C2008))            /*  pp1312  I2C Master Data */
#define I2C6_MTPR_R                 (*((volatile uint32_t *)0x400C200C))            /*  pp1313  I2C Master Timer Period */
#define I2C6_MIMR_R                 (*((volatile uint32_t *)0x400C2010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C6_MRIS_R                 (*((volatile uint32_t *)0x400C2014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C6_MMIS_R                 (*((volatile uint32_t *)0x400C2018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C6_MICR_R                 (*((volatile uint32_t *)0x400C201C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C6_MCR_R                  (*((volatile uint32_t *)0x400C2020))            /*  pp1326  I2C Master Configuration */
#define I2C6_MCLKOCNT_R             (*((volatile uint32_t *)0x400C2024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C6_MBMON_R                (*((volatile uint32_t *)0x400C202C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C6_MBLEN_R                (*((volatile uint32_t *)0x400C2030))            /*  pp1329  I2C Master Burst Length */
#define I2C6_MBCNT_R                (*((volatile uint32_t *)0x400C2034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C6_SOAR_R                 (*((volatile uint32_t *)0x400C2800))            /*  pp1331  I2C Slave Own Address */
#define I2C6_SCSR_R                 (*((volatile uint32_t *)0x400C2804))            /*  pp1332  I2C Slave Control/Status */
#define I2C6_SDR_R                  (*((volatile uint32_t *)0x400C2808))            /*  pp1335  I2C Slave Data */
#define I2C6_SIMR_R                 (*((volatile uint32_t *)0x400C280C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C6_SRIS_R                 (*((volatile uint32_t *)0x400C2810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C6_SMIS_R                 (*((volatile uint32_t *)0x400C2814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C6_SICR_R                 (*((volatile uint32_t *)0x400C2818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C6_SOAR2_R                (*((volatile uint32_t *)0x400C281C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C6_SACKCTL_R              (*((volatile uint32_t *)0x400C2820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C6_FIFODATA_R             (*((volatile uint32_t *)0x400C2F00))            /*  pp1348  I2C FIFO Data */
#define I2C6_FIFOCTL_R              (*((volatile uint32_t *)0x400C2F04))            /*  pp1350  I2C FIFO Control */
#define I2C6_FIFOSTATUS_R           (*((volatile uint32_t *)0x400C2F08))            /*  pp1352  I2C FIFO Status */
#define I2C6_PP_R                   (*((volatile uint32_t *)0x400C2FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C6_PC_R                   (*((volatile uint32_t *)0x400C2FC4))            /*  pp1355  I2C Peripheral Configuration */

    /*  I2C module 7 (I2C7) */
    // I2C Master
#define I2C7_MSA_R                  (*((volatile uint32_t *)0x400C3000))            /*  pp1302  I2C Master Slave Address */
#define I2C7_MCS_R                  (*((volatile uint32_t *)0x400C3004))            /*  pp1303  I2C Master Control/Status */
#define I2C7_MDR_R                  (*((volatile uint32_t *)0x400C3008))            /*  pp1312  I2C Master Data */
#define I2C7_MTPR_R                 (*((volatile uint32_t *)0x400C300C))            /*  pp1313  I2C Master Timer Period */
#define I2C7_MIMR_R                 (*((volatile uint32_t *)0x400C3010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C7_MRIS_R                 (*((volatile uint32_t *)0x400C3014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C7_MMIS_R                 (*((volatile uint32_t *)0x400C3018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C7_MICR_R                 (*((volatile uint32_t *)0x400C301C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C7_MCR_R                  (*((volatile uint32_t *)0x400C3020))            /*  pp1326  I2C Master Configuration */
#define I2C7_MCLKOCNT_R             (*((volatile uint32_t *)0x400C3024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C7_MBMON_R                (*((volatile uint32_t *)0x400C302C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C7_MBLEN_R                (*((volatile uint32_t *)0x400C3030))            /*  pp1329  I2C Master Burst Length */
#define I2C7_MBCNT_R                (*((volatile uint32_t *)0x400C3034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C7_SOAR_R                 (*((volatile uint32_t *)0x400C3800))            /*  pp1331  I2C Slave Own Address */
#define I2C7_SCSR_R                 (*((volatile uint32_t *)0x400C3804))            /*  pp1332  I2C Slave Control/Status */
#define I2C7_SDR_R                  (*((volatile uint32_t *)0x400C3808))            /*  pp1335  I2C Slave Data */
#define I2C7_SIMR_R                 (*((volatile uint32_t *)0x400C380C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C7_SRIS_R                 (*((volatile uint32_t *)0x400C3810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C7_SMIS_R                 (*((volatile uint32_t *)0x400C3814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C7_SICR_R                 (*((volatile uint32_t *)0x400C3818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C7_SOAR2_R                (*((volatile uint32_t *)0x400C381C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C7_SACKCTL_R              (*((volatile uint32_t *)0x400C3820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C7_FIFODATA_R             (*((volatile uint32_t *)0x400C3F00))            /*  pp1348  I2C FIFO Data */
#define I2C7_FIFOCTL_R              (*((volatile uint32_t *)0x400C3F04))            /*  pp1350  I2C FIFO Control */
#define I2C7_FIFOSTATUS_R           (*((volatile uint32_t *)0x400C3F08))            /*  pp1352  I2C FIFO Status */
#define I2C7_PP_R                   (*((volatile uint32_t *)0x400C3FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C7_PC_R                   (*((volatile uint32_t *)0x400C3FC4))            /*  pp1355  I2C Peripheral Configuration */

    /*  I2C module 8 (I2C8) */
    // I2C Master
#define I2C8_MSA_R                  (*((volatile uint32_t *)0x400B8000))            /*  pp1302  I2C Master Slave Address */
#define I2C8_MCS_R                  (*((volatile uint32_t *)0x400B8004))            /*  pp1303  I2C Master Control/Status */
#define I2C8_MDR_R                  (*((volatile uint32_t *)0x400B8008))            /*  pp1312  I2C Master Data */
#define I2C8_MTPR_R                 (*((volatile uint32_t *)0x400B800C))            /*  pp1313  I2C Master Timer Period */
#define I2C8_MIMR_R                 (*((volatile uint32_t *)0x400B8010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C8_MRIS_R                 (*((volatile uint32_t *)0x400B8014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C8_MMIS_R                 (*((volatile uint32_t *)0x400B8018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C8_MICR_R                 (*((volatile uint32_t *)0x400B801C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C8_MCR_R                  (*((volatile uint32_t *)0x400B8020))            /*  pp1326  I2C Master Configuration */
#define I2C8_MCLKOCNT_R             (*((volatile uint32_t *)0x400B8024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C8_MBMON_R                (*((volatile uint32_t *)0x400B802C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C8_MBLEN_R                (*((volatile uint32_t *)0x400B8030))            /*  pp1329  I2C Master Burst Length */
#define I2C8_MBCNT_R                (*((volatile uint32_t *)0x400B8034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C8_SOAR_R                 (*((volatile uint32_t *)0x400B8800))            /*  pp1331  I2C Slave Own Address */
#define I2C8_SCSR_R                 (*((volatile uint32_t *)0x400B8804))            /*  pp1332  I2C Slave Control/Status */
#define I2C8_SDR_R                  (*((volatile uint32_t *)0x400B8808))            /*  pp1335  I2C Slave Data */
#define I2C8_SIMR_R                 (*((volatile uint32_t *)0x400B880C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C8_SRIS_R                 (*((volatile uint32_t *)0x400B8810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C8_SMIS_R                 (*((volatile uint32_t *)0x400B8814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C8_SICR_R                 (*((volatile uint32_t *)0x400B8818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C8_SOAR2_R                (*((volatile uint32_t *)0x400B881C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C8_SACKCTL_R              (*((volatile uint32_t *)0x400B8820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C8_FIFODATA_R             (*((volatile uint32_t *)0x400B8F00))            /*  pp1348  I2C FIFO Data */
#define I2C8_FIFOCTL_R              (*((volatile uint32_t *)0x400B8F04))            /*  pp1350  I2C FIFO Control */
#define I2C8_FIFOSTATUS_R           (*((volatile uint32_t *)0x400B8F08))            /*  pp1352  I2C FIFO Status */
#define I2C8_PP_R                   (*((volatile uint32_t *)0x400B8FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C8_PC_R                   (*((volatile uint32_t *)0x400B8FC4))            /*  pp1355  I2C Peripheral Configuration */

    /*  I2C module 9 (I2C9) */
    // I2C Master
#define I2C9_MSA_R                  (*((volatile uint32_t *)0x400B9000))            /*  pp1302  I2C Master Slave Address */
#define I2C9_MCS_R                  (*((volatile uint32_t *)0x400B9004))            /*  pp1303  I2C Master Control/Status */
#define I2C9_MDR_R                  (*((volatile uint32_t *)0x400B9008))            /*  pp1312  I2C Master Data */
#define I2C9_MTPR_R                 (*((volatile uint32_t *)0x400B900C))            /*  pp1313  I2C Master Timer Period */
#define I2C9_MIMR_R                 (*((volatile uint32_t *)0x400B9010))            /*  pp1315  I2C Master Interrupt Mask */
#define I2C9_MRIS_R                 (*((volatile uint32_t *)0x400B9014))            /*  pp1318  I2C Master Raw Interrupt Status */
#define I2C9_MMIS_R                 (*((volatile uint32_t *)0x400B9018))            /*  pp1321  I2C Master Masked Interrupt Status */
#define I2C9_MICR_R                 (*((volatile uint32_t *)0x400B901C))            /*  pp1324  I2C Master Interrupt Clear */
#define I2C9_MCR_R                  (*((volatile uint32_t *)0x400B9020))            /*  pp1326  I2C Master Configuration */
#define I2C9_MCLKOCNT_R             (*((volatile uint32_t *)0x400B9024))            /*  pp1327  I2C Master Clock Low Timeout Count */
#define I2C9_MBMON_R                (*((volatile uint32_t *)0x400B902C))            /*  pp1328  I2C Master Bus Monitor */
#define I2C9_MBLEN_R                (*((volatile uint32_t *)0x400B9030))            /*  pp1329  I2C Master Burst Length */
#define I2C9_MBCNT_R                (*((volatile uint32_t *)0x400B9034))            /*  pp1330  I2C Master Burst Count */
    // I2C Slave
#define I2C9_SOAR_R                 (*((volatile uint32_t *)0x400B9800))            /*  pp1331  I2C Slave Own Address */
#define I2C9_SCSR_R                 (*((volatile uint32_t *)0x400B9804))            /*  pp1332  I2C Slave Control/Status */
#define I2C9_SDR_R                  (*((volatile uint32_t *)0x400B9808))            /*  pp1335  I2C Slave Data */
#define I2C9_SIMR_R                 (*((volatile uint32_t *)0x400B980C))            /*  pp1336  I2C Slave Interrupt Mask */
#define I2C9_SRIS_R                 (*((volatile uint32_t *)0x400B9810))            /*  pp1338  I2C Slave Raw Interrupt Status */
#define I2C9_SMIS_R                 (*((volatile uint32_t *)0x400B9814))            /*  pp1341  I2C Slave Masked Interrupt Status */
#define I2C9_SICR_R                 (*((volatile uint32_t *)0x400B9818))            /*  pp1344  I2C Slave Interrupt Clear */
#define I2C9_SOAR2_R                (*((volatile uint32_t *)0x400B981C))            /*  pp1346  I2C Slave Own Address 2 */
#define I2C9_SACKCTL_R              (*((volatile uint32_t *)0x400B9820))            /*  pp1347  I2C Slave ACK Control */
    // I2C Status and Control
#define I2C9_FIFODATA_R             (*((volatile uint32_t *)0x400B9F00))            /*  pp1348  I2C FIFO Data */
#define I2C9_FIFOCTL_R              (*((volatile uint32_t *)0x400B9F04))            /*  pp1350  I2C FIFO Control */
#define I2C9_FIFOSTATUS_R           (*((volatile uint32_t *)0x400B9F08))            /*  pp1352  I2C FIFO Status */
#define I2C9_PP_R                   (*((volatile uint32_t *)0x400B9FC0))            /*  pp1354  I2C Peripheral Properties */
#define I2C9_PC_R                   (*((volatile uint32_t *)0x400B9FC4))            /*  pp1355  I2C Peripheral Configuration */


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

    // Bit fields in the I2C_MIMR register                                              pp1315
#define I2C_MIMR_RXFFIM             0x00000800                                      /*  Receive FIFO Full Interrupt Mask */
#define I2C_MIMR_TXFEIM             0x00000400                                      /*  Transmit FIFO Empty Interrupt Mask */
#define I2C_MIMR_RXIM               0x00000200                                      /*  Receive FIFO Request Interrupt Mask */
#define I2C_MIMR_TXIM               0x00000100                                      /*  Transmit FIFO Request Interrupt Mask */
#define I2C_MIMR_ARBLOSTIM          0x00000080                                      /*  Arbitration Lost Interrupt Mask */
#define I2C_MIMR_STOPIM             0x00000040                                      /*  STOP Detection Interrupt Mask */
#define I2C_MIMR_STARTIM            0x00000020                                      /*  START Detection Interrupt Mask */
#define I2C_MIMR_NACKIM             0x00000010                                      /*  Address/Data NACK Interrupt Mask */
#define I2C_MIMR_DMATXIM            0x00000008                                      /*  Transmit DMA Interrupt Mask */
#define I2C_MIMR_DMARXIM            0x00000004                                      /*  Receive DMA Interrupt Mask */
#define I2C_MIMR_CLKIM              0x00000002                                      /*  Clock Timeout Interrupt Mask */
#define I2C_MIMR_IM                 0x00000001                                      /*  Master Interrupt Mask */

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

    // Bit fields in the I2C_MMIS register                                              pp1321
#define I2C_MMIS_RXFFMIS            0x00000800                                      /*  Receive FIFO Full Interrupt Mask */
#define I2C_MMIS_TXFEMIS            0x00000400                                      /*  Transmit FIFO Empty Interrupt Mask */
#define I2C_MMIS_RXMIS              0x00000200                                      /*  Receive FIFO Request Interrupt Mask */
#define I2C_MMIS_TXMIS              0x00000100                                      /*  Transmit Request Interrupt Mask */
#define I2C_MMIS_ARBLOSTMIS         0x00000080                                      /*  Arbitration Lost Interrupt Mask */
#define I2C_MMIS_STOPMIS            0x00000040                                      /*  STOP Detection Interrupt Mask */
#define I2C_MMIS_STARTMIS           0x00000020                                      /*  START Detection Interrupt Mask */
#define I2C_MMIS_NACKMIS            0x00000010                                      /*  Address/Data NACK Interrupt Mask */
#define I2C_MMIS_DMATXMIS           0x00000008                                      /*  Transmit DMA Interrupt Status */
#define I2C_MMIS_DMARXMIS           0x00000004                                      /*  Receive DMA Interrupt Status */
#define I2C_MMIS_CLKMIS             0x00000002                                      /*  Clock Timeout Masked Interrupt Status */
#define I2C_MMIS_MIS                0x00000001                                      /*  Masked Interrupt Status */

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

    // Bit fields in the I2C_MCLKOCNT register                                          pp1327
#define I2C_MCLKOCNT_CNTL_M         0x000000FF                                      /*  I2C Master Count mask */
#define I2C_MCLKOCNT_CNTL_S         0                                               /*  I2C Master Count shift */

    // Bit fields in the I2C_MBMON register                                             pp1328
#define I2C_MBMON_SDA               0x00000002                                      /*  I2C SDA Status */
#define I2C_MBMON_SCL               0x00000001                                      /*  I2C SCL Status */

    // Bit fields in the I2C_MBLEN register                                             pp1329
#define I2C_MBLEN_CNTL_M            0x000000FF                                      /*  I2C Burst Length mask */
#define I2C_MBLEN_CNTL_S            0                                               /*  I2C Burst Length shift */

    // Bit fields in the I2C_MBCNT register                                             pp1330
#define I2C_MBCNT_CNTL_M            0x000000FF                                      /*  I2C Master Burst Count mask */
#define I2C_MBCNT_CNTL_S            0                                               /*  I2C Master Burst Count shift */

    // Bit fields in the I2C_SOAR register                                              pp1331
#define I2C_SOAR_OAR_M              0x0000007F                                      /*  I2C Slave Own Address mask */
#define I2C_SOAR_OAR_S              0                                               /*  I2C Slave Own Address shift */

    // Bit fields in the I2C_SCSR register                                              pp1332
#define I2C_SCSR_ACTDMARX           0x80000000                                      /*  DMA RX Active Status */
#define I2C_SCSR_ACTDMATX           0x40000000                                      /*  DMA TX Active Status */
#define I2C_SCSR_QCMDRW             0x00000020                                      /*  Quick Command Read / Write */
#define I2C_SCSR_QCMDST             0x00000010                                      /*  Quick Command Status */
#define I2C_SCSR_OAR2SEL            0x00000008                                      /*  OAR2 Address Matched */
#define I2C_SCSR_FBR                0x00000004                                      /*  First Byte Received */
#define I2C_SCSR_RXFIFO             0x00000004                                      /*  RX FIFO Enable */
#define I2C_SCSR_TXFIFO             0x00000002                                      /*  TX FIFO Enable */
#define I2C_SCSR_TREQ               0x00000002                                      /*  Transmit Request */
#define I2C_SCSR_DA                 0x00000001                                      /*  Device Active */
#define I2C_SCSR_RREQ               0x00000001                                      /*  Receive Request */

    // Bit fields in the I2C_SDR register                                               pp1335
#define I2C_SDR_DATA_M              0x000000FF                                      /*  Data for Transfer mask */
#define I2C_SDR_DATA_S              0                                               /*  Data for Transfer shift */

    // Bit fields in the I2C_SIMR register                                              pp1336
#define I2C_SIMR_RXFFIM             0x00000100                                      /*  Receive FIFO Full Interrupt Mask */
#define I2C_SIMR_TXFEIM             0x00000080                                      /*  Transmit FIFO Empty Interrupt Mask */
#define I2C_SIMR_RXIM               0x00000040                                      /*  Receive FIFO Request Interrupt Mask */
#define I2C_SIMR_TXIM               0x00000020                                      /*  Transmit FIFO Request Interrupt Mask */
#define I2C_SIMR_DMATXIM            0x00000010                                      /*  Transmit DMA Interrupt Mask */
#define I2C_SIMR_DMARXIM            0x00000008                                      /*  Receive DMA Interrupt Mask */
#define I2C_SIMR_STOPIM             0x00000004                                      /*  Stop Condition Interrupt Mask */
#define I2C_SIMR_STARTIM            0x00000002                                      /*  Start Condition Interrupt Mask */
#define I2C_SIMR_DATAIM             0x00000001                                      /*  Data Interrupt Mask */

    // Bit fields in the I2C_SRIS register                                              pp1338
#define I2C_SRIS_RXFFRIS            0x00000100                                      /*  Receive FIFO Full Raw Interrupt Status */
#define I2C_SRIS_TXFERIS            0x00000080                                      /*  Transmit FIFO Empty Raw Interrupt Status */
#define I2C_SRIS_RXRIS              0x00000040                                      /*  Receive FIFO Request Raw Interrupt Status */
#define I2C_SRIS_TXRIS              0x00000020                                      /*  Transmit Request Raw Interrupt Status */
#define I2C_SRIS_DMATXRIS           0x00000010                                      /*  Transmit DMA Raw Interrupt Status */
#define I2C_SRIS_DMARXRIS           0x00000008                                      /*  Receive DMA Raw Interrupt Status */
#define I2C_SRIS_STOPRIS            0x00000004                                      /*  Stop Condition Raw Interrupt Status */
#define I2C_SRIS_STARTRIS           0x00000002                                      /*  Start Condition Raw Interrupt Status */
#define I2C_SRIS_DATARIS            0x00000001                                      /*  Data Raw Interrupt Status */

    // Bit fields in the I2C_SMIS register                                              pp1341
#define I2C_SMIS_RXFFMIS            0x00000100                                      /*  Receive FIFO Full Interrupt Mask */
#define I2C_SMIS_TXFEMIS            0x00000080                                      /*  Transmit FIFO Empty Interrupt Mask */
#define I2C_SMIS_RXMIS              0x00000040                                      /*  Receive FIFO Request Interrupt Mask */
#define I2C_SMIS_TXMIS              0x00000020                                      /*  Transmit FIFO Request Interrupt Mask */
#define I2C_SMIS_DMATXMIS           0x00000010                                      /*  Transmit DMA Masked Interrupt Status */
#define I2C_SMIS_DMARXMIS           0x00000008                                      /*  Receive DMA Masked Interrupt Status */
#define I2C_SMIS_STOPMIS            0x00000004                                      /*  Stop Condition Masked Interrupt Status */
#define I2C_SMIS_STARTMIS           0x00000002                                      /*  Start Condition Masked Interrupt Status */
#define I2C_SMIS_DATAMIS            0x00000001                                      /*  Data Masked Interrupt Status */

    // Bit fields in the I2C_SICR register                                              pp1344
#define I2C_SICR_RXFFIC             0x00000100                                      /*  Receive FIFO Full Interrupt Mask */
#define I2C_SICR_TXFEIC             0x00000080                                      /*  Transmit FIFO Empty Interrupt Mask */
#define I2C_SICR_RXIC               0x00000040                                      /*  Receive Request Interrupt Mask */
#define I2C_SICR_TXIC               0x00000020                                      /*  Transmit Request Interrupt Mask */
#define I2C_SICR_DMATXIC            0x00000010                                      /*  Transmit DMA Interrupt Clear */
#define I2C_SICR_DMARXIC            0x00000008                                      /*  Receive DMA Interrupt Clear */
#define I2C_SICR_STOPIC             0x00000004                                      /*  Stop Condition Interrupt Clear */
#define I2C_SICR_STARTIC            0x00000002                                      /*  Start Condition Interrupt Clear */
#define I2C_SICR_DATAIC             0x00000001                                      /*  Data Interrupt Clear */

    // Bit fields in the I2C_SOAR2 register                                             pp1346
#define I2C_SOAR2_OAR2EN            0x00000080                                      /*  I2C Slave Own Address 2 Enable */
#define I2C_SOAR2_OAR2_M            0x0000007F                                      /*  I2C Slave Own Address 2 mask */
#define I2C_SOAR2_OAR2_S            0                                               /*  I2C Slave Own Address 2 shift */

    // Bit fields in the I2C_SACKCTL register                                           pp1347
#define I2C_SACKCTL_ACKOVAL         0x00000002                                      /*  I2C Slave ACK Override Value */
#define I2C_SACKCTL_ACKOEN          0x00000001                                      /*  I2C Slave ACK Override Enable */

    // Bit fields in the I2C_FIFODATA register                                          pp1348
#define I2C_FIFODATA_DATA_M         0x000000FF                                      /*  I2C TX FIFO Write Data Byte mask */
#define I2C_FIFODATA_DATA_S         0                                               /*  I2C TX FIFO Write Data Byte shift */

    // Bit fields in the I2C_FIFOCTL register                                           pp1350
#define I2C_FIFOCTL_RXASGNMT        0x80000000                                      /*  RX Control Assignment */
#define I2C_FIFOCTL_RXFLUSH         0x40000000                                      /*  RX FIFO Flush */
#define I2C_FIFOCTL_DMARXENA        0x20000000                                      /*  DMA RX Channel Enable */
#define I2C_FIFOCTL_RXTRIG_M        0x00070000                                      /*  RX FIFO Trigger mask */
#define I2C_FIFOCTL_TXASGNMT        0x00008000                                      /*  TX Control Assignment */
#define I2C_FIFOCTL_TXFLUSH         0x00004000                                      /*  TX FIFO Flush */
#define I2C_FIFOCTL_DMATXENA        0x00002000                                      /*  DMA TX Channel Enable */
#define I2C_FIFOCTL_TXTRIG_M        0x00000007                                      /*  TX FIFO Trigger mask */
#define I2C_FIFOCTL_RXTRIG_S        16                                              /*  RX FIFO Trigger shift */
#define I2C_FIFOCTL_TXTRIG_S        0                                               /*  TX FIFO Trigger shift */

    // Bit fields in the I2C_FIFOSTATUS register                                        pp1352
#define I2C_FIFOSTATUS_RXABVTRIG    0x00040000                                      /*  RX FIFO Above Trigger Level */
#define I2C_FIFOSTATUS_RXFF         0x00020000                                      /*  RX FIFO Full */
#define I2C_FIFOSTATUS_RXFE         0x00010000                                      /*  RX FIFO Empty */
#define I2C_FIFOSTATUS_TXBLWTRIG    0x00000004                                      /*  TX FIFO Below Trigger Level */
#define I2C_FIFOSTATUS_TXFF         0x00000002                                      /*  TX FIFO Full */
#define I2C_FIFOSTATUS_TXFE         0x00000001                                      /*  TX FIFO Empty */

    // Bit fields in the I2C_PP register                                                pp1354
#define I2C_PP_HS                   0x00000001                                      /*  High-Speed Capable */

    // Bit fields in the I2C_PC register                                                pp1355
#define I2C_PC_HS                   0x00000001                                      /*  High-Speed Capable */


/*********************************************************************************
 * Prototipos de funciones públicas
 */

void I2C0_Init(void);                                                               /*  Inicialización del I2C0 */
void I2C1_Init(void);                                                               /*  Inicialización del I2C1 */
void I2C2_Init(void);                                                               /*  Inicialización del I2C2 */
void I2C3_Init(void);                                                               /*  Inicialización del I2C3 */
void I2C4_Init(void);                                                               /*  Inicialización del I2C4 */
void I2C5_Init(void);                                                               /*  Inicialización del I2C5 */
void I2C6_Init(void);                                                               /*  Inicialización del I2C6 */
void I2C7_Init(void);                                                               /*  Inicialización del I2C7 */
void I2C8_Init(void);                                                               /*  Inicialización del I2C8 */
void I2C9_Init(void);                                                               /*  Inicialización del I2C9 */


#endif                                                                              /*  I2C_H */
