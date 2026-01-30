CXX = g++
CXXFLAGS = -std=c++17 -Wall

OBJS = main.o HashTable.o LinkedList.o

project1 : $(OBJS)
	$(CXX) $(CXXFLAGS) -o project1 $(OBJS)

main.o : main.cpp HashTable.hpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

HashTable.o : HashTable.cpp HashTable.hpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c HashTable.cpp

LinkedList.o : LinkedList.cpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

clean:
	rm -f *.o project1 rawdata.txt encrypteddata.txt
