#include<iostream>
using namespace std;
int dp[100];
int main(){
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3 ; i <= n; i++){
        dp[i] = dp[i-1] + dp[i - 2];
    }
    cout << dp[n] << endl;
    return 0;
}