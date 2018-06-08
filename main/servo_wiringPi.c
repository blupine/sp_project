#include "KBN.h"

#define PIN 1

void servo(){
	softPwmCreate(PIN, 0, 200);
	softPwmWrite(PIN, 5);
	delay(1200);
	softPwmWrite(PIN, 25);
	delay(1200);

	return;
}
