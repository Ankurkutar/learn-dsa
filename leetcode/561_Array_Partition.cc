#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    int sum = 0;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i+=2){
        sum += nums[i]; // here aftr sorting adding elemnent bcz they also in pair in min ele
    }
    return sum;
}


int main() {
//    vector<int> nums = {1, 4, 3, 2};
   vector<int> nums = {6,2,6,5,1,2};

    int result = arrayPairSum(nums);
    cout << "The maximum sum of min elements in pairs is: " << result << std::endl;

    return 0;
}