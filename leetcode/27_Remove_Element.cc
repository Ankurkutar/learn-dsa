#include<iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int removeElement(vector<int> &nums, int val){
        int index = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};

int main(){
    vector<int>nums = {3,2,2,3};
    int val = 3;
    Solution solution;

    int newLength = solution.removeElement(nums, val);
    cout << "The new length of the array is: " << newLength << endl;

    // Print the modified array
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;

}