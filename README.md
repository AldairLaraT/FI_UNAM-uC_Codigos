# Curso de Microprocesadores y Microcontroladores
Repositorio de apoyo para el curso de Microprocesadores y Microcontroladores, impartido en la Facultad de Ingeniería, UNAM.

# Autor
**Nombre:** M. I. Christo Aldair Lara Tenorio

**Correo:** aldairlara.fi@gmail.com

**Cubículo:** Laboratorio de Instrumentación Electrónica de Sistemas Espaciales (LIESE), 2do piso del Edificio P, Conjunto Sur de la Facultad de Ingeniería, UNAM.

# Contenido
Este repositorio contiene códigos de ejemplo y ejercicios relacionados con la asignatura, con el objetivo de apoyar el aprendizaje de los alumnos.

# Requisitos
**IDE:** [Code Composer Studio (CCS) de Texas Instruments](https://www.ti.com/tool/download/CCSTUDIO/12.8.1).

**Versión:** 12.8.1 (Sep 30, 2024).

**Tarjeta de desarrollo:** [EK-TM4C1294XL Evaluation board](https://www.ti.com/tool/EK-TM4C1294XL).

# Estructura del repositorio
| Número | Tema                                                    | Lenguaje | Descripción                                          |
|:------:|:--------------------------------------------------------|:--------:|:-----------------------------------------------------|
| c01    | T05 - Programación estructurada en lenguaje ensamblador | `asm`    | Saltos incondicionales                               |
| c02    | T05 - Programación estructurada en lenguaje ensamblador | `asm`    | Saltos condicionales                                 |
| c03    | T05 - Programación estructurada en lenguaje ensamblador | `asm`    | Estructura de control: IF-ELSE                       |
| c04    | T05 - Programación estructurada en lenguaje ensamblador | `asm`    | Estructura de control: SWITCH-CASE                   |
| c05    | T05 - Programación estructurada en lenguaje ensamblador | `asm`    | Estructura de control: FOR                           |
| c06    | T05 - Programación estructurada en lenguaje ensamblador | `asm`    | Estructura de control: WHILE                         |
| c07    | T05 - Programación estructurada en lenguaje ensamblador | `asm`    | Bloque IT                                            |
| c08    | T05 - Programación estructurada en lenguaje ensamblador | `asm`    | Manejo del Stack                                     |
| c09    | T05 - Programación estructurada en lenguaje ensamblador | `asm`    | Subrutinas                                           |
| c10    | T06 - Puertos de entrada/salida                         | `asm`    | GPIO: Output                                         |
| c11    | T06 - Puertos de entrada/salida                         | `asm`    | GPIO: Input                                          |
| c12    | T06 - Puertos de entrada/salida                         | `asm`    | Temporizador SysTick                                 |
| c13    | T08 - Lenguaje C                                        | `c`      | GPIO: Output                                         |
| c14    | T08 - Lenguaje C                                        | `c`      | GPIO: Input                                          |
| c15    | T07 - Interrupciones y resets                           | `c`      | GPIO con interrupción                                |
| c16    | T09 - Periféricos                                       | `c`      | GPIO: Output (modular)                               |
| c17    | T09 - Periféricos                                       | `c`      | GPIO: Input (modular)                                |
| c18    | T09 - Periféricos                                       | `c`      | GPIO con interrupción (modular)                      |
| c19    | T09 - Periféricos                                       | `c`      | ADC: Potenciómetro                                   |
| c20    | T09 - Periféricos                                       | `c`      | ADC: Sensor de temperatura del TIVA                  |
| c21    | T09 - Periféricos                                       | `c`      | ADC: Múltiples canales con interrupción              |
| c22    | T09 - Periféricos                                       | `c`      | GPTM: Modo One-Shot                                  |
| c23    | T09 - Periféricos                                       | `c`      | GPTM: Modo Periodic                                  |
| c24    | T09 - Periféricos                                       | `c`      | GPTM: Modo Edge-Count                                |
| c25    | T09 - Periféricos                                       | `c`      | GPTM: Modo Edge-Time                                 |
| c26    | T09 - Periféricos                                       | `c`      | GPTM: Modo PWM                                       |
| c25    | T09 - Periféricos                                       | `c`      | UART                                                 |
<!-- | c28    | T09 - Periféricos                                       | `c`      | I2C: Reloj en tiempo real DS1307                     | -->
<!-- | c29    | T09 - Periféricos                                       | `c`      | I2C: Reloj en tiempo real DS1307 con interrupciones  | -->
<!-- | c30    | T09 - Periféricos                                       | `c`      | SSI: Potenciómetro digital MCP41010                  | -->

# Uso del repositorio
1. Descargar y descomprimir / clonar el repositorio.
```
git clone https://github.com/AldairLaraT/FI_UNAM-uC.git
```
2. Abrir *Code Composer Studio* y crear un nuevo *Workspace*.
3. Click en: `File` >> `Import` >> `Code Composer Studio` >> `CCS Projects`.
4. Seleccionar la carpeta *FI_UNAM-uC* y hacer click en `Select All`.
5. Click en `Finish`.