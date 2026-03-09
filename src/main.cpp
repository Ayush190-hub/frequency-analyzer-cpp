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


// Split text into words
vector<string> splitWords(string text) {

    vector<string> words;

    stringstream ss(text);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}


// Count word frequency
unordered_map<string,int> countFrequency(const vector<string>& words) {

    unordered_map<string,int> freq;

    for (const string& word : words) {
        freq[word]++;
    }

    return freq;
}


// Sort frequencies descending
vector<pair<string,int>> sortFrequencies(const unordered_map<string,int>& frequency) {

    vector<pair<string,int>> freqVector(frequency.begin(), frequency.end());

    sort(freqVector.begin(), freqVector.end(),
         [](const pair<string,int>& a, const pair<string,int>& b) {
             return a.second > b.second;
         });

    return freqVector;
}


// Print extracted words
void printWords(const vector<string>& words) {

    cout << "\n----- Words Extracted -----\n";

    for (const string& w : words) {
        cout << w << endl;
    }
}


// Print frequencies
void printFrequencies(const vector<pair<string,int>>& freqVector) {

    cout << "\n----- Word Frequencies (Sorted) -----\n";

    for (const auto& entry : freqVector) {
        cout << entry.first << " : " << entry.second << endl;
    }
}


// Show statistics
void showStatistics(const vector<string>& words,
                    const unordered_map<string,int>& frequency) {

    cout << "\n----- Text Statistics -----\n";

    int totalWords = words.size();
    int uniqueWords = frequency.size();

    cout << "Total Words : " << totalWords << endl;
    cout << "Unique Words : " << uniqueWords << endl;

    if (totalWords == 0) {
        cout << "No words available for statistics.\n";
        return;
    }

    // Most frequent word
    string mostWord;
    int maxCount = 0;

    for (const auto& entry : frequency) {

        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostWord = entry.first;
        }
    }

    cout << "Most Frequent Word : "
         << mostWord << " (" << maxCount << " times)" << endl;


    // Average word length
    int totalLength = 0;

    for (const string& w : words) {
        totalLength += w.length();
    }

    double avgLength = (double) totalLength / totalWords;

    cout << "Average Word Length : " << avgLength << endl;
}


int main() {

    cout << "===== Frequency Analyzer Project =====\n";
    cout << "Enter text (type EXIT on a new line to stop):\n\n";

    string line;
    string fullText;


    // Collect input
    while (true) {

        getline(cin, line);

        if (line == "EXIT") {
            break;
        }

        fullText += line + " ";
    }


    cout << "\n----- Raw Input Collected -----\n";
    cout << fullText << endl;


    // Preprocess
    string cleanedText = preprocessText(fullText);

    cout << "\n----- Cleaned Text -----\n";
    cout << cleanedText << endl;


    // Split words
    vector<string> words = splitWords(cleanedText);

    printWords(words);


    // Count frequency
    unordered_map<string,int> frequency = countFrequency(words);


    // Show statistics
    showStatistics(words, frequency);


    // Sort frequencies
    vector<pair<string,int>> sortedFreq = sortFrequencies(frequency);


    // Print sorted frequencies
    printFrequencies(sortedFreq);


    return 0;
}