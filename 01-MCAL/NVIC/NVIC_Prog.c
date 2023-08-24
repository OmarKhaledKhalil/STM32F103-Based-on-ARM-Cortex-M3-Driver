/*************************************************************************************************/
/* Author : Omar Khaled                                                                          */
/* Version : V01                                                                                 */
/* Data   : 30-6-2023                                                                            */
/*************************************************************************************************/

#include "StdTypes.h"
#include "Utils.h"

#inlcude "NVIC_Interface.h"
#inlcude "NVIC_Private.h"
#inlcude "NVIC_Cfg.h"





void MNVIC_voidEnableInterrupt( u8 Copy_u8IntNumber )
{
	
	if      ( Copy_u8IntNumber<=31 )
	
	{
		
		NVIC_ISER0  =  (1 << Copy_u8IntNumber ) ;
		
	}
	
	else if ( Copy_u8IntNumber<=59 )
	{
		
		Copy_u8IntNumber = Copy_u8IntNumber - 32;
	
		NVIC_ISER1  =  (1 << Copy_u8IntNumber ) ;
		
	}
	
	else
	{
		/* Return Error */
	}
	
	
}


void MNVIC_voidDisableInterrupt( u8 Copy_u8IntNumber )
{
	
	if      ( Copy_u8IntNumber<=31 )
	
	{
		
		NVIC_ICER0  =  (1 << Copy_u8IntNumber ) ;
		
	}
	
	else if ( Copy_u8IntNumber<=59 )
	{
		
		Copy_u8IntNumber = Copy_u8IntNumber - 32;
	
		NVIC_ICER1  =  (1 << Copy_u8IntNumber ) ;
		
	}
	
	else
	{
		/* Return Error */
	}
	
}


void MNVIC_voidSetPendingFlag  ( u8 Copy_u8IntNumber )
{
	
	if      ( Copy_u8IntNumber<=31 )
	
	{
		
		NVIC_ISPR0  =  (1 << Copy_u8IntNumber ) ;
		
	}
	
	else if ( Copy_u8IntNumber<=59 )
	{
		
		Copy_u8IntNumber = Copy_u8IntNumber - 32;
	
		NVIC_ISPR1  =  (1 << Copy_u8IntNumber ) ;
		
	}
	
	else
	{
		/* Return Error */
	}
	
}

void MNVIC_voidClearPendingFlag ( u8 Copy_u8IntNumber )
{
	
	if      ( Copy_u8IntNumber<=31 )
	
	{
		
		NVIC_ICPR0  =  (1 << Copy_u8IntNumber ) ;
		
	}
	
	else if ( Copy_u8IntNumber<=59 )
	{
		
		Copy_u8IntNumber = Copy_u8IntNumber - 32;
	
		NVIC_ICPR1  =  (1 << Copy_u8IntNumber ) ;
		
	}
	
	else
	{
		/* Return Error */
	}
	
}


u8   MNVIC_u8ReadActiveFlag     ( u8 Copy_u8IntNumber )
{
	u8 Local_Result = 0;
	
	if      ( Copy_u8IntNumber<=31 )
	
	{
		
		Local_Result = READ_BIT( IABR0 , Copy_u8IntNumber );
		
	}
	
	else if ( Copy_u8IntNumber<=59 )
	{
		
		Copy_u8IntNumber   =    Copy_u8IntNumber   -   32  ;
	
		Local_Result = READ_BIT( IABR1 , Copy_u8IntNumber );
		
	}
	
	else
	{
		/* Return Error */
	}
	
        return Local_Result ;
}
