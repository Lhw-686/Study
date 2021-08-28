#include<iostream>
#include<queue>
using namespace std;

typedef struct Node{
    int x, y, z, t;
}Node;
queue<Node> q;
int s[60][60][60];
int a, b, c, t;
int go[][3] = {
    1, 0, 0,
    -1, 0, 0,
    0, 0, -1,
    0, 0, 1,
    0, -1, 0,
    0, 1, 0
};
int check(Node n){
    if(n.x == a - 1 && n.y == b - 1 && n.z == c - 1) return 1;
    if(n.x < 0 || n.x >= a || n.y < 0 || n.y >= b || n.z < 0 || n.z >= c)
        return -1;
    if(s[n.x][n.y][n.z] == 1 || s[n.x][n.y][n.z] == -1) return -1;
    return 0;
}
int f(int x, int y, int z){
    q.push({0, 0, 0, 0});
    s[0][0][0] = -1;
    while(!q.empty()){
        Node cur = q.front(); q.pop();
        for(int i = 0; i < 6; i++){
            Node tmp;
            tmp.x = cur.x + go[i][0];
            tmp.y = cur.y + go[i][1];
            tmp.z = cur.z + go[i][2];
            tmp.t = cur.t + 1;
            int flag = check(tmp);
            if(flag == 1) return tmp.t;
            else if(flag == 0) {
                q.push(tmp);
                s[cur.x][cur.y][cur.z] = -1;
            }
        }
    }
    return -1;
}


int main(){
    scanf("%d %d %d %d", &a, &b, &c, &t);
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            for(int k = 0; k < c; k++){
                scanf("%d", &s[i][j][k]);
            }
        }
    }
    printf("%d\n", f(0, 0, 0));
    return 0;
}
