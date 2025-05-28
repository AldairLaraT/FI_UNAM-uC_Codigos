/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       27 de mayo de 2025
 * 
 * Tema 09:     Periféricos
 * Código 28:   I2C
 * Descripción: Configuración y uso del I2C para comunicarse con un RTC DS1307.
 *              Periféricos utilizados:
 *              - I2C0 => PB3 -> SDA | PB2 -> SCL.
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */
#include "GPIO.h"                                                                   /*  Archivo de cabecera del GPIO */
#include "I2C.h"                                                                    /*  Archivo de cabecera del I2C */
#include "SYSCTL.h"                                                                 /*  Archivo de cabecera del SYSCTL */


/*********************************************************************************
 * Variables globales
 */

int error = 0;
int Seconds, Minutes, Hours, Day, Date, Month, Year = 0;                            /*  DS1307 => RTC data */


/*********************************************************************************
 * Función principal
 */

int main(void) {

    I2C0_Init();                                                                    /*  Inicialización del I2C0 */

    uint8_t DS1307_Address = 0x68;                                                  /*  DS1307 => Slave Address */
    uint8_t Seconds_Reg = 0x00;                                                     /*  DS1307 => Seconds register pointer */
    uint8_t DS1307_StartDate[7] = {0x00, 0x00, 0x18, 0x03, 0x28, 0x05, 0x25};       /*  DS1307 Start Date (Seconds, Minutes, Hours, Day, Date, Month, Year) */
    // uint8_t DS1307_StartDate[7] = {0x40, 0x59, 0x23, 0x07, 0x31, 0x12, 0x24};       /*  DS1307 Start Date - New Year :D (Seconds, Minutes, Hours, Day, Date, Month, Year) */
    int index = sizeof(DS1307_StartDate) / sizeof(DS1307_StartDate[0]);
    I2C0_Transmit(DS1307_Address, Seconds_Reg, DS1307_StartDate, index);            /*  I2C0 => Transmisión de datos */

    uint8_t DS1307_RawData[7];

    do {

        I2C0_Receive(DS1307_Address, Seconds_Reg, DS1307_RawData, index);           /*  I2C0 => Recepción de datos */

        /*  Conversión del raw data del RTC DS1307 a decimal */
        Seconds = (((DS1307_RawData[0] & 0x70) >> 4)*10) + (DS1307_RawData[0] & 0x0F);
        Minutes = (((DS1307_RawData[1] & 0x70) >> 4)*10) + (DS1307_RawData[1] & 0x0F);
        Hours   = (((DS1307_RawData[2] & 0x30) >> 4)*10) + (DS1307_RawData[2] & 0x0F);
        Day     = DS1307_RawData[3];
        Date    = (((DS1307_RawData[4] & 0x30) >> 4)*10) + (DS1307_RawData[4] & 0x0F);
        Month   = (((DS1307_RawData[5] & 0x10) >> 4)*10) + (DS1307_RawData[5] & 0x0F);
        Year    = (((DS1307_RawData[6] & 0xF0) >> 4)*10) + (DS1307_RawData[6] & 0x0F);

    } while (error != 1);


    while(1) {}
}
