#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// using function 
// void reverseString(vector<char>& s){
//     reverse(s.begin(), s.end());
// }

// using loop 
void reverseString(vector<char>& s){
    int left = 0;
    int right = s.size()-1;

    while (left < right)
    {
        swap(s[left++], s[right--]);
    }
} 

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o', 'h'};
    reverseString(s);

    cout << "Reversed String: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}