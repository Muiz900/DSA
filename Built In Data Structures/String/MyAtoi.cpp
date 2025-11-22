#include<iostream>
#include<string>
using namespace std;
int myAtoi(string s) {
    int i = 0, sign = 1, result = 0;
    
    while (i < s.size() && s[i] == ' ') {
        i++;
    }
    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        cout << "Found sign at index: " << i << ", character: " << s[i] << endl;
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while (i < s.size() && isdigit(s[i])) {
        int digit = s[i] - '0';//Basic logic to convert char to int using ASCII values of(0-9)
        //i can do it with switch case as well

        
        if (result > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        result = result * 10 + digit;
        i++;
    }
    return result * sign;
}
int main() {
    string str;
    cout << "Enter a string to convert to integer: ";
    getline(cin, str);
    int result = myAtoi(str);
    cout << "Converted integer: " << result << endl;
    return 0;
}

