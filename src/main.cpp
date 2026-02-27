#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "===== Frequency analyzer project initialized EXIT=====\n" << endl;
    cout << "Enter text (type EXIT on a new line to stop):\n\n";

    string input;
    string line;
    string fullText;

    while (true) {
        getline(cin, line);

        if (line == "EXIT") {
            break;
        }

        fullText += line + " ";
    }

    cout << "\n-----  Raw Input collected-----\n";
    cout << fullText << endl;

    return 0;
}