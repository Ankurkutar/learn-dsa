#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        /*int titleToNumber(string columnTitle){
            int result = 0;
            for(char c : columnTitle){
                int value = c - 'A' + 1; // A here 65
                result = result * 26 + value;
            }
            return result;
        }*/

        int titleToNumber(string columnTitle){
            int result = 0;
            int index = columnTitle.length() - 1;
            int multiplier = 1; // This will represent powers of 26 (26^0, 26^1, ...)
            // cout<<"Size: "<<index<<endl;
            // Using a while loop to traverse from right to left
            while(index >= 0){
                char c = columnTitle[index];
                int value = c - 'A' + 1;
                result = result + value * multiplier;
                multiplier *= 26;
                index--; 
            }
            return result;
        }
};

int main(){
    Solution solution;

    // Test cases
    string s1 = "A";
    string s2 = "AB";
    string s3 = "ZY";

    // int index = s3.length() - 1;
    // cout<<index;

    cout << solution.titleToNumber(s1) << endl; // Output: 1
    cout << solution.titleToNumber(s2) << endl; // Output: 28
    cout << solution.titleToNumber(s3) << endl; // Output: 701
    
    return 0;

}