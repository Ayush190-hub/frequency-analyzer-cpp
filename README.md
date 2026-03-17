## **Frequency Analyzer (C++)**

A command-line C++ application that analyzes text input to compute word frequencies, statistics, and distributions using STL containers, algorithms, and file handling.


---

## Problem Statement

Analyzing large text manually to find frequent words and patterns is inefficient.

This project provides a simple text analysis tool that processes raw input, cleans the text, counts word frequencies, and generates statistical insights using C++.

The program can also export analysis results into a report file for further use.


---

## Why This Project?

I built this project to:

:- Strengthen my C++ STL skills

:- Practice string processing and text preprocessing

:- Implement hash-based frequency counting (unordered_map)

:- Learn sorting with STL algorithms and lambda functions

:- Work with file handling and report generation

:- Improve program structure and modular design

:- Gain experience with Git & GitHub workflow



---

## Features

(1) Accept text input from console

(2) Accept input from text file via command-line argument

(3) Text preprocessing (remove punctuation, convert to lowercase)

(4) Word tokenization using stringstream

(5) Word frequency counting using unordered_map

(6) Stop-word filtering (ignore common words)

(7) Sorted frequency analysis

(8) Text statistics

    Total words

    Unique words

    Most frequent word

    Average word length


(9) Word length distribution analysis

(10) Automatic report export to -- analysis_report.txt



---

## TECH STACK

* **Language:** C++

* **STL Containers:**

    * vector
    * unordered_map
    * unordered_set


* **Algorithms**

    * sort
    * lambda functions


* **File Handling**

    * ifstream
    * ofstream


* **Other Concepts**

    * stringstream
    * string processing


* **SAMPLE USAGE**

===== Frequency Analyzer =====

Enter text (type EXIT to stop)

Hello world
Hello data
Data science
EXIT

Output:

----- Text Statistics -----

Total Words : 6
Unique Words : 4
Most Frequent Word : data (2 times)
Average Word Length : 4.3


---

## TIME & SPACE COMPLEXITY

(1) Word Frequency Counting

Average Time: O(n) using unordered_map


(2) Sorting Frequencies

Time: O(n log n)


(3) Space Complexity

O(n) for storing words and frequency maps




---

## FUTURE IMPROVEMENTS

(1) Support multiple input files

(2) Add top-N frequent words filtering

(3) Implement configurable stop-word list

(4) Export results to CSV format

(5) Build a GUI version

(6) Add visual word frequency charts



---

## PROJECT STATUS

Completed (Core + Analytical Version)

The project is fully functional and demonstrates text preprocessing, hashing, sorting, and statistical analysis using C++ STL.

Further improvements would focus on advanced text analytics and visualization.
