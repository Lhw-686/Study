#include<iostream>
using namespace std;

const static int N = 100;
int s[N], n;

int process(int pre, int cur){
    if(cur == n) return 0;
    int a = 0, b;
    //Ҫ��ǰλ��
    if(pre < 0 || s[pre] < s[cur]){
        a = process(cur, cur + 1) + 1;
    }
    //��Ҫ��ǰλ�û�ǰλ�ò��������
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