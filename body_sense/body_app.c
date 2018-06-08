#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define DEV_PATH "/dev/body_dev"

int main(){
	int fd = 0;
	char buf[1024];

	fd = open(DEV_PATH, O_RDONLY);
	if(fd == -1){
		fprintf(stderr,"fopen() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		read(fd,buf,1);
		buf[0] == '1' ? printf("sensed\n") : printf("---\n");
		sleep(3);
	}
}
