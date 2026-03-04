#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Preprocess Text (remove punctuation, lowercase everything)
string preprocessText(string text) {
    string cleaned = "";

    for (char ch : text) {
        if (isalpha(ch) || isspace(ch)) {
            cleaned += tolower(ch);
        }
    }

    return cleaned;
}

// Split Text into Words
vector<string> splitWords(string text) {
    vector<string> words;
    stringstream ss(text);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

// Count Frequency using VECTOR instead of unordered_map
vector<pair<string, int>> countFrequency(const vector<string>& words) {
    vector<pair<string, int>> freq;

    for (const string& word : words) {
        bool found = false;

        // Check if word already exists
        for (auto& entry : freq) {
            if (entry.first == word) {
                entry.second++;
                found = true;
                break;
            }
        }

        // If not found, add new entry
        if (!found) {
            freq.push_back({word, 1});
        }
    }

    return freq;
}

void printWords(const vector<string>& words) {
    cout << "\n----- Word Extracted -----\n";
    for (const string& w : words) {
        cout << w << endl;
    }
}

int main() {

    cout << "===== Frequency Analyzer Project =====\n";
    cout << "Enter text (type EXIT on a new line to stop):\n\n";

    string line;
    string fullText;

    // Collect Input
    while (true) {
        getline(cin, line);

        if (line == "EXIT") {
            break;
        }

        fullText += line + " ";
    }

    // Print Raw Input
    cout << "\n----- Raw Input Collected -----\n";
    cout << fullText << endl;

    // Preprocess Text
    string cleanedText = preprocessText(fullText);

    cout << "\n----- Cleaned Text -----\n";
    cout << cleanedText << endl;

    // Split Words
    vector<string> words = splitWords(cleanedText);

    cout << "\n----- Words Extracted -----\n";
    for (const string &w : words) {
        cout << w << endl;
    }

    // Count Frequency using vector
    vector<pair<string, int>> frequency = countFrequency(words);

    // Sort by frequency (Descending)
    sort(frequency.begin(), frequency.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    // Print Sorted Frequencies
    cout << "\n----- Word Frequencies (Sorted by Frequency Descending) -----\n";

    for (const auto& entry : frequency) {
        cout << entry.first << " : " << entry.second << endl;
    }

    return 0;
}