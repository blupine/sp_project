#include <Python.h>
#include <stdio.h>

int main(){
	Py_Initialize();
	if(Py_IsInitialized()){
		char* str1 = "tmp2 = 20\nprint tmp2";
		char buf[1024] = "";
		dup2(0,1);
		PyRun_SimpleString("import RPi.GPIO as GPIO\n");
		PyRun_SimpleString("import dht11\n");
		PyRun_SimpleString("import time\n");
		PyRun_SimpleString("datetime\n");
		PyRun_SimpleString("GPIO.setwarnings(False)\n");
		PyRun_SimpleString("GPIO.setmode(GPIO.BCM)\n");
		PyRun_SimpleString("GPIO.cleanup()\n");
		PyRun_SimpleString("instance = dht11.DHT11(pin=4)\n");
		PyRun_SimpleString("while True:\n");
		PyRun_SimpleString("result = instance.read()\n");
		PyRun_SimpleString("if result.is_valid():\n");

		PyRun_SimpleString("print(\'Temperature: %dC\' % result.temperature)\n");
		PyRun_SimpleString("print(\'Humidity: %d %%\' % result.humidity)\n");
		while(gets(buf) != NULL){
			fprintf(stderr,"buf %s\n",buf);
			memset(buf,0,1024);
		}
		PyRun_SimpleString("time.sleep(1)\n");
		printf("\n");

		Py_Finalize();
	}
	return 0;
}
