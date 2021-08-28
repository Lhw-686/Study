#include<iostream>
#include<queue>
using namespace std;

vector<int> edge[505];
int inDegree[505];
queue<int> q;

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        if(n == 0 || m == 0) break;
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            inDegree[b]++;
        }
        queue<int> tmp;
        swap(tmp, q);
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int cur = q.front();q.pop();
            cnt++;
            for(int i = 0; i < edge[cur].size(); i++){
                inDegree[edge[cur][i]]--;
                if(inDegree[edge[cur][i]] == 0){
                    q.push(edge[cur][i]);
                }
            }
        }
        if(cnt == n) puts("YES");
        else puts("NO");
    }
    return 0;
}