/*********************************************************************************
 * Universidad Nacional Autónoma de México (UNAM)
 * Facultad de Ingeniería | Departamento de Electrónica
 * 
 * Asignatura:  Microprocesadores y Microcontroladores
 * Profesor:    M.I. Christo Aldair Lara Tenorio
 * Fecha:       18 de abril de 2025
 * 
 * Código:      Archivo fuente del SysTick
 * 
 * Tarjeta de desarrollo:   EK-TM4C1294XL Evaluation board
 *********************************************************************************/


/*********************************************************************************
 * Archivos de cabecera
 */

#include "SysTick.h"                                                                /*  Archivo de cabecera del SysTick */


/*********************************************************************************
 * Funciones
 */

 void SysTick_Init(uint32_t SysTick_Reload) {

    /*  Paso 1: Cargar el valor de cuenta del SysTick (STRELOAD) */
    NVIC_ST_RELOAD_R = (SysTick_Reload & NVIC_ST_RELOAD_M);                         /*  SysTick => RELOAD: Reload Value */

    /*  Paso 2: Limpiar el valor actual del SysTick (STCURRENT) al escribir cualquier valor */
    NVIC_ST_CURRENT_R = 0;                                                          /*  SysTick => CURRENT: Current Value */

    /*  Paso 3: Configurar el SysTick para la operación requerida (STCTRL) */
    uint32_t reg = NVIC_ST_CTRL_R;
    reg &= ~NVIC_ST_CTRL_CLK_SRC;                                                   /*  SysTick => CLK_SRC: Clock Source -> PIOSC divided by 4 */
    reg &= ~NVIC_ST_CTRL_INTEN;                                                     /*  SysTick => INTEN: Interrupt Enable -> Disabled */
    reg |= NVIC_ST_CTRL_ENABLE;                                                     /*  SysTick => ENABLE: Enable -> Enabled in multi-shot mode */
    NVIC_ST_CTRL_R = reg;

}
