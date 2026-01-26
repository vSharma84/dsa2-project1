#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

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
        cout << "Could not open names.txt\n";
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
        cout << "Could not create rawdata.txt\n";
        return 1;
    }

    for (int i = 0; i < userids.size(); i++) {
        string password;

        for (int j = 0; j < 9; j++) {
            char c = 'a' + (rand() % 26);
            password += c;
        }

        outfile << userids[i] << " " << password << "\n";
    }

    outfile.close();

    cout << "Created rawdata.txt with " << userids.size() << " entries\n";

    return 0;

}