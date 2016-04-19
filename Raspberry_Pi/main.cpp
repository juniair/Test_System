#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// we have to use BCM numbering when initializing with wiringPiSetupSys
// when choosing a different pin number please use the BCM numbering, also
// update the Property Pages - Build Events - Remote Post-Build Event command 
// which uses gpio export for setup for wiringPiSetupSys
#define	LED	29

int main(void)
{
	wiringPiSetupSys();

	pinMode(LED, OUTPUT);

	while (true)
	{
		printf("\n\n\n");
		digitalWrite(LED, HIGH);  // On
		system("gpio readall");
		delay(1000); // ms
		printf("\n\n\n");
		digitalWrite(LED, LOW);	  // Off
		system("gpio readall");
		delay(1000);
		
	}
	return 0;
}