#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <softPwm.h>
#include <pthread.h>
#include <sys/wait.h>
#include <lcd.h>

#define DEV_LED "/dev/3led_dev"
#define LCD_RS 11
#define LCD_E 10
#define LCD_D4 24
#define LCD_D5 23 
#define LCD_D6 22
#define LCD_D7 21

extern int lcd_num;
extern int power_chk;
extern int servo_chk;
extern int led_fd;
extern int sleep_on;

void* lcd(void*);
void* body();
void* touch();
void power();
void power2();
void servo();
void gp2y10();
void bme280();
