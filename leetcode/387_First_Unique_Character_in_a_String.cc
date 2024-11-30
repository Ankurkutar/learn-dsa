#include<iostream>
#include<vector>
using namespace std;

int firstUniqChar(string s){
    vector<int>count(26);
    for(char ch:s){
        count[ch - 'a']++;
    }

    for(int i=0; i<s.size(); i++){
        if(count[s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}

int main() {
    // string s = "leetcode";
    string s = "loveleetcode";

    cout << "Index is: " <<firstUniqChar(s) << endl;

    return 0;
}