CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = ../usr/bin/matrix_check  # <- путь к бинарнику
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p usr/bin          # создаём директорию, если её нет
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f usr/bin/matrix_check
