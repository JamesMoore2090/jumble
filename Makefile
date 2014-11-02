jumble: BTNode.o jumble.o
	g++ BTNode.o jumble.o -o jumble
BTNode.o: BTNode.cpp BTNode.h
	g++ -c BTNode.cpp
jumble.o: BTNode.h jumble.cpp
	g++ -c jumble.cpp
