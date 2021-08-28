#include<iostream>
using namespace std;

typedef struct Node{
    int v, w;
}Node;

Node s[10010];
int n, v;
int dp[10010];

int main(){
    scanf("%d %d", &n, &v);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &s[i].v, &s[i].w);
    }
    for(int j = 0; j <= v; j++){
        dp[j] = j / s[0].v * s[0].w;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= v; j++){
            if(j < s[i].v) dp[j] = dp[j];
            else dp[j] = max(dp[j-s[i].v] + s[i].w, dp[j]);
        }
    }
    printf("%d", dp[n-1][v]);
}