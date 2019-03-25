CLIB=-L/lib64 -L${HOME}lib/ -lc  -g
CINC=-I/${HOME}src/incl_c -I/usr/incl
CCFLAGS= -D DEBUG -g 
OBJECT=$(wildcard *.c)
OBJ=ch05.o main.o ch04.o
VPATH=/home/lpj/src/incl_c/
main:  $(OBJ) 
	cc -o main $(CCFLAGS)  $^ 
#ch03.o : ch03.c  
#	cc -c -o $@ $(CCFLAGS) -I/home/lpj/src/incl_c $*.c
#main.o : main.c  
#	cc -c -o $@ $(CCFLAGS) -I/home/lpj/src/incl_c $*.c
#ch04.o :   ch04.o
#	cc -c -o $@ $(CCFLAGS) -I/home/lpj/src/incl_c $*.c
$(OBJ):$(wildcard,*.c) public.h
	cc -c -I$(VPATH) -o $@  $?.c
.PHONE:clean
clean:
	-rm -rf $(OBJ)
