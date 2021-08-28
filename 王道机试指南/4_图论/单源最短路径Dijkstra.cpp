#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const static int N =10010;
const static int INF = 0x3f3f3f3f;
const static int MIN = 0xcfcfcfcf;
int dis[N], mark[N], cost[N];

typedef struct Edge{
    int next, len, cost;
    
}Edge;
vector<Edge> s[N];
typedef struct Node{
    int v, len;
    bool operator > (const Node& n) const{
        return len > n.len;
    }
}Node;
priority_queue<Node, vector<Node>, greater<Node>> q;

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        if(n == 0 || m == 0) break;
        for(int i = 1; i <= n; i++){
            s[i].clear();
            dis[i] = INF;
            mark[i]= false;
        }
        for(int i = 0; i < m; i++){
            int a, b;
            Edge tmp;
            scanf("%d %d %d %d", &a, &tmp.next, &tmp.len, &tmp.cost);
            s[a].push_back(tmp);
            b = tmp.next;
            tmp.next = a;
            s[b].push_back(tmp);
        }
        int S, T;
        scanf("%d %d", &S, &T);
        dis[S] = 0;
        q.push({S, 0});
        while(!q.empty()){
            Node tmp = q.top(); q.pop();
            if(mark[tmp.v]) continue;
            mark[tmp.v] = true;
            for(int i = 0; i < s[tmp.v].size(); i++){
                Edge t = s[tmp.v][i];
                if(mark[t.next]) continue;
                if(dis[tmp.v] + t.len < dis[t.next] ||
                dis[tmp.v] + t.len == dis[t.next] && cost[tmp.v] + t.cost < cost[t.next]){
                    dis[t.next] = dis[tmp.v] + t.len;
                    cost[t.next] = cost[tmp.v] + t.cost;
                    q.push({t.next, dis[t.next]});
                }
            }
        }
        printf("%d %d\n", dis[T], cost[T]);
    }
    return 0;
}