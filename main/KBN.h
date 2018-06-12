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

void* body();
void* touch();
void power();
void power2(int);
void servo();

