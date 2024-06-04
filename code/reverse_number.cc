#include <iostream>
using namespace std;

int main()
{
    int long number, reverse = 0, temp;
    cout << "Enter a number: ";
    cin >> number;
    temp = number;

    while (number > 0)
    {
        int rev = number % 10;
        reverse = reverse * 10 + rev;
        number = number / 10;
    }

    cout << "Reversed Number is: " << reverse;

    return 0;
}