#include <stdio.h>
#include <wiringPi.h>
#include <string.h>

#define GPIO_POWER 25//GPIO.25

void main(){
	char buf[1024];

	if(wiringPiSetup() == -1)
		return;

	pinMode(GPIO_POWER, OUTPUT);

	while(1){
		printf("1.ON 2.OFF 3.END\n");
		scanf("%s",buf);

		if(!strcmp(buf,"1"))	digitalWrite(GPIO_POWER, 1);
		else if(!strcmp(buf, "2"))	digitalWrite(GPIO_POWER, 0);
		else if(!strcmp(buf, "3"))	return;
	}
}
