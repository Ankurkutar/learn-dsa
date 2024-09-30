#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        // Initialize the row with `rowIndex + 1` elements, all set to 1
        vector<int> row(rowIndex + 1, 1);

        // Fill in the row, working from the second-to-last element backwards to avoid overwriting
        for (int i = 1; i <= rowIndex; i++)
        {
            for (int j = i - 1; j > 0; j--)
            {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
    }

    vector<int> generate(int numRows)
    {
        vector<vector<int>> ans; // Initialize the result vector to store the rows of Pascal's Triangle
        for (int i = 0; i < numRows; i++)
        {
            // Create a row of size (i + 1) and initialize all elements to 1
            vector<int> row(i + 1, 1);
            // Fill in the middle values (i.e., between the first and last elements)
            for (int j = 1; j < i; j++)
            {
                row[j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            // Add the row to the result
            ans.push_back(row);
        }

        return ans[numRows - 1]; // Return the (numRows-1)th row (0-indexed)
    }
};

// int main()
// {
//     Solution solution;
//     int rowIndex = 5;
//     vector<int> result = solution.getRow(rowIndex);

//     for (int num : result)
//     {
//         cout << num << " ";
//     }
//     cout << endl;
//     return 0;
// }


// for other way 
int main()
{
    Solution solution;
    int numRows = 5;

    // Get the specific row from Pascal's Triangle
    vector<int> result = solution.generate(numRows); 

    // Output the specific row of Pascal's Triangle
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
