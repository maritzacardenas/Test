
#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"

void delay(uint16_t delay);

int main(void) {
	/**Activating the GPIOB and GPIOE clock gating*/
	SIM->SCGC5 = 0x0400;
	SIM->SCGC5 |= 0x2000;

	SIM->SCGC5 = 0x2400;
	/**Pin control configuration of GPIOB pin22 and pin21 as GPIO*/
	PORTB->PCR[21] = 0x00000100;
	PORTB->PCR[22] = 0x00000100;
	PORTE->PCR[26] = 0x00000100;

	GPIOB->PDOR = 0xFFFFFFF;

	/**Configures GPIOB pin21 as output*/
	GPIOB->PDDR = 0x00200000;
	/**Configures GPIOB pin22 as output*/
	GPIOB->PDDR |= 0x00400000;
	/**Configures GPIOE pin26 as output*/
	GPIOE->PDDR |= 0x04000000;


    while(1) {


		GPIOB->PDOR &= ~(0x00200000);/**Blue led on*/
		delay(65000);
		GPIOB->PDOR |= 0x00200000;/**Blue led off*/

		GPIOB->PDOR &= ~(0x00400000);/**Read led on*/
		delay(65000);
		GPIOB->PDOR |= 0x00400000;/**Read led off*/
		delay(65000);

		GPIOE->PDOR &= ~(0x04000000);
		delay(65000);
		GPIOE->PDOR |= 0x04000000;
		delay(65000);

    }
    return 0 ;
}


////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
void delay(uint16_t delay)
{
	volatile uint16_t counter;

	for(counter=delay; counter > 0; counter--)
	{
		__asm("nop");
	}
}
