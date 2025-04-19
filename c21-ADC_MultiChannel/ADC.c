/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Código:      Archivo fuente del ADC
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "ADC.h"                                                                    /*  Macros para el uso de ADC */
#include "GPIO.h"                                                                   /*  Macros para el uso de GPIO */
#include "SYSCTL.h"                                                                 /*  Macros para el uso de SYSCTL */


/*********************************************************************************
 * Funciones
 */

 void ADC0_SS0_Init () {

    /**
     * Configuración del ADC
     */

    /*  Paso 1: Habilitar la señal de reloj del ADC (RCGCADC) y esperar a que se estabilice (PRADC) */
    SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0;                                          /*  R0: ADC0 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRADC_R & SYSCTL_PRADC_R0)) {}                                  /*  R0: ADC0 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 2: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;                                        /*  R1: GPIO PortB Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R1)) {}                                /*  R1: GPIO PortB Peripheral Ready -> Peripheral is ready for access? */

    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R9;                                        /*  R9: GPIO PortK Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R9)) {}                                /*  R9: GPIO PortK Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 3: Habilitar la función alterna del GPIO (GPIOAFSEL) */
    GPIO_PORTB_AHB_AFSEL_R |= GPIO_PIN_4;                                           /*  PortB[4] => AFSEL: Alternate Function Select -> Alternate hardware function */
    GPIO_PORTK_AFSEL_R |= GPIO_PIN_1;                                               /*  PortK[1] => AFSEL: Alternate Function Select -> Alternate hardware function */

    /*  Paso 4: Deshabilitar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTB_AHB_DEN_R &= ~GPIO_PIN_4;                                            /*  PortB[4] => DEN: Digital Enable -> Disabled */
    GPIO_PORTK_DEN_R &= ~GPIO_PIN_1;                                                /*  PortK[1] => DEN: Digital Enable -> Disabled */

    /*  Paso 5: Deshabilitar el circuito de aislamiento analógico del GPIO (GPIOAMSEL) */
    GPIO_PORTB_AHB_AMSEL_R |= GPIO_PIN_4;                                           /*  PortB[4] => GPIOAMSEL: Analog Mode Select -> Isolation disabled, analog function enabled */
    GPIO_PORTK_AMSEL_R |= GPIO_PIN_1;                                               /*  PortK[1] => GPIOAMSEL: Analog Mode Select -> Isolation disabled, analog function enabled */

    /*  Paso 6: Configurar los niveles de prioridad del secuenciador de muestras (ADCSSPRI) */
    uint32_t reg = ADC0_SSPRI_R;
    reg &= ~(ADC_SSPRI_SS3_M | ADC_SSPRI_SS2_M | ADC_SSPRI_SS1_M | ADC_SSPRI_SS0_M);    /*  ADC0 => SS3, SS2, SS1, SS0: SSn Priority -> Bits cleared */
    reg |= ((3 << ADC_SSPRI_SS3_S) |                                                /*  ADC0 => SS3: SS3 Priority -> 3 (lowest priority) */
            (2 << ADC_SSPRI_SS2_S) |                                                /*  ADC0 => SS2: SS2 Priority -> 2 */
            (1 << ADC_SSPRI_SS1_S) |                                                /*  ADC0 => SS1: SS1 Priority -> 1 */
            (0 << ADC_SSPRI_SS0_S));                                                /*  ADC0 => SS0: SS0 Priority -> 0 (highest priority) */
    ADC0_SSPRI_R = reg;

    /**
     * Configuración del secuenciador de muestras (SS)
     */

    /*  Paso 1: Deshabilitar el SS (ADCACTSS) */
    ADC0_ACTSS_R &= ~ADC_ACTSS_ASEN0;                                               /*  ADC0 => ASEN0: SS0 Enable -> Disabled */

    /*  Paso 2: Configurar el evento de disparo para el SS (ADCEMUX) */
    ADC0_EMUX_R = (ADC0_EMUX_R & ~ADC_EMUX_EM0_M) | ADC_EMUX_EM0_PROCESSOR;         /*  ADC0 => EM1: SS0 Trigger Select -> Processor (ADCPSSI) */

    /*  Paso 3: Cuando se utiliza un generador PWM como fuente de disparo, especificar el modulo PWM (ADCTSSEL) */

    /*  Paso 4: Para cada muestra en el SS, configurar la fuente de entrada (ADCSSMUXn y ADCSSEMUXn) */
    reg = ADC0_SSMUX0_R;
    reg &= ~(ADC_SSMUX0_MUX3_M | ADC_SSMUX0_MUX2_M | ADC_SSMUX0_MUX1_M | ADC_SSMUX0_MUX0_M);
    reg |= ((0 << ADC_SSMUX0_MUX7_S) |                                              /*  ADC0 => SS0 MUX7: 8th Sample Input Select -> AIN_0 */
            (0 << ADC_SSMUX0_MUX6_S) |                                              /*  ADC0 => SS0 MUX6: 7th Sample Input Select -> AIN_0 */
            (0 << ADC_SSMUX0_MUX5_S) |                                              /*  ADC0 => SS0 MUX5: 6th Sample Input Select -> AIN_0 */
            (0 << ADC_SSMUX0_MUX4_S) |                                              /*  ADC0 => SS0 MUX4: 5th Sample Input Select -> AIN_0 */
            (0 << ADC_SSMUX0_MUX3_S) |                                              /*  ADC0 => SS0 MUX3: 4th Sample Input Select -> AIN_0 */
            (0 << ADC_SSMUX0_MUX2_S) |                                              /*  ADC0 => SS0 MUX2: 3rd Sample Input Select -> AIN_0 */
            (1 << ADC_SSMUX0_MUX1_S) |                                              /*  ADC0 => SS0 MUX1: 2nd Sample Input Select -> AIN_17 */
            (10 << ADC_SSMUX0_MUX0_S));                                             /*  ADC0 => SS0 MUX0: 1st Sample Input Select -> AIN_10 */
    ADC0_SSMUX0_R = reg;

    reg = ADC0_SSEMUX0_R;
    reg &= ~ADC_SSEMUX0_EMUX7;                                                      /*  ADC0 => SS0 EMUX7: 8th Sample Input Select -> Selected from AIN[15:0] */
    reg &= ~ADC_SSEMUX0_EMUX6;                                                      /*  ADC0 => SS0 EMUX6: 7th Sample Input Select -> Selected from AIN[15:0] */
    reg &= ~ADC_SSEMUX0_EMUX5;                                                      /*  ADC0 => SS0 EMUX5: 6th Sample Input Select -> Selected from AIN[15:0] */
    reg &= ~ADC_SSEMUX0_EMUX4;                                                      /*  ADC0 => SS0 EMUX4: 5th Sample Input Select -> Selected from AIN[15:0] */
    reg &= ~ADC_SSEMUX0_EMUX3;                                                      /*  ADC0 => SS0 EMUX3: 4th Sample Input Select -> Selected from AIN[15:0] */
    reg &= ~ADC_SSEMUX0_EMUX2;                                                      /*  ADC0 => SS0 EMUX2: 3rd Sample Input Select -> Selected from AIN[15:0] */
    reg |= ADC_SSEMUX0_EMUX1;                                                       /*  ADC0 => SS0 EMUX1: 2nd Sample Input Select -> Selected from AIN[19:16] */
    reg &= ~ADC_SSEMUX0_EMUX0;                                                      /*  ADC0 => SS0 EMUX0: 1st Sample Input Select -> Selected from AIN[15:0] */
    ADC0_SSEMUX0_R = reg;

    /*  Paso 5: Para cada muestra en el SS, configurar los bits de control (ADCSSCTLn), asegurando que el bit END de la última muestra esté habilitado */
    reg = ADC0_SSCTL0_R;
    reg &= ~(0xFFFFFFFF);                                                           /*  ADC0 => SS0 8th, 7th, 6th, 5th, 4th, 3rd, 2nd, 1st control -> Bits cleared */
    reg |= (ADC_SSCTL0_TS2 |                                                        /*  ADC0 => SS0 TS2: 3rd Sample Temp Sensor Select -> The temperature sensor is read */
            ADC_SSCTL0_IE2 |                                                        /*          SS0 IE2: 3rd Sample Interrupt Enable -> Raw interrupt is asserted at the end of the conversion */
            ADC_SSCTL0_END2);                                                       /*          SS0 END2: 3rd Sample is End of Sequence -> Is the last sample of the sequence */
    ADC0_SSCTL0_R = reg;

    /*  Paso 6: Para la interrupción, desenmascarar la interrupción (ADCIM) */
    ADC0_IM_R &= ~ADC_IM_MASK0;                                                     /*  ADC0 => MASK0: SS0 Interrupt Mask -> Masked */

    /*  Paso 7: Habilitar el SS (ADCACTSS) */
    ADC0_ACTSS_R |= ADC_ACTSS_ASEN0;                                                /*  ADC0 => ASEN0: SS0 Enable -> Enabled */
    
    /**
     * Configuración de la interrupción
     */

    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    /*  Paso 2: Habilitar la interrupción (ENn) */

    /**
     * Habilitación del PLL
     * NOTA: Si se utiliza el PIOSC de 16MHz como fuente de reloj, es necesario habilitar y deshabilitar el PLL.
     */

    /*  Paso 1: Encender el PLL (PLLFREQ_0) y esperar a que esté encendido y retroalimentado () */
    SYSCTL_PLLFREQ0_R |= SYSCTL_PLLFREQ0_PLLPWR;                                    /*  PLL => PLLPWR: PLL Power -> Enabled and oscillate based on (PLLFREQ0, PLLFREQ1) */
    while (!(SYSCTL_PLLSTAT_R & SYSCTL_PLLSTAT_LOCK)) {}                            /*  PLL => LOCK: Lock -> PLL powered and locked */

    /*  Paso 2: Habilitar el PIOSC (ADCCC) */
    ADC0_CC_R = ((ADC0_CC_R & ~ADC_CC_CS_M) | ADC_CC_CS_PIOSC);                     /*  ADC0 => CS: Clock Source -> Alternate clock source as defined by ALTCLKCFG (default: PIOSC) */

    /*  Paso 3: Deshabilitar el PLL (PLLFREQ_0) */
    SYSCTL_PLLFREQ0_R &= ~SYSCTL_PLLFREQ0_PLLPWR;                                   /*  PLL => PLLPWR: PLL Power -> Disabled */

}
