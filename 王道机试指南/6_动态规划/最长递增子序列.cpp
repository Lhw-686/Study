#include<iostream>
using namespace std;
int dp[100];
int s[100];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &s[i]);
    }
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(s[i] > s[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}