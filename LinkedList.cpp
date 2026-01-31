/***************************************************************
  Student Name: Vansh Sharma
  File Name: LinkedList.cpp
  Assignment number: 1

 Contains the implementation of the LinkedList class methods
***************************************************************/

#include "LinkedList.hpp"


/***************************************************************
  Function: LinkedList
  Purpose: Initializes an empty linked list.
***************************************************************/
LinkedList::LinkedList() {
    head = nullptr;
}

/***************************************************************
  Function: insert
  Purpose: Inserts a userid and encrypted password into the linked list.
  Parameters: userid (string) - userid to insert
              encryptedPassword (string) - encrypted password
***************************************************************/
void LinkedList::insert(string userid, string encryptedPassword) {
    Node* newNode = new Node(userid, encryptedPassword);

    newNode->next = head;
    head = newNode;
}

/***************************************************************
  Function: search
  Purpose: Searches the linked list for a userid.
  Parameter: userid (string) - userid to search for
  Returns: Node* - pointer to node if found, nullptr otherwise
***************************************************************/
Node* LinkedList::search(string userid) {
    Node* current = head;

    while (current != nullptr) {
        if (current->userid == userid) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}