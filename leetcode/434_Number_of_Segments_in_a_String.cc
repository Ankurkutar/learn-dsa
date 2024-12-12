#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        /*int countSegments(string s){
            int count = 0;
            for(int i=0; i<s.size(); i++){
                if(s[i] != ' ' && (i == 0 || s[i-1] == ' ')){
                    count++;
                }
            }
            return count;
        }*/

        int countSegments(string s){
            int count = 0;
            bool isSegment = false;

            for(int i=0; i<s.size(); i++){
                if(s[i] != ' '){
                    if(!isSegment){
                        count++;
                        isSegment = true;
                    }
                }else{
                    isSegment = false;
                }
            }
            return count;
        }
};

int main() {
    Solution sol;

    cout << sol.countSegments("Hello, World!") << endl;  // Output: 2
    cout << sol.countSegments("   Leading spaces") << endl;  // Output: 2
    cout << sol.countSegments("Multiple    spaces") << endl;  // Output: 2
    cout << sol.countSegments("") << endl;  // Output: 0
    cout << sol.countSegments("A word") << endl;  // Output: 2
    cout << sol.countSegments("    ") << endl;  // Output: 0

    return 0;
}