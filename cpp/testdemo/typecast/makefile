TARGET=staticcast dynamiccast constcast
.PHONY:all
all:$(TARGET)

$(TARGET):%:%.o
	g++ -gdwarf-2 -g3 -O0 $< -L /usr/local/lib -o $@

%.o:%.cpp
	g++ -gdwarf-2 -g3 -c -O0 $< -o $@ 
clean:
	rm $(TARGET) -f
	rm *.o -f

