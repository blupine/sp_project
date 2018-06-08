#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <softPwm.h>
#include <pthread.h>

void* body();
void* touch();
void power();
void servo();

