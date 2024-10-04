#include<iostream>
using namespace std;

class Solution{
    public:
        // bool isPalindrome(string s){
        //     int left = 0; 
        //     int right = s.size()-1;

        //     while (left < right)
        //     {
        //         if(!isalnum(s[left])){
        //             left++;
        //         }else if(!isalnum(s[right])){
        //             right--;
        //         }else if(tolower(s[left]) != tolower(s[right])){
        //             return false;
        //         }else{
        //             left++;
        //             right--;
        //         }
        //     }
        //     return true;   
        // }

        // other way 
        bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main(){
    Solution solution;
    string testStr = "A man, a plan, a canal: Panama";  // Example palindrome

    if(solution.isPalindrome(testStr)){
        cout << "The string is a valid palindrome." << endl;
    }else{
        cout << "The string is not a valid palindrome." << endl;
    }

    return 0;
}