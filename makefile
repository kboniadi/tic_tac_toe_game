UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CXX=g++ # define the compiler to use
	TARGET=main # define the name of the executable
	SOURCES=$(wildcard *.cpp */*.cpp)
	CXXFLAGS=-Wall -D_DEFAULT_SOURCE -Wno-missing-braces -Wno-narrowing -Wno-enum-compare -s -O1 -Wl,-rpath,/home/kord/raylib/src -I/usr/local/include -isystem. -isystem/home/kord/raylib/src -isystem/home/kord/raylib/release/include -isystem/home/kord/raylib/src/external
	LFLAGS=-L. -L/usr/local/lib -L/home/kord/raylib/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lc -DPLATFORM_DESKTOP
else
	CXX=g++-10 # define the compiler to use
	TARGET=main # define the name of the executable
	SOURCES=$(wildcard *.cpp */*.cpp)
	CXXFLAGS=-Wall -Wno-narrowing -Wno-enum-compare `pkg-config --cflags raylib`
	LFLAGS=`pkg-config --libs raylib`
endif

#gdb main

################################################################################
### DO NOT EDIT THE FOLLOWING LINES ############################################

# define list of objects
OBJS=$(SOURCES:.cpp=.o)

# the target is obtained linking all .o files
all: $(SOURCES) $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(LFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
