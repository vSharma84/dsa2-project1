#include "HashTable.hpp"

HashTable::HashTable() {
}

int HashTable::hashFunction(string userid) {
    int sum = 0;

    for (int i = 0; i < userid.length(); i++) {
        sum += userid[i];
    }

    return sum % TABLE_SIZE;
}

void HashTable::insert(string userid, string encryptedPassword) {
    int index = hashFunction(userid);
    table[index].insert(userid, encryptedPassword);
}

Node* HashTable::search(string userid) {
    int index = hashFunction(userid);
    return table[index].search(userid);
}