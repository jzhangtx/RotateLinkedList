RotateLinkedList: RotateLinkedList.o
	g++ -g -o RotateLinkedList.exe RotateLinkedList.o -pthread    

RotateLinkedList.o: RotateLinkedList/RotateLinkedList.cpp
	g++ -g  -c -pthread RotateLinkedList/RotateLinkedList.cpp
