/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       16 de abril de 2025
 * 
 * Código:      Header file del GPIO
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef GPIO_H                                                                      /*  Verificar si GPIO_H no ha sido definido previamente */
#define GPIO_H                                                                      /*  Definir GPIO_H para evitar inclusiones mútliples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * General-Purpose Input/Output (GPIO) registers                                        pp757   Register map
 */

    /*  GPIO Port F (PortF) */
#define GPIO_PORTF_AHB_DATA_R       (*((volatile uint32_t *)0x4005D044))            /*  pp759   GPIO Data >> PortF[4,0] unmasked */
#define GPIO_PORTF_AHB_DIR_R        (*((volatile uint32_t *)0x4005D400))            /*  pp760   GPIO Direction */
#define GPIO_PORTF_AHB_DEN_R        (*((volatile uint32_t *)0x4005D51C))            /*  pp781   GPIO Digital Enable */

    /*  GPIO Port J (PortJ) */
#define GPIO_PORTJ_AHB_DATA_R       (*((volatile uint32_t *)0x4006000C))            /*  pp759   GPIO Data >> PortJ[1..0] unmasked */
#define GPIO_PORTJ_AHB_DIR_R        (*((volatile uint32_t *)0x40060400))            /*  pp760   GPIO Direction */
#define GPIO_PORTJ_AHB_IS_R         (*((volatile uint32_t *)0x40060404))            /*  pp761   GPIO Interrupt Sense */
#define GPIO_PORTJ_AHB_IBE_R        (*((volatile uint32_t *)0x40060408))            /*  pp762   GPIO Interrupt Both Edges */
#define GPIO_PORTJ_AHB_IEV_R        (*((volatile uint32_t *)0x4006040C))            /*  pp763   GPIO Interrupt Event */
#define GPIO_PORTJ_AHB_IM_R         (*((volatile uint32_t *)0x40060410))            /*  pp764   GPIO Interrupt Mask */
#define GPIO_PORTJ_AHB_ICR_R        (*((volatile uint32_t *)0x4006041C))            /*  pp769   GPIO Interrupt Clear */
#define GPIO_PORTJ_AHB_PUR_R        (*((volatile uint32_t *)0x40060510))            /*  pp776   GPIO Pull-Up Select */
#define GPIO_PORTJ_AHB_DEN_R        (*((volatile uint32_t *)0x4006051C))            /*  pp781   GPIO Digital Enable */

    /*  GPIO Port N (PortN) */
#define GPIO_PORTN_DATA_R           (*((volatile uint32_t *)0x4006400C))            /*  pp759   GPIO Data >> PortN[1..0] unmasked */
#define GPIO_PORTN_DIR_R            (*((volatile uint32_t *)0x40064400))            /*  pp760   GPIO Direction */
#define GPIO_PORTN_DEN_R            (*((volatile uint32_t *)0x4006451C))            /*  pp781   GPIO Digital Enable */


/*********************************************************************************
 * Macros de apoyo
 */

    // Bit fields for the GPIO pin
#define GPIO_PIN_7                  0x00000080                                      /*  GPIO pin 7 */
#define GPIO_PIN_6                  0x00000040                                      /*  GPIO pin 6 */
#define GPIO_PIN_5                  0x00000020                                      /*  GPIO pin 5 */
#define GPIO_PIN_4                  0x00000010                                      /*  GPIO pin 4 */
#define GPIO_PIN_3                  0x00000008                                      /*  GPIO pin 3 */
#define GPIO_PIN_2                  0x00000004                                      /*  GPIO pin 2 */
#define GPIO_PIN_1                  0x00000002                                      /*  GPIO pin 1 */
#define GPIO_PIN_0                  0x00000001                                      /*  GPIO pin 0 */

    // Bit fields in the GPIO_IM register                                               pp764
#define GPIO_IM_DMAIME              0x00000100                                      /*  GPIO uDMA Done Interrupt Mask Enable */

    // Bit fields in the GPIO_ICR register                                              pp769
#define GPIO_ICR_DMAIC              0x00000100                                      /*  GPIO uDMA Interrupt Clear */

    /*  Control de los LED de usuario (Dn) */
#define LED_D1_Toggle()             (GPIO_PORTN_DATA_R ^= GPIO_PIN_1)               /*  Conmutación del LED D1 (PortN[1]) */
#define LED_D2_Toggle()             (GPIO_PORTN_DATA_R ^= GPIO_PIN_0)               /*  Conmutación del LED D2 (PortN[0]) */
#define LED_D3_Toggle()             (GPIO_PORTF_AHB_DATA_R ^= GPIO_PIN_4)           /*  Conmutación del LED D3 (PortF[4]) */
#define LED_D4_Toggle()             (GPIO_PORTF_AHB_DATA_R ^= GPIO_PIN_0)           /*  Conmutación del LED D4 (PortF[0]) */

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
