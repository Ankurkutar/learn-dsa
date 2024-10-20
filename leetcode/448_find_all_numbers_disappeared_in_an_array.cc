#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        // using brute force method 
        /*vector<int>findDisappearedNumbers(vector<int>& nums){
            vector<int>result;
            int n = nums.size();

            for(int i = 1; i <= n; i++){
                bool found = false;
                
                for(int j=0; j<n; j++){
                    if(nums[j] == i){
                        found = true;
                        break;
                    }
                }

                if(!found){
                    result.push_back(i);
                }
            }
            return result;
        } */

        //    using index - concept 
        vector<int>findDisappearedNumbers(vector<int>& nums){
            vector<int>result;

            for(int i=0; i<nums.size(); i++){
                int index = abs(nums[i])-1; // Convert number to index
                if(nums[index] > 0){
                    // cout<<-nums[index];
                    nums[index] = -nums[index];
                }
            }

            for(int i=0; i<nums.size(); i++){
                if(nums[i] > 0){
                    result.push_back(i+1);
                }
            }

            return result;
        }
};


int main() {
    Solution solution;
    // Example array
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    // Call the function to find disappeared numbers
    vector<int> disappearedNumbers = solution.findDisappearedNumbers(nums);
    
    // Print the disappeared numbers
    cout << "Disappeared Numbers: ";
    for (int num : disappearedNumbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}