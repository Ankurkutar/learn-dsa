#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        void moveZeroes(vector<int>& nums){
            int insertPos = 0;
            for(int i = 0; i<nums.size(); i++){
                if(nums[i] != 0){
                    nums[insertPos] = nums[i];
                    insertPos++;
                }
            }

            while(insertPos < nums.size()){
                nums[insertPos] = 0;
                insertPos++;
            }
        }
};

int main(){

    Solution solution;

    // Example input
    vector<int> nums = {0, 1, 0, 3, 12};
    
    // Print the original array
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Call the moveZeroes function
    solution.moveZeroes(nums);

    // Print the modified array
    cout << "Array after moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}