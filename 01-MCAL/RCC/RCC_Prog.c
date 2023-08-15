/*************************************************************************************************/
/* Author : Omar Khaled                                                                          */
/* Version : V01                                                                                 */
/* Data   : 20-6-2023                                                                            */
/*************************************************************************************************/

#include "StdTypes.h"
#include "Utils"

#inlcude "RCC_Interface.h"
#inlcude "RCC_Private.h"
#inlcude "RCC_Cfg.h"

void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE   ==  RCC_HSE_CRYSTAL
	     
		 RCC_CR = 0x00010000; /* Enable HSE with no bypass */
		 RCC_CFGR=0x00000001; /* Choose that Clock System is HSE */
	
        #elif RCC_CLOCK_TYPE ==  RCC_HSE_RC
	
	         RCC_CR = 0x00050000; /* Enable HSE with bypass ( RC Shall Clock Shall be Conncected) */
		 RCC_CFGR=0x00000001 /* Choose that Clock System is HSE */

			 
	#elif RCC_CLOCK_TYPE ==  RCC_HSI
	
	         RCC_CR = 0x00000081; /* Enable HSI +  Triming=0 */ 
	         RCC_CFGR=0x00000000;

	
         #elif RCC_CLOCK_TYPE ==  RCC_PLL
	     
                 #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		 
	         #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		 
		 #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		 
		 #endif
	 #else 
		#error ("You Choosed The Wrong Clock Type")
	
	 #endif
}

void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
	if (Copy_u8PerId<=31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR   ,Copy_u8PerId); break;
			case RCC_APB1 : SET_BIT(RCC_AHPB1ENR ,Copy_u8PerId); break;
			case RCC_APB2 : SET_BIT(RCC_AHPB2ENR ,Copy_u8PerId); break;
		}
	}
	else
	{
		/* return Error; */
	}
	
}

void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
	if (Copy_u8PerId<=31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR   ,Copy_u8PerId); break;
			case RCC_APB1 : CLR_BIT(RCC_AHPB1ENR ,Copy_u8PerId); break;
			case RCC_APB2 : CLR_BIT(RCC_AHPB2ENR ,Copy_u8PerId); break;
		}
	}
	else
	{
		/* return Error; */
	}
	
}

