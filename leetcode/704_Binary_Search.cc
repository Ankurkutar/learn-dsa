#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int search(vector<int>& nums, int target){
            int left = 0, right = nums.size()-1;

            while (left <= right)
            {
                int mid = (left + right) / 2;
                if(nums[mid] == target){
                    return mid;
                }else if(nums[mid] > target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
            return -1;
        }
};

int main(){
    Solution solution;

    vector<int>nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int result = solution.search(nums, target);
    
    cout << "Target found at index: " << result << endl;
    
    return 0;

}