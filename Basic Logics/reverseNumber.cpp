#include <iostream>
#include <conio.h>
using namespace std;
int reverseNumber(int n)
{
    int reversed = 0;
    if (n >= 0)
    {
        while (n > 0)
        {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        return reversed;
    }
    else
    {
        int m = -n;

        while (m > 0)
        {
            reversed = reversed * 10 + m % 10;
            m /= 10;
        }
        return -reversed;
    }
}
//
int reverseInteger(int n){
    long long reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
        if (reversed > INT_MAX || reversed < INT_MIN) {
            cout << "Overflow occurred while reversing the number." << endl;
            return 0; 
        }

    }
    return reversed;
}
    int main()
    {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        int reversed = reverseNumber(n);
        cout << "Reversed number: " << reversed << endl;
        getch();
        return 0;
    }
