#include "KBN.h"

#define DEV_PATH "/dev/body_dev"

void* body(){
	int fd = 0;
	char buf[1024];

	fd = open(DEV_PATH, O_RDONLY);
	sleep(5);

	if(fd == -1){
		fprintf(stderr,"fopen() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		read(fd,buf,1);
		buf[0] == '1' ? printf("sensed\n") : NULL;
		sleep(3);
	}
}
