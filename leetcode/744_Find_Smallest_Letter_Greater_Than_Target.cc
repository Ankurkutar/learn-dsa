#include <iostream>
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0, right = letters.size()-1;

    while(left <= right){
        int mid = (left+right)/2;
        if(letters[mid] <= target)
            left = mid+1;
        else   
            right = mid-1;
    }
    return letters[left%letters.size()];
    
}

int main() {
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    
    cout << "Next greatest letter: " << nextGreatestLetter(letters, target) << endl;

    target = 'c';
    cout << "Next greatest letter: " << nextGreatestLetter(letters, target) << endl;

    target = 'j';
    cout << "Next greatest letter: " << nextGreatestLetter(letters, target) << endl;

    return 0;
}
