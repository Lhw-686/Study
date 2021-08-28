#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(a%b){
        int t = b;
        b = a % b;
        a = t;
    }
    return b;
}

int main(){
    int a, b;
    cin >> a >> b;
    printf("%d\n", gcd(a, b));
    return 0;
}