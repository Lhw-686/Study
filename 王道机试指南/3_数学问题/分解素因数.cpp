#include<iostream>
#include<vector>
using namespace std;

const static int N = 100;
int s[N], primes[N];
//vector<int> primes;
void f(){
    for(int i = 2; i < N / i; i++){
        if(s[i]) continue;
        //primes[]
        //primes.push_back(i);
        for(int j = i * i; j < N; j += i){
            s[j] = 1;
        }
    }
}

int ff(int n){
    int cnt = 0;
    for(int i = 2; i < N; i++){
        if(s[i] == 1) continue;
        while(n % i == 0){
            printf("%d ", i);
            n /= i;
            cnt++;
        }
    }
    printf("\n");
    return n == 0 ? cnt - 1 : cnt;
}

int main(){
    int n;
    f();
    cin >> n;
    cout << ff(n) << endl;
    return 0;
}