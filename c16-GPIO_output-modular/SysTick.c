/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       16 de abril de 2025
 * 
 * Código:      Archivo fuente del SysTick
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "SysTick.h"                                                                /*  Macros para el uso de SysTick */


/*********************************************************************************
 * Funciones
 */

void SysTick_Init(uint32_t SysTick_Reload) {

    /*  Paso 1: Cargar el valor de cuenta del SysTick (STRELOAD) */
    NVIC_ST_RELOAD_R = (SysTick_Reload & NVIC_ST_RELOAD_M);

    /*  Paso 2: Limpiar el valor actual del SysTick (STCURRENT) al escribir cualquier valor */
    NVIC_ST_CURRENT_R = 0;

    /*  Paso 3: Configurar el SysTick para la operación requerida (STCTRL) */
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;                                          /*  Fuente de reloj de 4 MHz, Interrupción deshabilitada, Habilitación del SysTick */

}
