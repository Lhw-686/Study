#include <iostream>
using namespace std;

int reverse(int n){
    int res;
    while(n){
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << reverse(n) << endl;
    return 0;
}