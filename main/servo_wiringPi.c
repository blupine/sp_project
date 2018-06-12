#include "KBN.h"

#define PIN 1

void servo(){
	pinMode(PIN, PWM_OUTPUT);

	softPwmCreate(PIN, 0, 200);
	softPwmWrite(PIN, 5);
<<<<<<< HEAD
	delay(1000);
	softPwmWrite(PIN, 25);
	delay(1000);
=======
	delay(600);
	softPwmWrite(PIN, 25);
	delay(600);
>>>>>>> 4976f076847bba790a17459b3b67b9a6a885215d

	return;
}
