/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       03 de mayo de 2025
 * 
 * Código:      Archivo de cabecera del GPTM
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


#ifndef GPTM_H                                                                      /*  Verificar si GPTM_H no ha sido definido previamente */
#define GPTM_H                                                                      /*  Definir GPTM_H para evitar inclusiones múltiples del mismo archivo */


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */


/*********************************************************************************
 * Macros de apuntadores a registros
 * General-Purpose Timers (GPTM) registers                                              pp974   Register map
 */

    /*  GPTM module 0 (TIMER0) */
#define TIMER0_CFG_R                (*((volatile uint32_t *)0x40030000))            /*  pp976   GPTM Configuration */
#define TIMER0_TAMR_R               (*((volatile uint32_t *)0x40030004))            /*  pp977   GPTM Timer A Mode */
#define TIMER0_TBMR_R               (*((volatile uint32_t *)0x40030008))            /*  pp982   GPTM Timer B Mode */
#define TIMER0_CTL_R                (*((volatile uint32_t *)0x4003000C))            /*  pp986   GPTM Control */
#define TIMER0_IMR_R                (*((volatile uint32_t *)0x40030018))            /*  pp993   GPTM Interrupt Mask */
#define TIMER0_RIS_R                (*((volatile uint32_t *)0x4003001C))            /*  pp996   GPTM Raw Interrupt Status */
#define TIMER0_ICR_R                (*((volatile uint32_t *)0x40030024))            /*  pp1002  GPTM Interrupt Clear */
#define TIMER0_TAILR_R              (*((volatile uint32_t *)0x40030028))            /*  pp1004  GPTM Timer A Interval Load */
#define TIMER0_TBILR_R              (*((volatile uint32_t *)0x4003002C))            /*  pp1005  GPTM Timer B Interval Load */
#define TIMER0_TAPR_R               (*((volatile uint32_t *)0x40030038))            /*  pp1008  GPTM Timer A Prescale */
#define TIMER0_TBPR_R               (*((volatile uint32_t *)0x4003003C))            /*  pp1009  GPTM Timer B Prescale */
#define TIMER0_TBV_R                (*((volatile uint32_t *)0x40030054))            /*  pp1015  GPTM Timer B Value */

    /*  GPTM module 1 (TIMER1) */
#define TIMER1_CFG_R                (*((volatile uint32_t *)0x40031000))            /*  pp976   GPTM Configuration */
#define TIMER1_TAMR_R               (*((volatile uint32_t *)0x40031004))            /*  pp977   GPTM Timer A Mode */
#define TIMER1_CTL_R                (*((volatile uint32_t *)0x4003100C))            /*  pp986   GPTM Control */
#define TIMER1_IMR_R                (*((volatile uint32_t *)0x40031018))            /*  pp993   GPTM Interrupt Mask */
#define TIMER1_ICR_R                (*((volatile uint32_t *)0x40031024))            /*  pp1002  GPTM Interrupt Clear */
#define TIMER1_TAILR_R              (*((volatile uint32_t *)0x40031028))            /*  pp1004  GPTM Timer A Interval Load */

    /*  GPTM module 2 (TIMER2) */
#define TIMER2_CFG_R                (*((volatile uint32_t *)0x40032000))            /*  pp976   GPTM Configuration */
#define TIMER2_TAMR_R               (*((volatile uint32_t *)0x40032004))            /*  pp977   GPTM Timer A Mode */
#define TIMER2_CTL_R                (*((volatile uint32_t *)0x4003200C))            /*  pp986   GPTM Control */
#define TIMER2_IMR_R                (*((volatile uint32_t *)0x40032018))            /*  pp993   GPTM Interrupt Mask */
#define TIMER2_ICR_R                (*((volatile uint32_t *)0x40032024))            /*  pp1002  GPTM Interrupt Clear */
#define TIMER2_TAILR_R              (*((volatile uint32_t *)0x40032028))            /*  pp1004  GPTM Timer A Interval Load */
#define TIMER2_TAR_R                (*((volatile uint32_t *)0x40032048))            /*  pp1012  GPTM Timer A */
#define TIMER2_TAV_R                (*((volatile uint32_t *)0x40032050))            /*  pp1014  GPTM Timer A Value */


/*********************************************************************************
 * Macros auxiliares
 */

    // Bit fields in the TIMER_CFG register                                             pp976
