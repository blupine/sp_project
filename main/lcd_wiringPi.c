#include "KBN.h"

void* lcd(void* buf){
	//printf("sleep : %d\n",lcd_sleep);
	if(lcd_sleep == 1){
	//	printf("sleep :if %d\n",lcd_sleep);
		return;
	} 
	lcd_sleep = 1;
	if(!strcmp((char*)buf,"normal_buf")){
		printf("nor\n");
		lcd_chk++;
	}
	else if(!strcmp((char*)buf, "lcd_mode")){
		printf("lcd_mode\n");
		lcd_chk++;
	}
	char* temp;

	printf("lcd start\n");

	temp = strtok((char*)buf," ");
	while(temp != NULL){
		lcdClear(lcd_num);
		lcdPosition(lcd_num, 0, 0);
		lcdPuts(lcd_num ,temp);
		printf("lcd : %s\n",temp);
		temp = strtok(NULL," ");
		delay(5000);
		//lcdClear(lcd_num);
	}
	printf("lcd done\n");
	lcd_sleep=0;
//	lcdPosition(lcd_num,0,0);
//	lcdPuts(lcd_num,"testing");
}
