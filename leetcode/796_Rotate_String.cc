#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        /*bool rotateString(string s, string goal){
            if(s.length() != goal.length()){
                return false;
            }

            string doubled = s+s;
            return doubled.find(goal) != string::npos;
        }*/
    //    other approach 
       bool rotateString(string s, string goal){
            if(s.length() != goal.length()){
                return false;
            }

            for(int i=0; i<s.size();i++){
                s = s.substr(1) + s[0];
                if(s == goal){
                    return true;
                }
            }
            return false;
       }
};

int main() {
    Solution solution;

    // Test cases
    cout << solution.rotateString("abcde", "cdeab") << endl; // Output: 1 (true)
    cout << solution.rotateString("abcde", "abced") << endl; // Output: 0 (false)
    cout << solution.rotateString("aa", "a") << endl;        // Output: 0 (false)
    cout << solution.rotateString("abcde", "abcde") << endl; // Output: 1 (true)

    return 0;
}