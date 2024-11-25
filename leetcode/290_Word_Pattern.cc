#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;

bool wordPattern(string pattern, string s){
    unordered_map<char, string>charToWord;
    unordered_map<string, char>wordToChar;
    
    // Split the string `s` into words array to words
    stringstream ss(s);
    string word;
    vector<string>words;

    while(ss >> word){
        words.push_back(word); // inserting all word to vector 
    }

     // If the pattern and words size don't match, return false
    if(pattern.size() != words.size()) return false;

    for(int i=0; i<pattern.size(); ++i){
        char c = pattern[i];
        string w = words[i];

        // Check if the pattern character already maps to a word
        if(charToWord.count(c)){
            if(charToWord[c] != w) return false; // Mismatch
        }else{
            charToWord[c] = w;
        }

        // Check if the word already maps to a pattern character
        if(wordToChar.count(w)){
            if(wordToChar[w] != c) return false; // Mismatch
        }else{
            wordToChar[w] = c;
        }
    }
    return true;

}

int main() {
    string pattern = "abba";
    // string s = "dog cat cat dog";
    string s = "dog cat cat fish";

    if (wordPattern(pattern, s)) {
        cout << "The pattern matches the string!" << endl;
    } else {
        cout << "The pattern does not match the string!" << endl;
    }

    return 0;
}