#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                answer.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                answer.push_back("Fizz");
            } else if (i % 5 == 0) {
                answer.push_back("Buzz");
            } else {
                answer.push_back(to_string(i)); // Correct conversion
            }
        }
        return answer;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    vector<string> result = solution.fizzBuzz(n);

    cout << "FizzBuzz Output:\n";
    for (const string& s : result) {
        cout << s << endl;
    }

    return 0;
}
