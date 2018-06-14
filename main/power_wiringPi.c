#include "KBN.h"

#define GPIO_POWER 6//GPIO.6

void power(){
	if(sleep_on == 1) return;
       
	char buf[1024];

	pinMode(GPIO_POWER, OUTPUT);

	printf("1.ON 2.OFF\n");
	scanf("%s",buf);

	if(!strcmp(buf,"1"))	digitalWrite(GPIO_POWER, 1);
	else if(!strcmp(buf, "2"))	digitalWrite(GPIO_POWER, 0);
}

void power2(){
	if(sleep_on == 1) return;

	pinMode(GPIO_POWER, OUTPUT);

	power_chk%2 == 0 ? digitalWrite(GPIO_POWER, 1) : digitalWrite(GPIO_POWER, 0);
	power_chk++;
}
