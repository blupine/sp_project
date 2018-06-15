#include <Python.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "KBN.h"

void dht11(){
	int temp;
	int fd = open("testing", O_WRONLY | O_CREAT | O_TRUNC);
	temp = dup(1);
	dup2(fd,1);
	Py_Initialize();
	if(Py_IsInitialized()){
		char* str1 = "tmp2 = 20\nprint tmp2";
		char buf[1024] = "";
		PyRun_SimpleString("import RPi.GPIO as GPIO\n");
		PyRun_SimpleString("import dht11\n");
		PyRun_SimpleString("import time\n");
		PyRun_SimpleString("import datetime\n");
		PyRun_SimpleString("GPIO.setwarnings(False)\n");
		PyRun_SimpleString("GPIO.setmode(GPIO.BCM)\n");
		PyRun_SimpleString("GPIO.cleanup()\n");
		PyRun_SimpleString("instance = dht11.DHT11(pin=4)\n");
		PyRun_SimpleString("while True:\n");
		PyRun_SimpleString("result = instance.read()\n");
		PyRun_SimpleString("if result.is_valid(): \n");

		PyRun_SimpleString("print(\'temperature:%dC\' % result.temperature)\n");
		PyRun_SimpleString("print(\'humidity:%d%%\' % result.humidity)\n");
		PyRun_SimpleString("time.sleep(1)\n");

		Py_Finalize();
	}
	fflush(stdout);
	close(fd);
	dup2(temp, 1);
	FILE* f_fd = fopen("testing", "r");
	char buf[1024]="";
	char buf2[1024]="";
	char buf3[1024]="";
	fprintf(stderr,"start\n");
	fscanf(f_fd,"%s\n", buf);
	fscanf(f_fd, "%s", buf2);
	fclose(f_fd);
	sprintf(buf3,"%s %s",buf,buf2);
	fprintf(stderr,"buf3 : %s\n",buf3);
	pthread_t tid;
	pthread_attr_t attr;
	if(pthread_attr_init(&attr) != 0)	exit(1);
	if(pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED) !=0 )	exit(1);
	if(pthread_create(&tid, &attr, lcd,(void*)buf3) != 0)	exit(1);
	
	//pthread_join(tid,NULL);
	fprintf(stderr,"done \n");
	return 0;
}
