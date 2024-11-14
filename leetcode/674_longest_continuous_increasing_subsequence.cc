#include<iostream>
#include<vector>
using namespace std;


class Solution{
    public:

        // first approach 
        /*int findLengthOfLCIS(vector<int>& nums){
            int ans = 1;
            int count = 1;

            for(int i=0; i<nums.size()-1; ++i){
                if(nums[i] < nums[i+1]){
                    count++;
                    ans = max(count, ans);
                }else{
                    count = 1;
                }
            }
            return ans;
        }*/

    //    reversing approach 
    int findLengthOfLCIS(vector<int>& nums){
        if(nums.empty()) return 0;

        int ans = 1;
        int count = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                count++;
                ans = max(count, ans);
            }else{
                count = 1;
            }
        }
        return ans;
    }
};


int main(){
    Solution solution;
    vector<int> nums = {1, 3, 5, 4, 7};
    int result = solution.findLengthOfLCIS(nums);
    cout << "Length of Longest Continuous Increasing Subsequence: " << result << endl;

    return 0;
}