TARGET = exe
LIBS = -lm
CC = g++
CFLAGS = -g -Wall
ROOT = $(shell pwd)

.PHONY: default all clean

default: lib1 lib2 exe
all: default

LIBRARIES= -lplugin1
LIBPATHS= -L/home/niclas/egna_projs/plugin_framework

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

exe:
	$(CC) main.cpp -Wall $(LIBS) -I./ -I../ -g -o exe -lplugin1 -L$(ROOT) -Wl,-rpath=$(ROOT)

lib1:
	$(CC) $(ROOT)/plugin1/plugin1.cpp $(ROOT)/plugin1/plugin.c -o $(ROOT)/libplugin1.so -fPIC -shared -I../ -I./

lib2:
	$(CC) $(ROOT)/plugin2/plugin2.cpp $(ROOT)/plugin2/plugin.c -o $(ROOT)/libplugin2.so -fPIC -shared -I../ -I./

clean:
	-rm -f *.o
	-rm -f $(TARGET)
	-rm -f *.so 
