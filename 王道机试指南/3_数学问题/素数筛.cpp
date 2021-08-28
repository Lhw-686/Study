#include<iostream>
#include<cstring>
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
    int a,n;
    while(scanf("%d %d", &a, &n)!=EOF){
		memset(st,0,sizeof st);
		memset(sst,0,sizeof sst);
		memset(primes,0,sizeof primes);
    f(n);
    int cnt = 0;
    //int cnt2 = f2(n);
    for(int i = a; i <= n; i++){
        if(st[i] == 0){
            cnt++;
        }
    }
    printf("%d\n", cnt);}
    return 0;
}
