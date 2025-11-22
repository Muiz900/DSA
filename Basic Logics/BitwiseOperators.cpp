#include<iostream>
using namespace std;

int bitwiseOperators() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Bitwise AND: " << (a & b) << endl;
    cout << "Bitwise OR: " << (a | b) << endl;
    cout << "Bitwise XOR: " << (a ^ b) << endl;
    cout << "Bitwise NOT of a: " << (~a) << endl;
    cout << "Bitwise NOT of b: " << (~b) << endl;
    cout << "Left shift a by 1: " << (a << 1) << endl;
    cout << "Right shift a by 1: " << (a >> 1) << endl;

    return 0;
}
bool bitwiseAnd(){
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    return (a & b);
}
bool bitwiseOr(){
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    return (a | b);
}
bool bitwiseXor(){
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    return (a ^ b);
}
bool bitwiseNotA(){
    int a;
    cout << "Enter an integer: ";
    cin >> a;

    return (~a);
}
bool LeftShiftA(){
    //Multipy number by 2 
    int a;
    cout << "Enter an integer: ";
    cin >> a;

    return (a << 1);
}
bool RightShiftA(){
    //Divide number by 2
    int a;
    cout << "Enter an integer: ";
    cin >> a;

    return (a >> 1);
}