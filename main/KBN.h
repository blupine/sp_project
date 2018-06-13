#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <softPwm.h>
#include <pthread.h>

int power_chk = 0;
int servo_chk = 0;

void* body();
void* touch();
void power();
void power2();
void servo();

