

/**
 * @file    OneLed.c
 * @brief   Application entry point.
 */
/**Standard input/output to debug console*/
#include <stdio.h>
/**Standard integer definition provided by the compiler*/
#include <stdint.h>
#include "MK64F12.h"


int main(void) {

	SIM->SCGC5 = 0x400;

	PORTB->PCR[22] = 0x00000100;

	GPIOB->PDOR = 0x00400000;

	GPIOB->PDDR = 0x00400000;


    while(1) {

		GPIOB->PDOR = 0;

		printf("RED LED ON\n");


		GPIOB->PDOR = 0x00400000;

		GPIOB->PDOR = 0x00000000;

		GPIOB->PDOR = 0x00200000;

		printf("RED LED OFF\n");

    }
    return 0 ;
}
