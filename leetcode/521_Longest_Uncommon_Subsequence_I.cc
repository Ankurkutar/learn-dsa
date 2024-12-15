#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
        int findLUSlength(string a, string b){
            if(a == b)
                return -1;
            
            return max(a.size(), b.size());
        }
};

int main() {
    Solution solution;
    string a = "abc";
    string b = "def";
    cout << solution.findLUSlength(a, b) << endl; // Output: 3
    return 0;
}