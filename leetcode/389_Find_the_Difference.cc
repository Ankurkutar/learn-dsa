#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
    public:
        // using XOR approach 
        char findTheDifference(string s, string t){
            char c = 0;
            for(char ch : s) c ^= ch;
            for(char ch : t) c ^= ch;
            return c;
        }

        //  Using Character Sum Difference
        // char findTheDifference(string s, string t){
        //     int sumS =0, sumT = 0;

        //     for(char ch : s) sumS += ch; // adding charcter into number formate like a 97, b= 98
        //     for(char ch : t) sumT += ch;

        //     return sumT - sumS;
        // }

        // Using Frequency Count (Hash Table)
        // char findTheDifference(string s, string t){
        //     vector<int>charCount(26, 0);

        //     for(char ch : s){
        //         charCount[ch - 'a']++;
        //     }

        //     for(char ch : t){
        //         charCount[ch - 'a']--;
        //         if(charCount[ch - 'a'] < 0){
        //             return ch;
        //         }
        //     }

        //     return '\0';
        // }

};


int main() {
    Solution solution;

    // Test cases
    string s1 = "abcd";
    string t1 = "abcde";
    cout << "The extra character is: " << solution.findTheDifference(s1, t1) << endl;

    string s2 = "xyz";
    string t2 = "xyza";
    cout << "The extra character is: " << solution.findTheDifference(s2, t2) << endl;

    string s3 = "";
    string t3 = "z";
    cout << "The extra character is: " << solution.findTheDifference(s3, t3) << endl;

    string s4 = "aa";
    string t4 = "aaa";
    cout << "The extra character is: " << solution.findTheDifference(s4, t4) << endl;

    return 0;
}