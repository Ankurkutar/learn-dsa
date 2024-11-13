#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> CopyNum(n + 1, -1);
        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {
            int numInd = nums[i];
            if (CopyNum[numInd] == 1)
            {
                ans.push_back(numInd);
            }
            else
            {
                CopyNum[numInd] = 1;
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            if (CopyNum[i] == -1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 2, 4}; // Example input

    // Find the duplicate and missing numbers
    vector<int> result = solution.findErrorNums(nums);

    // Output the result
    cout << "Duplicate number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;

    return 0;
}