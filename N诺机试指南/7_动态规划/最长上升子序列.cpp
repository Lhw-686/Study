#include<iostream>
using namespace std;

const static int N = 100;
int s[N], n;

int process(int pre, int cur){
    if(cur == n) return 0;
    int a = 0, b;
    //要当前位置
    if(pre < 0 || s[pre] < s[cur]){
        a = process(cur, cur + 1) + 1;
    }
    //不要当前位置或当前位置不满足递增
    b = process(pre, cur + 1);
    return max(a, b);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    cout << process(-1, 0) << endl;
    return 0;
}