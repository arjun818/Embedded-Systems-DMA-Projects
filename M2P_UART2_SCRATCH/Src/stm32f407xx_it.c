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
	USART_TypeDef *pUART2;
	pUART2 = USART2;
	//Here we will send UART2_TX DMA request to DMA1 controller.
	pUART2->CR3 |= (1 << 7);

	clear_exti_pending_bit();
}
