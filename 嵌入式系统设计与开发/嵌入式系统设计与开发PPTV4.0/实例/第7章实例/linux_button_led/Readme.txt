linux_button_led.c----LINUX下的按键控制LED点亮程序，程序启动后，按下KEY1~KEY4，依次点亮LED1~LED4，间隔一会后熄灭。执行该程序前，需用/etc/rc.d/init.d/leds  stop指令停止LINUX操作系统自带的LED点亮程序的运行。
button_led----编译好的linux_button_led.c
Makefile----编译linux_button_led.c的Makefile文件，生成的可执行程序名为button_led