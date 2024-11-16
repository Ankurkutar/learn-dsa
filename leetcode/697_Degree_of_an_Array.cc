#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int>count;
        map<int, int>start;
        map<int, int>end;

        int degree = 0;
        for(int i=0; i<nums.size(); i++){
            if(count[nums[i]] == 0){
                start[nums[i]] = i;
            }

            end[nums[i]] = i;
            count[nums[i]]++;
            degree = max(degree, count[nums[i]]);
        }

        int res = INT_MAX;
        for(auto it : count){
            if (it.second == degree) {
                res = std::min(res, end[it.first] - start[it.first] + 1);
            }
        }
        return res;
    }
};

int main() {
    // Test cases
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 2, 3, 1};
    cout << "Shortest subarray length for [1, 2, 2, 3, 1]: " 
         << sol.findShortestSubArray(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 2, 3, 1, 4, 2};
    cout << "Shortest subarray length for [1, 2, 2, 3, 1, 4, 2]: " 
         << sol.findShortestSubArray(nums2) << endl;

    // Example 3
    vector<int> nums3 = {1};
    cout << "Shortest subarray length for [1]: " 
         << sol.findShortestSubArray(nums3) << endl;

    return 0;
}