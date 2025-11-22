#include<iostream>
using namespace std;
//Method 1 Usiing Bitwise Operator &
bool isPowerofTwo(int n){
    if(n>=0)
    {

        // A number is a power of two if it has only one bit set in its binary representation
        return (n & (n - 1)) == 0;

    }
    return false;
}
//Method 2 Using Logarithm and Floor
#include<cmath>
bool isPowerofTwoLog(int n) {
    if (n <= 0) return false;
    double logValue = log2(n);
    return floor(logValue) == logValue; // Check if log2(n) is an integer
}
//Method 3 Using Loop
bool isPowerofTwoLoop(int n) {
    while(n>1)
    {
        n/=2;


    }
    return n==1;
}
//Method 4 Using Recursion
bool isPowerofTwoRecursion(int n) { 
    if (n < 1) return false; // Base case: if n is less than 1, it's not a power of two
    if (n == 1) return true; // Base case: 2^0 = 1
    if (n % 2 != 0) return false; // If n is odd, it can't be a power of two
    return isPowerofTwoRecursion(n / 2); // Recursive call with n divided by 2
}
//Method 5 Using Bit Manipulation
bool isPowerofTwoBitManipulation(int n) {
    if (n <= 0) return false; // If n is less than or equal to 0, it's not a power of two
    return (n & -n) == n; // Check if n is a power of two using bit manipulation
}//Method 6 Using Bit Count
bool isPowerofTwoBitCount(int n) {

    if (n <= 0) return false; // If n is less than or equal to 0, it's not a power of two
    
    int count = 0; // Initialize count of set bits
    while (n > 0) {
        count += n & 1; // Increment count if the least significant bit is set
        n >>= 1; // Right shift n to check the next bit
    }
    return count == 1; // A power of two has exactly one set bit
}
//Method 7 Using String Conversion
#include <bitset>
#include <string>
bool isPowerofTwoString(int n) {
    if (n <= 0) return false; // If n is less than or equal to 0, it's not a power of two
    string binary = bitset<32>(n).to_string(); // Convert n to binary string
    return binary.find('1') == binary.rfind('1'); // Check if there's only one '1' in the binary representation
}
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Method 1: " << (isPowerofTwo(n) ? "True" : "False") << endl;
    cout << "Method 2: " << (isPowerofTwoLog(n) ? "True" : "False") << endl;
    cout << "Method 3: " << (isPowerofTwoLoop(n) ? "True" : "False") << endl;
    cout << "Method 4: " << (isPowerofTwoRecursion(n) ? "True" : "False") << endl;
    cout << "Method 5: " << (isPowerofTwoBitManipulation(n) ? "True" : "False") << endl;
    cout << "Method 6: " << (isPowerofTwoBitCount(n) ? "True" : "False") << endl;
    cout << "Method 7: " << (isPowerofTwoString(n) ? "True" : "False") << endl;

    return 0;
}