#define TIMER_CFG_M                 0x00000007                                      /*  GPTM Configuration mask */
#define TIMER_CFG_32_BIT_TIMER      0x00000000                                      /*  For a 16/32-bit timer, this value selects the 32-bit timer configuration */
#define TIMER_CFG_32_BIT_RTC        0x00000001                                      /*  For a 16/32-bit timer, this value selects the 32-bit real-time clock (RTC) counter configuration */
#define TIMER_CFG_16_BIT            0x00000004                                      /*  For a 16/32-bit timer, this value selects the 16-bit timer configuration */

    // Bit fields in the TIMER_TAMR register                                            pp977
#define TIMER_TAMR_TCACT_M          0x0000E000                                      /*  Timer Compare Action Select mask */
#define TIMER_TAMR_TCACT_NONE       0x00000000                                      /*  Disable compare operations */
#define TIMER_TAMR_TCACT_TOGGLE     0x00002000                                      /*  Toggle State on Time-Out */
#define TIMER_TAMR_TCACT_CLRTO      0x00004000                                      /*  Clear CCP on Time-Out */
#define TIMER_TAMR_TCACT_SETTO      0x00006000                                      /*  Set CCP on Time-Out */
#define TIMER_TAMR_TCACT_SETTOGTO   0x00008000                                      /*  Set CCP immediately and toggle on Time-Out */
#define TIMER_TAMR_TCACT_CLRTOGTO   0x0000A000                                      /*  Clear CCP immediately and toggle on Time-Out */
#define TIMER_TAMR_TCACT_SETCLRTO   0x0000C000                                      /*  Set CCP immediately and clear on Time-Out */
#define TIMER_TAMR_TCACT_CLRSETTO   0x0000E000                                      /*  Clear CCP immediately and set on Time-Out */
#define TIMER_TAMR_TACINTD          0x00001000                                      /*  One-shot/Periodic Interrupt Disable */
#define TIMER_TAMR_TAPLO            0x00000800                                      /*  GPTM Timer A PWM Legacy Operation */
#define TIMER_TAMR_TAMRSU           0x00000400                                      /*  GPTM Timer A Match Register Update */
#define TIMER_TAMR_TAPWMIE          0x00000200                                      /*  GPTM Timer A PWM Interrupt Enable */
#define TIMER_TAMR_TAILD            0x00000100                                      /*  GPTM Timer A Interval Load Write */
#define TIMER_TAMR_TASNAPS          0x00000080                                      /*  GPTM Timer A Snap-Shot Mode */
#define TIMER_TAMR_TAWOT            0x00000040                                      /*  GPTM Timer A Wait-on-Trigger */
#define TIMER_TAMR_TAMIE            0x00000020                                      /*  GPTM Timer A Match Interrupt Enable */
#define TIMER_TAMR_TACDIR           0x00000010                                      /*  GPTM Timer A Count Direction */
#define TIMER_TAMR_TAAMS            0x00000008                                      /*  GPTM Timer A Alternate Mode Select */
#define TIMER_TAMR_TACMR            0x00000004                                      /*  GPTM Timer A Capture Mode */
#define TIMER_TAMR_TAMR_M           0x00000003                                      /*  GPTM Timer A Mode mask */
#define TIMER_TAMR_TAMR_1_SHOT      0x00000001                                      /*  One-Shot Timer mode */
#define TIMER_TAMR_TAMR_PERIOD      0x00000002                                      /*  Periodic Timer mode */
#define TIMER_TAMR_TAMR_CAP         0x00000003                                      /*  Capture mode */

    // Bit fields in the TIMER_TBMR register                                            pp982
