#include "KBN.h"

#define DEV_PATH "/dev/body_dev"

void* body(){
	int fd = 0;
	char buf[1024];
	int sense = 0;

	fd = open(DEV_PATH, O_RDONLY);
	sleep(5);

	if(fd == -1){
		fprintf(stderr,"fopen() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		read(fd,buf,1);

		buf[0] == '1' ? sense++ : (sense = 0);
		if(sense > 1000){
			sleep(3);
			continue;
		}
		else if(sense == 1000){
			write(led_fd,"100",3);
			servo_chk%2 == 1 ? servo() : NULL;
			power_chk%2 == 1 ? power2() : NULL;
			sleep_on = 1;
		}
		else if(sense == 0){
			sleep_on = 0;
			write(led_fd,"010",3);//turning GREEN
			printf("sensed!\n");
		}
		sleep(3);
	}
}
