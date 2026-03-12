
## Text Analysis Library
## Introduction
This is a C++ library project designed to analyze the contents of a text file. The library encapsulates file processing and data analysis in a `TextAnalyzer` class. It computes the line count, word count, the longest word, average word length and word frequencies in a case-insesitive manner. Through this project, I learnt many OOP principles while separating the **Interface** (`.h`) and **Implementation** (`.cpp`) files.



## Compilation and execution steps
To compile the project, run-
```bash
make
```
This will generate an executable named `text_analyzer` using `g++` with the `-std=c++11`, `-Wall` and `-Wextra` flags.

Run the program using the following command-line argument:
```bash
./text_analyzer <filename>
```
The file name should be mentioned with appropriate path reference with respect to the current directory.


## Design Overview
The `TextAnalyzer` class of the library has the following private members-
1. `vector<string> lines_` - to store the content of the file in the form of lines
2. `map<string, int> wordFreq_` - to store word frequencies
3. `void process()` - a helper function used to define a word and store their frequencies by iterating through `lines_`

The public interface contains the constructor function, as well as functions to determine the **total line count**, **total word count**, **longest word**, **average word length** and the **word frequency map**

### Program Input/Output Example (after compiling)

**Input:**
```
./text_analyzer hello.txt
```

**Output:**
```
--- Text Analysis Results ---

Lines:               4
Words:               12
Longest word:        project
Average word length: 3.5

Word frequencies:

a:2
file:1
hello:1
is:2
project:1
text:1
thank:1
this:2
you:1
```


## Assumptions and limitations
- Word Definition: Only characters A-Z and a-z are considered part of a word.
- Case Sensitivity: To ensure accurate frequency counting, all words are converted to lowercase before being stored in the frequency map. Hence, the `getLongestWord()` method will return the word in its lowercase form.
- Empty or Invalid Input: If the file is empty, the program will return a 0 line count, word count and average word length to avoid the Division-by-zero error. If the file cannot be opened, the program terminates using `exit(1)`.
- Time complexity: `void process()` has a time complexity of **O(N)** where **N** is the number of characters in the file.
- Memory Constraints: Since the library uses `vector<string>` to store the entire contents of the file, the program may encounter performance issues while analyzing large memory files.


## LLM Usage
I used an LLM(Gemini) to-
- Learn how file handling is done in C++
- Learn how to iterate through a map
- Guide me with the Makefile
- Guide me with the `process()` logic


