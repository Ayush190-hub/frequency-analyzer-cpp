#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

// Count Frequency using unordered_map
unordered_map<string, int> countFrequency(const vector<string>& words) {
    unordered_map<string, int> freq;
    for (const string& word : words) {
        freq[word]++;  // automatically handles new keys
    }
    return freq;
}

// Sort frequencies descending
vector<pair<string, int>> sortFrequencies(unordered_map<string, int>& frequency) {
    vector<pair<string, int>> freqVector(frequency.begin(), frequency.end());
    sort(freqVector.begin(), freqVector.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });
    return freqVector;
}

void printWords(const vector<string>& words) {
    cout << "\n----- Words Extracted -----\n";
    for (const string& w : words) {
        cout << w << endl;
    }
}

void printFrequencies(const vector<pair<string, int>>& freqVector) {
    cout << "\n----- Word Frequencies (Sorted by Frequency) -----\n";
    for (const auto& entry : freqVector) {
        cout << entry.first << " : " << entry.second << endl;
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

    // Split into Words
    vector<string> words = splitWords(cleanedText);
    printWords(words);

    // Count Frequency
    unordered_map<string, int> frequency = countFrequency(words);

    // Sort Frequencies
    vector<pair<string, int>> sortedFreq = sortFrequencies(frequency);

    // Print Frequencies
    printFrequencies(sortedFreq);

    return 0;
}