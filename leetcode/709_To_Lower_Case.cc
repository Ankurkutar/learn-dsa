#include<iostream>
#include<string>
using namespace std;

string toLowerCase(string s){
    for(char &c : s){
        if(c >= 'A' && c <= 'Z'){ // letter must be between this range
            c+= 32; // if add 32 small character get it
        }
    }
    return s;
}

int main() {
    // Test cases
    cout << toLowerCase("Hello") << endl;   // Output: "hello"
    cout << toLowerCase("here") << endl;    // Output: "here"
    cout << toLowerCase("LOVELY") << endl;  // Output: "lovely"
    return 0;
}