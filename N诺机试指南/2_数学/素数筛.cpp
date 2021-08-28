#include<iostream>
using namespace std;
const static int N = 1e8+10;
int st[N];
int sst[N], primes[N];
// ∞§ œ…∏
void f(int n){
    for(int i = 2; i <= n / i; i++){
        if(st[i] == 0){
            for(int j = i * i; j <= n; j += i){
                st[j] = 1;
            }
        }
    }
}

// œﬂ–‘…∏
int f2(int n){
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(sst[i] == 0) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            sst[primes[j] * i] = 1;
            if(i % primes[j] == 0) break; 
        }
    }
    return cnt;
}

int main(){
    int n;
    scanf("%d", &n);
    f(n);
    int cnt = 0;
    int cnt2 = f2(n);
    for(int i = 2; i <= n; i++){
        if(st[i] == 0){
            cnt++;
        }
    }
    printf("%d\n", cnt == cnt2);
    return 0;
}
