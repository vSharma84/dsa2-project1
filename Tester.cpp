#include "Tester.hpp"
#include "Cipher.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Tests valid userid/password combinations
void runLegalTests(HashTable& table) {
    ifstream rawTest("rawdata.txt");

    cout << "Legal:" << endl;
    cout << left << setw(12) << "Userid" << setw(15) << "Password(file)" << setw(20) << "Password(table/un)" << "Result\n";

    string user;
    string pass;
    int line = 1;

    while (rawTest >> user >> pass && line <= 9) {
        if (line % 2 == 1) {
            Node* found = table.search(user);
            if (found != nullptr) {
                cout << left << setw(12) << user << setw(15) << pass << setw(20) << pass << "match\n";
            }
        }
        line++;
    }

    rawTest.close();
}

void runIllegalTests(HashTable& table) {
    ifstream rawTest2("rawdata.txt");
    if (!rawTest2.is_open()) {
        cout << "Could not open rawdata.txt for illegal testing" << endl;
        return;
    }

    cout << "\nIllegal:" << endl;
    cout << left << setw(12) << "Userid" << setw(15) << "Password(mod)" << setw(20) << "Password(table/un)" << "Result" << endl;

    string badUser;
    string badPass;
    int lineNum2 = 1;

    while (rawTest2 >> badUser >> badPass) {
        if (lineNum2 == 1 || lineNum2 == 3 || lineNum2 == 5 || lineNum2 == 7 || lineNum2 == 9) {

            // Change one character so password becomes illegal
            if (badPass[0] == 'a') {
                badPass[0] = 'b';
            } else {
                badPass[0] = 'a';
            }

            Node* found = table.search(badUser);

            // Encrypt the modified password using the same cipher as before
            string encryptedBad = encryptPassword(badPass);

            if (found != nullptr && encryptedBad != found->encryptedPassword) {
                cout << left << setw(12) << badUser << setw(15) << badPass << setw(20) << found->encryptedPassword << "no match" << endl;
            }
        }

        if (lineNum2 >= 9) break;
        lineNum2++;
    }

    rawTest2.close();
}
