/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de mayo de 2025
 * 
 * Código:      Archivo fuente del UART
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "NVIC.h"                                                                   /*  Archivo de cabecera del NVIC */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */
#include "UART.h"                                                                   /*  Archivo de cabecera del UART */


/*********************************************************************************
 * Funciones
 */

void UART0_Init() {

    /**
     * Configuración del UART
     */

    /*  Paso 1: Habilitar la señal de reloj del UART (RCGCUART) y esperar a que se estabilice (PRUART) */
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;                                        /*  R0: UART0 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRUART_R & SYSCTL_PRUART_R0)) {}                                /*  R0: UART0 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 2: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;                                        /*  R0: GPIO PortA Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R0)) {}                                /*  R0: GPIO PortA Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 3: Habilitar la función alterna del GPIO (GPIOAFSEL) */
    GPIO_PORTA_AHB_AFSEL_R |= (GPIO_PIN_1 | GPIO_PIN_0);                            /*  PortA[1:0] => AFSEL: Alternate Function Select -> Alternate hardware function */

    /*  Paso 4: Configurar el nivel de corriente (GPIODR2R) y/o el slew rate () del GPIO */
    GPIO_PORTA_AHB_DR2R_R |= (GPIO_PIN_1 | GPIO_PIN_0);                             /*  PortA[1:0] => DRV2: Output Pad 2mA Drive Enable -> GPIO pin has 2-mA drive */
    GPIO_PORTA_AHB_SLR_R &= ~(GPIO_PIN_1 | GPIO_PIN_0);                             /*  PartA[1:0] => SRL: Slew Rate Limit Enable (8-mA, 10-mA and 12-mA drive only) -> Slew rate control is disabled */

    /*  Paso 5: Seleccionar la función alterna de hardware (GPIOPCTL) */
    uint32_t reg = GPIO_PORTA_AHB_PCTL_R;
    reg = ((reg & ~0x000000F0) | (1 << 4));                                         /*  PortA[1] => PMC1: Port Mux Control 1 -> UART0_Rx */
    reg = ((reg & ~0x0000000F) | (1 << 0));                                         /*  PortA[0] => PMC0: Port Mux Control 0 -> UART0_Tx */
    GPIO_PORTA_AHB_PCTL_R = reg;

    /*  Habilitar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTA_AHB_DEN_R |= (GPIO_PIN_1 | GPIO_PIN_0);                              /*  PortA[1:0] => DEN: Digital Enable -> Enabled */

    /**
     * Configuración del Baud-rate
     */

    /*  Paso 1: Deshabilitar el UART (UARTCTL) */
    UART0_CTL_R &= ~UART_CTL_UARTEN;                                                /*  UART0 => UARTEN: UART Enable -> Disabled */

    /*  Paso 2: Cargar la parte entera del Baud-Rate Divisor (UARTIBRD) */
    UART0_IBRD_R = (8 & UART_IBRD_DIVINT_M);                                        /*  UART0 => DIVINT: Integer Baud-Rate Divisor */

    /*  Paso 3: Cargar la parte decimal del Baud-Rate Divisor (UARTFBRD) */
    UART0_FBRD_R = (44 & UART_FBRD_DIVFRAC_M);                                      /*  UART0 => DIVFRAC: Fractional Baud-Rate Divisor */

    /*  Paso 4: Cargar los parámetros seriales deseados (UARTLCRH) */
    reg = UART0_LCRH_R;
    reg = ((reg & ~UART_LCRH_WLEN_M) | (UART_LCRH_WLEN_8));                         /*  UART0 => WLEN: UART Word Length -> 8 bits */
    reg |= UART_LCRH_FEN;                                                           /*  UART0 => FEN: UART Enable FIFOs -> Transmit and receive FIFO buffers are enabled (FIFO mode) */
    UART0_LCRH_R = reg;

    /*  Paso 5: Configurar la fuente de reloj del UART (UARTCC) */
    UART0_CC_R = ((UART0_CC_R & ~UART_CC_CS_M) | UART_CC_CS_PIOSC);                 /*  UART0 => CS: UART Baud Clock Source -> Alternate clock source as defined by ALTCLKCFG */

    /*  Paso 6: De manera opcional, configurar el canal uDMA y habilitar las opciones del DMA (UARTDMACTL) */

    /*  Para uso de interrupción, configurar el nivel de la FIFO de recepción y/o el nivel de la FIFO de 
        transmisión (UARTIFLS) y desenmascarar la interrupción (UARTIM) */
    UART0_IFLS_R = ((UART0_IFLS_R & ~UART_IFLS_RX_M) | UART_IFLS_RX1_8);            /*  UART0 => RXIFLSEL: UART Receive Interrupt FIFO Level Select -> RX FIFO >= 1/8 full */
    UART0_IM_R |= UART_IM_RXIM;                                                     /*  UART0 => RXIM: UART Receive Interrupt Mask -> Interrupt unmasked */

    /**
     * Configuración de la interrupción
     */

    /*  Paso 1: Configurar el nivel de prioridad de la interrupción (PRIn) */
    reg = NVIC_PRI1_R;
    reg &= ~NVIC_PRI1_INT5_M;                                                       /*  Interrupt 5 (UART0) => INTB: Interrupt Priority -> Bits cleared */
    reg |= (1 << NVIC_PRI1_INT5_S);                                                 /*  Interrupt 5 (UART0) => INTB: Interrupt Priority -> 1 */
    NVIC_PRI1_R = reg;

    /*  Paso 2: Habilitar la interrupción (ENn) */
    NVIC_EN0_R |= (1 << (5 - 0));                                                   /*  Interrupt 5 (UART0) => INT: Interrupt Enable -> Enabled */

    /*  Paso 7: Habilitar el UART (UARTCTL) */
    UART0_CTL_R |= UART_CTL_UARTEN;                                                 /*  UART0 => UARTEN: UART Enable -> Enabled */

}


void UART0_Transmit(char message[], int message_size) {
    int i = 0;
    for (i = 0; i < message_size; i++) {
        UART0_DR_R = (message[i] & UART_DR_DATA_M);                                 /*  UART0 => DATA: Data Transmitted or Received -> Loads DATA to be transmitted via UART */
        UART0_DataTransmit();                                                       /*  UART0 => TXFE: UART Transmit FIFO Empty -> The transmitter has data to transmit */
    }
}
