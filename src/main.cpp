#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string preprocessText (string text) {
    string cleaned = " ";

    for (char ch: text) {
        if (isalpha(ch) || isspace(ch)) {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    cout << "===== Frequency analyzer project initialized EXIT =====\n" << endl;
    cout << "Enter text (type EXIT on a new line to stop):\n\n";

    string input;
    string line;
    string fullText;

    string cleanedText =
    preprocessText(fullText);
    cout << "\n----- Cleaned Text -----\n";
    cout << cleanedText << endl;

    while (true) {
        getline(cin, line);

        if (line == "EXIT") {
            break;
        }

        fullText += line + " ";   // This is called Accumulator Pattern
    }

    cout << "\n-----  Raw Input collected-----\n";
    cout << fullText << endl;

    return 0;
}