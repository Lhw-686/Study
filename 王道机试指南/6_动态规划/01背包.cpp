#include<iostream>
using namespace std;

typedef struct Node{
    int v, t;
}Node;
Node s[1010];
int dp[1010][1010];
int main(){
    int t, m;
    scanf("%d %d", &t, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &s[i].t, &s[i].v);
    }
    //dp[i][j] = dp[i-1][j-s[i].t] + s[i].v, dp[i-1][j];
    for(int i = 0; i < m; i++){
        for(int j = 0; j <= t; j++){
            dp[i][j] = i-1 < 0 ? 0 : dp[i-1][j];
            if(j >= s[i].t){
                dp[i][j] = i-1 < 0 ? s[i].v : max(dp[i-1][j-s[i].t] + s[i].v, dp[i][j]);
            }
        }
    }
    printf("%d", dp[m-1][t]);
    return 0;
}