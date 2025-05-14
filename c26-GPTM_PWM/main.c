/**
 * School:      Universidad Nacional Autónoma de México | Facultad de Ingeniería
 * Department:  Ingeniería Electrónica
 * Subject:     Microprocesadores y Microcontroladores
 * Code:        Código 22 | Temporizadores de propósito general (modo PWM)
 * Description: Configuración del temporizador GPTM_2 en modo PWM con ciclo de trabajo
 *              ajustable con los botones SW1 y SW2 de la tarjeta de desarrollo, empleando
 *              interrupciones en GPIO.
 * Author:      M. I. Christo Aldair Lara Tenorio
 * Date:        24 de octubre de 2024
 */

/**
 * Archivos de cabecera
 */
#include <stdint.h>                                                                 /*  Definición de los tamaños de tipo entero */

/**
 * Definición de los apuntadores para acceso a memoria
 */
	/*	Nested Vectored Interrupt Controller Registers (NVIC) */				    /*	pp146	Register map */
#define NVIC_ST_CTRL_R 		    (*((volatile uint32_t *)0xE000E010))				/*	pp150	SysTick Control and Status Register */
#define NVIC_ST_RELOAD_R        (*((volatile uint32_t *)0xE000E014))    			/*	pp152	SysTick Reload Value Register */
#define NVIC_ST_CURRENT_R       (*((volatile uint32_t *)0xE000E018))    			/*	pp153	SysTick Current Value Register */
#define NVIC_EN1_R              (*((volatile uint32_t *)0xE000E104))				/*	pp154	Interrupt 32-63 Set Enable */
#define NVIC_PRI12_R            (*((volatile uint32_t *)0xE000E430))                /*  pp159   Interrupt 48-51 Priority */

    /*  System Control Registers (SYSCTL) */                                        /*  pp247   REGISTER MAP */
#define SYSCTL_RCGCTIMER_R      (*((volatile uint32_t *)0x400FE604))                /*  pp380   16/32-Bit GPTM Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))                /*  pp382   GPIO Run Mode Clock Gating Control */
#define SYSCTL_PRTIMER_R        (*((volatile uint32_t *)0x400FEA04))                /*  pp497   16/32-Bit GPTM Peripheral Ready */
#define SYSCTL_PRGPIO_R         (*((volatile uint32_t *)0x400FEA08))                /*  pp499   GPIO Peripheral Ready */

    /*  Timer registers (TIMER2) */                                                 /*  pp974   REGISTER MAP */
#define TIMER2_CFG_R            (*((volatile uint32_t *)0x40032000))                /*  pp976   GPTM Configuration */
#define TIMER2_TAMR_R           (*((volatile uint32_t *)0x40032004))                /*  pp977   GPTM Timer A Mode */
#define TIMER2_CTL_R            (*((volatile uint32_t *)0x4003200C))                /*  pp986   GPTM Control */
#define TIMER2_TAILR_R          (*((volatile uint32_t *)0x40032028))                /*  pp1004  GPTM Timer A Interval Load */
#define TIMER2_TAMATCHR_R       (*((volatile uint32_t *)0x40032030))                /*  pp1006  GPTM Timer A Match */
#define TIMER2_TAPR_R           (*((volatile uint32_t *)0x40032038))                /*  pp1008  GPTM Timer A Prescale */

	/*	GPIO Registers (PortJ) */													/*	pp757	Register map */
#define GPIO_PORTJ_AHB_DATA_R   (*((volatile uint32_t *)(0x40060000 | 0x03 << 2)))	/*	pp759	GPIO Data */
#define GPIO_PORTJ_AHB_DIR_R    (*((volatile uint32_t *)0x40060400))				/*	pp760	GPIO Direction */
#define GPIO_PORTJ_AHB_IS_R		(*((volatile uint32_t *)0x40060404))				/*	pp761	GPIO Interrupt Sense */
#define GPIO_PORTJ_AHB_IBE_R	(*((volatile uint32_t *)0x40060408))				/*	pp762	GPIO Interrupt Both Edges */
#define GPIO_PORTJ_AHB_IEV_R	(*((volatile uint32_t *)0x4006040C))				/*	pp763	GPIO Interrupt Event */
#define GPIO_PORTJ_AHB_IM_R		(*((volatile uint32_t *)0x40060410))				/*	pp764	GPIO Interrupt Mask */
#define GPIO_PORTJ_AHB_ICR_R	(*((volatile uint32_t *)0x4006041C))				/*	pp769	GPIO Interrupt Clear */
#define GPIO_PORTJ_AHB_PUR_R    (*((volatile uint32_t *)0x40060510))				/*	pp776	GPIO Pull-Up Select */
#define GPIO_PORTJ_AHB_DEN_R    (*((volatile uint32_t *)0x4006051C))				/*	pp781	GPIO Digital Enable */

    /*  GPIO Registers (PortM)*/                                                    /*  pp757   REGISTER MAP  */
