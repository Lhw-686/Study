#include<stdio.h>
int s[100010];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &s[i]);
        s[i] += s[i-1];
    }
    return 0;
}