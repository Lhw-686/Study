#include<iostream>
using namespace std;
const static int N = 100010;
int n, v, iv, iw, is;
typedef struct Node{
    int v, w, s;
}Node;
//Node s[N];
int dp[N];
int main(){
    scanf("%d %d", &n, &v);
    int index = 0;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &iv, &iw, &is);
        int p = 1, q = is;
        while(is){
            int k = min(p, q);
            //s[index++] = {min(p, q)*iv, min(p, q)*iw, 1};
            for(int j = v; j >= 0; j--){
                if(j < k*iv) dp[j] = dp[j];
                else dp[j] = max(dp[j-k*iv] + k*iw, dp[j]);
            }
            q -= p;
            p *= 2;
            is >>= 1;
        }
    }
    /*for(int j = 0; j <= v; j++){
        dp[0][j] = j < s[0].v ? 0 : s[0].w;
    }
    for(int i = 1; i < index; i++){
        for(int j = 0; j <= v; j++){
            if(j < s[i].v) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j-s[i].v] + s[i].w, dp[i-1][j]);
        }
    }
    printf("%d", dp[index-1][v]);*/
    /*for(int j = 0; j <= v; j++){
        dp[j] = j < s[0].v ? 0 : s[0].w;
    }
    for(int i = 1; i < index; i++){
        for(int j = v; j >= 0; j--){
            if(j < s[i].v) dp[j] = dp[j];
            else dp[j] = max(dp[j-s[i].v] + s[i].w, dp[j]);
        }
    }*/
    printf("%d", dp[v]);
    return 0;
}