#include<iostream>
using namespace std;

int main(){
    string str1, str2, sum;
    cout<<"Enter first String: ";
    cin>>str1;
    cout<<"Enter Second String: ";
    cin>>str2;

    sum = str1 + ' ' + str2;
    cout<<sum;

    return 0;
}