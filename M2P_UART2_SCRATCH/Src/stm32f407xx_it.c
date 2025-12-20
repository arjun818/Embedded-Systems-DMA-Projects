/*
 * stm32f407xx_it.c
 *
 *  Created on: Dec 11, 2025
 *      Author: Lenovo
 */
#include "stm32f407xx.h"

uint32_t is_it_HT(void){
	DMA_TypeDef *pDMA1;
	pDMA1 = DMA1;
	return pDMA1->HISR & (1 << 20);
}

uint32_t is_it_FT(void){
	DMA_TypeDef *pDMA1;
	pDMA1 = DMA1;
	return pDMA1->HISR & (1 << 21);
}

uint32_t is_it_TE(void){
	DMA_TypeDef *pDMA1;
	pDMA1 = DMA1;
	return pDMA1->HISR & (1 << 19);
}

uint32_t is_it_FE(void){
	DMA_TypeDef *pDMA1;
	pDMA1 = DMA1;
	return pDMA1->HISR & (1 << 16);
}
uint32_t is_it_DME(void){
	DMA_TypeDef *pDMA1;
	pDMA1 = DMA1;
	return pDMA1->HISR & (1 << 18);
}
extern void HT_Complete_Callback();
extern void FT_Complete_Callback();
extern void TE_Error_Callback();
extern void FE_Error_Callback();
extern void DME_Error_Callback();

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

//Implementation of IRQ handler for DMA1 stream6 global interrupt
void DMA1_Stream6_IRQHandler(void){
	//Half-Transfer
	if(is_it_HT()){
		DMA1->HIFCR |= (1 << 20);
		HT_Complete_Callback();
	}else if(is_it_FT()){
		DMA1->HIFCR |= (1 << 21);
		FT_Complete_Callback();
	}else if(is_it_TE()){
		DMA1->HIFCR |= (1 << 19);
		TE_Error_Callback();
	}else if(is_it_FE()){
		DMA1->HIFCR |= (1 << 16);
		FE_Error_Callback();
	}else if(is_it_DME()){
		DMA1->HIFCR |= (1 << 18);
		DME_Error_Callback();
	}else{
		;
	}
}
