#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
        string reverseStr(string s, int k){
            int n = s.size();
            for(int i=0; i<n; i+= 2*k){
                int left = i;
                int right = min(i+k-1, n-1);
                swap(s[left], s[right]);
                left++;
                right--;
            }
            return s;
        }
};

int main() {
    Solution solution;

    // Test Case 1
    string s1 = "abcdefg";
    int k1 = 2;
    cout << "Input: " << s1 << ", k = " << k1 << endl;
    cout << "Output: " << solution.reverseStr(s1, k1) << endl;

    // Test Case 2
    string s2 = "abcdefg";
    int k2 = 4;
    cout << "Input: " << s2 << ", k = " << k2 << endl;
    cout << "Output: " << solution.reverseStr(s2, k2) << endl;

    // Test Case 3
    string s3 = "a";
    int k3 = 2;
    cout << "Input: " << s3 << ", k = " << k3 << endl;
    cout << "Output: " << solution.reverseStr(s3, k3) << endl;

    // Test Case 4
    string s4 = "abcdefgh";
    int k4 = 3;
    cout << "Input: " << s4 << ", k = " << k4 << endl;
    cout << "Output: " << solution.reverseStr(s4, k4) << endl;

    return 0;
}