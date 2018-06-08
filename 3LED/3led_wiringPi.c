#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

//temp GPIO
#define RED 1
#define GREEN 2
#define BLUE 3

int main(){
	int buf;

	if(wiringPiSetup() == -1)
		return 1;

	pinMode(RED, OUTPUT);
	pinMode(BLUE, OUTPUT);
	pinMode(GREEN, OUTPUT);

	softPwmCreate(RED, 0, 255);
	softPwmCreate(GREEN, 0, 255);
	softPwmCreate(BLUE, 0, 255);

	while(scanf("%o",&buf) != 0){
		buf & 64 ? softPwmWrite(RED, 255) : softPwmWrite(RED, 0);
		buf & 8	?	softPwmWrite(GREEN, 255) : softPwmWrite(GREEN, 0);
		buf & 1	?	softPwmWrite(BLUE, 255) : softPwmWrite(BLUE, 0);

		printf("type 'rgb' by octect\n");
	}

	return 0;
}
