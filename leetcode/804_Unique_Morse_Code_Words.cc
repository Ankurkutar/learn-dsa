#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCodes = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
        };

        set<string>s;
        for(int i=0; i<words.size(); i++){
            string p = "";
            for(int j=0; j<words[i].size(); ++j){ //j starting from 0 means every indexing value start from first character
                p += morseCodes[words[i][j] - 'a']; // here is logic words[i][j] = words[1][0] means
                
            }
           
            s.insert(p);
        }
        return s.size();

    }
};

int main() {
    Solution solution;
    vector<vector<string>> testCases = {
        {"gin", "zen", "gig", "msg"},   // Test case 1: Should return 2
        {"a", "b", "c", "d"},          // Test case 2: Should return 4
        {"hello", "world"},            // Test case 3: Should return 2
        {"aaa", "aaa"},                // Test case 4: Should return 1
        {"zebra", "dog", "dog"}        // Test case 5: Should return 3
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";
        int result = solution.uniqueMorseRepresentations(testCases[i]);
        cout << "Result = " << result << endl;
    }

    return 0;
}
