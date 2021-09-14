CC	= gcc
CFLAGS	= -g
TARGET	= driver
OBJS	= driver.o

$ (TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

liblog.a: driver.o
	ar -rcs liblog.a driver.o

driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

clean:
	rm -rf *.o P1
