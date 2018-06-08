#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define DEV_PATH "/dev/body_dev"

int main(){
	FILE* fd = 0;
	char buf[1024];

	fd = fopen(DEV_PATH, "r");
	if(fd == NULL){
		fprintf(stderr,"fopen() error : %s\n",strerror(errno));
		exit(1);
	}

	while(fread(&buf,1,1,fd) != 0){
		buf[0] == '1' ? printf("sensed\n") : NULL;
	}
}
