#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> countMap;  // To store frequency of elements in nums1
    vector<int> result;  // To store the result
    
    // Count the frequency of each element in nums1
    // for (int num : nums1) {
    //     countMap[num]++;
    // }

    cout << "Storing counts for nums1:\n";
    for (int num : nums1) {
        // cout << "Element: " << num << ", Count before insert: " << countMap[num] << endl;
        countMap[num]++;
        // cout << "Element: " << num << ", Count after insert: " << countMap[num] << endl;
    }
    
    // Traverse nums2 and check if the element exists in the countMap with non-zero count
    for (int num : nums2) {
        if (countMap[num] > 0) {  // If element exists and count is greater than 0
            result.push_back(num);  // Add it to the result
            countMap[num]--;  // Decrease the count
            // cout << "Element: " << num << ", Count after insert: " << countMap[num] << endl;
        }
    }
    
    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    
    vector<int> intersectResult = intersect(nums1, nums2);
    
    // Output the result
    cout << "Intersection: ";
    for (int num : intersectResult) {
        cout << num << " ";
    }
    
    return 0;
}
