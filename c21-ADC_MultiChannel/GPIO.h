/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Código:      Archivo de cabecera del GPIO
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef GPIO_H                                                                      /*  Verificar si GPIO_H no ha sido definido previamente */
#define GPIO_H                                                                      /*  Definir GPIO_H para evitar inclusiones múLTiples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * General-Purpose Input/Output (GPIO) registers                                        pp757   Register map
 */

    /*  GPIO Port B (PortB) */
#define GPIO_PORTB_AHB_AFSEL_R      (*((volatile uint32_t *)0x40059420))            /*  pp770   GPIO Alternate Function Select */
#define GPIO_PORTB_AHB_DEN_R        (*((volatile uint32_t *)0x4005951C))            /*  pp781   GPIO Digital Enable */
#define GPIO_PORTB_AHB_AMSEL_R      (*((volatile uint32_t *)0x40059528))            /*  pp786   GPIO Analog Mode Select */

    /*  GPIO Port F (PortF) */
#define GPIO_PORTF_AHB_DATA_R       (*((volatile uint32_t *)0x4005D044))            /*  pp759   GPIO Data >> PortF[4,0] unmasked */
#define GPIO_PORTF_AHB_DIR_R        (*((volatile uint32_t *)0x4005D400))            /*  pp760   GPIO Direction */
#define GPIO_PORTF_AHB_IS_R         (*((volatile uint32_t *)0x4005D404))            /*  pp761   GPIO Interrupt Sense */
#define GPIO_PORTF_AHB_IBE_R        (*((volatile uint32_t *)0x4005D408))            /*  pp762   GPIO Interrupt Both Edges */
#define GPIO_PORTF_AHB_IEV_R        (*((volatile uint32_t *)0x4005D40C))            /*  pp763   GPIO Interrupt Event */
#define GPIO_PORTF_AHB_IM_R         (*((volatile uint32_t *)0x4005D410))            /*  pp764   GPIO Interrupt Mask */
#define GPIO_PORTF_AHB_ICR_R        (*((volatile uint32_t *)0x4005D41C))            /*  pp769   GPIO Interrupt Clear */
#define GPIO_PORTF_AHB_AFSEL_R      (*((volatile uint32_t *)0x4005D420))            /*  pp770   GPIO Alternate Function Select */
#define GPIO_PORTF_AHB_DR4R_R       (*((volatile uint32_t *)0x4005D504))            /*  pp773   GPIO 4-mA Drive Select */
#define GPIO_PORTF_AHB_DR8R_R       (*((volatile uint32_t *)0x4005D508))            /*  pp774   GPIO 8-mA Drive Select */
#define GPIO_PORTF_AHB_ODR_R        (*((volatile uint32_t *)0x4005D50C))            /*  pp775   GPIO Open Drain Select */
#define GPIO_PORTF_AHB_PUR_R        (*((volatile uint32_t *)0x4005D510))            /*  pp776   GPIO Pull-Up Select */
#define GPIO_PORTF_AHB_PDR_R        (*((volatile uint32_t *)0x4005D514))            /*  pp778   GPIO Pull-Down Select */
#define GPIO_PORTF_AHB_DEN_R        (*((volatile uint32_t *)0x4005D51C))            /*  pp781   GPIO Digital Enable */
#define GPIO_PORTF_AHB_DR12R_R      (*((volatile uint32_t *)0x4005D53C))            /*  pp792   GPIO 12-mA Drive Select */
#define GPIO_PORTF_AHB_PC_R         (*((volatile uint32_t *)0x4005DFC4))            /*  pp800   GPIO Peripheral Configuration */

    /*  GPIO Port J (PortJ) */
