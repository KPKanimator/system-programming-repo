# all: Demo01

#Demo01: Demo01.o
#	cc Demo01.o -o Demo01

#Demo01.o: Demo01.c
#	cc -c Demo01.c

#clean:
#	rm -f Demo01 Demo01.o

# Версія 2: Явне використання компілятора gcc
#CC = gcc

#all: Demo01

#Demo01: Demo01.o
#	$(CC) Demo01.o -o Demo01

#Demo01.o: Demo01.c
#	$(CC) -c Demo01.c

#clean:
#	rm -f Demo01 Demo01.o

# Версія 3: Вибір компілятора та файлу *.с через змінну оточення
CC = gcc
TARGET = Demo02

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).c
	$(CC) -c $(TARGET).c

clean:
	rm -f $(TARGET) $(TARGET).o