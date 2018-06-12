#include "KBN.h"

#define DEV_PATH "/dev/body_dev"

void* body(){
	int fd = 0;
	char buf[1024];
<<<<<<< HEAD
	int sense = 0;

=======
	int test=0;
>>>>>>> 4976f076847bba790a17459b3b67b9a6a885215d
	fd = open(DEV_PATH, O_RDONLY);
	sleep(5);

	if(fd == -1){
		fprintf(stderr,"fopen() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		read(fd,buf,1);
<<<<<<< HEAD
		sense = (buf[0] == '1' ? 1 : 0);//printf("sensed\n") : NULL;
=======
		test = (buf[0] == '1' ? 0 : ++test);
		if(test == 1000){
			servo();
			power2(0);
		}
>>>>>>> 4976f076847bba790a17459b3b67b9a6a885215d
		sleep(3);
	}
}
