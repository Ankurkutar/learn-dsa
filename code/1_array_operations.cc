#include<iostream>
using namespace std;

void show(int arr[], int size);
void insert_first(int arr[], int size);
void insert_last(int arr[], int size);
void insert_mid(int arr[], int size);
void insert_random(int arr[], int size);


int main(){
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int size = sizeof(arr)/sizeof(int);


    while(1){
        cout << "*****************Welecome**************\n";
        cout<<"Choose one option from the following list ...\n\n";
        cout << "1.Insert Element in first index:\n";
        cout << "2.Insert Element in last index:\n";
        cout << "3.Insert Element in mid index:\n";
        cout << "4.Insert Element in random index:\n";
        cout << "5.show\n";
        cout << "6.exit():\n";

        cout << "Enter your choice: ";
        int choice;
        cin>>choice;

        switch (choice)
        {
        case 1:
            insert_first(arr, size);
            break;
        case 2:
            insert_last(arr, size);
            break;
        case 3:
            insert_mid(arr, size);
            break;
        case 4:
            insert_random(arr, size);
            break;
        case 5:
            show(arr, size);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Oops you entered wrong choice please enter valid option:\n\n";
            break;
        }
    }
}

void show(int arr[], int size){
    cout<<"Element of array..\n";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
void insert_first(int arr[], int size){
    cout<<"Enter Element: ";
    int number;
    cin>>number;
    arr[0] = number;
}
void insert_last(int arr[], int size){
    cout<<"Enter Element: ";
    int number;
    cin>>number;
    arr[size-1] = number;
}
void insert_mid(int arr[], int size){
    cout<<"Enter Element: ";
    int number;
    cin>>number;
    int mid = size/2;
    arr[mid] = number;
}
void insert_random(int arr[], int size){
    cout<<"Enter Element: ";
    int number, position;
    cin>>number;
    cout<<"Enter Position: ";
    cin>>position;
    arr[position] = number;
}