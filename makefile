
all: control.c
	gcc -o controller control.c
run: all
	./controller
clean:
	rm *~