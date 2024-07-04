#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Sort the vector of strings
        sort(strs.begin(), strs.end());

        // Compare the first and last strings in the sorted vector
        string first = strs[0];
        string last = strs[strs.size() - 1];

        int index = 0;
        int minLength = min(first.size(), last.size());

        // Find the common prefix between the first and last strings
        while (index < minLength && first[index] == last[index]) {
            index++;
        }

        // Return the common prefix substring
        return first.substr(0, index);
    }
};

int main() {
    Solution solution;
    vector<string> strs;
    int n;

    cout << "Enter the number of strings: ";
    cin >> n;

    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    string result = solution.longestCommonPrefix(strs);
    cout << "The longest common prefix is: " << result << endl;

    return 0;
}
