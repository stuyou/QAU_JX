main.c:主文件，主函数main中调用的mysum2，mysum3, mysum4函数分别定义在fun2.c，fun3.c，fun4.c
main2.c:主文件，主函数main中只调用了mysum2函数，演示多目标时使用
makefile1：使用一般的方式
makefile2：使用变量
makefile3：使用伪目标
makefile4：使用隐含规则
makefile5：多目标(main和main2)
makefile6：使用模式规则