#include<iostream>
using namespace std;

int main() {
    int num1, num2, gcd = 1;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    
    if (num1 <= 0 || num2 <= 0) {
        cout << "Both numbers must be positive integers." << endl;
        return 1; 
    }

    // Find the GCD
    for (int i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            gcd = i;
        }
    }

    cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;

    return 0;
}
