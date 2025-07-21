# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude


# Sources and objects
SRC = main.cpp src/Request.cpp src/WebServer.cpp src/LoadBalancer.cpp
OBJ = $(SRC:.cpp=.o)


# Output executable
TARGET = main

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)

	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET) *.o

