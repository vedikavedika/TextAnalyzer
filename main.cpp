#include <iostream>
#include "TextAnalyzer.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input-file>\n";
        return 1;
    }

    TextAnalyzer analyzer(argv[1]);
    cout << endl;
    cout << "--- Text Analysis Results ---" << endl;
    cout << endl;
    cout << "Lines:               " << analyzer.getLineCount() << endl;
    cout << "Words:               " << analyzer.getWordCount() << endl;
    cout << "Longest word:        " << analyzer.getLongestWord() << endl;
    cout << "Average word length: " << analyzer.getAverageWordLength() << endl;
    cout << endl;
    cout << "Word frequencies:" << endl;
    cout << endl;
    auto freq= analyzer.getWordFrequency();
    for(auto const& pair: freq){
	cout << pair.first <<  ":" << pair.second << endl;
    }
    cout << endl;
    return 0;
}
