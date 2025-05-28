/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       27 de mayo de 2025
 * 
 * Código:      Archivo fuente del I2C
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "I2C.h"                                                                    /*  Archivo de cabecera del I2C */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */


/*********************************************************************************
 * Variables globales
 */

extern int error;


/*********************************************************************************
 * Funciones
 */

void I2C0_Init() {

    /**
     * Configuración del UART
     */

    /*  Paso 1: Habilitar la señal de reloj del I2C (RCGCI2C) y esperar a que se estabilice (PRI2C) */
    SYSCTL_RCGCI2C_R |= SYSCTL_RCGCI2C_R0;                                          /*  R0: I2C0 Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRI2C_R & SYSCTL_PRI2C_R0)) {}                                  /*  R0: I2C0 Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 2: Habilitar la señal de reloj del GPIO (RCGCGPIO) y esperar a que se estabilice (PRGPIO) */
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;                                        /*  R1: GPIO PortB Run Mode Clock Gating Control -> Enabled */
    while (!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R1)) {}                                /*  R1: GPIO PortB Peripheral Ready -> Peripheral is ready for access? */

    /*  Paso 3: Habilitar la función alterna del GPIO (GPIOAFSEL) */
    GPIO_PORTB_AHB_AFSEL_R |= (GPIO_PIN_3 | GPIO_PIN_2);                            /*  PortB[3:2] => AFSEL: Alternate Function Select -> Alternate hardware function */

    /*  Paso 4: Configurar el GPIO utilizado para la señal SDA como Open Drain (GPIOODR) */
    GPIO_PORTB_AHB_ODR_R |= GPIO_PIN_3;                                             /*  PortB[3] => ODE: Output Pad Open Drain Enable -> Enabled */

    /*  Paso 5: Seleccionar la función alterna de hardware (GPIOPCTL) */
    uint32_t reg = GPIO_PORTB_AHB_PCTL_R;
    reg = ((reg & ~0x0000F000) | (2 << 12));                                        /*  PortB[3] => PMC3: Port Mux Control 3 -> I2C0_SDA */
    reg = ((reg & ~0x00000F00) | (2 << 8));                                         /*  PortB[2] => PMC2: Port Mux Control 2 -> I2C0_SCL */
    GPIO_PORTB_AHB_PCTL_R = reg;

    /*  Habilitar las funciones digitales del GPIO (GPIODEN) */
    GPIO_PORTB_AHB_DEN_R |= (GPIO_PIN_3 | GPIO_PIN_2);                              /*  PortB[3:2] => DEN: Digital Enable -> Enabled */

    /*  Paso 6: Configurar el módulo I2C como maestro (I2CMCR) */
    I2C0_MCR_R |= I2C_MCR_MFE;                                                      /*  I2C0 => MFE: I2C Master Function Enable -> Master mode is enabled */

    /*  Paso 7: Configurar la velocidad del reloj deseada para la señal SCL (I2CMTPR) */
    I2C0_MTPR_R = (I2C0_MTPR_R & ~I2C_MTPR_TPR_M) | (7 << I2C_MTPR_TPR_S);          /*  I2C0 => TPR: Timer Period -> 100kbps */

}


int I2C0_MasterBUSY() {

    I2C0_RawInterrupt_wait();                                                       /*  I2C0 => RIS: Master Raw Interrupt Status -> A master interrupt is pending */
    I2C0_ClearFlags();                                                              /*  I2C0 => IC: Master Interrupt Clear -> RIS bit (I2CMRIS) and MIS bit (I2CMMIS) cleared */

    if (I2C0_ErrorFlag) {                                                           /*  I2C0 => ERROR: Error -> An error occurred on the last operation */
        error = 1;
    }

    return error;

}


