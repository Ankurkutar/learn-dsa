#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int searchInsert(vector<int>& nums, int target){
            int left = 0;
            int right = nums.size()-1;

            while(left <= right){
                int mid = (left + right) / 2;

                if(nums[mid] == target){
                    return mid;
                }else if(nums[mid] < target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }

            return left;
        }

};


int main(){
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int result = solution.searchInsert(nums, target);
    cout << "The index of the target or the insert position is: " << result << endl;


    return 0;
}