led_misc.c----采用杂项设备的LED驱动程序，加载驱动模块后，自动产生设备节点/dev/myled_misc
led_misc.ko----编译出来的LED驱动程序模块，使用insmod led_misc.ko载入LINXU内核
led_misc_test.c----LED驱动程序的测试程序。运行测试程序之前，需先运行如下指令：/etc/rc.d/init.d/leds  stop指令停止LINUX操作系统自带的LED点亮程序的运行。
ledmisc_test-----编译出来的LED驱动程序的测试程序
Makefile----编译驱动程序的Makefile文件