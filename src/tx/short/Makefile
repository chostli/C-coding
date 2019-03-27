CCFLAGS= -D DEBUG -g -shared -fPIC 
HOMEPATH=~/lib/
HOME=/home/lpj
INC=-I$(HOME)/src/incl_c -I/usr/include/ 
LIB=-L$(HOME)/lib  -lbase
OBJECT=ch03.so ch04.so ch05.so ch06.so
OBJECT1=ch03.o ch04.o ch05.o ch06.o
all:$(OBJECT)
$(OBJECT):$(OBJECT1)
	cc -o $@ $(CCFLAGS) $(INC) $(LIB) $
	mv *.so $(HOME)/lib/
%.o:%.c
	cc -c -o $@ $(CCFLAGS) $(INC) $(LIB) $<

.PHONE:clean
clean:
	-rm -rf *.o
