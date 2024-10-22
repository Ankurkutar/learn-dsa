#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        /*int findMaxConsecutiveOnes(vector<int>& nums) {
            int count = 0;
            int maxCount = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == 1){
                    count++;
                    // cout<<"plus: "<<count<<endl;
                }else{
                    maxCount = max(maxCount, count);
                    count = 0;
                }
            }
            maxCount = max(maxCount, count);

            return maxCount;
        }*/

       int findMaxConsecutiveOnes(vector<int>& nums) {
            int count = 0;
            int maxCount = 0;
            for(int num : nums){
                if(num == 1){
                    count++;
                }else{
                    maxCount = max(maxCount, count);
                    count = 0;
                }
            }
            maxCount = max(maxCount, count);

            return maxCount;
        }
};

int main(){
    Solution solution;

    // vector<int>nums = {1,1,0,1,1,1};
    vector<int>nums = {1,0,1,1,0,1};
    int result = solution.findMaxConsecutiveOnes(nums);
    
    cout << "Max Consecutive Ones: " << result << endl;
    
    return 0;

}