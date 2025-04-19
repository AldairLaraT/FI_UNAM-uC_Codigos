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

 void ADC1_SS2_Init () {

    /**
     * Configuración del ADC
     */

    /*  Paso 1: Habilitar la señal de reloj del ADC (RCGCADC) y esperar a que se estabilice (PRADC) */
    SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R1;                                          /*  R1: ADC1 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRADC_R & SYSCTL_PRADC_R1)) {}                                  /*  R1: ADC1 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 2: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    /*  Paso 3: Habilitar la función alterna del GPIO (GPIOAFSEL) */
    /*  Paso 4: Deshabilitar las funciones digitales del GPIO (GPIODEN) */
    /*  Paso 5: Deshabilitar el circuito de aislamiento analógico del GPIO (GPIOAMSEL) */

    /*  Paso 6: Configurar los niveles de prioridad del secuenciador de muestras (ADCSSPRI) */
    uint32_t reg = ADC1_SSPRI_R;
    reg &= ~(ADC_SSPRI_SS3_M | ADC_SSPRI_SS2_M | ADC_SSPRI_SS1_M | ADC_SSPRI_SS0_M);    /*  ADC1 => SS3, SS2, SS1, SS0: SSn Priority -> Bits cleared */
    reg |= ((3 << ADC_SSPRI_SS3_S) |                                                /*  ADC1 => SS3: SS3 Priority -> 3 (lowest priority) */
            (2 << ADC_SSPRI_SS2_S) |                                                /*  ADC1 => SS2: SS2 Priority -> 2 */
            (1 << ADC_SSPRI_SS1_S) |                                                /*  ADC1 => SS1: SS1 Priority -> 1 */
            (0 << ADC_SSPRI_SS0_S));                                                /*  ADC1 => SS0: SS0 Priority -> 0 (highest priority) */
    ADC1_SSPRI_R = reg;

    /**
     * Configuración del secuenciador de muestras (SS)
     */

    /*  Paso 1: Deshabilitar el SS (ADCACTSS) */
    ADC1_ACTSS_R &= ~ADC_ACTSS_ASEN2;                                               /*  ADC1 => ASEN2: SS2 Enable -> Disabled */

    /*  Paso 2: Configurar el evento de disparo para el SS (ADCEMUX) */
    ADC1_EMUX_R = (ADC1_EMUX_R & ~ADC_EMUX_EM2_M) | ADC_EMUX_EM2_PROCESSOR;         /*  ADC1 => EM2: SS2 Trigger Select -> Processor (ADCPSSI) */

    /*  Paso 3: Cuando se utiliza un generador PWM como fuente de disparo, especificar el modulo PWM (ADCTSSEL) */

    /*  Paso 4: Para cada muestra en el SS, configurar la fuente de entrada (ADCSSMUXn y ADCSSEMUXn) */
    reg = ADC1_SSMUX2_R;
    reg &= ~(ADC_SSMUX2_MUX3_M | ADC_SSMUX2_MUX2_M | ADC_SSMUX2_MUX1_M | ADC_SSMUX2_MUX0_M);
    reg |= ((0 << ADC_SSMUX2_MUX3_S) |                                              /*  ADC1 => SS2 MUX3: 4th Sample Input Select -> AIN_0 */
            (0 << ADC_SSMUX2_MUX2_S) |                                              /*  ADC1 => SS2 MUX2: 3rd Sample Input Select -> AIN_0 */
            (0 << ADC_SSMUX2_MUX1_S) |                                              /*  ADC1 => SS2 MUX1: 2nd Sample Input Select -> AIN_0 */
            (0 << ADC_SSMUX2_MUX0_S));                                              /*  ADC1 => SS2 MUX0: 1st Sample Input Select -> AIN_0 */
    ADC1_SSMUX2_R = reg;

    reg = ADC1_SSEMUX2_R;
    reg &= ~ADC_SSEMUX2_EMUX3;                                                      /*  ADC1 => SS2 EMUX3: 4th Sample Input Select -> Selected from AIN[15:0] */
    reg &= ~ADC_SSEMUX2_EMUX2;                                                      /*  ADC1 => SS2 EMUX2: 3rd Sample Input Select -> Selected from AIN[15:0] */
    reg &= ~ADC_SSEMUX2_EMUX1;                                                      /*  ADC1 => SS2 EMUX1: 2nd Sample Input Select -> Selected from AIN[15:0] */
    reg &= ~ADC_SSEMUX2_EMUX0;                                                      /*  ADC1 => SS2 EMUX0: 1st Sample Input Select -> Selected from AIN[15:0] */
    ADC1_SSEMUX2_R = reg;

    /*  Paso 5: Para cada muestra en el SS, configurar los bits de control (ADCSSCTLn), asegurando que el bit END de la última muestra esté habilitado */
    reg = ADC1_SSCTL2_R;
    reg &= ~(0x0000FFFF);                                                           /*  ADC1 => 4th, 3rd, 2nd, 1st control -> Bits cleared */
    reg |= (ADC_SSCTL2_TS0 |                                                        /*  ADC1 => SS2 TS0: 1st Sample Temp Sensor Select -> The temperature sensor is read */
            ADC_SSCTL2_IE0 |                                                        /*          SS2 IE0: 1st Sample Interrupt Enable -> Raw interrupt is asserted at the end of the conversion */
            ADC_SSCTL2_END0);                                                       /*          SS2 END0: 1st Sample is End of Sequence -> Is the last sample of the sequence */
    ADC1_SSCTL2_R = reg;

    /*  Paso 6: Para la interrupción, desenmascarar la interrupción (ADCIM) */
    ADC1_IM_R &= ~ADC_IM_MASK2;                                                     /*  ADC1 => MASK2: SS2 Interrupt Mask -> Masked */

    /*  Paso 7: Habilitar el SS (ADCACTSS) */
    ADC1_ACTSS_R |= ADC_ACTSS_ASEN2;                                                /*  ADC1 => ASEN2: SS2 Enable -> Enabled */
    
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
    ADC1_CC_R = ((ADC1_CC_R & ~ADC_CC_CS_M) | ADC_CC_CS_PIOSC);                     /*  ADC1 => CS: Clock Source -> Alternate clock source as defined by ALTCLKCFG (default: PIOSC) */

    /*  Paso 3: Deshabilitar el PLL (PLLFREQ_0) */
    SYSCTL_PLLFREQ0_R &= ~SYSCTL_PLLFREQ0_PLLPWR;                                   /*  PLL => PLLPWR: PLL Power -> Disabled */

}
