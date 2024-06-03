#include <iostream>
using namespace std;

int main() {
    int firstNumber = 0;
    int secondNumber = 1;
    int newNumber, count;

    cout << "Enter the number of limit: ";
    cin >> count;

    cout << firstNumber << " " << secondNumber << " "; // Print the first two numbers

    for (int i = 2; i < count; i++) { // Start from 2 since first two numbers are already printed
        newNumber = firstNumber + secondNumber;
        cout << newNumber << " ";

        firstNumber = secondNumber;
        secondNumber = newNumber;
    }

    return 0;
}