#define GPIO_PORTJ_AHB_DATA_R       (*((volatile uint32_t *)0x4006000C))            /*  pp759   GPIO Data >> PortJ[1..0] unmasked */
#define GPIO_PORTJ_AHB_DIR_R        (*((volatile uint32_t *)0x40060400))            /*  pp760   GPIO Direction */
#define GPIO_PORTJ_AHB_IS_R         (*((volatile uint32_t *)0x40060404))            /*  pp761   GPIO Interrupt Sense */
#define GPIO_PORTJ_AHB_IBE_R        (*((volatile uint32_t *)0x40060408))            /*  pp762   GPIO Interrupt Both Edges */
#define GPIO_PORTJ_AHB_IEV_R        (*((volatile uint32_t *)0x4006040C))            /*  pp763   GPIO Interrupt Event */
#define GPIO_PORTJ_AHB_IM_R         (*((volatile uint32_t *)0x40060410))            /*  pp764   GPIO Interrupt Mask */
#define GPIO_PORTJ_AHB_ICR_R        (*((volatile uint32_t *)0x4006041C))            /*  pp769   GPIO Interrupt Clear */
#define GPIO_PORTJ_AHB_AFSEL_R      (*((volatile uint32_t *)0x40060420))            /*  pp770   GPIO Alternate Function Select */
#define GPIO_PORTJ_AHB_DR4R_R       (*((volatile uint32_t *)0x40060504))            /*  pp773   GPIO 4-mA Drive Select */
#define GPIO_PORTJ_AHB_DR8R_R       (*((volatile uint32_t *)0x40060508))            /*  pp774   GPIO 8-mA Drive Select */
#define GPIO_PORTJ_AHB_ODR_R        (*((volatile uint32_t *)0x4006050C))            /*  pp775   GPIO Open Drain Select */
#define GPIO_PORTJ_AHB_PUR_R        (*((volatile uint32_t *)0x40060510))            /*  pp776   GPIO Pull-Up Select */
#define GPIO_PORTJ_AHB_PDR_R        (*((volatile uint32_t *)0x40060514))            /*  pp778   GPIO Pull-Down Select */
#define GPIO_PORTJ_AHB_DEN_R        (*((volatile uint32_t *)0x4006051C))            /*  pp781   GPIO Digital Enable */
#define GPIO_PORTJ_AHB_DR12R_R      (*((volatile uint32_t *)0x4006053C))            /*  pp792   GPIO 12-mA Drive Select */
#define GPIO_PORTJ_AHB_PC_R         (*((volatile uint32_t *)0x40060FC4))            /*  pp800   GPIO Peripheral Configuration */

    /*  GPIO Port K (PortK) */
#define GPIO_PORTK_AFSEL_R          (*((volatile uint32_t *)0x40061420))            /*  pp770   GPIO Alternate Function Select */
#define GPIO_PORTK_DEN_R            (*((volatile uint32_t *)0x4006151C))            /*  pp781   GPIO Digital Enable */
#define GPIO_PORTK_AMSEL_R          (*((volatile uint32_t *)0x40061528))            /*  pp786   GPIO Analog Mode Select */

    /*  GPIO Port N (PortN) */
#define GPIO_PORTN_DATA_R           (*((volatile uint32_t *)0x4006400C))            /*  pp759   GPIO Data >> PortN[1:0] unmasked */
#define GPIO_PORTN_DIR_R            (*((volatile uint32_t *)0x40064400))            /*  pp760   GPIO Direction */
#define GPIO_PORTN_IS_R             (*((volatile uint32_t *)0x40064404))            /*  pp761   GPIO Interrupt Sense */
#define GPIO_PORTN_IBE_R            (*((volatile uint32_t *)0x40064408))            /*  pp762   GPIO Interrupt Both Edges */
#define GPIO_PORTN_IEV_R            (*((volatile uint32_t *)0x4006440C))            /*  pp763   GPIO Interrupt Event */
#define GPIO_PORTN_IM_R             (*((volatile uint32_t *)0x40064410))            /*  pp764   GPIO Interrupt Mask */
#define GPIO_PORTN_ICR_R            (*((volatile uint32_t *)0x4006441C))            /*  pp769   GPIO Interrupt Clear */
#define GPIO_PORTN_AFSEL_R          (*((volatile uint32_t *)0x40064420))            /*  pp770   GPIO Alternate Function Select */
#define GPIO_PORTN_DR4R_R           (*((volatile uint32_t *)0x40064504))            /*  pp773   GPIO 4-mA Drive Select */
#define GPIO_PORTN_DR8R_R           (*((volatile uint32_t *)0x40064508))            /*  pp774   GPIO 8-mA Drive Select */
#define GPIO_PORTN_ODR_R            (*((volatile uint32_t *)0x4006450C))            /*  pp775   GPIO Open Drain Select */
#define GPIO_PORTN_PUR_R            (*((volatile uint32_t *)0x40064510))            /*  pp776   GPIO Pull-Up Select */
#define GPIO_PORTN_PDR_R            (*((volatile uint32_t *)0x40064514))            /*  pp778   GPIO Pull-Down Select */
#define GPIO_PORTN_DEN_R            (*((volatile uint32_t *)0x4006451C))            /*  pp781   GPIO Digital Enable */
#define GPIO_PORTN_DR12R_R          (*((volatile uint32_t *)0x4006453C))            /*  pp792   GPIO 12-mA Drive Select */
#define GPIO_PORTN_PC_R             (*((volatile uint32_t *)0x40064FC4))            /*  pp800   GPIO Peripheral Configuration */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the GPIO_PC register                                               pp800
#define GPIO_PC_EDM7_M              0x0000C000                                      /*  Extended Drive Mode Bit 7 Mask */
#define GPIO_PC_EDM6_M              0x00003000                                      /*  Extended Drive Mode Bit 6 Mask */
#define GPIO_PC_EDM5_M              0x00000C00                                      /*  Extended Drive Mode Bit 5 Mask */
#define GPIO_PC_EDM4_M              0x00000300                                      /*  Extended Drive Mode Bit 4 Mask */
#define GPIO_PC_EDM3_M              0x000000C0                                      /*  Extended Drive Mode Bit 3 Mask */
#define GPIO_PC_EDM2_M              0x00000030                                      /*  Extended Drive Mode Bit 2 Mask */
#define GPIO_PC_EDM1_M              0x0000000C                                      /*  Extended Drive Mode Bit 1 Mask */
#define GPIO_PC_EDM0_M              0x00000003                                      /*  Extended Drive Mode Bit 0 Mask */
#define GPIO_PC_EDM7_S              14                                              /*  Extended Drive Mode Bit 7 Shift */
#define GPIO_PC_EDM6_S              12                                              /*  Extended Drive Mode Bit 6 Shift */
#define GPIO_PC_EDM5_S              10                                              /*  Extended Drive Mode Bit 5 Shift */
#define GPIO_PC_EDM4_S              8                                               /*  Extended Drive Mode Bit 4 Shift */
#define GPIO_PC_EDM3_S              6                                               /*  Extended Drive Mode Bit 3 Shift */
#define GPIO_PC_EDM2_S              4                                               /*  Extended Drive Mode Bit 2 Shift */
#define GPIO_PC_EDM1_S              2                                               /*  Extended Drive Mode Bit 1 Shift */
#define GPIO_PC_EDM0_S              0                                               /*  Extended Drive Mode Bit 0 Shift */

    // Bit fields for the GPIO pin
