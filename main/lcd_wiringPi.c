#include "KBN.h"

void* lcd(void* buf){
	char* temp;

/*	temp = strtok((char*)buf," ");
	while(temp != NULL){
		lcdPosition(lcd_num, 0, 0);
		lcdPuts(lcd_num ,temp);
		printf("lcd : %s\n",temp);
		temp = strtok(NULL," ");
		delay(10000);
	}

*/	
	lcdPosition(lcd_num,0,0);
	lcdPuts(lcd_num,"testing");
}
