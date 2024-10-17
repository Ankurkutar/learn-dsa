#include <iostream>
#include <vector>
#include <algorithm>  // For std::find
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        // Iterate through each element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            // Check if the element exists in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    // Check if the element is already in the result
                    if (find(result.begin(), result.end(), nums1[i]) == result.end()) {
                        result.push_back(nums1[i]);  // Add unique element to result
                    }
                    break; // Stop further comparisons once a match is found
                }
            }
        }

        return result;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());  // Store all unique elements of nums1
        set<int> result; // To store the intersection

        for(int num : nums2){
            if(set1.find(num) != set1.end()){
                result.insert(num);  // Insert the common element into result
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    Solution solution;

    // Example input 1
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    vector<int> result = solution.intersection(nums1, nums2);
    
    cout << "Intersection of nums1 and nums2 (Brute Force): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Example input 2
    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    
    result = solution.intersection(nums1, nums2);
    
    cout << "Intersection of nums1 and nums2 (Brute Force): ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
