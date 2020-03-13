CC=gcc -g 

all : interpreter.o shell.o shellmemory.o kernel.o ram.o pcb.o cpu.o
	$(CC) interpreter.o shell.o shellmemory.o kernel.o ram.o pcb.o cpu.o -o mykernel

interpreter.o : interpreter.c 
	$(CC) -c interpreter.c 

shell.o : shell.c 
	$(CC) -c shell.c 

shellmemory.o : shellmemory.c
	$(CC) -c shellmemory.c

kernel.o : kernel.c
	$(CC) -c kernel.c

ram.o : ram.c
	$(CC) -c ram.c

pcb.o : pcb.c
	$(CC) -c pcb.c

cpu.o : cpu.c
	$(CC) -c cpu.c

.PHONY:
clean:
	rm -f interpreter.o shell.o shellmemory.o kernel.o ram.o pcb.o cpu.o
	rm -f mykernel