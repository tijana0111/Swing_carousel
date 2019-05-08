PROGRAM = ringispil
CC      = gcc
CFLAGS  = -g -Wall -lm
LDLIBS  = -lglut -lGLU -lGL

$(PROGRAM): keyboard_and_timer.o swing_carousel.o main.o child.o colors.o image.o background.o
	$(CC) -o $(PROGRAM) main.o keyboard_and_timer.o swing_carousel.o child.o colors.o image.o background.o $(CFLAGS) $(LDLIBS)

.PHONY:  clean

clean:
	-rm *.o $(PROGRAM)
