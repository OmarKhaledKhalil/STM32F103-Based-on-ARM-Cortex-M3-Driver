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

