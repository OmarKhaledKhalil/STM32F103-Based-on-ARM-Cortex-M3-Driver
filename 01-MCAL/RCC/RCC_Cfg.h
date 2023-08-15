/*************************************************************************************************/
/* Author : Omar Khaled                                                                          */
/* Version : V01                                                                                 */
/* Data   : 20-6-2023                                                                            */
/*************************************************************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H


/* Options For Clock Type:
                 
                 RCC_HSE_CRYSTAL
                 RCC_HSE_RC
				         RCC_HSI
			           RCC_PLL
				                         */

#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL





/***************************PLL Section********************************/	

/*NOTE :- Select Values only if you have PLL as an input clock source.*/	


/* options for PLL Input Type :   
                
                RCC_PLL_IN_HSI_DIV_2
                RCC_PLL_IN_HSE_DIV_2
				        RCC_PLL_IN_HSE      
				                     */	

#if RCC_CLOCK_TYPE ==RCC_PLL

#define  RCC_PLL_INPUT  RCC_PLL_IN_HSE_DIV_2

#endif


/*Option :-  Multiplication Factor of PLL from 2 up to 16   */

#if RCC_CLOCK_TYPE ==RCC_PLL

#define  RCC_PLL_MUL_VAL	 4

#endif									 
									 
/***************************PLL Section********************************/	

#endif
