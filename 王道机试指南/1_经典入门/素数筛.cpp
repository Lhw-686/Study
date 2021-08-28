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

int main(){
    f();
    for(int i = 11; i < N; i += 10){
        if(s[i] == 0){
            printf("%d\n", i);
        }
    }
    return 0;
}