#include "LinkedList.hpp"

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::insert(string userid, string encryptedPassword) {
    Node* newNode = new Node(userid, encryptedPassword);

    newNode->next = head;
    head = newNode;
}

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