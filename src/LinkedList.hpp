#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>

using std::string;

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

class LinkedList {
private:
    Node* head;

public:
    LinkedList();

    void insert(string userid, string encryptedPassword);
    Node* search(string userid);
};

#endif
