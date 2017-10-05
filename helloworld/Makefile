

KVER := $(shell uname -r)
KSRC := /lib/modules/$(KVER)/build


obj-m := helloworld.o 

all: modules

modules:
	make -C $(KSRC) M=$(shell pwd) modules

clean:
	rm -f Module.symvers Module.markers modules.order
	rm -f *.mod.c *.mod *.o *.ko

