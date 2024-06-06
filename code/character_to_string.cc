#include<iostream>
using namespace std;

int main (){
    char char_array[] = {'J','A','V','A','T','P','O','I','N','T'};  
    int array_size = sizeof(char_array) / sizeof(char);  
    string name = "";

// first method 
    // for(int i =0 ; i<array_size; i++){
    //     cout<<char_array[i];
    // }

// second method 
    for(int i =0 ; i<array_size; i++){
        name = name + char_array[i];
    }
    cout<<name;
    return  0;
}