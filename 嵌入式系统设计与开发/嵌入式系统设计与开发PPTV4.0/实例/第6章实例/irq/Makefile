irq.bin: start.o main.o led.o irq.o
	arm-linux-ld -Ttext 0x50000000 -o irq.elf $^
	arm-linux-objcopy -O binary irq.elf irq.bin
	arm-linux-objdump -D irq.elf > irq_elf.dis
%.o : %.S
	arm-linux-gcc -o $@ $< -c

%.o : %.c
	arm-linux-gcc -o $@ $< -c 

clean:
	rm *.o *.elf *.bin *.dis  -rf
