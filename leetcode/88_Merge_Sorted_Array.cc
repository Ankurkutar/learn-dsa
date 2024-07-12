#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
       void merge(vector<int>&nums1, int m, vector<int>&nums2, int n){
            int i = m -1, j = n-1, k = m + n -1;

            while(j >= 0){
                if(i>=0 && nums1[i] > nums2[j]){
                    nums1[k--] = nums1[i--];
                }else{
                    nums1[k--] = nums2[j--];
                }
            }
       }
};




int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3; // Number of initialized elements in nums1
    vector<int> nums2 = {2, 5, 6};
    int n = 3; // Number of elements in nums2

    Solution solution;
    solution.merge(nums1, m, nums2, n);

    // Print the merged array
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}