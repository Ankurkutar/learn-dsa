#include<iostream>
#include<vector>
using namespace std;


// brute force approach 
/*class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int n = nums.size();
            for(int i=0; i<n; i++){
                int leftSum = 0, rightSum = 0;

                // calculating left sum 
                for(int j = 0; j<i; j++){
                    leftSum += nums[j];
                }

                // calculating right sum 
                for(int j = i+1; j<n; j++){
                    rightSum += nums[j];
                }

                if(leftSum == rightSum){
                    return i;
                }
            }
            return -1;
        }
};*/


// optimized approach 
class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int totalSum = 0, leftSum = 0;
            for(int num : nums){
                totalSum += num;
            }

            for(int i=0; i<nums.size(); i++){
                int rightSum = totalSum - leftSum - nums[i];
                if(leftSum == rightSum){
                    return i;
                }
                leftSum += nums[i];
            }
            return -1;
        }
};

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    Solution solution;
    int result = solution.pivotIndex(nums);

    if (result != -1) {
        cout << "Pivot index: " << result << endl;
    } else {
        cout << "No pivot index found" << endl;
    }

    return 0;
}