#include<iostream>
using namespace std;

const static int N = 1e7;
int fs[N];

void init(){
    for(int i = 0; i < n; i++){
        fa[i] = i;
    }
}

void find(int x){
    if(fa[x] == x){
        return x;
    }else{
        fa[x] = find(fa[x]);
        return fa[x];
    }
}


// 将i所在的集合并入j所在的集合
void merge(int i, int j){
    fa[find(i)] = find(j);
}

int main(){
    
    return 0;
}