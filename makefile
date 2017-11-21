CXXFLAGS =  -g -std=c++17 -pedantic -Wall

all: bubbleSort.h studentStruct.h main
		
version:
	g++ --version

-include make-rules