#define TIMER_TBMR_TCACT_M          0x0000E000                                      /*  Timer Compare Action Select mask */
#define TIMER_TBMR_TCACT_NONE       0x00000000                                      /*  Disable compare operations */
#define TIMER_TBMR_TCACT_TOGGLE     0x00002000                                      /*  Toggle State on Time-Out */
#define TIMER_TBMR_TCACT_CLRTO      0x00004000                                      /*  Clear CCP on Time-Out */
#define TIMER_TBMR_TCACT_SETTO      0x00006000                                      /*  Set CCP on Time-Out */
#define TIMER_TBMR_TCACT_SETTOGTO   0x00008000                                      /*  Set CCP immediately and toggle on Time-Out */
#define TIMER_TBMR_TCACT_CLRTOGTO   0x0000A000                                      /*  Clear CCP immediately and toggle on Time-Out */
#define TIMER_TBMR_TCACT_SETCLRTO   0x0000C000                                      /*  Set CCP immediately and clear on Time-Out */
#define TIMER_TBMR_TCACT_CLRSETTO   0x0000E000                                      /*  Clear CCP immediately and set on Time-Out */
#define TIMER_TBMR_TBCINTD          0x00001000                                      /*  One-Shot/Periodic Interrupt Disable */
#define TIMER_TBMR_TBPLO            0x00000800                                      /*  GPTM Timer B PWM Legacy Operation */
#define TIMER_TBMR_TBMRSU           0x00000400                                      /*  GPTM Timer B Match Register Update */
#define TIMER_TBMR_TBPWMIE          0x00000200                                      /*  GPTM Timer B PWM Interrupt Enable */
#define TIMER_TBMR_TBILD            0x00000100                                      /*  GPTM Timer B Interval Load Write */
#define TIMER_TBMR_TBSNAPS          0x00000080                                      /*  GPTM Timer B Snap-Shot Mode */
#define TIMER_TBMR_TBWOT            0x00000040                                      /*  GPTM Timer B Wait-on-Trigger */
#define TIMER_TBMR_TBMIE            0x00000020                                      /*  GPTM Timer B Match Interrupt Enable */
#define TIMER_TBMR_TBCDIR           0x00000010                                      /*  GPTM Timer B Count Direction */
#define TIMER_TBMR_TBAMS            0x00000008                                      /*  GPTM Timer B Alternate Mode Select */
#define TIMER_TBMR_TBCMR            0x00000004                                      /*  GPTM Timer B Capture Mode */
#define TIMER_TBMR_TBMR_M           0x00000003                                      /*  GPTM Timer B Mode mask */
#define TIMER_TBMR_TBMR_1_SHOT      0x00000001                                      /*  One-Shot Timer mode */
#define TIMER_TBMR_TBMR_PERIOD      0x00000002                                      /*  Periodic Timer mode */
#define TIMER_TBMR_TBMR_CAP         0x00000003                                      /*  Capture mode */

    // Bit fields in the TIMER_CTL register                                             pp986
#define TIMER_CTL_TBPWML            0x00004000                                      /*  GPTM Timer B PWM Output Level */
#define TIMER_CTL_TBOTE             0x00002000                                      /*  GPTM Timer B Output Trigger Enable */
#define TIMER_CTL_TBEVENT_M         0x00000C00                                      /*  GPTM Timer B Event Mode mask */
#define TIMER_CTL_TBEVENT_POS       0x00000000                                      /*  Positive edge */
#define TIMER_CTL_TBEVENT_NEG       0x00000400                                      /*  Negative edge */
#define TIMER_CTL_TBEVENT_BOTH      0x00000C00                                      /*  Both edges */
#define TIMER_CTL_TBSTALL           0x00000200                                      /*  GPTM Timer B Stall Enable */
#define TIMER_CTL_TBEN              0x00000100                                      /*  GPTM Timer B Enable */
#define TIMER_CTL_TAPWML            0x00000040                                      /*  GPTM Timer A PWM Output Level */
#define TIMER_CTL_TAOTE             0x00000020                                      /*  GPTM Timer A Output Trigger Enable */
#define TIMER_CTL_RTCEN             0x00000010                                      /*  GPTM RTC Stall Enable */
#define TIMER_CTL_TAEVENT_M         0x0000000C                                      /*  GPTM Timer A Event Mode mask */
#define TIMER_CTL_TAEVENT_POS       0x00000000                                      /*  Positive edge */
#define TIMER_CTL_TAEVENT_NEG       0x00000004                                      /*  Negative edge */
#define TIMER_CTL_TAEVENT_BOTH      0x0000000C                                      /*  Both edges */
#define TIMER_CTL_TASTALL           0x00000002                                      /*  GPTM Timer A Stall Enable */
#define TIMER_CTL_TAEN              0x00000001                                      /*  GPTM Timer A Enable */

    // Bit fields in the TIMER_IMR register                                             pp993
