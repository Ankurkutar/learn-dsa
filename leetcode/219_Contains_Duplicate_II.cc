#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map; // Map to store the last seen index of each number
        for (int i = 0; i < nums.size(); i++)
        {
            // Check if the current number is already in the map
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k)
            {
                return true;
            }
            // Update the last seen index of nums[i]
            map[nums[i]] = i; // Store the current index
        }
        return false; // No duplicates found within the range
    }

    // bool containsNearbyDuplicate(vector<int>& nums, int k) {
    //     for(int i=0; i<nums.size(); i++){
    //         for(int j = i+1; j<nums.size(); j++){
    //             if(nums[i] == nums[j] && abs(i-j) <= k){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    bool result1 = solution.containsNearbyDuplicate(nums1, k1);
    cout << "Test case 1: " << (result1 ? "true" : "false") << endl;

    // Test case 2
    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    bool result2 = solution.containsNearbyDuplicate(nums2, k2);
    cout << "Test case 2: " << (result2 ? "true" : "false") << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;
    bool result3 = solution.containsNearbyDuplicate(nums3, k3);
    cout << "Test case 3: " << (result3 ? "true" : "false") << endl;

    return 0;
}