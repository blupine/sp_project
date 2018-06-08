#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define DEV_NAME "/dev/power_dev"

int main(){
	int fd = 0;
	char buf[2]="";

	fd = open(DEV_NAME, O_WRONLY);
	if(fd == -1){
		fprintf(stderr,"open() error : %s\n",strerror(errno));
		exit(1);
	}

	while(1){
		printf("1.ON 2.OFF 3.END\n");
		scanf("%s",buf);
		
		if(!strcmp(buf,"3"))	return;

		write(fd,buf,1);
	}
}
