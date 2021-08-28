#include<iostream>
using namespace std;
char s[101];

int tox(int n, int x){
    int index = 0;
    do{
        int t = n % x;
        s[index++] = t < 10 ? '0' + t : t - 10 + 'a';
        n /= x;
    }while(n);
    s[index] = 0;
    return index;
}

int xto(int x){
    int t = 1, ans = 0;
    for(int i = 0; s[i] != 0; i++){
        int a = s[i] <= '9' ? s[i] - '0' : s[i] - 'a' + 10;
        ans += a * t;
        t *= x;
    }
    return ans;
}

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    int index = tox(n, x);
    for(int i = index - 1; i >= 0; i--){
        printf("%c",s[i]);
    }
    printf("\n");
    printf("%d\n", xto(x));
    return 0;
}