#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "HashTable.hpp"
#include "LinkedList.hpp"


using namespace std;

string encryptPassword(string password) {
    string key = "jones";
    string result = "";
    int counter = 0;

    for (int i = 0; i < password.size(); i++) {
        int shift = (password[i] - 'a') + (key[counter] - 'a');
        char encryptedChar = 'a' + (shift % 26);
        
        result += encryptedChar;

        counter++;
        if (counter >= key.size()) {
            counter = 0;
        }
    }

    return result;
}

int main() {
    ifstream infile("names.txt");

    if (!infile.is_open()) {
        cout << "Could not open names.txt" << endl;
        return 1;
    }

    vector<string> userids;
    string userid;
    string restOfLine;

    while (infile >> userid) {
        userids.push_back(userid);
        getline(infile, restOfLine);
    }

    infile.close();

    srand(time(0));

    ofstream outfile("rawdata.txt");

    if (!outfile.is_open()) {
        cout << "Could not create rawdata.txt" << endl;
        return 1;
    }

    for (int i = 0; i < userids.size(); i++) {
        string password;

        for (int j = 0; j < 9; j++) {
            char c = 'a' + (rand() % 26);
            password += c;
        }

        outfile << userids[i] << " " << password << endl;
    }

    outfile.close();

    ifstream rawfile("rawdata.txt");
        if (!rawfile.is_open()) {
            cout << "Could not open rawdata.txt" << endl;
            return 1;
        }

    ofstream encfile("encrypteddata.txt");
    if (!encfile.is_open()) {
        cout << "Could not create encrypteddata.txt" << endl;
        return 1;
    }

    string id;
    string plainPassword;

    while (rawfile >> id >> plainPassword) {
        string encrypted = encryptPassword(plainPassword);
        encfile << id << " " << encrypted << endl;
    }  

    rawfile.close();
    encfile.close();

    HashTable table;

    ifstream encInput("encrypteddata.txt");
    if (!encInput.is_open()) {
        cout << "Could not open encrypteddata.txt\n";
        return 1;
    }

    string uid;
    string encryptedPassword;

    while (encInput >> uid >> encryptedPassword) {
        table.insert(uid, encryptedPassword);
    }

    encInput.close();

    Node* testNode = table.search("SMITH");

    return 0;

}