#include<iostream>
#include <unordered_set>
#include<string>

using namespace std;

class Solution{
    public:
        // first approach
        /*int numJewelsInStones(string jewels, string stones){
            int count = 0;

            for(int i=0; i<jewels.size(); i++){
                for(int j=0; j<stones.size(); j++){
                    if(jewels[i] == stones[j]){
                        count++;
                    }
                }
            }
            return count;
        }*/

        // second approach 
        int numJewelsInStones(string jewels, string stones){
            unordered_set<char> jewelSet(jewels.begin(), jewels.end());
            int count = 0;
            for(char stone : stones){
                if(jewelSet.count(stone)){
                    count++;
                }
            }
            return count;
        }

};


int main() {
    // Test cases
    Solution solution;

    string jewels1 = "aA";
    string stones1 = "aAAbbbb";
    cout << "Test 1: " << solution.numJewelsInStones(jewels1, stones1) << endl; // Output: 3

    string jewels2 = "z";
    string stones2 = "ZZ";
    cout << "Test 2: " << solution.numJewelsInStones(jewels2, stones2) << endl; // Output: 0

    string jewels3 = "abc";
    string stones3 = "aabbccdd";
    cout << "Test 3: " << solution.numJewelsInStones(jewels3, stones3) << endl; // Output: 6

    string jewels4 = "AB";
    string stones4 = "aAbBAB";
    cout << "Test 4: " << solution.numJewelsInStones(jewels4, stones4) << endl; // Output: 3

    return 0;
}
