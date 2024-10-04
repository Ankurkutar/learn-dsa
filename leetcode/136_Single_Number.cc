#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
        int singleNumber(vector<int>& nums){
            sort(nums.begin(), nums.end());
            for(int i=0; i<nums.size()-1; i +=2){
                if(nums[i] != nums[i+1]){
                    return nums[i];
                }
            }

            // If we reach the end, the last element is the single one
            return nums[nums.size() - 1];
        }


        // by brute force method 
        int singleNumberByBruteForce(vector<int>& nums){
            for(int i=0; i<nums.size(); i++){
                bool foundDuplicate = false;
                for(int j=0; j<nums.size(); j++){
                    if(i != j && nums[i] == nums[j]){
                        foundDuplicate = true;
                        break;
                    }
                }
                if (!foundDuplicate) {
                return nums[i];
            }
            }
            return -1;
        }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 1, 2, 1, 2}; // Example input

    // Call the function and print the result
    // int result = solution.singleNumber(nums);

    // by brute force method 
    int result = solution.singleNumberByBruteForce(nums);
    cout << "The single number is: " << result << endl;

    return 0;
}