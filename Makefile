CXX       := /usr/bin/g++
CXX_FLAGS := -std=c++17 -fdiagnostics-color=always -Wall
RELEASE_FLAGS := -Ofast
OPENCV := -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc

all: clean main.exe

release: main.cpp
	$(CXX) $(CXX_FLAGS) $(RELEASE_FLAGS) $^ -o main.exe $(OPENCV) 

main.exe: main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(OPENCV)

run: all
	./main.exe

clean:
	rm -f *.exe
