#CC=arm-linux-gnueabihf-gcc
CC=gcc

all:
	$(CC) -o ipcmq_send_exe ipcmq_send.c -lrt
	$(CC) -o ipcmq_recv_exe ipcmq_recv.c -lrt
clean:
	rm -r -f *.o
	rm *_exe

