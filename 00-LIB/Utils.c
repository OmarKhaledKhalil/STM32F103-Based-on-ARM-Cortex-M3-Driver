/*************************************************************************************************/
/* Author : Omar Khaled                                                                          */
/* Version : V01                                                                                 */
/* Data   : 20-6-2023                                                                            */
/*************************************************************************************************/

#ifndef UTILS_H_
#define UTILS_H_

#define  READ_BIT(reg,bit)     ((reg>>bit)&1)
#define  SET_BIT(reg,bit)     (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)     (reg=reg&~(1<<bit))
#define  TOG_BIT(reg,bit)     (reg=reg^(1<<bit))

#define NULL 0







#endif /* UTILS_H_ */
