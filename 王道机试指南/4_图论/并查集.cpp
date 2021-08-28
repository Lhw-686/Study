#include<iostream>
using namespace std;
const static int N = 1005;
int fa[N];
int sum[N];
void init(){
    for(int i = 0; i < N; i++){
        fa[i] = i;
        sum[i] = 1;
    }
}
int find(int num){
    if(fa[num] == num) return num;
    fa[num] = find(fa[num]);
    return fa[num];
}
void merge(int a, int b){
    fa[find(a)] = find(b);
    sum[b] += sum[a];
}
int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF && n != 0){
        init();
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            if(find(fa[a]) != find(fa[b])){
                merge(a, b);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(fa[i] == i) ans++;
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}