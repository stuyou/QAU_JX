obj-m += led_drv.o
KDIR := /opt/FriendlyARM/mini6410/linux/linux-2.6.38 #嵌入式LINUX内核源码路径

PWD = $(shell pwd)
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -rf *.o
