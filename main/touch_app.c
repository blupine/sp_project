#include "KBN.h"

#define DEV_PATH "/dev/touch_dev"

void* touch(){
	int fd = 0;
	char buf[5]="";
	if((fd = open(DEV_PATH, O_RDONLY)) < 0){
		fprintf(stderr,"open() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		read(fd,buf, 4);
	//	printf("%d%d%d%d\n",buf[0],buf[1],buf[2],buf[3]);
		
		buf[0] == '1' ? servo() : NULL;
		buf[1] == '1' ? power2(1) : NULL;
		buf[2] == '1' ? power2(0) : NULL;
		buf[3] == '1' ? printf("4\n") : NULL;
		sleep(1);	
	/*
		buf & 1 ? printf("1\n") : NULL;
		buf & 8 ? printf("2\n") : NULL;
		buf & 64 ? printf("3\n") : NULL;
		buf & 512 ? printf("4\n") : NULL;
	*/
	//	sleep(2);
	}
}
