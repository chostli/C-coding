CFLAGS=-ldl -g -D DEBUG -rdynamic
main: main.o 
	cc -o $@  $(CFLAGS)  -I/home/lpj/src/incl_c/ -L/home/lpj/lib -I/home/lpj/lib/ $< -L/home/lpj/lib/ch06.so -lbase
main.o: main.c 
	cc -c -o $@  $(CFLAGS) -I/home/lpj/src/incl_c/ -L/home/lpj/lib $<
clean:
	rm -rf *.o
