#include<iostream>
using namespace std;

int main(){
    int n, num, arr[100];
    cout<<"How Many number do you want to enter: ";
    cin>>n;

    cout<<"Enter Numbers which you want: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

 int temp = arr[0];
    cout<<endl<<"Greatest number is: ";
    for(int i=0; i<n; i++){
        if (arr[i] > temp) {
            temp = arr[i];
        }
    }

    cout<<temp;

    return  0;
}