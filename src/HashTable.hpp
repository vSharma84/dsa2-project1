#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>
#include "LinkedList.hpp"

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 101;
    LinkedList table[TABLE_SIZE];

    int hashFunction(string userid);

public:
    HashTable();

    void insert(string userid, string encryptedPassword);
    Node* search(string userid);
};

#endif