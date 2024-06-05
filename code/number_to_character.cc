#include<iostream>
using namespace std;

void character(int);

int main(){

    int long number, temp[100], i=0;
    cout<<"Enter number to convert to character: ";
    cin>>number;

    while(number > 0){
        int digit = number % 10;
        temp[i] = digit;
        number = number / 10;
        i++;
    }
    
    for (int j = i - 1; j >= 0; j--) {
        character(temp[j]);
        if (j != 0) {
            cout << ", ";
        }
    }

    return 0;
}

void character(int number) {
    switch (number) {
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
            break;
        case 3:
            cout << "Three";
            break;
        case 4:
            cout << "Four";
            break;
        case 5:
            cout << "Five";
            break;
        case 6:
            cout << "Six";
            break;
        case 7:
            cout << "Seven";
            break;
        case 8:
            cout << "Eight";
            break;
        case 9:
            cout << "Nine";
            break;
        case 0:
            cout << "Zero";
            break;
        default:
            cout << "Invalid digit";
    }
}