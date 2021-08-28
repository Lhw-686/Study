#include<iostream>
using namespace std;

unsigned long long f(int a, int b){
    unsigned long long ans = 1;
    while(b){//cout << a << endl;
        if(b & 1){
            
            ans *= a;
        }
        a *= a;
        b = b >> 1;
    }
    return ans;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << f(a, b) << endl;
}