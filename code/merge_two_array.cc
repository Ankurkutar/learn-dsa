// #include<iostream>
#include <bits/stdc++.h>
using namespace std;


// without function 

int main(){
    int n, m,num, j=0;
    cout<<"Enter The Size of first array: " ;
    cin>>n;
    cout<<"Enter The Size of Second array: " ;
    cin>>m;

    int a[n],b[m], res[n+m];

    // take input for first arrray 
    cout<<"Enter the element of first array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>num;
        a[i] = num;

        // storing element in other array 
        res[j] = num;
        j++;
    }


    // take input  for secnd arrray 
    cout<<"Enter the element of second array: "<<endl;
    for(int i=0; i<m; i++){
        cin>>num;
        b[i] = num;

        res[j] = num;
        j++;
    }

    CZ

    // Print the merged and sorted array
    cout << endl << "Merged Array as well sorted: " << endl;
    for (int k = 0; k < n + m; k++) {
        cout << res[k] << " ";
    }



    return 0;
}