#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        bool isSubsequence(string s, string t){
            int j =0;

            for(int i=0; i<t.size() && j < s.size(); i++){
                if(s[j] == t[i]){
                    j++;
                }
            }

            return j == s.size();
        }
};


int main() {
    Solution solution;

    // Test cases
    string s1 = "abc", t1 = "ahbgdc";
    string s2 = "axc", t2 = "ahbgdc";

    // Checking first test case
    if (solution.isSubsequence(s1, t1)) {
        cout << "\"" << s1 << "\" is a subsequence of \"" << t1 << "\"." << endl;
    } else {
        cout << "\"" << s1 << "\" is NOT a subsequence of \"" << t1 << "\"." << endl;
    }

    // Checking second test case
    if (solution.isSubsequence(s2, t2)) {
        cout << "\"" << s2 << "\" is a subsequence of \"" << t2 << "\"." << endl;
    } else {
        cout << "\"" << s2 << "\" is NOT a subsequence of \"" << t2 << "\"." << endl;
    }

    return 0;
}