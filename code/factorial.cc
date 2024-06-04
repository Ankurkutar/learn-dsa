#include <iostream>
using namespace std;

int main()
{
    int long number, fact = 1;
    cout << "Enter a desire number and get factorial: ";
    cin >> number;

    for (int i = 1; i <= number; i++)
    {
        fact = fact * i;
    }

    cout << "Factorial is: " << fact;
    return 0;
}