#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) {
                    return false;
                } else {
                    char top = stk.top();
                    if ((s[i] == ')' && top == '(') || 
                        (s[i] == ']' && top == '[') || 
                        (s[i] == '}' && top == '{')) {
                        stk.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        return stk.empty();
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter a string of parentheses: ";
    cin >> s;

    bool result = solution.isValid(s);
    cout << "The string is " << (result ? "valid" : "invalid") << endl;

    return 0;
}
