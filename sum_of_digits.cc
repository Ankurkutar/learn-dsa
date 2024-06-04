#include<iostream>
using namespace std;

int main(){
    
    int long number,temp, sum = 0;
    cout << "Enter a number get sum of digits: ";
    cin >> number;
    temp = number;
    while(number > 0){
        int reverse = number % 10;
        sum += reverse;
        number = number / 10;
    }

    cout<<"Sum of given Number is: "<<sum;

    
    return 0;
}