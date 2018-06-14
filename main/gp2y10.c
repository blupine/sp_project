#include <wiringPiI2C.h>
#include "KBN.h"

#define ADCArduinoI2CADDR 0x04
#define ADCREQCOMMAND 0x20

void gp2y10(){
	int fd, dustVal;
	float dustDensity;

	if ((fd = wiringPiI2CSetup(ADCArduinoI2CADDR)) == -1)
		return -2;

	wiringPiI2CWrite(fd, ADCREQCOMMAND);
	dustVal = wiringPiI2CRead(fd);

	dustDensity = 0.17 * (dustVal / 10000 * 0.0049) - 0.1;
//	printf("Dust density from GP2Y10 PM2.5 Sensor: %f\n", dustDensity);
	char buf[100]="";
	sprintf(buf,"Dust %f",dustDensity);
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&tid, &attr, lcd, (void*)buf);

	return 0;
}
