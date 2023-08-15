/*************************************************************************************************/
/* Author : Omar Khaled                                                                          */
/* Version : V01                                                                                 */
/* Data   : 20-6-2023                                                                            */
/*************************************************************************************************/


#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

typedef enum 
{
	GPIOA   =   0,
	TIM1    =   0,
	TIM2    =   0,
	TIM3    =   1,
	GPIOB   =   1,
	GPIOC   =   2,
	TIM4    =   2,
	GPIOD   =   3,
	TIM5    =   3,
	GPIOE   =   4,
	USART1  =   4,
	USART6  =   5,
	GPIOH   =   7,
	ADC1    =   8,
	SDIO    =  11,
	WWDG    =  11,
	CRC     =  12,
	SPI1    =  12,
	SPI4    =  13,
	SPI2    =  14,
	SYSCFG  =  14,
	SPI3    =  15,
	TIM9    =  16,
	TIM10   =  17,
	USART2  =  17,
	TIM11   =  18,
	I2C1    =  21,
	DMA1    =  21,
	DMA2    =  22,
	I2C2    =  22,
	I2C3    =  23,
	PWR     =  28
	
	
}BusId_type;

typedef enum 
{
	RCC_ِAHB  =   0,
	RCC_APB  =   1,
	RCC_APB2 =   2
	
}PerId_type;

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);

#endif
