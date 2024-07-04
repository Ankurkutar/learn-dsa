#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            // If the current value is less than the next value, subtract it
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                result -= roman[s[i]];
            } else {
                // Otherwise, add it
                result += roman[s[i]];
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    std::string romanNumeral;

    std::cout << "Enter a Roman numeral: ";
    std::cin >> romanNumeral;

    int integerValue = solution.romanToInt(romanNumeral);
    std::cout << "The integer value is: " << integerValue << std::endl;

    return 0;
}
