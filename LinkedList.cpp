/***************************************************************
  Student Name: Vansh Sharma
  File Name: LinkedList.cpp
  Assignment number: 1

 Contains the implementation of the LinkedList class methods
***************************************************************/

#include "LinkedList.hpp"

LinkedList::LinkedList() {
    head = nullptr;
}

// Inserts a new node at the head
void LinkedList::insert(string userid, string encryptedPassword) {
    Node* newNode = new Node(userid, encryptedPassword);

    newNode->next = head;
    head = newNode;
}

// Searches for a userid
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