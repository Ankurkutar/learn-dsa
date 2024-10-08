#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        string convertToTitle(int columnNumber){
            string result = "";

            while(columnNumber > 0){
                columnNumber--;   // Decrement columnNumber by 1 to map 1-26 to 0-25 (for 26 letters A-Z)
                char ch  = (columnNumber % 26) + 'A';  // Get the character corresponding to columnNumber % 26
                result = ch + result;  // Prepend the character to the result string
                // cout<<columnNumber<<" ";
                columnNumber = columnNumber / 26; // Update n for the next iteration
            }
            return result;
        }
};

int main(){
    Solution solution;

    // Test cases
    int n1 = 1;
    int n2 = 28;
    int n3 = 701;

    // cout << solution.convertToTitle(n1) << endl; // Output: A
    // cout << solution.convertToTitle(n2) << endl; // Output: AB
    cout << solution.convertToTitle(n3) << endl; // Output: ZY
    
    return 0;
}