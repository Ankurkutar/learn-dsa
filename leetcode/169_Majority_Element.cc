#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution{
    public:
        // first way bcz major element must be mid in case of sorting
        // int majorityElement(vector<int>& nums) {
        //     sort(nums.begin(), nums.end());
        //     int n = nums.size()/2;
        //     return nums[n];
        // }

        // using hashMap second way 
        /*int majorityElement(vector<int>& nums) {
            unordered_map<int, int>countMap;
            int majorityCount = nums.size() / 2;

            for(int num : nums){
                countMap[num]++;
                // cout<<countMap[num]<< " ";
                if(countMap[num] > majorityCount){
                    return num;
                }
            }
            return -1;
        }*/

        // using moore's algorithm
        int majorityElement(vector<int>& nums) {
            int res = nums[0];
            int count = 1;

            for(int i =0; i < nums.size(); i++){
                if(res == nums[i]){
                    count++;
                }else{
                    count--;
                }

                if(count == 0){
                    res = nums[i];
                    count = 1;
                }
            }
            return res;
        }
};

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution solution;

    int result = solution.majorityElement(nums);
    cout<<"Duplicate Element is: "<<result;
    return 0;
}