#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine){
    unordered_map<char, int>charCount;

    for(char ch : magazine)
        charCount[ch]++;

    for(char ch : ransomNote){
        if(charCount[ch] == 0){
            return false;
        }
        
        charCount[ch]--;
    }
    return true;
}

// int main() {
//     string ransomNote = "aa";
//     string magazine = "aab";

//     if (canConstruct(ransomNote, magazine)) {
//         cout << "Ransom note can be constructed!" << endl;
//     } else {
//         cout << "Ransom note cannot be constructed!" << endl;
//     }

//     return 0;
// }

// with multiple cases 
int main() {
    vector<pair<string, string>> testCases = {
        {"aa", "aab"},   // Can construct
        {"aa", "ab"},    // Cannot construct
        {"hello", "hlleo"}, // Can construct
        {"xyz", "axyz"}, // Can construct
        {"abc", "ab"},   // Cannot construct
        {"", "anything"} // Empty ransomNote, always true
    };

    cout << "Test results:" << endl;
    for (const auto& testCase : testCases) {
        string ransomNote = testCase.first;
        string magazine = testCase.second;

        if (canConstruct(ransomNote, magazine)) {
            cout << "Ransom note \"" << ransomNote 
                 << "\" can be constructed from \"" << magazine << "\"." << endl;
        } else {
            cout << "Ransom note \"" << ransomNote 
                 << "\" cannot be constructed from \"" << magazine << "\"." << endl;
        }
    }

    return 0;
}