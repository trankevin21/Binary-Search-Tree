bst: BST.o
	g++ BST.o -o bst

BST.o: BST.cpp BST.h
	g++ -c BST.cpp
clean:
	rm -f *.o
	rm bst
run: bst
	./bst