void I2C0_Transmit(uint8_t SlaveAddress, uint8_t StartPointer, uint8_t Data[], int index) {

    I2C0_BUSY_wait();                                                               /*  I2C0 => BUSY: I2C Busy -> The controller is busy */

    I2C0_MSA_R = (SlaveAddress << 1) & ~I2C_MSA_RS;                                 /*  I2C0 => SA: I2C Slave Address, R/S: Receive/Send -> Transmit */
    I2C0_MDR_R = StartPointer;                                                      /*  I2C0 => DATA: Data transferred during a transaction */
    I2C0_MCS_R = (I2C_MCS_START | I2C_MCS_RUN);                                     /*  I2C0 => START condition followed by TRANSMIT (master goes to the Master Transmit state) */
    I2C0_MasterBUSY();                                                              /*  I2C0 => Esperar a que termine la última operación */

    int i = 0;
    for (i = 0; i < index - 1; i++) {
        I2C0_MDR_R = Data[i];                                                       /*  I2C0 => DATA: Data transferred during a transaction */
        I2C0_MCS_R = I2C_MCS_RUN;                                                   /*  I2C0 => TRANSMIT operation (master remains in Master Transmit state) */
        I2C0_MasterBUSY();                                                          /*  I2C0 => Esperar a que termine la última operación */
    }

    I2C0_MDR_R = Data[index - 1];                                                   /*  I2C0 => DATA: Data transferred during a transaction */
    I2C0_MCS_R = (I2C_MCS_STOP | I2C_MCS_RUN);                                      /*  I2C0 => TRANSMIT followed by STOP condition (master goes to idle state) */
    I2C0_MasterBUSY();                                                              /*  I2C0 => Esperar a que termine la última operación */

}


void I2C0_Receive(uint8_t SlaveAddress, uint8_t StartPointer, uint8_t RawData[], int index){

    I2C0_BUSY_wait();                                                               /*  I2C0 => BUSY: I2C Busy -> The controller is busy */

    // Master Single TRANSMIT
    I2C0_MSA_R = (SlaveAddress << 1) & ~I2C_MSA_RS;                                 /*  I2C0 => SA: I2C Slave Address, R/S: Receive/Send -> Transmit */
    I2C0_MDR_R = StartPointer;                                                      /*  I2C0 => DATA: Data transferred during a transaction */
    I2C0_MCS_R = (I2C_MCS_START | I2C_MCS_RUN);                                     /*  I2C0 => START condition followed by TRANSMIT (master goes to the Master Transmit state) */
    I2C0_MasterBUSY();                                                              /*  I2C0 => Esperar a que termine la última operación */

    // Master RECEIVE of Multiple Data Bytes
    I2C0_MSA_R = (SlaveAddress << 1) | I2C_MSA_RS;                                  /*  I2C0 => SA: I2C Slave Address, R/S: Receive/Send -> Receive */
    I2C0_MCS_R = (I2C_MCS_ACK | I2C_MCS_START | I2C_MCS_RUN);                       /*  I2C_0 => Repeated START condition followed by RECEIVE (master goes to Master Receive state) */
    I2C0_MasterBUSY();                                                              /*  I2C0 => Esperar a que termine la última operación */

    RawData[0] = I2C0_MDR_R;                                                        /*  I2C0 => DATA: Data transferred during a transaction */

    int i = 0;
    for (i = 0; i < index - 2; i++) {
        I2C0_MCS_R = (I2C_MCS_ACK | I2C_MCS_RUN);                                   /*  I2C_0 => RECEIVE operation (master remains in Master Receive state) */
        I2C0_MasterBUSY();                                                          /*  I2C0 => Esperar a que termine la última operación */
        RawData[i + 1] = I2C0_MDR_R;                                                /*  I2C0 => DATA: Data transferred during a transaction */
    }

    I2C0_MCS_R = (I2C_MCS_STOP | I2C_MCS_RUN);                                      /*  I2C_0 => RECEIVE followed by STOP condition (master goes to idle state) */
    I2C0_MasterBUSY();                                                              /*  I2C0 => Esperar a que termine la última operación */
    RawData[index - 1] = I2C0_MDR_R;                                                /*  I2C0 => DATA: Data transferred during a transaction */

}
