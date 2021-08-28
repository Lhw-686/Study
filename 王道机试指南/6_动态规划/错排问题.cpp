#include<iostream>
using namespace std;
int n;
int dp[50];
int main(){
    dp[1] = 0;
    dp[2] = 1;
    while(scanf("%d", &n)){
        for(int i = 3; i <= n; i++){
            dp[i] = (n-1) * dp[i - 2] + (n-1) * dp[i - 1];
        }
        cout << dp[n] << endl;
    }
    return 0;
}