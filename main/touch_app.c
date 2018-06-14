#include "KBN.h"

#define DEV_PATH "/dev/touch_dev"

void* touch(){
	int fd = 0;
	char buf[5]="";
	int lcd_chk = 0;

	if((fd = open(DEV_PATH, O_RDONLY)) < 0){
		fprintf(stderr,"open() error : %s\n",strerror(errno));
		exit(1);
	}
	while(1){
		read(fd,buf, 4);
		if(lcd_chk%2 == 0){
			buf[0] == '1' ? servo() : NULL;
			buf[1] == '1' ? power2() : NULL;
			buf[2] == '1' ? exit(1) : NULL;//terminating
			buf[3] == '1' ? lcd_chk++ : NULL;
			sleep(1);	
		}//normal mode
		else if(lcd_chk%2 == 1){
			buf[0] == '1' ? bme280() : NULL;
		//	buf[1] == '1' ? function("dht11") : NULL;
			buf[2] == '1' ?	gp2y10() : NULL;
			buf[3] == '1' ? lcd_chk++ : NULL;
			sleep(1);	
		}//lcd mode
		buf[0] == '1' ? printf("touch 1\n") : NULL;
		buf[1] == '1' ? printf("touch 2\n") : NULL;
		buf[2] == '1' ? printf("touch 3\n") : NULL;
		buf[3] == '1' ? printf("touch 4\n") : NULL;

	}
}
