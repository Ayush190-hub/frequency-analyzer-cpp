#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

using namespace std;

unordered_set<string> stopWords = {
    "the","and","is","to","of","in","a"
};

string preprocessText(const string& text) {
    string cleaned;

    for (char ch : text) {
        if (isalpha(ch) || isspace(ch))
            cleaned += tolower(ch);
    }

    return cleaned;
}

vector<string> splitWords(const string& text) {

    vector<string> words;
    stringstream ss(text);
    string word;

    while (ss >> word)
        words.push_back(word);

    return words;
}

unordered_map<string,int> countFrequency(const vector<string>& words) {

    unordered_map<string,int> freq;

    for (const string& word : words) {

        if (stopWords.find(word) == stopWords.end())
            freq[word]++;
    }

    return freq;
}

vector<pair<string,int>> sortFrequencies(const unordered_map<string,int>& frequency) {

    vector<pair<string,int>> vec(frequency.begin(), frequency.end());

    sort(vec.begin(), vec.end(),
         [](const pair<string,int>& a,const pair<string,int>& b){
            return a.second > b.second;
         });

    return vec;
}

void showStatistics(const vector<string>& words,
                    const unordered_map<string,int>& frequency) {

    cout << "\n----- Text Statistics -----\n";

    int totalWords = words.size();
    int uniqueWords = frequency.size();

    cout << "Total Words : " << totalWords << endl;
    cout << "Unique Words : " << uniqueWords << endl;

    if(totalWords == 0)
        return;

    string mostWord;
    int maxCount = 0;

    for(const auto& entry : frequency){

        if(entry.second > maxCount){
            maxCount = entry.second;
            mostWord = entry.first;
        }
    }

    cout<<"Most Frequent Word : "<<mostWord<<" ("<<maxCount<<" times)\n";

    int totalLength = 0;

    for(const string& w : words)
        totalLength += w.length();

    cout<<"Average Word Length : "
        <<(double)totalLength/totalWords<<endl;
}

void showWordLengthDistribution(const vector<string>& words){

    unordered_map<int,int> lengthFreq;

    for(const string& w : words)
        lengthFreq[w.length()]++;

    cout<<"\n----- Word Length Distribution -----\n";

    for(const auto& entry : lengthFreq)
        cout<<"Length "<<entry.first<<" : "<<entry.second<<" words\n";
}

void printFrequencies(const vector<pair<string,int>>& sortedFreq){

    cout<<"\n----- Word Frequencies -----\n";

    for(const auto& entry : sortedFreq)
        cout<<entry.first<<" : "<<entry.second<<endl;
}

void exportReport(const vector<string>& words,
                  const unordered_map<string,int>& frequency,
                  const vector<pair<string,int>>& sortedFreq){

    ofstream file("analysis_report.txt");

    if(!file){
        cout<<"Error creating report file\n";
        return;
    }

    int totalWords = words.size();
    int uniqueWords = frequency.size();

    file<<"Frequency Analyzer Report\n";
    file<<"=========================\n\n";

    file<<"Total Words: "<<totalWords<<"\n";
    file<<"Unique Words: "<<uniqueWords<<"\n\n";

    file<<"Word Frequencies\n";
    file<<"----------------\n";

    for(const auto& entry : sortedFreq)
        file<<entry.first<<" : "<<entry.second<<"\n";

    file.close();

    cout<<"\nReport exported to analysis_report.txt\n";
}

int main(int argc, char* argv[]) {

    cout<<"===== Frequency Analyzer =====\n";

    string fullText;

    if(argc > 1){

        ifstream file(argv[1]);

        if(!file){
            cout<<"Could not open file.\n";
            return 1;
        }

        string line;

        while(getline(file,line))
            fullText += line + " ";

    }else{

        cout<<"Enter text (type EXIT to stop)\n";

        string line;

        while(true){

            getline(cin,line);

            if(line == "EXIT")
                break;

            fullText += line + " ";
        }
    }

    cout<<"\n----- Raw Input -----\n"<<fullText<<endl;

    string cleanedText = preprocessText(fullText);

    vector<string> words = splitWords(cleanedText);

    unordered_map<string,int> frequency = countFrequency(words);

    showStatistics(words,frequency);

    showWordLengthDistribution(words);

    vector<pair<string,int>> sortedFreq = sortFrequencies(frequency);

    printFrequencies(sortedFreq);

    exportReport(words,frequency,sortedFreq);

    return 0;
}
