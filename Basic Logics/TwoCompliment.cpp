#include<iostream>
using namespace std;
int twoCompliment(){
    //Convert decimal to binary
    int n,binary=0,base=1;
    while(n>0){
        int last_digit=n%2;
        binary+=last_digit*base;
        base*=10;
        n/=2;
    }
    //COnvert binary to two's complement
    int two_complement=0,carry=1;
    while(binary>0){
        int last_digit=binary%10;
        int sum=1-last_digit+carry;
        //we are adding 1 last digit to get reverse of binary
        //and carry will be 1 if sum is greater than 1
        carry=sum/2;
        two_complement+=sum%2*base;
        base*=10;
        binary/=10;
    }

}
