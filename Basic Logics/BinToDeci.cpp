#include<iostream>
using namespace std;
int bintoDeci() {
    int n, decimal = 0, base = 1;
    cout << "Enter a binary number: ";
    cin >> n;

    while (n > 0) {
        int last_digit = n % 10;
        decimal += last_digit * base;
        base *= 2;
        n /= 10;
    }

    return decimal;
}
