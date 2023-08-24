/*************************************************************************************************/
/* Author : Omar Khaled                                                                          */
/* Version : V01                                                                                 */
/* Data   : 30-6-2023                                                                            */
/*************************************************************************************************/

#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H



/*Register Defination*/

/* Base Address = 0xE000E100 */

#define   NVIC_ISER0        *(volatile (u32*)0xE000E100) /* Enable  Interrupts from  0      to    31     */
#define   NVIC_ISER1        *(volatile (u32*)0xE000E104) /* Enable  Interrupts from  32     to    63     */
#define   NVIC_ICER0        *(volatile (u32*)0xE000E180) /* Disable Interrupts from  0      to    31     */
#define   NVIC_ICER1        *(volatile (u32*)0xE000E184) /* Disable Interrupts from  32     to    63     */
#define   NVIC_ISPR0        *(volatile (u32*)0xE000E200) /* Set Pending Flag Interrupts from   0 to 31   */ 
#define   NVIC_ISPR1        *(volatile (u32*)0xE000E204) /* Set Pending Flag Interrupts from   32 to 63  */
#define   NVIC_ICPR0        *(volatile (u32*)0xE000E280) /* Clear Pending Flag Interrupts from 0 to 31   */ 
#define   NVIC_ICPR1        *(volatile (u32*)0xE000E284) /* Clear Pending Flag Interrupts from 32 to 63  */
#define   NVIC_IABR0        *(volatile (u32*)0xE000E300) /* Read Active Flag  Interrupts  from 0 to 31   */
#define   NVIC_IABR1        *(volatile (u32*)0xE000E304) /* Read Active Flag  Interrupts  from 32 to 63  */

#endif
