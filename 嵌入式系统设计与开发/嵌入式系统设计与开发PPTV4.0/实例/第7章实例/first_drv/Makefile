obj-m += first_drv.o
KDIR := /opt/FriendlyARM/mini6410/linux/linux-2.6.38 #如果是用于arm平台，则内核路径为arm内核的路径

PWD = $(shell pwd)
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -rf *.o
