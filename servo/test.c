#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <unistd.h>

#define PIN 1
int main(){
	int pos = 180;
	int dir = 1;

	if(wiringPiSetup() == -1)
		return 1;

	pinMode(PIN, OUTPUT);
	digitalWrite(PIN, LOW);
	softPwmCreate(0,0,200);

	for(int i =0; i<4; i++){
		printf("asd\n");
		pos += dir;
		if(pos < 180 || pos > 194) dir *= -1;
		softPwmWrite(0,pos);
		delay(1000);
	}
	return 0;
}
/*
	softPwmCreate(PIN, 0, 200);
	softPwmWrite(PIN, 5);
	delay(300);
	softPwmWrite(PIN, 25);
	delay(300);
*/
	//digitalWrite(PIN, 1);
//	return 0;
//}
