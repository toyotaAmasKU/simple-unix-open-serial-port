TARGET=main
CFLAGS=-Iinclude -I.
OBJS= serial_port.o

.SECONDARY:

all: $(TARGET).elf

clean:
	-rm -f *.o *.elf

%.elf:  %.o $(OBJS)
	gcc $(CFLAGS) -o $@ $^

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<
