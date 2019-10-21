/*
 * DR_Variables.h
 *
 *  Created on: 22 Sep 2019
 *      Author: rnsavinelli
 */

#ifndef DR_VARIABLES_H_
#define DR_VARIABLES_H_

#define TRUE	1
#define FALSE	0

#define     __R					volatile const  	/* READ ONLY  */
#define 	__W     			volatile 	       	/* WRITE ONLY */
#define 	__RW				volatile           	/* READ-WRITE */
#define 	ON					1
#define 	OFF					0

#define 	NULL				(( void *) 0)

typedef		unsigned int		uint32_t;
typedef		short unsigned int	uint16_t;
typedef		unsigned char		uint8_t;
typedef		int					int32_t;
typedef		short int			int16_t;
typedef		char				int8_t;

#endif /* DR_VARIABLES_H_ */
