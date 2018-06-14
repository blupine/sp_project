#include <wiringPi.h>
#include <lcd.h>
#include <stdio.h>

#define LCD_RS 11
#define LCD_E 10
#define LCD_D4 21//5GPIO.24
#define LCD_D5 22//6GPIO.23
#define LCD_D6 23//13GPIO.22
#define LCD_D7 24//19GPIO.21 1 -> 24

int main(){
	int lcd;
	wiringPiSetup();

	if(lcd = lcdInit(2,16,4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0,0,0,0)){
		printf("lcd init failed!\n");
		return -1;
	}

	lcdPosition(lcd,0,0);
	lcdPuts(lcd, "LOVE Min A");

	getchar();
}
