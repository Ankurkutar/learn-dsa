#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
    public:
        int longestPalindrome(string s){
            unordered_map<char, int>charCount;
            for(char ch : s){
                charCount[ch]++;
            }

            int length = 0;
            bool oddFound = false;

            for(auto &pair : charCount){
                if(pair.second % 2 == 0){
                    length += pair.second;
                }else{
                    length += pair.second-1;
                    oddFound = true;
                }
            }

            if(oddFound)
                length++;
            
            return length;
        }
};


int main() {
    Solution solution;

    // Test cases
    string s1 = "abccccdd";   zKIU89COIHXK,M            
    string s2 = "aabbccdde";

    cout << "Longest Palindrome length for \"" << s1 << "\": " 
         << solution.longestPalindrome(s1) << endl;

    cout << "Longest Palindrome length for \"" << s2 << "\": " 
         << solution.longestPalindrome(s2) << endl;

    return 0;
}