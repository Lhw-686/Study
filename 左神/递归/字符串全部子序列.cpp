#include <iostream>
using namespace std;
string s;
void process(string cur, int i){
    if(i == s.length()){
        cout << cur << endl;
        return;
    }
    process(cur + s[i], i+1);
    process(cur, i+1);
}

void process2(int i){
    if(i == s.length()){
        cout << s << s.length() <<endl;
        return;
    }
    process2(i+1);
    char temp = s[i];
    s[i] = 0;
    process2(i+1);
    s[i] = temp;
}

int main(){
    //cin >> s;
    //process2(0);
    char ch[4];
    for(int i = 0; i <= 2; i++){
        cin >> ch[i];
    }
    for(int i = 0; i < 3; i++){
        cout << ch[i];
    }
    cout << endl;
    char temp = ch[1];
    ch[1] = 0;
    for(int i = 0; i < 3; i++){
        cout << ch[i];
    }
    cout << endl;
    ch[1] = temp;
    for(int i = 0; i < 3; i++){
        cout << ch[i];
    }
    cout << endl;
    //s = "abc";
    //s[2] = 'd';
    //cout << s << endl;
    return 0;
}