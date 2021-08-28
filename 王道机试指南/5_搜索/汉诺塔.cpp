#include<iostream>
using namespace std;

int f(int n){
    if(n == 1) return 2;
    return f(n-1) + 1 + f(n-1) + 1 + f(n-1);
}
int ff(int n){
    if(n == 1) return 1;
    return 2*ff(n-1) + 1;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        printf("%d\n", ff(n));
    }
    return 0;
}