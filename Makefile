CXX = g++
CXXFLAGS = -std=c++17 -Wall

OBJS = main.o HashTable.o LinkedList.o Tester.o

project1 : $(OBJS)
	$(CXX) $(CXXFLAGS) -o project1 $(OBJS)

main.o : main.cpp HashTable.hpp LinkedList.hpp Tester.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

HashTable.o : HashTable.cpp HashTable.hpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c HashTable.cpp

LinkedList.o : LinkedList.cpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

Tester.o : Tester.cpp Tester.hpp HashTable.hpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c Tester.cpp

clean:
	rm -f *.o project1 rawdata.txt encrypteddata.txt
