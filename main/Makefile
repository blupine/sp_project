main : main.o body_app.o power_wiringPi.o touch_app.o servo_wiringPi.o
	gcc -o main main.o body_app.o power_wiringPi.o touch_app.o servo_wiringPi.o -pthread -lwiringPi

main.o : main.c
	gcc -c -o main.o main.c

body_app.o : body_app.c
	gcc -c -o body_app.o body_app.c

power_wiringPi.o : power_wiringPi.c
	gcc -c -o power_wiringPi.o power_wiringPi.c

touch_app.o : touch_app.c
	gcc -c -o touch_app.o touch_app.c

servo_wiringPi.o : servo_wiringPi.c
	gcc -c -o servo_wiringPi.o servo_wiringPi.c

clear :
	rm *.o main
