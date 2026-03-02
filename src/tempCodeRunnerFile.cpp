#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <unordered_map>

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

unordered_map<string, int> countFrequency(const vector<string>& words) {
    unordered_map<string, int> freq;

    for (const string& word : words) {
        freq[word]++;
    }

    return freq;
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

    unordered_map<string, int> frequency = countFrequency(words);

    cout << "\n----- Word Frequencies (unsorted) -----\n";

    for (const auto& entry : frequency) {
        cout << entry.first << " : " << entry.second << endl;
    }

    return 0;
}