#define GPIO_PORTM_DIR_R        (*((volatile uint32_t *)0x40063400))                /*  pp760   GPIO Direction */
#define GPIO_PORTM_AFSEL_R      (*((volatile uint32_t *)0x40063420))                /*  pp770   GPIO Alternate Function Select */
#define GPIO_PORTM_DEN_R        (*((volatile uint32_t *)0x4006351C))                /*  pp781   GPIO Digital Enable */
#define GPIO_PORTM_PCTL_R       (*((volatile uint32_t *)0x4006352C))                /*  pp787   GPIO Port Control */

/**
 * Definiciones
 */
#define NVIC_ST_CTRL_COUNT  	0x00010000										    /*	Bandera COUNT del registro STCTRL del SysTick */
#define NVIC_ST_CTRL_ENABLE     0x00000001  										/*	SysTick => STCTRL register -> Enable */
#define SYSCTL_RCGCTIMER_R2     0x00000004                                          /*  TIMER_2 => Run Mode Clock */
#define SYSCTL_RCGCGPIO_R8      0x00000100  										/*	GPIO PortJ => Run Mode Clock */
#define SYSCTL_RCGCGPIO_R11     0x00000800                                          /*  GPIO PortM => Run Mode Clock */

/**
 * Variables globales
 */
uint8_t SW1 = 0x02;																	/*	GPIO PortJ[0] */
uint8_t SW2 = 0x01;																	/*	GPIO PortJ[1] */
uint32_t bounce = 100000;															/*	Retardo de rebote (f = 4 Mhz) */
uint32_t freq = 16000;
uint32_t DutyCycle = 8000;

/**
 * Funciones
 */
void GPIO_PortJ_Init(void){
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R8;				    					/*  Habilitación del reloj del PortJ */
	while ((SYSCTL_PRGPIO_R & SYSCTL_RCGCGPIO_R8) == 0) {};							/*	Espera a que se estabilice el reloj del PortJ */

	GPIO_PORTJ_AHB_DIR_R &= ~0x03;													/*	PortJ[1:0] => Input */
	GPIO_PORTJ_AHB_PUR_R |= 0x03;													/*	PortJ[1:0] => Pull-Up resistors -> Enabled */
	GPIO_PORTJ_AHB_DEN_R |= 0x03;													/*	PortJ[1:0] => Digital functions -> Enabled */
	GPIO_PORTJ_AHB_IS_R &= ~0x03;													/*	PortJ[1:0] => Interrupt sense -> Edge-sensitive */
	GPIO_PORTJ_AHB_IBE_R &= ~0x03;													/*	PortJ[1:0] => Interrupt both edges -> Controlled by the GPIO_IEV register */
	GPIO_PORTJ_AHB_IEV_R &= ~0x03;													/*	PortJ[1:0] => Interrupt event -> Falling edge triggers an interrupt */
	GPIO_PORTJ_AHB_ICR_R = 0x03;                                                    /*  PortJ[1,0] => Interrupt is Cleared */
	GPIO_PORTJ_AHB_IM_R |= 0x03;													/*	PortJ[1:0] => Interrupt mask -> Unmasked */
	NVIC_PRI12_R = (NVIC_PRI12_R & 0x00FFFFFF) | (0b000 << 29);                     /*  PortJ => Interrupt priority -> 0 */
	NVIC_EN1_R = 1 << (51-32);														/*	Interrupt 51 (PortJ) => Enabled */
}

