#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

string preprocessText(string text) {
    string cleaned = "";

    for (char ch : text) {
        if (isalpha(ch) || isspace(ch)) {
            cleaned += tolower(ch);
        }
    }

    return cleaned;
}

vector<string> splitWords(string text) {
    vector<string> words;
    stringstream ss(text);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

int main() {
    cout << "===== Frequency Analyzer Project =====\n";
    cout << "Enter text (type EXIT on a new line to stop):\n\n";

    string line;
    string fullText;

    // 1️⃣ Collect Input
    while (true) {
        getline(cin, line);

        if (line == "EXIT") {
            break;
        }

        fullText += line + " ";
    }

    // 2️⃣ Print Raw Input
    cout << "\n----- Raw Input Collected -----\n";
    cout << fullText << endl;

    // 3️⃣ Preprocess Text
    string cleanedText = preprocessText(fullText);

    cout << "\n----- Cleaned Text -----\n";
    cout << cleanedText << endl;

    // 4️⃣ Split Words
    vector<string> words = splitWords(cleanedText);

    // 5️⃣ Print Words
    cout << "\n----- Words Extracted -----\n";
    for (const string &w : words) {
        cout << w << endl;
    }

    return 0;
}