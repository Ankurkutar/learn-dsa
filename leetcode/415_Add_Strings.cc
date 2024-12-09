#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// Similarly, '1' has an ASCII value of 49, '2' has an ASCII value of 50, and so on. 
// let's try with 3 
// '3' - '0' = 51 - 48 = 3


class Solution{
    public:
        string addStrings(string nums1, string nums2){
            string result = "";
            int carry = 0;

            int i = nums1.size()-1;
            int j = nums2.size()-1;

            while(i>= 0 || j>= 0 || carry > 0){
                int digit1 = (i >= 0) ? nums1[i] - '0' : 0;
                int digit2 = (j >= 0) ? nums2[j] - '0' : 0;

                int sum = digit1 + digit2 + carry;
                carry = sum / 10;

                result.push_back((sum % 10) + '0');
                i--;
                j--;
            }

            reverse(result.begin(), result.end());
            return result;
        }
};

int main() {
    Solution solution;
    string num1 = "456", num2 = "777";

    string result = solution.addStrings(num1, num2);
    cout << "Sum: " << result << endl;

    return 0;
}