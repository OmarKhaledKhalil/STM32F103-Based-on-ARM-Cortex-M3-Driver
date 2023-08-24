/*************************************************************************************************/
/* Author : Omar Khaled                                                                          */
/* Version : V01                                                                                 */
/* Data   : 23-6-2023                                                                            */
/*************************************************************************************************/

#include "StdTypes"
#include "Utils.h"

#inlcude "GPIO_Interface"
#include "GPIO_Private"


void MGPIO_voidSetPinDirection(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode)
{
	switch(copy_u8Port)
	{
		case GPIOA :
		
		            if(copy_u8Pin <=7)
					{
						GPIOA_CRL & =   ~    ( (ob1111) << (copy_u8Pin*4) ); // Reset Last Mode
						
						GPIOA_CRL | =   ( (copy_u8Mode) << (copy_u8Pin*4) ); // Set  New   Mode
						
					}
					else if(copy_u8Pin <=15)
					{
						copy_u8Pin= copy_u8Pin-8 ;
						
						GPIOA_CRH & =   ~    ( (ob1111) << (copy_u8Pin*4) ); // Reset Last Mode
						
						GPIOA_CRH | =   ( (copy_u8Mode) << (copy_u8Pin*4) ); // Set  New   Mode
						
					}
					
					break;
					
		case GPIOB :
		
		            if(copy_u8Pin <=7)
					{
						GPIOB_CRL & =   ~    ( (ob1111) << (copy_u8Pin*4) ); // Reset Last Mode
						
						GPIOB_CRL | =   ( (copy_u8Mode) << (copy_u8Pin*4) ); // Set  New   Mode
						
					}
					else if(copy_u8Pin <=15)
					{
						copy_u8Pin= copy_u8Pin-8 ;
						
						GPIOB_CRH & =   ~    ( (ob1111) << (copy_u8Pin*4) ); // Reset Last Mode
						
						GPIOB_CRH | =   ( (copy_u8Mode) << (copy_u8Pin*4) ); // Set  New   Mode
						
					}
					
					break;
					
		case GPIOC :
		            
					if(copy_u8Pin <=7)
					{
						GPIOC_CRL & =   ~    ( (ob1111) << (copy_u8Pin*4) ); // Reset Last Mode
						
						GPIOC_CRL | =   ( (copy_u8Mode) << (copy_u8Pin*4) ); // Set  New   Mode
						
					}
					else if(copy_u8Pin <=15)
					{
						copy_u8Pin= copy_u8Pin-8 ;
						
						GPIOC_CRH & =   ~    ( (ob1111) << (copy_u8Pin*4) ); // Reset Last Mode
						
						GPIOC_CRH | =   ( (copy_u8Mode) << (copy_u8Pin*4) ); // Set  New   Mode
						
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
						
						SET_BIT(GPIOA_BSRR,copy_u8Pin);  //Set Pin OutPut High (3.3v)
						
					}
					else if( copy_u8Pin == GPIO_LOW )
					{
						 
						SET_BIT(GPIOA_BRR ,copy_u8Pin); //Set Pin OutPut Low     (0v)
						
					}
					
					break;
					
		case GPIOB :
		
		            if( copy_u8Value == GPIO_HIGH )
					{
						
						SET_BIT(GPIOB_BSRR,copy_u8Pin); //Set Pin OutPut High (3.3v)
						
					}
					else if( copy_u8Pin == GPIO_LOW )
					{
						 
						SET_BIT(GPIOB_BRR ,copy_u8Pin); //Set Pin OutPut Low    (0v)
						
					}
					
					break;
					
		case GPIOC :
		            
					 if( copy_u8Value == GPIO_HIGH )
					{
						
						SET_BIT(GPIOC_BSRR,copy_u8Pin); //Set Pin OutPut High (3.3v)
						
					}
					else if( copy_u8Pin == GPIO_LOW )
					{
						 
						SET_BIT(GPIOC_BRR ,copy_u8Pin); //Set Pin OutPut Low    (0v)
						
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
		
		            LOC_u8Result = READ_BIT( GPIOA_IDR , copy_u8Pin ); //Copy Pin Status to Local Variable.
				   
					break;
					
		case GPIOB :
		
		            LOC_u8Result = READ_BIT( GPIOB_IDR , copy_u8Pin ); //Copy Pin Status to Local Variable.
					
					break;
		
		case GPIOC :
		            
			    LOC_u8Result = READ_BIT( GPIOC_IDR , copy_u8Pin ); //Copy Pin Status to Local Variable.
					 
					break;
					
					
					
		default : break;
					
	}
	
	return LOC_u8Result;
}


void MGPIO_voidSetPortODRValue(u8 copy_u8Port, u16 copy_u16Value)
{
	switch(copy_u8Port)
	{
		case GPIOA :
		
		                        GPIOA_ODR = copy_u16Value; //Set the whole port value in one time.
				   
					break;
					
		case GPIOB :
		
		                        GPIOB_ODR = copy_u16Value; //Set the whole port value in one time.
					
					break;
		
		case GPIOC :
		            
					GPIOC_ODR = copy_u16Value; //Set the whole port value in one time.
					 
					break;
					
					
					
		default : break;
					
	}
}

void MGPIO_voidLockPin (u8 copy_u8Port , u8 copy_u8Pin)
{
	
	switch(copy_u8Port)
	{
		case GPIOA :
		
		                        SET_BIT(GPIOA_LCK    ,    16);
				        CLR_BIT(GPIOA_LCK    ,    16); //Open Session for Writing Sequence .
					SET_BIT(GPIOA_LCK,copy_u8Pin); //           Lock               Pin .
					SET_BIT(GPIOA_LCK    ,    16); //Close Session for Writing Sequence.
				   
					break;
					
		case GPIOB :
		
		                        SET_BIT(GPIOB_LCK    ,    16);
				        CLR_BIT(GPIOB_LCK    ,    16); //Open Session for Writing Sequence .
					SET_BIT(GPIOB_LCK,copy_u8Pin); //           Lock               Pin .
					SET_BIT(GPIOB_LCK    ,    16); //Close Session for Writing Sequence.
					
					break;
		
		case GPIOC :
		            
					SET_BIT(GPIOC_LCK    ,    16);
				        CLR_BIT(GPIOC_LCK    ,    16); //Open Session for Writing Sequence .
					SET_BIT(GPIOC_LCK,copy_u8Pin); //           Lock               Pin .
					SET_BIT(GPIOC_LCK    ,    16); //Close Session for Writing Sequence.
					 
					break;
					
					
					
		default : break;
					
	}
}

void MGPIO_voidSetLCKR (u8 copy_u8Port, u16 copy_u16Value)
{
	switch(copy_u8Port)
	{
		case GPIOA :
		
		                        SET_BIT(GPIOA_LCK    ,    16);
				        CLR_BIT(GPIOA_LCK    ,    16); //Open Session for Writing Sequence .
					GPIOA_LCK   =   copy_u16Value; //lock the Locked Pins in the Port  .
					SET_BIT(GPIOA_LCK    ,    16); //Close Session for Writing Sequence.
				   
					break;
					
		case GPIOB :
		
		                        SET_BIT(GPIOB_LCK    ,    16);
				        CLR_BIT(GPIOB_LCK    ,    16); //Open Session for Writing Sequence .
					GPIOB_LCK   =   copy_u16Value; //lock the Locked Pins in the Port  .
					SET_BIT(GPIOB_LCK    ,    16); //Close Session for Writing Sequence.
					
					break;
		
		case GPIOC :
		            
					SET_BIT(GPIOC_LCK    ,    16);
				        CLR_BIT(GPIOC_LCK    ,    16); //Open Session for Writing Sequence .
					GPIOC_LCK   =   copy_u16Value; //lock the Locked Pins in the Port  .
					SET_BIT(GPIOC_LCK    ,    16); //Close Session for Writing Sequence.
					 
					break;
					
					
					
		default : break;
					
	}
}