void GPTM2A_Init(void){
	// TIMER - 0. Habilitar el reloj del módulo GPTM (RCGCTIMER).
	//			  Esperar a que se estabilice el reloj (PRTIMER).
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R2;                                      /*  Habilitación del GPTM_2 */
    while ((SYSCTL_PRTIMER_R & SYSCTL_RCGCTIMER_R2) == 0) {};                       /*  Espera a que se estabilice el reloj del GPTM_2 */

    // CONFIGURACIÓN DEL GPIO COMO TC2CCP0 (PM0)
    // GPIO - 1. Habilitar el reloj del módulo GPIO en el registro RCGCGPIO y esperar a que se estabilice el reloj 
    //           en el registro PRGPIO.
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R11;                                       /*  Habilitación del reloj del PortM */
    while ((SYSCTL_PRGPIO_R & SYSCTL_RCGCGPIO_R11) == 0) {};                        /*  Espera a que se estabilice el reloj del PortM */

    // GPIO - 2. Configurar la dirección del pin GPIO como entrada en el registro GPIODIR.
    GPIO_PORTM_DIR_R |= 0x01;                                                       /*  PortM[0] => Output */

    // GPIO - 3. Habilitar la función alterna de hardware del pin GPIO en el registro GPIOAFSEL y seleccionar la 
    //           función alterna requerida en el registro GPIOPCTL.
    GPIO_PORTM_AFSEL_R |= 0x01;                                                     /*  PortM[0] => Alternate hardware function -> Enable */
    GPIO_PORTM_PCTL_R = (GPIO_PORTM_PCTL_R & ~0x0000000F) | (3 << 0);               /*  PortM[0] => GPIO controlled by the function T2CCP0 */

    // GPIO - 9. Habilitar las funciones digitales del pin GPIO en el registro GPIODEN.
    GPIO_PORTM_DEN_R |= 0x01;                                                       /*  PortM[0] => Digital functions -> Enabled */

	// TIMER - 1. Asegurarse de que el TIMER está deshabilitado (GPTMCTL).
        // TnEN
    TIMER2_CTL_R &= ~0x01;                                                          /*  TIMER_2 => Timer A -> TAEN -> Timer disabled */

	// TIMER - 2. Configurar el TIMER para que funcione de forma individual (16 bits) (GPTMCFG).
    TIMER2_CFG_R = 0x4;                                                             /*  TIMER_2 => GPTMCFG -> 16-bit timer configuration */

    // TIMER - 3. Configurar los siguientes campos (GPTMTnMR).
		// TnAMS -> Habilitar el modo PWM
        // TnCMR -> Configurar en modo captura de eventos
        // TnMR  -> Configurar en modo periódico
    TIMER2_TAMR_R = (TIMER2_TAMR_R & ~0x08) | (0x1 << 3);                           /*  TIMER_2 => Timer A -> TAAMS -> PWM mode enabled */
    TIMER2_TAMR_R = (TIMER2_TAMR_R & ~0x04) | (0x0 << 2);                           /*  TIMER_2 => Timer A -> TACMR -> Edge-Count mode */
    TIMER2_TAMR_R = (TIMER2_TAMR_R & ~0x03) | (0x2 << 0);                           /*  TIMER_2 => Timer A -> TAMR -> Periodic timer mode */

	// TIMER - 4. Configurar el estado de salida de la señal PWM (GPTMCTL).
        // TnPWML
    TIMER2_CTL_R &= ~0x0040;                                                        /*  TIMER_2 => Timer A -> TAPWML -> PWM Output Level -> Unaffected */

	// TIMER - 5. Si se utilizará preescalador, cargarlo con el valor adecuado [23:16] (GPTMTnPR).
    TIMER2_TAPR_R = ((freq & 0x00FF0000) >> 16);

    // TIMER - 6. Si se requiere interrupción:
		// Configurar la condición de interrupción => TnEVENT (GPTMCTL).
		// Habilitar la interrupción => TnPWMIE (GPTMTnMR).

	// TIMER - 7. Carga el valor de inicio [15:0] (GPTMTnILR).
    TIMER2_TAILR_R = (freq & 0x0000FFFF);

	// TIMER - 8. Cargar el valor de match (GPTMTnMATCHR).
    TIMER2_TAMATCHR_R = (DutyCycle & 0x0000FFFF);

	// TIMER - 9. Habilitar el TIMER => TnEN (GPTMCTL).
    TIMER2_CTL_R |= 0x01;                                                           /*  TIMER_2 => Timer A -> TAEN -> Timer enabled */
}

void SysTick_OneShot(uint32_t delay){
	NVIC_ST_RELOAD_R = (delay & 0x00FFFFFF) - 17;									/*	Programar el valor de cuenta del SysTick (4,000,000) */
	NVIC_ST_CURRENT_R = 0;														    /*	Limpiar el registro STCURRENT al escribirle un valor cualquiera */
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE;											/*	Habilitar el SysTick con fuente de reloj de 4MHz */
	NVIC_ST_RELOAD_R = 0;													    	/*	Limpiar el registro RELOAD para que el SysTick se apague cuando termine la cuenta */
	while ((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0) {}							/*	Espera a que termine la cuenta del SysTick */
}

/**
 * Funciones de interrupción
 */
void GPIOPortJ_Handler(void){
    SysTick_OneShot(bounce);													    /*	Retardo de rebote con el SysTick */
    if (GPIO_PORTJ_AHB_DATA_R == SW1) {                                             /*	Validación de la habilitación del SW1 */
        if (DutyCycle < 14400) {
            DutyCycle += 1600;
        }
        TIMER2_TAMATCHR_R = (DutyCycle & 0x0000FFFF);                               /*  Carga del valor de match */
	}
	if (GPIO_PORTJ_AHB_DATA_R == SW2) {												/*	Validación de la habilitación del SW2 */
		if (DutyCycle > 1600) {
            DutyCycle -= 1600;
        }
        TIMER2_TAMATCHR_R = (DutyCycle & 0x0000FFFF);                               /*  Carga del valor de match */
	}
    GPIO_PORTJ_AHB_ICR_R = 0x03;                                                    /*  PortJ[1,0] => Interrupt is Cleared */
}

/**
 * Función principal
 */
int main(void){

    GPIO_PortJ_Init();                                                              /*  Inicialización del GPIO PortJ */
    GPTM2A_Init();                                                                  /*  Inicialización del GPTM_2 Timer A */

    while(1){}
}
