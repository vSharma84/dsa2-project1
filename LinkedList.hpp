/***************************************************************
  Student Name: Vansh Sharma
  File Name: LinkedList.hpp
  Assignment number: 1

 Defines Node structure and the LinkedList class.
***************************************************************/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>

using std::string;

// Node structure for storing one userid and encrypted password
struct Node {
    string userid;
    string encryptedPassword;
    Node* next;

    Node(string u, string p) {
        userid = u;
        encryptedPassword = p;
        next = nullptr;
    }
};

// Linked list class used as a bucket in the hash table
class LinkedList {
private:
    Node* head;

public:
    LinkedList();

    void insert(string userid, string encryptedPassword);
    Node* search(string userid);
};

#endif
