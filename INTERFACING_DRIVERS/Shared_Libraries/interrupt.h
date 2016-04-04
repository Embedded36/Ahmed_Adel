/*
 * interrupt.h
 *
 *  Created on: Apr 4, 2016
 *      Author: Ahmed
 */

#ifndef SHARED_LIBRARIES_INTERRUPT_H_
#define SHARED_LIBRARIES_INTERRUPT_H_

#define ISR(vector, ...) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
		void vector(void)


#endif /* SHARED_LIBRARIES_INTERRUPT_H_ */
