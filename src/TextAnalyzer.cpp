#include "../include/TextAnalyzer.h"

#include <string> 
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

TextAnalyzer::TextAnalyzer(const string& filename){
	ifstream TextFile(filename);
	if(!TextFile.is_open()){
		cerr << "ERROR: Could not open file " << filename << endl;
		exit(1);
	}
	string line;
	while(getline(TextFile, line)){
		lines_.push_back(line);
	}
	TextFile.close();
	
	process();

}

int TextAnalyzer::getLineCount() const{
	return lines_.size();
}

int TextAnalyzer::getWordCount() const{
	int count=0;
	for(auto& pair: wordFreq_){
                string word= pair.first;
		count+= pair.second;
	}
	return count;
}

string TextAnalyzer::getLongestWord() const{
	string maxstr="";
	int maxlen=0;
	for(const auto& pair: wordFreq_){
		string word= pair.first;
		int len=word.length();
		if(len>maxlen){
			maxstr=pair.first;
			maxlen=len;
		}
	}
	return maxstr;
		
}

double TextAnalyzer::getAverageWordLength() const{
	int totWords= getWordCount();
	if(totWords==0) return 0;
	double sum=0;
        for(const auto& pair: wordFreq_){
		string word= pair.first;
		sum+=pair.second*word.length();
	}
	int k=getWordCount();
	double avg= sum/k;
	return avg;
}


map<string,int> TextAnalyzer::getWordFrequency() const{
	
        return wordFreq_;
}


void TextAnalyzer::process() {
	
	for(string line: lines_){
		string word="";
		int k=line.length();
		for(int i=0; i<k;i++){
			if((line[i]>=65 && line[i]<=90) || (line[i]>=97 && line[i]<=122)){
				word+=tolower(line[i]);
			}
			else{
				if(!word.empty()){
					wordFreq_[word]++;
				}
				word="";
			}
		}
		if(!word.empty()){
			wordFreq_[word]++;
		}
	}
}
