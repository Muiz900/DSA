
#include<iostream>
using namespace std;
bool isPalindrome(int n) {
    int original = n;
    long reversed = 0;
if(n < 0) {
        return false; // Negative numbers are not palindromes
    }
    while (n > 0) {
        if(reversed>INT_MAX){
            return false; // Overflow check
        }
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return original == reversed;
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPalindrome(n)) {
        cout << n << " is a palindrome." << endl;
    } else {
        cout << n << " is not a palindrome." << endl;
    }

    return 0;
}