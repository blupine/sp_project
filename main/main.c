#include "KBN.h"

int main(){
	int chk = 0;
	pthread_t tid[2];
	int status;

	if(wiringPiSetup() == -1)
		return;

	pthread_create(&tid[0], NULL, body, NULL);
	pthread_create(&tid[1], NULL, touch, NULL);

	while(1){
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
}
