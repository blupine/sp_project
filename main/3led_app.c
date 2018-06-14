#include "KBN.h"

int main(){
	int fd = open(DEV_LED, O_WRONLY);
	char buf[1024] ="";
	if(fd == -1){
		fprintf(stderr,"open() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		printf("type 'R:G:B'\n");
		scanf("%s",buf);
		write(fd,buf,strlen(buf));
	}
}
	
