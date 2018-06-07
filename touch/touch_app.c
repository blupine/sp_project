#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define DEV_PATH "/dev/touch_dev"

int main(){
	int fd = 0;
	char buf[4];
	if((fd = open(DEV_PATH, O_RDONLY)) < 0){
		fprintf(stderr,"open() error : %s\n",strerror(errno));
		exit(1);
	}

	while(read(fd,buf, 4) == 4){
		buf[0] == 1 ? printf("1\n") : NULL;
		buf[1] == 1 ? printf("2\n") : NULL;
		buf[2] == 1 ? printf("3\n") : NULL;
		buf[3] == 1 ? printf("4\n") : NULL;
	}
}
