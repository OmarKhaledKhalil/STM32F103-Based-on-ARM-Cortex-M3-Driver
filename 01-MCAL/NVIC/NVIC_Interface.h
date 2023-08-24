/*************************************************************************************************/
/* Author : Omar Khaled                                                                          */
/* Version : V01                                                                                 */
/* Data   : 30-6-2023                                                                            */
/*************************************************************************************************/
#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H


void MNVIC_voidEnableInterrupt  ( u8 Copy_u8IntNumber );
void MNVIC_voidDisableInterrupt ( u8 Copy_u8IntNumber );
void MNVIC_voidSetPendingFlag   ( u8 Copy_u8IntNumber );
void MNVIC_voidClearPendingFlag ( u8 Copy_u8IntNumber );
u8   MNVIC_u8ReadActiveFlag     ( u8 Copy_u8IntNumber );

#endif
