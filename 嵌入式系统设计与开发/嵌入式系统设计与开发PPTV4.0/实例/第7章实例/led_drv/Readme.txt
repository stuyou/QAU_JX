led_drv.c----LED驱动程序，加载驱动模块后，自动产生设备节点/dev/myled_drv
led_drv.ko----编译出来的LED驱动程序模块
led_drv_test.c----LED驱动程序的测试程序。运行测试程序之前，需先运行如下指令：/etc/rc.d/init.d/leds  stop指令停止LINUX操作系统自带的LED点亮程序的运行。
leddrv_test-----编译出来的LED驱动程序的测试程序
Makefile----编译驱动程序的Makefile文件