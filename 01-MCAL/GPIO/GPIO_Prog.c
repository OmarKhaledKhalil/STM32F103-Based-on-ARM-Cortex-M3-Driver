/*************************************************************************************************/
/* Author : Omar Khaled                                                                          */
/* Version : V01                                                                                 */
/* Data   : 23-6-2023                                                                            */
/*************************************************************************************************/

#include "StdTypes"
#include "Utils"

#inlcude "GPIO_Interface"
#include "GPIO_Private"


void MGPIO_voidSetPinDirection(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode)
{
	switch(copy_u8Port)
	{
		case GPIOA :
		
		            if(copy_u8Pin <=7)
					{
						GPIOA_CRL & =   ~    ( (ob1111) << (copy_u8Pin*4) );
						
						GPIOA_CRL | =   ( (copy_u8Mode) << (copy_u8Pin*4) );
						
					}
					else if(copy_u8Pin <=15)
					{
						copy_u8Pin= copy_u8Pin-8 ;
						
						GPIOA_CRH & =   ~    ( (ob1111) << (copy_u8Pin*4) );
						
						GPIOA_CRH | =   ( (copy_u8Mode) << (copy_u8Pin*4) );
						
					}
					
					break;
					
		case GPIOB :
		
		            if(copy_u8Pin <=7)
					{
						GPIOB_CRL & =   ~    ( (ob1111) << (copy_u8Pin*4) );
						
						GPIOB_CRL | =   ( (copy_u8Mode) << (copy_u8Pin*4) );
						
					}
					else if(copy_u8Pin <=15)
					{
						copy_u8Pin= copy_u8Pin-8 ;
						
						GPIOB_CRH & =   ~    ( (ob1111) << (copy_u8Pin*4) );
						
						GPIOB_CRH | =   ( (copy_u8Mode) << (copy_u8Pin*4) );
						
					}
					
					break;
					
		case GPIOC :
		            
					if(copy_u8Pin <=7)
					{
						GPIOC_CRL & =   ~    ( (ob1111) << (copy_u8Pin*4) );
						
						GPIOC_CRL | =   ( (copy_u8Mode) << (copy_u8Pin*4) );
						
					}
					else if(copy_u8Pin <=15)
					{
						copy_u8Pin= copy_u8Pin-8 ;
						
						GPIOC_CRH & =   ~    ( (ob1111) << (copy_u8Pin*4) );
						
						GPIOC_CRH | =   ( (copy_u8Mode) << (copy_u8Pin*4) );
						
					}
					
					break;
					
		
		default : break;
					
	}
	
}

void MGPIO_voidSetPinValue(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value)
{
	switch(copy_u8Port)
	{
		case GPIOA :
		
		            if( copy_u8Value == GPIO_HIGH )
					{
						
						SET_BIT(GPIOA_ODR,copy_u8Pin);
						
					}
					else if( copy_u8Pin == GPIO_LOW )
					{
						 
						 CLR_BIT(GPIOA_ODR,copy_u8Pin);
						
					}
					
					break;
					
		case GPIOB :
		
		            if( copy_u8Value == GPIO_HIGH )
					{
						
						SET_BIT(GPIOB_ODR,copy_u8Pin);
						
					}
					else if( copy_u8Pin == GPIO_LOW )
					{
						 
						 CLR_BIT(GPIOB_ODR,copy_u8Pin);
						
					}
					
					break;
					
		case GPIOC :
		            
					 if( copy_u8Value == GPIO_HIGH )
					{
						
						SET_BIT(GPIOC_ODR,copy_u8Pin);
						
					}
					else if( copy_u8Pin == GPIO_LOW )
					{
						 
						 CLR_BIT(GPIOC_ODR,copy_u8Pin);
						
					}
					
					break;
					
		
		default : break;
					
	}
}

u8 MGPIO_u8GetPinValue(u8 copy_u8Port , u8 copy_u8Pin)
{
	u8 LOC_u8Result = 0 ;
	
	
	switch(copy_u8Port)
	{
		case GPIOA :
		
		           LOC_u8Result = READ_BIT( GPIOA_IDR , copy_u8Pin );
				   
					break;
					
		case GPIOB :
		
		            LOC_u8Result = READ_BIT( GPIOB_IDR , copy_u8Pin );
					
					break;
		case GPIOC :
		            
					LOC_u8Result = READ_BIT( GPIOC_IDR , copy_u8Pin );
					 
					break;
					
					
					
		default : break;
					
	}
	
	return LOC_u8Result;
}
