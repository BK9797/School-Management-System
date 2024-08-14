/*
 ============================================================================
 Name        : main.c
 Author      : BISHOY KAMEL
 Date        : 6-8-2024
 Copyright   : Your copyright notice
 Description : School Management System Project Using C
 ============================================================================
 */
/*******************************************************************************
 *                             Main Function definition                         *
 *******************************************************************************/

#include "school.h"
int main(void) {
	welcome();
	if(pass()){
		while (1) {
			menu();
		}
	}
	return 0;
}
