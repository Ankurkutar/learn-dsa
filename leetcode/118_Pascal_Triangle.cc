#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
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

        return ans;
    }

    vector<vector<int>> generateNew(int numRows)
    {
        vector<vector<int>> triangle;

        if (numRows == 0)
        {
            return triangle;
        }

        // First base case row
        triangle.push_back({1});

        // Generate each row
        for (int i = 1; i < numRows; i++)
        {
            vector<int> row(i + 1); // Create a new row of size (i + 1)
            row[0] = row[i] = 1;    // The first and last elements are always 1

            // Fill in the middle elements
            for (int j = 1; j < i; j++)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};

int main()
{
    Solution solution;
    int numRows = 5;

    // vector<vector<int>> result = solution.generate(numRows);

    vector<vector<int>> result = solution.generateNew(numRows); // for different method
    // Output the generated Pascal's Triangle
    for (const auto &row : result)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}