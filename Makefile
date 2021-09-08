
all : tutorial

tutorial : tutorial.cpp
	g++ -otutorial tutorial.cpp -lSDL2 -lSDL2_image
