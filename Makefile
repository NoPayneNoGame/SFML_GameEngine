#project (file name)
PROJ = app.out

#compiler
CC = g++

#compile options
COMP_OP = -I include/ -c -Wall

#libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

#find source files
SRC_FILES := $(foreach f, src/, $(wildcard $(f)*.cpp) )

#create an o file for each cpp file
OBJS = $(patsubst %.cpp, %.o, $(SRC_FILES))


all: $(PROJ)

$(PROJ): $(OBJS)
	$(CC) -o $(PROJ) $(OBJS) $(LIBS)

%.o: %.cpp
	$(CC) -c $(COMP_OP) -o $@ $<


clean:
	rm app.out src/*.o .*.swp vgcore.* 

