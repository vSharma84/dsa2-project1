/***************************************************************
  Student Name: Vansh Sharma
  File Name: main.cpp
  Assignment number: 1

 Generates random passwords from names.txt, encrypts them using a Vigenère cipher,
 puts them into hash table, and runs legal and 
 illegal tests.
***************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "HashTable.hpp"
#include "LinkedList.hpp"


using namespace std;

//Encrypts a password using the Vigenere cipher with key "jones"
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
    //Read userids from names.txt
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

    //Generate random plaintext passwords and write to rawdata.txt
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

    //Read rawdata.txt, encrypt passwords, and write encrypteddata.txt
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

    //Load encrypted data into the hash table
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
    
    //Test legal userid/password combinations
    ifstream rawTest("rawdata.txt");

    if (!rawTest.is_open()) {
        cout << "Could not open rawdata.txt for testing" << endl;
        return 1;
    }

    cout << "Legal:" << endl;
    cout << "Userid Password(file) Password(table/un) Result" << endl;

    string testUser;
    string testPass;
    int lineNum = 1;

    while (rawTest >> testUser >> testPass) {
        if (lineNum == 1 || lineNum == 3 || lineNum == 5 || lineNum == 7 || lineNum == 9) {
            Node* found = table.search(testUser);
            string encryptedTest = encryptPassword(testPass);

        if (found != nullptr && encryptedTest == found->encryptedPassword) {
            cout << testUser << " " << testPass << " " << testPass << " match" << endl;
        }
        }

        if (lineNum >= 9) {
            break;
        }
        lineNum++;
    }

    rawTest.close();

    //Test illegal password combinations (modified passwords)
    ifstream rawTest2("rawdata.txt");
    if (!rawTest2.is_open()) {
            cout << "Could not open rawdata.txt for illegal testing" << endl;
        return 1;
    }

    cout << "\nIllegal:\n";
    cout << "Userid Password(mod) Password(table/un) Result" << endl;

    string badUser;
    string badPass;
    int lineNum2 = 1;

    while (rawTest2 >> badUser >> badPass) {
        if (lineNum2 == 1 || lineNum2 == 3 || lineNum2 == 5 ||
            lineNum2 == 7 || lineNum2 == 9) {

            badPass[0] = (badPass[0] == 'a') ? 'b' : 'a';

            Node* found = table.search(badUser);
            string encryptedBad = encryptPassword(badPass);

        if (found != nullptr && encryptedBad != found->encryptedPassword) {
            cout << badUser << " "
                 << badPass << " "
                 << found->encryptedPassword << " no match" << endl;
        }
    }

        if (lineNum2 >= 9) break;
        lineNum2++;
    }

    rawTest2.close();

    return 0;

}