#define TIMER_IMR_DMABIM            0x00002000                                      /*  GPTM Timer B DMA Done Interrupt Mask */
#define TIMER_IMR_TBMIM             0x00000800                                      /*  GPTM Timer B Match Interrupt Mask */
#define TIMER_IMR_CBEIM             0x00000400                                      /*  GPTM Timer B Capture Mode Event Interrupt Mask */
#define TIMER_IMR_CBMIM             0x00000200                                      /*  GPTM Timer B Capture Mode Match Interrupt Mask */
#define TIMER_IMR_TBTOIM            0x00000100                                      /*  GPTM Timer B Time-Out Interrupt Mask */
#define TIMER_IMR_DMAAIM            0x00000020                                      /*  GPTM Timer A DMA Done Interrupt Mask */
#define TIMER_IMR_TAMIM             0x00000010                                      /*  GPTM Timer A Match Interrupt Mask */
#define TIMER_IMR_RTCIM             0x00000008                                      /*  GPTM RTC Interrupt Mask */
#define TIMER_IMR_CAEIM             0x00000004                                      /*  GPTM Timer A Capture Mode Event Interrupt Mask */
#define TIMER_IMR_CAMIM             0x00000002                                      /*  GPTM Timer A Capture Mode Match Interrupt Mask */
#define TIMER_IMR_TATOIM            0x00000001                                      /*  GPTM Timer A Time-Out Interrupt Mask */

    // Bit fields in the TIMER_RIS register                                             pp996
#define TIMER_RIS_DMABRIS           0x00002000                                      /*  GPTM Timer B DMA Done Raw Interrupt Status */
#define TIMER_RIS_TBMRIS            0x00000800                                      /*  GPTM Timer B Match Raw Interrupt */
#define TIMER_RIS_CBERIS            0x00000400                                      /*  GPTM Timer B Capture Mode Event Raw Interrupt */
#define TIMER_RIS_CBMRIS            0x00000200                                      /*  GPTM Timer B Capture Mode Match Raw Interrupt */
#define TIMER_RIS_TBTORIS           0x00000100                                      /*  GPTM Timer B Time-Out Raw Interrupt */
#define TIMER_RIS_DMAARIS           0x00000020                                      /*  GPTM Timer A DMA Done Raw Interrupt Status */
#define TIMER_RIS_TAMRIS            0x00000010                                      /*  GPTM Timer A Match Raw Interrupt */
#define TIMER_RIS_RTCRIS            0x00000008                                      /*  GPTM RTC Raw Interrupt */
#define TIMER_RIS_CAERIS            0x00000004                                      /*  GPTM Timer A Capture Mode Event Raw Interrupt */
#define TIMER_RIS_CAMRIS            0x00000002                                      /*  GPTM Timer A Capture Mode Match Raw Interrupt */
#define TIMER_RIS_TATORIS           0x00000001                                      /*  GPTM Timer A Time-Out Raw Interrupt */

    // Bit fields in the TIMER_ICR register                                             pp1002
#define TIMER_ICR_DMABINT           0x00002000                                      /*  GPTM Timer B DMA Done Interrupt Clear */
#define TIMER_ICR_TBMCINT           0x00000800                                      /*  GPTM Timer B Match Interrupt Clear */
#define TIMER_ICR_CBECINT           0x00000400                                      /*  GPTM Timer B Capture Mode Event Interrupt Clear */
#define TIMER_ICR_CBMCINT           0x00000200                                      /*  GPTM Timer B Capture Mode Match Interrupt Clear */
#define TIMER_ICR_TBTOCINT          0x00000100                                      /*  GPTM Timer B Time-Out Interrupt Clear */
#define TIMER_ICR_DMAAINT           0x00000020                                      /*  GPTM Timer A DMA Done Interrupt Clear */
#define TIMER_ICR_TAMCINT           0x00000010                                      /*  GPTM Timer A Match Interrupt Clear */
#define TIMER_ICR_RTCCINT           0x00000008                                      /*  GPTM RTC Interrupt Clear */
#define TIMER_ICR_CAECINT           0x00000004                                      /*  GPTM Timer A Capture Mode Event Interrupt Clear */
#define TIMER_ICR_CAMCINT           0x00000002                                      /*  GPTM Timer A Capture Mode Match Interrupt Clear */
#define TIMER_ICR_TATOCINT          0x00000001                                      /*  GPTM Timer A Time-Out Raw Interrupt */

    // Bit fields in the TIMER_TAILR register                                           pp1004
