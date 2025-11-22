#include<iostream>
#include<vector>
using namespace std;
int fabonacci(int num){

    if(num==0){return 0;}
    if(num==1){;return 1
        ;
    
    
    
    }
    return fabonacci(num-1)+fabonacci(num-2);

}

int main(){
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; ++i) {
        cout<<fabonacci(i);
        if (i < n - 1) cout << " ";
    }
    cout << endl;

}