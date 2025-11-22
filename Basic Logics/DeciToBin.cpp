#include<iostream>
using namespace std;
int deciToBin() {
    int n, binary = 0, base = 1;
    cout << "Enter a decimal number: ";
    cin >> n;

    while (n > 0) {
        int last_digit = n % 2;
        binary += last_digit * base;
        base *= 10;
        n /= 2;
    }

    return binary;
}