#ifndef TEXT_ANALYZER_H
#define TEXT_ANALYZER_H

#include <string>
#include <vector>
#include <map>

class TextAnalyzer {
public:
    // Constructor: loads and processes the file
    explicit TextAnalyzer(const std::string& filename);

    // Query functions
    int getLineCount() const;
    int getWordCount() const;
    std::string getLongestWord() const;
    double getAverageWordLength() const;
    std::map<std::string, int> getWordFrequency() const;

private:
    // Stores raw lines from the file
    std::vector<std::string> lines_;

    // Stores word -> frequency mapping
    std::map<std::string, int> wordFreq_;

    // Helper function to process file contents
    void process();
};

#endif // TEXT_ANALYZER_H
