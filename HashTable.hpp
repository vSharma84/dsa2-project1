/***************************************************************
  Student Name: Vansh Sharma
  File Name: HashTable.hpp
  Assignment number: 1

 Defines the HashTable class, handling an array of LinkedList objects.
***************************************************************/

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>
#include "LinkedList.hpp"

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 101;
    LinkedList table[TABLE_SIZE];

    int hashFunction(string userid); // Hash function that maps a userid

public:
    HashTable();

    void insert(string userid, string encryptedPassword); // Inserts a userid and encrypted password 
    Node* search(string userid); // Searches the hash table for a userid and returns the node
};

#endif