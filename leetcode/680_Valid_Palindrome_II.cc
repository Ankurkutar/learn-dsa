#include<iostream>
#include<string>
using  namespace std;

class Solution{
    public:
        bool isPalindrome(string &s, int left, int right){
            while(left < right){
                if(s[left] != s[right]){
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }

        bool validPalindrome(string s){
            int left = 0, right = s.size();

            while(left < right){
                if(s[left] != s[right]){
                    return isPalindrome(s, left+1, right) || isPalindrome(s, left, right+1);
                }
                left++;
                right--;
            }
            return true;
        }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "abca";
    string test2 = "racecar";
    string test3 = "hello";
    string test4 = "a";
    string test5 = "ab";

    // Run tests
    cout << "Test case: " << test1 << " -> " << (solution.validPalindrome(test1) ? "true" : "false") << endl;
    cout << "Test case: " << test2 << " -> " << (solution.validPalindrome(test2) ? "true" : "false") << endl;
    cout << "Test case: " << test3 << " -> " << (solution.validPalindrome(test3) ? "true" : "false") << endl;
    cout << "Test case: " << test4 << " -> " << (solution.validPalindrome(test4) ? "true" : "false") << endl;
    cout << "Test case: " << test5 << " -> " << (solution.validPalindrome(test5) ? "true" : "false") << endl;

    return 0;
}