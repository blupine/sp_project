KERNELDIR = /lib/modules/$(shell uname -r)/build

obj-m := power_dev.o

PWD := $(shell pwd)

default :
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
