#include<iostream>
#include<cstring>
using namespace std;

int n, m, t, sx, sy, ex, ey;
char s[10][10];
int go[][2] = {0, 1, 1, 0, -1, 0, 0, -1};
bool flag = false;
bool check(int x, int y){
    if(x < 0 || x >= n || y < 0 || y>= m) return false;
    if(s[x][y] == 'X') return false;
    return true;
}

bool dfs(int x, int y, int step){
    if(x == ex && y == ey && step == t) return true;;
    for(int i = 0; i < 4; i++){
        int tx = x+go[i][0], ty = y+go[i][1];
        if(check(tx, ty)){
            s[tx][ty] = 'X';
            bool flag = dfs(tx, ty, step + 1);
            if(flag) return true;
            s[tx][ty] = '.';
        }
    }
    return false;
}
int dfs2(int x, int y){
    if(x == ex && y == ey) {flag = true;return 0;}
    for(int i = 0; i < 4; i++){
        int tx = x+go[i][0], ty = y+go[i][1];
        if(check(tx, ty)){
            s[tx][ty] = 'X';
            int step = 1 + dfs2(tx, ty);
            if(flag) return step;
            s[tx][ty] = '.';
        }
    }
    return -1;
}
int main(){
    scanf("%d %d %d", &n, &m, &t);
    getchar();
    //cout << n << " " << m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%c", &s[i][j]);
            if(s[i][j] == 'S'){
                sx = i;
                sy = j;
            }
            if(s[i][j] == 'D'){
                ex = i;
                ey = j;
            }
        }
        getchar();
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", dfs2(0, 0));
    /*bool ans = dfs(sx, sy, 0);
    if(ans) puts("YES");
    else puts("NO");*/
    
    return 0;
}