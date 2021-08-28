#include <iostream>
using namespace std;

string s;
unsigned long long cnt = 0;

void process(string cur, int i){
    if(i >= s.length()){
        //cout << cur << endl;
        cnt++;
        return;
    }
    if(s[i] > '0' && s[i] <= '9'){
        int a = s[i] - '0', b;
        char ch;
        if(s[i] <= '2' && i + 1 < s.length() && s[i+1] <= '6'){
            b = s[i+1] - '0';
            ch = a*10+b-1 + 'A';
            cur += ch;
            process(cur, i+2);
            cur[cur.length()-1] = 0;
        }
        ch = a-1+'A';
        cur += ch;
        process(cur, i+1);
        cur[cur.length()-1] = 0;
    }
}

int main(){
    cin >> s;
    process("", 0);
    cout << cnt << endl;
}