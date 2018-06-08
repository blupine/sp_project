#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define DEV_PATH "/dev/touch_dev"

int main(){
	int fd = 0;
	char buf[5]="";
	if((fd = open(DEV_PATH, O_RDONLY)) < 0){
		fprintf(stderr,"open() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		read(fd,buf, 4);
	//	printf("%d%d%d%d\n",buf[0],buf[1],buf[2],buf[3]);
		
		buf[0] == '1' ? printf("1\n") : NULL;
		buf[1] == '1' ? printf("2\n") : NULL;
		buf[2] == '1' ? printf("3\n") : NULL;
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
