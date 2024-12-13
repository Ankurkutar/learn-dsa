#include <iostream>
#include <string>

using namespace std;

class Solution{
    public:
        bool repeatedSubstringPattern(string s){
            string doubled = s + s;
            // cout<<"doubled "<<doubled<<endl;

            string modified = doubled.substr(1, doubled.size()-2);
            // cout<<"Modified: "<<modified<<endl;

            return modified.find(s) != string::npos;
        }
};

int main() {
    Solution sol;

    cout << sol.repeatedSubstringPattern("abab") << endl;   // Output: true
    cout << sol.repeatedSubstringPattern("aba") << endl;    // Output: false
    cout << sol.repeatedSubstringPattern("abcabcabcabc") << endl; // Output: true
    cout << sol.repeatedSubstringPattern("a") << endl;      // Output: false

    return 0;
}
