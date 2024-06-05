#include<iostream>
using namespace std;

int main(){
    int a, b;
    cout<<"Enter firt Number: ";
    cin>>a;
    cout<<endl<<"Enter Second Number: ";
    cin>>b;

    cout<<endl<<"After Swapping : "<<endl;

    a = a + b;
    b = a-b;
    a = a-b;


    cout<<a<<"  "<<b;
    return 0;

}