#define GPIO_PIN_7                  0x00000080                                      /*  GPIO pin 7 */
#define GPIO_PIN_6                  0x00000040                                      /*  GPIO pin 6 */
#define GPIO_PIN_5                  0x00000020                                      /*  GPIO pin 5 */
#define GPIO_PIN_4                  0x00000010                                      /*  GPIO pin 4 */
#define GPIO_PIN_3                  0x00000008                                      /*  GPIO pin 3 */
#define GPIO_PIN_2                  0x00000004                                      /*  GPIO pin 2 */
#define GPIO_PIN_1                  0x00000002                                      /*  GPIO pin 1 */
#define GPIO_PIN_0                  0x00000001                                      /*  GPIO pin 0 */

    /*  Control de los LED de usuario (Dn) */
#define LED_D1_On()                 (GPIO_PORTN_DATA_R |= GPIO_PIN_1)               /*  Encendido del LED D1 (PortN[1]) */
#define LED_D1_Off()                (GPIO_PORTN_DATA_R &= ~GPIO_PIN_1)              /*  Apagado del LED D1 (PortN[1]) */

#define LED_D2_On()                 (GPIO_PORTN_DATA_R |= GPIO_PIN_0)               /*  Encendido del LED D2 (PortN[0]) */
#define LED_D2_Off()                (GPIO_PORTN_DATA_R &= ~GPIO_PIN_0)              /*  Apagado del LED D2 (PortN[0]) */

#define LED_D3_On()                 (GPIO_PORTF_AHB_DATA_R |= GPIO_PIN_4)           /*  Encendido del LED D3 (PortF[4]) */
#define LED_D3_Off()                (GPIO_PORTF_AHB_DATA_R &= ~GPIO_PIN_4)          /*  Apagado del LED D3 (PortF[4]) */

#define LED_D4_On()                 (GPIO_PORTF_AHB_DATA_R |= GPIO_PIN_0)           /*  Encendido del LED D4 (PortF[0]) */
#define LED_D4_Off()                (GPIO_PORTF_AHB_DATA_R &= ~GPIO_PIN_0)          /*  Apagado del LED D4 (PortF[0]) */

    /*  Lectura de los botones de usuario (SWn) */
#define SW1_Pressed                 (!(GPIO_PORTJ_AHB_DATA_R & GPIO_PIN_0))         /*  Lectura del SW1 (PortJ[0]) => Presionado */
#define SW2_Pressed                 (!(GPIO_PORTJ_AHB_DATA_R & GPIO_PIN_1))         /*  Lectura del SW2 (PortJ[1]) => Presionado */


/*********************************************************************************
 * Prototipos de funciones públicas
 */

void GPIO_PortF_Init(void);                                                         /*  Inicialización del GPIO PortF */
void GPIO_PortJ_Init(void);                                                         /*  Inicialización del GPIO PortJ */
void GPIO_PortN_Init(void);                                                         /*  Inicialización del GPIO PortN */


#endif
