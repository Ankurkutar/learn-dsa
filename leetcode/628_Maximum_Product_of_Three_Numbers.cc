#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int result = max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    //cout<<result; // -99 * -98 * 5 = 9702 - which is smaller than 4950.
    return result;
}


int main() {

//    vector<int> nums = {1,2,3,4};
   vector<int> nums = {-100,-99,-98,3,4,5};

    int result = maximumProduct(nums);
    cout << "Maximum Product of Three Numbers: " << result <<endl;

    return 0;
}