#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        bool checkRecord(string s){
            int countA = 0;

            for(int i=0; i<s.size(); i++){
                if(s[i] == 'A'){
                    countA++;
                    if(countA > 1) return false;
                }

                if(i >= 2 && s[i] == 'L'  && s[i-1] == 'L' && s[i-2] == 'L'){
                    return false;
                }
            }

            return true;
        }
};


int main() {
    Solution solution;

    string s1 = "PPALLP";
    cout << solution.checkRecord(s1) << endl; // Output: true

    string s2 = "PPALLL";
    cout << solution.checkRecord(s2) << endl; // Output: false

    string s3 = "PAAL";
    cout << solution.checkRecord(s3) << endl; // Output: false

    string s4 = "PPLLP";
    cout << solution.checkRecord(s4) << endl; // Output: true

    return 0;
}