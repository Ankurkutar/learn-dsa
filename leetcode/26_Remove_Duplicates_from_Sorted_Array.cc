#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0; // Handle empty vector

        int index = 1; // Start from the second element
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] != nums[i+1]){
                nums[index] = nums[i+1];
                index++;
            }
        }

        return index;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int result = solution.removeDuplicates(nums);
    cout << "The length of the array after removing duplicates is: " << result << endl;

    // Print the modified array
    for (int i = 0; i < result; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
