#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
        int dominantIndex(vector<int>& nums) {
            if(nums.size() == 1) return 0;

            int max = nums[0], index = 0;

            // first loop for finding max element and it's index
            for(int i=0; i<nums.size(); i++){
                if(max < nums[i]){
                    max = nums[i];
                    index = i;
                }
            }

            // second loop to check double of ith index 
            for(int i=0; i<nums.size(); i++){
                if(i != index && max < nums[i] * 2){
                    return -1;
                }
            }
            return index;
        }
};


int main() {
    Solution solution;
    vector<vector<int>> testCases = {
        {3, 6, 1, 0},   // Test case 1: Should return 1
        {1, 2, 3, 4},   // Test case 2: Should return -1
        {1},            // Test case 3: Should return 0
        {0, 0, 3, 0},   // Test case 4: Should return 2
        {2, 8, 4, 1}    // Test case 5: Should return 1
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";
        int result = solution.dominantIndex(testCases[i]);
        cout << "Result = " << result << endl;
    }

    return 0;
}