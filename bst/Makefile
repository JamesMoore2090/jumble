
run: testDict
	./testDict

testDict: main.o BST.o LL.o HT.o
	g++ -o testDict main.o BST.o LL.o HT.o

main.o: main.cpp BST.h LL.h HT.h
	g++ -c main.cpp

BST.o: BST.cpp BST.h
	g++ -c BST.cpp

HT.o: HT.cpp HT.h
	g++ -c HT.cpp

LL.o: LL.cpp LL.h
	g++ -c LL.cpp

