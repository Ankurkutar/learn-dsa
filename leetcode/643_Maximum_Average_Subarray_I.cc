#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Using Other Approach 
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<k; ++i){
            sum = sum + nums[i];
        }
        int maxSum = sum;

        for(int i=k; i<nums.size(); ++i){
            sum = sum + nums[i];
            sum = sum - nums[i-k];
            maxSum = max(maxSum, sum);
        }
        return (maxSum*1.0)/k;
    }


    // simple approach 
    /*double findMaxAverage(vector<int>& nums, int k) {
        double maxSum = -1e9; // Initialize to a very small value to handle negative numbers
        
        for(int i=0; i<= nums.size()-k; i++){
            int sum = 0;
            for(int j=i; j<i+k; ++j){
                sum += nums[j];
            }
            maxSum = max(maxSum, static_cast<double>(sum));
        }

        return maxSum/k;
    }*/
};


int main() {
    // Test case
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    
    // Create Solution object
    Solution solution;
    
    // Call the function and print the result
    double maxAverage = solution.findMaxAverage(nums, k);
    cout << "The maximum average for subarrays of length " << k << " is: " << maxAverage << endl;
    
    return 0;
}