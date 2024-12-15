#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
        bool detectCapitalUse(string word){
            int capitalCount = 0;

            for(char c : word){
                if(isupper(c)){
                    capitalCount++;
                }
            }

            // here dealing of all UpperCase and LoweCase 
            if(capitalCount == word.size() && capitalCount == 0)
                return true;

            // here dealealing with the only first uppCase letter 
            if(capitalCount == 1 && isupper(word[0]))
                return true;

            return false;
        }
};

int main() {
    Solution solution;
    string word = "Google";
    cout << (solution.detectCapitalUse(word) ? "true" : "false") << endl;
    return 0;
}