linux_led.c----LINUX下的LED控制程序，程序启动后，依次轮流点亮LED1~LED4。执行该程序前，需用/etc/rc.d/init.d/leds  stop指令停止LINUX操作系统自带的LED点亮程序的运行。
linux_leds_drv.c----友善之臂提供的led驱动程序
Makefile----编译linux_led.c的Makefile文件，生成的可执行程序名为linux_led