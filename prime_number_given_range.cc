#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number;
    bool isPrime;

    cout << "Enter the range to get prime numbers: ";
    cin >> number;

    if (number >= 2) {
        cout << "2 "; 
    }

    for (int i = 3; i <= number; i++) { 
        isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << i << " ";
        }
    }

    return 0;
}
