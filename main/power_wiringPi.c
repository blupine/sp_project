#include "KBN.h"

#define GPIO_POWER 25//GPIO.25

void power(){
	char buf[1024];

	pinMode(GPIO_POWER, OUTPUT);

	printf("1.ON 2.OFF\n");
	scanf("%s",buf);

	if(!strcmp(buf,"1"))	digitalWrite(GPIO_POWER, 1);
	else if(!strcmp(buf, "2"))	digitalWrite(GPIO_POWER, 0);
}