#define TIMER_TAILR_M               0xFFFFFFFF                                      /*  GPTM Timer A Interval Load Register mask */
#define TIMER_TAILR_S               0                                               /*  GPTM Timer A Interval Load Register shift */

    // Bit fields in the TIMER_TBILR register                                           pp1005
#define TIMER_TBILR_M               0xFFFFFFFF                                      /*  GPTM Timer B Interval Load Register mask */
#define TIMER_TBILR_S               0                                               /*  GPTM Timer B Interval Load Register shift */

    // Bit fields in the TIMER_TAPR register                                            pp1008
#define TIMER_TAPR_TAPSR_M          0x000000FF                                      /*  GPTM Timer A Prescale mask */
#define TIMER_TAPR_TAPSR_S          0                                               /*  GPTM Timer A Prescale shift */

    // Bit fields in the TIMER_TAR register                                             pp1012
#define TIMER_TAR_M                 0xFFFFFFFF                                      /*  GPTM Timer A Register mask */
#define TIMER_TAR_S                 0                                               /*  GPTM Timer A Register shift */

    // Bit fields in the TIMER_TAV register                                             pp1014
#define TIMER_TAV_M                 0xFFFFFFFF                                      /*  GPTM Timer A Value mask */
#define TIMER_TAV_S                 0                                               /*  GPTM Timer A Value shift */

    // Bit fields in the TIMER_TBV register                                             pp1015
#define TIMER_TBV_M                 0xFFFFFFFF                                      /*  GPTM Timer B Value mask */
#define TIMER_TBV_S                 0                                               /*  GPTM Timer B Value shift */

    /*  Habilitación del TIMER */
#define GPTM0_A_Initiate()          (TIMER0_CTL_R |= TIMER_CTL_TAEN)                /*  GPTM0 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */
#define GPTM0_B_Initiate()          (TIMER0_CTL_R |= TIMER_CTL_TBEN)                /*  GPTM0 => TBEN: GPTM Timer B Enable -> Enabled and begins counting */
#define GPTM1_A_Initiate()          (TIMER1_CTL_R |= TIMER_CTL_TAEN)                /*  GPTM1 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */
#define GPTM2_A_Initiate()          (TIMER2_CTL_R |= TIMER_CTL_TAEN)                /*  GPTM2 => TAEN: GPTM Timer A Enable -> Enabled and begins counting */

    /*  Detener el TIMER */
#define GPTM2_A_Stop()              (TIMER2_CTL_R &= ~TIMER_CTL_TAEN)               /*  GPTM2 => TAEN: GPTM Timer A Enable -> Disabled */

    /*  Lectura del estado del TIMER (Time-Out) */
#define GPTM0_A_RawInterrupt_TimeOut_wait()     while (!(TIMER0_RIS_R & TIMER_RIS_TATORIS)) {}  /*  GPTM0 => TATORIS: GPTM Timer A Time-Out Raw Interrupt -> Timer A has timed out */

    /*  Limpieza de las banderas del TIMER */
#define GPTM0_A_ClearFlags_TimeOut()    (TIMER0_ICR_R |= TIMER_ICR_TATOCINT)        /*  GPTM0 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */
#define GPTM1_A_ClearFlags_TimeOut()    (TIMER1_ICR_R |= TIMER_ICR_TATOCINT)        /*  GPTM1 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */
#define GPTM2_A_ClearFlags_TimeOut()    (TIMER2_ICR_R |= TIMER_ICR_TATOCINT)        /*  GPTM2 => TATOCINT: GPTM Timer A Time-Out Raw Interrupt -> TATORIS bit (GPTMRIS) and TATOMIS bit (GPTMMIS) cleared */

/*********************************************************************************
 * Prototipos de funciones públicas
 */

void GPTM0A_Init_OneShot(uint32_t LoadValue);                                       /*  Inicialización del GPTM0 (subtimer A) en modo One-Shot */
void GPTM0B_Init_Periodic(uint32_t LoadValue);                                      /*  Inicialización del GPTM0 (subtimer B) en modo Periodic */
void GPTM1AB_Init_OneShot(uint32_t LoadValue);                                      /*  Inicialización del GPTM1 (subtimers A y B concatenados) en modo One-Shot */
void GPTM2AB_Init_OneShot(uint32_t LoadValue);                                      /*  Inicialización del GPTM2 (subtimers A y B concatenados) en modo One-Shot */


#endif                                                                              /*  GPTM_H */
