#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char &ch) {
    string vowels = "aeiouAEIOU";
    //return vowels.find(ch) != string::npos; // Check if ch is in vowels
  
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
    }
    return false;
}

string reverseVowels(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (!isVowel(s[left])) {
            left++;
        } else if (!isVowel(s[right])) {
            right--;
        } else {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

int main() {
    string s = "IceCreAm";

    cout << "Reversed Vowels: " << reverseVowels(s) << endl;

    return 0;
}
