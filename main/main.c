#include "KBN.h"

int servo_chk = 0;
int power_chk = 0;
int led_fd = 0;
int sleep_on = 0;
int lcd_num = 0;

int main(){
	int chk = 0;
	pthread_t tid[2];
	int status;

	if(wiringPiSetup() == -1)
		return;

	led_fd = open(DEV_LED, O_WRONLY);
	if(lcd_num = lcdInit(2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0)){
	       fprintf(stderr,"lcd init failed!\n");
	       exit(1);
	}
	if(led_fd == -1){
	       fprintf(stderr,"3led_dev open error : %s\n",strerror(errno));
	       exit(1);
	}
	pthread_create(&tid[0], NULL, body, NULL);
	pthread_create(&tid[1], NULL, touch, NULL);

/*	while(1){
		if(sleep_on == 1)	continue;
		printf("what you want?\n1.power adjustment 2.servo activating\n");
		scanf("%d",&chk);
		if(chk == 1){
			power();
		}//power
		else if(chk == 2){
			servo();
		}//servo
		else{
			printf("error shutdown\n");
			exit(1);
		}//input error
	}
*/
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	close(led_fd);
}
