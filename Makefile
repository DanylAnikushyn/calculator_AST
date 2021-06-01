CXX = g++
CXXFLAGS = -Wall -g
TARGET = main
objects = main.o calc.o ast.o lexer.o parser.o token.o 

all: $(TARGET)

$(TARGET): $(objects) libio
	$(CXX) $(objects) -o main -L. -lio

main.o: src/main.cpp src/include/calc.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp

calc.o: src/calc.cpp src/include/calc.h src/include/io.h \
        src/include/parser.h src/include/lexer.h
	$(CXX) $(CXXFLAGS) -c src/calc.cpp

ast.o: src/ast.cpp src/include/ast.h src/include/token.h
	$(CXX) $(CXXFLAGS) -c src/ast.cpp

lexer.o: src/lexer.cpp src/include/lexer.h src/include/token.h
	$(CXX) $(CXXFLAGS) -c src/lexer.cpp

parser.o: src/parser.cpp src/include/parser.h
	$(CXX) $(CXXFLAGS) -c src/parser.cpp

token.o: src/token.cpp src/include/token.h
	$(CXX) $(CXXFLAGS) -c src/token.cpp

io.o: src/io.cpp src/include/io.h
	$(CXX) $(CXXFLAGS) -c src/io.cpp

libio: 
	$(CXX) -fpic -shared -o libio.so src/io.cpp

clean:
	rm $(TARGET) $(objects) 

.PHONY: all clean