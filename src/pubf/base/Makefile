CFLAGS= -g -fPIC -shared
OBJECT=pubf_base_file.o
CC= cc
HOME=/home/lpj
LIB=-L$(HOME)/lib
INCLUDE=-I$(HOME)/src/incl_c -I/usr/include
all:libbase.so
libbase.so:$(OBJECT)
	$(CC) -o $@ $(CFLAGS) $(INCLUDE) $(LIB) $<
	mv $@ ~/lib/
%.o:%.c
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE) 
clean:
	rm -rf *.o
