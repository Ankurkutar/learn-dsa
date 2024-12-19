#include<iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution{
    public:
        /*string reverseWords(string s){
            stringstream ss(s);
            string word, result;

            while(ss >> word){
                reverse(word.begin(), word.end());

                if(!result.empty()) result += " ";
                result += word;
            }
            return result;
        }*/

        string reverseWords(string s){
            int i = 0, j = 0;

            while(i < s.size()){
                while (i < j || i < s.size() && s[i] == ' ')
                {
                    i++;
                }

                while (j < i || j < s.size() && s[j] != ' ')
                {
                    j++;
                }
                reverse(s.begin()+i, s.begin()+j);
                
            }
            return s;

        }
};

int main() {
    Solution solution;

    string s1 = "Let's code";
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: \"" << solution.reverseWords(s1) << "\"" << endl;

    string s2 = "Hello World";
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: \"" << solution.reverseWords(s2) << "\"" << endl;

    string s3 = "a b c";
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: \"" << solution.reverseWords(s3) << "\"" << endl;

    string s4 = "SingleWord";
    cout << "Input: \"" << s4 << "\"" << endl;
    cout << "Output: \"" << solution.reverseWords(s4) << "\"" << endl;

    return 0;
}
