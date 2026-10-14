CXX = g++
CXXFLAGS = -O3 -fopenmp -Wall -Wextra
SRC = src/main.cpp src/matmul.cpp
TARGET = matmul_engine

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)