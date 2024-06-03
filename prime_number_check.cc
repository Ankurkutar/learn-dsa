#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number;
    bool flag = true;

    cout << "Enter the number which you want to check: ";
    cin >> number;

    if (number <= 1) {
        flag = false;
    } else {
        for (int i = 2; i <= sqrt(number); i++) {
            // cout << i << " "<< sqrt(number);
            if (number % i == 0) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        cout << "Number is Prime " << number << endl;
    } else {
        cout << "Number is Not Prime " << number << endl;
    }

    return 0;
}







// *********************first method ********************

// #include <iostream>
// using namespace std;

// int main() {
    
//     int number, flag= true;
//     cout << "Enter the number which you want to check: ";
//     cin>>number;

//     for(int i = 2; i<number/2; i++ ){
//         if(number % i == 0){
//             flag = false;
//             break;
//         }
//     }

//     if(flag){
//         cout << "Number is Prime "<<number;
//     }else{
//         cout << "Number is Not Prime "<<number;
//     }

//     return 0;
// }


