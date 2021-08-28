#include <iostream>
using namespace std;
string s;

void process(int i){
    if(i == s.length()){
        cout << s << endl;
        return;
    }
    bool visit[26];
    for(int j = 0; j < s.length(); j++){
        if(!visit[s[j] - 'a']){
            visit[s[j] - 'a'] = true;
            swap(s[i], s[j]);
            process(i+1);
            swap(s[i], s[j]);
            visit[s[j] - 'a'] = false;
        }
    }
}

int main(){
    cin >> s;
    process(0);
    return 0;
}