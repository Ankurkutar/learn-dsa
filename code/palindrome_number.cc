#include<iostream>
using namespace std;

int main(){
    int number, temp, sum= 0;
    cout<<"Enter a number and check number is pallindrome or not: ";
    cin>>number;

    temp = number;
    while(number > 0){
        int reverse = number%10;
        sum = (sum * 10) + reverse;
        number = number / 10;
    }

    if(temp == sum){
        cout<<"Number is pallindrom: "<<temp;
    }else{
        cout<<"Number is not pallindrom: "<<temp;
    }
 

    return 0;

}