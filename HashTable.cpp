/***************************************************************
  Student Name: Vansh Sharma
  File Name: HashTable.cpp
  Assignment number: 1

 Implements the hash table's logic, using a custom hash function 
***************************************************************/

#include "HashTable.hpp"

HashTable::HashTable() {
}

// Computes a hash value for a userid
int HashTable::hashFunction(string userid) {
    int sum = 0;

    for (int i = 0; i < userid.length(); i++) {
        sum += userid[i];
    }

    return sum % TABLE_SIZE;
}

// Inserts a userid and encrypted password
void HashTable::insert(string userid, string encryptedPassword) {
    int index = hashFunction(userid);
    table[index].insert(userid, encryptedPassword);
}

// Searches the hash table for a given userid
Node* HashTable::search(string userid) {
    int index = hashFunction(userid);
    return table[index].search(userid);
}