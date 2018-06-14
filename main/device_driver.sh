#!/bin/sh
insmod /home/pi/sp_project/touch/touch_dev.ko
mknod -m 666 /dev/touch_dev c 260 0
insmod /home/pi/sp_project/body_sense/body_dev.ko
mknod -m 666 /dev/body_dev c 261 0
insmod /home/pi/sp_project/3LED/3led_dev.ko
mknod -m 666 /dev/3led_dev c 262 0
