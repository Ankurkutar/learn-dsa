#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int>result;
            for(int i=0; i<nums1.size(); i++){
                bool found = false; 
                for(int j=0; j<nums2.size(); j++){
                    if(nums1[i] == nums2[j]){
                        for(int k= j+1; k<nums2.size(); k++){
                            if(nums2[k] > nums1[i]){
                                result.push_back(nums2[k]);
                                found = true;
                                break;
                            }
                        }
                        break;
                    }
                    
                }
                if(!found){
                    result.push_back(-1);
               }
            }
            return result;
        }

        // issue in this code 
        /*vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int>result;
            for(int i=0; i<nums1.size(); i++){         //{4,1,2};;
                for(int j=0; j<nums2.size(); j++){     //{1,3,4,2};
                    if(nums2[j] > nums1[i]){ // issue here
                        result.push_back(nums2[j]);
                        cout<<"pushing: i and j "<<i<< " " <<j<<" "<<nums2[j]<<endl;
                        break;
                    }
                }
                result.push_back(-1); // issue here
            }
            return result;
        }*/
};

int main(){
    Solution solution;

    vector<int>nums1 = {4,1,2};
    vector<int>nums2 = {1,3,4,2};
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    
    cout << "Next Greater Element 1st is: " << endl;
    for(int num : result){
        cout<<num<<" ";
    }
    
    return 0;

}