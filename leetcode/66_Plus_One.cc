#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        vector<int> plusOne(vector<int>& digits){
            int n = digits.size();

            for(int i=n-1; i>=0; i--){

                // number is less than from 9
                if(digits[i] < 9){
                    digits[i]++;
                    return digits;
                }
                // number is greater than from 9
                digits[i] = 0;
            }

            digits.insert(digits.begin(), 1);
            return digits;
        }
};

int main() {
    Solution solution;
    // vector<int> digits = {9, 9, 9};
    vector<int> digits = {4,2,3,1};

    vector<int> result = solution.plusOne(digits);
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}