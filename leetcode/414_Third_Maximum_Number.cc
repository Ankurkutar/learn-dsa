#include <iostream>
#include <vector>
#include <algorithm>  // for sort
#include <limits.h>  // For LONG_MIN

using namespace std;

class Solution {
public:
    /*int thirdMax(vector<int>& nums) {
        // Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());

        // Remove duplicates
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        // After removing duplicates, check the size of the array
        int n = nums.size();
        // cout<<"Size: "<<n;

        // If there are less than 3 distinct numbers, return the maximum
        if (n < 3) {
            return nums[n - 1];  // return the largest number
        }

        // Otherwise, return the third largest distinct number
        return nums[n - 3];
    }*/

    // using another way
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (int num : nums) {
            if (num == first || num == second || num == third) {
                continue;
            }

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        return third == LONG_MIN ? first : third;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1};

    int result = solution.thirdMax(nums);
    cout << "The third maximum is: " << result << endl;

    return 0;
}
