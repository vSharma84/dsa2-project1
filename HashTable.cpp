/***************************************************************
  Student Name: Vansh Sharma
  File Name: HashTable.cpp
  Assignment number: 1

 Implements the hash table's logic, using a custom hash function 
***************************************************************/

#include "HashTable.hpp"

/***************************************************************
  Function: HashTable
  Purpose: Initializes the hash table.
***************************************************************/
HashTable::HashTable() {
}

/***************************************************************
  Function: hashFunction
  Purpose: Computes a hash value for a userid.
  Parameter: userid (string) - userid to hash
  Returns: int - index in hash table
***************************************************************/
int HashTable::hashFunction(string userid) {
    int sum = 0;

    for (int i = 0; i < userid.length(); i++) {
        sum += userid[i];
    }

    return sum % TABLE_SIZE;
}

/***************************************************************
  Function: insert
  Purpose: Inserts a userid and encrypted password into the hash table.
  Parameters: userid (string) - userid to insert
              encryptedPassword (string) - encrypted password
***************************************************************/
void HashTable::insert(string userid, string encryptedPassword) {
    int index = hashFunction(userid);
    table[index].insert(userid, encryptedPassword);
}

/***************************************************************
  Function: search
  Purpose: Searches the hash table for a userid.
  Parameter: userid (string) - userid to search for
  Returns: Node* - pointer to node if found, nullptr otherwise
***************************************************************/
Node* HashTable::search(string userid) {
    int index = hashFunction(userid);
    return table[index].search(userid);
}