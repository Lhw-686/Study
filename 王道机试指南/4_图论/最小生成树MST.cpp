#include<iostream>
#include<queue>
using namespace std;
typedef struct Edge{
    int a, b, cost;
    bool operator > (const Edge &e) const{
        return cost > e.cost;
    }
}Edge;
int fa[10010];
void init(int n){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
}
int find(int x){
    if(fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int a, int b){
    fa[find(a)] = find(b);
}
priority_queue<Edge, vector<Edge>, greater<Edge>> q;
int main(){
    int n;
    while(scanf("%d", &n) && n != 0){
        init(n);
        int m = n * (n - 1) / 2;
        for(int i = 0; i < m; i++){
            Edge tmp;
            scanf("%d %d %d", &tmp.a, &tmp.b, &tmp.cost);
            q.push(tmp);
        }
        int ans = 0;
        while(!q.empty()){
            Edge tmp = q.top();q.pop();
            if(find(tmp.a) != find(tmp.b)){
                ans += tmp.cost;
                merge(tmp.a, tmp.b);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}