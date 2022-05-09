
# Getting all the sources
SOURCE := $(wildcard *.cpp)
HEADERS := $(wildcard *.H)

# Creating the list of objects by replacing the .cpp with .o for the sources
OBJECTS := $(SOURCE:.cpp=.o)

MAINS := lorenz.o lorenz_test.o 
OBJECTS := $(filter-out $(MAINS), $(OBJECTS))

# Debug mode
DEBUG = TRUE

# Compiling a .cpp file to .o
%.o : %.cpp ${HEADERS}
	g++ -std=c++20 ${CXXFLAGS} -c $<

# Rules for making the main build
lorenz: lorenz.o ${OBJECTS}
	g++ -std=c++20 -o $@ lorenz.o ${OBJECTS}

# Rules for making the test build
lorenz_test: lorenz_test.o $(OBJECTS)
	g++ -std=c++20 -o $@ lorenz_test.o ${OBJECTS}
	./lorenz_test

# Erase intermediate objects
clean:
	rm -f *.o lorenz
	rm -f *.o lorenz_test
	rm -f *.dat lorenz
	rm -f *.dat lorenz_test

