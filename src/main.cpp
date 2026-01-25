#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

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

    cout << "Read " << userids.size() << " userids\n";
    cout << "First 5 userids:\n";

    for (size_t i = 0; i < userids.size() && i < 5; ++i) {
        cout << userids[i] << "\n";
    }

    return 0;
}