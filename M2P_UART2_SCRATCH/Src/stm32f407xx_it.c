/*
 * stm32f407xx_it.c
 *
 *  Created on: Dec 11, 2025
 *      Author: Lenovo
 */
#include "stm32f407xx.h"

void clear_exti_pending_bit(void){
	EXTI_TypeDef *pEXTI;
	pEXTI = EXTI;

	if(pEXTI->PR & (1 << 0)){
		pEXTI->PR |= (1 << 0);
	}

}

void EXTI0_IRQHandler(void){
	clear_exti_pending_bit();
}

