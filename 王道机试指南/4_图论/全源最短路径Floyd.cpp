#include<iostream>
using namespace std;
const static int N = 110;
int s[N][N];

void init(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            s[i][j] = -1;
        }
        s[i][i] = 0;
    }
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        if(n == 0 || m == 0) break;
        init(n);
        for(int i = 0; i < m; i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            s[a][b] = c;
            s[b][a] = c;
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(s[i][k] == -1 || s[k][j] == -1) continue;
                    if(s[i][j] == -1 || s[i][k] + s[k][j] < s[i][j]){
                        s[i][j] = s[i][k] + s[k][j];
                    }
                }
            }
        }
        printf("%d\n", s[1][n]);
    }
}