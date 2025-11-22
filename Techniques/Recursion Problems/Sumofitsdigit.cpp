#include<iostream>
#include<vector>
using namespace std;
int sum(int num) {
    if(num<0){
        num*=-1;
    }
    if (num == 0) return 0;
    return num % 10 + sum(num / 10);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Sum of its digits: " << sum(num) << endl;
    return 0;
}