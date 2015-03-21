all: llist driver.c
	gcc -o driver llist.o driver.c

llist: llist.h llist.c
	gcc -c llist.c

clean:
	rm -rf driver
	rm -rf llist.o