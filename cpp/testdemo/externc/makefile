TARGET=externc
.PHONY:all
all:$(TARGET)

$(TARGET):%:%.o testfunc.o
	g++ -gdwarf-2 -g3 -O0 $< testfunc.o -L /usr/local/lib -o $@
testfunc.o:testfunc.c
	gcc -c testfunc.c -o testfunc.o
%.o:%.cpp
	g++ -gdwarf-2 -g3 -c -O0 $< -o $@ 
clean:
	rm $(TARGET) -f
	rm *.o -f

