# by default, make will try to build the first target it encounters.
# here we make up a dummy name "ALL" (note: this is not a special make
# name, it is just commonly used).

# CFLAGS += -O2 -s -DNDEBUG

ALL: lorenz

# find all of the source files and header files

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# create a list of object files by replacing .cpp with .o

OBJECTS := $(SOURCES:.cpp=.o)

# debug: executable

# a recipe for making an object file from a .cpp file
# Note: this makes every header file a dependency of every object file,
# which is not ideal, but it is safe.


# Attempt to add debug and optimize flag
%.o : %.cpp ${HEADERS}
	g++ -std=c++20 -g -O2 -c $<

# explicitly write the rule for linking together the executable

# Attempt to add debug and optimize flag
lorenz: ${OBJECTS}
	g++ -std=c++20 -g -O2 -o $@ ${OBJECTS}