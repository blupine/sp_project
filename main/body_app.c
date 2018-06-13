#include "KBN.h"

#define DEV_PATH "/dev/body_dev"

void* body(){
	int fd = 0;
	char buf[1024];
	int test=0;
	fd = open(DEV_PATH, O_RDONLY);
	sleep(5);

	if(fd == -1){
		fprintf(stderr,"fopen() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		read(fd,buf,1);
		test = (buf[0] == '1' ? 0 : ++test);
		if(test == 1000){
			servo_chk%2 == 1 ? servo() : NULL;
			power_chk%2 == 1 ? power2() : NULL;
		}
		else if(test == 0){
			printf("sensed!\n");
		}
		sleep(3);
	}
}
