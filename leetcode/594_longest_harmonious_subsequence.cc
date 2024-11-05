#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int findLHS(vector<int>& nums) {
    int maxLength = 0;

    for(int i=0; i<nums.size(); i++){
        cout<<"Round for Outer loop: "<<i<<" ele: " << nums[i] <<endl;
        int count1 = 0, count2 = 0;
        for(int j = 0; j<nums.size(); j++){
            cout<<"Round for innner loop: "<<j<<" ele: " << nums[j] <<endl;
            if(nums[j] == nums[i]){
                count1++; // 1,3,2,2,5,2,3,7
                cout<<"First: "<<nums[j]<< " "<<nums[i]<<endl;
                cout<<"count1: "<<count1<<" & count2: "<<count2<<endl;
            }

            if(nums[j] == nums[i]+1){ // this conditon makes important role 
                count2++;
                cout<<"second: "<<nums[j]<< " "<<nums[i]+1<<endl;
                cout<<"count1: "<<count1<<" & count2: "<<count2<<endl;
            }
        }
        maxLength = max(maxLength, count1+count2);
    }
    return maxLength;
}

 // optimized approach
/*int findLHS(vector<int>& nums) {
    unordered_map<int, int> countMap;
    for (int num : nums) {
        countMap[num]++;
    }

    int maxLength = 0;
    for (const auto& [num, count] : countMap) {
        // Check if there exists an element num + 1
        if (countMap.find(num + 1) != countMap.end()) {
            int harmoniousLength = count + countMap[num + 1];
            maxLength = max(maxLength, harmoniousLength);
        }
    }

    return maxLength;
}*/

int main() {

   vector<int> nums = {1,3,2,2,5,2,3,7};

    int result = findLHS(nums);
    cout << "Harmonious maxlenght is: " << result <<endl;

    return 0;
}