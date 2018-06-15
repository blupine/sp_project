main : main.o bme280.o body_app.o power_wiringPi.o touch_app.o servo_wiringPi.o lcd_wiringPi.o gp2y10.o dht11.o
	gcc -o main main.o body_app.o power_wiringPi.o touch_app.o servo_wiringPi.o lcd_wiringPi.o gp2y10.o bme280.o dht11.o -I/usr/include/python3.5m -lpython3.5m -pthread -lwiringPi -lwiringPiDev -g -Wall -Wextra -pedantic -std=c11 -D_DEFAULT_SOURCE -D_BSD_SOURCE -lm

dht11.o : python.c
	gcc -c -o dht11.o python.c -I/usr/include/python3.5m -lpython3.5m

gp2y10.o : gp2y10.c
	gcc -c -o gp2y10.o gp2y10.c

lcd_wiringPi.o : lcd_wiringPi.c
	gcc -c -o lcd_wiringPi.o lcd_wiringPi.c

bme280.o : bme280.c
	gcc -g -Wall -Wextra -pedantic -std=c11 -D_DEFAULT_SOURCE -D_BSD_SOURCE -c -o bme280.o bme280.c -lwiringPi -lm

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
