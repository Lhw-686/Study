#include<iostream>
#include<cstring>
using namespace std;
int dp[120];
char s1[110];
char s2[110];
int main(){
    gets(s1);
    gets(s2);
    int n = strlen(s1);
    int m = strlen(s2);
    for(int i = 1; i <= n; i++){
        int pre = 0;
        for(int j = 1; j <= m; j++){
            int tmp = dp[j];
            if(i-1 == -1 || j-1 == -1) dp[j] = 0;
            else{
                if(s1[i-1] == s2[j-1]){
                    dp[j] = pre + 1;
                }else{
                    dp[j] = max(dp[j], dp[j-1]);
                }
            }
            pre = dp[j];
        }
    }
    printf("%d", dp[m]);
    return 0;
}