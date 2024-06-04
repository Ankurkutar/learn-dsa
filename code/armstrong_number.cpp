#include<iostream>
using namespace std;

int main(){
    
    int long number,temp, i=0, sum = 0;
    cout << "Enter a number check number is armstrong or not: ";
    cin >> number;
    temp = number;
    while(number > 0){
        i++;
        int armstrong = number %  10;
        cout<<"iteration "<<i<<" cube root is "<<(armstrong * armstrong * armstrong)<<endl;
        sum = sum + (armstrong * armstrong * armstrong);
        number = number / 10;
    }

if(temp == sum)
cout<<"Number is Armstrong: "<<temp;
else
cout<<"Number is Not Armstrong: "<<temp;

    
    return 0;
}